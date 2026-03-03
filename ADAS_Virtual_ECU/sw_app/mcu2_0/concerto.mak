ifeq ($(BUILD_APP_RTOS_LINUX),yes)
ifeq ($(BUILD_CPU_MCU2_0),yes)
ifeq ($(TARGET_CPU),R5F)

# OS_ID must be set before include $(PRELUDE)
OS_ID=linux

_MODULE=$(OS_ID)
include $(PRELUDE)

DEFS+=BUILD_MCU2_0
ifeq ($(ADDRUNTIMESTATS),RT_ENABLE)
DEFS+=ADDRUNTIMESTATS
endif

TARGET      := hydra3_rtos_linux_mcu2_0
TARGETTYPE  := exe
CSOURCES    := os/main.c
CSOURCES    += os/ApplicationTasks.c
CSOURCES    += os/BaseSwTasks.c
CSOURCES    += App/cam_testpattern.c
CSOURCES    += diagnostics/diagnostics.c
CSOURCES    += Safety_CDD/Safety_CDD.c
CSOURCES    += ../bookshelf/FuSa/vim/vim_mainR5.c
CSOURCES    += ../bookshelf/FuSa/magna/timers/timer_fusa_utils.c

include $($(_MODULE)_SDIR)/concerto_mcu2_0_inc.mak
IDIRS	+= $($(_MODULE)_SDIR)/Safety_CDD
IDIRS   += $(VISION_APPS_PATH)/platform/$(SOC)/rtos/common_linux
IDIRS   += $(ME_BOOKSHELF_PATH)/includes
IDIRS   += $(ME_BOOKSHELF_PATH)/SSM/inc $(ME_BOOKSHELF_PATH)/SSM/cfg
IDIRS   += $(ME_BOOKSHELF_PATH)/SignalMgr/inc $(ME_BOOKSHELF_PATH)/SignalMgr/cfg
IDIRS   += $(ME_BOOKSHELF_PATH)/ErrorManager/inc $(ME_BOOKSHELF_PATH)/ErrorManager/cfg $(ME_BOOKSHELF_PATH)/ErrorManager/gen
IDIRS   += $(ME_BOOKSHELF_PATH)/ipc_manager/inc $(ME_BOOKSHELF_PATH)/ipc_manager/cfg
IDIRS   += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/algo/_sharedutils
IDIRS   += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/code
IDIRS 	+= $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/_sharedutils
IDIRS	+= $(ME_BOOKSHELF_PATH)/PerformanceStats/AddRuntimeStats/inc
IDIRS	+= $(ME_BOOKSHELF_PATH)/PerformanceStats/RunTimeStats/inc
IDIRS  	+= ${ME_REPO_ROOT}/sw/mcu2_0/os
IDIRS 	+= $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/common/inc
IDIRS 	+= $(ME_BOOKSHELF_PATH)/FuSa/vim
IDIRS 	+= $(ME_BOOKSHELF_PATH)/FuSa/magna/timers
IDIRS 	+= $(ME_BOOKSHELF_PATH)/main_domain/console_io/include
IDIRS   += ${ME_REPO_ROOT}/sw/platform/sdk/rtos/vision_apps/apps/edt_server

IDIRS   += $(ME_BOOKSHELF_PATH)/magna_apps/ViewManager/inc $(ME_BOOKSHELF_PATH)/magna_apps/ViewManager/code
#IDIRS   += $(ME_BOOKSHELF_PATH)/magna_apps/ViewManager/inc
IDIRS   += $(ME_BOOKSHELF_PATH)/magna_apps/tha_sm_vc/algo/_sharedutils
IDIRS   += $(ME_BOOKSHELF_PATH)/magna_apps/tha_sm_vc/algo/common

STATIC_LIBS += app_rtos_linux
STATIC_LIBS += errormanager
STATIC_LIBS += systemstate_manager
STATIC_LIBS += ipc_manager
STATIC_LIBS += signalmanager
STATIC_LIBS += ViewManager
STATIC_LIBS += wdg_magna
STATIC_LIBS += wdgif_magna
STATIC_LIBS += wdgm_magna
ifeq ($(ADDRUNTIMESTATS),RT_ENABLE)
STATIC_LIBS += AddRuntimeStats
endif

