#
# Utility makefile to build u-boot with MCU1_0 image
#
# Edit this file to suit your specific build needs
#

ifeq ($(PROFILE), $(filter $(PROFILE),debug all))
UBOOT_APP_PROFILE=debug
endif
ifeq ($(PROFILE), $(filter $(PROFILE),release all))
UBOOT_APP_PROFILE=release
endif

ATF_OPTEE_PATH=$(VISION_APPS_PATH)/out/sbl_bootfiles/atf_optee_dir

VISION_APPS_LINUX_DM=$(VISION_APPS_PATH)/out/$(TARGET_SOC)/R5F/$(RTOS)/$(UBOOT_APP_PROFILE)/vx_app_rtos_linux_mcu1_0.out
VISION_APPS_LINUX_DM_STRIP=$(VISION_APPS_PATH)/out/$(TARGET_SOC)/R5F/$(RTOS)/$(UBOOT_APP_PROFILE)/vx_app_rtos_linux_mcu1_0_strip.out
# VISION_APPS_LINUX_DM=$(VISION_APPS_PATH)/out/$(TARGET_SOC)/R5F/$(RTOS)/$(UBOOT_APP_PROFILE)/can_gw_diag.out
# VISION_APPS_LINUX_DM_STRIP=$(VISION_APPS_PATH)/out/$(TARGET_SOC)/R5F/$(RTOS)/$(UBOOT_APP_PROFILE)/can_gw_diag_strip.out

VISION_APPS_QNX_DM=$(VISION_APPS_PATH)/out/$(TARGET_SOC)/R5F/$(RTOS)/$(UBOOT_APP_PROFILE)/vx_app_rtos_qnx_mcu1_0.out
VISION_APPS_QNX_DM_STRIP=$(VISION_APPS_PATH)/out/$(TARGET_SOC)/R5F/$(RTOS)/$(UBOOT_APP_PROFILE)/vx_app_rtos_qnx_mcu1_0_strip.out
# VISION_APPS_QNX_DM=$(VISION_APPS_PATH)/out/$(TARGET_SOC)/R5F/$(RTOS)/$(UBOOT_APP_PROFILE)/can_gw_diag.out
# VISION_APPS_QNX_DM_STRIP=$(VISION_APPS_PATH)/out/$(TARGET_SOC)/R5F/$(RTOS)/$(UBOOT_APP_PROFILE)/can_gw_diag_strip.out

uboot_check:
ifeq ($(BUILD_TARGET_MODE),yes)
	@if [ ! -d $(PSDK_LINUX_PATH) ]; then echo 'ERROR: $(PSDK_LINUX_PATH) not found !!!'; exit 1; fi
	@if [ ! -d $(PSDK_LINUX_PATH)/board-support/u-boot-* ]; then echo 'ERROR: $(PSDK_LINUX_PATH)/board-support/u-boot-* not found !!!'; exit 1; fi
	@if [ ! -f $(ATF_OPTEE_PATH)/bl31.bin ]; then echo 'ERROR: $(ATF_OPTEE_PATH)/bl31.bin not found !!! Plase run make sbl_atf_optee first'; exit 1; fi
	@if [ ! -f $(ATF_OPTEE_PATH)/bl32.bin ]; then echo 'ERROR: $(ATF_OPTEE_PATH)/bl32.bin not found !!! Plase run make sbl_atf_optee first'; exit 1; fi
endif

uboot_check_firmware:
ifeq ($(BUILD_TARGET_MODE),yes)
ifeq ($(BUILD_LINUX_A72),yes)
	@if [ ! -f  $(VISION_APPS_LINUX_DM) ]; then echo 'ERROR: $(VISION_APPS_LINUX_DM) not found !!!'; exit 1; fi
endif
ifeq ($(BUILD_QNX_A72),yes)
	@if [ ! -f $(VISION_APPS_QNX_DM) ]; then echo 'ERROR: $(VISION_APPS_QNX_DM) !!!'; exit 1; fi
endif
endif

uboot_clean:
ifeq ($(BUILD_TARGET_MODE),yes)
	$(MAKE) -C $(PSDK_LINUX_PATH)/board-support/u-boot-* clean
	$(MAKE) -C $(PSDK_LINUX_PATH) u-boot-r5_clean
	rm -rf $(PSDK_LINUX_PATH)/board-support/u-boot-*/$(SOC)-arm64-linux/
	rm -rf $(PSDK_LINUX_PATH)/board-support/u-boot-*/$(SOC)-arm64-qnx/
	rm -rf $(PSDK_LINUX_PATH)/board-support/u-boot_build/r5/
endif

uboot: uboot_check uboot_check_firmware
ifeq ($(BUILD_TARGET_MODE),yes)
ifeq ($(BUILD_LINUX_A72),yes)
	cp $(VISION_APPS_LINUX_DM) $(VISION_APPS_LINUX_DM_STRIP)
	$(TIARMCGT_LLVM_ROOT)/bin/tiarmstrip -p $(VISION_APPS_LINUX_DM_STRIP)
