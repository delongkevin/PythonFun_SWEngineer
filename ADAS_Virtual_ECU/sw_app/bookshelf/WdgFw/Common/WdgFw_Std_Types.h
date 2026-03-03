/**
 * @file WdgFw_Std_Types.h
 * @brief Watchdog framework common data types header file
 *
 * @details This file contains Watchdog framework common data types for non AutoSar cores
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2022. Magna Electronics owns all
 *   rights to this work and intends to maintain it in confidence
 *   to preserve its trade secret status. Magna Electronics
 *   reserves the right, under the copyright laws of the United
 *   States or those of any other country that may have jurisdiction,
 *   to protect this work as an unpublished work, in the event of
 *   an inadvertent or deliberate unauthorized publication.
 *   Magna Electronics also reserves its rights under all copyright
 *   laws to protect this work as a published work, when appropriate.
 *   Those having access to this work may not copy it, use it,
 *   modify it, or disclose the information contained in it without
 *   the written authorization of Magna Electronics.
 *
 * --------------------------------------------------------------------------
 * @author Pramod Kumar (Pramod.kumar1@magna.com)
 */

#ifndef WDGFW_STD_TYPES_H
# define WDGFW_STD_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "PlatformDataTypes.h"
#include <stdio.h>

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


# define STD_TYPES_VENDOR_ID               (30u)  /* SREQ00015345, SREQ00015361 */
# define STD_TYPES_MODULE_ID               (197u) /* SREQ00015345, SREQ00015361 */

/* ESCAN00067740 */
# define STD_VENDOR_ID                     STD_TYPES_VENDOR_ID
# define STD_MODULE_ID                     STD_TYPES_MODULE_ID

/* ##V_CFG_MANAGEMENT ##CQProject : CommonAsr__Common CQComponent : Impl_StdTypes */
# define COMMONASR__COMMON_IMPL_STDTYPES_VERSION 0x0304
# define COMMONASR__COMMON_IMPL_STDTYPES_RELEASE_VERSION 0x05

/* AUTOSAR Software Specification Version Information */
/* AUTOSAR release 4.0 R3 */
#  define STD_TYPES_AR_RELEASE_MAJOR_VERSION       (4u)
#  define STD_TYPES_AR_RELEASE_MINOR_VERSION       (0u)
#  define STD_TYPES_AR_RELEASE_REVISION_VERSION    (3u)

/* ESCAN00067740 */
#  define STD_AR_RELEASE_MAJOR_VERSION             STD_TYPES_AR_RELEASE_MAJOR_VERSION
#  define STD_AR_RELEASE_MINOR_VERSION             STD_TYPES_AR_RELEASE_MINOR_VERSION
#  define STD_AR_RELEASE_REVISION_VERSION          STD_TYPES_AR_RELEASE_REVISION_VERSION

/* Component Version Information */
# define STD_TYPES_SW_MAJOR_VERSION       (3u)
# define STD_TYPES_SW_MINOR_VERSION       (4u)
# define STD_TYPES_SW_PATCH_VERSION       (5u)

/* ESCAN00067740 */
# define STD_SW_MAJOR_VERSION             STD_TYPES_SW_MAJOR_VERSION
# define STD_SW_MINOR_VERSION             STD_TYPES_SW_MINOR_VERSION
# define STD_SW_PATCH_VERSION             STD_TYPES_SW_PATCH_VERSION

# define STD_HIGH     1u /* Physical state 5V or 3.3V */
# define STD_LOW      0u /* Physical state 0V */

# define STD_ACTIVE   1u /* Logical state active */
# define STD_IDLE     0u /* Logical state idle */

# define STD_ON       1u
# define STD_OFF      0u

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* This typedef has been added for OSEK compliance */
#  define E_OK      0u

# define E_NOT_OK  1u

typedef uint8 Std_ReturnType;

/**********************************************************************************************************************
 *  TYPE DEFINITIONS AND FURTHER INCLUDES
 *********************************************************************************************************************/

typedef uint8 WdgMMode;
typedef uint16 WdgM_CheckpointIdType;
typedef uint8 WdgM_GlobalStatusType;
typedef uint8 WdgM_LocalStatusType;
typedef uint8 WdgM_ModeType;
typedef uint16 WdgM_SupervisedEntityIdType;

/* From Compiler.h*/
#ifndef NULL_PTR
#define NULL_PTR  (NULL)
#endif

# define FUNC(rettype, memclass) rettype
# define P2VAR(ptrtype, memclass, ptrclass) ptrtype*
# define P2CONST(ptrtype, memclass, ptrclass) const ptrtype*
# define CONST(type, memclass) const type
# define VAR(vartype, memclass) vartype


/* From Compiler_Cfg.h*/
/* WDGM */
#define WDGM_CODE
#define WDGM_APPL_CODE
#define WDGM_CONST
#define WDGM_VAR_INIT
#define WDGM_VAR_NOINIT
#define WDGM_VAR_ZERO_INIT
#define WDGM_APPL_DATA
#define WDGM_APPL_CONST

/******* WDGIF ******/
#define WDGIF_CODE
#define WDGIF_CONST
#define WDGIF_VAR
#define WDGIF_APPL_DATA
#define WDGIF_APPL_CONST

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* WDGFW_STD_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
