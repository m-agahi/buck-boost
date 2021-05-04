/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

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





#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "leds.h"
#include "buttons.h"
#include "leds_rgb.h"
#include "adc.h"
#include "timer_1ms.h"
#include "system.h"
#include "debounce.h"
#include "msi.h"
#include "uart1.h"


#pragma message "Connect USB-UART port on board to your PC and set COM port to: 230400 baud, 8-bit, 1 stop."

//------------------------------------------------------------------------------
//Application related definitions
//------------------------------------------------------------------------------
#define BUTTON_DEBOUCE_TIME_MS      20

typedef enum
{
    BUTTON_COLOR_RED = 0,
    BUTTON_COLOR_GREEN = 1,
    BUTTON_COLOR_BLUE = 2
} BUTTON_COLOR;


//------------------------------------------------------------------------------
//Private prototypes
//------------------------------------------------------------------------------
static void ChangeColor(void);

//------------------------------------------------------------------------------
//Global variables
//------------------------------------------------------------------------------
static volatile BUTTON_COLOR buttonColor = BUTTON_COLOR_RED;
static volatile bool transientLoadTestEnabled = false;

void ButtonS1Callback(bool pressed)
{
    if(pressed == true)
    {
        ChangeColor();
        LED_On(LED_LED1);
    }
    else
    {
        LED_Off(LED_LED1);
    }
}

void ButtonS2Callback(bool pressed)
{
    if(pressed == true)
    {
        ChangeColor();
        LED_On(LED_LED2);
    }
    else
    {
        LED_Off(LED_LED2);
    }
}

void ButtonS3Callback(bool pressed)
{
    if(pressed == true)
    {
        transientLoadTestEnabled = !transientLoadTestEnabled;
        
        while(MSI_EnableTransientLoad(transientLoadTestEnabled) == false)
        {
        }
    }
}


//------------------------------------------------------------------------------
//Main Function
//------------------------------------------------------------------------------
int main(void)
{
    uint16_t potentiometer = 0;
    
    uint16_t red = 512, green = 256, blue = 100;
    
    struct debounced_button *button_s1, *button_s2, *button_s3;
    
    float buckVoltage = 0, inputVoltage = 0;
    
    SYSTEM_Initialize();
            
    buttonColor = BUTTON_COLOR_RED;
    transientLoadTestEnabled = false;
    
    //Configure the pushbutton pins as digital inputs.
    BUTTON_Enable(BUTTON_S1);
    BUTTON_Enable(BUTTON_S2);
    BUTTON_Enable(BUTTON_S3);

    //Configure and enable the I/O pins controlling the general purpose LEDs, and 
    //the PWM outputs controlling the RGB LED.
    LED_Enable(LED_LED1);
    LED_Enable(LED_LED2);
    
    LED_RGB_Enable(LED_RGB_LD3);
    
    //Enable and configure the ADC so it can sample the potentiometer.
    ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT);
    ADC_ChannelEnable(ADC_CHANNEL_POTENTIOMETER);
    
    //Turn on a timer, so to generate periodic interrupts.
    TIMER_SetConfiguration(TIMER_CONFIGURATION_1MS);

    DEBOUNCE_Initialize();
    
    button_s1 = DEBOUNCE_AddButton(&BUTTON_S1_IsPressed);
    button_s2 = DEBOUNCE_AddButton(&BUTTON_S2_IsPressed);
    button_s3 = DEBOUNCE_AddButton(&BUTTON_S3_IsPressed);
       
    DEBOUNCE_SetCallback(button_s1, &ButtonS1Callback);
    DEBOUNCE_SetCallback(button_s2, &ButtonS2Callback);
    DEBOUNCE_SetCallback(button_s3, &ButtonS3Callback);
    
    TIMER_RequestTick(&DEBOUNCE_Tasks, 1);   
    
    printf("\033[2J");      //Clear screen
    printf("\033[0;0f");    //return cursor to 0,0
    printf("\033[?25l");    //disable cursor
    
    printf("------------------------------------------------------------------\r\n");
    printf("dsPIC33CH Curiosity Demo\r\n");
    printf("------------------------------------------------------------------\r\n");
    printf("S1 - controls LED1, changes active RGB color\r\n");
    printf("S2 - controls LED2, changes active RGB color\r\n");
    printf("S3 - enable/disable transient load test\r\n");
    printf("Potentiometer - controls active RGB color intensity\r\n");
    printf("\r\n");
    
    while(1)
    {
        printf("\033[9;0f");    //move cursor to row 8, column 0
        
        potentiometer = ADC_Read12bitAverage(ADC_CHANNEL_POTENTIOMETER, 20);
        
        printf("Potentiometer Value: %4d\r\n", potentiometer);
        printf("\r\n");
        
        //Use the potentiometer ADC value to set the brightness of the currently
        //selected color channel on the RGB LED.  The "currently selected channel"
        //is manually selected by the user at runtime by pressing the pushbuttons.
        switch(buttonColor)
        {
            case BUTTON_COLOR_RED:
                red = potentiometer >> 2;
                printf("Active Color: red  \r\n");
                break;

            case BUTTON_COLOR_GREEN:
                green = potentiometer >> 2;
                printf("Active Color: green\r\n");
                break;

            case BUTTON_COLOR_BLUE:
                blue = potentiometer >> 2;
                printf("Active Color: blue \r\n");
                break;

            default:
                break;
        }
        
        printf("Current Color: \r\n");
        printf("  Red:   %4d\r\n  Green: %4d\r\n  Blue:  %4d\r\n", red, green, blue);

        LED_RGB_Set(LED_RGB_LD3, red, green, blue);
        
        if(MSI_IsOutputVoltageReady() == true)
        {
            buckVoltage = MSI_ReadOutputVoltage();
        }
        
        if(MSI_IsInputVoltageReady() == true)
        {
            inputVoltage = MSI_ReadInputVoltage();
        }
        
        printf("\r\n");
        printf("Buck/boost output on VOUT test pin:\r\n");
        printf("Output Voltage: %f volts         \r\nInput  Voltage: %f volts          \r\n", (double)buckVoltage, (double)inputVoltage);
        
        printf("\r\n");
        if(transientLoadTestEnabled == true)
        {
            printf("Transient load test: Enabled, load applied for 5ms at 5Hz rate\r\n");
        }
        else
        {
            printf("Transient load test: Disabled                                 \r\n");
        }
    }
}

static void ChangeColor(void)
{         
    switch(buttonColor)
    {
        case BUTTON_COLOR_RED:
            buttonColor = BUTTON_COLOR_GREEN;
            break;

        case BUTTON_COLOR_GREEN:
            buttonColor = BUTTON_COLOR_BLUE;
            break;

        case BUTTON_COLOR_BLUE:
            buttonColor = BUTTON_COLOR_RED;
            break;

        default:
            buttonColor = BUTTON_COLOR_RED;
            break;
    }
}

