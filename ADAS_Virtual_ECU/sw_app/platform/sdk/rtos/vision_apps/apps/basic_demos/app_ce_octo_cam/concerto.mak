ifeq ($(TARGET_CPU), $(filter $(TARGET_CPU), A72))

include $(PRELUDE)

TARGET      := vx_app_ce_octo_cam

CSOURCES    := main.c app_sensor_module.c app_capture_module.c
CSOURCES    += app_viss_module.c app_img_mosaic_module.c app_display_module.c app_csitx_module.c

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

# SYS_SHARED_LIBS += screen
TARGETTYPE  := exe

CSOURCES    += main_linux_arm.c

include $(VISION_APPS_PATH)/apps/concerto_a72_inc.mak

STATIC_LIBS += $(IMAGING_LIBS)
# STATIC_LIBS += vx_kernels_img_proc
STATIC_LIBS += vx_kernels_fileio
STATIC_LIBS += vx_target_kernels_fileio
STATIC_LIBS += vx_kernels_sample
STATIC_LIBS += vx_target_kernels_sample_a72

STATIC_LIBS += $(VISION_APPS_KERNELS_LIBS)

endif
endif

SYS_SHARED_LIBS += EGL
SYS_SHARED_LIBS += GLESv2
ifeq ($(TARGET_OS), LINUX)
SYS_SHARED_LIBS += gbm
endif
ifeq ($(TARGET_OS), QNX)
SYS_SHARED_LIBS += screen
endif

# IDIRS += $(VISION_APPS_SRV_IDIRS)

STATIC_LIBS += $(VISION_APPS_SRV_LIBS)

IDIRS += $(IMAGING_IDIRS)
IDIRS += $(VISION_APPS_PATH)/kernels/img_proc/include
IDIRS += $(VISION_APPS_PATH)/kernels/fileio/include
IDIRS += $(VISION_APPS_PATH)/kernels/sample/include
IDIRS += $(VISION_APPS_PATH)/kernels/sample

include $(FINALE)

endif
