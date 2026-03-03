Os_Hal_Asm_Load_Register_Immediate .macro Register, Immediate
  movw Register, Immediate
  movt Register, Immediate
  .endm
Os_Hal_Asm_LoadRegister32 .macro Register, Value
  movw Register, Value
  movt Register, Value
  .endm
  .def Os_Hal_FlushInstructionCache
  .def Os_Hal_FlushDataCache
  .sect .OS_CODE, RO
  .arm
Os_Hal_FlushInstructionCache .asmfunc
  push {r0}
  mov r0, #0
  mcr p15,#0,r0,c7,c5,#0
  mcr p15,#0,r0,c7,c5,#6
  isb
  pop {r0}
  bx lr
  .endasmfunc
Os_Hal_FlushDataCache .asmfunc
  push {r0-r12}
  mrc p15,#1,r0,c0,c0,#1
  ands r3, r0, #0x07000000
  mov r3, r3, LSR #23
  beq Finished
  mov r10, #0
Loop1
  add r2, r10, r10, LSR #1
  mov r1, r0, LSR r2
  and r1, r1, #7
  cmp r1, #2
  blt Skip
  mcr p15,#2,r10,c0,c0,#0
  isb
  mrc p15,#1,r1,c0,c0,#0
  and r2, r1, #7
  add r2, r2, #4
  movw r4, #0x03FF
  movt r4, #0x0000
  ands r4, r4, r1, LSR #3
  clz r5, r4
  mov r9, r4
Loop2
  movw r7, #0x7fff
  movt r7, #0x0000
  ands r7, r7, r1, LSR #13
Loop3
  orr r11, r10, r9, LSL r5
  orr r11, r11, r7, LSL r2
  mcr p15,#0,r11,c7,c10,#2
  subs r7, r7, #1
  bge Loop3
  subs r9, r9, #1
  bge Loop2
Skip
  add r10, r10, #2
  cmp r3, r10
  bgt Loop1
  dsb
Finished
  pop {r0-r12}
  bx lr
  .endasmfunc
  .end
