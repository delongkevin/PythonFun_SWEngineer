# Default bootmode for Main domain cores is via MMCSD, unless specified at command line differently
#BOOTMODE ?= mmcsd
BOOTMODE ?= ospi
# Default OSPI DMA to "yes" (enabled).  Change to "no", if building PDK SBL with -DSBL_USE_DMA=0
ENABLE_OSPI_DMA ?= yes
# Boot function options are enabled or disabled
BOOTFUNC ?= enabled
#BOOTFUNC ?= disabled
# HLOS Boot options are linux, qnx, or none (rtos is loaded)
#HLOSBOOT ?= linux
HLOSBOOT ?= qnx
#HLOSBOOT ?= none
#Default App Log Levels
APP_LOG_LEVEL ?= 1

# BIST options are enabled or disabled
BISTFUNC ?= disabled
#Setting BISTFUNC to enabled is only supported on j721e
#BISTFUNC ?= enabled
$(info Building Autosar Boot App with BISTFUNC=$(BISTFUNC), BOOTFUNC=$(BOOTFUNC), HLOSBOOT=$(HLOSBOOT), BOOTMODE=$(BOOTMODE))
include $(MCUSW_INSTALL_PATH)/build/Rules.make
include $(PDK_INSTALL_PATH)/ti/drv/spi/spi_component.mk
PDK_SBL_COMP_PATH = $(PDK_INSTALL_PATH)/ti/boot/sbl

APP_NAME = fisker_hydra_mcu1_0_boot_app_rtos

SRCDIR += boot/
SRCDIR += os/
SRCDIR += SWC_DiagnosticMgr/
#SRCDIR += SWC_PartNumMgr/
SRCDIR += SWC_VoltageMgr/
SRCDIR += SWC_ErrorMgr/
SRCDIR += SWC_DegManager/
SRCDIR += SWC_SSM/
SRCDIR += IoHwAb/
SRCDIR += SWC_ProxiConfigMgr/
SRCDIR += SWC_VCANMgr/
SRCDIR += SWC_SafeVCANMgr/
SRCDIR += Safety_Guard/
SRCDIR += CDD_PMIC/
SRCDIR += CDD_WDG/
SRCDIR += CDD_GenericBswM/
SRCDIR += CDD_CryptoMgr/
SRCDIR += CDD_E2EWrapper/
SRCDIR += CDD_IPCHandler/
SRCDIR += SWC_KinematicModule/
SRCDIR += CalDataProvider/
SRCDIR += ../../common/pmic/
SRCDIR += ../../common/pmic/pmic_voltmon
SRCDIR += ../../common/pmic/pmic_lbist
SRCDIR += ../../common/pmic/pmic_thermal_warning_and_shutdown
SRCDIR += ../../common/pmic/pmic_clock_monitoring
SRCDIR += ../../common/pmic/pmic_mcu_esm
SRCDIR += ../../common/pmic/pmic_register_lock
SRCDIR += ../../common/pmic/pmic_bist_sts
SRCDIR += ../../common/pmic/pmic_readback
SRCDIR += ../../common/pmic/pmic_utils
SRCDIR += ../../common/pmic/pmic_crc
SRCDIR += MeOsprofiling/
SRCDIR += SWC_WdgFw/
SRCDIR += CDD_Safety/
SRCDIR += Cdd_RunTimeStats_QM/
SRCDIR += Cdd_RunTimeStats_B/

INCDIR = .

