ifeq ($(TARGET_PLATFORM),J721S2)
ifeq ($(TARGET_OS), $(filter $(TARGET_OS), SAFERTOS FREERTOS))
ifeq ($(TARGET_CPU),R5F)

include $(PRELUDE)
TARGET      := AddRuntimeStats
TARGETTYPE  := library

CSOURCES    := src/AddRuntimeStats.c 

IDIRS       := $(ME_BOOKSHELF_PATH)/includes
IDIRS	    += $(ME_BOOKSHELF_PATH)/PerformanceStats/AddRuntimeStats/inc
IDIRS 		+= $(ME_REPO_ROOT)/sw/mcu2_0/os
IDIRS		+= $(ME_BOOKSHELF_PATH)/main_domain/console_io/include

DEFS += BUILD_MCU2_0
DEFS += ADDRUNTIMESTATS

include $(FINALE)

endif
endif
endif
