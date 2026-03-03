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
 *            Module: Xcp
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Xcp_Lcfg.h
 *   Generation Time: 2024-02-13 13:07:50
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

    
#if !defined(XCP_LCFG_H)
#define XCP_LCFG_H

#include "Xcp_Types.h"

#define XCP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#if( XCP_DAQ == STD_ON )
extern CONSTP2VAR(uint8, XCP_VAR_NOINIT, AUTOMATIC) Xcp_SendQueueRef[XCP_NUMBER_OF_CORES];
extern CONST(uint32, XCP_CONST) Xcp_SendQueueSize[XCP_NUMBER_OF_CORES];
extern CONST(Xcp_ECcIDType, XCP_CONST) Xcp_ECcIdMapping[XCP_MAX_EVENT];
#endif

extern CONST(Xcp_TlApiType, XCP_CONST) Xcp_TlApi[1];

/* Events */
extern CONST(uint8, XCP_CONST) kXcpEventName_0[21];

extern CONSTP2CONST(uint8, XCP_CONST, XCP_CONST) kXcpEventName[1];
extern CONST(uint8, XCP_CONST) kXcpEventNameLength[1];
extern CONST(uint8, XCP_CONST) kXcpEventCycle[1];
extern CONST(uint8, XCP_CONST) kXcpEventUnit[1];
extern CONST(uint8, XCP_CONST) kXcpEventDirection[1];
extern CONST(uint8, XCP_CONST) kXcpEventNumDaq[1];


/* Event Channel SNV IDs */



/**
 * \defgroup XcpHandleIdsEventChannelHandleIDs Handle IDs of handle space EventChannel Handle IDs.
 * \brief Symbolic Name Values (SNVs) for EventChannel Handles
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define XcpConf_XcpEventChannel_XcpEventChannel_10ms                  0
/**\} */


/* Flash programming */

#define XCP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */


#endif /* XCP_LCFG_H */   

