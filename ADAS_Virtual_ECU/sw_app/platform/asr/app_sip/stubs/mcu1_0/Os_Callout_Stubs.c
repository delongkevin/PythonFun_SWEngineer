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
 *              File: Os_Callout_Stubs.c
 *   Generation Time: 2024-02-13 12:17:19
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define OS_CALLOUT_STUBS_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Os.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_Include>
 *********************************************************************************************************************/
#include "EcuM.h"
#include "app_log_Boot.h"
#include "OsHooks_RpStruct.h"
#include "Os_ErrorInt.h"

#define DEBUG_OS_ERROR_NOTIF_PATTERN 		(0xA5A5A5A5u)
#define DEBUG_ERROR_HOOK_TYPE 				(0x01u)
#define DEBUG_PROTECTION_HOOK_TYPE 			(0x02u)
#define DEBUG_PANIC_HOOK_TYPE 				(0x03u)
#define PRE_EXC_STACK_OFFSET 				(0x20u)

extern uint8_t gSDL_Running;


/* union for safe integer-to-pointer conversion */
typedef struct {
	union {
		uint32_t addr;
		uint32_t *ptr;
	} U32AddrPtr;
} stackPtr_t;

ME_OsHookDebugData_t s_ME_OsHookDebugData_RPRAM_as __attribute__ ((section("reset_protected_ram_DebugDataToCAN")));
static volatile stackPtr_t resetmgr_stack_ptr = {.U32AddrPtr.addr = 0u};
static volatile uint32_t resetmgr_LinkReg = 0u;
static volatile uint32_t resetmgr_SPSR;
static volatile uint32_t resetmgr_CPSR;

static uint32_t resetmgr_getAIFSR(void);
static uint32_t resetmgr_getDFSR(void);
static uint32_t resetmgr_getDFAR(void);
static uint32_t resetmgr_getIFSR(void);
static uint32_t resetmgr_getIFAR(void);
static uint32_t resetmgr_getADFSR(void);
static uint32_t resetmgr_getSPSR(void);
static uint32_t resetmgr_getCurrCPSR(void);
static uint32_t resetmgr_getcurrLinkReg(void);
static volatile uint32_t resetmgr_getCPSR(void);
static void resetmgr_extractandupdatestackptr_autosar(Resetmode_E mode);
static void resetmgr_update_fault_registers(void);
static void resetmgr_record_stack_autosar(Resetmode_E mode);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/*
* Purpose: get AIFSR register value
* Description: get AIFSR register value
* Precondition: must not be usr mode
* Return Type : AIFSR register value
*/
static uint32_t resetmgr_getAIFSR(void)
{
	uint32_t ret = 0;
	__asm volatile (" MRC p15, 0, %0, c5, c1, 1" \
                   : "=r" (ret) \
                   : \
                   : );
	return ret;
}

/*
* Purpose: get DFSR register value
* Description: get DFSR register value
* Precondition: must not be usr mode
* Return Type : DFSR register value
*/
static uint32_t resetmgr_getDFSR(void)
{
	uint32_t ret = 0;
	__asm volatile (" MRC p15, 0, %0, c5, c0, 0" \
                   : "=r" (ret) \
                   : \
                   : );
	return ret;
}

/*
* Purpose: get DFAR register value
* Description: get DFAR register value
* Precondition: must not be usr mode
* Return Type : DFAR register value
*/
static uint32_t resetmgr_getDFAR(void)
{
	uint32_t ret = 0;
	__asm volatile (" MRC p15, 0, %0, c6, c0, 0" \
                   : "=r" (ret) \
                   : \
                   : );
	return ret;
}

/*
* Purpose: get IFSR register value
* Description: get IFSR register value
* Precondition: must not be usr mode
* Return Type : IFSR register value
*/
static uint32_t resetmgr_getIFSR(void)
{
	uint32_t ret = 0;
	__asm volatile (" MRC p15, 0, %0, c5, c0, 1" \
                   : "=r" (ret) \
                   : \
                   : );
	return ret;
}

/*
* Purpose: get IFAR register value
* Description: get IFAR register value
* Precondition: must not be usr mode
* Return Type : IFAR register value
*/
static uint32_t resetmgr_getIFAR(void)
{
	uint32_t ret = 0;
	__asm volatile (" MRC p15, 0, %0, c6, c0, 2" \
                   : "=r" (ret) \
                   : \
                   : );
	return ret;
}

/*
* Purpose: get ADFSR register value
* Description: get ADFSR register value
* Precondition: must not be usr mode
* Return Type : ADFSR register value
*/
static uint32_t resetmgr_getADFSR(void)
{
	uint32_t ret = 0;
	__asm volatile (" MRC p15, 0, %0, c5, c1, 0" \
                   : "=r" (ret) \
                   : \
                   : );
	return ret;
}

