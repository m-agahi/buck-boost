#ifndef TRANSIENT_LOAD_H
#define TRANSIENT_LOAD_H

#include <stdint.h>

void TRANSIENT_LOAD_Initialize(void);
void TRANSIENT_LOAD_Tasks(void);
void TRANSIENT_LOAD_Enable(void);
void TRANSIENT_LOAD_Disable(void);
void TRANSIENT_LOAD_SetOnTime(uint16_t milliseconds);
void TRANSIENT_LOAD_SetPeriod(uint16_t milliseconds);
void TRANSIENT_LOAD_SetCurrent(int16_t currentDuringTransient);

#endif
