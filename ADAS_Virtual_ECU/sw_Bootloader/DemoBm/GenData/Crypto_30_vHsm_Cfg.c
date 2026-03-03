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
 *            Module: Crypto_30_vHsm
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_vHsm_Cfg.c
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_vHsm_Cfg.h"
#include "Crypto_30_vHsm.h"
#include "Crypto_30_vHsm_Ipc_Types.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CRYPTO_30_VHSM_LOCAL)
# define CRYPTO_30_VHSM_LOCAL static
#endif

#if !defined (CRYPTO_30_VHSM_LOCAL_INLINE)
# define CRYPTO_30_VHSM_LOCAL_INLINE LOCAL_INLINE
#endif




/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Crypto_30_vHsm_KeyMgmObj
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_KeyMgmObj
  \details
  Element          Description
  ObjectInfoIdx    the index of the 1:1 relation pointing to Crypto_30_vHsm_ObjectInfo
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_vHsm_KeyMgmObjType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_KeyMgmObj[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ObjectInfoIdx        Referable Keys */
  { /*     0 */            5u }   /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_MemoryArea
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_MemoryArea
  \brief  Memory to which vHsm has direct access without the need of a copy.
  \details
  Element      Description
  AreaStart    Start address of area
  AreaStop     Stop address of area
  AreaType     Access type of area
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_vHsm_MemoryAreaType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_MemoryArea[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AreaStart    AreaStop     AreaType                                        Referable Keys */
  { /*     0 */ 0x41C00000u, 0x41C03D10u, CRYPTO_30_VHSM_AREA_HSM_READWRITE_ACCESS },  /* [/ActiveEcuC/Crypto_30_vHsm/CryptovHsm/TDA4x_MCU_MSRAM_HOST] */
  { /*     1 */ 0x41010000u, 0x41018000u, CRYPTO_30_VHSM_AREA_HSM_READWRITE_ACCESS }   /* [/ActiveEcuC/Crypto_30_vHsm/CryptovHsm/TDA4x_MCU_MSRAM_HOST_CERTSTORE] */
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_ObjMap
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_ObjMap
  \details
  Element          Description
  ObjectInfoIdx    the index of the 0:1 relation pointing to Crypto_30_vHsm_ObjectInfo
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_vHsm_ObjMapType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_ObjMap[10] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ObjectInfoIdx                                  Referable Keys */
  { /*     0 */                                      0u },  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Custom] */
  { /*     1 */                                      1u },  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  { /*     2 */                                      2u },  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_GVCS] */
  { /*     3 */                                      3u },  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  { /*     4 */ CRYPTO_30_VHSM_NO_OBJECTINFOIDXOFOBJMAP },  /* [INVALID] */
  { /*     5 */                                      4u },  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyMRemote] */
  { /*     6 */                                      5u },  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  { /*     7 */                                      6u },  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  { /*     8 */ CRYPTO_30_VHSM_NO_OBJECTINFOIDXOFOBJMAP },  /* [INVALID] */
  { /*     9 */                                      7u }   /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_ObjectInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_ObjectInfo
  \details
  Element                     Description
  SharedDataBufferEndIdx      the end index of the 0:n relation pointing to Crypto_30_vHsm_SharedDataBuffer
  SharedDataBufferStartIdx    the start index of the 0:n relation pointing to Crypto_30_vHsm_SharedDataBuffer
  BufferUsed              
  HsmObjId                
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_vHsm_ObjectInfoType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_ObjectInfo[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SharedDataBufferEndIdx  SharedDataBufferStartIdx  BufferUsed  HsmObjId        Referable Keys */
  { /*     0 */                   387u,                       0u,       TRUE,       0u },  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Custom] */
  { /*     1 */                   388u,                     387u,      FALSE,       1u },  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  { /*     2 */                   516u,                     388u,       TRUE,       2u },  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_GVCS] */
  { /*     3 */                  1557u,                     516u,       TRUE,       3u },  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  { /*     4 */                  1558u,                    1557u,      FALSE,       5u },  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyMRemote] */
  { /*     5 */                  1559u,                    1558u,      FALSE,       6u },  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  { /*     6 */                  1946u,                    1559u,       TRUE,       7u },  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  { /*     7 */                  1947u,                    1946u,      FALSE,       9u }   /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_ChannelState
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_ChannelState
  \brief  Tracks which IPC channel is currently used.
