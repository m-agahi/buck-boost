/*
 * File:   main.c
 * Author: max
 *
 * Created on February 12, 2021, 3:19 PM
 */


#include "xc.h"
#include "pins.h"
#include <stdbool.h>

#define LED_LED1_LAT      LATEbits.LATE0
#define LED_LED2_LAT      LATEbits.LATE1

#define LED_LED1_TRIS     TRISEbits.TRISE0
#define LED_LED2_TRIS     TRISEbits.TRISE1
#define LED1212     TRISEbits.TRISE0


#define LED_ON  1
#define LED_OFF 0

#define INPUT  1
#define OUTPUT 0

//#include <libpic30.h>

void SYSTEM_Initialize(void)
{
    //Switch to FRC (no divider, no PLL), assuming we aren't already running from that.
    if(OSCCONbits.COSC != 0b000)
    {
        __builtin_write_OSCCONH(0x00);  //NOSC = 0b000 = FRC without divider or PLL
        __builtin_write_OSCCONL((OSCCON & 0x7E) | 0x01);  //Clear CLKLOCK and assert OSWEN = 1 to initiate switchover
        //Wait for switch over to complete.
        while(OSCCONbits.COSC != OSCCONbits.NOSC);
    }
    
    // Configure PLL prescaler, both PLL postscalers, and PLL feedback divider
    CLKDIVbits.PLLPRE = 1;      // N1=1
    PLLFBDbits.PLLFBDIV = 160;  // M = 160 (ex: FVCO = 1280MHz = 8MHz * 160)
    PLLDIVbits.POST1DIV = 4;    // N2=4 (1280MHz / 4, followed by /2 (N3), followed by fixed / 2 = 80MHz)
    PLLDIVbits.POST2DIV = 2;    // N3=2
    // Initiate Clock Switch to FRC with PLL (NOSC = 0b001)
    __builtin_write_OSCCONH(0x01);
    if(OSCCONbits.COSC != OSCCONbits.NOSC)
    {
        __builtin_write_OSCCONL((OSCCON & 0x7F) | 0x01);    //Assert OSWEN and make sure CLKLOCK is clear, to initiate the switching operation
        // Wait for clock switch to finish
        while(OSCCONbits.COSC != OSCCONbits.NOSC);    
    }
    
    MSI1CONbits.MTSIRQ = 0;


}
int main(void)
{
   // SYSTEM_Initialize();
    for (;;)
    {
        //LED1212=1;
        LED_LED1_LAT=1;
    }
    return 0;
}
