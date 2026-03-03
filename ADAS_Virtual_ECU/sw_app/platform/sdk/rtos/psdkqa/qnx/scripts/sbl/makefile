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

ifeq ($(SOC), $(filter $(SOC), am62x))
BOARD_TYPE ?= sk
ifeq ($(BOARD_TYPE),$(filter $(BOARD_TYPE), sk-lp))
	MCU_BOARD_TYPE = am62x-sk-lp
else
	MCU_BOARD_TYPE = am62x-sk
endif
endif

ifeq ($(SOC), $(filter $(SOC), am62a))
BOARD_TYPE ?= sk
MCU_BOARD_TYPE = am62ax-sk
endif


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

# Build profile for EthFW build
ifeq ($(PROFILE), $(filter $(PROFILE), release all))
  BUILD_PROFILE=release
endif
ifeq ($(PROFILE),debug)
  BUILD_PROFILE=debug
endif

# Supported : pdk, mcusw
BOOTAPP ?= pdk

# With or without OP-TEE (1 or 0)
USE_OPTEE ?= 0

SBL_CORE=mcu1_0
MCUSW_PATH=$(PSDK_RTOS_PATH)/mcusw
SBL_REPO_PATH=$(PDK_PATH)/packages/ti/boot/sbl
MULTICORE_APPIMAGE_GEN_TOOL_PATH=$(SBL_REPO_PATH)/tools/multicoreImageGen/bin
SBL_OUT2RPRC_GEN_TOOL_PATH=$(SBL_REPO_PATH)/tools/out2rprc/bin
ETHFW_FIRMWARE_PATH=$(PSDK_QNX_PATH)/ethfw_firmware
ECHO_FIRMWARE_PATH=$(PSDK_QNX_PATH)/echo_firmware
SBL_BOOTFILES_PATH?=$(PSDK_QNX_PATH)/sbl_bootfiles
SBL_ETHFW_BOOTFILES_PATH=$(PSDK_QNX_PATH)/sbl_ethfw_bootfiles
SBL_ECHO_BOOTFILES_PATH=$(PSDK_QNX_PATH)/sbl_echo_bootfiles
SBL_ETHFW_BOOTFILES_HS_PATH=$(PSDK_QNX_PATH)/sbl_ethfw_bootfiles_hs
SBL_ECHO_BOOTFILES_HS_PATH=$(PSDK_QNX_PATH)/sbl_echo_bootfiles_hs
ATF_OPTEE_PATH=$(SBL_BOOTFILES_PATH)/atf_optee_dir
LDS_PATH=$(PSDK_QNX_PATH)/qnx/scripts/sbl
DEV_ID=55

#OSPI DATA
OSPI_LOCATION_SBL_IMAGE=0
OSPI_LOCATION_SYSFW_BIN=80000
OSPI_LOCATION_BOOT_APP=100000
OSPI_LOCATION_MULTI_CORE_IMAGE_1=1FC0000
OSPI_LOCATION_MULTI_CORE_IMAGE_2=27C0000
OSPI_LOCATION_ATF_IMAGE=1C0000
OSPI_LOCATION_LINUX_DTB=1EC0000
OSPI_LOCATION_HLOS_KERNEL_IMAGE=7C0000
ifeq ($(SOC),$(filter $(SOC), j721e))
  OSPI_PATTERN=3FE0000
endif
ifeq ($(SOC),$(filter $(SOC), j7200 j721s2 j784s4))
  OSPI_PATTERN=3FC0000
endif
OSPI_PATTERN_FILE=$(PDK_PATH)/packages/ti/board/src/flash/nor/ospi/nor_spi_patterns.bin

#UNIFLASH INFO
ifeq ($(SOC),$(filter $(SOC), am62x am62a))
UNIFLASH_DIR= $(MCU_PLUS_PATH)/tools/boot
UNIFLASH_COM_PORT= /dev/ttyUSB0
UNIFLASH_SCRIPT= uart_uniflash.py
UART_BOOTLOADER_SCRIPT= uart_bootloader.py
else
UNIFLASH_VERSION=uniflash_7.1.0
UNIFLASH_DIR=${HOME}/ti/$(UNIFLASH_VERSION)
UNIFLASH_COM_PORT=/dev/ttyUSB5
UNIFLASH_SCRIPT=$(UNIFLASH_DIR)/dslite.sh
endif

ifneq ("$(wildcard $(UNIFLASH_SCRIPT))","")
  UNIFLASH_FOUND=yes
else
  UNIFLASH_FOUND=no
endif

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
ifeq ($(SOC),$(filter $(SOC), am62x))
  SOC_TAG = am62x
  SOC_CAPS = AM62X
  K3_USART=0x8
  CFG_CONSOLE_UART=0x8
  DM_APP_NAME = sciserver_freertos_for_qnx.release.xer5f
  DM_APPIMAGE_NAME =sciserver_freertos_for_qnx.release.appimage
endif
ifeq ($(SOC),$(filter $(SOC), am62a))
  SOC_TAG = am62a
  SOC_CAPS = AM62A
  K3_USART=0x8
  CFG_CONSOLE_UART=0x8
  DM_APP_NAME = sciserver_freertos_for_qnx.release.xer5f
  DM_APPIMAGE_NAME =sciserver_freertos_for_qnx.release.appimage
endif

REMOTE_CORE_LIST_LATEAPP1=
REMOTE_CORE_LIST_LATEAPP1+=10 $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f0_0-fw.rprc
REMOTE_CORE_LIST_LATEAPP1+=11 $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f0_1-fw.rprc

REMOTE_CORE_LIST_LATEAPP2=
REMOTE_CORE_LIST_LATEAPP2=12 $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f1_0-fw.rprc
REMOTE_CORE_LIST_LATEAPP2+=13 $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f1_1-fw.rprc
ifeq ($(SOC),$(filter $(SOC), j721e))
  REMOTE_CORE_LIST_LATEAPP2+=16 $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c66_0-fw.rprc
  REMOTE_CORE_LIST_LATEAPP2+=17 $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c66_1-fw.rprc
  REMOTE_CORE_LIST_LATEAPP2+=18 $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c71_0-fw.rprc
endif
ifeq ($(SOC),$(filter $(SOC), j721s2))
  REMOTE_CORE_LIST_LATEAPP2+=18 $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c71_0-fw.rprc
  REMOTE_CORE_LIST_LATEAPP2+=19 $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c71_1-fw.rprc
