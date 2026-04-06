
.include "xc.inc"
#include "buck_dcdt_v1.h"

.data   ; Tell assembler to add subsequent data to the data section

.text   ; Begin program instructions


.global _INIT_AltRegContext1Setup

  _INIT_AltRegContext1Setup:

  CTXTSWP #0x1   ;Swap to Alternate W-Reg context #1

  ; Note: w0 register will be used for compensator control reference parameter
  ; Initialize Alternate Working Registers context #1
  mov #ADCBUF1,                  w1    ; Address of the ADCBUF1 register  (Input)
  mov #DAC1DATH,                  w2    ; Address of the DAC target register (Output)

  ; w3, w4, w5 used for MAC/MPY instructions
  mov #BUCK_COMP_2P2Z_POSTSCALER, w6
  mov #BUCK_COMP_2P2Z_POSTSHIFT,  w7
  ; w8 free
  mov #_buckABCoefficients,       w9
  mov #_buckErrorControlHistory,  w10
  mov #BUCK_COMP_2P2Z_MIN_CLAMP,  w11
  mov #BUCK_COMP_2P2Z_MAX_CLAMP,  w12
  mov #PG7TRIGC,		  w13
  mov #BUCK_COM_2P2Z_TRG_DLY,     w14

  CTXTSWP #0x0  ; Swap back to main register set

  return        ; Exit Alt-WREG1 set-up function

.end
