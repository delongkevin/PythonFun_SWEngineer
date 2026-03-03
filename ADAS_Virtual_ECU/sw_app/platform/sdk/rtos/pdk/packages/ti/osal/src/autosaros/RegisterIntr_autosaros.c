/*
 * Copyright (c) 2017-present, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== RegisterIntr_nonos.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ti/osal/osal.h>
#include <ti/osal/src/autosaros/autosaros_config.h>
#include <ti/osal/RegisterIntr.h>
#include <ti/csl/arch/r5/interrupt.h>
#include <ti/csl/csl.h>
#ifdef _TMS320C6X
#include <ti/csl/src/intc/csl_intcAux.h>
#endif
#include "Os.h"
#ifdef BUILD_MCU1_0
#include <ti/csl/soc/j721s2/src/cslr_intr_mcu_r5fss0_core0.h>
#else
#include <ti/csl/soc/j721s2/src/cslr_intr_r5fss1_core0.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_OSAL_INTR_NUM  OS_ISRID_COUNT
#define INVALID_ADDRESS_INTR_HANDLE 0x70800000 /* 0x70800000 is a valid address, need to find out real invalid address*/

static void       *argArray[MAX_OSAL_INTR_NUM];
static IntrFuncPtr fxnArray[MAX_OSAL_INTR_NUM];
static uint32_t    intnum[MAX_OSAL_INTR_NUM];

static ISRType Osal_Autosar_IntNum(int32_t interruptNum);

/*
 * Purpose:     Initializes the interrupt registration config structure
 * Description: Initializes the interrupt registration config structure prior to
 *              invoking the Osal_registerIntr API
 */
void Osal_RegisterInterrupt_initParams(OsalRegisterIntrParams_t *interruptRegParams)
{
  if(interruptRegParams!=NULL_PTR) {
      /* Corepac config */
      interruptRegParams->corepacConfig.name= (char *) NULL_PTR;
      interruptRegParams->corepacConfig.corepacEventNum=-1;
      interruptRegParams->corepacConfig.intVecNum=-1;
      interruptRegParams->corepacConfig.isrRoutine=(void (*)(uintptr_t arg)) NULL_PTR;
      interruptRegParams->corepacConfig.arg=(uintptr_t)0U;
      interruptRegParams->corepacConfig.priority=0x20U; /* Default */
      interruptRegParams->corepacConfig.enableIntr=TRUE;
#if defined (__ARM_ARCH_7A__)
      interruptRegParams->corepacConfig.triggerSensitivity = 0x3; /* interrupt edge triggered */
#endif

#if defined(__aarch64__) || defined (__TI_ARM_V7R4__)
      interruptRegParams->corepacConfig.triggerSensitivity = (uint32_t)OSAL_ARM_GIC_TRIG_TYPE_LEVEL; /* interrupt level triggered */
#endif
      /* SOC Mux Config */
      interruptRegParams->socMuxConfig.muxInParams=(MuxIntcP_inParams *) NULL_PTR;
      interruptRegParams->socMuxConfig.muxOutParams=(MuxIntcP_outParams *) NULL_PTR;
  }
  return;
}

void Osal_intrHandler(uint32_t intvecnum)
{
    IntrFuncPtr  fxnPtr;
    uint8_t      i;

    for (i = 0; i < MAX_OSAL_INTR_NUM; i++) {
        if (intnum[i] == intvecnum) {
            break;
        }
    }
    if (i < MAX_OSAL_INTR_NUM) {
        fxnPtr = fxnArray[i];
        if (fxnPtr != NULL) {
            fxnPtr(argArray[i]);
        }
    }
}
/*
 * Purpose:     Registers the interrupt for the event with the params provided
 * Description: Registers the event with the event combiner/Interrupt Vector.
 *
 * Returns:     The Hwi Handle and the return codes defined in OsalInterruptRetCode_e
 */
