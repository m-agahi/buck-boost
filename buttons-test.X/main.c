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
 * File:   main.c
 * Author: max
 *
 * Created on February 13, 2021, 12:30 PM
 */



#include "xc.h"
#include <p33CH512MP508.h>

#define    FCY    16000000UL    // Instruction cycle frequency, Hz - required for __delayXXX() to work
#include <libpic30.h>        // __delayXXX() functions macros defined here

int main(void)
{
    int s1;
    int s2;
    
    while (1)
    {
        s1=_LATE7;
        s2=_LATE8;
        if (s1==1)
        {
            _RE0=1;
        }
        __delay_ms(100);
    }
    return 0;
}
