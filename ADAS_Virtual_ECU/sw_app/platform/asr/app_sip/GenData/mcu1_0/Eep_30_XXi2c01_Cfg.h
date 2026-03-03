/**** Protection against multiple inclusion **************************************************************************/
#if !defined (EEP_30_XXI2C01_CFG_H)
# define EEP_30_XXI2C01_CFG_H

/**********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 *********************************************************************************************************************/

#ifndef EEP_30_XXI2C01_USE_DUMMY_STATEMENT
#define EEP_30_XXI2C01_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef EEP_30_XXI2C01_DUMMY_STATEMENT
#define EEP_30_XXI2C01_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef EEP_30_XXI2C01_DUMMY_STATEMENT_CONST
#define EEP_30_XXI2C01_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef EEP_30_XXI2C01_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define EEP_30_XXI2C01_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef EEP_30_XXI2C01_ATOMIC_VARIABLE_ACCESS
#define EEP_30_XXI2C01_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef EEP_30_XXI2C01_PROCESSOR_TDA4VE88
#define EEP_30_XXI2C01_PROCESSOR_TDA4VE88
#endif
#ifndef EEP_30_XXI2C01_COMP_LLVMTEXASINSTRUMENTS
#define EEP_30_XXI2C01_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef EEP_30_XXI2C01_GEN_GENERATOR_MSR
#define EEP_30_XXI2C01_GEN_GENERATOR_MSR
#endif
#ifndef EEP_30_XXI2C01_CPUTYPE_BITORDER_LSB2MSB
#define EEP_30_XXI2C01_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef EEP_30_XXI2C01_CONFIGURATION_VARIANT_PRECOMPILE
#define EEP_30_XXI2C01_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef EEP_30_XXI2C01_CONFIGURATION_VARIANT_LINKTIME
#define EEP_30_XXI2C01_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef EEP_30_XXI2C01_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define EEP_30_XXI2C01_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef EEP_30_XXI2C01_CONFIGURATION_VARIANT
#define EEP_30_XXI2C01_CONFIGURATION_VARIANT EEP_30_XXI2C01_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef EEP_30_XXI2C01_POSTBUILD_VARIANT_SUPPORT
#define EEP_30_XXI2C01_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

/**********************************************************************************************************************
 *  GENERATOR VERSION
 *********************************************************************************************************************/

/* This is not the sub-package version but a compatibility version, which will only be updated if a change in the 
   generator (i.e. generated files) affects the implementation sub-package */
# define EEP_30_XXI2C01_CFG_MAJOR_VERSION	(2u) 
# define EEP_30_XXI2C01_CFG_MINOR_VERSION	(1u) 
# define EEP_30_XXI2C01_CFG_PATCH_VERSION	(0u) 

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define EEP_30_XXI2C01_DEV_ERROR_DETECT         STD_ON 
# define EEP_30_XXI2C01_DEV_ERROR_REPORT         STD_ON 
# define EEP_30_XXI2C01_VERSION_INFO_API         STD_OFF 
# define EEP_30_XXI2C01_MULTI_CHANNEL            STD_OFF 
# define EEP_30_XXI2C01_TEST_COM_API             STD_OFF 
# define EEP_30_XXI2C01_EXTENDED_ADDRESSING      STD_OFF 

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
# include "Dem.h" 
# include "MemIf_Types.h" 
# include "Det.h" 
# include "I2c.h" 

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* type for main function handling */
typedef enum
{
  EEP_30_XXI2C01_HANDLING_BURST = 0, 
  EEP_30_XXI2C01_HANDLING_RECURRENT
} Eep_30_XXi2c01_HandlingType;

/* types for addressing data on the EEPROM chip (depends on EEPROM memory base address + used size. It's either uint8, uint16 or uint32) */
typedef uint16 Eep_30_XXi2c01_AddressType;
typedef uint16 Eep_30_XXi2c01_LengthType;

/* notification callback function declaration type */
typedef P2FUNC(void, EEP_30_XXI2C01_APPL_CODE, Eep_30_XXi2c01_NotificationType)(void);

/* EEPROM chip type */
typedef struct
{
  I2c_DataLengthType CommandBufferSize;
  uint16 PageSize;
  uint16 WriteTime;
} Eep_30_XXi2c01_ChipType;



/* Spi interface */
typedef P2FUNC(Std_ReturnType, EEP_30_XXI2C01_CODE, Eep_30_XXi2c01_SetupEBPtrType)(I2c_ChannelType Channel, const I2c_DataType * TxDataBufferPtr, I2c_DataType * RxDataBufferPtr, I2c_DataLengthType Length); 
typedef P2FUNC(Std_ReturnType, EEP_30_XXI2C01_CODE, Eep_30_XXi2c01_AsyncTransmitPtrType)(I2c_SequenceType Sequence); 
typedef P2FUNC(I2c_SeqResultType, EEP_30_XXI2C01_CODE, Eep_30_XXi2c01_GetSequenceResultPtrType)(I2c_SequenceType Sequence); 

