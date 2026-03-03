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
 *              File: Os_Ioc_Lcfg.c
 *   Generation Time: 2024-02-13 13:07:50
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_IOC_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"
#include "vstdlib.h"

/* Os module declarations */
#include "Os_Ioc_Cfg.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Ioc_Types.h"
#include "Os_Ioc.h"
#include "Ioc.h"

/* Os kernel module dependencies */
#include "Os_Fifo08.h"
#include "Os_Fifo16.h"
#include "Os_Fifo32.h"
#include "Os_Hook.h"
#include "Os_Spinlock_Lcfg.h"
#include "OsInt.h"

/* Os hal dependencies */

/* User file includes */
# include "Rte.h"
# include "usrostyp.h"


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
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_IocCopy_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM()
 *********************************************************************************************************************/
/*! \brief        Copies the given target data to the source address, based on the native data type.
 *  \details      -
 *  \param[in]    Source  The source address to read from. Parameter must not be NULL.
 *  \param[out]   Target  The target address to write to. Parameter must not be NULL.
 *  \context      OS_INTERNAL
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) Os_IocCopy_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM
(
  P2CONST(void, AUTOMATIC, OS_APPL_DATA) Source,
  P2VAR(void, AUTOMATIC, OS_APPL_DATA) Target
);

/**********************************************************************************************************************
 *  Os_IocInit_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM()
 *********************************************************************************************************************/
/*! \brief        Initializes the data buffer with configured initial values.
 *  \details      -
 *  \param[in]    Data  The pointer to the data buffer. Parameter must not be NULL.
 *  \context      OS_INTERNAL
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) Os_IocInit_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM
(
  P2VAR(void, AUTOMATIC, OS_APPL_DATA) Data
);

#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic IOC receive data: Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM */
OS_LOCAL VAR(Os_IocReadType, OS_VAR_NOINIT) OsCfg_IocRecv_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic IOC send data: Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_0 */
OS_LOCAL VAR(Os_IocWriteType, OS_VAR_NOINIT) OsCfg_IocSend_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_0_Dyn;

