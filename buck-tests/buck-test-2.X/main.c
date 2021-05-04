/*
 * File:   main.c
 * Author: max
 *
 * Created on February 24, 2021, 7:40 PM
 */



//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//    smps_2p2z_dspic_v2.s  ????




//main.c
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <xc.h>
#include <p33CH512MP508.h>
//#include <p33CH512MP508S1.h>

//#include "msi.h"  //added
//#include "system.h" // added
//#include "transient_load.h" //added
//#include "timer_1ms.h" //added
//#include "compensator_init.h" //added
//#include "smps_control.h" //added
//#include "buck_dcdt_v1.h" //added
//#include "pwm.h" //added
//#include "pdm_dac.h"
//#include "adc.h" //added


//msi.h
bool MSI_SendOutputVoltage(uint16_t outputVoltage);
bool MSI_SendInputVoltage(uint16_t inputVoltage);

//system.h
#ifndef SYSTEM_H
#define SYSTEM_H

void SYSTEM_Initialize(void);

#endif

//transient_load.h
#ifndef TRANSIENT_LOAD_H
#define TRANSIENT_LOAD_H

void TRANSIENT_LOAD_Initialize(void);
void TRANSIENT_LOAD_Tasks(void);
void TRANSIENT_LOAD_Enable(void);
void TRANSIENT_LOAD_Disable(void);
void TRANSIENT_LOAD_SetOnTime(uint16_t milliseconds);
void TRANSIENT_LOAD_SetPeriod(uint16_t milliseconds);
void TRANSIENT_LOAD_SetCurrent(int16_t currentDuringTransient);

#endif

//timer_1ms.h
#ifndef TIMER_1MS
#define TIMER_1MS

#define TIMER_TICK_INTERVAL_MICRO_SECONDS 1000

/* Type Definitions ***********************************************/
typedef void (*TICK_HANDLER)(void);

typedef enum
{
    TIMER_CONFIGURATION_1MS,
    TIMER_CONFIGURATION_OFF
} TIMER_CONFIGURATIONS;

/*********************************************************************
* Function: void TIMER_CancelTick(TICK_HANDLER handle)
*
* Overview: Cancels a tick request.
*
* PreCondition: None
*
* Input:  handle - the function that was handling the tick request
*
* Output: None
*
********************************************************************/
void TIMER_CancelTick(TICK_HANDLER handle);

/*********************************************************************
* Function: bool TIMER_RequestTick(TICK_HANDLER handle, uint32_t rate)
*
* Overview: Requests to receive a periodic event.
*
* PreCondition: None
*
* Input:  handle - the function that will be called when the time event occurs
*         rate - the number of ticks per event.
*
* Output: bool - true if successful, false if unsuccessful
*
********************************************************************/
bool TIMER_RequestTick(TICK_HANDLER handle, uint32_t rate);

/*********************************************************************
* Function: bool TIMER_SetConfiguration(TIMER_CONFIGURATIONS configuration)
*
* Overview: Initializes the timer.
*
* PreCondition: TIMER_CONFIGURATIONS - configuration to run
*
* Input:  None
*
* Output: bool - true if successful, false if unsuccessful
*
********************************************************************/
bool TIMER_SetConfiguration(TIMER_CONFIGURATIONS configuration);

#endif //TIMER_1MS

//compensator.h
#ifndef COMPENSATOR_INIT_H
#define COMPENSATOR_INIT_H

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

//smps_control.h
/**************************************************************************
  Company:
    Microchip Technology Inc.
  File Name:
    smps_interfaces.h


  Summary:
    This header file lists the interfaces used by the Switch Mode Power
    Supply compensator library.


  Description:
    SMPS Control (Compensator) library interface header file

    This header file lists the type defines for structures used by the SMPS
    library. Library function definitions are also listed along with
    information regarding the arguments of each library function.
  **************************************************************************/
//smps_control.h
// DOM-IGNORE-BEGIN
////////////////////////////////////////////////////////////////////////////////
// © 2015 Microchip Technology Inc.
//
// MICROCHIP SOFTWARE NOTICE AND DISCLAIMER:  You may use this software, and any
// derivatives created by any person or entity by or on your behalf, exclusively
// with Microchip?s products.  Microchip and its licensors retain all ownership
// and intellectual property rights in the accompanying software and in all
// derivatives here to.
//
// This software and any accompanying information is for suggestion only.  It
// does not modify Microchip?s standard warranty for its products.  You agree
// that you are solely responsible for testing the software and determining its
// suitability.  Microchip has no obligation to modify, test, certify, or
// support the software.
//
// THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER
// EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED
// WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR
// PURPOSE APPLY TO THIS SOFTWARE, ITS INTERACTION WITH MICROCHIP?S PRODUCTS,
// COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.
//
// IN NO EVENT, WILL MICROCHIP BE LIABLE, WHETHER IN CONTRACT, WARRANTY, TORT
// (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), STRICT LIABILITY,
// INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, PUNITIVE,
// EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF
// ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWSOEVER CAUSED, EVEN IF
// MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.
// TO THE FULLEST EXTENT ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
// CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF
// FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
//
// MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
// TERMS.
////////////////////////////////////////////////////////////////////////////////
// DOM-IGNORE-END
//smps_control.h
#ifndef _SMPS_CONTROL_H		// Guards against multiple inclusion
#define _SMPS_CONTROL_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

//**************************************************************************
/* Data type for the 3-pole 3-zero (3P3Z) controller

  Summary:
    Data type for the 3-pole 3-zero (3P3Z) controller

  Description:
    The 3P3Z controller is the digital implementation of the analog type III
    controller. This is a filter which generates a compensator characteristic
    considering three poles and three zeros. This controller requires four
    feedback errors multiplied by their associated coefficients plus the three
    latest controller output values multiplied by their associated coefficients
    along the delay line to provide proper compensation of the power converter.
    The coefficients are determined externally using simulation tools.

    The SMPS_3P3Z_T data structure contains a pointer to derived
    coefficients in X-space and pointer to error/control history samples in
    Y-space. User must declare variables for the derived coefficients and
    the error history samples.

    The abCoefficients referenced by the SMPS_3P3Z_T data structure are
    derived from the coefficients B0-B3 plus A1-A3. These will be declared
    in external arrays. The SMPS_3P3Z_T data structure just holds pointers
    to these arrays.

    The coefficients will be determined by simulation tools, their outputs are
    given as floating point numbers. These numbers will be copied into the
    declared arrays after they have been converted into 16-bit integer numbers.

*/

typedef struct
{
    int16_t*    aCoefficients ;         // Pointer to A coefficients located in X-space
    int16_t*    bCoefficients ;         // Pointer to B coefficients located in X-space
    int16_t*    controlHistory ;	// Pointer to 3 delay-line samples located in Y-space
                                        // with the first sample being the most recent
    int16_t*    errorHistory ;          // Pointer to 4 delay-line samples located in Y-space
                                        // with the first sample being the most recent
    uint16_t    preShift ;		// Normalization from ADC-resolution to Q15 (R/W)
    int16_t     postShift ;		// Normalization bit-shift from Q15 to PWM register resolution (R/W)
    int16_t     postScaler ;		// Controller output post-scaler  (R/W)
    uint16_t    minOutput ;		// Minimum output value used for clamping (R/W)
    uint16_t    maxOutput ;		// Maximum output value used for clamping (R/W)
} SMPS_3P3Z_T;

// *****************************************************************************
/* Data type for the 2-pole 2-zero (2P2Z) controller

  Summary:
	Data type for the 2-pole 2-zero (2P2Z) controller

  Description:
	The 2P2Z controller is the digital implementation of the analog type II
	controller. This is a filter which generates a compensator characteristic
	considering two poles and two zeros. This controller requires three feedback
	error multiplied by their associated coefficients plus the two latest
	controller output values multiplied by their associated coefficients along
	the delay line to provide proper compensation of the power converter.
	The coefficients are determined externally using simulation tools.

    The SMPS_2P2Z_T data structure contains a pointer to derived
    coefficients in X-space and pointer to error/control history samples in
    Y-space. User must declare variables for the derived coefficients and
    the error history samples.

    The abCoefficients referenced by the SMPS_2P2Z_T data structure are
    derived from the coefficients B0-B2 plus A1-A2. These will be declared
    in external arrays. The SMPS_2P2Z_T data structure and just holds
    pointers to these arrays.

    The coefficients will be determined by simulation tools, which output
    is given as floating point numbers. These numbers will be copied into
    the declared arrays after they have been converted into 16-bit integer
    numbers.
*/
typedef struct
{
    int16_t*    aCoefficients ;         // Pointer to A coefficients located in X-space
    int16_t*    bCoefficients ;         // Pointer to B coefficients located in X-space
    int16_t*    controlHistory ;	// Pointer to 2 delay-line samples located in Y-space
                                        // with the first sample being the most recent
    int16_t*    errorHistory ;          // Pointer to 3 delay-line samples located in Y-space
                                        // with the first sample being the most recent
    uint16_t    preShift ;		// Normalization from ADC-resolution to Q15 (R/W)
    int16_t     postShift ;		// Normalization bit-shift from Q15 to PWM register resolution (R/W)
    int16_t     postScaler ;		// Controller output post-scaler  (R/W)
    uint16_t    minOutput ;		// Minimum output value used for clamping (R/W)
    uint16_t    maxOutput ;		// Maximum output value used for clamping (R/W)
} SMPS_2P2Z_T ;

//***********************************************************************
/* Data type for the PID controller

  Summary:
    Data type for the PID controller

  Description:
	Data type for the Proportional Integral Derivative (PID) controller

    This digital implementation of a PID controller is a filter which
    generates a compensator characteristic considering the values of the
    coefficients KA, KB, KC these coefficients will determine the
    converter's frequency response. These coefficients are determined
    externally using simulation tools.

    This function call includes the pointer to the controller data
    structure, pointer of the input source register, control reference
    value, and to the pointer to the output register.
 */
