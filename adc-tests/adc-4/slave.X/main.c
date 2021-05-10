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
#define    FCY    16000000UL    // Instruction cycle frequency, Hz - required for __delayXXX() to work
#include <libpic30.h>        // __delayXXX() functions macros defined here
/*
                         Main application
 */
int main(void)
{
    int highOutputPin, lowOutputPin, pwmIOConH, DTCMPSELReg, PMODReg;
    int ADCResult, Q2, Q6;
    unsigned int period, dutyCycle;
    //enum ADC1_CHANNEL ADCChannel = channel_S1AN0;
    
    // initialize the device
    SYSTEM_Initialize();
    
    int operationMode = 1; // 0: off, 1: buck, 2: boost, 3: buck-boost
    
    switch (operationMode)
    {
        case 0:
            highOutputPin = 0; // PIN C14
            lowOutputPin = 0; // PIN C15
            Q6 = 0; // OFF
            Q2 = 0; // OFF
            break;
        case 1:
            highOutputPin = 1; // PIN C14
            lowOutputPin = 0; // PIN C15
            Q6 = 2; // PWM
            Q2 = 0; // OFF
            break;
        case 2:
            highOutputPin = 0; // PIN C14
            lowOutputPin = 1; // PIN C15
            Q6 = 1; // ON
            Q2 = 2; // PWM
            break;
        case 3:
            highOutputPin = 1; // PIN C14
            lowOutputPin = 1; // PIN C15
            Q6 = 2; // PWM
            Q2 = 2; // PWM
            break;
    }
    
    
    int dutyCycleCalculate (unsigned int periodTemp, float percent)
    {
        unsigned int onePercent;
        unsigned int dutyCycleTemp;
        onePercent = (periodTemp + 8) / 100;
        dutyCycleTemp = (int)(onePercent * percent);
        return (dutyCycleTemp);
    }
    
   
    
    
    //period = 39992; // 100 kHz
    period = 39992; // 100 kHz
    //dutyCycle = 7.65; // for 6.37 V output with boost mode
    dutyCycle = 80;
    dutyCycle = dutyCycleCalculate(period, dutyCycle);  

    
    
    
    
    
    
    //dutyCycle = 3060; //6.6?
    //dutyCycle = 38000;

    DTCMPSELReg=1; // Dead-time compensation is controlled by PCI feed-forward limit logic
    PMODReg= 1; // PWM Generator outputs operate in Independent mode
    _LATE0 = 0;
    _LATE1 = 0;

    pwmIOConH = (PMODReg << 4) + (highOutputPin << 3) + (lowOutputPin << 2) + (DTCMPSELReg << 7);
    PWM_Initialize(period, dutyCycle, pwmIOConH);
    
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
    
    
    ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT, false, true, true);
    ADC_ChannelEnable(ADC_CHANNEL_FB, 0x1);    //Select alternate input #1 to core 0 
    //ADC_ChannelEnable(ADC_CHANNEL_VIN_FB, false);
    //ADC_ChannelInterruptConfig(ADC_CHANNEL_BUCK_FB, 6, 13);
    //ADC_ChannelInterruptConfig(ADC_CHANNEL_VIN_FB, 4, 13);          //Triggered from same source as buck output, ISR priority not used as read from same ISR
    //ADC_ChannelInterruptEnable(ADC_CHANNEL_BUCK_FB); 
    //ADC_ChannelInterruptEnable(ADC_CHANNEL_FB);     


    while (1)
    {
        // Add your application code
        //if (ADC1_IsConversionComplete( ADCChannel ))
        //{
            ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT, false, true, true);
            ADC_ChannelEnable(ADC_CHANNEL_FB, 0x1);    //Select alternate input #1 to core 0 
            ADCResult = ADC_Read12bit( ADC_CHANNEL_FB );
            

            
        //}
            
        ADCResult = dutyCycle;
        
        if ( ADCResult <= 1024 )
        {
            _LATE0 = 0;
            _LATE1 = 0;
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
            _LATE0 = 1;
            _LATE1 = 1;
        }
        
        
        //Enable and configure the ADC so it can sample the output/input voltages.
    
        
        
        
        
        __delay_ms(500)
            _LATE0 = 0;
            _LATE1 = 0;
        
        __delay_ms(500)

    }
    return 1; 
}
/**
 End of File
*/

