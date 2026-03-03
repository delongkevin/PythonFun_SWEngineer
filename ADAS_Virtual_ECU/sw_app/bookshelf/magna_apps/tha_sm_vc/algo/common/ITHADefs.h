/// --------------------------------------------------------------------------
/// @file THADefs.h
/// @brief Contains common enum, structure definitions
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Kirti Balani (kirti.balani@magna.com)
/// @author Jignesh Vasoya (jignesh.vasoya@magna.com)
/// --------------------------------------------------------------------------

#ifndef I_THA_DEFS_H
#define I_THA_DEFS_H

typedef enum
{
    e_Off = 0,
    e_Initial,
    e_Idle,
    e_Enabled,
    e_EnabledSelection,
    e_Engaged,
    e_EngagedDelta,
    e_EngagedInquiry,
    e_Complete,
    e_Faulted,
    e_SNA,
    e_Size_Enforcer = 0xFFFFFFFF,
}THAState_e;

typedef enum
{
    e_Invalid = 0,
    e_Cplr_Above_Hitch,
    e_Cplr_Below_Hitch,
    e_CplrHitch_Size_Enforcer = 0xFFFFFFFF,
}CplrHitchSts_e;

typedef enum
{
    e_Hitch_Not_Valid = 0,
    e_Hitch_Not_Detected,
    e_Hitch_Detected,
    e_Hitch_Size_Enforcer = 0xFFFFFFFF,
}HitchDetStatus_e;

typedef enum
{
    e_Cplr_Not_Valid = 0,
    e_Cplr_Not_Detected,
    e_Cplr_Detected,
    e_Cplr_Size_Enforcer = 0xFFFFFFFF,
}CplrDetStatus_e;

typedef enum
{
    e_Trlr_Not_Valid = 0,
    e_Trlr_Not_Detected,
    e_Trlr_Detected,
    e_Trlr_Size_Enforcer = 0xFFFFFFFF,
}TrlrDetStatus_e;

typedef enum
{
    e_PS_Inactive = 0,
    e_PS_Initialization,
    e_PS_WaitUserInput,
    e_PS_WaitHitch,
    e_PS_WaitCoupler_UserSel,
    e_PS_WaitCoupler,
    e_PS_WaitCouplerAngle,
    e_PS_WaitHitchCouplerHeight,
    e_PS_CouplerConfirmComplete,
    e_PS_Size_Enforcer = 0xFFFFFFFF,
}AlgoState_e;

#endif // !I_THA_DEFS_H
