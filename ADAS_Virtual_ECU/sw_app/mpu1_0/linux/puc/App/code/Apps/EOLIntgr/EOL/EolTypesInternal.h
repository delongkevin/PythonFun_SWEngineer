//--------------------------------------------------------------------------
/// @file EolTypesInternal.h
/// @brief Contains internal Eol types
///
///
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Muzammil Rasool (muzammil.rasool@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef EOLTYPESINTERNAL_H_
#define EOLTYPESINTERNAL_H_

#include "EolConfig.h"
#include "mecl/mecl.h"

#define HC_EOL_DATA 0
#define DUMP_EOL_DATA 0
#define USE_DESIGN_VALUES 0
#define EOL_PARAMS_DEBUGGING 0
#define TARGET_SIZE 8.5F //200.0F/25.4F//8.5F //7.1F //8.5F
#define IMAGE_WIDTH 1920U
#define IMAGE_HEIGHT 1280U

namespace eol
{

typedef enum AParaMgrECalibrationType_e
{
    e_NoCalibration = 0,
    e_EndOfLineCalibration,
    e_ServiceCalibration,
    e_ServiceTadHorizontalCalibration,
    e_EndOfLineTadCalibration,
    e_EndOfLineTadVerticalCalibration,
    e_SetFromOutsideCalibration
}aParaMgr_E_CalibrationType_t;

typedef enum CameraId_e
{
    e_FrontCamAlgo = 0,
    e_LeftCamAlgo = 1,
    e_RearCamAlgo = 2,
    e_RightCamAlgo = 3
} E_CameraId_t;


enum CameraType_e
{
    e_MiamiCamera,
    e_LondonCamera,
    e_ZuerichCamera
};
typedef enum CameraType_e E_CameraType;



typedef enum ETargetSide_e {
    e_TargetLeft = 0,
    e_TargetMiddle,
    e_TargetRight
} E_TargetSide_t;

typedef struct TTarget_s
{
    E_CameraId_t        camId_e;
    E_TargetSide_t      side_e;
    sint8_t             index_s8;

    uint8_t             nx_u8;
    uint8_t             ny_u8;

    float64_t           real_af64[4][4];
    float64_t           cam_af64[3][4];
    float64_t           screen_af64[3][4];

    float64_t           h_af64[9];
    float64_t           hinv_af64[9];
} T_Target_t;

typedef struct AParaMgrSErrorStateSingle_s
{
    uint8_t status_u8;                   /* Calibration State         */
    sint8_t targetInit_s8;              /* Target Init               */
    sint8_t targetLimitF_s8;           /* Target Limit Front        */
    sint8_t targetLimitR_s8;           /* Target Limit Rear         */
    sint8_t targetDetectLF_s8;         /* Target Detect Left-Front  */
    sint8_t targetDetectLR_s8;         /* Target Detect Left-Rear   */
    sint8_t targetDetectRF_s8;         /* Target Detect Right-Front */
    sint8_t targetDetectRR_s8;         /* Target Detect Right-Rear  */
}aParaMgr_S_ErrorStateSingle_t ;

typedef struct AParaMgrSErrorState_s
{
    uint8_t targetSeparation_u8;          /* Target Separation */
    uint8_t optimizer_u8;                 /* Optimizer         */
    aParaMgr_S_ErrorStateSingle_t camState_s;
}aParaMgr_S_ErrorState_t;

typedef struct AParaMgrSCalibration_s
{
    float32_t                           camYaw_f32  ;
    float32_t                           camPitch_f32;
    float32_t                           camRoll_f32 ;
    float32_t                           camX_f32    ;
    float32_t                           camY_f32    ;
    float32_t                           camZ_f32    ;
    E_CameraId_t                        camId_e  ;
    uint8_t                         calibrationType_u8 ;
    aParaMgr_S_ErrorState_t         errorState_s;
}aParaMgr_S_Calibration_t;


typedef enum AParaMgrECalibrationStatus_e
{
    e_InProcess = 0,
    e_Success,
    e_MissingSoftware,
    e_PreconditionVrange,
    e_PreconditionNumCameras,
    e_MissingInternalLink,
    e_VariantCoding,
    e_TargetNotFoundInit,
    e_TargetNotFoundLeft,
    e_TargetNotFoundRight,
    e_TargetIdentErrorLeft,
    e_TargetIdentErrorRight,
    e_ExceededQualityLimit,
    e_NotCalibrated,
    e_Aborted,
    e_HomographyEstimationError,
    e_PreconditionVelocity,
    e_PreconditionDoors,
    e_WrongCameraSoftware,
    e_Precondition
}aParaMgr_E_CalibrationStatus_t;


} // namespace eol

#endif /* EOLTYPESINTERNAL_H_ */
