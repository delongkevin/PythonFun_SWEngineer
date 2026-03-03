/** @file vim.c
 *  @brief  VIM Application
 *
 *  Vectored Interrupt module (VIM) Application
 *
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 *
 *  @author Anonymous Author (Anonymous.Author@magna.com)
 */


/**
 * This file contains functions that initializes
 * for the Vectored Interrupt Module (VIM) application.
 *
 *  \details  VIM Safety module
 */
#include <stdio.h>
#include <string.h>

#include "PlatformDataTypes.h"
#include <sdl_types.h>
#include <sdl_vim.h>
#include <ti/csl/soc/j721s2/src/cslr_intr_mcu_r5fss0_core0.h>
#include "fusa_application.h"
#include "app_log.h"
#include "app_log_Boot.h"

#include "interrupt.h"

#include "vim.h"
#include "pmic.h"

#include "Os_TimerInt.h"
#include "Os_Hal_Cfg.h"
#include "Os_Hal_Interrupt_Lcfg.h"
#include "ErrorManagerSatellite.h"
#include "ErrorManagerShared.h"


/*------------------------- External Definitions -------------------------*/
#if 0
extern void Os_Isr_Core0_Interrupt_0(void);
extern void Os_Isr_Core0_Interrupt_2(void);
extern void Os_Isr_Core0_Interrupt_6(void);
extern void Os_Isr_Core0_Interrupt_7(void);
extern void Os_Isr_Core0_Interrupt_18(void);
/* Note: Not part of SW anymore */
/*extern void Os_Isr_Core0_Interrupt_23(void);*/
extern void Os_Isr_Core0_Interrupt_39(void);
extern void Os_Isr_Core0_Interrupt_44(void);
extern void Os_Isr_Core0_Interrupt_48(void);
extern void Os_Isr_Core0_Interrupt_49(void);
extern void Os_Isr_Core0_Interrupt_53(void);
extern void Os_Isr_Core0_Interrupt_70(void);
extern void Os_Isr_Core0_Interrupt_71(void);
extern void Os_Isr_Core0_Interrupt_72(void);
extern void Os_Isr_Core0_Interrupt_73(void);
extern void Os_Isr_Core0_Interrupt_78(void);
extern void Os_Isr_Core0_Interrupt_79(void);
extern void Os_Isr_Core0_Interrupt_96(void);
extern void Os_Isr_Core0_Interrupt_98(void);
extern void Os_Isr_Core0_Interrupt_99(void);
extern void Os_Isr_Core0_Interrupt_100(void);
extern void Os_Isr_Core0_Interrupt_140(void);
extern void Os_Isr_Core0_Interrupt_141(void);
extern void Os_Isr_Core0_Interrupt_142(void);
extern void Os_Isr_Core0_Interrupt_376(void);
extern void Os_Isr_Core0_Interrupt_377(void);
#endif
/*------------------------- Structure Definitions -------------------------*/
typedef struct Safety_arm_vim_cfg_tag {
    uint32_t intrNum;
    uint32_t pri;
    uint32_t intrMap;
    uint32_t intrType;
    uint32_t intrEnClr;
    uint32_t intrEnSet;
    /*uint32_t vecAddr;*/
} Safety_arm_vim_cfg __attribute__((__packed__));

/**
  * @brief This structure defines the static register groups identified for VIM
 *
 *
 */
typedef struct {
    volatile uint32_t PID;                       /** Revision Register */
    volatile uint32_t INFO;                      /** Info Register */
} Safety_vimStaticRegs;

/*------------------------- Macros & Defines -------------------------*/
#define SDL_MCU_ARMSS_VIM_NULL_ADDR           ((void *) 0 )
/* Commented -- Can be enabled in Future
* #define VIM_PRIV_VAL_0x0F                     (0x0F)
* #define VIM_PRIV_VAL_0x0B                     (0x0B)
* #define VIM_INTR_MAP_VAL_0                    (0x0)
*/
#define VIM_INTR_TYPE_VAL_0                   (0x0)
#define VIM_INTR_EN_VAL_1                     (0x1)

#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/*------------------------- const section -------------------------*/
static const Safety_arm_vim_cfg j721s2_vim_data_1_0[] = {
		/* MCAN0 */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_MCAN0_MCANSS_MCAN_LVL_INT_0,
				.pri = OS_ISR_CAN_30_MCANISR_0_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				/*.vecAddr = (uint32_t)&Os_Isr_Core0_Interrupt_0,*/
		},
		/* MCAN1 */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_MCAN1_MCANSS_MCAN_LVL_INT_0,
				.pri = OS_ISR_CAN_30_MCANISR_1_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				/*.vecAddr = (uint32_t)&Os_Isr_Core0_Interrupt_2,*/
		},
		/* ADC0 */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_ADC12FCC0_GEN_LEVEL_0,
				.pri = OS_ISR_ADC0_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				/*.vecAddr = (uint32_t)&Os_Isr_Core0_Interrupt_6,*/
		},
		/* ADC1 */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_ADC12FCC1_GEN_LEVEL_0,
				.pri = OS_ISR_ADC1_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				/*.vecAddr = (uint32_t)&Os_Isr_Core0_Interrupt_7,*/
		},
		/* System Timer */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_TIMER1_INTR_PEND_0,
				.pri = OS_ISR_COUNTERISR_SYSTEMTIMER_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				/*.vecAddr = (uint32_t)(uintptr_t)&Os_Isr_Core0_Interrupt_39,*/
		},
