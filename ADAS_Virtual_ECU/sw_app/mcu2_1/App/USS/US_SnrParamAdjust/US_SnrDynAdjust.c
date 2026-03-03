#include "US_SnrDrv_Global.h"
#include "US_SnrDrvMgr_Global.h"
#include "US_SysMgr_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_Platform_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_Ctrl_Global.h"
#include "US_ComOutputBuffer_Global.h"
#include "US_ComInputBuffer_Global.h"
#include "US_SnrDynAdjust.h"
#include <math.h>

/* this would turn off this entire file */
#ifdef US_D_ENABLE_DYNCALADJ

/* Local functions */
#if (US_D_USE_FAPA_API == ME_TRUE)
static bool_t UssSPA_FAPA_IsActive(void);
static bool_t UssSPA_FAPA_IsPerpSlotLocked(void);

static IJobFPAOutput_t UssSnrDynAdj_g_sJobFPAOutputData;
static TbAP_DriveAssistStatOut_t UssSnrDynAdj_g_sDriveAssistStatOut; /*PRQA S 0776*/ /* six characters are common as functionality is same*/
#endif


/*
<SegmentGroup start="0" profile="US_E_PROFILE_C">
<Segment time="20" mode="0" target="34" Rsv="0" tb="320" />
<Segment time="33" mode="0" target="45" Rsv="0" tb="320" />
<Segment time="47" mode="0" target="53" Rsv="0" tb="320" />
<Segment time="59" mode="0" target="58" Rsv="0" tb="320" />
</SegmentGroup>
<SegmentGroup start="4" profile="US_E_PROFILE_C">
<Segment time="68" mode="0" target="64" Rsv="0" tb="320" />
<Segment time="81" mode="0" target="70" Rsv="0" tb="300" />
<Segment time="218" mode="0" target="110" Rsv="0" tb="20" />
<Segment time="218" mode="0" target="110" Rsv="0" tb="20" />
</SegmentGroup>
*/
/* \TODO Move table to a new file! */
 /*comment out avoid commenting code ( US_D_ENABLE_PBUTTON_PROFC_ADJUST  ==  ME_TRUE ) */
#if 0
const US_S_Stg_t US_ROM_ProfileC_STG_OuterRedux1 =
{
    .US_STG[0] = 
    {
        .start  = 0,
        .seg[0] = {    .time = 0,   .th   = 255,    .step = -10,    .tb   = 0,},
        .seg[1] = {    .time = 4,   .th   = 103,    .step = -10,    .tb   = 0,},
        .seg[2] = {    .time = 8,    .th   = 83,    .step = -10,    .tb   = 0,},
        .seg[3] = {    .time = 12,    .th   = 78,    .step = -10,    .tb   = 0,},
        .profile = US_E_PROFILE_C,
    },
    .US_STG[1] = 
    {
        .start  = 4,
        .seg[0] ={    .time = 16,    .th   = 71,    .step = -10,    .tb   = 0,},
        .seg[1] ={    .time = 21,    .th   = 78,    .step = -10,    .tb   = 0,},
        .seg[2] ={    .time = 26,    .th   = 77,    .step = -10,    .tb   = 0,},
        .seg[3] ={    .time = 31,    .th   = 72,    .step = -10,    .tb   = 0,},
        .profile = US_E_PROFILE_C
    },
    .US_STG[2] = 
    {
        .start  = 8,
        .seg[0] ={    .time = 37,    .th   = 71,    .step = -10,    .tb   = 0,},
        .seg[1] ={    .time = 43,    .th   = 68,    .step = -10,    .tb   = 0,},
        .seg[2] ={    .time = 48,    .th   = 64,    .step = -10,    .tb   = 0,},
        .seg[3] ={    .time = 54,    .th   = 83,    .step = -10,    .tb   = 0,},
        .profile = US_E_PROFILE_C
    },
    .US_STG[3] = 
    {
        .start  = 12,
        .seg[0] ={    .time = 61,    .th   = 77,    .step = -10,    .tb   = 0,},
        .seg[1] ={    .time = 68,    .th   = 80,    .step = -10,    .tb   = 0,},
        .seg[2] ={    .time = 75,    .th   = 84,    .step = -10,    .tb   = 0,},
        .seg[3] ={    .time = 81,    .th   = 87,    .step = -10,    .tb   = 0,},
        .profile = US_E_PROFILE_C
    }
};
#endif

