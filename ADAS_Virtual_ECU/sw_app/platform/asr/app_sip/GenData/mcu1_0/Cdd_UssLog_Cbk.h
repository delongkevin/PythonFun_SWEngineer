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
 *            Module: Cdd
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Cdd_UssLog_Cbk.h
 *   Generation Time: 2024-02-13 13:07:46
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/



#if !defined (CDD_USSLOG_CBK_H)
# define CDD_USSLOG_CBK_H

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "ComStack_Types.h"



/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef CDD_USSLOG_USE_DUMMY_STATEMENT
#define CDD_USSLOG_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CDD_USSLOG_DUMMY_STATEMENT
#define CDD_USSLOG_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CDD_USSLOG_DUMMY_STATEMENT_CONST
#define CDD_USSLOG_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CDD_USSLOG_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CDD_USSLOG_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CDD_USSLOG_ATOMIC_VARIABLE_ACCESS
#define CDD_USSLOG_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CDD_USSLOG_PROCESSOR_TDA4VE88
#define CDD_USSLOG_PROCESSOR_TDA4VE88
#endif
#ifndef CDD_USSLOG_COMP_LLVMTEXASINSTRUMENTS
#define CDD_USSLOG_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef CDD_USSLOG_GEN_GENERATOR_MSR
#define CDD_USSLOG_GEN_GENERATOR_MSR
#endif
#ifndef CDD_USSLOG_CPUTYPE_BITORDER_LSB2MSB
#define CDD_USSLOG_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CDD_USSLOG_CONFIGURATION_VARIANT_PRECOMPILE
#define CDD_USSLOG_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CDD_USSLOG_CONFIGURATION_VARIANT_LINKTIME
#define CDD_USSLOG_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CDD_USSLOG_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CDD_USSLOG_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CDD_USSLOG_CONFIGURATION_VARIANT
#define CDD_USSLOG_CONFIGURATION_VARIANT CDD_USSLOG_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CDD_USSLOG_POSTBUILD_VARIANT_SUPPORT
#define CDD_USSLOG_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define CDD_USSLOG_COMIF  STD_OFF
#define CDD_USSLOG_COMIF_RX  STD_OFF
#define CDD_USSLOG_COMIF_TX  STD_OFF
#define CDD_USSLOG_COMIF_TRIGGERTRANSMIT  STD_OFF

#define CDD_USSLOG_PDUR_UL_COMIF  STD_ON
#define CDD_USSLOG_PDUR_UL_COMIF_TRIGGERTRANSMIT  STD_OFF

#define CDD_USSLOG_PDUR_UL_COMTP  STD_OFF

#define CDD_USSLOG_PDUR_LL_COMIF  STD_OFF
#define CDD_USSLOG_PDUR_LL_COMIF_TRIGGERTRANSMIT  STD_OFF

#define CDD_USSLOG_PDUR_LL_COMTP  STD_OFF

#define CDD_USSLOG_SOADUL_COMIF_RX  STD_OFF
#define CDD_USSLOG_SOADUL_COMIF_TRIGGERTRANSMIT  STD_OFF
#define CDD_USSLOG_SOADUL_COMIF_TXCONFIRMATION   STD_OFF

#define CDD_USSLOG_SOADUL_COMTP_RX  STD_OFF
#define CDD_USSLOG_SOADUL_COMTP_TX  STD_OFF





/**
 * \defgroup Cdd_UssLogHandleIdsPduRUpperLayerTx Handle IDs of handle space PduRUpperLayerTx.
 * \brief CddPduRUpperLayerContribution Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define Cdd_UssLogConf_CddPduRUpperLayerTxPdu_CddPduRUpperLayerTxPdu_LogPackedData1 1u
#define Cdd_UssLogConf_CddPduRUpperLayerTxPdu_CddPduRUpperLayerTxPdu_LogPackedData2 2u
#define Cdd_UssLogConf_CddPduRUpperLayerTxPdu_CddPduRUpperLayerTxPdu_LogPackedNoise 0u
#define Cdd_UssLogConf_CddPduRUpperLayerTxPdu_CddPduRUpperLayerTxPdu_LogSnr_01 3u
#define Cdd_UssLogConf_CddPduRUpperLayerTxPdu_CddPduRUpperLayerTxPdu_LogSnr_02 4u
#define Cdd_UssLogConf_CddPduRUpperLayerTxPdu_CddPduRUpperLayerTxPdu_LogSnr_03 5u
#define Cdd_UssLogConf_CddPduRUpperLayerTxPdu_CddPduRUpperLayerTxPdu_LogSnr_04 6u
#define Cdd_UssLogConf_CddPduRUpperLayerTxPdu_CddPduRUpperLayerTxPdu_LogSnr_05 7u
#define Cdd_UssLogConf_CddPduRUpperLayerTxPdu_CddPduRUpperLayerTxPdu_LogSnr_06 8u
#define Cdd_UssLogConf_CddPduRUpperLayerTxPdu_CddPduRUpperLayerTxPdu_LogSnr_07 9u
/**\} */

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
# define CDD_USSLOG_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
# include "Cdd_UssLog_MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_MemMap */
/*lint -restore */



