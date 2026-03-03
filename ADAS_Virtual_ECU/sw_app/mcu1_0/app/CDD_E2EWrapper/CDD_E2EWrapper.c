/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  CDD_E2EWrapper.c
 *           Config:  D:/git/L2H4060_Software_develop/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  CDD_E2EWrapper
 *  Generation Time:  2023-05-21 16:54:30
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <CDD_E2EWrapper>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * E2E_MEP_CheckStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * E2E_MEP_DataIDMode
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_CDD_E2EWrapper.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CDD_E2EWrapper.h"

#if defined( BUILD_MCU1_0 )
#define CDD_E2EWrapper_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_E2EWrapper_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define CDD_E2EWrapper_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_E2EWrapper_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define CDD_E2EWrapper_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "CDD_E2EWrapper_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define CDD_E2EWrapper_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "CDD_E2EWrapper_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define CDD_E2EWrapper_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "CDD_E2EWrapper_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define CDD_E2EWrapper_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "CDD_E2EWrapper_MemMap.h"
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * E2E_MEP_CheckStatusType: Integer in interval [0...255]
 * E2E_MEP_DataIDMode: Integer in interval [0...255]
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Record Types:
 * =============
 * E2E_MEP_CheckStateType: Record with elements
 *   LastValidCounter of type uint8
 *   MaxDeltaCounter of type uint8
 *   WaitForFirstData of type boolean
 *   NewDataAvailable of type boolean
 *   LostData of type uint8
 *   Status of type E2E_MEP_CheckStatusType
 *   SyncCounter of type uint8
 *   NoNewOrRepeatedDataCounter of type uint8
 * E2E_MEP_ConfigType: Record with elements
 *   CounterOffset of type uint16
 *   CRCOffset of type uint16
 *   DataID of type uint16
 *   DataIDNibbleOffset of type uint16
 *   DataIDMode of type E2E_MEP_DataIDMode
 *   DataLength of type uint16
 *   MaxDeltaCounterInit of type uint8
 *   MaxNoNewOrRepeatedData of type uint8
 *   SyncCounterInit of type uint8
 * E2E_MEP_ProtectStateType: Record with elements
 *   Counter of type uint8
 *
 *********************************************************************************************************************/


