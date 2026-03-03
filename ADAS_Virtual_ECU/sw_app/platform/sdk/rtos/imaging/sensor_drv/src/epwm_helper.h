#ifndef _EPWM_HELPER_H_
#define _EPWM_HELPER_H_

#include <ti/csl/csl_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/csl_epwm.h>
#include <ti/drv/sciclient/sciclient.h>
#include <ti/drv/sciclient/include/sciclient_pm.h>
#include <ti/drv/sciclient/sciclient.h>
#include <ti/drv/sciclient/soc/sysfw/include/j721s2/tisci_devices.h>
#include <ti/drv/sciclient/soc/sysfw/include/j721s2/tisci_clocks.h>
#include <ti/csl/soc/j721s2/src/cslr_main_ctrl_mmr.h>
#include <ti/csl/soc/j721s2/src/cslr_soc_baseaddress.h>
#ifdef j721s2_hyd
#include <ti/board/src/j721s2_hyd/include/board_internal.h>
#endif

/** \brief Structure holding the EPWM configuration parameters. */
typedef struct CSL_EpwmAppPwmCfg
{
    CSL_EpwmTimebaseCfg_t       tbCfg;
    /**< Timebase Sub-module configuration data structure. */
    CSL_EpwmCounterCmpCfg_t     ccCfg;
    /**< Counter comparator values . */
    CSL_EpwmAqActionCfg_t       aqCfg;
    /**< Action Qualifier Sub-module configuration data structure. */
} CSL_EpwmAppPwmCfg_t;

/**< \brief Structure holding the EPWM object data structure. */
typedef struct CSL_EpwmAppPwmObj
{
    bool                    initialized;

    uint8_t                 dutyCycle;

    uint32_t                pwmCh;
    /**< EPWM channel [A or B]. */
    uint32_t                instAddr;
    /**< EPWM instance address. */
    uint32_t                funcClk;
    /**< Functional clock(in Hz) input to the PWMSS. */
    /**< Enable Trip zone processing. */
    CSL_EpwmAppPwmCfg_t     pwmCfg;
    /**< EPWM configuration data structure. */
} CSL_EpwmAppPwmObj_t;


/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

#define EHRPWM_FCLK                 (143000000U)
#define EHRPWM_PREDIV               (256U)
#define EHRPWM_OUTPUT_CH            (CSL_EPWM_OUTPUT_CH_A)
#define EHRPWM_DUTY_CYCLE           (3U)
#define EHRPWM_INST_BASE_ADDR       (CSL_EPWM1_EPWM_BASE)
#define DEFAULT_OUT_FRQ             (15U)

#define MMR_KICK0_UNLOCK_VAL            (0x68EF3490U)
#define MMR_KICK1_UNLOCK_VAL            (0xD172BC5AU)

void epwm_init(uint8_t fps);
void epwm_deinit(void);
int epwm_set_fps(uint8_t fps);
uint8_t epwm_get_fps();
int epwm_set_duty(uint8_t duty);
uint8_t epwm_get_duty();

#endif /* _EPWM_HELPER_H_ */
