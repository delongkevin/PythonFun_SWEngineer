##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************
## $Id: CMakeLists.txt 1.1 2021/08/19 15:23:34CEST Martin Rachor (MEE_MRACHO) draft  $
##********************************************************************************************

## ensure cmake version
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

## Your project's name
message("CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
project(puc_app C CXX)
message("CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")

## Activate the necessary parts. This will avoid long command line issue
#set(CMAKE_C_USE_RESPONSE_FILE_FOR_LIBRARIES 1)
#set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_LIBRARIES 1)

#set(CMAKE_C_USE_RESPONSE_FILE_FOR_OBJECTS 1)
#set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_OBJECTS 1)

#set(CMAKE_C_USE_RESPONSE_FILE_FOR_INCLUDES 1)
#set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES 1)

## Set policies
#cmake_policy(SET CMP0015 NEW)

## Detect OS environment (CMAKE_SYSTEM_NAME == "Linux")
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "INFO: Unix/Linux environment detected.")
else()
    message(STATUS "INFO: Windows environment detected.")
endif()


## ensure out-of-source build
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "Project requires an out-of-source build. Please create a separate build directory and run 'cmake path/to/${project} [options]' there.")
endif()
add_definitions( -DBUILD_MCUQNX )

option(ENABLE_RUNTIME_STATS "Enable runtime statistics" ON)

if(ENABLE_RUNTIME_STATS)
    add_definitions(-DENABLE_RUNTIME_STATS)
    message(STATUS "Runtime statistics enabled")
else()
    message(STATUS "Runtime statistics disabled")
endif()

# Add custom cmake files/functions
set(TOOLS_DIR "${CMAKE_CURRENT_LIST_DIR}/../../Tools")
get_filename_component(TOOLS_DIR ${TOOLS_DIR} ABSOLUTE)
include(${TOOLS_DIR}/cmake_buildsys/addons/utilities.cmake)
set(CMAKE_MODULE_PATH "${TOOLS_DIR}/cmake_buildsys/addons" ${CMAKE_MODULE_PATH})


## project level generic definitions
#set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)
#set(CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET_ABS_PATH(OUTPUT_BASE_DIR "${CMAKE_CURRENT_LIST_DIR}/../build")

if (MSVC)
    if(MSVC_VERSION EQUAL 1500)
        set(vsversion "vs9")
    elseif(MSVC_VERSION EQUAL 1600)
        set(vsversion "vs10")
    elseif(MSVC_VERSION EQUAL 1700)
        set(vsversion "vs11")
    else()
        set(vsversion "vs")
    endif()
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/${vsversion})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/${vsversion})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/${vsversion})
endif()


#SET( CMAKE_SHARED_LINKER_FLAGS_PROFILE "-Wl,--warn-unresolved-symbols,--warn-once" CACHE STRING "Flags used by the shared libraries linker during profile builds." FORCE )
#MARK_AS_ADVANCED(CMAKE_CXX_FLAGS_PROFILE CMAKE_C_FLAGS_PROFILE CMAKE_EXE_LINKER_FLAGS_PROFILE CMAKE_SHARED_LINKER_FLAGS_PROFILE)
# Update the documentation string of CMAKE_BUILD_TYPE for GUIs
#SET( CMAKE_BUILD_TYPE "${CMAKE_BUILD_TYPE}" CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel profile." FORCE )


## compile flags and linker flags for both release and debug builds
if(${CMAKE_SYSTEM_NAME} STREQUAL "QNX")
    set(BUILD_FLAGS_PATH                "${TOOLS_DIR}/cmake_buildsys/app/buildoptions")
    set(CMAKE_C_FLAGS_RELEASE           "@${BUILD_FLAGS_PATH}/compiler_options_rel_build")
    set(CMAKE_C_FLAGS_DEBUG             "@${BUILD_FLAGS_PATH}/compiler_options_deb_build")
    set(CMAKE_CXX_FLAGS_RELEASE         "@${BUILD_FLAGS_PATH}/compiler_options_rel_build")
    set(CMAKE_CXX_FLAGS_DEBUG           "@${BUILD_FLAGS_PATH}/compiler_options_deb_build")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE  "@${BUILD_FLAGS_PATH}/linker_options_rel_build")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG    "@${BUILD_FLAGS_PATH}/linker_options_deb_build")
    set(CMAKE_CXX_FLAGS_PROFILE         "@${BUILD_FLAGS_PATH}/compiler_options_pro_build"   CACHE STRING "Flags used by the C++ compiler during profile builds."    FORCE)
    set(CMAKE_C_FLAGS_PROFILE           "@${BUILD_FLAGS_PATH}/compiler_options_pro_build"   CACHE STRING "Flags used by the C compiler during profile builds."      FORCE)
    set(CMAKE_EXE_LINKER_FLAGS_PROFILE  "@${BUILD_FLAGS_PATH}/linker_options_pro_build"     CACHE STRING "Flags used for linking binaries during profile builds."   FORCE)

    IF(${CMAKE_BUILD_TYPE} MATCHES "Debug")
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/qnx/debug)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/qnx/debug)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/qnx/debug)
    ENDIF()

    IF(${CMAKE_BUILD_TYPE} MATCHES "Release")
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/qnx/release)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/qnx/release)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/qnx/release)
    ENDIF()

    IF(${CMAKE_BUILD_TYPE} MATCHES "Profile")
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/qnx/profile)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/qnx/profile)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/qnx/profile)
    ENDIF()
