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
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: I2c_PBcfg.c
 *   Generation Time: 2024-02-13 13:07:49
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define I2C_PBCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "I2c.h"
#include "Eep_30_XXi2c01_Cbk.h"
#include "CDD_PMIC.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if (  (I2C_CFG_MAJOR_VERSION != (2u)) \
    || (I2C_CFG_MINOR_VERSION != (1u)) )
#error "Version numbers of I2c_PBcfg.c and I2c_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/
#define I2C_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 
static CONST(I2c_ConstHwUnitDescType, I2C_CONST) I2c_ConstHwUnitDescrList_I2cConfigSet[1]; 

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 

#define I2C_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 
static VAR(I2c_VarHwUnitDescType, I2C_VAR) I2c_VarHwUnitDescrList_I2cConfigSet[1]; 

#define I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 

#define I2C_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 
static CONST(I2c_BusDescType, I2C_CONST) I2c_ConstBusDescrList_I2cConfigSet[1]; 

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 

#define I2C_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 
/* PRQA S 0777 1 */  /* MD_MSR_5.1_777 */ 
static CONST(I2c_ChannelType, I2C_CONST) I2c_I2cConfigSet_I2cSequence_EEPROM_Read_ChannelList[2]; 

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 

#define I2C_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 
/* PRQA S 0777 1 */  /* MD_MSR_5.1_777 */ 
static CONST(I2c_ChannelType, I2C_CONST) I2c_I2cConfigSet_I2cSequence_EEPROM_Write_ChannelList[2]; 

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 

#define I2C_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 
/* PRQA S 0777 1 */  /* MD_MSR_5.1_777 */ 
static CONST(I2c_ChannelType, I2C_CONST) I2c_I2cConfigSet_I2cSequence_EEPROM_Status_ChannelList[1]; 

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 

#define I2C_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 
static CONST(I2c_ConstSeqDescType, I2C_CONST) I2c_ConstSeqDescrList_I2cConfigSet[3]; 

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 

#define I2C_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 
static VAR(I2c_VarSeqDescType, I2C_VAR) I2c_VarSeqDescrList_I2cConfigSet[3]; 

#define I2C_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 

#define I2C_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 
static VAR(I2c_VarChannelDescType, I2C_VAR) I2c_VarChannelDescrList_I2cConfigSet[5]; 

#define I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 

#define I2C_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 
static CONST(I2c_ConstChannelDescType, I2C_CONST) I2c_ConstChannelDescrList_I2cConfigSet[5]; 

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 


/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define I2C_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */

 /* Global Config Pointer. */
VAR(I2c_ConfigPtrType, I2C_PBCFG) I2c_ConfigPtr;

#define I2C_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
 
 
#define I2C_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
static VAR(I2c_VarHwUnitDescType, I2C_VAR) I2c_VarHwUnitDescrList_I2cConfigSet[1] =
{
  {
    { /*  PrioQueue  */ 
      0u /*  Start Index  */ , 
      0u /*  Stop Index  */ , 
      { /*  Queued sequences.  */ 
        0u /*  Queue pos. 0  */ , 
        0u /*  Queue pos. 1  */ , 
        0u /*  Queue pos. 2  */ , 
        0u /*  Queue pos. 3  */ , 
        0u /*  Queue pos. 4  */ , 
        0u /*  Queue pos. 5  */ , 
        0u /*  Queue pos. 6  */ , 
        0u /*  Queue pos. 7  */ , 
        0u /*  Queue pos. 8  */ , 
        0u /*  Queue pos. 9  */ , 
        0u /*  Queue pos. 10  */ 
      }
    }, 
    { /*  Hardware processor data  */ 
      0u /*  Sequence in progress.  */ , 
      FALSE /*  Tranmission is ongoing.  */ , 
      FALSE /*  Cancel ongoing transmission.  */ 
    }, 
    { /*  Tranmission Descriptor List  */ 
      0x0000u /*  Slave address  */ , 
      {
        {
          NULL_PTR /*  Target buffer.  */ , 
          0u /*  Data length.  */ , 
          FALSE /*  Single value.  */ 
        }, 
        {
          NULL_PTR /*  Target buffer.  */ , 
          0u /*  Data length.  */ , 
          FALSE /*  Single value.  */ 
        }
      }, 
      I2C_WRITE /*  Transfer direction.  */ , 
      0u /*  No. of channels.  */ , 
      FALSE /*  Hold bus after transfer.  */ 
    }
  }
};

