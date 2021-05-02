#include <stdbool.h>
#include <stdint.h>
#include <xc.h>

#include "pwm.h"

#ifndef TRANSIENT_LOAD_CONFIG_ON_TIME_DEFAULT
#define TRANSIENT_LOAD_CONFIG_ON_TIME_DEFAULT 5
#endif

#ifndef TRANSIENT_LOAD_CONFIG_PERIOD_DEFAULT
#define TRANSIENT_LOAD_CONFIG_PERIOD_DEFAULT 200
#endif

static bool enabled = false;
static volatile uint16_t millisecondCount = 0;
static uint16_t onTime, period;
static int16_t dutyCycle = 16383;

#define TRANSIENT_LOAD_PWM_INSTANCE ((struct PWM_INSTANCE*)&PG2CONL)
#define PWM_OUTPUT_FREQ 800000

#ifndef PWM_INPUT_FREQ
#define PWM_INPUT_FREQ 500000000
#endif

#define LOAD_TRANSIENT_PWM_PERIOD (uint16_t)(PWM_INPUT_FREQ/PWM_OUTPUT_FREQ)
#define LOAD_TRANSIENT_PWM_DUTY (uint16_t) (LOAD_TRANSIENT_PWM_PERIOD * 0.5)

//PWM Gen I/O Control
#define LOAD_TRANSIENT_PWM_MODE 1       //0-Comp, 1-Independent, 2-Push/Pull
#define LOAD_TRANSIENT_PWM_H_EN 0       // 0-Dis
#define LOAD_TRANSIENT_PWM_L_EN 1       // 1-EN
#define LOAD_TRANSIENT_PWM_H_INV 0
#define LOAD_TRANSIENT_PWM_L_INV 0

#define LOAD_TRANSIENT_WRITE_IOCONTROL ((LOAD_TRANSIENT_PWM_MODE<<4) | (LOAD_TRANSIENT_PWM_H_EN << 3) | (LOAD_TRANSIENT_PWM_L_EN << 2) | (LOAD_TRANSIENT_PWM_H_INV << 1) | (LOAD_TRANSIENT_PWM_L_INV))

static void LoadAttach(void)
{
    LATCbits.LATC13 = 1;
}

static void LoadDetach(void)
{
    LATCbits.LATC13 = 0;
}

void TRANSIENT_LOAD_Initialize(void)
{
    /* Load attach pin set to output. */
    TRISCbits.TRISC13 = 0;
    
    enabled = false;
    millisecondCount = 0;
    onTime = TRANSIENT_LOAD_CONFIG_ON_TIME_DEFAULT;
    period = TRANSIENT_LOAD_CONFIG_PERIOD_DEFAULT;
    
    LoadDetach();
}

void TRANSIENT_LOAD_Tasks(void)
{
    if(enabled == true)
    {
        if(millisecondCount == 0)
        {
            LoadAttach();
        }
        else if (millisecondCount == onTime)
        {
            LoadDetach();
        }
        
        millisecondCount++;
        
        if (millisecondCount >= period)
        {
            millisecondCount = 0;
        }
    }
}

void TRANSIENT_LOAD_SetOnTime(uint16_t milliseconds)
{
    onTime = milliseconds;
}

void TRANSIENT_LOAD_SetPeriod(uint16_t milliseconds)
{
    period = milliseconds;
}

void TRANSIENT_LOAD_SetCurrent(int16_t currentDuringTransient)
{    
    //Enable the PWM for setting the current during the transient.  Approximate
    //current versus duty cycle is measured as follows (but varies somewhat between boards,
    //and across temperature due to BJT VBE forward voltage and resistor tolerances).
    //As measured on one board at room temp:
    //15% duty = ~800mA
    //47% duty = ~415mA
    //49% duty = ~400mA
    //50% duty = ~390mA
    //60% duty = ~270mA
    //70% duty = ~145mA
    //80% duty = ~30mA
    //85%+ duty = 0mA
    //So: current is ~= -12mA/+1% duty cycle change
    //Desired Duty ~= 1.00 - (Desired Current (A) / 1.2) - 0.17
    //dutyCycle = (float)1.00 - (currentDuringTransient / 1.2) - 0.17;

    dutyCycle = 27197 - (__builtin_mulss(currentDuringTransient, 27306) >> 15);

}

void TRANSIENT_LOAD_Enable(void)
{
    PWM_InitTimeBase(TRANSIENT_LOAD_PWM_INSTANCE, LOAD_TRANSIENT_PWM_PERIOD, dutyCycle, 0x0, 0x0, 0x0);
    PWM_InitOutputState(TRANSIENT_LOAD_PWM_INSTANCE, LOAD_TRANSIENT_WRITE_IOCONTROL, false, 0x0, 0x0);   //Output onto S1PWM2L pin, active high signal
    enabled = true;
}

void TRANSIENT_LOAD_Disable(void)
{
    enabled = false;
    millisecondCount = 0;
    LoadDetach();
    PWM_DisableModule(TRANSIENT_LOAD_PWM_INSTANCE);
}