#if (ME_TRUE == US_D_LAUTERBACH_DEBUG_VARS)
    #ifdef US_D_DNN_PROFC_OUTER_TEST
    US_S_Stc_t g_LAUD_ProfC_STC1; /* to edit on laud */
    US_S_Stg_t g_LAUD_ProfC_STG1; /* to edit on laud */
    uint8_t g_LAUD_ReduxDebug_USE_ROM = 0x01;
    #endif /* US_D_DNN_PROFC_OUTER_TEST */
#endif


//static uint32_t US_AdjComBuffer[512/4];
static uint16_t g_nTemp_Point = 0,g_TempIndex =0;
static float32_t g_fTempBinFraction = 0.0f;


#if (US_D_ENABLE_FAPA_DYN_STG == ME_TRUE)
extern uint32_t last_descr;
extern uint16_t last_itemID;

//static
US_S_StgSeg_t g_US_SetSnrAdj_PDC_STG_new_FrontInner[FOUR];
US_S_StgSeg_t g_US_SetSnrAdj_PDC_STG_new_RearInner[FOUR];
US_S_StgSeg_t g_US_SetSnrAdj_PDC_STG_new_FrontSide[FOUR];
US_S_StgSeg_t g_US_SetSnrAdj_PDC_STG_new_RearSide[FOUR];
uint16_t debug_int = 0;
#if (US_D_USE_FAPA_API == ME_TRUE)
IHMIInfoToFPA_t v_HMIToFPA_st;
#endif
uint8_t g_US_SetSnrAdj_DynAmt = 0u; //setable by lauderback (set to zero for turning off)
uint8_t g_US_SetSnrAdj_ConfigAmt = 0u;//10u;//6u;//12u; //keep
#endif /*comment out avoid commented (US_D_ENABLE_FAPA_DYN_STG == ME_TRUE) */

/* Global debug variables */


uint8_t g_UssDbg_InterpTempIndex = 0xFF;
uint8_t g_UssDbg_InterpBinError = ZERO;
/* comment out uint8_t g_UssDbg_ProfC_STC_Redux_LastStep = 0xFF; */
/* comment out uint8_t g_UssDbg_ProfC_STG_Redux_LastStep = 0xFF; */
uint8_t g_UssDbg_InterpChosenBin10x = 0xFF;

/****** Public Functions *******/
void UssDynAdj_Init(void)
{
    #if (ME_TRUE == US_D_LAUTERBACH_DEBUG_VARS)
        #if 0
        //init this debug
        g_LAUD_ProfC_STC1 = US_ROM_ProfileC_STC_OuterRedux1;
        g_LAUD_ProfC_STG1 = US_ROM_ProfileC_STG_OuterRedux1;
        #endif
    #endif
}

void UssDynAdj_SetSnrAdj_TempParam(float32_t fTempBinFraction,uint16_t temp_index)
{
	g_fTempBinFraction   = fTempBinFraction;
	g_TempIndex          = temp_index;
    g_UssDbg_InterpTempIndex = (uint8_t)temp_index;
}

void UssDynAdj_SetSnr_TempPoints(uint16_t nTemp_Point)
{
	g_nTemp_Point        = nTemp_Point;
}


const uint8_t *UssDynAdj_ProfileA_DoAdjust(const US_S_ProfileCfg_t * const Cal_Data, uint32_t Type, uint16_t temp_index, uint16_t nCfg, uint32_t UserInfo)
{
    (void)temp_index;
    (void)UserInfo;
    const uint8_t *ret = (const uint8_t*)Cal_Data; /*PRQA S 0751*/ /*required for functionality*/
    if((Type & (uint32_t)0xf) == ((uint32_t)US_E_PROFILE_A))
	{
    	if(nCfg  > ONE)
    	{
		/* do adjust calculation here */
    	}
	}
	return ret;
}

