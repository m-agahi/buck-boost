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
#include "mcc_generated_files/delay.h"
#include "opmode.h"

/*
                         Main application
 */
int main(void)
{
    
    int buttonPinNumber;
    int pwmIOConH;
    int mode; // 0 = off, 1 = Buck, 2 = Boost, 3 = Buck-Boost
    int previousMode;
    int dutyCyclePercent;
    int ADCResult;
    unsigned int period;
    unsigned int dutyCycle;
    //enum ADC1_CHANNEL ADCChannel = channel_S1AN0;
    
    // initialize the device
    SYSTEM_Initialize();
    
    //dutyCycle = 3060; //6.6?
    //dutyCycle = 38000;
    //dutyCycle = 7.65; // for 6.37 V output with boost mode
    //period = 39992; // 100 kHz
    period = 39992; // 100 kHz
    dutyCyclePercent = 50; // 80 percent
    mode = 2; // start off  
    previousMode = -1; // to make sure that first initialization turns off the PWM
    pwmIOConH = MODE_Config(mode);
    ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT, false, true, true);
    ADC_ChannelEnable(ADC_CHANNEL_FB, 0x1);    //Select alternate input #1 to core 0 
    //ADC_ChannelEnable(ADC_CHANNEL_VIN_FB, false);
    //ADC_ChannelInterruptConfig(ADC_CHANNEL_BUCK_FB, 6, 13);
    //ADC_ChannelInterruptConfig(ADC_CHANNEL_VIN_FB, 4, 13);          //Triggered from same source as buck output, ISR priority not used as read from same ISR
    //ADC_ChannelInterruptEnable(ADC_CHANNEL_BUCK_FB); 
    //ADC_ChannelInterruptEnable(ADC_CHANNEL_FB);     


    while (1)
    {
        //if (ADC1_IsConversionComplete( ADCChannel ))
        //{
            ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT, false, true, true);
            ADC_ChannelEnable(ADC_CHANNEL_FB, 0x1);    //Select alternate input #1 to core 0 
            ADCResult = ADC_Read12bit( ADC_CHANNEL_FB );
        //}        
 
        /*    
        buttonPinNumber = READ_Buttons();
        switch (buttonPinNumber)
        {
            case 1:
                mode++;
                break;
            case 2:
                dutyCyclePercent++;
                previousMode = -1; // to make sure that the new DC will apply
                break;
            case 3:
                dutyCyclePercent--;
                previousMode = -1; // to make sure that the new DC will apply
                break;
        }
        */
        
            
        LED_Indication(mode);
        
        /*
        // rotating the modes
        if (mode > 3)
        {
            mode = 0;
        };
        */
        
        /*
        // prevent the circuit to go beyond limits;
        if (dutyCyclePercent > 99)
        {
            dutyCyclePercent = 99;
        };
        if (dutyCyclePercent < 1)
        {
            dutyCyclePercent = 1;
        };
        */
                
        if ( ADCResult < 3295 ) //3394
        {
            dutyCycle = dutyCycleCalculate(period, ++dutyCyclePercent);
            PWM_Initialize(period, dutyCycle, pwmIOConH);
        }
        else if ( ADCResult > 3305 )
        {
            dutyCycle = dutyCycleCalculate(period, --dutyCyclePercent);
            PWM_Initialize(period, dutyCycle, pwmIOConH);
        }
        
        //DELAY_milliseconds(200);    

    }
    return 1; 
}
/**
 End of File
*/

