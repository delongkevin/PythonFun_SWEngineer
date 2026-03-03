#ifndef THASmVc_VrntTunParam_H_INCGUARD
#define THASmVc_VrntTunParam_H_INCGUARD

#include "PlatformDataTypes.h"

typedef struct TbTHASmVc_VrntTunParam_s
{
	float32 KsTHA_deg_StrToRdWhlAngTD[17];
	float32	KsTHA_mps_DistSpdTD[6];
	float32	KsTHA_k_ErrxPropGainTD[5];
	float32 KsTHA_k_ErrxHeadingErrTD[4];
	float32	KeTHA_M_SteerTweakTrq;
	float32	KeTHA_s_SteerTweakTime;
	float32 KeTHA_k_SteerTrqCtrlKp;
	float32	KeTHA_k_SteerTrqCtrlKi;
	float32	KeTHA_k_SteerTrqCtrlKd;
	float32	KeTHA_k_SteerTrqCtrlFiltCoef;
	float32	KeTHA_k_TrqCtrlKp;
	float32	KeTHA_k_TrqCtrlKi;
	float32	KeTHA_k_TrqCtrlKd;
	float32	KeTHA_k_TrqCtrlFiltCoef;
	float32 KeTHA_k_HeadingErrGain;
	float32	KeTHA_m_WhlCircumference;
	uint16	KeTHA_px_HitchCplrDeltaThd1;
	uint16	KeTHA_px_HitchCplrDeltaThd2;
	uint16	KeTHA_px_RearBrkSuppDist;
	uint16	KeTHA_ddeg_StrRateLimFinal;
	uint16	KeTHA_ddeg_StrRateLimInit;
	uint8_t	KeTHA_b_Dummy1;
	uint8_t KeTHA_b_Dummy2;
} TbTHASmVc_VrntTunParam_t;
#endif

