/*=========================*/
/*     Linker Settings     */
/*=========================*/

/* Standard linker options */
--retain="*(.bootCode)"
--retain="*(.startupCode)"
--retain="*(.startupData)"
--retain="*(.irqStack)"
--retain="*(.fiqStack)"
--retain="*(.abortStack)"
--retain="*(.undStack)"
--retain="*(.svcStack)"

--fill_value=0
--stack_size=0x2000
--heap_size=0x1000
--entry_point=_freertosresetvectors

/*-------------------------------------------*/
/*       Stack Sizes for various modes       */
/*-------------------------------------------*/
__IRQ_STACK_SIZE   = 0x1000;
__FIQ_STACK_SIZE   = 0x0100;
__ABORT_STACK_SIZE = 0x0100;
__UND_STACK_SIZE   = 0x0100;
__SVC_STACK_SIZE   = 0x0100;

/*=========================*/
/*          DEFINES        */
/*=========================*/
#define DDR0_ALLOCATED_START 	 0x97C00000
#define MCU2_1_DDR_SPACE_BASE    (DDR0_ALLOCATED_START)
#define MCU2_0_DDR_SPACE_BASE    (MCU2_0_DDR_SPACE_BASE + 0x00400000)

/* DDR ASIL Regions */
/*Core     Start Addr    Size      End Addr
* MCU1_0   0xB6000000    0x400000  0xB63FFFFF
* MCU2_0   0xB6400000    0x400000  0xB67FFFFF
* MCU2_1   0xB6800000    0x400000  0xB6BFFFFF
*/

/* Shared Memory configuration */
/* Core     Start Addr    Size      End Addr
* mcu1_0   0xB6C00000  0x00080000  0xB6C7FFFF
* mcu2_0   0xB6C80000  0x00080000  0xB6CFFFFF
* mcu2_1   0xB6D00000  0x00080000  0xB6D7FFFF
* mpu      0xB6D80000  0x00080000  0xB6DFFFFF
* C7x      0xB6E00000  0x00040000  0xB6E3FFFF
*/

/*IPC shared memory buffer allocated in DDR*/
#define IPC_SHARED_MEM_BUFFER_START    0xB6D00000
#define IPC_SHARED_MEM_BUFFER_SIZE     0x00080000

#define ATCM_START 0x00000000
#define OCMRAM_MCU1_0_START 0x41cfe000
#define OCMRAM_MCU1_1_START 0x41cff000

/*=========================*/
/*        MEMORY MAP       */
/*=========================*/
MEMORY
{
    VECTORS (X)                 : origin = 0x00000000   length = 0x00000040

    /* MCU0_R5F_0 local view */
    MCU2_R5F1_ATCM (X)          : origin=0x00000040     length=0x00007FC0
    MCU2_R5F1_BTCM(RWIX)        : origin=0x41010000     length=0x00008000
	
	
    /* MCU2_R5F_1 SoC view  */
    MCU2_R5F1_ATCM_G (RWIX) : origin=0x5C00000 length=0x8000
    MCU2_R5F1_BTCM_G (RWIX) : origin=0x5C10000 length=0x8000
	
    /* MSMC_SRAM : MSMC RAM is not being allocated to MCU2_1 */
    /* MAIN_MSRAM_0 (X)        : origin=0x70200200 length=0x8000 */  

    /* MCUSS RAM */ /* Might need to enable RAT module for this : TODO */
	MSRAM_512K0_RAM origin=0x4F02000000 length=0x80000
	MSRAM_512K1_RAM origin=0x4F02080000 length=0x80000

    MCU2_0_DDR_SPACE (RWIX)	: origin=MCU2_0_DDR_SPACE_BASE    length=0x02800000	/* 40MB  */
		   
    MCU2_1_DDR_SPACE (RWIX)	: origin=MCU2_1_DDR_SPACE_BASE    length=0x00400000	/*  4MB */
	
	/* DDR for MCU2_1 for code/data [ size is 4.00 MB ] */    
    DDR_MCU2_1_ASIL           ( RWIX ) : ORIGIN = 0xB6800000 , LENGTH = 0x400000
	   
    /* Memory for IPC Vring's. MUST be non-cached or cache-coherent [ size 32.00 MB ] */
    IPC_VRING_MEM           : ORIGIN = 0x9E000000 , LENGTH = 0x02000000
	
    IPC_SHARED_MEM_BUFF_SPACE (RWIX)     : origin=IPC_SHARED_MEM_BUFFER_START  length=IPC_SHARED_MEM_BUFFER_SIZE   /*  256 KB */
	
    /* Memory for remote core logging [ size 256.00 KB ] */
    APP_LOG_MEM                       : ORIGIN = 0xA0000000 , LENGTH = 0x00040000
}

