ifeq ($(TARGET_PLATFORM),J721S2)
ifeq ($(TARGET_OS), $(filter $(TARGET_OS), FREERTOS SAFERTOS))
ifeq ($(TARGET_CPU),R5F)


include $(PRELUDE)
TARGET      := wdgm_magna
TARGETTYPE  := library


CSOURCES    := src/WdgM.c 
CSOURCES    += cfg/MCU2_0/WdgM_Cfg.c

IDIRS       := $(ME_BOOKSHELF_PATH)/includes 
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/Common
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/WdgM_Magna/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/WdgM_Magna/cfg
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/WdgM_Magna/cfg/MCU2_0
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/WdgIf_Magna/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/WdgIf_Magna/cfg
IDIRS       += ${ME_REPO_ROOT}/sw/platform/asr/app_sip/Common/Implementation
IDIRS       += ${ME_REPO_ROOT}/sw/platform/asr/app_sip/GenData/mcu1_0

SAFERTOS_PATH = $(ME_SDK_INSTALL_PATH)/SafeRTOS_TI_CR5_Clang_TDA4VL_DAP_v9.4.1_SAFECheckpoints/source_code_and_projects/SafeRTOS
IDIRS += $(SAFERTOS_PATH)/api/199_TI_CR5
IDIRS += $(SAFERTOS_PATH)/config
IDIRS += $(SAFERTOS_PATH)/kernel/include_api
IDIRS += $(SAFERTOS_PATH)/portable/199_TI_CR5
IDIRS += $(SAFERTOS_PATH)/portable/199_TI_CR5/024_Clang
IDIRS += $(SAFERTOS_PATH)/api/PrivWrapperStd
IDIRS += $(SAFERTOS_PATH)/checkpoints

DEFS += BUILD_MCU2_0

include $(FINALE)

endif
endif
endif
