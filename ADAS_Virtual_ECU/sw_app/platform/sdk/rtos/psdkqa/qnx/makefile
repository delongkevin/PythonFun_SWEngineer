include qnx_tools_path.mak

.PHONY: all clean scrub
.PHONY: qnx_libs qnx_libs_clean
.PHONY: qnx_bins qnx_bins_clean
.PHONY: qnx_codec qnx_codec_clean
.PHONY: examples examples_clean
.PHONY: qnx_codec_tests qnx_codec_tests_clean
.PHONY: utils utils_clean
.PHONY: bsp bsp_clean
.PHONY: sbl_echo_test sbl_echo_test_clean
.PHONY: sbl_ethfw sbl_ethfw_clean
.PHONY: qnx_fs_create
.PHONY: qnx_spl_create_copy
.PHONY: qnx_sbl_ethfw_create_copy qnx_sbl_ethfw_hs_create_copy
.PHONY: qnx_sbl_echo_create_copy qnx_sbl_echo_hs_create_copy
.PHONY: qnx_create_all_platform_packages

## Supported PROFILE -> release, debug, all
export PROFILE ?= release

## Supported BOARD -> j721s2_hyd
export BOARD ?= j721s2_hyd

export PLATFORM = aarch64le
export PSDK_QNX_VERSION_REL = PSDKQNX_08_05_00
export PSDK_QNX_TAGID ?= QNX$(QNX_SDP_VERSION)_$(BOARD)

## Use Dymamic .so PDK library
export PSDK_QNX_USE_DSO ?=1

ifeq ($(QNX_SDP_VERSION), 700)
  $(error SDP700 not support for BOARD=j7200_evm!)
endif

ifeq ($(BOARD),$(filter $(BOARD), j721e_evm))
  export SOC = j721e
else ifeq ($(BOARD),$(filter $(BOARD), j7200_evm))
  export SOC = j7200
else ifeq ($(BOARD),$(filter $(BOARD), j721s2_evm j721s2_hyd))
  export SOC = j721s2
else ifeq ($(BOARD),$(filter $(BOARD), j784s4_evm))
  export SOC = j784s4
else ifeq ($(BOARD),$(filter $(BOARD), am62x_evm))
  export SOC = am62x
  export SOC_MCU_PLUS = am62x
  ## sk or sk-lp
  export BOARD_TYPE ?= sk
else ifeq ($(BOARD),$(filter $(BOARD), am62a_evm))
  export SOC = am62a
  export SOC_MCU_PLUS = am62ax
  ## sk
  export BOARD_TYPE ?= sk
else
  $(error Unsupported BOARD!)
endif

## flag to denote if it is a vision app build
export VISION_APPS_BUILD_FLAGS_MAK ?=0


####################
# help
####################
help:
	### Important build env varibles:
	#
	# PROFILE                       Supported build profile ## release (Default), debug, all
	# BOARD                         Supported Boards  ## j721s2_hyd
	# SOC                           Supported SOCs    ## j721s2
ifeq ($(SOC), $(filter $(SOC), am62x am62a))
	# BOARD_TYPE                    Supported Board types  ##sk, sk-lp
endif	
	# PSDK_QNX_USE_DSO              Use Dymamic .so PDK library ## 1 (Default), 0
	# VISION_APPS_BUILD_FLAGS_MAK   Use Vision Apps make build flag ## 0 (Default), 1
	#
	### Use below make targets to build SDK and/or different components with the SDK
	#
	# make help                  # Show supported makefile target's
	# make all                   # Build all PSDK QNX components (qnx_libs qnx_bins qnx_codec bsp examples qnx_codec_tests utils)
	# make clean                 # Clean all PSDK QNX components
	# make scrub                 # Delete all generated files and folders in SDK
	#
	# make qnx_fs_create         # Install PSDK QNX binaries & libraries to the local stage folder
	# make qnx_fs_copy_spl_uboot # Install spl-uboot bootloader  to the local stage folder
	# make qnx_fs_clean          # Cleanup the local stage folder
	#
	# make qnx_docs              # Generate the PSDK QNX documentation
	# make qnx_docs_clean        # Clean PSDK QNX documentation
	# make bsp                   # Build QNX BSP
	# make bsp_clean             # Clean QNX BSP
	#
	# make qnx_libs              # Build QNX PDK libraries
	# make qnx_libs_clean        # Clean QNX PDK libraries
	#
	# make qnx_bins              # Build PSDK QNX binaries (DEVNP, RMs)
	# make qnx_bins_clean        # Clean PSDK QNX binaries
	#
	# make examples              # Build PSDK QNX examples
	# make examples_clean        # Clean PSDK QNX examples
	#
	# make utils                 # Build PSDK QNX utils (k3conf)
	# make utils_clean           # Clean PSDK QNX utils
	#