*/ 
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Crypto_30_vHsm_ChannelStateType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_ChannelState[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_DriverObjectLock
**********************************************************************************************************************/
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Crypto_30_vHsm_DriverObjectLockUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_DriverObjectLock;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Custom] */
  /*     1 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*     2 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_GVCS] */
  /*     3 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*     4 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyMRemote] */
  /*     5 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*     6 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*     7 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_JobRequest
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_JobRequest
  \brief  Stores data for a job request sent to vHSM.
  \details
  Element                  Description
  OutputOffset         
  SecondaryOutputOffset
  UsedBuffer           
  Cancel               
  Counter              
  Kind                 
  Lock                 
  ProcessingType       
  Result               
  State                
  TrimmedOutputBuffer  
  CryptoJob            
  JobState             
  KeyMJob              
*/ 
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Crypto_30_vHsm_JobRequestUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_JobRequest;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Custom] */
  /*     1 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*     2 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_GVCS] */
  /*     3 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*     4 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyMRemote] */
  /*     5 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*     6 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*     7 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_OutputLengthPtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_OutputLengthPtrDataBuffer
  \brief  Buffer for the outputLengthPtr data on the shared RAM.
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_OutputLengthPtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_OutputLengthPtrDataBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Custom] */
  /*     1 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*     2 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_GVCS] */
  /*     3 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*     4 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyMRemote] */
  /*     5 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*     6 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*     7 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer
  \brief  Buffer for the secondaryOutputLengthPtr data on the shared RAM.
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Custom] */
  /*     1 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*     2 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_GVCS] */
  /*     3 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*     4 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyMRemote] */
  /*     5 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*     6 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*     7 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_SharedDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_SharedDataBuffer
  \brief  Buffer for input and output data on the shared RAM
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_SharedDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_SharedDataBuffer;  /* PRQA S 0759, 1514, 1533, 0612, 0613 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure, MD_CSL_BigStructure */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Custom] */
  /*   ... */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Custom] */
  /*   386 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Custom] */
  /*   387 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*   388 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_GVCS] */
  /*   ... */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_GVCS] */
  /*   515 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_GVCS] */
  /*   516 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*   ... */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*  1556 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*  1557 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyMRemote] */
  /*  1558 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*  1559 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*   ... */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*  1945 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*  1946 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_VerifyPtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_VerifyPtrDataBuffer
  \brief  Buffer for the verifyPtr data on the shared RAM.
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_VerifyPtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_VerifyPtrDataBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Custom] */
  /*     1 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*     2 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_GVCS] */
  /*     3 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*     4 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyMRemote] */
  /*     5 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*     6 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*     7 */  /* [/ActiveEcuC/Crypto_30_vHsm/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
#include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
CONST(Crypto_30_vHsm_Ipc_MemoryLayoutType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_Ipc_MemoryLayout =
{
  /* protocolInformationOffset */
  0u,
  /* txChannelMemoryLayout[CRYPTO_30_VHSM_IPC_NUM_TX_CHANNELS] */
  {
    { Crypto_30_vHsm_Ipc_GetTxChannelWriteIndexOffset(0u), Crypto_30_vHsm_Ipc_GetTxChannelReadIndexOffset(0u), Crypto_30_vHsm_Ipc_GetTxChannelBufferOffset(0u) },
    { Crypto_30_vHsm_Ipc_GetTxChannelWriteIndexOffset(1u), Crypto_30_vHsm_Ipc_GetTxChannelReadIndexOffset(1u), Crypto_30_vHsm_Ipc_GetTxChannelBufferOffset(1u) },
    { Crypto_30_vHsm_Ipc_GetTxChannelWriteIndexOffset(2u), Crypto_30_vHsm_Ipc_GetTxChannelReadIndexOffset(2u), Crypto_30_vHsm_Ipc_GetTxChannelBufferOffset(2u) },
    { Crypto_30_vHsm_Ipc_GetTxChannelWriteIndexOffset(3u), Crypto_30_vHsm_Ipc_GetTxChannelReadIndexOffset(3u), Crypto_30_vHsm_Ipc_GetTxChannelBufferOffset(3u) }  
  },
  /* rxChannelMemoryLayout[CRYPTO_30_VHSM_IPC_NUM_RX_CHANNELS] */
  {
    { Crypto_30_vHsm_Ipc_GetRxChannelWriteIndexOffset(0u), Crypto_30_vHsm_Ipc_GetRxChannelReadIndexOffset(0u), Crypto_30_vHsm_Ipc_GetRxChannelBufferOffset(0u) },
    { Crypto_30_vHsm_Ipc_GetRxChannelWriteIndexOffset(1u), Crypto_30_vHsm_Ipc_GetRxChannelReadIndexOffset(1u), Crypto_30_vHsm_Ipc_GetRxChannelBufferOffset(1u) },
    { Crypto_30_vHsm_Ipc_GetRxChannelWriteIndexOffset(2u), Crypto_30_vHsm_Ipc_GetRxChannelReadIndexOffset(2u), Crypto_30_vHsm_Ipc_GetRxChannelBufferOffset(2u) },
    { Crypto_30_vHsm_Ipc_GetRxChannelWriteIndexOffset(3u), Crypto_30_vHsm_Ipc_GetRxChannelReadIndexOffset(3u), Crypto_30_vHsm_Ipc_GetRxChannelBufferOffset(3u) }  
  },
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (0u),  /* stackProtectionCanaryPE1Offset */  
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (4u),  /* stackProtectionCanaryPE2Offset */  
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (8u),  /* seedOffset */                      
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (12u), /* detModuleIdOffset */               
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (16u), /* detInstanceIdOffset */             
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (20u), /* detApiIdOffset */                  
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (24u), /* detErrorIdOffset */                
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (28u), /* readyFlagOffset */                 
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (32u), /* endRamExecFlagOffset */            
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (36u), /* ramExecFlagOffset */               
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (40u)  /* detReportFlag */                   
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_Cfg.c
 *********************************************************************************************************************/
