/** @file osal.c 
 *  @brief  osal api Handler
 * 
 *  osal api Handler
 * 
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * 
 *  @author Anonymous Author (Anonymous.Author@magna.com)
 */



/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/osal/osal.h>

#include <ti/osal/HwiP.h>
#include <ti/csl/hw_types.h>

#include <ti/drv/sciclient/sciclient.h>
#include <soc.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include "fusa_osal_interface_nonos.h"
#if defined (BIST_SBL)
#include "sbl_log.h"
#elif defined (BIST_BOOT_APP)
#include "app_log.h"
#include "app_log_Boot.h"
#endif



/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* Test application stack size */

/**< Stack required for the stack */
/**< Task names */
/**< Task Priority Levels */



/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
SDL_OSAL_Interface freeRTOS_osal_interface =
{
    .enableInterrupt = (pSDL_OSAL_interruptFunction) FUSA_freeRTOS_enableInterrupt,
    .disableInterrupt = (pSDL_OSAL_interruptFunction) FUSA_freeRTOS_disableInterrupt,
    .registerInterrupt = (pSDL_OSAL_registerFunction) FUSA_freeRTOS_registerInterrupt,
    .deregisterInterrupt = (pSDL_OSAL_deregisterFunction) FUSA_freeRTOS_deregisterInterrupt,
    .globalDisableInterrupts = (pSDL_OSAL_globalDisableInterruptsFunction) FUSA_freeRTOS_globalDisableInterrupts,
    .globalRestoreInterrupts = (pSDL_OSAL_globalRestoreInterruptsFunction) FUSA_freeRTOS_globalRestoreInterrupts,
    .printFxn = (pSDL_OSAL_printFunction) FUSA_freeRTOS_applog_printf,
    .delay = (pSDL_OSAL_delayFunction) FUSA_freeRTOS_Osal_delay,
    .addrTranslate = (pSDL_OSAL_addrTranslateFunction) FUSA_freeRTOS_addrTranslate
};

/* ========================================================================== */
/*                            External Variables                              */
/* ========================================================================== */

/**< CAN IF Driver Status, defined in CanIf.c */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/* TimeStamp Provider structure */

static uintptr_t GTC_BASE_ADDR = 0;
static uint64_t mhzFreq = 0;

#define GET_GTC_VALUE64 (*(volatile uint64_t*)(GTC_BASE_ADDR + 0x8U))
#define GTC_TIMER_MAPPED_BASE       (0xa90000UL)
#define GTC_TIMER_MAPPED_SIZE       (512)
#define HZ_TO_MHZ (1000000)

int32_t FUSA_freeRTOS_GlobalTimeInit(void)
{
  /* DD-ID: {5D72C321-6F66-4b9e-86B2-71BFB70CFFB8}*/
    int32_t status = 0;
    uint64_t clkFreq;


    GTC_BASE_ADDR = (uintptr_t)GTC_TIMER_MAPPED_BASE;


    /* needs to be enabled only once, do it from R5F */
    #if 1//defined(R5F)
    /* Configure GTC Timer - running at 200MHz as per config and default mux mode */
    /* 200 MHz depends on 'MCU_PLL1' and is selected through 'GTCCLK_SEL' mux */
    /* Enable GTC */
    HW_WR_REG32(*(volatile uint32_t*)GTC_BASE_ADDR + 0x0U, 0x1);
    #endif

    if (0 == status)
    {
        status = Sciclient_pmGetModuleClkFreq(TISCI_DEV_GTC0,
                                           TISCI_DEV_GTC0_GTC_CLK,
                                           &clkFreq,
                                           SCICLIENT_SERVICE_WAIT_FOREVER);
    }

    if (0 == status)
    {
        mhzFreq = clkFreq / HZ_TO_MHZ;
    }

    return status;
}

