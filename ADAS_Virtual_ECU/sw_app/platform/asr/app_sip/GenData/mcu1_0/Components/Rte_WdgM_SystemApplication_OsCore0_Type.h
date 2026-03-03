/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_WdgM_SystemApplication_OsCore0_Type.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application types header file for SW-C <WdgM_SystemApplication_OsCore0>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_TYPE_H
# define RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef WDGM_GLOBAL_STATUS_OK
#   define WDGM_GLOBAL_STATUS_OK (0U)
#  endif

#  ifndef WDGM_GLOBAL_STATUS_FAILED
#   define WDGM_GLOBAL_STATUS_FAILED (1U)
#  endif

#  ifndef WDGM_GLOBAL_STATUS_EXPIRED
#   define WDGM_GLOBAL_STATUS_EXPIRED (2U)
#  endif

#  ifndef WDGM_GLOBAL_STATUS_STOPPED
#   define WDGM_GLOBAL_STATUS_STOPPED (3U)
#  endif

#  ifndef WDGM_GLOBAL_STATUS_DEACTIVATED
#   define WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
#  endif

#  ifndef WDGM_LOCAL_STATUS_OK
#   define WDGM_LOCAL_STATUS_OK (0U)
#  endif

#  ifndef WDGM_LOCAL_STATUS_FAILED
#   define WDGM_LOCAL_STATUS_FAILED (1U)
#  endif

#  ifndef WDGM_LOCAL_STATUS_EXPIRED
#   define WDGM_LOCAL_STATUS_EXPIRED (2U)
#  endif

#  ifndef WDGM_LOCAL_STATUS_DEACTIVATED
#   define WDGM_LOCAL_STATUS_DEACTIVATED (4U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_TYPE_H */