typedef struct {

    int16_t*  abcCoefficients;	// Pointer to A, B & C coefficients located in X-space
                                // These coefficients are derived from
                                // the PID gain values - Kp, Ki and Kd
    int16_t*  errorHistory;	// Pointer to 3 delay-line samples located in Y-space
				            // with the first sample being the most recent
    int16_t  controlHistory;    // Stores the most recent controller output (n-1)
    int16_t  postScaler;	// PID basic Coefficient scaling Factor
    int16_t  preShift ;		// Normalization from ADC-resolution to Q15 (R/W)
    int16_t  postShift;		// Normalization from DSP to PWM register
    uint16_t minOutput;		// Minimum output value used for clamping
    uint16_t maxOutput;		// Maximum output value used for clamping


} SMPS_PID_T;




// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

/************************************************************************
  Function:
    void SMPS_3P3ZInitialize( SMPS_3P3Z_T *controller_data )

  Summary:
    This function clears the SMPS_3P3Z_T data history structure arrays

  Description:
    This function clears the SMPS_3P3Z_T data history structure arrays.
	It's recommended to clear the error-history and controller-history
	arrays before 3P3Z controller implementation.
  Conditions:
    None.
  Input:
    SMPS_3P3Z_T * -  This parameter is a pointer to a SMPS_3P3Z_T type
                     structure
  Return:
    Void.
  Example:
    <code lang="c++">
    SMPS_3P3Z_T controller3P3Z;
    SMPS_3P3ZInitialize(&amp;controller3P3Z);
    </code>

  ************************************************************************/

void SMPS_Controller3P3ZInitialize(SMPS_3P3Z_T *controllerData );

/*****************************************************************************************
  Function:
    \ \


    <code lang="c++">
        void SMPS_Controller3P3ZUpdate(SMPS_3P3Z_T* controllerData,
                                     volatile uint16_t* controllerInputRegister,
                                     int16_t reference,
                                     volatile uint16_t* controllerOutputRegister);
    </code>




  Summary:
    This function calls the SMPS_Controller3P3ZUpdate controller

  Description:
    This function updates the 3P3Z controller and can be called as soon as the
    coefficients have been loaded into their arrays.

  Conditions:
    Before the controller can be used, it has to be initialized. The data
    structure has to be filled by copying the pointers to the coefficient,
    error and controller history arrays to the structure and the physical
    clamping limits of the output value. In the function call pointers to
    the Input source register, reference value, and pointer to the output
    register need to be called.

  Input:
    SMPS_3P3Z_T * controllerData -        This parameter is a pointer to a
                                          SMPS_3P3Z_T type structure<p />
    uint16_t* controllerInputRegister -   This parameter is a pointer to the
                                          \input source register or variable
                                          being tracked by the 3P3Z (e.g.
                                          ADCBUF0).<p />
    int16_t reference -                   This parameter is a signed integer
                                          value that will be used by the
                                          controller as the feedback
                                          reference or set\-point.<p />
    uint16_t* controllerOutputRegister -  This parameter is a pointer to the
                                          Control loop target register of
                                          the calculated result(e.g. PDC1).
  Return:
    void
  Example:
    <code lang="c++">
    int16_t controlReference;
    SMPS_3P3Z_T controller3P3Z;
    SMPS_Controller3P3ZUpdate(&amp;controller3P3Z,&amp;ADCBUF0,controlReference,&amp;PDC1)
    </code>

  *****************************************************************************************/


void SMPS_Controller3P3ZUpdate(SMPS_3P3Z_T* controllerData,
                               volatile uint16_t* controllerInputRegister,
			       int16_t reference,
			       volatile uint16_t* controllerOutputRegister);


/************************************************************************
  Function:
    void SMPS_Controller2P2ZUpdate_HW_Accel( void );

  Summary:
    This function calls the 2-Pole, 2-Zero compensator/controller.

  Description:
    This function updates the duty cycle register (PDCx) once every function call.
    There are three options via the structure SMPS_Controller_Options_T which allows the user
    to select whether the trigger update is enabled. The options are as follows:

    1. No trigger option is selected.

    2. Trigger On-Time is selected:

       Trigger Register = PDCx/2 + Delay

    3. Trigger Off-Time is selected:

       Trigger Register = PDCx + (PTPER - PDCx)/2 + Delay

    It's recommended to clear the error-history and controller-history arrays before
    2P2Z controller implementation.

    Conditions:  For use with the new 'dsPIC33EPGS' parts that have the Alternate
                 Working (Alt-W) register context features.

    Input:       None.
    Return:      Void.

  ************************************************************************/

void SMPS_Controller2P2ZUpdate_HW_Accel(void); // Function prototype for 2P2Z library

/*****************************************************************************************/



/************************************************************************
  Function:
    void SMPS_Controller3P3ZUpdate_HW_Accel( void );

  Summary:
    This function calls the 3-Pole, 3-Zero compensator/controller.

  Description:
    This function updates the duty cycle register (PDCx) once every function call.
    There are three options via the structure SMPS_Controller_Options_T which allows the user
    to select whether the trigger update is enabled. The options are as follows:

    1. No trigger option is selected.

    2. Trigger On-Time is selected:

       Trigger Register = PDCx/2 + Delay

    3. Trigger Off-Time is selected:

       Trigger Register = PDCx + (PTPER - PDCx)/2 + Delay

    It's recommended to clear the error-history and controller-history arrays before
    the calling the 3P23 compensator/controller.

    Conditions:  For use with the new 'dsPIC33EPGS' parts that have the Alternate
                 Working (Alt-W) register context features.

    Input:       None.
    Return:      Void.

  ************************************************************************/

void SMPS_Controller3P3ZUpdate_HW_Accel(void); // Function prototype for 3P3Z library

/*************************************************************************/



/************************************************************************
  Function:
    void SMPS_Controller4P4ZUpdate_HW_Accel( void );

  Summary:
    This function calls the 4-Pole, 4-Zero compensator/controller.

  Description:
    This function updates the duty cycle register (PDCx) once every function call.
    There are three options via the structure SMPS_Controller_Options_T which allows the user
    to select whether the trigger update is enabled. The options are as follows:

    1. No trigger option is selected.

    2. Trigger On-Time is selected:

       Trigger Register = PDCx/2 + Delay

    3. Trigger Off-Time is selected:

       Trigger Register = PDCx + (PTPER - PDCx)/2 + Delay

    It's recommended to clear the error-history and controller-history arrays before
    the calling the 4P4P compensator/controller.

    Conditions:  For use with the new 'dsPIC33EPGS' parts that have the Alternate
                 Working (Alt-W) register context features.

    Input:       None.
    Return:      Void.

  ************************************************************************/
void SMPS_Controller4P4ZUpdate_HW_Accel(void); // Function prototype for 3P3Z library

/*************************************************************************/


/************************************************************************
  Function:
    void SMPS_ControllerPIDUpdate_HW_Accel( void );

  Summary:
    This function calls the PID compensator/controller.

  Description:
    This function updates the duty cycle register (PDCx) once every function call.
    There are three options via the structure SMPS_Controller_Options_T which allows the user
    to select whether the trigger update is enabled. The options are as follows:

    1. No trigger option is selected.

    2. Trigger On-Time is selected:

       Trigger Register = PDCx/2 + Delay

    3. Trigger Off-Time is selected:

       Trigger Register = PDCx + (PTPER - PDCx)/2 + Delay
 
    It's recommended to clear the error-history and controller-history arrays before
    the calling the PID compensator/controller.

    Conditions:  For use with the new 'dsPIC33EPGS' parts that have the Alternate
                 Working (Alt-W) register context features.

    Input:       None.
    Return:      Void.

  ************************************************************************/

void SMPS_ControllerPIDUpdate_HW_Accel(void); // Function prototype for PID library

/*************************************************************************/



typedef struct {

     uint16_t  triggerSelectFlag; // 00 = No Trigger Enabled
	                          // 01 = Trigger On-Time Enabled
			          // 10 = Trigger Off-Time Enabled

     uint16_t                delayValue;      //
     volatile unsigned int*  trigger;         // Pointer to trigger source
     volatile unsigned int*  period;          // Pointer to time base (i.e., PTPER) register

     // User to add additional structure elements as needed
     //             .
     //             .
     //             .

} SMPS_Controller_Options_T; // Converter User Enabled Options



//void SMPS_Controller3P3Z(CONVERTER* controllerData);



/************************************************************************
  Function:
          void SMPS_2P2ZInitialize(void)

  Summary:
    This function clears the SMPS_2P2Z_T data structure arrays

  Description:
    This function clears the SMPS_2P2Z_T data history structure arrays.
	It's recommended to clear the error-history and controller-history
	arrays before 2P2Z controller implementation.

  Conditions:
    None.
  Input:
    SMPS_2P2Z_T* -  This parameter is a pointer to a SMPS_2P2Z_T type
                    structure
  Return:
    void
  Example:
    <code lang="c++">
    SMPS_2P2Z_T controller2P2Z;
    SMPS_Controller2P2ZUpdateInitialize(&amp;controller2P2Z);
    </code>

  ************************************************************************/

void SMPS_Controller2P2ZInitialize(SMPS_2P2Z_T *controllerData);


