##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************
## $Id: CMakeLists.txt 1.3 2021/09/13 12:59:01CEST Martin Rachor (MEE_MRACHO) draft  $
##********************************************************************************************

## ensure cmake version
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)


add_subdirectory(EOLIntgr)
add_subdirectory(OVL3DIntgr)
add_subdirectory(OCIntgr)
add_subdirectory(TIOVXIntgr)
add_subdirectory(CALSMIntgr)
add_subdirectory(THAIntgr)
add_subdirectory(TAD2Intgr)
add_subdirectory(DLDIntgr)
