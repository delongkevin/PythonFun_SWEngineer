unset(QNX_HOST CACHE)
unset(QCC_EXE_EXT CACHE)

FIND_PATH(QNX_HOST
    NAME usr/bin/qcc.exe
    PATHS $ENV{QNX_HOST}
    NO_CMAKE_PATH
    NO_CMAKE_ENVIRONMENT_PATH
    )

if (QNX_HOST)
    set(QCC_EXE_EXT ".exe")
    message("windows exe found " ${QNX_HOST})
else(QNX_HOST)
    unset(QNX_HOST CACHE)
    FIND_PATH(QNX_HOST
        NAME usr/bin/qcc
        PATHS $ENV{QNX_HOST}
        NO_CMAKE_PATH
        NO_CMAKE_ENVIRONMENT_PATH)
    message("QNX_HOST: " ${QNX_HOST})
endif(QNX_HOST)

FIND_PATH(QNX_TARGET
NAME usr/include/stdio.h
PATHS $ENV{QNX_TARGET}
NO_CMAKE_PATH
NO_CMAKE_ENVIRONMENT_PATH
)

set(CMAKE_SYSTEM_NAME QNX)
set(QNX_ARCH aarch64le)

set(arch gcc_ntoaarch64le)

message("COMPILER:      " "${QNX_HOST}/usr/bin/qcc${QCC_EXE_EXT}")

set(CMAKE_C_COMPILER    "${QNX_HOST}/usr/bin/qcc${QCC_EXE_EXT}")
set(CMAKE_CXX_COMPILER  "${QNX_HOST}/usr/bin/qcc${QCC_EXE_EXT}")
set(CMAKE_C_COMPILER_TARGET ${arch})
set(CMAKE_CXX_COMPILER_TARGET ${arch})

set( CMAKE_C_FLAGS            " -D__QNX__ " CACHE STRING "CFLAGS" )
set( CMAKE_CXX_FLAGS          " -D__QNX__ " CACHE STRING "CXXFLAGS" )