/*****************************************************************************************
  Function:
    \ \


    <code>
        void SMPS_Controller2P2ZUpdate(SMPS_2P2Z_T* controllerData,
                                       volatile uint16_t* controllerInputRegister,
                                       int16_t reference,
                                       volatile uint16_t* controllerOutputRegister);

    </code>
  Summary:
    This function calls the SMPS_Controller2P2ZUpdate controller

  Description:
    This function updates the 2P2Z controller and can be called as soon as the
	coefficients have been loaded into their arrays.

  Conditions:
    Before the controller can be used, it has to be initialized. The data
    structure has to be filled by copying the pointers to the coefficient,
    error and controller history arrays to the structure and the physical
    clamping limits of the output value. In the function call pointers to
    the Input source register, reference value, and pointer to the output
    register need to be called.
  Input:
    SMPS_2P2Z_T * controllerData -        This parameter is a pointer to a
                                          SMPS_2P2Z_T type structure<p />
    uint16_t* controllerInputRegister -   This parameter is a pointer to the
                                          \input source register or variable
                                          being tracked by the 2P2Z (e.g.
                                          ADCBUF0).<p />
    int16_t reference -                   This parameter is a signed integer
                                          value that will be used by the
                                          controller as the feedback
                                          reference or set\-point.<p />
    uint16_t* controllerOutputRegister -  This parameter is a pointer to the
                                          Control loop target register of
                                          the calculated result(e.g. PDC1).
  Return:
    void
  Example:
    <code lang="c++">
    int16_t controlReference;
    SMPS_2P2Z_T controller2P2Z;
    SMPS_Controller2P2ZUpdate(&amp;controller2P2Z,&amp;ADCBUF0,controlReference,&amp;PDC1)
    </code>

  *****************************************************************************************/

void SMPS_Controller2P2ZUpdate(SMPS_2P2Z_T* controllerData,
                               volatile uint16_t* controllerInputRegister,
                               int16_t reference,
                               volatile uint16_t* controllerOutputRegister);


/****************************************************************************
  Function:
          void SMPS_PIDInitialize( SMPS_PID_T *controller_data )

  Summary:
    This function clears the SMPS_PID_T data structure arrays

  Description:
    This function clears the SMPS_PID_T data history structure arrays.
	It's recommended to clear the error-history and controller-history
	arrays before PID controller implementation.

  Conditions:
    None.
  Input:
    SMPS_PID_T* -  This parameter is a pointer to a SMPS_PID_T type structure
  Return:
    void
  Example:
    <code lang="c++">
    SMPS_PID_T controllerPID;
    SMPS_ControllerPIDUpdateInitialize(&amp;controllerPID);
    </code>

  ****************************************************************************/
void SMPS_ControllerPIDInitialize(SMPS_PID_T *controllerData );

/***************************************************************************************
  Function:
    \ \


    <code>
      void SMPS_ControllerPIDUpdate(SMPS_PID_T* controllerData,
                                   volatile uint16_t* controllerInputRegister,
                                   int16_t reference,
                                   volatile uint16_t* controllerOutputRegister);
    </code>




  Summary:
    This function calls the SMPS_ControllerPIDUpdate controller

  Description:
    This function updates the PID controller and can be called as soon as the
	coefficients have been loaded into their arrays.

  Conditions:
    Before the controller can be used, it has to be initialized. The data
    structure has to be filled by copying the pointers to the coefficient,
    error and controller history arrays to the structure and the physical
    clamping limits of the output value. In the function call pointers to
    the Input source register, reference value, and pointer to the output
    register need to be called.

  Input:
    SMPS_PID_T * controllerData -         This parameter is a pointer to a
                                          SMPS_PID_T type structure<p />
    uint16_t* controllerInputRegister -   This parameter is a pointer to the
                                          \input source register or variable
                                          being tracked by the PID (e.g.
                                          ADCBUF0).<p />
    int16_t reference -                   This parameter is a signed integer
                                          value that will be used by the
                                          controller as the feedback
                                          reference or set\-point.<p />
    uint16_t* controllerOutputRegister -  This parameter is a pointer to the
                                          Control loop target register of
                                          the calculated result(e.g. PDC1).
  Return:
    void
  Example:
    <code lang="c++">
    int16_t controlReference;
    SMPS_PID_T controllerPID;
    SMPS_ControllerPIDUpdate(&amp;controllerPID,&amp;ADCBUF0,controlReference,&amp;PDC1)
    </code>

  ***************************************************************************************/
void SMPS_ControllerPIDUpdate(SMPS_PID_T* controllerData,
                              volatile uint16_t* controllerInputRegister,
                              int16_t reference,
                              volatile uint16_t* controllerOutputRegister);


#ifdef __cplusplus  // Provide C++ Compatibility
    }
#endif

#endif // _SMPS_CONTROL_H
/* EOF */

//buck_dcdf.h
#ifndef _BUCK_DCDT_DEFINES_H
#define _BUCK_DCDT_DEFINES_H

/**
  Compensator Type:  2P2Z
      Entry                Value  
    ---------            ---------
  Pole 0                 6.0420e+03 Hz
  Pole 2                 2.0854e+04 Hz
  Zero 1                 2.0000e+02 Hz
  Gain(Kdc)              1.000
  Warp                   false
  PWM Frequency          3.5000e+05
  PWM Sampling Ratio     2
  Sampling Frequency     1.7500e+05
  PWM Max Resolution     1.0600e-09
  Computational Delay    3.0000e-07
  Control Output Min.    0
  Control Output Max.    4095


  PWM Calculations
      Name                Value  
    ---------           ---------
  Bits of Resolution    12.396
  Gain                  1.855e-04


  s-domain transfer function

               Wp0   Wp2(Wz1 + s)
  H(s) = Kdc X --- X ------------
                s    Wz1(Wp2 + s)

                  3.80e+04   1.31e+05(1.26e+03 + s)
  H(s) = 1.000 X -------- X ----------------------
                     s       1.26e+03(1.31e+05 + s)



  Digital Compensator Coefficients

  Name    Value     Normalized    Q15      Hex
  ----    -----     ----------    ---      ---
  a1      1.455     0.176         5773     0x168D
  a2      -0.455    -0.055        -1805    0xF8F3
  b0      8.259     1.000         32764    0x7FFC
  b1      0.059     0.007         234      0x00EA
  b2      -8.199    -0.993        -32530   0x80EE


  z-domain transfer function

         u(z)  B0 + B1z^(-1) + B2z^(-2)
  H(z) = --- = ------------------------
         e(z)  A0 - A1z^(-1) - A2z^(-2)

          (8.259) + (0.059)z^(-1) + (-8.199)z^(-2)
  H(z) = ---------------------------------------------
          1 - (1.455)z^(-1) - (-0.455)z^(-2)

**/

/* Compensator Coefficient Defines */
// Used for v0.2
//#define BUCK_COMP_2P2Z_COEFF_A1      2867
//#define BUCK_COMP_2P2Z_COEFF_A2      819
//#define BUCK_COMP_2P2Z_COEFF_B0      32767
//#define BUCK_COMP_2P2Z_COEFF_B1      3876
//#define BUCK_COMP_2P2Z_COEFF_B2      -28892
//
//#define BUCK_COMP_2P2Z_POSTSCALER    18202
//#define BUCK_COMP_2P2Z_POSTSHIFT     -4

// Used for v1.0
#define BUCK_COMP_2P2Z_COEFF_A1      9055
#define BUCK_COMP_2P2Z_COEFF_A2      -3366
#define BUCK_COMP_2P2Z_COEFF_B0      32767
#define BUCK_COMP_2P2Z_COEFF_B1      1996
#define BUCK_COMP_2P2Z_COEFF_B2      -30771

#define BUCK_COMP_2P2Z_POSTSCALER    23596
#define BUCK_COMP_2P2Z_POSTSHIFT     -3

//Fc=5kHz, Fp0 = 3kHz, Fz1 = Fc/10, Vin = 4.38
//#define BUCK_COMP_2P2Z_COEFF_A1      22987
//#define BUCK_COMP_2P2Z_COEFF_A2      -8546
//#define BUCK_COMP_2P2Z_COEFF_B0      32767
//#define BUCK_COMP_2P2Z_COEFF_B1      1013
//#define BUCK_COMP_2P2Z_COEFF_B2      -31754
//
//#define BUCK_COMP_2P2Z_POSTSCALER    18588
//#define BUCK_COMP_2P2Z_POSTSHIFT     -2

// Compensator Clamp Limits
#define BUCK_COMP_2P2Z_MIN_CLAMP    0x0000
#define BUCK_COMP_2P2Z_MAX_CLAMP    0x0FFF

#define BUCK_COM_2P2Z_TRG_DLY       50

#endif


//pwm.h    
#ifndef PWM_H
#define	PWM_H

struct PWM_INSTANCE;

//Configures final output conditions for PWM and enabled module
void PWM_InitOutputState(struct PWM_INSTANCE *pInstance, uint8_t PWMOutputMode, bool swapPWMOutput, uint8_t PWMFLData, uint8_t PWMCLData);
//Configures Switching Freq, Duty Cycle, Phase and DT registers 
void PWM_InitTimeBase(struct PWM_INSTANCE *pInstance, uint16_t PWMSwitchingPeriod, int16_t PWMDutyCyclePercentage, uint16_t PWMPhaseShift, uint16_t PWMDeadTimeH, uint16_t PWMDeadTimeL);
//Force update of PWM data registers
void PWM_UpdateOnTime(struct PWM_INSTANCE *pInstance, uint16_t newOnTimeRegisterValue);
//Disable PWM generator
void PWM_DisableModule(struct PWM_INSTANCE *pInstance);

//Option to override PWM manually if fault condition
void PWM_OverrideChannel(struct PWM_INSTANCE *pInstance, bool overrideHighPWM, bool overrideLowPWM, uint8_t overrideData);
//Configure Leading Edge blanking
void PWM_InitLEBState(struct PWM_INSTANCE *pInstance, uint16_t LEBDelay, bool PWMHighRis, bool PWMHighFall, bool PWMLowRis, bool PWMLowFall);
//Configure PWM trigger points
void PWM_InitTrigger(struct PWM_INSTANCE *pInstance, uint16_t triggerA, uint16_t triggerB, uint16_t triggerC);
//Sets PWM trigger to ADC trigger
void PWM_InitADCTrig1(struct PWM_INSTANCE *pInstance, uint8_t pstScaleTrig, bool trigSrcA, bool trigSrcB, bool trigSrcC);
void PWM_InitADCTrig2(struct PWM_INSTANCE *pInstance, bool trigSrcA, bool trigSrcB, bool trigSrcC);
//Configures PWM control interface logic for current limit, doesnt support termination logic only manually terminates when PCI source transitions
void PWM_InitPCILogicCL(struct PWM_INSTANCE *pInstance, bool acceptQaulPol, uint8_t acceptQualSrc, bool pciPol, uint8_t pciSrcSelect, uint8_t pciAcceptCriteria);

