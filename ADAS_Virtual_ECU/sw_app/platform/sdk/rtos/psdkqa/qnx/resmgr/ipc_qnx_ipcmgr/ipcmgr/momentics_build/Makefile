ARTIFACT = ipcmgr

#Build architecture/variant string, possible values: x86, armv7le, etc...
PLATFORM ?= aarch64le

#Build profile, possible values: release, debug, profile, coverage
BUILD_PROFILE ?= debug

CONFIG_NAME ?= $(PLATFORM)-$(BUILD_PROFILE)
OUTPUT_DIR = build/$(CONFIG_NAME)
TARGET = $(OUTPUT_DIR)/$(ARTIFACT)

QNX_SDP_VERSION = 710
SOC = j721s2
BOARD = j721s2_hyd
PSDK_QNX_VERSION_REL = PSDKQNX_08_05_00_06
PSDK_QNX_TAGID ?= QNX$(QNX_SDP_VERSION)_$(BOARD)

#Compiler definitions

CC = qcc -Vgcc_nto$(PLATFORM)
#CXX = q++ -Vgcc_nto$(PLATFORM)_cxx
LD = $(CC)

IPC_PATH = ./../src
QNX_HOST = /home/user0/qnx710/host/linux/x86_64
#Add extra include path
PDK_INSTALL_PATH += $(IPC_PATH)/../../../../../pdk/packages
PDK_QNX_PATH   +=  $(IPC_PATH)/../../../../../pdk
VISION_APP_PATH += $(IPC_PATH)/../../../../../../vision_apps
PSDK_QNX_PATH += $(IPC_PATH)/../../../../../qnx/
RSMGR_IPC_QNX_PATH += $(IPC_PATH)/../../../../../qnx/resmgr/ipc_qnx_rsmgr/usr
RSMGR_QNX_PATH = $(RSMGR_IPC_QNX_PATH)/../../../../pdk

$(info $(PWD))