#define CDD_E2EWrapper_START_SEC_CODE
#include "CDD_E2EWrapper_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_E2EWrapperCheck
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ME_E2E_Check> of PortPrototype <PpE2EServices>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RE_E2EWrapperCheck(E2E_MEP_ConfigType *ConfigPtr, E2E_MEP_CheckStateType *StatePtr, uint8 *DataPtr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL
 *   RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL
 *   RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG
 *   RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG
 *   RTE_E_IF_E2EServices_ME_E2E_E_INTERR
 *   RTE_E_IF_E2EServices_ME_E2E_E_INTERR
 *   RTE_E_IF_E2EServices_ME_E2E_E_WRONGSTATE
 *   RTE_E_IF_E2EServices_ME_E2E_E_WRONGSTATE
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_E2EWrapperCheck_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_E2EWrapper_CODE) RE_E2EWrapperCheck(P2VAR(E2E_MEP_ConfigType, AUTOMATIC, RTE_CDD_E2EWRAPPER_APPL_VAR) ConfigPtr, P2VAR(E2E_MEP_CheckStateType, AUTOMATIC, RTE_CDD_E2EWRAPPER_APPL_VAR) StatePtr, P2VAR(uint8, AUTOMATIC, RTE_CDD_E2EWRAPPER_APPL_VAR) DataPtr) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_E2EWrapperCheck (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {9B343CF3-4765-4a6f-9966-6FA61D3820E8}*/
   /* #10 Check validity of input parameters */
    Std_ReturnType v_ret_u8 = f_E2ECheckVerifyInputs_u8(ConfigPtr, StatePtr, DataPtr); /* SBSW_E2E_03 */

    if (v_ret_u8 == E_OK)
    {
        uint8 v_ReceivedCounter_u8;
        uint8 v_ComputedCRC_u8;
        uint8 v_ReceivedCRC_u8;
        uint16 v_ComputedOffset_u16;

        /* #20 Maximum allowed delta between previous and current counter is incremented every function invocation */
        if (StatePtr->MaxDeltaCounter < ME_E2E_P99_MAX_COUNTER_VALUE)
        {
            StatePtr->MaxDeltaCounter++; /* SBSW_E2E_03 */
        }
        /* #30 Check if new data is available */
        if (StatePtr->NewDataAvailable == TRUE)
        {
            v_ComputedOffset_u16 = ConfigPtr->CounterOffset >> 3u;
            /* #40 Counter is read from Data, at the configured offset */
            if ((ConfigPtr->CounterOffset & 0x07u) == 0u)
            {
                v_ReceivedCounter_u8 = DataPtr[v_ComputedOffset_u16] & 0x0Fu;
            }
            else
            {
                v_ReceivedCounter_u8 = (DataPtr[v_ComputedOffset_u16] & 0xF0u) >> 4u;
            }

            /* #50 Check if v_ReceivedCounter_u8 is within range */
            if (v_ReceivedCounter_u8 <= ME_E2E_P99_MAX_COUNTER_VALUE) /*PRQA S 2991, 2995*/
            {

                /* #60 CRC is read from Data */
                v_ComputedOffset_u16 = ConfigPtr->CRCOffset >> 3u;
                v_ReceivedCRC_u8 = DataPtr[v_ComputedOffset_u16];

                /* #80 Calculate CRC in the same way as the Sender did */
                v_ComputedCRC_u8 = f_E2E_ComputeCRC_u8(DataPtr, ConfigPtr, v_ReceivedCounter_u8); /* SBSW_E2E_03 */

                /* #100 Check if received CRC matches the computed one */
                if (v_ReceivedCRC_u8 == v_ComputedCRC_u8)
                {
                    /* #110 Check if any correct data has already been received */
                    if (StatePtr->WaitForFirstData == FALSE)
                    {
                        /* #120 Evaluate counter value of subsequent data */
                        f_E2E_CheckDeltaCounter_v(ConfigPtr, StatePtr, v_ReceivedCounter_u8); /* SBSW_E2E_03 */
                    }
                    else
                    {
                        StatePtr->WaitForFirstData = FALSE;                         /* SBSW_E2E_03 */
                        StatePtr->MaxDeltaCounter = ConfigPtr->MaxDeltaCounterInit; /* SBSW_E2E_03 */
                        StatePtr->LastValidCounter = v_ReceivedCounter_u8;               /* SBSW_E2E_03 */
                        StatePtr->Status = E2E_MEP_STATUS_INITIAL;                   /* SBSW_E2E_03 */
                    }
                }
                else
                {
                    StatePtr->Status = E2E_MEP_STATUS_WRONGCRC; /* SBSW_E2E_03 */
                }
            }
            else
            {
                v_ret_u8 = RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG;
            }
        }
        else
        {
            if (StatePtr->NoNewOrRepeatedDataCounter < ME_E2E_P99_MAX_COUNTER_VALUE)
            {
                StatePtr->NoNewOrRepeatedDataCounter++; /* SBSW_E2E_03 */
            }
            StatePtr->Status = E2E_MEP_STATUS_NONEWDATA; /* SBSW_E2E_03 */
        }
    }

    return v_ret_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_E2EWrapperProtect
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ME_E2E_Protect> of PortPrototype <PpE2EServices>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RE_E2EWrapperProtect(E2E_MEP_ConfigType *ConfigPtr, E2E_MEP_ProtectStateType *StatePtr, uint8 *DataPtr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL
 *   RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL
 *   RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL
 *   RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG
 *   RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG
 *   RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG
 *   RTE_E_IF_E2EServices_ME_E2E_E_INTERR
 *   RTE_E_IF_E2EServices_ME_E2E_E_INTERR
 *   RTE_E_IF_E2EServices_ME_E2E_E_INTERR
 *   RTE_E_IF_E2EServices_ME_E2E_E_WRONGSTATE
 *   RTE_E_IF_E2EServices_ME_E2E_E_WRONGSTATE
 *   RTE_E_IF_E2EServices_ME_E2E_E_WRONGSTATE
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_E2EWrapperProtect_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_E2EWrapper_CODE) RE_E2EWrapperProtect(P2VAR(E2E_MEP_ConfigType, AUTOMATIC, RTE_CDD_E2EWRAPPER_APPL_VAR) ConfigPtr, P2VAR(E2E_MEP_ProtectStateType, AUTOMATIC, RTE_CDD_E2EWRAPPER_APPL_VAR) StatePtr, P2VAR(uint8, AUTOMATIC, RTE_CDD_E2EWRAPPER_APPL_VAR) DataPtr) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_E2EWrapperProtect (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {7FB648AA-4231-4e67-A929-40F0002CE570}*/
    /* #10 Check validity of input parameters */
    Std_ReturnType v_ret_u8 = f_E2E_ProtectVerifyInputs_u8(ConfigPtr, StatePtr, DataPtr); /* SBSW_E2E_03 */
    if (v_ret_u8 == E2E_MEP_STATUS_OK)
    {
        uint8 v_ComputedCRC_u8;
        uint16 v_ComputedOffset_u16 = ConfigPtr->CounterOffset >> 3u;
        /* #20 Counter is written to position in DataPtr, Offset is pointing to */
        /* #21 Write value of Counter to low nibble in DataPtr, v_ComputedOffset_u16 is pointing to */
        if ((ConfigPtr->CounterOffset & 0x07u) == 0u)
        {
            DataPtr[v_ComputedOffset_u16] = (DataPtr[v_ComputedOffset_u16] & 0xF0u) /* SBSW_E2E_03 */
                                      | StatePtr->Counter;
        }
        /* #22 Write value of Counter to high nibble in DataPtr, v_ComputedOffset_u16 is pointing to */
        else
        {
            DataPtr[v_ComputedOffset_u16] = (DataPtr[v_ComputedOffset_u16] & 0x0Fu) /* SBSW_E2E_03 */
                                      | (StatePtr->Counter << 4u);
        }
        v_ComputedCRC_u8 = f_E2E_ComputeCRC_u8(DataPtr, ConfigPtr, StatePtr->Counter); /* SBSW_E2E_03 */

        /* #50 Write computed CRC to DataPtr, where CRCOffset is pointing to */
        DataPtr[ConfigPtr->CRCOffset >> 3u] = v_ComputedCRC_u8; /* SBSW_E2E_03 */

        /* #60 Increment value of Counter. Valid values are 0..14 */
        StatePtr->Counter = (StatePtr->Counter + 1u) % (ME_E2E_P99_MAX_COUNTER_VALUE + 1u); /* SBSW_E2E_03 */
    }
    return v_ret_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_E2EWrapper_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_E2EWrapper_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_E2EWrapper_CODE) RE_E2EWrapper_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_E2EWrapper_Init
 *********************************************************************************************************************/
  /* DD-ID: {17A3094B-B714-4e42-80C7-AE135E61847E}*/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}





