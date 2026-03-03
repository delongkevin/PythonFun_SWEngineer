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









