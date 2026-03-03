.PHONY: all clean

ifeq ($(PSDK_QNX_PATH), )
  $(error PSDK_QNX_PATH not set!)
endif

ifeq ($(PSDK_RTOS_PATH), )
  $(error PSDK_RTOS_PATH not set!)
endif

ifeq ($(PDK_PATH), )
  $(error PDK_PATH not set!)
endif

BUILD_ETHFW ?= 0

# Supported : j721e_evm, j7200_evm, j721s2_evm, j721s2_hyd, j784s4_evm
BOARD ?= j721s2_hyd

# Supported : j721e, j7200, j721s2, j784s4
SOC ?= j721s2

ifeq ($(BUILD_ETHFW),$(filter $(BUILD_ETHFW), 1))
  ifeq ($(ETHFW_PATH), )
    $(error ETHFW_PATH not set!)
  endif
  ifeq ($(SOC),$(filter $(SOC), j721s2))
    $(error ETHFW build not supported for j721s2!)
  endif
endif

SBL_CORE=mcu1_0
MCUSW_PATH=$(PSDK_RTOS_PATH)/mcusw
SBL_REPO_PATH=$(PDK_PATH)/packages/ti/boot/sbl
COMBINED_APPIMAGE_TOOL_PATH=$(SBL_REPO_PATH)/tools/combined_appimage
ETHFW_FIRMWARE_PATH=$(PSDK_QNX_PATH)/ethfw_firmware
ECHO_FIRMWARE_PATH=$(PSDK_QNX_PATH)/echo_firmware
SBL_COMBINED_BOOTFILES_PATH=$(PSDK_QNX_PATH)/sbl_combined_bootfiles
ATF_OPTEE_PATH=$(SBL_COMBINED_BOOTFILES_PATH)/atf_optee_dir
INPUT_IMG_PATH=$(SBL_COMBINED_BOOTFILES_PATH)/input_img
LDS_PATH=$(PSDK_QNX_PATH)/qnx/scripts/sbl
DEV_ID=55

# SoC Specific source files
ifeq ($(SOC),$(filter $(SOC), j721e))
  SCICLIENT_SOCVER = V1
  SOC_TAG = j7
  SOC_CAPS = J721E
  K3_USART=0
  CFG_CONSOLE_UART=0
endif
ifeq ($(SOC),$(filter $(SOC), j7200))
  SCICLIENT_SOCVER = V2
  SOC_TAG = j7200
  SOC_CAPS = J7200
  K3_USART=0
  CFG_CONSOLE_UART=0
endif
ifeq ($(SOC),$(filter $(SOC), j721s2))
  SCICLIENT_SOCVER = V4
  SOC_TAG = j721s2
  SOC_CAPS = J721S2
  K3_USART=0x8
  CFG_CONSOLE_UART=0x8
endif
ifeq ($(SOC),$(filter $(SOC), j784s4))
  SCICLIENT_SOCVER = V6
  SOC_TAG = j784s4
  SOC_CAPS = J784S4
  K3_USART=0x8
  CFG_CONSOLE_UART=0x8
endif

CERT_SCRIPT=$(PDK_PATH)/packages/ti/build/makerules/x509CertificateGen.sh


#OSPI DATA
OSPI_LOCATION_SBL_IMAGE=0
OSPI_LOCATION_SYSFW_BIN=80000
OSPI_LOCATION_APPIMAGE=100000
ifeq ($(SOC),$(filter $(SOC), j721e))
  OSPI_PATTERN=3FE0000
endif
ifeq ($(SOC),$(filter $(SOC), j7200 j721s2 j784s4))
  OSPI_PATTERN=3FC0000
endif

OSPI_PATTERN_FILE=$(PDK_PATH)/packages/ti/board/src/flash/nor/ospi/nor_spi_patterns.bin

#UNIFLASH INFO
UNIFLASH_VERSION=uniflash_7.1.0
UNIFLASH_DIR=${HOME}/ti/$(UNIFLASH_VERSION)
UNIFLASH_COM_PORT=/dev/ttyUSB5
UNIFLASH_SCRIPT=$(UNIFLASH_DIR)/dslite.sh