#endif	/* PWM_H */

//pdm_dac.h
#ifndef PDM_DAC_H
#define	PDM_DAC_H
//------------------------------------------------------------------------------
//Prototypes
//------------------------------------------------------------------------------
void PDMDAC_Init(uint8_t moduleInstanceNumber, int16_t initialValue, bool AFPLLO500MHzAvailable, bool outputToDACOUTPin);
void PDMDAC_SetValue(uint8_t moduleInstanceNumber, int16_t outputCode);
void PDMDAC_InitTrigger(uint8_t moduleInstanceNumber, uint8_t startSlopeTrigger, uint8_t stopSlopeTriggerB, uint8_t stopSlopeTriggerA);
void PDMDAC_InitDACandCMPWithSlope(uint8_t moduleInstanceNumber, uint32_t moduleClockFreq, double DACReferenceVoltage, uint16_t startingDACLevel, double slopeVoltsPerMicrosecond, uint32_t PWMFrequency, bool invertComparatorOutput, uint8_t INSELFieldValue);

#endif	/* PDM_DAC_H */

//adc.h
#ifndef ADC_H
#define ADC_H

/*** ADC Channel Definitions *****************************************/
#define ADC_CHANNEL_BUCK_FB ADC_CHANNEL_1 //ADC_CHANNEL_13
#define ADC_CHANNEL_VIN_FB  ADC_CHANNEL_15

typedef enum
{
    ADC_CHANNEL_1  = 1,
    ADC_CHANNEL_15 = 15        
} ADC_CHANNEL;

typedef enum
{
    ADC_CONFIGURATION_DEFAULT
} ADC_CONFIGURATION;


/*********************************************************************
* Function: ADC_Read12bit(ADC_CHANNEL channel);
*
* Overview: Reads the requested ADC channel and returns the 12-bit
*           representation of this data.
*
* PreCondition: channel is configured via the ADCConfigure() function
*
* Input: ADC_CHANNEL channel - enumeration of the ADC channels
*        available in this demo.  They should be meaningful names and
*        not the names of the ADC pins on the device (as the demo code
*        may be ported to other boards).
*         i.e. - ADCReadPercentage(ADC_CHANNEL_POTENTIOMETER);
*
* Output: uint16_t - The 12-bit ADC channel conversion value, or 0xFFFF for an 
 *                   error.
*
********************************************************************/
uint16_t ADC_Read12bit(ADC_CHANNEL channel);

void ADC_ChannelInterruptEnable(ADC_CHANNEL channel);

void ADC_ChannelInterruptConfig(ADC_CHANNEL channel, uint8_t channelISRPriority, uint8_t channelISRTrigSRC);


/*********************************************************************
* Function: uint16_t ADC_Read12bitAverage(ADC_CHANNEL channel, uint16_t numberOfSamplesInAverage)
*
* Overview: Repeatedly reads the requested ADC channel and returns a 12-bit
*           representation of the average value returned by the ADC over the
*           sample set.
*
* PreCondition: channel is configured via the ADCConfigure() function
*
* Input: ADC_CHANNEL channel - enumeration of the ADC channels
*        available in this demo.  They should be meaningful names and
*        not the names of the ADC pins on the device (as the demo code
*        may be ported to other boards).
*         i.e. - ADCReadPercentage(ADC_CHANNEL_POTENTIOMETER);
*        uint16_t numberOfSamplesInAverage - the number of samples to take when
*                 computing the average result.  The more the samples, the better
*                 the result quality, but the longer the operation will take.
*
* Output: uint16_t - The 12-bit average ADC channel conversion result value
*
********************************************************************/
uint16_t ADC_Read12bitAverage(ADC_CHANNEL channel, uint16_t numberOfSamplesInAverage);


/*********************************************************************
* Function: bool ADC_ChannelEnable(ADC_CHANNEL channel, ADC_CONFIGURATION configuration);
*
* Overview: Enables specified channel
*
* PreCondition: none
*
* Input: ADC_CHANNEL channel - the channel to enable
*        altInput - What alternate input to connect to core 
*
* Output: bool - true if successfully configured.  false otherwise.
*
********************************************************************/
bool ADC_ChannelEnable(ADC_CHANNEL channel, uint8_t altInput);

/*********************************************************************
* Function: bool ADC_SetConfiguration(ADC_CONFIGURATION configuration)
*
* Overview: Configures the ADC module to specified setting
*
* PreCondition: none
*
* Input: ADC_CONFIGURATION configuration - the mode in which to run the ADC
*
* Output: bool - true if successfully configured.  false otherwise.
*
********************************************************************/
bool ADC_SetConfiguration(ADC_CONFIGURATION configuration, bool enCore0, bool enCore1, bool enSHCore);

#endif  //ADC_H



/****************************************************************************
 * **************************************************************************
 * **************************************************************************
 * **************************************************************************
 * **************************************************************************
 * **************************************************************************
 * **************************************************************************
 * **************************************************************************
 * **************************************************************************
 * **************************************************************************
 ***************************************************************************/

//system.c
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
    
    //Clock switch to 200MHz CPU freq (100MIPs) from FRC+PLL (ex: ((8MHz * 200) / 4) / 2 = 200MHz)
    // Configure PLL prescaler, both PLL postscalers, and PLL feedback divider
    CLKDIVbits.PLLPRE = 1;      // N1=1
    PLLFBDbits.PLLFBDIV = 200;  // M = 200 (ex: FVCO = 1600MHz = 8MHz * 200)
    PLLDIVbits.POST1DIV = 4;    // N2=4 (1600MHz / 4, followed by fixed / 2 = 200MHz)
    PLLDIVbits.POST2DIV = 1;    // N3=1
    // Initiate Clock Switch to FRC with PLL (NOSC = 0b001)
    __builtin_write_OSCCONH(0x01);
    if(OSCCONbits.COSC != OSCCONbits.NOSC)
    {
        __builtin_write_OSCCONL((OSCCON & 0x7F) | 0x01);    //Assert OSWEN and make sure CLKLOCK is clear, to initiate the switching operation
        // Wait for clock switch to finish
        while(OSCCONbits.COSC != OSCCONbits.NOSC);    
    }
    
    //Configures AUX PLL for 500MHz output, from FRC input
    //Use FRC at 8MHz for clock input to AUX PLL.
    ACLKCON1 = 0x0101;      //APLLPRE = 1:1 mode, FRC as input

    //Note: If you uncomment the below, the code assumes that an 8MHz crystal is connected and used as the input to the AUX PLL
    //ACLKCON1 = 0x0001;      //APLLPRE = 1:1 mode, primary oscillator as input

    APLLFBD1 = 125;         //8MHz * 125x = 1.00GHz
    APLLDIV1 = 0x0221;      //AFPLLO = 1GHz / 2 / 1 = 500MHz, with AFVCODIV = (1Ghz VCO) / 2 = 500MHz

    ACLKCON1bits.APLLEN = 1;        //Enable the AUX PLL now
    
    _MSICIE=1;
    
    TRISDbits.TRISD9 = 0; //I/O for AN13 ISR indication
    
    //Define Output Pin
    TRISCbits.TRISC14 = 0;  //Output
    ODCCbits.ODCC14 = 1;    //Open Drain Enabled
}

//transient_load.c
#ifndef TRANSIENT_LOAD_CONFIG_ON_TIME_DEFAULT
#define TRANSIENT_LOAD_CONFIG_ON_TIME_DEFAULT 5
#endif
//transient_load.c
#ifndef TRANSIENT_LOAD_CONFIG_PERIOD_DEFAULT
#define TRANSIENT_LOAD_CONFIG_PERIOD_DEFAULT 200
#endif
//transient_load.c
static bool enabled = false;
static volatile uint16_t millisecondCount = 0;
static uint16_t onTime, period;
static int16_t dutyCycle = 16383;
//transient_load.c
#define TRANSIENT_LOAD_PWM_INSTANCE ((struct PWM_INSTANCE*)&PG2CONL)
#define PWM_OUTPUT_FREQ 800000

