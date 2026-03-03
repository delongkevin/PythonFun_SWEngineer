#ifndef DEGMANAGER_B_MEMMAP_H_INCLUDEGUARD
#define DEGMANAGER_B_MEMMAP_H_INCLUDEGUARD
#if defined(BUILD_MCU1_0)
  #define DegManager_B_START_SEC_CODE
  #include "DegManager_B_MemMap.h"
  
  #define DegManager_B_START_SEC_VAR_INIT_UNSPECIFIED
  #include "DegManager_B_MemMap.h"
  
  //#define ErrorMgrSat_1_0_B_START_SEC_VAR_NOINIT_UNSPECIFIED
 // #include "DegManager_B_MemMap.h"
  
  //#define ErrorMgrSat_1_0_B_START_SEC_CONST_UNSPECIFIED
  //#include "DegManager_B_MemMap.h"
#endif
#endif
