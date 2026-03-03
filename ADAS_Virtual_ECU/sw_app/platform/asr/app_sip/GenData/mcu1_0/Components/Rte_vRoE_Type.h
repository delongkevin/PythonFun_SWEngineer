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
 *             File:  Rte_vRoE_Type.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application types header file for SW-C <vRoE>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_VROE_TYPE_H
# define RTE_VROE_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef VROE_STATE_ENABLED
#   define VROE_STATE_ENABLED (0U)
#  endif

#  ifndef VROE_STATE_DISABLED
#   define VROE_STATE_DISABLED (1U)
#  endif

#  ifndef VROE_E_CONDITIONSNOTCORRECT
#   define VROE_E_CONDITIONSNOTCORRECT (34U)
#  endif

#  ifndef VROE_E_REQUESTOUTOFRANGE
#   define VROE_E_REQUESTOUTOFRANGE (49U)
#  endif

#  ifndef VROE_INITIAL
#   define VROE_INITIAL (0U)
#  endif

#  ifndef VROE_PENDING
#   define VROE_PENDING (1U)
#  endif

#  ifndef VROE_CANCEL
#   define VROE_CANCEL (2U)
#  endif

#  ifndef VROE_FORCE_RCRRP_OK
#   define VROE_FORCE_RCRRP_OK (3U)
#  endif

#  ifndef VROE_FORCE_RCRRP_NOT_OK
#   define VROE_FORCE_RCRRP_NOT_OK (64U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_VROE_TYPE_H */