INCLUDES += -I$(PDK_QNX_PATH)/packages
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/ipc_manager/inc
INCLUDES += -I$(ME_REPO_ROOT)/sw/ookshelf/ipc_manager/inc
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/ipc_manager/cfg
INCLUDES += -I$(PROJECT_ROOT)/src/qnx_inc
INCLUDES += -I$(PROJECT_ROOT)/sw/bookshelf/magna_apps/AutoPark/Include/
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/magna_apps/AutoPark/Include/
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/includes/
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/SignalMgr/gen/
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/SignalMgr/inc/
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/SSM/inc
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/SSM/cfg
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/includes
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/magna_apps
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/magna_apps/
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/apa
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/apa/common
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/apa/fpa
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/cd
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/common
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/hsf
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/lsf
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/mecl
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/CalDataProvider/inc/
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/ErrorManager/gen/
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/ErrorManager/inc/
INCLUDES += -I$(ME_REPO_ROOT)/sw/bookshelf/ErrorManager/cfg/
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/common_includes
INCLUDES += -I$(ME_BOOKSHELF_PATH)/magna_apps/trsc/algo/_sharedutils
INCLUDES += -I$(ME_BOOKSHELF_PATH)/magna_apps/trsc/code
INCLUDES += -I$(ME_BOOKSHELF_PATH)/magna_apps/apfusion/common
INCLUDES += -I$(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/_sharedutils
INCLUDES += -I$(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/common/inc
INCLUDES += -I$(ME_BOOKSHELF_PATH)/magna_apps/tha_sm_vc/algo/_sharedutils
INCLUDES += -I$(ME_BOOKSHELF_PATH)/magna_apps/tha_sm_vc/algo/common
INCLUDES += -I${PSDK_RTOS_PATH}/vision_apps/platform/j721s2/qnx


CCFLAG1 += -DBUILD_MPU1_0=1 -DBUILD_MCUQNX=1 -DDEBUG_INFO=1
CCFLAGS_all += -DSOC_J721E=1
CCOPTS += -fPIC
CCOPTS += -DBUILD_MPU1_0 -DIPC_SUPPORT_SCICLIENT -DQNX_OS=1
CCOPTS += -DVISION_APPS_BUILD_FLAGS_MAK=$(VISION_APPS_BUILD_FLAGS_MAK)
LIBS       += -L$(QNX_HOST)/usr/lib

#EXTRA_LIBVPATH += $(PDK_QNX_PATH)/../qnx/resmgr/ipc_qnx_rsmgr/usr/aarch64/a.le/
#EXTRA_LIBVPATH += $(PDK_QNX_PATH)/packages/ti/drv/ipc/lib/$(SOC)/qnx_mpu1_0/$(BUILD_PROFILE)/
EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/resmgr/ipc_qnx_rsmgr/usr/aarch64/a.le/
EXTRA_LIBVPATH += $(PDK_QNX_PATH)/packages/ti/osal/lib/qnx/$(SOC)/qnx_a72/$(BUILD_PROFILE)/
EXTRA_LIBVPATH += $(PDK_QNX_PATH)/packages/ti/drv/sciclient/lib/$(SOC)/qnx_mpu1_0/$(BUILD_PROFILE)/
EXTRA_LIBVPATH += $(PDK_QNX_PATH)/packages/ti/csl/lib/$(SOC)/qnx_a72/$(BUILD_PROFILE)/
EXTRA_LIBVPATH += $(PDK_QNX_PATH)/packages/ti/csl/lib/$(BOOTMODE)/$(SOC)/qnx_a72/$(BUILD_PROFILE)/
#EXTRA_LIBVPATH += $(PDK_QNX_PATH)/ti/board/lib/$(BOARD)/a72/$(BUILD_PROFILE)/
EXTRA_LIBVPATH += $(PDK_QNX_PATH)/packages/ti/board/lib/$(BOOTMODE)/$(BOARD)/qnx_a72/$(BUILD_PROFILE)/
EXTRA_LIBVPATH += ${PSDK_RTOS_PATH}/vision_apps/lib/J721S2/A72/QNX/release/
EXTRA_LIBVPATH += ${PSDK_RTOS_PATH}/vision_apps/out/J721S2/A72/QNX/release/
EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/sharedmemallocator/usr/aarch64/a.le/

LIBS +=-Lti.osal.aa72fg
LIBS +=-Lti.csl.aa72fg
LIBS +=-Lsciclient.aa72fg
LIBS +=-Lti.csl.aa72fg
LIBS +=-Lti.osal.aa72fg
LIBS +=-Lti.board.aa72fg
LIBS +=-Llibtiipc-usr.a

#Add source path
LIBS       += -L$(PSDK_QNX_PATH)/qnx/resmgr/ipc_qnx_rsmgr/usr/aarch64/a.le/



#$(info $(EXTRA_LIBVPATH))
#Compiler flags for build profiles
CCFLAGS_release += -O2
CCFLAGS_debug += -g -O0 -fno-builtin
CCFLAGS_coverage += -g -O0 -ftest-coverage -fprofile-arcs -nopipe -Wc,-auxbase-strip,$@
LDFLAGS_coverage += -ftest-coverage -fprofile-arcs
CCFLAGS_profile += -g -O0 -finstrument-functions
LIBS_profile += -lprofilingS

#Generic compiler flags (which include build type flags)
CCFLAGS_all += -Wall -fmessage-length=0 
CCFLAGS_all += $(CCFLAGS_$(BUILD_PROFILE)) 
#Shared library has to be compiled with -fPIC
#CCFLAGS_all += -fPIC
LDFLAGS_all += $(LDFLAGS_$(BUILD_PROFILE)) 
LIBS_all += $(LIBS_$(BUILD_PROFILE)) 
DEPS = -Wp,-MMD,$(@:%.o=%.d),-MT,$@
LIBPREF_libapp_utils_console_io.a = -Bstatic

#Macro to expand files recursively: parameters $1 -  directory, $2 - extension, i.e. cpp
rwildcard = $(wildcard $(addprefix $1/*.,$2)) $(foreach d,$(wildcard $1/*),$(call rwildcard,$d,$2))

#Source list
SRCS += $(call rwildcard, $(IPC_PATH)/os, c)
SRCS += $(call rwildcard, $(IPC_PATH)/ipc_manager/src, c)


#Object files list
OBJS = $(addprefix $(OUTPUT_DIR)/,$(addsuffix .o, $(basename $(SRCS))))

#Compiling rule
$(OUTPUT_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$ make -C $(PSDK_QNX_PATH)/ ipc_libs_release
	$ make -C $(PSDK_QNX_PATH)/ resmgr_a72
	$(CC) -c $(DEPS) -o $@ $(INCLUDES) $(CCFLAGS_all) $(CCFLAGS) $(CCFLAG1) $<

#Linking rule
$(TARGET):$(OBJS)
	$(LD) -o $(TARGET) $(LDFLAGS_all) $(LDFLAGS) $(OBJS) $(EXTRA_LIBVPATH2)/libtiipc-usr.a -lm $(LIBS_all) $(LIBS) $(EXTRA_LIBVPATH1)/libapp_utils_console_io.a -lm -Bstatic $(EXTRA_LIBVPATH3)/sciclient.aa72fg -lm -Bstatic $(EXTRA_LIBVPATH4)/ti.osal.aa72fg -lm -Bstatic $(EXTRA_LIBVPATH5)/ti.csl.aa72fg -lm 
#Rules section for default compilation and linking
all: $(TARGET)

clean:
	rm -fr $(OUTPUT_DIR)
	$ make -C $(PSDK_QNX_PATH)/ ipc_libs_release_clean
	

rebuild: clean all

#Inclusion of dependencies (object files to source and includes)
-include $(OBJS:%.o=%.d)