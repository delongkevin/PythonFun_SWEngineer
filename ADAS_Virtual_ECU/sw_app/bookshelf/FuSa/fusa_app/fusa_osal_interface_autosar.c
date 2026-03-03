/** @file fusa_osal_interface_autosar.c 
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
 *  @author Matt Kloepfer (Matt.Kloepfer@magna.com)
 */



/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <ti/osal/osal.h>
#include <ti/osal/HwiP.h>
#include <ti/drv/sciclient/sciclient.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/src/ip/rat/V0/csl_rat.h>
#include <soc.h>
#include "app_log.h"
#include "app_log_Boot.h"
#include "fusa_osal_interface_autosar.h"
#include "fusa_application.h"
#include "Os.h"


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
static int32_t FUSA_autosar_enableInterrupt(int32_t intNum);
static int32_t FUSA_autosar_disableInterrupt(int32_t intNum);
static HwiP_Handle FUSA_autosar_registerInterrupt(SDL_OSAL_hwipParams *pParams);
static int32_t FUSA_autosar_deregisterInterrupt(pSDL_OSAL_hwipHandle handle);
static int32_t FUSA_autosar_globalDisableInterrupts(uintptr_t *key);
static int32_t FUSA_autosar_globalRestoreInterrupts(uintptr_t key);
static void FUSA_autosar_applog_printf(const char* traceBuf);
static int32_t FUSA_autosar_Osal_delay(int32_t ndelay);
static void* FUSA_autosar_addrTranslate(uint64_t addr, uint32_t size);
static void* FUSA_TEST_addrTranslate(uint64_t addr, uint32_t size);


#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
static SDL_OSAL_Interface autosar_osal_interface =
{
    .enableInterrupt = (pSDL_OSAL_interruptFunction) FUSA_autosar_enableInterrupt,
    .disableInterrupt = (pSDL_OSAL_interruptFunction) FUSA_autosar_disableInterrupt,
    .registerInterrupt = (pSDL_OSAL_registerFunction) FUSA_autosar_registerInterrupt,
    .deregisterInterrupt = (pSDL_OSAL_deregisterFunction) FUSA_autosar_deregisterInterrupt,
    .globalDisableInterrupts = (pSDL_OSAL_globalDisableInterruptsFunction) FUSA_autosar_globalDisableInterrupts,
    .globalRestoreInterrupts = (pSDL_OSAL_globalRestoreInterruptsFunction) FUSA_autosar_globalRestoreInterrupts,
    .printFxn = (pSDL_OSAL_printFunction) FUSA_autosar_applog_printf,
    .delay = (pSDL_OSAL_delayFunction) FUSA_autosar_Osal_delay,
    .addrTranslate = (pSDL_OSAL_addrTranslateFunction) FUSA_autosar_addrTranslate
};

static uintptr_t GTC_BASE_ADDR = 0;
static uint64_t mhzFreq = 0;

#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

#define GET_GTC_VALUE64 (*(volatile uint64_t*)(GTC_BASE_ADDR + 0x8U))
#define GTC_TIMER_MAPPED_BASE       (0xa90000UL)
/* Commented -- Can be enabled in Future
* #define GTC_TIMER_MAPPED_SIZE       (512)
*/
#define HZ_TO_MHZ (1000000)