INCDIR += boot/
INCDIR += os/
INCDIR += SWC_DiagnosticMgr/
#INCDIR += SWC_PartNumMgr/
INCDIR += SWC_VoltageMgr/
INCDIR += SWC_ErrorMgr/
INCDIR += SWC_DegManager/
INCDIR += SWC_SSM/
INCDIR += IoHwAb/
INCDIR += SWC_ProxiConfigMgr/
INCDIR += SWC_VCANMgr/
INCDIR += SWC_SafeVCANMgr/
INCDIR += Safety_Guard/
INCDIR += CDD_PMIC/
INCDIR += CDD_WDG/
INCDIR += CDD_GenericBswM/
INCDIR += CDD_CryptoMgr/
INCDIR += CDD_E2EWrapper/
INCDIR += CDD_IPCHandler/
INCDIR += SWC_KinematicModule/
INCDIR += CalDataProvider/
INCDIR += MeOsProfiling/
INCDIR += ../../common/pmic/
INCDIR += ../../common/pmic/pmic_voltmon
INCDIR += ../../common/pmic/pmic_lbist
INCDIR += ../../common/pmic/pmic_thermal_warning_and_shutdown
INCDIR += ../../common/pmic/pmic_clock_monitoring
INCDIR += ../../common/pmic/pmic_mcu_esm
INCDIR += ../../common/pmic/pmic_register_lock
INCDIR += ../../common/pmic/pmic_bist_sts
INCDIR += ../../common/pmic/pmic_readback
INCDIR += ../../common/pmic/pmic_utils
INCDIR += ../../common/pmic/pmic_crc
INCDIR += CDD_Safety/
INCDIR += Cdd_RunTimeStats_QM/
INCDIR += Cdd_RunTimeStats_B/

INCDIR += ../../bookshelf/includes/
INCDIR += ../../bookshelf/ErrorManager/inc
INCDIR += ../../bookshelf/CalDataProvider/inc
INCDIR += ../../bookshelf/ErrorManager/gen
INCDIR += ../../bookshelf/ErrorManager/cfg
INCDIR += ../../bookshelf/ipc_manager/cfg
INCDIR += ../../bookshelf/ipc_manager/inc

INCDIR += ../../bookshelf/FuSa/fusa_app
INCDIR += ../../bookshelf/FuSa/vtm
INCDIR += ../../bookshelf/FuSa/bist
INCDIR += ../../bookshelf/FuSa/magna/adc
INCDIR += ../../bookshelf/FuSa/magna/GPIO_Safety
INCDIR += ../../bookshelf/FuSa/magna/MSMC_Safety
INCDIR += ../../bookshelf/FuSa/magna/reset
INCDIR += ../../bookshelf/FuSa/magna/mmr_safety
INCDIR += ../../bookshelf/FuSa/magna/timers
INCDIR += ../../bookshelf/WdgFw/Common
INCDIR += ../../bookshelf/WdgFw/Wdg/inc
INCDIR += ../../bookshelf/WdgFw/Wdg/cfg
INCDIR += ../../bookshelf/WdgFw/WdgIf/inc
INCDIR += ../../bookshelf/WdgFw/WdgIf/cfg
INCDIR += ../../bookshelf/WdgFw/WdgM/inc
INCDIR += ../../bookshelf/WdgFw/WdgM/cfg
INCDIR += ../../bookshelf/WdgFw/WdgSlave/inc
INCDIR += ../../bookshelf/WdgFw/WdgSlave/cfg
INCDIR += ../../bookshelf/PerformanceStats/AddRuntimeStats/inc

INCDIR += $(PDK_INSTALL_PATH)/ti/drv/ipc/include
INCDIR += $(PDK_INSTALL_PATH)/ti/drv/pmic
INCDIR += $(PDK_INSTALL_PATH)/ti/drv/pmic/src
INCDIR += $(PDK_INSTALL_PATH)/ti/drv/pmic/include
INCDIR += $(PDK_INSTALL_PATH)/ti/board/src/devices/pmic
INCDIR += $(PDK_SBL_COMP_PATH)
INCDIR += $(PDK_SBL_COMP_PATH)/soc
INCDIR += $(PDK_SBL_COMP_PATH)/board/src
INCDIR += $(PDK_SBL_COMP_PATH)/src/rprc
INCDIR += $(PDK_SBL_COMP_PATH)/src/$(BOOTMODE)
INCDIR += $(PDK_SBL_COMP_PATH)/soc/k3
INCDIR += ../../platform/asr/ti_mcal/ADC/Include
INCDIR += ../../platform/asr/ti_mcal/Dio/Include
INCDIR += ../../platform/asr/ti_mcal/CddIpc/include
INCDIR += $(PDK_INSTALL_PATH)/ti/drv/sciclient
INCDIR += $(PDK_INSTALL_PATH)/ti/drv/sciclient/include
INCDIR += ../../platform/inc
INCDIR +=../../bookshelf/includes

