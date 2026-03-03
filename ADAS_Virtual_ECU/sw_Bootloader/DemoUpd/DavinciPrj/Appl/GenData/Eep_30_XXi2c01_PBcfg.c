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
 *            Module: Eep
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Eep_30_XXi2c01_PBcfg.c
 *   Generation Time: 2022-11-08 19:25:58
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D04
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#define EEP_30_XXI2C01_PBCFG_SOURCE

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
#include "Eep_30_XXi2c01.h"
#include "fbl_inc.h" 
 
/**********************************************************************************************************************
 * VERSION CHECK
 *********************************************************************************************************************/
 
#if( (EEP_30_XXI2C01_CFG_MAJOR_VERSION != (2u)) || \
      (EEP_30_XXI2C01_CFG_MINOR_VERSION != (1u))    \
    ) 
# error "Configurator version numbers of Eep_30_XXi2c01_PBcfg.c and Eep_30_XXi2c01_Cfg.h are inconsistent" 
#endif 
 
#if( (EEP_30_XXI2C01_SW_MAJOR_VERSION != (2u)) || \
      (EEP_30_XXI2C01_SW_MINOR_VERSION != (0u))    \
    ) 
# error "Software version numbers of Eep_30_XXi2c01_PBcfg.c and Eep_30_XXi2c01.h are inconsistent" 
#endif 

/**********************************************************************************************************************
 * CONFIGURATION CONSTANT DATA
 *********************************************************************************************************************/
# define EEP_30_XXI2C01_START_SEC_PBCFG_ROOT 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
/* EepInst1 EEPROM root configuration */ 
CONST (Eep_30_XXi2c01_ConfigType, EEP_30_XXI2C01_PBCFG) Eep_30_XXi2c01_Runtime = 
{
  EEP_E_READ_FAILED /*  Ref to DemEvent (EEP_E_READ_FAILED)  */ , 
  EEP_E_COMPARE_FAILED /*  Ref to DemEvent (EEP_E_COMPARE_FAILED)  */ , 
  EEP_E_WRITE_FAILED /*  Ref to DemEvent (EEP_E_WRITE_FAILED)  */ , 
  EEP_E_ERASE_FAILED /*  Ref to DemEvent (EEP_E_ERASE_FAILED)  */ , 
  /* I2C references */
  I2cConf_I2cSequence_I2cSequence_Eep_Read /*  i2c read sequence  */ , 
  I2cConf_I2cChannel_I2cChannel_Eep_Read_Command /*  i2c read command channel  */ , 
  I2cConf_I2cChannel_I2cChannel_Eep_Read_Data /*  i2c read data channel  */ , 
  I2cConf_I2cSequence_I2cSequence_Eep_Write /*  i2c write sequence  */ , 
  I2cConf_I2cChannel_I2cChannel_Eep_Write_Command /*  i2c write command channel  */ , 
  I2cConf_I2cChannel_I2cChannel_Eep_Write_Data /*  i2c write data channel  */ , 
  I2cConf_I2cSequence_I2cSequence_Eep_Ack /*  ackSequence  */ , 
  I2cConf_I2cChannel_I2cChannel_Eep_Ack_Ack /*  ackChannel  */ , 
  MEMIF_MODE_FAST /*  Default mode  */ , 
  EEP_30_XXI2C01_HANDLING_BURST /*  Default handling  */ , 
  2u /*  number of recurrent queries depending on the handling mode  */ , 
  65535u /*  number of burst queries  */ , 
  0u /*  Base address for EEPROM memory.  */ , 
  4095u /*  Last used address for EEPROM memory.  */ , 
  { /*  Read/compare sizes for normal and fast mode  */ 
    16u, 
    16u
  }, 
  { /*  Write/erase sizes for normal and fast mode  */ 
    32u, 
    32u
  }, 
  NULL_PTR /*  EepJobEndNotification  */ , 
  NULL_PTR /*  EepJobErrorNotification  */ , 
  &Eep_30_XXi2c01_I2cApi0 /*  Pointer to I2c API functions  */ 
}; 
 
# define EEP_30_XXI2C01_STOP_SEC_PBCFG_ROOT 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 


/**********************************************************************************************************************
 * I2c INTERFACE
 *********************************************************************************************************************/
# define EEP_30_XXI2C01_START_SEC_CONST_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
CONST(Eep_30_XXi2c01_I2cApiType, EEP_30_XXI2C01_CONST) Eep_30_XXi2c01_I2cApi0 = 
{
  I2c_SetupEB /*  SetupEB  */ , 
  I2c_AsyncTransmit /*  AsyncTransmit  */ , 
  I2c_GetSequenceResult /*  GetSequenceResult  */ 
}; 
 
# define EEP_30_XXI2C01_STOP_SEC_CONST_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 


 /**********************************************************************************************************************
 *  END OF FILE: Eep_30_XXi2c01_PBcfg.c
 *********************************************************************************************************************/
 
