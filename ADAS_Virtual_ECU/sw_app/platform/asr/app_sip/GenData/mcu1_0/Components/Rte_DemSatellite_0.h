/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_DemSatellite_0.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <DemSatellite_0>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_DEMSATELLITE_0_H
# define RTE_DEMSATELLITE_0_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_DemSatellite_0_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x1002_Vehicle_Speed_24_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x1002_Vehicle_Speed_24_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x1004_Battery_Voltage_24_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x1004_Battery_Voltage_24_ReadData(P2VAR(DataArrayType_uint8_1, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x1008_ECU_Life_Time_24_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x1008_ECU_Life_Time_24_ReadData(P2VAR(DataArrayType_uint8_3, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x1921_CombinedSignal_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x1921_CombinedSignal_ReadData(P2VAR(DataArrayType_uint8_9, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x2001_Odometer_24_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x2001_Odometer_24_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x200a_Ignition_ON_Counter_24_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x200a_Ignition_ON_Counter_24_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Aging_Counter_ID_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Calibrated_Successfully_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Calibration_Aborted_Failed_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Calibration_Not_Started_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Calibration_Pending_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Calibration_Running_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Camera_Occlusion_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Current_Gear_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_DisplayStatus_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Door_Status_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_ECU_Voltage_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_External_Temperature_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Frequency_Counter_ID_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_LiftgateAjar_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_New_Bit_Field_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Odometer_Value_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Odometer_Value_ReadData(P2VAR(DataArrayType_uint8_3, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Radio_Display_Status_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Reserved_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Reserved_1_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Reserved_2_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Steering_Wheel_Angle_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Supplier_Internal_Code_ReadData(Dem_EventIdType EventId, P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Supplier_Internal_Code_ReadData(Dem_EventIdType EventId, P2VAR(DataArrayType_uint8_9, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_THA_state_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_TRSC_Stat_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_TRSKM_and_USS_status_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_TireLines_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Touch_Screen_Status_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Touch_Screen_X_Coordinate_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Vehicle_Speed_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_CBReadData_Data_DID_0x1002_Vehicle_Speed_24_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x1002_Vehicle_Speed_24_ReadData
#  define Rte_Call_CBReadData_Data_DID_0x1004_Battery_Voltage_24_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x1004_Battery_Voltage_24_ReadData
#  define Rte_Call_CBReadData_Data_DID_0x1008_ECU_Life_Time_24_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x1008_ECU_Life_Time_24_ReadData
#  define Rte_Call_CBReadData_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_ReadData
#  define Rte_Call_CBReadData_Data_DID_0x1921_CombinedSignal_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x1921_CombinedSignal_ReadData
#  define Rte_Call_CBReadData_Data_DID_0x2001_Odometer_24_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x2001_Odometer_24_ReadData
#  define Rte_Call_CBReadData_Data_DID_0x200a_Ignition_ON_Counter_24_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x200a_Ignition_ON_Counter_24_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Aging_Counter_ID_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Aging_Counter_ID_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Calibrated_Successfully_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Calibrated_Successfully_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Calibration_Aborted_Failed_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Calibration_Aborted_Failed_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Calibration_Not_Started_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Calibration_Not_Started_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Calibration_Pending_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Calibration_Pending_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Calibration_Running_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Calibration_Running_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Camera_Occlusion_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Camera_Occlusion_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Current_Gear_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Current_Gear_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_DisplayStatus_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_DisplayStatus_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Door_Status_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Door_Status_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_ECU_Voltage_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_ECU_Voltage_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_External_Temperature_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_External_Temperature_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Frequency_Counter_ID_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Frequency_Counter_ID_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_LiftgateAjar_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_LiftgateAjar_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_New_Bit_Field_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_New_Bit_Field_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Odometer_Value_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Odometer_Value_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Radio_Display_Status_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Radio_Display_Status_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Reserved_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Reserved_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Reserved_1_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Reserved_1_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Reserved_2_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Reserved_2_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Steering_Wheel_Angle_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Steering_Wheel_Angle_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Supplier_Internal_Code_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Supplier_Internal_Code_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_THA_state_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_THA_state_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_TRSC_Stat_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_TRSC_Stat_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_TRSKM_and_USS_status_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_TRSKM_and_USS_status_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_TireLines_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_TireLines_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Touch_Screen_Status_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Touch_Screen_Status_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Touch_Screen_X_Coordinate_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Touch_Screen_X_Coordinate_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate_ReadData
#  define Rte_Call_CBReadData_Data_OccurrenceCounter_Vehicle_Speed_ReadData Rte_Call_DemSatellite_0_CBReadData_Data_OccurrenceCounter_Vehicle_Speed_ReadData

# endif /* !defined(RTE_CORE) */


