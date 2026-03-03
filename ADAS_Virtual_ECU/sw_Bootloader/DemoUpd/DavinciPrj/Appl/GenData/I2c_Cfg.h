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
 *            Module: I2c
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: I2c_Cfg.h
 *   Generation Time: 2022-11-08 19:25:58
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D04
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined I2C_CFG_H
#define I2C_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Det.h"
#include "SchM_I2c.h"
#include "I2c_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define I2C_CFG_MAJOR_VERSION       (2u)
#define I2C_CFG_MINOR_VERSION       (1u)
#define I2C_CFG_PATCH_VERSION       (0u)

/*! \brief Version defines that are used to check the compatibility of the generated data */
# define I2C_CFG_COMP_MAJOR_VERSION   2u
# define I2C_CFG_COMP_MINOR_VERSION   1u
# define I2C_CFG_COMP_PATCH_VERSION   0u


#define I2C_GET_STATUS_API          (STD_ON) /*!< Enables/disables the API service I2c_GetStatus(). */
#define I2C_CANCEL_API              (STD_ON) /*!< Enables/disables the API service I2c_Cancel(). */
#define I2C_VERSION_INFO_API        (STD_ON) /*!< Enables/disables the API service I2c_GetVersionApi(). */

#define I2C_PROTECTED_MODE          (STD_OFF) /*!< Enables/disables the usage of OS APIs for register access. */

#define I2C_POLLING_MODE            (STD_ON) /*!< Enables/disables the I2c Polling mode. */

#define I2C_DEV_ERROR_DETECT        (STD_ON) /*!< Enables/Disables Development Error Detection. */
#define I2C_DEV_ERROR_REPORT        (STD_ON) /*!< Enables/Disables Development Error Reporting. */

#define I2C_DEM_ERROR_REPORT        (STD_OFF)  /*!< Enables/Disables Diagnostic Event Reporting. */


#define I2C_PRIO_QUEUE_DEPTH        (10u) /*!< Depth of sequence priority queue (per HwUnit). */
#define I2C_PRIO_QUEUE_BUFFER_SIZE  (I2C_PRIO_QUEUE_DEPTH + 1U) /*!< Add. queue elem. required for management purpose. */

#define I2C_TRANS_BUFFER_SIZE       (2u) /*!< Size of transmission buffer (equals max. channel chain length). */

/**********************************************************************************************************************
*  GENERAL DEFINE BLOCK
*********************************************************************************************************************/
#ifndef I2C_USE_DUMMY_STATEMENT
#define I2C_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef I2C_DUMMY_STATEMENT
#define I2C_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef I2C_DUMMY_STATEMENT_CONST
#define I2C_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef I2C_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define I2C_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef I2C_ATOMIC_VARIABLE_ACCESS
#define I2C_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef I2C_PROCESSOR_TDA4VE88
#define I2C_PROCESSOR_TDA4VE88
#endif
#ifndef I2C_COMP_LLVMTEXASINSTRUMENTS
#define I2C_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef I2C_GEN_GENERATOR_MSR
#define I2C_GEN_GENERATOR_MSR
#endif
#ifndef I2C_CPUTYPE_BITORDER_LSB2MSB
#define I2C_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef I2C_CONFIGURATION_VARIANT_PRECOMPILE
#define I2C_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef I2C_CONFIGURATION_VARIANT_LINKTIME
#define I2C_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef I2C_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define I2C_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef I2C_CONFIGURATION_VARIANT
#define I2C_CONFIGURATION_VARIANT I2C_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef I2C_POSTBUILD_VARIANT_SUPPORT
#define I2C_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

 
/**********************************************************************************************************************
*  Symbolic name values
*********************************************************************************************************************/
/* Symbolic Name Values for Channels of I2cConfigSet */ 
#define I2cConf_I2cChannel_I2cChannel_Eep_Ack_Ack  (4u) 
#define I2cConf_I2cChannel_I2cChannel_Eep_Read_Command  (0u) 
#define I2cConf_I2cChannel_I2cChannel_Eep_Read_Data  (1u) 
#define I2cConf_I2cChannel_I2cChannel_Eep_Write_Command  (2u) 
#define I2cConf_I2cChannel_I2cChannel_Eep_Write_Data  (3u) 

/* Symbolic Name Values for sequences of I2cConfigSet */ 
#define I2cConf_I2cSequence_I2cSequence_Eep_Ack  (2u) 
#define I2cConf_I2cSequence_I2cSequence_Eep_Read  (0u) 
#define I2cConf_I2cSequence_I2cSequence_Eep_Write  (1u) 




