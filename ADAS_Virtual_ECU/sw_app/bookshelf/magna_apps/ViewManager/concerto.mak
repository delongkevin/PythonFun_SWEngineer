ifeq ($(BUILD_APP_RTOS_QNX),yes)
ifeq ($(BUILD_CPU_MCU2_0),yes)
ifeq ($(TARGET_CPU),R5F)

include $(PRELUDE)
TARGET      := ViewManager
TARGETTYPE  := library
CSOURCES    := algo/src/aHmiM.c algo/src/aHmiM_STM.c algo/src/aHmiM_STM_Cfg.c algo/src/aHmiM_STM_Functions.c algo/src/aHmiM_STM_Functions.c algo/src/External_Dependency.c algo/src/aHmiM_STM_RadioDisp.c
CPPSOURCES  += code/DataProviderHMI.cpp code/HMI.cpp code/JobHMI.cpp

IDIRS       := $(ME_BOOKSHELF_PATH)/magna_apps/ViewManager/code
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/ViewManager/algo/inc
IDIRS	    += $(ME_BOOKSHELF_PATH)/SignalMgr/gen 
IDIRS	    += $(ME_BOOKSHELF_PATH)/SignalMgr/inc 
IDIRS	    += $(ME_BOOKSHELF_PATH)/SignalMgr/cfg
IDIRS	    += $(ME_BOOKSHELF_PATH)/includes
IDIRS       += $(ME_BOOKSHELF_PATH)/SSM/gen 
IDIRS	    += $(ME_BOOKSHELF_PATH)/SSM/inc
IDIRS	    += $(ME_BOOKSHELF_PATH)/ErrorManager/inc $(ME_BOOKSHELF_PATH)/ErrorManager/cfg  $(ME_BOOKSHELF_PATH)/ErrorManager/gen 
IDIRS       += $(ME_BOOKSHELF_PATH)/CalDataProvider/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/common_includes
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/algo/_sharedutils
IDIRS       += $(fisker_hydra_PATH)/bookshelf/magna_apps/tha_sm_vc/algo/inc $(fisker_hydra_PATH)/bookshelf/includes
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/_sharedutils $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/common/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/algo/TRSC_InputAdapter
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/algo/TRSC_OutputAdapter
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/algo/TRSC_SM_VC
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/algo/TRSC_SM_VC_Int
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/algo/TRSC_StateMachine
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/algo/TRSC_VC
IDIRS       += $(ME_BOOKSHELF_PATH)/includes
IDIRS       += $(ME_BOOKSHELF_PATH)/SSM/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/SignalMgr/inc $(ME_BOOKSHELF_PATH)/SignalMgr/cfg $(ME_BOOKSHELF_PATH)/SignalMgr/gen
IDIRS       += $(ME_BOOKSHELF_PATH)/SSM/inc $(ME_BOOKSHELF_PATH)/SSM/cfg
IDIRS       += $(ME_BOOKSHELF_PATH)/CalDataProvider/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/ipc_manager/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/tha_sm_vc/algo/_sharedutils
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/tha_sm_vc/algo/common
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/KM/code
IDIRS 	    += $(ME_BOOKSHELF_PATH)/../mcu2_1/App/USS/US_Includes
IDIRS       += ${ME_REPO_ROOT}/sw/platform/sdk/rtos/tiovx/source/isp_qnx_magna/public/cogent
IDIRS       += ${ME_REPO_ROOT}/sw/mcu2_0/App
IDIRS 	    += $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA
IDIRS 	    += $(ME_BOOKSHELF_PATH)/magna_apps/Arbiter/FeatureArbiter_ert_rtw/_sharedutils
IDIRS   	+= $(ME_BOOKSHELF_PATH)/WdgFw/Wdg/inc

#STATIC_LIBS += VISION_APPS_UTILS_LIBS 

DEFS += BUILD_MCU2_0

include $(FINALE)

endif
endif
endif
