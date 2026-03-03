/// --------------------------------------------------------------------------
/// @file JobTHAOutput.h
/// @brief Contains THA detection output structure definition
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Jignesh Vasoya (jignesh.vasoya@magna.com)
/// --------------------------------------------------------------------------


#ifndef JOB_THA_OUTPUT_H
#define JOB_THA_OUTPUT_H

#include "CppAdaptation.h"
#include "ITHADefs.h"
#include "PlatformDataTypes.h"

typedef struct JobTHADetOutput_s
{
    
    /*
    * Detection output parameters
    */

    /*
    @@ SUB_STRUCTURE = HitchLoc_p3f
    @@ STRUCTURE = JobTHADetOutput_t
    @@ DATA_TYPE = STRUCTURE Point3f
    @@ END
    */
    Point3f_c HitchLoc_p3f;                   /* Hitch location in real world (Future purpose) */

    /*
    @@ SUB_STRUCTURE = HitchPix_p2d
    @@ STRUCTURE = JobTHADetOutput_t
    @@ DATA_TYPE = STRUCTURE Point2i
    @@ END
    */
    Point2i_c HitchPix_p2d;                   /* <IPC signal name: MeTHA_px_HitchPnt> Hitch pixel position in rear view image */

    /*
    @@ SUB_STRUCTURE = CplrLoc_p3f
    @@ STRUCTURE = JobTHADetOutput_t
    @@ DATA_TYPE = STRUCTURE Point3f
    @@ END
    */
    Point3f_c CplrLoc_p3f;                    /* Coupler ball location in real world (Future purpose)*/

    /*
    @@ SUB_STRUCTURE = CplrPix_p2d
    @@ STRUCTURE = JobTHADetOutput_t
    @@ DATA_TYPE = STRUCTURE Point2i
    @@ END
    */
    Point2i_c CplrPix_p2d;                    /* <IPC signal name: MeTHA_px_CplrPnt> Coupler ball pixel position in rear view image */

    /*
    @@ ELEMENT = CplrAng_f32
    @@ STRUCTURE = JobTHADetOutput_t
    @@ A2L_TYPE = MEASURE
    @@ DATA_TYPE = FLOAT
    @@ END
    */
    float32_t CplrAng_f32;                  /* <IPC signal name: MeTHA_deg_CplrAng> Coupler angle in deg */

    /*
    @@ ELEMENT = CplrDist_f32
    @@ STRUCTURE = JobTHADetOutput_t
    @@ A2L_TYPE = MEASURE
    @@ DATA_TYPE = FLOAT
    @@ END
    */
    float32_t CplrDist_f32;                 /* Coupler to hitch distance */
    /*
        @@ ELEMENT = HitchDetctStatus_e
        @@ STRUCTURE = JobTHADetOutput_t
        @@ A2L_TYPE = MEASURE
        @@ DATA_TYPE = UBYTE
        @@ END
        */
    HitchDetStatus_e HitchDetctStatus_e;    /* <IPC signal name: MeTHA_e_HitchDetctStatus> Hitch detection status */

    /*
    @@ ELEMENT = CplrDetctStatus_e
    @@ STRUCTURE = JobTHADetOutput_t
    @@ A2L_TYPE = MEASURE
    @@ DATA_TYPE = UBYTE
    @@ END
    */
    CplrDetStatus_e CplrDetctStatus_e;      /* <IPC signal name: MeTHA_e_CplrDetctStatus> Coupler ball detection status */

    /*
    @@ ELEMENT = HitchCplrPixDiffLongY_s32
    @@ STRUCTURE = JobTHADetOutput_t
    @@ A2L_TYPE = MEASURE
    @@ DATA_TYPE = UWORD
    @@ END
    */
    sint32_t HitchCplrPixDiffLongY_s32;     /* <IPC signal name: MeTHA_px_HitchCplrPixDiffLong> Hitch coupler longitudinal (pix Y) difference */

    /*
    @@ ELEMENT = HitchCplrPixDiffLatX_s32
    @@ STRUCTURE = JobTHADetOutput_t
    @@ A2L_TYPE = MEASURE
    @@ DATA_TYPE = UWORD
    @@ END
    */
    sint32_t HitchCplrPixDiffLatX_s32;      /* <IPC signal name: MeTHA_px_HitchCplrPixDiffLat> Hitch coupler lateral (pix X) difference */

    /*
    @@ ELEMENT = CplrDetctConf_u8
    @@ STRUCTURE = JobTHADetOutput_t
    @@ A2L_TYPE = MEASURE
    @@ DATA_TYPE = UBYTE
    @@ END
    */
    uint8_t CplrDetctConf_u8; /* <IPC signal name: MeTHA_pct_CplrDetConf> DID: Trailer coupler detection confidence */

    /*
    @@ ELEMENT = CplrTrackConf_u8
    @@ STRUCTURE = JobTHADetOutput_t
    @@ A2L_TYPE = MEASURE
    @@ DATA_TYPE = UBYTE
    @@ END
    */
    uint8_t CplrTrackConf_u8; /* <IPC signal name: MeTHA_pct_CplrTrckConf> DID: Trailer coupler tracking confidence */

    /*
    @@ ELEMENT = StatusCplrZone_b
    @@ STRUCTURE = JobTHADetOutput_t
    @@ A2L_TYPE = MEASURE
    @@ DATA_TYPE = UBYTE [0 ... 1]
    @@ END
    */
    bool_t StatusCplrZone_b;                /* Status of coupler inside the detection range (Future purpose) */

    /*
    @@ ELEMENT = CplrAngFound_b
    @@ STRUCTURE = JobTHADetOutput_t
    @@ A2L_TYPE = MEASURE
    @@ DATA_TYPE = UBYTE [0 ... 1]
    @@ END
    */
    bool_t CplrAngFound_b;                  /* Coupler angle found status */

    /*
    @@ ELEMENT = TrlrCplrStatus_b
    @@ STRUCTURE = JobTHADetOutput_t
    @@ A2L_TYPE = MEASURE
    @@ DATA_TYPE = UBYTE [0 ... 1]
    @@ END
    */
    bool_t TrlrCplrStatus_b;                /* Traile coupler reached status */

} JobTHADetOutput_t;

