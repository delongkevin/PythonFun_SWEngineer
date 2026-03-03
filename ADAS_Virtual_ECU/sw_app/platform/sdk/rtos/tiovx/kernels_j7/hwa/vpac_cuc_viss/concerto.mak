
ifeq ($(TARGET_CPU), $(filter $(TARGET_CPU), X86 x86_64 R5F))

include $(PRELUDE)
TARGET      := vx_target_kernels_vpac_cuc_isp
TARGETTYPE  := library
CSOURCES    := vx_kernels_hwa_target.c

ifeq ($(TARGET_CPU),R5F)
  CSOURCES    += vx_vpac_cuc_rc_target.c vx_vpac_cuc_common.c
  CSOURCES    += vx_vpac_cuc_viss_target.c vx_vpac_cuc_viss_target_driver.c
  CSOURCES    += common_sensor_api.c
  CSOURCES    += processing.c
  CSOURCES    += def_cfg_ox3c.c def_cfg_233.c
else
  CSOURCES    += vx_vpac_cuc_viss_target_sim.c vx_vpac_cuc_viss_target_sim_priv.c
  IDIRS       += $(J7_C_MODELS_PATH)/include
  DEFS        += __aarch64__
endif

DEFS        += ISP_SENSOR_OX3C
#DEFS        += ISP_SENSOR_AR233
IDIRS       += $(PDK_PATH)/packages
IDIRS       += $(VISION_APPS_PATH)/
IDIRS       += $(XDCTOOLS_PATH)/packages
IDIRS       += $(BIOS_PATH)/packages
DEFS        += SOC_J721S2

IDIRS       += $(CUSTOM_KERNEL_PATH)/hwa/include
IDIRS       += $(HOST_ROOT)/kernels/include
IDIRS       += $(VXLIB_PATH)/packages
IDIRS       += $(HOST_ROOT)/sensor_drv/include
IDIRS       += $(IMAGING_PATH)/sensor_drv/include

IDIRS       += $(VISION_APPS_PATH)/utils/remote_service/include
IDIRS       += $(VISION_APPS_PATH)/utils/ipc/include
IDIRS       += $(ME_REPO_ROOT)/sw/mcu2_0/safety

STATIC_LIBS += isp_qnx_magna

IDIRS       += $(HOST_ROOT)/source/isp_qnx_magna/public/cogent/

ifeq ($(TARGET_CPU)$(BUILD_VLAB),R5F)
DEFS += VLAB_HWA
endif

ifeq ($(HOST_COMPILER),GCC_LINUX)
CFLAGS += -Wno-unused-result
endif

include $(FINALE)

endif
