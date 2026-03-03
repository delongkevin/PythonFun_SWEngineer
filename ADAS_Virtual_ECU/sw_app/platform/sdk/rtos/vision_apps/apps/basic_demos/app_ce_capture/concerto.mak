ifeq ($(TARGET_CPU), $(filter $(TARGET_CPU), A72))

include $(PRELUDE)

TARGET      := vx_app_ce_capture

CSOURCES    := main.c app_sensor_module.c app_capture_module.c

SYS_SHARED_LIBS += png z

ifeq ($(TARGET_CPU),x86_64)

TARGETTYPE  := exe

CSOURCES    += main_x86.c

include $(VISION_APPS_PATH)/apps/concerto_x86_64_inc.mak

STATIC_LIBS += $(IMAGING_LIBS)
STATIC_LIBS += vx_kernels_img_proc
STATIC_LIBS += vx_kernels_fileio
STATIC_LIBS += vx_target_kernels_fileio

endif

ifeq ($(TARGET_CPU),A72)
ifeq ($(TARGET_OS), $(filter $(TARGET_OS), LINUX QNX))

TARGETTYPE  := exe

CSOURCES    += main_linux_arm.c

include $(VISION_APPS_PATH)/apps/concerto_a72_inc.mak

STATIC_LIBS += $(IMAGING_LIBS)
STATIC_LIBS += vx_kernels_img_proc
STATIC_LIBS += vx_kernels_fileio
STATIC_LIBS += vx_target_kernels_fileio

endif
endif

IDIRS += $(IMAGING_IDIRS)
IDIRS += $(VISION_APPS_PATH)/kernels/img_proc/include
IDIRS += $(VISION_APPS_PATH)/kernels/fileio/include

include $(FINALE)

endif
