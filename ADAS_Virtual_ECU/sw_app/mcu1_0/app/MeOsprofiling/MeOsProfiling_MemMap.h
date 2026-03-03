/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @addtogroup     MeOsProfiling
 *  @file           MeOsProfiling_MemMap.h
 *  @brief          AUTOSAR Vendor dependant OS Profiling MemMap
 *
 * It is recommended to keep MeOsProfiling vars and code in fast memory
 * together with OS vars and code.
 *
 * OS profiling MemMap for Vector AUTOSAR (LIDAR).
 *
 *  @author         Bernard Bosnjak
 *
 * ========================================================================= */

/* PRQA S 5087,0883,0841 ++ */

#if (defined MEOSPROF_START_SEC_CODE)
  #undef MEOSPROF_START_SEC_CODE
  /* Vendor dependant implementation here. */
  #define OS_START_SEC_CODE
  #include "Os_MemMap_OsCode.h"
#elif (defined MEOSPROF_STOP_SEC_CODE)
  #undef MEOSPROF_STOP_SEC_CODE
  /* Vendor dependant implementation here. */
  #define OS_STOP_SEC_CODE
  #include "Os_MemMap_OsCode.h"
#elif (defined MEOSPROF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
  #undef MEOSPROF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
  /* Vendor dependant implementation here. */
  #define OS_START_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED
  #include "Os_MemMap_OsSections.h"
#elif (defined MEOSPROF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
  #undef MEOSPROF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
  /* Vendor dependant implementation here. */
  #define OS_STOP_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED
  #include "Os_MemMap_OsSections.h"
#else
  #error "MeOsProfiling_MemMap unexpected section"
#endif
