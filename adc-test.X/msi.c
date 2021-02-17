#include "msi.h"
#include <xc.h>
#include <string.h>
#include <stdint.h>

float MSI_ReadOutputVoltage(void)
{
    float voltage;
    
    voltage = (float)MSI1MBX0D * 0.00147017;
    
    return voltage;
}

bool MSI_IsOutputVoltageReady(void)
{
    return _DTRDYA;
}

float MSI_ReadInputVoltage(void)
{
    float inVoltage;
    
    inVoltage = (float)MSI1MBX1D * 0.00137158;
    
    return inVoltage;
}

bool MSI_IsInputVoltageReady(void)
{
    return _DTRDYB;
}

bool MSI_EnableTransientLoad(bool enable)
{
    if(_DTRDYC == 1)
    {
        return false;
    }
    
    MSI1MBX2D = (uint16_t)enable;
    
    return true;
}