/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


static Std_ReturnType f_E2E_ProtectVerifyInputs_u8(const E2E_MEP_ConfigType *i_ConfigPtr_ps, const E2E_MEP_ProtectStateType* i_StatePtr_ps,const  uint8* i_DataPtr_pu8)
{
  /* DD-ID: {A15A97EB-4408-4d45-8F21-48B58E652080}*/
    Std_ReturnType v_ret_u8 = RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL;

    /* #10 Check input pointer parameter for NULL_PTR */
    if ((i_ConfigPtr_ps != NULL_PTR) && (i_StatePtr_ps != NULL_PTR) && (i_DataPtr_pu8 != NULL_PTR))
    {
        /* #20 Check if value of Counter is within valid range */
        if (i_StatePtr_ps->Counter > ME_E2E_P99_MAX_COUNTER_VALUE)
        {
            v_ret_u8 = RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG;
        }
        else
        {
            v_ret_u8 = E_OK;
        }
    }

    return v_ret_u8;
}

 /* ===========================================================================
 *
 *
 *
 * ========================================================================= */

static uint8 f_E2E_ComputeCRC_u8(const uint8* i_DataPtr_pu8, const E2E_MEP_ConfigType* i_ConfigPtr_ps, uint8 i_Counter_u8)
{
  /* DD-ID: {5E6857D4-7F7D-4455-977C-DF6452A4481E}*/
    uint8 v_crc_u8 = ME_CRC_INITIAL_VALUE8;
    uint16 v_CalculatedOffset_u16;
    (void)i_Counter_u8;

     v_CalculatedOffset_u16 = i_ConfigPtr_ps->CRCOffset >> 3u;
    /* #30 CRC is computed over the area before the CRC position (if CRC is not the first byte)  */
    if ((v_CalculatedOffset_u16) > 0u)
    {
        v_crc_u8 = f_E2E_CalculateCRC_u8(i_DataPtr_pu8, v_CalculatedOffset_u16, 0XFF, FALSE);
    }
    return v_crc_u8;
}

 /* ===========================================================================
 *
 *
 *
 * ========================================================================= */

