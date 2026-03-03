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
 *            Module: vDiagSecAcc
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vDiagSecAcc_Cfg.c
 *   Generation Time: 2024-02-13 13:07:46
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define VDIAGSECACC_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vDiagSecAcc_Cfg.h"
#include "vDiagSecAcc.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (VDIAGSECACC_LOCAL)
# define VDIAGSECACC_LOCAL static
#endif

#if !defined (VDIAGSECACC_LOCAL_INLINE)
# define VDIAGSECACC_LOCAL_INLINE LOCAL_INLINE
#endif




/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  vDiagSecAcc_SeedBuffer
**********************************************************************************************************************/
#define VDIAGSECACC_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "vDiagSecAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(vDiagSecAcc_SeedBufferUType, VDIAGSECACC_VAR_NOINIT) vDiagSecAcc_SeedBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */  /* 31 */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/vDiagSecAcc/vDiagSecAccSecurityLevels/vDiagSecAccSecurityLevel] */
  /*   ... */  /* [/ActiveEcuC/vDiagSecAcc/vDiagSecAccSecurityLevels/vDiagSecAccSecurityLevel] */
  /*    31 */  /* [/ActiveEcuC/vDiagSecAcc/vDiagSecAccSecurityLevels/vDiagSecAccSecurityLevel] */

#define VDIAGSECACC_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "vDiagSecAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


#define VDIAGSECACC_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "vDiagSecAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
/**********************************************************************************************************************
 *  Function Group SecurityLevel: 0x000B vDiagSecAcc_CompareKey_L0x000B
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vDiagSecAcc_CompareKey_L0x000B
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_CompareKey_L0x000B(P2CONST(uint8, AUTOMATIC, VDIAGSECACC_DCM_VAR) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDIAGSECACC_DCM_VAR) ErrorCode)
{
  return vDiagSecAcc_Local_CompareKey((P2CONST(uint8, AUTOMATIC, VDIAGSECACC_APPL_DATA))Key, OpStatus, (P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDIAGSECACC_APPL_VAR))ErrorCode, vDiagSecAccConf_vDiagSecAccSecurityLevel_vDiagSecAccSecurityLevel);

}

/**********************************************************************************************************************
 *  Function Group SecurityLevel: 0x000B vDiagSecAcc_GetSeed_L0x000B
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vDiagSecAcc_GetSeed_L0x000B
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_GetSeed_L0x000B(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, VDIAGSECACC_DCM_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDIAGSECACC_DCM_VAR) ErrorCode)
{
  return vDiagSecAcc_Local_GetSeed(OpStatus, (P2VAR(uint8, AUTOMATIC, VDIAGSECACC_APPL_VAR))Seed, (P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDIAGSECACC_APPL_VAR))ErrorCode, vDiagSecAccConf_vDiagSecAccSecurityLevel_vDiagSecAccSecurityLevel);
}

#define VDIAGSECACC_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "vDiagSecAcc_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
 *  END OF FILE: vDiagSecAcc_Cfg.c
 *********************************************************************************************************************/
