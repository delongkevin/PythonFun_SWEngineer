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
 *            Module: Dem
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dem_Lcfg.c
 *   Generation Time: 2025-09-16 12:41:51
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/



/* configuration, interrupt handling implementations differ from the
 * source identification define used here. The naming
 * schemes for those files can be taken from this list:
 *
 * Dem.c:         DEM_SOURCE
 * Dem_Lcfg.c:    DEM_LCFG_SOURCE
 * Dem_PBcfg.c:   DEM_PBCFG_SOURCE */
#define DEM_LCFG_SOURCE


/**********************************************************************************************************************
  MISRA JUSTIFICATIONS
**********************************************************************************************************************/

/* PRQA S 0828 EOF */ /* MD_MSR_1.1_828 */                                      /* Maximum '#if...' nesting exceeds 8 levels - program is non-conforming -- caused by #include'd files. */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */                                      /* Number of macro definitions exceeds 1024 - program is non-conforming -- caused by #include'd files. */
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */                                          /* Identifier does not differ in 32 significant characters -- caused by Autosar algorithm for unique symbolic names. */
/* PRQA S 0612 EOF */ /* MD_DEM_1.1_612 */                                      /* The size of an object exceeds 32767 bytes - program is non-conforming -- caused by large user configuration. */
/* PRQA S 0613 EOF */ /* MD_DEM_613 */                                          /* The size of an object exceeds 65535 bytes - program is non-conforming -- caused by large user configuration. */


/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