#define I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define I2C_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
static CONST(I2c_ConstHwUnitDescType, I2C_CONST) I2c_ConstHwUnitDescrList_I2cConfigSet[1] =
{
  {
    I2cConf_I2cHardwareUnit_I2cHardwareUnit_EEPROM /*  Hardware unit.  */ , 
    0x40B10000u /*  Unit base address.  */ , 
    &I2c_VarHwUnitDescrList_I2cConfigSet[0] /*  Pointer to runtime data.  */ 
  }
};

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */

 
#define I2C_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
static CONST(I2c_BusDescType, I2C_CONST) I2c_ConstBusDescrList_I2cConfigSet[1] =
{
  {
    I2cConf_I2cBus_I2cBus_EEPROM /*  Bus identifier.  */ , 
    &I2c_ConstHwUnitDescrList_I2cConfigSet[0] /*  Pointer to bus hardware configuration.  */ , 
    4u /*  Bus timeout (in "Main Function Period" cycles).  */ , 
    { /*  Values specifying the baudrate.   */ 
      0x05u /*  I2C SCL Low Time register value (I2C_SCLL register).  */ , 
      0x08u /*  I2C SCL High Time register value (I2C_SCLH register).  */ , 
      0x09u /*  I2C Clock Prescaler register value (I2C_PSC register).  */ 
    }
  }
};

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define I2C_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
static CONST(I2c_ChannelType, I2C_CONST) I2c_I2cConfigSet_I2cSequence_EEPROM_Read_ChannelList[2] =
{
  I2cConf_I2cChannel_I2cChannel_EEPROM_ReadCom, 
  I2cConf_I2cChannel_I2cChannel_EEPROM_ReadData
};

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define I2C_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
static CONST(I2c_ChannelType, I2C_CONST) I2c_I2cConfigSet_I2cSequence_EEPROM_Write_ChannelList[2] =
{
  I2cConf_I2cChannel_I2cChannel_EEPROM_WriteCom, 
  I2cConf_I2cChannel_I2cChannel_EEPROM_WriteData
};

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define I2C_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
static CONST(I2c_ChannelType, I2C_CONST) I2c_I2cConfigSet_I2cSequence_EEPROM_Status_ChannelList[1] =
{
  I2cConf_I2cChannel_I2cChannel_EEPROM_Ack
};

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */

 
#define I2C_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
static VAR(I2c_VarChannelDescType, I2C_VAR) I2c_VarChannelDescrList_I2cConfigSet[5] =
{
  {
    0x0050u /*  Slave address.  */ , 
    NULL_PTR /*  BufferPtr.  */ , 
    0u /*  BufferLength.  */ , 
    I2C_CH_STATUS_IDLE /*  Channel status.  */ , 
    I2C_CH_RESULT_OK /*  Channel result.  */ , 
    I2C_WRITE /*  Transmission direction.  */ 
  }, 
  {
    0x0050u /*  Slave address.  */ , 
    NULL_PTR /*  BufferPtr.  */ , 
    0u /*  BufferLength.  */ , 
    I2C_CH_STATUS_IDLE /*  Channel status.  */ , 
    I2C_CH_RESULT_OK /*  Channel result.  */ , 
    I2C_WRITE /*  Transmission direction.  */ 
  }, 
  {
    0x0050u /*  Slave address.  */ , 
    NULL_PTR /*  BufferPtr.  */ , 
    0u /*  BufferLength.  */ , 
    I2C_CH_STATUS_IDLE /*  Channel status.  */ , 
    I2C_CH_RESULT_OK /*  Channel result.  */ , 
    I2C_WRITE /*  Transmission direction.  */ 
  }, 
  {
    0x0050u /*  Slave address.  */ , 
    NULL_PTR /*  BufferPtr.  */ , 
    0u /*  BufferLength.  */ , 
    I2C_CH_STATUS_IDLE /*  Channel status.  */ , 
    I2C_CH_RESULT_OK /*  Channel result.  */ , 
    I2C_WRITE /*  Transmission direction.  */ 
  }, 
  {
    0x0050u /*  Slave address.  */ , 
    NULL_PTR /*  BufferPtr.  */ , 
    0u /*  BufferLength.  */ , 
    I2C_CH_STATUS_IDLE /*  Channel status.  */ , 
    I2C_CH_RESULT_OK /*  Channel result.  */ , 
    I2C_WRITE /*  Transmission direction.  */ 
  }
};

