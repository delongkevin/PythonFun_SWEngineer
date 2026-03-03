ifeq ($(TARGET_CPU), $(filter $(TARGET_CPU), A72))

include $(PRELUDE)

TARGET      := vx_app_ce_single_cam

CSOURCES    := app_single_cam_main.c

SYS_SHARED_LIBS += png z

ifeq ($(TARGET_CPU),x86_64)

TARGETTYPE  := exe

CSOURCES    += main_x86.c

include $(VISION_APPS_PATH)/apps/concerto_x86_64_inc.mak

STATIC_LIBS += $(IMAGING_LIBS)

endif

ifeq ($(TARGET_CPU),A72)
ifeq ($(TARGET_OS), $(filter $(TARGET_OS), LINUX QNX))

TARGETTYPE  := exe

CSOURCES    += main_linux_arm.c

include $(VISION_APPS_PATH)/apps/concerto_a72_inc.mak

STATIC_LIBS += $(IMAGING_LIBS)

endif
endif

ifeq ($(TARGET_CPU),A72)
ifeq ($(TARGET_OS),SYSBIOS)

TARGETTYPE  := library

include $(VISION_APPS_PATH)/apps/concerto_a72_inc.mak

endif
endif

IDIRS += $(IMAGING_IDIRS)



include $(FINALE)

endif
