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
 *            Module: WdgIf
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D03
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WdgIf_Cfg_Features.h
 *   Generation Time: 2023-04-12 20:18:51
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D03
 *      Tool Version: DaVinci Configurator Classic (beta) 5.25.37 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Classic and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

#if !defined (WDGIF_CFG_FEATURES_H)
# define WDGIF_CFG_FEATURES_H
 
/**********************************************************************************************************************
 *  VERSION INFORMATION
 *********************************************************************************************************************/
# define WDGIF_CFG_FEATURE_MAJOR_VERSION (2u) 
# define WDGIF_CFG_FEATURE_MINOR_VERSION (3u) 
# define WDGIF_CFG_FEATURE_PATCH_VERSION (1u) 


/**********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CONSTANT MACROS
 *********************************************************************************************************************/
# define WDGIF_VERSION_INFO_API                  STD_OFF
# define WDGIF_DEV_ERROR_DETECT                  STD_OFF
# define WDGIF_USE_STATECOMBINER                 STD_OFF

# if (WDGIF_DEV_ERROR_DETECT == STD_ON)
/* PRQA S 3453 2 */ /* MD_MSR_FctLikeMacro */
#  define WdgIf_ReportDet(WdgIf_FunctionId, WdgIf_ErrorCode) \
     ( (void) Det_ReportError( (WDGIF_MODULE_ID), (WDGIF_INSTANCE_ID), (WdgIf_FunctionId), (WdgIf_ErrorCode)) )
# else
#  define WdgIf_ReportDet(WdgIf_FunctionId, WdgIf_ErrorCode)
# endif /* (WDGIF_DEV_ERROR_DETECT == STD_ON) */

#endif /* WDGIF_CFG_FEATURES_H*/

/**********************************************************************************************************************
 *  END OF FILE: WdgIf_Cfg_Features.h
 *********************************************************************************************************************/





