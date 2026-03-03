##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************
## $Id: CMakeLists.txt 1.4 2021/08/31 11:28:20CEST Martin Rachor (MEE_MRACHO) draft  $
##********************************************************************************************

## ensure cmake version
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)


## Your Module name. default is to use the directory name
get_filename_component(module_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" module_name ${module_name})

set(exe_name "puc_app${TARGET_EXTN}")

MESSAGE(STATUS)
MESSAGE(STATUS "-------------------------------------------------------------------------------")
MESSAGE(STATUS "MODULE NAME                 : ${module_name}")
MESSAGE(STATUS "CMAKE_CURRENT_LIST_DIR      : ${CMAKE_CURRENT_LIST_DIR}")
MESSAGE(STATUS "-------------------------------------------------------------------------------")
MESSAGE(STATUS)

###################################################################################################

GET_SOURCE_FILES("")

add_executable(${exe_name} ${SourceFiles} )

target_include_directories(${exe_name} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}

    ${CORE_SERVICES_DIR}/AppMIntgr
    ${CORE_SERVICES_DIR}/VarMIntgr
    ${CORE_SERVICES_DIR}/SigMIntgr
    ${CORE_SERVICES_DIR}/SysMonIntgr
    ${CORE_SERVICES_DIR}/LogMIntgr
    ${CORE_SERVICES_DIR}/CALSMIntgr

    ${APPS_DIR}
    ${APPS_DIR}/EOLIntgr
    ${APPS_DIR}/OVL3DIntgr
    ${APPS_DIR}/OCIntgr
    ${APPS_DIR}/OCIntgr/cfg
    ${APPS_DIR}/OCIntgr/oc
    ${APPS_DIR}/TIOVXIntgr
    ${APPS_DIR}/THAIntgr
    $ENV{ME_BOOKSHELF_PATH}/includes
    ${APPS_DIR}/TAD2Intgr
    ${APPS_DIR}/TAD2Intgr/algo/inc
    ${APPS_DIR}/DLDIntgr
    $ENV{ME_BOOKSHELF_PATH}/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA
    
    # DMS Core include path
    #${APPS_DIR}/DMSIntgr/dms/
    #${APPS_DIR}/DMSIntgr/dms/dms/src
    
    # DMS Core PuC dependencie include path
    # Logger library
    ${CORE_LIBS_DIR}/logging/logging
    # Time, Mutex library
    ${CORE_LIBS_DIR}/platform/platform/stdlib
    # SeeingMachine include path
    #${APPS_DIR}/DMSIntgr/dms/dms/sm/include
    
    # calib statemachine include directory
    ${APPS_DIR}/CALSMIntgr

    ${CORE_LIBS_DIR}/platform
    ${CORE_LIBS_DIR}/osal
    ${CORE_LIBS_DIR}/bsp
    ${CORE_LIBS_DIR}/dlt
    ${CORE_LIBS_DIR}/container
    ${CORE_LIBS_DIR}/variants
    ${CORE_LIBS_DIR}/mecl
    ${CORE_LIBS_DIR}/logging
    ${CORE_LIBS_DIR}/sensor
    ${CORE_LIBS_DIR}/me3d
    ${CORE_LIBS_DIR}/me3d/me3d
    ${CORE_LIBS_DIR}/meal/meal/camera/core/inc
    ${CORE_LIBS_DIR}/meal/
    ${CORE_LIBS_DIR}/meal/meal
    ${CORE_LIBS_DIR}/fsdata
    ${CORE_LIBS_DIR}/mecl/mecl/core
    ${APPS_DIR}/TAD2Intgr/TAD2/algo/common
    #TIDL include paths
    ${PSDK_PATH}/tidl_j721s2_08_05_00_16/ti_dl/inc
    ${PSDK_PATH}/vision_apps/kernels/img_proc/include
    ${PSDK_PATH}/tiovx/utils/include
    ${PSDK_PATH}/ivision/
)

target_link_libraries(${exe_name}
                        AppMIntgr
                        SigMIntgr
                        VarMIntgr
                        OVL3DIntgr
                        EOLIntgr
                        OCIntgr
                        SysMonIntgr
                        LogMIntgr
                        TIOVXIntgr						
                        THAIntgr
                        TAD2Intgr
                        CALSMIntgr
                        DLDIntgr
                        platform
                        logging
                        osal
                        container
                        dlt
                        me3d
                        sensor
                        mecl
                        bsp
                        meal
                        fsdata
)

if(DEFINED USE_RTOS)
    target_link_libraries(${exe_name} FreeRTOS)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "QNX")
    target_link_libraries(${exe_name}
                          ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libscreen.so
  	                      ${QNX_TARGET}/${QNX_ARCH}/lib/libgestures.so
                          ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libEGL.so
                          ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libGLESv2.so
                          ${PSDK_PATH}/vision_apps/out/J721S2/A72/QNX/release/libtivision_apps.so
						  ${PSDK_PATH}/psdkqa/qnx/sharedmemallocator/usr/aarch64/so.le/libsharedmemallocator.so
						  ${PSDK_PATH}/psdkqa/qnx/resmgr/ipc_qnx_rsmgr/usr/aarch64/so.le/libtiipc-usr.so
						  ${PSDK_PATH}/psdkqa/qnx/resmgr/udma_qnx_rsmgr/usr/aarch64/so.le/libtiudma-usr.so
						  ${PSDK_PATH}/psdkqa/qnx/pdk_libs/pdk/aarch64/so.le/libti-pdk.so
						  ${PSDK_PATH}/psdkqa/qnx/pdk_libs/udmalld/aarch64/so.le/libti-udmalld.so
						  ${PSDK_PATH}/psdkqa/qnx/pdk_libs/sciclient/aarch64/so.le/libti-sciclient.so
						  slog2)

else()
    add_definitions(-DUSE_DIRECTORY_WATCHER)
    target_link_libraries(${exe_name}
                          ${CORE_LIBS_DIR}/me3d/OpenGL/lib/x86/libEGL.lib
                          ${CORE_LIBS_DIR}/me3d/OpenGL/lib/x86/libGLESv2.lib)

#copy dlls
add_custom_command(TARGET ${exe_name} POST_BUILD
  # debug
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CORE_LIBS_DIR}/me3d/OpenGL/lib/x86/libEGL.dll          ${OUTPUT_BASE_DIR}/libs/vs10/debug
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CORE_LIBS_DIR}/me3d/OpenGL/lib/x86/libGLESv2.dll       ${OUTPUT_BASE_DIR}/libs/vs10/debug

  # Output Message
  COMMENT "Copying external dlls '${CORE_LIBS_DIR}/me3d/OpenGL/lib/x86/' to '${OUTPUT_BASE_DIR}/libs/vs10/debug'" VERBATIM
)

endif()



###################################################################################################