#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
int32_t FUSA_autosar_GlobalTimeInit(void)
{
  /* DD-ID: {CBA7345E-F58D-4205-ADFD-DBBFA03B4502}*/
    int32_t status = 0;
    uint64_t clkFreq;


    GTC_BASE_ADDR = (uintptr_t)GTC_TIMER_MAPPED_BASE;


    /* needs to be enabled only once, do it from R5F */
    /* Configure GTC Timer - running at 200MHz as per config and default mux mode */
    /* 200 MHz depends on 'MCU_PLL1' and is selected through 'GTCCLK_SEL' mux */
    /* Enable GTC */
    HW_WR_REG32(*(volatile uint32_t*)GTC_BASE_ADDR + 0x0U, 0x1);

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

/* Need to call FUSA_autosar_GlobalTimeInit */
uint64_t FUSA_autosar_GetGlobalTimeInUsec(void)
{
  /* DD-ID: {F437E5E4-3510-4da8-A9CC-172FF9414EDF}*/
    uint64_t cur_ts = 0; /* Returning ts in usecs */

    if ((0UL != GTC_BASE_ADDR) &&
        (0UL != mhzFreq) )
    {
        cur_ts = GET_GTC_VALUE64 / mhzFreq;
    }

    return cur_ts;
}


int32_t FUSA_autosar_osalInit(void)
{
  /* DD-ID: {99E8F0FD-A5F4-4fde-9D49-2A2758EF81C3}*/
    SDL_ErrType_t ret = SDL_PASS;

    ret = SDL_OSAL_init(&autosar_osal_interface);

    return ret;
}

static int32_t FUSA_autosar_enableInterrupt(int32_t intNum)
{
  /* DD-ID: {93C4B883-CF86-411f-9E6A-121F06FE558E}*/
    SDL_ErrType_t ret = SDL_PASS;

    Osal_EnableInterrupt((int32_t)0, intNum);

    return ret;
}

static int32_t FUSA_autosar_disableInterrupt(int32_t intNum)
{
  /* DD-ID: {8C763A3A-7F65-4f20-BB90-4BB4917C8BBB}*/
    SDL_ErrType_t ret = SDL_PASS;

    Osal_DisableInterrupt((int32_t)0, intNum);

    return ret;
}

static HwiP_Handle FUSA_autosar_registerInterrupt(SDL_OSAL_hwipParams *pParams)
{
  /* DD-ID: {748C8344-1F84-449d-8401-C774350AE9E9}*/
    pSDL_OSAL_hwipHandle hwiHandle;
    OsalRegisterIntrParams_t    intrPrms;
    OsalInterruptRetCode_e      osalRetVal;

    /* Check HwiP function is valid*/
    if (pParams == NULL_PTR)
    {
        hwiHandle = NULL_PTR;
    }
    else
    {

        Osal_RegisterInterrupt_initParams(&intrPrms);
        intrPrms.corepacConfig.arg          = pParams->callbackArg;
        intrPrms.corepacConfig.isrRoutine   = pParams->callback;
        intrPrms.corepacConfig.intVecNum    = pParams->intNum;

        osalRetVal = Osal_RegisterInterrupt(&intrPrms, &hwiHandle);
        if(OSAL_INT_SUCCESS != osalRetVal)
        {
            hwiHandle = NULL_PTR;
        }
    }

    return hwiHandle;
}

static int32_t FUSA_autosar_deregisterInterrupt(pSDL_OSAL_hwipHandle handle)
{
  /* DD-ID: {A7804291-1993-4eb2-A754-5069AA3F1F56}*/
    SDL_ErrType_t ret = SDL_PASS;

    /* Check HwiP function is valid */
    if (handle == NULL_PTR)
    {
        ret = SDL_EINVALID_PARAMS;
    }
    else
    {
        ret = Osal_DeleteInterrupt(handle, (int32_t)0);
    }

    return ret;
}

static int32_t FUSA_autosar_globalDisableInterrupts(uintptr_t *key)
{
  /* DD-ID: {68DDC14C-034D-48c2-908E-ED4D646F0B57}*/
    SDL_ErrType_t ret = SDL_PASS;

    if (key == NULL_PTR)
    {
        ret = SDL_EINVALID_PARAMS;
    }
    else
    {
        SuspendOSInterrupts();
    }

    return ret;
}

static int32_t FUSA_autosar_globalRestoreInterrupts(uintptr_t key)
{
  /* DD-ID: {D2EAAADA-2327-457f-B621-90F887961D37}*/
    SDL_ErrType_t ret = SDL_PASS;
   (void)key;
    ResumeOSInterrupts();

    return ret;
}

static void FUSA_autosar_applog_printf(const char* traceBuf)
{
  /* DD-ID: {BD40DF1E-22D1-48e9-B3B4-703DF6198FB7}*/
	(void)traceBuf;
    /*appLogPrintf(traceBuf);*/
	return;
}

static int32_t FUSA_autosar_Osal_delay(int32_t ndelay)
{
  /* DD-ID: {D26F979A-8645-4d98-909E-1130B63A64D8}*/
    SDL_ErrType_t ret;

    ret = Osal_delay((uint32_t)ndelay);

    return ret;
}

static void* FUSA_autosar_addrTranslate(uint64_t addr, uint32_t size)
{
  /* DD-ID: {E917608D-7421-4d20-A111-9B85DF97C5B5}*/
    void *ret;

     ret = FUSA_TEST_addrTranslate(addr, size);

    return ret;
}


#define PBIST_RAT_CFG_BASE SDL_MCU_R5FSS0_RAT_CFG_BASE
#define PBIST_RAT_REGION_INDEX            0

/* Note that this example provide a single instance of mappedEccRegs (which is RAT-mapped
 * ECC aggregator configuration registers that lie in larger address space than the 32-bit
 * address space on the MCU.  If more ECC aggregator registers need to be mapped, additional
 * global variables are needed for each set of aggregator registers, and SDL_ECC_init() needs
 * to be modified to make SDL_ECC_mapEccAggrReg() calls for each one that needs to be mapped.
 * The expectation is that this mapping will be retained in perpetuity because in order to obtain
 * information about the ECC errors, the ECC Aggregator configuration registers require to be
 * visible from the MCU. */
__attribute((section(".my_aggr_reg"))) static uint8_t mappedEccRegs[0x400];
/* Unsed var: __attribute((section(".my_aggr_reg1"))) static uint8_t mappedEccRegs1[0x400]*/
__attribute((section(".my_aggr_reg2"))) static uint8_t mappedEccRegs2[0x1000];
__attribute((section(".my_aggr_reg3"))) static uint8_t mappedEccRegs3[0x1000];
__attribute((section(".my_aggr_reg4"))) static uint8_t mappedEccRegs4[0x1000];
__attribute((section(".my_aggr_reg5"))) static uint8_t mappedEccRegs5[0x1000];
__attribute((section(".my_aggr_reg6"))) static uint8_t mappedEccRegs6[0x400];
__attribute((section(".my_aggr_reg7"))) static uint8_t mappedEccRegs7[0x400];
__attribute((section(".my_aggr_reg8"))) static uint8_t mappedEccRegs8[0x400];
__attribute((section(".my_aggr_reg9"))) static uint8_t mappedEccRegs9[0x400];

static void* FUSA_TEST_addrTranslate(uint64_t addr, uint32_t size)
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
                    offset = (uint32_t)(addr - SDL_COMPUTE_CLUSTER0_MSMC_ECC_AGGR0_BASE);
                    addr = SDL_COMPUTE_CLUSTER0_MSMC_ECC_AGGR0_BASE;
                    size = 0x1000;
                    index = 2;
#ifdef 	Enable_Printf
                    APP_log(APP_LOG_MAX,"\nConfigure the RAT index %d address 0x%x transAddr 0x%x offset 0x%x size 0x%x\n", index, addr,transAddr, offset, size);
#endif
                    break;

                case SDL_COMPUTE_CLUSTER0_ECC_AGGR_BASE:
                	transAddr = (uint32_t)mappedEccRegs;
                	index = 0;
#ifdef 	Enable_Printf
                	APP_log(APP_LOG_MAX,"\nConfigure the RAT index %d address 0x%x transAddr 0x%x offset 0x%x size 0x%x\n", index, addr,transAddr, offset, size);
#endif
                	break;

                case SDL_COMPUTE_CLUSTER0_MPU0_COREPAC_ECC_AGGR_BASE:
                case SDL_COMPUTE_CLUSTER0_MPU0_CORE0_ECC_AGGR_BASE:
                case SDL_COMPUTE_CLUSTER0_MPU0_CORE1_ECC_AGGR_BASE:
                	transAddr = (uint32_t)mappedEccRegs3;
                	offset = (uint32_t)(addr - SDL_COMPUTE_CLUSTER0_MPU0_COREPAC_ECC_AGGR_BASE);
                	addr = SDL_COMPUTE_CLUSTER0_MPU0_COREPAC_ECC_AGGR_BASE;
                	size = 0x1000;
                	index = 3;
#ifdef 	Enable_Printf
                	APP_log(APP_LOG_MAX,"\nConfigure the RAT index %d address 0x%x transAddr 0x%x offset 0x%x size 0x%x\n", index, addr,transAddr, offset, size);
#endif
                	break;

                case SDL_COMPUTE_CLUSTER0_DDR0_0_ECC_AGGR_CTL_BASE:
                case SDL_COMPUTE_CLUSTER0_DDR0_0_ECC_AGGR_CFG_BASE:
                case SDL_COMPUTE_CLUSTER0_DDR0_0_ECC_AGGR_VBUS_BASE:
                case SDL_COMPUTE_CLUSTER0_DDR1_1_ECC_AGGR_CTL_BASE:
                	transAddr = (uint32_t)mappedEccRegs4;
                	offset = (uint32_t)(addr - SDL_COMPUTE_CLUSTER0_DDR0_0_ECC_AGGR_CTL_BASE);
                	addr = SDL_COMPUTE_CLUSTER0_DDR0_0_ECC_AGGR_CTL_BASE;
                	size = 0x1000;
                	index = 4;
#ifdef 	Enable_Printf
                	APP_log(APP_LOG_MAX,"\nConfigure the RAT index %d address 0x%x transAddr 0x%x offset 0x%x size 0x%x\n", index, addr,transAddr, offset, size);
#endif                	
                	break;

                case SDL_COMPUTE_CLUSTER0_DDR1_1_ECC_AGGR_CFG_BASE:
                case SDL_COMPUTE_CLUSTER0_DDR1_1_ECC_AGGR_VBUS_BASE:
                	transAddr = (uint32_t)mappedEccRegs5;
                	offset = (uint32_t)(addr - SDL_COMPUTE_CLUSTER0_DDR1_1_ECC_AGGR_VBUS_BASE);
                	addr = SDL_COMPUTE_CLUSTER0_DDR1_1_ECC_AGGR_VBUS_BASE;
                	size = 0x1000;
                	index = 5;
#ifdef 	Enable_Printf
                	APP_log(APP_LOG_MAX,"\nConfigure the RAT index %d address 0x%x transAddr 0x%x offset 0x%x size 0x%x\n", index, addr,transAddr, offset, size);
#endif
                	break;

                case SDL_COMPUTE_CLUSTER0_MSMC_DDR_1_ECC_AGGR3_BASE:
                	transAddr = (uint32_t)mappedEccRegs6;
                	index = 6;
#ifdef 	Enable_Printf
                	APP_log(APP_LOG_MAX,"\nConfigure the RAT index %d address 0x%x transAddr 0x%x offset 0x%x size 0x%x\n", index, addr,transAddr, offset, size);
#endif
                	break;

                case SDL_COMPUTE_CLUSTER0_DSP1_ECCAGGR_BASE:
                	transAddr = (uint32_t)mappedEccRegs7;
                	index = 7;
#ifdef 	Enable_Printf
                	APP_log(APP_LOG_MAX,"\nConfigure the RAT index %d address 0x%x transAddr 0x%x offset 0x%x size 0x%x\n", index, addr,transAddr, offset, size);
#endif
                	break;

                case SDL_COMPUTE_CLUSTER0_DSP0_ECC_AGGR_BASE:
                	transAddr = (uint32_t)mappedEccRegs8;
                	index = 8;
#ifdef 	Enable_Printf
                	APP_log(APP_LOG_MAX,"\nConfigure the RAT index %d address 0x%x transAddr 0x%x offset 0x%x size 0x%x\n", index, addr,transAddr, offset, size);
#endif
                	break;

                case SDL_MSRAM_512K0_RAM_BASE:
                case SDL_MSRAM_512K1_RAM_BASE:
                	transAddr = (uint32_t)mappedEccRegs9;
                	index = 9;
#ifdef 	Enable_Printf
                	APP_log(APP_LOG_MAX,"\nConfigure the RAT index %d address 0x%x transAddr 0x%x offset 0x%x size 0x%x\n", index, addr,transAddr, offset, size);
#endif
                    break;
                default:
                    /* Do nothing */
                    break;
            }
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
#ifdef 	Enable_Printf
            APP_log(APP_LOG_ERR,"\nFailed to configure the RAT index %d address 0x%x\n", index, addr);
#endif
	}
    }
    else if (addr < 0x100000000UL)
    {
        ret = (void *)addr;
    }
    else{
        /* Do nothing */
    }
 

    return ret;
}

/* Nothing Beyond this line */
#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