//transient_load.c
#ifndef PWM_INPUT_FREQ
#define PWM_INPUT_FREQ 500000000
#endif
//transient_load.c
#define LOAD_TRANSIENT_PWM_PERIOD (uint16_t)(PWM_INPUT_FREQ/PWM_OUTPUT_FREQ)
#define LOAD_TRANSIENT_PWM_DUTY (uint16_t) (LOAD_TRANSIENT_PWM_PERIOD * 0.5)
//PWM Gen I/O Control
#define LOAD_TRANSIENT_PWM_MODE 1       //0-Comp, 1-Independent, 2-Push/Pull
#define LOAD_TRANSIENT_PWM_H_EN 0       // 0-Dis
#define LOAD_TRANSIENT_PWM_L_EN 1       // 1-EN
#define LOAD_TRANSIENT_PWM_H_INV 0
#define LOAD_TRANSIENT_PWM_L_INV 0
#define LOAD_TRANSIENT_WRITE_IOCONTROL ((LOAD_TRANSIENT_PWM_MODE<<4) | (LOAD_TRANSIENT_PWM_H_EN << 3) | (LOAD_TRANSIENT_PWM_L_EN << 2) | (LOAD_TRANSIENT_PWM_H_INV << 1) | (LOAD_TRANSIENT_PWM_L_INV))
//transient_load.c
static void LoadAttach(void)
{
    LATCbits.LATC13 = 1;
}
//transient_load.c
static void LoadDetach(void)
{
    LATCbits.LATC13 = 0;
}
//transient_load.c
void TRANSIENT_LOAD_Initialize(void)
{
    /* Load attach pin set to output. */
    TRISCbits.TRISC13 = 0;
    
    enabled = false;
    millisecondCount = 0;
    onTime = TRANSIENT_LOAD_CONFIG_ON_TIME_DEFAULT;
    period = TRANSIENT_LOAD_CONFIG_PERIOD_DEFAULT;
    
    LoadDetach();
}
//transient_load.c
void TRANSIENT_LOAD_Tasks(void)
{
    if(enabled == true)
    {
        if(millisecondCount == 0)
        {
            LoadAttach();
        }
        else if (millisecondCount == onTime)
        {
            LoadDetach();
        }
        
        millisecondCount++;
        
        if (millisecondCount >= period)
        {
            millisecondCount = 0;
        }
    }
}
//transient_load.c
void TRANSIENT_LOAD_SetOnTime(uint16_t milliseconds)
{
    onTime = milliseconds;
}
//transient_load.c
void TRANSIENT_LOAD_SetPeriod(uint16_t milliseconds)
{
    period = milliseconds;
}
//transient_load.c
void TRANSIENT_LOAD_SetCurrent(int16_t currentDuringTransient)
{    
    //Enable the PWM for setting the current during the transient.  Approximate
    //current versus duty cycle is measured as follows (but varies somewhat between boards,
    //and across temperature due to BJT VBE forward voltage and resistor tolerances).
    //As measured on one board at room temp:
    //15% duty = ~800mA
    //47% duty = ~415mA
    //49% duty = ~400mA
    //50% duty = ~390mA
    //60% duty = ~270mA
    //70% duty = ~145mA
    //80% duty = ~30mA
    //85%+ duty = 0mA
    //So: current is ~= -12mA/+1% duty cycle change
    //Desired Duty ~= 1.00 - (Desired Current (A) / 1.2) - 0.17
    //dutyCycle = (float)1.00 - (currentDuringTransient / 1.2) - 0.17;

    dutyCycle = 27197 - (__builtin_mulss(currentDuringTransient, 27306) >> 15);

}
//transient_load.c
void TRANSIENT_LOAD_Enable(void)
{
    PWM_InitTimeBase(TRANSIENT_LOAD_PWM_INSTANCE, LOAD_TRANSIENT_PWM_PERIOD, dutyCycle, 0x0, 0x0, 0x0);
    PWM_InitOutputState(TRANSIENT_LOAD_PWM_INSTANCE, LOAD_TRANSIENT_WRITE_IOCONTROL, false, 0x0, 0x0);   //Output onto S1PWM2L pin, active high signal
    enabled = true;
}
//transient_load.c
void TRANSIENT_LOAD_Disable(void)
{
    enabled = false;
    millisecondCount = 0;
    LoadDetach();
    PWM_DisableModule(TRANSIENT_LOAD_PWM_INSTANCE);
}




//timer_1ms.c
/* Compiler checks and configuration *******************************/
#ifndef TIMER_MAX_1MS_CLIENTS
    #define TIMER_MAX_1MS_CLIENTS 10
#endif
//timer_1ms.c
/* Type Definitions ************************************************/
typedef struct
{
    TICK_HANDLER handle;
    uint32_t rate;
    uint32_t count;
} TICK_REQUEST;
//timer_1ms.c
/* Variables *******************************************************/
static TICK_REQUEST requests[TIMER_MAX_1MS_CLIENTS];
static bool configured = false;
//timer_1ms.c
/*********************************************************************
* Function: void TIMER_CancelTick(TICK_HANDLER handle)
*
* Overview: Cancels a tick request.
*
* PreCondition: None
*
* Input:  handle - the function that was handling the tick request
*
* Output: None
*
********************************************************************/
void TIMER_CancelTick(TICK_HANDLER handle)
{
    uint8_t i;

    for(i = 0; i < TIMER_MAX_1MS_CLIENTS; i++)
    {
        if(requests[i].handle == handle)
        {
            requests[i].handle = NULL;
        }
    }
}
//timer_1ms.c
/*********************************************************************
 * Function: bool TIMER_RequestTick(TICK_HANDLER handle, uint32_t rate)
 *
 * Overview: Requests to receive a periodic event.
 *
 * PreCondition: None
 *
 * Input:  handle - the function that will be called when the time event occurs
 *         rate - the number of ticks per event.
 *
 * Output: bool - true if successful, false if unsuccessful
 *
 ********************************************************************/
bool TIMER_RequestTick ( TICK_HANDLER handle , uint32_t rate )
{
    uint8_t i;
	
    if(configured == false)
    {
        return false;
    }

    for(i = 0; i < TIMER_MAX_1MS_CLIENTS; i++)
    {
        if(requests[i].handle == NULL)
        {
            requests[i].handle = handle;
            requests[i].rate = rate;
            requests[i].count = 0;

            return true;
        }
    }

    return false;
}
//timer_1ms.c
/*********************************************************************
 * Function: bool TIMER_SetConfiguration(TIMER_CONFIGURATIONS configuration)
 *
 * Overview: Initializes the timer.
 *
 * PreCondition: None
 *
 * Input:  None
 *
 * Output: bool - true if successful, false if unsuccessful
 *
 ********************************************************************/
bool TIMER_SetConfiguration ( TIMER_CONFIGURATIONS configuration )
{
    switch(configuration)
    {
        case TIMER_CONFIGURATION_1MS:
            //Disable timer interrupt vectoring before re-configuring it.
            T1CONbits.TON = 0;      
            _T1IE = 0;

            //Clear any registered timer callback function requests
            memset(requests, 0, sizeof(requests));
            
            //(Re-)Configure the timer for 1ms interrupt rate
            _T1IF = 0;
            _T1IP = 4;
            TMR1 = 0;
            PR1 = 999;
            T1CONbits.TECS = 0b11;  //FRC
            T1CONbits.TCS = 1;      //clock source based on TECS value
            T1CONbits.TSYNC = 0;    //synchronize
            T1CONbits.TCKPS = 0b01; //1:8
            T1CONbits.TON = 1;      //Timer on
            
            _T1IE = 1;

            configured = true;
            return true;

        case TIMER_CONFIGURATION_OFF:
            _T1IE = 0;
            configured = false;
            return true;
    }

    return false;
}
//timer_1ms.c
/****************************************************************************
  Function:
    void __attribute__((__interrupt__, auto_psv)) _T3Interrupt(void)

  Description:
    Timer ISR, used to update application state. If no transfers are pending
    new input request is scheduled.
  Precondition:
    None

  Parameters:
    None

  Return Values:
    None

  Remarks:
    None
  ***************************************************************************/
//timer_1ms.c
void __attribute__((__interrupt__, auto_psv)) _T1Interrupt( void )
{
    uint8_t i;

    for(i = 0; i < TIMER_MAX_1MS_CLIENTS; i++)
    {
        if(requests[i].handle != NULL)
        {
            requests[i].count++;
            
            if(requests[i].count == requests[i].rate)
            {
                requests[i].handle();
                requests[i].count = 0;
            }
        }
    }
    
    _T1IF = 0;
}

