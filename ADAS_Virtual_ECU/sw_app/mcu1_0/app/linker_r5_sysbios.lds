/*----------------------------------------------------------------------------*/
/* File: k3m4_r5f_linker.cmd                                                  */
/* Description:                                                               */
/*    Link command file for j721e M4 MCU 0 view                               */
/*    TI ARM Compiler version 15.12.3 LTS or later                            */
/*                                                                            */
/*    Platform: QT                                                            */
/* (c) Texas Instruments 2017, All rights reserved.                           */
/*----------------------------------------------------------------------------*/
/*  History:                                                                  */
/*    Aug 26th, 2016 Original version .......................... Loc Truong   */
/*    Aug 01th, 2017 new TCM mem map  .......................... Loc Truong   */
/*    Nov 07th, 2017 Changes for R5F Init Code.................. Vivek Dhande */
/*----------------------------------------------------------------------------*/
/* Linker Settings                                                            */
/* Standard linker options                                                    */
--retain="*(.utilsCopyVecsToAtcm)"
--fill_value=0
-e __VECS_ENTRY_POINT

-heap 0x1000

/* interface with SBL */
sblProfileLogAddr = 0x41c001f0;
sblProfileLogIndxAddr = 0x41c001f4;
sblProfileLogOvrFlwAddr = 0x41c001f8;
/*----------------------------------------------------------------------------*/
/*
*Region Name                 Start Address  End Address
*MCU_R5FSS0_CORE0_ATCM       0x00000000     0x0000FFFF
*MCU_R5FSS0_CORE0_BTCM       0x41010000     0x4101FFFF
*DDR0_MEM                    0x92000000     0xFFFFFFFF
*MCU_MSRAM_1MB0_RAM          0x41C00000     0x41CFFFFF
*/

/* Memory Map                                                                 */

--define FILL_PATTERN=0xFEAA55EF
--define FILL_LENGTH=0x100

/* 1 MB of MCU Domain MCU_MSRAM_1MB0_RAM is split as shown below */
/* MCU_MSRAM_1MB0_RAM  0x41C00000    to 0x41CFFFFF , length =1MB*/
/* Size used  F0000 Number of slices 4 */
/*                                  Rounding Offset */
/*SBL?      Start   41C00000    245760  0   */
/*          End     41C3C000                */
/*MCU 10    Start   41C3C100    245760  100 */
/*          End     41C78100                */
/*MCU 11    Start   41C78200    245760  100 */
/*          End     41CB4200                */

/*=========================*/
/*          DEFINES        */
/*=========================*/
#define DDR0_ALLOCATED_START      (0x94000000)
#define C7X_DDR_SPACE_BASE        (DDR0_ALLOCATED_START)
#define MCU2_1_DDR_SPACE_BASE     (0x97C00000)
#define MCU2_0_DDR_SPACE_BASE     (0x98000000)

#define MCU1_0_DDR_SPACE_BASE     (0x97800000)
#define MCU1_0_DDR_CERT_STORE_BASE (0x97BEFC00)
#define MCU1_0_DDR_PART_SPACE      (0x97BFFC00)

#define MCU_MSRAM_1MB0_RAM          0x41C00000
#define MCU1_0_SRAM_SAFETY (MCU_MSRAM_1MB0_RAM + 0x80000)

/* DDR ASIL Regions */
/*Core     Start Addr    Size      End Addr
* MCU1_0   0xB6000000    0x400000  0xB63FFFFF
* MCU2_0   0xB6400000    0x400000  0xB67FFFFF
* MCU2_1   0xB6800000    0x400000  0xB6BFFFFF
/* #define DDR_MCU1_0_ASIL  (0xB6000000)
*  #define DDR_MCU2_0_ASIL  (0xB6400000)
*  #define DDR_MCU2_1_ASIL  (0xB6800000)
*/

/* Shared Memory configuration */
/* Core     Start Addr    Size      End Addr
 * mcu1_0   0xB6C00000  0x00080000  0xB6C7FFFF
 * mcu2_0   0xB6C80000  0x00080000  0xB6CFFFFF
 * mcu2_1   0xB6D00000  0x00080000  0xB6D7FFFF
 * mpu      0xB6D80000  0x00080000  0xB6DFFFFF
 * C7x      0xB6E00000  0x00040000  0xB6E3FFFF
 */

/*IPC shared memory buffer allocated in DDR : 512KB */
#define IPC_SHARED_MEM_BUFFER_START    0xB6C00000
#define IPC_SHARED_MEM_BUFFER_SIZE     0x00080000

#define ATCM_START 0x00000000
#define OCMRAM_MCU1_0_START 0x41cfe000
#define OCMRAM_MCU1_1_START 0x41cff000


MEMORY
  {
  /* MCU0_R5F_0 local view */
  MCU0_R5F_TCMA_SBL_RSVD (X)    : origin=0x0        length=0x100
  MCU0_R5F_TCMA (RWIX)             : origin=0x100      length=0x10000 - 0x100 /* MCU1_0 is in Lockstep, Hence 64 KB*/

  MCU0_R5F_TCMB0_VECS(RWIX)     : origin=0x41010000 length=0x200
  //MCU0_R5F_TCMB0_Bootloader(RWIX) : origin=0x41010200 length=0x1000 // Used in Bootloader , we skip it t be safe
  MCU0_R5F_TCMB0(RWIX)          : origin=0x41011200 length=0x10000 - 0x1200 /* MCU1_0 is in Lockstep, Hence 64 KB*/


  /* j721e MCMS3 locations */
  /* j721e Reserved Memory for ARM Trusted Firmware */
  MSMC3_ARM_FW (RWIX)           : origin=0x70000000 length=0x40000         /* 256KB */
  /* j721e Reserved Memory for DMSC Firmware */
  MSMC3_DMSC_FW  (RWIX)         : origin=0x707F0000 length=0x10000         /* 64KB */

  /*START of MSR /OCRAM section*/

  vHsmIpcMemory     (RWIX)      : origin=0x41C00000 length=0x00000380
  vHsmComm_HsmReserved (RWIX)	: origin=0x41C00380 length = 0x00000580 /* 2 KiB */
  vHsmComm_Host2Hsm (RWIX)      : origin=0x41C00900 length=0x4
  vHSMComm_Hsm2Host (RWIX)      : origin=0x41C00904 length=0x4
  vHsmGlobalRamBuffer (RWIX)    : origin=0x41C00908 length=0x2000

  /* Memory for MCU1_0 core logging [ size 32.00 KB ] */
  APP_LOG_MEM                   : origin = 0x41C03000 , LENGTH = 0x8000  /* Reserve 30KB ONLY for Printf, delete in Production*/


  /* Refer the user guide for details on persistence of these sections */
  /* RESERVED (X)            : origin=0x41C3E000 length=0x2000*/
  OCMC_RAM_SCISERVER (RWIX)     : origin=0x41C0C000 length=0x72000

  /* This is HSM AREA , NO Shfting , Dependency on Bootloader/HSM Linker file*/
  VMemAccmSatelitedata (RWIX) : origin=0x41C7E000 length=0x800
  SBLVersionAddr       (RWIX) : origin=0x41C7EFF8 length=0x8


  /* MCU0 memory used for the SBL to save OSPI PHY tuning data for later apps to use */
  OCMRAM_SBL_PHY_TUNING (RWIX) : origin=0x41c7ffe0 length=0x20

 /* DO NOT TOUCH!!!--It's for SAFETY  OS (ASIL)*/
  SRAM_SAFETY    (RWIX)         : origin=0x41C80000 length=0x40000 /* DO NOT TOUCH!!!--It's for SAFETY  OS (ASIL)*/
  //OCMC_RAM_Bootloader (RWIX)  : origin=0x41CC0000 length=0x10000 /* Bootloader reserves this*/
  OCMC_RAM_SCISERVER1 (RWIX)    : origin=0x41CD0000 length=0x11000
  OCMC_RAM_BOARD_CFG (RWIX)     : origin=0x41CE1000 length=0x1000
  RESET_VECTORS (X)             : origin=0x41CE2000 length=0x100
  OCMC_RAM (RWIX)               : origin=0x41CE2100 length=0x1DA00
  OCMC_RAM_X509_HEADER (RWIX)   : origin=0x41CFFB00 length=0x500



/*====================================================================*/
/*     No clear RAM (512 bytes)   origin=0x40280000 length=0x200      */
/*====================================================================*/
  MCU_PSRAM0_RAM (RWIX)                           : origin=0x40280000 length=0x08      /* 8 Bytes : Magic Flag */
  MCU_PSRAM0_RAM_SAFE_SHUTDOWN_FLAG (RWIX)        : origin=0x40280008 length=0x04      /* 4 Byte  : Safe Shutdown flag */
  MCU_PSRAM0_RAM_FBL_RESET_HANDLE (RWIX)          : origin=0x4028000C length=0x02      /* 2 Byte  : FBL Reset Handling */
  MCU_PSRAM0_RAM_DEBUG_DATA_CAN (RWIX)            : origin=0x4028000E length=0x5A      /* 90 Byte : System Debug Data To CAN*/

  MCU2_0_DDR_SPACE (RWIX)       : origin=MCU2_0_DDR_SPACE_BASE length=0x02800000 /* 40MB */
  MCU2_1_DDR_SPACE (RWIX)       : origin=MCU2_1_DDR_SPACE_BASE length=0x400000   /* 4MB */
  MCU1_0_DDR_SPACE (RWIX)       : origin=MCU1_0_DDR_SPACE_BASE length=0x3EFC00  /* 3.93MB */
  MCU1_0_DDR_CERT_STORE (RWIX)  : origin=MCU1_0_DDR_CERT_STORE_BASE length=0x10000 /* 64KB */
  MCU1_0_DDR_PART (RWIX)        : origin=MCU1_0_DDR_PART_SPACE length=0x400 /* 1K */

  /* RAT translation Memmap for MSMC ECC */
  ECC_CFG_SCRATCH  (RWIX)  : origin=0x60000000 length=0x400            /* 1 K */
  ECC_CFG_SCRATCH1 (RWIX)  : origin=0x60000400 length=0x400            /* 1 K */
  ECC_CFG_SCRATCH2 (RWIX)  : origin=0x60001000 length=0x1000           /* 4 K */
  ECC_CFG_SCRATCH3 (RWIX)  : origin=0x60002000 length=0x1000           /* 4 K */
  ECC_CFG_SCRATCH4 (RWIX)  : origin=0x60003000 length=0x1000           /* 4 K */
  ECC_CFG_SCRATCH5 (RWIX)  : origin=0x60004000 length=0x1000           /* 4 K */
  ECC_CFG_SCRATCH6 (RWIX)  : origin=0x60005000 length=0x400            /* 1 K */
  ECC_CFG_SCRATCH7 (RWIX)  : origin=0x60005400 length=0x400            /* 1 K */
  ECC_CFG_SCRATCH8 (RWIX)  : origin=0x60005800 length=0x400            /* 1 K */
  ECC_CFG_SCRATCH9 (RWIX)  : origin=0x60005c00 length=0x400            /* 1 K */

  /* Memory for IPC Vring's. MUST be non-cached or cache-coherent [ size 32.00 MB ] */
  IPC_VRING_MEM                 : ORIGIN = 0x9E000000 , LENGTH = 0x02000000

  IPC_SHARED_MEM_BUFF_SPACE (RWIX) : origin=IPC_SHARED_MEM_BUFFER_START  length=IPC_SHARED_MEM_BUFFER_SIZE




}  /* end of MEMORY */

