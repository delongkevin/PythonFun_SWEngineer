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
 *    License Scope : The usage is restricted to CBD2101146_D12
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Eep_30_XXi2c01_Lcfg.c
 *   Generation Time: 2023-10-27 18:05:39
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D12
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#define EEP_30_XXI2C01_LCFG_SOURCE

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
#include "Eep_30_XXi2c01.h"

/**********************************************************************************************************************
 * VERSION CHECK
 *********************************************************************************************************************/

#if( (EEP_30_XXI2C01_CFG_MAJOR_VERSION != (2u)) || \
      (EEP_30_XXI2C01_CFG_MINOR_VERSION != (1u))    \
    ) 
# error "Configurator version numbers of Eep_30_XXi2c01_Lcfg.c and Eep_30_XXi2c01_Cfg.h are inconsistent" 
#endif 
 
#if( (EEP_30_XXI2C01_SW_MAJOR_VERSION != (2u)) || \
      (EEP_30_XXI2C01_SW_MINOR_VERSION != (0u))    \
    ) 
# error "Software version numbers of Eep_30_XXi2c01_Lcfg.c and Eep_30_XXi2c01.h are inconsistent" 
#endif 

/**********************************************************************************************************************
 * CONFIGURATION CONSTANT DATA
 *********************************************************************************************************************/
 
# define EEP_30_XXI2C01_START_SEC_CONST_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
/* EEPROM chip properties: ONSemiconductor_N24C64 */ 
/* PRQA S 1533 1 */ /* MD_Eep__coreAsr_BlockScopeDefinition */ 
CONST(Eep_30_XXi2c01_ChipType, EEP_30_XXI2C01_CONST) Eep_30_XXi2c01_Chip =  
{
  2u /*  command buffer size  */ , 
  32u /*  page size  */ , 
  4u /*  write time  */ 
}; 
# define EEP_30_XXI2C01_STOP_SEC_CONST_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 

/**********************************************************************************************************************
 * CONFIGURATION VARIABLE DATA
 *********************************************************************************************************************/

# define EEP_30_XXI2C01_START_SEC_VAR_NO_INIT_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
/* EEPROM command buffer for Inst1. */ 
/* PRQA S 1533 1 */ /* MD_Eep__coreAsr_BlockScopeDefinition */ 
VAR(I2c_DataType, EEP_30_XXI2C01_VAR_NO_INIT) Eep_30_XXi2c01_CommandBuffer[2u]; 
 
 
/* EEPROM data buffer for Inst1. Its size is max(page size and read size) */ 
/* PRQA S 1533 1 */ /* MD_Eep__coreAsr_BlockScopeDefinition */ 
VAR(I2c_DataType, EEP_30_XXI2C01_VAR_NO_INIT) Eep_30_XXi2c01_DataBuffer[32u]; 
 
# define EEP_30_XXI2C01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 


# define EEP_30_XXI2C01_START_SEC_VAR_INIT_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
P2CONST(Eep_30_XXi2c01_ChipType, EEP_30_XXI2C01_VAR_INIT, EEP_30_XXI2C01_CONST) Eep_30_XXi2c01_ChipPtr[1U] = 
{
  NULL_PTR
}; 
 
P2VAR(I2c_DataType, EEP_30_XXI2C01_VAR_INIT, EEP_30_XXI2C01_VAR_NO_INIT) Eep_30_XXi2c01_CommandBufferPtr[1U] = 
{
  NULL_PTR
}; 
 
P2VAR(I2c_DataType, EEP_30_XXI2C01_VAR_INIT, EEP_30_XXI2C01_VAR_NO_INIT) Eep_30_XXi2c01_DataBufferPtr[1U] = 
{
  NULL_PTR
}; 
 
P2CONST(Eep_30_XXi2c01_ConfigType, EEP_30_XXI2C01_VAR_INIT, EEP_30_XXI2C01_CONST) Eep_30_XXi2c01_CfgPtr[1U] = 
{
  NULL_PTR
}; 
 
# define EEP_30_XXI2C01_STOP_SEC_VAR_INIT_UNSPECIFIED 
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 


/* Justification for module-specific MISRA deviations:
    MD_Eep__coreAsr_BlockScopeDefinition: rule 8.9
    Reason: 	This object is only referenced by the function 'Eep_30_XXspi01_InitMemory'.
            	An object should be defined at block scope if its identifier only appears in a single function.
    Risk:		This object is accessible from any instance including this file.
    Prevention: A prevention is not possible. This object is part of the generated dynamic code. But the vMem_InitMemory()
    			is part of the static source code.
*/

/**********************************************************************************************************************
 *  END OF FILE: Eep_30_XXi2c01_Lcfg.c
 *********************************************************************************************************************/
 