/* Need to call FUSA_freeRTOS_GlobalTimeInit */
uint64_t FUSA_freeRTOS_GetGlobalTimeInUsec(void)
{
  /* DD-ID: {8D29095F-C075-461e-9D36-DC7F713EF935}*/
    uint64_t cur_ts = 0; /* Returning ts in usecs */

    #if 0
    if ((NULL != (void*)GTC_BASE_ADDR) &&
        (0 != mhzFreq) )
    {
        cur_ts = GET_GTC_VALUE64 / mhzFreq;
    }
    #else
    cur_ts = TimerP_getTimeInUsecs();
    #endif

    return cur_ts;
}


int32_t FUSA_freeRTOS_osalInit(void)
{
  /* DD-ID: {A37EDE54-3B4C-42bb-B21F-792A1F0F9830}*/
    SDL_ErrType_t ret = SDL_PASS;

    ret = SDL_OSAL_init(&freeRTOS_osal_interface);

    return ret;
}

int32_t FUSA_freeRTOS_enableInterrupt(int32_t intNum)
{
  /* DD-ID: {940A90EB-1C0D-4c96-AEB1-E93A661238ED}*/
    HwiP_enableInterrupt(intNum);
    return SDL_PASS;
}

int32_t FUSA_freeRTOS_disableInterrupt(int32_t intNum)
{
  /* DD-ID: {8E2C32B0-A360-42a4-91F6-79BA087488D3}*/
    HwiP_disableInterrupt(intNum);
    return SDL_PASS;
}

HwiP_Handle FUSA_freeRTOS_registerInterrupt(SDL_OSAL_hwipParams *pParams)
{
  /* DD-ID: {DB03856F-BDBF-46d6-BE79-B51BFFDA5F9B}*/
    HwiP_Params hwipParams;
    HwiP_Params_init(&hwipParams);

    hwipParams.arg = pParams->callbackArg;

    return HwiP_create(pParams->intNum, pParams->callback, &hwipParams);
}

int32_t FUSA_freeRTOS_deregisterInterrupt(pSDL_OSAL_hwipHandle handle)
{
  /* DD-ID: {567C64D9-3D5B-4fec-BA97-78DE14253667}*/
    SDL_ErrType_t ret = SDL_PASS;

    // Check HwiP function is valid
    if (handle == NULL_PTR)
    {
        ret = SDL_EINVALID_PARAMS;
    }
    else
    {
        ret = HwiP_delete(handle);
    }

    return ret;
}

int32_t FUSA_freeRTOS_globalDisableInterrupts(uintptr_t *key)
{
  /* DD-ID: {3CF3E1DE-9600-4ff4-9B69-77F016ABC36A}*/
    *key = HwiP_disable();
    return SDL_PASS;
}

int32_t FUSA_freeRTOS_globalRestoreInterrupts(uintptr_t key)
{
  /* DD-ID: {D895FBCE-4B67-4d08-8345-866A27D252AE}*/
    HwiP_restore(key);
    return SDL_PASS;
}

void FUSA_freeRTOS_applog_printf(const char* traceBuf, ...)
{
  /* DD-ID: {6FED3CDB-3E78-4e5a-9EB6-46C8B5DF3A61}*/
	SBL_log(SBL_LOG_MIN,traceBuf);
	return;
}

int32_t FUSA_freeRTOS_Osal_delay(int32_t ndelay)
{
  /* DD-ID: {D7CDBAE2-3245-4dc8-A142-DD95F9717A37}*/
    SDL_ErrType_t ret;

    ret = Osal_delay(ndelay);

    return ret;
}

#include <ti/csl/csl_rat.h>
#include "sdl_rat.h"
void* SDL_TEST_addrTranslate(uint64_t addr, uint32_t size);

void* FUSA_freeRTOS_addrTranslate(uint64_t addr, uint32_t size)
{
  /* DD-ID: {5FDF369B-63A5-4239-8AE5-294BCA24DC9A}*/
    void *ret = (void *)(-1);

    ret = FUSA_TEST_addrTranslate(addr, size);

    return ret;
}



