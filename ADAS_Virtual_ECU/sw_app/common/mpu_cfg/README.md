# sw/common/mpu_cfg Directory

The contents in this directory are temporary and used as a workaround to allow
the mcu2_0 application to build. The mcu2_0 build is anable to link against
files that are in absolute paths (hence, it's not possible to add the
"sw/common/mpu_cfg/j721s2_mpu_cfg.c" file from it's original location under

    $(ME_VISION_APPS_PATH)/platform/$(SOC)/rtos/common/mpu_cfg/$(SOC)_mpu_cfg.c