const uint8_t *UssDynAdj_STC_DoAdjust(const US_S_Stc_t * const Cal_Data,uint32_t Type, uint16_t temp_index, uint16_t nCfg, uint32_t UserInfo)
{
#if (US_D_ENABLE_PBUTTON_PROFC_ADJUST == ME_TRUE)
    const US_S_Stc_t US_ROM_ProfileC_STC_Scanning1 =
    {
        .US_STC[0] =
        {
            .start    = 0,
            /* .rsv skipped */
            .seg[0] = {   .time   = 20,    .mode   = 0,    .target = 34,   .tb     = 320,    },
            .seg[1] = {   .time   = 33,    .mode   = 0,    .target = 45,   .tb     = 320,    },
            .seg[2] = {   .time   = 47,    .mode   = 0,    .target = 53,   .tb     = 320,    },
            .seg[3] = {   .time   = 59,    .mode   = 0,    .target = 58,   .tb     = 320,    },
            .profile  = US_E_PROFILE_C,
        },
        .US_STC[1] =
        {
            .start    = 4,
            /* .rsv skipped */
            .seg[0] = {   .time   = 68,    .mode   = 0,    .target = 64,   .tb     = 320,    },
            .seg[1] = {   .time   = 81,    .mode   = 0,    .target = 70,   .tb     = 300,    },
            .seg[2] = {   .time   = 218,    .mode   = 0,    .target = 110,   .tb     = 20,    },
            .seg[3] = {   .time   = 218,    .mode   = 0,    .target = 110,   .tb     = 20,    },
            .profile  = US_E_PROFILE_C,
        }
    };
#endif
    static bool_t g_ScanningProfC_STC_Exists = ME_FALSE;
    static uint8_t g_UssDbg_ProfC_STC_Scanning_LastStep = 0xFF;
    static US_S_Stc_t g_US_SetSnrAdj_TempRAM_STC; /* Just for a RAM pointer + prev used */
    
    const uint8_t *ret = (const uint8_t*)Cal_Data; /*PRQA S 0751*/ /*required for functionality*/
    //comment out g_UssDbg_ProfC_STC_Scanning_LastStep = 0x00;
    (void)temp_index;
    if((Type & (uint32_t)0xfu) ==((uint32_t)US_E_PROFILE_A))
    {
        if(nCfg  > ((uint16_t)ONE))
        {
            /* do adjust calculation here */

#if (US_D_ENABLE_DNN_PROFC_ALL_ADJUST == ME_TRUE)
            /* Profile A values are currently loaded, now switch the flag to profile C */
            if(UserInfo == US_D_DYNADJ_UI_PFC_COPY)
            {
                uint8_t uSegIdx;
                US_S_Stc_t *psOutgoingCalData;

                /* Copy data to RAM buffer, no guarantee that ret is a RAM pointer by now */
                /*g_US_SetSnrAdj_TempRAM_STC = *(US_S_Stc_t*)ret;*/ 
                g_US_SetSnrAdj_TempRAM_STC = *(Cal_Data);
               /* comment out (void)memcpy((void*)&g_US_SetSnrAdj_TempRAM_STC, ret, sizeof(US_S_Stc_t));*/
                psOutgoingCalData = &g_US_SetSnrAdj_TempRAM_STC;
                for (uSegIdx = ZERO; uSegIdx < TWO; uSegIdx++)
                {
                    psOutgoingCalData->US_STC[uSegIdx].profile = US_E_PROFILE_C;
                }
                if((Type & US_SIDE_POS) == US_SIDE_POS)
                {
                    /* Save profA's values for profC side sensors, used later for US_D_DYNADJ_UI_PFC_SCAN when FAPA not scanning */
                    //comment out g_US_SetSnrAdj_TempRAM_ProfC_STC = *psOutgoingCalData;
                    //comment out g_ScanningProfC_STC_Exists = ME_TRUE;
                    /* JWR3 TODO: Requires unique global temp variable IF this functionality is wanted */
                }
                ret = (const uint8_t*)psOutgoingCalData;
            }
#endif
        }
    } /* profile A */

#if (US_D_ENABLE_PBUTTON_PROFC_ADJUST == ME_TRUE)
    if( (Type ==((uint32_t)US_E_PROFILE_C)) && (UserInfo == US_D_DYNADJ_UI_PFC_SCAN) )
    {
        //temp_index doesn't matter for profile C so far
        //lets check if the config size makes sense for having only 1 bin
        if(nCfg == ONE)
        {
    #if (US_D_USE_FAPA_API == ME_TRUE)
            if( (UssSPA_FAPA_IsActive() == ME_TRUE) && (UssSPA_FAPA_IsPerpSlotLocked() == ME_FALSE) ) /*PRQA S 3415, 3416*/ /*no side effect*/
            {
                #if (US_D_PROFC_ADJ_STYLE == US_D_ADJ_STY_STATIC)
                //copy rom data to ram - unsure if rom pointer will work with calibration system
                //comment out memcpy((void*)&g_US_SetSnrAdj_TempRAM_STC, (void*)&US_ROM_ProfileC_STC_Scanning1, sizeof(US_S_Stc_t));
                g_US_SetSnrAdj_TempRAM_STC = US_ROM_ProfileC_STC_Scanning1;
                ret = (const uint8_t*)&g_US_SetSnrAdj_TempRAM_STC; /*PRQA S 0751*/ /*required for functionality*/
                g_ScanningProfC_STC_Exists = ME_FALSE; /* Overwrote, allow other system to set if needed */
                #endif
                //other styles not created, do nothing
                g_UssDbg_ProfC_STC_Scanning_LastStep = 0x01;
            }
            else
    #endif /* US_D_USE_FAPA_API */
            {
                //Conditions not correct, use normal cal
		#if 0	
                if(ME_TRUE == g_ScanningProfC_STC_Exists)
                {
                    ret = (uint8_t*)&g_US_SetSnrAdj_TempRAM_STC; /*PRQA S 0751*/ /*required for functionality*/
                }
                g_UssDbg_ProfC_STC_Scanning_LastStep = 0x02;
		#endif	
            }
        }
        else
        {
            //Profile C has changed, redo this code!
            g_UssDbg_ProfC_STC_Scanning_LastStep = 0x03;
        }
    }
#endif
#if 0
    if( (Type == US_E_PROFILE_C) && (UserInfo == US_D_DYNADJ_UI_PFC_OFOVRD) )
    {
        //temp_index - doesn't matter for so far
        //nCfg - number of configs doesn't matter yet

        g_UssDbg_ProfC_STC_Redux_LastStep = 0x00;
        if (g_LAUD_ReduxDebug_USE_ROM == 0x01)
        {
            g_US_SetSnrAdj_TempRAM_STC = US_ROM_ProfileC_STC_OuterRedux1;
            ret = (uint8_t*)&g_US_SetSnrAdj_TempRAM_STC;
            g_UssDbg_ProfC_STC_Redux_LastStep = 0x02;
        }
        else
        {
            ret = (uint8_t*)&g_LAUD_ProfC_STC1;
            g_UssDbg_ProfC_STC_Redux_LastStep = 0x03;
    	}
	}

#endif
    /*comment out g_UssDbg_ProfC_STC_Scanning_LastStep |= 0x80;*/
	return ret;
}

