

#include "US_ME_Typedefs_Global.h"

#include "US_Data_Typedefs_Global.h"
#include "US_SnrDrv_Global.h"
#include "US_SnrDrvMgr_Global.h"
#include "US_SnrCfg_Global.h"
#include "US_SysMgr_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_Platform_Global.h"
#include "US_Ctrl_Global.h"
#include "US_ComOutputBuffer_Global.h"
#include "US_SnrDynAdjust.h"

/* Local variable declaration */

/* Local function declaration */
static const uint8_t *US_GetAdjustment(const uint8_t *Data,uint32_t Type, uint16_t Len,  uint16_t ItemID,uint16_t TempIndex, uint32_t UserInfo);
static const uint8_t *US_STCAdjustment(const uint8_t *const Data,uint32_t Type, uint16_t Len, uint16_t TempIndex, uint32_t UserInfo);
static const uint8_t *US_STGAdjustment(const uint8_t *const Data, uint32_t Type,uint16_t Len, uint16_t TempIndex, uint32_t UserInfo);
static const uint8_t *US_ProfileAdjustment(const uint8_t *const Data,uint32_t Type, uint16_t Len, uint16_t TempIndex, uint32_t UserInfo);

uint16_t UssDynAdj_STC_DoAdjustCntr = 0;
uint16_t UssDynAdj_STG_DoAdjustCntr = 0;
uint16_t UssDynAdj_ProfileA_DoAdjustCntr = 0;
/* ===========================================================================
 * Name:     US_STCAdjustment
 * Remarks:  DD-ID:{7B509149-1E7B-4720-996F-02609B1FCDB6} 
 * ===========================================================================*/
static const uint8_t *US_STCAdjustment(const uint8_t *const Data,uint32_t Type, uint16_t Len, uint16_t TempIndex, uint32_t UserInfo)
{
	uint16_t nSTC;
    const uint8_t *ret = NULL;
    const US_S_Stc_t *STC_Data = (const US_S_Stc_t*)Data; /* Loss of ptr addr const, intentional*/
	nSTC = (uint16_t)(Len/sizeof(US_S_Stc_t));                
    (void)Type;
	if((Data != NULL)&&(Len != (uint16_t)ZERO))
	{
		if(nSTC > ONE)     /* if depends on temperature */
		{
			if(TempIndex < nSTC)
			{
			  STC_Data = STC_Data + TempIndex;
			}
			else
			{
				STC_Data = STC_Data + nSTC - ONE;
			}
		}
        ret = (const uint8_t *)STC_Data;
		/**************************************
		 * do ADJ HERE
		 *
		 ************************************/
#ifdef	US_D_ENABLE_DYNCALADJ
        ret = UssDynAdj_STC_DoAdjust((const US_S_Stc_t * const)STC_Data,Type,TempIndex,nSTC,UserInfo);
		UssDynAdj_STC_DoAdjustCntr++;
#endif
	}
	return ret;
}
/* ===========================================================================
 * Name:     US_STGAdjustment
 * Remarks:  DD-ID:{E69C1DFD-9F20-49da-8743-74916630D511} 
 * ===========================================================================*/
static const uint8_t *US_STGAdjustment(const uint8_t *const Data, uint32_t Type,uint16_t Len, uint16_t TempIndex, uint32_t UserInfo)
{
	uint16_t nSTG;
    const uint8_t *ret = Data;
    const US_S_Stg_t *STG_Data = (const US_S_Stg_t*)Data; /* Loss of ptr addr const, intentional*/
    (void)Type;    
	nSTG = (uint16_t)(Len/sizeof(US_S_Stg_t));                      
	if((Data != NULL)&&(Len != (uint16_t)ZERO))         
	{
		if(nSTG > ONE)     /* if depends on temperature */
		{
			if(TempIndex < nSTG)
			{
				STG_Data = STG_Data + TempIndex;
			}
			else
			{
				STG_Data = STG_Data + nSTG -ONE;
			}
		}
        ret = (const uint8_t *)STG_Data;
		/**************************************
		 * do ADJ HERE
		 *
		 ************************************/
#ifdef	US_D_ENABLE_DYNCALADJ
        ret = UssDynAdj_STG_DoAdjust((const US_S_Stg_t * const)STG_Data,Type,TempIndex,nSTG,UserInfo);
		UssDynAdj_STG_DoAdjustCntr++;
#endif
	 }
	return ret;
}
/* ===========================================================================
 * Name:     US_ProfileAdjustment
 * Remarks:  DD-ID:{AEFF2D90-5EA9-4e17-87AE-D32C81764F5D} 
 * ===========================================================================*/
