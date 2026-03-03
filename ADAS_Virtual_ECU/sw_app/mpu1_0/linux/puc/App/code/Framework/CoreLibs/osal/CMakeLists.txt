##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************
## $Id: CMakeLists.txt 1.3 2021/08/26 13:40:09CEST Martin Rachor (MEE_MRACHO) draft  $
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

## sources (file wise is prefered. recursive selection is not recommended)

###################################################################################################

GET_SOURCE_FILES("")

add_library(${module_name} ${SourceFiles})

target_include_directories(${module_name} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CORE_LIBS_DIR}/platform
)

target_link_libraries(${module_name} platform)

###################################################################################################

