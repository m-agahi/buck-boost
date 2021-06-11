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
#include "math.h"

/*
                         Main application
 */
void SOFT_Start(void)
{
    PWM_Initialize(39992, dutyCycleCalculate(39992, 15), MODE_Config(2));
    DELAY_milliseconds(500); // allow the system to enter a steady state
};

float one_Percent(float dutyCyclePercent,float step)
{
    int ADCResult, ADCResultTemp, i, pwmIOConH;
    int mode; // 0 = off, 1 = Buck, 2 = Boost, 3 = Buck-Boost
    unsigned int period, dutyCycle;
    float adconeper;

    period = 39992; // 100 kHz
    dutyCyclePercent = 10; // 80 percent
    mode = 2; // start boost 
    adconeper=0;
    ADCResultTemp = 0;
    pwmIOConH = MODE_Config(mode);
    
    ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT, false, true, true);
    ADC_ChannelEnable(ADC_CHANNEL_FB, 0x1);    //Select alternate input #1 to core 0 
    ADCResult = ADC_Read12bitAverage( ADC_CHANNEL_FB,8 );
    ADCResultTemp = ADCResult;
    
    for (i=0;i<5;i++) // calculate how much 0.01 change in dutycycle changes the output coltage;
    {
        dutyCyclePercent += step; 
        dutyCycle = dutyCycleCalculate(period, dutyCyclePercent);
        PWM_Initialize(period, dutyCycle, pwmIOConH);
        DELAY_milliseconds(1);
        ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT, false, true, true);
        ADC_ChannelEnable(ADC_CHANNEL_FB, 0x1);    //Select alternate input #1 to core 0 
        ADCResult = ADC_Read12bitAverage( ADC_CHANNEL_FB,8 );
        adconeper += abs(ADCResultTemp - ADCResult);
        ADCResultTemp = ADCResult;
    };
    adconeper /= 6; // for each 0.01 percent an average of adconeper will be generated in the output;
    adconeper *= 100; // for each 1 percent an average of adconeper will be generated in the output;
    
    return adconeper;
};

int main(void)
{
    int ADCResult, ADCResultTemp, ADCRef, ADCRefHighLimit, ADCRefLowLimit, margin, gain, pwmIOConH;
    int mode; // 0 = off, 1 = Buck, 2 = Boost, 3 = Buck-Boost
    unsigned int period, dutyCycle;
    float adconeper, dutyCyclePercent,dutyCyclePercentDiff,dutyCyclePercentStep;
    
    SYSTEM_Initialize();
    SOFT_Start();

    period = 39992; // 100 kHz
    dutyCyclePercent = 10; // Initial Duty Cycle
    ADCRef = 3510;
    margin = 10;
    ADCRefHighLimit = ADCRef + margin;
    ADCRefLowLimit = ADCRef - margin;
    mode = 2; // start boost 
    gain = 1;
    adconeper=0;
    ADCResultTemp = 0;
    pwmIOConH = MODE_Config(mode);

    ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT, false, true, true);
    ADC_ChannelEnable(ADC_CHANNEL_FB, 0x1);    //Select alternate input #1 to core 0 
    adconeper = one_Percent(dutyCyclePercent,0.01);
   
    LED_Indication(mode);
    while (1)
    {
        ADCResult = ADC_Read12bitAverage( ADC_CHANNEL_FB,8 );
        dutyCyclePercentDiff = abs(ADCRef - ADCResult)/adconeper;
        if ( ADCResult < ADCRefLowLimit ) //3394
        {
            dutyCyclePercent += dutyCyclePercentDiff;
            dutyCycle = dutyCycleCalculate(period, dutyCyclePercent);
            PWM_Initialize(period, dutyCycle, pwmIOConH);
        }
        else if ( ADCResult > ADCRefHighLimit)
        {
            dutyCyclePercent -= dutyCyclePercentDiff;
            dutyCycle = dutyCycleCalculate(period, dutyCyclePercent);
            PWM_Initialize(period, dutyCycle, pwmIOConH);
        }
        
        ADCResult = ADC_Read12bitAverage( ADC_CHANNEL_FB,8 );
        gain = log10(abs(ADCRef - ADCResult));
        dutyCyclePercentStep = ((gain+1)*0.01);
        if ( ADCResult < ADCRefLowLimit ) //3394??
        {
            dutyCyclePercent += dutyCyclePercentStep;
            dutyCycle = dutyCycleCalculate(period, dutyCyclePercent) + (margin/2);
            PWM_Initialize(period, dutyCycle, pwmIOConH);
        }
        else if ( ADCResult > ADCRefHighLimit )
        {
            dutyCyclePercent -= dutyCyclePercentStep;
            dutyCycle = dutyCycleCalculate(period, dutyCyclePercent) - (margin/2) ;
            PWM_Initialize(period, dutyCycle, pwmIOConH);
        }
    }
    return 1; 
}
/**
 End of File
*/

