/*******************************************************************************
Copyright 2017 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#include "sccp.h"

struct SCCP_INSTANCE
{
    volatile uint16_t CCPxCON1L;
    volatile uint16_t CCPxCON1H;
    volatile uint16_t CCPxCON2L;
    volatile uint16_t CCPxCON2H;
    volatile uint16_t CCPxCON3L;    //Note: Potentially Reserved location, may not be implemented on all devices.
    volatile uint16_t CCPxCON3H;
    volatile uint16_t CCPxSTATL;
    volatile uint16_t CCPxSTATH;
    volatile uint16_t CCPxTMRL;
    volatile uint16_t CCPxTMRH;
    volatile uint16_t CCPxPRL;
    volatile uint16_t CCPxPRH;
    volatile uint16_t CCPxRA;
    volatile uint16_t CCPxRAH;      //Note: Potentially Reserved location, may not be implemented on all devices.
    volatile uint16_t CCPxRB;
    volatile uint16_t CCPxRBH;      //Note: Potentially Reserved location, may not be implemented on all devices.
    volatile uint16_t CCPxBUFL;
    volatile uint16_t CCPxBUFH;
};

//Turns on the PWM output with the output enabled with the specified conditions.
//desiredOutputDutyCycle is a double value between [0.000 and 1.000]
void SCCP_InitPWMOutput(struct SCCP_INSTANCE *pInstance, uint32_t perpheralClockFrequency, uint32_t desiredPWMOutputFrequency, double desiredOutputDutyCycle)
{
    uint32_t periodRegValue;
    uint32_t onTimeRegValue;
    
    //Compute the period register value we should use to get the desired PWM frequency.
    periodRegValue = (perpheralClockFrequency / desiredPWMOutputFrequency) - 1;
    if(periodRegValue > 0xFFFF)
    {
        periodRegValue = 0xFFFF;
    }
    
    //Compute the on time register value we need to get the desired PWM duty cycle
    onTimeRegValue = (double)((((double)periodRegValue + 1) * desiredOutputDutyCycle) + 0.5);
        
    //Load up the register values to run in 16-bit bufferred dual edge compare PWM mode.
    pInstance->CCPxCON1L = 0x0005; //16-bit, bufferred dual edge compare PWM mode.
    pInstance->CCPxCON1H = 0x0000;     //No sync, rollover on PRx match
    pInstance->CCPxCON2L = 0x0000;     //No auto-shutdown features enabled
    pInstance->CCPxCON2H = 0x0100;     //Output enabled on SCCPxA output pin.
    pInstance->CCPxPRH = 0;
    pInstance->CCPxPRL = periodRegValue;   //New period starts when the timer reaches this + 1.
    pInstance->CCPxRA = 0x0000;            //Output goes high when timer matches this (ex: 0x0000 = start with output high at the start of the period)
    pInstance->CCPxRB = onTimeRegValue;    //Output goes low when timer matches this

    //Turn on and trigger the module now.
    pInstance->CCPxCON1L |= 0x8000;       //Set the CCPON bit = 1.
    pInstance->CCPxSTATL |= 0x0040;       //Set TRSET = 1, so as to trigger the SCCP module to start running now.
}

//Updates only the PWM duty cycle.  Note: SCCP_InitPWMOutput() should have been called once first to enable the module.
void SCCP_UpdatePWMDutyCycle(struct SCCP_INSTANCE *pInstance, double desiredOutputDutyCycle)
{
    uint32_t onTimeRegValue;

    //Compute the new on-time register value.
    if(desiredOutputDutyCycle <= 0)
    {
        //0% duty cycle.
        onTimeRegValue = 0;
    }
    else if(desiredOutputDutyCycle >= 1.0)
    {
        //100% duty cycle.
        onTimeRegValue = (uint32_t)pInstance->CCPxPRL + 1;
    }
    else
    {
        onTimeRegValue = (uint32_t)((((uint32_t)(pInstance->CCPxPRL) + 1) * desiredOutputDutyCycle) + 0.5);
    }
    //Make sure we didn't overflow past what the 16-bit register can hold (sometimes possible due to +1 value used above)
    if(onTimeRegValue > 0xFFFF)
    {
        onTimeRegValue = 0xFFFF;        
    }
    
    //Update the PWM duty cycle register to make the change take effect.    
    pInstance->CCPxRA = 0;                 //Time when the output goes high (ex: 0 = start of the period)
    pInstance->CCPxRB = onTimeRegValue;    //Time when the output goes low (until the start of the next period)
}

//Turns off the MCCP/SCCP module.  NOTE: It is the caller's responsibility to correctly have pre-configured
//the LAT/TRIS bits for the GPIO pin which was being used as the output, so that when the module becomes disabled,
//the control reverts to the proper TRIS/LAT settings that the user wants/needs to avoid damage/harm to the 
//application (ex: usually logic low, for non-inverting N-Channel MOSFET drivers).
void SCCP_DisableModule(struct SCCP_INSTANCE *pInstance)
{
    //Clear the CCPxCON1L register, thus disabling the module and forcing it back to default timer mode with no output
    pInstance->CCPxCON1L = 0x0000; //Disable module
}
