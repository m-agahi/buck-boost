/*******************************************************************************
Copyright 2017 Microchip Technology Inc. (www.microchip.com)

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

#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "msi.h"
#include "system.h"
#include "transient_load.h"
#include "timer_1ms.h"
#include "compensator_init.h"

extern uint8_t buckSSActiveFlag;
extern uint16_t buckVoltage;

uint16_t inputVoltage;

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
            
        MSI_SendOutputVoltage(buckVoltage);
        MSI_SendInputVoltage(inputVoltage);
    }
}