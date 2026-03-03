/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: CanTrcv
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTrcv_30_Tja1043_Cfg.c
 *   Generation Time: 2024-02-13 13:07:49
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "CanTrcv_30_Tja1043.h"

/**********************************************************************************************************************
  VERSION DEFINES (Adapted with: ESCAN00086365)
**********************************************************************************************************************/
#if (DRVTRANS_CAN_30_TJA1043_GENTOOL_CFG5_MAJOR_VERSION != 0x03u)
# error "CanTrcv_30_30_Tja1043_Cfg.c : Incompatible DRVTRANS_30_TJA1043_GENTOOL_CFG5_MAJOR_VERSION in generated File!"
#endif

#if (DRVTRANS_CAN_30_TJA1043_GENTOOL_CFG5_MINOR_VERSION != 0x03u)
# error "CanTrcv_30_30_Tja1043_Cfg.c : Incompatible DRVTRANS_30_TJA1043_GENTOOL_CFG5_MINOR_VERSION in generated File!"
#endif

#if (DRVTRANS_CAN_30_TJA1043_GENTOOL_CFG5_PATCH_VERSION != 0x00u)
# error "CanTrcv_30_30_Tja1043_Cfg.c : Incompatible DRVTRANS_30_TJA1043_GENTOOL_CFG5_PATCH_VERSION in generated File!"
#endif


/**********************************************************************************************************************
    ADDITIONAL (HW SPECIFIC)
**********************************************************************************************************************/



/**********************************************************************************************************************
  ComStackLib
**********************************************************************************************************************/
/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanTrcv_30_Tja1043_ChannelUsed
**********************************************************************************************************************/
#define CANTRCV_30_TJA1043_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_30_Tja1043_ChannelUsedType, CANTRCV_30_TJA1043_CONST) CanTrcv_30_Tja1043_ChannelUsed[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ChannelUsed  */
  /*     0 */         TRUE
};
#define CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTrcv_30_Tja1043_DioConfiguration
**********************************************************************************************************************/
/** 
  \var    CanTrcv_30_Tja1043_DioConfiguration
  \details
  Element    Description
  PinEN  
  PinERR 
  PinRXD 
  PinSTB 
*/ 
#define CANTRCV_30_TJA1043_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_30_Tja1043_DioConfigurationType, CANTRCV_30_TJA1043_CONST) CanTrcv_30_Tja1043_DioConfiguration[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PinEN                                PinERR                                PinRXD                                PinSTB                               */
  { /*     0 */ DioConf_DioChannel_DioChannel_pinEN, DioConf_DioChannel_DioChannel_PinERR, DioConf_DioChannel_DioChannel_PINRXD, DioConf_DioChannel_DioChannel_PinSTB }
};
#define CANTRCV_30_TJA1043_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTrcv_30_Tja1043_Hw_VariantGroup
**********************************************************************************************************************/
#define CANTRCV_30_TJA1043_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_30_Tja1043_Hw_VariantGroupType, CANTRCV_30_TJA1043_CONST) CanTrcv_30_Tja1043_Hw_VariantGroup[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Hw_VariantGroup      Comment */
  /*     0 */            0x00u   /* [Tja1043 Reference Group] */
};
#define CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTrcv_30_Tja1043_WakeupByBusUsed
**********************************************************************************************************************/
#define CANTRCV_30_TJA1043_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_30_Tja1043_WakeupByBusUsedType, CANTRCV_30_TJA1043_CONST) CanTrcv_30_Tja1043_WakeupByBusUsed[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     WakeupByBusUsed  */
  /*     0 */             TRUE
};
#define CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTrcv_30_Tja1043_WakeupSource
**********************************************************************************************************************/
#define CANTRCV_30_TJA1043_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_30_Tja1043_WakeupSourceType, CANTRCV_30_TJA1043_CONST) CanTrcv_30_Tja1043_WakeupSource[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     WakeupSource  */
  /*     0 */         0x40u
};
#define CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/





