////////////////////////////////////////////////////////////////////////////////
// © 2015 Microchip Technology Inc.
//
// MICROCHIP SOFTWARE NOTICE AND DISCLAIMER:  You may use this software, and any 
//derivatives, exclusively with Microchip?s products. This software and any 
//accompanying information is for suggestion only.  It does not modify Microchip?s 
//standard warranty for its products.  You agree that you are solely responsible 
//for testing the software and determining its suitability.  Microchip has no 
//obligation to modify, test, certify, or support the software.
//
// THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER EXPRESS,
//IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF
//NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE, OR ITS 
//INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE 
//IN ANY APPLICATION.
 
//IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL 
//OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE 
//SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR 
//THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S 
//TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED 
//THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

//MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE TERMS. 

////////////////////////////////////////////////////////////////////////////////


#ifndef COMPENSATOR_INIT_H
#define COMPENSATOR_INIT_H

#include "smps_control.h"
#include "buck_dcdt_v1.h"
#include "pwm.h"
#include "pdm_dac.h"
#include "adc.h"

// Output Voltage Setpoint        
#define BUCKVOLTAGEREFERENCE   3.3   // Buck output voltage in volts (max 3.8V with on-board load)        

#define ADCRESOLUTION  1241      // 4096/3.3V

//buck feedback gains   
#define VBUCKFBGAIN   0.54808   // 1k/(1k+825) (J13 connected)

#define BUCKVOLTAGEREFERENCEADC (unsigned int)(VBUCKFBGAIN*ADCRESOLUTION*BUCKVOLTAGEREFERENCE)
#define BUCK_FB_LOOP_CHECK  (BUCKVOLTAGEREFERENCEADC>>2)
#define BUCKINCREMENT 10

#define SOFTSTART_FAULTCNT 3
// Clear error history arrays at initialization

#define MACRO_CLR_BUCKHISTORY()     \
        buckErrorControlHistory[0] = 0;  \
        buckErrorControlHistory[1] = 0;  \
        buckErrorControlHistory[2] = 0;  \
        buckErrorControlHistory[3] = 0;


void SOFTSTART_BuckTask(void);
void INIT_BuckComp(void);
void INIT_BuckDrive(void);

#endif	/* COMPENSATOR_INIT_H */

