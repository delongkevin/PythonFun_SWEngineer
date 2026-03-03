/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vDam.h
 *        \brief  Diagnostic Access Manager
 *
 *      \details  Implementation of the Diagnostic Access Manager
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2020-03-21  vismwe  STORYC-1550   Initial creation
 *  02.00.00  2022-01-28  vismhh  HSM-2070      SafeBsw for vDam
 *                                HSM-2195      Support postbuild loadable and postbuild selectable
 *                                HSM-2208      Usage of Mip_Memmap
 *                                ESCAN00111306 Fixed overflow when using more than 255 services or subservices
 *  02.00.02  2022-12-07  vismhh  ESCAN00113071 Added callout to map internal error to custom NRC
 *                                ESCAN00113087 Corrected description of vDam_ServiceRole_Indication
 *                        vismwe  ESCAN00113455 Wrong Identifier check for Service 0x22 and 0x2A with invalid Identifier 
 *                                              in strategy ALLOW_NOT_CONFIGURED
 *                                ESCAN00113484 Insufficient Role evaluation for Identifier restrictions with 
 *                                              additional Service restrictions.
 *********************************************************************************************************************/

#if !defined (VDAM_H)
# define VDAM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "vDam_Cfg.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define VDAM_VENDOR_ID                                               (30u)
# define VDAM_MODULE_ID                                               (0xFFu)
# define VDAM_INSTANCE_ID                                             (0u)

/* AUTOSAR Software specification version information */
# define VDAM_AR_RELEASE_MAJOR_VERSION                                (4u)
# define VDAM_AR_RELEASE_MINOR_VERSION                                (3u)
# define VDAM_AR_RELEASE_REVISION_VERSION                             (0u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define VDAM_SW_MAJOR_VERSION                                        (2u)
# define VDAM_SW_MINOR_VERSION                                        (0u)
# define VDAM_SW_PATCH_VERSION                                        (2u)

/* API service IDs */
# define VDAM_SID_INIT                                                0x00u  /* Service ID: vDam_Init */
# define VDAM_SID_INIT_MEMORY                                         0x01u  /* Service ID: vDam_InitMemory */
# define VDAM_SID_GET_VERSION_INFO                                    0x02u  /* Service ID: vDam_GetVersionInfo */
# define VDAM_SID_SERVICE_ROLE_INDICATION                             0x03u  /* Service ID: vDam_ServiceRole_Indication */
# define VDAM_SID_SERVICE_ROLE_CONFIRMATION                           0x04u  /* Service ID: vDam_ServiceRole_Confirmation */
# define VDAM_SID_DE_INIT                                             0x05u  /* Service ID: vDam_DeInit */

/* Modes */
/* State: Uninitialized */
# define VDAM_UNINIT                                                  (0x00u)
/* State: Initialized */
# define VDAM_INITIALIZED                                             (0x01u)

/* Development Error Types */
#  define VDAM_E_NO_ERROR                                             (255u)
#  define VDAM_E_UNINIT                                               (0u)
#  define VDAM_E_INIT_FAILED                                          (1u)
#  define VDAM_E_PARAM_POINTER                                        (2u)
#  define VDAM_E_PARAM_CONFIG                                         (6u)

/* Values for the negative response code of diagnostic services.
 * Values differ from DCM and are only used internally to mask out different error states by logical AND.
 * Due to this, values are sorted and masked accordingly to their priority starting with E_OK = 0:
 */
/* Values are only used for vDam program flow.
 * Do NOT use in Appl_vDamRemapNrcCalloutFunc. */
#define VDAM_E_RIGHTS_CHECKNEXTLEVEL                                  0x09u
#define VDAM_NO_SUB_FUNCTION                                          0xFFu

/* Values are used for mapping of negative response codes. These values
 * can be used for remapping in Appl_vDamRemapNrcCalloutFunc.
 * Element values must be ordered that the blocking errors have a high value.
 * Attention values are used in a <= compare. */

/* The matching data type is vDam_InternalErrorStateType. */
#define VDAM_E_RIGHTS_E_OK                                            E_OK
#define VDAM_E_RIGHTS_E_NOT_OK                                        E_NOT_OK
#define VDAM_E_RIGHTS_IDNOTSUPPORTED                                  0x11u
#define VDAM_E_RIGHTS_SUBFUNCTIONNOTSUPPORTED                         0x13u
#define VDAM_E_RIGHTS_SERVICENOTSUPPORTED                             0x17u
#define VDAM_E_RIGHTS_INVALID_REQUESTDATA                             0x18u
#define VDAM_E_RIGHTS_SECURITYACCESSDENIED                            0x19u

/* If the error is higher than this value stop searching for ids. */
#define VDAM_E_RIGHTS_STOP_SEARCHING                                  VDAM_E_RIGHTS_SUBFUNCTIONNOTSUPPORTED

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VDAM_START_SEC_CODE
# include "vDam_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * vDam_InitMemory()
 *********************************************************************************************************************/
/*! \brief       The function initializes variables, which cannot be initialized with the startup code.
 *  \details     Initialize component variables at power up.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VDAM_CODE) vDam_InitMemory(void);

/**********************************************************************************************************************
 * vDam_Init()
 *********************************************************************************************************************/
/*! \brief       Initialization function
 *  \details     This function initializes the module vDam. It initializes all variables and sets the module state to
 *               initialized.
 *  \param[in]   configPtr                    Configuration structure for initializing the module
 *  \pre         Module is uninitialized.
 *  \pre         vDam_InitMemory has been called unless vDam_ModuleInitialized is initialized by start-up code.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VDAM_CODE) vDam_Init(P2CONST(vDam_ConfigType, AUTOMATIC, VDAM_APPL_DATA) configPtr);

/**********************************************************************************************************************
 * vDam_DeInit()
 **********************************************************************************************************************/
/*! \brief       Deinitialization function
 *  \details     This function stops the functionality of the component. By a call to vDam_DeInit the vDam module is
 *               put into a not initialized state (vDam_UNINIT).
 *  \pre         Module is initialized.
 *  \context     TASK
 *  \synchronous TRUE
 *  \reentrant   FALSE
 **********************************************************************************************************************/
FUNC(void, VDAM_CODE) vDam_DeInit(void);

# if (VDAM_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  vDam_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief       Returns the version information
 *  \details     vDam_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  versioninfo             Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      VDAM_VERSION_INFO_API == STD_ON
 *********************************************************************************************************************/
FUNC(void, VDAM_CODE) vDam_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, VDAM_APPL_VAR) versioninfo);
# endif /* (VDAM_VERSION_INFO_API == STD_ON) */

# define VDAM_STOP_SEC_CODE
# include "vDam_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VDAM_H */
/**********************************************************************************************************************
 *  END OF FILE: vDam.h
 *********************************************************************************************************************/