//compensator.c
#define BUCK_PWM_INSTANCE ((struct PWM_INSTANCE*)&PG7CONL)
#define BUCK_PWM_TRIG_INSTANCE ((struct PWM_INSTANCE*)&PG6CONL)
#define BUCK_SWITCHING_FREQ 100000
#ifndef PWM_INPUT_FREQ
#define PWM_INPUT_FREQ 500000000UL
#endif
#define BUCK_PWM_PERIOD (uint16_t)(PWM_INPUT_FREQ/BUCK_SWITCHING_FREQ)
//PWM Gen I/O Control
#define BUCK_PWM_MODE 1       //0-Comp, 1-Independent, 2-Push/Pull
#define BUCK_PWM_H_EN 1       // 0-Dis, 1-EN
#define BUCK_PWM_L_EN 0       
#define BUCK_PWM_H_INV 1      // 0-Active High, 1-Active Low
#define BUCK_PWM_L_INV 0
#define BUCK_WRITE_IOCONTROL ((BUCK_PWM_MODE<<4) | (BUCK_PWM_H_EN << 3) | (BUCK_PWM_L_EN << 2) | (BUCK_PWM_H_INV << 1) | (BUCK_PWM_L_INV))
#define BUCK_BLANKING_DELAY 50
#define ACCEPTQUALIFIER 2       // LEB active
#define PCISOURCE 28            // Slave 1 comparator
#define PCIACCEPTCRITERIA 3     // Latched
//compensator.c
void INIT_AltRegContext1Setup(void);
int16_t buckErrorControlHistory[4] __attribute__ ((space (ymemory), far));
int16_t buckABCoefficients[5]__attribute__ ((section (".xbss")));
uint16_t buckVoltage = 0;
uint8_t buckSSActiveFlag = 0;
static uint8_t buckErrorCount = 0;
uint16_t buckControlReference = 0;
//compensator.c
void INIT_BuckComp(void)
{
    MACRO_CLR_BUCKHISTORY();
            
    buckABCoefficients[0] = BUCK_COMP_2P2Z_COEFF_B0;
    buckABCoefficients[1] = BUCK_COMP_2P2Z_COEFF_B1;
    buckABCoefficients[2] = BUCK_COMP_2P2Z_COEFF_B2;

    buckABCoefficients[3] = BUCK_COMP_2P2Z_COEFF_A1;
    buckABCoefficients[4] = BUCK_COMP_2P2Z_COEFF_A2;
 
    INIT_AltRegContext1Setup();       // Setup  working registers to be used with compensator
}
//compensator.c
void INIT_BuckDrive(void)
{    
    //Init the slope compensation DAC
    PDMDAC_Init(1, 0, true, true);  
    PDMDAC_InitTrigger(1, 7, 1, 7);
    PDMDAC_InitDACandCMPWithSlope(1, PWM_INPUT_FREQ, 3.3, 0, -0.27272727, 100000, false, 0);
     
    //Init PWM for buck converter
    PWM_InitTimeBase(BUCK_PWM_INSTANCE, BUCK_PWM_PERIOD, (.95*32767), 0x0, 0x0, 0x0);
  
    PWM_InitPCILogicCL(BUCK_PWM_INSTANCE, true, ACCEPTQUALIFIER, false, PCISOURCE, PCIACCEPTCRITERIA);
    PWM_InitLEBState(BUCK_PWM_INSTANCE, BUCK_BLANKING_DELAY, true, false, false, false);
      
    PWM_InitTrigger(BUCK_PWM_INSTANCE, (BUCK_PWM_PERIOD*.5), (BUCK_PWM_PERIOD*.94), 20); 
    PWM_InitADCTrig1(BUCK_PWM_INSTANCE, 0x0, true, false, false);
    PWM_InitADCTrig2(BUCK_PWM_INSTANCE, false, true, false);
    
    PWM_InitOutputState(BUCK_PWM_INSTANCE, BUCK_WRITE_IOCONTROL, false, 0x0, 0x0);
    
    //PWM6 for generating Trigger
    PWM_InitTimeBase(BUCK_PWM_TRIG_INSTANCE, BUCK_PWM_PERIOD, (.95*32767), 0x0, 0x0, 0x0);   
    
    PWM_InitTrigger(BUCK_PWM_TRIG_INSTANCE, 20, 0x0, 0x0);  //TrigA at 20 used for ADC triggering
    PWM_InitADCTrig1(BUCK_PWM_TRIG_INSTANCE, 0x0, true, false, false);
    
    PWM_InitOutputState(BUCK_PWM_TRIG_INSTANCE, BUCK_WRITE_IOCONTROL, false, 0x0, 0x0);

 
    //Enable and configure the ADC so it can sample the output/input voltages.
    ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT, false, true, true);
    ADC_ChannelEnable(ADC_CHANNEL_BUCK_FB, 0x1);    //Select alternate input #1 to core 0 
    ADC_ChannelEnable(ADC_CHANNEL_VIN_FB, false);
    ADC_ChannelInterruptConfig(ADC_CHANNEL_BUCK_FB, 6, 13);
    ADC_ChannelInterruptConfig(ADC_CHANNEL_VIN_FB, 4, 13);          //Triggered from same source as buck output, ISR priority not used as read from same ISR
    
    INIT_BuckComp();
    
    //Start softstart for buck output
    buckSSActiveFlag = true;

    //Enable ISR as last step
    ADC_ChannelInterruptEnable(ADC_CHANNEL_BUCK_FB);
}
//compensator.c
void SOFTSTART_BuckTask(void)
{
    if(buckSSActiveFlag)
    {
        if(buckControlReference < BUCKVOLTAGEREFERENCEADC)
        {
            buckControlReference += BUCKINCREMENT;
        }
        else {
            buckErrorCount = buckSSActiveFlag = 0;
            buckControlReference   = BUCKVOLTAGEREFERENCEADC;
        }
    }
}







/*pwm.c*/
//Note: This code is intended to be used with the "High Resolution PWM with Fine Edge Placement" 
//module, like implemented on the dsPIC33CH512MP508.

//High Speed PWM w/FEP register block structure, as implemented in the dsPIC33CH512MP508 device
struct PWM_INSTANCE
{
    uint16_t PGxCONL;
    uint16_t PGxCONH;
    uint16_t PGxSTAT;
    uint16_t PGxIOCONL;
    uint16_t PGxIOCONH;
    uint16_t PGxEVTL;
    uint16_t PGxEVTH;
    uint16_t PGxFPCIL;
    uint16_t PGxFPCIH;
    uint16_t PGxCLPCIL;
    uint16_t PGxCLPCIH;
    uint16_t PGxFFPCIL;
    uint16_t PGxFFPCIH;
    uint16_t PGxSPCIL;
    uint16_t PGxSPCIH;
    uint16_t PGxLEBL;
    uint16_t PGxLEBH;
    uint16_t PGxPHASE;
    uint16_t PGxDC;
    uint16_t PGxDCA;
    uint16_t PGxPER;
    uint16_t PGxTRIGA;
    uint16_t PGxTRIGB;
    uint16_t PGxTRIGC;
    uint16_t PGxDTL;
    uint16_t PGxDTH;
    uint16_t PGxCAP;    
};
//Note: Below function configures the module to run from the AFPLLO in 1:1.  
//So, to run the PWM module at 500MHz, pre-configure the AUX PLL AFPLLO frequency for 500MHz.
//Note 2: Although this function is primarily module specific, it does write to the common PCLKCON register
//shared by the various PWM modules.
//Note 3: Assumes using local time base not MASTER. Could create an additional API that configures MASTER settings independently 
//Note 4: Assumes Independent Edge PWM mode
void PWM_InitTimeBase(struct PWM_INSTANCE *pInstance, uint16_t PWMSwitchingPeriod, int16_t PWMDutyCyclePercentage, uint16_t PWMPhaseShift, uint16_t PWMDeadTimeH, uint16_t PWMDeadTimeL)
{
    //Setup master/common settings for all high res PWM modules
    //PCLKCON = 0x0001;       //Master clock input: 00 = p13_clock, 01 = AUX PLL VCO /2, 10 = pll_div_clk, 11 = aux_clk
    //PCLKCON = 0x0000;       //Master clock input: 00 = Fosc
    PCLKCON = 0x0003;       //Master clock input: 11 = AFPLLO
      
    pInstance->PGxCONL = 0x0008;       //Clock source is MCLK in 1:1, independent edge PWM mode
    pInstance->PGxCONH = 0x0000;       //This PWM module uses the local duty cycle/period registers, not the common ones. 
    
    pInstance->PGxPHASE = PWMPhaseShift;         //PWM phase
    pInstance->PGxDC = (__builtin_mulus(PWMSwitchingPeriod, PWMDutyCyclePercentage) >> 15);    //PWM duty cycle
    pInstance->PGxPER = PWMSwitchingPeriod;      //PWM period
    pInstance->PGxDTH = PWMDeadTimeH;
    pInstance->PGxDTL = PWMDeadTimeL;

}
void PWM_InitOutputState(struct PWM_INSTANCE *pInstance, uint8_t PWMOutputMode, bool swapPWMOutput, uint8_t PWMFLData, uint8_t PWMCLData)
{
    //Load up PWMx module register settings
    
    pInstance->PGxIOCONL |= (swapPWMOutput << 14);
    pInstance->PGxIOCONL |= ((PWMFLData << 2) | (PWMCLData << 4));
    
    pInstance->PGxIOCONH =  PWMOutputMode;      //TimeBase capture and deadtime compensation cleared
        
    //Enable the PWMx Module now (should see output on PWMxH or PWMxL output pin (as configured)
    pInstance->PGxCONL |= 0x8000;   //ON = 1, module enabled now!
}
void PWM_InitTrigger(struct PWM_INSTANCE *pInstance, uint16_t triggerA, uint16_t triggerB, uint16_t triggerC)
{
    pInstance->PGxTRIGA = triggerA;
    pInstance->PGxTRIGB = triggerB;
    pInstance->PGxTRIGC = triggerC;
}
void PWM_InitADCTrig1(struct PWM_INSTANCE *pInstance, uint8_t pstScaleTrig, bool trigSrcA, bool trigSrcB, bool trigSrcC)
{
    pInstance->PGxEVTL |= ((pstScaleTrig << 11) | (trigSrcA << 8) | (trigSrcB << 9) | (trigSrcC << 10));
    
}
void PWM_InitADCTrig2(struct PWM_INSTANCE *pInstance, bool trigSrcA, bool trigSrcB, bool trigSrcC)
{
    pInstance->PGxEVTH |= ((trigSrcA << 5) | (trigSrcB << 6) | (trigSrcC << 7));
        
}
void PWM_InitPCILogicCL(struct PWM_INSTANCE *pInstance, bool acceptQaulPol, uint8_t acceptQualSrc, bool pciPol, uint8_t pciSrcSelect, uint8_t pciAcceptCriteria)
{
    pInstance->PGxCLPCIL |= 0x1000;     // Set auto-terminate
    
    pInstance->PGxCLPCIL |= ((acceptQaulPol<<11) | (acceptQualSrc<<8) | (pciPol<<5) | (pciSrcSelect));
    
    pInstance->PGxCLPCIH |= (pciAcceptCriteria<<8);

}
//Updates the PWM output duty cycle/on time.
void PWM_UpdateOnTime(struct PWM_INSTANCE *pInstance, uint16_t newOnTimeRegisterValue)
{    
    //Update the PWM duty cycle register now.
    pInstance->PGxDC = newOnTimeRegisterValue;
    
    //Let the hardware know we wrote new value to the register and it should perform an internal bufferred update procedure.
    pInstance->PGxSTAT |= 0x0008;   //Set the UPDREQ bit to initiate the hardware update
}
void PWM_InitLEBState(struct PWM_INSTANCE *pInstance, uint16_t LEBDelay, bool PWMHighRis, bool PWMHighFall, bool PWMLowRis, bool PWMLowFall)
{
    pInstance->PGxLEBL = LEBDelay;
    
    pInstance->PGxLEBH |= ((PWMHighRis<<3)|(PWMHighFall<<2)|(PWMLowRis<<1)|(PWMLowFall)); 
}
//Disables the specified PWM module by clearing the respective PGxCONL<ON> bit.
void PWM_DisableModule(struct PWM_INSTANCE *pInstance)
{    
    //Clear the ON bit to turn off the module
    pInstance->PGxCONL &= 0x7FFF;
}


//pdm_dac.c
#if defined(__XC16__)
    #include <libpic30.h>
