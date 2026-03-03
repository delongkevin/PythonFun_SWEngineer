##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************
## $Id: CMakeLists.txt 1.1 2020/03/18 05:41:27EDT Martin Rachor (MEE_MRACHO) draft  $
##********************************************************************************************

## ensure cmake version
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)


## Your Module name. default is to use the directory name
get_filename_component(module_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" module_name ${module_name})

MESSAGE(STATUS)
MESSAGE(STATUS "-------------------------------------------------------------------------------")
MESSAGE(STATUS "MODULE NAME                 : ${module_name}")
MESSAGE(STATUS "CMAKE_CURRENT_LIST_DIR      : ${CMAKE_CURRENT_LIST_DIR}")
MESSAGE(STATUS "-------------------------------------------------------------------------------")
MESSAGE(STATUS)

###################################################################################################

GET_SOURCE_FILES("")

add_library(${module_name} ${SourceFiles})

add_definitions("-O3 -Wall -Wextra -Wno-unused-parameter -Wno-unused-local-typedefs -Wno-unused-variable -Wno-unused-but-set-variable -Wno-strict-aliasing")

target_include_directories(${module_name} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    
    ${PSDK_PATH}/tidl_j721s2_08_05_00_16/ti_dl/inc
    ${PSDK_PATH}/tiovx/include
    ${PSDK_PATH}/tiovx/utils/include
    ${PSDK_PATH}/tiovx/kernels/include
    ${PSDK_PATH}/tiovx/kernels_j7/include
    ${PSDK_PATH}/imaging
    ${PSDK_PATH}/imaging/kernels/include
    ${PSDK_PATH}/imaging/sensor_drv/include
    ${PSDK_PATH}/vision_apps/
    ${PSDK_PATH}/vision_apps/utils/
    ${PSDK_PATH}/vision_apps/apps/basic_demos/app_tirtos/tirtos_qnx/mpu1
    ${PSDK_PATH}/vision_apps/apps/basic_demos/app_tirtos/tirtos_qnx
    ${PSDK_PATH}/vision_apps/apps/basic_demos/app_tirtos/common
    ${PSDK_PATH}/vision_apps/utils/itt_server/include
    ${PSDK_PATH}/vision_apps/utils/network_api/include
    ${PSDK_PATH}/vision_apps/kernels
    ${PSDK_PATH}/vision_apps/kernels/fileio/include
    ${PSDK_PATH}/vision_apps/kernels/img_proc/include
    ${PSDK_PATH}/tiadalg/include
    ${PSDK_PATH}/ivision/
    ${CMAKE_CURRENT_LIST_DIR}/THA/
    ${CMAKE_CURRENT_LIST_DIR}/THA/modules/src/
    ${CMAKE_CURRENT_LIST_DIR}/THA/modules/include/
    ${CMAKE_CURRENT_LIST_DIR}/THA/algo/
    ${CMAKE_CURRENT_LIST_DIR}/THA/algo/common/
    ${CMAKE_CURRENT_LIST_DIR}/THA/algo/inc/
    ${CMAKE_CURRENT_LIST_DIR}/THA/algo/Tracker/
    ${CMAKE_CURRENT_LIST_DIR}/THA/cfg/
    ${CMAKE_CURRENT_LIST_DIR}/../OVL3DIntgr/
    ${CMAKE_CURRENT_LIST_DIR}/../OVL3DIntgr/sv/inc
    ${CORE_LIBS_DIR}/platform
    ${CORE_LIBS_DIR}/container
    ${CORE_LIBS_DIR}/osal
    ${CORE_LIBS_DIR}/bsp
    ${CORE_LIBS_DIR}/logging
    ${CORE_LIBS_DIR}/variants
    ${CORE_LIBS_DIR}/sensor
    ${CORE_LIBS_DIR}/mecl
    ${CORE_LIBS_DIR}/mecl/mecl
    ${CORE_LIBS_DIR}/meal/
    ${CORE_LIBS_DIR}/meal/meal/camera/core/inc
    $ENV{ME_BOOKSHELF_PATH}/../mcu2_1/App/USS/US_Includes
    $ENV{ME_BOOKSHELF_PATH}/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA
)

###################################################################################################