#if 0 /* ToDo: Enable once WDG Timer is integrated */
		/* WDG Timer */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_TIMER3_INTR_PEND_0,
				.pri = OS_ISR_OSISR_TIMER3_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				.vecAddr = (uint32_t)&Os_Isr_Core0_Interrupt_41,
		},
#endif
		/* I2C */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_WKUP_I2C0_POINTRPEND_0,
				.pri = OS_ISR_I2C_IRQUNIT0_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				/*.vecAddr = (uint32_t)&Os_Isr_Core0_Interrupt_96,*/
		},
		/* SDL_MAIN_ESM0_Cfg_Level */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_ESM0_ESM_INT_CFG_LVL_0,
				.pri = OS_ISR_MAIN_ESM0_ESM_INT_CFG_LVL_0_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				/*.vecAddr = (uint32_t)&Os_Isr_Core0_Interrupt_142,*/
		},
		/* SDL_MAIN_ESM0_High_Level */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_ESM0_ESM_INT_HI_LVL_0,
				.pri = OS_ISR_MAIN_ESM0_ESM_INT_HI_LVL_0_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				/*.vecAddr = (uint32_t)&Os_Isr_Core0_Interrupt_141,*/
		},
		/* SDL_MAIN_ESM0_Low_Level */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_ESM0_ESM_INT_LOW_LVL_0,
				.pri = OS_ISR_MAIN_ESM0_ESM_INT_LOW_LVL_0_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				/*.vecAddr = (uint32_t)&Os_Isr_Core0_Interrupt_140,*/
		},
		/* SDL_MCU_ESM0_Cfg_Level */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_ESM0_ESM_INT_CFG_LVL_0,
				.pri = OS_ISR_MCU_ESM0_ESM_INT_CFG_LVL_0_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				/*.vecAddr = (uint32_t)&Os_Isr_Core0_Interrupt_53,*/
		},
		/* SDL_MCU_ESM0_High_Level */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_ESM0_ESM_INT_HI_LVL_0,
				.pri = OS_ISR_MCU_ESM0_ESM_INT_HI_LVL_0_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				/*.vecAddr = (uint32_t)&Os_Isr_Core0_Interrupt_49,*/
		},
		/* SDL_MCU_ESM0_Low_Level */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_ESM0_ESM_INT_LOW_LVL_0,
				.pri = OS_ISR_MCU_ESM0_ESM_INT_LOW_LVL_0_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				/*.vecAddr = (uint32_t)&Os_Isr_Core0_Interrupt_48,*/
		},
		/* SDL_WKUP_ESM0_Cfg_Level */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_WKUP_ESM0_ESM_INT_CFG_LVL_0,
				.pri = OS_ISR_WKUP_ESM0_ESM_INT_CFG_LVL_0_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				/*.vecAddr = (uint32_t)&Os_Isr_Core0_Interrupt_100,*/
		},
		/* SDL_WKUP_ESM0_High_Level */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_WKUP_ESM0_ESM_INT_HI_LVL_0,
				.pri = OS_ISR_WKUP_ESM0_ESM_INT_HI_LVL_0_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				/*.vecAddr = (uint32_t)&Os_Isr_Core0_Interrupt_99,*/
		},
		/* SDL_WKUP_ESM0_Low_Level */
		{
				.intrNum = CSLR_MCU_R5FSS0_CORE0_INTR_WKUP_ESM0_ESM_INT_LOW_LVL_0,
				.pri = OS_ISR_WKUP_ESM0_ESM_INT_LOW_LVL_0_LEVEL,
				.intrMap = SDL_VIM_INTR_MAP_IRQ,
				.intrType = VIM_INTR_TYPE_VAL_0,
				.intrEnClr = VIM_INTR_EN_VAL_1,
				.intrEnSet = VIM_INTR_EN_VAL_1,
				/*.vecAddr = (uint32_t)&Os_Isr_Core0_Interrupt_98,*/
		}
};

static const Safety_vimStaticRegs j721s2_vim_static_data_1_0 = {
        .PID = 0x60900001,
        .INFO = 0x0200
};