#include "Dem.h"
#include "Os.h"
#if (DEM_CFG_USE_NVM == STD_ON)
# include "NvM.h"                                                               /* get: symbolic names for NvM block IDs */
#endif
#if (DEM_CFG_SUPPORT_J1939 == STD_ON)
# include "J1939Nm.h"                                                           /* get: symbolic names for J1939Nm node IDs */
#endif
#if (DEM_CFG_USE_RTE == STD_ON)
/* DEM used with RTE */
# include "Rte_DemMaster_0.h"
#endif
#include "Dem_AdditionalIncludeCfg.h"                                           /* additional, configuration defined files */

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
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
  Dem_Cfg_CallbackDtcStatusChanged
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_DtcStatusChangedFPtrType, DEM_CONST) Dem_Cfg_CallbackDtcStatusChanged[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CallbackDtcStatusChanged  */
  /*     0 */ vRoE_OnDTCStatusChange   
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataCollectionTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataCollectionTable
  \details
  Element                                Description
  IdNumber                           
  Trigger                                Trigger for storage and update of extended data records
  CollectionSize                     
  DataElementTableCol2ElmtIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_DataElementTableCol2ElmtInd
  DataElementTableCol2ElmtIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_DataElementTableCol2ElmtInd
  StorageKind                        
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataCollectionTableType, DEM_CONST) Dem_Cfg_DataCollectionTable[9] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IdNumber  Trigger                     CollectionSize  DataElementTableCol2ElmtIndEndIdx                                  DataElementTableCol2ElmtIndStartIdx                                  StorageKind                     Referable Keys */
  { /*     0 */  0x0000u, DEM_CFG_TRIGGER_NONE      ,             0u, DEM_CFG_NO_DATAELEMENTTABLECOL2ELMTINDENDIDXOFDATACOLLECTIONTABLE, DEM_CFG_NO_DATAELEMENTTABLECOL2ELMTINDSTARTIDXOFDATACOLLECTIONTABLE, DEM_CFG_EREC_TYPE_GLOBAL },  /* [#NoDataCollectionConfigured] */
  { /*     1 */  0x0001u, DEM_CFG_TRIGGER_TESTFAILED,            51u,                                                               33u,                                                                  0u, DEM_CFG_EREC_TYPE_USER   },  /* [#EdrExtendedDataRecord_OccurrenceCounter, Ext:ExtendedDataClass_240799f9, #ExtendedDataRecord] */
  { /*     2 */  0x1002u, DEM_CFG_TRIGGER_NONE      ,             2u,                                                               34u,                                                                 33u, DEM_CFG_EREC_TYPE_USER   },  /* [#DidDID_221002_Vehicle_Speed_0x1002, Ffm:FreezeFrame_a2168519] */
  { /*     3 */  0x1004u, DEM_CFG_TRIGGER_NONE      ,             1u,                                                               35u,                                                                 34u, DEM_CFG_EREC_TYPE_USER   },  /* [#DidDID_221004_Battery_Voltage_0x1004, Ffm:FreezeFrame_a2168519] */
  { /*     4 */  0x1008u, DEM_CFG_TRIGGER_NONE      ,             3u,                                                               36u,                                                                 35u, DEM_CFG_EREC_TYPE_USER   },  /* [#DidDID_221008_ECU_Life_Time_0x1008, Ffm:FreezeFrame_a2168519] */
  { /*     5 */  0x1009u, DEM_CFG_TRIGGER_NONE      ,             2u,                                                               37u,                                                                 36u, DEM_CFG_EREC_TYPE_USER   },  /* [#DidDID_221009_ECU_Time_Since_Ignition_ON_0x1009, Ffm:FreezeFrame_a2168519] */
  { /*     6 */  0x1921u, DEM_CFG_TRIGGER_NONE      ,             9u,                                                               38u,                                                                 37u, DEM_CFG_EREC_TYPE_USER   },  /* [#DidDID_221921_Operational_Mode_Status_0x1921, Ffm:FreezeFrame_a2168519] */
  { /*     7 */  0x2001u, DEM_CFG_TRIGGER_NONE      ,             2u,                                                               39u,                                                                 38u, DEM_CFG_EREC_TYPE_USER   },  /* [#DidDID_222001_Odometer_0x2001, Ffm:FreezeFrame_a2168519] */
  { /*     8 */  0x200Au, DEM_CFG_TRIGGER_NONE      ,             2u,                                                               40u,                                                                 39u, DEM_CFG_EREC_TYPE_USER   }   /* [#DidDID_22200A_Ignition_ON_Counter_0x200a, Ffm:FreezeFrame_a2168519] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataCollectionTableFfm2CollInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataCollectionTableFfm2CollInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_Cfg_DataCollectionTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataCollectionTableFfm2CollIndType, DEM_CONST) Dem_Cfg_DataCollectionTableFfm2CollInd[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     DataCollectionTableFfm2CollInd      Referable Keys */
  /*     0 */                              4u,  /* [Ffm:FreezeFrame_a2168519] */
  /*     1 */                              5u,  /* [Ffm:FreezeFrame_a2168519] */
  /*     2 */                              8u,  /* [Ffm:FreezeFrame_a2168519] */
  /*     3 */                              7u,  /* [Ffm:FreezeFrame_a2168519] */
  /*     4 */                              3u,  /* [Ffm:FreezeFrame_a2168519] */
  /*     5 */                              6u,  /* [Ffm:FreezeFrame_a2168519] */
  /*     6 */                              2u   /* [Ffm:FreezeFrame_a2168519] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataElementTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataElementTable
  \details
  Element            Description
  ElementDataType    DataElement data type, returned by Dem_Cfg_DataElementDataType()
  ElementKind        DataElement kind, returned by Dem_Cfg_DataCallbackType()
  ElementSize        Size of data element in Byte.
  ReadDataFunc       C-function for getting the data. Its signature depends on ElementKind and ElementDataType: With value(s) DEM_CFG_DATA_FROM_CS_PORT_WITH_EVENTID use: Std_ReturnType (*)(uint8* Buffer, uint16 EventId); - and use: Std_ReturnType (*)(uint8* Buffer); with the other values DEM_CFG_DATA_FROM_CS_PORT, DEM_CFG_DATA_FROM_SR_PORT.
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataElementTableType, DEM_CONST) Dem_Cfg_DataElementTable[41] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ElementDataType            ElementKind                             ElementSize  ReadDataFunc                                                                                                                                                          Referable Keys */
  { /*     0 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATAELEMENT_INVALID           ,          0u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                                                           },  /* [#NoDataElementConfigured] */
  { /*     1 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0x1004_Battery_Voltage_24_ReadData                                    },  /* [#Data_DID_0x1004_Battery_Voltage_24, DidDID_221004_Battery_Voltage_0x1004] */
  { /*     2 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATA_FROM_CS_PORT             ,          3u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0x1008_ECU_Life_Time_24_ReadData                                      },  /* [#Data_DID_0x1008_ECU_Life_Time_24, DidDID_221008_ECU_Life_Time_0x1008] */
  { /*     3 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATA_FROM_CS_PORT             ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_ReadData                            },  /* [#Data_DID_0x1009_ECU_Time_Since_Ignition_ON, DidDID_221009_ECU_Time_Since_Ignition_ON_0x1009] */
  { /*     4 */ DEM_CFG_DATA_TYPE_UINT16 , DEM_CFG_DATA_FROM_CS_PORT             ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Aging_Counter_ID_ReadData                               },  /* [#Data_OccurrenceCounter_Aging_Counter_ID, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*     5 */ DEM_CFG_DATA_TYPE_UINT16 , DEM_CFG_DATA_FROM_CS_PORT             ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Frequency_Counter_ID_ReadData                           },  /* [#Data_OccurrenceCounter_Frequency_Counter_ID, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*     6 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATA_FROM_CS_PORT             ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0x200a_Ignition_ON_Counter_24_ReadData                                },  /* [#Data_DID_0x200a_Ignition_ON_Counter_24, DidDID_22200A_Ignition_ON_Counter_0x200a] */
  { /*     7 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATA_FROM_CS_PORT             ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0x1002_Vehicle_Speed_24_ReadData                                      },  /* [#Data_DID_0x1002_Vehicle_Speed_24, DidDID_221002_Vehicle_Speed_0x1002] */
  { /*     8 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATA_FROM_CS_PORT             ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0x2001_Odometer_24_ReadData                                           },  /* [#Data_DID_0x2001_Odometer_24, DidDID_222001_Odometer_0x2001] */
  { /*     9 */ DEM_CFG_DATA_TYPE_UINT16 , DEM_CFG_DATA_FROM_CS_PORT             ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate_ReadData                      },  /* [#Data_OccurrenceCounter_Touch_Screen_Y_Coordinate, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    10 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATA_FROM_CS_PORT             ,          3u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Odometer_Value_ReadData                                 },  /* [#Data_OccurrenceCounter_Odometer_Value, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    11 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Camera_Occlusion_ReadData                               },  /* [#Data_OccurrenceCounter_Camera_Occlusion, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    12 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_THA_state_ReadData                                      },  /* [#Data_OccurrenceCounter_THA_state, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    13 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATA_FROM_CS_PORT_WITH_EVENTID,          9u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Supplier_Internal_Code_ReadData                         },  /* [#Data_OccurrenceCounter_Supplier_Internal_Code, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    14 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Current_Gear_ReadData                                   },  /* [#Data_OccurrenceCounter_Current_Gear, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    15 */ DEM_CFG_DATA_TYPE_UINT16 , DEM_CFG_DATA_FROM_CS_PORT             ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Vehicle_Speed_ReadData                                  },  /* [#Data_OccurrenceCounter_Vehicle_Speed, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    16 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_DisplayStatus_ReadData                                  },  /* [#Data_OccurrenceCounter_DisplayStatus, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    17 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_TRSC_Stat_ReadData                                      },  /* [#Data_OccurrenceCounter_TRSC_Stat, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    18 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_ECU_Voltage_ReadData                                    },  /* [#Data_OccurrenceCounter_ECU_Voltage, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    19 */ DEM_CFG_DATA_TYPE_UINT16 , DEM_CFG_DATA_FROM_CS_PORT             ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Touch_Screen_X_Coordinate_ReadData                      },  /* [#Data_OccurrenceCounter_Touch_Screen_X_Coordinate, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    20 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Touch_Screen_Status_ReadData                            },  /* [#Data_OccurrenceCounter_Touch_Screen_Status, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    21 */ DEM_CFG_DATA_TYPE_UINT16 , DEM_CFG_DATA_FROM_CS_PORT             ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_External_Temperature_ReadData                           },  /* [#Data_OccurrenceCounter_External_Temperature, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    22 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_TireLines_ReadData                                      },  /* [#Data_OccurrenceCounter_TireLines, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    23 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Door_Status_ReadData                                    },  /* [#Data_OccurrenceCounter_Door_Status, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    24 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Radio_Display_Status_ReadData                           },  /* [#Data_OccurrenceCounter_Radio_Display_Status, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    25 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_AGINGCTR            ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                                                           },  /* [#Data_OccurrenceCounter_Aging_Counter, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    26 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_OCCCTR              ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                                                           },  /* [#Data_OccurrenceCounter_DID_DataObject, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    27 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_TRSKM_and_USS_status_ReadData                           },  /* [#Data_OccurrenceCounter_TRSKM_and_USS_status, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    28 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_LiftgateAjar_ReadData                                   },  /* [#Data_OccurrenceCounter_LiftgateAjar, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    29 */ DEM_CFG_DATA_TYPE_UINT16 , DEM_CFG_DATA_FROM_CS_PORT             ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID_ReadData },  /* [#Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    30 */ DEM_CFG_DATA_TYPE_UINT16 , DEM_CFG_DATA_FROM_CS_PORT             ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Steering_Wheel_Angle_ReadData                           },  /* [#Data_OccurrenceCounter_Steering_Wheel_Angle, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    31 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Reserved_ReadData                                       },  /* [#Data_OccurrenceCounter_Reserved, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    32 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Reserved_1_ReadData                                     },  /* [#Data_OccurrenceCounter_Reserved_1, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    33 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Calibration_Aborted_Failed_ReadData                     },  /* [#Data_OccurrenceCounter_Calibration_Aborted_Failed, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    34 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Calibration_Pending_ReadData                            },  /* [#Data_OccurrenceCounter_Calibration_Pending, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    35 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Calibration_Running_ReadData                            },  /* [#Data_OccurrenceCounter_Calibration_Running, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    36 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_New_Bit_Field_ReadData                                  },  /* [#Data_OccurrenceCounter_New_Bit_Field, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    37 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Calibration_Not_Started_ReadData                        },  /* [#Data_OccurrenceCounter_Calibration_Not_Started, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    38 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Calibrated_Successfully_ReadData                        },  /* [#Data_OccurrenceCounter_Calibrated_Successfully, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    39 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT             ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_OccurrenceCounter_Reserved_2_ReadData                                     },  /* [#Data_OccurrenceCounter_Reserved_2, EdrExtendedDataRecord_OccurrenceCounter] */
  { /*    40 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATA_FROM_CS_PORT             ,          9u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0x1921_CombinedSignal_ReadData                                        }   /* [#Data_DID_0x1921_CombinedSignal, DidDID_221921_Operational_Mode_Status_0x1921] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataElementTableCol2ElmtInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataElementTableCol2ElmtInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_Cfg_DataElementTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataElementTableCol2ElmtIndType, DEM_CONST) Dem_Cfg_DataElementTableCol2ElmtInd[40] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     DataElementTableCol2ElmtInd      Referable Keys */
  /*     0 */                           4u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*     1 */                          25u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*     2 */                           5u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*     3 */                          26u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*     4 */                          29u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*     5 */                          31u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*     6 */                          13u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*     7 */                          14u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*     8 */                          15u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*     9 */                          21u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    10 */                          10u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    11 */                          39u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    12 */                          18u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    13 */                          30u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    14 */                          32u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    15 */                          23u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    16 */                          28u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    17 */                          20u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    18 */                          19u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    19 */                           9u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    20 */                          24u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    21 */                          27u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    22 */                          17u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    23 */                          11u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    24 */                          12u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    25 */                          16u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    26 */                          22u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    27 */                          37u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    28 */                          34u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    29 */                          35u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    30 */                          38u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    31 */                          33u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    32 */                          36u,  /* [EdrExtendedDataRecord_OccurrenceCounter] */
  /*    33 */                           7u,  /* [DidDID_221002_Vehicle_Speed_0x1002] */
  /*    34 */                           1u,  /* [DidDID_221004_Battery_Voltage_0x1004] */
  /*    35 */                           2u,  /* [DidDID_221008_ECU_Life_Time_0x1008] */
  /*    36 */                           3u,  /* [DidDID_221009_ECU_Time_Since_Ignition_ON_0x1009] */
  /*    37 */                          40u,  /* [DidDID_221921_Operational_Mode_Status_0x1921] */
  /*    38 */                           8u,  /* [DidDID_222001_Odometer_0x2001] */
  /*    39 */                           6u   /* [DidDID_22200A_Ignition_ON_Counter_0x200a] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DebounceTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DebounceTable
  \details
  Element                   Description
  DecrementStepSize         (-1) * DemDebounceCounterDecrementStepSize of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  FailedThreshold           DemDebounceCounterFailedThreshold of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  IncrementStepSize         DemDebounceCounterIncrementStepSize of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  PassedThreshold           DemDebounceCounterPassedThreshold of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  EventDebounceAlgorithm    Used DemEventParameter/DemEventClass/DemDebounceAlgorithmClass
  MaskedBits                contains bitcoded the boolean data of Dem_Cfg_DebounceContinuousOfDebounceTable, Dem_Cfg_EventDebounceBehaviorOfDebounceTable, Dem_Cfg_JumpDownOfDebounceTable, Dem_Cfg_JumpUpOfDebounceTable, Dem_Cfg_StorageOfDebounceTable
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DebounceTableType, DEM_CONST) Dem_Cfg_DebounceTable[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DecrementStepSize  FailedThreshold  IncrementStepSize  PassedThreshold  EventDebounceAlgorithm                                                      MaskedBits        Referable Keys */
  { /*     0 */                -1,             127,                 1,            -128, DEM_CFG_DEM_CFG_DEBOUNCETYPE_COUNTER_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x06u },  /* [Dem_SystemInternalFailure] */
  { /*     1 */              -128,             127,               127,            -128, DEM_CFG_DEM_CFG_DEBOUNCETYPE_COUNTER_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x00u },  /* [Battery_Voltage_Over_Voltage_B210C17, Battery_Voltage_Under_Voltage_B210C16, Calibration_Not_Learned_Lost_Calibration_B228600, ECU_In_Plant_Mode_C221200, ECU_Internal_Performance_B22A900, Front_Camera_Circuit_Voltage_Out_of_Range_B23C51C, Front_Camera_Performance_or_Incorrect_Operation_B23C592, Front_Sensors_PS_Bus_Sig_Msg_Failures_B212A08, Front_Sensors_PS_VltgeAboveThreshold_B212A17, Front_Sensors_PS_VltgeBelowThreshold_B212A16, HS_FD_CAN2_Comm_Bus_Performance_U104E00, HS_FD_CANR_Comm_Bus_Performance_U100B00, Implausible_Data_From_BSC_Module_1_U041800, Implausible_Data_Received_From_Body_Control_Module_U042200, Implausible_Data_Received_from_Radio_U048500, Implausible_Data_from_ORC_module_U045500, Implausible_Data_received_from_TRSKM_module_U14A000, Implausible_data_received_from_ECM_U040100, Invalid_Data_Received_From_Power_Steering_Control_Module_U042000, Left_Camera_Circuit_Voltage_Out_of_Range_B23C61C, Left_Camera_Performance_or_Incorrect_Operation_B23C692, Loss_Communication_with_TRS_Knob_Module_U12B900, Loss_of_Comm_With_Engine_Control_Module_U010000, Lost_Communication_With_BCM_U014000, Lost_Communication_With_BSC_module_1_U012900, Lost_Communication_With_PSC_Module_A_U013100, Lost_Communication_With_Radio_U018400, Lost_Communication_with_Front_Camera_U026500, Lost_Communication_with_Left_Camera_U026600, Lost_Communication_with_ORC_U015100, Lost_Communication_with_Rear_Camera_U026400, Lost_Communication_with_Right_Camera_U026700, PPP_Assist_Switch_Stuck_B12B22A, PTS_Sensor_10_Circuit_Open_B129713, PTS_Sensor_10_Performance_or_Incorrect_Operation_B129792, PTS_Sensor_11_Circuit_Open_B129813, PTS_Sensor_11_Performance_or_Incorrect_Operation_B129892, PTS_Sensor_12_Circuit_Open_B129913, PTS_Sensor_12_Performance_or_Incorrect_Operation_B129992, PTS_Sensor_1_Circuit_Open_B128E13, PTS_Sensor_1_Performance_or_Incorrect_Operation_B128E92, PTS_Sensor_2_Circuit_Open_B128F13, PTS_Sensor_2_Performance_or_Incorrect_Operation_B128F92, PTS_Sensor_3_Circuit_Open_B129013, PTS_Sensor_3_Performance_or_Incorrect_Operation_B129092, PTS_Sensor_4_Circuit_Open_B129113, PTS_Sensor_4_Performance_or_Incorrect_Operation_B129192, PTS_Sensor_5_Circuit_Open_B129213, PTS_Sensor_5_Performance_or_Incorrect_Operation_B129292, PTS_Sensor_6_Circuit_Open_B129313, PTS_Sensor_6_Performance_or_Incorrect_Operation_B129392, PTS_Sensor_7_Circuit_Open_B129413, PTS_Sensor_7_Performance_or_Incorrect_Operation_B129492, PTS_Sensor_8_Circuit_Open_B129513, PTS_Sensor_8_Performance_or_Incorrect_Operation_B129592, PTS_Sensor_9_Circuit_Open_B129613, PTS_Sensor_9_Performance_or_Incorrect_Operation_B129692, Park_Assist_PTS_Switch_Stuck_B12852A, Rear_Camera_Circuit_Voltage_Out_of_Range_B217A1C, Rear_Camera_Performance_or_Incorrect_Operation_B217A92, Rear_Sensors_PS_Bus_Sig_Msg_Failures_B212B08, Rear_Sensors_PS_VltgeAboveThreshold_B212B17, Rear_Sensors_PS_VltgeBelowThreshold_B212B16, Right_Camera_Circuit_Voltage_Out_of_Range_B23C71C, Right_Camera_Performance_or_Incorrect_Operation_B23C792, Vehicle_Configuration_Mismatch_B223B00] */
  { /*     2 */                 0,               0,                 0,               0, DEM_CFG_DEM_CFG_DEBOUNCETYPE_INVALID_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x00u }   /* [#EVENT_INVALID] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DtcTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DtcTable
  \details
  Element           Description
  UdsDtc        
  FunctionalUnit
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DtcTableType, DEM_CONST) Dem_Cfg_DtcTable[67] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    UdsDtc       FunctionalUnit        Referable Keys */
  { /*     0 */ 0x00FFFFFFu,           255u },  /* [#NoUdsDtcConfigured, #NoObdDtcConfigured, #NoJ1939DtcConfigured] */
  { /*     1 */ 0x00A10C17u,             0u },  /* [DTCClass_DtcClass_Battery_Voltage_Over_Voltage_B210C17] */
  { /*     2 */ 0x00A10C16u,             0u },  /* [DTCClass_DtcClass_Battery_Voltage_Under_Voltage_B210C16] */
  { /*     3 */ 0x00A28600u,             0u },  /* [DTCClass_DtcClass_Calibration_Not_Learned_Lost_Calibration_B228600] */
  { /*     4 */ 0x00621200u,             0u },  /* [DTCClass_DtcClass_ECU_In_Plant_Mode_C221200] */
  { /*     5 */ 0x00A2A900u,             0u },  /* [DTCClass_DtcClass_ECU_Internal_Performance_B22A900] */
  { /*     6 */ 0x00A3C51Cu,             0u },  /* [DTCClass_DtcClass_Front_Camera_Circuit_Voltage_Out_of_Range_B23C51C] */
  { /*     7 */ 0x00A3C592u,             0u },  /* [DTCClass_DtcClass_Front_Camera_Performance_or_Incorrect_Operation_B23C592] */
  { /*     8 */ 0x00A12A08u,             0u },  /* [DTCClass_DtcClass_Front_Sensors_PS_Bus_Sig_Msg_Failures_B212A08] */
  { /*     9 */ 0x00A12A17u,             0u },  /* [DTCClass_DtcClass_Front_Sensors_PS_VltgeAboveThreshold_B212A17] */
  { /*    10 */ 0x00A12A16u,             0u },  /* [DTCClass_DtcClass_Front_Sensors_PS_VltgeBelowThreshold_B212A16] */
  { /*    11 */ 0x00D04E00u,             0u },  /* [DTCClass_DtcClass_HS_FD_CAN2_Comm_Bus_Performance_U104E00] */
  { /*    12 */ 0x00D00B00u,             0u },  /* [DTCClass_DtcClass_HS_FD_CANR_Comm_Bus_Performance_U100B00] */
  { /*    13 */ 0x00C41800u,             0u },  /* [DTCClass_DtcClass_Implausible_Data_From_BSC_Module_1_U041800] */
  { /*    14 */ 0x00C42200u,             0u },  /* [DTCClass_DtcClass_Implausible_Data_Received_From_Body_Control_Module_U042200] */
  { /*    15 */ 0x00C48500u,             0u },  /* [DTCClass_DtcClass_Implausible_Data_Received_from_Radio_U048500] */
  { /*    16 */ 0x00C45500u,             0u },  /* [DTCClass_DtcClass_Implausible_Data_from_ORC_module_U045500] */
  { /*    17 */ 0x00D4A000u,             0u },  /* [DTCClass_DtcClass_Implausible_Data_received_from_TRSKM_module_U14A000] */
  { /*    18 */ 0x00C40100u,             0u },  /* [DTCClass_DtcClass_Implausible_data_received_from_ECM_U040100] */
  { /*    19 */ 0x00C42000u,             0u },  /* [DTCClass_DtcClass_Invalid_Data_Received_From_Power_Steering_Control_Module_U042000] */
  { /*    20 */ 0x00A3C61Cu,             0u },  /* [DTCClass_DtcClass_Left_Camera_Circuit_Voltage_Out_of_Range_B23C61C] */
  { /*    21 */ 0x00A3C692u,             0u },  /* [DTCClass_DtcClass_Left_Camera_Performance_or_Incorrect_Operation_B23C692] */
  { /*    22 */ 0x00D2B900u,             0u },  /* [DTCClass_DtcClass_Loss_Communication_with_TRS_Knob_Module_U12B900] */
  { /*    23 */ 0x00C10000u,             0u },  /* [DTCClass_DtcClass_Loss_of_Comm_With_Engine_Control_Module_U010000] */
  { /*    24 */ 0x00C14000u,             0u },  /* [DTCClass_DtcClass_Lost_Communication_With_BCM_U014000] */
  { /*    25 */ 0x00C12900u,             0u },  /* [DTCClass_DtcClass_Lost_Communication_With_BSC_module_1_U012900] */
  { /*    26 */ 0x00C13100u,             0u },  /* [DTCClass_DtcClass_Lost_Communication_With_PSC_Module_A_U013100] */
  { /*    27 */ 0x00C18400u,             0u },  /* [DTCClass_DtcClass_Lost_Communication_With_Radio_U018400] */
  { /*    28 */ 0x00C26500u,             0u },  /* [DTCClass_DtcClass_Lost_Communication_with_Front_Camera_U026500] */
  { /*    29 */ 0x00C26600u,             0u },  /* [DTCClass_DtcClass_Lost_Communication_with_Left_Camera_U026600] */
  { /*    30 */ 0x00C15100u,             0u },  /* [DTCClass_DtcClass_Lost_Communication_with_ORC_U015100] */
  { /*    31 */ 0x00C26400u,             0u },  /* [DTCClass_DtcClass_Lost_Communication_with_Rear_Camera_U026400] */
  { /*    32 */ 0x00C26700u,             0u },  /* [DTCClass_DtcClass_Lost_Communication_with_Right_Camera_U026700] */
  { /*    33 */ 0x0092B22Au,             0u },  /* [DTCClass_DtcClass_PPP_Assist_Switch_Stuck_B12B22A] */
  { /*    34 */ 0x00928E13u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_1_Circuit_Open_B128E13] */
  { /*    35 */ 0x00928E92u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_1_Performance_or_Incorrect_Operation_B128E92] */
  { /*    36 */ 0x00928F13u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_2_Circuit_Open_B128F13] */
  { /*    37 */ 0x00928F92u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_2_Performance_or_Incorrect_Operation_B128F92] */
  { /*    38 */ 0x00929013u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_3_Circuit_Open_B129013] */
  { /*    39 */ 0x00929092u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_3_Performance_or_Incorrect_Operation_B129092] */
  { /*    40 */ 0x00929113u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_4_Circuit_Open_B129113] */
  { /*    41 */ 0x00929192u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_4_Performance_or_Incorrect_Operation_B129192] */
  { /*    42 */ 0x00929213u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_5_Circuit_Open_B129213] */
  { /*    43 */ 0x00929292u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_5_Performance_or_Incorrect_Operation_B129292] */
  { /*    44 */ 0x00929313u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_6_Circuit_Open_B129313] */
  { /*    45 */ 0x00929413u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_7_Circuit_Open_B129413] */
  { /*    46 */ 0x00929492u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_7_Performance_or_Incorrect_Operation_B129492] */
  { /*    47 */ 0x00929513u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_8_Circuit_Open_B129513] */
  { /*    48 */ 0x00929592u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_8_Performance_or_Incorrect_Operation_B129592] */
  { /*    49 */ 0x00929613u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_9_Circuit_Open_B129613] */
    /* Index    UdsDtc       FunctionalUnit        Referable Keys */
  { /*    50 */ 0x00929692u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_9_Performance_or_Incorrect_Operation_B129692] */
  { /*    51 */ 0x00929713u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_10_Circuit_Open_B129713] */
  { /*    52 */ 0x00929792u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_10_Performance_or_Incorrect_Operation_B129792] */
  { /*    53 */ 0x00929813u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_11_Circuit_Open_B129813] */
  { /*    54 */ 0x00929892u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_11_Performance_or_Incorrect_Operation_B129892] */
  { /*    55 */ 0x00929913u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_12_Circuit_Open_B129913] */
  { /*    56 */ 0x00929992u,             0u },  /* [DTCClass_DtcClass_PTS_Sensor_12_Performance_or_Incorrect_Operation_B129992] */
  { /*    57 */ 0x0092852Au,             0u },  /* [DTCClass_DtcClass_Park_Assist_PTS_Switch_Stuck_B12852A] */
  { /*    58 */ 0x00A17A1Cu,             0u },  /* [DTCClass_DtcClass_Rear_Camera_Circuit_Voltage_Out_of_Range_B217A1C] */
  { /*    59 */ 0x00A17A92u,             0u },  /* [DTCClass_DtcClass_Rear_Camera_Performance_or_Incorrect_Operation_B217A92] */
  { /*    60 */ 0x00A12B08u,             0u },  /* [DTCClass_DtcClass_Rear_Sensors_PS_Bus_Sig_Msg_Failures_B212B08] */
  { /*    61 */ 0x00A12B17u,             0u },  /* [DTCClass_DtcClass_Rear_Sensors_PS_VltgeAboveThreshold_B212B17] */
  { /*    62 */ 0x00A12B16u,             0u },  /* [DTCClass_DtcClass_Rear_Sensors_PS_VltgeBelowThreshold_B212B16] */
  { /*    63 */ 0x00A3C71Cu,             0u },  /* [DTCClass_DtcClass_Right_Camera_Circuit_Voltage_Out_of_Range_B23C71C] */
  { /*    64 */ 0x00A3C792u,             0u },  /* [DTCClass_DtcClass_Right_Camera_Performance_or_Incorrect_Operation_B23C792] */
  { /*    65 */ 0x00A23B00u,             0u },  /* [DTCClass_DtcClass_Vehicle_Configuration_Mismatch_B223B00] */
  { /*    66 */ 0x00929392u,             0u }   /* [DTCClass_DtcClass_PTS_Sensor_6_Performance_or_Incorrect_Operation_B129392] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionGroupTableInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionGroupTableInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_Cfg_EnableConditionGroupTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EnableConditionGroupTableIndType, DEM_CONST) Dem_Cfg_EnableConditionGroupTableInd[53] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     EnableConditionGroupTableInd      Referable Keys */
  /*     0 */                            0u,  /* [__Internal_ControlDtcSetting] */
  /*     1 */                           13u,  /* [__Internal_ControlDtcSetting] */
  /*     2 */                           11u,  /* [__Internal_ControlDtcSetting] */
  /*     3 */                            3u,  /* [__Internal_ControlDtcSetting] */
  /*     4 */                            1u,  /* [__Internal_ControlDtcSetting] */
  /*     5 */                            2u,  /* [__Internal_ControlDtcSetting] */
  /*     6 */                           12u,  /* [__Internal_ControlDtcSetting] */
  /*     7 */                            7u,  /* [__Internal_ControlDtcSetting] */
  /*     8 */                           14u,  /* [__Internal_ControlDtcSetting] */
  /*     9 */                            8u,  /* [__Internal_ControlDtcSetting] */
  /*    10 */                           10u,  /* [__Internal_ControlDtcSetting] */
  /*    11 */                            9u,  /* [__Internal_ControlDtcSetting] */
  /*    12 */                            6u,  /* [__Internal_ControlDtcSetting] */
  /*    13 */                            5u,  /* [__Internal_ControlDtcSetting] */
  /*    14 */                            4u,  /* [__Internal_ControlDtcSetting] */
  /*    15 */                           11u,  /* [EC1] */
  /*    16 */                            2u,  /* [EC1] */
  /*    17 */                           12u,  /* [EC1] */
  /*    18 */                            7u,  /* [EC1] */
  /*    19 */                           10u,  /* [EC1] */
  /*    20 */                            9u,  /* [EC1] */
  /*    21 */                            4u,  /* [EC1] */
  /*    22 */                            1u,  /* [EC1_EC4_EC8] */
  /*    23 */                           14u,  /* [EC1_EC8] */
  /*    24 */                           13u,  /* [EC2] */
  /*    25 */                           11u,  /* [EC2] */
  /*    26 */                            3u,  /* [EC2] */
  /*    27 */                            1u,  /* [EC2] */
  /*    28 */                           12u,  /* [EC2] */
  /*    29 */                           14u,  /* [EC2] */
  /*    30 */                            8u,  /* [EC2] */
  /*    31 */                           10u,  /* [EC2] */
  /*    32 */                            9u,  /* [EC2] */
  /*    33 */                            6u,  /* [EC2] */
  /*    34 */                            5u,  /* [EC2] */
  /*    35 */                            4u,  /* [EC2] */
  /*    36 */                           13u,  /* [EC4] */
  /*    37 */                           11u,  /* [EC4] */
  /*    38 */                            2u,  /* [EC4] */
  /*    39 */                           10u,  /* [EC4] */
  /*    40 */                            4u,  /* [EC4] */
  /*    41 */                           13u,  /* [EC5] */
  /*    42 */                           11u,  /* [EC5] */
  /*    43 */                            3u,  /* [EC5] */
  /*    44 */                           10u,  /* [EC5] */
  /*    45 */                            6u,  /* [EC5] */
  /*    46 */                            4u,  /* [EC5] */
  /*    47 */                           10u,  /* [EC7] */
  /*    48 */                           13u,  /* [EC9] */
  /*    49 */                            6u,  /* [EC9] */
  /* Index     EnableConditionGroupTableInd      Referable Keys */
  /*    50 */                            5u,  /* [EC9] */
  /*    51 */                            4u,  /* [EC9] */
  /*    52 */                            9u   /* [EC10] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionInitTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionInitTable
  \details
  Element            Description
  FulfilledAtInit    Initial value: 'FALSE' condition is not fulfilled, 'TRUE' condition is fulfilled
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EnableConditionInitTableType, DEM_CONST) Dem_Cfg_EnableConditionInitTable[10] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FulfilledAtInit */
  { /*     0 */            TRUE },
  { /*     1 */           FALSE },
  { /*     2 */           FALSE },
  { /*     3 */           FALSE },
  { /*     4 */           FALSE },
  { /*     5 */           FALSE },
  { /*     6 */           FALSE },
  { /*     7 */           FALSE },
  { /*     8 */           FALSE },
  { /*     9 */           FALSE }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionTable
  \brief  Map each EnableCondition(Id) to the referring EnableConditionGroups - this is reverse direction of the AUTOSAR configuration model.
  \details
  Element                                 Description
  EnableConditionGroupTableIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_EnableConditionGroupTableInd
  EnableConditionGroupTableIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_EnableConditionGroupTableInd
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EnableConditionTableType, DEM_CONST) Dem_Cfg_EnableConditionTable[10] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EnableConditionGroupTableIndEndIdx  EnableConditionGroupTableIndStartIdx */
  { /*     0 */                                15u,                                   0u },
  { /*     1 */                                22u,                                  15u },
  { /*     2 */                                23u,                                  22u },
  { /*     3 */                                24u,                                  23u },
  { /*     4 */                                36u,                                  24u },
  { /*     5 */                                41u,                                  36u },
  { /*     6 */                                47u,                                  41u },
  { /*     7 */                                48u,                                  47u },
  { /*     8 */                                52u,                                  48u },
  { /*     9 */                                53u,                                  52u }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventTable
  \details
  Element                         Description
  AgingCounterIndex               Calculated AgingCounterIndex for accessing AgingCounter array in Dem_Cfg_AgingData
  AgingCycleCounterThreshold      DemAgingCycleCounterThreshold of the DemEventParameter/DemEventClass. If AgingAllowedOfEventTable==FALSE and DemAgingCycleCounterThreshold does not exist '255' is set. If AgingAllowedOfEventTable==TRUE and DemAgingCycleCounterThreshold does not exist '0' is set.
  AgingCycleId                    DemOperationCycle (ID) referenced by DemEventParameter/DemEventClass/DemAgingCycleRef
  DtcTableIdx                     the index of the 1:1 relation pointing to Dem_Cfg_DtcTable
  EnableConditionGroupTableIdx    the index of the 1:1 relation pointing to Dem_Cfg_EnableConditionGroupTable
  EventDestination                Memory Destination of the referenced DTC
  ExtendedDataTableIdx            the index of the 1:1 relation pointing to Dem_Cfg_ExtendedDataTable
  FreezeFrameNumTableEndIdx       the end index of the 0:n relation pointing to Dem_Cfg_FreezeFrameNumTable
  FreezeFrameNumTableStartIdx     the start index of the 0:n relation pointing to Dem_Cfg_FreezeFrameNumTable
  MaskedBits                      contains bitcoded the boolean data of Dem_Cfg_AgingAllowedOfEventTable, Dem_Cfg_EventLatchTFOfEventTable, Dem_Cfg_OBDVisibilityDelayedUntilDcyQualificationOfEventTable
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EventTableType, DEM_CONST) Dem_Cfg_EventTable[68] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AgingCounterIndex  AgingCycleCounterThreshold  AgingCycleId                             DtcTableIdx  EnableConditionGroupTableIdx  EventDestination          ExtendedDataTableIdx  FreezeFrameNumTableEndIdx                         FreezeFrameNumTableStartIdx                         MaskedBits        Referable Keys */
  { /*     0 */                8u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,          1u,                           7u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [#EVENT_INVALID, #NoExtendedDataRecordConfigured, Satellite#0] */
  { /*     1 */                8u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,          1u,                           7u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Battery_Voltage_Over_Voltage_B210C17, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*     2 */               17u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,          2u,                           2u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Battery_Voltage_Under_Voltage_B210C16, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*     3 */               52u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,          3u,                          12u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Calibration_Not_Learned_Lost_Calibration_B228600, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*     4 */               61u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,          4u,                           8u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [ECU_In_Plant_Mode_C221200, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*     5 */               50u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,          5u,                           8u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [ECU_Internal_Performance_B22A900, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*     6 */               46u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,          6u,                           9u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Front_Camera_Circuit_Voltage_Out_of_Range_B23C51C, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*     7 */               30u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,          7u,                           9u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Front_Camera_Performance_or_Incorrect_Operation_B23C592, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*     8 */               33u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,          8u,                          14u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Front_Sensors_PS_Bus_Sig_Msg_Failures_B212A08, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*     9 */                9u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,          9u,                          14u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Front_Sensors_PS_VltgeAboveThreshold_B212A17, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    10 */                2u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         10u,                          14u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Front_Sensors_PS_VltgeBelowThreshold_B212A16, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    11 */               19u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         11u,                           5u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [HS_FD_CAN2_Comm_Bus_Performance_U104E00, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    12 */               56u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         12u,                           5u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [HS_FD_CANR_Comm_Bus_Performance_U100B00, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    13 */               47u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         13u,                           4u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Implausible_Data_From_BSC_Module_1_U041800, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    14 */               57u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         14u,                           6u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Implausible_Data_Received_From_Body_Control_Module_U042200, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    15 */               28u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         15u,                           4u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Implausible_Data_Received_from_Radio_U048500, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    16 */               62u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         16u,                           4u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Implausible_Data_from_ORC_module_U045500, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    17 */               29u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         17u,                           4u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Implausible_Data_received_from_TRSKM_module_U14A000, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    18 */               39u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         18u,                           4u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Implausible_data_received_from_ECM_U040100, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    19 */                0u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         19u,                           4u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Invalid_Data_Received_From_Power_Steering_Control_Module_U042000, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    20 */                3u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         20u,                           9u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Left_Camera_Circuit_Voltage_Out_of_Range_B23C61C, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    21 */               43u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         21u,                           9u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Left_Camera_Performance_or_Incorrect_Operation_B23C692, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    22 */               31u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         22u,                           4u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Loss_Communication_with_TRS_Knob_Module_U12B900, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    23 */               21u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         23u,                           4u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Loss_of_Comm_With_Engine_Control_Module_U010000, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    24 */               58u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         24u,                          13u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Lost_Communication_With_BCM_U014000, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    25 */               41u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         25u,                           4u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Lost_Communication_With_BSC_module_1_U012900, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    26 */               34u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         26u,                           4u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Lost_Communication_With_PSC_Module_A_U013100, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    27 */               13u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         27u,                           4u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Lost_Communication_With_Radio_U018400, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    28 */               35u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         28u,                           9u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Lost_Communication_with_Front_Camera_U026500, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    29 */                1u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         29u,                           9u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Lost_Communication_with_Left_Camera_U026600, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    30 */               53u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         30u,                           4u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Lost_Communication_with_ORC_U015100, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    31 */               55u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         31u,                          12u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Lost_Communication_with_Rear_Camera_U026400, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    32 */               22u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         32u,                           9u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Lost_Communication_with_Right_Camera_U026700, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    33 */               38u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         33u,                          10u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PPP_Assist_Switch_Stuck_B12B22A, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    34 */               54u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         34u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_1_Circuit_Open_B128E13, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    35 */               23u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         35u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_1_Performance_or_Incorrect_Operation_B128E92, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    36 */               59u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         36u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_2_Circuit_Open_B128F13, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    37 */               25u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         37u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_2_Performance_or_Incorrect_Operation_B128F92, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    38 */               60u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         38u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_3_Circuit_Open_B129013, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    39 */               36u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         39u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_3_Performance_or_Incorrect_Operation_B129092, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    40 */               10u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         40u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_4_Circuit_Open_B129113, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    41 */               18u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         41u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_4_Performance_or_Incorrect_Operation_B129192, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    42 */               15u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         42u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_5_Circuit_Open_B129213, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    43 */               16u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         43u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_5_Performance_or_Incorrect_Operation_B129292, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    44 */               45u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         44u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_6_Circuit_Open_B129313, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    45 */               32u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         45u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_7_Circuit_Open_B129413, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    46 */               42u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         46u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_7_Performance_or_Incorrect_Operation_B129492, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    47 */               27u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         47u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_8_Circuit_Open_B129513, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    48 */               37u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         48u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_8_Performance_or_Incorrect_Operation_B129592, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    49 */               20u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         49u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_9_Circuit_Open_B129613, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
    /* Index    AgingCounterIndex  AgingCycleCounterThreshold  AgingCycleId                             DtcTableIdx  EnableConditionGroupTableIdx  EventDestination          ExtendedDataTableIdx  FreezeFrameNumTableEndIdx                         FreezeFrameNumTableStartIdx                         MaskedBits        Referable Keys */
  { /*    50 */               51u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         50u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_9_Performance_or_Incorrect_Operation_B129692, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    51 */               40u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         51u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_10_Circuit_Open_B129713, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    52 */               48u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         52u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_10_Performance_or_Incorrect_Operation_B129792, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    53 */               49u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         53u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_11_Circuit_Open_B129813, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    54 */               12u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         54u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_11_Performance_or_Incorrect_Operation_B129892, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    55 */               11u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         55u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_12_Circuit_Open_B129913, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    56 */                7u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         56u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_12_Performance_or_Incorrect_Operation_B129992, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    57 */               14u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         57u,                          11u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Park_Assist_PTS_Switch_Stuck_B12852A, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    58 */                6u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         58u,                          12u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Rear_Camera_Circuit_Voltage_Out_of_Range_B217A1C, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    59 */               24u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         59u,                          12u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Rear_Camera_Performance_or_Incorrect_Operation_B217A92, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    60 */                5u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         60u,                          14u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Rear_Sensors_PS_Bus_Sig_Msg_Failures_B212B08, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    61 */               64u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         61u,                          14u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Rear_Sensors_PS_VltgeAboveThreshold_B212B17, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    62 */                4u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         62u,                          14u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Rear_Sensors_PS_VltgeBelowThreshold_B212B16, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    63 */               26u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         63u,                           9u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Right_Camera_Circuit_Voltage_Out_of_Range_B23C71C, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    64 */               63u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         64u,                           9u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Right_Camera_Performance_or_Incorrect_Operation_B23C792, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    65 */               44u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         65u,                           3u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [Vehicle_Configuration_Mismatch_B223B00, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    66 */               65u,                        40u, DemConf_DemOperationCycle_IgnitionCycle,         66u,                           1u, DEM_CFG_MEMORYID_PRIMARY,                   1u,                                               1u,                                                 0u,      0x04u },  /* [PTS_Sensor_6_Performance_or_Incorrect_Operation_B129392, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  { /*    67 */              255u,                       255u, /*no AgingCycle*/ 1U                   ,          0u,                           0u, DEM_CFG_MEMORYID_INVALID,                   0u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,      0x00u }   /* [Dem_SystemInternalFailure, #NoExtendedDataRecordConfigured, Satellite#0] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ExtendedDataTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ExtendedDataTable
  \details
  Element                                   Description
  DataCollectionTableEdr2CollIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableEdr2CollInd
  DataCollectionTableEdr2CollIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableEdr2CollInd
  MaxRecordSize                         
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_ExtendedDataTableType, DEM_CONST) Dem_Cfg_ExtendedDataTable[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DataCollectionTableEdr2CollIndEndIdx                                DataCollectionTableEdr2CollIndStartIdx                                MaxRecordSize        Referable Keys */
  { /*     0 */ DEM_CFG_NO_DATACOLLECTIONTABLEEDR2COLLINDENDIDXOFEXTENDEDDATATABLE, DEM_CFG_NO_DATACOLLECTIONTABLEEDR2COLLINDSTARTIDXOFEXTENDEDDATATABLE,            0u },  /* [#NoExtendedDataRecordConfigured, Dem_SystemInternalFailure] */
  { /*     1 */                                                                 1u,                                                                   0u,           51u }   /* [#ExtendedDataClass_240799f9, #EVENT_INVALID, Battery_Voltage_Over_Voltage_B210C17, Battery_Voltage_Under_Voltage_B210C16, Calibration_Not_Learned_Lost_Calibration_B228600, ECU_In_Plant_Mode_C221200, ECU_Internal_Performance_B22A900, Front_Camera_Circuit_Voltage_Out_of_Range_B23C51C, Front_Camera_Performance_or_Incorrect_Operation_B23C592, Front_Sensors_PS_Bus_Sig_Msg_Failures_B212A08, Front_Sensors_PS_VltgeAboveThreshold_B212A17, Front_Sensors_PS_VltgeBelowThreshold_B212A16, HS_FD_CAN2_Comm_Bus_Performance_U104E00, HS_FD_CANR_Comm_Bus_Performance_U100B00, Implausible_Data_From_BSC_Module_1_U041800, Implausible_Data_Received_From_Body_Control_Module_U042200, Implausible_Data_Received_from_Radio_U048500, Implausible_Data_from_ORC_module_U045500, Implausible_Data_received_from_TRSKM_module_U14A000, Implausible_data_received_from_ECM_U040100, Invalid_Data_Received_From_Power_Steering_Control_Module_U042000, Left_Camera_Circuit_Voltage_Out_of_Range_B23C61C, Left_Camera_Performance_or_Incorrect_Operation_B23C692, Loss_Communication_with_TRS_Knob_Module_U12B900, Loss_of_Comm_With_Engine_Control_Module_U010000, Lost_Communication_With_BCM_U014000, Lost_Communication_With_BSC_module_1_U012900, Lost_Communication_With_PSC_Module_A_U013100, Lost_Communication_With_Radio_U018400, Lost_Communication_with_Front_Camera_U026500, Lost_Communication_with_Left_Camera_U026600, Lost_Communication_with_ORC_U015100, Lost_Communication_with_Rear_Camera_U026400, Lost_Communication_with_Right_Camera_U026700, PPP_Assist_Switch_Stuck_B12B22A, PTS_Sensor_1_Circuit_Open_B128E13, PTS_Sensor_1_Performance_or_Incorrect_Operation_B128E92, PTS_Sensor_2_Circuit_Open_B128F13, PTS_Sensor_2_Performance_or_Incorrect_Operation_B128F92, PTS_Sensor_3_Circuit_Open_B129013, PTS_Sensor_3_Performance_or_Incorrect_Operation_B129092, PTS_Sensor_4_Circuit_Open_B129113, PTS_Sensor_4_Performance_or_Incorrect_Operation_B129192, PTS_Sensor_5_Circuit_Open_B129213, PTS_Sensor_5_Performance_or_Incorrect_Operation_B129292, PTS_Sensor_6_Circuit_Open_B129313, PTS_Sensor_7_Circuit_Open_B129413, PTS_Sensor_7_Performance_or_Incorrect_Operation_B129492, PTS_Sensor_8_Circuit_Open_B129513, PTS_Sensor_8_Performance_or_Incorrect_Operation_B129592, PTS_Sensor_9_Circuit_Open_B129613, PTS_Sensor_9_Performance_or_Incorrect_Operation_B129692, PTS_Sensor_10_Circuit_Open_B129713, PTS_Sensor_10_Performance_or_Incorrect_Operation_B129792, PTS_Sensor_11_Circuit_Open_B129813, PTS_Sensor_11_Performance_or_Incorrect_Operation_B129892, PTS_Sensor_12_Circuit_Open_B129913, PTS_Sensor_12_Performance_or_Incorrect_Operation_B129992, Park_Assist_PTS_Switch_Stuck_B12852A, Rear_Camera_Circuit_Voltage_Out_of_Range_B217A1C, Rear_Camera_Performance_or_Incorrect_Operation_B217A92, Rear_Sensors_PS_Bus_Sig_Msg_Failures_B212B08, Rear_Sensors_PS_VltgeAboveThreshold_B212B17, Rear_Sensors_PS_VltgeBelowThreshold_B212B16, Right_Camera_Circuit_Voltage_Out_of_Range_B23C71C, Right_Camera_Performance_or_Incorrect_Operation_B23C792, Vehicle_Configuration_Mismatch_B223B00, PTS_Sensor_6_Performance_or_Incorrect_Operation_B129392] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FreezeFrameTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FreezeFrameTable
  \details
  Element                                   Description
  DataCollectionTableFfm2CollIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableFfm2CollInd
  DataCollectionTableFfm2CollIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableFfm2CollInd
  RecordSize                                Summarized size of did data that is stored in Dem_Cfg_PrimaryEntryType.SnapshotData[][] (i.e. typically without size of dids containing internal data elements).
  RecordSizeUds                             Summarized size of did data, did numbers and snapshot header (i.e. dynamical payload size of the uds response message).
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_FreezeFrameTableType, DEM_CONST) Dem_Cfg_FreezeFrameTable[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DataCollectionTableFfm2CollIndEndIdx                               DataCollectionTableFfm2CollIndStartIdx                               RecordSize  RecordSizeUds        Referable Keys */
  { /*     0 */ DEM_CFG_NO_DATACOLLECTIONTABLEFFM2COLLINDENDIDXOFFREEZEFRAMETABLE, DEM_CFG_NO_DATACOLLECTIONTABLEFFM2COLLINDSTARTIDXOFFREEZEFRAMETABLE,         0u,            0u },  /* [#NoFreezeFrameConfigured] */
  { /*     1 */                                                                7u,                                                                  0u,        21u,           37u }   /* [#FreezeFrame_a2168519, #EVENT_INVALID, Battery_Voltage_Over_Voltage_B210C17, Battery_Voltage_Under_Voltage_B210C16, Calibration_Not_Learned_Lost_Calibration_B228600, ECU_In_Plant_Mode_C221200, ECU_Internal_Performance_B22A900, Front_Camera_Circuit_Voltage_Out_of_Range_B23C51C, Front_Camera_Performance_or_Incorrect_Operation_B23C592, Front_Sensors_PS_Bus_Sig_Msg_Failures_B212A08, Front_Sensors_PS_VltgeAboveThreshold_B212A17, Front_Sensors_PS_VltgeBelowThreshold_B212A16, HS_FD_CAN2_Comm_Bus_Performance_U104E00, HS_FD_CANR_Comm_Bus_Performance_U100B00, Implausible_Data_From_BSC_Module_1_U041800, Implausible_Data_Received_From_Body_Control_Module_U042200, Implausible_Data_Received_from_Radio_U048500, Implausible_Data_from_ORC_module_U045500, Implausible_Data_received_from_TRSKM_module_U14A000, Implausible_data_received_from_ECM_U040100, Invalid_Data_Received_From_Power_Steering_Control_Module_U042000, Left_Camera_Circuit_Voltage_Out_of_Range_B23C61C, Left_Camera_Performance_or_Incorrect_Operation_B23C692, Loss_Communication_with_TRS_Knob_Module_U12B900, Loss_of_Comm_With_Engine_Control_Module_U010000, Lost_Communication_With_BCM_U014000, Lost_Communication_With_BSC_module_1_U012900, Lost_Communication_With_PSC_Module_A_U013100, Lost_Communication_With_Radio_U018400, Lost_Communication_with_Front_Camera_U026500, Lost_Communication_with_Left_Camera_U026600, Lost_Communication_with_ORC_U015100, Lost_Communication_with_Rear_Camera_U026400, Lost_Communication_with_Right_Camera_U026700, PPP_Assist_Switch_Stuck_B12B22A, PTS_Sensor_1_Circuit_Open_B128E13, PTS_Sensor_1_Performance_or_Incorrect_Operation_B128E92, PTS_Sensor_2_Circuit_Open_B128F13, PTS_Sensor_2_Performance_or_Incorrect_Operation_B128F92, PTS_Sensor_3_Circuit_Open_B129013, PTS_Sensor_3_Performance_or_Incorrect_Operation_B129092, PTS_Sensor_4_Circuit_Open_B129113, PTS_Sensor_4_Performance_or_Incorrect_Operation_B129192, PTS_Sensor_5_Circuit_Open_B129213, PTS_Sensor_5_Performance_or_Incorrect_Operation_B129292, PTS_Sensor_6_Circuit_Open_B129313, PTS_Sensor_7_Circuit_Open_B129413, PTS_Sensor_7_Performance_or_Incorrect_Operation_B129492, PTS_Sensor_8_Circuit_Open_B129513, PTS_Sensor_8_Performance_or_Incorrect_Operation_B129592, PTS_Sensor_9_Circuit_Open_B129613, PTS_Sensor_9_Performance_or_Incorrect_Operation_B129692, PTS_Sensor_10_Circuit_Open_B129713, PTS_Sensor_10_Performance_or_Incorrect_Operation_B129792, PTS_Sensor_11_Circuit_Open_B129813, PTS_Sensor_11_Performance_or_Incorrect_Operation_B129892, PTS_Sensor_12_Circuit_Open_B129913, PTS_Sensor_12_Performance_or_Incorrect_Operation_B129992, Park_Assist_PTS_Switch_Stuck_B12852A, Rear_Camera_Circuit_Voltage_Out_of_Range_B217A1C, Rear_Camera_Performance_or_Incorrect_Operation_B217A92, Rear_Sensors_PS_Bus_Sig_Msg_Failures_B212B08, Rear_Sensors_PS_VltgeAboveThreshold_B212B17, Rear_Sensors_PS_VltgeBelowThreshold_B212B16, Right_Camera_Circuit_Voltage_Out_of_Range_B23C71C, Right_Camera_Performance_or_Incorrect_Operation_B23C792, Vehicle_Configuration_Mismatch_B223B00, PTS_Sensor_6_Performance_or_Incorrect_Operation_B129392, Dem_SystemInternalFailure] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryBlockId
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryBlockId
  \brief  The array contains these items: Admin, Status, 10 * Primary, Aging
*/ 
#define DEM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_MemoryBlockIdType, DEM_CONST) Dem_Cfg_MemoryBlockId[13] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MemoryBlockId                                                      Comment */
  /*     0 */ NvMConf_NvMBlockDescriptor_NvM_Dem_ADMIN /*NvMBlockId=27*/    ,  /* [DemNvRamBlockId_ADMIN] */
  /*     1 */ NvMConf_NvMBlockDescriptor_NvM_Dem_STATUS /*NvMBlockId=39*/   ,  /* [DemNvRamBlockId_STATUS] */
  /*     2 */ NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY0 /*NvMBlockId=29*/ ,  /* [DemNvRamBlockId_000] */
  /*     3 */ NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY1 /*NvMBlockId=30*/ ,  /* [DemNvRamBlockId_001] */
  /*     4 */ NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY2 /*NvMBlockId=31*/ ,  /* [DemNvRamBlockId_002] */
  /*     5 */ NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY3 /*NvMBlockId=32*/ ,  /* [DemNvRamBlockId_003] */
  /*     6 */ NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY4 /*NvMBlockId=33*/ ,  /* [DemNvRamBlockId_004] */
  /*     7 */ NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY5 /*NvMBlockId=34*/ ,  /* [DemNvRamBlockId_005] */
  /*     8 */ NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY6 /*NvMBlockId=35*/ ,  /* [DemNvRamBlockId_006] */
  /*     9 */ NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY7 /*NvMBlockId=36*/ ,  /* [DemNvRamBlockId_007] */
  /*    10 */ NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY8 /*NvMBlockId=37*/ ,  /* [DemNvRamBlockId_008] */
  /*    11 */ NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY9 /*NvMBlockId=38*/ ,  /* [DemNvRamBlockId_009] */
  /*    12 */ NvMConf_NvMBlockDescriptor_NvM_Dem_Aging /*NvMBlockId=28*/       /* [Dem_Cfg_Aging_0] */
};
#define DEM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryBlockIdToMemoryEntryId
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryBlockIdToMemoryEntryId
  \brief  The array contains these items: Admin, Status, 10 * Primary, Aging
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_MemoryEntryHandleType, DEM_CONST) Dem_Cfg_MemoryBlockIdToMemoryEntryId[13] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MemoryBlockIdToMemoryEntryId        Comment */
  /*     0 */ DEM_MEMORYENTRY_HANDLE_INVALID ,  /* [DemNvRamBlockId_ADMIN] */
  /*     1 */ DEM_MEMORYENTRY_HANDLE_INVALID ,  /* [DemNvRamBlockId_STATUS] */
  /*     2 */ 0u                             ,  /* [DemNvRamBlockId_000] */
  /*     3 */ 1u                             ,  /* [DemNvRamBlockId_001] */
  /*     4 */ 2u                             ,  /* [DemNvRamBlockId_002] */
  /*     5 */ 3u                             ,  /* [DemNvRamBlockId_003] */
  /*     6 */ 4u                             ,  /* [DemNvRamBlockId_004] */
  /*     7 */ 5u                             ,  /* [DemNvRamBlockId_005] */
  /*     8 */ 6u                             ,  /* [DemNvRamBlockId_006] */
  /*     9 */ 7u                             ,  /* [DemNvRamBlockId_007] */
  /*    10 */ 8u                             ,  /* [DemNvRamBlockId_008] */
  /*    11 */ 9u                             ,  /* [DemNvRamBlockId_009] */
  /*    12 */ DEM_MEMORYENTRY_HANDLE_INVALID    /* [Dem_Cfg_Aging_0] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryDataPtr
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryDataPtr
  \brief  The array contains these items: Admin, Status, 10 * Primary, Aging
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_NvDataPtrType, DEM_CONST) Dem_Cfg_MemoryDataPtr[13] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MemoryDataPtr                                                                                  Comment */
  /*     0 */ (Dem_NvDataPtrType) &Dem_Cfg_GetAdminData()        /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_ADMIN] */
  /*     1 */ (Dem_NvDataPtrType) &Dem_Cfg_GetStatusData()       /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_STATUS] */
  /*     2 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_0()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_000] */
  /*     3 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_1()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_001] */
  /*     4 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_2()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_002] */
  /*     5 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_3()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_003] */
  /*     6 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_4()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_004] */
  /*     7 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_5()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_005] */
  /*     8 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_6()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_006] */
  /*     9 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_7()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_007] */
  /*    10 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_8()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_008] */
  /*    11 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_9()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_009] */
  /*    12 */ (Dem_NvDataPtrType) &Dem_Cfg_GetAgingData()        /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */   /* [Dem_Cfg_Aging_0] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryDataSize
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryDataSize
  \brief  The array contains these items: Admin, Status, 10 * Primary, Aging
*/ 
#define DEM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_MemoryDataSizeType, DEM_CONST) Dem_Cfg_MemoryDataSize[13] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MemoryDataSize                                                        Comment */
  /*     0 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetAdminData())      ,  /* [DemNvRamBlockId_ADMIN] */
  /*     1 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetStatusData())     ,  /* [DemNvRamBlockId_STATUS] */
  /*     2 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_0()) ,  /* [DemNvRamBlockId_000] */
  /*     3 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_1()) ,  /* [DemNvRamBlockId_001] */
  /*     4 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_2()) ,  /* [DemNvRamBlockId_002] */
  /*     5 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_3()) ,  /* [DemNvRamBlockId_003] */
  /*     6 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_4()) ,  /* [DemNvRamBlockId_004] */
  /*     7 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_5()) ,  /* [DemNvRamBlockId_005] */
  /*     8 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_6()) ,  /* [DemNvRamBlockId_006] */
  /*     9 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_7()) ,  /* [DemNvRamBlockId_007] */
  /*    10 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_8()) ,  /* [DemNvRamBlockId_008] */
  /*    11 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_9()) ,  /* [DemNvRamBlockId_009] */
  /*    12 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetAgingData())         /* [Dem_Cfg_Aging_0] */
};
#define DEM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryEntry
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryEntry
  \brief  The array contains these items: 10 * Primary, ReadoutBuffer; size = DEM_CFG_GLOBAL_PRIMARY_SIZE + DEM_CFG_GLOBAL_SECONDARY_SIZE + DEM_CFG_NUMBER_OF_READOUTBUFFERS * DEM_CFG_NUMBER_OF_SUBEVENT_DATA_READOUTBUFFERS
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_SharedMemoryEntryPtrType, DEM_CONST) Dem_Cfg_MemoryEntry[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MemoryEntry                                                                                          Comment */
  /*     0 */ &Dem_Cfg_GetPrimaryEntry_0()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_000] */
  /*     1 */ &Dem_Cfg_GetPrimaryEntry_1()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_001] */
  /*     2 */ &Dem_Cfg_GetPrimaryEntry_2()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_002] */
  /*     3 */ &Dem_Cfg_GetPrimaryEntry_3()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_003] */
  /*     4 */ &Dem_Cfg_GetPrimaryEntry_4()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_004] */
  /*     5 */ &Dem_Cfg_GetPrimaryEntry_5()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_005] */
  /*     6 */ &Dem_Cfg_GetPrimaryEntry_6()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_006] */
  /*     7 */ &Dem_Cfg_GetPrimaryEntry_7()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_007] */
  /*     8 */ &Dem_Cfg_GetPrimaryEntry_8()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_008] */
  /*     9 */ &Dem_Cfg_GetPrimaryEntry_9()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlockId_009] */
  /*    10 */ &Dem_Cfg_GetReadoutBuffer(0).ReadOutBufferData[0].Data   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */   /* [Dem_Cfg_ReadoutBuffer[0].ReadOutBufferData[0].Data] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryEntryInit
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_PrimaryEntryType, DEM_CONST) Dem_Cfg_MemoryEntryInit = { 0 };  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_TimeSeriesEntryInit
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_TimeSeriesEntryType, DEM_CONST) Dem_Cfg_TimeSeriesEntryInit = { 0 };  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_AdminData
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_AdminDataType, DEM_NVM_DATA_NOINIT) Dem_Cfg_AdminData;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_AgingData
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_AgingDataType, DEM_NVM_DATA_NOINIT) Dem_Cfg_AgingData;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ClearDTCTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ClearDTCTable
  \brief  size = DEM_CFG_NUMBER_OF_CLEARDTCS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_ClearDTC_DataType, DEM_VAR_NOINIT) Dem_Cfg_ClearDTCTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_CommitBuffer
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_CommitBufferType, DEM_VAR_NOINIT) Dem_Cfg_CommitBuffer;  /* PRQA S 1514, 1533, 0759 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_MSR_Union */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DTCSelectorTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DTCSelectorTable
  \brief  size = DEM_CFG_NUMBER_OF_DTCSELECTORS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_DTCSelector_DataType, DEM_VAR_NOINIT) Dem_Cfg_DTCSelectorTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionFulfilled
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionFulfilled
  \brief  (DEM_CFG_SUPPORT_ENABLE_CONDITIONS == STD_ON) or there are internal EnableConditions. Table index: Condition ID. Table value: current condition state 'FALSE' not fulfilled, 'TRUE' fulfilled.
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_EnableConditionFulfilledType, DEM_VAR_NOINIT) Dem_Cfg_EnableConditionFulfilled[10];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionGroupCounter
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionGroupCounter
  \brief  (DEM_CFG_SUPPORT_ENABLE_CONDITIONS == STD_ON) or there are internal EnableConditions. Table index: Condition group number. Table value: count of conditions in state 'enable'.
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_EnableConditionGroupCounterType, DEM_VAR_NOINIT) Dem_Cfg_EnableConditionGroupCounter[15];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [##NoEnableConditionGroupConfigured, __Internal_ControlDtcSetting] */
  /*     1 */  /* [#EnableConditionGroup_2b31122d, __Internal_ControlDtcSetting, EC1_EC4_EC8, EC2] */
  /*     2 */  /* [#EnableConditionGroup_35222079, __Internal_ControlDtcSetting, EC1, EC4] */
  /*     3 */  /* [#EnableConditionGroup_5090bf01, __Internal_ControlDtcSetting, EC2, EC5] */
  /*     4 */  /* [#EnableConditionGroup_58fca5ad, __Internal_ControlDtcSetting, EC1, EC2, EC4, EC5, EC9] */
  /*     5 */  /* [#EnableConditionGroup_5926f32a, __Internal_ControlDtcSetting, EC2, EC9] */
  /*     6 */  /* [#EnableConditionGroup_9fd149a3, __Internal_ControlDtcSetting, EC2, EC5, EC9] */
  /*     7 */  /* [#EnableConditionGroup_EC1, __Internal_ControlDtcSetting, EC1] */
  /*     8 */  /* [#EnableConditionGroup_EC2, __Internal_ControlDtcSetting, EC2] */
  /*     9 */  /* [#EnableConditionGroup_a3268155, __Internal_ControlDtcSetting, EC1, EC2, EC10] */
  /*    10 */  /* [#EnableConditionGroup_bf4488aa, __Internal_ControlDtcSetting, EC1, EC2, EC4, EC5, EC7] */
  /*    11 */  /* [#EnableConditionGroup_d35ce624, __Internal_ControlDtcSetting, EC1, EC2, EC4, EC5] */
  /*    12 */  /* [#EnableConditionGroup_dc41854c, __Internal_ControlDtcSetting, EC1, EC2] */
  /*    13 */  /* [#EnableConditionGroup_eab14353, __Internal_ControlDtcSetting, EC2, EC4, EC5, EC9] */
  /*    14 */  /* [#EnableConditionGroup_f0773a88, __Internal_ControlDtcSetting, EC1_EC8, EC2] */

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionGroupState
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionGroupState
  \brief  (DEM_CFG_SUPPORT_ENABLE_CONDITIONS == STD_ON) or there are internal EnableConditions. Table index: Condition group number. Table value: count of conditions in state 'enable'.
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Dem_Cfg_EnableConditionGroupStateType, DEM_VAR_NOINIT) Dem_Cfg_EnableConditionGroupState[15];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [##NoEnableConditionGroupConfigured, __Internal_ControlDtcSetting] */
  /*     1 */  /* [#EnableConditionGroup_2b31122d, __Internal_ControlDtcSetting, EC1_EC4_EC8, EC2] */
  /*     2 */  /* [#EnableConditionGroup_35222079, __Internal_ControlDtcSetting, EC1, EC4] */
  /*     3 */  /* [#EnableConditionGroup_5090bf01, __Internal_ControlDtcSetting, EC2, EC5] */
  /*     4 */  /* [#EnableConditionGroup_58fca5ad, __Internal_ControlDtcSetting, EC1, EC2, EC4, EC5, EC9] */
  /*     5 */  /* [#EnableConditionGroup_5926f32a, __Internal_ControlDtcSetting, EC2, EC9] */
  /*     6 */  /* [#EnableConditionGroup_9fd149a3, __Internal_ControlDtcSetting, EC2, EC5, EC9] */
  /*     7 */  /* [#EnableConditionGroup_EC1, __Internal_ControlDtcSetting, EC1] */
  /*     8 */  /* [#EnableConditionGroup_EC2, __Internal_ControlDtcSetting, EC2] */
  /*     9 */  /* [#EnableConditionGroup_a3268155, __Internal_ControlDtcSetting, EC1, EC2, EC10] */
  /*    10 */  /* [#EnableConditionGroup_bf4488aa, __Internal_ControlDtcSetting, EC1, EC2, EC4, EC5, EC7] */
  /*    11 */  /* [#EnableConditionGroup_d35ce624, __Internal_ControlDtcSetting, EC1, EC2, EC4, EC5] */
  /*    12 */  /* [#EnableConditionGroup_dc41854c, __Internal_ControlDtcSetting, EC1, EC2] */
  /*    13 */  /* [#EnableConditionGroup_eab14353, __Internal_ControlDtcSetting, EC2, EC4, EC5, EC9] */
  /*    14 */  /* [#EnableConditionGroup_f0773a88, __Internal_ControlDtcSetting, EC1_EC8, EC2] */

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventDataCommitNumber
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventDataCommitNumber
  \brief  Index = Index in Dem_Cfg_Eventtable
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Dem_Cfg_EventDataCommitNumberType, DEM_VAR_NOINIT) Dem_Cfg_EventDataCommitNumber[68];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventDebounceValue
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventDebounceValue
  \brief  size = DEM_G_NUMBER_OF_EVENTS
