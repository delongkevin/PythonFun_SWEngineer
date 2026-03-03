include $(MCUSW_INSTALL_PATH)/build/Rules.make
BUILD_OS_TYPE?=safertos
BOOTMODE ?= qspi
APP_NAME = fisker_hydra_app_mcu2_1
AP_FUSION_EN=no
AUTO_PARK_EN = yes
ENABLE_THA_SM_VC = yes
ENABLE_OBJECT_FUSION = no
ENABLE_OBJECT_FUSION_CALL = no
NFCD_EN = no
FOD_EN = yes
ARBITER_EN = yes
ENABLE_TIME_MANAGE = no
ENABLE_TRSC = yes

SRCDIR = . os/
ifeq ($(ENABLE_TIME_MANAGE), yes)
SRCDIR += TimeManagerProxy
endif
SRCDIR += Safety_CDD
ifeq ($(BUILD_OS_TYPE),freertos)
SRCDIR += $(fisker_hydra_PATH)/bookshelf/PerformanceStats/cpu_load/src
endif
SRCDIR += $(fisker_hydra_PATH)/bookshelf/FuSa/vim
SRCDIR += $(fisker_hydra_PATH)/bookshelf/FuSa/magna/timers


INCLUDE_EXTERNAL_INTERFACES = pdk uart csl csl_init board sciclient

ifeq ($(AUTO_PARK_EN), yes)
INCLUDE_EXTERNAL_INTERFACES += autopark
endif
ifeq ($(ENABLE_THA_SM_VC), yes)
INCLUDE_EXTERNAL_INTERFACES += tha_sm_vc
endif
ifeq ($(ENABLE_OBJECT_FUSION), yes)
INCLUDE_EXTERNAL_INTERFACES += RAEB_ObjectFusion
endif
ifeq ($(FOD_EN), yes)
INCLUDE_EXTERNAL_INTERFACES += FOD
endif
ifeq ($(ARBITER_EN), yes)
INCLUDE_EXTERNAL_INTERFACES += Arbiter
endif
ifeq ($(ENABLE_TRSC), yes)
INCLUDE_EXTERNAL_INTERFACES += trsc
endif


INCLUDE_INTERNAL_INTERFACES = wdgm_magna

INCDIR += ../../sw/platform/inc

INCLUDE_INTERNAL_INTERFACES =
ifeq ($(ENABLE_TIME_MANAGE), yes)
INCDIR += TimeManagerProxy
endif
INCDIR += Safety_CDD

INCDIR += $(fisker_hydra_PATH)/mcu2_1/os/
INCDIR += $(fisker_hydra_PATH)/bookshelf/PerformanceStats/AddRuntimeStats/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/PerformanceStats/RuntimeStats/inc
INCDIR += $(fisker_hydra_PATH)/platform/inc/
INCDIR += $(fisker_hydra_PATH)/platform/utils/
INCDIR += $(fisker_hydra_PATH)/bookshelf/includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/CalDataProvider/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/Common
INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/Wdg/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/CalDataProvider/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/algo/_sharedutils
INCDIR += $(fisker_hydra_PATH)/mcu2_1/App/USS/US_Manager
INCDIR += $(fisker_hydra_PATH)/mcu2_1/App/USS/US_Includes
INCDIR += $(fisker_hydra_PATH)/mcu2_1/App/USS/Us_Csm
INCDIR += $(fisker_hydra_PATH)/mcu2_1/App/USS/US_Platform/US_Platform_Source

INCDIR += $(fisker_hydra_PATH)/bookshelf/includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/WdgIf/inc

INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/KM/code
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps
INCDIR += $(fisker_hydra_PATH)/bookshelf/PerformanceStats/cpu_load/inc
INCDIR += $(PDK_BOARD_COMP_PATH)/src/j721s2_hyd/include
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/common_includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/algo/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/Arbiter/FeatureArbiter_ert_rtw/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA
#INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/Wdg/inc
#INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/WdgM/inc
#INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/Common
INCDIR += $(fisker_hydra_PATH)/bookshelf/FuSa/vim
INCDIR += $(fisker_hydra_PATH)/bookshelf/FuSa/magna/timers
INCDIR += $(fisker_hydra_PATH)/bookshelf/main_domain/console_io/include
SAFERTOS_PATH = $(TOOLS_INSTALL_PATH)/ti-psdk-rtos-j721s2-08_05_00_11/SafeRTOS_TI_CR5_Clang_TDA4VL_DAP_v9.4.1_SAFECheckpoints/source_code_and_projects/SafeRTOS
INCDIR += $(SAFERTOS_PATH)/api/199_TI_CR5
INCDIR += $(SAFERTOS_PATH)/config
INCDIR += $(SAFERTOS_PATH)/kernel/include_api
INCDIR += $(SAFERTOS_PATH)/portable/199_TI_CR5
INCDIR += $(SAFERTOS_PATH)/portable/199_TI_CR5/024_Clang
INCDIR += $(SAFERTOS_PATH)/api/PrivWrapperStd
INCDIR += $(SAFERTOS_PATH)/checkpoints

ifeq ($(AUTO_PARK_EN), yes)
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/autopark/code
endif
ifeq ($(ENABLE_THA_SM_VC), yes)
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/tha_sm_vc/code
endif
ifeq ($(ENABLE_OBJECT_FUSION), yes)
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/RAEB_ObjectFusion/code
endif
ifeq ($(NFCD_EN), yes)
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/nfcd/code
endif
ifeq ($(FOD_EN), yes)
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/FOD/
endif
ifeq ($(ARBITER_EN), yes)
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/Arbiter/code
endif
ifeq ($(ENABLE_TRSC), yes)
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/code
endif

#COMP_LIST_COMMON = uart board_app sciclient

SRCS_COMMON    += ./App/USS/US_Platform/US_Platform.c \
               ./App/USS/US_Platform/US_Platform_Source/US_Task.c \
               ./App/USS/US_Platform/US_Platform_Source/US_DSI3Drv.c \
		       ./App/USS/US_Platform/US_Platform_Source/US_HsdMain.c \
               ./App/USS/US_Platform/US_Platform_Source/US_Hsd_Stub.c \
		       ./App/USS/US_Platform/US_Platform_Source/US_HsdGpioHandler.c \
			   ./App/USS/US_Platform/US_Platform_Source/US_ErrMgr.c \
			   ./App/USS/US_Platform/US_Platform_Source/US_ErrMgrCfg.c 

SRCS_COMMON    += ./App/USS/US_Odometry/US_OdoKinematics.c 

SRCS_COMMON    += ./App/USS/US_SnrDrv/US_SnrDrvCom.c \
               ./App/USS/US_SnrDrv/US_SnrDrvMgr_Req.c \
               ./App/USS/US_SnrDrv/US_SnrDrvMgr_Setup.c \
			   ./App/USS/US_SnrDrv/US_SnrDrv_E521_24.c 

SRCS_COMMON    += ./App/USS/US_Control/US_CtrlInterface.c \
               ./App/USS/US_Control/US_CtrlMain.c \
               ./App/USS/US_Control/US_CtrlEnvCheckFsm.c \
               ./App/USS/US_Control/US_CtrlFireSeqSelect.c \
               ./App/USS/US_Control/US_CtrlPlatformSpecifc.c \
			   ./App/USS/US_Control/US_CtrlSnrCfg.c \
               ./App/USS/US_Control/US_CtrlFireSeqData.c \
			   ./App/USS/US_Control/US_CtrlSnrAdjCfg.c

SRCS_COMMON    += ./App/USS/US_ObjDetect/US_ObjDetTriang.c \
               ./App/USS/US_ObjDetect/US_ObjDetData.c \
               ./App/USS/US_ObjDetect/US_ObjDetMain.c \
               ./App/USS/US_ObjDetect/US_ObjDetZone.c \
               ./App/USS/US_ObjDetect/US_ObjDetMinDist.c \
               ./App/USS/US_ObjDetect/US_ObjDetUtility.c \
               ./App/USS/US_ObjDetect/US_ObjDetPointMap.c \
	       ./App/USS/US_ObjDetect/US_ObjDetHeight.c

