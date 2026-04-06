/* 
 * File:   PDM_DAC.h
 */

#ifndef PDM_DAC_H
#define	PDM_DAC_H

#include "stdint.h"
#include "stdbool.h"

//------------------------------------------------------------------------------
//Prototypes
//------------------------------------------------------------------------------
void PDMDAC_Init(uint8_t moduleInstanceNumber, int16_t initialValue, bool AFPLLO500MHzAvailable, bool outputToDACOUTPin);
void PDMDAC_SetValue(uint8_t moduleInstanceNumber, int16_t outputCode);
void PDMDAC_InitTrigger(uint8_t moduleInstanceNumber, uint8_t startSlopeTrigger, uint8_t stopSlopeTriggerB, uint8_t stopSlopeTriggerA);
void PDMDAC_InitDACandCMPWithSlope(uint8_t moduleInstanceNumber, uint32_t moduleClockFreq, double DACReferenceVoltage, uint16_t startingDACLevel, double slopeVoltsPerMicrosecond, uint32_t PWMFrequency, bool invertComparatorOutput, uint8_t INSELFieldValue);

#endif	/* PDM_DAC_H */