# define DemSatellite_0_START_SEC_CODE
# include "DemSatellite_0_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Dem_SatelliteMainFunction Dem_SatelliteMainFunction
#  define RTE_RUNNABLE_GetDTCOfEvent Dem_GetDTCOfEvent
#  define RTE_RUNNABLE_GetDebouncingOfEvent Dem_GetDebouncingOfEvent
#  define RTE_RUNNABLE_GetEventEnableCondition Dem_GetEventEnableCondition
#  define RTE_RUNNABLE_GetEventExtendedDataRecordEx Dem_GetEventExtendedDataRecordEx
#  define RTE_RUNNABLE_GetEventFailed Dem_GetEventFailed
#  define RTE_RUNNABLE_GetEventFreezeFrameDataEx Dem_GetEventFreezeFrameDataEx
#  define RTE_RUNNABLE_GetEventStatus Dem_GetEventUdsStatus
#  define RTE_RUNNABLE_GetEventTested Dem_GetEventTested
#  define RTE_RUNNABLE_GetEventUdsStatus Dem_GetEventUdsStatus
#  define RTE_RUNNABLE_GetFaultDetectionCounter Dem_GetFaultDetectionCounter
#  define RTE_RUNNABLE_GetMonitorStatus Dem_GetMonitorStatus
#  define RTE_RUNNABLE_ResetEventDebounceStatus Dem_ResetEventDebounceStatus
#  define RTE_RUNNABLE_ResetEventStatus Dem_ResetEventStatus
#  define RTE_RUNNABLE_SetEventStatus Dem_SetEventStatus
# endif

FUNC(void, DemSatellite_0_CODE) Dem_SatelliteMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_GetDTCOfEvent(Dem_EventIdType parg0, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DTCOfEvent); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_GetDebouncingOfEvent(Dem_EventIdType parg0, P2VAR(Dem_DebouncingStateType, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DebouncingState); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_GetEventEnableCondition(Dem_EventIdType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) ConditionFullfilled); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_GetEventExtendedDataRecordEx(Dem_EventIdType parg0, uint8 RecordNumber, P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) BufSize); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_GetEventExtendedDataRecordEx(Dem_EventIdType parg0, uint8 RecordNumber, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) BufSize); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_GetEventFailed(Dem_EventIdType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) EventFailed); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_GetEventFreezeFrameDataEx(Dem_EventIdType parg0, uint8 RecordNumber, uint16 DataId, P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) BufSize); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_GetEventFreezeFrameDataEx(Dem_EventIdType parg0, uint8 RecordNumber, uint16 DataId, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) BufSize); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_GetEventUdsStatus(Dem_EventIdType parg0, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_VAR_NOINIT) UDSStatusByte); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_GetEventTested(Dem_EventIdType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) EventTested); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_GetEventUdsStatus(Dem_EventIdType parg0, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) UDSStatusByte); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_GetFaultDetectionCounter(Dem_EventIdType parg0, P2VAR(sint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_GetMonitorStatus(Dem_EventIdType parg0, P2VAR(Dem_MonitorStatusType, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) MonitorStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_ResetEventDebounceStatus(Dem_EventIdType parg0, Dem_DebounceResetStatusType DebounceResetStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_ResetEventStatus(Dem_EventIdType parg0); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemSatellite_0_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define DemSatellite_0_STOP_SEC_CODE
# include "DemSatellite_0_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CSDataServices_Data_DID_0x1002_Vehicle_Speed_24_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x1004_Battery_Voltage_24_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x1008_ECU_Life_Time_24_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x1921_CombinedSignal_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x2001_Odometer_24_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x200a_Ignition_ON_Counter_24_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Aging_Counter_ID_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Calibrated_Successfully_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Calibration_Aborted_Failed_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Calibration_Not_Started_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Calibration_Pending_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Calibration_Running_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Camera_Occlusion_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Current_Gear_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_DisplayStatus_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Door_Status_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_ECU_Voltage_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_External_Temperature_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Frequency_Counter_ID_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_LiftgateAjar_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_New_Bit_Field_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Odometer_Value_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Radio_Display_Status_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Reserved_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Reserved_1_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Reserved_2_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Steering_Wheel_Angle_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Supplier_Internal_Code_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_THA_state_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_TRSC_Stat_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_TRSKM_and_USS_status_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_TireLines_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Touch_Screen_Status_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Touch_Screen_X_Coordinate_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Vehicle_Speed_E_NOT_OK (1U)

#  define RTE_E_DiagnosticInfo_DEM_BUFFER_TOO_SMALL (21U)

#  define RTE_E_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE (10U)

#  define RTE_E_DiagnosticInfo_DEM_E_NO_FDC_AVAILABLE (14U)

#  define RTE_E_DiagnosticInfo_DEM_NO_SUCH_ELEMENT (48U)

#  define RTE_E_DiagnosticInfo_E_NOT_OK (1U)

#  define RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL (21U)

#  define RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE (10U)

#  define RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE (14U)

#  define RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT (48U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_BUFFER_TOO_SMALL (21U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE (10U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_E_NO_FDC_AVAILABLE (14U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_NO_SUCH_ELEMENT (48U)

#  define RTE_E_GeneralDiagnosticInfo_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_DEMSATELLITE_0_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_1330:  MISRA rule: Rule8.3
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