/*------------------------- Global Variables -------------------------*/
static size_t j721s2_vim_safety_cnt = sizeof(j721s2_vim_data_1_0) / sizeof(j721s2_vim_data_1_0[0]);

#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*------------------------- Local Prototypes -------------------------*/

/**
 * @function name - Safety_VIM_VerifyStaticRegs
 * @param - Safety_vimStaticRegs *arm_vim_static_data
 * @return - int32_t
 * @description - Verify Static registers
 */
static int32_t Safety_VIM_VerifyStaticRegs( const Safety_vimStaticRegs *arm_vim_static_data)
{
  /* DD-ID:{5265D2D8-6880-46a9-B520-35A23A100E7E}*/
    int32_t  retVal = SDL_PASS;
    Safety_vimStaticRegs vimData;
    uint32_t tempPID;

    SDL_vimRegs *pRegs;
    pRegs = (SDL_vimRegs *)(uintptr_t)SDL_MCU_DOMAIN_VIM_BASE_ADDR;

    if ( pRegs == SDL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        /* No actions - API fails to read back */
        retVal = SDL_EFAIL;
    }

    if (retVal == SDL_PASS)
    {
        vimData.PID  = SDL_REG32_RD(&pRegs->PID);
        vimData.INFO = SDL_REG32_RD(&pRegs->INFO);
        retVal = SDL_PASS;
    }

    if (retVal != SDL_EFAIL)
    {
    	tempPID = arm_vim_static_data->PID;
        /* verify if parameter matches */
        if ((vimData.PID != tempPID) ||
            (vimData.INFO != (uint32_t)arm_vim_static_data->INFO))
        {
            retVal = SDL_EFAIL;
        }
    }

    return (retVal);
}

/**
 * @function name - Safety_VIM_verifyCfgIntr
 * @param - Safety_arm_vim_cfg * arm_vim_cfg_data
 * @return - int32_t
 * @description - Verify Interrupt config
 */
static int32_t Safety_VIM_verifyCfgIntr( const Safety_arm_vim_cfg *arm_vim_cfg_data)
{
  /* DD-ID:{060E370F-AD09-441b-B5A4-B1CC2F5E8E2A}*/
    int32_t  retVal = SDL_EFAIL;
    uint32_t bitNum, groupNum;
    uint32_t intrMapVal, intrTypeVal, priVal, intrEnSetVal, intrEnClrVal;
    uint32_t    maxIntrs = 0, num_groups = 0;

    SDL_vimRegs *pRegs;
    pRegs = (SDL_vimRegs *)(uintptr_t)SDL_MCU_DOMAIN_VIM_BASE_ADDR;

    if (pRegs != SDL_MCU_ARMSS_VIM_NULL_ADDR)
    {
        maxIntrs   = pRegs->INFO;
        num_groups = maxIntrs / SDL_VIM_NUM_INTRS_PER_GROUP;
        groupNum = arm_vim_cfg_data->intrNum / SDL_VIM_NUM_INTRS_PER_GROUP;

        /* Condition "(vecAddr - 1U)" is need for THUMB Mode as TI ARM CLANG marks LSB as '1' */
        if( (arm_vim_cfg_data->intrNum < maxIntrs)                              &&
            (arm_vim_cfg_data->pri <= SDL_VIM_PRI_INT_VAL_MAX)                  &&
            (arm_vim_cfg_data->intrMap <= SDL_VIM_INTR_MAP_FIQ)                 &&
            (arm_vim_cfg_data->intrType <= SDL_VIM_INTR_TYPE_PULSE))
        {
        	bitNum = arm_vim_cfg_data->intrNum & (SDL_VIM_NUM_INTRS_PER_GROUP-1U);

        	/* Read INTMAP */
        	intrMapVal  = SDL_REG32_RD( &pRegs->GRP[groupNum].INTMAP );
        	/* Get the interrupt map value */
        	intrMapVal  = intrMapVal >> bitNum;
        	intrMapVal &= (uint32_t)(0x1U);

        	/* Read INTTYPE */
        	intrTypeVal  = SDL_REG32_RD( &pRegs->GRP[groupNum].INTTYPE );
        	/* Get the interrupt type value */
        	intrTypeVal  = intrTypeVal >> bitNum;
        	intrTypeVal &= (uint32_t)(0x1U);

        	/* Read INTR_EN_SET */
        	intrEnSetVal  = SDL_REG32_RD( &pRegs->GRP[groupNum].INTR_EN_SET );
        	/* Get the interrupt En Set value */
        	intrEnSetVal  = intrEnSetVal >> bitNum;
        	intrEnSetVal &= (uint32_t)(0x1U);

        	/* Read INTR_EN_CLR */
        	intrEnClrVal  = SDL_REG32_RD( &pRegs->GRP[groupNum].INTR_EN_CLR );
        	/* Get the interrupt En Clear value */
        	intrEnClrVal  = intrEnClrVal >> bitNum;
        	intrEnClrVal &= (uint32_t)(0x1U);

        	/* Read PRI */
        	priVal = SDL_REG32_RD( &pRegs->PRI[arm_vim_cfg_data->intrNum].INT);

        	/* Read VEC */
        	/*vecVal = SDL_REG32_RD( &pRegs->VEC[arm_vim_cfg_data->intrNum].INT);*/
        	retVal = SDL_PASS;
        }
    }

    if (retVal != SDL_EFAIL)
    {
        /* verify if parameter matches */
        if ((intrMapVal != arm_vim_cfg_data->intrMap) ||
            (intrTypeVal != (uint32_t)arm_vim_cfg_data->intrType) ||
            (priVal != arm_vim_cfg_data->pri) ||
            (intrEnSetVal != arm_vim_cfg_data->intrEnSet) ||
            (intrEnClrVal != arm_vim_cfg_data->intrEnClr))
        {
        	retVal = SDL_EFAIL;
        }
    }

    return retVal;
}
/* vim_init: VIM initialization routine
*/
void vim_init(void)
{
  /* DD-ID: {B4D77C52-C84F-43d4-97B5-4B4CE99C2556}*/
    /* Req. -ID: 17462110 */
    /* MCU R5F */
    int32_t sdlRet;
    uint32_t  cnt;
    ldef_ErrorMgr_stAddData SDL_VimAddtionalData_au8 = {0u};

    /* Verify Configuration */
    for(cnt=0u; cnt < j721s2_vim_safety_cnt; cnt++)
    {
        sdlRet = Safety_VIM_verifyCfgIntr(&j721s2_vim_data_1_0[cnt]);
        if (sdlRet != SDL_PASS)
        {
        	/* MCU R5F */
        	(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_VIM_Register_Config_Mismatch,
                                                ldef_ErrorMgr_ErrorActive,
                                                (const ldef_ErrorMgr_stAddData *)&SDL_VimAddtionalData_au8);
    		/* Report error to CAN msg */
    		f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_VIM_Register_Config_Mismatch);
            /* Report any errors */
            #if defined (SDL_APP_VIM_UART_PRINTS_ENABLED)
        	APP_log(APP_LOG_ERR,"SDL_VIM_verifyCfgIntr: failure for VIM instance: Interrupt %d \n", j721s2_vim_data_1_0[cnt].intrNum);
            #endif
        }
    }

}

