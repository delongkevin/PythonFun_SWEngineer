include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = FUSA

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

SRCDIR += ./fusa_app
SRCDIR += ./esm
SRCDIR += ./ecc
SRCDIR += ./vtm
SRCDIR += ./bist
SRCDIR += ./bist/pbist
SRCDIR += ./bist/lbist
SRCDIR += ./bist/soc/j721s2
SRCDIR += ./pok
SRCDIR += ./ccm
SRCDIR += ./dcc
SRCDIR += ./tog
SRCDIR += ./vim
SRCDIR += ./magna/GPIO_Safety
SRCDIR += ./magna/MSMC_Safety
SRCDIR += ./magna/adc
SRCDIR += ./magna/reset
SRCDIR += ./magna/mmr_safety
SRCDIR += ./magna/DDR
SRCDIR += ./magna/CBASS
SRCDIR += ./magna/timers

INCDIR += ./fusa_app
INCDIR += ./vtm
INCDIR += ./esm
INCDIR += ./ecc
INCDIR += ./bist
INCDIR += ./bist/pbist
INCDIR += ./bist/lbist
INCDIR += ./bist/soc/j721s2
INCDIR += ./pok
INCDIR += ./ccm
INCDIR += ./dcc
INCDIR += ./tog
INCDIR += ./vim
INCDIR += ./magna/DDR
INCDIR += ./magna/MSMC_Safety
INCDIR += ./magna/CBASS
INCDIR += ./magna/adc
INCDIR += ./magna/GPIO_Safety
INCDIR += ./magna/reset
INCDIR += ./magna/mmr_safety
INCDIR += ./magna/timers

INCDIR += ./../../platform/inc
INCDIR += ./../includes
INCDIR += ./../ErrorManager/inc
INCDIR += ./../ErrorManager/gen
INCDIR += ./../ErrorManager/cfg
INCDIR += ./../../common/pmic
INCDIR += $(PSDK_INSTALL_PATH)/pdk_j721s2_08_05_00_36/packages/ti/drv/pmic/include

INCDIR += $(PDK_SDL_COMP_PATH)/
INCDIR += $(PDK_SDL_COMP_PATH)/osal/
INCDIR += $(PDK_SDL_COMP_PATH)/src/sdl
INCDIR += $(PDK_SDL_COMP_PATH)/src/ip
INCDIR += $(PDK_SDL_COMP_PATH)/include
INCDIR += $(PDK_SDL_COMP_PATH)/include/soc/$(SOC)
INCDIR += $(PDK_SDL_COMP_PATH)/test/r5f_startup
INCDIR += $(PDK_SDL_COMP_PATH)/src/ip/r5
INCDIR += $(PSDK_INSTALL_PATH)/tidl_j721s2_08_05_00_16/common
INCDIR += $(PSDK_INSTALL_PATH)/mcusw/mcal_drv/mcal
INCDIR += $(PSDK_INSTALL_PATH)/pdk_j721s2_08_05_00_36/packages/
INCDIR += $(PSDK_INSTALL_PATH)/pdk_j721s2_08_05_00_36/packages/ti/csl/example/ecc/ecc_test_app
INCDIR += $(PSDK_INSTALL_PATH)/pdk_j721s2_08_05_00_36/packages/ti/drv/sciclient/src/rm_pm_hal/include
INCDIR += $(PSDK_INSTALL_PATH)/pdk_j721s2_08_05_00_36/packages/ti/drv/sciclient/src/priv
INCDIR += ./../../mcu1_0/app/MeOsprofiling
INCDIR += ./../../mcu1_0/app/boot

SRCS_COMMON += esm.c
SRCS_COMMON += ecc.c
SRCS_COMMON += ecc_trigger.c
SRCS_COMMON += vtm.c
SRCS_COMMON += fusa_application.c
SRCS_COMMON += fusa_osal_interface_autosar.c
SRCS_COMMON += lbist_utils.c
SRCS_COMMON += pbist_utils.c
SRCS_COMMON += power_seq.c
SRCS_COMMON += armv8_power_utils.c
SRCS_COMMON += bist_core_defs.c
SRCS_COMMON += lbist_defs.c
SRCS_COMMON += pbist_defs.c
SRCS_COMMON += bist.c
SRCS_COMMON += pok.c
SRCS_COMMON += pok_example.c
SRCS_COMMON += ccm.c
SRCS_COMMON += dcc.c
SRCS_COMMON += sdl_dcc_funcTest.c
SRCS_COMMON += tog_main.c tog_usecase.c
SRCS_COMMON += vim.c

SRCS_ASM_COMMON += tog_test_utils.asm
SRCS_COMMON += GPIO_Safety.c
SRCS_COMMON += adc_safety.c
SRCS_COMMON += reset_safety.c
SRCS_COMMON += mmr_safety.c
SRCS_COMMON += MSMC_Safety.c
SRCS_COMMON += CBASS_safety.c
SRCS_COMMON += timer_fusa.c
#safety DDR
SRCS_COMMON += DDR_safety.c
#ECC DDR
SRCS_COMMON += ecc_ddr.c

INCLUDE_EXTERNAL_INTERFACES = pdk

#include RTE Depenencies
ifeq ($(CORE),$(filter $(CORE), mcu1_0))
INCLUDE_INTERNAL_INTERFACES += gendata os bswm nvm
endif

#Default App Log Levels
APP_LOG_LEVEL ?= 1
#Default App Log Levels
PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON = $(MCUSW_CFLAGS) -DSOC_J721S2 -DBIST_BOOT_APP -DAPP_LOG_LEVEL=$(APP_LOG_LEVEL) #-DBIST_ERRMGR_LOG

# Core/SoC/platform specific source files and CFLAGS
# Example:
#   SRCS_<core/SoC/platform-name> =
#   CFLAGS_LOCAL_<core/SoC/platform-name> =

include $(MAKERULEDIR)/common.mk

# OBJs and libraries are built by using rule defined in rules_<target>.mk
#     and need not be explicitly specified here

# Nothing beyond this point