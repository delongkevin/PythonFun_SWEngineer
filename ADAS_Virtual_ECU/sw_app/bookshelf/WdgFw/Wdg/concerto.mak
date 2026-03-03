ifeq ($(TARGET_PLATFORM),J721S2)
ifeq ($(TARGET_OS), $(filter $(TARGET_OS), FREERTOS SAFERTOS))
ifeq ($(TARGET_CPU),R5F)


include $(PRELUDE)
TARGET      := wdg_magna
TARGETTYPE  := library


CSOURCES    := src/Wdg.c

IDIRS       := $(ME_BOOKSHELF_PATH)/includes
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/WdgM_Magna/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/WdgM_Magna/cfg
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/WdgM_Magna/cfg/MCU2_0
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/Common
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/WdgIf_Magna/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/Wdg/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/Wdg/cfg
IDIRS       += $(ME_BOOKSHELF_PATH)/SignalMgr/gen
IDIRS       += $(ME_BOOKSHELF_PATH)/SignalMgr/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/ErrorManager/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/ErrorManager/gen
IDIRS       += $(ME_BOOKSHELF_PATH)/ErrorManager/cfg
IDIRS       += $(ME_BOOKSHELF_PATH)/CalDataProvider/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/SSM/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/SSM/cfg
IDIRS       += ${ME_REPO_ROOT}/sw/platform/asr/app_sip/Common/Implementation
IDIRS       += ${ME_REPO_ROOT}/sw/platform/asr/app_sip/GenData/mcu1_0
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/_sharedutils
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/common/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/Arbiter/FeatureArbiter_ert_rtw/_sharedutils
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/tha_sm_vc/algo/_sharedutils
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/tha_sm_vc/algo/common
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/KM/code
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/common_includes
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/algo/_sharedutils
IDIRS       += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw
IDIRS       += $(ME_BOOKSHELF_PATH)/CalDataProvider/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/SSM/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/SSM/cfg
IDIRS       += ${ME_REPO_ROOT}/sw/mcu2_1/App/USS/US_Includes

DEFS += BUILD_MCU2_0

include $(FINALE)

endif
endif
endif