#define I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */

 
#define I2C_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
static CONST(I2c_ConstChannelDescType, I2C_CONST) I2c_ConstChannelDescrList_I2cConfigSet[5] =
{
  {
    I2cConf_I2cChannel_I2cChannel_EEPROM_ReadCom /*   Channel id: 0  */ , 
    0x0050u /*  Slave address.  */ , 
    0xFFu /*  Default data.  */ , 
    FALSE /*  Chained attribute.  */ , 
    &I2c_VarChannelDescrList_I2cConfigSet[0] /*  Pointer to runtime data.  */ 
  }, 
  {
    I2cConf_I2cChannel_I2cChannel_EEPROM_ReadData /*   Channel id: 1  */ , 
    0x0050u /*  Slave address.  */ , 
    0xFFu /*  Default data.  */ , 
    FALSE /*  Chained attribute.  */ , 
    &I2c_VarChannelDescrList_I2cConfigSet[1] /*  Pointer to runtime data.  */ 
  }, 
  {
    I2cConf_I2cChannel_I2cChannel_EEPROM_WriteCom /*   Channel id: 2  */ , 
    0x0050u /*  Slave address.  */ , 
    0xFFu /*  Default data.  */ , 
    FALSE /*  Chained attribute.  */ , 
    &I2c_VarChannelDescrList_I2cConfigSet[2] /*  Pointer to runtime data.  */ 
  }, 
  {
    I2cConf_I2cChannel_I2cChannel_EEPROM_WriteData /*   Channel id: 3  */ , 
    0x0050u /*  Slave address.  */ , 
    0xFFu /*  Default data.  */ , 
    TRUE /*  Chained attribute.  */ , 
    &I2c_VarChannelDescrList_I2cConfigSet[3] /*  Pointer to runtime data.  */ 
  }, 
  {
    I2cConf_I2cChannel_I2cChannel_EEPROM_Ack /*   Channel id: 4  */ , 
    0x0050u /*  Slave address.  */ , 
    0xFFu /*  Default data.  */ , 
    FALSE /*  Chained attribute.  */ , 
    &I2c_VarChannelDescrList_I2cConfigSet[4] /*  Pointer to runtime data.  */ 
  }
};

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define I2C_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
static VAR(I2c_VarSeqDescType, I2C_VAR) I2c_VarSeqDescrList_I2cConfigSet[3] =
{
  {
    I2C_SEQ_OK /*  Sequence result.  */ , 
    0u /*  Leading channel.  */ , 
    0u /*  Next channel.  */ 
  }, 
  {
    I2C_SEQ_OK /*  Sequence result.  */ , 
    0u /*  Leading channel.  */ , 
    0u /*  Next channel.  */ 
  }, 
  {
    I2C_SEQ_OK /*  Sequence result.  */ , 
    0u /*  Leading channel.  */ , 
    0u /*  Next channel.  */ 
  }
};

#define I2C_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define I2C_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
static CONST(I2c_ConstSeqDescType, I2C_CONST) I2c_ConstSeqDescrList_I2cConfigSet[3] =
{
  {
    I2cConf_I2cSequence_I2cSequence_EEPROM_Read /*  Sequence identifier.  */ , 
    Eep_30_XXi2c01_ComEnd /*  End notification function.  */ , 
    NULL_PTR /*  Error notification function.  */ , 
    &I2c_VarSeqDescrList_I2cConfigSet[0] /*  Pointer to runtime data.  */ , 
    I2c_I2cConfigSet_I2cSequence_EEPROM_Read_ChannelList /*  Channel mapping.  */ , 
    2u /*  No. of channels in sequence.  */ , 
    &I2c_ConstBusDescrList_I2cConfigSet[0] /*  Bus configuration.  */ , 
    FALSE /*  Handle NACK as error.  */ , 
    1u /*  Sequence queue priority.  */ 
  }, 
  {
    I2cConf_I2cSequence_I2cSequence_EEPROM_Write /*  Sequence identifier.  */ , 
    Eep_30_XXi2c01_ComEnd /*  End notification function.  */ , 
    NULL_PTR /*  Error notification function.  */ , 
    &I2c_VarSeqDescrList_I2cConfigSet[1] /*  Pointer to runtime data.  */ , 
    I2c_I2cConfigSet_I2cSequence_EEPROM_Write_ChannelList /*  Channel mapping.  */ , 
    2u /*  No. of channels in sequence.  */ , 
    &I2c_ConstBusDescrList_I2cConfigSet[0] /*  Bus configuration.  */ , 
    FALSE /*  Handle NACK as error.  */ , 
    1u /*  Sequence queue priority.  */ 
  }, 
  {
    I2cConf_I2cSequence_I2cSequence_EEPROM_Status /*  Sequence identifier.  */ , 
    Eep_30_XXi2c01_ComEnd /*  End notification function.  */ , 
    NULL_PTR /*  Error notification function.  */ , 
    &I2c_VarSeqDescrList_I2cConfigSet[2] /*  Pointer to runtime data.  */ , 
    I2c_I2cConfigSet_I2cSequence_EEPROM_Status_ChannelList /*  Channel mapping.  */ , 
    1u /*  No. of channels in sequence.  */ , 
    &I2c_ConstBusDescrList_I2cConfigSet[0] /*  Bus configuration.  */ , 
    FALSE /*  Handle NACK as error.  */ , 
    1u /*  Sequence queue priority.  */ 
  }
};

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */

 
#define I2C_START_SEC_PBCFG_ROOT
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
CONST(I2c_ConfigType, I2C_CONST) I2c_ConfigSet[1] =
{
  {
    I2c_ConstSeqDescrList_I2cConfigSet, 
    I2c_ConstChannelDescrList_I2cConfigSet, 
    I2c_ConstBusDescrList_I2cConfigSet, 
    I2c_ConstHwUnitDescrList_I2cConfigSet, 
    3u /*  No. of sequences.  */ , 
    5u /*  No. of channels.  */ , 
    1u /*  No. of buses.  */ , 
    1u /*  No. of hardware units.  */ 
  }
};

#define I2C_STOP_SEC_PBCFG_ROOT
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */





/**********************************************************************************************************************
 *  END OF FILE: I2c_PBcfg.c
 *********************************************************************************************************************/