/* Symbolic Name Values for buses of I2cConfigSet */ 
#define I2cConf_I2cBus_I2cBus  (0u) 


/* Symbolic Name Values for HwUnits of I2cConfigSet */ 
#define I2cConf_I2cHardwareUnit_I2cHardwareUnit  (0u) 


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! Priority Queue Descriptor. */
 
typedef struct
{
  I2c_PrioQueueLengthType StartIndex;
  I2c_PrioQueueLengthType EndIndex;
  I2c_SequenceType PrioQueue[I2C_PRIO_QUEUE_BUFFER_SIZE];
} I2c_PrioQueueDescType;
typedef P2VAR(I2c_PrioQueueDescType, AUTOMATIC, I2C_VAR) I2c_PrioQueueDescPtrType; 
typedef P2CONST(I2c_PrioQueueDescType, AUTOMATIC, I2C_CONST) I2c_ConstPrioQueueDescPtrType;



/* Definition of the maximum amount of I2c HW-Loop cycles */
#define I2C_HW_LOOP_MAX   (20u) /*!< Maximum number of HW-Loop cycles. */

typedef struct
{
  I2c_AddressType SlaveAddress;
  I2c_TransBufferDescType TransBufferDesc[I2C_TRANS_BUFFER_SIZE];
  I2c_TransDirectionType TransDir;
  I2c_ChannelIndexType NumOfChannels;
  boolean HoldBus;
  boolean RepeatedStart;
} I2c_TransDataType;
typedef P2VAR(I2c_TransDataType, AUTOMATIC, I2C_VAR_NO_INIT) I2c_TransDataPtrType;
typedef P2CONST(I2c_TransDataType, AUTOMATIC, I2C_CONST) I2c_ConstTransDataPtrType;

/*! Type to define the baud-rate. */
typedef struct
{
  uint32 ScllRegValue;
  uint32 SclhRegValue;
  uint8 PscRegValue;
} I2c_BaudrateType;

/*! Type to determine the timeout */
typedef struct
{
  I2c_TimeoutType LimitVal; /*!< Limit after which timeout exceeds. */
  I2c_TimeoutType CntVal; /*!< Current timeout counter. */
} I2c_TimeoutValuesType;

typedef enum
{
  UNINIT,
  IDLE,
  BUSY,
  READ_REQUEST
} I2c_PerMgrStates;

/*! Type to store runtime data of Peripheral Manager. */
typedef struct
{
  I2c_PerMgrStates State; /*!< Stores the state of the PerMgr. */
  uint32 BufDescrIdx; /*!< Index of currently processed buffer descriptor. */
  I2c_DataLengthType CurBufIdx; /*!< Stores index of byte in current BufDescr. */
  I2c_TimeoutValuesType Timeout; /*!< Timeout-specific values. */
  boolean ReportResult; /*!< Indicates whether result should be reported to TransProc. */
  I2c_ChannelResultType Result; /*!< Stores the result which should be reported to TransProc. */
} I2c_PerMgrType;
typedef P2VAR(I2c_PerMgrType, AUTOMATIC, I2C_VAR_NO_INIT) I2c_VarPerMgrPtrType;
typedef P2CONST(I2c_PerMgrType, AUTOMATIC, I2C_CONST) I2c_ConstPerMgrPtrType;

/* Variable descriptor for I2C hardware unit. */
typedef struct
{
  I2c_PrioQueueDescType PrioQueueDesc; /*!< Bus specific sequence priority queue. */
  I2c_HardwareProcessorType ProcessedSeq; /*!< Currently processed sequence. */
  I2c_TransDataType TransData; /*!< Transmission specific data. */
  I2c_PerMgrType PerData; /*!< Peripheral specific data. */
} I2c_VarHwUnitDescType;
typedef P2VAR(I2c_VarHwUnitDescType, AUTOMATIC, I2C_VAR_NO_INIT) I2c_VarHwUnitDescPtrType;

/* Constant descriptor for I2C hardware unit. */
typedef struct
{
  I2c_HwUnitType HwUnitId;
  uint32 UnitBaseAddr; /*!< Pointer to units registers. */
# if (I2C_PROTECTED_MODE == STD_ON)
  Os_PeripheralIdType OsAreaReg; /*!< Area parameter for safe OS. */
# endif
  I2c_VarHwUnitDescPtrType varHwUnitDescPtr; /*!< Pointer to the variable HwUnit descriptor. */
} I2c_ConstHwUnitDescType;
typedef P2CONST(I2c_ConstHwUnitDescType, AUTOMATIC, I2C_PBCFG) I2c_ConstHwUnitDescPtrType;


