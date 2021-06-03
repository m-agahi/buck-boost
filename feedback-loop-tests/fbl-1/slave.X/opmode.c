//
//
//
#include "mcc_generated_files/pin_manager.h"
#include "opmode.h"

void BUTTON_Released(int buttonPinNumber)
{
    switch (buttonPinNumber)
    {
        case 1:
            while(!IO_RE7_GetValue());
            break;
        case 2:
            while(!IO_RE8_GetValue());
            break;
        case 3:
            while(!IO_RE9_GetValue());
            break;
    };
};

int READ_Buttons()
{
    int buttonPinNumber = 0;
    if (!IO_RE7_GetValue())
    {
        buttonPinNumber = 1;
    }
    else if (!IO_RE8_GetValue())
    {
        buttonPinNumber = 2;
    }
    else if (!IO_RE9_GetValue())
    {
        buttonPinNumber = 3;
    };
    BUTTON_Released(buttonPinNumber);
   
    return buttonPinNumber;
};

int MODE_Config(int mode)
{
    int highOutputPin;
    int lowOutputPin;
    int pwmIOConH;
    int DTCMPSELReg;
    int PMODReg;
    int Q2;
    int Q6;
    
    DTCMPSELReg=1; // Dead-time compensation is controlled by PCI feed-forward limit logic
    PMODReg= 1; // PWM Generator outputs operate in Independent mode /0: complimentary 
    
    // 0: off, 1: buck, 2: boost, 3: buck-boost

    switch (mode)
    {
        case 0: //off
            highOutputPin = 0; // PIN C14
            lowOutputPin = 0; // PIN C15
            Q6 = 0; // OFF
            Q2 = 0; // OFF
            break;
        case 1: //buck
            highOutputPin = 1; // PIN C14
            lowOutputPin = 0; // PIN C15
            Q6 = 2; // PWM
            Q2 = 0; // OFF
            break;
        case 2: //boost
            highOutputPin = 0; // PIN C14
            lowOutputPin = 1; // PIN C15
            Q6 = 1; // ON
            Q2 = 2; // PWM
            break;
        case 3: //buck-boost
            highOutputPin = 1; // PIN C14
            lowOutputPin = 1; // PIN C15
            Q6 = 2; // PWM
            Q2 = 2; // PWM
            PMODReg= 0; //PWM output pins in complementary mode
            break;      
    };
    
    pwmIOConH = (PMODReg << 4) + (highOutputPin << 3) + (lowOutputPin << 2) + (DTCMPSELReg << 7);
    
    if (Q6 == 0)
    {
        _LATC14 = 1;
    }
    else if (Q6 == 1)
    {
        _LATC14 = 0;
    }
    if (Q2 == 0)
    {
        _LATC15 = 0;
    }
    
    return pwmIOConH; 
};

int dutyCycleCalculate (unsigned int period, float percent)
{
    unsigned int onePercent;
    unsigned int dutyCycle;
    onePercent = (period + 8) / 100;
    dutyCycle = (int)(onePercent * percent);
    return (dutyCycle);
};

void LED_Indication(int mode)
{
    switch (mode)
    {
        case 0:
            _LATE0 = 0;
            _LATE1 = 0;
            break;
        case 1:
            _LATE0 = 1;
            _LATE1 = 0;
            break;
        case 2:
            _LATE0 = 0;
            _LATE1 = 1;
            break;
        case 3:
            _LATE0 = 1;
            _LATE1 = 1;
            break;
    };
};