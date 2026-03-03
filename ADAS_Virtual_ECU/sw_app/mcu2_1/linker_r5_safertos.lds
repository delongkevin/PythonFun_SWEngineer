/*=========================*/
/*     Linker Settings     */
/*=========================*/

--retain="*(.rstvectors)"
--retain="*(.bootCode)"
--retain="*(.startupCode)"
--retain="*(.startupData)"
--retain="*(.intvecs)"
--retain="*(.intc_text)"
--retain="*(.rstvectors)"
--retain="*(.safeRTOSrstvectors)"
--retain="*(.irqStack)"
--retain="*(.fiqStack)"
--retain="*(.abortStack)"
--retain="*(.undStack)"
--retain="*(.svcStack)"

--fill_value=0
--diag_suppress=10063                   /* entry point not _c_int00 */
--stack_size=0x8000
--heap_size=0x10000
--entry_point=_axSafeRTOSresetVectors     /* C RTS boot.asm with added SVC handler	*/

-stack  0x8000  /* SOFTWARE STACK SIZE */
-heap   0x10000 /* HEAP AREA SIZE      */
/*-------------------------------------------*/
/*       Stack Sizes for various modes       */
/*-------------------------------------------*/
__IRQ_STACK_SIZE   = 0x1000;
__FIQ_STACK_SIZE   = 0x1000;
__ABORT_STACK_SIZE = 0x1000;
__UND_STACK_SIZE   = 0x1000;
__SVC_STACK_SIZE   = 0x1000;

/*=========================*/
/*          DEFINES        */
/*=========================*/
#define DDR0_ALLOCATED_START 	 0x97C00000
#define MCU2_1_DDR_SPACE_BASE    (DDR0_ALLOCATED_START) /*4MB*/
#define MCU2_0_DDR_SPACE_BASE    (MCU2_1_DDR_SPACE_BASE + 0x00400000)
#define MCU2_1_DDR_ASILB_BASE     0xB6800000 /* 4MB*/

#define MCU2_1_DDR_TEXT_RODATA_BASE   (MCU2_1_DDR_SPACE_BASE) /*1 MB for code/text, Ro regions*/
#define MCU2_1_DDR_DATA_BASE          (MCU2_1_DDR_TEXT_RODATA_BASE + 0x110000) /*2.9375MB for data,bss,stack*/