/*! IOC communication single data buffer: Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM */
OS_LOCAL VAR(ErrorMgr_ErrorCommPack_1_0_QM, OS_APPL_DATA) OsCfg_Ioc_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_Buffer_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic IOC send data: Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_1 */
OS_LOCAL VAR(Os_IocWriteType, OS_VAR_NOINIT) OsCfg_IocSend_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_1_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/*! IOC receive configuration data: Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM */
CONST(Os_IocReadConfigType, OS_CONST) OsCfg_IocRecv_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM =
{
  /* .Ioc      = */
  {
      /* .Spinlock              = */ NULL_PTR,
      /* .LockMode              = */ OS_IOCLOCKMODE_INTERRUPTS,
      /* .Dyn                   = */ OS_IOC_CASTDYN_IOCREAD_2_IOC(OsCfg_IocRecv_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_Dyn),
      /* .SubClass              = */ IocRead,
      /* .AccessingApplications = */ OS_APPID2MASK(OsApplication_QM)  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    },
  /* .Data     = */ &OsCfg_Ioc_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_Buffer_Dyn,   /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */
  /* .CopyCbk  = */ Os_IocCopy_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! IOC send configuration data: Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_0 */
CONST(Os_IocWriteConfigType, OS_CONST) OsCfg_IocSend_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_0 =
{
  /* .Ioc       = */
  {
      /* .Spinlock              = */ NULL_PTR,
      /* .LockMode              = */ OS_IOCLOCKMODE_INTERRUPTS,
      /* .Dyn                   = */ OS_IOC_CASTDYN_IOCWRITE_2_IOC(OsCfg_IocSend_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_0_Dyn),
      /* .SubClass              = */ IocWrite,
      /* .AccessingApplications = */ OS_APPID2MASK(OsApplication_Safety)  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    },
  /* .Data      = */ (P2VAR(void, AUTOMATIC, OS_APPL_DATA)) &OsCfg_Ioc_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_Buffer_Dyn,  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
  /* .Callback  = */
  {
      /* .CallbackRefs  = */ NULL_PTR,
      /* .CallbackCount = */ OS_CFG_NUM_IOC_RTE_ERRORMGRAGG_1_0_QM_R_SATERROR_DATA_ERRORMGR_ERRORCOMMPACK_1_0_QM_CALLBACKS
    },
  /* .CopyCbk   = */ Os_IocCopy_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM,
  /* .InitCbk   = */ Os_IocInit_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! IOC send configuration data: Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_1 */
CONST(Os_IocWriteConfigType, OS_CONST) OsCfg_IocSend_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_1 =
{
  /* .Ioc       = */
  {
      /* .Spinlock              = */ NULL_PTR,
      /* .LockMode              = */ OS_IOCLOCKMODE_INTERRUPTS,
      /* .Dyn                   = */ OS_IOC_CASTDYN_IOCWRITE_2_IOC(OsCfg_IocSend_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_1_Dyn),
      /* .SubClass              = */ IocWrite,
      /* .AccessingApplications = */ OS_APPID2MASK(OsApplication_QM)  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    },
  /* .Data      = */ (P2VAR(void, AUTOMATIC, OS_APPL_DATA)) &OsCfg_Ioc_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_Buffer_Dyn,  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
  /* .Callback  = */
  {
      /* .CallbackRefs  = */ NULL_PTR,
      /* .CallbackCount = */ OS_CFG_NUM_IOC_RTE_ERRORMGRAGG_1_0_QM_R_SATERROR_DATA_ERRORMGR_ERRORCOMMPACK_1_0_QM_CALLBACKS
    },
  /* .CopyCbk   = */ Os_IocCopy_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM,
  /* .InitCbk   = */ Os_IocInit_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  IocRead_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Redirect call to the general receive function.
 * \endinternal
 */
Std_ReturnType IocRead_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM
(
  ErrorMgr_ErrorCommPack_1_0_QM *Arg0
)
{
  Std_ReturnType status;
  ErrorMgr_ErrorCommPack_1_0_QM localVar;

  /* #10 Redirect call to the general receive function. */
  status = Os_TrapIocRead(TRUE, &OsCfg_IocRecv_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM, (P2VAR(void, AUTOMATIC, OS_APPL_DATA)) &localVar);  /* PRQA S 0310, 0314 */ /* MD_Os_Rule11.3_0310, MD_Os_Dir1.1_0314 */ 
  VStdLib_MemCpy(Arg0, &localVar, (VStdLib_CntType) sizeof(ErrorMgr_ErrorCommPack_1_0_QM));  /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */

  return status;
}



/**********************************************************************************************************************
 *  IocWrite_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_0()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Redirect call to the general send function.
 * \endinternal
 */
Std_ReturnType IocWrite_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_0
(
  const ErrorMgr_ErrorCommPack_1_0_QM *Arg0
)
{
  /* #10 Redirect call to the general send function. */
  return Os_TrapIocWrite(TRUE, &OsCfg_IocSend_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_0, (P2CONST(void, AUTOMATIC, OS_APPL_DATA)) Arg0);  /* PRQA S 0314, 1340 */ /* MD_Os_Dir1.1_0314, MD_Os_Rule17.8_1340 */
}


/**********************************************************************************************************************
 *  IocWrite_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_1()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Redirect call to the general send function.
 * \endinternal
 */
Std_ReturnType IocWrite_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_1
(
  const ErrorMgr_ErrorCommPack_1_0_QM *Arg0
)
{
  /* #10 Redirect call to the general send function. */
  return Os_TrapIocWrite(TRUE, &OsCfg_IocSend_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_1, (P2CONST(void, AUTOMATIC, OS_APPL_DATA)) Arg0);  /* PRQA S 0314, 1340 */ /* MD_Os_Dir1.1_0314, MD_Os_Rule17.8_1340 */
}


/**********************************************************************************************************************
 *  Os_IocCopy_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Copy data from source to target.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) Os_IocCopy_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM
(
  P2CONST(void, AUTOMATIC, OS_APPL_DATA) Source,
  P2VAR(void, AUTOMATIC, OS_APPL_DATA) Target
)
{
  /* #10 Copy data from source to target. */
  VStdLib_MemCpy(Target, Source, (VStdLib_CntType) sizeof(ErrorMgr_ErrorCommPack_1_0_QM));
}


/**********************************************************************************************************************
 *  Os_IocInit_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Initialize data.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) Os_IocInit_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM
(
  P2VAR(void, AUTOMATIC, OS_APPL_DATA) Data
)
{
  /* #10 Initialize data. */
  VStdLib_MemCpy(Data, &Rte_IocInitValue_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM, (VStdLib_CntType) sizeof(ErrorMgr_ErrorCommPack_1_0_QM)); /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  END OF FILE: Os_Ioc_Lcfg.c
 *********************************************************************************************************************/
