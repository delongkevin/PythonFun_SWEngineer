##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************
## $Id: CMakeLists.txt 1.2 2021/08/17 08:52:03CEST Martin Rachor (MEE_MRACHO) draft  $
##********************************************************************************************

## ensure cmake version
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

add_subdirectory(bsp)
add_subdirectory(platform)
add_subdirectory(osal)
add_subdirectory(mecl)
add_subdirectory(me3d)
add_subdirectory(container)
add_subdirectory(variants)
add_subdirectory(logging)
add_subdirectory(dlt)
add_subdirectory(sensor)
add_subdirectory(meal)
add_subdirectory(fsdata)
#add_subdirectory(crypto)