#endif
//Note: This code is intended for use with with the PDM DACs + Comparators implemented in the dsPIC33CH512MP508.

//------------------------------------------------------------------------------
//Definitions
//------------------------------------------------------------------------------

//Structure with the order of the registers, as implemented in devices like the dsPIC33CH512MP508
typedef struct _DACREGS
{
    uint16_t DACxCONL;
    uint16_t DACxCONH;
    uint16_t DACxDATL;
    uint16_t DACxDATH;
    uint16_t SLPxCONL;
    uint16_t SLPxCONH;
    uint16_t SLPxDAT;
}DACREGS;
void PDMDAC_Init(uint8_t moduleInstanceNumber, int16_t initialValue, bool AFPLLO500MHzAvailable, bool outputToDACOUTPin)
{
    DACREGS* pRegs = (void*)&DAC1CONL;
    
    //Move the pointer to point to the register block of the module instance of interest
    if(moduleInstanceNumber > 1)
    {
        pRegs += (moduleInstanceNumber - 1);
    }
    
    //If the AUX PLL is available and configured for 500MHz AFPLLO frequency, use
    //that as the clock source for the PDM DAC.  However, if not, use the normal FPLLO in 1:1 instead.
    if(AFPLLO500MHzAvailable == true)
    {
        DACCTRL1L = 0x0080;     //AFPLLO assumed to be at 500MHz, with 1:1 DAC clock input dividers
    }
    else
    {
        DACCTRL1L = 0x00C0;     //FPLLO, 1:1 = ex: up to 200MHz, comparator filter clock div = 1:1.
    }
    
    //Configure the DACx module registers
    pRegs->DACxDATH = initialValue;  
    if(outputToDACOUTPin)
    {
        pRegs->DACxCONL |= 0x0200;   //Set DACOEN to enable output to the DACOUT pin
    }
    pRegs->DACxDATL = 0;            //Low data register (used in sloping output modes)
    
    //Enable the DAC module now.
    pRegs->DACxCONL |= 0x8000;      //Set DACEN bit to enable the module.
    DACCTRL1Lbits.DACON = 1;        //Set top level common enable bit for the all the DAC modules associated with the core  
}
//Updates the DACx to the specified output code between [0 to 4095].
void PDMDAC_SetValue(uint8_t moduleInstanceNumber, int16_t outputCode)
{
    DACREGS* pRegs = (void*)&DAC1CONL;
    
    //Move the pointer to point to the register block of the module instance of interest
    if(moduleInstanceNumber > 1)
    {
        pRegs += (moduleInstanceNumber - 1);
    }

    //Boundary check the value to make sure it properly fits in a 12-bit number.
    if(outputCode > 4095u)
    {
        outputCode = 4095;
    }
    else if(outputCode < 0)
    {
        outputCode = 0;
    }
    
    //Load the DAC output value register
    pRegs->DACxDATH = outputCode;
}
void PDMDAC_InitTrigger(uint8_t moduleInstanceNumber, uint8_t startSlopeTrigger, uint8_t stopSlopeTriggerB, uint8_t stopSlopeTriggerA)
{
    DACREGS* pRegs = (void*)&DAC1CONL;
    
    //Move the pointer to point to the register block of the module instance of interest
    if(moduleInstanceNumber > 1)
    {
        pRegs += (moduleInstanceNumber - 1);
    }
    
    //Configure the PDM DAC slope generation slew rate, and start/stop conditions.
    //Note: If the slew rate is too high, such that the output code tries to cross over the DAC1DATL low value before
    //the PWM trigger event resets the DAC output, the DAC will reset itself and go back to the DACxDATH level, potentially
    //before the comparator has tripped and terminated the current PWM on time.  To avoid this, make sure to select a slew rate and DAC1DATL
    //level that ensures that the active DAC output level never tries to cross over the DAC1DATL level during the PWM period.    
    pRegs->SLPxCONL = (uint16_t)(0x0F & startSlopeTrigger) | (((uint16_t)0x0F & stopSlopeTriggerB) << 4) | (((uint16_t)0x0F & stopSlopeTriggerA) << 8);
    
}
//Enables the comparator and DAC module to operate in positive or negative sloping mode (as would typically be used in a peak current mode control SMPS control loop, where the DAC slope provides the ramp compensation).
//Note: If slopeVoltsPerMicrosecond is a negative number, the result will be a falling slope waveform.  If a positive number is specified, then a positive sloping waveform will be produced instead.
void PDMDAC_InitDACandCMPWithSlope(uint8_t moduleInstanceNumber, uint32_t moduleClockFreq, double DACReferenceVoltage, uint16_t startingDACLevel, double slopeVoltsPerMicrosecond, uint32_t PWMFrequency, bool invertComparatorOutput, uint8_t INSELFieldValue)
{
    DACREGS* pRegs = (void*)&DAC1CONL;
    uint16_t maxSlopeDATValue;
    uint16_t targetSlopeDATValue;
    bool negativeSlopeRequested = false;
    double DACClocksPerMicrosecond;
    #define DAC_OUTPUT_CODES   4096        //12-bit DAC, so [0-4095] = 4096 DAC output codes
   
    //Move the pointer to point to the register block of the module instance of interest
    if(moduleInstanceNumber > 1)
    {
        pRegs += (moduleInstanceNumber - 1);
    }    
    
    //Load the DAC control registers with appropriate values
    pRegs->DACxCONL = 0x2200 | ((uint16_t)INSELFieldValue << 3);          //DACOUT enabled,  INSEL value specified used as CMP positive input, negative input is the DAC, no blanking/digital filtering/hysteresis, not inverted
    if(invertComparatorOutput)
    {
        pRegs->DACxCONL |= 0x0040;      //Set the CMPPOL bit to enable the comparator output to be inverted
    }
    if(slopeVoltsPerMicrosecond < 0.0)
    {
         //Configure for negative slope generation mode
        pRegs->SLPxCONH = 0x0000;         
        negativeSlopeRequested = true;
        slopeVoltsPerMicrosecond = -slopeVoltsPerMicrosecond;   //Get positive/complement value of the negative number (makes below math simpler)
        pRegs->DACxDATL = 0;                   //DAC low value
        pRegs->DACxDATH = startingDACLevel;    //Note: DAC value starts at this, then slopes upwards or downward as configured
    }
    else
    {
        //Configure for positive slope generation mode
        pRegs->SLPxCONH = 0x0200;                   //Configure for positive slope generation mode
        pRegs->DACxDATL = startingDACLevel;         //Starts at this level 
        pRegs->DACxDATH = DAC_OUTPUT_CODES - 1;     //Slopes up until it reaches this level (or the stop trigger signal is received)
    }
    
    //Compute the slope data register value.  The output moves by (SLP1DAT >> 4) number of LSB codes, per DAC clock cycle 
    //(which is 4ns, assuming 500MHz module clock frequency - as internal slope logic frequency is half the module input freq).
    //Note: Fractional LSB moves per clock cycle are allowed.  For example, SLPxDAT value of 0x0001 means that the output value moves by 1/16th of an LSB
    //every clock period.  A value of 0x0011 means that the DAC output moves 1.0625 LSBs every internal clock period.
    moduleClockFreq /= 2;   //Divide input clock frequency of the DAC by 2 to get the internal clock frequency of the DAC change intervals.
    if(negativeSlopeRequested == true)
    {
        //Negative slope
        maxSlopeDATValue = ((double)startingDACLevel / ((double)moduleClockFreq / (double)PWMFrequency)) * (double)16;
    }
    else
    {
        //Positive slope
        maxSlopeDATValue = ((double)((DAC_OUTPUT_CODES - 1) - startingDACLevel) / ((double)moduleClockFreq / (double)PWMFrequency)) * (double)16;
    }
    if(maxSlopeDATValue > 0)
    {
        maxSlopeDATValue--;
    }
    
    //Compute the SLPxDAT value for the specified slopeVoltsPerMicrosecond value.
    DACClocksPerMicrosecond = (double)moduleClockFreq / 1000000;    
    targetSlopeDATValue = (((double)slopeVoltsPerMicrosecond * (double)16) / ((DACClocksPerMicrosecond * DACReferenceVoltage) / (double)DAC_OUTPUT_CODES));

    pRegs->SLPxDAT = targetSlopeDATValue;           //Slope rate (Note: 12.4 formatted fractional number, larger numbers = faster slew rate).
    
    pRegs->DACxCONL |= 0x8000;      //Set DACEN to enable the DAC + comparator
    pRegs->SLPxCONH |= 0x8000;      //Set SLOPEN to enable the slope generation feature of the DAC
}
/*EOF PDM_DAC.c*/