/*! \defgroup ProvidedCddCdd_UssLogUpperLayerComIf2PduR Provided Cdd_UssLog communication interface to PduR
    \brief    These services have to be provided by the Cdd_UssLog if the CDD is an upper layer for the PduR. */
/*\{*/

/**********************************************************************************************************************
  Cdd_UssLog_RxIndication
**********************************************************************************************************************/
/*! \brief         The function is called to indicate the complete reception of a RX I-PDU.
    \param[in]     RxPduId      id of the IF CddPduRUpperLayerRxPdu.
    \param[in]     PduInfoPtr   Payload information of the received I-PDU (pointer to data and data length).
    \return        none
    \pre           The Cdd_UssLog is initialized and active.
    \context       The function can be called in interrupt and on task level and should not to interrupted by another
                   Cdd_UssLog_RxIndication call for the same RxPduId.
    \note          The function is called by the PduR.
**********************************************************************************************************************/
FUNC(void, CDD_USSLOG_CODE) Cdd_UssLog_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, CDD_USSLOG_APPL_DATA) PduInfoPtr);

/**********************************************************************************************************************
  Cdd_UssLog_TxConfirmation
**********************************************************************************************************************/
/*! \brief         The function is called to confirm the complete transmission of a TX I-PDU.
    \param[in]     TxPduId      id of the IF CddPduRUpperLayerTxPdu.
    \return        none
    \pre           The Cdd_UssLog is initialized and active.
    \context       The function can be called in interrupt and on task level and should not to interrupted by another
                   Cdd_UssLog_TxConfirmation call for the same TxPduId.
    \note          The function is called by the PduR.
**********************************************************************************************************************/
FUNC(void, CDD_USSLOG_CODE) Cdd_UssLog_TxConfirmation(PduIdType TxPduId);

#if (CDD_USSLOG_PDUR_UL_COMIF_TRIGGERTRANSMIT == STD_ON)
/**********************************************************************************************************************
  Cdd_UssLog_TriggerTransmit
**********************************************************************************************************************/
/*! \brief         The function is calledto request the TX I-PDU data before transmission.
    \param[in]     TxPduId      id of the IF CddPduRUpperLayerTxPdu.
    \param[in,out] PduInfoPtr   Contains a pointer to a buffer (SduDataPtr) to where the SDU
                                data shall be copied, and the available buffer size in SduLengh.
                                On return, the service will indicate the length of the copied SDU
                                data in SduLength.
    \return        E_OK         SDU has been copied and SduLength indicates the number of copied bytes.
    \return        E_NOT_OK     No data has been copied, because
                                Cdd is not initialized
                                or TxPduId is not valid
                                or PduInfoPtr is NULL_PTR
                                or SduDataPtr is NULL_PTR
                                or SduLength is too small.
    \pre           The Cdd_UssLog is initialized and active.
    \context       The function can be called in interrupt and on task level and should not to interrupted by another
                   Cdd_UssLog_TriggerTransmit call for the same TxPduId.
    \note          The function is called by the PduR.
**********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_USSLOG_CODE) Cdd_UssLog_TriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, CDD_USSLOG_APPL_DATA) PduInfoPtr);
#endif

/*\}*/




# define CDD_USSLOG_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
# include "Cdd_UssLog_MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_MemMap */
/*lint -restore */

#endif  /* CDD_USSLOG_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Cdd_UssLog_Cbk.h
**********************************************************************************************************************/