/*--------------------------------------------------------------*/
/*                     Section Configuration                    */
/*--------------------------------------------------------------*/
SECTIONS
{
    .freertosrstvectors : {} palign(8)      > VECTORS
    .bootCode           : {} palign(8)      > MCU2_R5F1_BTCM
    .startupCode        : {} palign(8)      > MCU2_R5F1_BTCM
    .startupData        : {} palign(8)      > MCU2_R5F1_BTCM, type = NOINIT
    .boardcfg_data 		: {} palign(128)    > MCU2_R5F1_BTCM
	GROUP
	{
		.text.hwi       : palign(8)
		.text.cache     : palign(8)
		.text.mpu       : palign(8)
		.text.boot      : palign(8)
	}      > MCU2_R5F1_BTCM
    .cinit              : {} palign(8)      > MCU2_1_DDR_SPACE
    .pinit              : {} palign(8)      > MCU2_1_DDR_SPACE
    .text               : {} palign(8)      > MCU2_1_DDR_SPACE
    .const              : {} palign(8)      > MCU2_1_DDR_SPACE
    .rodata             : {} palign(8)      > MCU2_1_DDR_SPACE
    .bss                : {} align(4)       > MCU2_1_DDR_SPACE
    .far                : {} align(4)       > MCU2_1_DDR_SPACE
    .data               : {} palign(128)    > MCU2_1_DDR_SPACE
    .sysmem             : {} align(8)       > MCU2_1_DDR_SPACE
    .stack              : {} align(4)       > MCU2_1_DDR_SPACE
	
    .bss:taskStackSection > MCU2_1_DDR_SPACE
    .bss:app_log_mem        (NOLOAD) : {} > APP_LOG_MEM
    .bss:ipc_vring_mem      (NOLOAD) : {} > IPC_VRING_MEM
    ipc_data_buffer (NOINIT) : {} palign(128)    > MCU2_1_DDR_SPACE
    ipc_shared_Mem_buff (NOINIT) : {} palign(8)    > IPC_SHARED_MEM_BUFF_SPACE

    .data_buffer        : {} palign(128)    > MCU2_1_DDR_SPACE
    .const.devgroup*    : {} align(4)       > MCU2_1_DDR_SPACE

    .resource_table          :
    {
        __RESOURCE_TABLE = .;
    }                                           > MCU2_1_DDR_SPACE
	
    .irqStack   : {. = . + __IRQ_STACK_SIZE;} align(4)      > MCU2_1_DDR_SPACE  (HIGH)
    RUN_START(__IRQ_STACK_START)
    RUN_END(__IRQ_STACK_END)

    .fiqStack   : {. = . + __FIQ_STACK_SIZE;} align(4)      > MCU2_1_DDR_SPACE  (HIGH)
    RUN_START(__FIQ_STACK_START)
    RUN_END(__FIQ_STACK_END)

    .abortStack : {. = . + __ABORT_STACK_SIZE;} align(4)    > MCU2_1_DDR_SPACE  (HIGH)
    RUN_START(__ABORT_STACK_START)
    RUN_END(__ABORT_STACK_END)

    .undStack   : {. = . + __UND_STACK_SIZE;} align(4)      > MCU2_1_DDR_SPACE  (HIGH)
    RUN_START(__UND_STACK_START)
    RUN_END(__UND_STACK_END)

    .svcStack   : {. = . + __SVC_STACK_SIZE;} align(4)      > MCU2_1_DDR_SPACE  (HIGH)
    RUN_START(__SVC_STACK_START)
    RUN_END(__SVC_STACK_END)
	
    .tracebuf                : {} align(1024)   > MCU2_1_DDR_SPACE
}

/*-------------------------------- END ---------------------------------------*/
