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
 *            Module: IoHwAb
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: IoHwAb_Cfg.h
 *   Generation Time: 2024-02-13 13:07:47
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if (!defined IOHWAB_CFG_H)
#define IOHWAB_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/

/* ===== MODULE INCLUDES ================================================== */

/* ===== SCHM INCLUDE ===================================================== */ 
#include "SchM_IoHwAb.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/* ===== VERSION IDENTIFICATION =========================================== */
#define IOHWAB_CFG_MAJOR_VERSION  (6u) 
#define IOHWAB_CFG_MINOR_VERSION  (1u) 
#define IOHWAB_CFG_PATCH_VERSION  (0u) 



/* ====== API CONFIGURATION =============================================== */

#define IOHWAB_VERSION_INFO_API                 (STD_OFF)
#define IOHWAB_USE_INIT_FUNCTION                (STD_ON)

/* ====== CONFIGURATION FOR DEVELOPMENT MODE ============================== */

#define IOHWAB_DEV_ERROR_DETECT                 (STD_ON)



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


#define IoHwAb_GlobalSuspend() SchM_Enter_IoHwAb_IOHWAB_EXCLUSIVE_AREA_0()
#define IoHwAb_GlobalRestore() SchM_Exit_IoHwAb_IOHWAB_EXCLUSIVE_AREA_0()



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/* Prototypes of Sender/Receiver functions can be found in Rte_IoHwAb.h */

/* Prototypes of Client/Server functions can be found in Rte_IoHwAb.h */

/* Prototypes of Handler functions can be found in Rte_IoHwAb.h */



#endif /* (!defined IOHWAB_CFG_H) */
/**********************************************************************************************************************
 *  END OF FILE: IoHwAb_Cfg.h
 **********************************************************************************************************************/
