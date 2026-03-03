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
 *            Module: CanSM
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanSM_Lcfg.c
 *   Generation Time: 2024-02-13 13:07:48
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/




#define CANSM_LCFG_C


 /**********************************************************************************************************************
 *  Includes
 **********************************************************************************************************************/

#include "CanSM_EcuM.h"



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanSM_ChannelConfig
**********************************************************************************************************************/
/** 
  \var    CanSM_ChannelConfig
  \details
  Element                             Description
  Trcv_InActive_AtAll_NonPNCannels    Config feature which determines if Trvc is active at a Non PN channel
  NetworkHandle                   
  TransceiverId                   
*/ 
#define CANSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanSM_ChannelConfigType, CANSM_CONST) CanSM_ChannelConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Trcv_InActive_AtAll_NonPNCannels  NetworkHandle  TransceiverId                         */
  { /*     0 */                            FALSE,            1u,                                    0u },
  { /*     1 */                             TRUE,            0u, CANSM_NO_TRANSCEIVERIDOFCHANNELCONFIG }
};
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanSM_ChannelVarRecord
**********************************************************************************************************************/
#define CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanSM_ChannelVarRecordType, CANSM_VAR_NOINIT) CanSM_ChannelVarRecord[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/




 /**********************************************************************************************************************
 *  VAR DATA PROTOTYPES
 **********************************************************************************************************************/




#define CANSM_START_SEC_VAR_ZERO_INIT_8BIT 
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint8, CANSM_VAR_ZERO_INIT) CanSM_EnableSetBusSleep[ CANSM_ENABLE_SET_BUS_SLEEP_ARRAY_MAX_SIZE ] =
{
  0u /*  enable CANSM_SET_BUS_SLEEP_MODE  */ , 
  0u /*  enable CANSM_SET_BUS_SLEEP_MODE  */ 
};

#define CANSM_STOP_SEC_VAR_ZERO_INIT_8BIT 
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

 /* -----------------------------------------------
 BusOffIndicationFct  Begin
 ----------------------------------------------- */

#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(CanSM_BusOffBeginIndicationFctPtrType, CANSM_CONST) CanSM_BusOffBeginIndicationFctPtr = Appl_BusOffBegin;  /* PRQA S 1533 */ /* MD_CANSM_Rule8.9 */

#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


 /* -----------------------------------------------
 BusOffIndicationFct  End
 ----------------------------------------------- */

#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(CanSM_BusOffEndIndicationFctPtrType, CANSM_CONST) CanSM_BusOffEndIndicationFctPtr = Appl_BusOffEnd;   /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */

#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */







