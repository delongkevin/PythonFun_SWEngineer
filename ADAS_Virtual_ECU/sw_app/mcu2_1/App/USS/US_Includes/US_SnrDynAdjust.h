#ifndef US_SNRDYNADJUST_GLOBAL_H_
#define US_SNRDYNADJUST_GLOBAL_H_
#include "US_ME_Typedefs_Global.h"

#include "US_Data_Typedefs_Global.h"

#include "US_PlatformCfg_Global.h" /* needed for defines */
#include "US_SnrCfg_Global.h" /* needed for shared "User Info None" define*/

#define US_D_DYNADJ_USERINFO_NONE   USERINFO_NONE
/* Profile C, side sensor extra sensitive for scanning */
#define US_D_DYNADJ_UI_PFC_SCAN     (0xC4840303U)
/* profile C, outer sensor FOV redux */
#define US_D_DYNADJ_UI_PFC_OFOVRD   (0xC2810032U)
/* Profile C, Copy normal settings for overall FOV Redux/DNN */
#define US_D_DYNADJ_UI_PFC_COPY     (0xC1588634U)

/* Adjustment option names */
#define US_D_ADJ_STY_STATIC     0xAA
#define US_D_ADJ_STY_OFFSET     0xBB
#define US_D_ADJ_STY_FORMULAIC  0xCC

#if (US_D_ENABLE_PBUTTON_PROFC_ADJUST == ME_TRUE)
    #define US_D_PROFC_ADJ_STYLE    US_D_ADJ_STY_STATIC
#endif

//#define US_D_DNN_PROFC_OUTER_TEST

#define US_D_SNR_TEMP_INTERP_HYST 2.0f //if temperature changes by more than 2 degrees, then re-update stg settings 
#define F_INVALID_AMB_TEMP 1e6f

void UssDynAdj_Init(void);

#ifdef US_D_ENABLE_DYNCALADJ
void UssDynAdj_SetSnrAdj_TempParam(float32_t fTempBinFraction,uint16_t temp_index);
void UssDynAdj_SetSnr_TempPoints(uint16_t nTemp_Point);
const uint8_t *UssDynAdj_ProfileA_DoAdjust(const US_S_ProfileCfg_t * const Cal_Data, uint32_t Type, uint16_t temp_index, uint16_t nCfg, uint32_t UserInfo);
const uint8_t *UssDynAdj_STC_DoAdjust(const US_S_Stc_t * const Cal_Data,uint32_t Type, uint16_t temp_index, uint16_t nCfg, uint32_t UserInfo);
const uint8_t *UssDynAdj_STG_DoAdjust(const US_S_Stg_t * const Cal_Data,uint32_t Type, uint16_t temp_index, uint16_t nCfg, uint32_t UserInfo);
#endif
extern uint8_t g_UssDbg_InterpChosenBin10x ;

#endif /* ifndef US_SNRDYNADJUST_GLOBAL_H_ */
