##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************
## $Id: toolchain_hydra3_linux.cmake 1.0 2020/09/14 21:43:51EDT Grigory Kletkso draft  $
##********************************************************************************************

set(CMAKE_SYSTEM_NAME QNX)
set(CMAKE_SYSTEM_VERSION 7.1.0)                                     # QNX OS Version
set(arch gcc_ntoaarch64le)
set(CMAKE_SYSTEM_PROCESSOR aarch64-unknown-nto-qnx7.1.0)
set(QNX_ARCH aarch64le)

set(CMAKE_STATIC_LIBRARY_PREFIX "lib")
set(CMAKE_STATIC_LIBRARY_SUFFIX ".a")

#set(PSDK_INC_PATH "/opt/magna/hydra3_qnx/psdk/ti-processor-sdk-rtos-j721e-evm-07_03_00_07/psdkqa/pdk/packages")
#set(ENV{PSDK_LIB_PATH} "/opt/magna/hydra3_qnx/psdk/ti-processor-sdk-rtos-j721e-evm-07_03_00_07/psdkqa/bootfs/tilib")
#set(PSDK_INC_PATH "~/prjtools/ti-processor-sdk-rtos-j721s2-evm-08_05_00_11/psdkqa/pdk/packages")
#set(ENV{PSDK_LIB_PATH} "~/prjtools/ti-processor-sdk-rtos-j721s2-evm-08_05_00_11/psdkqa/bootfs/tilib")
set(ME_PSDK_PATH $ENV{ME_SDK_INSTALL_PATH})
set(PSDK_PATH ${ME_PSDK_PATH})
set(PSDK_INC_PATH "${PSDK_PATH}/psdkqa/pdk/packages")
set(PSDK_LIB_PATH "${PSDK_PATH}/psdkqa/bootfs/tilib")
set(TIOVX_INC_PATH
  "${PSDK_PATH}/tiovx/include"
  "${PSDK_PATH}/tiovx/kernels_j7/include"
  "${PSDK_PATH}/tiovx/kernels/include"
  "${PSDK_PATH}/imaging/kernels/include"
  "${PSDK_PATH}/imaging"
  "${PSDK_PATH}/imaging/sensor_drv/include"
  "${PSDK_PATH}/vision_apps"
  "${PSDK_PATH}/vision_apps/utils/app_init/include"
  "${PSDK_PATH}/vision_apps/apps/basic_demos/app_tirtos/tirtos_qnx/mpu1"
)


FIND_PATH(QNX_HOST
  NAME usr/bin/qcc
  PATHS $ENV{QNX_HOST} "~/qnx710/host/linux/x86_64"
  NO_CMAKE_PATH
  NO_CMAKE_ENVIRONMENT_PATH
)
 
FIND_PATH(QNX_TARGET
  NAME usr/include/stdio.h
  PATHS $ENV{QNX_TARGET} "~/qnx710/target/qnx7"
  NO_CMAKE_PATH
  NO_CMAKE_ENVIRONMENT_PATH
)

set(ENV{QNX_HOST} ${QNX_HOST})
set(ENV{QNX_TARGET} ${QNX_TARGET})
set(ENV{PATH} "${QNX_HOST}/usr/bin;$ENV{PATH}")

set(CMAKE_MAKE_PROGRAM "/usr/bin/make"    CACHE PATH "Host Make Program")
set(CMAKE_SH           "/usr/bin/sh"      CACHE PATH "Host shell Program")
set(CMAKE_AR           "${QNX_HOST}/usr/bin/aarch64-unknown-nto-qnx7.1.0-ar"       CACHE PATH "GCC ar Program")
set(CMAKE_RANLIB       "${QNX_HOST}/usr/bin/aarch64-unknown-nto-qnx7.1.0-ranlib"   CACHE PATH "GCC ranlib Program")
set(CMAKE_NM           "${QNX_HOST}/usr/bin/aarch64-unknown-nto-qnx7.1.0-nm"       CACHE PATH "GCC nm Program")
set(CMAKE_OBJCOPY      "${QNX_HOST}/usr/bin/aarch64-unknown-nto-qnx7.1.0-objcopy"  CACHE PATH "GCC objcopy Program")
set(CMAKE_OBJDUMP      "${QNX_HOST}/usr/bin/aarch64-unknown-nto-qnx7.1.0-objdump"  CACHE PATH "GCC objdump Program")
set(CMAKE_LINKER       "${QNX_HOST}/usr/bin/aarch64-unknown-nto-qnx7.1.0-ld"       CACHE PATH "GCC Linker Program")
set(CMAKE_STRIP        "${QNX_HOST}/usr/bin/aarch64-unknown-nto-qnx7.1.0-strip"    CACHE PATH "GCC Strip Program")
#set(CMAKE_C_COMPILER   "${QNX_HOST}/usr/bin/aarch64-unknown-nto-qnx7.1.0-qcc")
#set(CMAKE_CXX_COMPILER "${QNX_HOST}/usr/bin/aarch64-unknown-nto-qnx7.1.0-g++")

set(CMAKE_C_COMPILER    "${QNX_HOST}/usr/bin/qcc")
set(CMAKE_CXX_COMPILER  "${QNX_HOST}/usr/bin/qcc")

set(CMAKE_C_COMPILER_TARGET ${arch})
set(CMAKE_CXX_COMPILER_TARGET ${arch})

set(CMAKE_FIND_ROOT_PATH  "${QNX_HOST}" "${QNX_TARGET}")
# search headers and libraries in the target environment, search
# programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set( CMAKE_C_FLAGS $ENV{CFLAGS} -DSOC_J721S2 CACHE STRING "" FORCE )
set( CMAKE_CXX_FLAGS $ENV{CXXFLAGS} -DSOC_J721S2 CACHE STRING "" FORCE )
set( CMAKE_ASM_FLAGS ${CMAKE_C_FLAGS} CACHE STRING "" FORCE )
set( CMAKE_LDFLAGS_FLAGS ${CMAKE_CXX_FLAGS} CACHE STRING "" FORCE )
#set( CMAKE_SYSROOT ${HYDRA_TARGET_SYSROOT} )

include_directories( ${PSDK_INC_PATH} ${TIOVX_INC_PATH})

