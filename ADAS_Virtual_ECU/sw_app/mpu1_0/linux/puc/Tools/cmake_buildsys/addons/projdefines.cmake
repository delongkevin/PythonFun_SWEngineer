##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************
## $Id: projdefines.cmake 1.3.3.3 2021/08/31 11:28:20CEST Martin Rachor (MEE_MRACHO) draft  $
##********************************************************************************************


set(TARGET_EXTN ".out")


# Project DIR defines
SET_ABS_PATH(CODE_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../App/code")

set(EXT_RTOS_DIR        "${CODE_DIR}/../../../bsp/rtos")
set(EXT_LINUX_DIR       "${CODE_DIR}/../../../bsp/linux")
set(CORE_LIBS_DIR       "${CODE_DIR}/Framework/CoreLibs")
set(CORE_SERVICES_DIR   "${CODE_DIR}/Framework/CoreServices")
set(OS_DIR              "${CODE_DIR}/Os")
set(APPS_DIR            "${CODE_DIR}/Apps")
set(RTOS_DIR            "${OS_DIR}/FreeRTOS")
set(BSP_DIR             "${OS_DIR}/BSP/QNX")
set(BSP_SRC_DIR         "${BSP_DIR}/src")
set(BSP_LIB_DIR         "${BSP_SRC_DIR}/lib")
set(BSP_CAPTURE_DIR     "${BSP_LIB_DIR}/lib")

add_definitions(-D__ARM_NEON__)


#---------------------------------------------
# LogM
#---------------------------------------------
add_definitions(-DDEFAULT_LOG_LEVEL=logging::e_LogLvlInfo)

#---------------------------------------------
# OVL3D
#---------------------------------------------
if(${CMAKE_SYSTEM_NAME} STREQUAL "QNX")
add_definitions(-DME_USE_EXTERNAL_IMAGE_EXTENSION)
endif()