volatile uint8_t ISR_enrty_exists=0;
OsalInterruptRetCode_e Osal_RegisterInterrupt(OsalRegisterIntrParams_t *interruptRegParams,HwiP_Handle *hwiPHandlePtr)
{

    OsalInterruptRetCode_e     ret=OSAL_INT_SUCCESS;
    uint8_t i;

    ISR_enrty_exists=0;

    for (i = 0; ((i < MAX_OSAL_INTR_NUM) && (0x00 == ISR_enrty_exists)); i++) {
        if (intnum[i] == interruptRegParams->corepacConfig.intVecNum) {
            fxnArray[i] = (IntrFuncPtr)interruptRegParams->corepacConfig.isrRoutine;
            argArray[i] = (void *)interruptRegParams->corepacConfig.arg;
            intnum[i] = interruptRegParams->corepacConfig.intVecNum;
            ISR_enrty_exists =1;
        }
    }
    if (0x00 == ISR_enrty_exists)
    {
        for (i = 0; i < MAX_OSAL_INTR_NUM; i++) {
            if (fxnArray[i] == NULL) {
                fxnArray[i] = (IntrFuncPtr)interruptRegParams->corepacConfig.isrRoutine;
                argArray[i] = (void *)interruptRegParams->corepacConfig.arg;
                intnum[i] = interruptRegParams->corepacConfig.intVecNum;
                break;
            }
        }
    }

    if (i == MAX_OSAL_INTR_NUM) {
        ret= OSAL_INT_UNSUPPORTED;
    }
    else
    {
        if(0x01 == interruptRegParams->corepacConfig.enableIntr)
        {
            Osal_EnableInterrupt((int32_t)0, interruptRegParams->corepacConfig.intVecNum);
        }
        else
        {
            /* 
             *  Note: We should be disabling the interrupt but commenting the code per the review feedback
             *  since it will impact perfromance of other components.
            */
            /* Osal_DisableInterrupt((int32_t)0, interruptRegParams->corepacConfig.intVecNum); */
        }
    }

    /* creates an exception if Someone uses this handle - j721e
     * since INVALID_ADDRESS_INTR_HANDLE is invalid address.
     * To support Osal_DeleteInterrupt implementation, we are now adding
     * interruptNum to INVALID_ADDRESS_INTR_HANDLE. Then handle will be used in
     * Osal_DeleteInterrupt to delete and disable the interrupt.
    */
    *hwiPHandlePtr = (HwiP_Handle)(INVALID_ADDRESS_INTR_HANDLE + interruptRegParams->corepacConfig.intVecNum);
    return ret;
}

/*
 * Purpose:     Registers the interrupt for the event with the params provided
 * Description: Registers the event with the event combiner/Interrupt Vector.
 *
 * Returns:     The Hwi Handle and the return codes defined in OsalInterruptRetCode_e
 */
OsalInterruptRetCode_e Osal_RegisterInterruptDirect(OsalRegisterIntrParams_t *interruptRegParams,
                                                    HwiP_DirectFxn isrFxn, HwiP_Handle *hwiPHandlePtr)
{

    OsalInterruptRetCode_e     ret=OSAL_INT_SUCCESS;
    HwiP_Handle                hwiPHandle=NULL_PTR;
    HwiP_Params                 hwiInputParams;

    /* Program the corepac interrupt */
    if( (isrFxn == (void (*)(void)) NULL_PTR) ||
        (interruptRegParams->corepacConfig.corepacEventNum<0)) {
        ret=OSAL_INT_ERR_INVALID_PARAMS;
    }

    HwiP_Params_init(&hwiInputParams);

    hwiInputParams.name = interruptRegParams->corepacConfig.name;
    hwiInputParams.arg  = (uintptr_t)interruptRegParams->corepacConfig.arg;
    hwiInputParams.priority = interruptRegParams->corepacConfig.priority;
    hwiInputParams.evtId = (uint32_t)interruptRegParams->corepacConfig.corepacEventNum;
    hwiInputParams.enableIntr = interruptRegParams->corepacConfig.enableIntr;
#if defined (__ARM_ARCH_7A__) || defined (__aarch64__) || defined (__TI_ARM_V7R4__)
    hwiInputParams.triggerSensitivity = interruptRegParams->corepacConfig.triggerSensitivity;
#endif

#ifdef _TMS320C6X
    ret = OSAL_INT_UNSUPPORTED;
#else

#if (defined (__ARM_ARCH_7A__) || defined (__aarch64__)) && !defined (SOC_AM437x) &&  !defined(SOC_AM335x)
    /* Initialize GIC if not done already */
    Osal_HwAttrs hwAttrs;
    (void)Osal_getHwAttrs(&hwAttrs);
    if(hwAttrs.hwAccessType==OSAL_HWACCESS_UNRESTRICTED)
    {
        /* Do GIC init only in the case of unrestricted hw access */
        OsalArch_gicInit();
    }
#if defined(SOC_K2G) || defined (SOC_K2L) || defined (SOC_K2H) || defined (SOC_K2K) || defined (SOC_K2E)
    /* Keystone parts don't need subtract by 32 for ARM GIC ID */
#else
    /* Subtract 32 as the IRQ handler for A15 subtracts 32, Keystone handler does not do it */
#if !defined(__aarch64__)
    interruptRegParams->corepacConfig.intVecNum -= 32;
#endif
#endif
#endif

    hwiPHandle =  HwiP_createDirect(interruptRegParams->corepacConfig.intVecNum, isrFxn, &hwiInputParams);
    if(hwiPHandle ==NULL_PTR) {
        ret=OSAL_INT_ERR_HWICREATE;
    }
#endif

    /* creates an exception if Someone uses this handle - j721e
     * since INVALID_ADDRESS_INTR_HANDLE is invalid address.
     * To support Osal_DeleteInterrupt implementation, we are now adding
     * interruptNum to INVALID_ADDRESS_INTR_HANDLE. Then handle will be used in
     * Osal_DeleteInterrupt to delete and disable the interrupt.
    */
    *hwiPHandlePtr = (HwiP_Handle)(INVALID_ADDRESS_INTR_HANDLE + interruptRegParams->corepacConfig.intVecNum);
    return ret ;
}