typedef struct JobTHADetDebug_s
{
    /*
    * Detection debug output parameters
    */
    /*
    @@ ELEMENT = TrlrDetctStatus_e
    @@ STRUCTURE = JobTHADetDebug_t
    @@ A2L_TYPE = MEASURE
    @@ DATA_TYPE = UBYTE
    @@ END
    */
    TrlrDetStatus_e TrlrDetctStatus_e;
    /*
    @@ SUB_STRUCTURE = TrlrPnt_p2d
    @@ STRUCTURE = JobTHADetDebug_t
    @@ DATA_TYPE = STRUCTURE Point2i
    @@ END
    */
    Point2i_c TrlrPnt_p2d;                 /* Trialer base pixel position in rear view image */

#ifdef _WIN32
   Point2i_c TrlrBasePnt_p2d;                 /* Trailer base pixel position in rear view image */
    /*
    @@ SUB_STRUCTURE = TrlrBaseLoc_p3f
    @@ STRUCTURE = JobTHAAlgoDetDebug_t
    @@ DATA_TYPE = STRUCTURE Point3f
    @@ END
    */
    Point3f_c TrlrBaseLoc_p3f;                 /* Trialer base location in real world */
    /*
    @@ SUB_STRUCTURE = TrlrLoc_p3f
    @@ STRUCTURE = JobTHAAlgoDetDebug_t
    @@ DATA_TYPE = STRUCTURE Point3f
    @@ END
    */
    Point3f_c TrlrLoc_p3f;                 /* Trialer base location in real world (Future purpose)*/               /* Trialer base location in real world (Future purpose)*/
    /*
    @@ SUB_STRUCTURE = TrlrBB
    @@ STRUCTURE = JobTHADetDebug_t
    @@ DATA_TYPE = STRUCTURE Recti
    @@ END
    */
    Recti_c TrlrBB;
    /*
    @@ SUB_STRUCTURE = CplrBB
    @@ STRUCTURE = JobTHADetDebug_t
    @@ DATA_TYPE = STRUCTURE Recti
    @@ END
    */
    Recti_c CplrBB;
    /*
    @@ SUB_STRUCTURE = HitchBB
    @@ STRUCTURE = JobTHADetDebug_t
    @@ DATA_TYPE = STRUCTURE Recti
    @@ END
    */
    Recti_c HitchBB;
    int16_t DynCrpStartX;               /*Dynamic crop rect start X*/
    int16_t DynCrpStartY;               /*Dynamic crop rect start Y*/
    uint8_t TrlrDetConf;
    uint8_t CplrRegDetConf;
    uint8_t TrkdObjInfo;
    CplrDetStatus_e CplrBallDetctStatus_e;
    CplrDetStatus_e CplrRegDetctStatus_e;
    Point2i_c CplrRegPnt_p2d;
    Recti_c CplrRegBB;
#endif // _WIN32
} JobTHADetDebug_t;

#endif // !JOB_THA_OUTPUT_H