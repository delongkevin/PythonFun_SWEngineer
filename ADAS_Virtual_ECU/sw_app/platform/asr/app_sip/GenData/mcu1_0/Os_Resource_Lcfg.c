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
 *            Module: Os
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Resource_Lcfg.c
 *   Generation Time: 2024-02-13 13:07:51
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_RESOURCE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Resource_Lcfg.h"
#include "Os_Resource.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"

/* Os hal dependencies */
#include "Os_Hal_Interrupt_Lcfg.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic resource data: OsResource */
OS_LOCAL VAR(Os_ResourceInterruptType, OS_VAR_NOINIT) OsCfg_Resource_OsResource_Dyn;

/*! Dynamic resource data: OsResource_PMIC */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_OsResource_PMIC_Dyn;

/*! Dynamic resource data: OsResource_SciSecureproxy */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_OsResource_SciSecureproxy_Dyn;

/*! Dynamic resource data: OsResource_SciServerSync */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_OsResource_SciServerSync_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/*! Resource configuration data: OsResource */
CONST(Os_ResourceInterruptConfigType, OS_CONST) OsCfg_Resource_OsResource =
{
  /* .Resource        = */
  {
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCEINTERRUPT_2_LOCK(OsCfg_Resource_OsResource_Dyn),
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_INTERRUPT
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ OsResource,
  /* .CeilingPriority = */ 0
},
  /* .InterruptLevel = */ &OsCfg_Hal_Resource_OsResource_IntLevel
};


/*! Resource configuration data: OsResource_PMIC */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_OsResource_PMIC =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_OsResource_PMIC_Dyn),
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ OsResource_PMIC,
  /* .CeilingPriority = */ 0
};


/*! Resource configuration data: OsResource_SciSecureproxy */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_OsResource_SciSecureproxy =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_OsResource_SciSecureproxy_Dyn),
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ OsResource_SciSecureproxy,
  /* .CeilingPriority = */ 0
};


/*! Resource configuration data: OsResource_SciServerSync */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_OsResource_SciServerSync =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_OsResource_SciServerSync_Dyn),
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ OsResource_SciServerSync,
  /* .CeilingPriority = */ 1
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for resources. */
CONSTP2CONST(Os_ResourceConfigType, OS_CONST, OS_CONST) OsCfg_ResourceRefs[OS_RESOURCEID_COUNT + 1] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_RESOURCE_CASTCONFIG_RESOURCEINTERRUPT_2_RESOURCE(OsCfg_Resource_OsResource),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_OsResource_PMIC),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_OsResource_SciSecureproxy),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_OsResource_SciServerSync),
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Resource_Lcfg.c
 *********************************************************************************************************************/
