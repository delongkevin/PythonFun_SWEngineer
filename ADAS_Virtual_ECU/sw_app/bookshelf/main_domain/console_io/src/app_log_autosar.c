#include "app_log_priv.h"
#include <string.h>
#include <ti/drv/sciclient/sciclient.h>
#include "app_global_timer_priv.h"
#include "Os.h"

static uintptr_t GTC_BASE_ADDR = 0;
static uint64_t mhzFreq = 0;

#define GET_GTC_VALUE64 (*(volatile uint64_t*)(GTC_BASE_ADDR + 0x8U))

int32_t appLogWrCreateLock(app_log_wr_obj_t *obj)
{
    int32_t ret = 0;
    /* No implementation as autosar OS will use
       suspend/resume for critical section implementation*/
    return ret;
}

uintptr_t appLogWrLock(app_log_wr_obj_t *obj)
{
  SuspendAllInterrupts();

  return (uintptr_t)NULL;
}

void appLogWrUnLock(app_log_wr_obj_t *obj, uintptr_t key)
{
  ResumeAllInterrupts();
}

uint64_t appLogGetGlobalTimeInUsec()
{
    uint64_t cur_ts = 0; /* Returning ts in usecs */

    if (((uintptr_t)NULL != GTC_BASE_ADDR) &&
        (0 != mhzFreq) )
    {
        cur_ts = GET_GTC_VALUE64 / mhzFreq;
    }

    return cur_ts;
}

uint64_t appLogGetLocalTimeInUsec()
{
  uint64_t ret = 0;
    /* No implementation for autosar*/
  return ret;
}

uint64_t appLogGetTimeInUsec()
{
    #ifdef APP_LOG_USE_GLOBAL_TIME
    return appLogGetGlobalTimeInUsec();
    #else
    return appLogGetLocalTimeInUsec();
    #endif
}

int32_t appLogGlobalTimeInit()
{
    int32_t status = 0;
    uint64_t clkFreq;

    #ifdef C66
    GTC_BASE_ADDR = (uintptr_t)GTC_TIMER_MAPPED_BASE_C66;
    #else
    GTC_BASE_ADDR = (uintptr_t)GTC_TIMER_MAPPED_BASE;
    #endif

    #ifdef C66
    CSL_RatTranslationCfgInfo translationCfg;
    CSL_ratRegs *pGTCRatRegs = (CSL_ratRegs *)(CSL_C66_COREPAC_C66_RATCFG_BASE);

    translationCfg.sizeInBytes = GTC_TIMER_MAPPED_SIZE;
    translationCfg.baseAddress = GTC_BASE_ADDR;
    translationCfg.translatedAddress = CSL_GTC0_GTC_CFG1_BASE;

    CSL_ratConfigRegionTranslation(pGTCRatRegs, 1, &translationCfg);
    #endif

    /* needs to be enabled only once, do it from R5F */
    #if defined(R5F)
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
        mhzFreq = clkFreq / APP_LOG_HZ_TO_MHZ;
    }

    return status;
}

int32_t appLogGlobalTimeDeInit()
{
    return 0;
}

void appLogWaitMsecs(uint32_t time_in_msecs)
{
  /* No implementation for autosar cores */
}

int32_t   appLogRdCreateTask(app_log_rd_obj_t *obj, app_log_init_prm_t *prm)
{
    int32_t status = 0;

    /* reader is not supported by cores running autosar */

    return status;
}

void *appMemMap(void *phys_ptr, uint32_t size)
{
    return phys_ptr; /* phys == virtual in sysbios */
}

int32_t appMemUnMap(void *virt_ptr, uint32_t size)
{
    return 0; /* nothing to do in sysbios */
}