/* I2c bus configuration structure */
typedef struct
{
  I2c_BusType BusId;
  I2c_ConstHwUnitDescPtrType HwCfgPtr;
  I2c_TimeoutType BusTimeout; /* Timeout for unit */
  I2c_BaudrateType Baudrate;
} I2c_BusDescType;
typedef P2CONST(I2c_BusDescType, AUTOMATIC, I2C_PBCFG) I2c_BusDescPtrType;

/* Variable sequence configuration structure. */
typedef struct
{
  I2c_SeqResultType SeqResult;
  I2c_ChannelIndexType LeadingChannel;
  I2c_ChannelIndexType NextChannel;
} I2c_VarSeqDescType;
typedef P2VAR(I2c_VarSeqDescType, AUTOMATIC, I2C_PBCFG) I2c_VarSeqDescPtrType;

/* I2c sequence configuration structure. */
typedef struct
{
  I2c_SequenceType SeqId; /* Unique sequence ID. */
  SequenceEndNotificationType SequenceEndNotification; /* Sequence end notification   */
  SequenceErrorNotificationType SequenceErrorNotification; /* Sequence error notification */
  I2c_VarSeqDescPtrType VarSeqDescPtr; /* Pointer to sequence result */
  I2c_ChannelConstPtrType ChannelListPtr; /* Pointer to channel list in a sequence */
  I2c_ChannelIndexType NumOfChannels; /* Number of channels within the channel list. */
  I2c_BusDescPtrType BusCfgPtr; /* Pointer to bus configuration */
  boolean NackAsError; /* Handle NACK as error (yes = 1) */
  I2c_SeqPrioType SequencePrio; /* Priority of sequence. (0 = lowest) */
} I2c_ConstSeqDescType;
typedef P2CONST(I2c_ConstSeqDescType, AUTOMATIC, I2C_PBCFG) I2c_ConstSeqDescPtrType;

/* Variable descriptor type for I2c channels. */
typedef struct
{
  I2c_AddressType SlaveDevAddr; /* Slave address. */
  I2c_DataPtrType BufPtr; /* Pointer to the transmission buffer. */
  I2c_DataLengthType Length; /* Length of the transmission buffer. */
  I2c_ChannelStatusType Status; /* Channel status. */
  I2c_ChannelResultType Result; /* Channel result. */
  I2c_TransDirectionType TransDir; /* Transmission direction. */
} I2c_VarChannelDescType;
typedef P2VAR(I2c_VarChannelDescType, AUTOMATIC, I2C_VAR) I2c_VarChannelDescPtrType;

/* Const descriptor type for I2c channels. */
typedef struct
{
  I2c_ChannelType ChannelId;
  I2c_AddressType DefaultSlaveDevAddr; /* Configured slave address. */
  I2c_DataType DefaultData; /* Data to be transmitted if buffers are NULL_PTR */
  boolean Chained; /* Chained channel  */
  I2c_VarChannelDescPtrType VarChannelDescPtr; /* Pointer to the variable channel parameters */
} I2c_ConstChannelDescType;
typedef P2CONST(I2c_ConstChannelDescType, AUTOMATIC, I2C_PBCFG) I2c_ConstChannelDescPtrType;

/* Configuration type. */
typedef struct
{
# if(I2C_DEM_ERROR_REPORT == STD_ON)
  Dem_EventIdType DemAddressError;
  Dem_EventIdType DemArbitrationLoss;
  Dem_EventIdType DemBusError;
# endif
  I2c_ConstSeqDescPtrType SequenceCfgPtr; /* Sequence configuration mapping */
  I2c_ConstChannelDescPtrType ChannelCfgPtr; /* Channel configuration mapping  */
  I2c_BusDescPtrType BusCfgPtr;
  I2c_ConstHwUnitDescPtrType HwCfgPtr; /* Hardware configuration mapping */
  uint8 NumOfSeq; /* Maximum number of sequences */
  uint8 NumOfCh; /* Maximum number of channels  */
  uint8 NumOfBus; /* Maximum number of buses */
  uint8 NumOfHwUnits; /* Maximum number of hardware units */
} I2c_ConfigType;
typedef P2CONST(I2c_ConfigType, AUTOMATIC, I2C_PBCFG) I2c_ConfigPtrType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define I2C_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(I2c_ConfigPtrType, I2C_PBCFG) I2c_ConfigPtr;

#define I2C_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define I2C_START_SEC_PBCFG_ROOT
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 
extern CONST(I2c_ConfigType, I2C_CONST) I2c_ConfigSet[1]; 

#define I2C_STOP_SEC_PBCFG_ROOT
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 


#endif /* I2C_CFG_H */
/**********************************************************************************************************************
 *  END OF FILE: I2c_Cfg.h
 *********************************************************************************************************************/
