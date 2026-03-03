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
 *             File:  Rte_ErrorMgrSat_1_0_QM_Type.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application types header file for SW-C <ErrorMgrSat_1_0_QM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_ERRORMGRSAT_1_0_QM_TYPE_H
# define RTE_ERRORMGRSAT_1_0_QM_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef ErrorMgr_Error_MissingMessage_ORC_FD1
#   define ErrorMgr_Error_MissingMessage_ORC_FD1 (0U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_ORC_FD1
#   define ErrorMgr_Error_DLC_Fault_ORC_FD1 (1U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_TRSKM_FD_1
#   define ErrorMgr_Error_MissingMessage_TRSKM_FD_1 (2U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_TRSKM_FD_1
#   define ErrorMgr_Error_DLC_Fault_TRSKM_FD_1 (3U)
#  endif

#  ifndef ErrorMgr_Error_TRSC_EnableBtn_Sts_Invld
#   define ErrorMgr_Error_TRSC_EnableBtn_Sts_Invld (4U)
#  endif

#  ifndef ErrorMgr_Error_TRSC_CenterBtn_Sts_Invld
#   define ErrorMgr_Error_TRSC_CenterBtn_Sts_Invld (5U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_TRSKM
#   define ErrorMgr_Error_CRC_Fault_TRSKM (6U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_TRSKM
#   define ErrorMgr_Error_MC_Fault_TRSKM (7U)
#  endif

#  ifndef ErrorMgr_Error_SBR1RowDriverSeatSts_Invld
#   define ErrorMgr_Error_SBR1RowDriverSeatSts_Invld (8U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_ORC
#   define ErrorMgr_Error_CRC_Fault_ORC (9U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_ORC
#   define ErrorMgr_Error_MC_Fault_ORC (10U)
#  endif

#  ifndef ErrorMgr_Error_TRSC_RawKnob_OOR_Fault
#   define ErrorMgr_Error_TRSC_RawKnob_OOR_Fault (11U)
#  endif

#  ifndef ErrorMgr_ErrorNum_Max
#   define ErrorMgr_ErrorNum_Max (1112U)
#  endif

#  ifndef ErrorMgr_Invalid
#   define ErrorMgr_Invalid (0U)
#  endif

#  ifndef ErrorMgr_ErrorInactive
#   define ErrorMgr_ErrorInactive (1U)
#  endif

#  ifndef ErrorMgr_ErrorActive
#   define ErrorMgr_ErrorActive (2U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_ERRORMGRSAT_1_0_QM_TYPE_H */