ifeq ($(ADDRUNTIMESTATS),RT_ENABLE)
STATIC_LIBS += RunTimeStats
endif
include $(FINALE)

endif
endif
endif

ifeq ($(BUILD_APP_RTOS_QNX),yes)
ifeq ($(BUILD_CPU_MCU2_0),yes)
ifeq ($(TARGET_CPU),R5F)

# OS_ID must be set before include $(PRELUDE)
OS_ID=qnx

_MODULE=$(OS_ID)
include $(PRELUDE)

DEFS+=BUILD_MCU2_0
ifeq ($(ADDRUNTIMESTATS),RT_ENABLE)
DEFS+=ADDRUNTIMESTATS
endif

TARGET      := hydra3_rtos_qnx_mcu2_0
TARGETTYPE  := exe
CSOURCES    := os/main.c
CSOURCES    += os/ApplicationTasks.c
CSOURCES    += os/BaseSwTasks.c
CSOURCES    += App/cam_testpattern.c
CSOURCES    += diagnostics/diagnostics.c
CSOURCES    += safety/safety.c
CSOURCES    += Safety_CDD/Safety_CDD.c
CSOURCES    += ../bookshelf/FuSa/vim/vim_mainR5.c
CSOURCES    += ../bookshelf/FuSa/magna/timers/timer_fusa_utils.c

include $($(_MODULE)_SDIR)/concerto_mcu2_0_inc.mak

IDIRS   += $(VISION_APPS_PATH)/platform/$(SOC)/rtos/common_qnx
IDIRS   += $(ME_BOOKSHELF_PATH)/includes
IDIRS   += $(ME_BOOKSHELF_PATH)/SSM/inc $(ME_BOOKSHELF_PATH)/SSM/cfg
IDIRS   += $(ME_BOOKSHELF_PATH)/SignalMgr/inc $(ME_BOOKSHELF_PATH)/SignalMgr/cfg $(ME_BOOKSHELF_PATH)/SignalMgr/gen
IDIRS   += $(ME_BOOKSHELF_PATH)/CalDataProvider/inc
IDIRS   += $(ME_BOOKSHELF_PATH)/ErrorManager/inc $(ME_BOOKSHELF_PATH)/ErrorManager/cfg $(ME_BOOKSHELF_PATH)/ErrorManager/gen
IDIRS   += $(ME_BOOKSHELF_PATH)/ipc_manager/inc $(ME_BOOKSHELF_PATH)/ipc_manager/cfg
IDIRS   += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/code
IDIRS   += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/algo/_sharedutils
IDIRS   += $(autopark_INCLUDE)

IDIRS	+= $(ME_BOOKSHELF_PATH)/PerformanceStats/AddRuntimeStats/inc
IDIRS	+= $(ME_BOOKSHELF_PATH)/PerformanceStats/RunTimeStats/inc
IDIRS  	+= ${ME_REPO_ROOT}/sw/mcu2_0/os
IDIRS	+= $($(_MODULE)_SDIR)/diagnostics
IDIRS	+= $($(_MODULE)_SDIR)/safety
IDIRS   += ${ME_REPO_ROOT}/sw/mcu2_0/App
IDIRS   += $(ME_SDK_INSTALL_PATH)/vision_apps/utils/iss/include
IDIRS   += $(ME_SDK_INSTALL_PATH)/imaging/sensor_drv/include
IDIRS   += $(ME_SDK_INSTALL_PATH)/imaging/sensor_drv/src
IDIRS   += $(HOST_ROOT)/sensor_drv/include
IDIRS	+= $($(_MODULE)_SDIR)/Safety_CDD
IDIRS   += ${ME_REPO_ROOT}/sw/platform/sdk/rtos/tiovx/source/isp_qnx_magna/public/cogent
IDIRS   += ${ME_REPO_ROOT}/sw/mcu1_0/app/SWC_VCANMgr/
IDIRS   += $(ME_BOOKSHELF_PATH)/magna_apps/ViewManager/inc $(ME_BOOKSHELF_PATH)/magna_apps/ViewManager/code
#IDIRS   += $(ME_BOOKSHELF_PATH)/magna_apps/ViewManager/inc
IDIRS 	+= $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/_sharedutils
IDIRS 	+= $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/common/inc
IDIRS 	+= $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA	
IDIRS   += $(ME_BOOKSHELF_PATH)/magna_apps/tha_sm_vc/algo/_sharedutils
IDIRS   += $(ME_BOOKSHELF_PATH)/magna_apps/common_includes
IDIRS   += $(ME_BOOKSHELF_PATH)/magna_apps/tha_sm_vc/algo/common
IDIRS   += $(ME_BOOKSHELF_PATH)/../mcu2_1/App/USS/US_Includes
IDIRS   += ${ME_REPO_ROOT}/sw/platform/sdk/rtos/vision_apps/apps/edt_server
IDIRS   += $(ME_BOOKSHELF_PATH)/PerformanceStats/cpu_load/inc

