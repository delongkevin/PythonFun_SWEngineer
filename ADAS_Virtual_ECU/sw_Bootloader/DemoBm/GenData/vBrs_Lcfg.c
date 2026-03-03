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
 *              File: .\vBrs_Lcfg.c
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Please note:
 *    The demo and example programs only show special aspects of the software. With regard to the fact
 *    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
 *    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *********************************************************************************************************************/

#define VBRS_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "vBrs_Lcfg.h"

#if (BRSHW_SOURCECODE_TEMPLATE_VERSION >= 0x0103u)
/*******************************************************************************
 Logical to phyiscal core assingment
*******************************************************************************/
extern Brs_AddressOfConstType BRSHW_DEFINE_STARTUP_STACK(BRSHW_INIT_CORE_ID);

const uint32 BrsMain_CoreConfig_Size = 1;

/* See BrsMain_Types.h for declaration of BrsMain_CoreConfig.
   Information is mainly used for StartupStack pointer initialization in StartupCode and
   call of BrsHw_ExceptionTable_Init() in main().
   For MultiCore setups, the information is mainly based on the actual OS configuration */

const brsMain_CoreType BrsMain_CoreConfig[1u] =
{
  {
    /* .LogicalCoreId        = */ 0u,
    /* .PhysicalCoreId       = */ BRSHW_INIT_CORE_ID,
    /* .StartupStackEndLabel = */ (Brs_AddressOfConstType)(&BRSHW_DEFINE_STARTUP_STACK(BRSHW_INIT_CORE_ID)),
    /* .StartupStackSize     = */ 1024u,
    /* .CoreIsAsr            = */ NON_ASR,
    /* .ExcVecLabel          = */ BRS_DEFINE_ADDRESS_UNUSED,
    /* .IntVecLabel          = */ BRS_DEFINE_ADDRESS_UNUSED 
  }
};

#endif /*BRSHW_SOURCECODE_TEMPLATE_VERSION>=0x0103u*/