ifneq ("$(wildcard $(UNIFLASH_SCRIPT))","")
	UNIFLASH_FOUND=yes
else
	UNIFLASH_FOUND=no
endif


all: sbl_bootimage

clean: sbl_bootimage_scrub

sbl_pdk: sbl_pdk_sd sbl_pdk_ospi tifs

sbl_bootimage: sbl_pdk remote_core_firmware sbl_atf_optee sbl_qnx_combined_bootimage

pre_step:
	echo "Board is $(BOARD)"
	echo "SOC is $(SOC)"
	mkdir -p $(SBL_COMBINED_BOOTFILES_PATH)
ifeq ($(BUILD_ETHFW),$(filter $(BUILD_ETHFW), 1))
	mkdir -p $(ETHFW_FIRMWARE_PATH)
else
	mkdir -p $(ECHO_FIRMWARE_PATH)
endif

#################
## SBL
#################
sbl_pdk_sd: pre_step
	$(MAKE) -C $(PDK_PATH)/packages/ti/build sbl_mmcsd_img_hlos DISABLE_RECURSE_DEPS=no BOARD=$(BOARD) CORE=$(SBL_CORE) -s
	mkdir -p $(SBL_COMBINED_BOOTFILES_PATH)
	cp $(PDK_PATH)/packages/ti/boot/sbl/binary/$(BOARD)/mmcsd/bin/sbl_mmcsd_img_hlos_$(SBL_CORE)_release.tiimage $(SBL_COMBINED_BOOTFILES_PATH)/tiboot3.bin

sbl_pdk_ospi: pre_step sbl_pdk_sd
	$(MAKE) -C $(PDK_PATH)/packages/ti/build sbl_ospi_img_hlos DISABLE_RECURSE_DEPS=no BOARD=$(BOARD) CORE=$(SBL_CORE) -s
	mkdir -p $(SBL_COMBINED_BOOTFILES_PATH)
	cp $(PDK_PATH)/packages/ti/boot/sbl/binary/$(BOARD)/ospi/bin/sbl_ospi_img_hlos_$(SBL_CORE)_release.tiimage $(SBL_COMBINED_BOOTFILES_PATH)/tiboot3.bin.ospi.tiimage

#################
## TIFS
#################
tifs: pre_step
	cp $(PDK_PATH)/packages/ti/drv/sciclient/soc/$(SCICLIENT_SOCVER)/tifs.bin $(SBL_COMBINED_BOOTFILES_PATH)/tifs.bin

##############################
## FIRMWARE
##############################
ifeq ($(BUILD_ETHFW),$(filter $(BUILD_ETHFW), 1))
remote_core_firmware: ethfw_image
else
remote_core_firmware: echo_firmware
endif