ifneq ($(SOC), $(filter $(SOC), am62x am62a))
	# make qnx_codec             # Build PSDK QNX codec binary/libries
	# make qnx_codec_clean       # Clean PSDK QNX codec binary/libries
	# make qnx_codec_tests       # Build PSDK QNX codec tests
	# make qnx_codec_tests_clean # Clean PSDK QNX codec tests
	#
	### Use below make targets to build --> SBL + Boot image
	### NOTE: Need to call "make all" and "make qnx_fs_create" before call below:
	#
	# make sbl_echo_test                      # Build SBL + BootAPP + Echo test firmware images + A72 App images
	# make sbl_echo_test_clean                # Clean SBL + BootAPP + Echo test firmware images + A72 App images
	# make sbl_ethfw                          # Build SBL + BootAPP + EthFw firmware images + A72 App images
	# make sbl_ethfw_clean                    # Clean SBL + BootAPP + EthFw firmware images + A72 App images
	# make sbl_echo_test_hs                   # Build SBL + BootAPP + Echo test firmware images + A72 App images (Signed for HS device)
	# make sbl_echo_test_clean_hs             # Clean SBL + BootAPP + Echo test firmware images + A72 App images
	# make sbl_ethfw_hs                       # Build SBL + BootAPP + EthFw firmware images + A72 App images (Signed for HS device)
	# make sbl_ethfw_clean_hs                 # Clean SBL + BootAPP + EthFw firmware images + A72 App images
	#
	# make sbl_echo_test_ospi_flashing        # Flash SBL + BootAPP + Echo test firmware images + A72 App images to OSPI
	# make sbl_ethfw_ospi_flashing            # Flash SBL + BootAPP + EthFW firmware images + A72 App images to OSPI
	# make sbl_echo_test_ospi_flashing_hs     # Flash SBL + BootAPP + Echo test firmware images + A72 App images to OSPI (Signed for HS device)
	# make sbl_ethfw_ospi_flashing_hs         # Flash SBL + BootAPP + EthFW firmware images + A72 App images to OSPI (Signed for HS device)
	#
	# make sbl_combined_boot_echo_test        # Build SBL + Echo test firmware images + A72 App images (combined image)
	# make sbl_combined_boot_echo_test_clean  # Clean SBL + Echo test firmware images + A72 App images (combined image)
	# make sbl_combined_boot_ethfw            # Build SBL + EthFw firmware images + A72 App images (combined image)
	# make sbl_combined_boot_ethfw_clean      # Clean SBL + EthFw firmware images + A72 App images (combined image)
	#
	# make sbl_combined_boot_echo_test_ospi_flashing        # Flash SBL + Echo test firmware images + A72 App images (combined image) to OSPI
	# make sbl_combined_boot_ethfw_ospi_flashing            # Flash SBL + EthFw firmware images + A72 App images (combined image) to OSPI
	#
	### Use below make targets for automating the creation of QNX filesystems
	# make qnx_spl_create_copy                # Clean SPL binaries + Build SPL based QNX Filesystem
	# make qnx_sbl_ethfw_create_copy          # Clean SBL binaries + Build SBL based QNX Filesystem for Ethernet Firmware
	# make qnx_sbl_ethfw_hs_create_copy       # Clean SBL binaries + Build SBL based QNX Filesystem for Ethernet Firmware with Signed binaries for HS devices
	# make qnx_sbl_echo_create_copy           # Clean SBL binaries + Build SBL based QNX Filesystem for IPC Echo Test
	# make qnx_sbl_echo_hs_create_copy        # Clean SBL binaries + Build SBL based QNX Filesystem for IPC Echo Test with Signed binaries for HS devices
	# make qnx_create_all_platform_packages   # Scrub All binaries + Build SPL and SBL based QNX Filesystems for Supported Jacinto Platforms (J7200, J721E, J721S2, J784S4)
	#