ifeq  ($(SOC), am62a)
	$(MAKE) -C $(PSDK_LINUX_PATH)/board-support/u-boot-* ARCH=arm CROSS_COMPILE=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- O=$(SOC)-arm64-linux -j8 $(SOC)x_evm_a53_defconfig
else
	$(MAKE) -C $(PSDK_LINUX_PATH)/board-support/u-boot-* ARCH=arm CROSS_COMPILE=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- O=$(SOC)-arm64-linux -j8 $(SOC)_evm_a72_defconfig
endif
	$(MAKE) -C $(PSDK_LINUX_PATH)/board-support/u-boot-* ARCH=arm CROSS_COMPILE=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- ATF=$(ATF_OPTEE_PATH)/bl31.bin TEE=$(ATF_OPTEE_PATH)/bl32.bin DM=$(VISION_APPS_LINUX_DM_STRIP) O=$(SOC)-arm64-linux
endif
ifeq ($(BUILD_QNX_A72),yes)
	cp $(VISION_APPS_QNX_DM) $(VISION_APPS_QNX_DM_STRIP)
	$(TIARMCGT_LLVM_ROOT)/bin/tiarmstrip -p $(VISION_APPS_QNX_DM_STRIP)
ifeq  ($(SOC), am62a)
	$(MAKE) -C $(PSDK_LINUX_PATH)/board-support/u-boot-* ARCH=arm CROSS_COMPILE=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- O=$(SOC)-arm64-qnx -j8 $(SOC)x_evm_a53_defconfig
else
	$(MAKE) -C $(PSDK_LINUX_PATH)/board-support/u-boot-* ARCH=arm CROSS_COMPILE=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- O=$(SOC)-arm64-qnx -j8 $(SOC)_evm_a72_defconfig
endif
	$(MAKE) -C $(PSDK_LINUX_PATH)/board-support/u-boot-* ARCH=arm CROSS_COMPILE=$(GCC_LINUX_ARM_ROOT)/bin/aarch64-none-linux-gnu- ATF=$(ATF_OPTEE_PATH)/bl31.bin TEE=$(ATF_OPTEE_PATH)/bl32.bin DM=$(VISION_APPS_QNX_DM_STRIP) O=$(SOC)-arm64-qnx
endif
	$(MAKE) -C $(PSDK_LINUX_PATH) u-boot-r5
endif

uboot_linux_install_sd: uboot_check
ifeq ($(BUILD_TARGET_MODE),yes)
	cp $(PSDK_LINUX_PATH)/board-support/u-boot-*/$(SOC)-arm64-linux/tispl.bin $(LINUX_SD_FS_BOOT_PATH)/
	cp $(PSDK_LINUX_PATH)/board-support/u-boot-*/$(SOC)-arm64-linux/u-boot.img $(LINUX_SD_FS_BOOT_PATH)/
	sync
endif

uboot_qnx_install_sd: uboot_check
ifeq ($(BUILD_TARGET_MODE),yes)
	cp $(PSDK_LINUX_PATH)/board-support/u-boot-*/$(SOC)-arm64-qnx/tispl.bin $(QNX_SD_FS_BOOT_PATH)/
	cp $(PSDK_LINUX_PATH)/board-support/u-boot-*/$(SOC)-arm64-qnx/u-boot.img $(QNX_SD_FS_BOOT_PATH)/
	cp $(PSDK_LINUX_PATH)/board-support/k3-image-gen-*/tiboot3.bin $(QNX_SD_FS_BOOT_PATH)/
	cp $(PSDK_LINUX_PATH)/board-support/k3-image-gen-*/sysfw.itb $(QNX_SD_FS_BOOT_PATH)/
	sync
endif

uboot_qnx_install: uboot_check
ifeq ($(BUILD_TARGET_MODE),yes)
	cp $(PSDK_LINUX_PATH)/board-support/u-boot-*/j721s2-arm64-qnx/tispl.bin $(QNX_FS_PATH)/
	cp $(PSDK_LINUX_PATH)/board-support/u-boot-*/j721s2-arm64-qnx/u-boot.img $(QNX_FS_PATH)/
	cp $(PSDK_LINUX_PATH)/board-support/k3-image-gen-*/tiboot3.bin $(QNX_FS_PATH)/
	# Actually this is not u-boot, but let it be here...
	# Use prebuilded
	cp $(PSDK_LINUX_PATH)/board-support/k3-image-gen-*/sysfw.itb $(QNX_FS_PATH)/
	sync
endif

.PHONY: uboot_check uboot_check_firmware uboot_clean uboot uboot_linux_install_sd uboot_qnx_install_sd uboot_qnx_install
