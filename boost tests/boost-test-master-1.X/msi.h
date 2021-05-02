#include <stdbool.h>

float MSI_ReadOutputVoltage(void);
bool MSI_IsOutputVoltageReady(void);

float MSI_ReadInputVoltage(void);
bool MSI_IsInputVoltageReady(void);

bool MSI_EnableTransientLoad(bool enable);
