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
 *            Module: vBRS
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: .\EcuM.c
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  EXAMPLE CODE ONLY
*  -------------------------------------------------------------------------------------------------------------------
*  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
*  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
*  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
*  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
*  according to the state of the art before their use.
*********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "EcuM.h"


#include "Det.h"
#include "vXSpi.h"
#include "vMemAccM.h"
#include "Eep_30_XXi2c01.h"
#include "Crypto_30_vHsm.h"
#include "CryIf.h"
#include "Csm.h"
#include "I2c.h"
#include "Fls_30_vMemAccM.h"
#include "Fee.h"
#include "Ea.h"
#include "WrapNv.h"
#include "NvM.h"

/**********************************************************************************************************************
  PROTOTYPES OF EXTERN FUNCTIONS
**********************************************************************************************************************/
extern void FblMain(void);
 
/**********************************************************************************************************************
  PROTOTYPES OF LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  FUNCTION DEFINITIONS
**********************************************************************************************************************/
void EcuM_Init(void)
{
  /* Module: Det / InitPhase: INIT_MEMORY */
  Det_InitMemory();
  /* Module: vXSpi / InitPhase: INIT_MEMORY */
  vXSpi_InitMemory();
  /* Module: vMemAccM / InitPhase: INIT_MEMORY */
  vMemAccM_InitMemory();
  /* Module: Eep / InitPhase: INIT_MEMORY */
  Eep_30_XXi2c01_InitMemory();
  /* Module: Crypto_30_vHsm / InitPhase: INIT_MEMORY */
  Crypto_30_vHsm_InitMemory();
  /* Module: CryIf / InitPhase: INIT_MEMORY */
  CryIf_InitMemory();
  /* Module: Csm / InitPhase: INIT_MEMORY */
  Csm_InitMemory();
  /* Module: Det / InitPhase: INIT_ZERO */
  Det_Init(Det_Config_Ptr);
  /* Module: I2c / InitPhase: INIT_ONE */
  I2c_Init(&I2c_ConfigSet[0]);

  FblMain();
}

void EcuM_StartupTwo(void)
{
  /* Module: vXSpi / InitPhase: INIT_TWO_DRV */
  vXSpi_Init(&vXSpi_HwConfig);
  /* Module: vMemAccM / InitPhase: INIT_TWO_DRV */
  vMemAccM_Init();
  /* Module: Eep / InitPhase: INIT_TWO_DRV */
  Eep_30_XXi2c01_Init(&Eep_30_XXi2c01_Runtime);
  /* Module: Fls / InitPhase: INIT_TWO_DRV */
  Fls_30_vMemAccM_Init();
  /* Module: Crypto_30_vHsm / InitPhase: INIT_TWO_DRV */
  Crypto_30_vHsm_Init();
  /* Module: Fee / InitPhase: INIT_TWO_IF */
  Fee_Init();
  /* Module: Ea / InitPhase: INIT_TWO_IF */
  Ea_Init();
  /* Module: CryIf / InitPhase: INIT_TWO_IF */
  CryIf_Init();
  /* Module: WrapNv / InitPhase: INIT_TWO_SYS */
  WrapNv_Init();
  /* Module: NvM / InitPhase: INIT_TWO_SYS */
  NvM_Init();
  /* Module: Csm / InitPhase: INIT_TWO_SYS */
  Csm_Init();
}

void EcuM_Shutdown(void)
{
}

void EcuM_BswErrorHook(uint16 moduleId, uint8 errorId)
{
#if defined (ECUM_STUB_BSWERRORHOOK_CALLOUT)
  BrsTestsuite_EcuM_BswErrorHook_Callout(moduleId, errorId);
#endif
}

void EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource)
{
#if defined (ECUM_STUB_CHECKWAKEUP_CALLOUT)
  BrsTestsuite_EcuM_CheckWakeup_Callout(wakeupSource);
#endif
}

void EcuM_GeneratorCompatibilityError(uint16 moduleId, uint8 instanceId)
{
#if defined (ECUM_STUB_GENERATORCOMPATIBILITYERROR_CALLOUT)
  BrsTestsuite_EcuM_GeneratorCompatibilityError_Callout(moduleId, instanceId);
#endif
}

void EcuM_SetWakeupEvent(EcuM_WakeupSourceType wakeupSource)
{
#if defined (ECUM_STUB_SETWAKEUPEVENT_CALLOUT)
  BrsTestsuite_EcuM_SetWakeupEvent_Callout(wakeupSource);
#endif
}

void EcuM_ValidationWakeupEvent(EcuM_WakeupSourceType wakeupSource)
{
#if defined (ECUM_STUB_VALIDATIONWAKEUPEVENT_CALLOUT)
  BrsTestsuite_EcuM_ValidationWakeupEvent_Callout(wakeupSource);
#endif
}