else
	### Use below make targets to build --> SBL + IPC firmware images for A53
	### NOTE: Need to call "make all" and "make qnx_fs_create" before call below:
	# make sbl_echo_test                      # Build SBL + Echo test firmware images + A53 App image
	# make sbl_echo_test_clean                # Clean SBL + Echo test firmware images + A53 App image
	#
	# make sbl_echo_test_ospi_flashing        # Flash SBL + Echo test firmware images + A53 App image to OSPI NOR
	# make sbl_echo_test_ospi_nand_flashing   # Flash SBL + Echo test firmware images + A53 App image to OSPI NAND
	# make sbl_echo_test_emmc_flashing        # Flash SBL + Echo test firmware images + A53 App image to eMMC
	# make sbl_echo_test_uart_bootloader      # Flash SBL + Echo test firmware images + A53 App image to UART
	#
endif

all: qnx_libs qnx_bins qnx_codec examples qnx_codec_tests utils

clean: 
	$(MAKE) bsp_clean
	$(MAKE) qnx_libs_clean
	$(MAKE) qnx_bins_clean
	$(MAKE) examples_clean
	$(MAKE) utils_clean
	$(MAKE) qnx_codec_clean
	$(MAKE) qnx_codec_tests_clean
	$(MAKE) qnx_fs_clean

scrub: clean
	$(MAKE) qnx_libs_scrub
	$(MAKE) sbl_echo_test_clean
ifeq ($(SOC),$(filter $(SOC), j721e j7200 j784s4))
	$(MAKE) sbl_ethfw_clean
endif
	$(MAKE) sbl_echo_test_clean_hs
ifeq ($(SOC),$(filter $(SOC), j721e j7200 j784s4))
	$(MAKE) sbl_ethfw_clean_hs
endif
	$(MAKE) sbl_combined_boot_echo_test_clean
ifeq ($(SOC),$(filter $(SOC), j721e j7200 j784s4))
	$(MAKE) sbl_combined_boot_ethfw_clean
endif

####################
# qnx docs
####################
qnx_docs:
	$(MAKE) -C ./internal_docs/sphinx_user_guide/ USERGUIDE_OUT_DIR=$(shell  pwd)/docs/user_guide DEVFAMILY=$(shell echo $(SOC) | tr a-z A-Z)

qnx_docs_clean:
	$(MAKE) -C ./internal_docs/sphinx_user_guide/  clean USERGUIDE_OUT_DIR=$(shell  pwd)/docs/user_guide DEVFAMILY=$(shell echo $(SOC) | tr a-z A-Z)

####################
# psdk qnx packaging
####################

ifeq ($(QNX_SDP_VERSION), 710)
qnx_fs_create:
	mkdir -p $(QNX_BOOT_PATH)
	mkdir -p $(QNX_FS_PATH)
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/scripts/qnx_fs_create_qnx710.mk qnx_sdk BOARD=$(BOARD) SOC=$(SOC) PROFILE=$(PROFILE)

qnx_fs_copy_spl_uboot:
	mkdir -p $(QNX_BOOT_PATH)
	mkdir -p $(QNX_FS_PATH)
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/scripts/qnx_fs_create_qnx710.mk copy_spl_uboot BOARD=$(BOARD) SOC=$(SOC) PROFILE=$(PROFILE)
endif

qnx_fs_clean:
	rm -rf $(QNX_BOOT_PATH)
	rm -rf $(QNX_FS_PATH)
	rm -rf $(QNX_AUX_FS_PATH)

####################
# sbl bootapp boot
####################

sbl_echo_test:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl                    all   PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) BOARD=$(BOARD) SOC=$(SOC) SOC_MCU_PLUS=$(SOC_MCU_PLUS) PROFILE=$(PROFILE) BOARD_TYPE=$(BOARD_TYPE)

sbl_echo_test_clean:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl                    clean PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) BOARD=$(BOARD) SOC=$(SOC) SOC_MCU_PLUS=$(SOC_MCU_PLUS) PROFILE=$(PROFILE) BOARD_TYPE=$(BOARD_TYPE)