/*
 * Purpose:     Deletes/Unregisters an interrupt
 * Description: Deletes/Unregisters an interrupt associated with an event number(0-127).
 *
 * Returns:     OSAL_INT_SUCCESS if successful,OSAL_INT_ERR_DELETE if failed
 */
OsalInterruptRetCode_e Osal_DeleteInterrupt(HwiP_Handle handle,int32_t corepacEventNum)
{

    HwiP_Status hwiP_ret=HwiP_OK;
    OsalInterruptRetCode_e ret=OSAL_INT_SUCCESS;
    uint8_t i;
    int32_t interruptNum=(int32_t)handle - INVALID_ADDRESS_INTR_HANDLE;
#ifdef _TMS320C6X
   /* For C66x, it needs to be found out if this is derived out of
    * an event combiner. If so, do not delete the HWI. Just unregister the function from from the event combiner & disable the event.
    */
    {
       CSL_IntcEventId hwi_eventId;
       
       /* In the baremetal case the handle holds the information (handle->eventId) 
          if this is a event combiner handle, in which case the handle->eventId = [0-3]
        */  
       hwi_eventId=(((Hwi_Struct *)handle)->handle)->eventId;
       if( (hwi_eventId > 0) && (hwi_eventId <4)) { 
           /* This is event combiner, so do not destroy the hwi, but remove the dispatch table entry */
          (void)EventCombinerP_dispatchPlug((uint32_t)corepacEventNum,(EventCombinerP_FuncPtr) NULL_PTR,0,(bool)false);
          (void)EventCombinerP_disableEvent((uint32_t)corepacEventNum);
          /* Return Success */
       } else {
          /* This is not an event dispatcher function, so destruct the HwiP as usual */
           hwiP_ret=HwiP_delete(handle);
           if(hwiP_ret!=HwiP_OK) {
             ret=OSAL_INT_ERR_DELETE;
           }
       }

    }
#else
    /* For non-c66x cases, just delete the handle */
    /* for Autosar, delete interrupt is not possible, return true */
    for (i = 0; i < MAX_OSAL_INTR_NUM; i++) {
        if (intnum[i] == interruptNum) {
            fxnArray[i] = NULL;
            argArray[i] = NULL;
            intnum[i] = 0u;
            Osal_DisableInterrupt((int32_t)0, interruptNum);
            break;
        }
    }
    if(hwiP_ret!=HwiP_OK) {
      ret=OSAL_INT_ERR_DELETE;
    }
#endif
    return(ret);
}



/*
 * Purpose:     Enables an event/interrupt
 * Description: Enables the interrupt associated with an event number(0-127).
 *              In case of the event combiner, the corresponding event is
 *              enabled within the Event Combiner.
 *
 * Returns:     None
 */
void Osal_EnableInterrupt(int32_t corepacEvent,int32_t interruptNum)
{
    ISRType ISRID = INVALID_ISR;
#ifdef _TMS320C6X
    CSL_Reg32    csrRegVal;
    if(interruptNum==OSAL_REGINT_INTVEC_EVENT_COMBINER) {
     /* If this is called from a module which uses event combiner */
     /* Just enable the event inside the event combiner and
      * not the whole interrupt as it will be used by the event dispatcher */
        (void)EventCombinerP_enableEvent((uint32_t)corepacEvent);
        /* Make sure GIE bit in CSR is set for interrupts */
        csrRegVal = CSL_chipReadCSR();
        if ((csrRegVal & CSL_CHIP_CSR_GIE_ENABLE) == 0U)  {
           csrRegVal |= CSL_CHIP_CSR_GIE_ENABLE;
           (void)CSL_chipWriteCSR(csrRegVal);
        }
    } else {
      /* This is not an event combiner based interrupt */
        HwiP_enableInterrupt(interruptNum);
    }
#else
    /* For non c66x cases, there is no event combiner , just invoke the HwiP */
    //HwiP_enableInterrupt(interruptNum);
    ISRID = Osal_Autosar_IntNum(interruptNum);
    if(ISRID != INVALID_ISR)
    {
        Os_EnableInterruptSource(ISRID, TRUE);
    }
#endif
}