/*
* Purpose: get SPSR register value
* Description: get SPSR register value
* Precondition: must not be usr mode
* Return Type : SPSR register value
*/
static uint32_t resetmgr_getSPSR(void)
{
	uint32_t ret = 0;
	__asm volatile (" MRS %0, SPSR" \
                   : "=r" (ret) \
                   : \
                   : );
	return ret;
}

/*
* Purpose: get CPSR register value
* Description: get CPSR register value
* Precondition: must not be usr mode
* Return Type : CPSR register value
*/
static uint32_t resetmgr_getCurrCPSR(void)
{
	uint32_t ret = 0;
	__asm volatile (" MRS %0, CPSR" \
                   : "=r" (ret) \
                   : \
                   : );
	return ret;
}

/*
* Purpose: get link register value
* Precondition: none
* Return Type : R14 register value
*/
static uint32_t resetmgr_getcurrLinkReg(void)
{
	uint32_t ret = 0;
	__asm volatile (" MOV %0, R14" \
                   : "=r" (ret) \
                   : \
                   : );
	return ret;
}

/*
* Purpose: get CPSR register value
* Precondition: none
* Return Type : CPSR register value
*/
static volatile uint32_t resetmgr_getCPSR(void)
{
	return resetmgr_CPSR;
}

/*
* Purpose: get stack pointer
* Description: Get stack pointer from the mode right before when
* the exception occured for autosar exceptions. All global
* variables are used here because as we change mode the stack also
* gets changed so we can't rely on local variables.
* Precondition: none
* Return Type : none, updates stack pointer global variable.
*/
static void resetmgr_extractandupdatestackptr_autosar(Resetmode_E mode)
{
   	uint32_t temp_val;
	static volatile uint32_t resetmgr_abtstack_ptr = 0u;
	static volatile uint32_t resetmgr_CPSR_copy;
	stackPtr_t tempStack_ptr;

   	if ((mode == Reset_Abort_mode) || (mode == Reset_Undef_mode))
   	{
       	/* In case of Abt or Und mode the stack pointer
          and the link register at the time the issue occured
          will be stored into the corresponding abt or und mode stack*/
		resetmgr_CPSR = resetmgr_getCurrCPSR();
		temp_val = resetmgr_CPSR;
		temp_val &= 0xFFFFFFE0U; /* clear mode bits */
		if (mode == Reset_Abort_mode)
		{
			temp_val |= 0x17U; /* set abt mode */
		} else
		{
			temp_val |= 0x1BU; /* set UND mode */
		}
       	/* disable the interrupt as we don't want to be interrupted
          when mode was changed as this is one way street to safe state */
       	temp_val |= 0x80U;
       	__asm volatile (" MSR     cpsr_cf, %0 " \
                         : \
                         : "r" (temp_val) \
                         : );
       	/* get the stack pointer (R13) */
       	__asm volatile (" MOV %0, R13" \
                   : "=r" (resetmgr_abtstack_ptr) \
                   : \
                   : );
       	/* stack pointer is stored at offset 0x20 */
		temp_val = resetmgr_abtstack_ptr;
	   	tempStack_ptr.U32AddrPtr.addr = (temp_val > (UINT32_MAX - PRE_EXC_STACK_OFFSET)) ? temp_val : (temp_val + PRE_EXC_STACK_OFFSET);
		resetmgr_stack_ptr.U32AddrPtr.addr = *tempStack_ptr.U32AddrPtr.ptr;

		/* link register is stored at offset 0x24 */
       	resetmgr_LinkReg = resetmgr_getcurrLinkReg();

		/* go back to the original mode */
		resetmgr_CPSR_copy = resetmgr_getCPSR();
       	__asm volatile (" MSR     cpsr_cf, %0 " \
                         : \
                         : "r" (resetmgr_CPSR_copy) \
                         : );
   	}
   	else
   	{
		/* In case of default simply update the current modes
			stack and link register values */
		__asm volatile (" MOV %0, R13" \
                   : "=r" (resetmgr_stack_ptr.U32AddrPtr.addr) \
                   : \
                   : );
		resetmgr_LinkReg = resetmgr_getcurrLinkReg();
   	}

}

/*
* Purpose: update all the exception registers
* Precondition: must not be in usr mode
* Return Type : none, resetblock is updated
*/
static void resetmgr_update_fault_registers(void)
{
   s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_DFSR = resetmgr_getDFSR();
   s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_DFAR = resetmgr_getDFAR();
   s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_IFSR = resetmgr_getIFSR();
   s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_IFAR = resetmgr_getIFAR();
   s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_ADFSR = resetmgr_getADFSR();
   s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_AIFSR = resetmgr_getAIFSR();
   s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_SPSR = resetmgr_getSPSR();
}

