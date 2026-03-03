##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************
## $Id: toolchain_hydra3_linux.cmake 1.0 2020/09/14 21:43:51EDT Grigory Kletkso draft  $
##********************************************************************************************
set( CMAKE_SYSTEM_NAME Linux )
set( arch aarch64-linux )

set(PSDK_PATH "/opt/magna/hydra/build/psdk_rtos_auto_j7_07_00_00_11/" CACHE PATH "PSDK Path")

#set(CMAKE_IMPORT_LIBRARY_SUFFIX ".a")
#set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
#set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
set(CMAKE_STATIC_LIBRARY_PREFIX "lib")
set(CMAKE_STATIC_LIBRARY_SUFFIX ".a")

set(GCC_LINUX_ARM_ROOT "${PSDK_PATH}/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu" CACHE PATH "GCC Toolchain path")

set(HYDRA_TARGET_SYSROOT "${PSDK_PATH}/targetfs" CACHE PATH "Target filesystem path")
set(ENV{PATH} "${HYDRA_TARGET_SYSROOT}/usr/bin;$ENV{PATH}")

set(CMAKE_MAKE_PROGRAM "/usr/bin/make"    CACHE PATH "Host Make Program")
set(CMAKE_SH           "/usr/bin/sh"      CACHE PATH "Host shell Program")
set(CMAKE_AR           "${GCC_LINUX_ARM_ROOT}/bin/aarch64-none-linux-gnu-ar"       CACHE PATH "GCC ar Program")
set(CMAKE_RANLIB       "${GCC_LINUX_ARM_ROOT}/bin/aarch64-none-linux-gnu-ranlib"   CACHE PATH "GCC ranlib Program")
set(CMAKE_NM           "${GCC_LINUX_ARM_ROOT}/bin/aarch64-none-linux-gnu-nm"       CACHE PATH "GCC nm Program")
set(CMAKE_OBJCOPY      "${GCC_LINUX_ARM_ROOT}/bin/aarch64-none-linux-gnu-objcopy"  CACHE PATH "GCC objcopy Program")
set(CMAKE_OBJDUMP      "${GCC_LINUX_ARM_ROOT}/bin/aarch64-none-linux-gnu-objdump"  CACHE PATH "GCC objdump Program")
set(CMAKE_LINKER       "${GCC_LINUX_ARM_ROOT}/bin/aarch64-none-linux-gnu-ld"           CACHE PATH "GCC Linker Program")
set(CMAKE_STRIP        "${GCC_LINUX_ARM_ROOT}/bin/aarch64-none-linux-gnu-strip"    CACHE PATH "GCC Strip Program")

set(CMAKE_C_COMPILER    "${GCC_LINUX_ARM_ROOT}/bin/aarch64-none-linux-gnu-gcc")
set(CMAKE_CXX_COMPILER  "${GCC_LINUX_ARM_ROOT}/bin/aarch64-none-linux-gnu-g++")

set(CMAKE_C_COMPILER_TARGET ${arch})
set(CMAKE_CXX_COMPILER_TARGET ${arch})

set(CMAKE_FIND_ROOT_PATH  "${HYDRA_TARGET_SYSROOT}")
# search headers and libraries in the target environment, search
# programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)


set( CMAKE_C_FLAGS $ENV{CFLAGS} CACHE STRING "" FORCE )
set( CMAKE_CXX_FLAGS $ENV{CXXFLAGS}  CACHE STRING "" FORCE )
set( CMAKE_ASM_FLAGS ${CMAKE_C_FLAGS} CACHE STRING "" FORCE )
set( CMAKE_LDFLAGS_FLAGS ${CMAKE_CXX_FLAGS} CACHE STRING "" FORCE )
set( CMAKE_SYSROOT ${HYDRA_TARGET_SYSROOT} )