SRCS_COMMON    += ./App/USS/US_Manager/US_MgrBlockage.c \
               ./App/USS/US_Manager/US_MgrDiagnostic.c \
               ./App/USS/US_Manager/US_MgrEnvCheck.c \
               ./App/USS/US_Manager/US_MgrInterface.c \
               ./App/USS/US_Manager/US_MgrModeControl.c \
               ./App/USS/US_Manager/US_MgrPlatformSpecific.c \
               ./App/USS/US_Manager/US_MgrSensorProc.c \
               ./App/USS/US_Manager/US_MgrFilter.c \
               ./App/USS/US_Manager/US_MgrUtility.c \
               ./App/USS/US_Manager/US_MgrHeightAlgo.c \
               ./App/USS/US_Manager/US_MgrMath.c \
               ./App/USS/US_Manager/US_MgrHeightAlgoDNN.c \
               ./App/USS/US_Manager/US_MgrHeightAlgoRNN.c \
               ./App/USS/US_Manager/US_MgrMain.c \
               ./App/USS/US_Manager/US_MgrDataSim.c 

SRCS_COMMON    += ./App/USS/US_SnrCmd/US_SnrCmdProc.c \
               ./App/USS/US_SnrCmd/US_SnrCmdCallback.c \
               ./App/USS/US_SnrCmd/US_SnrCmdSend.c 

SRCS_COMMON    += ./App/USS/US_Diagnostic/US_Diagnostic.c \
				./App/USS/US_Diagnostic/US_ECUDiagnostic.c 

SRCS_COMMON    += ./App/USS/US_Calibration/US_SnrCfg.c \
                  ./App/USS/US_Calibration/US_SnrCfg_Calibration.c \
                  ./App/USS/US_Calibration/US_SnrCfg_DataArry.c \
                  ./App/USS/US_Calibration/US_SnrCfg_Adj.c 
			   
			   
SRCS_COMMON    += ./App/USS/US_SnrParamAdjust/US_SnrDynAdjust.c 


SRCS_COMMON    += ./App/USS/US_Stub/US_Stub_Input.c \
               ./App/USS/US_Stub/US_Stub_Output.c \
			   ./App/USS/US_InputOutputBuff/US_InputBuffer.c \
			   ./App/USS/US_InputOutputBuff/US_OutputBuffer.c \
			   ./App/USS/US_InputOutputBuff/US_InputOutputBuff_Task.c
			   
			   

SRCS_COMMON    += ./App/USS/Us_Csm/Us_Csm_Conf.c \
               ./App/USS/Us_Csm/Us_Csm.c \
			   ./App/USS/Us_Csm/Us_Csm_Actions.c\
               ./App/USS/Us_Csm/Us_Csm_StateActions.c\
			   ./App/USS/Us_Csm/Us_Csm_Rules.c\
               ./App/USS/Us_Csm/Us_Csm_Stub.c

#OS Task definition files
SRCS_COMMON += Tasks.c ApplicationTasks.c BaseSwTasks.c   
ifeq ($(BUILD_OS_TYPE),freertos)
SRCS_COMMON += cpu_load.c
SRCS_COMMON += j721s2_freertos_mpu_cfg.c
endif

ifeq ($(BUILD_OS_TYPE),safertos)
SRCS_COMMON += j721s2_safertos_mpu_cfg.c
SRCS_COMMON += SafetyTasks.c 
ifeq ($(ENABLE_TIME_MANAGE), yes)
SRCS_COMMON += TimeManagerProxy.c
endif
endif