const uint8_t *UssDynAdj_STG_DoAdjust(const US_S_Stg_t * const Cal_Data, uint32_t Type,uint16_t temp_index, uint16_t nCfg, uint32_t UserInfo)
{
    static US_S_StgSeg_t *g_PDC_STG_next;
    //static  US_S_StgSeg_t *g_PDC_STG_prev;
   // static US_S_StgSeg_t *g_PDC_STG_curr;
    static const US_S_StgSeg_t *g_PDC_STG_interp; /* pointer can change addr, but data is ready-only*/
    static uint8_t g_UssDbg_InterpRunCounter = ZERO;
    static uint8_t g_UssDbg_InterpSkippedCounter = ZERO;
    static float32_t g_fInterpAlpha = 0.0f;
    static US_S_Stg_t g_US_SetSnrAdj_TempRAM_STG; /* Just for a RAM pointer */

    const uint8_t *ret = (const uint8_t*)Cal_Data;/*PRQA S 0751*/ /*required for functionality*/     /*return orignal Cal data if adjustment does not need*/
#if (US_D_ENABLE_FAPA_DYN_STG == ME_TRUE)
    static US_S_StgSeg_t g_US_SetSnrAdj_PDC_STG_new[FOUR];/*PRQA S 0776*/ /* six characters are common as functionality is same*/
#endif
    (void)temp_index;
    if((Type & (uint32_t)0xfu) == ((uint32_t)US_E_PROFILE_A))
    {
        /* **why did is this setting to US_AdjComBuffer????*/
        /* comment out US_S_StgSeg_t *PDC_STG_interp =(US_S_StgSeg_t *)US_AdjComBuffer;*/
        US_S_StgSeg_t *PDC_STG_interp = (US_S_StgSeg_t *)g_US_SetSnrAdj_TempRAM_STG.US_STG; //g_US_SetSnrAdj_PDC_STG_new
        const US_S_StgSeg_t *PDC_STG = (const US_S_StgSeg_t*)Cal_Data; /*PRQA S 0310*/ /*Pointer assignement is done to fetch values, it references to same data type */
#if (US_D_ENABLE_FAPA_DYN_STG == ME_TRUE)
    #if (US_D_USE_FAPA_API == ME_TRUE)
        SigMgr_Data_IHMIInfoToFPA_t_Get(&v_HMIToFPA_st);
        SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Get(&UssSnrDynAdj_g_sDriveAssistStatOut);
        SigMgr_PpJobFPAData_IJobFPAOutput_t_Get(&UssSnrDynAdj_g_sJobFPAOutputData);    
        SigMgr_Data_IFPAInfoToVC_t_Get(&(UssSnrDynAdj_g_sJobFPAOutputData.m_FpaInfoToVC));

        //Change the stg values by 12 if active or not perpendicular
        if (!(TeAutoPark_e_AutoParkStatus_Active == UssSnrDynAdj_g_sDriveAssistStatOut.IeAP_e_AutoParkStatus) || 
                (ParkingSlotType_E_PW_PERPENDICULAR == UssSnrDynAdj_g_sJobFPAOutputData.m_FpaInfoToVC.stFPALockedSlotData.m_SlotType))
        {
            g_US_SetSnrAdj_DynAmt = 0u;
        }
        else
        {
            g_US_SetSnrAdj_DynAmt = g_US_SetSnrAdj_ConfigAmt;
        }
    #endif /* FAPA API */
#endif /* US_D_ENABLE_FAPA_DYN_STG */

#if (US_D_ENABLE_SNR_TEMPERATURE_INTERP == ME_TRUE)
        if(nCfg  > ONE)
        {
            if ((g_TempIndex < g_nTemp_Point)&&(g_TempIndex > ZERO)) //only need to interpolate for bins 1 and 2 (bins 0 and 3 are cropped, so they remain unchanged)
            {
                //pointer to the next bin:
                const US_S_StgSeg_t *PDC_STG_next = (const US_S_StgSeg_t*)(Cal_Data + ONE); /*PRQA S 0310, 0488*/ /*Pointer assignement is done to fetch values, it references to same data type */ /*one bin later */
                //pointer to the previous bin:
                const US_S_StgSeg_t *PDC_STG_prev = (const US_S_StgSeg_t*)(Cal_Data - ONE); /*PRQA S 0310, 0488*/ /*Pointer assignement is done to fetch values, it references to same data type */ /* one bin earlier. */
                //loop indices:
                uint8_t uSegIdx, uThIdx;

                //fill in the values into our interpolated array to get the other params besides ".th":
                (void)memcpy((void*)PDC_STG_interp, (const void*)Cal_Data, sizeof(US_S_Stg_t));/*PRQA S 1496*/ /* there are four segments worth of data.*/

                for (uSegIdx = ZERO; uSegIdx<FOUR;uSegIdx++)
                {
                    for (uThIdx = ZERO; uThIdx<FOUR;uThIdx++)
                    {
                        /* if we are less than half way into the bin, use the previous bin */
                        if ((0.0f <= g_fTempBinFraction) &&  (g_fTempBinFraction < 0.5f))
                        {
                        PDC_STG_interp[uSegIdx].seg[uThIdx].th = (uint8_t )roundf(
                            ((float32_t)PDC_STG_prev[uSegIdx].seg[uThIdx].th * (1.0f - (2.0f*g_fTempBinFraction)))  +  /*PRQA S 1800, 4492 *//* round function is used as only int is req.*/
                            ((float32_t)PDC_STG[uSegIdx].seg[uThIdx].th      * (       2.0f*g_fTempBinFraction)) );  /*PRQA S 1800 *//* round function is used as only int is req.*/

                            g_fInterpAlpha = 2.0f*g_fTempBinFraction; 
                        }
                        else if ((0.5f <= g_fTempBinFraction) &&  (g_fTempBinFraction <= 1.0f))
                        {
                        PDC_STG_interp[uSegIdx].seg[uThIdx].th = (uint8_t )roundf(
                            ((float32_t)PDC_STG[uSegIdx].seg[uThIdx].th      * (1.0f - (2.0f*(g_fTempBinFraction-0.5f))))  +  /*PRQA S 1800, 4492 *//* round function is used as only int is req.*/
                            ((float32_t)PDC_STG_next[uSegIdx].seg[uThIdx].th * (       2.0f*(g_fTempBinFraction-0.5f))) ); /*PRQA S 1800 *//* round function is used as only int is req.*/

                            g_fInterpAlpha = 1.0f-(2.0f*g_fTempBinFraction); 
                        }
                        else
                        {
                            PDC_STG_interp[uSegIdx].seg[uThIdx].th = 255u; //just stop detections so we can noitice.
                            //error (the bin fraction is wrong).
                            g_UssDbg_InterpBinError++; /*PRQA S 3383*/ /*debug variable it is ok to to roll over with increament operation*/
                        }
                    }
                }
                g_UssDbg_InterpChosenBin10x = (uint8_t)(g_fTempBinFraction * 10.0f); /*PRQA S 4395*/ /*expected conversion*/
                /* comment out g_PDC_STG_next = PDC_STG_next; */
               /* comment out g_PDC_STG_prev = PDC_STG_prev; */
               /* comment out g_PDC_STG_curr = PDC_STG;  */
                g_PDC_STG_interp = PDC_STG_interp;

                //set the pointer for data going to sensor to point to our array:
                ret = (const uint8_t*)PDC_STG_interp;  /*PRQA S 0751*/ /*required for functionality*/

                g_UssDbg_InterpRunCounter++;  /*PRQA S 3383*/ /*debug variable it is ok to to roll over with increament operation*/
            }
            else /* skipped because bin 0 or bin 3*/
            {
                g_UssDbg_InterpSkippedCounter++; /*PRQA S 3383*/ /*debug variable it is ok to to roll over with increament operation*/
            }
        }
#endif /*comment out  #if (US_D_ENABLE_SNR_TEMPERATURE_INTERP == ME_TRUE) */

#if (US_D_ENABLE_FAPA_DYN_STG == ME_TRUE)
        /* fill in the values into our interpolated array to get the other params besides ".th":*/
		/* comment out memcpy((void*)PDC_STG_interp, (void*)Cal_Data, sizeof(US_S_Stg_t));*/ /*there are four segments worth of data. */

		/* copy the data from ret, which is updated by interpolation if enabled, or initialzed to Cal Data */
		memcpy((void*)g_US_SetSnrAdj_PDC_STG_new, ret, sizeof(US_S_StgSeg_t)*FOUR); //there are four segments worth of data.
		
		debug_int = 0;

        if(nCfg  > ONE)
        {
            //comment out if (g_bIsPerp || g_bIsPara)
            if ((0x0411 == last_descr) || (0x0421 == last_descr) || (TeAutoPark_e_AutoParkStatus_Complete == UssSnrDynAdj_g_sDriveAssistStatOut.IeAP_e_AutoParkStatus)) 
            {

                uint8_t uSegIdx, uThIdx;

                for (uSegIdx = ZERO; uSegIdx<FOUR;uSegIdx++)
                {
                    for (uThIdx = ZERO; uThIdx<FOUR;uThIdx++)
                    {
                        
                        if (g_US_SetSnrAdj_PDC_STG_new[uSegIdx].seg[uThIdx].th	> 200u)
                        {
                            //do nothing. leave unaffect for ringing. 
                    
                        }
                        else if (g_US_SetSnrAdj_PDC_STG_new[uSegIdx].seg[uThIdx].th	> g_US_SetSnrAdj_DynAmt)
                        {
                            g_US_SetSnrAdj_PDC_STG_new[uSegIdx].seg[uThIdx].th -= g_US_SetSnrAdj_DynAmt;
                        
                        }
                        else
                        {
                            /* JWR: why put to zero? instead of leaving as is */
                            g_US_SetSnrAdj_PDC_STG_new[uSegIdx].seg[uThIdx].th = 0; 
        
                        }
                    }
                }

                //debug purposes
                if(0x51 == last_descr)
                {
                    memcpy(g_US_SetSnrAdj_PDC_STG_new_FrontInner, g_US_SetSnrAdj_PDC_STG_new, sizeof(g_US_SetSnrAdj_PDC_STG_new));
                }
                else if (0x61 == last_descr)
                {
                    memcpy(g_US_SetSnrAdj_PDC_STG_new_RearInner, g_US_SetSnrAdj_PDC_STG_new, sizeof(g_US_SetSnrAdj_PDC_STG_new));
                }
                else if (0x0411 == last_descr)
                {
                    memcpy(g_US_SetSnrAdj_PDC_STG_new_FrontSide, g_US_SetSnrAdj_PDC_STG_new, sizeof(g_US_SetSnrAdj_PDC_STG_new));
                }
                else if (0x0421 == last_descr)
                {
                    memcpy(g_US_SetSnrAdj_PDC_STG_new_RearSide, g_US_SetSnrAdj_PDC_STG_new, sizeof(g_US_SetSnrAdj_PDC_STG_new));
							}
							else
							{
                                    //DO Nothing
							}
                ret = (const uint8_t*)g_US_SetSnrAdj_PDC_STG_new;
						}
					}
#endif /*comment out #if (US_D_ENABLE_FAPA_DYN_STG == ME_TRUE) */
#if (US_D_ENABLE_DNN_PROFC_ALL_ADJUST == ME_TRUE)
        /* Profile A values are currently loaded, now switch the flag to profile C */
        if ((nCfg > ONE) && (UserInfo == US_D_DYNADJ_UI_PFC_COPY))
        {
            uint8_t uSegIdx;
            US_S_Stg_t *psOutgoingCalData;

            /* Copy data to RAM buffer, no guarantee that ret is a RAM pointer by now */
            g_US_SetSnrAdj_TempRAM_STG = *(Cal_Data);
            psOutgoingCalData = &g_US_SetSnrAdj_TempRAM_STG;
            for (uSegIdx = ZERO; uSegIdx < FOUR; uSegIdx++)
            {
                psOutgoingCalData->US_STG[uSegIdx].profile = US_E_PROFILE_C;
            }
            ret = (const uint8_t*)psOutgoingCalData;
        }
#endif /*comment out #if (US_D_ENABLE_DNN_PROFC_ALL_ADJUST == ME_TRUE) */
    } /* If profile A */

#if 0
    if( (Type == US_E_PROFILE_C) && (UserInfo == US_D_DYNADJ_UI_PFC_OFOVRD) )
    {
        //temp_index - doesn't matter for so far
        //nCfg - number of configs doesn't matter yet

        g_UssDbg_ProfC_STG_Redux_LastStep = 0x00;
        if (g_LAUD_ReduxDebug_USE_ROM == 0x01)
        {
            g_US_SetSnrAdj_TempRAM_STG = US_ROM_ProfileC_STG_OuterRedux1;
            ret = (uint8_t*)&g_US_SetSnrAdj_TempRAM_STG;
            g_UssDbg_ProfC_STG_Redux_LastStep = 0x02;
    	}
        else
        {
            ret = (uint8_t*)&g_LAUD_ProfC_STG1;
            g_UssDbg_ProfC_STG_Redux_LastStep = 0x03;
        }
    }
#endif

    return ret;
}