INCDIR +=../../bookshelf/main_domain/console_io/include
INCDIR +=../../bookshelf/magna_apps/KM/code
INCDIR +=../../bookshelf/FuSa/bist


INCDIR += $(PDK_INSTALL_PATH)
INCDIR += $(PDK_INSTALL_PATH)/ti/board
ifeq ($(BOARD),$(filter $(BOARD), j721e_hyd))
INCDIR += $(PDK_INSTALL_PATH)/ti/board/src/j721e_hyd/include
endif
ifeq ($(BOARD),$(filter $(BOARD), j721s2_evm))
INCDIR += $(PDK_INSTALL_PATH)/ti/board/src/j721s2_evm/include
endif
ifeq ($(BOARD),$(filter $(BOARD), j721s2_hyd))
INCDIR += $(PDK_INSTALL_PATH)/ti/board/src/j721s2_hyd/include
endif
INCDIR += $(PDK_INSTALL_PATH)/ti/board/src/flash/include

# SDL Library Files
INCDIR += $(SOC)/
INCDIR += $(PSDK_SDL_INSTALL_PATH)/
INCDIR += $(PSDK_SDL_INSTALL_PATH)/osal/
INCDIR += $(PSDK_SDL_INSTALL_PATH)/src/sdl
INCDIR += $(PSDK_SDL_INSTALL_PATH)/src/ip
INCDIR += $(PSDK_SDL_INSTALL_PATH)/include
INCDIR += $(PSDK_SDL_INSTALL_PATH)/include/soc/$(SOC)

ifeq ($(SOC),$(filter $(SOC), j721e j7200 j721s2))
INCDIR += soc/$(SOC)/
endif

INCDIR += $(SDK_INSTALL_PATH)/rtos/pdk/packages/ti/board/src/j721s2_hyd/include

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk

INCLUDE_INTERNAL_INTERFACES = board bswm cdd_ipc mcan cansm com comm det os ecum pdur vstdlib stubs gendata canif cantp dcm dem ea eep vi2c memif nvm cantrcv_tja1043 dio cannm nm crc $(BOOTMODE) vRoE adc errormanager systemstate_manager degmanager KM CalDataProvider xcp canxcp

INCLUDE_INTERNAL_INTERFACES += Crypto_30_vHsm Csm CryIf vdiagsecacc wdgm wdgif wdg_magna vdam console_io wdgSlave

# List all the components required by the application
COMP_LIST_COMMON = bswm cdd_ipc mcan cansm com comm det os ecum pdur vstdlib stubs gendata canif cantrcv_tja1043 dio cannm nm cantp dcm dem ea eep vi2c memif nvm crc vRoE adc errormanager ipc_manager systemstate_manager degmanager KM CalDataProvider xcp canxcp FUSA
COMP_LIST_COMMON += Crypto_30_vHsm Csm CryIf vdiagsecacc wdgm wdgif wdg_magna vdam wdgSlave
COMP_LIST_COMMON += console_io

# List all the external ibs required by the application
EXT_LIB_LIST_COMMON += $(csl_LIBPATH)/$(SOC)/$(ISA_EXT)/$(BUILD_PROFILE_$(CORE))/$(csl_LIBNAME).$(LIBEXT)
EXT_LIB_LIST_COMMON += $(csl_init_LIBPATH)/$(SOC)/$(ISA_EXT)/$(BUILD_PROFILE_$(CORE))/ti.csl.init.$(LIBEXT)
EXT_LIB_LIST_COMMON += $(gpio_LIBPATH)/$(SOC)/mcu1_0/release/ti.drv.gpio.aer5f
EXT_LIB_LIST_COMMON += $(pmic_LIBPATH)/$(BOARD)/r5f/$(BUILD_PROFILE)/pmic.aer5f