static uint8 f_E2E_CalculateCRC_u8(const uint8* i_CrcDataPtr_pu8, uint32 i_CrcLength_u32, uint8 i_CrcStartValue_u8, boolean i_CrcIsFirstCall_b)
{
  /* DD-ID: {2034997E-9A30-4fbe-93D0-C6090860B563}*/
    uint8 v_CrcValue_u8;
    if (i_CrcIsFirstCall_b == TRUE)
    {
        v_CrcValue_u8 = ME_CRC_INITIAL_VALUE8;
    }
    else
    {
        v_CrcValue_u8 = (ME_CRC_FINAL_XOR_CRC8 ^ i_CrcStartValue_u8);
    }
     v_CrcValue_u8 = f_E2E_CalculateCRCRuntime_u8(i_CrcLength_u32, i_CrcDataPtr_pu8, 0xFF, ME_CRC_POLYNOMIAL_8); 
      /* #40 Final CRC value is XORed */
     return v_CrcValue_u8 ^ ME_CRC_FINAL_XOR_CRC8;
}

 /* ===========================================================================
 *
 *
 *
 * ========================================================================= */

static uint8 f_E2E_CalculateCRCRuntime_u8(uint32 i_CrcLength_u32, Crc_DataRefType_t i_CrcDataPtr_pu8, uint8 i_CrcValue_u8, uint8 i_CrcPoly_u8)
{
  /* DD-ID: {493670F3-A93A-4a03-8C6E-2466CD65AB89}*/
    uint32 v_Crc_DataPtrAddr_u32;
    uint8 v_Crc_LoopCounter_u8;
    uint8 v_Crc_CalcValue_u8;

    v_Crc_CalcValue_u8 = i_CrcValue_u8;

    /* #10 Perform CRC calculation for each byte in Crc_DataPtr */
    for (v_Crc_DataPtrAddr_u32 = 0; v_Crc_DataPtrAddr_u32 < i_CrcLength_u32; v_Crc_DataPtrAddr_u32++)
    {
        /* #20 XOR next byte of Crc_DataPtr with current CRC value. This is equivalent to calculating CRC value of
         *     concatenated bytes */
        v_Crc_CalcValue_u8 ^= i_CrcDataPtr_pu8[v_Crc_DataPtrAddr_u32];

        /* #30 Perform modulo-2 division, a bit at a time */
        for (v_Crc_LoopCounter_u8 = 0u; v_Crc_LoopCounter_u8 < 8u; v_Crc_LoopCounter_u8++)
        {
            /* #35 If MSB is 1, CRC value is XORed with polynomial */
            if ((v_Crc_CalcValue_u8 & (uint8)0x80u) > 0u)
            {
                v_Crc_CalcValue_u8 = ((uint8)(v_Crc_CalcValue_u8 << 1u)) ^ i_CrcPoly_u8;
            }
            else
            {
                v_Crc_CalcValue_u8 = (uint8)(v_Crc_CalcValue_u8 << 1u);
            }
        }
    }

    return v_Crc_CalcValue_u8;
}

 /* ===========================================================================
 *
 *
 *
 * ========================================================================= */

static Std_ReturnType f_E2ECheckVerifyInputs_u8(const E2E_MEP_ConfigType* i_ConfigPtr_ps, const E2E_MEP_CheckStateType* b_StatePtr_ps, const uint8* i_DataPtr_u8)
{
  /* DD-ID: {418A6E16-6682-4530-921D-6C295048A624}*/
    Std_ReturnType v_ret_u8 = RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL; 
    /* #10 Check input parameter for NULL_PTR */
    if (  (i_ConfigPtr_ps != NULL_PTR)
       && (b_StatePtr_ps != NULL_PTR)
       && (i_DataPtr_u8 != NULL_PTR)
    )
    {
        /* #20 Check if counter values are within valid range */
        if (  (b_StatePtr_ps->LastValidCounter > ME_E2E_P99_MAX_COUNTER_VALUE)
           || (b_StatePtr_ps->MaxDeltaCounter > ME_E2E_P99_MAX_COUNTER_VALUE)
           || (b_StatePtr_ps->SyncCounter > i_ConfigPtr_ps->SyncCounterInit)
           || (b_StatePtr_ps->NoNewOrRepeatedDataCounter > ME_E2E_P99_MAX_COUNTER_VALUE)
           )
        {
            v_ret_u8 = RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG;
        }
        else
        {
            v_ret_u8 = E_OK;
        }
    }
    return v_ret_u8;
}
/* ===========================================================================
 *
 *
 *
 * ========================================================================= */
static void f_E2E_CheckDeltaCounter_v(const E2E_MEP_ConfigType* i_ConfigPtr_ps, E2E_MEP_CheckStateType* b_StatePtr_ps, uint8 i_ReceivedCounter_u8)
{
  /* DD-ID: {8BA70F36-2E03-421e-9003-F47EDB50A01E}*/
    /* #10 Calculate delta between received and last valid counter. Overflow is also considered */
    uint8 v_DeltaCounter_u8 = (uint8)(i_ReceivedCounter_u8 - b_StatePtr_ps->LastValidCounter) & 0x0Fu; /* PRQA S 2897 */ /* MD_MSR_Dir1.1 */

    /* #20 Check if counter didn't change, thus no new data was received */
    if (v_DeltaCounter_u8 == 0u)
    {
        if (b_StatePtr_ps->NoNewOrRepeatedDataCounter < ME_E2E_P99_MAX_COUNTER_VALUE)
        {
            b_StatePtr_ps->NoNewOrRepeatedDataCounter++; /* SBSW_E2E_03 */
        }
        b_StatePtr_ps->Status = E2E_MEP_STATUS_REPEATED; /* SBSW_E2E_03 */
    }
    else
    {
        /* #30 If v_DeltaCounter_u8 equals 1, the correct data was received. No message was lost in between */
        if (v_DeltaCounter_u8 == 1u)
        {
            b_StatePtr_ps->MaxDeltaCounter = i_ConfigPtr_ps->MaxDeltaCounterInit; /* SBSW_E2E_03 */
            b_StatePtr_ps->LastValidCounter = i_ReceivedCounter_u8; /* SBSW_E2E_03 */
            b_StatePtr_ps->LostData = 0u; /* SBSW_E2E_03 */
            b_StatePtr_ps->Status = E2E_MEP_STATUS_OK; /* SBSW_E2E_03 */
            f_E2E_CheckSync_v(i_ConfigPtr_ps, b_StatePtr_ps); /* SBSW_E2E_03 */
        }
        else
        {
            /* #40 Received data is not subsequent data, but counter is still tolerable */
            if (v_DeltaCounter_u8 <= b_StatePtr_ps->MaxDeltaCounter)
            {
                b_StatePtr_ps->MaxDeltaCounter = i_ConfigPtr_ps->MaxDeltaCounterInit; /* SBSW_E2E_03 */
                b_StatePtr_ps->LastValidCounter = i_ReceivedCounter_u8; /* SBSW_E2E_03 */
                b_StatePtr_ps->LostData = v_DeltaCounter_u8 - 1u; /* SBSW_E2E_03 */
                b_StatePtr_ps->Status = E2E_MEP_STATUS_OKSOMELOST; /* SBSW_E2E_03 */
                f_E2E_CheckSync_v(i_ConfigPtr_ps, b_StatePtr_ps); /* SBSW_E2E_03 */
            }
            /* #50 Counter of received data is out of range */
            else
            {
                b_StatePtr_ps->NoNewOrRepeatedDataCounter = 0u; /* SBSW_E2E_03 */
                b_StatePtr_ps->SyncCounter = i_ConfigPtr_ps->SyncCounterInit; /* SBSW_E2E_03 */
                /* if (b_StatePtr_ps->SyncCounter > 0u) */ /* To fix defect 22290423 */
                {
                    b_StatePtr_ps->MaxDeltaCounter = i_ConfigPtr_ps->MaxDeltaCounterInit; /* SBSW_E2E_03 */
                    b_StatePtr_ps->LastValidCounter = i_ReceivedCounter_u8; /* SBSW_E2E_03 */
                }
                b_StatePtr_ps->Status = E2E_MEP_STATUS_WRONGSEQUENCE; /* SBSW_E2E_03 */
            }
        }
    }
}

 /* ===========================================================================
 *
 *
 *
 * ========================================================================= */
static void f_E2E_CheckSync_v(const E2E_MEP_ConfigType* i_ConfigPtr_ps, E2E_MEP_CheckStateType* b_StatePtr_ps)
{
  /* DD-ID: {7338EE81-153A-40c3-81EF-D6F3A6CD7B23}*/
    /* #10 Check if NoNewOrRepeatedDataCounter didn't reach its limit */
    if (b_StatePtr_ps->NoNewOrRepeatedDataCounter <= i_ConfigPtr_ps->MaxNoNewOrRepeatedData)
    {
        b_StatePtr_ps->NoNewOrRepeatedDataCounter = 0u; /* SBSW_E2E_03 */

        /* #20 Status is STATUS_SYNC in case SyncCounter is greater than 0 */
        if (b_StatePtr_ps->SyncCounter > 0u)
        {
            b_StatePtr_ps->SyncCounter--; /* SBSW_E2E_03 */
            b_StatePtr_ps->Status = E2E_MEP_STATUS_SYNC; /* SBSW_E2E_03 */
        }
    }
    else
    {
        b_StatePtr_ps->NoNewOrRepeatedDataCounter = 0u; /* SBSW_E2E_03 */
        b_StatePtr_ps->SyncCounter = i_ConfigPtr_ps->SyncCounterInit; /* SBSW_E2E_03 */
        b_StatePtr_ps->Status = E2E_MEP_STATUS_SYNC; /* SBSW_E2E_03 */
    }
}

#define CDD_E2EWrapper_STOP_SEC_CODE
#include "CDD_E2EWrapper_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