//adc.c
#ifndef FCY
#define FCY 180000000
#endif
/*********************************************************************
* Function: ADC_Read12bit(ADC_CHANNEL channel);
*
* Overview: Reads the requested ADC channel and returns the 12-bit
*           representation of this data.
*
* PreCondition: channel is configured via the ADCConfigure() function
*
* Input: ADC_CHANNEL channel - enumeration of the ADC channels
*        available in this demo.  They should be meaningful names and
*        not the names of the ADC pins on the device (as the demo code
*        may be ported to other boards).
*         i.e. - ADCReadPercentage(ADC_CHANNEL_POTENTIOMETER);
*
* Output: uint16_t - The 12-bit ADC channel conversion value, or 0xFFFF for an 
 *                   error.
*
********************************************************************/
uint16_t ADC_Read12bit(ADC_CHANNEL channel)
{
    //For devices using the new high speed multi-core SAR, like the dsPIC33CH512MP508
    volatile uint16_t* pResultRegister = (&ADCBUF0) + channel;
    
    uint16_t bitOfInterestMask;

    //Select the channel of interest
    ADCON3L = (ADCON3L & 0xFE00) | channel;
    //Generate a manual single channel trigger event to start the conversion
    ADCON3Lbits.CNVRTCH = 1;

    //Wait for the conversion to be complete and the result to be ready.
    if(channel < 16)
    {
        //Wait until the corresponding ANxxRDY bit asserts, indicating new data available.
        bitOfInterestMask = (0x0001 << channel);
        while((ADSTATL & bitOfInterestMask) == 0);            
    }
    else
    {
        //Wait until the corresponding ANxxRDY bit asserts, indicating new data available.
        bitOfInterestMask = (0x0001 << (channel - 16));
        while((ADSTATH & bitOfInterestMask) == 0);            
    }

    //The data should be available.  Return it now.
    return (*pResultRegister);
}
/*********************************************************************
* Function: uint16_t ADC_Read12bitAverage(ADC_CHANNEL channel, uint16_t numberOfSamplesInAverage)
*
* Overview: Repeatedly reads the requested ADC channel and returns a 12-bit
*           representation of the average value returned by the ADC over the
*           sample set.
*
* PreCondition: channel is configured via the ADCConfigure() function
*
* Input: ADC_CHANNEL channel - enumeration of the ADC channels
*        available in this demo.  They should be meaningful names and
*        not the names of the ADC pins on the device (as the demo code
*        may be ported to other boards).
*         i.e. - ADCReadPercentage(ADC_CHANNEL_POTENTIOMETER);
*        uint16_t numberOfSamplesInAverage - the number of samples to take when
*                 computing the average result.  The more the samples, the better
*                 the result quality, but the longer the operation will take.
*
* Output: uint16_t - The 12-bit average ADC channel conversion result value
*
********************************************************************/
uint16_t ADC_Read12bitAverage(ADC_CHANNEL channel, uint16_t numberOfSamplesInAverage)
{
    uint32_t resultAccumulator = 0;
    uint16_t i;
    
    //Collect a series of ADC result values and add them to an accumulator.
    for(i = 0; i < numberOfSamplesInAverage; i++)
    {
        resultAccumulator += ADC_Read12bit(channel);
    }
    
    if(i > 0)
    {
        //Divide the accumulator sum by the number of samples in the sum, to get the average result value.
        return ((resultAccumulator + (i >> 1)) / i);       //Note: + (i >> 1) is done to achieve a rounding effect, rather than simple truncation.
    }
    
    return 0;
}
/*********************************************************************
* Function: bool ADC_ChannelEnable(ADC_CHANNEL channel, ADC_CONFIGURATION configuration);
*
* Overview: Configures the ADC module to specified setting
*
* PreCondition: none
*
* Input: ADC_CHANNEL channel - the channel to enable
*        ADC_CONFIGURATION configuration - the mode in which to run the ADC
*
* Output: bool - true if successfully configured.  false otherwise.
*
********************************************************************/
bool ADC_ChannelEnable(ADC_CHANNEL channel, uint8_t altInput)
{
    switch(channel)
    {
        case ADC_CHANNEL_1:
            ANSELCbits.ANSELC1 = 1 ;
            ADCON4Hbits.C1CHS = altInput;
            return true;
          
        case ADC_CHANNEL_15:
            ANSELAbits.ANSELA1 = 1 ;
            return true;   
            
        default:
            return false;
    }
    
    return false;
}
/*********************************************************************
* Function: bool ADC_SetConfiguration(ADC_CONFIGURATION configuration)
*
* Overview: Configures the ADC module to specified setting
*
* PreCondition: none
*
* Input: ADC_CONFIGURATION configuration - the mode in which to run the ADC
*
* Output: bool - true if successfully configured.  false otherwise.
*
********************************************************************/
bool ADC_SetConfiguration(ADC_CONFIGURATION configuration, bool enCore0, bool enCore1, bool enSHCore)
{
    if(configuration == ADC_CONFIGURATION_DEFAULT)
    {
        ADCON1L = 0x0000;       //CVD off, ADC operates in idle mode.
        ADCON1H = 0x0060;       //Integer output formatting, 12-bit resolution
        
        //NOTE: ADC clock period should be >=14.28ns, based on dsPIC33CH512MP508 datasheet
        ADCON2L = 0x0000;       //TADCORE = TCORESRC / 2
        ADCON2H = 0x0002;       //Sample time (SAMC) = 4 * TADCORE
        ADCON3L = 0x0000;       //AVDD/AVSS as references
        ADCON3H = 0x4000;       //TCORESRC = FOSC
        ADCON5H = 0x0F00;       //32768 TCORESRC clocks for warm up time

        ADCON1Lbits.ADON = 1;   //Turn on the ADC module now.
        
        if(enCore0)
        {
            ADCON3Hbits.C0EN = 1;   //Enable Core 0
            ADCON5Lbits.C0PWR = 1;
            //Wait until the ADC "shared core" claims it is ready to go.
            while(ADCON5Lbits.C0RDY == 0); 
        }    
        
        if(enCore1)
        {
            ADCON3Hbits.C1EN = 1;   //Enable Core 1
            ADCON5Lbits.C1PWR = 1;
            //Wait until the ADC "shared core" claims it is ready to go.
            while(ADCON5Lbits.C1RDY == 0); 
        }    
        
        if(enSHCore)
        {   
            ADCON3Hbits.SHREN = 1;   //Enable Shared Core 
            ADCON5Lbits.SHRPWR = 1;
            //Wait until the ADC "shared core" claims it is ready to go.
            while(ADCON5Lbits.SHRRDY == 0);
        }
            
            
        return true;
    }
		
    return false;
}
void ADC_ChannelInterruptEnable(ADC_CHANNEL channel)
{
    uint16_t bitOfInterestMask;
     
    //Enable the interrupt
    if(channel > 4)
    {
        bitOfInterestMask = (0x0001 << (channel-5));
        IEC6 |=  bitOfInterestMask;
    }
    else {
        bitOfInterestMask = (0x0001 << (channel+11));
        IEC5 |=  bitOfInterestMask;        
    }    
    
    //Enable ISR from ADC point of view
    if(channel < 16)
    {
        bitOfInterestMask = (0x0001 << channel);
        ADIEL |= bitOfInterestMask;
    }
    else {
        bitOfInterestMask = (0x0001 << (channel-16));
        ADIEH |= bitOfInterestMask;
    }  
    
}
void ADC_ChannelInterruptConfig(ADC_CHANNEL channel, uint8_t channelISRPriority, uint8_t channelISRTrigSRC)
{
    volatile uint16_t *pTriggerRegister = (&ADTRIG0L) + (channel>>1);
    volatile uint16_t *pIPCRegister = (&IPC22);
    
    uint16_t bitOfInterestMask = 0xFFF8, sftFactor = 0;
    uint16_t offset = 0;
    
    //Set IPL level for proper ADC Channel
    if(channel > 0  && channel <= 4) offset = 1;
    else if(channel > 4 && channel <= 8) offset = 2;
    else if(channel > 8 && channel <= 12) offset = 3;
    else if(channel > 12 && channel <= 16) offset = 4;
    else if(channel > 16 && channel <= 20) offset = 5;
    
    // Bit Shifting
    if(channel % 4 == 1)
    {
        //Write to bits 2:0
        bitOfInterestMask = 0xFFF8;
        sftFactor = 0;
    }
    else if(channel % 4 == 2)
    {
        //Write to bits 6:4
        bitOfInterestMask = 0xFF8F;
        sftFactor = 4;
    }
    else if(channel % 4 == 3)
    {
        //Write to bits 10:8
        bitOfInterestMask = 0xF8FF;
        sftFactor = 8;
    }
    else if(channel % 4 == 0)
    {
        //Write to bits 14:12
        bitOfInterestMask = 0x8FFF;
        sftFactor = 12;
    }

    pIPCRegister = (&IPC22) + offset;
    *pIPCRegister &= bitOfInterestMask;
    *pIPCRegister |= (channelISRPriority << sftFactor);    
    
    //Set the proper trigger source for the given ANx Channel
    if(channel & 0x1) //odd
    {
        *pTriggerRegister &= 0x00FF;
        *pTriggerRegister |= (channelISRTrigSRC<<8);
    }    
    else {
        *pTriggerRegister &= 0xFF00;
        *pTriggerRegister |= channelISRTrigSRC;  
    }
}




//msi.c
bool MSI_SendOutputVoltage(uint16_t outputVoltage)
{
    if(_DTRDYA)
    {
        return false;
    }

    SI1MBX0D = outputVoltage;
    
    return true;
}
bool MSI_SendInputVoltage(uint16_t inputVoltage)
{
    if(_DTRDYB)
    {
        return false;
    }

    SI1MBX1D = inputVoltage;
    
    return true;
}
void __attribute__ ((interrupt, no_auto_psv)) _MSICInterrupt(void)
{
    bool enable = (bool)SI1MBX2D;
    
    if(enable == true)
    {
        TRANSIENT_LOAD_Enable();
    }
    else
    {
        TRANSIENT_LOAD_Disable();
    }
    
    _MSICIF=0;
}





//main.c
extern uint8_t buckSSActiveFlag;
extern uint16_t buckVoltage;
uint16_t inputVoltage;
//main.c
int main(void) { 
   
    SYSTEM_Initialize();
    
    TRANSIENT_LOAD_Initialize();
    TRANSIENT_LOAD_SetCurrent(.1*32767);    //0->1 range scaled to Q15
    TRANSIENT_LOAD_SetOnTime(5);
    TRANSIENT_LOAD_SetPeriod(200);  
    
    TIMER_SetConfiguration(TIMER_CONFIGURATION_1MS);
    TIMER_RequestTick(&TRANSIENT_LOAD_Tasks, 1);
    
    INIT_BuckDrive();
    
    TIMER_RequestTick(&SOFTSTART_BuckTask, 1);
    
    while(1)
    {
        
        if(!buckSSActiveFlag) 
        {
            TIMER_CancelTick(&SOFTSTART_BuckTask);
        }
            
        //MSI_SendOutputVoltage(buckVoltage);
        //MSI_SendInputVoltage(inputVoltage);
    }
}