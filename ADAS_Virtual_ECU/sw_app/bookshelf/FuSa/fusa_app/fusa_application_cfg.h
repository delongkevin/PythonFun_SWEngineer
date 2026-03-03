#include <src/sdl/sdl_dcc.h>
#include <src/sdl/dcc/soc/j721s2/sdl_soc_dcc.h>

#ifndef SDLAPP_CFG_H_INCGUARD
#define SDLAPP_CFG_H_INCGUARD

/* RESET CONFIG */
#define SDL_APP_RESET_ENABLED SDL_APP_ON
#define SDL_APP_RESET_SELFTEST_ENABLED SDL_APP_OFF

/* ADC CONFIG */
#define SDL_APP_ADC_ENABLED SDL_APP_ON
#define SDL_APP_ADC_SELFTEST_ENABLED SDL_APP_OFF

/* MMR CONFIG */
#define SDL_APP_MMR_ENABLED SDL_APP_ON
#define SDL_APP_MMR_SELFTEST_ENABLED SDL_APP_OFF

/*#define SDL_APP_ADC_UART_PRINTS_ENABLED*/

/* DCC config type */
/* 100 resolution = 1% frequency error allowance */
#define APP_DCC_RESOLUTION (100U)
#define SDL_APP_NUM_DCC_INST (7U)
typedef uint32_t SDL_DCC_clkFreq;
typedef struct _SDL_APP_DCC_cfg_t {
    bool instEnabled;
    SDL_DCC_Inst instance;
    SDL_DCC_mode mode;
    SDL_DCC_clkSrc0 srcClk;
    SDL_DCC_clkFreq srcFreq;
    SDL_DCC_clkSrc1 testClk;
    SDL_DCC_clkFreq testFreq;
} SDL_APP_DCC_cfg_t;
extern SDL_APP_DCC_cfg_t SDL_APP_DCC_cfg[SDL_APP_NUM_DCC_INST];
#endif

/*===============================End Of File========================================================*/
