Os_Hal_Asm_Load_Register_Immediate .macro Register, Immediate
  movw Register, Immediate
  movt Register, Immediate
  .endm
Os_Hal_Asm_LoadRegister32 .macro Register, Value
  movw Register, Value
  movt Register, Value
  .endm
  .sect .OS_CODE, RO
  NOP
  .def Os_Hal_ReadFpscr
  .def Os_Hal_ReadFpexc
Os_Hal_ReadFpscr .asmfunc
  .if __TI_VFP_SUPPORT__
  vmrs r0, FPSCR
  .endif
  bx lr
  .endasmfunc
Os_Hal_ReadFpexc .asmfunc
  .if __TI_VFP_SUPPORT__
  vmrs r0, FPEXC
  .endif
  bx lr
  .endasmfunc
  .end