endif()

if(DEFINED USE_RTOS)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/rtos)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/rtos)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/rtos)
    include_directories(${ME_PSDK_PATH})
    include_directories(${ME_PSDK_PATH}/tiovx/include)
    include_directories(${ME_PSDK_PATH}/tiovx/kernels/include)
    include_directories(${ME_PSDK_PATH}/tiovx/kernels_j7/include)
    include_directories(${ME_PSDK_PATH}/imaging)
    include_directories(${ME_PSDK_PATH}/imaging/kernels/include)
    include_directories(${ME_PSDK_PATH}/imaging/sensor_drv/include)
    include_directories(${ME_PSDK_PATH}/vision_apps)
    include_directories(${ME_PSDK_PATH}/vision_apps/apps/basic_demos/app_tirtos/tirtos_qnx/mpu1)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    IF(${CMAKE_BUILD_TYPE} MATCHES "Debug")
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/unx/debug)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/unx/debug)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/unx/debug)
    ENDIF()

    IF(${CMAKE_BUILD_TYPE} MATCHES "Release")
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/unx/release)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/unx/release)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/unx/release)
    ENDIF()

    IF(${CMAKE_BUILD_TYPE} MATCHES "Profile")
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/unx/profile)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/unx/profile)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_BASE_DIR}/libs/unx/profile)
    ENDIF()
endif()

## Project modules
include(${TOOLS_DIR}/cmake_buildsys/addons/projdefines.cmake)

if(DEFINED USE_RTOS)
    add_definitions(-D__RTOS__)
    add_subdirectory(${RTOS_DIR})
    include_directories(SYSTEM ${RTOS_DIR}/Source/include)
    include_directories(SYSTEM ${RTOS_DIR}/Source/portable/MSVC-MingW)
endif()
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    include_directories(${ME_PSDK_PATH})
    include_directories(${ME_PSDK_PATH}/tiovx/include)
    include_directories(${ME_PSDK_PATH}/tiovx/kernels/include)
    include_directories(${ME_PSDK_PATH}/tiovx/kernels_j7/include)
    include_directories(${ME_PSDK_PATH}/imaging)
    include_directories(${ME_PSDK_PATH}/imaging/kernels/include)
    include_directories(${ME_PSDK_PATH}/imaging/sensor_drv/include)
    include_directories(${ME_PSDK_PATH}/vision_apps)
    include_directories(${ME_PSDK_PATH}/vision_apps/apps/basic_demos/app_tirtos/tirtos_qnx/mpu1)
    include_directories(${ME_PSDK_PATH}/psdkqa)
    include_directories(${ME_PSDK_PATH}/psdkqa/pdk)
    include_directories(${ME_PSDK_PATH}/psdkqa/pdk/packages)