/*
* Purpose: record the callstack information for
* cores running autosar when the issue occured.
* Precondition: must not be in usr mode
* Return Type : none, resetblock is updated
*/
static void resetmgr_record_stack_autosar(Resetmode_E mode)
{
	uint8_t i;

	resetmgr_extractandupdatestackptr_autosar(mode);
	for (i = 0; i < RESETMGR_MAX_STACK_LEN; i++ ) {
		s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_Stack[i] = resetmgr_stack_ptr.U32AddrPtr.ptr[i];
	}
	s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_Link = resetmgr_LinkReg;
}

/**********************************************************************************************************************
 *  StartupHook()
 *********************************************************************************************************************/
#if OS_CFG_STARTUPHOOK_SYSTEM == STD_ON
# define OS_START_SEC_STARTUPHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_STARTUPHOOK_CODE) StartupHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_StartupHook>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_STARTUPHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_STARTUPHOOK_SYSTEM */


/**********************************************************************************************************************
 *  ShutdownHook()
 *********************************************************************************************************************/
#if OS_CFG_SHUTDOWNHOOK_SYSTEM == STD_ON
# define OS_START_SEC_SHUTDOWNHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_EXCEPTION_HOOK_SAFE_SATE() {while(1);}

FUNC(void, OS_SHUTDOWNHOOK_CODE) ShutdownHook(StatusType Fatalerror)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ShutdownHook>
 *********************************************************************************************************************/
  (void)Fatalerror;
  EcuM_Shutdown();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_SHUTDOWNHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_SHUTDOWNHOOK_SYSTEM */


/**********************************************************************************************************************
 *  ErrorHook()
 *********************************************************************************************************************/
