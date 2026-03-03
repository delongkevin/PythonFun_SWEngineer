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
 *            Module: EcuM
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EcuM_Cfg.c
 *   Generation Time: 2024-02-13 13:07:48
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/




/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* PRQA S 0310 EOF */ /* MD_CSL_0310 */
#include "EcuM_Cbk.h"

#define ECUM_PRIVATE_CFG_PARTLY_INCLUDE
#include "EcuM_PrivateCfg.h"
#undef ECUM_PRIVATE_CFG_PARTLY_INCLUDE /* PRQA S 0841 */ /* MD_EcuM_0841 */

#if((ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON) ||(ECUM_PNCOFCOMMPNCS == STD_ON) || (ECUM_SUPPORT_COMM == STD_ON))
#include "ComM.h"
#endif

#if !defined (ECUM_LOCAL) /* COV_ECUM_LOCAL */
# define ECUM_LOCAL static
#endif

#if !defined (ECUM_LOCAL_INLINE) /* COV_ECUM_LOCAL_INLINE */
# define ECUM_LOCAL_INLINE LOCAL_INLINE
#endif 

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  EcuM_DriverInitOne
**********************************************************************************************************************/
/** 
  \var    EcuM_DriverInitOne
  \details
  Element     Description
  Function
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_DriverInitOneType, ECUM_CONST) EcuM_DriverInitOne[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Function              */
  { /*     0 */ EcuM_AL_DriverInitOne }
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_WakeupSourceList
**********************************************************************************************************************/
/** 
  \var    EcuM_WakeupSourceList
  \brief  Contains all parameters configured for Wakeup Sources
  \details
  Element           Description
  Channel           Mapped ComM channel number - 255 if no ComM channel is assigned.
  ValidationTime    Timeout for Wakeup Validation - if 0 no Validation is performed
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_WakeupSourceListType, ECUM_CONST) EcuM_WakeupSourceList[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Channel                                   ValidationTime        Comment                                    Referable Keys */
  { /*     0 */ 255                                     ,             0u },  /* [ECUM_WKSOURCE_POWER]          */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_POWER, ECUM_WKSOURCE_POWER] */
  { /*     1 */ 255                                     ,             0u },  /* [ECUM_WKSOURCE_RESET]          */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_RESET, ECUM_WKSOURCE_RESET] */
  { /*     2 */ 255                                     ,             0u },  /* [ECUM_WKSOURCE_INTERNAL_RESET] */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_INTERNAL_RESET, ECUM_WKSOURCE_INTERNAL_RESET] */
  { /*     3 */ 255                                     ,             0u },  /* [ECUM_WKSOURCE_INTERNAL_WDG]   */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_INTERNAL_WDG, ECUM_WKSOURCE_INTERNAL_WDG] */
  { /*     4 */ 255                                     ,             0u },  /* [ECUM_WKSOURCE_EXTERNAL_WDG]   */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_EXTERNAL_WDG, ECUM_WKSOURCE_EXTERNAL_WDG] */
  { /*     5 */ ComMConf_ComMChannel_CN_FDCAN14_a902658e,             0u },  /* [CN_FDCAN14_a902658e]          */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/CN_FDCAN14_a902658e, CN_FDCAN14_a902658e] */
  { /*     6 */ ComMConf_ComMChannel_CN_FDCAN2_28a8fc44 ,           100u }   /* [CN_FDCAN2_28a8fc44]           */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/CN_FDCAN2_28a8fc44, CN_FDCAN2_28a8fc44] */
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_ModuleState
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_StateType, ECUM_VAR_NO_INIT) EcuM_ModuleState;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_ValidationTimeoutTable
**********************************************************************************************************************/
/** 
  \var    EcuM_ValidationTimeoutTable
  \brief  Validation Timeout Table
*/ 
#define ECUM_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_ValidationTimeoutTableType, ECUM_VAR_NO_INIT) EcuM_ValidationTimeoutTable[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_POWER, ECUM_WKSOURCE_POWER] */
  /*     1 */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_RESET, ECUM_WKSOURCE_RESET] */
  /*     2 */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_INTERNAL_RESET, ECUM_WKSOURCE_INTERNAL_RESET] */
  /*     3 */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_INTERNAL_WDG, ECUM_WKSOURCE_INTERNAL_WDG] */
  /*     4 */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_EXTERNAL_WDG, ECUM_WKSOURCE_EXTERNAL_WDG] */
  /*     5 */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/CN_FDCAN14_a902658e, CN_FDCAN14_a902658e] */
  /*     6 */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/CN_FDCAN2_28a8fc44, CN_FDCAN2_28a8fc44] */

#define ECUM_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/