endif
ifeq ($(SOC),$(filter $(SOC), j784s4))
  REMOTE_CORE_LIST_LATEAPP2+=14 $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f2_0-fw.rprc
  REMOTE_CORE_LIST_LATEAPP2+=15 $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f2_1-fw.rprc
  REMOTE_CORE_LIST_LATEAPP2+=18 $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c71_0-fw.rprc
  REMOTE_CORE_LIST_LATEAPP2+=19 $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c71_1-fw.rprc
  REMOTE_CORE_LIST_LATEAPP2+=20 $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c71_2-fw.rprc
  REMOTE_CORE_LIST_LATEAPP2+=21 $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c71_3-fw.rprc
endif
CERT_SCRIPT=$(PDK_PATH)/packages/ti/build/makerules/x509CertificateGen.sh

all: sbl_bootimage

clean: sbl_bootimage_scrub

ifeq ($(SOC),$(filter $(SOC), am62x am62a))
sbl_bootimage: sbl a53_appimages
else
ifeq ($(BOOTAPP),$(filter $(BOOTAPP), pdk))
bootapp: pdk_bootapp
bootapp_hs: pdk_bootapp_hs
endif
ifeq ($(BOOTAPP),$(filter $(BOOTAPP), mcusw))
bootapp: mcusw_bootapp
bootapp_hs: mcusw_bootapp_hs
endif
sbl_bootimage: sbl tifs bootapp lateapps a72_appimages
endif