#added for SDL integration:
EXT_LIB_LIST_COMMON += $(PSDK_SDL_INSTALL_PATH)/binary/osal/lib/$(SOC)/r5f/$(BUILD_PROFILE)/sdl_osal.$(LIBEXT)
EXT_LIB_LIST_COMMON += $(PSDK_SDL_INSTALL_PATH)/binary/src/ip/lib/$(SOC)/r5f/$(BUILD_PROFILE)/sdl_ip.$(LIBEXT)
EXT_LIB_LIST_COMMON += $(PSDK_SDL_INSTALL_PATH)/binary/src/sdl/lib/$(SOC)/r5f/$(BUILD_PROFILE)/sdl_api.$(LIBEXT)
EXT_LIB_LIST_COMMON += $(PSDK_SDL_INSTALL_PATH)/binary/src/ip/r5/lib/$(SOC)/r5f/$(BUILD_PROFILE)/r5f_core.$(LIBEXT)

# Required for sciclient
ifeq ($(SOC),$(filter $(SOC), j721e j7200 j721s2))
ifeq ($(CORE),mcu1_0)
EXT_LIB_LIST_COMMON += $(sciclient_direct_autosar_LIBPATH)/$(SOC)/$(CORE)/$(BUILD_PROFILE_$(CORE))/$(sciclient_direct_autosar_LIBNAME).$(LIBEXT)
EXT_LIB_LIST_COMMON += $(sciserver_autosaros_LIBPATH)/$(SOC)/$(CORE)/$(BUILD_PROFILE_$(CORE))/$(sciserver_autosaros_LIBNAME).$(LIBEXT)
EXT_LIB_LIST_COMMON += $(rm_pm_hal_LIBPATH)/$(SOC)/$(CORE)/$(BUILD_PROFILE_$(CORE))/$(rm_pm_hal_LIBNAME).$(LIBEXT)
  else
  EXT_LIB_LIST_COMMON += $(sciclient_LIBPATH)/$(SOC)/$(CORE)/$(BUILD_PROFILE_$(CORE))/$(sciclient_LIBNAME).$(LIBEXT)
  endif
else
  EXT_LIB_LIST_COMMON += $(sciclient_LIBPATH)/$(SOC)/$(CORE)/$(BUILD_PROFILE_$(CORE))/$(sciclient_LIBNAME).$(LIBEXT)
endif

# Required for PM (for timer setup)
EXT_LIB_LIST_COMMON += $(pm_lib_LIBPATH)/$(SOC)/$(ISA_EXT)/$(BUILD_PROFILE_$(CORE))/$(pm_lib_LIBNAME).$(LIBEXT)
# Required for uart
EXT_LIB_LIST_COMMON += $(uart_LIBPATH)/$(SOC)/$(ISA_EXT)/$(BUILD_PROFILE_$(CORE))/$(uart_LIBNAME).$(LIBEXT)
#Board module
EXT_LIB_LIST_COMMON += $(board_app_$(BOOTMODE)_LIBPATH)/$(BOARD)/$(ISA_EXT)/$(BUILD_PROFILE_$(CORE))/$(board_app_$(BOOTMODE)_LIBNAME).$(LIBEXT)
# Required by board
EXT_LIB_LIST_COMMON += $(i2c_LIBPATH)/$(SOC)/$(ISA_EXT)/$(BUILD_PROFILE_$(CORE))/$(i2c_LIBNAME).$(LIBEXT)
#added for IPC driver integration dependency
EXT_LIB_LIST_COMMON += $(osal_autosaros_LIBPATH)/$(SOC)/$(ISA)/$(BUILD_PROFILE_$(CORE))/$(osal_autosaros_LIBNAME).$(LIBEXT)
#added for IPC driver integration:
EXT_LIB_LIST_COMMON += $(ipc_baremetal_LIBPATH)/$(SOC)/$(CORE)/$(BUILD_PROFILE_$(CORE))/$(ipc_baremetal_LIBNAME).$(LIBEXT)

