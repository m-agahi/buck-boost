#include <xc.h>

#include "msi.h"
#include <string.h>
#include "transient_load.h"

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
