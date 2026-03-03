;******************************************************************************
;  @file  arm_r5.asm
;
;  @brief
;   Implementation file for the ARM R5 module CSL-FL.
;
;   Contains the different control command and status query functions definitions
;
;   \par
;   ============================================================================
;   @n   (C) Copyright 2018, Texas Instruments, Inc.
;
;   Redistribution and use in source and binary forms, with or without
;   modification, are permitted provided that the following conditions
;   are met:
;
;     Redistributions of source code must retain the above copyright
;     notice, this list of conditions and the following disclaimer.
;
;     Redistributions in binary form must reproduce the above copyright
;     notice, this list of conditions and the following disclaimer in the
;     documentation and/or other materials provided with the
;     distribution.
;
;     Neither the name of Texas Instruments Incorporated nor the names of
;     its contributors may be used to endorse or promote products derived
;     from this software without specific prior written permission.
;
;   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
;   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
;   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
;   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
;   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
;   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
;   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE,
;   DATA, OR PROFITS;  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
;   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
;   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
;   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;******************************************************************************
    .text

;           Below code is for custom MPU configuration - this configuration varies from usecase to usecase




;/* MPU region 1 is the created for the 2GB DDR address space starting with 0x80M to 0xA0M
; *      *
; *   attributes:  xn  = 0 (bit 12)    - execution permitted
; *                ap  = 3 (bits 10:8) - read/write full access, 3=> full access privilege and user
; *                tex = 1 (bits 5:3)  - Normal  				7=> cacheable, write back, no write allocate
; *                S   = 0 (bit 2)     - non-shared 			0=> marking non-shared to enable cache,
; *                CB  = 0 (bits 1:0)  - Noncache  				3=>write back, no write allocate cache
; */


mpu_region_0_base		 .word 0x0      											;The MPU Region Base Address Register
mpu_region_0_size		 .word 0x3f                     							;Region Size and Enable bits (and Subre region enable )
mpu_region_0_permissions .word 0x1104 ;The MPU Region Access Control

mpu_region_1_base		 .word 0x0											;The MPU Region Base Address Register
mpu_region_1_size		 .word 0x1d							;Region Size and Enable bits (and Subre region enable )
mpu_region_1_permissions .word 0x10f;The MPU Region Access Control

mpu_region_2_base		 .word 0x41000000											;The MPU Region Base Address Register
mpu_region_2_size		 .word 0x1d	;Region Size and Enable bits (and Subre region enable )
mpu_region_2_permissions .word 0x10b;The MPU Region Access Control

mpu_region_3_base		 .word 0x41010000											;The MPU Region Base Address Register
mpu_region_3_size		 .word 0x1d							;Region Size and Enable bits (and Subre region enable )
mpu_region_3_permissions .word 0x10b;The MPU Region Access Control

mpu_region_4_base		 .word 0x41c00000											;The MPU Region Base Address Register
mpu_region_4_size		 .word 0x27							;Region Size and Enable bits (and Subre region enable )
mpu_region_4_permissions .word 0x10b;The MPU Region Access Control


mpu_region_5_base        .word 0x70000000                                           ;The MPU Region Base Address Register
mpu_region_5_size        .word 0x2d                          ; disable subregion 7 (masking out 0x2000 bytes)
                                                                                    ; 64KB region size (0x0F).
                                                                                    ; Enable bits
mpu_region_5_permissions .word 0x10b;The MPU Region Access Control.  non cache

mpu_region_6_base		 .word 0x80000000											
mpu_region_6_size		 .word 0x3d							
mpu_region_6_permissions .word 0x30f

mpu_region_7_base		 .word 0xaa000000											
mpu_region_7_size		 .word 0x31							
mpu_region_7_permissions .word 0x1304

mpu_region_8_base		 .word 0x50000000											
mpu_region_8_size		 .word 0x31							
mpu_region_8_permissions .word 0x10b

mpu_region_9_base		 .word 0x52000000											
mpu_region_9_size		 .word 0x2f							
mpu_region_9_permissions .word 0x10b

mpu_region_10_base		 .word 0x53000000											
mpu_region_10_size		 .word 0x2d							
mpu_region_10_permissions .word 0x10b

mpu_region_11_base		 .word 0x53800000											
mpu_region_11_size		 .word 0x2b							
mpu_region_11_permissions .word 0x10b

mpu_region_12_base		 .word 0x53c00000											
mpu_region_12_size		 .word 0x29							
mpu_region_12_permissions .word 0x10b

mpu_region_13_base		 .word 0x53e00000											
mpu_region_13_size		 .word 0x27							
mpu_region_13_permissions .word 0x10b

mpu_region_14_base		 .word 0x53f00000											
mpu_region_14_size		 .word 0x27							
mpu_region_14_permissions .word 0x10c

mpu_region_15_base		 .word 0x00000000										
mpu_region_15_size		 .word 0x0							
mpu_region_15_permissions .word 0x0

