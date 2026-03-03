##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************
## $Id: toolchain.cmake 1.1.2.4 2021/08/23 16:41:04CEST Martin Rachor (MEE_MRACHO) draft  $
##********************************************************************************************


# Skip CMake’s checks for a working compiler 
# set(CMAKE_C_COMPILER_ID "Tasking")

#set(CMAKE_C_COMPILER_WORKS TRUE CACHE INTERNAL "")
#set(CMAKE_CXX_COMPILER_WORKS TRUE CACHE INTERNAL "")
#
#set(CMAKE_C_COMPILER_FORCED TRUE CACHE INTERNAL "")
#set(CMAKE_CXX_COMPILER_FORCED TRUE CACHE INTERNAL "")
#
##   variables needed to be set to prevent an attempt to identify the compiler
#set(CMAKE_C_COMPILER_ID_RUN TRUE CACHE INTERNAL "")
#set(CMAKE_CXX_COMPILER_ID_RUN TRUE CACHE INTERNAL "")
#

#use Generic for embedded systems
#set(CMAKE_CROSSCOMPILING "TRUE")

set(CMAKE_SYSTEM_NAME QNX)
set(CMAKE_SYSTEM_VERSION 7.1.0)                                     # QNX OS Version
set(arch gcc_ntoaarch64le)
set(CMAKE_SYSTEM_PROCESSOR aarch64-unknown-nto-qnx7.1.0)
set(QNX_ARCH aarch64le)

#set(CMAKE_IMPORT_LIBRARY_SUFFIX ".a")
#set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
#set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
set(CMAKE_STATIC_LIBRARY_PREFIX "lib")
set(CMAKE_STATIC_LIBRARY_SUFFIX ".a")

FIND_PATH(QNX_HOST
  NAME usr/bin/qcc.exe
  PATHS $ENV{QNX_HOST} "${QNX_DIR}/host/win64/x86_64"
  NO_CMAKE_PATH
  NO_CMAKE_ENVIRONMENT_PATH
)
 
FIND_PATH(QNX_TARGET
  NAME usr/include/stdio.h
  PATHS $ENV{QNX_TARGET} "${QNX_DIR}/target/qnx7"
  NO_CMAKE_PATH
  NO_CMAKE_ENVIRONMENT_PATH
)

set(ENV{QNX_HOST} ${QNX_HOST})
set(ENV{QNX_TARGET} ${QNX_TARGET})
set(ENV{PATH} "${QNX_HOST}/usr/bin;$ENV{PATH}")


set(CMAKE_MAKE_PROGRAM "${QNX_HOST}/usr/bin/make.exe"    CACHE PATH "QNX Make Program")
set(CMAKE_SH           "${QNX_HOST}/usr/bin/sh.exe"      CACHE PATH "QNX shell Program")
set(CMAKE_AR           "${QNX_HOST}/usr/bin/${CMAKE_SYSTEM_PROCESSOR}-ar.exe"       CACHE PATH "QNX ar Program")
set(CMAKE_RANLIB       "${QNX_HOST}/usr/bin/${CMAKE_SYSTEM_PROCESSOR}-ranlib.exe"   CACHE PATH "QNX ranlib Program")
set(CMAKE_NM           "${QNX_HOST}/usr/bin/${CMAKE_SYSTEM_PROCESSOR}-nm.exe"       CACHE PATH "QNX nm Program")
set(CMAKE_OBJCOPY      "${QNX_HOST}/usr/bin/${CMAKE_SYSTEM_PROCESSOR}-objcopy.exe"  CACHE PATH "QNX objcopy Program")
set(CMAKE_OBJDUMP      "${QNX_HOST}/usr/bin/${CMAKE_SYSTEM_PROCESSOR}-objdump.exe"  CACHE PATH "QNX objdump Program")
set(CMAKE_LINKER       "${QNX_HOST}/usr/bin/${CMAKE_SYSTEM_PROCESSOR}-ld"           CACHE PATH "QNX Linker Program")
set(CMAKE_STRIP        "${QNX_HOST}/usr/bin/${CMAKE_SYSTEM_PROCESSOR}-strip.exe"    CACHE PATH "QNX Strip Program")

set(CMAKE_C_COMPILER    "${QNX_HOST}/usr/bin/qcc.exe")
set(CMAKE_CXX_COMPILER  "${QNX_HOST}/usr/bin/qcc.exe")
set(CMAKE_C_COMPILER_TARGET ${arch})
set(CMAKE_CXX_COMPILER_TARGET ${arch})

set(CMAKE_FIND_ROOT_PATH  "${QNX_HOST}" "${QNX_TARGET}")
# search headers and libraries in the target environment, search
# programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)


#
## Override the archiver options
#set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> -static -a <TARGET> <LINK_FLAGS> <OBJECTS>")
#set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> -static -a <TARGET> <LINK_FLAGS> <OBJECTS>")
#set(CMAKE_C_ARCHIVE_FINISH "")
## CMAKE_RANLIB is not necessary in Tasking compiler tool-set
## Ref 7.3.2 How the Linker Extracts Objects from Libraries - page 233 of ctc_user_guide.pdf
##set(CMAKE_RANLIB         "C:/cygwin/bin/echo.exe")
#
### customise the original LINK command
##set(CMAKE_C_LINK_EXECUTABLE  "<CMAKE_C_COMPILER> <FLAGS> <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
#set(CMAKE_C_LINK_EXECUTABLE  "<CMAKE_C_COMPILER> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
#