sbl_ethfw:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl                    all   PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) ETHFW_PATH=$(ETHFW_PATH) BOARD=$(BOARD) SOC=$(SOC) PROFILE=$(PROFILE) BUILD_ETHFW=1

sbl_ethfw_clean:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl                    clean PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) ETHFW_PATH=$(ETHFW_PATH) BOARD=$(BOARD) SOC=$(SOC) PROFILE=$(PROFILE)  BUILD_ETHFW=1

sbl_echo_test_hs:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl                    sbl_bootimage_hs   PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) BOARD=$(BOARD) SOC=$(SOC) PROFILE=$(PROFILE)

sbl_echo_test_clean_hs:
	$(MAKE) sbl_echo_test_clean

sbl_ethfw_hs:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl                    sbl_bootimage_hs   PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) ETHFW_PATH=$(ETHFW_PATH) BOARD=$(BOARD) SOC=$(SOC) PROFILE=$(PROFILE) BUILD_ETHFW=1

sbl_ethfw_clean_hs:
	$(MAKE) sbl_ethfw_clean

####################
# OSPI boot flashing
####################
sbl_echo_test_ospi_flashing:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl    sbl_bootimage_install_ospi   PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) BOARD=$(BOARD) SOC=$(SOC) SOC_MCU_PLUS=$(SOC_MCU_PLUS) PROFILE=$(PROFILE) BOARD_TYPE=$(BOARD_TYPE)

sbl_echo_test_ospi_flashing_hs:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl    sbl_bootimage_install_ospi   PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) BOARD=$(BOARD)_hs SOC=$(SOC) SOC_MCU_PLUS=$(SOC_MCU_PLUS) PROFILE=$(PROFILE) BOARD_TYPE=$(BOARD_TYPE) SBL_BOOTFILES_PATH=$(PSDK_QNX_PATH)/sbl_bootfiles/hs_signed

sbl_ethfw_ospi_flashing:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl    sbl_bootimage_install_ospi   PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) ETHFW_PATH=$(ETHFW_PATH) BOARD=$(BOARD) SOC=$(SOC) PROFILE=$(PROFILE) BUILD_ETHFW=1

sbl_ethfw_ospi_flashing_hs:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl    sbl_bootimage_install_ospi   PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) ETHFW_PATH=$(ETHFW_PATH) BOARD=$(BOARD)_hs SOC=$(SOC) PROFILE=$(PROFILE) BUILD_ETHFW=1 SBL_BOOTFILES_PATH=$(PSDK_QNX_PATH)/sbl_bootfiles/hs_signed


ifeq ($(SOC), $(filter $(SOC), am62x am62a))
sbl_echo_test_ospi_nand_flashing:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl    sbl_uniflash_ospi_nand   PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) BOARD=$(BOARD) SOC=$(SOC) SOC_MCU_PLUS=$(SOC_MCU_PLUS) PROFILE=$(PROFILE) BOARD_TYPE=$(BOARD_TYPE)

#####################
# eMMC boot flashing
#####################
sbl_echo_test_emmc_flashing:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl    sbl_uniflash_emmc   PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) BOARD=$(BOARD) SOC=$(SOC) SOC_MCU_PLUS=$(SOC_MCU_PLUS) PROFILE=$(PROFILE) BOARD_TYPE=$(BOARD_TYPE)

###################
# UART bootloader
###################
sbl_echo_test_uart_bootloader:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl   sbl_uart_bootloader    PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) BOARD=$(BOARD) SOC=$(SOC) SOC_MCU_PLUS=$(SOC_MCU_PLUS) PROFILE=$(PROFILE) BOARD_TYPE=$(BOARD_TYPE)
endif

####################
# sbl combined boot
####################
sbl_combined_boot_echo_test:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl_combined_boot      all   PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) BOARD=$(BOARD) SOC=$(SOC) PROFILE=$(PROFILE)

sbl_combined_boot_echo_test_clean:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl_combined_boot      clean PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) BOARD=$(BOARD) SOC=$(SOC) PROFILE=$(PROFILE)

sbl_combined_boot_ethfw:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl_combined_boot      all   PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) ETHFW_PATH=$(ETHFW_PATH) BOARD=$(BOARD) SOC=$(SOC) PROFILE=$(PROFILE) BUILD_ETHFW=1

