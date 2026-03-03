ifeq ($(TARGET_CPU), $(filter $(TARGET_CPU), A72 R5F))

include $(PRELUDE)
TARGET      := ti_imaging_sensordrv
TARGETTYPE  := library
CSOURCES    := $(call all-c-files)

CSOURCES    += imagers/ar0233.c
CSOURCES    += imagers/ar0233_60fps.c
CSOURCES    += imagers/dummy.c
CSOURCES    += imagers/ox03c10.c imagers/ox03c10_crc16.c imagers/ox03c10_otp_crc.c

IDIRS       += $(ME_REPO_ROOT)/sw/mcu2_0/safety
IDIRS       += $(HOST_ROOT)/sensor_drv/include
IDIRS       += $(HOST_ROOT)/
IDIRS       += $(VISION_APPS_PATH)/utils/remote_service/include
IDIRS       += $(VISION_APPS_PATH)/utils/ipc/include
IDIRS       += $(VISION_APPS_PATH)/utils/iss/include
IDIRS       += $(PDK_PATH)/packages
IDIRS       += $(ME_BOOKSHELF_PATH)/includes
IDIRS       += $(ME_BOOKSHELF_PATH)/ErrorManager/inc $(ME_BOOKSHELF_PATH)/ErrorManager/cfg $(ME_BOOKSHELF_PATH)/ErrorManager/gen

ifeq ($(SOC), am62a)
SKIPBUILD=1
endif

ifeq ($(BUILD_PDK_BOARD), j721s2_hyd)
DEFS+=j721s2_hyd
endif

ifeq ($(TARGET_CPU), R5F)
IDIRS   	+= $(ME_BOOKSHELF_PATH)/SignalMgr/inc 
IDIRS   	+= $(ME_BOOKSHELF_PATH)/SignalMgr/cfg 
IDIRS   	+= $(ME_BOOKSHELF_PATH)/SignalMgr/gen
DEFS+=BUILD_MCU2_0
endif

include $(FINALE)

endif
