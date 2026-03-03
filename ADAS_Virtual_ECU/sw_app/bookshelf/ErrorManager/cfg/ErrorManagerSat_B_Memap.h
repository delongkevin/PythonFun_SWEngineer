#ifndef ERRORMANAGER_SAT_B_MEMMAP_H_INCLUDEGUARD
#define ERRORMANAGER_SAT_B_MEMMAP_H_INCLUDEGUARD

/*#if defined(BUILD_MCU2_1) || defined(BUILD_MCU3_0)
  #define START_ASILB_CODE_SECTION
  #include "asil_memmap.h"

  #define START_ASILB_DATA_SECTION
  #include "asil_memmap.h"

  #define START_ASILB_BSS_SECTION
  #include "asil_memmap.h"

  #define START_ASILB_CONST_SECTION
  #include "asil_memmap.h"
#endif */


#if defined(BUILD_MCU1_0)
  #define ErrorMgrSat_1_0_B_START_SEC_CODE
  #include "ErrorMgrSat_1_0_B_MemMap.h"

  #define ErrorMgrSat_1_0_B_START_SEC_VAR_INIT_UNSPECIFIED
  #include "ErrorMgrSat_1_0_B_MemMap.h"

  //#define ErrorMgrSat_1_0_B_START_SEC_VAR_NOINIT_UNSPECIFIED
 // #include "ErrorMgrSat_1_0_B_MemMap.h"

  //#define ErrorMgrSat_1_0_B_START_SEC_CONST_UNSPECIFIED
  //#include "ErrorMgrSat_1_0_B_MemMap.h"
#endif

#if defined(BUILD_MCU3_1)
  #define ErrorMgrSat_3_1_B_START_SEC_CODE
  #include "ErrorMgrSat_3_1_B_MemMap.h"

  #define ErrorMgrSat_3_1_B_START_SEC_VAR_INIT_UNSPECIFIED
  #include "ErrorMgrSat_3_1_B_MemMap.h"

  //#define ErrorMgrSat_3_1_B_START_SEC_VAR_NOINIT_UNSPECIFIED
  //#include "ErrorMgrSat_3_1_B_MemMap.h"

  //#define ErrorMgrSat_3_1_B_START_SEC_CONST_UNSPECIFIED
  //#include "ErrorMgrSat_3_1_B_MemMap.h"
#endif



#endif