/*
 * Purpose:     Disables an event/interrupt
 * Description: Disables the interrupt associated with an event number(0-127).
 *              In case of the event combiner, the corresponding event is
 *              disabled within the Event Combiner.
 *
 * Returns:     None
 */
void Osal_DisableInterrupt(int32_t corepacEvent,int32_t interruptNum)
{
    ISRType ISRID = INVALID_ISR;
#ifdef _TMS320C6X
    if(interruptNum==OSAL_REGINT_INTVEC_EVENT_COMBINER) {
     /* If this is called from a module which uses event combiner */
     /* Just enable the event inside the event combiner and
      * not the whole interrupt as it will be used by the event dispatcher */
        (void)EventCombinerP_disableEvent((uint32_t)corepacEvent);
    } else {
      /* This is not an event combiner based interrupt */
        HwiP_disableInterrupt(interruptNum);
    }
#else
    /* For non c66x cases, there is no event combiner , just invoke the HwiP */
    //HwiP_disableInterrupt(interruptNum);
    ISRID = Osal_Autosar_IntNum(interruptNum);
    if(ISRID != INVALID_ISR)
    {
        Os_DisableInterruptSource(ISRID);
    }
#endif
}

/*
 * Purpose:     Clears a pending interrupt
 * Description: Clears a pending interrupt associated with an event number(0-127).
 *
 * Returns:     None
 */
void Osal_ClearInterrupt(int32_t corepacEvent,int32_t interruptNum)
{
    ISRType ISRID = INVALID_ISR;
#ifdef _TMS320C6X
    if(interruptNum==OSAL_REGINT_INTVEC_EVENT_COMBINER) {
     /* If this is called from a module which uses event combiner,
      * Just clear the event inside the event combiner and
      * not the whole interrupt as it will be used by the event dispatcher */
        (void)EventCombinerP_clearEvent((uint32_t)corepacEvent);
    } else {
      /* This is not an event combiner based interrupt */
        HwiP_clearInterrupt(interruptNum);
    }
#else
    /* For non c66x cases, there is no event combiner , just clear the interruptNum's vector */
    //HwiP_clearInterrupt(interruptNum);
    ISRID = Osal_Autosar_IntNum(interruptNum);
    if(ISRID != INVALID_ISR)
    {
        Os_ClearPendingInterrupt(ISRID);
    }
#endif
}

static ISRType Osal_Autosar_IntNum(int32_t interruptNum)
{
    ISRType ISRID = INVALID_ISR;

    #ifdef BUILD_MCU1_0
    switch(interruptNum)
    {
	case CSLR_MCU_R5FSS0_CORE0_INTR_MCU_NAVSS0_INTR_ROUTER_0_OUTL_INTR_14:
		ISRID = MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_MCU_NAVSS0_INTR_ROUTER_0_OUTL_INTR_15:
		ISRID = MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_MCU_ESM0_ESM_INT_CFG_LVL_0:
		ISRID = MCU_ESM0_ESM_INT_CFG_LVL_0;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_MCU_ESM0_ESM_INT_HI_LVL_0:
		ISRID = MCU_ESM0_ESM_INT_HI_LVL_0;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_MCU_ESM0_ESM_INT_LOW_LVL_0:
		ISRID = MCU_ESM0_ESM_INT_LOW_LVL_0;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_WKUP_ESM0_ESM_INT_CFG_LVL_0:
		ISRID = WKUP_ESM0_ESM_INT_CFG_LVL_0;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_WKUP_ESM0_ESM_INT_HI_LVL_0:
		ISRID = WKUP_ESM0_ESM_INT_HI_LVL_0;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_WKUP_ESM0_ESM_INT_LOW_LVL_0:
		ISRID = WKUP_ESM0_ESM_INT_LOW_LVL_0;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_ESM0_ESM_INT_CFG_LVL_0:
		ISRID = MAIN_ESM0_ESM_INT_CFG_LVL_0;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_ESM0_ESM_INT_HI_LVL_0:
		ISRID = MAIN_ESM0_ESM_INT_HI_LVL_0;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_ESM0_ESM_INT_LOW_LVL_0:
		ISRID = MAIN_ESM0_ESM_INT_LOW_LVL_0;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304;
		break;

	case CSLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0:
		ISRID = SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305;
		break;
	default:
		ISRID = INVALID_ISR;
		break;
	}
    #else
    ISRID = INVALID_ISR;
    #endif

    return ISRID;
}

#ifdef __cplusplus
}
#endif
