/// --------------------------------------------------------------------------
/// @file THADefs.h
/// @brief Contains common enum, structure definitions
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Jignesh Vasoya (jignesh.vasoya@magna.com)
/// --------------------------------------------------------------------------

#ifndef THA_DEFS_H
#define THA_DEFS_H

#ifdef _WIN32
#include <MECL/mecl.h>
#include "Point.h"
#else
#include "mecl/mecl.h"
#include "meal/camera/core/inc/CameraPoint.h"
#endif // _WIN32

namespace tha
{
    enum THAState_e
    {
        e_Off = 0,
        e_Initial = 1,
        e_Idle = 2,
        e_Enabled = 3,
        e_EnabledSelection = 4,
        e_Engaged = 5,
        e_EngagedDelta = 6,
        e_EngagedInquiry = 7,
        e_Complete = 8,
        e_Faulted = 9,
        e_SNA = 10,
        e_Size_Enforcer = 0xFFFFFFFFu
    };

    enum CplrHitchSts_e
    {
        e_Invalid = 0,
        e_Cplr_Above_Hitch = 1,
        e_Cplr_Below_Hitch = 2,
        e_CplrHitch_Size_Enforcer = 0xFFFFFFFFu
    };

    enum HitchDetStatus_e
    {
        e_Hitch_Not_Valid = 0,
        e_Hitch_Not_Detected = 1,
        e_Hitch_Detected = 2,
        e_Hitch_Size_Enforcer = 0xFFFFFFFFu
    };

    enum CplrDetStatus_e
    {
        e_Cplr_Not_Valid = 0,
        e_Cplr_Not_Detected = 1,
        e_Cplr_Detected = 2,
        e_Cplr_Size_Enforcer = 0xFFFFFFFFu
    };

    enum TrlrDetStatus_e
    {
        e_Trlr_Not_Valid = 0,
        e_Trlr_Not_Detected = 1,
        e_Trlr_Detected = 2,
        e_Trlr_Size_Enforcer = 0xFFFFFFFFu
    };

    enum ObjTrkStatus_e
    {
        e_Not_Tracked = 0,
        e_Tracked = 1,
        e_ObjTrk_Size_Enforcer = 0xFFFFFFFFu
    };
    enum AlgoState_e
    {
        e_PS_Inactive = 0,
        e_PS_Initialization = 1,
        e_PS_WaitUserInput = 2,
        e_PS_WaitHitch = 3,
        e_PS_WaitCoupler_UserSel = 4,
        e_PS_WaitCoupler = 5,
        e_PS_WaitCouplerAngle = 6,
        e_PS_WaitHitchCouplerHeight = 7,
        e_PS_CouplerConfirmComplete = 8,
        e_PS_Size_Enforcer = 0xFFFFFFFFu
    };

} // namespace tha
#endif // !THA_DEFS_H
