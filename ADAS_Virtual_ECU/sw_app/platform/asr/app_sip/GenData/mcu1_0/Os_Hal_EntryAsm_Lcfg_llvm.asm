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
  .global OsCfg_Stack_KernelStacks
  .global Os_UnhandledExc
  .sect .OS_CODE, RO
  .def Os_Hal_UnhandledExceptionEntry
  .def Os_Hal_UnhandledSysCallExceptionEntry
  .def Os_Hal_UnhandledExceptionEntry_WithMemoryProtection
  .def Os_Hal_UndefinedInstructionExceptionEntry
  .def Os_Hal_UndefinedInstructionExceptionEntry_WithMemoryProtection
  .def Os_Hal_DataAbortExceptionEntry
  .def Os_Hal_PrefetchAbortExceptionEntry
Os_Hal_Sub2FromReg .asmfunc
  sub r1, r1, #2
  bx lr
  .endasmfunc
Os_Hal_Sub4FromReg .asmfunc
  sub r1, r1, #4
  bx lr
  .endasmfunc
Os_Hal_UnhandledExceptionEntry .asmfunc
  stm sp, {r0-r5}
  str lr, [sp, #0x18]
  mrs r0, spsr
  str r0, [sp, #0x1C]
  mov r3, sp
  cps #0x1F
  str sp, [r3, #0x20]
  str lr, [r3, #0x24]
  bl Os_Hal_CoreGetId_Asm
  Os_Hal_Asm_LoadRegister32 r1, OsCfg_Stack_KernelStacks
  mov r2, #0x4
  mul r2, r2, r0
  add r1, r1, r2
  ldr r2, [r1, #0]
  ldr sp, [r2, #0]
  mov r1, #7
  bl Os_Hal_Context_SaveExcContext
  mov r0, #7
  ldr r1, [r3, #0x18]
  cmp r0, #7
  bleq Os_Hal_Sub4FromReg
  ldr r2, [r3, #0x1C]
  and r2, r2, #0x0F
  push {r9, r12}
  bl Os_UnhandledExc
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
Os_Hal_UnhandledSysCallExceptionEntry .asmfunc
  cps #0x17
  stm sp, {r0-r5}
  mov r3, sp
  cps #0x13
  str lr, [r3, #0x18]
  mrs r0, spsr
  str r0, [r3, #0x1C]
  cps #0x1F
  str sp, [r3, #0x20]
  str lr, [r3, #0x24]
  bl Os_Hal_CoreGetId_Asm
  Os_Hal_Asm_LoadRegister32 r1, OsCfg_Stack_KernelStacks
  mov r2, #0x4
  mul r2, r2, r0
  add r1, r1, r2
  ldr r2, [r1, #0]
  ldr sp, [r2, #0]
  mov r1, #2
  bl Os_Hal_Context_SaveExcContext
  mov r0, #2
  ldr r2, [r3, #0x1C]
  ldr r1, [r3, #0x18]
  sub r1, r1, #2
  and r4, r2, #0x20
  cmp r4, #0
  bleq Os_Hal_Sub2FromReg
  and r2, r2, #0x0F
  push {r9, r12}
  bl Os_UnhandledExc
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
Os_Hal_UnhandledExceptionEntry_WithMemoryProtection .asmfunc
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
  mov r1, #7
  bl Os_Hal_Context_SaveExcContext
  mov r0, #7
  ldr r1, [r3, #0x18]
  cmp r0, #7
  bleq Os_Hal_Sub4FromReg
  ldr r2, [r3, #0x1C]
  and r2, r2, #0x0F
  push {r9, r12}
  bl Os_UnhandledExc
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
Os_Hal_UndefinedInstructionExceptionEntry .asmfunc
  stm sp, {r0-r5}
  str lr, [sp, #0x18]
  mrs r0, spsr
  str r0, [sp, #0x1C]
  mov r3, sp
  cps #0x1F
  str sp, [r3, #0x20]
  str lr, [r3, #0x24]
  bl Os_Hal_CoreGetId_Asm
  Os_Hal_Asm_LoadRegister32 r1, OsCfg_Stack_KernelStacks
  mov r2, #0x4
  mul r2, r2, r0
  add r1, r1, r2
  ldr r2, [r1, #0]
  ldr sp, [r2, #0]
  mov r1, #1
  bl Os_Hal_Context_SaveExcContext
  mov r0, #1
  ldr r2, [r3, #0x1C]
  ldr r1, [r3, #0x18]
  sub r1, r1, #2
  and r4, r2, #0x20
  cmp r4, #0
  bleq Os_Hal_Sub2FromReg
  and r2, r2, #0x0F
  push {r9, r12}
  bl Os_UnhandledExc
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
Os_Hal_UndefinedInstructionExceptionEntry_WithMemoryProtection .asmfunc
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
  mov r1, #1
  bl Os_Hal_Context_SaveExcContext
  mov r0, #1
  ldr r2, [r3, #0x1C]
  ldr r1, [r3, #0x18]
  sub r1, r1, #2
  and r4, r2, #0x20
  cmp r4, #0
  bleq Os_Hal_Sub2FromReg
  and r2, r2, #0x0F
  push {r9, r12}
  bl Os_UnhandledExc
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
Os_Hal_DataAbortExceptionEntry .asmfunc
  stm sp, {r0-r5}
  str lr, [sp, #0x18]
  mrs r0, spsr
  str r0, [sp, #0x1C]
  mov r3, sp
  cps #0x1F
  str sp, [r3, #0x20]
  str lr, [r3, #0x24]
  bl Os_Hal_CoreGetId_Asm
  Os_Hal_Asm_LoadRegister32 r1, OsCfg_Stack_KernelStacks
  mov r2, #0x4
  mul r2, r2, r0
  add r1, r1, r2
  ldr r2, [r1, #0]
  ldr sp, [r2, #0]
  mov r1, #4
  bl Os_Hal_Context_SaveExcContext
  mov r0, #4
  ldr r1, [r3, #0x18]
  sub r1, r1, #8
  ldr r2, [r3, #0x1C]
  and r2, r2, #0x0F
  push {r9, r12}
  bl Os_UnhandledExc
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
Os_Hal_PrefetchAbortExceptionEntry .asmfunc
  stm sp, {r0-r5}
  str lr, [sp, #0x18]
  mrs r0, spsr
  str r0, [sp, #0x1C]
  mov r3, sp
  cps #0x1F
  str sp, [r3, #0x20]
  str lr, [r3, #0x24]
  bl Os_Hal_CoreGetId_Asm
  Os_Hal_Asm_LoadRegister32 r1, OsCfg_Stack_KernelStacks
  mov r2, #0x4
  mul r2, r2, r0
  add r1, r1, r2
  ldr r2, [r1, #0]
  ldr sp, [r2, #0]
  mov r1, #3
  bl Os_Hal_Context_SaveExcContext
  mov r0, #3
  ldr r1, [r3, #0x18]
  sub r1, r1, #4
  ldr r2, [r3, #0x1C]
  and r2, r2, #0x0F
  push {r9, r12}
  bl Os_UnhandledExc
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
  .global OsCfg_Stack_KernelStacks
  .global Os_UnhandledExc
  .global Os_UnhandledIrq
Os_Hal_Jacinto_SpuriousIRQ_Handler .asmfunc
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endasmfunc
Os_Hal_Jacinto_PulseIntClear .asmfunc
  str r0, [r1, #0x410]
  bx lr
  .endasmfunc
Os_Hal_IrqInterruptEntry_Jacinto7_Mcu .macro
  sub lr,lr,#4
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  movw r2, #0x0000
  movt r2, #0x40F8
  ldr r8, [r2, #0x18]
  ldr r1, [r2, #0x20]
  lsrs r1, r1, #31
  cmp r1, #0
  beq Os_Hal_Jacinto_SpuriousIRQ_Handler
  ldr r0, [r2, #0x20]
  movw r3, #0x3FF
  and r0, r0, r3
  lsr r1, r0, #0x5
  and r0, r0, #0x1F
  add r1, r2, r1, lsl #0x5
  mov r3, #0x1
  lsl r0, r3, r0
  ldr r3, [r1, #0x41C]
  and r3, r3, r0
  cmp r3, #0
  blne Os_Hal_Jacinto_PulseIntClear
  mov pc, r8
  .endm
Os_Hal_FiqInterruptEntry_Jacinto7_Mcu .macro
  sub lr,lr,#4
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  movw r2, #0x0000
  movt r2, #0x40F8
  ldr r8, [r2, #0x1C]
  ldr r1, [r2, #0x24]
  lsrs r1, r1, #31
  cmp r1, #0
  beq Os_Hal_Jacinto_SpuriousIRQ_Handler
  ldr r0, [r2, #0x24]
  movw r3, #0x3FF
  and r0, r0, r3
  lsr r1, r0, #0x5
  and r0, r0, #0x1F
  add r1, r2, r1, lsl #0x5
  mov r3, #0x1
  lsl r0, r3, r0
  ldr r3, [r1, #0x41C]
  and r3, r3, r0
  cmp r3, #0
  blne Os_Hal_Jacinto_PulseIntClear
  mov pc, r8
  .endm
Os_Hal_IrqInterruptEntry_Jacinto7_Main .macro
  sub lr,lr,#4
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  movw r2, #0x0000
  movt r2, #0x0FF8
  ldr r8, [r2, #0x18]
  ldr r1, [r2, #0x20]
  lsrs r1, r1, #31
  cmp r1, #0
  beq Os_Hal_Jacinto_SpuriousIRQ_Handler
  ldr r0, [r2, #0x20]
  movw r3, #0x3FF
  and r0, r0, r3
  lsr r1, r0, #0x5
  and r0, r0, #0x1F
  add r1, r2, r1, lsl #0x5
  mov r3, #0x1
  lsl r0, r3, r0
  ldr r3, [r1, #0x41C]
  and r3, r3, r0
  cmp r3, #0
  blne Os_Hal_Jacinto_PulseIntClear
  mov pc, r8
  .endm
Os_Hal_FiqInterruptEntry_Jacinto7_Main .macro
  sub lr,lr,#4
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  movw r2, #0x0000
  movt r2, #0x0FF8
  ldr r8, [r2, #0x1C]
  ldr r1, [r2, #0x24]
  lsrs r1, r1, #31
  cmp r1, #0
  beq Os_Hal_Jacinto_SpuriousIRQ_Handler
  ldr r0, [r2, #0x24]
  movw r3, #0x3FF
  and r0, r0, r3
  lsr r1, r0, #0x5
  and r0, r0, #0x1F
  add r1, r2, r1, lsl #0x5
  mov r3, #0x1
  lsl r0, r3, r0
  ldr r3, [r1, #0x41C]
  and r3, r3, r0
  cmp r3, #0
  blne Os_Hal_Jacinto_PulseIntClear
  mov pc, r8
  .endm
Os_Hal_CatEntry_Interrupt_Jacinto7 .macro JumpTarget
 
  bl JumpTarget
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endm
Os_Hal_Cat2Entry_Interrupt_Jacinto7 .macro IsrConfig
 
  Os_Hal_Asm_LoadRegister32 r0, IsrConfig
  bl Os_IsrRun
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endm
Os_Hal_UnhandledInterruptEntry_Jacinto7 .macro Id
 
  mov r0, #Id
  ldr r1, [sp, #0x1C]
  ldr r2, [sp, #0x20]
  and r2, r2, #0xF
  sub r1, r1, #4
  bl Os_UnhandledIrq
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endm
  .global Os_IsrRun
  .global Os_UnhandledIrq
Os_Hal_Handle_Traveo_Spurious_Interrupt .asmfunc
  movw r0, #0x0000
  movt r0, #0xB040
  ldrh r1, [r0, #0xC]
  str r1, [r0, #0xC48]
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endasmfunc
Os_Hal_Handle_E3_Spurious_Interrupt .asmfunc
  str r0, [r2, #0xF00]
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endasmfunc
Os_Hal_Cat2Entry_SiintcInterrupt .macro IsrConfig
 
  sub lr,lr,#4
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  movw r2, #0x0104
  movt r2, #0x1000
  mov r0, #0
  str r0, [r2]
  dsb
  Os_Hal_Asm_LoadRegister32 r0, IsrConfig
  movw r2, #0x0100
  movt r2, #0x1000
  ldr r1,[r0, #4]
  lsl r1, r1, #2
  str r1, [r2]
  bl Os_IsrRun
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endm
Os_Hal_CatEntry_SiintcInterrupt .macro JumpTarget
 
  sub lr,lr,#4
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  movw r2, #0x0104
  movt r2, #0x1000
  mov r0, #0
  str r0, [r2]
  dsb
  bl JumpTarget
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endm
Os_Hal_Cat2Entry_Interrupt_Traveo .macro IsrConfig
 
  sub lr,lr,#4
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  movw r0, #0x0000
  movt r0, #0xB040
  ldrb r1, [r0, #0xE]
  ldr r0, [r0, #0xC90]
  cmp r0, r1
  bls Os_Hal_Handle_Traveo_Spurious_Interrupt
  Os_Hal_Asm_LoadRegister32 r0, IsrConfig
  bl Os_IsrRun
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endm
Os_Hal_CatEntry_Interrupt_Traveo .macro JumpTarget
 
  sub lr,lr,#4
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  movw r0, #0x0000
  movt r0, #0xB040
  ldrb r1, [r0, #0xE]
  ldr r0, [r0, #0xC90]
  cmp r0, r1
  bls Os_Hal_Handle_Traveo_Spurious_Interrupt
  bl JumpTarget
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endm
Os_Hal_Cat2Entry_Interrupt_E3 .macro IsrConfig, SourceId, BaseAddr, CurrentPrio
 
  sub lr,lr,#4
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  Os_Hal_Asm_LoadRegister32 r1, SourceId
  Os_Hal_Asm_LoadRegister32 r2, BaseAddr
  add r2, r2, #0x80
  lsr r0, r1, #0x5
  add r0, r2, r0, lsl #0x2
  ldr r3, [r0]
  mov r2, #0x1
  and r1, r1, #0x1F
  lsl r1, r2, r1
  and r0, r3, r1
  cmp r0, r1
  Os_Hal_Asm_LoadRegister32 r2, BaseAddr
  bne Os_Hal_Handle_E3_Spurious_Interrupt
  Os_Hal_Asm_LoadRegister32 r0, IsrConfig
  Os_Hal_Asm_LoadRegister32 r2, BaseAddr
  add r2, r2, #0x3C8
  ldr r3, [r2]
  clz r2, r3
  mov r3, #0x20
  sub r1, r3, r2
  Os_Hal_Asm_LoadRegister32 r2, CurrentPrio
  cmp r1,r2
  Os_Hal_Asm_LoadRegister32 r2, BaseAddr
  bls Os_Hal_Handle_E3_Spurious_Interrupt
  bl Os_IsrRun
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endm
Os_Hal_CatEntry_Interrupt_E3 .macro JumpTarget, SourceId, BaseAddr, CurrentPrio
 
  sub lr,lr,#4
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  Os_Hal_Asm_LoadRegister32 r1, SourceId
  Os_Hal_Asm_LoadRegister32 r2, BaseAddr
  add r2, r2, #0x80
  lsr r0, r1, #0x5
  add r0, r2, r0, lsl #0x2
  ldr r3, [r0]
  mov r2, #0x1
  and r1, r1, #0x1F
  lsl r1, r2, r1
  and r0, r3, r1
  cmp r0, r1
  Os_Hal_Asm_LoadRegister32 r2, BaseAddr
  bne Os_Hal_Handle_E3_Spurious_Interrupt
  Os_Hal_Asm_LoadRegister32 r2, BaseAddr
  add r2, r2, #0x3C8
  ldr r3, [r2]
  clz r2, r3
  mov r3, #0x20
  sub r1, r3, r2
  Os_Hal_Asm_LoadRegister32 r2, CurrentPrio
  cmp r1,r2
  Os_Hal_Asm_LoadRegister32 r2, BaseAddr
  bls Os_Hal_Handle_E3_Spurious_Interrupt
  bl JumpTarget
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endm
Os_Hal_Cat2Entry_Interrupt .macro IsrConfig
 
  sub lr,lr,#4
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  Os_Hal_Asm_LoadRegister32 r0, IsrConfig
  bl Os_IsrRun
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endm
Os_Hal_CatEntry_Interrupt .macro JumpTarget
 
  sub lr,lr,#4
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  bl JumpTarget
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endm
Os_Hal_IsrEntry_Interrupt_Gic .macro JumpTarget
 
  sub lr,lr,#4
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  ldr r0, [sp, #0x1C]
  ldr r1, [sp, #0x20]
  and r1, r1, #0xF
  bl JumpTarget
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endm
Os_Hal_UnhandledInterruptEntry .macro Id
 
  srsfd sp!, #0x1f
  cps #0x1f
  push {r0-r3,r8,r12,lr}
  mov r0, #Id
  ldr r1, [sp, #0x1C]
  ldr r2, [sp, #0x20]
  and r2, r2, #0xF
  sub r1, r1, #4
  bl Os_UnhandledIrq
  pop {r0-r3,r8,r12,lr}
  rfefd sp!
  .endm
  .arm
  .sect .OS_CODE, RO
  .global Os_Hal_SysCallHandler_Jacinto7
  .global Os_Hal_MemFault_PrefetchAbort
  .global Os_Hal_MemFault_DataAbort
  .sect .OS_CODE, RO
  .def Os_Hal_IrqHandler_Jacinto7_Mcu_Core0
Os_Hal_IrqHandler_Jacinto7_Mcu_Core0 .asmfunc
  Os_Hal_IrqInterruptEntry_Jacinto7_Mcu
  .endasmfunc
  .def Os_Hal_FiqHandler_Jacinto7_Mcu_Core0
Os_Hal_FiqHandler_Jacinto7_Mcu_Core0 .asmfunc
  Os_Hal_FiqInterruptEntry_Jacinto7_Mcu
  .endasmfunc
  .global _c_int00
  .sect .OS_EXCVEC_CORE0_CODE, RO
  .def OsCfg_Hal_Core_OsCore0_ExceptionTable
OsCfg_Hal_Core_OsCore0_ExceptionTable
  ldr pc,[pc,#0x18]
  ldr pc,[pc,#0x18]
  ldr pc,[pc,#0x18]
  ldr pc,[pc,#0x18]
  ldr pc,[pc,#0x18]
  ldr pc,[pc,#0x18]
  ldr pc,[pc,#0x18]
  ldr pc,[pc,#0x18]
Os_Hal_Core_0_Exception_0_Address
  .long _c_int00
Os_Hal_Core_0_Exception_1_Address
  .long Os_Hal_UndefinedInstructionExceptionEntry_WithMemoryProtection
Os_Hal_Core_0_Exception_2_Address
  .long Os_Hal_SysCallHandler_Jacinto7
Os_Hal_Core_0_Exception_3_Address
  .long Os_Hal_MemFault_PrefetchAbort
Os_Hal_Core_0_Exception_4_Address
  .long Os_Hal_MemFault_DataAbort
Os_Hal_Core_0_Exception_5_Address
  .long Os_Hal_UnhandledExceptionEntry_WithMemoryProtection
Os_Hal_Core_0_Exception_6_Address
  .long Os_Hal_IrqHandler_Jacinto7_Mcu_Core0
Os_Hal_Core_0_Exception_7_Address
  .long Os_Hal_FiqHandler_Jacinto7_Mcu_Core0
  .sect .OS_INTVEC_CORE0_CODE, RO
  .def Os_Isr_Core0_Interrupt_0
  .global OsCfg_Isr_Can_30_McanIsr_0
Os_Isr_Core0_Interrupt_0 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_Can_30_McanIsr_0
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_2
  .global OsCfg_Isr_Can_30_McanIsr_1
Os_Isr_Core0_Interrupt_2 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_Can_30_McanIsr_1
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_6
  .global OsCfg_Isr_ADC0
Os_Isr_Core0_Interrupt_6 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_ADC0
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_7
  .global OsCfg_Isr_ADC1
Os_Isr_Core0_Interrupt_7 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_ADC1
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_18
  .global OsCfg_Isr_I2c_IrqUnit0
Os_Isr_Core0_Interrupt_18 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_I2c_IrqUnit0
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_36
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36
Os_Isr_Core0_Interrupt_36 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_37
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37
Os_Isr_Core0_Interrupt_37 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_39
  .global OsCfg_Isr_CounterIsr_SystemTimer
Os_Isr_Core0_Interrupt_39 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_CounterIsr_SystemTimer
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_44
  .global OsCfg_Isr_vHsmResponseIsr
Os_Isr_Core0_Interrupt_44 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_vHsmResponseIsr
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_47
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47
Os_Isr_Core0_Interrupt_47 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_48
  .global OsCfg_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0
Os_Isr_Core0_Interrupt_48 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_49
  .global OsCfg_Isr_MCU_ESM0_ESM_INT_HI_LVL_0
Os_Isr_Core0_Interrupt_49 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MCU_ESM0_ESM_INT_HI_LVL_0
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_53
  .global OsCfg_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0
Os_Isr_Core0_Interrupt_53 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_70
  .global OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn1
Os_Isr_Core0_Interrupt_70 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn1
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_71
  .global OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn2
Os_Isr_Core0_Interrupt_71 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn2
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_72
  .global OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn3
Os_Isr_Core0_Interrupt_72 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn3
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_73
  .global OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn4
Os_Isr_Core0_Interrupt_73 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn4
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_78
  .global OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78
Os_Isr_Core0_Interrupt_78 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_79
  .global OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79
Os_Isr_Core0_Interrupt_79 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_96
  .global OsCfg_Isr_I2c_IrqUnit1
Os_Isr_Core0_Interrupt_96 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_I2c_IrqUnit1
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_98
  .global OsCfg_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0
Os_Isr_Core0_Interrupt_98 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_99
  .global OsCfg_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0
Os_Isr_Core0_Interrupt_99 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_100
  .global OsCfg_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0
Os_Isr_Core0_Interrupt_100 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_140
  .global OsCfg_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0
Os_Isr_Core0_Interrupt_140 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_141
  .global OsCfg_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0
Os_Isr_Core0_Interrupt_141 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_142
  .global OsCfg_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0
Os_Isr_Core0_Interrupt_142 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_290
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290
Os_Isr_Core0_Interrupt_290 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_291
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291
Os_Isr_Core0_Interrupt_291 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_295
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295
Os_Isr_Core0_Interrupt_295 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_296
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296
Os_Isr_Core0_Interrupt_296 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_297
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297
Os_Isr_Core0_Interrupt_297 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_298
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298
Os_Isr_Core0_Interrupt_298 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_299
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299
Os_Isr_Core0_Interrupt_299 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_300
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300
Os_Isr_Core0_Interrupt_300 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_304
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304
Os_Isr_Core0_Interrupt_304 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_305
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305
Os_Isr_Core0_Interrupt_305 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_306
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306
Os_Isr_Core0_Interrupt_306 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_307
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307
Os_Isr_Core0_Interrupt_307 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_308
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308
Os_Isr_Core0_Interrupt_308 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_309
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309
Os_Isr_Core0_Interrupt_309 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_310
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310
Os_Isr_Core0_Interrupt_310 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_312
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312
Os_Isr_Core0_Interrupt_312 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_313
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313
Os_Isr_Core0_Interrupt_313 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_314
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314
Os_Isr_Core0_Interrupt_314 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_317
  .global OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317
Os_Isr_Core0_Interrupt_317 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_376
  .global OsCfg_Isr_IPC_mailbox1
Os_Isr_Core0_Interrupt_376 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_IPC_mailbox1
  .endasmfunc
  .def Os_Isr_Core0_Interrupt_377
  .global OsCfg_Isr_IPC_mailbox2
Os_Isr_Core0_Interrupt_377 .asmfunc
  Os_Hal_Cat2Entry_Interrupt_Jacinto7 OsCfg_Isr_IPC_mailbox2
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_1
Os_Isr_Core0_UnhandledInterrupt_1 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 1
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_3
Os_Isr_Core0_UnhandledInterrupt_3 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 3
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_4
Os_Isr_Core0_UnhandledInterrupt_4 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 4
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_5
Os_Isr_Core0_UnhandledInterrupt_5 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 5
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_8
Os_Isr_Core0_UnhandledInterrupt_8 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 8
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_9
Os_Isr_Core0_UnhandledInterrupt_9 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 9
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_10
Os_Isr_Core0_UnhandledInterrupt_10 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 10
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_11
Os_Isr_Core0_UnhandledInterrupt_11 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 11
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_12
Os_Isr_Core0_UnhandledInterrupt_12 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 12
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_13
Os_Isr_Core0_UnhandledInterrupt_13 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 13
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_14
Os_Isr_Core0_UnhandledInterrupt_14 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 14
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_15
Os_Isr_Core0_UnhandledInterrupt_15 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 15
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_16
Os_Isr_Core0_UnhandledInterrupt_16 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 16
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_17
Os_Isr_Core0_UnhandledInterrupt_17 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 17
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_19
Os_Isr_Core0_UnhandledInterrupt_19 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 19
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_20
Os_Isr_Core0_UnhandledInterrupt_20 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 20
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_21
Os_Isr_Core0_UnhandledInterrupt_21 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 21
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_22
Os_Isr_Core0_UnhandledInterrupt_22 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 22
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_23
Os_Isr_Core0_UnhandledInterrupt_23 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 23
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_24
Os_Isr_Core0_UnhandledInterrupt_24 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 24
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_25
Os_Isr_Core0_UnhandledInterrupt_25 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 25
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_26
Os_Isr_Core0_UnhandledInterrupt_26 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 26
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_27
Os_Isr_Core0_UnhandledInterrupt_27 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 27
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_28
Os_Isr_Core0_UnhandledInterrupt_28 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 28
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_29
Os_Isr_Core0_UnhandledInterrupt_29 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 29
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_30
Os_Isr_Core0_UnhandledInterrupt_30 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 30
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_31
Os_Isr_Core0_UnhandledInterrupt_31 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 31
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_32
Os_Isr_Core0_UnhandledInterrupt_32 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 32
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_33
Os_Isr_Core0_UnhandledInterrupt_33 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 33
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_34
Os_Isr_Core0_UnhandledInterrupt_34 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 34
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_35
Os_Isr_Core0_UnhandledInterrupt_35 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 35
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_38
Os_Isr_Core0_UnhandledInterrupt_38 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 38
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_40
Os_Isr_Core0_UnhandledInterrupt_40 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 40
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_41
Os_Isr_Core0_UnhandledInterrupt_41 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 41
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_42
Os_Isr_Core0_UnhandledInterrupt_42 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 42
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_43
Os_Isr_Core0_UnhandledInterrupt_43 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 43
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_45
Os_Isr_Core0_UnhandledInterrupt_45 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 45
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_46
Os_Isr_Core0_UnhandledInterrupt_46 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 46
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_50
Os_Isr_Core0_UnhandledInterrupt_50 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 50
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_51
Os_Isr_Core0_UnhandledInterrupt_51 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 51
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_52
Os_Isr_Core0_UnhandledInterrupt_52 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 52
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_54
Os_Isr_Core0_UnhandledInterrupt_54 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 54
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_55
Os_Isr_Core0_UnhandledInterrupt_55 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 55
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_56
Os_Isr_Core0_UnhandledInterrupt_56 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 56
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_57
Os_Isr_Core0_UnhandledInterrupt_57 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 57
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_58
Os_Isr_Core0_UnhandledInterrupt_58 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 58
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_59
Os_Isr_Core0_UnhandledInterrupt_59 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 59
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_60
Os_Isr_Core0_UnhandledInterrupt_60 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 60
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_61
Os_Isr_Core0_UnhandledInterrupt_61 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 61
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_62
Os_Isr_Core0_UnhandledInterrupt_62 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 62
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_63
Os_Isr_Core0_UnhandledInterrupt_63 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 63
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_64
Os_Isr_Core0_UnhandledInterrupt_64 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 64
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_65
Os_Isr_Core0_UnhandledInterrupt_65 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 65
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_66
Os_Isr_Core0_UnhandledInterrupt_66 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 66
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_67
Os_Isr_Core0_UnhandledInterrupt_67 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 67
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_68
Os_Isr_Core0_UnhandledInterrupt_68 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 68
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_69
Os_Isr_Core0_UnhandledInterrupt_69 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 69
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_74
Os_Isr_Core0_UnhandledInterrupt_74 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 74
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_75
Os_Isr_Core0_UnhandledInterrupt_75 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 75
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_76
Os_Isr_Core0_UnhandledInterrupt_76 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 76
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_77
Os_Isr_Core0_UnhandledInterrupt_77 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 77
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_80
Os_Isr_Core0_UnhandledInterrupt_80 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 80
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_81
Os_Isr_Core0_UnhandledInterrupt_81 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 81
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_82
Os_Isr_Core0_UnhandledInterrupt_82 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 82
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_83
Os_Isr_Core0_UnhandledInterrupt_83 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 83
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_84
Os_Isr_Core0_UnhandledInterrupt_84 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 84
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_85
Os_Isr_Core0_UnhandledInterrupt_85 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 85
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_86
Os_Isr_Core0_UnhandledInterrupt_86 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 86
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_87
Os_Isr_Core0_UnhandledInterrupt_87 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 87
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_88
Os_Isr_Core0_UnhandledInterrupt_88 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 88
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_89
Os_Isr_Core0_UnhandledInterrupt_89 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 89
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_90
Os_Isr_Core0_UnhandledInterrupt_90 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 90
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_91
Os_Isr_Core0_UnhandledInterrupt_91 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 91
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_92
Os_Isr_Core0_UnhandledInterrupt_92 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 92
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_93
Os_Isr_Core0_UnhandledInterrupt_93 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 93
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_94
Os_Isr_Core0_UnhandledInterrupt_94 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 94
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_95
Os_Isr_Core0_UnhandledInterrupt_95 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 95
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_97
Os_Isr_Core0_UnhandledInterrupt_97 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 97
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_101
Os_Isr_Core0_UnhandledInterrupt_101 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 101
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_102
Os_Isr_Core0_UnhandledInterrupt_102 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 102
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_103
Os_Isr_Core0_UnhandledInterrupt_103 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 103
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_104
Os_Isr_Core0_UnhandledInterrupt_104 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 104
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_105
Os_Isr_Core0_UnhandledInterrupt_105 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 105
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_106
Os_Isr_Core0_UnhandledInterrupt_106 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 106
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_107
Os_Isr_Core0_UnhandledInterrupt_107 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 107
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_108
Os_Isr_Core0_UnhandledInterrupt_108 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 108
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_109
Os_Isr_Core0_UnhandledInterrupt_109 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 109
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_110
Os_Isr_Core0_UnhandledInterrupt_110 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 110
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_111
Os_Isr_Core0_UnhandledInterrupt_111 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 111
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_112
Os_Isr_Core0_UnhandledInterrupt_112 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 112
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_113
Os_Isr_Core0_UnhandledInterrupt_113 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 113
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_114
Os_Isr_Core0_UnhandledInterrupt_114 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 114
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_115
Os_Isr_Core0_UnhandledInterrupt_115 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 115
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_116
Os_Isr_Core0_UnhandledInterrupt_116 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 116
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_117
Os_Isr_Core0_UnhandledInterrupt_117 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 117
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_118
Os_Isr_Core0_UnhandledInterrupt_118 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 118
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_119
Os_Isr_Core0_UnhandledInterrupt_119 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 119
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_120
Os_Isr_Core0_UnhandledInterrupt_120 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 120
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_121
Os_Isr_Core0_UnhandledInterrupt_121 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 121
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_122
Os_Isr_Core0_UnhandledInterrupt_122 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 122
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_123
Os_Isr_Core0_UnhandledInterrupt_123 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 123
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_124
Os_Isr_Core0_UnhandledInterrupt_124 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 124
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_125
Os_Isr_Core0_UnhandledInterrupt_125 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 125
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_126
Os_Isr_Core0_UnhandledInterrupt_126 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 126
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_127
Os_Isr_Core0_UnhandledInterrupt_127 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 127
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_128
Os_Isr_Core0_UnhandledInterrupt_128 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 128
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_129
Os_Isr_Core0_UnhandledInterrupt_129 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 129
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_130
Os_Isr_Core0_UnhandledInterrupt_130 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 130
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_131
Os_Isr_Core0_UnhandledInterrupt_131 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 131
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_132
Os_Isr_Core0_UnhandledInterrupt_132 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 132
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_133
Os_Isr_Core0_UnhandledInterrupt_133 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 133
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_134
Os_Isr_Core0_UnhandledInterrupt_134 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 134
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_135
Os_Isr_Core0_UnhandledInterrupt_135 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 135
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_136
Os_Isr_Core0_UnhandledInterrupt_136 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 136
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_137
Os_Isr_Core0_UnhandledInterrupt_137 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 137
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_138
Os_Isr_Core0_UnhandledInterrupt_138 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 138
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_139
Os_Isr_Core0_UnhandledInterrupt_139 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 139
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_143
Os_Isr_Core0_UnhandledInterrupt_143 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 143
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_144
Os_Isr_Core0_UnhandledInterrupt_144 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 144
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_145
Os_Isr_Core0_UnhandledInterrupt_145 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 145
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_146
Os_Isr_Core0_UnhandledInterrupt_146 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 146
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_147
Os_Isr_Core0_UnhandledInterrupt_147 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 147
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_148
Os_Isr_Core0_UnhandledInterrupt_148 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 148
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_149
Os_Isr_Core0_UnhandledInterrupt_149 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 149
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_150
Os_Isr_Core0_UnhandledInterrupt_150 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 150
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_151
Os_Isr_Core0_UnhandledInterrupt_151 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 151
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_152
Os_Isr_Core0_UnhandledInterrupt_152 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 152
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_153
Os_Isr_Core0_UnhandledInterrupt_153 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 153
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_154
Os_Isr_Core0_UnhandledInterrupt_154 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 154
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_155
Os_Isr_Core0_UnhandledInterrupt_155 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 155
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_156
Os_Isr_Core0_UnhandledInterrupt_156 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 156
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_157
Os_Isr_Core0_UnhandledInterrupt_157 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 157
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_158
Os_Isr_Core0_UnhandledInterrupt_158 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 158
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_159
Os_Isr_Core0_UnhandledInterrupt_159 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 159
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_160
Os_Isr_Core0_UnhandledInterrupt_160 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 160
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_161
Os_Isr_Core0_UnhandledInterrupt_161 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 161
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_162
Os_Isr_Core0_UnhandledInterrupt_162 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 162
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_163
Os_Isr_Core0_UnhandledInterrupt_163 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 163
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_164
Os_Isr_Core0_UnhandledInterrupt_164 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 164
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_165
Os_Isr_Core0_UnhandledInterrupt_165 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 165
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_166
Os_Isr_Core0_UnhandledInterrupt_166 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 166
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_167
Os_Isr_Core0_UnhandledInterrupt_167 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 167
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_168
Os_Isr_Core0_UnhandledInterrupt_168 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 168
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_169
Os_Isr_Core0_UnhandledInterrupt_169 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 169
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_170
Os_Isr_Core0_UnhandledInterrupt_170 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 170
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_171
Os_Isr_Core0_UnhandledInterrupt_171 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 171
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_172
Os_Isr_Core0_UnhandledInterrupt_172 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 172
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_173
Os_Isr_Core0_UnhandledInterrupt_173 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 173
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_174
Os_Isr_Core0_UnhandledInterrupt_174 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 174
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_175
Os_Isr_Core0_UnhandledInterrupt_175 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 175
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_176
Os_Isr_Core0_UnhandledInterrupt_176 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 176
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_177
Os_Isr_Core0_UnhandledInterrupt_177 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 177
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_178
Os_Isr_Core0_UnhandledInterrupt_178 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 178
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_179
Os_Isr_Core0_UnhandledInterrupt_179 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 179
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_180
Os_Isr_Core0_UnhandledInterrupt_180 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 180
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_181
Os_Isr_Core0_UnhandledInterrupt_181 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 181
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_182
Os_Isr_Core0_UnhandledInterrupt_182 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 182
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_183
Os_Isr_Core0_UnhandledInterrupt_183 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 183
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_184
Os_Isr_Core0_UnhandledInterrupt_184 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 184
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_185
Os_Isr_Core0_UnhandledInterrupt_185 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 185
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_186
Os_Isr_Core0_UnhandledInterrupt_186 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 186
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_187
Os_Isr_Core0_UnhandledInterrupt_187 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 187
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_188
Os_Isr_Core0_UnhandledInterrupt_188 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 188
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_189
Os_Isr_Core0_UnhandledInterrupt_189 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 189
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_190
Os_Isr_Core0_UnhandledInterrupt_190 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 190
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_191
Os_Isr_Core0_UnhandledInterrupt_191 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 191
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_192
Os_Isr_Core0_UnhandledInterrupt_192 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 192
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_193
Os_Isr_Core0_UnhandledInterrupt_193 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 193
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_194
Os_Isr_Core0_UnhandledInterrupt_194 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 194
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_195
Os_Isr_Core0_UnhandledInterrupt_195 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 195
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_196
Os_Isr_Core0_UnhandledInterrupt_196 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 196
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_197
Os_Isr_Core0_UnhandledInterrupt_197 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 197
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_198
Os_Isr_Core0_UnhandledInterrupt_198 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 198
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_199
Os_Isr_Core0_UnhandledInterrupt_199 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 199
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_200
Os_Isr_Core0_UnhandledInterrupt_200 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 200
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_201
Os_Isr_Core0_UnhandledInterrupt_201 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 201
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_202
Os_Isr_Core0_UnhandledInterrupt_202 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 202
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_203
Os_Isr_Core0_UnhandledInterrupt_203 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 203
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_204
Os_Isr_Core0_UnhandledInterrupt_204 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 204
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_205
Os_Isr_Core0_UnhandledInterrupt_205 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 205
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_206
Os_Isr_Core0_UnhandledInterrupt_206 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 206
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_207
Os_Isr_Core0_UnhandledInterrupt_207 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 207
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_208
Os_Isr_Core0_UnhandledInterrupt_208 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 208
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_209
Os_Isr_Core0_UnhandledInterrupt_209 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 209
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_210
Os_Isr_Core0_UnhandledInterrupt_210 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 210
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_211
Os_Isr_Core0_UnhandledInterrupt_211 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 211
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_212
Os_Isr_Core0_UnhandledInterrupt_212 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 212
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_213
Os_Isr_Core0_UnhandledInterrupt_213 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 213
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_214
Os_Isr_Core0_UnhandledInterrupt_214 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 214
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_215
Os_Isr_Core0_UnhandledInterrupt_215 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 215
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_216
Os_Isr_Core0_UnhandledInterrupt_216 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 216
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_217
Os_Isr_Core0_UnhandledInterrupt_217 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 217
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_218
Os_Isr_Core0_UnhandledInterrupt_218 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 218
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_219
Os_Isr_Core0_UnhandledInterrupt_219 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 219
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_220
Os_Isr_Core0_UnhandledInterrupt_220 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 220
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_221
Os_Isr_Core0_UnhandledInterrupt_221 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 221
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_222
Os_Isr_Core0_UnhandledInterrupt_222 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 222
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_223
Os_Isr_Core0_UnhandledInterrupt_223 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 223
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_224
Os_Isr_Core0_UnhandledInterrupt_224 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 224
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_225
Os_Isr_Core0_UnhandledInterrupt_225 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 225
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_226
Os_Isr_Core0_UnhandledInterrupt_226 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 226
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_227
Os_Isr_Core0_UnhandledInterrupt_227 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 227
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_228
Os_Isr_Core0_UnhandledInterrupt_228 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 228
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_229
Os_Isr_Core0_UnhandledInterrupt_229 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 229
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_230
Os_Isr_Core0_UnhandledInterrupt_230 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 230
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_231
Os_Isr_Core0_UnhandledInterrupt_231 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 231
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_232
Os_Isr_Core0_UnhandledInterrupt_232 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 232
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_233
Os_Isr_Core0_UnhandledInterrupt_233 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 233
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_234
Os_Isr_Core0_UnhandledInterrupt_234 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 234
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_235
Os_Isr_Core0_UnhandledInterrupt_235 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 235
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_236
Os_Isr_Core0_UnhandledInterrupt_236 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 236
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_237
Os_Isr_Core0_UnhandledInterrupt_237 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 237
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_238
Os_Isr_Core0_UnhandledInterrupt_238 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 238
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_239
Os_Isr_Core0_UnhandledInterrupt_239 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 239
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_240
Os_Isr_Core0_UnhandledInterrupt_240 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 240
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_241
Os_Isr_Core0_UnhandledInterrupt_241 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 241
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_242
Os_Isr_Core0_UnhandledInterrupt_242 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 242
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_243
Os_Isr_Core0_UnhandledInterrupt_243 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 243
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_244
Os_Isr_Core0_UnhandledInterrupt_244 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 244
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_245
Os_Isr_Core0_UnhandledInterrupt_245 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 245
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_246
Os_Isr_Core0_UnhandledInterrupt_246 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 246
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_247
Os_Isr_Core0_UnhandledInterrupt_247 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 247
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_248
Os_Isr_Core0_UnhandledInterrupt_248 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 248
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_249
Os_Isr_Core0_UnhandledInterrupt_249 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 249
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_250
Os_Isr_Core0_UnhandledInterrupt_250 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 250
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_251
Os_Isr_Core0_UnhandledInterrupt_251 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 251
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_252
Os_Isr_Core0_UnhandledInterrupt_252 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 252
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_253
Os_Isr_Core0_UnhandledInterrupt_253 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 253
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_254
Os_Isr_Core0_UnhandledInterrupt_254 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 254
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_255
Os_Isr_Core0_UnhandledInterrupt_255 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 255
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_256
Os_Isr_Core0_UnhandledInterrupt_256 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 256
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_257
Os_Isr_Core0_UnhandledInterrupt_257 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 257
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_258
Os_Isr_Core0_UnhandledInterrupt_258 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 258
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_259
Os_Isr_Core0_UnhandledInterrupt_259 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 259
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_260
Os_Isr_Core0_UnhandledInterrupt_260 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 260
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_261
Os_Isr_Core0_UnhandledInterrupt_261 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 261
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_262
Os_Isr_Core0_UnhandledInterrupt_262 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 262
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_263
Os_Isr_Core0_UnhandledInterrupt_263 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 263
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_264
Os_Isr_Core0_UnhandledInterrupt_264 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 264
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_265
Os_Isr_Core0_UnhandledInterrupt_265 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 265
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_266
Os_Isr_Core0_UnhandledInterrupt_266 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 266
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_267
Os_Isr_Core0_UnhandledInterrupt_267 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 267
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_268
Os_Isr_Core0_UnhandledInterrupt_268 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 268
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_269
Os_Isr_Core0_UnhandledInterrupt_269 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 269
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_270
Os_Isr_Core0_UnhandledInterrupt_270 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 270
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_271
Os_Isr_Core0_UnhandledInterrupt_271 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 271
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_272
Os_Isr_Core0_UnhandledInterrupt_272 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 272
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_273
Os_Isr_Core0_UnhandledInterrupt_273 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 273
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_274
Os_Isr_Core0_UnhandledInterrupt_274 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 274
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_275
Os_Isr_Core0_UnhandledInterrupt_275 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 275
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_276
Os_Isr_Core0_UnhandledInterrupt_276 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 276
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_277
Os_Isr_Core0_UnhandledInterrupt_277 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 277
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_278
Os_Isr_Core0_UnhandledInterrupt_278 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 278
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_279
Os_Isr_Core0_UnhandledInterrupt_279 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 279
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_280
Os_Isr_Core0_UnhandledInterrupt_280 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 280
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_281
Os_Isr_Core0_UnhandledInterrupt_281 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 281
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_282
Os_Isr_Core0_UnhandledInterrupt_282 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 282
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_283
Os_Isr_Core0_UnhandledInterrupt_283 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 283
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_284
Os_Isr_Core0_UnhandledInterrupt_284 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 284
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_285
Os_Isr_Core0_UnhandledInterrupt_285 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 285
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_286
Os_Isr_Core0_UnhandledInterrupt_286 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 286
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_287
Os_Isr_Core0_UnhandledInterrupt_287 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 287
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_288
Os_Isr_Core0_UnhandledInterrupt_288 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 288
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_289
Os_Isr_Core0_UnhandledInterrupt_289 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 289
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_292
Os_Isr_Core0_UnhandledInterrupt_292 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 292
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_293
Os_Isr_Core0_UnhandledInterrupt_293 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 293
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_294
Os_Isr_Core0_UnhandledInterrupt_294 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 294
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_301
Os_Isr_Core0_UnhandledInterrupt_301 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 301
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_302
Os_Isr_Core0_UnhandledInterrupt_302 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 302
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_303
Os_Isr_Core0_UnhandledInterrupt_303 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 303
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_311
Os_Isr_Core0_UnhandledInterrupt_311 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 311
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_315
Os_Isr_Core0_UnhandledInterrupt_315 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 315
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_316
Os_Isr_Core0_UnhandledInterrupt_316 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 316
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_318
Os_Isr_Core0_UnhandledInterrupt_318 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 318
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_319
Os_Isr_Core0_UnhandledInterrupt_319 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 319
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_320
Os_Isr_Core0_UnhandledInterrupt_320 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 320
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_321
Os_Isr_Core0_UnhandledInterrupt_321 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 321
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_322
Os_Isr_Core0_UnhandledInterrupt_322 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 322
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_323
Os_Isr_Core0_UnhandledInterrupt_323 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 323
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_324
Os_Isr_Core0_UnhandledInterrupt_324 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 324
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_325
Os_Isr_Core0_UnhandledInterrupt_325 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 325
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_326
Os_Isr_Core0_UnhandledInterrupt_326 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 326
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_327
Os_Isr_Core0_UnhandledInterrupt_327 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 327
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_328
Os_Isr_Core0_UnhandledInterrupt_328 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 328
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_329
Os_Isr_Core0_UnhandledInterrupt_329 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 329
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_330
Os_Isr_Core0_UnhandledInterrupt_330 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 330
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_331
Os_Isr_Core0_UnhandledInterrupt_331 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 331
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_332
Os_Isr_Core0_UnhandledInterrupt_332 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 332
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_333
Os_Isr_Core0_UnhandledInterrupt_333 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 333
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_334
Os_Isr_Core0_UnhandledInterrupt_334 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 334
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_335
Os_Isr_Core0_UnhandledInterrupt_335 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 335
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_336
Os_Isr_Core0_UnhandledInterrupt_336 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 336
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_337
Os_Isr_Core0_UnhandledInterrupt_337 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 337
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_338
Os_Isr_Core0_UnhandledInterrupt_338 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 338
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_339
Os_Isr_Core0_UnhandledInterrupt_339 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 339
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_340
Os_Isr_Core0_UnhandledInterrupt_340 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 340
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_341
Os_Isr_Core0_UnhandledInterrupt_341 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 341
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_342
Os_Isr_Core0_UnhandledInterrupt_342 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 342
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_343
Os_Isr_Core0_UnhandledInterrupt_343 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 343
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_344
Os_Isr_Core0_UnhandledInterrupt_344 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 344
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_345
Os_Isr_Core0_UnhandledInterrupt_345 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 345
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_346
Os_Isr_Core0_UnhandledInterrupt_346 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 346
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_347
Os_Isr_Core0_UnhandledInterrupt_347 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 347
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_348
Os_Isr_Core0_UnhandledInterrupt_348 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 348
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_349
Os_Isr_Core0_UnhandledInterrupt_349 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 349
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_350
Os_Isr_Core0_UnhandledInterrupt_350 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 350
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_351
Os_Isr_Core0_UnhandledInterrupt_351 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 351
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_352
Os_Isr_Core0_UnhandledInterrupt_352 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 352
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_353
Os_Isr_Core0_UnhandledInterrupt_353 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 353
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_354
Os_Isr_Core0_UnhandledInterrupt_354 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 354
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_355
Os_Isr_Core0_UnhandledInterrupt_355 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 355
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_356
Os_Isr_Core0_UnhandledInterrupt_356 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 356
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_357
Os_Isr_Core0_UnhandledInterrupt_357 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 357
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_358
Os_Isr_Core0_UnhandledInterrupt_358 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 358
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_359
Os_Isr_Core0_UnhandledInterrupt_359 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 359
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_360
Os_Isr_Core0_UnhandledInterrupt_360 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 360
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_361
Os_Isr_Core0_UnhandledInterrupt_361 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 361
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_362
Os_Isr_Core0_UnhandledInterrupt_362 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 362
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_363
Os_Isr_Core0_UnhandledInterrupt_363 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 363
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_364
Os_Isr_Core0_UnhandledInterrupt_364 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 364
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_365
Os_Isr_Core0_UnhandledInterrupt_365 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 365
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_366
Os_Isr_Core0_UnhandledInterrupt_366 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 366
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_367
Os_Isr_Core0_UnhandledInterrupt_367 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 367
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_368
Os_Isr_Core0_UnhandledInterrupt_368 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 368
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_369
Os_Isr_Core0_UnhandledInterrupt_369 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 369
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_370
Os_Isr_Core0_UnhandledInterrupt_370 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 370
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_371
Os_Isr_Core0_UnhandledInterrupt_371 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 371
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_372
Os_Isr_Core0_UnhandledInterrupt_372 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 372
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_373
Os_Isr_Core0_UnhandledInterrupt_373 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 373
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_374
Os_Isr_Core0_UnhandledInterrupt_374 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 374
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_375
Os_Isr_Core0_UnhandledInterrupt_375 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 375
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_378
Os_Isr_Core0_UnhandledInterrupt_378 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 378
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_379
Os_Isr_Core0_UnhandledInterrupt_379 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 379
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_380
Os_Isr_Core0_UnhandledInterrupt_380 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 380
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_381
Os_Isr_Core0_UnhandledInterrupt_381 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 381
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_382
Os_Isr_Core0_UnhandledInterrupt_382 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 382
  .endasmfunc
  .def Os_Isr_Core0_UnhandledInterrupt_383
Os_Isr_Core0_UnhandledInterrupt_383 .asmfunc
  Os_Hal_UnhandledInterruptEntry_Jacinto7 383
  .endasmfunc
  .end