ifeq ($(BOOTMODE), mmcsd)
$(info DebugInfo2 sbl_lib_mmcsd_LIBNAME=$(sbl_lib_mmcsd_LIBNAME),fatfs_indp_LIBNAME=$(fatfs_indp_LIBNAME),mmcsd_LIBNAME=$(mmcsd_LIBNAME))
    INCDIR += $(PDK_SBL_COMP_PATH)/src/mmcsd
    COMP_LIST_COMMON += mmcsd sbl_lib_mmcsd fatfs_indp

    # Required for sbl
    EXT_LIB_LIST_COMMON += $(sbl_lib_mmcsd_LIBPATH)/$(BOARD)/$(ISA_EXT)/$(BUILD_PROFILE_$(CORE))/$(sbl_lib_mmcsd_LIBNAME).$(LIBEXT)
    EXT_LIB_LIST_COMMON += $(fatfs_indp_LIBPATH)/$(ISA_EXT)/$(BUILD_PROFILE_$(CORE))/$(fatfs_indp_LIBNAME).$(LIBEXT)
    EXT_LIB_LIST_COMMON += $(mmcsd_LIBPATH)/$(SOC)/$(ISA_EXT)/$(BUILD_PROFILE_$(CORE))/$(mmcsd_LIBNAME).$(LIBEXT)
endif

ifeq ($(BOOTMODE), $(filter $(BOOTMODE), ospi qspi))
  ifeq ($(ENABLE_OSPI_DMA), yes)
    COMP_LIST_COMMON += board_app_$(BOOTMODE) udma spi_dma_app sbl_lib_$(BOOTMODE)

    EXT_LIB_LIST_COMMON += $(udma_LIBPATH)/$(SOC)/$(CORE)/$(BUILD_PROFILE)/$(udma_LIBNAME).$(LIBEXT)
    EXT_LIB_LIST_COMMON += $(spi_dma_app_LIBPATH)/$(SOC)/$(CORE)/$(BUILD_PROFILE_$(CORE))/$(spi_dma_app_LIBNAME).$(LIBEXT)
  else
    COMP_LIST_COMMON += spi board_app_$(BOOTMODE) sbl_lib_$(BOOTMODE)_nondma

    EXT_LIB_LIST_COMMON += $(PDK_SPI_COMP_PATH)/lib/$(SOC)/$(ISA_EXT)/$(BUILD_PROFILE_$(CORE))/ti.drv.spi.$(LIBEXT)
  endif
endif

INCLUDE_EXTERNAL_INTERFACES += xdc bios
SRCS_COMMON = Tasks.c
SRCS_COMMON += SWC_DIDMgr.c
SRCS_COMMON += SWC_DTCMgr.c
SRCS_COMMON += SWC_RIDMgr.c
SRCS_COMMON += SWC_PartNumMgr.c
SRCS_COMMON += SWC_VoltageMgr.c
SRCS_COMMON += SWC_ErrorMgr/ErrorMgrAgg_1_0_B.c
SRCS_COMMON += SWC_ErrorMgr/ErrorMgrAgg_1_0_QM.c
SRCS_COMMON += SWC_ErrorMgr/ErrorMgrSat_1_0_B.c
SRCS_COMMON += SWC_ErrorMgr/ErrorMgrSat_1_0_QM.c
SRCS_COMMON += SWC_DegManager/DegManager_B.c
SRCS_COMMON += SWC_DegManager/DegManager_QM.c
SRCS_COMMON += SWC_SSM/SSM_Master.c
SRCS_COMMON += SWC_SSM/SSM_Slave_1_0.c
SRCS_COMMON += IoHwAb/IoHwAb.c
SRCS_COMMON += SWC_ProxiConfigMgr.c
SRCS_COMMON += SWC_VCANRx.c
SRCS_COMMON += SWC_VCANTx.c
SRCS_COMMON += SWC_SafeVCANRx.c
SRCS_COMMON += SWC_SafeVCANTx.c
SRCS_COMMON += Safety_Guard.c
SRCS_COMMON += CDD_PMIC.c
SRCS_COMMON += CDD_WDG.c
SRCS_COMMON += CDD_GenericBswM.c
SRCS_COMMON += CDD_CryptoMgr.c
SRCS_COMMON += CDD_E2EWrapper.c
SRCS_COMMON += CDD_IPCHandler.c
SRCS_COMMON += SWC_KinematicModule.c
SRCS_COMMON += CalDataProvider.c
SRCS_COMMON += pmic.c pmic_cfg.c pmic_safe_state.c pmic_voltmon.c pmic_voltmon_cfg.c pmic_error.c pmic_lbist.c pmic_thermal_warn_shutdown.c pmic_clock_mon.c pmic_mcu_esm.c pmic_reg_lock.c pmic_bist_sts.c pmic_readback.c
SRCS_COMMON += pmic_utils.c
SRCS_COMMON += pmic_crc_mon.c
SRCS_COMMON += boot_core_defs.c boot.c stacks.c
SRCS_COMMON += MeOsProfiling.c
SRCS_COMMON += SWC_WdgFw.c
SRCS_COMMON += CDD_Safety.c
SRCS_COMMON += Cdd_RunTimeStats_QM.c
SRCS_COMMON += Cdd_RunTimeStats_B.c

