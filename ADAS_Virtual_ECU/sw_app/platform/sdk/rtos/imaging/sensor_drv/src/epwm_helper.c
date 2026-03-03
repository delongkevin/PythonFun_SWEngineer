#include <iss_sensor_priv.h>
#include "epwm_helper.h"

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief IP default configuration */
static CSL_EpwmAppPwmObj_t gAppPwmObj =
{
    false,
    EHRPWM_DUTY_CYCLE,                      /* dutyCycle  */
    EHRPWM_OUTPUT_CH,                       /* pwmCh */
    EHRPWM_INST_BASE_ADDR,                  /* instAddr */
    0,                                          /* funcClk */
    /* CSL_EpwmAppPwmCfg_t*/
    {
        /* CSL_EpwmTimebaseCfg_t */
        {
            0,                                  /* tbClk */
            DEFAULT_OUT_FRQ,                /* pwmtbCounterFreqPrd */
            CSL_EPWM_TB_COUNTER_DIR_UP_DOWN,    /* tbCntrDirection */
            FALSE,                              /* enableSynchronization */
            PWMSS_EPWM_TBCTL_PHSDIR_COUNT_DOWN, /* cntDirAfterSync */
            0U,                                 /* phsCountAfterSync */
            PWMSS_EPWM_TBCTL_SYNCOSEL_EPWMXSYNC /* syncOutSrc */
        },
        /* CSL_EpwmCounterCmpCfg_t */
        {
            0,                                  /* cmpAValue */
            0                                   /* cmpBValue */
        },
        /* CSL_EpwmAqActionCfg_t */
        {
            CSL_EPWM_AQ_ACTION_DONOTHING,       /* zeroAction */
            CSL_EPWM_AQ_ACTION_DONOTHING,       /* prdAction */
            CSL_EPWM_AQ_ACTION_HIGH,            /* cmpAUpAction */
            CSL_EPWM_AQ_ACTION_LOW,             /* cmpADownAction */
            CSL_EPWM_AQ_ACTION_HIGH,            /* cmpBUpAction */
            CSL_EPWM_AQ_ACTION_LOW              /* cmpBDownAction */
        },
    }
};

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

static void EPwmAppGetPwmFuncClock(CSL_EpwmAppPwmObj_t *pObj);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
static void EPwmAppGetPwmFuncClock(CSL_EpwmAppPwmObj_t *pObj)
{
    uint32_t prdVal;

    /* Update object based on ePWM module frequency */
    pObj->funcClk = EHRPWM_FCLK;
    pObj->pwmCfg.tbCfg.tbClk = pObj->funcClk / EHRPWM_PREDIV;
    /* NOTE: /2 is added because up&down counter is selected. So period is 2 times */
    prdVal = (pObj->pwmCfg.tbCfg.tbClk / pObj->pwmCfg.tbCfg.pwmtbCounterFreqPrd) / 2;
    pObj->pwmCfg.ccCfg.cmpAValue = prdVal - ((pObj->dutyCycle * prdVal) / 100U);
    pObj->pwmCfg.ccCfg.cmpBValue = pObj->pwmCfg.ccCfg.cmpAValue;
}

/* Enable ePWM time base clock */
static void EpwmAppTbClockEnable(bool enable)
{
    uint32_t regVal;

    CSL_main_ctrl_mmr_cfg0Regs *pMainCtrlMmrCfg0Regs;

    pMainCtrlMmrCfg0Regs = (CSL_main_ctrl_mmr_cfg0Regs *)CSL_CTRL_MMR0_CFG0_BASE;

    regVal = CSL_REG32_RD(&pMainCtrlMmrCfg0Regs->LOCK1_KICK0);
    if (!(regVal & 0x1))
    {
        /* Unlock CTLR_MMR0 registers */
        CSL_REG32_WR(&pMainCtrlMmrCfg0Regs->LOCK1_KICK0, MMR_KICK0_UNLOCK_VAL);
        CSL_REG32_WR(&pMainCtrlMmrCfg0Regs->LOCK1_KICK1, MMR_KICK1_UNLOCK_VAL);
        do {
            regVal = CSL_REG32_RD(&pMainCtrlMmrCfg0Regs->LOCK1_KICK0);
        } while (!(regVal & 0x1));
    }

    /* 0x4140 */
    CSL_REG32_FINS(&pMainCtrlMmrCfg0Regs->EPWM1_CTRL,
                  MAIN_CTRL_MMR_CFG0_EPWM1_CTRL_TB_CLKEN, enable ? 1U: 0U);
}

