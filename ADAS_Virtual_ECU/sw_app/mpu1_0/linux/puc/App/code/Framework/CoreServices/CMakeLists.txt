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


add_subdirectory(AppMIntgr)
add_subdirectory(LogMIntgr)
add_subdirectory(SigMIntgr)
add_subdirectory(SysIntgr)
add_subdirectory(VarMIntgr)
add_subdirectory(SysMonIntgr)