ifeq ($(ADDRUNTIMESTATS),RT_ENABLE)
INCLUDE_EXTERNAL_INTERFACES += AddRuntimeStats
COMP_LIST_COMMON += AddRuntimeStats
CFLAGS_LOCAL_COMMON += -DADDRUNTIMESTATS
endif

# Enable copy of vectors
ifeq ($(ISA),$(filter $(ISA), r5f))
  SRCS_ASM_COMMON += utilsCopyVecs2ATcm.asm
endif

# Enable XDC build for application by providing XDC CFG File per core
EXTERNAL_LNKCMD_FILE_LOCAL = $(fisker_hydra_PATH)/mcu1_0/app/linker_r5_sysbios.lds


PACKAGE_SRCS_COMMON = .

CFLAGS_LOCAL_COMMON += $(MCUSW_CFLAGS)
LNKFLAGS_LOCAL_COMMON = $(MCUSW_LNKFLAGS)

#BUILD_MCU1_0 macro used by Error Manager conditional compilation.
CFLAGS_LOCAL_COMMON += -DBUILD_MCU1_0

CFLAGS_LOCAL_COMMON += -DSBL_LOG_LEVEL=0
CFLAGS_LOCAL_COMMON += -DBOOT_TASK_ENABLED
#CFLAGS_LOCAL_COMMON += -DMPU1_HLOS_BOOT_ENABLED -DQNX_OS

#D_DV_BOARD flag used to compile DV board version.
CFLAGS_LOCAL_COMMON += -DD_DV_BOARD

ifeq ($(BOOTMODE), mmcsd)
    CFLAGS_LOCAL_COMMON += -DBOOT_MMCSD
endif
ifeq ($(BOOTMODE), ospi)
    CFLAGS_LOCAL_COMMON += -DBOOT_OSPI
  ifeq ($(ENABLE_OSPI_DMA), yes)
    CFLAGS_LOCAL_COMMON += -DENABLE_DMA
  endif
endif

ifeq ($(BOOTMODE), qspi)
    CFLAGS_LOCAL_COMMON += -DBOOT_QSPI
  ifeq ($(ENABLE_OSPI_DMA), yes)
    CFLAGS_LOCAL_COMMON += -DENABLE_DMA
  endif
endif

ifeq ($(ENABLE_EEP_DEBUG), yes)
    CFLAGS_LOCAL_COMMON += -DEEP_DEBUG
endif

ifeq ($(ENABLE_KEEP_ALIVE), yes)
    CFLAGS_LOCAL_COMMON += -DKEEP_ALIVE_NO_CAN
endif

ifeq ($(HLOSBOOT), qnx)
    CFLAGS_LOCAL_COMMON += -DMPU1_HLOS_BOOT_ENABLED -DHLOS_BOOT_QNX_OS
endif

ifneq ($(APP_LOG_LEVEL), "")
    CFLAGS_LOCAL_COMMON += -DAPP_LOG_LEVEL=$(APP_LOG_LEVEL)
endif

# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk
include $(MAKERULEDIR)/build_config.mk
