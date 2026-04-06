#include "compensator_init.h"

#define BUCK_PWM_INSTANCE ((struct PWM_INSTANCE*)&PG7CONL)
#define BUCK_PWM_TRIG_INSTANCE ((struct PWM_INSTANCE*)&PG6CONL)
#define BUCK_SWITCHING_FREQ 100000

#ifndef PWM_INPUT_FREQ
#define PWM_INPUT_FREQ 500000000UL
#endif

#define BUCK_PWM_PERIOD (uint16_t)(PWM_INPUT_FREQ/BUCK_SWITCHING_FREQ)

//PWM Gen I/O Control
#define BUCK_PWM_MODE 1       //0-Comp, 1-Independent, 2-Push/Pull
#define BUCK_PWM_H_EN 1       // 0-Dis, 1-EN
#define BUCK_PWM_L_EN 0       
#define BUCK_PWM_H_INV 1      // 0-Active High, 1-Active Low
#define BUCK_PWM_L_INV 0

#define BUCK_WRITE_IOCONTROL ((BUCK_PWM_MODE<<4) | (BUCK_PWM_H_EN << 3) | (BUCK_PWM_L_EN << 2) | (BUCK_PWM_H_INV << 1) | (BUCK_PWM_L_INV))

#define BUCK_BLANKING_DELAY 50
#define ACCEPTQUALIFIER 2       // LEB active
#define PCISOURCE 28            // Slave 1 comparator
#define PCIACCEPTCRITERIA 3     // Latched

void INIT_AltRegContext1Setup(void);

int16_t buckErrorControlHistory[4] __attribute__ ((space (ymemory), far));
int16_t buckABCoefficients[5]__attribute__ ((section (".xbss")));

uint16_t buckVoltage = 0;
uint8_t buckSSActiveFlag = 0;
static uint8_t buckErrorCount = 0;
uint16_t buckControlReference = 0;

void INIT_BuckComp(void)
{
    MACRO_CLR_BUCKHISTORY();
            
    buckABCoefficients[0] = BUCK_COMP_2P2Z_COEFF_B0;
    buckABCoefficients[1] = BUCK_COMP_2P2Z_COEFF_B1;
    buckABCoefficients[2] = BUCK_COMP_2P2Z_COEFF_B2;

    buckABCoefficients[3] = BUCK_COMP_2P2Z_COEFF_A1;
    buckABCoefficients[4] = BUCK_COMP_2P2Z_COEFF_A2;
 
    INIT_AltRegContext1Setup();       // Setup  working registers to be used with compensator
}

void INIT_BuckDrive(void)
{    
    //Init the slope compensation DAC
    PDMDAC_Init(1, 0, true, true);  
    PDMDAC_InitTrigger(1, 7, 1, 7);
    PDMDAC_InitDACandCMPWithSlope(1, PWM_INPUT_FREQ, 2.1, 0, -0.27272727, 100000, false, 0);
     
    //Init PWM for buck converter
    PWM_InitTimeBase(BUCK_PWM_INSTANCE, BUCK_PWM_PERIOD, (.95*32767), 0x0, 0x0, 0x0);
  
    PWM_InitPCILogicCL(BUCK_PWM_INSTANCE, true, ACCEPTQUALIFIER, false, PCISOURCE, PCIACCEPTCRITERIA);
    PWM_InitLEBState(BUCK_PWM_INSTANCE, BUCK_BLANKING_DELAY, true, false, false, false);
      
    PWM_InitTrigger(BUCK_PWM_INSTANCE, (BUCK_PWM_PERIOD*.5), (BUCK_PWM_PERIOD*.94), 20); 
    PWM_InitADCTrig1(BUCK_PWM_INSTANCE, 0x0, true, false, false);
    PWM_InitADCTrig2(BUCK_PWM_INSTANCE, false, true, false);
    
    PWM_InitOutputState(BUCK_PWM_INSTANCE, BUCK_WRITE_IOCONTROL, false, 0x0, 0x0);
    
    //PWM6 for generating Trigger
    PWM_InitTimeBase(BUCK_PWM_TRIG_INSTANCE, BUCK_PWM_PERIOD, (.95*32767), 0x0, 0x0, 0x0);   
    
    PWM_InitTrigger(BUCK_PWM_TRIG_INSTANCE, 20, 0x0, 0x0);  //TrigA at 20 used for ADC triggering
    PWM_InitADCTrig1(BUCK_PWM_TRIG_INSTANCE, 0x0, true, false, false);
    
    PWM_InitOutputState(BUCK_PWM_TRIG_INSTANCE, BUCK_WRITE_IOCONTROL, false, 0x0, 0x0);

 
    //Enable and configure the ADC so it can sample the output/input voltages.
    ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT, false, true, true);
    ADC_ChannelEnable(ADC_CHANNEL_BUCK_FB, 0x1);    //Select alternate input #1 to core 0 
    ADC_ChannelEnable(ADC_CHANNEL_VIN_FB, false);
    ADC_ChannelInterruptConfig(ADC_CHANNEL_BUCK_FB, 6, 13);
    ADC_ChannelInterruptConfig(ADC_CHANNEL_VIN_FB, 4, 13);          //Triggered from same source as buck output, ISR priority not used as read from same ISR
    
    INIT_BuckComp();
    
    //Start softstart for buck output
    buckSSActiveFlag = true;

    //Enable ISR as last step
    ADC_ChannelInterruptEnable(ADC_CHANNEL_BUCK_FB);
}


void SOFTSTART_BuckTask(void)
{
    if(buckSSActiveFlag)
    {
        if(buckControlReference < BUCKVOLTAGEREFERENCEADC)
        {
            buckControlReference += BUCKINCREMENT;
        }
        else {
            buckErrorCount = buckSSActiveFlag = 0;
            buckControlReference   = BUCKVOLTAGEREFERENCEADC;
        }
    }
}
    