typedef struct
{
  Eep_30_XXi2c01_SetupEBPtrType SetupEB; 
  Eep_30_XXi2c01_AsyncTransmitPtrType AsyncTransmit; 
  Eep_30_XXi2c01_GetSequenceResultPtrType GetSequenceResult; 
} Eep_30_XXi2c01_I2cApiType;

typedef P2CONST(Eep_30_XXi2c01_I2cApiType, AUTOMATIC, EEP_30_XXI2C01_APPL_DATA) Eep_30_XXi2c01_I2cApiPtrType;

/* Config type */
typedef struct
{
  /* DEM events */ 
  Dem_EventIdType EReadFailed; 
  Dem_EventIdType ECompareFailed; 
  Dem_EventIdType EWriteFailed; 
  Dem_EventIdType EEraseFailed; 
  /* I2C references */ 
  I2c_SequenceType RdSequence; 
  I2c_ChannelType RdCommandChannel; 
  I2c_ChannelType RdDataChannel; 
  I2c_SequenceType WrSequence; 
  I2c_ChannelType WrCommandChannel; 
  I2c_ChannelType WrDataChannel; 
  I2c_SequenceType AckSequence; 
  I2c_ChannelType AckChannel; 
  /* default mode and default handling */ 
  MemIf_ModeType DefaultMode; 
  Eep_30_XXi2c01_HandlingType DefaultHandling; 
  /* the number of recurrent/ burst queries depending on the handling mode */ 
  uint16 NbOfRecurrentQueries; 
  uint16 NbOfBurstQueries; 
  /* base address and last used address for EEPROM memory (if present, the incremental registers are located within address space [0..BaseAddress - 1] */ 
  Eep_30_XXi2c01_AddressType MemBaseAddress; 
  Eep_30_XXi2c01_AddressType MemLastUsedAddress; 
  /* read/ compare and write/ erase sizes for slow (normal) mode and fast mode */ 
  uint16 ReadSize[2u]; 
  uint16 WriteSize[2u]; 
  /* notification callbacks */ 
  Eep_30_XXi2c01_NotificationType JobEndNotification; 
  Eep_30_XXi2c01_NotificationType JobErrorNotification; 
  /* pointer to I2c functions */ 
  Eep_30_XXi2c01_I2cApiPtrType I2cApiPtr; 
} Eep_30_XXi2c01_ConfigType;

/**********************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/* chip configurations */
# define EEP_30_XXI2C01_START_SEC_CONST_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
extern CONST(Eep_30_XXi2c01_ChipType, EEP_30_XXI2C01_CONST) Eep_30_XXi2c01_Chip; 
 
# define EEP_30_XXI2C01_STOP_SEC_CONST_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 

/* EEPROM root configurations */
# define EEP_30_XXI2C01_START_SEC_PBCFG_ROOT 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
extern CONST(Eep_30_XXi2c01_ConfigType, EEP_30_XXI2C01_PBCFG) Eep_30_XXi2c01_Runtime; 
 
# define EEP_30_XXI2C01_STOP_SEC_PBCFG_ROOT 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 

/* EEPROM buffers */
# define EEP_30_XXI2C01_START_SEC_VAR_NO_INIT_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
/* command buffers */ 
extern VAR(I2c_DataType, EEP_30_XXI2C01_VAR_NO_INIT) Eep_30_XXi2c01_CommandBuffer[2u]; 
 
 
/* data buffers */ 
extern VAR(I2c_DataType, EEP_30_XXI2C01_VAR_NO_INIT) Eep_30_XXi2c01_DataBuffer[32u]; 
 
# define EEP_30_XXI2C01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 


# define EEP_30_XXI2C01_START_SEC_VAR_INIT_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
/* array with chip configurations */ 
extern P2CONST(Eep_30_XXi2c01_ChipType, EEP_30_XXI2C01_VAR_INIT, EEP_30_XXI2C01_CONST) Eep_30_XXi2c01_ChipPtr[1u]; 
 
/* array with command buffers */ 
extern P2VAR(I2c_DataType, EEP_30_XXI2C01_VAR_INIT, EEP_30_XXI2C01_VAR_NO_INIT) Eep_30_XXi2c01_CommandBufferPtr[1u]; 
 
/* array with data buffers */ 
extern P2VAR(I2c_DataType, EEP_30_XXI2C01_VAR_INIT, EEP_30_XXI2C01_VAR_NO_INIT) Eep_30_XXi2c01_DataBufferPtr[1u]; 
 
/* array with config pointers */ 
extern P2CONST(Eep_30_XXi2c01_ConfigType, EEP_30_XXI2C01_VAR_INIT, EEP_30_XXI2C01_CONST) Eep_30_XXi2c01_CfgPtr[1u]; 
 
# define EEP_30_XXI2C01_STOP_SEC_VAR_INIT_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 


/* bus interface */
# define EEP_30_XXI2C01_START_SEC_CONST_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
extern CONST(Eep_30_XXi2c01_I2cApiType, EEP_30_XXI2C01_CONST) Eep_30_XXi2c01_I2cApi0; 
 
# define EEP_30_XXI2C01_STOP_SEC_CONST_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 


#endif /* EEP_30_XXI2C01_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Eep_30_XXi2c01_Cfg.h
 *********************************************************************************************************************/
 