/* DDR ASIL Regions */
/*Core     Start Addr    Size      End Addr
* MCU1_0   0xB6000000    0x400000  0xB63FFFFF
* MCU2_0   0xB6400000    0x400000  0xB67FFFFF
* MCU2_1   0xB6800000    0x400000  0xB6BFFFFF
*/
#define MCU2_1_DDR_ASILB_DATA_BASE  MCU2_1_DDR_ASILB_BASE
#define MCU2_1_DDR_STACK_BASE       (MCU2_1_DDR_ASILB_DATA_BASE + 0x300000)


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
    VECTORS (X)                 : origin = 0x00000000   length = 0x00000100

    /* MCU0_R5F_0 local view */
    MCU2_R5F1_ATCM (X)          : origin=0x00000100     length=0x00007F00
    MCU2_R5F1_BTCM(RWIX)        : origin=0x41010000     length=0x00008000	
	
    /* MCU2_R5F_1 SoC view  */
    MCU2_R5F1_ATCM_G (RWIX) 	: origin=0x5C00000 length=0x8000
    MCU2_R5F1_BTCM_G (RWIX) 	: origin=0x5C10000 length=0x8000
	
    /* MSMC_SRAM */
    MAIN_MSRAM_0 (X)        	: origin=0x70200200 length=0x8000

    /* MCUSS RAM */ /* Might need to enable RAT module for this : TODO */
    MSRAM_512K0_RAM 		: origin=0x4F02000000 length=0x80000
    MSRAM_512K1_RAM 		: origin=0x4F02080000 length=0x80000

    MCU2_0_DDR_SPACE (RWIX)	: origin=MCU2_0_DDR_SPACE_BASE    length=0x02800000	/* 40MB  */
		   
    MCU2_1_DDR_TEXT_RO_SPACE (RWIX)	             : origin=MCU2_1_DDR_TEXT_RODATA_BASE   length=0x110000	    /*  1MB */ 
    MCU2_1_DDR_DATA_SPACE (RWIX)	             : origin=MCU2_1_DDR_DATA_BASE          length=0x2F0000	    /*  3MB */
    MCU2_1_DDR_ASILB_DATA_SPACE (RWIX)           : origin=MCU2_1_DDR_ASILB_DATA_BASE    length=0x300000    /*  3MB */
    MCU2_1_DDR_STACK_SPACE (RWIX)	             : origin=MCU2_1_DDR_STACK_BASE         length=0x100000	/*  1MB */
	
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
    GROUP
    {
        .safeRTOSrstvectors	    : {} palign(8)
        .rstvectors             : {} palign(8)
    } > VECTORS
  
    GROUP
    {
        .bootCode                                               : {} palign( 8 )
        .startupCode                                            : {} palign( 8 )   
        .pinit                                                  : {} align( 32 )
        .MPU_INIT_FUNCTION                                      : {} palign( 8 )
        .startupData                                            : {} palign( 8 ), type = NOINIT
    } > MCU2_R5F1_ATCM    

    GROUP : palign(8) > MCU2_R5F1_BTCM
	{
        .KERNEL_DATA LOAD_START( lnkKernelDataStartAddr ),
                     LOAD_END( lnkKernelDataEndAddr )           : {} palign( 0x800 )
    }

    .cinit   : {} align( 32 ) > MCU2_1_DDR_DATA_SPACE

    asil_data:
    {
      /*--library=ti.osal.aer5f*<TimerP_nonos.oer5f>(.bss.*)*/ 
      /*--library=ti.osal.aer5f*<TimerP_nonos.oer5f>(.data.*)*/
      /*--library=ti.osal.aer5f*<board_clock.oer5f>(.bss.*)  */
      /*--library=ti.osal.aer5f*<board_clock.oer5f>(.data.*) */
    }: {} palign(8) > MCU2_1_DDR_ASILB_DATA_SPACE

    __asilb_data__   : {} palign(8) > MCU2_1_DDR_ASILB_DATA_SPACE
    __asilb_bss__    : {} palign(8) > MCU2_1_DDR_ASILB_DATA_SPACE
    __asilb_code__   : {} palign(8) > MCU2_1_DDR_TEXT_RO_SPACE
    __asilb_const__  : {} palign(8) > MCU2_1_DDR_TEXT_RO_SPACE

    /* Code sections. */
    GROUP LOAD_START( lnkFlashStartAddr ), LOAD_END( lnkFlashEndAddr )
    {
        .KERNEL_FUNCTION LOAD_START( lnkKernelFuncStartAddr ),
                         LOAD_END( lnkKernelFuncEndAddr )       : {} palign( 0x10000 )
        
        .text               : palign(8)
        .text.hwi           : palign(8)
        .text.cache         : palign(8)
        .text.mpu           : palign(8)
        .text.boot          : palign(8)
        .rodata             : palign(8)
    } > MCU2_1_DDR_TEXT_RO_SPACE 
    
    .bss:app_log_mem        (NOLOAD) : {}                > APP_LOG_MEM
    .bss:ipc_vring_mem      (NOLOAD) : {}                > IPC_VRING_MEM
     ipc_shared_Mem_buff    (NOINIT) : {} palign(8)      > IPC_SHARED_MEM_BUFF_SPACE
    .bss:taskStackSection            : {}                > MCU2_1_DDR_STACK_SPACE

    /* Data sections. */
    GROUP  palign( 0x10000 ), LOAD_START( lnkRamStartAddr ), LOAD_END( lnkRamEndAddr )
    {
        .bss                                                    : {} align( 4 )        
        .far                                                    : {} align( 4 )
        .data                                                   : {} palign( 128 )
        .boardcfg_data                                          : {} palign( 128 )
        .sysmem                                                 : {}
        .bss.devgroup*                                          : {} align( 4 )
        .const.devgroup*                                        : {} align( 4 )
        ipc_data_buffer (NOINIT)                                : {} palign(128)

    /* Additional sections settings. */

        .data_buffer                                            : {} palign(128)
        /* USB or any other LLD buffer for benchmarking */
        .benchmark_buffer (NOLOAD)                              : {} ALIGN (8)

    /* Stack sections. */
        .stack  RUN_START( lnkStacksStartAddr ) : {}                            align(4)
        .irqStack                               : {. = . + __IRQ_STACK_SIZE;}   align(4)
        RUN_START(__IRQ_STACK_START)
        RUN_END(__IRQ_STACK_END)

        .fiqStack                               : {. = . + __FIQ_STACK_SIZE;}   align(4)
        RUN_START(__FIQ_STACK_START)
        RUN_END(__FIQ_STACK_END)

        .abortStack                             : {. = . + __ABORT_STACK_SIZE;} align(4)
        RUN_START(__ABORT_STACK_START)
        RUN_END(__ABORT_STACK_END)

        .undStack                               : {. = . + __UND_STACK_SIZE;}   align(4)
        RUN_START(__UND_STACK_START)
        RUN_END(__UND_STACK_END)

        .svcStack    END( lnkStacksEndAddr )    : {. = . + __SVC_STACK_SIZE;}   align(4)
        RUN_START(__SVC_STACK_START)
        RUN_END(__SVC_STACK_END)	
    } > MCU2_1_DDR_DATA_SPACE 
}

/*-------------------------------- END ---------------------------------------*/
