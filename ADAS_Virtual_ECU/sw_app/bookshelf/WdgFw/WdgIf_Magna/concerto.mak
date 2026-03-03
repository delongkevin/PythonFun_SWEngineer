ifeq ($(TARGET_PLATFORM),J721S2)
ifeq ($(TARGET_OS), $(filter $(TARGET_OS), FREERTOS SAFERTOS))
ifeq ($(TARGET_CPU),R5F)


include $(PRELUDE)
TARGET      := wdgif_magna
TARGETTYPE  := library


CSOURCES    := src/WdgIf.c

IDIRS       := $(ME_BOOKSHELF_PATH)/includes 
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/Common
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/WdgIf_Magna/inc
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/WdgIf_Magna/cfg
IDIRS       += $(ME_BOOKSHELF_PATH)/WdgFw/Wdg/inc
IDIRS       += ${ME_REPO_ROOT}/sw/platform/asr/app_sip/Common/Implementation
IDIRS       += ${ME_REPO_ROOT}/sw/platform/asr/app_sip/GenData/mcu1_0

DEFS += BUILD_MCU2_0

include $(FINALE)

endif
endif
endif