int epwm_apply()
{
    CSL_EpwmAppPwmObj_t *pObj = &gAppPwmObj;
    uint32_t baseAddr = pObj->instAddr;
    CSL_EpwmAppPwmCfg_t *pPwmCfg = &pObj->pwmCfg;
    CSL_EpwmTimebaseCfg_t *pTbCfg = &pPwmCfg->tbCfg;
    CSL_EpwmCounterCmpCfg_t *pCcCfg = &pPwmCfg->ccCfg;

    if (false == pObj->initialized)
        return -1;

    EPwmAppGetPwmFuncClock(pObj);

    /*
     * Time base Sub-Module
     * */

    /* Configure Time base clock */
    CSL_epwmTbTimebaseClkCfg(baseAddr, pTbCfg->tbClk, pObj->funcClk);

    /* Configure PWM time base counter frequency and direction */
    CSL_epwmTbPwmFreqCfg(
        baseAddr,
        pTbCfg->tbClk,
        pTbCfg->pwmtbCounterFreqPrd,
        pTbCfg->tbCntrDirection,
        CSL_EPWM_SHADOW_REG_CTRL_ENABLE);

    /* Disable Synchronization */
    CSL_epwmTbSyncDisable(baseAddr);

    /* Configure Sync out signal */
    CSL_epwmTbSetSyncOutMode(baseAddr, pTbCfg->syncOutSrc);

    /* Configure the emulation behaviour */
    CSL_epwmTbSetEmulationMode(baseAddr, EPWM_TB_EMU_MODE_FREE_RUN);

    /*
     * Counter-Comparator Sub-Module Configuration
     */

    /* Counter Comparator A configuration */
    CSL_epwmCounterComparatorCfg(
        baseAddr,
        CSL_EPWM_CC_CMP_A,
        pCcCfg->cmpAValue,
        CSL_EPWM_SHADOW_REG_CTRL_ENABLE,
        CSL_EPWM_CC_CMP_LOAD_MODE_CNT_EQ_ZERO,
        TRUE);

    /* Counter Comparator B configuration */
    CSL_epwmCounterComparatorCfg(
        baseAddr,
        CSL_EPWM_CC_CMP_B,
        pCcCfg->cmpBValue,
        CSL_EPWM_SHADOW_REG_CTRL_ENABLE,
        CSL_EPWM_CC_CMP_LOAD_MODE_CNT_EQ_ZERO,
        TRUE);

    return 0;
}

int epwm_set_fps(uint8_t fps)
{
    CSL_EpwmAppPwmObj_t *pObj = &gAppPwmObj;
    pObj->pwmCfg.tbCfg.pwmtbCounterFreqPrd = fps;

    return epwm_apply();
}

uint8_t epwm_get_fps()
{
    CSL_EpwmAppPwmObj_t *pObj = &gAppPwmObj;

    if (false == pObj->initialized)
        return 0;

    return pObj->pwmCfg.tbCfg.pwmtbCounterFreqPrd;
}

int epwm_set_duty(uint8_t duty)
{
    CSL_EpwmAppPwmObj_t *pObj = &gAppPwmObj;
    pObj->dutyCycle = duty;

    return epwm_apply();
}

uint8_t epwm_get_duty()
{
    CSL_EpwmAppPwmObj_t *pObj = &gAppPwmObj;

    if (false == pObj->initialized)
        return 0;

    return pObj->dutyCycle;
}

void epwm_init(uint8_t fps)
{
    CSL_EpwmAppPwmObj_t *pObj = &gAppPwmObj;
    uint32_t baseAddr = pObj->instAddr;
    uint32_t pwmCh    = pObj->pwmCh;
    CSL_EpwmAppPwmCfg_t *pPwmCfg = &pObj->pwmCfg;

    EpwmAppTbClockEnable(true);
    pObj->initialized = true;

    epwm_set_fps(fps);

    /* Configure Action Qualifier */
    CSL_epwmAqActionOnOutputCfg(baseAddr, pwmCh, &pPwmCfg->aqCfg);
    /* CSL_epwmAqActionOnOutputCfg(baseAddr, CSL_EPWM_OUTPUT_CH_A, &pPwmCfg->aqCfg); */

    /* Bypass dead band sub module */
    CSL_epwmDeadbandBypass(baseAddr);

    /* Disable Chopper */
    CSL_epwmChopperEnable(baseAddr, FALSE);

    /* Disable trip zone event handling and ignore all trip zone events */
    CSL_epwmTzTripEventDisable(baseAddr, CSL_EPWM_TZ_EVENT_ONE_SHOT, 0);
    CSL_epwmTzTripEventDisable(baseAddr, CSL_EPWM_TZ_EVENT_CYCLE_BY_CYCLE, 0);

    /* Disable Event trigger interrupts */
    CSL_epwmEtIntrDisable(baseAddr);
}

void epwm_deinit()
{
    CSL_EpwmAppPwmObj_t *pObj = &gAppPwmObj;

    EpwmAppTbClockEnable(false);
    pObj->initialized = false;
}