#if OS_CFG_ERRORHOOK_SYSTEM == STD_ON
# define OS_START_SEC_ERRORHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_ERRORHOOK_CODE) ErrorHook(StatusType Error)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ErrorHook>
 *********************************************************************************************************************/
  Os_ErrorInformationType CurrentError;
  volatile uint8 endless = 1u;
  volatile TaskType activatedTask;
  (void)Os_GetDetailedError(&CurrentError);
  if (CurrentError.Error == (StatusType)OS_STATUS_LIMIT)
  {
      return;
  }
  else
  {
	  (void)Os_GetDetailedError(&CurrentError);
	  activatedTask = OSError_ActivateTask_TaskID();

#ifdef Enable_Printf
	  APP_log(APP_LOG_ERR, "\n Log from = %d %s\n Current Service = %d\n Current Error = %d\n Detail Error = %d\n Activated Task Id = %d\n Error = %d\n",\
			  __LINE__, __func__, CurrentError.Service, CurrentError.Error, CurrentError.DetailedError, activatedTask, Error);
#endif

	  s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_Type_MCU1_0 = DEBUG_ERROR_HOOK_TYPE;
	  s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_Service_MCU1_0 = (uint16)CurrentError.Service;
	  s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_Error_MCU1_0 = (uint8)CurrentError.Error;
	  s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_DtErr_MCU1_0 = (uint16)CurrentError.DetailedError;
	  s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_actTsk_MCU1_0 = (uint8)activatedTask;
	  s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_fatalErr_MCU1_0 = Error;
	  s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_PresentPtr_MCU1_0 = DEBUG_OS_ERROR_NOTIF_PATTERN;

	  /* Capture the information regarding this error in reset block */
	  resetmgr_update_fault_registers();
	  resetmgr_record_stack_autosar(Reset_default_mode);
	  while ((uint8)1 == endless)
	  {
		  ;
	  }
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_ERRORHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_ERRORHOOK_SYSTEM */


/**********************************************************************************************************************
 *  ProtectionHook()
 *********************************************************************************************************************/
#if OS_CFG_PROTECTIONHOOK_SYSTEM == STD_ON
# define OS_START_SEC_PROTECTIONHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(ProtectionReturnType, OS_PROTECTIONHOOK_CODE) ProtectionHook(StatusType Fatalerror)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ProtectionHook>
 *********************************************************************************************************************/
	Os_ErrorInformationType CurrentError;
	volatile TaskType activatedTask;

	if ( gSDL_Running == (uint8_t)TRUE ) {
		/* ignore exceptions while self test is running*/
		return PRO_IGNORE_EXCEPTION;
	}else {

		(void)Os_GetDetailedError(&CurrentError);
		activatedTask = OSError_ActivateTask_TaskID();

		/* SSR Req ID : 18416634, 18416616 when exception happens from non-critical context */
		s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_Type_MCU1_0 = DEBUG_PROTECTION_HOOK_TYPE;
		s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_Service_MCU1_0 = (uint16)CurrentError.Service;
		s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_Error_MCU1_0 = (uint8)CurrentError.Error;
		s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_DtErr_MCU1_0 = (uint16)CurrentError.DetailedError;
		s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_actTsk_MCU1_0 = (uint8)activatedTask;
		s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_fatalErr_MCU1_0 = Fatalerror;
		s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_PresentPtr_MCU1_0 = DEBUG_OS_ERROR_NOTIF_PATTERN;

#ifdef Enable_Printf
		uint32_t AIFSR = resetmgr_getAIFSR();
		uint32_t DFSR  = resetmgr_getDFSR();
		uint32_t IFSR = resetmgr_getIFSR();
		uint32_t IFAR = resetmgr_getIFAR();
		uint32_t DFAR =  resetmgr_getDFAR();
		uint32_t ADFSR = resetmgr_getADFSR();
		uint32_t SPSR = resetmgr_getSPSR();
		uint32_t CPSR = resetmgr_getCPSR();
		appLogPrintf("\n %d %s %d %d %d %d AIFSR:%X DFSR:%X, IFSR:%X, IFAR:%X, DFAR:%X, ADFSR:%X, SPSR: %X, CPSR:%X",__LINE__, __func__, CurrentError.Service, CurrentError.Error, CurrentError.DetailedError, activatedTask,AIFSR,DFSR,IFSR,IFAR,DFAR,ADFSR,SPSR,CPSR);
#endif

		/* Capture the information regarding this error in reset block */
		resetmgr_update_fault_registers();
		if ((StatusType)OS_STATUS_PROTECTION_MEMORY == Fatalerror)
		{
			resetmgr_record_stack_autosar(Reset_Abort_mode);
		} else if ((StatusType)OS_STATUS_PROTECTION_EXCEPTION == Fatalerror)
		{
			resetmgr_record_stack_autosar(Reset_Undef_mode);
		}
		else
		{
			resetmgr_record_stack_autosar(Reset_default_mode);
		}

		OS_EXCEPTION_HOOK_SAFE_SATE()

		return PRO_SHUTDOWN;
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_PROTECTIONHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_PROTECTIONHOOK_SYSTEM */


/**********************************************************************************************************************
 *  PreTaskHook()
 *********************************************************************************************************************/
#if OS_CFG_PRETASKHOOK == STD_ON
# define OS_START_SEC_PRETASKHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_PRETASKHOOK_CODE) PreTaskHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PreTaskHook>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_PRETASKHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_PRETASKHOOK */


/**********************************************************************************************************************
 *  PostTaskHook()
 *********************************************************************************************************************/
#if OS_CFG_POSTTASKHOOK == STD_ON
# define OS_START_SEC_POSTTASKHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_POSTTASKHOOK_CODE) PostTaskHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PostTaskHook>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_POSTTASKHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_POSTTASKHOOK */


/**********************************************************************************************************************
 *  Os_PanicHook()
 *********************************************************************************************************************/
#if OS_CFG_PANICHOOK == STD_ON
# define OS_START_SEC_PANICHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_PANICHOOK_CODE) Os_PanicHook(Os_PanicStatusType Status)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PanicHook>
 *********************************************************************************************************************/
	(void)Status;
	Os_ErrorInformationType CurrentError;
	volatile TaskType activatedTask;
	activatedTask = OSError_ActivateTask_TaskID();
	(void)Os_GetDetailedError(&CurrentError);
#ifdef Enable_Printf
	APP_log(APP_LOG_ERR, "\n Log from = %d %s\n Current Service = %d\n Current Error = %d\n Detail Error = %d\n Activated Task Id = %d\n",\
			__LINE__, __func__, CurrentError.Service, CurrentError.Error, CurrentError.DetailedError, activatedTask);
#endif
	s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_Type_MCU1_0 = DEBUG_PANIC_HOOK_TYPE;
	s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_Service_MCU1_0 = (uint16)CurrentError.Service;
	s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_Error_MCU1_0 = (uint8)CurrentError.Error;
	s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_DtErr_MCU1_0 = (uint16)CurrentError.DetailedError;
	s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_actTsk_MCU1_0 = (uint8)activatedTask;
	s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_fatalErr_MCU1_0 = 0x00u;
	s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_PresentPtr_MCU1_0 = DEBUG_OS_ERROR_NOTIF_PATTERN;
	/* Capture the information regarding this error in reset block */
	resetmgr_update_fault_registers();
	resetmgr_record_stack_autosar(Reset_default_mode);

	/* Panic Hook Does Not Return - Implement SafeState2
	 * SSR Req ID : 18416634, 18416616 when exception happens from critical context
	 */
	OS_EXCEPTION_HOOK_SAFE_SATE()
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_PANICHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_PANICHOOK */



/* Unrecognized User Blocks */
#if 0
#endif


/**********************************************************************************************************************
 *  END OF FILE: Os_Callout_Stubs.c
 *********************************************************************************************************************/