/* vim_MainFunction: Function to check VIM health.
*/
void vim_MainFunction(void)
{
  /* DD-ID: {AA213F38-D00C-4110-BB75-6B0837340D39}*/
    /* Req. -ID: 17462110 */
    /* Req. -ID: 17462112 */
    /* MCU R5F */
    int32_t  testResult = SDL_PASS;
    uint32_t cnt = 0u;
    ldef_ErrorMgr_stAddData SDL_VimAddtionalData_au8 = {0u};

    /* Verify Static registers */
    testResult = Safety_VIM_VerifyStaticRegs(&j721s2_vim_static_data_1_0);
    if (testResult != SDL_PASS)
    {
    	/* MCU R5F */
    	(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_VIM_Register_Config_Mismatch,
    			ldef_ErrorMgr_ErrorActive,
				(const ldef_ErrorMgr_stAddData *)&SDL_VimAddtionalData_au8);
    	/* Report error to CAN msg */
    	f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_VIM_Register_Config_Mismatch);
#if defined (SDL_APP_VIM_UART_PRINTS_ENABLED)
    	APP_log(APP_LOG_ERR,"SDL_VIM_getStaticRegisters: Read failure for VIM instance: Get Static Regs on line no. %d \n", __LINE__);
#endif
    }

    /* Verify Configuration */
    for(cnt=0; cnt < j721s2_vim_safety_cnt; cnt++)
    {
        testResult = Safety_VIM_verifyCfgIntr(&j721s2_vim_data_1_0[cnt]);
        if (testResult != SDL_PASS)
        {
            /* MCU R5F */
            (void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_VIM_Register_Config_Mismatch,
                                                ldef_ErrorMgr_ErrorActive,
                                                (const ldef_ErrorMgr_stAddData *)&SDL_VimAddtionalData_au8);
    		/* Report error to CAN msg */
    		f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_VIM_Register_Config_Mismatch);
            /* Report any errors */
            #if defined (SDL_APP_VIM_UART_PRINTS_ENABLED)
        	APP_log(APP_LOG_ERR,"SDL_VIM_verifyCfgIntr: failure for VIM instance: Interrupt %d \n", j721s2_vim_data_1_0[cnt].intrNum);
            #endif
        }
    }

}

#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
