##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************
## $Id: toolchain.cmake 1.1 2019/11/03 02:43:51CET Gopinath Ramanathan (gopirama) draft  $
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

set(CMAKE_SYSTEM_NAME MinGW_RTOS)
set(CMAKE_SYSTEM_VERSION 8.1.0)                                     # QNX OS Version
set(arch gcc)
set(CMAKE_SYSTEM_PROCESSOR x86_64-w64-mingw32)
set(QNX_ARCH x86_64)

#set(CMAKE_IMPORT_LIBRARY_SUFFIX ".a")
#set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
#set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
set(CMAKE_STATIC_LIBRARY_PREFIX "lib")
set(CMAKE_STATIC_LIBRARY_SUFFIX ".a")

 
FIND_PATH(MINGW_PATH
  NAME bin/gcc.exe
  PATHS $ENV{MINGW_PATH} "C:/prjtools/mingw32/ver_8.1.0/bin"
  NO_CMAKE_PATH
  NO_CMAKE_ENVIRONMENT_PATH
)

set(ENV{MINGW_PATH} ${MINGW_PATH})
set(ENV{PATH} "${MINGW_PATH}/bin;$ENV{PATH}")

set(CMAKE_MAKE_PROGRAM "${MINGW_PATH}/bin/${CMAKE_SYSTEM_PROCESSOR}-make.exe"    CACHE PATH "MINGW Make Program")
set(CMAKE_SH           "${MINGW_PATH}/bin/sh.exe"       CACHE PATH "MINGW shell Program")
set(CMAKE_AR           "${MINGW_PATH}/bin/ar.exe"       CACHE PATH "MINGW ar Program")
set(CMAKE_RANLIB       "${MINGW_PATH}/bin/ranlib.exe"   CACHE PATH "MINGW ranlib Program")
set(CMAKE_NM           "${MINGW_PATH}/bin/nm.exe"       CACHE PATH "MINGW nm Program")
set(CMAKE_OBJCOPY      "${MINGW_PATH}/bin/objcopy.exe"  CACHE PATH "MINGW objcopy Program")
set(CMAKE_OBJDUMP      "${MINGW_PATH}/bin/objdump.exe"  CACHE PATH "MINGW objdump Program")
set(CMAKE_LINKER       "${MINGW_PATH}/bin/ld"           CACHE PATH "MINGW Linker Program")
set(CMAKE_STRIP        "${MINGW_PATH}/bin/strip.exe"    CACHE PATH "MINGW Strip Program")

set(CMAKE_C_COMPILER    "${MINGW_PATH}/bin/${CMAKE_SYSTEM_PROCESSOR}-gcc.exe")
set(CMAKE_CXX_COMPILER  "${MINGW_PATH}/bin/${CMAKE_SYSTEM_PROCESSOR}-g++.exe")
set(CMAKE_C_COMPILER_TARGET ${arch})
set(CMAKE_CXX_COMPILER_TARGET ${arch})
set(CMAKE_C_FLAGS_RELEASE "-fmessage-length=0 -g -O0 -fno-builtin")
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++11 -fpermissive -fmessage-length=0 -g -O0 -fno-builtin")
set(CMAKE_C_FLAGS_DEBUG "-fmessage-length=0 -g -O0 -fno-builtin")
set(CMAKE_CXX_FLAGS_DEBUG "-std=c++11 -fpermissive -fmessage-length=0 -g -O0 -fno-builtin")

set(CMAKE_FIND_ROOT_PATH "${MINGW_PATH}")
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