static const uint8_t *US_ProfileAdjustment(const uint8_t *const Data,uint32_t Type, uint16_t Len, uint16_t TempIndex, uint32_t UserInfo)
{
	uint16_t nProfile;
    const uint8_t *ret = NULL;
    const US_S_ProfileCfg_t *Profile_Data = (const US_S_ProfileCfg_t*)Data; /* Loss of ptr addr const, intentional*/
    (void)Type; 
	nProfile = (uint16_t)(Len/sizeof(US_S_ProfileCfg_t));                      
	if((Data != NULL)&&(Len != (uint16_t)ZERO))
	{
		if(nProfile > ONE)     /* if depends on temperature */
		{
			if(TempIndex < nProfile)
			{
				Profile_Data = Profile_Data + TempIndex;
			}
			else
			{
				Profile_Data = Profile_Data + nProfile -ONE;
			}
		}
        ret = (const uint8_t *)Profile_Data;
		/**************************************
		 * do ADJ HERE
		 *
		 ************************************/
#ifdef	US_D_ENABLE_DYNCALADJ
        ret = UssDynAdj_ProfileA_DoAdjust((const US_S_ProfileCfg_t * const)Profile_Data,Type,TempIndex,nProfile,UserInfo);
    UssDynAdj_ProfileA_DoAdjustCntr++;
#endif
	}
	return ret;
}
/* ===========================================================================
 * Name:     US_GetAdjustment
 * Remarks:  DD-ID:{E5C54201-7A8A-485d-87CC-C7CE6E829E60}
 * ===========================================================================*/
static const uint8_t *US_GetAdjustment(const uint8_t* Data, uint32_t Type, uint16_t Len,  uint16_t ItemID,uint16_t TempIndex, uint32_t UserInfo)
{
    const uint8_t* ret = Data;
	if((Data != NULL)&&(Len != (uint16_t)ZERO))
	{
		switch(ItemID)
		{
		case STC_CFG_ID:
            ret = US_STCAdjustment((const uint8_t *const)Data,Type, Len, TempIndex, UserInfo);
			break;
		case STG_CFG_ID:
            ret = US_STGAdjustment((const uint8_t *const)Data,Type, Len, TempIndex, UserInfo);
			break;
		case PROFILE_CFG_ID:
            ret = US_ProfileAdjustment((const uint8_t *const)Data,Type, Len, TempIndex, UserInfo);
			break;
		default:     
		/* empty */
			break;
		}
	}
	return ret;
}
/* ===========================================================================
 * Name:     US_SnrCfg_SnrCalAdjust
 * Remarks:  DD-ID:{1F1D93A6-5F4D-4755-A46F-F7C766E6905B}
 * ===========================================================================*/
const uint8_t *US_SnrCfg_SnrCalAdjust(uint16_t TempIndex, uint32_t Type, uint16_t ItemID, uint32_t UserInfo)
{
	uint16_t Data_Len;
    const uint8_t *CalData,*ret = NULL;
    CalData = (const uint8_t *)US_SnrCfg_F_Get_CaliItemData(&Data_Len,(uint32_t)BLOCK_TUNE_ID,Type,ItemID);  /* get this item Calibration Data */
	if(CalData != NULL)
	{
        ret = US_GetAdjustment((const uint8_t*)CalData,Type,Data_Len,ItemID,TempIndex,UserInfo);
	}
	return ret;
}