IDIRS   += $(ME_BOOKSHELF_PATH)/WdgFw/Common
IDIRS   += $(ME_BOOKSHELF_PATH)/WdgFw/Wdg/inc
IDIRS   += $(ME_BOOKSHELF_PATH)/WdgFw/WdgM_Magna/inc
IDIRS   += $(ME_BOOKSHELF_PATH)/WdgFw/Common
IDIRS   += $(ME_BOOKSHELF_PATH)/WdgFw/WdgM_Magna/inc
IDIRS   += $(ME_BOOKSHELF_PATH)/WdgFw/WdgM_Magna/cfg
IDIRS   += $(ME_BOOKSHELF_PATH)/WdgFw/WdgM_Magna/cfg/MCU2_0
IDIRS   += $(ME_BOOKSHELF_PATH)/WdgFw/WdgIf_Magna/inc
IDIRS   += $(ME_BOOKSHELF_PATH)/WdgFw/WdgIf_Magna/cfg

IDIRS   += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw
IDIRS   += $(ME_BOOKSHELF_PATH)/magna_apps/KM/code
IDIRS 	+= $(ME_BOOKSHELF_PATH)/FuSa/vim
IDIRS 	+= $(ME_BOOKSHELF_PATH)/FuSa/magna/timers
IDIRS 	+= $(ME_BOOKSHELF_PATH)/main_domain/console_io/include

SAFERTOS_PATH = $(ME_SDK_INSTALL_PATH)/SafeRTOS_TI_CR5_Clang_TDA4VL_DAP_v9.4.1_SAFECheckpoints/source_code_and_projects/SafeRTOS
IDIRS += $(SAFERTOS_PATH)/api/199_TI_CR5
IDIRS += $(SAFERTOS_PATH)/config
IDIRS += $(SAFERTOS_PATH)/kernel/include_api
IDIRS += $(SAFERTOS_PATH)/portable/199_TI_CR5
IDIRS += $(SAFERTOS_PATH)/portable/199_TI_CR5/024_Clang
IDIRS += $(SAFERTOS_PATH)/api/PrivWrapperStd
IDIRS += $(SAFERTOS_PATH)/checkpoints

STATIC_LIBS += app_rtos_qnx
STATIC_LIBS += errormanager
STATIC_LIBS += systemstate_manager
STATIC_LIBS += ipc_manager
STATIC_LIBS += signalmanager
STATIC_LIBS += ViewManager
STATIC_LIBS += wdg_magna
STATIC_LIBS += wdgif_magna
STATIC_LIBS += wdgm_magna

ifeq ($(ADDRUNTIMESTATS),RT_ENABLE)
STATIC_LIBS += AddRuntimeStats
endif
ifeq ($(ADDRUNTIMESTATS),RT_ENABLE)
STATIC_LIBS += RunTimeStats
endif
ifeq ($(RTOS),FREERTOS)
STATIC_LIBS += cpu_load
endif

include $(FINALE)

endif
endif
endif
