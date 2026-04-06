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
        Device            :  dsPIC33CH512MP508
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
#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/pwm.h"
#include "mcc_generated_files/pin_manager.h"

#define    FCY    8000000UL    // Instruction cycle frequency, Hz - required for __delayXXX() to work
#include <libpic30.h>        // __delayXXX() functions macros defined here

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    ADC1_Enable();
    ADC1_ChannelSelect( channel_AN0 );
    int i,j;
    
    
    int potentiometer,temp_Potentiometer,frequency,duty_Cycle,duty_Cycle_A;
    while (1)
    {
        // Add your application code
        /*if (ADC1_IsConversionComplete(channel_AN0))
        {
            potentiometer = ADC1_ConversionResultGet( channel_AN0 );
            
            frequency = potentiometer;
            duty_Cycle = potentiometer/2;
            duty_Cycle_A = 0;
            if ( temp_Potentiometer != potentiometer )
            {
                PWM_Initialize_2(frequency,duty_Cycle,duty_Cycle_A);
                temp_Potentiometer = potentiometer;
                
                IO_RE0_Toggle();
                __delay_ms(100);
                IO_RE0_Toggle();
                __delay_ms(100);
            };
        };
        //for (i=0;i<4096;i++)
        {
            frequency = (1000000/(i*20));
            for (j=0;j<500;j+=50)
            {
                duty_Cycle = j;
                duty_Cycle_A = 0;
                PWM_Initialize_2(frequency,duty_Cycle,duty_Cycle_A);
                __delay_ms(1000);
            };
            __delay_ms(1000);
        };*/
    }
    return 1; 
}
/**
 End of File
*/

