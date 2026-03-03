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
 *              File: Ioc.h
 *   Generation Time: 2024-02-13 13:07:48
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef IOC_H
# define IOC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"
# include "vstdlib.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */

/* User file includes */
# include "Rte.h"
# include "usrostyp.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! IOC function return types */
# define IOC_E_OK                                (RTE_E_OK          )
# define IOC_E_NOK                               ((Std_ReturnType) 1)
# define IOC_E_NO_DATA                           (RTE_E_NO_DATA     )
# define IOC_E_LOST_DATA                         (RTE_E_LOST_DATA   )
# define IOC_E_LIMIT                             (RTE_E_LIMIT       )
# define IOC_E_CHANNEL                           (IOC_E_NOK         )


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
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  IocRead_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM()
 *********************************************************************************************************************/
/*! \brief        Reads the data from the IOC.
 *  \details      -
 *  \param[out]   Arg0  Data read from the IOC. Parameter must not be NULL.
 *  \returns      For further information see Os_IocRead().
 *  \context      TASK|ISR2
 *  \reentrant    TRUE if concurrent access is prevented by configuration.
 *  \synchronous  TRUE
 *  \pre          Channel is initialized.
 *********************************************************************************************************************/
Std_ReturnType IocRead_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM
(
  ErrorMgr_ErrorCommPack_1_0_QM *Arg0
);

/**********************************************************************************************************************
 *  IocWrite_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_0()
 *********************************************************************************************************************/
/*! \brief        Writes the given data to the IOC.
 *  \details      -
 *  \param[in]    Arg0  The data to write to the IOC. Parameter must not be NULL.
 *  \returns      For further information see Os_IocWrite().
 *  \context      TASK|ISR2
 *  \reentrant    TRUE if concurrent access is prevented by configuration.
 *  \synchronous  TRUE
 *  \pre          -
 *********************************************************************************************************************/
Std_ReturnType IocWrite_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_0
(
  const ErrorMgr_ErrorCommPack_1_0_QM *Arg0
);

/**********************************************************************************************************************
 *  IocWrite_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_1()
 *********************************************************************************************************************/
/*! \brief        Writes the given data to the IOC.
 *  \details      -
 *  \param[in]    Arg0  The data to write to the IOC. Parameter must not be NULL.
 *  \returns      For further information see Os_IocWrite().
 *  \context      TASK|ISR2
 *  \reentrant    TRUE if concurrent access is prevented by configuration.
 *  \synchronous  TRUE
 *  \pre          -
 *********************************************************************************************************************/
Std_ReturnType IocWrite_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_1
(
  const ErrorMgr_ErrorCommPack_1_0_QM *Arg0
);


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* IOC_H */

/**********************************************************************************************************************
 *  END OF FILE: Ioc.h
 *********************************************************************************************************************/