#define PBIST_RAT_CFG_BASE SDL_MCU_R5FSS0_RAT_CFG_BASE
#define PBIST_RAT_REGION_INDEX            0

#if 0

/* Note that this example provide a single instance of mappedEccRegs (which is RAT-mapped
 * ECC aggregator configuration registers that lie in larger address space than the 32-bit
 * address space on the MCU.  If more ECC aggregator registers need to be mapped, additional
 * global variables are needed for each set of aggregator registers, and SDL_ECC_init() needs
 * to be modified to make SDL_ECC_mapEccAggrReg() calls for each one that needs to be mapped.
 * The expectation is that this mapping will be retained in perpetuity because in order to obtain
 * information about the ECC errors, the ECC Aggregator configuration registers require to be
 * visible from the MCU. */
__attribute((section(".my_aggr_reg"))) uint8_t mappedEccRegs[0x400];
__attribute((section(".my_aggr_reg1"))) uint8_t mappedEccRegs1[0x400];
__attribute((section(".my_aggr_reg2"))) uint8_t mappedEccRegs2[0x400];
__attribute((section(".my_aggr_reg3"))) uint8_t mappedEccRegs3[0x400];
__attribute((section(".my_aggr_reg4"))) uint8_t mappedEccRegs4[0x400];
__attribute((section(".my_aggr_reg5"))) uint8_t mappedEccRegs5[0x400];
__attribute((section(".my_aggr_reg6"))) uint8_t mappedEccRegs6[0x400];
__attribute((section(".my_aggr_reg7"))) uint8_t mappedEccRegs7[0x400];
__attribute((section(".my_aggr_reg8"))) uint8_t mappedEccRegs8[0x400];
__attribute((section(".my_aggr_reg9"))) uint8_t mappedEccRegs9[0x400];

#endif