sbl_combined_boot_ethfw_clean:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl_combined_boot      clean PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) ETHFW_PATH=$(ETHFW_PATH) BOARD=$(BOARD) SOC=$(SOC) PROFILE=$(PROFILE)  BUILD_ETHFW=1

################################################
# OSPI boot flashing of sbl combined boot image
################################################
sbl_combined_boot_echo_test_ospi_flashing:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl_combined_boot    sbl_combined_bootimage_install_ospi   PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) BOARD=$(BOARD) SOC=$(SOC) PROFILE=$(PROFILE)

sbl_combined_boot_ethfw_ospi_flashing:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/scripts/sbl_combined_boot    sbl_combined_bootimage_install_ospi   PSDK_RTOS_PATH=$(PSDK_RTOS_PATH) PDK_PATH=$(PDK_PATH) ETHFW_PATH=$(ETHFW_PATH) BOARD=$(BOARD) SOC=$(SOC) PROFILE=$(PROFILE) BUILD_ETHFW=1

####################
# qnx bsp
####################
bsp: qnx_bins examples utils
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/bsp all SOC=$(SOC) PROFILE=$(PROFILE)
	mkdir -p ${QNX_BOOT_PATH}
ifeq ($(SOC),$(filter $(SOC), j721e))
	cp -rfL ${PSDK_QNX_PATH}/qnx/bsp/images/ifs-j721e-evm-ti.raw                                        ${QNX_BOOT_PATH}/qnx-ifs
else ifeq ($(SOC),$(filter $(SOC), j7200))
	cp -rfL ${PSDK_QNX_PATH}/qnx/bsp/images/ifs-j7200-evm-ti.raw                                        ${QNX_BOOT_PATH}/qnx-ifs
else ifeq ($(SOC),$(filter $(SOC), j721s2))
	cp -rfL ${PSDK_QNX_PATH}/qnx/bsp/images/ifs-j721s2-magna-fca.raw                                    ${QNX_BOOT_PATH}/qnx-ifs
else ifeq ($(SOC),$(filter $(SOC), am62x))
	cp -rfL ${PSDK_QNX_PATH}/qnx/bsp/images/ifs-am62x-evm-ti.raw                                        ${QNX_BOOT_PATH}/qnx-ifs
else ifeq ($(SOC),$(filter $(SOC), am62a))
	cp -rfL ${PSDK_QNX_PATH}/qnx/bsp/images/ifs-am62a-evm-ti.raw                                        ${QNX_BOOT_PATH}/qnx-ifs
else ifeq ($(SOC),$(filter $(SOC), j784s4))
	cp -rfL ${PSDK_QNX_PATH}/qnx/bsp/images/ifs-j784s4-evm-ti.raw                                       ${QNX_BOOT_PATH}/qnx-ifs
endif

bsp_clean:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/bsp SOC=$(SOC) PROFILE=$(PROFILE) clean 

####################
# qnx pdk libs
####################
ifeq ($(PROFILE), $(filter $(PROFILE),debug all))
qnx_libs: qnx_libs_debug
endif
ifeq ($(PROFILE), $(filter $(PROFILE),release all))
qnx_libs: qnx_libs_release
endif
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/pdk_libs/pdk                   PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/pdk_libs/sciclient             PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/pdk_libs/ipclld                PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/pdk_libs/udmalld               PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/pdk_libs/enetlld               PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
ifeq ($(SOC),$(filter $(SOC), am62a))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/pdk_libs/csirxlld              PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/pdk_libs/fvid2lld              PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
endif

	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/sharedmemallocator/usr         PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) VISION_APPS_BUILD_FLAGS_MAK=$(VISION_APPS_BUILD_FLAGS_MAK)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/resmgr/ipc_qnx_rsmgr/usr       PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/resmgr/udma_qnx_rsmgr/usr      PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)

qnx_libs_debug:
	$(MAKE) -C $(PDK_QNX_PATH)/packages/ti/build                   pdk_libs        PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages BUILD_OS_TYPE=qnx CORE=qnx_mpu1_0 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=debug -s

qnx_libs_release:
	$(MAKE) -C $(PDK_QNX_PATH)/packages/ti/build                   pdk_libs        PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages BUILD_OS_TYPE=qnx CORE=qnx_mpu1_0 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=release -s