SRCS_COMMON += Safety_CDD.c
SRCS_COMMON += vim_mainR5.c
SRCS_COMMON += timer_fusa_utils.c
# List all the external ibs required by the application
EXT_LIB_LIST_COMMON += $(csl_init_LIBPATH)/$(SOC)/$(ISA)/$(BUILD_PROFILE_$(CORE))/$(csl_init_LIBNAME).$(LIBEXT)
# List all the external ibs required by the application
EXT_LIB_LIST_COMMON += $(csl_LIBPATH)/$(SOC)/$(ISA)/$(BUILD_PROFILE_$(CORE))/$(csl_LIBNAME).$(LIBEXT)
# Required for sciclient required by UDMA driver
EXT_LIB_LIST_COMMON += $(sciclient_LIBPATH)/$(SOC)/$(CORE)/$(BUILD_PROFILE_$(CORE))/$(sciclient_LIBNAME).$(LIBEXT)
# Required for uart
EXT_LIB_LIST_COMMON += $(uart_LIBPATH)/$(SOC)/$(ISA)/$(BUILD_PROFILE_$(CORE))/$(uart_LIBNAME).$(LIBEXT)
#Board module
EXT_LIB_LIST_COMMON += $(board_LIBPATH)/$(BOARD)/$(ISA)/$(BUILD_PROFILE_$(CORE))/$(board_LIBNAME).$(LIBEXT)

# Required by board
EXT_LIB_LIST_COMMON += $(i2c_LIBPATH)/$(SOC)/$(ISA)/$(BUILD_PROFILE_$(CORE))/$(i2c_LIBNAME).$(LIBEXT)
# Required for IPC
EXT_LIB_LIST_COMMON += $(ipc_LIBPATH)/$(SOC)/$(CORE)/$(BUILD_PROFILE_$(CORE))/$(ipc_LIBNAME).$(LIBEXT)
# Required by GPIO
EXT_LIB_LIST_COMMON += $(gpio_LIBPATH)/$(SOC)/$(CORE)/$(BUILD_PROFILE_$(CORE))/$(gpio_LIBNAME).$(LIBEXT)
# Required by SPI
#EXT_LIB_LIST_COMMON += $(spi_dma_app_LIBPATH)/$(SOC)/$(CORE)/$(BUILD_PROFILE_$(CORE))/$(spi_dma_app_LIBNAME).$(LIBEXT)
EXT_LIB_LIST_COMMON += $(spi_dma_LIBPATH)/$(SOC)/$(ISA)/$(BUILD_PROFILE_$(CORE))/$(spi_dma_LIBNAME).$(LIBEXT)
# Required by UDMA
EXT_LIB_LIST_COMMON += $(udma_LIBPATH)/$(SOC)/$(CORE)/$(BUILD_PROFILE_$(CORE))/$(udma_LIBNAME).$(LIBEXT)

ifeq ($(BUILD_OS_TYPE),freertos)
CFLAGS_OS_DEFINES = -DFREERTOS
INCLUDE_EXTERNAL_INTERFACES += freertos osal_freertos ipc ipc_manager signalmgr errormanager systemstate_manager cpu_load
#OSAL Module
EXT_LIB_LIST_COMMON += $(osal_freertos_LIBPATH)/$(SOC)/$(ISA_EXT)/$(BUILD_PROFILE_$(CORE))/$(osal_freertos_LIBNAME).$(LIBEXT)
#Freertos Module
EXT_LIB_LIST_COMMON += $(freertos_LIBPATH)/$(SOC)/$(CORE)/$(BUILD_PROFILE_$(CORE))/$(freertos_LIBNAME).$(LIBEXT)
COMP_LIST_COMMON    += $(PDK_COMMON_FREERTOS_COMP) osal_freertos ipc ipc_manager signalmgr errormanager apfusion systemstate_manager cpu_load
EXTERNAL_LNKCMD_FILE_LOCAL = $(fisker_hydra_PATH)/mcu2_1/linker_r5_freertos.lds
endif

