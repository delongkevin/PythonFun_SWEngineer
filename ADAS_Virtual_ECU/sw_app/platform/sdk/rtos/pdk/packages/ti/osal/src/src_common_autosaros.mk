
SRCDIR += . src/autosaros arch/core
SRCDIR += arch/core/r5
SRCDIR += soc/$(SOC)
INCDIR += . src/autosaros  $(fisker_hydra_PATH)/platform/asr/app_sip/Os/Implementation $(fisker_hydra_PATH)/platform/asr/app_sip/Common/Implementation
INCDIR += $(fisker_hydra_PATH)/mcu1_0/app/os
INCDIR += $(fisker_hydra_PATH)/mcu1_0/app/boot
INCDIR += $(fisker_hydra_PATH)/platform/asr/app_sip/os
INCDIR += $(fisker_hydra_PATH)/platform/asr/app_sip/GenData/mcu1_0/




SRCS_COMMON += delay.c HwiP_autosaros.c CycleprofilerP_autosaros.c RegisterIntr_autosaros.c EventCombinerP_autosaros.c DebugP_autosaros.c TimerP_autosaros.c
SRCS_COMMON += CacheP_nonos.c SemaphoreP_autosaros.c Utils_autosaros.c Arch_util.c TimerP_default.c 

SRCS_ASM_COMMON += TimestampProvider_asm.asm

INCLUDE_EXTERNAL_INTERFACES = os

PACKAGE_SRCS_COMMON = makefile HwiP.h SwiP.h osal.h osal_component.mk CycleprofilerP.h \
                      EventCombinerP.h RegisterIntr.h TimerP.h CacheP.h DebugP.h soc/$(SOC) soc/osal_soc.h \
                      src/autosaros/CycleprofilerP_autosaros.c src/autosaros/EventCombinerP_autosaros.c \
                      src/autosaros/HwiP_autosaros.c \
                      src/autosaros/RegisterIntr_autosaros.c \
                      src/autosaros/TimerP_autosaros.c src/autosaros/DebugP_autosaros.c src/autosaros/autosaros_config.h src/src_common_autosaros.mk

PACKAGE_SRCS_COMMON += arch/core/r5 SemaphoreP.h

