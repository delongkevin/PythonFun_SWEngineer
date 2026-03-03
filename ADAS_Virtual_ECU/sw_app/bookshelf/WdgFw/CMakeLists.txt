##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************
## $Id: CMakeLists.txt 1.3 2019/11/18 15:50:11CET Mark Reichert2 (Mark.Reichert2) draft  $
##********************************************************************************************

## ensure cmake version
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(WdgFw)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(${CMAKE_ADDONS_DIR}/utilities.cmake)
include(${CMAKE_ADDONS_DIR}/output.cmake)


MESSAGE(STATUS)
MESSAGE(STATUS "-------------------------------------------------------------------------------")
MESSAGE(STATUS "MODULE NAME                 : ${PROJECT_NAME}")
MESSAGE(STATUS "CMAKE_SOURCE_DIR            : ${CMAKE_SOURCE_DIR}")
MESSAGE(STATUS "CMAKE_CURRENT_LIST_DIR      : ${CMAKE_CURRENT_LIST_DIR}")
MESSAGE(STATUS "-------------------------------------------------------------------------------")
MESSAGE(STATUS)

GET_SOURCE_FILES("Wdg/src")
GET_SOURCE_FILES("Wdg/cfg/MCU3_0")
GET_SOURCE_FILES("WdgIf")
GET_SOURCE_FILES("WdgM")
GET_SOURCE_FILES("Wdg")

add_definitions(-DSOC_J721E=1 -DBUILD_MPU1_0=1 -DBUILD_MCUQNX=1 -DDEBUG_INFO=1)
add_definitions(-DSIGNALMGR_CFG_RTOS=SIGNALMGR_CFG_RTOS_QNX)
add_definitions(-DBUILD_MPUCOMPONENT=1)

add_library(${PROJECT_NAME} SHARED ${SourceFiles})

set(RTOS_DIR ${CMAKE_CURRENT_LIST_DIR}/../../../../linux/bsp/rtos)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    
    ${CMAKE_CURRENT_LIST_DIR}/Common   
    ${CMAKE_CURRENT_LIST_DIR}/Wdg/cfg
    ${CMAKE_CURRENT_LIST_DIR}/Wdg/inc   
    ${CMAKE_CURRENT_LIST_DIR}/WdgIf/cfg
    ${CMAKE_CURRENT_LIST_DIR}/WdgIf/inc    
    ${CMAKE_CURRENT_LIST_DIR}/WdgM/cfg
    ${CMAKE_CURRENT_LIST_DIR}/WdgM/cfg/MCU3_0
    ${CMAKE_CURRENT_LIST_DIR}/WdgM/inc
    ${CMAKE_CURRENT_LIST_DIR}/WdgSlave/cfg
    ${CMAKE_CURRENT_LIST_DIR}/WdgSlave/inc
    
    ${CMAKE_CURRENT_LIST_DIR}/../CalDataProvider/cfg
    ${CMAKE_CURRENT_LIST_DIR}/../CalDataProvider/inc
    
    ${CMAKE_CURRENT_LIST_DIR}/../ipc_manager/cfg
    ${CMAKE_CURRENT_LIST_DIR}/../ipc_manager/inc
    
    ${CMAKE_CURRENT_LIST_DIR}/../ErrorManager/cfg
    ${CMAKE_CURRENT_LIST_DIR}/../ErrorManager/gen
    ${CMAKE_CURRENT_LIST_DIR}/../ErrorManager/inc
    
    ${CMAKE_CURRENT_LIST_DIR}/../SignalMgr/gen
    ${CMAKE_CURRENT_LIST_DIR}/../SignalMgr/inc
    
    ${CMAKE_CURRENT_LIST_DIR}/../SSM/cfg
    ${CMAKE_CURRENT_LIST_DIR}/../SSM/inc
    
    ${CMAKE_CURRENT_LIST_DIR}/../../magna_apps/common

    ${CMAKE_CURRENT_LIST_DIR}/../../magna_apps/hsf/algo/Sq1/_sharedutils
    ${CMAKE_CURRENT_LIST_DIR}/../../magna_apps/hsf/algo/Sq2/_sharedutils
    ${CMAKE_CURRENT_LIST_DIR}/../../magna_apps/hsf/algo/Sq3/_sharedutils
    ${CMAKE_CURRENT_LIST_DIR}/../../magna_apps/hsf/algo/Sq4/_sharedutils
    ${CMAKE_CURRENT_LIST_DIR}/../../magna_apps/hsf/algo/Sq5/_sharedutils
    
    ${CMAKE_CURRENT_LIST_DIR}/../../magna_apps/lsf/algo/includes/EnvObjDet
    
    #${CMAKE_CURRENT_LIST_DIR}/../../main_domain/console_io/include
    ${CMAKE_CURRENT_LIST_DIR}/../../includes
    
    ${PDK_DIR}/packages
)


###################################################################################################

# make cache variables for install destinations
include(GNUInstallDirs)

include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}Config.cmake.in
                             "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
                              INSTALL_DESTINATION ${INSTALL_BASE_DIR}
)

CONFIG_LIBRARY_INSTALL(${PROJECT_NAME} ${INSTALL_BASE_DIR})

install(FILES ${PROJECT_NAME}Config.cmake DESTINATION ${INSTALL_BASE_DIR})

install(EXPORT ${PROJECT_NAME}Targets
        FILE ${PROJECT_NAME}.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${INSTALL_BASE_DIR}/cmake
)
