##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************

target_include_directories(${OS_TARGET}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_include_directories(${CDD_TARGET}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(${CDD_TARGET}
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/MeOsProfiling.c
    ${CMAKE_CURRENT_LIST_DIR}/MeOsProfiling.h
    ${CMAKE_CURRENT_LIST_DIR}/MeOsProfiling_ASR.h

    ${CMAKE_CURRENT_LIST_DIR}/MeOsProfiling_Tick.h
    ${CMAKE_CURRENT_LIST_DIR}/MeOsProfiling_Print.h
    ${CMAKE_CURRENT_LIST_DIR}/MeOsProfiling_MemMap.h

    ${CMAKE_CURRENT_LIST_DIR}/MeOsProfiling_Cfg.h
)