ifeq ($(BUILD_OS_TYPE),safertos)
CFLAGS_OS_DEFINES = -DSAFERTOS
INCLUDE_EXTERNAL_INTERFACES += safertos osal_safertos ipc ipc_manager signalmgr errormanager systemstate_manager wdgm_magna wdgif_magna wdg_magna
#OSAL Module
EXT_LIB_LIST_COMMON += $(osal_safertos_LIBPATH)/$(SOC)/$(ISA_EXT)/$(BUILD_PROFILE_$(CORE))/$(osal_safertos_LIBNAME).$(LIBEXT)
#Safertos Module
EXT_LIB_LIST_COMMON += $(safertos_LIBPATH)/$(SOC)/$(CORE)/$(BUILD_PROFILE_$(CORE))/$(safertos_LIBNAME).$(LIBEXT)

COMP_LIST_COMMON    += $(PDK_COMMON_SAFERTOS_COMP) osal_safertos ipc ipc_manager signalmgr errormanager apfusion systemstate_manager wdgm_magna wdgif_magna wdg_magna
EXTERNAL_LNKCMD_FILE_LOCAL = $(fisker_hydra_PATH)/mcu2_1/linker_r5_safertos.lds
endif

ifeq ($(ADDRUNTIMESTATS),RT_ENABLE)
INCLUDE_EXTERNAL_INTERFACES += AddRuntimeStats
COMP_LIST_COMMON    += AddRuntimeStats
CFLAGS_OS_DEFINES += -DADDRUNTIMESTATS
endif

ifeq ($(ADDRUNTIMESTATS),RT_ENABLE)
INCLUDE_EXTERNAL_INTERFACES += RunTimeStats
COMP_LIST_COMMON    += RunTimeStats
CFLAGS_OS_DEFINES += -DADDRUNTIMESTATS
endif

#/* DT project don't have Time Manage requirement */
ifeq ($(ENABLE_TIME_MANAGE), yes)
CFLAGS_OS_DEFINES += -DTIME_MANAGER_PROXY
endif

ifeq ($(AUTO_PARK_EN), yes)
COMP_LIST_COMMON    += autopark
CFLAGS_LOCAL_COMMON += -DAUTO_PARK_EN
endif
ifeq ($(ENABLE_THA_SM_VC), yes)
COMP_LIST_COMMON    += tha_sm_vc
CFLAGS_LOCAL_COMMON += -DENABLE_THA_SM_VC
endif
#ifeq ($(ENABLE_OBJECT_FUSION), yes)
#COMP_LIST_COMMON    += RAEB_ObjectFusion
#CFLAGS_LOCAL_COMMON += -DENABLE_OBJECT_FUSION
#endif
ifeq ($(NFCD_EN), yes)
COMP_LIST_COMMON    += nfcd
CFLAGS_LOCAL_COMMON += -DNFCD_EN
endif
ifeq ($(FOD_EN), yes)
COMP_LIST_COMMON    += FOD
CFLAGS_LOCAL_COMMON += -DFOD_EN
endif
ifeq ($(ARBITER_EN), yes)
COMP_LIST_COMMON    += Arbiter
CFLAGS_LOCAL_COMMON += -DARBITER_EN
endif
ifeq ($(ENABLE_TRSC), yes)
COMP_LIST_COMMON    += trsc
CFLAGS_LOCAL_COMMON += -DENABLE_TRSC
endif

CFLAGS_LOCAL_COMMON += $(MCUSW_CFLAGS) $(CFLAGS_OS_DEFINES)
ifeq ($(PERF_STATS_OUT), yes)
CFLAGS_LOCAL_COMMON += -DPERF_STATS_OUT
endif

LNKFLAGS_LOCAL_COMMON = $(MCUSW_LNKFLAGS)

ifeq ($(MCUSW_UART_ENABLE),TRUE)
    CFLAGS_LOCAL_COMMON += -DUART_ENABLED
ifeq ($(UART_PORT),)
    CFLAGS_LOCAL_COMMON += -DUART_WRITE_PORT=1
else
    CFLAGS_LOCAL_COMMON += -DUART_WRITE_PORT=$(UART_PORT)
endif
endif

# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk
