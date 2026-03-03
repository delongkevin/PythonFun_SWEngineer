#ifndef CDD_E2EWRAPPER_H_
#define CDD_E2EWRAPPER_H_

# include "Std_Types.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#define ME_E2E_P99_MAX_COUNTER_VALUE      15u
#define ME_CRC_INITIAL_VALUE8          (0xFFu)
#define ME_CRC_POLYNOMIAL_8            (0x1Du)
#define ME_CRC_FINAL_XOR_CRC8          (0xFFu)

typedef P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataRefType_t;

 /* ===========================================================================
 *
 *   Name:  f_E2E_ProtectVerifyInputs_u8
 *
 *   Function: Check the input parameter
 *
 *   Inputs: None
 *
 *   Outputs: None
 *
 *   Side Effects: None
 *
 *   Remarks: None
 *
 * ========================================================================= */
static Std_ReturnType f_E2E_ProtectVerifyInputs_u8(const E2E_MEP_ConfigType* i_ConfigPtr_ps, const E2E_MEP_ProtectStateType* i_StatePtr_ps, const uint8* i_DataPtr_pu8);
 /* ===========================================================================
 *
 *   Name:  f_E2E_ComputeCRC_u8
 *
 *   Function: Calculate the CRC of the data
 *   
 *   Inputs: None
 *
 *   Outputs: None
 *
 *   Side Effects: None
 *
 *   Remarks: None
 *
 * ========================================================================= */
static uint8 f_E2E_ComputeCRC_u8(const uint8* i_DataPtr_pu8, const E2E_MEP_ConfigType* i_ConfigPtr_ps, uint8 i_Counter_u8);
 /* ===========================================================================
 *
 *   Name:  f_E2E_CalculateCRC_u8
 *
 *   Function: Calculate the CRC of the data
 *   
 *   Inputs: None
 *
 *   Outputs: None
 *
 *   Side Effects: None
 *
 *   Remarks: None
 *
 * ========================================================================= */
static uint8 f_E2E_CalculateCRC_u8(const uint8* i_CrcDataPtr_pu8, uint32 i_CrcLength_u32, uint8 i_CrcStartValue_u8, boolean i_CrcIsFirstCall_b);
 /* ===========================================================================
 *
 *   Name:  f_E2E_CalculateCRCRuntime_u8
 *
 *   Function: Calculate the CRC of the data
 *   
 *   Inputs: None
 *
 *   Outputs: None
 *
 *   Side Effects: None
 *
 *   Remarks: None
 *
 * ========================================================================= */
static uint8 f_E2E_CalculateCRCRuntime_u8(uint32 i_CrcLength_u32, Crc_DataRefType_t i_CrcDataPtr_pu8, uint8 i_CrcValue_u8, uint8 i_CrcPoly_u8);

 /* ===========================================================================
 *
 *   Name:  f_E2ECheckVerifyInputs_u8
 *
 *   Function: Verify the input parameter
 *   
 *   Inputs: None
 *
 *   Outputs: None
 *
 *   Side Effects: None
 *
 *   Remarks: None
 *
 * ========================================================================= */
static Std_ReturnType f_E2ECheckVerifyInputs_u8(const E2E_MEP_ConfigType* i_ConfigPtr_ps, const E2E_MEP_CheckStateType* b_StatePtr_ps, const uint8* i_DataPtr_u8);
 /* ===========================================================================
 *
 *   Name:  f_E2E_CheckDeltaCounter_v
 *
 *   Function: Check the counter
 *   
 *   Inputs: None
 *
 *   Outputs: None
 *
 *   Side Effects: None
 *
 *   Remarks: None
 *
 * ========================================================================= */
static void f_E2E_CheckDeltaCounter_v(const E2E_MEP_ConfigType* i_ConfigPtr_ps, E2E_MEP_CheckStateType* b_StatePtr_ps, uint8 i_ReceivedCounter_u8);
 /* ===========================================================================
 *
 *   Name:  f_E2E_CheckSync_v
 *
 *   Function: Check for sync
 *   
 *   Inputs: None
 *
 *   Outputs: None
 *
 *   Side Effects: None
 *
 *   Remarks: None
 *
 * ========================================================================= */
static void f_E2E_CheckSync_v(const E2E_MEP_ConfigType* i_ConfigPtr_ps, E2E_MEP_CheckStateType* b_StatePtr_ps);

#endif /*CDD_E2EWRAPPER_H_*/
