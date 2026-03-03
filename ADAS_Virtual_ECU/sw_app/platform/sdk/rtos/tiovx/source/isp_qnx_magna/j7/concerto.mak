include $(PRELUDE)

ifeq ($(TARGET_CPU), $(filter $(TARGET_CPU), R5F X86 x86_64))

TARGET      := isp_qnx_magna
TARGETTYPE  := library
CSOURCES    :=

# isp_qnx_magna build configuration options
USE_TWEAK := no

ISP_RC_PATH := ..
ISP_RC_PATH_ABS := $(abspath source/isp_qnx_magna)

CSOURCES    += $(ISP_RC_PATH)/src/isp_algo.c
CSOURCES    += $(ISP_RC_PATH)/src/magna_controls.c
CSOURCES    += $(ISP_RC_PATH)/src/isp_awb_wrapper.c
CSOURCES    += $(ISP_RC_PATH)/src/isp_autoexposure.c
CSOURCES    += $(ISP_RC_PATH)/src/isp_aux.c
CSOURCES    += $(ISP_RC_PATH)/src/reg_write_233.c
CSOURCES    += $(ISP_RC_PATH)/src/reg_write_ox3c.c
CSOURCES    += $(ISP_RC_PATH)/src/awb-impl.c
CSOURCES    += $(ISP_RC_PATH)/src/emb_parser.c
CSOURCES    += $(ISP_RC_PATH)/src/isp_process.c
CSOURCES    += $(ISP_RC_PATH)/src/cogent_api.c
CSOURCES    += $(ISP_RC_PATH)/src/parameters_storage.c
CSOURCES    += $(ISP_RC_PATH)/src/config_reader_aux.c
CSOURCES    += $(ISP_RC_PATH)/src/def_cfg_233.c
CSOURCES    += $(ISP_RC_PATH)/src/def_cfg_ox3c.c
CSOURCES    += $(ISP_RC_PATH)/src/profiler.c
CSOURCES    += $(ISP_RC_PATH)/src/tweak_wrapper.c
CSOURCES    += $(ISP_RC_PATH)/src/config_dump.c
CSOURCES    += $(ISP_RC_PATH)/src/crc32c.c

# See configuration options in the beginning of this file
ifeq ($(USE_TWEAK),yes)
  DEFS        += USE_TWEAK
endif


IDIRS       += $(VISION_APPS_PATH)/utils/console_io/include
IDIRS       += $(VISION_APPS_PATH)/../imaging
IDIRS       += $(VISION_APPS_PATH)/../imaging/sensor_drv/include
IDIRS       += $(VISION_APPS_PATH)/utils/iss/include
IDIRS       += $(BIOS_PATH)/packages
IDIRS       += $(XDCTOOLS_PATH)/packages
IDIRS       += $(PDK_PATH)/packages

IDIRS       += $(ISP_RC_PATH_ABS)/public/cogent
IDIRS       += $(ISP_RC_PATH_ABS)/src/cogent
IDIRS       += $(ISP_RC_PATH_ABS)/src/

IDIRS       += $(ME_BOOKSHELF_PATH)/includes
IDIRS       += $(ME_REPO_ROOT)/sw/mcu2_0/safety

# TWEAK_PATH  := $(VISION_APPS_PATH)/utils/cogent_tweaktool
#
# IDIRS       += $(TWEAK_PATH)/tweak-json/include
# IDIRS       += $(TWEAK_PATH)/tweak-wire/include
# IDIRS       += $(TWEAK_PATH)/tweak-pickle/include
# IDIRS       += $(TWEAK_PATH)/tweak-common/include
# IDIRS       += $(TWEAK_PATH)/tweak2lib/include
# IDIRS       += $(TWEAK_PATH)/tweak-metadata/include
# IDIRS       += $(TWEAK_PATH)/tweak-app/include

DEFS        += SOC_J721S2
DEFS        += ISP_SENSOR_OX3C

DEFS        += DEFAULT_LOG_LEVEL=4

ifeq ($(HOST_COMPILER),TIARMCGT)
  CFLAGS      += --display_error_number
  CFLAGS      += --c99

  ifeq ($(PROFILE),release)
    CFLAGS      += --opt_for_speed
  endif

  IDIRS       += $(BIOS_PATH)/packages/ti/posix/ccs

# Workaround for spurious error: argument of type "float32_t (*)[2]" is incompatible with parameter of type "const float32_t (*)[2]"
  CFLAGS      += --diag_remark=145
  CFLAGS      += --diag_remark=169
endif

CFLAGS += -O3


endif

include $(FINALE)