void* FUSA_TEST_addrTranslate(uint64_t addr, uint32_t size)
{
  /* DD-ID: {1E4EC16D-AD20-4185-AF84-009B074737AB}*/
    void * ret = (void *)(-1);
    CSL_RatTranslationCfgInfo translationCfg;
    uint32_t transAddr = (uint32_t)(-1);
    uint32_t index = 0;
    bool result;
    uint32_t offset = 0;

    if ((addr == SDL_COMPUTE_CLUSTER0_MSMC_PBIST0_BASE) ||
        (addr == SDL_COMPUTE_CLUSTER0_MPU_PBIST0_BASE) ||
		(addr == SDL_COMPUTE_CLUSTER0_DSP0_PBIST_BASE) ||
		(addr == SDL_COMPUTE_CLUSTER0_DSP1_PBIST_BASE))
    {
        /* Disable RAT translation */
        result = CSL_ratDisableRegionTranslation((CSL_ratRegs *)PBIST_RAT_CFG_BASE,
                                                 PBIST_RAT_REGION_INDEX);
        transAddr = (uint32_t)0x60000000;
        index = PBIST_RAT_REGION_INDEX;
    }
    else
    {
#if 0
            /* Currently, below aggregators configuration registers can be
             * mapped by this code.  To expand to other aggregators, additional
             * instances of "mappedEccRegs" are needed and should be mapped to
             * those additional aggregators. */
            switch(addr)
            {
                case SDL_COMPUTE_CLUSTER0_MSMC_ECC_AGGR0_BASE:
                case SDL_COMPUTE_CLUSTER0_MSMC_ECC_AGGR1_BASE:
                case SDL_COMPUTE_CLUSTER0_MSMC_DDR_0_ECC_AGGR2_BASE:
                    transAddr = (uint32_t)mappedEccRegs2;
                    offset = (addr - SDL_COMPUTE_CLUSTER0_MSMC_ECC_AGGR0_BASE);
                    addr = SDL_COMPUTE_CLUSTER0_MSMC_ECC_AGGR0_BASE;
                    size = 0x1000;
                                        index = 2;
                    break;
                case SDL_COMPUTE_CLUSTER0_ECC_AGGR_BASE:
                    transAddr = (uint32_t)mappedEccRegs;
                                        index = 0;
                    break;
                case SDL_COMPUTE_CLUSTER0_MPU0_COREPAC_ECC_AGGR_BASE:
                case SDL_COMPUTE_CLUSTER0_MPU0_CORE0_ECC_AGGR_BASE:
                case SDL_COMPUTE_CLUSTER0_MPU0_CORE1_ECC_AGGR_BASE:
                    transAddr = (uint32_t)mappedEccRegs3;
                    offset = (addr - SDL_COMPUTE_CLUSTER0_MPU0_COREPAC_ECC_AGGR_BASE);
                    addr = SDL_COMPUTE_CLUSTER0_MPU0_COREPAC_ECC_AGGR_BASE;
                    size = 0x1000;
                                        index = 3;
                    break;
                case SDL_COMPUTE_CLUSTER0_DDR0_0_ECC_AGGR_CTL_BASE:
                case SDL_COMPUTE_CLUSTER0_DDR0_0_ECC_AGGR_CFG_BASE:
                case SDL_COMPUTE_CLUSTER0_DDR0_0_ECC_AGGR_VBUS_BASE:
                case SDL_COMPUTE_CLUSTER0_DDR1_1_ECC_AGGR_CTL_BASE:
                    transAddr = (uint32_t)mappedEccRegs4;
                    offset = (addr - SDL_COMPUTE_CLUSTER0_DDR0_0_ECC_AGGR_CTL_BASE);
                    addr = SDL_COMPUTE_CLUSTER0_DDR0_0_ECC_AGGR_CTL_BASE;
                    size = 0x1000;
                                        index = 4;
                    break;
                case SDL_COMPUTE_CLUSTER0_DDR1_1_ECC_AGGR_CFG_BASE:
                case SDL_COMPUTE_CLUSTER0_DDR1_1_ECC_AGGR_VBUS_BASE:
                    transAddr = (uint32_t)mappedEccRegs5;
                    offset = (addr - SDL_COMPUTE_CLUSTER0_DDR1_1_ECC_AGGR_VBUS_BASE);
                    addr = SDL_COMPUTE_CLUSTER0_DDR1_1_ECC_AGGR_VBUS_BASE;
                    size = 0x1000;
                                        index = 5;
                    break;
                case SDL_COMPUTE_CLUSTER0_MSMC_DDR_1_ECC_AGGR3_BASE:
                    transAddr = (uint32_t)mappedEccRegs6;
                                        index = 6;
                    break;
                case SDL_COMPUTE_CLUSTER0_DSP1_ECCAGGR_BASE:
                    transAddr = (uint32_t)mappedEccRegs7;
                                        index = 7;
                    break;
                case SDL_COMPUTE_CLUSTER0_DSP0_ECC_AGGR_BASE:
                    transAddr = (uint32_t)mappedEccRegs8;
                                        index = 8;
                    break;
                case SDL_MSRAM_512K0_RAM_BASE:
                case SDL_MSRAM_512K1_RAM_BASE:
                    transAddr = (uint32_t)mappedEccRegs9;
                                        index = 9;
                    break;
                default:
                    break;
            }
#endif
    }

    if (transAddr != (uint32_t)(-1))
    {
    	/* Add RAT configuration to access address > 32bit address range */
    	translationCfg.translatedAddress = addr;
    	translationCfg.sizeInBytes = size;
    	translationCfg.baseAddress = transAddr;

    	/* Set up RAT translation */
    	result = CSL_ratConfigRegionTranslation((CSL_ratRegs *)PBIST_RAT_CFG_BASE,
    			index, &translationCfg);
    	if (result == (bool)true ) {
    		ret = (void *)(transAddr + offset);
    	}
    	else {
    		FUSA_freeRTOS_applog_printf("\nFailed to configure the RAT index %d address 0x%x\n", index, addr);
    	}
    }
    else if (addr < 0x100000000)
    {
        ret = (void *)addr;
    }

    return ret;
}

/* Nothing Beyond this line */