#################
## ETHFW
#################
ethfw_image: sbl_pdk echo_firmware_mcu1_0
	$(MAKE) -C $(ETHFW_PATH) ethfw_all BUILD_CPU_MCU2_0=yes BUILD_CPU_MCU2_1=yes BUILD_QNX_A72=yes BUILD_APP_TIRTOS=no BUILD_APP_FREERTOS=yes BUILD_SOC_LIST=$(SOC_CAPS) PROFILE=$(PROFILE) -s -j
	mkdir -p $(ETHFW_FIRMWARE_PATH)
	cp $(ETHFW_PATH)/out/$(SOC_CAPS)/R5Ft/FREERTOS/$(PROFILE)/app_remoteswitchcfg_server.xer5f $(ETHFW_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f0_0-fw
	cp $(ETHFW_PATH)/out/$(SOC_CAPS)/R5Ft/FREERTOS/$(PROFILE)/app_remoteswitchcfg_client.xer5f $(ETHFW_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f0_1-fw
	mkdir -p $(INPUT_IMG_PATH)
	cp $(ETHFW_PATH)/out/$(SOC_CAPS)/R5Ft/FREERTOS/$(PROFILE)/app_remoteswitchcfg_server.xer5f $(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f0_0-fw.xer5f
	cp $(ETHFW_PATH)/out/$(SOC_CAPS)/R5Ft/FREERTOS/$(PROFILE)/app_remoteswitchcfg_client.xer5f $(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f0_1-fw.xer5f

##############################
## IPC ECHO TEST FIRMWARE
##############################
ifeq ($(SOC),$(filter $(SOC), j721e))
echo_firmware: sbl_pdk echo_firmware_mcu1_0 echo_firmware_mcu1_1 echo_firmware_mcu2_0 echo_firmware_mcu2_1 echo_firmware_mcu3_0 echo_firmware_mcu3_1 echo_firmware_c66xdsp_1 echo_firmware_c66xdsp_2 echo_firmware_c7x_1
endif
ifeq ($(SOC),$(filter $(SOC), j7200))
echo_firmware: sbl_pdk echo_firmware_mcu1_0 echo_firmware_mcu1_1 echo_firmware_mcu2_0 echo_firmware_mcu2_1
endif
ifeq ($(SOC),$(filter $(SOC), j721s2))
echo_firmware: sbl_pdk echo_firmware_mcu1_0 echo_firmware_mcu1_1 echo_firmware_mcu2_0 echo_firmware_mcu2_1 echo_firmware_mcu3_0 echo_firmware_mcu3_1 echo_firmware_c7x_1 echo_firmware_c7x_2
endif
ifeq ($(SOC),$(filter $(SOC), j784s4))
echo_firmware: sbl_pdk echo_firmware_mcu1_0 echo_firmware_mcu1_1 echo_firmware_mcu2_0 echo_firmware_mcu2_1 echo_firmware_mcu3_0 echo_firmware_mcu3_1 echo_firmware_mcu4_0 echo_firmware_mcu4_1 echo_firmware_c7x_1 echo_firmware_c7x_2 echo_firmware_c7x_3 echo_firmware_c7x_4
endif

echo_firmware_mcu1_0:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_testb_freertos CORE=mcu1_0 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_testb_freertos/bin/$(BOARD)/ipc_qnx_echo_testb_freertos_mcu1_0_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-mcu-r5f0_0-fw
	mkdir -p $(INPUT_IMG_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_testb_freertos/bin/$(BOARD)/ipc_qnx_echo_testb_freertos_mcu1_0_$(PROFILE)_strip.xer5f $(INPUT_IMG_PATH)/$(SOC_TAG)-mcu-r5f0_0-fw.xer5f

echo_firmware_mcu1_1:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=mcu1_1 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu1_1_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-mcu-r5f0_1-fw
	mkdir -p $(INPUT_IMG_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu1_1_$(PROFILE)_strip.xer5f $(INPUT_IMG_PATH)/$(SOC_TAG)-mcu-r5f0_1-fw.xer5f

echo_firmware_mcu2_0:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=mcu2_0 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu2_0_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f0_0-fw
	mkdir -p $(INPUT_IMG_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu2_0_$(PROFILE)_strip.xer5f $(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f0_0-fw.xer5f

echo_firmware_mcu2_1:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=mcu2_1 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu2_1_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f0_1-fw
	mkdir -p $(INPUT_IMG_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu2_1_$(PROFILE)_strip.xer5f $(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f0_1-fw.xer5f

echo_firmware_mcu3_0:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=mcu3_0 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu3_0_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f1_0-fw
	mkdir -p $(INPUT_IMG_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu3_0_$(PROFILE)_strip.xer5f $(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f1_0-fw.xer5f

echo_firmware_mcu3_1:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=mcu3_1 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu3_1_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f1_1-fw
	mkdir -p $(INPUT_IMG_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu3_1_$(PROFILE)_strip.xer5f $(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f1_1-fw.xer5f

echo_firmware_mcu4_0:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=mcu4_0 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu4_0_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f2_0-fw
	mkdir -p $(INPUT_IMG_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu4_0_$(PROFILE)_strip.xer5f $(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f2_1-fw.xer5f

echo_firmware_mcu4_1:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=mcu4_1 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu4_1_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f2_1-fw
	mkdir -p $(INPUT_IMG_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu4_1_$(PROFILE)_strip.xer5f $(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f2_1-fw.xer5f

echo_firmware_c66xdsp_1:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=c66xdsp_1 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c66xdsp_1_$(PROFILE)_strip.xe66 $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c66_0-fw
	mkdir -p $(INPUT_IMG_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c66xdsp_1_$(PROFILE)_strip.xe66 $(INPUT_IMG_PATH)/$(SOC_TAG)-c66_0-fw.xe66


echo_firmware_c66xdsp_2: echo_firmware_c66xdsp_1
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=c66xdsp_2 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c66xdsp_2_$(PROFILE)_strip.xe66 $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c66_1-fw
	mkdir -p $(INPUT_IMG_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c66xdsp_2_$(PROFILE)_strip.xe66 $(INPUT_IMG_PATH)/$(SOC_TAG)-c66_1-fw.xe66


echo_firmware_c7x_1:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=c7x_1 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c7x_1_$(PROFILE)_strip.xe71 $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c71_0-fw
	mkdir -p $(INPUT_IMG_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c7x_1_$(PROFILE)_strip.xe71 $(INPUT_IMG_PATH)/$(SOC_TAG)-c71_0-fw.xe71

echo_firmware_c7x_2: echo_firmware_c7x_1
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=c7x_2 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c7x_2_$(PROFILE)_strip.xe71 $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c71_1-fw
	mkdir -p $(INPUT_IMG_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c7x_2_$(PROFILE)_strip.xe71 $(INPUT_IMG_PATH)/$(SOC_TAG)-c71_1-fw.xe71

echo_firmware_c7x_3: echo_firmware_c7x_2
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=c7x_3 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c7x_3_$(PROFILE)_strip.xe71 $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c71_2-fw
	mkdir -p $(INPUT_IMG_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c7x_3_$(PROFILE)_strip.xe71 $(INPUT_IMG_PATH)/$(SOC_TAG)-c71_2-fw.xe71

echo_firmware_c7x_4: echo_firmware_c7x_3
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=c7x_4 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c7x_4_$(PROFILE)_strip.xe71 $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c71_3-fw
	mkdir -p $(INPUT_IMG_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c7x_4_$(PROFILE)_strip.xe71 $(INPUT_IMG_PATH)/$(SOC_TAG)-c71_3-fw.xe71

#################
## ATF + OPTEE
#################
sbl_atf_optee: sbl_pdk
	# For ATF, setting HANDLE_EA_EL3_FIRST=0 for QNX so that the all runtime exception to be routed to current exception level (or in EL1 if the current exception level is EL0)
	$(MAKE) -C $(PDK_PATH)/../arm-trusted-firmware -s -j32 CROSS_COMPILE=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- PLAT=k3 TARGET_BOARD=generic SPD=opteed HANDLE_EA_EL3_FIRST=0 K3_USART=$(K3_USART)
	$(MAKE) -C $(PDK_PATH)/../ti-optee-os -s -j32 CROSS_COMPILE_core=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- CROSS_COMPILE_ta_arm32=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- CROSS_COMPILE_ta_arm64=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- NOWERROR=1 CFG_TEE_TA_LOG_LEVEL=0 CFG_TEE_CORE_LOG_LEVEL=2 CFG_ARM64_core=y ta-targets=ta_arm64 PLATFORM=k3 PLATFORM_FLAVOR=j7 CFG_CONSOLE_UART=$(CFG_CONSOLE_UART)
	mkdir -p $(ATF_OPTEE_PATH)
	cp $(PDK_PATH)/../arm-trusted-firmware/build/k3/generic/release/bl31.bin $(ATF_OPTEE_PATH)/bl31.bin
	cp $(PDK_PATH)/../ti-optee-os/out/arm-plat-k3/core/tee-pager_v2.bin $(ATF_OPTEE_PATH)/bl32.bin

##############################
## QNX Combined bootapp image
##############################
OUT_DIR=$(SBL_COMBINED_BOOTFILES_PATH)
ATF_IMG=mpu1_0,$(ATF_OPTEE_PATH)/bl31.bin,0x70000000,0x70000000
OPTEE_IMG=load_only,$(ATF_OPTEE_PATH)/bl32.bin,0x90800000,0x90800000
KERNEL_IMG=load_only,$(QNX_BOOT_PATH)/qnx-ifs,0x80080000,0x80080000
DTB_IMG=
SPL_IMG=
ifeq ($(BUILD_ETHFW),$(filter $(BUILD_ETHFW), 1))
  IMG1=mcu1_0,$(INPUT_IMG_PATH)/$(SOC_TAG)-mcu-r5f0_0-fw.xer5f
  IMG2=mcu2_0,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f0_0-fw.xer5f
  IMG3=mcu2_1,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f0_1-fw.xer5f
  IMG4=
  IMG5=
  IMG6=
  IMG7=
  IMG8=
else
  ifeq ($(SOC),$(filter $(SOC), j721e))
    IMG1=mcu1_0,$(INPUT_IMG_PATH)/$(SOC_TAG)-mcu-r5f0_0-fw.xer5f
    IMG2=mcu2_0,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f0_0-fw.xer5f
    IMG3=mcu2_1,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f0_1-fw.xer5f
    IMG4=mcu3_0,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f1_0-fw.xer5f
    IMG5=mcu3_1,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f1_1-fw.xer5f
    IMG6=c66xdsp_1,$(INPUT_IMG_PATH)/$(SOC_TAG)-c66_0-fw.xe66
    IMG7=c66xdsp_2,$(INPUT_IMG_PATH)/$(SOC_TAG)-c66_1-fw.xe66
    IMG8=c7x_1,$(INPUT_IMG_PATH)/$(SOC_TAG)-c71_0-fw.xe71
  endif
  ifeq ($(SOC),$(filter $(SOC), j7200))
    IMG1=mcu1_0,$(INPUT_IMG_PATH)/$(SOC_TAG)-mcu-r5f0_0-fw.xer5f
    IMG2=mcu2_0,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f0_0-fw.xer5f
    IMG3=mcu2_1,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f0_1-fw.xer5f
    IMG4=
    IMG5=
    IMG6=
    IMG7=
    IMG8=
  endif
  ifeq ($(SOC),$(filter $(SOC), j721s2))
    IMG1=mcu1_0,$(INPUT_IMG_PATH)/$(SOC_TAG)-mcu-r5f0_0-fw.xer5f
    IMG2=mcu2_0,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f0_0-fw.xer5f
    IMG3=mcu2_1,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f0_1-fw.xer5f
    IMG4=mcu3_0,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f1_0-fw.xer5f
    IMG5=mcu3_1,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f1_1-fw.xer5f
    IMG6=c7x_1,$(INPUT_IMG_PATH)/$(SOC_TAG)-c71_0-fw.xe71
    IMG7=c7x_2,$(INPUT_IMG_PATH)/$(SOC_TAG)-c71_1-fw.xe71
    IMG8=
  endif
  ifeq ($(SOC),$(filter $(SOC), j784s4))
    IMG1=mcu1_0,$(INPUT_IMG_PATH)/$(SOC_TAG)-mcu-r5f0_0-fw.xer5f
    IMG2=mcu2_0,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f0_0-fw.xer5f
    IMG3=mcu2_1,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f0_1-fw.xer5f
    IMG4=mcu3_0,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f1_0-fw.xer5f
    IMG5=mcu3_1,$(INPUT_IMG_PATH)/$(SOC_TAG)-main-r5f1_1-fw.xer5f
    IMG6=c7x_1,$(INPUT_IMG_PATH)/$(SOC_TAG)-c71_0-fw.xe71
    IMG7=c7x_2,$(INPUT_IMG_PATH)/$(SOC_TAG)-c71_1-fw.xe71
    IMG8=c7x_2,$(INPUT_IMG_PATH)/$(SOC_TAG)-c71_2-fw.xe71
  endif
endif

sbl_qnx_combined_bootimage: sbl_atf_optee remote_core_firmware
	echo "---------------------------"
	echo "start"
	echo "---------------------------"
	$(MAKE) -C $(COMBINED_APPIMAGE_TOOL_PATH) PDK_INSTALL_PATH=$(PDK_PATH)/packages OUT_DIR=$(OUT_DIR) ATF_IMG=$(ATF_IMG) OPTEE_IMG=$(OPTEE_IMG) KERNEL_IMG=$(KERNEL_IMG) DTB_IMG=$(DTB_IMG) SPL_IMG=$(SPL_IMG) IMG1=$(IMG1) IMG2=$(IMG2) IMG3=$(IMG3) IMG4=$(IMG4) IMG5=$(IMG5) IMG6=$(IMG6) IMG7=$(IMG7) IMG8=$(IMG8)
	cp $(OUT_DIR)/combined.appimage $(OUT_DIR)/app
	echo "---------------------------"
	echo "done"
	echo "---------------------------"


#################
## CLEAN UPS
#################
sbl_atf_optee_scrub:
	$(MAKE) -C $(PDK_PATH)/../arm-trusted-firmware clean
	$(MAKE) -C $(PDK_PATH)/../ti-optee-os clean CFG_ARM64_core=y PLATFORM=k3 PLATFORM_FLAVOR=j7
	rm -rf $(PDK_PATH)/../arm-trusted-firmware/build/k3
	rm -rf $(PDK_PATH)/../ti-optee-os/out/arm-plat-k3

sbl_bootimage_scrub: sbl_atf_optee_scrub
	$(MAKE) -C $(PDK_PATH)/packages/ti/build    clean BOARD=$(BOARD) SOC=$(SOC) PROFILE=$(PROFILE) -s
	rm -rf $(PDK_PATH)/packages/ti/binary/*
	rm -rf $(PDK_PATH)/packages/ti/boot/sbl/binary
	rm -rf $(MCUSW_PATH)/binary
	rm -rf $(SBL_COMBINED_BOOTFILES_PATH)
ifeq ($(BUILD_ETHFW),$(filter $(BUILD_ETHFW), 1))
	$(MAKE) -C $(ETHFW_PATH) ethfw_all_clean BUILD_CPU_MCU2_0=yes BUILD_CPU_MCU2_1=yes BUILD_SOC_LIST=$(SOC_CAPS) PROFILE=$(PROFILE) -s -j
	rm -rf $(ETHFW_FIRMWARE_PATH)
else
	rm -rf $(ECHO_FIRMWARE_PATH)
endif


#################
## OSPI FLASHING
#################
sbl_combined_bootimage_install_ospi:
ifeq ($(UNIFLASH_FOUND), yes)
	$(UNIFLASH_SCRIPT) --mode processors -c $(UNIFLASH_COM_PORT) -f $(UNIFLASH_DIR)/processors/FlashWriter/$(BOARD)/uart_$(SOC)_evm_flash_programmer_release.tiimage -i 0 || true
else
	echo "Uniflash not found! Please install uniflash or update the uniflash path in makefile"
endif
ifeq ($(UNIFLASH_FOUND), yes)
	#SBL Image
	$(UNIFLASH_SCRIPT) --mode processors -c $(UNIFLASH_COM_PORT) -f $(SBL_COMBINED_BOOTFILES_PATH)/tiboot3.bin.ospi.tiimage -d 3 -o $(OSPI_LOCATION_SBL_IMAGE) || true
	echo "*************************"
	echo "SBL flashed"
	echo "*************************"
	#OSPI Patten file
	$(UNIFLASH_SCRIPT) --mode processors -c $(UNIFLASH_COM_PORT) -f $(OSPI_PATTERN_FILE) -d 3 -o $(OSPI_PATTERN) || true
	echo "*************************"
	echo "OSPI Patten flashed"
	echo "*************************"
	#SYSFW BIN
	$(UNIFLASH_SCRIPT) --mode processors -c $(UNIFLASH_COM_PORT) -f $(SBL_COMBINED_BOOTFILES_PATH)/tifs.bin -d 3 -o $(OSPI_LOCATION_SYSFW_BIN) || true
	echo "*************************"
	echo "SYSFW BIN flashed"
	echo "*************************"
	#Combined_bootimage
	$(UNIFLASH_SCRIPT) --mode processors -c $(UNIFLASH_COM_PORT) -f $(SBL_COMBINED_BOOTFILES_PATH)/combined.appimage -d 3 -o $(OSPI_LOCATION_APPIMAGE) || true
	echo "*************************"
	echo "Boot App flashed"
	echo "*************************"
else
	echo "Uniflash not found! Please install uniflash or update the uniflash path in makefile"
endif