*/ 
#define DEM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Dem_Cfg_EventDebounceValueType, DEM_VAR_NOINIT) Dem_Cfg_EventDebounceValue[68];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [#EVENT_INVALID, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*     1 */  /* [Battery_Voltage_Over_Voltage_B210C17, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     2 */  /* [Battery_Voltage_Under_Voltage_B210C16, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     3 */  /* [Calibration_Not_Learned_Lost_Calibration_B228600, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     4 */  /* [ECU_In_Plant_Mode_C221200, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     5 */  /* [ECU_Internal_Performance_B22A900, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     6 */  /* [Front_Camera_Circuit_Voltage_Out_of_Range_B23C51C, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     7 */  /* [Front_Camera_Performance_or_Incorrect_Operation_B23C592, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     8 */  /* [Front_Sensors_PS_Bus_Sig_Msg_Failures_B212A08, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     9 */  /* [Front_Sensors_PS_VltgeAboveThreshold_B212A17, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    10 */  /* [Front_Sensors_PS_VltgeBelowThreshold_B212A16, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    11 */  /* [HS_FD_CAN2_Comm_Bus_Performance_U104E00, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    12 */  /* [HS_FD_CANR_Comm_Bus_Performance_U100B00, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    13 */  /* [Implausible_Data_From_BSC_Module_1_U041800, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    14 */  /* [Implausible_Data_Received_From_Body_Control_Module_U042200, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    15 */  /* [Implausible_Data_Received_from_Radio_U048500, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    16 */  /* [Implausible_Data_from_ORC_module_U045500, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    17 */  /* [Implausible_Data_received_from_TRSKM_module_U14A000, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    18 */  /* [Implausible_data_received_from_ECM_U040100, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    19 */  /* [Invalid_Data_Received_From_Power_Steering_Control_Module_U042000, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    20 */  /* [Left_Camera_Circuit_Voltage_Out_of_Range_B23C61C, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    21 */  /* [Left_Camera_Performance_or_Incorrect_Operation_B23C692, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    22 */  /* [Loss_Communication_with_TRS_Knob_Module_U12B900, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    23 */  /* [Loss_of_Comm_With_Engine_Control_Module_U010000, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    24 */  /* [Lost_Communication_With_BCM_U014000, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    25 */  /* [Lost_Communication_With_BSC_module_1_U012900, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    26 */  /* [Lost_Communication_With_PSC_Module_A_U013100, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    27 */  /* [Lost_Communication_With_Radio_U018400, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    28 */  /* [Lost_Communication_with_Front_Camera_U026500, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    29 */  /* [Lost_Communication_with_Left_Camera_U026600, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    30 */  /* [Lost_Communication_with_ORC_U015100, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    31 */  /* [Lost_Communication_with_Rear_Camera_U026400, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    32 */  /* [Lost_Communication_with_Right_Camera_U026700, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    33 */  /* [PPP_Assist_Switch_Stuck_B12B22A, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    34 */  /* [PTS_Sensor_1_Circuit_Open_B128E13, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    35 */  /* [PTS_Sensor_1_Performance_or_Incorrect_Operation_B128E92, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    36 */  /* [PTS_Sensor_2_Circuit_Open_B128F13, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    37 */  /* [PTS_Sensor_2_Performance_or_Incorrect_Operation_B128F92, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    38 */  /* [PTS_Sensor_3_Circuit_Open_B129013, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    39 */  /* [PTS_Sensor_3_Performance_or_Incorrect_Operation_B129092, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    40 */  /* [PTS_Sensor_4_Circuit_Open_B129113, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    41 */  /* [PTS_Sensor_4_Performance_or_Incorrect_Operation_B129192, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    42 */  /* [PTS_Sensor_5_Circuit_Open_B129213, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    43 */  /* [PTS_Sensor_5_Performance_or_Incorrect_Operation_B129292, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    44 */  /* [PTS_Sensor_6_Circuit_Open_B129313, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    45 */  /* [PTS_Sensor_7_Circuit_Open_B129413, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    46 */  /* [PTS_Sensor_7_Performance_or_Incorrect_Operation_B129492, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    47 */  /* [PTS_Sensor_8_Circuit_Open_B129513, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    48 */  /* [PTS_Sensor_8_Performance_or_Incorrect_Operation_B129592, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    49 */  /* [PTS_Sensor_9_Circuit_Open_B129613, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /* Index        Referable Keys */
  /*    50 */  /* [PTS_Sensor_9_Performance_or_Incorrect_Operation_B129692, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    51 */  /* [PTS_Sensor_10_Circuit_Open_B129713, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    52 */  /* [PTS_Sensor_10_Performance_or_Incorrect_Operation_B129792, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    53 */  /* [PTS_Sensor_11_Circuit_Open_B129813, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    54 */  /* [PTS_Sensor_11_Performance_or_Incorrect_Operation_B129892, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    55 */  /* [PTS_Sensor_12_Circuit_Open_B129913, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    56 */  /* [PTS_Sensor_12_Performance_or_Incorrect_Operation_B129992, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    57 */  /* [Park_Assist_PTS_Switch_Stuck_B12852A, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    58 */  /* [Rear_Camera_Circuit_Voltage_Out_of_Range_B217A1C, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    59 */  /* [Rear_Camera_Performance_or_Incorrect_Operation_B217A92, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    60 */  /* [Rear_Sensors_PS_Bus_Sig_Msg_Failures_B212B08, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    61 */  /* [Rear_Sensors_PS_VltgeAboveThreshold_B212B17, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    62 */  /* [Rear_Sensors_PS_VltgeBelowThreshold_B212B16, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    63 */  /* [Right_Camera_Circuit_Voltage_Out_of_Range_B23C71C, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    64 */  /* [Right_Camera_Performance_or_Incorrect_Operation_B23C792, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    65 */  /* [Vehicle_Configuration_Mismatch_B223B00, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    66 */  /* [PTS_Sensor_6_Performance_or_Incorrect_Operation_B129392, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    67 */  /* [Dem_SystemInternalFailure, #NoExtendedDataRecordConfigured, Satellite#0] */

