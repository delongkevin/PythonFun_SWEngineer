ifeq ($(TARGET_PLATFORM),J721S2)
ifeq ($(TARGET_OS), $(filter $(TARGET_OS), FREERTOS SAFERTOS))
ifeq ($(TARGET_CPU),R5F)


include $(PRELUDE)
TARGET      := errormanager
TARGETTYPE  := library

CSOURCES    := gen/ErrorManagerAggDef.c gen/ErrorManagerAggregatorDef_B.c gen/ErrorManagerAggregatorDef_QM.c gen/ErrorManagerCallbacks_QM.c
CSOURCES    += gen/ErrorManagerDef.c gen/ErrorManagerSatDef.c gen/ErrorManagerSatelliteDef_B.c gen/ErrorManagerSatelliteDef_QM.c gen/ErrorManagerCallbacks_B.c
CSOURCES    += src/ErrorManagerAggregator.c src/ErrorManagerAggregatorApp.c src/ErrorManagerSatellite.c src/ErrorManagerSatelliteApp.c


IDIRS       := $(ME_BOOKSHELF_PATH)/includes
IDIRS       += $(ME_BOOKSHELF_PATH)/ErrorManager/inc $(ME_BOOKSHELF_PATH)/ErrorManager/cfg $(ME_BOOKSHELF_PATH)/ErrorManager/gen
IDIRS       += $(ME_BOOKSHELF_PATH)/SignalMgr/inc $(ME_BOOKSHELF_PATH)/SignalMgr/cfg $(ME_BOOKSHELF_PATH)/SignalMgr/gen
IDIRS       += $(ME_BOOKSHELF_PATH)/SSM/inc $(ME_BOOKSHELF_PATH)/SSM/cfg
IDIRS       += $(ME_BOOKSHELF_PATH)/CalDataProvider/inc
IDIRS   	+= $(ME_BOOKSHELF_PATH)/magna_apps/trsc/algo/_sharedutils
IDIRS   	+= $(ME_BOOKSHELF_PATH)/magna_apps/trsc/code
IDIRS   	+= $(ME_BOOKSHELF_PATH)/magna_apps/trsc
IDIRS   	+= $(ME_BOOKSHELF_PATH)/magna_apps/common_includes
IDIRS   	+= $(ME_BOOKSHELF_PATH)/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw
IDIRS 		+= $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/_sharedutils
IDIRS 		+= $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/common/inc
IDIRS   	+= $(ME_BOOKSHELF_PATH)/magna_apps/tha_sm_vc/algo/_sharedutils
IDIRS   	+= $(ME_BOOKSHELF_PATH)/magna_apps/tha_sm_vc/algo/common
IDIRS   	+= $(ME_BOOKSHELF_PATH)/magna_apps/KM/code
IDIRS 		+= $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA
IDIRS 		+= $(ME_BOOKSHELF_PATH)/magna_apps/Arbiter/FeatureArbiter_ert_rtw/_sharedutils
IDIRS   	+= $(ME_BOOKSHELF_PATH)/../mcu2_1/App/USS/US_Includes
IDIRS		+= $(ME_BOOKSHELF_PATH)/WdgFw/Wdg/inc
IDIRS		+= $(ME_BOOKSHELF_PATH)/ipc_manager/inc

DEFS += BUILD_MCU2_0

include $(FINALE)

endif
endif
endif
