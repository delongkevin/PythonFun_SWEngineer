##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************
## $Id: CMakeLists.txt 1.3 2021/08/26 13:40:10CEST Martin Rachor (MEE_MRACHO) draft  $
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


target_compile_definitions(${module_name} PRIVATE -DAM_MAKE_STATIC_LIBRARY )# To set same Makro definitions "VG_API_CALL"

# add the include directory to project
set (INC_DIR "../"
			 "../amanith/include"

 )



 foreach(IncDir ${INC_DIR})
	target_include_directories(${module_name} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/${IncDir}) 
endforeach(IncDir)
 
target_include_directories(${module_name} PRIVATE
	${APPS_DIR}
	${APPS_DIR}/amanith/include
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/cfg
    ${CMAKE_CURRENT_LIST_DIR}/cfg/DataProvider
    ${CMAKE_CURRENT_LIST_DIR}/EOL
    $ENV{ME_BOOKSHELF_PATH}/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA

    
    ${CORE_LIBS_DIR}/platform
    ${CORE_LIBS_DIR}/container
    ${CORE_LIBS_DIR}/osal
    ${CORE_LIBS_DIR}/bsp
    ${CORE_LIBS_DIR}/logging
    ${CORE_LIBS_DIR}/variants
    ${CORE_LIBS_DIR}/sensor
    ${CORE_LIBS_DIR}/mecl
    ${CORE_LIBS_DIR}/mecl/mecl
    $ENV{ME_BOOKSHELF_PATH}/../mcu2_1/App/USS/US_Includes
)

###################################################################################################




