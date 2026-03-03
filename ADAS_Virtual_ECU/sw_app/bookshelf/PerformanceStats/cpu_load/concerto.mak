ifeq ($(TARGET_PLATFORM),J721S2)
ifeq ($(TARGET_OS), $(filter $(TARGET_OS), FREERTOS))
ifeq ($(TARGET_CPU),R5F)


include $(PRELUDE)
TARGET      := cpu_load
TARGETTYPE  := library


CSOURCES    := src/cpu_load.c 

IDIRS       += $(ME_BOOKSHELF_PATH)/includes
IDIRS	    += $(ME_BOOKSHELF_PATH)/PerformanceStats/cpu_load/inc 

DEFS += BUILD_MCU2_0
# Uncomment this label for printing CPU load on UART
# DEFS += LOG_CPU_LOAD_MCU2_0

include $(FINALE)

endif
endif
endif