;==============================================================================
;   void USB_armR5EnableMPUandCache( void )
;==============================================================================
    .global USB_armR5EnableMPUandCache
USB_armR5EnableMPUandCache:
; below wont work
;    MRS     r0, cpsr
;    MOV     r1, r0         ;preserve current mode in r1
;    BIC     r0, r0, #0x1F  ; CLEAR MODES
;    ORR     r0, r0, #0x13  ; SET USER MODE
;    MSR     cpsr_cf, r0

;	Disable MPU first
	mrc p15, #0, r0, c1, c0, #0 ; Read SCTLR
	bic r0 , r0 , #1          ; clear MPU enable bit
	mcr p15, #0, r0, c1, c0, #0 ; Write SCTLR

;Set Region 15
    ldr     r2, mpu_region_15_base
    ldr     r3, mpu_region_15_size
    ldr     r4, mpu_region_15_permissions
	
    mov		r0, #15
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control
;Set Region 14
    ldr     r2, mpu_region_14_base
    ldr     r3, mpu_region_14_size
    ldr     r4, mpu_region_14_permissions
	
    mov		r0, #14
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control
;Set Region 13
    ldr     r2, mpu_region_13_base
    ldr     r3, mpu_region_13_size
    ldr     r4, mpu_region_13_permissions
	
    mov		r0, #13
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control
;Set Region 12
    ldr     r2, mpu_region_12_base
    ldr     r3, mpu_region_12_size
    ldr     r4, mpu_region_12_permissions
	
    mov		r0, #12
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control
;Set Region 11
    ldr     r2, mpu_region_11_base
    ldr     r3, mpu_region_11_size
    ldr     r4, mpu_region_11_permissions
	
    mov		r0, #11
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control
;Set Region 10
    ldr     r2, mpu_region_10_base
    ldr     r3, mpu_region_10_size
    ldr     r4, mpu_region_10_permissions
	
    mov		r0, #10
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control
;Set Region 9
    ldr     r2, mpu_region_9_base
    ldr     r3, mpu_region_9_size
    ldr     r4, mpu_region_9_permissions
	
    mov		r0, #9
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control
;Set Region 8
    ldr     r2, mpu_region_8_base
    ldr     r3, mpu_region_8_size
    ldr     r4, mpu_region_8_permissions
	
    mov		r0, #8
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control
;Set Region 7
    ldr     r2, mpu_region_7_base
    ldr     r3, mpu_region_7_size
    ldr     r4, mpu_region_7_permissions
	
    mov		r0, #7
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control
;Set Region 6
    ldr     r2, mpu_region_6_base
    ldr     r3, mpu_region_6_size
    ldr     r4, mpu_region_6_permissions

    mov		r0, #6
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control
;Set Region 5
	ldr      r2, mpu_region_5_base
	ldr      r3, mpu_region_5_size
	ldr      r4, mpu_region_5_permissions

    mov		r0, #5
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control
;Set Region 4
	ldr      r2, mpu_region_4_base
	ldr      r3, mpu_region_4_size
	ldr      r4, mpu_region_4_permissions

    mov		r0, #4
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control

;Set Region 2

	ldr      r2, mpu_region_2_base
	ldr      r3, mpu_region_2_size
	ldr      r4, mpu_region_2_permissions

    mov	    r0, #2                     ;Region NUmber
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control

;Set Region 3

	ldr      r2, mpu_region_3_base
	ldr      r3, mpu_region_3_size
	ldr      r4, mpu_region_3_permissions

    mov	    r0, #3                     ;Region NUmber
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control

;Set Region 1

	ldr      r2, mpu_region_1_base
	ldr      r3, mpu_region_1_size
	ldr      r4, mpu_region_1_permissions

    mov	    r0, #1                     ;Region NUmber
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control

;Set Region 0

	ldr      r2, mpu_region_0_base
	ldr      r3, mpu_region_0_size
	ldr      r4, mpu_region_0_permissions

    mov	    r0, #0                     ;Region NUmber
    mcr     p15, #0, r0, c6, c2, #0    ;Write MPU region number register
    mcr     p15, #0, r2, c6, c1, #0    ;The MPU Region Base Address Register
    mcr     p15, #0, r3, c6, c1, #2    ;The MPU Region Size and Enable bits (and Subre region enable )
    mcr     p15, #0, r4, c6, c1, #4    ;The MPU Region Access Control

	mrc p15, #0, r0, c1, c0, #0 ; Read SCTLR
	orr r0 , r0 , #1          ; Enable MPU enable bit
	mcr p15, #0, r0, c1, c0, #0 ; Write SCTLR

    ;*------------------------------------------------------
    ;* Switch back to the previous mode, R1 expected to be preserved throughput this func
    ;*------------------------------------------------------

	nop
	nop
	nop

	BX lr

    .end