#define DEM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventInternalStatus
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventInternalStatus
  \brief  size = DEM_G_NUMBER_OF_EVENTS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Dem_Event_InternalStatusType, DEM_VAR_NOINIT) Dem_Cfg_EventInternalStatus[68];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [#EVENT_INVALID, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*     1 */  /* [Battery_Voltage_Over_Voltage_B210C17, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     2 */  /* [Battery_Voltage_Under_Voltage_B210C16, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     3 */  /* [Calibration_Not_Learned_Lost_Calibration_B228600, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     4 */  /* [ECU_In_Plant_Mode_C221200, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     5 */  /* [ECU_Internal_Performance_B22A900, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     6 */  /* [Front_Camera_Circuit_Voltage_Out_of_Range_B23C51C, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     7 */  /* [Front_Camera_Performance_or_Incorrect_Operation_B23C592, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     8 */  /* [Front_Sensors_PS_Bus_Sig_Msg_Failures_B212A08, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*     9 */  /* [Front_Sensors_PS_VltgeAboveThreshold_B212A17, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    10 */  /* [Front_Sensors_PS_VltgeBelowThreshold_B212A16, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    11 */  /* [HS_FD_CAN2_Comm_Bus_Performance_U104E00, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    12 */  /* [HS_FD_CANR_Comm_Bus_Performance_U100B00, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    13 */  /* [Implausible_Data_From_BSC_Module_1_U041800, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    14 */  /* [Implausible_Data_Received_From_Body_Control_Module_U042200, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    15 */  /* [Implausible_Data_Received_from_Radio_U048500, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    16 */  /* [Implausible_Data_from_ORC_module_U045500, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    17 */  /* [Implausible_Data_received_from_TRSKM_module_U14A000, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    18 */  /* [Implausible_data_received_from_ECM_U040100, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    19 */  /* [Invalid_Data_Received_From_Power_Steering_Control_Module_U042000, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    20 */  /* [Left_Camera_Circuit_Voltage_Out_of_Range_B23C61C, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    21 */  /* [Left_Camera_Performance_or_Incorrect_Operation_B23C692, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    22 */  /* [Loss_Communication_with_TRS_Knob_Module_U12B900, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    23 */  /* [Loss_of_Comm_With_Engine_Control_Module_U010000, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    24 */  /* [Lost_Communication_With_BCM_U014000, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    25 */  /* [Lost_Communication_With_BSC_module_1_U012900, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    26 */  /* [Lost_Communication_With_PSC_Module_A_U013100, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    27 */  /* [Lost_Communication_With_Radio_U018400, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    28 */  /* [Lost_Communication_with_Front_Camera_U026500, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    29 */  /* [Lost_Communication_with_Left_Camera_U026600, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    30 */  /* [Lost_Communication_with_ORC_U015100, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    31 */  /* [Lost_Communication_with_Rear_Camera_U026400, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    32 */  /* [Lost_Communication_with_Right_Camera_U026700, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    33 */  /* [PPP_Assist_Switch_Stuck_B12B22A, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    34 */  /* [PTS_Sensor_1_Circuit_Open_B128E13, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    35 */  /* [PTS_Sensor_1_Performance_or_Incorrect_Operation_B128E92, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    36 */  /* [PTS_Sensor_2_Circuit_Open_B128F13, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    37 */  /* [PTS_Sensor_2_Performance_or_Incorrect_Operation_B128F92, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    38 */  /* [PTS_Sensor_3_Circuit_Open_B129013, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    39 */  /* [PTS_Sensor_3_Performance_or_Incorrect_Operation_B129092, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    40 */  /* [PTS_Sensor_4_Circuit_Open_B129113, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    41 */  /* [PTS_Sensor_4_Performance_or_Incorrect_Operation_B129192, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    42 */  /* [PTS_Sensor_5_Circuit_Open_B129213, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    43 */  /* [PTS_Sensor_5_Performance_or_Incorrect_Operation_B129292, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    44 */  /* [PTS_Sensor_6_Circuit_Open_B129313, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    45 */  /* [PTS_Sensor_7_Circuit_Open_B129413, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    46 */  /* [PTS_Sensor_7_Performance_or_Incorrect_Operation_B129492, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    47 */  /* [PTS_Sensor_8_Circuit_Open_B129513, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    48 */  /* [PTS_Sensor_8_Performance_or_Incorrect_Operation_B129592, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    49 */  /* [PTS_Sensor_9_Circuit_Open_B129613, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /* Index        Referable Keys */
  /*    50 */  /* [PTS_Sensor_9_Performance_or_Incorrect_Operation_B129692, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    51 */  /* [PTS_Sensor_10_Circuit_Open_B129713, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    52 */  /* [PTS_Sensor_10_Performance_or_Incorrect_Operation_B129792, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    53 */  /* [PTS_Sensor_11_Circuit_Open_B129813, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    54 */  /* [PTS_Sensor_11_Performance_or_Incorrect_Operation_B129892, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    55 */  /* [PTS_Sensor_12_Circuit_Open_B129913, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    56 */  /* [PTS_Sensor_12_Performance_or_Incorrect_Operation_B129992, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    57 */  /* [Park_Assist_PTS_Switch_Stuck_B12852A, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    58 */  /* [Rear_Camera_Circuit_Voltage_Out_of_Range_B217A1C, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    59 */  /* [Rear_Camera_Performance_or_Incorrect_Operation_B217A92, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    60 */  /* [Rear_Sensors_PS_Bus_Sig_Msg_Failures_B212B08, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    61 */  /* [Rear_Sensors_PS_VltgeAboveThreshold_B212B17, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    62 */  /* [Rear_Sensors_PS_VltgeBelowThreshold_B212B16, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    63 */  /* [Right_Camera_Circuit_Voltage_Out_of_Range_B23C71C, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    64 */  /* [Right_Camera_Performance_or_Incorrect_Operation_B23C792, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    65 */  /* [Vehicle_Configuration_Mismatch_B223B00, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    66 */  /* [PTS_Sensor_6_Performance_or_Incorrect_Operation_B129392, #EdrExtendedDataRecord_OccurrenceCounter, Satellite#0] */
  /*    67 */  /* [Dem_SystemInternalFailure, #NoExtendedDataRecordConfigured, Satellite#0] */

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ExtendedDataRecordIteratorTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ExtendedDataRecordIteratorTable
  \brief  size = 1
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_ExtendedDataRecordIterator_FilterType, DEM_VAR_NOINIT) Dem_Cfg_ExtendedDataRecordIteratorTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FilterInfoTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FilterInfoTable
  \brief  size = DEM_CFG_NUMBER_OF_FILTER
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_FilterData_InfoType, DEM_VAR_NOINIT) Dem_Cfg_FilterInfoTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FreezeFrameIteratorTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FreezeFrameIteratorTable
  \brief  size = DEM_CFG_NUMBER_OF_FREEZEFRAMEITERATORS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_FreezeFrameIterator_FilterType, DEM_VAR_NOINIT) Dem_Cfg_FreezeFrameIteratorTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryCurrentCount
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_MemoryCurrentCountType, DEM_VAR_NOINIT) Dem_Cfg_MemoryCurrentCount[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryStatus
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryStatus
  \brief  The array contains these items: Admin, Status, 10 * Primary, Aging
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_MemoryStatusType, DEM_VAR_NOINIT) Dem_Cfg_MemoryStatus[13];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryChronology
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_PrimaryChronology
  \brief  size = DEM_CFG_GLOBAL_PRIMARY_SIZE
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_MemoryIndexType, DEM_VAR_NOINIT) Dem_Cfg_PrimaryChronology[10];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_0
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_0;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_1
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_1;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_2
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_2;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_3
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_3;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_4
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_4;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_5
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_5;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_6
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_6;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_7
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_7;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_8
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_8;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_9
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_9;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ReadoutBuffer
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_ReadoutBufferEntryType, DEM_VAR_NOINIT) Dem_Cfg_ReadoutBuffer[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ReportedEventsOfFilter
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ReportedEventsOfFilter
  \brief  size = DEM_CFG_NUMBER_OF_FILTER
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_ReportedEventsType, DEM_VAR_NOINIT) Dem_Cfg_ReportedEventsOfFilter[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SatelliteInfo0
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_SatelliteInfo0
  \brief  Buffer for satellite data on OsApplication "0"
*/ 
#define DEM_START_SEC_0_VAR_ZERO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_SatelliteInfoType0, DEM_VAR_ZERO_INIT) Dem_Cfg_SatelliteInfo0 = {0};  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_0_VAR_ZERO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_StatusData
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_StatusDataType, DEM_NVM_DATA_NOINIT) Dem_Cfg_StatusData;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/



/**********************************************************************************************************************
  END OF FILE: Dem_Lcfg.c     [Fca (Vector), VARIANT-PRE-COMPILE, 22.06.00.146775]
**********************************************************************************************************************/

