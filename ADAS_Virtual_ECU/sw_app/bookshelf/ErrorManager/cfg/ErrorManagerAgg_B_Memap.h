#ifndef ERRORMANAGER_AGG_B_MEMMAP_H_INCLUDEGUARD
#define ERRORMANAGER_AGG_B_MEMMAP_H_INCLUDEGUARD

#if defined(BUILD_MCU1_0)
  #define ErrorMgrAgg_1_0_B_START_SEC_CODE
  #include "ErrorMgrAgg_1_0_B_MemMap.h"
  
  
  #define ErrorMgrAgg_1_0_B_START_SEC_VAR_NOINIT_UNSPECIFIED
  #include "ErrorMgrAgg_1_0_B_MemMap.h"
  
//  #define ErrorMgrSat_1_0_B_STOP_SEC_VAR_NOINIT_UNSPECIFIED
 // #include "ErrorMgrSat_1_0_B_MemMap.h"
  
  //#define ErrorMgrSat_1_0_B_STOP_SEC_CONST_UNSPECIFIED
 // #include "ErrorMgrSat_1_0_B_MemMap.h"
#endif

#endif
