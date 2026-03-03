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
 *             File:  Rte_CDD_E2EWrapper_Type.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application types header file for SW-C <CDD_E2EWrapper>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CDD_E2EWRAPPER_TYPE_H
# define RTE_CDD_E2EWRAPPER_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef E2E_MEP_STATUS_OK
#   define E2E_MEP_STATUS_OK (0U)
#  endif

#  ifndef E2E_MEP_STATUS_NONEWDATA
#   define E2E_MEP_STATUS_NONEWDATA (1U)
#  endif

#  ifndef E2E_MEP_STATUS_WRONGCRC
#   define E2E_MEP_STATUS_WRONGCRC (2U)
#  endif

#  ifndef E2E_MEP_STATUS_SYNC
#   define E2E_MEP_STATUS_SYNC (3U)
#  endif

#  ifndef E2E_MEP_STATUS_INITIAL
#   define E2E_MEP_STATUS_INITIAL (4U)
#  endif

#  ifndef E2E_MEP_STATUS_REPEATED
#   define E2E_MEP_STATUS_REPEATED (8U)
#  endif

#  ifndef E2E_MEP_STATUS_OKSOMELOST
#   define E2E_MEP_STATUS_OKSOMELOST (32U)
#  endif

#  ifndef E2E_MEP_STATUS_WRONGSEQUENCE
#   define E2E_MEP_STATUS_WRONGSEQUENCE (64U)
#  endif

#  ifndef E2E_MEP_DATAID_BOTH
#   define E2E_MEP_DATAID_BOTH (0U)
#  endif

#  ifndef E2E_MEP_DATAID_ALT
#   define E2E_MEP_DATAID_ALT (1U)
#  endif

#  ifndef E2E_MEP_DATAID_LOW
#   define E2E_MEP_DATAID_LOW (2U)
#  endif

#  ifndef E2E_MEP_DATAID_NIBBLE
#   define E2E_MEP_DATAID_NIBBLE (3U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CDD_E2EWRAPPER_TYPE_H */
