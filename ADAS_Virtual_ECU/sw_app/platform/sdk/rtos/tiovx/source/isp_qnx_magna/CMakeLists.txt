##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************
## $Id: CMakeLists.txt 1.1 2018/10/09 $
##********************************************************************************************
cmake_minimum_required (VERSION 3.2)
project(magna_isp_qnx)


get_filename_component(CURDIR ${CMAKE_CURRENT_LIST_DIR} ABSOLUTE)
message("CURDIR = " ${CURDIR})

add_definitions(-DDRV_ARCH_RCAR_V3M)

SET(PLATFORM_INC_DIRS ${CURDIR}/public)

set(PC_VER 0 CACHE BOOL "PC_VER")
set(USE_TWEAK 1 CACHE BOOL "using qt tweak lib")
set(REBUILD_TWEAK_LIB ${PC_VER} CACHE BOOL "rebuild  tweak lib")
set(DEFAULT_CFG 1 CACHE BOOL "build default config")
set(VERSION_GEN 0 CACHE BOOL "generate version header from git repository")
set(UTEST_BUILD 0 CACHE BOOL "Special build for unit testing purposes")

if (DEFAULT_CFG)
    add_definitions(-DDEFAULT_CFG)
endif(DEFAULT_CFG)

if (VERSION_GEN)
    add_definitions(-DVERSION_GEN)
endif(VERSION_GEN)

if (PC_VER)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g -fsanitize=address -fno-omit-frame-pointer -Werror -Wall")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O0 -g -fsanitize=address -fno-omit-frame-pointer -Werror -Wall")
    add_definitions(-DPC_VER)
else(PC_VER)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -O2 -Wall -Wstrict-prototypes")
endif(PC_VER)

if (USE_TWEAK)
    message("-- TWEAKTOOL enabled")
    add_definitions(-DUSE_TWEAK)

    if (REBUILD_TWEAK_LIB)
        set(TWEAK_H "${CURDIR}/src/cogent/tweak.h" "${CURDIR}/src/internal/tweak_socket.h")
        set(TWEAK_C "${CURDIR}/src/internal/tweak_socket_client.c")
        set(TWEAK_CLIENT_STATIC tweak_client_custom)
    else(REBUILD_TWEAK_LIB)
        set(TWEAK_H "${CURDIR}/src/cogent/tweak.h")
        set(TWEAK_C)
        set(TWEAK_CLIENT_STATIC tweak_client_orig)
        link_directories(${CURDIR}/src/cogent/)
    endif(REBUILD_TWEAK_LIB)

    set(TWEAK_DEPENDENT_H_SRC ${TWEAK_H})

else(USE_TWEAK)
    set(REBUILD_TWEAK_LIB 0)
    message("-- TWEAKTOOL disabled")
endif(USE_TWEAK)

if (UTEST_BUILD)
    add_definitions(-D_UTESTS)
    message("-- UTEST_BUILD enabled")
else(UTEST_BUILD)
endif(UTEST_BUILD)


include_directories(
    ${CURDIR}
    ${CURDIR}/public/cogent
    ${CURDIR}/public/cogent/isp
    ${CURDIR}/src/cogent
    ${CURDIR}/src/
)

set(LIB_H_SRC
    ${CURDIR}/src/isp_aux.h
    ${CURDIR}/public/cogent/isp/tisp.h
    ${CURDIR}/public/cogent/isp/isp_cfg.h
    ${CURDIR}/public/cogent/isp/cisp.h
    ${CURDIR}/public/cogent/isp/isp.h
    ${CURDIR}/public/cogent/isp/drv.h
    ${CURDIR}/public/cogent/cogent_api.h
    ${CURDIR}/src/isp_process.h
    ${CURDIR}/src/config_reader.h
    ${CURDIR}/src/algo_defaults.h
    ${CURDIR}/src/algo_reg.h
    ${CURDIR}/src/awb-impl.h
    ${CURDIR}/src/isp_algo.h
    ${CURDIR}/src/items.h
    ${CURDIR}/src/parameters_storage.h
    ${TWEAK_DEPENDENT_H_SRC}
)

set(LIB_C_SRC
    ${CURDIR}/src/isp_algo.c
    ${CURDIR}/src/magna_controls.c
    ${CURDIR}/src/isp_awb_wrapper.c
    ${CURDIR}/src/isp_autoexposure.c
    ${CURDIR}/src/isp_aux.c
    ${CURDIR}/src/awb-impl.c
    ${CURDIR}/src/emb_parser.c
    ${CURDIR}/src/isp_process.c
    ${CURDIR}/src/cogent_api.c
    ${CURDIR}/src/parameters_storage.c
    ${CURDIR}/src/config_reader_aux.c
    ${CURDIR}/src/def_cfg.c
    ${CURDIR}/src/def_cfg_147.c
)

set(LIBR
    ${TWEAK_CLIENT_STATIC}
    ${SOCKET_LIB}
)
file(GLOB LIB_C_VER ${CMAKE_CURRENT_SOURCE_DIR}/version.h)


if (REBUILD_TWEAK_LIB)
    add_library(tweak_client_custom ${TWEAK_H} ${TWEAK_C})
    set_property(TARGET tweak_client_custom PROPERTY C_STANDARD 99)
    target_link_libraries(tweak_client_custom ${TWEAK_LIB_DEP})
endif(REBUILD_TWEAK_LIB)

link_directories(${QNX_TARGET}/${QNX_ARCH}/usr/lib/)
message("LINK DIRS: " "${QNX_TARGET}/${QNX_ARCH}/usr/lib/")

if (VERSION_GEN)
    add_custom_command(
        OUTPUT ${CURDIR}/version1.h
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/generate_version.cmake
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

    set_source_files_properties(
        ${CURDIR}/version1.h
        PROPERTIES GENERATED TRUE
        )

    add_custom_target(
        gen_ver DEPENDS ${CURDIR}/version1.h
    )
endif(VERSION_GEN)

if (PC_VER)
    add_executable(cogent_isp_tuning ${LIB_H_SRC} ${LIB_C_SRC} ${CURDIR}/src/internal/test.c ${CURDIR}/src/internal/1.c ${TWEAK_C})
    if (VERSION_GEN)
        add_dependencies(cogent_isp_tuning gen_ver)
    endif(VERSION_GEN)
    set_property(TARGET cogent_isp_tuning PROPERTY C_STANDARD 99)
    target_link_libraries(cogent_isp_tuning ${LIBR} m pthread asan)
else(PC_VER)
    add_library(cogent_isp_tuning SHARED ${LIB_H_SRC} ${LIB_C_SRC} ${LIB_C_VER})
    if (VERSION_GEN)
        add_dependencies(cogent_isp_tuning gen_ver)
    endif(VERSION_GEN)
    set_property(TARGET cogent_isp_tuning PROPERTY C_STANDARD 99)
    if (UTEST_BUILD)
    else(UTEST_BUILD)
        target_link_libraries(cogent_isp_tuning ${LIBR})
    endif(UTEST_BUILD)
endif(PC_VER)



