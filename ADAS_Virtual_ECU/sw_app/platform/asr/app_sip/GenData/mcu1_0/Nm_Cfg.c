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
 *            Module: Nm
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Nm_Cfg.c
 *   Generation Time: 2024-02-13 13:07:46
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define NM_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Nm_Cfg.h"


#include "ComM.h"
#include "CanNm.h"
#include "BswM_Nm.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/
/* (NM_SYSTONMCHIND == STD_ON) If the number of system channels is not equal to the number of NM channels,
 * channel indirection is needed. Otherwise, the channel index is equals to the network handler. */
# if ( NM_SYSTONMCHIND == STD_ON )
#  define NM_CHANNEL_IDX                          Nm_GetSysToNmChInd(nmNetworkHandle)
# else
#  define NM_CHANNEL_IDX                          nmNetworkHandle
# endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
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
  Nm_CarWakeUpCallbackFctPtr
**********************************************************************************************************************/
/** 
  \var    Nm_CarWakeUpCallbackFctPtr
  \brief  Car Wake Up Callback
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Nm_CallbackFunction, NM_CONST) Nm_CarWakeUpCallbackFctPtr = NULL_PTR;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_ChannelConfig
**********************************************************************************************************************/
/** 
  \var    Nm_ChannelConfig
  \brief  Structure for channel specific configuration parameters
  \details
  Element               Description
  NmChannelId       
  NmFunctionTableIdx    the index of the 1:1 relation pointing to Nm_NmFunctionTable
  PartitionConfigIdx    the index of the 1:1 relation pointing to Nm_PCPartitionConfig
  PduRxIndication   
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Nm_ChannelConfigType, NM_CONST) Nm_ChannelConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    NmChannelId                               NmFunctionTableIdx  PartitionConfigIdx  PduRxIndication        Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_CN_FDCAN14_a902658e,                 0u,                 0u, NULL_PTR        },  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN14_a902658e] */
  { /*     1 */  ComMConf_ComMChannel_CN_FDCAN2_28a8fc44,                 0u,                 0u, NULL_PTR        }   /* [/ActiveEcuC/ComM/ComMConfigSet/CN_FDCAN2_28a8fc44] */
};
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_NmFunctionTable
**********************************************************************************************************************/
/** 
  \var    Nm_NmFunctionTable
  \details
  Element                   Description
  GetLocalNodeIdentifier
  GetNodeIdentifier     
  GetPduData            
  GetState              
  DisableCommunication  
  EnableCommunication   
  NetworkRelease        
  NetworkRequest        
  PassiveStartUp        
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Nm_NmFunctionTableType, NM_CONST) Nm_NmFunctionTable[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    GetLocalNodeIdentifier        GetNodeIdentifier        GetPduData        GetState        DisableCommunication        EnableCommunication        NetworkRelease        NetworkRequest        PassiveStartUp              Referable Keys */
  { /*     0 */ CanNm_GetLocalNodeIdentifier, CanNm_GetNodeIdentifier, CanNm_GetPduData, CanNm_GetState, CanNm_DisableCommunication, CanNm_EnableCommunication, CanNm_NetworkRelease, CanNm_NetworkRequest, CanNm_PassiveStartUp }   /* [CanNm] */
};
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    Nm_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to Nm_PCPartitionConfig
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Nm_PartitionIdentifiersType, NM_CONST) Nm_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV         PCPartitionConfigIdx */
  { /*     0 */ NM_SINGLE_PARTITION,                   0u }
};
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_Initialized
**********************************************************************************************************************/
/** 
  \var    Nm_Initialized
  \brief  Initialized state
*/ 
#define NM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Nm_InitializedType, NM_VAR_NO_INIT) Nm_Initialized;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define NM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_PostInitialized
**********************************************************************************************************************/
/** 
  \var    Nm_PostInitialized
  \brief  Post-Initialized state
*/ 
#define NM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Nm_PostInitializedType, NM_VAR_NO_INIT) Nm_PostInitialized[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define NM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



#if ( NM_USE_INIT_POINTER == STD_ON )
# define NM_START_SEC_VAR_INIT_UNSPECIFIED
# include "Nm_MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Pointer to Postbuild configuration */
P2CONST(Nm_ConfigType, NM_VAR_INIT, NM_CONST) Nm_ConfigPtr = NULL_PTR;

# define NM_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "Nm_MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

 

/**********************************************************************************************************************
 *  END OF FILE: Nm_Cfg.c
 *********************************************************************************************************************/