ifeq ($(PROFILE), $(filter $(PROFILE),debug all))
qnx_libs_clean: qnx_libs_debug_clean
endif
ifeq ($(PROFILE), $(filter $(PROFILE),release all))
qnx_libs_clean: qnx_libs_release_clean
endif
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/pdk_libs/pdk            clean  PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/pdk_libs/sciclient      clean  PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/pdk_libs/ipclld         clean  PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/pdk_libs/udmalld        clean  PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/pdk_libs/enetlld        clean  PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
ifeq ($(SOC),$(filter $(SOC), am62a))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/pdk_libs/csirxlld       clean  PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/pdk_libs/fvid2lld       clean  PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
endif
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/sharedmemallocator/usr    clean  PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) VISION_APPS_BUILD_FLAGS_MAK=$(VISION_APPS_BUILD_FLAGS_MAK)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/resmgr/ipc_qnx_rsmgr/usr  clean PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/resmgr/udma_qnx_rsmgr/usr clean PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)

qnx_libs_debug_clean:
	$(MAKE) -C $(PDK_QNX_PATH)/packages/ti/build                   pdk_libs_clean  PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages BUILD_OS_TYPE=qnx CORE=qnx_mpu1_0 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=debug -s

qnx_libs_release_clean:
	$(MAKE) -C $(PDK_QNX_PATH)/packages/ti/build                   pdk_libs_clean  PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages BUILD_OS_TYPE=qnx CORE=qnx_mpu1_0 BOARD=$(BOARD) SOC=$(SOC) BUILD_PROFILE=release -s

qnx_libs_scrub:
	$(MAKE) -C $(PDK_QNX_PATH)/packages/ti/build                   allclean        PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages

####################
# qnx bins
####################
qnx_bins: qnx_libs
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/sharedmemallocator/resmgr              PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) VISION_APPS_BUILD_FLAGS_MAK=$(VISION_APPS_BUILD_FLAGS_MAK)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/sharedmemallocator/samples             PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) VISION_APPS_BUILD_FLAGS_MAK=$(VISION_APPS_BUILD_FLAGS_MAK)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/resmgr/sciclient_qnx_rsmgr             PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/resmgr/ipc_qnx_rsmgr/resmgr            PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/resmgr/ipc_qnx_ipcmgr/ipcmgr           PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/resmgr/udma_qnx_rsmgr/resmgr           PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
ifeq ($(SOC),$(filter $(SOC), j721e j7200 j721s2 j784s4))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp/cpsw2g                           PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
endif
ifeq ($(SOC),$(filter $(SOC), j721e j784s4))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp/ethremotecfg                     PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) ETHFW_PATH=$(PSDK_QNX_PATH)/../ethfw REMOTE_DEVICE_PATH=$(PSDK_QNX_PATH)/../remote_device
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp/remote_device                    PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) REMOTE_DEVICE_PATH=$(PSDK_QNX_PATH)/../remote_device
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp/cpsw9g                           PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) ETHFW_PATH=$(PSDK_QNX_PATH)/../ethfw REMOTE_DEVICE_PATH=$(PSDK_QNX_PATH)/../remote_device
endif
ifeq ($(SOC),$(filter $(SOC), j7200))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp/ethremotecfg                     PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) ETHFW_PATH=$(PSDK_QNX_PATH)/../ethfw REMOTE_DEVICE_PATH=$(PSDK_QNX_PATH)/../remote_device
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp/remote_device                    PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) REMOTE_DEVICE_PATH=$(PSDK_QNX_PATH)/../remote_device
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp/cpsw5g                           PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) ETHFW_PATH=$(PSDK_QNX_PATH)/../ethfw REMOTE_DEVICE_PATH=$(PSDK_QNX_PATH)/../remote_device
endif
ifeq ($(SOC),$(filter $(SOC), j721s2))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp/cpsw2g-main                      PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
endif

qnx_bins_clean:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/sharedmemallocator/resmgr              clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/sharedmemallocator/samples             clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/resmgr/sciclient_qnx_rsmgr             clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/resmgr/ipc_qnx_rsmgr/resmgr            clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/resmgr/ipc_qnx_ipcmgr/ipcmgr           clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/resmgr/udma_qnx_rsmgr/resmgr           clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp                                  clean
ifeq ($(SOC),$(filter $(SOC), j721e))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp/ethremotecfg                     clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp/remote_device                    clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp/cpsw9g                           clean
else ifeq ($(SOC),$(filter $(SOC), j7200))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp/ethremotecfg                     clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp/remote_device                    clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp/cpsw5g                           clean
else ifeq ($(SOC),$(filter $(SOC), j721s2))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/devnp/cpsw2g-main                      clean
endif

####################
# qnx codec
####################
qnx_codec: qnx_libs
ifeq ($(SOC),$(filter $(SOC), j721e))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/img/qnx                  PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PSDK_QNX_PATH=$(PSDK_QNX_PATH) PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
endif
ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/vpulib    PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgrlib            PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgr               PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL            PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
endif

qnx_codec_clean:
ifeq ($(SOC),$(filter $(SOC), j721e))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/img/qnx                  PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PSDK_QNX_PATH=$(PSDK_QNX_PATH) clean
endif
ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/vpulib    PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL            PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgrlib            PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgr               PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages clean
endif

####################
# qnx examples
####################
examples: qnx_bins
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/ipc/ipc_test_qnx              PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/udma/udma_memcpy_test_qnx     PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/sciclient/sciclient_qnx_app   PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/osal/sem_test                 PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/cpsw/ptp_test                 PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/gpio                          PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/crypto/decrypt_app            PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
ifeq ($(SOC),$(filter $(SOC), am62a))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/csirx/csirx_capture_test_qnx  PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
endif

ifeq ($(SOC),$(filter $(SOC), j721e j7200 j721s2 j784s4))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/cpsw/cpsw_test                PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID)
endif

examples_clean:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/ipc/ipc_test_qnx              clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/udma/udma_memcpy_test_qnx     clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/sciclient/sciclient_qnx_app   clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/osal/sem_test                 clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/cpsw/ptp_test                 clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/gpio                          clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/crypto/decrypt_app            clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/cpsw/cpsw_test                clean
ifeq ($(SOC),$(filter $(SOC), am62a))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/examples/csirx/csirx_capture_test_qnx  clean
endif

####################
# qnx codec tests
####################
qnx_codec_tests: qnx_codec
ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/vpu/tests/decoder_test            PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/vpu/tests/encoder_test            PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/vpu/tests/multi_inst_test         PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)
endif

qnx_codec_tests_clean:
ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4))
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/vpu/tests/decoder_test            clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/vpu/tests/encoder_test            clean
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/codec/vpu/tests/multi_inst_test         clean
endif

####################
# qnx utils
####################
utils: qnx_bins
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/utils/k3conf                           -f Makefile_qnx PDK_INSTALL_PATH=$(PDK_QNX_PATH)/packages PROFILE=$(PROFILE) BOARD=$(BOARD) SOC=$(SOC) PSDK_QNX_VERSION_REL=$(PSDK_QNX_VERSION_REL) PSDK_QNX_TAGID=$(PSDK_QNX_TAGID) PSDK_QNX_USE_DSO=$(PSDK_QNX_USE_DSO)

utils_clean:
	$(MAKE) -C $(PSDK_QNX_PATH)/qnx/utils/k3conf                           -f Makefile_qnx clean

####################
# qnx automated packaging
####################
ifeq ($(SOC),$(filter $(SOC), j7200 j721e j721s2 j784s4))
qnx_spl_create_copy:
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/scripts/automation/qnx_automation.mak   spl_create_copy

qnx_sbl_ethfw_create_copy:
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/scripts/automation/qnx_automation.mak   sbl_ethfw_create_copy

qnx_sbl_ethfw_hs_create_copy:
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/scripts/automation/qnx_automation.mak   sbl_ethfw_hs_create_copy

qnx_sbl_echo_create_copy:
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/scripts/automation/qnx_automation.mak   sbl_echo_create_copy

qnx_sbl_echo_hs_create_copy:
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/scripts/automation/qnx_automation.mak   sbl_echo_hs_create_copy

qnx_create_all_platform_packages:
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/scripts/automation/qnx_automation.mak   create_all_platform_packages
endif