else()
    include_directories(${ME_PSDK_PATH})
    include_directories(${ME_PSDK_PATH}/psdkqa)
    include_directories(${ME_PSDK_PATH}/psdkqa/pdk)
    include_directories(${ME_PSDK_PATH}/psdkqa/pdk/packages)
    include_directories(${ME_PSDK_PATH}/psdkqa/pdk/packages/ti)
    include_directories(${ME_PSDK_PATH}/psdkqa/pdk/packages/ti/drv)
    include_directories(${ME_PSDK_PATH}/psdkqa/pdk/packages/ti/drv/ipc)
    include_directories(${ME_PSDK_PATH}/psdkqa/pdk/packages/ti/drv/ipc/include)

    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/magna_apps/tha_sm_vc/algo/common/)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/magna_apps/tha_sm_vc/algo)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/magna_apps/tha_sm_vc)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/magna_apps/common_includes)    
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/includes)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/ipc_manager/inc/)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/_sharedutils)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/SignalMgr/inc/)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/magna_apps/trsc/algo/_sharedutils/)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/common/inc/)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/magna_apps/KM/code/)

    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/common/inc/)
    include_directories($ENV{ME_REPO_ROOT}/sw/mcu2_1/App/USS/US_Includes)
        include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/SSM/inc/)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/SSM/cfg/)
    include_directories($ENV{ME_REPO_ROOT}/sw/platform/asr/app_sip/GenData/mcu1_0/)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw/)
    include_directories($ENV{ME_REPO_ROOT}/sw/mcu2_1/App/USS/US_Includes/)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/ErrorManager/gen/)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/ErrorManager/inc/)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/ErrorManager/cfg/)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/magna_apps/tha_sm_vc/algo/_sharedutils/)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw/)
    include_directories($ENV{ME_REPO_ROOT}/sw/mcu2_1/App/USS/US_Includes/)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw/)
    include_directories($ENV{ME_REPO_ROOT}/sw/mpu1_0/linux/puc/App/code/Framework/CoreLibs/container/cfg/shmdata/)
    include_directories($ENV{ME_REPO_ROOT}/sw/bookshelf/CalDataProvider/inc/)
    include_directories($ENV{ME_REPO_ROOT}/)
    include_directories($ENV{ME_REPO_ROOT}/)
    
    
endif()

add_definitions( -DBUILD_MCUQNX )
#include_directories(${CMAKE_CURRENT_LIST_DIR}/../../../../../bookshelf/includes)

add_subdirectory(Apps)
add_subdirectory(Framework)



# Display system configurations
MESSAGE(STATUS)
MESSAGE(STATUS "------------------------------------------------------------------------------------")
MESSAGE(STATUS "CMAKE_SYSTEM_NAME               : ${CMAKE_SYSTEM_NAME}")
MESSAGE(STATUS "QNX_HOST                        : ${QNX_HOST}")
MESSAGE(STATUS "QNX_TARGET                      : ${QNX_TARGET}")
MESSAGE(STATUS "CMAKE_C_COMPILER                : ${CMAKE_C_COMPILER}")
MESSAGE(STATUS "CMAKE_CXX_COMPILER              : ${CMAKE_CXX_COMPILER}")
MESSAGE(STATUS "CMAKE_C_COMPILER_ID             : ${CMAKE_C_COMPILER_ID}")
MESSAGE(STATUS "CMAKE_CXX_COMPILER_ID           : ${CMAKE_CXX_COMPILER_ID}")
MESSAGE(STATUS "CMAKE_C_FLAGS_RELEASE           : ${CMAKE_C_FLAGS_RELEASE}")
MESSAGE(STATUS "CMAKE_CXX_FLAGS_RELEASE         : ${CMAKE_CXX_FLAGS_RELEASE}")
MESSAGE(STATUS "CMAKE_C_FLAGS_DEBUG             : ${CMAKE_C_FLAGS_DEBUG}")
MESSAGE(STATUS "CMAKE_CXX_FLAGS_DEBUG           : ${CMAKE_CXX_FLAGS_DEBUG}")
MESSAGE(STATUS "CMAKE_C_FLAGS_PROFILE           : ${CMAKE_C_FLAGS_PROFILE}")
MESSAGE(STATUS "CMAKE_CXX_FLAGS_PROFILE         : ${CMAKE_CXX_FLAGS_PROFILE}")
MESSAGE(STATUS "CMAKE_EXE_LINKER_FLAGS_PROFILE  : ${CMAKE_EXE_LINKER_FLAGS_PROFILE}")
MESSAGE(STATUS "CMAKE_CURRENT_LIST_DIR          : ${CMAKE_CURRENT_LIST_DIR}")
message(STATUS "CMAKE_MODULE_PATH               : ${CMAKE_MODULE_PATH}")
MESSAGE(STATUS "TOOLS_DIR                       : ${TOOLS_DIR}")
MESSAGE(STATUS "CMAKE_LIBRARY_OUTPUT_DIRECTORY  : ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
MESSAGE(STATUS "CMAKE_BUILD_TYPE                : ${CMAKE_BUILD_TYPE}")
MESSAGE(STATUS "------------------------------------------------------------------------------------")
MESSAGE(STATUS)







