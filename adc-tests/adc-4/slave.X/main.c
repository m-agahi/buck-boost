/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  dsPIC33CH512MP508S1
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB 	          :  MPLAB X v5.45
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pwm.h"
#include "mcc_generated_files/adc1.h"
#define    FCY    8000000UL    // Instruction cycle frequency, Hz - required for __delayXXX() to work
#include <libpic30.h>        // __delayXXX() functions macros defined here
/*
                         Main application
 */
int main(void)
{
    int highOutputPin, lowOutputPin, pwmIOConH, period, dutyCycle,DTCMPSELReg, PMODReg;
    int ADCResult;
    enum ADC1_CHANNEL ADCChannel = channel_S1AN2;
    
    // initialize the device
    SYSTEM_Initialize();
    
    highOutputPin = 0; // PIN C14
    lowOutputPin = 1; // PIN C15
    period = 39992;
    dutyCycle = 3060;
    DTCMPSELReg=1; // Dead-time compensation is controlled by PCI feed-forward limit logic
    PMODReg= 1; // PWM Generator outputs operate in Independent mode
    _LATE0 = 0;
    _LATE1 = 0;
    

    pwmIOConH = (PMODReg << 4) + (highOutputPin << 3) + (lowOutputPin << 2) + (DTCMPSELReg << 7);
    PWM_Initialize(period, dutyCycle, pwmIOConH);
    


    while (1)
    {
        // Add your application code
        if (ADC1_IsConversionComplete( ADCChannel ))
        {
            ADCResult = ADC1_ConversionResultGet( ADCChannel );
        }
        
        if ( ADCResult <= 1024 )
        {
            _LATE0 = 1;
            _LATE1 = 1;
        }
        else if (ADCResult <= 2048)
        {
            _LATE0 = 0;
            _LATE1 = 1;
        }
        else if (ADCResult <= 3072)
        {
            _LATE0 = 1;
            _LATE1 = 0;
        }
        else
        {
            _LATE0 = 0;
            _LATE1 = 0;
        }
    }
    return 1; 
}
/**
 End of File
*/