/* Local Functions */

#if (US_D_USE_FAPA_API == ME_TRUE)
static bool_t UssSPA_FAPA_IsActive(void)
{
    SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Get(&UssSnrDynAdj_g_sDriveAssistStatOut);
    return (bool_t)(TeAutoPark_e_AutoParkStatus_Active == UssSnrDynAdj_g_sDriveAssistStatOut.IeAP_e_AutoParkStatus); /*PRQA S 4304*/ /*bool and Uchar are essentially same*/
}

static bool_t UssSPA_FAPA_IsPerpSlotLocked(void)
{
    SigMgr_PpJobFPAData_IJobFPAOutput_t_Get(&UssSnrDynAdj_g_sJobFPAOutputData);    
    SigMgr_Data_IFPAInfoToVC_t_Get(&(UssSnrDynAdj_g_sJobFPAOutputData.m_FpaInfoToVC));
    return (bool_t)(ParkingSlotType_E_PW_PERPENDICULAR == UssSnrDynAdj_g_sJobFPAOutputData.m_FpaInfoToVC.stFPALockedSlotData.m_SlotType);  /*PRQA S 4304*/ /*bool and Uchar are essentially same*/
}
#endif /*comment out #if (US_D_USE_FAPA_API == ME_TRUE) */

#endif /* US_D_ENABLE_DYNCALADJ */
