ifeq ($(TARGET_CPU),A72)
ifeq ($(TARGET_OS), $(filter $(TARGET_OS), LINUX))

include $(PRELUDE)

TARGETTYPE  := exe
TARGET      := edt_server
CSOURCES    := $(call all-c-files)

IDIRS += $(PDK_QNX_PATH)/packages/ti/drv/ipc/
IDIRS += $(PDK_QNX_PATH)/packages/

DEFS+=SOC_J7
DEFS+=SOC_J721E

include $(VISION_APPS_PATH)/apps/concerto_a72_inc.mak

include $(FINALE)

endif
endif