/*----------------------------------------------------------------------------*/
/* Section Configuration                                                      */

SECTIONS
{
  OSEXCVEC_CORE0_CODE: align=8, load > MCU0_R5F_TCMB0_VECS
  {
    __VECS_ENTRY_POINT = .;
    #define OS_LINK_EXCVEC_CODE
    #include "..\..\platform\asr\app_sip\GenData\mcu1_0\Os_Link_Core0.ld"
  }
  .text:__TI_auto_init*     : {} palign(8) > OCMC_RAM_SCISERVER

  .bootCode    : {} palign(8)     > MCU0_R5F_TCMB0
  .startupData : {} palign(8)     > MCU0_R5F_TCMB0
  .startupCode : {} palign(8)     > MCU0_R5F_TCMB0
  .utilsCopyVecsToAtcm : {} palign(8) > MCU0_R5F_TCMB0
   .bss:app_log_mem        (NOLOAD) : {} > APP_LOG_MEM
  .cinit    : {} palign(8)      > MCU1_0_DDR_SPACE
  .pinit    : {} palign(8)      > OCMC_RAM_SCISERVER
  .text     : {} palign(8)      > MCU1_0_DDR_SPACE
  .rodata   : {} palign(128)    > MCU1_0_DDR_SPACE
  .const    : {} palign(8)      > OCMC_RAM_SCISERVER1
  .bss      : {} align(4)       > MCU1_0_DDR_SPACE
  .far      : {} align(4)       > OCMC_RAM_SCISERVER
  .data     : {} palign(128)    > MCU1_0_DDR_SPACE
  .stack    : {} align(4)       > MCU0_R5F_TCMB0  (HIGH) fill=FILL_PATTERN

  .boardcfg_data      : {} align(4)      > OCMC_RAM_SCISERVER
  .bss.devgroup*      : {} align(4)      > MCU1_0_DDR_SPACE
  .const.devgroup*    : {} align(4)      > OCMC_RAM
  .data_user          : {} align(4)      > OCMC_RAM_SCISERVER
  .boardcfg_data      : {} align(4)      > OCMC_RAM_SCISERVER

  .bss:ipc_vring_mem (NOLOAD)      : {}             > IPC_VRING_MEM
  cert_store (NOINIT)              : {} palign(8)   > MCU1_0_DDR_CERT_STORE
  ipc_data_buffer (NOINIT)         : {} palign(128) > MCU1_0_DDR_SPACE
  ipc_shared_Mem_buff (NOINIT)     : {} palign(8)   > IPC_SHARED_MEM_BUFF_SPACE

  /* RAT translation Memmap for MSMC ECC */
  .my_aggr_reg           : {*(.my_aggr_reg)}         > ECC_CFG_SCRATCH, type = NOINIT
  .my_aggr_reg1          : {*(.my_aggr_reg1)}        > ECC_CFG_SCRATCH1, type = NOINIT
  .my_aggr_reg2          : {*(.my_aggr_reg2)}        > ECC_CFG_SCRATCH2, type = NOINIT
  .my_aggr_reg3          : {*(.my_aggr_reg3)}        > ECC_CFG_SCRATCH3, type = NOINIT
  .my_aggr_reg4          : {*(.my_aggr_reg4)}        > ECC_CFG_SCRATCH4, type = NOINIT
  .my_aggr_reg5          : {*(.my_aggr_reg5)}        > ECC_CFG_SCRATCH5, type = NOINIT
  .my_aggr_reg6          : {*(.my_aggr_reg6)}        > ECC_CFG_SCRATCH6, type = NOINIT
  .my_aggr_reg7          : {*(.my_aggr_reg7)}        > ECC_CFG_SCRATCH7, type = NOINIT
  .my_aggr_reg8          : {*(.my_aggr_reg8)}        > ECC_CFG_SCRATCH8, type = NOINIT
  .my_aggr_reg9          : {*(.my_aggr_reg9)}        > ECC_CFG_SCRATCH9, type = NOINIT

  .vHsmIpcMemory (NOINIT)          : {} palign(8)   > vHsmIpcMemory
  .vHsmGlobalRamBuffer (NOINIT)    : {} palign(8)   > vHsmGlobalRamBuffer

  /* Additional sections settings   */
  //.sysfw_data_cfg_board      : {} palign(128) > OCMC_RAM
  //.sysfw_data_cfg_board_rm   : {} palign(128) > OCMC_RAM
  //.sysfw_data_cfg_board_sec  : {} palign(128) > OCMC_RAM
  .ospi_phy_tuning_data        : {} palign(8)   > OCMRAM_SBL_PHY_TUNING, type = NOINIT

  SAFERAM : align(4) > SRAM_SAFETY
  {
  	SWC_SafeVCANRx.oer5f*(.data)
  	SWC_SafeVCANRx.oer5f*(.bss)
  	
  	SWC_SafeVCANTx.oer5f*(.data)
  	SWC_SafeVCANTx.oer5f*(.bss)
  	
  	CDD_IPCHandler.oer5f*(.data)
  	CDD_IPCHandler.oer5f*(.bss)
  	
  	SWC_ProxiConfigMgr.oer5f*(.data)
  	SWC_ProxiConfigMgr.oer5f*(.bss)
  	
  	CDD_E2EWrapper.oer5f*(.data)
  	CDD_E2EWrapper.oer5f*(.bss)
  	
  	CDD_PMIC.oer5f*(.data)
  	CDD_PMIC.oer5f*(.bss)
  	
  	SWC_WdgFw.oer5f*(.data)
  	SWC_WdgFw.oer5f*(.bss)
  	
  	CDD_WDG.oer5f*(.data)
  	CDD_WDG.oer5f*(.bss)
  	
  	Safety_Guard.oer5f*(.data)
  	Safety_Guard.oer5f*(.bss)
  	
  	CDD_Safety.oer5f*(.data)
  	CDD_Safety.oer5f*(.bss)
  	
  	CalDataProvider.oer5f*(.data)
  	CalDataProvider.oer5f*(.bss)
  	
    --library=FUSA.aer5f*<*>(.bss)
    --library=FUSA.aer5f*<*>(.data)
    
    --library=sdl_api.aer5f*<*>(.bss)
    --library=sdl_api.aer5f*<*>(.data)
    
    --library=r5f_core.aer5f*<*>(.bss)
    --library=r5f_core.aer5f*<*>(.data)
    
    --library=sdl_ip.aer5f*<*>(.bss)
    --library=sdl_ip.aer5f*<*>(.data)
    
    --library=sdl_osal.aer5f*<*>(.bss)
    --library=sdl_osal.aer5f*<*>(.data)
    
    --library=pmic.aer5f*<*>(.bss)
    --library=pmic.aer5f*<*>(.data)
    
    pmic_voltmon.oer5f*(.data)
    pmic_voltmon.oer5f*(.bss) 
                          
	pmic_utils.oer5f*(.data)
    pmic_utils.oer5f*(.bss) 
                                             
	pmic.oer5f*(.data)
    pmic.oer5f*(.bss) 
                                                  
	pmic_error.oer5f*(.data)
    pmic_error.oer5f*(.bss) 
                                             
	pmic_voltmon_cfg.oer5f*(.data)
    pmic_voltmon_cfg.oer5f*(.bss) 
                                        
	pmic_cfg.oer5f*(.data)
    pmic_cfg.oer5f*(.bss) 
                                               
	pmic_readback.oer5f*(.data)
    pmic_readback.oer5f*(.bss) 
                                            
	pmic_mcu_esm.oer5f*(.data)
    pmic_mcu_esm.oer5f*(.bss) 
                                             
	pmic_bist_sts.oer5f*(.data)
    pmic_bist_sts.oer5f*(.bss) 
                                            
	pmic_crc_mon.oer5f*(.data)
    pmic_crc_mon.oer5f*(.bss) 
                                           
	pmic_thermal_warn_shutdown.oer5f*(.data)
    pmic_thermal_warn_shutdown.oer5f*(.bss) 
                               
	pmic_clock_mon.oer5f*(.data)
    pmic_clock_mon.oer5f*(.bss) 
                                           
	pmic_reg_lock.oer5f*(.data)
    pmic_reg_lock.oer5f*(.bss) 
                                            
	pmic_lbist.oer5f*(.data)
    pmic_lbist.oer5f*(.bss) 
                                               
	pmic_safe_state.oer5f*(.data)
    pmic_safe_state.oer5f*(.bss) 
    
    --library=wdgSlave.aer5f*<*>(.bss)
    --library=wdgSlave.aer5f*<*>(.data)
    
    --library=wdg_magna.aer5f*<*>(.bss)
    --library=wdg_magna.aer5f*<*>(.data)  
    
    --library=wdgif.aer5f*<*>(.bss)
    --library=wdgif.aer5f*<*>(.data)  
    
	--library=wdgm.aer5f*<*>(.bss)
    --library=wdgm.aer5f*<*>(.data)
    
    #define OS_LINK_VAR_APP_OSAPPLICATION_SAFETY_FAR_CACHE_NOINIT
    #define OS_LINK_VAR_APP_OSAPPLICATION_SAFETY_FAR_NOCACHE_NOINIT
    #define OS_LINK_VAR_APP_OSAPPLICATION_SAFETY_FAR_CACHE_INIT
    #define OS_LINK_VAR_APP_OSAPPLICATION_SAFETY_FAR_CACHE_ZERO_INIT
    #include "..\..\platform\asr\app_sip\GenData\mcu1_0\Os_Link_Core0.ld"
  }
  
  /* Place QM variables here !!! */
  QMRAM : align(4) > MCU1_0_DDR_SPACE 
  {
  	
  }
  
  

    ERRManager_BSS_B_HighPerf  (NOINIT): {} palign(128) > SRAM_SAFETY
	ERRManager_BSS_QM_HighPerf  (NOINIT): {} palign(128) > OCMC_RAM
	ERRManager_CONST_HighPerf  (NOINIT): {} palign(128) > MCU1_0_DDR_SPACE
    DegManager_BSS_B_HighPerf  : {} palign(128) > SRAM_SAFETY
	DegManager_BSS_QM_HighPerf  : {} palign(128) > OCMC_RAM
	ERRManager_BSS_B  (NOINIT): {} palign(128) > SRAM_SAFETY
	ERRManager_BSS_QM  (NOINIT): {} palign(128) > MCU1_0_DDR_SPACE
	DegManager_BSS_B  : {} palign(128) > SRAM_SAFETY
	DegManager_BSS_QM  : {} palign(128) > MCU1_0_DDR_SPACE

   .text_ecctest {
	    *ti.csl.aer5f<csl_emif.oer5f> (.text.CSL_emifDisableECC)
		*ti.csl.aer5f<csl_emif.oer5f> (.text.CSL_emifEnableECC)
		*ti.csl.aer5f<csl_emif.oer5f> (.text.CSL_emifClearAllECCErrors)
		*ti.csl.aer5f<csl_emif.oer5f> (.text.CSL_emifClearECCInterruptStatus)
		*ti.csl.aer5f<csl_emif.oer5f> (.text.CSL_emifEnableECCInterrupts)
		*ti.csl.aer5f<csl_cache.oer5f> (.text.CSL_armR5CacheWbInv)
		*ti.csl.aer5f<csl_arm_r5.oer5f> (.text)
		*ti.osal.aer5f<CacheP_nonos.oer5f> (.text.CacheP_wbInv)
		--library=FUSA.aer5f*<ecc_ddr.oer5f> (.text.*)
    } > OCMC_RAM_SCISERVER

  .OS_CONST                                 : {} align(4)      > MCU0_R5F_TCMA
  .OS_CORE0_CONST                           : {} palign(8)     > OCMC_RAM_SCISERVER
  .OS_INTVEC_CORE0_CONST                    : {} align(4)      > OCMC_RAM_SCISERVER
  .OS_SystemApplication_OsCore0_VAR_NOINIT  : {} align(4)      > OCMC_RAM_SCISERVER
  .OS_GLOBALSHARED_VAR_NOCACHE_NOINIT       : {} align(4)      > MCU0_R5F_TCMA
  .OS_CORE0_VAR                             : {} align(4)      > MCU0_R5F_TCMA
  .OS_OsApplication_VAR                     : {} align(4)      > MCU0_R5F_TCMA

  .OS_CORE0_VAR_NOINIT                    : {} align(4)      > MCU0_R5F_TCMA
  .OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT    : {} align(4)      > MCU0_R5F_TCMA
  .OS_VAR_NOCACHE_NOINIT                  : {} align(4)      > MCU0_R5F_TCMA
  .OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT : {} align(4)      > MCU0_R5F_TCMA
  .OS_OsApplication_VAR_NOINIT            : {} align(4)      > MCU0_R5F_TCMA
  .OS_CORE0_VAR_NOCACHE_NOINIT            : {} align(4)      > MCU0_R5F_TCMA
  .OS_PUBLIC_CORE0_VAR_NOINIT                                > MCU0_R5F_TCMA




  .OS_ApplTask_Init_CODE          : {} align(4)  > MCU0_R5F_TCMB0
  .OS_ApplTask00_10ms_CODE        : {} align(4)  > MCU0_R5F_TCMB0
  .OS_ApplTask01_10ms_CODE        : {} align(4)  > MCU0_R5F_TCMB0
  .OS_ApplTask_200ms_CODE         : {} align(4)  > MCU0_R5F_TCMB0
  .OS_BootAppOsTask_CODE          : {} align(4)  > MCU0_R5F_TCMB0
  .OS_BswTask_ComTask_10ms_CODE   : {} align(4)  > MCU0_R5F_TCMB0
  .OS_BswTask_ComTask_5ms_CODE    : {} align(4)  > MCU0_R5F_TCMB0
  .OS_BswTask_MemTask_CODE        : {} align(4)  > MCU0_R5F_TCMB0
  .OS_BswTask_DiagTask_CODE       : {} align(4)  > MCU0_R5F_TCMB0
  .OS_Can_30_McanIsr_0_CODE       : {} align(4)  > MCU0_R5F_TCMB0
  .OS_Can_30_McanIsr_1_CODE       : {} align(4)  > MCU0_R5F_TCMB0
  .OS_Adc_IrqUnit0_CODE           : {} align(4)  > OCMC_RAM_SCISERVER
  .OS_Adc_IrqUnit1_CODE           : {} align(4)  > OCMC_RAM_SCISERVER
  .OS_I2c_IrqUnit0_CODE           : {} align(4)  > OCMC_RAM_SCISERVER
  .OS_I2c_IrqUnit1_CODE           : {} align(4)  > OCMC_RAM_SCISERVER
  .OS_I2c_IrqUnit2_CODE           : {} align(4)  > OCMC_RAM_SCISERVER
  .OS_IPC_mailbox1_CODE           : {} align(4)  > OCMC_RAM_SCISERVER
  .OS_IPC_mailbox2_CODE           : {} align(4)  > OCMC_RAM_SCISERVER
  .OS_StartUpTask_CODE            : {} align(4)  > OCMC_RAM_SCISERVER

  .OS_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78_CODE : {} align(4)  > OCMC_RAM_SCISERVER
  .OS_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79_CODE : {} align(4)  > OCMC_RAM_SCISERVER

  .OS_SciServerHighOsTask_CODE            : {} align(4)  > MCU0_R5F_TCMA
  .OS_SciServerLowOsTask_CODE             : {} align(4)  > MCU0_R5F_TCMA
  .OS_SciServer_OsIsr_UserMsgHwiFxn1_CODE : {} align(4)  > MCU0_R5F_TCMA
  .OS_SciServer_OsIsr_UserMsgHwiFxn2_CODE : {} align(4)  > MCU0_R5F_TCMA
  .OS_SciServer_OsIsr_UserMsgHwiFxn3_CODE : {} align(4)  > MCU0_R5F_TCMA
  .OS_SciServer_OsIsr_UserMsgHwiFxn4_CODE : {} align(4)  > MCU0_R5F_TCMA


GROUP : palign(8) > OCMC_RAM_SCISERVER
    {
      .fastcode_autosar
      {
        --library=mcan.aer5f*<Can_30_Mcan.oer5f>(.text.*)
        --library=cannm.aer5f*<CanNm.oer5f>(.text.*)
        --library=nvm.aer5f*<NvM.oer5f>(.text.*)
	--library=nvm.aer5f*<NvM_Act.oer5f>(.text.*)
	--library=cantp.aer5f*<CanTp.oer5f>(.text.*)
	--library=cansm.aer5f*<CanSM.oer5f>(.text.*)
        --library=com.aer5f*<Com_RxProcessing.oer5f>(.text.Com_RxProcessing_RxPduSigEvent)
        --library=com.aer5f*<Com_Lcfg.oer5f>(.text.Com_MainFunctionRx_ComMainFunctionRx)
        --library=com.aer5f*<Com_Lcfg.oer5f>(.text.Com_MainFunctionTx_ComMainFunctionTx)
        --library=com.aer5f*<Com_TxModeHdlr.oer5f>(.text.Com_TxModeHdlr_MainFunctionTx_CycleCounter)
        --library=com.aer5f*<Com_TxModeHdlr.oer5f>(.text.Com_TxModeHdlr_MainFunctionTx_Transmit)
        --library=com.aer5f*<Com_TxModeHdlr.oer5f>(.text.Com_TxModeHdlr_ExitExclusiveArea)
        --library=com.aer5f*<Com_TxModeHdlr.oer5f>(.text.Com_TxModeHdlr_ExitExclusiveArea_CycleCounter)
        --library=com.aer5f*<Com_TxModeHdlr.oer5f>(.text.Com_TxModeHdlr_Confirmation)
        --library=com.aer5f*<Com_MainFunctions.oer5f>(.text.Com_MainFunctionTxInternal)
        --library=com.aer5f*<Com_MainFunctions.oer5f>(.text.Com_MainFunctionRxInternal)
        --library=com.aer5f*<Com_Deserializer.oer5f>(.text.Com_Signal_ReadSignal_UInt32)
        --library=com.aer5f*<Com_Deserializer.oer5f>(.text.Com_Signal_ReadSignal_UInt16)
        --library=com.aer5f*<Com_Deserializer.oer5f>(.text.Com_Signal_ReadSignal_UInt8)
        --library=com.aer5f*<Com_Notifications.oer5f>(.text.Com_CacheOrCallRxCbkFctPtr)
        --library=cantrcv_tja1043.aer5f*<CanTrcv_30_Tja1043.oer5f>(.text.CanTrcv_30_Tja1043_GetOpMode)
        --library=cantrcv_tja1043.aer5f*<CanTrcv_30_Tja1043.oer5f>(.text.CanTrcv_30_Tja1043_Init)
        --library=cantrcv_tja1043.aer5f*<CanTrcv_30_Tja1043.oer5f>(.text.CanTrcv_30_Tja1043_MainFunction)
        --library=cantrcv_tja1043.aer5f*<CanTrcv_30_Tja1043.oer5f>(.text.CanTrcv_30_Tja1043_SetOpMode)
        --library=com.aer5f*<Com_Notifications.oer5f>(.text.Com_CacheOrCallRxDeferredCbkFctPtr)
        --library=com.aer5f*<Com_RxProcessing.oer5f>(.text.Com_RxDeferredPduProcessing)
        --library=com.aer5f*<Com_Deserializer.oer5f>(.text.Com_Signal_ReadSignalApplTypeSpecific)
        --library=com.aer5f*<Com_LLIf.oer5f>(.text.Com_TxLLIf_Transmit)
        --library=com.aer5f*<Com_RxProcessing.oer5f>(.text.Com_RxProcessing_EnterExclusiveArea_Deferred)
        --library=com.aer5f*<Com_RxProcessing.oer5f>(.text.Com_ProcessRxFctPtrCache)
        --library=com.aer5f*<Com_RxProcessing.oer5f>(.text.Com_RxProcessing_ExitExclusiveArea_Deferred)
        --library=com.aer5f*<Com_SignalIf.oer5f>(.text.Com_ReceiveSignal_GetRxSigBuffer)
        --library=com.aer5f*<Com_Notifications.oer5f>(.text.Com_TxNHdlr_MainFunctionTx)
        --library=com.aer5f*<Com_Timer.oer5f>(.text.Com_RxDlMon_MainFunctionRx)
        --library=com.aer5f*<Com.oer5f>(.text.Com_ReceiveSignal)
        --library=com.aer5f*<Com.oer5f>(.text.Com_SendSignal)
        --library=canif.aer5f*<CanIf.oer5f>(.text.CanIf_TrcvModeIndication)
        --library=cansm.aer5f*<CanSM.oer5f>(.text.CanSM_TransceiverModeIndication)
        --library=comm.aer5f*<ComM.oer5f>(.text.*)
        --library=os.aer5f*<Os_Task.oer5f>(.OS_CODE)
        --library=os.aer5f*<Os_Trap.oer5f>(.text.*)
        --library=crc.aer5f*<Crc.oer5f>(.text.Crc_CalculateCRC16)
        --library=pdur.aer5f*<PduR.oer5f>(.text.PduR_UpTransmit)
        --library=pdur.aer5f*<PduR.oer5f>(.text.PduR_LoIfRxIndication)
        --library=pdur.aer5f*<PduR_RmIf.oer5f>(.text.PduR_RmIf_ProcessDestPdu)
        --library=pdur.aer5f*<PduR_RmIf.oer5f>(.text.PduR_RmIf_RoutePdu)
        --library=pdur.aer5f*<PduR_RmIf.oer5f>(.text.PduR_RmIf_DispatchDestPdu)
        --library=pdur.aer5f*<PduR_Lcfg.oer5f>(.text.PduR_ComTransmit)
        --library=pdur.aer5f*<PduR.oer5f>(.text.PduR_LoTpStartOfReception)
        --library=pdur.aer5f*<PduR.oer5f>(.text.PduR_LoTpCopyRxData)
        --library=pdur.aer5f*<PduR.oer5f>(.text.PduR_LoTpRxIndication)
        --library=canif.aer5f*<CanIf.oer5f>(.text.*)
        --library=det.aer5f*<Det.oer5f>(.text.Det_ReportError)
        --library=det.aer5f*<Det.oer5f>(.text.Det_ReportRuntimeError)
        --library=ipc_manager.aer5f*<ipc_manager.oer5f>(.text.IPC_F_WrapperSend_u32)
        --library=ipc_manager.aer5f*<ipc_manager.oer5f>(.text.IPC_f_GetMsgIdTxIdx_u16)
        --library=ipc_manager.aer5f*<ipc_crc.oer5f>(.text.IPC_F_CalcCrc8_u8)
        --library=ipc_manager.aer5f*<ipc_crc.oer5f>(.text.IPC_F_CalcCrc32_u32)
        --library=ipc_manager.aer5f*<ipc_large_buff_mgr.oer5f>(.text.IPC_F_GetSmBuff_u32)
        --library=ipc_manager.aer5f*<ipc_error.oer5f>(.text.IPC_F_CollectTxErr_v)
        --library=ipc_manager.aer5f*<ipc_error.oer5f>(.text.IPC_F_CollectCmnErr_v)
	--library=cryif.aer5f*<CryIf.oer5f>(.text.CryIf_ProcessJob)
        CDD_IPCHandler.oer5f (.text.*)


      }
    }

GROUP : palign(8) > MCU0_R5F_TCMB0
 {

    .CDD_ram
      {
        CDD_PMIC.oer5f (.text.*)
	CDD_WDG.oer5f (.text.*)
	--library=wdgm.aer5f*<WdgM.oer5f>(.text.*)
	--library=wdg_magna.aer5f*<Wdg.oer5f>(.text.*)
	CDD_GenericBswM.oer5f (.text.*)
	--library=bswm.aer5f*<BswM_Lcfg.oer5f>(.text.*)
	--library=nm.aer5f*<Nm.oer5f>(.text.*)
	IoHwAb.oer5f (.text.*)
	SWC_VoltageMgr.oer5f (.text.*)
	--library=Crypto_30_vHsm.aer5f*<Crypto_30_vHsm.oer5f>(.text.*)
	--library=Csm.aer5f*<Csm.oer5f>(.text.*)
	--library=Crypto_30_vHsm.aer5f*<Crypto_30_vHsm_Ipc.oer5f>(.text.*)
	--library=Crypto_30_vHsm.aer5f*<Crypto_30_vHsm_KeyManagement.oer5f>(.text.*)
	--library=Crypto_30_vHsm.aer5f*<Crypto_30_vHsm_Jobs.oer5f>(.text.*)
      }

 }


 GROUP : palign(8) > MCU0_R5F_TCMA
 {
/*

    .SDL_ram
      {
	--library=sdl_osal.aer5f*<sdl_osal.oer5f>(.text.*)
	--library=sdl_api.aer5f*<sdl_ecc_r5.oer5f>(.text.*)
	--library=sdl_api.aer5f*<sdl_ecc.oer5f>(.text.*)
	--library=sdl_api.aer5f*<sdl_ccm.oer5f>(.text.*)
	--library=sdl_api.aer5f*<sdl_esm_core.oer5f>(.text.*)
	--library=sdl_api.aer5f*<sdl_esm_priv.oer5f>(.text.*)
	--library=sdl_api.aer5f*<sdl_esm.oer5f>(.text.*)
	--library=sdl_api.aer5f*<sdl_pok.oer5f>(.text.*)
	--library=sdl_ip.aer5f*<sdl_vtm.oer5f>(.text.*)
	--library=sdl_ip.aer5f*<sdl_ip_pok_defs.oer5f>(.text.*)
	--library=sdl_api.aer5f*<sdl_soc_lbist.oer5f>(.text.*)
	--library=sdl_api.aer5f*<sdl_ecc_utils.oer5f>(.text.*)
	--library=sdl_ip.aer5f*<sdl_ip_ecc.oer5f>(.text.*)
	--library=sdl_ip.aer5f*<sdl_ip_esm.oer5f>(.text.*)
	--library=sdl_ip.aer5f*<sdl_ip_vtm.oer5f>(.text.*)
	--library=sdl_ip.aer5f*<sdl_ip_lbist.oer5f>(.text.*)
	--library=sdl_ip.aer5f*<sdl_vtm_pvt_sensor.oer5f>(.text.*)
	--library=r5f_core.aer5f*<sdl_mcu_armss_ccmr5.oer5f>(.text.*)
	--library=FUSA.aer5f*<ccm.oer5f>(.text.*)
	--library=FUSA.aer5f*<pok_example.oer5f>(.text.*)
	--library=FUSA.aer5f*<pok.oer5f>(.text.*)
	--library=FUSA.aer5f*<esm.oer5f>(.text.*)
	--library=FUSA.aer5f*<fusa_osal_interface_autosar.oer5f>(.text.*)
	--library=FUSA.aer5f*<fusa_application.oer5f>(.text.*)
	--library=FUSA.aer5f*<bist.oer5f>(.text.*)
	--library=FUSA.aer5f*<vtm.oer5f>(.text.*)
	--library=FUSA.aer5f*<lbist_utils.oer5f>(.text.*)
	--library=FUSA.aer5f*<bist_core_defs.oer5f>(.text.*)
	--library=FUSA.aer5f*<ecc.oer5f>(.text.*)
	--library=FUSA.aer5f*<ecc_trigger.oer5f>(.text.*)
      }
*/
 }

GROUP : palign(8) > MCU0_R5F_TCMB0
 {

    .fastcode_ram
      {
        //--library=os.aer5f*<Os_Trap.oer5f>(.OS_CODE)
        //--library=os.aer5f*<Os_Isr.oer5f>(.OS_CODE)
        --library=os.aer5f*<Os_Trap.oer5f>(.text.SuspendAllInterrupts)
        --library=os.aer5f*<Os_Trap.oer5f>(.text.ResumeAllInterrupts)
        //--library=os.aer5f*<Os_Trap.oer5f>(.text.OSError_ActivateTask_TaskID)
        --library=os.aer5f*<Os_Spinlock.oer5f>(.text.Os_SpinlockForciblyReleaseThreadLocks)
        --library=os.aer5f*<Os_Resource.oer5f>(.text.Os_ResourceForciblyReleaseLocks)
        --library=os.aer5f*<Os_Hal_ContextAsm.oer5f>(.text.Os_Hal_ContextGo)
        --library=os.aer5f*<Os_Hal_Context.oer5f>(.text.Os_Hal_ContextCallOnStack)
        --library=os.aer5f*<Os_Hal_ContextAsm.oer5f>(.text.Os_Hal_ContextRestorePermanentAndGo)
        --library=os.aer5f*<Os_Hook.oer5f>(.text.Os_Hal_ReadPsr)
        --library=os.aer5f*<Os_Hook.oer5f>(.text.Os_Hal_GetMultiprocessorIdRegister)
        --library=os.aer5f*<Os_Hal_Context.oer5f>(.text.Os_Hal_ContextSwitch)
        --library=os.aer5f*<Os_Hook.oer5f>(.text.Os_Hal_GetThreadIdRegister)
        --library=os.aer5f*<Os_ServiceFunction.oer5f>(.text.Os_ServiceCallForceRelease)
        //--library=os.aer5f*<Os_Trap.oer5f>(.text.Os_TrapHookReturn)
        //--library=os.aer5f*<Os_Trap.oer5f>(.text.Os_TrapHookGetStatus)
        --library=os.aer5f*<Os_Scheduler.oer5f>(.text.Os_SchedulerInternalSchedule)
        --library=os.aer5f*<Os_Counter.oer5f>(.text.Os_CounterStart)
        --library=os.aer5f*<Os_Core.oer5f>(.text.Os_Hal_DisableAndReturnPriorState)
        --library=os.aer5f*<Os_Core.oer5f>(.text.Os_Hal_GetThreadIdRegister)
        --library=os.aer5f*<Os_Core.oer5f>(.text.Os_Hal_ReadPsr)
        --library=os.aer5f*<Os_Error.oer5f>(.text.Os_ErrProtectionException)
        --library=os.aer5f*<Os_Error.oer5f>(.text.Os_ErrProtectionError)
        --library=os.aer5f*<Os_TimingProtection.oer5f>(.text.Os_TpStart)
        --library=os.aer5f*<Os_XSignal.oer5f>(.text.Os_XSigInit)
        --library=os.aer5f*<Os_Application.oer5f>(.text.Os_AppInit)
        --library=os.aer5f*<Os_Resource.oer5f>(.text.Os_ResourceInit)
        --library=os.aer5f*<Os_Scheduler.oer5f>(.text.Os_SchedulerInit)
        --library=os.aer5f*<Os_TimingProtection.oer5f>(.text.Os_TpInit)
        --library=os.aer5f*<Os_Application.oer5f>(.text.Os_AppServicesInit)
        --library=os.aer5f*<Os_Stack.oer5f>(.text.Os_StackInitInternal)
        --library=os.aer5f*<Os_Error.oer5f>(.text.Os_ErrInit)
        --library=os.aer5f*<Os_Interrupt.oer5f>(.text.Os_InterruptInit)
        --library=os.aer5f*<Os_TimingProtection.oer5f>(.text.Os_TpReducedInit)
        --library=os.aer5f*<Os_Hal_Core.oer5f>(.text.Os_Hal_CoreInit)
        --library=os.aer5f*<Os_Barrier.oer5f>(.text.Os_BarrierInit)
        --library=os.aer5f*<Os_Barrier.oer5f>(.text.Os_BarrierAttach)
        --library=os.aer5f*<Os_Hal_Core.oer5f>(.text.Os_Hal_CoreInitHardware)
        --library=os.aer5f*<Os_Core.oer5f>(.text.Os_Hal_GetMultiprocessorIdRegister)
        --library=os.aer5f*<Os_Application.oer5f>(.text.Os_AppKillNoSuicide)
        --library=os.aer5f*<Os_Error.oer5f>(.text.Os_ErrKernelPanic)
        --library=os.aer5f*<Os_Barrier.oer5f>(.text.Os_BarrierDetach)
        --library=os.aer5f*<Os_Barrier.oer5f>(.text.Os_BarrierSynchronizeInternal)
        --library=os.aer5f*<Os_Isr.oer5f>(.text.Os_IsrRun)
      }
  /*    .OSCODE_RAM  :
      {

        --library=os.aer5f*<Os_AccessCheck.oer5f>(.OS_CODE)
        --library=os.aer5f*<Os_Core.oer5f>(.OS_CODE)
        --library=os.aer5f*<Os_Hal_Compiler_LlvmTI.oer5f>(.OS_CODE)
        --library=os.aer5f*<Os_Hook.oer5f>(.OS_CODE)
      }align(4)
      */
 }

GROUP : palign(8) > OCMC_RAM
    {
      .fastcode_can
      {

        CDD_E2EWrapper.oer5f (.text.*)
        SWC_VCANTx.oer5f (.text.*)
	SWC_VCANRx.oer5f (.text.*)
	SWC_SafeVCANRx.oer5f (.text.*)
	SWC_SafeVCANTx.oer5f (.text.*)

     }
    }
/*
GROUP : palign(8) > MCU0_R5F_TCMB0
  {

    .fastcode_ErrM
    {
       --library=errormanager.aer5f*<ErrorManagerAggDef.oer5f>(.text.ErrorMgr_getGetErrorDesc)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_B.oer5f>(.text.ErrorMgrAggregator_HandleNotification_1_0_B)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_B.oer5f>(.text.ErrorMgrAggregator_HandleNotification_2_0_B)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_B.oer5f>(.text.ErrorMgrAggregator_HandleNotification_2_1_B)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_B.oer5f>(.text.ErrorMgrAggregator_HandleNotification_QNX_B)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_B.oer5f>(.text.ErrorMgrAgg_GetDebug_ErrCount_B)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_B.oer5f>(.text.ErrorMgrAgg_GetDebug_ErrMgrSt_QM)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_B.oer5f>(.text.ErrorMgrAggregator_GetMonitorConf_B)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_B.oer5f>(.text.ErrorMgrAgg_GetDebug_ErrMgrStSize_B)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_QM.oer5f>(.text.ErrorMgrAggregator_HandleNotification_1_0_QM)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_QM.oer5f>(.text.ErrorMgrAggregator_HandleNotification_2_0_QM)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_QM.oer5f>(.text.ErrorMgrAggregator_HandleNotification_2_1_QM)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_QM.oer5f>(.text.ErrorMgrAggregator_HandleNotification_QNX_QM)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_QM.oer5f>(.text.ErrorMgrAgg_GetDebug_ErrCount_QM)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_QM.oer5f>(.text.ErrorMgrAgg_GetDebug_ErrMgrSt_QM)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_QM.oer5f>(.text.ErrorMgrAggregator_GetMonitorConf_QM)
        --library=errormanager.aer5f*<ErrorManagerAggregatorDef_QM.oer5f>(.text.ErrorMgrAgg_GetDebug_ErrMgrStSize_QM)
        --library=errormanager.aer5f*<ErrorManagerCallbacks_QM.oer5f>(.text.ErrorMgrAggregator_Callback_Clear_QM)
        --library=errormanager.aer5f*<ErrorManagerCallbacks_QM.oer5f>(.text.ErrorMgrAggregator_Callback_HandleError_LossOfCommm_QM)
        --library=errormanager.aer5f*<ErrorManagerCallbacks_QM.oer5f>(.text.ErrorMgrAggregator_Callback_WriteDtcData_QM)
        --library=errormanager.aer5f*<ErrorManagerCallbacks_B.oer5f>(.text.ErrorMgrAggregator_Callback_Clear_B)
        --library=errormanager.aer5f*<ErrorManagerCallbacks_B.oer5f>(.text.ErrorMgrAggregator_Callback_HandleError_LossOfCommm_B)
        --library=errormanager.aer5f*<ErrorManagerCallbacks_B.oer5f>(.text.ErrorMgrAggregator_Callback_WriteDtcData_B)
        --library=errormanager.aer5f*<ErrorManagerDef.oer5f>(.text.ErrorMgr_getErrorMapping)
        --library=errormanager.aer5f*<ErrorManagerSatDef.oer5f>(.text.ErrorMgr_getErrorCommPack)
        --library=errormanager.aer5f*<ErrorManagerSatDef.oer5f>(.text.ErrorMgr_getGetErrorLocalDesc)
        --library=errormanager.aer5f*<ErrorManagerSatelliteDef_B.oer5f>(.text.ErrorManagerSatelliteDef_Init_B)
        --library=errormanager.aer5f*<ErrorManagerSatelliteDef_QM.oer5f>(.text.ErrorManagerSatelliteDef_Init_QM)
        --library=errormanager.aer5f*<ErrorManagerAggregator.oer5f>(.text.ErrorMgrAggregator_Init_B)
        --library=errormanager.aer5f*<ErrorManagerAggregator.oer5f>(.text.ErrorMgrAggregator_Init_QM)
        --library=errormanager.aer5f*<ErrorManagerAggregator.oer5f>(.text.ErrorMgrAggregator_PeriodicFunction_B)
        --library=errormanager.aer5f*<ErrorManagerAggregator.oer5f>(.text.ErrorMgrAggregator_PeriodicFunction_QM)
        --library=errormanager.aer5f*<ErrorManagerAggregator.oer5f>(.text.ErrorMgrAggregator_VerifyCRC)
        --library=errormanager.aer5f*<ErrorManagerAggregator.oer5f>(.text.ErrorMgrAggregator_PeriodicFunction)
        --library=errormanager.aer5f*<ErrorManagerAggregator.oer5f>(.text.ErrorMgrAggregator_HandleandVerifyRunningCount)
        --library=errormanager.aer5f*<ErrorManagerAggregatorApp.oer5f>(.text.ErrorMgrAggregatorApp_Init)
        --library=errormanager.aer5f*<ErrorManagerAggregatorApp.oer5f>(.text.ErrorMgrAggregatorApp_ReadInputs)
        --library=errormanager.aer5f*<ErrorManagerAggregatorApp.oer5f>(.text.ErrorMgrAggregatorApp_Write_AsilGrouped_ErrorStatus)
        --library=errormanager.aer5f*<ErrorManagerAggregatorApp.oer5f>(.text.ErrorMgrAggregatorApp_Write_SafeState)
        --library=errormanager.aer5f*<ErrorManagerSatellite.oer5f>(.text.ErrorMgrSatellite_Init_B)
        --library=errormanager.aer5f*<ErrorManagerSatellite.oer5f>(.text.ErrorMgrSatellite_Init_QM)
        --library=errormanager.aer5f*<ErrorManagerSatellite.oer5f>(.text.ErrorMgrSatellite_PeriodicFunction)
        --library=errormanager.aer5f*<ErrorManagerSatellite.oer5f>(.text.ErrorMgrSatellite_PeriodicFunction_B)
        --library=errormanager.aer5f*<ErrorManagerSatellite.oer5f>(.text.ErrorMgrSatellite_PeriodicFunction_QM)
        --library=errormanager.aer5f*<ErrorManagerSatellite.oer5f>(.text.ErrorMgrSatellite_ReportErrorStatus)
        --library=errormanager.aer5f*<ErrorManagerSatelliteApp.oer5f>(.text.ErrorMgrSatelliteApp_Init)
        --library=errormanager.aer5f*<ErrorManagerSatelliteApp.oer5f>(.text.ErrorMggrSatelliteApp_Send)
        --library=gendata.aer5f*<Rte_OsApplication_Safety.oer5f>(.text.Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B)
        --library=gendata.aer5f*<Rte_OsApplication_Safety.oer5f>(.text.Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_B)
        --library=gendata.aer5f*<Rte_OsApplication_Safety.oer5f>(.text.Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_B)
        --library=gendata.aer5f*<Rte_OsApplication_QM.oer5f>(.text.Rte_Read_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM)
        --library=gendata.aer5f*<Rte_OsApplication_QM.oer5f>(.text.Rte_Read_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_QM)
        --library=gendata.aer5f*<Rte_OsApplication_QM.oer5f>(.text.Rte_Read_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_QM)
        --library=gendata.aer5f*<Rte_OsApplication_QM.oer5f>(.text.Rte_Read_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_QM)
        --library=gendata.aer5f*<Rte_OsApplication_Safety.oer5f>(.text.Rte_Write_ErrorMgrSat_1_0_B_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B)
        --library=gendata.aer5f*<Rte_OsApplication_QM.oer5f>(.text.Rte_Write_ErrorMgrSat_1_0_QM_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM)
         ErrorMgrSat_1_0_B.oer5f (.text.RE_Periodic_ErrorMgrSat_1_0_B)
         ErrorMgrSat_1_0_B.oer5f (.text.RE_ReportErrorStatus1_0_B)
         ErrorMgrSat_1_0_B.oer5f (.text.RE_Init_ErrorMgrSat_1_0_B)
         ErrorMgrSat_1_0_B.oer5f (.text.Rte_Write_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B_stub)
         ErrorMgrSat_1_0_QM.oer5f (.text.RE_Init_ErrorMgrSat_1_0_QM)
         ErrorMgrSat_1_0_QM.oer5f (.text.Rte_Write_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_stub)
         ErrorMgrSat_1_0_QM.oer5f (.text.RE_Periodic_ErrorMgrSat_1_0_QM)
        DegManager_B.oer5f (.text.Rte_DEGMANAGER_READ_QM_INPUT_BY_B)
        DegManager_B.oer5f (.text.Rte_Write_P_FID_Output_B_FID_B_stub)
        DegManager_B.oer5f (.text.Rte_Write_P_RES_Output_B_RES_B_stub)
        DegManager_B.oer5f (.text.RE_Init_DegManager_B)
        DegManager_B.oer5f (.text.RE_Periodic_DegManager_B)
        DegManager_B.oer5f (.text.Rte_DEGMANAGER_READ_B_INPUT_BY_B)
        DegManager_QM.oer5f (.text.Rte_Write_P_FID_Output_QM_FID_QM_stub)
        DegManager_QM.oer5f (.text.Rte_Write_P_RES_Output_QM_RES_QM_stub)
        DegManager_QM.oer5f (.text.RE_Init_DegManager_QM)
        DegManager_QM.oer5f (.text.RE_Periodic_DegManager_QM)
        DegManager_QM.oer5f (.text.Rte_DEGMANAGER_READ_B_INPUT_BY_QM)
        DegManager_QM.oer5f (.text.Rte_DEGMANAGER_READ_QM_INPUT_BY_QM)
        DegManager_QM.oer5f (.text.Rte_Call_R_IPC_IPC_Write_v_stub)
        ErrorMgrAgg_1_0_B.oer5f (.text.RE_Periodic_ErrorMgrAgg_1_0_B)
        ErrorMgrAgg_1_0_B.oer5f (.text.Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B_stub)
        ErrorMgrAgg_1_0_B.oer5f (.text.Rte_Call_DtcData_stub_B)
        ErrorMgrAgg_1_0_B.oer5f (.text.Rte_Write_P_SafeState_SafeStateOp_B_stub)
        ErrorMgrAgg_1_0_B.oer5f (.text.Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_B_stub)
        ErrorMgrAgg_1_0_B.oer5f (.text.Rte_Write_P_Errors_B_Errors_B_stub)
        ErrorMgrAgg_1_0_B.oer5f (.text.RE_Init_ErrorMgrAgg_1_0_B)
        ErrorMgrAgg_1_0_B.oer5f (.text.Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_B_stub)
        ErrorMgrAgg_1_0_QM.oer5f (.text.Rte_Call_DtcData_stub_QM)
        ErrorMgrAgg_1_0_QM.oer5f (.text.Rte_Write_P_SafeState_SafeStateOp_QM_stub)
        ErrorMgrAgg_1_0_QM.oer5f (.text.RE_Init_ErrorMgrAgg_1_0_QM)
        ErrorMgrAgg_1_0_QM.oer5f (.text.RE_Periodic_ErrorMgrAgg_1_0_QM)
        ErrorMgrAgg_1_0_QM.oer5f (.text.Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_stub)
        ErrorMgrAgg_1_0_QM.oer5f (.text.Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_QM_stub)
        ErrorMgrAgg_1_0_QM.oer5f (.text.Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_QM_stub)
        ErrorMgrAgg_1_0_QM.oer5f (.text.Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_QM_stub)
        ErrorMgrSat_1_0_QM.oer5f (.text.Rte_Write_PpSatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_stub)
        ErrorMgrAgg_1_0_QM.oer5f (.text.Rte_Write_P_Errors_QM_Errors_QM_stub)
        --library=degmanager.aer5f*<DegManagerCore_B.oer5f>(.text.DegManager_Init_B)
        --library=degmanager.aer5f*<DegManagerCore_B.oer5f>(.text.DegManager_Periodic_B)
        --library=degmanager.aer5f*<DegManager.oer5f>(.text.DegManager_FimCalcualtion)
        --library=degmanager.aer5f*<DegManager_app.oer5f>(.text.DegManagerApp_Read)
        --library=degmanager.aer5f*<DegManager_app.oer5f>(.text.DegManagerApp_Send)
        --library=degmanager.aer5f*<DegManagerCore_QM.oer5f>(.text.DegManager_Init_QM)
        --library=degmanager.aer5f*<DegManagerCore_QM.oer5f>(.text.DegManager_Periodic_QM)

	   }
  }
*/

  OSSTACK : align=4, load > MCU0_R5F_TCMB0
  {
    . = align(1024);
    *(.ABT_STACK)
    __ABORT_STACK_END = .;

    . = align(1024);
    *(.FIQ_STACK)
    __FIQ_STACK_END = .;

    . = align(1024);
    *(.IRQ_STACK)
    __IRQ_STACK_END = .;

    . = align(1024);
    *(.SVC_STACK)
    __SVC_STACK_END = .;

    . = align(1024);
    *(.UND_STACK)
    __UND_STACK_END = .;
  }

  OSSTACK_NOINIT : align=4, load > OCMC_RAM_SCISERVER
  {
      #define OS_LINK_KERNEL_STACKS
      #include "..\..\platform\asr\app_sip\GenData\mcu1_0\Os_Link_Core0_Stacks.ld"
  }

  OSCODE  : align=4, load > OCMC_RAM_SCISERVER
  {
      #define OS_LINK_CODE
      #include "..\..\platform\asr\app_sip\GenData\mcu1_0\Os_Link.ld"
  }

  OSCALLOUT_CODE  : align=4, load > OCMC_RAM_SCISERVER
  {
      #define OS_LINK_CALLOUT_CODE
      #include "..\..\platform\asr\app_sip\GenData\mcu1_0\Os_Link.ld"
  }

  OSINTVEC_CODE  : align=4, load > OCMC_RAM
  {
      #define OS_LINK_INTVEC_CODE
      #include "..\..\platform\asr\app_sip\GenData\mcu1_0\Os_Link_Core0.ld"
  }


  McalTextSection : fill=FILL_PATTERN, align=4, load > OCMC_RAM_SCISERVER1
  {
    .=align(4);
    __linker_spi_text_start = .;
    . += FILL_LENGTH;
    *(SPI_TEXT_SECTION)
    *(SPI_ISR_TEXT_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_spi_text_end = .;

    .=align(4);
    __linker_gpt_text_start = .;
    . += FILL_LENGTH;
    *(GPT_TEXT_SECTION)
    *(GPT_ISR_TEXT_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_gpt_text_end = .;

    .=align(4);
    __linker_dio_text_start = .;
    . += FILL_LENGTH;
    *(DIO_TEXT_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_dio_text_end = .;

    .=align(4);
    __linker_eth_text_start = .;
    . += FILL_LENGTH;
    *(ETH_TEXT_SECTION)
    *(ETH_ISR_TEXT_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_eth_text_end = .;

    .=align(4);
    __linker_ethtrcv_text_start = .;
    . += FILL_LENGTH;
    *(ETHTRCV_TEXT_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_ethtrcv_text_end = .;

    .=align(4);
    __linker_can_text_start = .;
    . += FILL_LENGTH;
    *(CAN_TEXT_SECTION)
    *(CAN_ISR_TEXT_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_can_text_end = .;

    .=align(4);
    __linker_wdg_text_start = .;
    . += FILL_LENGTH;
    *(WDG_TEXT_SECTION)
    *(WDG_ISR_TEXT_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_wdg_text_end = .;

    .=align(4);
    __linker_pwm_text_start = .;
    . += FILL_LENGTH;
    *(PWM_TEXT_SECTION)
    *(PWM_ISR_TEXT_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_pwm_text_end = .;

    __linker_adc_text_start = .;
    . += FILL_LENGTH;
    *(ADC_TEXT_SECTION)
    *(ADC_ISR_TEXT_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_adc_text_end = .;

    .=align(4);
    __linker_cdd_ipc_text_start = .;
    . += FILL_LENGTH;
    *(CDD_IPC_TEXT_SECTION)
    *(CDD_IPC_ISR_TEXT_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_cdd_ipc_text_end = .;

  }
  McalConstSection : fill=FILL_PATTERN, align=4, load > OCMC_RAM_SCISERVER1
  {
    .=align(4);
    __linker_spi_const_start = .;
    . += FILL_LENGTH;
    *(SPI_CONST_32_SECTION)
    *(SPI_CONFIG_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_spi_const_end = .;

    .=align(4);
    __linker_gpt_const_start = .;
    . += FILL_LENGTH;
    *(GPT_CONST_32_SECTION)
    *(GPT_CONFIG_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_gpt_const_end = .;

    .=align(4);
    __linker_dio_const_start = .;
    . += FILL_LENGTH;
    *(DIO_CONST_32_SECTION)
    *(DIO_CONST_UNSPECIFIED_SECTION)
    *(DIO_CONFIG_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_dio_const_end = .;

    .=align(4);
    __linker_can_const_start = .;
    . += FILL_LENGTH;
    *(CAN_CONST_8_SECTION)
    *(CAN_CONST_32_SECTION)
    *(CAN_CONFIG_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_can_const_end = .;

    .=align(4);
    __linker_eth_const_start = .;
    . += FILL_LENGTH;
    *(ETH_CONST_32_SECTION)
    *(ETH_CONFIG_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_eth_const_end = .;

    .=align(4);
    __linker_ethtrcv_const_start = .;
    . += FILL_LENGTH;
    *(ETHTRCV_CONST_32_SECTION)
    *(ETHTRCV_CONFIG_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_ethtrcv_const_end = .;

    .=align(4);
    __linker_wdg_const_start = .;
    . += FILL_LENGTH;
    *(WDG_CONST_32_SECTION)
    *(WDG_CONFIG_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_wdg_const_end = .;

    .=align(4);
    __linker_pwm_const_start = .;
    . += FILL_LENGTH;
    *(PWM_CONST_32_SECTION)
    *(PWM_CONFIG_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_pwm_const_end = .;

    .=align(4);
    __linker_adc_const_start = .;
    . += FILL_LENGTH;
    *(ADC_CONST_32_SECTION)
    *(ADC_CONFIG_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_adc_const_end = .;

    .=align(4);
    __linker_cdd_ipc_const_start = .;
    . += FILL_LENGTH;
    *(CDD_IPC_CONST_32_SECTION)
    *(CDD_IPC_CONFIG_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_cdd_ipc_const_end = .;
  }

  McalInitSection : fill=FILL_PATTERN, align=4, load > OCMC_RAM_SCISERVER1
  {
    .=align(4);
    __linker_spi_init_start = .;
    . += FILL_LENGTH;
    *(SPI_DATA_INIT_UNSPECIFIED_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_spi_init_end = .;

    .=align(4);
    __linker_gpt_init_start = .;
    . += FILL_LENGTH;
    *(GPT_DATA_INIT_32_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_gpt_init_end = .;

    .=align(4);
    __linker_pwm_init_start = .;
    . += FILL_LENGTH;
    *(PWM_DATA_INIT_32_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_pwm_init_end = .;

    .=align(4);
    __linker_dio_init_start = .;
    . += FILL_LENGTH;
    *(DIO_DATA_INIT_32_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_dio_init_end = .;

    .=align(4);
    __linker_eth_init_start = .;
    . += FILL_LENGTH;
    *(ETH_DATA_INIT_UNSPECIFIED_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_eth_init_end = .;

    .=align(4);
    __linker_ethtrcv_init_start = .;
    . += FILL_LENGTH;
    *(ETHTRCV_DATA_INIT_UNSPECIFIED_SECTION)
    *(ETHTRCV_DATA_INIT_32_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_ethtrcv_init_end = .;

    .=align(4);
    __linker_can_init_start = .;
    . += FILL_LENGTH;
    *(CAN_DATA_INIT_8_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_can_init_end = .;

    .=align(4);
    __linker_wdg_init_start = .;
    . += FILL_LENGTH;
    *(WDG_DATA_INIT_UNSPECIFIED_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_wdg_init_end = .;

    .=align(4);
    __linker_adc_init_start = .;
    . += FILL_LENGTH;
    *(ADC_DATA_INIT_UNSPECIFIED_SECTION)
    *(ADC_DATA_INIT_32_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_adc_init_end = .;

    .=align(4);
    __linker_cdd_ipc_init_start = .;
    . += FILL_LENGTH;
    *(CDD_IPC_DATA_INIT_UNSPECIFIED_SECTION)
    *(CDD_IPC_DATA_INIT_32_SECTION)
    *(CDD_IPC_DATA_INIT_8_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_cdd_ipc_init_end = .;
  }
  McalNoInitSection : fill=FILL_PATTERN, align=4, load > OCMC_RAM_SCISERVER1, type = NOINIT
  {
    .=align(4);
    __linker_spi_no_init_start = .;
    . += FILL_LENGTH;
    *(SPI_DATA_NO_INIT_UNSPECIFIED_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_spi_no_init_end = .;

    .=align(4);
    __linker_gpt_no_init_start = .;
    . += FILL_LENGTH;
    *(GPT_DATA_NO_INIT_UNSPECIFIED_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_gpt_no_init_end = .;

    .=align(4);
    __linker_dio_no_init_start = .;
    . += FILL_LENGTH;
    *(DIO_DATA_NO_INIT_UNSPECIFIED_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_dio_no_init_end = .;

    .=align(4);
    __linker_eth_no_init_start = .;
    . += FILL_LENGTH;
    *(ETH_DATA_NO_INIT_UNSPECIFIED_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_eth_no_init_end = .;

    .=align(4);
    __linker_ethtrcv_no_init_start = .;
    . += FILL_LENGTH;
    *(ETHTRCV_DATA_NO_INIT_UNSPECIFIED_SECTION)
    *(ETHTRCV_DATA_NO_INIT_16_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_ethtrcv_no_init_end = .;

    .=align(4);
    __linker_can_no_init_start = .;
    . += FILL_LENGTH;
    *(CAN_DATA_NO_INIT_UNSPECIFIED_SECTION)
    *(CAN_DATA_NO_INIT_32_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_can_no_init_end = .;

    .=align(4);
    __linker_wdg_no_init_start = .;
    . += FILL_LENGTH;
    *(WDG_DATA_NO_INIT_UNSPECIFIED_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_wdg_no_init_end = .;

    .=align(4);
    __linker_pwm_no_init_start = .;
    . += FILL_LENGTH;
    *(PWM_DATA_NO_INIT_UNSPECIFIED_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_pwm_no_init_end = .;

    __linker_adc_no_init_start = .;
    . += FILL_LENGTH;
    *(ADC_DATA_NO_INIT_UNSPECIFIED_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_adc_no_init_end = .;

    __linker_cdd_ipc_no_init_start = .;
    . += FILL_LENGTH;
    *(CDD_IPC_DATA_NO_INIT_UNSPECIFIED_SECTION)
    *(CDD_IPC_DATA_NO_INIT_8_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_cdd_ipc_no_init_end = .;

  }
  /* Example Utility specifics */
  VariablesAlignedNoInitSection : align=8, load > OCMC_RAM_SCISERVER1, type = NOINIT
  {
    .=align(8);
    __linker_cdd_ipc_no_init_align_8b_start = .;
    . += FILL_LENGTH;
    *(CDD_IPC_DATA_NO_INIT_8_ALIGN_8B_SECTION)
    .=align(8);
    . += FILL_LENGTH;
    __linker_cdd_ipc_no_init_align_8b_end = .;
  }
  /* Example Utility specifics */
  UtilityNoInitSection : align=4, load > OCMC_RAM, type = NOINIT
  {
    .=align(4);
    __linker_utility_no_init_start = .;
    . += FILL_LENGTH;
    *(EG_TEST_RESULT_32_SECTION)
    .=align(4);
    . += FILL_LENGTH;
    __linker_utility_no_init_end = .;
  }
  SciClientBoardCfgSection : align=128, load > OCMC_RAM, type = NOINIT
  {
    .=align(128);
    __linker_boardcfg_data_start = .;
    . += FILL_LENGTH;
    *(.boardcfg_data)
    .=align(128);
    . += FILL_LENGTH;
    __linker_boardcfg_data_end = .;
  }
  /* This section is used for descs and ring mems. It's best to have
  * it in OCMRAM or MSMC3 */
  McalUdmaSection : fill=FILL_PATTERN, align=128, load > OCMC_RAM
  {
    .=align(128);
    __linker_eth_udma_start = .;
    . += FILL_LENGTH;
    *(ETH_UDMA_SECTION)
    .=align(128);
    . += FILL_LENGTH;
    __linker_eth_udma_end = .;
  }
  McalTxDataSection : fill=FILL_PATTERN, align=128, load > OCMC_RAM_SCISERVER1, type = NOINIT
  {
    .=align(128);
    __linker_eth_tx_data_start = .;
    . += FILL_LENGTH;
    *(ETH_TX_DATA_SECTION)
    .=align(128);
    . += FILL_LENGTH;
    __linker_eth_tx_data_end = .;
  }
  McalRxDataSection : fill=FILL_PATTERN, align=128, load > OCMC_RAM_SCISERVER1, type = NOINIT
  {
    .=align(128);
    __linker_eth_rx_data_start = .;
    . += FILL_LENGTH;
    *(ETH_RX_DATA_SECTION)
    .=align(128);
    . += FILL_LENGTH;
    __linker_eth_rx_data_end = .;
  }


 /* DDR_PART_NUMBER : load > MCU1_0_DDR_PART, type = NOINIT
  {

  } */

/* Magic Flag 8 bytes allocated */
  reset_protected_ram : load > MCU_PSRAM0_RAM, type = NOINIT
  {
  }
/* Safe Shut Down Flag 4 bytes allocated */
  reset_protected_ram_ShutDownFlag : load > MCU_PSRAM0_RAM_SAFE_SHUTDOWN_FLAG, type = NOINIT
  {
  }
/* 2 Byte  : FBL Reset Handling */
  reset_protected_ram_FBL_ResetHandling : load > MCU_PSRAM0_RAM_FBL_RESET_HANDLE, type = NOINIT
  {
  }
/* 86 Byte  : System Debug Data To Can */
  reset_protected_ram_DebugDataToCAN : load > MCU_PSRAM0_RAM_DEBUG_DATA_CAN, type = NOINIT
  {
  }   
  autosarvar : load > OCMC_RAM_SCISERVER, type = NOINIT
  {
  }
}  /* end of SECTIONS */

/*----------------------------------------------------------------------------*/
/* Misc linker settings                                                       */


/*-------------------------------- END ---------------------------------------*/