ifeq ($(BUILD_ETHFW),$(filter $(BUILD_ETHFW), 1))
	mkdir -p $(SBL_ETHFW_BOOTFILES_PATH)
	cp $(SBL_BOOTFILES_PATH)/app $(SBL_ETHFW_BOOTFILES_PATH)
	cp $(SBL_BOOTFILES_PATH)/*.appimage $(SBL_ETHFW_BOOTFILES_PATH)
	cp $(SBL_BOOTFILES_PATH)/lateapp* $(SBL_ETHFW_BOOTFILES_PATH)
	cp $(SBL_BOOTFILES_PATH)/tiboot3.bin $(SBL_ETHFW_BOOTFILES_PATH)
	cp $(SBL_BOOTFILES_PATH)/tifs.bin $(SBL_ETHFW_BOOTFILES_PATH)
else ifneq ($(SOC),$(filter $(SOC), am62x am62a))
	mkdir -p $(SBL_ECHO_BOOTFILES_PATH)
	cp $(SBL_BOOTFILES_PATH)/app $(SBL_ECHO_BOOTFILES_PATH)
	cp $(SBL_BOOTFILES_PATH)/*.appimage $(SBL_ECHO_BOOTFILES_PATH)
	cp $(SBL_BOOTFILES_PATH)/lateapp* $(SBL_ECHO_BOOTFILES_PATH)
	cp $(SBL_BOOTFILES_PATH)/tiboot3.bin $(SBL_ECHO_BOOTFILES_PATH)
	cp $(SBL_BOOTFILES_PATH)/tifs.bin $(SBL_ECHO_BOOTFILES_PATH)
endif

sbl_bootimage_hs: sbl_hs tifs_hs bootapp_hs lateapps_hs a72_appimages_hs
ifeq ($(BUILD_ETHFW),$(filter $(BUILD_ETHFW), 1))
	mkdir -p $(SBL_ETHFW_BOOTFILES_HS_PATH)
	cp $(SBL_BOOTFILES_PATH)/hs_signed/* $(SBL_ETHFW_BOOTFILES_HS_PATH)
else
	mkdir -p $(SBL_ECHO_BOOTFILES_HS_PATH)
	cp $(SBL_BOOTFILES_PATH)/hs_signed/* $(SBL_ECHO_BOOTFILES_HS_PATH)
endif

pre_step:
	echo "Board is $(BOARD)"
	echo "SOC is $(SOC)"
	mkdir -p $(SBL_BOOTFILES_PATH)
ifeq ($(BUILD_ETHFW),$(filter $(BUILD_ETHFW), 1))
	mkdir -p $(ETHFW_FIRMWARE_PATH)
else
	mkdir -p $(ECHO_FIRMWARE_PATH)
endif

#################
## SBL
#################
ifeq ($(SOC),$(filter $(SOC), am62x am62a))
sbl: 
	$(MAKE) -C $(MCU_PLUS_PATH) all DEVICE=$(SOC_MCU_PLUS) -sj 
else
sbl: sbl_sd sbl_ospi
endif

sbl_hs: sbl_sd_hs sbl_ospi_hs

sbl_sd: pre_step
	$(MAKE) -C $(PDK_PATH)/packages/ti/build sbl_mmcsd_img DISABLE_RECURSE_DEPS=no BOARD=$(BOARD) CORE=$(SBL_CORE) -s
	mkdir -p $(SBL_BOOTFILES_PATH)
	cp $(PDK_PATH)/packages/ti/boot/sbl/binary/$(BOARD)/mmcsd/bin/sbl_mmcsd_img_$(SBL_CORE)_release.tiimage $(SBL_BOOTFILES_PATH)/tiboot3.bin

sbl_sd_hs: sbl_sd
	$(MAKE) -C $(PDK_PATH)/packages/ti/build sbl_mmcsd_img_hs DISABLE_RECURSE_DEPS=no BOARD=$(BOARD) CORE=$(SBL_CORE) -s
	mkdir -p $(SBL_BOOTFILES_PATH)/hs_signed
	cp $(PDK_PATH)/packages/ti/boot/sbl/binary/$(BOARD)_hs/mmcsd/bin/sbl_mmcsd_img_$(SBL_CORE)_release.tiimage $(SBL_BOOTFILES_PATH)/hs_signed/tiboot3.bin

sbl_ospi: pre_step sbl_sd
	$(MAKE) -C $(PDK_PATH)/packages/ti/build sbl_cust_img DISABLE_RECURSE_DEPS=no BOARD=$(BOARD) CORE=$(SBL_CORE) -s
	mkdir -p $(SBL_BOOTFILES_PATH)
	cp $(PDK_PATH)/packages/ti/boot/sbl/binary/$(BOARD)/cust/bin/sbl_cust_img_$(SBL_CORE)_release.tiimage $(SBL_BOOTFILES_PATH)/tiboot3.bin.ospi.tiimage

sbl_ospi_hs: sbl_ospi
	$(MAKE) -C $(PDK_PATH)/packages/ti/build sbl_cust_img_hs DISABLE_RECURSE_DEPS=no BOARD=$(BOARD) CORE=$(SBL_CORE) -s
	mkdir -p $(SBL_BOOTFILES_PATH)/hs_signed
	cp $(PDK_PATH)/packages/ti/boot/sbl/binary/$(BOARD)_hs/cust/bin/sbl_cust_img_$(SBL_CORE)_release.tiimage $(SBL_BOOTFILES_PATH)/hs_signed/tiboot3.bin.ospi.tiimage


#################
# TIFS
#################
tifs:
	mkdir -p $(SBL_BOOTFILES_PATH)
	cp $(PDK_PATH)/packages/ti/drv/sciclient/soc/$(SCICLIENT_SOCVER)/tifs.bin $(SBL_BOOTFILES_PATH)/tifs.bin

tifs_hs: tifs
ifeq ($(SOC),$(filter $(SOC), j721e))
	mkdir -p $(SBL_BOOTFILES_PATH)
	mkdir -p $(SBL_BOOTFILES_PATH)/hs_signed
	cp $(PDK_PATH)/packages/ti/drv/sciclient/soc/$(SCICLIENT_SOCVER)/tifs_sr1.1-hs-enc.bin $(SBL_BOOTFILES_PATH)/hs_signed/tifs.bin.sr1.1
	cp $(PDK_PATH)/packages/ti/drv/sciclient/soc/$(SCICLIENT_SOCVER)/tifs-hs-enc.bin $(SBL_BOOTFILES_PATH)/hs_signed/tifs.bin.sr1.0
endif
ifeq ($(SOC),$(filter $(SOC), j7200))
	mkdir -p $(SBL_BOOTFILES_PATH)
	mkdir -p $(SBL_BOOTFILES_PATH)/hs_signed
	cp $(PDK_PATH)/packages/ti/drv/sciclient/soc/$(SCICLIENT_SOCVER)/tifs-hs-enc.bin $(SBL_BOOTFILES_PATH)/hs_signed/tifs.bin.sr1.0
	cp $(PDK_PATH)/packages/ti/drv/sciclient/soc/$(SCICLIENT_SOCVER)/tifs_sr2-hs-enc.bin $(SBL_BOOTFILES_PATH)/hs_signed/tifs.bin.sr2.0
endif
ifeq ($(SOC),$(filter $(SOC),  j721s2 j784s4))
	mkdir -p $(SBL_BOOTFILES_PATH)/hs_signed
	cp $(PDK_PATH)/packages/ti/drv/sciclient/soc/$(SCICLIENT_SOCVER)/tifs-hs-enc.bin $(SBL_BOOTFILES_PATH)/hs_signed/tifs.bin
endif

#################
## MCU BootApp
#################
mcusw_bootapp: mcusw_bootapp_sd mcusw_bootapp_ospi

mcusw_bootapp_hs: mcusw_bootapp_sd_hs mcusw_bootapp_ospi_hs

sbl_mcusw_bootimage_touch:
	touch $(MCUSW_PATH)/mcuss_demos/boot_app_mcu_rtos/boot.c
	touch $(MCUSW_PATH)/mcuss_demos/boot_app_mcu_rtos/main_tirtos.c
	touch $(MCUSW_PATH)/mcuss_demos/boot_app_mcu_rtos/soc/$(SOC)/boot_core_defs.c

mcusw_bootapp_sd: sbl
	$(MAKE) sbl_mcusw_bootimage_touch
	$(MAKE) -C $(MCUSW_PATH)/build can_boot_app_mcu_rtos -s HLOSBOOT=qnx BOOTMODE=mmcsd BOARD=$(BOARD) CORE=$(SBL_CORE) BUILD_OS_TYPE=freertos CANFUNC=none
	mkdir -p $(SBL_BOOTFILES_PATH)
	cp $(MCUSW_PATH)/binary/can_boot_app_mcu_rtos/bin/$(BOARD)/can_boot_app_mcu_rtos_$(SBL_CORE)_release.appimage $(SBL_BOOTFILES_PATH)/app

mcusw_bootapp_sd_hs: mcusw_bootapp_sd
	mkdir -p $(SBL_BOOTFILES_PATH)/hs_signed
	cp -f $(SBL_BOOTFILES_PATH)/app $(SBL_BOOTFILES_PATH)/app.save
	$(CERT_SCRIPT)  -b $(SBL_BOOTFILES_PATH)/app -o $(SBL_BOOTFILES_PATH)/hs_signed/app -c R5 -l 0x0 -k $(PDK_PATH)/packages/ti/build/makerules/k3_dev_mpk.pem
	mv -f $(SBL_BOOTFILES_PATH)/app.save $(SBL_BOOTFILES_PATH)/app

mcusw_bootapp_ospi: sbl mcusw_bootapp_sd
	$(MAKE) sbl_mcusw_bootimage_touch
	$(MAKE) -C $(MCUSW_PATH)/build can_boot_app_mcu_rtos -s HLOSBOOT=qnx BOOTMODE=ospi BOARD=$(BOARD) CORE=$(SBL_CORE) BUILD_OS_TYPE=freertos CANFUNC=none
	mkdir -p $(SBL_BOOTFILES_PATH)
	cp $(MCUSW_PATH)/binary/can_boot_app_mcu_rtos/bin/$(BOARD)/can_boot_app_mcu_rtos_$(SBL_CORE)_release.appimage $(SBL_BOOTFILES_PATH)/app_ospi

mcusw_bootapp_ospi_hs: mcusw_bootapp_ospi
	mkdir -p $(SBL_BOOTFILES_PATH)/hs_signed
	cp -f $(SBL_BOOTFILES_PATH)/app_ospi $(SBL_BOOTFILES_PATH)/app_ospi.save
	$(CERT_SCRIPT)  -b $(SBL_BOOTFILES_PATH)/app_ospi -o $(SBL_BOOTFILES_PATH)/hs_signed/app_ospi -c R5 -l 0x0 -k $(PDK_PATH)/packages/ti/build/makerules/k3_dev_mpk.pem
	mv -f $(SBL_BOOTFILES_PATH)/app_ospi.save $(SBL_BOOTFILES_PATH)/app_ospi

#################
## PDK BootApp
#################
pdk_bootapp: pdk_bootapp_sd pdk_bootapp_ospi

pdk_bootapp_hs: pdk_bootapp_sd_hs pdk_bootapp_ospi_hs

pdk_bootapp_sd: sbl
	$(MAKE) -C $(PDK_PATH)/packages/ti/build boot_app_mmcsd_qnx -s BOARD=$(BOARD) CORE=$(SBL_CORE) DISABLE_RECURSE_DEPS=no
	mkdir -p $(SBL_BOOTFILES_PATH)
	cp $(PDK_PATH)/packages/ti/boot/sbl/example/boot_app/binary/$(BOARD)/mmcsd/sbl_boot_app_mmcsd_qnx_$(BOARD)_$(SBL_CORE)_freertos_TestApp_release.appimage $(SBL_BOOTFILES_PATH)/app

pdk_bootapp_sd_hs: pdk_bootapp_sd
	$(MAKE) -C $(PDK_PATH)/packages/ti/build boot_app_mmcsd_qnx_hs -s BOARD=$(BOARD) CORE=$(SBL_CORE) DISABLE_RECURSE_DEPS=no
	mkdir -p $(SBL_BOOTFILES_PATH)/hs_signed
	cp $(PDK_PATH)/packages/ti/boot/sbl/example/boot_app/binary/$(BOARD)_hs/mmcsd/sbl_boot_app_mmcsd_qnx_hs_$(BOARD)_$(SBL_CORE)_freertos_TestApp_release.appimage.signed $(SBL_BOOTFILES_PATH)/hs_signed/app

pdk_bootapp_ospi: sbl pdk_bootapp_sd
	$(MAKE) -C $(PDK_PATH)/packages/ti/build boot_app_ospi_qnx -s BOARD=$(BOARD) CORE=$(SBL_CORE) DISABLE_RECURSE_DEPS=no
	mkdir -p $(SBL_BOOTFILES_PATH)
	cp $(PDK_PATH)/packages/ti/boot/sbl/example/boot_app/binary/$(BOARD)/ospi/sbl_boot_app_ospi_qnx_$(BOARD)_$(SBL_CORE)_freertos_TestApp_release.appimage $(SBL_BOOTFILES_PATH)/app_ospi

pdk_bootapp_ospi_hs: pdk_bootapp_ospi
	$(MAKE) -C $(PDK_PATH)/packages/ti/build boot_app_ospi_qnx_hs -s BOARD=$(BOARD) CORE=$(SBL_CORE) DISABLE_RECURSE_DEPS=no
	mkdir -p $(SBL_BOOTFILES_PATH)/hs_signed
	cp $(PDK_PATH)/packages/ti/boot/sbl/example/boot_app/binary/$(BOARD)_hs/ospi/sbl_boot_app_ospi_qnx_hs_$(BOARD)_$(SBL_CORE)_freertos_TestApp_release.appimage.signed $(SBL_BOOTFILES_PATH)/hs_signed/app_ospi

#################
## ETHFW
#################
ethfw_image:
	$(MAKE) -C $(ETHFW_PATH) ethfw_all BUILD_CPU_MCU2_0=yes BUILD_CPU_MCU2_1=yes BUILD_QNX_A72=yes BUILD_APP_TIRTOS=no BUILD_APP_FREERTOS=yes BUILD_SOC_LIST=$(SOC_CAPS) PROFILE=$(BUILD_PROFILE) -s -j
	mkdir -p $(ETHFW_FIRMWARE_PATH)
	cp $(ETHFW_PATH)/out/$(SOC_CAPS)/R5Ft/FREERTOS/$(BUILD_PROFILE)/app_remoteswitchcfg_server.xer5f $(ETHFW_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f0_0-fw
	cp $(ETHFW_PATH)/out/$(SOC_CAPS)/R5Ft/FREERTOS/$(BUILD_PROFILE)/app_remoteswitchcfg_client.xer5f $(ETHFW_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f0_1-fw

##############################
## IPC ECHO TEST FIRMWARE
##############################
echo_firmware_mcu1_0:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_testb_freertos CORE=mcu1_0 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) DISABLE_RECURSE_DEPS=no -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_testb_freertos/bin/$(BOARD)/ipc_qnx_echo_testb_freertos_mcu1_0_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-mcu-r5f0_0-fw

echo_firmware_mcu1_1:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=mcu1_1 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) DISABLE_RECURSE_DEPS=no -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu1_1_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-mcu-r5f0_1-fw

echo_firmware_mcu2_0:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=mcu2_0 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) DISABLE_RECURSE_DEPS=no -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu2_0_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f0_0-fw

echo_firmware_mcu2_1: 
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=mcu2_1 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) DISABLE_RECURSE_DEPS=no -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu2_1_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f0_1-fw

echo_firmware_mcu3_0:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=mcu3_0 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) DISABLE_RECURSE_DEPS=no -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu3_0_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f1_0-fw

echo_firmware_mcu3_1:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=mcu3_1 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) DISABLE_RECURSE_DEPS=no -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu3_1_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f1_1-fw

echo_firmware_mcu4_0:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=mcu4_0 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) DISABLE_RECURSE_DEPS=no -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu4_0_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f2_0-fw

echo_firmware_mcu4_1:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=mcu4_1 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) DISABLE_RECURSE_DEPS=no -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_mcu4_1_$(PROFILE)_strip.xer5f $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f2_1-fw

echo_firmware_c66xdsp_1:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=c66xdsp_1 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) DISABLE_RECURSE_DEPS=no -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c66xdsp_1_$(PROFILE)_strip.xe66 $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c66_0-fw

echo_firmware_c66xdsp_2: echo_firmware_c66xdsp_1
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=c66xdsp_2 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) DISABLE_RECURSE_DEPS=no -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c66xdsp_2_$(PROFILE)_strip.xe66 $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c66_1-fw

echo_firmware_c7x_1:
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=c7x_1 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) DISABLE_RECURSE_DEPS=no -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c7x_1_$(PROFILE)_strip.xe71 $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c71_0-fw

echo_firmware_c7x_2: echo_firmware_c7x_1
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=c7x_2 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) DISABLE_RECURSE_DEPS=no -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c7x_2_$(PROFILE)_strip.xe71 $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c71_1-fw

echo_firmware_c7x_3: echo_firmware_c7x_2
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=c7x_3 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) DISABLE_RECURSE_DEPS=no -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c7x_3_$(PROFILE)_strip.xe71 $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c71_2-fw

echo_firmware_c7x_4: echo_firmware_c7x_3
	$(MAKE) -C $(PDK_PATH)/packages/ti/build   ipc_qnx_echo_test_freertos CORE=c7x_4 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=$(PROFILE) DISABLE_RECURSE_DEPS=no -s
	mkdir -p $(ECHO_FIRMWARE_PATH)
	cp $(PDK_PATH)/packages/ti/binary/ipc_qnx_echo_test_freertos/bin/$(BOARD)/ipc_qnx_echo_test_freertos_c7x_4_$(PROFILE)_strip.xe71 $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c71_3-fw

#################
## LATEAPPS
#################
ifeq ($(SOC),$(filter $(SOC), j721e j721s2 j784s4))
lateapps: bootapp sbl_lateapp1 sbl_lateapp2

lateapps_hs: bootapp_hs sbl_lateapp1_hs sbl_lateapp2_hs
endif
ifeq ($(SOC),$(filter $(SOC), j7200))
lateapps: bootapp sbl_lateapp1

lateapps_hs: bootapp_hs sbl_lateapp1_hs
endif

ifeq ($(BUILD_ETHFW),$(filter $(BUILD_ETHFW), 1))
sbl_lateapp1: ethfw_image
	mkdir -p $(SBL_BOOTFILES_PATH)/rprcs
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ETHFW_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f0_0-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f0_0-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ETHFW_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f0_1-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f0_1-fw.rprc
	$(MULTICORE_APPIMAGE_GEN_TOOL_PATH)/MulticoreImageGen LE $(DEV_ID) $(SBL_BOOTFILES_PATH)/lateapp1 $(REMOTE_CORE_LIST_LATEAPP1)
else
sbl_lateapp1: echo_firmware_mcu1_0 echo_firmware_mcu1_1 echo_firmware_mcu2_0 echo_firmware_mcu2_1
	mkdir -p $(SBL_BOOTFILES_PATH)/rprcs
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f0_0-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f0_0-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f0_1-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f0_1-fw.rprc
	$(MULTICORE_APPIMAGE_GEN_TOOL_PATH)/MulticoreImageGen LE $(DEV_ID) $(SBL_BOOTFILES_PATH)/lateapp1 $(REMOTE_CORE_LIST_LATEAPP1)
endif

sbl_lateapp1_hs: sbl_lateapp1
	mkdir -p $(SBL_BOOTFILES_PATH)/hs_signed
	cp -f $(SBL_BOOTFILES_PATH)/lateapp1 $(SBL_BOOTFILES_PATH)/lateapp1.save
	$(CERT_SCRIPT) -b $(SBL_BOOTFILES_PATH)/lateapp1 -o $(SBL_BOOTFILES_PATH)/hs_signed/lateapp1 -c R5 -l 0x0 -k $(PDK_PATH)/packages/ti/build/makerules/k3_dev_mpk.pem
	mv -f $(SBL_BOOTFILES_PATH)/lateapp1.save $(SBL_BOOTFILES_PATH)/lateapp1

ifeq ($(BUILD_ETHFW),$(filter $(BUILD_ETHFW), 1))
sbl_lateapp2:

sbl_lateapp2_hs:
else
ifeq ($(SOC),$(filter $(SOC), j721e))
sbl_lateapp2: echo_firmware_mcu3_0 echo_firmware_mcu3_1 echo_firmware_c66xdsp_1 echo_firmware_c66xdsp_2 echo_firmware_c7x_1
	mkdir -p $(SBL_BOOTFILES_PATH)/rprcs
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f1_0-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f1_0-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f1_1-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f1_1-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c66_0-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c66_0-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c66_1-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c66_1-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c71_0-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c71_0-fw.rprc
	$(MULTICORE_APPIMAGE_GEN_TOOL_PATH)/MulticoreImageGen LE $(DEV_ID) $(SBL_BOOTFILES_PATH)/lateapp2 $(REMOTE_CORE_LIST_LATEAPP2)
endif

ifeq ($(SOC),$(filter $(SOC), j721s2))
sbl_lateapp2: echo_firmware_mcu3_0 echo_firmware_mcu3_1 echo_firmware_c7x_1 echo_firmware_c7x_2
	mkdir -p $(SBL_BOOTFILES_PATH)/rprcs
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f1_0-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f1_0-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f1_1-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f1_1-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c71_0-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c71_0-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c71_1-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c71_1-fw.rprc
	$(MULTICORE_APPIMAGE_GEN_TOOL_PATH)/MulticoreImageGen LE $(DEV_ID) $(SBL_BOOTFILES_PATH)/lateapp2 $(REMOTE_CORE_LIST_LATEAPP2)
endif

ifeq ($(SOC),$(filter $(SOC), j784s4))
sbl_lateapp2: echo_firmware_mcu3_0 echo_firmware_mcu3_1 echo_firmware_mcu4_0 echo_firmware_mcu4_1 echo_firmware_c7x_1 echo_firmware_c7x_2 echo_firmware_c7x_3 echo_firmware_c7x_4
	mkdir -p $(SBL_BOOTFILES_PATH)/rprcs
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f1_0-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f1_0-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f1_1-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f1_1-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f2_0-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f2_0-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-main-r5f2_1-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-main-r5f2_1-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c71_0-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c71_0-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c71_1-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c71_1-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c71_2-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c71_2-fw.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(ECHO_FIRMWARE_PATH)/$(SOC_TAG)-c71_3-fw $(SBL_BOOTFILES_PATH)/rprcs/$(SOC_TAG)-c71_3-fw.rprc
	$(MULTICORE_APPIMAGE_GEN_TOOL_PATH)/MulticoreImageGen LE $(DEV_ID) $(SBL_BOOTFILES_PATH)/lateapp2 $(REMOTE_CORE_LIST_LATEAPP2)
endif

sbl_lateapp2_hs: sbl_lateapp2
	mkdir -p $(SBL_BOOTFILES_PATH)/hs_signed
	cp -f $(SBL_BOOTFILES_PATH)/lateapp2 $(SBL_BOOTFILES_PATH)/lateapp2.save
	$(CERT_SCRIPT) -b $(SBL_BOOTFILES_PATH)/lateapp2 -o $(SBL_BOOTFILES_PATH)/hs_signed/lateapp2 -c R5 -l 0x0 -k $(PDK_PATH)/packages/ti/build/makerules/k3_dev_mpk.pem
	mv -f $(SBL_BOOTFILES_PATH)/lateapp2.save $(SBL_BOOTFILES_PATH)/lateapp2
endif

#################
## ATF + OPTEE
#################
atf_optee:
	# For ATF, setting HANDLE_EA_EL3_FIRST=0 for QNX so that the all runtime exception to be routed to current exception level (or in EL1 if the current exception level is EL0)
ifeq ($(SOC),$(filter $(SOC), j784s4))
	$(MAKE) -C $(PDK_PATH)/../arm-trusted-firmware -s -j32 CROSS_COMPILE=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- PLAT=k3 TARGET_BOARD=$(SOC) SPD=opteed HANDLE_EA_EL3_FIRST=0 K3_USART=$(K3_USART)
else
	$(MAKE) -C $(PDK_PATH)/../arm-trusted-firmware -s -j32 CROSS_COMPILE=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- PLAT=k3 TARGET_BOARD=generic SPD=opteed HANDLE_EA_EL3_FIRST=0 K3_USART=$(K3_USART)
endif
	$(MAKE) -C $(PDK_PATH)/../ti-optee-os -s -j32 CROSS_COMPILE_core=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- CROSS_COMPILE_ta_arm32=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- CROSS_COMPILE_ta_arm64=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- NOWERROR=1 CFG_TEE_TA_LOG_LEVEL=0 CFG_TEE_CORE_LOG_LEVEL=2 CFG_ARM64_core=y ta-targets=ta_arm64 PLATFORM=k3 PLATFORM_FLAVOR=j7 CFG_CONSOLE_UART=$(CFG_CONSOLE_UART)
	mkdir -p $(ATF_OPTEE_PATH)
ifeq ($(SOC),$(filter $(SOC), j784s4))
	cp $(PDK_PATH)/../arm-trusted-firmware/build/k3/$(SOC)/release/bl31.bin $(ATF_OPTEE_PATH)/bl31.bin
else
	cp $(PDK_PATH)/../arm-trusted-firmware/build/k3/generic/release/bl31.bin $(ATF_OPTEE_PATH)/bl31.bin
endif
	cp $(PDK_PATH)/../ti-optee-os/out/arm-plat-k3/core/tee-pager_v2.bin $(ATF_OPTEE_PATH)/bl32.bin

atf_optee_a53:
	$(MAKE) -C $(PDK_QNX_PATH)/../../arm-trusted-firmware -s -j32 CROSS_COMPILE=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- PLAT=k3 TARGET_BOARD=lite SPD=opteed HANDLE_EA_EL3_FIRST=0
	$(MAKE) -C $(PDK_QNX_PATH)/../../ti-optee-os -s -j32 CROSS_COMPILE_core=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- CROSS_COMPILE_ta_arm32=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- CROSS_COMPILE_ta_arm64=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- NOWERROR=1 CFG_TEE_TA_LOG_LEVEL=0 CFG_TEE_CORE_LOG_LEVEL=2 CFG_ARM64_core=y ta-targets=ta_arm64 PLATFORM=k3-am65x
	mkdir -p $(ATF_OPTEE_PATH)
	cp $(PDK_QNX_PATH)/../../arm-trusted-firmware/build/k3/lite/release/bl31.bin $(ATF_OPTEE_PATH)/bl31.bin
	cp $(PDK_QNX_PATH)/../../ti-optee-os/out/arm-plat-k3/core/tee-pager_v2.bin $(ATF_OPTEE_PATH)/bl32.bin

#################
## ATF only
#################
atf_only:
	# For ATF, setting HANDLE_EA_EL3_FIRST=0 for QNX so that the all runtime exception to be routed to current exception level (or in EL1 if the current exception level is EL0)
ifeq ($(SOC),$(filter $(SOC), j784s4))
	$(MAKE) -C $(PDK_PATH)/../arm-trusted-firmware -s -j32 CROSS_COMPILE=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- PLAT=k3 TARGET_BOARD=$(SOC) HANDLE_EA_EL3_FIRST=0 K3_USART=$(K3_USART)
else
	$(MAKE) -C $(PDK_PATH)/../arm-trusted-firmware -s -j32 CROSS_COMPILE=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- PLAT=k3 TARGET_BOARD=generic HANDLE_EA_EL3_FIRST=0 K3_USART=$(K3_USART)
endif
	mkdir -p $(ATF_OPTEE_PATH)
ifeq ($(SOC),$(filter $(SOC), j784s4))
	cp $(PDK_PATH)/../arm-trusted-firmware/build/k3/$(SOC)/release/bl31.bin $(ATF_OPTEE_PATH)/bl31.bin
else
	cp $(PDK_PATH)/../arm-trusted-firmware/build/k3/generic/release/bl31.bin $(ATF_OPTEE_PATH)/bl31.bin
endif

#################
## QNX APPIMAGES
#################
ifeq ($(USE_OPTEE),$(filter $(USE_OPTEE), 1))
a72_appimages: atf_optee
ifeq ("$(wildcard $(QNX_BOOT_PATH)/qnx-ifs)","")
	$(error qnx-ifs is still not built!)
endif
	mkdir -p $(SBL_BOOTFILES_PATH)/rprcs
	curr_dir=$(PWD)
	cd $(ATF_OPTEE_PATH) && \
	$(QNX_BASE)/host/linux/x86_64/usr/bin/$(QNX_CROSS_COMPILER_TOOL)ld -T $(LDS_PATH)/atf_optee.lds -o $(SBL_BOOTFILES_PATH)/rprcs/atf_optee.elf && \
	cd $(QNX_BOOT_PATH) && \
	$(QNX_BASE)/host/linux/x86_64/usr/bin/$(QNX_CROSS_COMPILER_TOOL)ld -T $(LDS_PATH)/ifs_qnx.lds -o $(SBL_BOOTFILES_PATH)/rprcs/ifs_qnx.elf && \
	cd $(curr_dir)
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(SBL_BOOTFILES_PATH)/rprcs/atf_optee.elf $(SBL_BOOTFILES_PATH)/rprcs/atf_optee.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(SBL_BOOTFILES_PATH)/rprcs/ifs_qnx.elf $(SBL_BOOTFILES_PATH)/rprcs/ifs_qnx.rprc
	$(MULTICORE_APPIMAGE_GEN_TOOL_PATH)/MulticoreImageGen LE $(DEV_ID) $(SBL_BOOTFILES_PATH)/atf_optee.appimage 0 $(SBL_BOOTFILES_PATH)/rprcs/atf_optee.rprc
	$(MULTICORE_APPIMAGE_GEN_TOOL_PATH)/MulticoreImageGen LE $(DEV_ID) $(SBL_BOOTFILES_PATH)/ifs_qnx.appimage 0 $(SBL_BOOTFILES_PATH)/rprcs/ifs_qnx.rprc
else
a72_appimages: atf_only
ifeq ("$(wildcard $(QNX_BOOT_PATH)/qnx-ifs)","")
	$(error qnx-ifs is still not built!)
endif
	mkdir -p $(SBL_BOOTFILES_PATH)/rprcs
	curr_dir=$(PWD)
	cd $(ATF_OPTEE_PATH) && \
	$(QNX_BASE)/host/linux/x86_64/usr/bin/$(QNX_CROSS_COMPILER_TOOL)ld -T $(LDS_PATH)/atf_only.lds -o $(SBL_BOOTFILES_PATH)/rprcs/atf_only.elf && \
	cd $(QNX_BOOT_PATH) && \
	$(QNX_BASE)/host/linux/x86_64/usr/bin/$(QNX_CROSS_COMPILER_TOOL)ld -T $(LDS_PATH)/ifs_qnx.lds -o $(SBL_BOOTFILES_PATH)/rprcs/ifs_qnx.elf && \
	cd $(curr_dir)
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(SBL_BOOTFILES_PATH)/rprcs/atf_only.elf $(SBL_BOOTFILES_PATH)/rprcs/atf_only.rprc
	$(SBL_OUT2RPRC_GEN_TOOL_PATH)/out2rprc.exe $(SBL_BOOTFILES_PATH)/rprcs/ifs_qnx.elf $(SBL_BOOTFILES_PATH)/rprcs/ifs_qnx.rprc
	$(MULTICORE_APPIMAGE_GEN_TOOL_PATH)/MulticoreImageGen LE $(DEV_ID) $(SBL_BOOTFILES_PATH)/atf_optee.appimage 0 $(SBL_BOOTFILES_PATH)/rprcs/atf_only.rprc
	$(MULTICORE_APPIMAGE_GEN_TOOL_PATH)/MulticoreImageGen LE $(DEV_ID) $(SBL_BOOTFILES_PATH)/ifs_qnx.appimage 0 $(SBL_BOOTFILES_PATH)/rprcs/ifs_qnx.rprc
endif

a72_appimages_hs: a72_appimages
	mkdir -p $(SBL_BOOTFILES_PATH)/hs_signed
	$(CERT_SCRIPT) -b $(SBL_BOOTFILES_PATH)/atf_optee.appimage -o $(SBL_BOOTFILES_PATH)/hs_signed/atf_optee.appimage -c R5 -l 0x0 -k $(PDK_PATH)/packages/ti/build/makerules/k3_dev_mpk.pem
	$(CERT_SCRIPT) -b $(SBL_BOOTFILES_PATH)/ifs_qnx.appimage -o $(SBL_BOOTFILES_PATH)/hs_signed/ifs_qnx.appimage -c R5 -l 0x0 -k $(PDK_PATH)/packages/ti/build/makerules/k3_dev_mpk.pem

a53_appimages: atf_optee_a53
ifeq ("$(wildcard $(QNX_BOOT_PATH)/qnx-ifs)","")
	$(error qnx-ifs is still not built!)
endif
	$(MAKE) -C $(MCU_PLUS_PATH)/tools/boot/deviceManagerAppimageGen clean BOARD=$(MCU_BOARD_TYPE) DM_APP_NAME=$(DM_APP_NAME) DM_APPIMAGE_NAME=$(DM_APPIMAGE_NAME)
	$(MAKE) -C $(MCU_PLUS_PATH)/tools/boot/deviceManagerAppimageGen all BOARD=$(MCU_BOARD_TYPE) DM_APP_NAME=$(DM_APP_NAME) DM_APPIMAGE_NAME=$(DM_APPIMAGE_NAME)
	$(MAKE) -C $(MCU_PLUS_PATH)/tools/boot/HSMAppimageGen clean BOARD=$(MCU_BOARD_TYPE) DM_APP_NAME=$(DM_APP_NAME) DM_APPIMAGE_NAME=$(DM_APPIMAGE_NAME)
	$(MAKE) -C $(MCU_PLUS_PATH)/tools/boot/HSMAppimageGen all BOARD=$(MCU_BOARD_TYPE) DM_APP_NAME=$(DM_APP_NAME) DM_APPIMAGE_NAME=$(DM_APPIMAGE_NAME)
	$(MAKE) -C $(MCU_PLUS_PATH)/tools/boot/qnxAppimageGen clean BOARD=$(MCU_BOARD_TYPE)
	$(MAKE) -C $(MCU_PLUS_PATH)/tools/boot/qnxAppimageGen all BOARD=$(MCU_BOARD_TYPE)
	mkdir -p $(SBL_BOOTFILES_PATH)
	cp $(MCU_PLUS_PATH)/tools/boot/qnxAppimageGen/board/$(MCU_BOARD_TYPE)/qnx.appimage $(SBL_BOOTFILES_PATH)/ifs_qnx.appimage

#################
## CLEAN UPS
#################
atf_optee_scrub:
	$(MAKE) -C $(PDK_PATH)/../arm-trusted-firmware clean
	$(MAKE) -C $(PDK_PATH)/../ti-optee-os clean CFG_ARM64_core=y PLATFORM=k3 PLATFORM_FLAVOR=j7
	rm -rf $(PDK_PATH)/../arm-trusted-firmware/build/k3
	rm -rf $(PDK_PATH)/../ti-optee-os/out/arm-plat-k3

sbl_bootimage_scrub: atf_optee_scrub
	$(MAKE) -C $(PDK_PATH)/packages/ti/build    clean BOARD=$(BOARD) SOC=$(SOC) PROFILE=$(PROFILE) -s
	rm -rf $(PDK_PATH)/packages/ti/binary/*
	rm -rf $(PDK_PATH)/packages/ti/boot/sbl/binary
	rm -rf $(MCUSW_PATH)/binary
	rm -rf $(SBL_BOOTFILES_PATH)
ifeq ($(BUILD_ETHFW),$(filter $(BUILD_ETHFW), 1))
	$(MAKE) -C $(ETHFW_PATH) ethfw_all_clean BUILD_CPU_MCU2_0=yes BUILD_CPU_MCU2_1=yes BUILD_SOC_LIST=$(SOC_CAPS) PROFILE=$(PROFILE) -s -j
	rm -rf $(ETHFW_FIRMWARE_PATH)
	rm -rf $(SBL_ETHFW_BOOTFILES_PATH)
	rm -rf $(SBL_ETHFW_BOOTFILES_HS_PATH)
else
	rm -rf $(ECHO_FIRMWARE_PATH)
	rm -rf $(SBL_ECHO_BOOTFILES_PATH)
	rm -rf $(SBL_ECHO_BOOTFILES_HS_PATH)
endif


#################
## OSPI FLASHING
#################
ifeq ($(SOC),$(filter $(SOC), am62x am62a))
sbl_bootimage_install_ospi:
	cd $(UNIFLASH_DIR) && \
	python3 $(UNIFLASH_SCRIPT) -p $(UNIFLASH_COM_PORT) --cfg=sbl_prebuilt/$(MCU_BOARD_TYPE)/default_sbl_ospi_qnx.cfg
else
sbl_bootimage_install_ospi:
	$(MAKE) sbl_bootimage_flash_uniflash_programmer
	$(MAKE) sbl_bootimage_flash_sbl_sysfw_bootapp
ifeq ($(BUILD_ETHFW),$(filter $(BUILD_ETHFW), 1))
	$(MAKE) sbl_bootimage_flash_ethfw
else
	$(MAKE) sbl_bootimage_flash_echotest
endif
	$(MAKE) sbl_bootimage_flash_hlos
endif

sbl_bootimage_flash_uniflash_programmer:
ifeq ($(UNIFLASH_FOUND), yes)
	$(UNIFLASH_SCRIPT) --mode processors -c $(UNIFLASH_COM_PORT) -f $(UNIFLASH_DIR)/processors/FlashWriter/$(BOARD)/uart_$(SOC)_evm_flash_programmer_release.tiimage -i 0 || true
else
	echo "Uniflash not found! Please install uniflash or update the uniflash path in makefile"
endif

sbl_bootimage_flash_sbl_sysfw_bootapp:
ifeq ($(UNIFLASH_FOUND), yes)
	#SBL Image
	$(UNIFLASH_SCRIPT) --mode processors -c $(UNIFLASH_COM_PORT) -f $(SBL_BOOTFILES_PATH)/tiboot3.bin.ospi.tiimage -d 3 -o $(OSPI_LOCATION_SBL_IMAGE) || true
	echo "*************************"
	echo "SBL flashed"
	echo "*************************"
	#OSPI Patten file
	$(UNIFLASH_SCRIPT) --mode processors -c $(UNIFLASH_COM_PORT) -f $(OSPI_PATTERN_FILE) -d 3 -o $(OSPI_PATTERN) || true
	echo "*************************"
	echo "OSPI Patten flashed"
	echo "*************************"
	#SYSFW BIN
	$(UNIFLASH_SCRIPT) --mode processors -c $(UNIFLASH_COM_PORT) -f $(SBL_BOOTFILES_PATH)/tifs.bin -d 3 -o $(OSPI_LOCATION_SYSFW_BIN) || true
	echo "*************************"
	echo "SYSFW BIN flashed"
	echo "*************************"
	#Boot App
	cp -fv $(SBL_BOOTFILES_PATH)/app_ospi $(SBL_BOOTFILES_PATH)/app_ospi.appimage
	$(UNIFLASH_SCRIPT) --mode processors -c $(UNIFLASH_COM_PORT) -f $(SBL_BOOTFILES_PATH)/app_ospi.appimage -d 3 -o $(OSPI_LOCATION_BOOT_APP) || true
	rm -rf $(SBL_BOOTFILES_PATH)/app_ospi.appimage
	echo "*************************"
	echo "Boot App flashed"
	echo "*************************"
else
	echo "Uniflash not found! Please install uniflash or update the uniflash path in makefile"
endif

sbl_bootimage_flash_ethfw:
ifeq ($(UNIFLASH_FOUND), yes)
	#Multicore Image 1
	cp -fv $(SBL_BOOTFILES_PATH)/lateapp1 $(SBL_BOOTFILES_PATH)/lateapp1.appimage
	$(UNIFLASH_SCRIPT) --mode processors -c $(UNIFLASH_COM_PORT) -f $(SBL_BOOTFILES_PATH)/lateapp1.appimage -d 3 -o $(OSPI_LOCATION_MULTI_CORE_IMAGE_1) || true
	rm -rf $(SBL_BOOTFILES_PATH)/lateapp1.appimage
	echo "*************************"
	echo "Multicore Image 1 flashed"
	echo "*************************"
else
	echo "Uniflash not found! Please install uniflash or update the uniflash path in makefile"
endif

sbl_bootimage_flash_echotest:
ifeq ($(UNIFLASH_FOUND), yes)
	#Multicore Image 1
	cp -fv $(SBL_BOOTFILES_PATH)/lateapp1 $(SBL_BOOTFILES_PATH)/lateapp1.appimage
	$(UNIFLASH_SCRIPT) --mode processors -c $(UNIFLASH_COM_PORT) -f $(SBL_BOOTFILES_PATH)/lateapp1.appimage -d 3 -o $(OSPI_LOCATION_MULTI_CORE_IMAGE_1) || true
	rm -rf $(SBL_BOOTFILES_PATH)/lateapp1.appimage
	echo "*************************"
	echo "Multicore Image 1 flashed"
	echo "*************************"
ifeq ($(BUILD_ETHFW),$(filter $(BUILD_ETHFW), 1))
	### no lateapp2 imaage for ethfw build
else
ifeq ($(SOC),$(filter $(SOC), j721e j721s2 j784s4))
	#Multicore Image 2
	cp -fv $(SBL_BOOTFILES_PATH)/lateapp2 $(SBL_BOOTFILES_PATH)/lateapp2.appimage
	$(UNIFLASH_SCRIPT) --mode processors -c $(UNIFLASH_COM_PORT) -f $(SBL_BOOTFILES_PATH)/lateapp2.appimage -d 3 -o $(OSPI_LOCATION_MULTI_CORE_IMAGE_2) || true
	rm -rf $(SBL_BOOTFILES_PATH)/lateapp2.appimage
	echo "*************************"
	echo "Multicore Image 2 flashed"
	echo "*************************"
endif
endif
else
	echo "Uniflash not found! Please install uniflash or update the uniflash path in makefile"
endif

sbl_bootimage_flash_hlos:
ifeq ($(UNIFLASH_FOUND), yes)
	#ATF Image
	$(UNIFLASH_SCRIPT) --mode processors -c $(UNIFLASH_COM_PORT) -f $(SBL_BOOTFILES_PATH)/atf_optee.appimage -d 3 -o $(OSPI_LOCATION_ATF_IMAGE) || true
	echo "*************************"
	echo "ATF Image flashed"
	echo "*************************"
	#HLOS Image
	$(UNIFLASH_SCRIPT) --mode processors -c $(UNIFLASH_COM_PORT) -f $(SBL_BOOTFILES_PATH)/ifs_qnx.appimage -d 3 -o $(OSPI_LOCATION_HLOS_KERNEL_IMAGE) || true
	echo "*************************"
	echo "HLOS Image flashed"
	echo "*************************"
else
	echo "Uniflash not found! Please install uniflash or update the uniflash path in makefile"
endif

ifeq ($(SOC),$(filter $(SOC), am62x am62a))
######################
## OSPI NAND FLASHING
######################
sbl_uniflash_ospi_nand:
	cd $(UNIFLASH_DIR) && \
	python3 $(UNIFLASH_SCRIPT) -p $(UNIFLASH_COM_PORT) --cfg=sbl_prebuilt/$(MCU_BOARD_TYPE)/default_sbl_ospi_nand_qnx.cfg

#################
## EMMC FLASHING
#################
sbl_uniflash_emmc:
	cd $(UNIFLASH_DIR) && \
	python3 $(UNIFLASH_SCRIPT) -p $(UNIFLASH_COM_PORT) --cfg=sbl_prebuilt/$(MCU_BOARD_TYPE)/default_sbl_emmc_qnx.cfg

###################
## UART BOOTLOADER
###################
sbl_uart_bootloader:
	cd $(UNIFLASH_DIR) && \
	python3 $(UART_BOOTLOADER_SCRIPT) -p $(UNIFLASH_COM_PORT) --cfg=sbl_prebuilt/$(MCU_BOARD_TYPE)/default_sbl_uart_qnx.cfg
endif
