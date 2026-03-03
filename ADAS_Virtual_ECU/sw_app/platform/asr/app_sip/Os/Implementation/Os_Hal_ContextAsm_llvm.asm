Os_Hal_Asm_Load_Register_Immediate .macro Register, Immediate
  movw Register, Immediate
  movt Register, Immediate
  .endm
Os_Hal_Asm_LoadRegister32 .macro Register, Value
  movw Register, Value
  movt Register, Value
  .endm
 
  .global Os_Hal_CoreExceptionGetInterruptLockLevel
  .global Os_Hal_CoreExceptionSetInterruptLockLevel
  .sect .OS_CODE, RO
 
Os_Hal_WriteSysModeToReg .asmfunc
  mov r0, #0x1F
  bx lr
 
  .endasmfunc
 
Os_Hal_Copy_SP_sys_FromVarToReg .asmfunc
  ldr r2, [r3, #0x20]
  bx lr
 
  .endasmfunc
 
Os_Hal_Copy_LR_sys_FromVarToReg .asmfunc
  ldr r2, [r3, #0x24]
  bx lr
 
  .endasmfunc
 
Os_Hal_WriteDummyToReg .asmfunc
  movw r2, #0xDEAD
  bx lr
 
  .endasmfunc
 
Os_Hal_StoreDataFaultRegisters .asmfunc
  mrc p15, #0, r0, c5, c0, #0
  str r0, [r5, #0x94]
  mrc p15, #0, r0, c5, c1, #0
  str r0, [r5, #0x98]
  mrc p15, #0, r0, c6, c0, #0
  str r0, [r5, #0x9C]
  bx lr
 
  .endasmfunc
 
Os_Hal_StoreDummyForDataFaultRegisters .asmfunc
  movw r0, #0xDEAD
  str r0, [r5, #0x94]
  str r0, [r5, #0x98]
  str r0, [r5, #0x9C]
  bx lr
 
  .endasmfunc
 
Os_Hal_StoreInstructionFaultRegisters .asmfunc
  mrc p15, #0, r0, c5, c0, #1
  str r0, [r5, #0xA0]
  mrc p15, #0, r0, c5, c1, #1
  str r0, [r5, #0xA4]
  mrc p15, #0, r0, c6, c0, #2
  str r0, [r5, #0xA8]
  bx lr
 
  .endasmfunc
 
Os_Hal_StoreDummyForInstructionFaultRegisters .asmfunc
  movw r0, #0xDEAD
  str r0, [r5, #0xA0]
  str r0, [r5, #0xA4]
  str r0, [r5, #0xA8]
  bx lr
 
  .endasmfunc
 
Os_Hal_RetAddr_Und_Svc_Thumb .asmfunc
  add r0, r0, #2
  bx lr
 
  .endasmfunc
 
Os_Hal_RetAddr_Und_Svc .asmfunc
  cmp r4, #0
  push {lr}
  blne Os_Hal_RetAddr_Und_Svc_Thumb
  pop {lr}
  bx lr
 
  .endasmfunc
 
Os_Hal_RetAddr_DABT .asmfunc
  sub r0, r0, #4
  bx lr
 
  .endasmfunc
 
Os_Hal_RetAddr_Fiq .asmfunc
  sub r0, r0, #4
  bx lr
 
  .endasmfunc
 
Os_Hal_Context_SaveExcContext .asmfunc
  push {lr}
  .global OsCfg_Hal_Context_ExceptionContextRef
  Os_Hal_Asm_Load_Register_Immediate r5, OsCfg_Hal_Context_ExceptionContextRef
  ldr r5, [r5, r0, lsl #2]
  str r1, [r5]
  ldr r0, [r3, #0x1C]
  and r0, r0, #0x1F
  cmp r0, #0x10
  bleq Os_Hal_WriteSysModeToReg
  mrs r2, cpsr
  movw r4, #0xFFE0
  movt r4, #0xFFFF
  and r2, r2, r4
  orr r2, r2, r0
  msr cpsr_cxsf, r2
  ldr r4, [r3]
  str r4, [r5, #0x04]
  ldr r4, [r3, #0x04]
  str r4, [r5, #0x08]
  ldr r4, [r3, #0x08]
  str r4, [r5, #0x0C]
  ldr r4, [r3, #0x0C]
  str r4, [r5, #0x10]
  ldr r4, [r3, #0x10]
  str r4, [r5, #0x14]
  ldr r4, [r3, #0x14]
  str r4, [r5, #0x18]
  str r6, [r5, #0x1C]
  str r7, [r5, #0x20]
  str r8, [r5, #0x24]
  str r9, [r5, #0x28]
  str r10, [r5, #0x2C]
  str r11, [r5, #0x30]
  str r12, [r5, #0x34]
  mov r2, sp
  cmp r0, #0x1F
  bleq Os_Hal_Copy_SP_sys_FromVarToReg
  cmp r0, #0x11
  mov r4, lr
  bleq Os_Hal_WriteDummyToReg
  mov lr, r4
  str r2, [r5, #0x38]
  mov r2, lr
  cmp r0, #0x1F
  bleq Os_Hal_Copy_LR_sys_FromVarToReg
  str r2, [r5, #0x3C]
  cps #0x11
  str r8, [r5, #0x40]
  str r9, [r5, #0x44]
  str r10, [r5, #0x48]
  str r11, [r5, #0x4C]
  str r12, [r5, #0x50]
  movw r0, #0xDEAD
  str r0, [r5, #0x54]
  str lr, [r5, #0x58]
  mrs r0, spsr
  str r0, [r5, #0x5C]
  cps #0x12
  str sp, [r5, #0x60]
  str lr, [r5, #0x64]
  mrs r0, spsr
  str r0, [r5, #0x68]
  cps #0x17
  movw r0, #0xDEAD
  str r0, [r5, #0x6C]
  str lr, [r5, #0x70]
  mrs r0, spsr
  str r0, [r5, #0x74]
  cps #0x13
  str sp, [r5, #0x78]
  str lr, [r5, #0x7C]
  mrs r0, spsr
  str r0, [r5, #0x80]
  cps #0x1B
  movw r0, #0xDEAD
  str r0, [r5, #0x84]
  str lr, [r5, #0x88]
  mrs r0, spsr
  str r0, [r5, #0x8C]
  cps #0x1F
  mrc p15, #0, r0, c13, c0, #3
  str r0, [r5, #0x90]
  cmp r1, #4
  bleq Os_Hal_StoreDataFaultRegisters
  blne Os_Hal_StoreDummyForDataFaultRegisters
  cmp r1, #3
  bleq Os_Hal_StoreInstructionFaultRegisters
  blne Os_Hal_StoreDummyForInstructionFaultRegisters
  add r0, r5, #0xAC
  vstm r0, {s0-s31}
  vmrs r2, FPSCR
  str r2, [r5, #0x130]
  vmrs r0, FPEXC
  str r0, [r5, #0x12C]
  mov r0, #15
  str r0, [r5, #0x134]
  ldr r0, [r3, #0x28]
  str r0, [r5, #0x138]
  ldr r0, [r3, #0x2C]
  str r0, [r5, #0x13C]
  ldr r0, [r3, #0x30]
  str r0, [r5, #0x140]
  ldr r0, [r3, #0x18]
  sub r0, r0, #4
  ldr r2, [r3, #0x1C]
  and r4, r2, #0x20
  cmp r1, #1
  bleq Os_Hal_RetAddr_Und_Svc
  cmp r1, #2
  bleq Os_Hal_RetAddr_Und_Svc
  cmp r1, #4
  bleq Os_Hal_RetAddr_DABT
  str r0, [r5, #0x144]
  ldr r0, [r3, #0x18]
  cmp r1, #7
  bleq Os_Hal_RetAddr_Fiq
  str r0, [r5, #0x148]
  push {r3, r9, r12}
  bl Os_Hal_CoreExceptionGetInterruptLockLevel
  pop {r3, r9, r12}
  str r0, [r5, #0x14C]
  cps #0x1F
  pop {lr}
  bx lr
 
  .endasmfunc
 
Os_Hal_Context_RestoreUpdatedExcContext .asmfunc
  mov r4, lr
  .global OsCfg_Hal_Context_ExceptionContextRef
  Os_Hal_Asm_Load_Register_Immediate r5, OsCfg_Hal_Context_ExceptionContextRef
  ldr r5, [r5, r0, lsl #2]
  ldr r0, [r5, #0x14C]
  bl Os_Hal_CoreExceptionSetInterruptLockLevel
  add r0, r5, #0xAC
  vldm r0, {s0-s31}
  cps #0x11
  add r0, r5, #0x40
  ldm r0, {r8-r12}
  ldr lr, [r5, #0x58]
  ldr r0, [r5, #0x5C]
  msr spsr_cxsf, r0
  cps #0x12
  ldr sp, [r5, #0x60]
  ldr lr, [r5, #0x64]
  ldr r0, [r5, #0x68]
  msr spsr_cxsf, r0
  cps #0x17
  ldr lr, [r5, #0x70]
  ldr r0, [r5, #0x74]
  msr spsr_cxsf, r0
  cps #0x13
  ldr lr, [r5, #0x7C]
  ldr r0, [r5, #0x80]
  msr spsr_cxsf, r0
  cps #0x13
  ldr lr, [r5, #0x88]
  ldr r0, [r5, #0x8C]
  msr spsr_cxsf, r0
  cps #0x1F
  add r0, r5, #0x1C
  ldm r0, {r6-r12}
  ldr lr, [r5, #0x3C]
  mov r0, #15
  mcr p15,#0,r0,c6,c2,#0
  mov r0, #0
  mcr p15,#0,r0,c6,c1,#2
  ldr r0, [r5, #0x138]
  mcr p15,#0,r0,c6,c1,#0
  ldr r0, [r5, #0x13C]
  mcr p15,#0,r0,c6,c1,#4
  ldr r0, [r5, #0x140]
  mcr p15,#0,r0,c6,c1,#2
  cps #0x17
  mov r3, sp
  cps #0x1F
  ldr sp, [r5, #0x38]
  bx r4
 
  .endasmfunc
 
  .sect .OS_CODE, RO
Os_Hal_CoreGetId_Asm .asmfunc
  mrc p15,#0,r0,c0,c0,#5
  and r1, r0, #0xFF
  and r0, r0, #0xFF00
  orr r0, r1, r0, lsr #(7)
  bx lr
  .endasmfunc
 
  .sect .OS_CODE, RO
  .def Os_Hal_MemFault_PrefetchAbort
  .def Os_Hal_MemFault_DataAbort
  .def Os_Hal_SysCallHandler
  .def Os_Hal_SysCallHandler_Jacinto7
  .global OsCfg_Stack_KernelStacks
  .global Os_MemFault
  .global Os_TrapHandler
Os_Hal_SysCallHandler .asmfunc
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  add r1, sp, #0x20
  bl Os_TrapHandler
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endasmfunc
Os_Hal_SysCallHandler_Jacinto7 .asmfunc
  cpsid f
  mov lr, r1
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  add r1, sp, #0x20
  bl Os_TrapHandler
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endasmfunc
Os_Hal_MemFault_PrefetchAbort .asmfunc
  stm sp, {r0-r5}
  str lr, [sp, #0x18]
  mrs r0, spsr
  str r0, [sp, #0x1C]
  mov r3, sp
  cps #0x1F
  str sp, [r3, #0x20]
  str lr, [r3, #0x24]
  mov r0, #15
  mcr p15,#0,r0,c6,c2,#0
  mrc p15,#0,r0,c6,c1,#0
  str r0, [r3, #0x28]
  mrc p15,#0,r0,c6,c1,#4
  str r0, [r3, #0x2C]
  mrc p15,#0,r0,c6,c1,#2
  str r0, [r3, #0x30]
  bl Os_Hal_CoreGetId_Asm
  Os_Hal_Asm_LoadRegister32 r1, OsCfg_Stack_KernelStacks
  mov r2, #0x4
  mul r2, r2, r0
  add r1, r1, r2
  ldr r2, [r1, #0]
  ldr sp, [r2, #0]
  ldr r1, [r2, #4]
  ldr r4, [r2, #8]
  mov r2, #0
  mcr p15,#0,r2,c6,c1,#2
  mcr p15,#0,r1,c6,c1,#0
  movw r2, #0x130B
  movt r2, #0
  mcr p15,#0,r2,c6,c1,#4
  mcr p15,#0,r4,c6,c1,#2
  mov r1, #3
  bl Os_Hal_Context_SaveExcContext
  ldr r0, [r3, #0x18]
  sub r0, r0, #4
  ldr r1, [r3, #0x1C]
  and r1, r1, #0x0F
  push {r9, r12}
  bl Os_MemFault
  pop {r9, r12}
  bl Os_Hal_CoreGetId_Asm
  bl Os_Hal_Context_RestoreUpdatedExcContext
  ldr r2, [r3, #0x1C]
  ldr r1, [r5, #0x148]
  push {r1-r2}
  add r5, r5, #4
  ldm r5, {r0-r5}
  rfefd sp!
  .endasmfunc
Os_Hal_MemFault_DataAbort .asmfunc
  stm sp, {r0-r5}
  str lr, [sp, #0x18]
  mrs r0, spsr
  str r0, [sp, #0x1C]
  mov r3, sp
  cps #0x1F
  str sp, [r3, #0x20]
  str lr, [r3, #0x24]
  mov r0, #15
  mcr p15,#0,r0,c6,c2,#0
  mrc p15,#0,r0,c6,c1,#0
  str r0, [r3, #0x28]
  mrc p15,#0,r0,c6,c1,#4
  str r0, [r3, #0x2C]
  mrc p15,#0,r0,c6,c1,#2
  str r0, [r3, #0x30]
  bl Os_Hal_CoreGetId_Asm
  Os_Hal_Asm_LoadRegister32 r1, OsCfg_Stack_KernelStacks
  mov r2, #0x4
  mul r2, r2, r0
  add r1, r1, r2
  ldr r2, [r1, #0]
  ldr sp, [r2, #0]
  ldr r1, [r2, #4]
  ldr r4, [r2, #8]
  mov r2, #0
  mcr p15,#0,r2,c6,c1,#2
  mcr p15,#0,r1,c6,c1,#0
  movw r2, #0x130B
  movt r2, #0
  mcr p15,#0,r2,c6,c1,#4
  mcr p15,#0,r4,c6,c1,#2
  mov r1, #4
  bl Os_Hal_Context_SaveExcContext
  ldr r0, [r3, #0x18]
  sub r0, r0, #8
  ldr r1, [r3, #0x1C]
  and r1, r1, #0x0F
  push {r9, r12}
  bl Os_MemFault
  pop {r9, r12}
  bl Os_Hal_CoreGetId_Asm
  bl Os_Hal_Context_RestoreUpdatedExcContext
  ldr r2, [r3, #0x1C]
  ldr r1, [r5, #0x148]
  push {r1-r2}
  add r5, r5, #4
  ldm r5, {r0-r5}
  rfefd sp!
  .endasmfunc
 
  .sect .OS_CODE, RO
  .def Os_Hal_StorePermanentRegisters
  .def Os_Hal_ContextGoWithParameter
  .def Os_Hal_ContextGoWithParameterMpSwitch
  .def Os_Hal_ContextRestorePermanentAndGo
  .def Os_Hal_ContextGo
  .def Os_Hal_ContextRestorePermanentAndGoWithReturn
Os_Hal_StorePermanentRegisters .asmfunc
  stm r0, {r4-r11}
  bx lr
  .endasmfunc
Os_Hal_ContextGoWithParameter .asmfunc
  str lr, [r3]
  str sp, [r3, #0x8]
  add r3, r3, #0x14
  stm r3, {r4-r11}
  Os_Hal_Asm_LoadRegister32 lr, ret_label_1
  movs pc, lr
ret_label_1
  mov lr, r2
  bx r1
  .endasmfunc
Os_Hal_ContextGoWithParameterMpSwitch .asmfunc
  str lr, [r2, #0x00]
  str sp, [r2, #0x8]
  add r2, r2, #0x14
  stm r2, {r4-r11}
  mov r2, #15
  mcr p15,#0,r2,c6,c2,#0
  mov r2, #0
  mcr p15,#0,r2,c6,c1,#2
  mcr p15,#0,r0,c6,c1,#0
  movw r2, #0x130B
  movt r2, #0
  mcr p15,#0,r2,c6,c1,#4
  mcr p15,#0,r1,c6,c1,#2
  isb
  ldr r0, [r3, #0x10]
  ldr r1, [r3, #0x00]
  ldr r2, [r3, #0x0C]
  Os_Hal_Asm_LoadRegister32 lr, ret_label_1B
  movs pc, lr
ret_label_1B
  mov lr, r2
  bx r1
  .endasmfunc
Os_Hal_ContextRestorePermanentAndGo .asmfunc
  add r1, r0, #0x14
  ldm r1, {r4-r11}
  ldr r1, [r0, #0x3C]
  ldr r2, [r0, #0x38]
  mov r3, #15
  mcr p15,#0,r3,c6,c2,#0
  mov r3, #0
  mcr p15,#0,r3,c6,c1,#2
  mcr p15,#0,r2,c6,c1,#0
  movw r3, #0x130B
  movt r3, #0
  mcr p15,#0,r3,c6,c1,#4
  mcr p15,#0,r1,c6,c1,#2
  isb
  ldr r2, [r0, #0xc]
  ldr r3, [r0]
  Os_Hal_Asm_LoadRegister32 lr, ret_label_2
  movs pc, lr
ret_label_2
  mov lr, r2
  bx r3
  .endasmfunc
Os_Hal_ContextGo .asmfunc
  ldr r1, [r0, #0x3C]
  ldr r2, [r0, #0x38]
  mov r3, #15
  mcr p15,#0,r3,c6,c2,#0
  mov r3, #0
  mcr p15,#0,r3,c6,c1,#2
  mcr p15,#0,r2,c6,c1,#0
  movw r3, #0x130B
  movt r3, #0
  mcr p15,#0,r3,c6,c1,#4
  mcr p15,#0,r1,c6,c1,#2
  isb
  ldr r2, [r0, #0xc]
  ldr r3, [r0]
  Os_Hal_Asm_LoadRegister32 lr, ret_label_2B
  movs pc, lr
ret_label_2B
  mov lr, r2
  bx r3
  .endasmfunc
Os_Hal_ContextRestorePermanentAndGoWithReturn .asmfunc
  str lr, [r1]
  str sp, [r1, #0x8]
  add r1, r1, #0x14
  stm r1, {r4-r11}
  ldr r1, [r0, #0x3C]
  ldr r2, [r0, #0x38]
  mov r3, #15
  mcr p15,#0,r3,c6,c2,#0
  mov r3, #0
  mcr p15,#0,r3,c6,c1,#2
  mcr p15,#0,r2,c6,c1,#0
  movw r3, #0x130B
  movt r3, #0
  mcr p15,#0,r3,c6,c1,#4
  mcr p15,#0,r1,c6,c1,#2
  isb
  ldr r2, [r0, #0xc]
  ldr r3, [r0]
  add r1, r0, #0x14
  ldm r1, {r4-r11}
  Os_Hal_Asm_LoadRegister32 lr, ret_label_3
  movs pc, lr
ret_label_3
  mov lr, r2
  bx r3
  .endasmfunc
  .end
