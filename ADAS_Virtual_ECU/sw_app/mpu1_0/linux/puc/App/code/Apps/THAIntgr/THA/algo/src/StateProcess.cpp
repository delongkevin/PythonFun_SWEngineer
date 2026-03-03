/// --------------------------------------------------------------------------
/// @file StateProcess.cpp
/// @brief Contains THA detection state machine, Detection calling functions
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Jignesh Vasoya (jignesh.vasoya@magna.com)
/// --------------------------------------------------------------------------
#include "StateProcess.h"
#ifdef _WIN32
    #include "THAImpl.h"
#endif
#include "../common/THADefs.h"
#include "MatrixUtils.h"

#if THA_TRACKER_UT
#include "JobTHA.h"

#include "Tracker_UT_Inputs/fp_UsrCplrSelected_b.h"
#include "Tracker_UT_Inputs/fp_UtilizeTrailerTracker.h"
#include "Tracker_UT_Inputs/fp_m_StatusCplrZone_b.h"
#include "Tracker_UT_Inputs/fp_v_CplrBallDetSts_e.h"
#include "Tracker_UT_Inputs/fp_v_CplrPix_ix.h"
#include "Tracker_UT_Inputs/fp_v_CplrPix_iy.h"
#include "Tracker_UT_Inputs/fp_v_CplrLoc_x.h"
#include "Tracker_UT_Inputs/fp_v_CplrLoc_y.h"
#include "Tracker_UT_Inputs/fp_v_CplrLoc_z.h"
#include "Tracker_UT_Inputs/fp_v_CplrBB_x.h"
#include "Tracker_UT_Inputs/fp_v_CplrBB_y.h"
#include "Tracker_UT_Inputs/fp_v_CplrBB_width.h"
#include "Tracker_UT_Inputs/fp_v_CplrBB_height.h"
#include "Tracker_UT_Inputs/fp_m_ObjTrackerStarted.h"
#include "Tracker_UT_Inputs/fp_m_CplrBallDetStsPrev_e.h"
#include "Tracker_UT_Inputs/fp_CouplerHeight.h"
#include "Tracker_UT_Inputs/fp_v_CplrRegDetSts_e.h"
#include "Tracker_UT_Inputs/fp_v_CplrRegPix_x.h"
#include "Tracker_UT_Inputs/fp_v_CplrRegPix_y.h"
#include "Tracker_UT_Inputs/fp_v_CplrRegLoc_x.h"
#include "Tracker_UT_Inputs/fp_v_CplrRegLoc_y.h"
#include "Tracker_UT_Inputs/fp_v_CplrRegLoc_z.h"
#include "Tracker_UT_Inputs/fp_v_CplrRegBB_x.h"
#include "Tracker_UT_Inputs/fp_v_CplrRegBB_y.h"
#include "Tracker_UT_Inputs/fp_v_CplrRegBB_width.h"
#include "Tracker_UT_Inputs/fp_v_CplrRegBB_height.h"
#include "Tracker_UT_Inputs/fp_m_CplrRegDetStsPrev_e.h"
#include "Tracker_UT_Inputs/fp_v_TrlrDetSts_e.h"
#include "Tracker_UT_Inputs/fp_m_TrlrDetStsPrev_e.h"
#include "Tracker_UT_Inputs/fp_CplrPixX_u16.h"
#include "Tracker_UT_Inputs/fp_CplrPixY_u16.h"
#include "Tracker_UT_Inputs/fp_v_TrlrPix_x.h"
#include "Tracker_UT_Inputs/fp_v_TrlrPix_y.h"
#include "Tracker_UT_Inputs/fp_v_CplrPix_x.h"
#include "Tracker_UT_Inputs/fp_v_CplrPix_y.h"
volatile uint16_t u16FrameNo = 0;
#endif //THA_TRACKER_UT

#if 0
// Dipti : TrailerPose V14 hence 30 classes in classList
char* classList[30]= {"-60", "-50", "-40", "-30", "-20", "-10", "0", "10", "20", "30", "40", "50", "60",
"-0060", "-0050", "-0040", "-0030", "-0020", "-0010", "00000", "00010", "00020", "00030", "00040", "00050", "00060", "-90", "90", "-0090", "00090"};
#endif

// Dipti : Cropped Image for TrailerPose
#define inputTensorSize ((uint32_t)112*112*3) //As trailerPose requires 112*112*3
static uint8_t TrailerPoseDNNInput_img[inputTensorSize];// RGB = (112*112*3)

// Get RGB image for DNN models
#define rgb_image_size ((uint32_t)409600) // One plane = (640w x 640h )
static uint8_t DetDNNInput_img[rgb_image_size*3];// RGB = (640w x 640h )*3

#if ENABLE_DEBUG_THA
static osal::Time v_Time_o;
uint64_t timeStamp = 0;
#endif
//======================= Setup ===================================
namespace tha
{
    StateProcess::StateProcess() :
#ifdef OD_TRACKER
        m_ObjTrackerStarted( false ),
#endif // OD_TRACKER 
        m_InitCplrAngFound_b( false ),
        m_InitHitchFound_b( false ),
#ifdef OD_ONNX
#ifdef _WIN32
        m_pOnnxDetector( NULL ),
        m_pOnnxClassifier( NULL ),
#endif
#endif // OD_ONNX
        m_WaitFrameCountAngle( 0 ),
        m_WaitFrameCountHitchBB( 0 ),
        m_WaitFrameCount( 0 ),
#ifdef OD_TRACKER
        m_CouplerTrackerObj( m_TrailerTrackConfig )
#endif // OD_TRACKER     
    {
#ifdef OD_TRACKER
        m_ObjTrackerStarted = false;
#endif // OD_TRACKER
        m_InitCplrAngFound_b = false;
        m_InitHitchFound_b = false;
#ifdef OD_ONNX
#ifdef _WIN32
        m_pOnnxDetector = NULL;
        m_pOnnxClassifier = NULL;
#endif
#endif // OD_ONNX
        m_WaitFrameCountAngle = 0;
        m_WaitFrameCountHitchBB = 0;
        m_WaitFrameCount = 0;
    }

StateProcess::~StateProcess()
{
#ifdef OD_ONNX
#ifdef _WIN32

    if( m_pOnnxEnv != NULL )
    {
        m_pOnnxEnv->release();
    }

    if( m_pOnnxDetector != NULL )
    {
        delete m_pOnnxDetector;
    }

    if( m_pOnnxClassifier != NULL )
    {
        delete m_pOnnxClassifier;
    }

#endif //_WIN32
#endif // OD_ONNX
}
    /*
    * Name: Init
    * Remarks: DD-ID: {A69ECC1B-012A-4ffd-8312-3B0224901328}
    * Remarks: DD-ID: {772632F0-39D2-441b-8692-4CAD3AB84824}
    */
void StateProcess::Init()
{
    Reset();
    m_WaitFrameCountAngle = 0;
    m_WaitFrameCount = 0;
    m_WaitFrameCountHitchBB = 0;
    /*
    * Detection parameter
    */
    m_StatusCplrZone_b = false;
    m_CplrBallDetStsPrev_e = e_Cplr_Not_Valid;
    m_CplrRegDetStsPrev_e = e_Cplr_Not_Valid;
    m_TrlrDetStsPrev_e = e_Trlr_Not_Valid;
    m_HitchDetStsPrev_e = e_Hitch_Not_Valid;
#ifdef OD_TRACKER
        m_TrkdObjInfo = 0;
    {
            m_CouplerTrackerObj.setImgWidth( 640 );
            m_CouplerTrackerObj.setImgHeight( 400 );
        m_CouplerTrackerObj.Init();
    }
#endif // OD_TRACKER
        m_TrackerResizeFactorW = static_cast<float32_t>( m_ImgWidth ) / static_cast<float32_t>( m_CouplerTrackerObj.getImgWidth() );
        m_TrackerResizeFactorH = static_cast<float32_t>( m_ImgHeight ) / static_cast<float32_t>( m_CouplerTrackerObj.getImgHeight() );
        m_HitchPixPrev = Point2i( static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorW ), static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorH ) );
        m_CplrPixPrev = Point2i( static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorW ), static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorH ) );
        m_CplrRegPixPrev = Point2i( static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorW ), static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorH ) );
        m_TrlrPixPrev = Point2i( static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorW ), static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorH ) );
        m_OpPixPrev = Point2i( static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorW ) , static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorH ) );
        m_TrlrBaseLocPrev = Point3f( ( static_cast<float32_t>( m_Cfg.getDefaultHitchX_mm() ) / 1000.0f ),
                                     ( static_cast<float32_t>( m_Cfg.getDefaultHitchY_mm() ) / 1000.0f ),
                                     ( static_cast<float32_t>( m_Cfg.getDefaultHitchZ_mm() ) / 1000.0f ) );
    m_InitCplrAngFound_b = false;
    m_InitHitchFound_b = false;
    m_CplrToHitchReachStatus_b = false;
        m_InitCplrAng = m_Cfg.getDefaultTrailerAngle_deg();
    m_InitCplrHtichEucDist = 0;
    m_EucDistThrshCplrBall = 0;
    m_EucDistThrshCplrReg = 0;
    m_EucDistThrshTrlr = 0;
#if ENABLE_SMOOTH_OP
    m_CplrXBuff[m_CplrPntBuffSize] = { 0 };
    m_CplrYBuff[m_CplrPntBuffSize] = { 0 };
    m_IndxCplrPnt = 0;
#endif // ENABLE_SMOOTH_OP
#ifdef OD_TRACKER
    m_ObjTrackerStarted = false;
#endif // OD_TRACKER
#ifdef _WIN32
        m_DynCrpStartX = ( m_ImgWidth / 2 ) - ( m_Cfg.getDetDNNInputDimW() / 2 );
        m_DynCrpStartY = m_ImgHeight - m_Cfg.getDetDNNInputDimW();
#endif // _WIN32
}
    /*
    * Name: Reset
    * Remarks: DD-ID: {B465856A-6A18-453e-93E2-5D4BA67EC37E}
    * Remarks: DD-ID: {F9BD0433-80D6-47bc-BD20-6D95BD0249D9}
    */
void StateProcess::Reset()
{
    /*
    * Detection parameter
    */
    m_StatusCplrZone_b = false;
    m_CplrBallDetStsPrev_e = e_Cplr_Not_Valid;
    m_CplrRegDetStsPrev_e = e_Cplr_Not_Valid;
    m_TrlrDetStsPrev_e = e_Trlr_Not_Valid;
    m_HitchDetStsPrev_e = e_Hitch_Not_Valid;
        m_HitchPixPrev = Point2i( static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchX_pix() ) * m_TrackerResizeFactorW ), static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorH ) );
        m_CplrPixPrev = Point2i( static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchX_pix() ) * m_TrackerResizeFactorW ), static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorH ) );
        m_CplrRegPixPrev = Point2i( static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchX_pix() ) * m_TrackerResizeFactorW ), static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorH ) );
        m_TrlrPixPrev = Point2i( static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchX_pix() ) * m_TrackerResizeFactorW ), static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorH ) );
        m_OpPixPrev = Point2i( static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchX_pix() ) * m_TrackerResizeFactorW ), static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorH ) );
        m_TrlrBaseLocPrev = Point3f( ( static_cast<float32_t>( m_Cfg.getDefaultHitchX_mm() ) / 1000.0f ),
                                     ( static_cast<float32_t>( m_Cfg.getDefaultHitchY_mm() ) / 1000.0f ),
                                     ( static_cast<float32_t>( m_Cfg.getDefaultHitchZ_mm() ) / 1000.0f ) );
        m_InitCplrAngFound_b = false;
    m_InitHitchFound_b = false;
        m_InitCplrAng = m_Cfg.getDefaultTrailerAngle_deg();
        /*
         * m_CplrToHitchReachStatus_b = false;
         */
    m_WaitFrameCountAngle = 0;
    m_WaitFrameCount = 0;
    m_WaitFrameCountHitchBB = 0;
    m_ValidTrlrRectCurr = Recti( 0, 0, 0, 0 );
    m_ValidCplrRegRectCurr = Recti( 0, 0, 0, 0 );
    m_ValidCplrBallRectCurr = Recti( 0, 0, 0, 0 );
    m_ValidTrlrRectCurr_b = false;
    m_ValidCplrRegRectCurr_b = false;
    m_ValidCplrBallRectCurr_b = false;
    m_InitCplrHtichEucDist = 0;
    m_InitCplrHtichEucDist = 0;
    m_EucDistThrshCplrBall = 0;
    m_EucDistThrshCplrReg = 0;
    m_EucDistThrshTrlr = 0;
#if ENABLE_SMOOTH_OP
    m_CplrXBuff[m_CplrPntBuffSize] = { 0 };
    m_CplrYBuff[m_CplrPntBuffSize] = { 0 };
    m_IndxCplrPnt = 0;
#endif // ENABLE_SMOOTH_OP
        memset( m_CplrBallDetConfBuffer, 0, 5 * sizeof( float32_t ) ); //PRQA S 3840
        memset( m_CplrRegDetConfBuffer, 0, 5 * sizeof( float32_t ) ); //PRQA S 3840
        memset( m_TrlrDetConfBuffer, 0, 5 * sizeof( float32_t ) ); //PRQA S 3840
    m_IndxDetConf = 0;
    // --- Reset output parameters
    m_THADetOutput = {};
    m_THADetDebugOutput = {};

    if( m_ObjList.size_u32() > 0 )
    {
        m_ObjList.clear_v();
    }

#ifdef OD_TRACKER
        m_TrkdObjInfo = 0;

        if( ( m_ObjTrackerStarted == true ) && ( m_Cfg.getUtilizeTrailerTracker() == true ) )
    {
        m_CouplerTrackerObj.Close();
        m_ObjTrackerStarted = false;
    }

#endif // OD_TRACKER
#ifdef _WIN32
        m_DynCrpStartX = ( m_ImgWidth / 2 ) - ( m_Cfg.getDetDNNInputDimW() / 2 );
        m_DynCrpStartY = m_ImgHeight - m_Cfg.getDetDNNInputDimW();
#endif // _WIN32
}
    /*
    * Name: ProcessTHASM
    * Function: ProcessTHASM : THA SM determines the THA detection algorithm state
      based on which corresponding detection function will be called.
    * Remarks: DD-ID: {510F8CAC-CAA8-4b56-B7D4-EC2F33E41F08}
    * Remarks: DD-ID: {BF891AD9-ED34-44b6-B22C-8A321CF65880}
    */
#ifdef _WIN32
    void StateProcess::ProcessTHASM()
#else
    void StateProcess::ProcessTHASM( AppObj_CD_HD* TIObj_s_CD_HD, AppObj_TrailerPose* TIObj_s_TrailerPose )
#endif //_WIN32
{
    /*
    * Tunabale parameters
    */
    uint16_t v_MaxEucDistThrshTrlr = 128;
    uint16_t v_MinEucDistThrshTrlr = 64;
    uint16_t v_MaxEucDistThrshCplrReg = 64;
    uint16_t v_MinEucDistThrshCplrReg = 32;
    uint16_t v_MaxEucDistThrshCplrBall = 32;
    uint16_t v_MinEucDistThrshCplrBall = 16;
    /*
    * Hitch detection data
    */
    HitchDetStatus_e v_HitchDetSts_e = e_Hitch_Not_Valid;
        Point3f v_HitchLoc = Point3f( ( static_cast<float32_t>( m_Cfg.getDefaultHitchX_mm() ) / 1000.0f ),
                                      ( static_cast<float32_t>( m_Cfg.getDefaultHitchY_mm() ) / 1000.0f ),
                                      ( static_cast<float32_t>( m_Cfg.getDefaultHitchZ_mm() ) / 1000.0f ) ); /* (x, y, z) = (10, 0, 30) in cm  */
        Point2i v_DefaultPix = Point2i( static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchX_pix() ) * m_TrackerResizeFactorW ), static_cast<int32_t>( static_cast<float32_t>( m_Cfg.getDefaultHitchY_pix() ) * m_TrackerResizeFactorH ) );
        Point2i v_HitchPix = v_DefaultPix;
    Recti v_HitchBB = Recti( 0, 0, 0, 0 );
    /*
    * Trailer detection data
    */
    TrlrDetStatus_e v_TrlrDetSts_e = e_Trlr_Not_Valid;
    Point3f v_TrlrLoc = v_HitchLoc;
    Point2i v_TrlrPix = v_HitchPix;
    Point2i v_TrlrBasePix = v_HitchPix;
    Point3f v_TrlrBaseLoc = v_HitchLoc;
    Recti v_TrlrBB = Recti( 0, 0, 0, 0 );
    /*
    * Coupler detection data
    */
    CplrDetStatus_e v_CplrDetSts_e = e_Cplr_Not_Valid;
    CplrDetStatus_e v_CplrBallDetSts_e = e_Cplr_Not_Valid;
    CplrDetStatus_e v_CplrRegDetSts_e = e_Cplr_Not_Valid;
    Point3f v_CplrLoc = v_HitchLoc; /* (x, y, z) = (10, 0, 30) in cm  */
    Point3f v_CplrBallLoc = v_HitchLoc; /* (x, y, z) = (10, 0, 30) in cm  */
    Point3f v_CplrRegLoc = v_HitchLoc; /* (x, y, z) = (10, 0, 30) in cm  */
    Point2i v_CplrPix = v_HitchPix;
    Point2i v_CplrBallPix = v_HitchPix;
    Point2i v_CplrRegPix = v_HitchPix;
    Recti v_CplrBB = Recti( 0, 0, 0, 0 );
    Recti v_CplrBallBB = Recti( 0, 0, 0, 0 );
    Recti v_CplrRegBB = Recti( 0, 0, 0, 0 );
    float32_t v_CplrBallDetConf = 0.0f;
    float32_t v_CplrRegDetConf = 0.0f;
    float32_t v_TrlrDetConf = 0.0f;
    m_ValidTrlrRectCurr_b = false;
    m_ValidCplrRegRectCurr_b = false;
    m_ValidCplrBallRectCurr_b = false;
    /*Detection confidence Threshold*/
    float32_t v_DetConfThrsh = 0.60;
    /*
    * Trailer Angle data
    */
        /*
         * bool_t v_CplrAngFound_b = false;
         */
    bool_t v_CplrAngSteep_b = true;
        float32_t v_TrailerCplrAng_f32 = m_Cfg.getDefaultTrailerAngle_deg();
    /*
    * Coupler to hitch distance
    */
    float32_t v_CplrToHitch_f32 = 0.0f; // Default value. Can be modified to other based on test
    float32_t v_CplrToHitchLat_f32 = 0.0f; // Default value. Can be modified to other based on test
    bool_t v_return_b = false;
    JobTHAAlgoDetOutput_t v_THAInfo_s = {};
    JobTHAAlgoDetDebug_t v_THAInfoDebug_s = {};
    /*
    * Detection parameters
    */
    //--- Obj detection para
    bool_t v_detectionSuccess_b = false;
    //--- Feature Ouput para
    ODInfo Obj_Info;
#ifdef OD_TRACKER
    //--- Obj Tracking para
    bool_t v_ObjTrackGoodConf_b = false;
    float32_t v_ObjTrackConf = 0.0f;
        ObjTrkStatus_e v_ObjTrkSts_e = e_Not_Tracked;
#endif // OD_TRACKER
    //--- Reset detections' info
    m_ObjList.clear_v();
#if !THA_TRACKER_UT
    // --- Run THA detection only into valid State. Reset detection if state is chagned from valid state to any other.
    if( ( m_JobTHAInput.SMInput_s.THASmState_e != THAState_e::e_EnabledSelection ) &&
        ( m_JobTHAInput.SMInput_s.THASmState_e != THAState_e::e_Engaged ) &&
        ( m_JobTHAInput.SMInput_s.THASmState_e != THAState_e::e_EngagedDelta ) )
    {
        v_return_b = true;
        Reset();
    }
	#if ENABLE_DEBUG_THA
        timeStamp = v_Time_o.getTimeMsec_u64();
        ME_Debugger_F_Printf_v("\n ### THA:StateProcess::Time:%lld,State_e=%d v_return_b=%d ### \n ",timeStamp,m_JobTHAInput.SMInput_s.THASmState_e, v_return_b);
    #endif //ENABLE_DEBUG_THA
    // if coupler is not selected by user, Reset trailer angle and coupler inside zone status flag
    if( m_JobTHAInput.SMInput_s.UsrCplrSelected_b == false )
    {
        m_InitCplrAngFound_b = false;
            m_InitCplrAng = m_Cfg.getDefaultTrailerAngle_deg();
        m_StatusCplrZone_b = false;
        m_WaitFrameCountAngle = 0;
        m_CplrToHitchReachStatus_b = false;
    }

    /*
    * Run detection if Gear is R and Veh speed < v_VehSpdThresh_f32
    */
    if( v_return_b == false )
    {
        switch( m_JobTHAInput.SMInput_s.THASmState_e )
        {
            case THAState_e::e_SNA:
            {
                v_return_b = true;
                break;
            }

            case THAState_e::e_Faulted:
            {
                v_return_b = true;
                break;
            }

            case THAState_e::e_Off:
            {
                v_return_b = true;
                break;
            }

            case THAState_e::e_Initial:
            {
                v_return_b = true;
                break;
            }

            case THAState_e::e_Idle:
            {
                v_return_b = true;
                break;
            }

            case THAState_e::e_Enabled:
            {
                v_return_b = true;
                break;
            }

            case THAState_e::e_EnabledSelection:
            case THAState_e::e_Engaged:
            case THAState_e::e_EngagedDelta:
            case THAState_e::e_EngagedInquiry:
            {
                #if ENABLE_DEBUG_THA
                  ME_Debugger_F_Printf_v("\n ### THA: StateProcess::%d,%d### \n",m_HitchDetStsPrev_e,m_JobTHAInput.SMInput_s.UsrCplrSelected_b);
                #endif //ENABLE_DEBUG_THA
                if( ( m_JobTHAInput.SMInput_s.UsrCplrSelected_b == false ) &&
                    ( m_HitchDetStsPrev_e != e_Hitch_Not_Valid ) )
                {
                    v_return_b = true;
                    break;
                }

                /*
                * Run Detection
                */
#ifdef OD_ONNX
                #if ENABLE_DEBUG_THA
                  ME_Debugger_F_Printf_v("\n ### THA: StateProcess::ProcessTHASM b4 Onnx_CD_HD_Run ### \n ");
                #endif
#ifdef _WIN32
                v_detectionSuccess_b = Onnx_CD_HD_Run();
#else
                #if ENABLE_CD_HD
                #if PROFILE_THA
                osal::Time v_Time_o;
                uint64_t v_StartTime_u64 = 0;
                uint64_t v_EndTime_u64 = 0;
                static uint64_t v_TotalTime_u64 = 0;
                v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
                #endif
                v_detectionSuccess_b = Onnx_CD_HD_Run(TIObj_s_CD_HD);
                #if PROFILE_THA
                v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
                v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
                ME_Debugger_F_Printf_v("\ncdhd_run: %f ms ", (float32_t)(v_TotalTime_u64 * 1.0f));
                #endif//PROFILE_THA
                #endif
#endif // _WIN32
#endif // OD_ONNX

                if( ( m_HitchDetStsPrev_e != e_Hitch_Detected ) && ( m_WaitFrameCount > 14 ) )
                {
                    v_HitchDetSts_e = e_Hitch_Not_Detected;
                    m_HitchDetStsPrev_e = e_Hitch_Not_Detected;
                }
                else if( m_WaitFrameCount < 17 )
                {
                    m_WaitFrameCount = m_WaitFrameCount + 1;
                }
                else
                {
                    // Do Nothing:MISRA 4070
                }

                //--- Update Hitch Detection
                if( v_detectionSuccess_b && ( m_HitchDetStsPrev_e == e_Hitch_Not_Valid ) )
                {
                    if( IsObjectFound( m_ObjList, Obj_Hitch, Obj_Info ) )
                    {
                            v_HitchLoc = Obj_Info.getPoint_3D();
                            v_HitchPix = Obj_Info.getPoint_2D();
                            v_HitchBB = Obj_Info.getRect();

                        //--- + KF based Hitch BB smoothing
                            if( m_Cfg.getEnableKFSmooth() == true )
                        {
                            if( ( m_InitHitchFound_b == true ) )
                            {
                                if( m_HitchDetStsPrev_e != e_Hitch_Detected )
                                {
                                    if( ( mecl::math::abs_x( m_HitchPixPrev.x - v_HitchPix.x ) <= m_KFSmoothThresh ) && ( mecl::math::abs_x( m_HitchPixPrev.y - v_HitchPix.y ) <= m_KFSmoothThresh ) )
                                    {
                                        Recti v_HitchBBTemp = Recti( 0, 0, 0, 0 );
                                        v_HitchBBTemp = KFSmoothHitchBB( v_HitchBB );
                                        v_HitchBB = v_HitchBBTemp;
                                        v_HitchPix.x = ( v_HitchBBTemp.x + ( v_HitchBBTemp.width / 2 ) );
                                        v_HitchPix.y = ( v_HitchBBTemp.y + ( v_HitchBBTemp.height / 2 ) );
                                        Point2i v_TempCplrGnd = Point2i( 0, 0 );
                                        #ifdef _WIN32
                                        ConvertPointImage2WCS( v_HitchPix, v_HitchLoc, v_TempCplrGnd, static_cast<float32_t>( m_Cfg.getCouplerHeight() ) );
                                        #else
                                        Image2WorldCS( v_HitchPix, v_HitchLoc, static_cast<float32_t>( m_Cfg.getCouplerHeight()), m_ImgWidth, m_ImgHeight );
                                        #endif
                                        m_HitchBBPrev = v_HitchBB;
                                        m_HitchPixPrev = v_HitchPix;
                                        m_WaitFrameCountHitchBB = m_WaitFrameCountHitchBB + 1;

                                        if( m_WaitFrameCountHitchBB > 9 )
                                        {
                                            m_HitchDetStsPrev_e = e_Hitch_Detected;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                m_InitHitchFound_b = true;
                                m_WaitFrameCountHitchBB = m_WaitFrameCountHitchBB + 1;
                                m_HitchPixPrev = v_HitchPix;
                            }
                        }
                        else
                        {
                            m_HitchBBPrev = v_HitchBB;
                            m_HitchPixPrev = v_HitchPix;
                            m_HitchDetStsPrev_e = e_Hitch_Detected;
                        }

                        //--- - KF based Hitch BB smoothing
                    }
                }

                //--- Update Trailer Detection
                if( m_JobTHAInput.SMInput_s.UsrCplrSelected_b == true )
                {
                    if( v_detectionSuccess_b == true )
                    {
                        if( IsObjectFound( m_ObjList, Obj_Trailer, Obj_Info ) )
                        {
                            v_TrlrDetSts_e = TrlrDetStatus_e::e_Trlr_Detected;
                                v_TrlrLoc = Obj_Info.getPoint_3D();
                                v_TrlrBB = Obj_Info.getRect();
                                v_TrlrPix = Obj_Info.getPoint_2D();
                                v_TrlrBasePix = Obj_Info.getPoint_2D();
                                v_TrlrBaseLoc = Obj_Info.getPoint_3D();
                                // Smooth trailer base point
                                KFSmoothTrlrBasePoint( v_TrlrBaseLoc );
                                m_TrlrBaseLocPrev = v_TrlrBaseLoc;
                            m_TrlrPixPrev = v_TrlrPix;
                                v_TrlrDetConf = Obj_Info.getDetConf();
                            m_ValidTrlrRectCurr = v_TrlrBB;
                            m_ValidTrlrRectCurr_b = true;
                        }
                        else // Detection found but Trailer not found
                        {
                            v_TrlrDetSts_e = TrlrDetStatus_e::e_Trlr_Not_Detected;
                        }
                    }
                    else // Detection not found
                    {
                        v_TrlrDetSts_e = TrlrDetStatus_e::e_Trlr_Not_Detected;
                    }
                }

                //--- Update Coupler Detection
                if( m_JobTHAInput.SMInput_s.UsrCplrSelected_b == true )
                {
                    if( v_detectionSuccess_b == true )
                    {
                        if( IsObjectFound( m_ObjList, Obj_CouplerReg, Obj_Info ) )
                        {
                            v_CplrRegDetSts_e = e_Cplr_Detected;
                                v_CplrRegLoc = Obj_Info.getPoint_3D();
                                v_CplrRegBB = Obj_Info.getRect();
                                v_CplrRegPix = Obj_Info.getPoint_2D();
                                v_CplrRegDetConf = Obj_Info.getDetConf();
                            m_CplrRegPixPrev = v_CplrRegPix;
                            m_ValidCplrRegRectCurr = v_CplrRegBB;
                            m_ValidCplrRegRectCurr_b = true;

                            if( v_TrlrDetSts_e == e_Trlr_Detected )
                            {
                                if( IsCouplerInsideTrailer( v_TrlrBB, v_CplrRegPix ) == true )
                                {
                                    v_CplrRegDetSts_e = e_Cplr_Detected;
                                        v_CplrRegLoc = Obj_Info.getPoint_3D();
                                        v_CplrRegBB = Obj_Info.getRect();
                                    // Get approx coupler point
                                    v_CplrRegPix = getApproxCoupler( v_CplrRegBB, v_TrlrBB, m_ImgHeight, m_HitchDetStsPrev_e, m_HitchPixPrev.y );
                                }
                                else // Coupler region is outside trailer BB
                                {
                                    v_CplrRegDetSts_e = e_Cplr_Not_Detected;
                                    v_CplrRegLoc = v_HitchLoc;
                                    v_CplrRegPix = v_HitchPix;
                                }
                            }
                            else // Trailer is not detected
                            {
                                v_CplrRegDetSts_e = e_Cplr_Detected;
                            }
                        }
                        else // Detection found but coupler region not detected
                        {
                            v_CplrRegDetSts_e = e_Cplr_Not_Detected;
                        }

                        if( IsObjectFound( m_ObjList, Obj_Coupler, Obj_Info ) )
                        {
                            v_CplrBallDetSts_e = e_Cplr_Detected;
                                v_CplrBallLoc = Obj_Info.getPoint_3D();
                                v_CplrBallBB = Obj_Info.getRect();
                                v_CplrBallPix = Obj_Info.getPoint_2D();
                                v_CplrBallDetConf = Obj_Info.getDetConf();
                            m_CplrPixPrev = v_CplrBallPix;
                            m_ValidCplrBallRectCurr = v_CplrBallBB;
                            m_ValidCplrBallRectCurr_b = true;

                            if( v_TrlrDetSts_e == e_Trlr_Detected )
                            {
                                if( IsCouplerInsideTrailer( v_TrlrBB, v_CplrBallPix ) == true )
                                {
                                    v_CplrBallDetSts_e = e_Cplr_Detected;
                                        v_CplrBallLoc = Obj_Info.getPoint_3D();
                                        v_CplrBallBB = Obj_Info.getRect();
                                }
                                else // Coupler is outside trailer BB
                                {
                                    v_CplrBallDetSts_e = e_Cplr_Not_Detected;
                                    v_CplrBallLoc = v_HitchLoc;
                                    v_CplrBallPix = v_HitchPix;
                                }
                            }
                            else // Trailer is not detected
                            {
                                v_CplrBallDetSts_e = e_Cplr_Detected;
                            }
                        }
                        else // Detection found but coupler not detected
                        {
                            v_CplrBallDetSts_e = e_Cplr_Not_Detected;
                        }
                    }
                    else // Detection not found
                    {
                        v_CplrBallDetSts_e = e_Cplr_Not_Detected;
                        v_CplrRegDetSts_e = e_Cplr_Not_Detected;
                    }

                    // Update average detection confidence
                    v_TrlrDetConf = getAvgDetConfidence( static_cast<CplrDetStatus_e>( v_TrlrDetSts_e ), 1.0f, m_TrlrDetConfBuffer );
                    v_CplrBallDetConf = getAvgDetConfidence( v_CplrBallDetSts_e, 1.0f, m_CplrBallDetConfBuffer );
                    v_CplrRegDetConf = getAvgDetConfidence( v_CplrRegDetSts_e, 1.0f, m_CplrRegDetConfBuffer );

                    if( m_IndxDetConf < m_DetConfBuffSize )
                    {
                        m_IndxDetConf = m_IndxDetConf + 1;
                    }
                    else
                    {
                        // Do nothing
                    }
                }

                break;
            }

            default:
            {
                break;
            }
        }
    }

    //+ Run Conventional Angle Detection
    if( m_JobTHAInput.SMInput_s.UsrCplrSelected_b == true )
        {
        if( v_detectionSuccess_b == true )
        {
            if( ( m_InitCplrAngFound_b == false ) &&
                ( ( v_CplrRegDetSts_e == CplrDetStatus_e::e_Cplr_Detected ) ||
                  ( v_TrlrDetSts_e == TrlrDetStatus_e::e_Trlr_Detected ) ) )
            {
                Recti rectDetBB = Recti( 0, 0, 0, 0 );

                if( v_TrlrDetSts_e == TrlrDetStatus_e::e_Trlr_Detected )
                {
                    rectDetBB = Recti( v_TrlrBB.x, v_TrlrBB.y, v_TrlrBB.width, v_TrlrBB.height );
                }
                else if( v_CplrRegDetSts_e == CplrDetStatus_e::e_Cplr_Detected )
                {
                    rectDetBB = Recti( v_CplrRegBB.x, v_CplrRegBB.y, v_CplrRegBB.width, v_CplrRegBB.height );
                }
                        else
                        {
                            // Do Nothing: MISRA 4070
                        }

                ValidateAndUpdateBB( rectDetBB, static_cast<int32_t>( m_ImgWidth ), static_cast<int32_t>( m_ImgHeight ) );
#ifdef USR_POINT_WITH_TRLRBB
                Point2i v_UsrSelPnt_s32 = Point2i( 0, 0 );
#ifdef _WIN32
                v_UsrSelPnt_s32 = Point2i( static_cast<int32_t>( m_JobTHAInput.HMIInput_s.CplrPixX_u16 ), static_cast<int32_t>( m_JobTHAInput.HMIInput_s.CplrPixY_u16 ) );
#else
                TransformHMICplrPnt( v_UsrSelPnt_s32, m_JobTHAInput.HMIInput_s.CplrPixX_u16, m_JobTHAInput.HMIInput_s.CplrPixY_u16 );
#endif // _WIN32
#endif // USR_POINT_WITH_TRLRBB
                uint8_t v_CplrBallOffset = 0;

                if( v_CplrBallDetSts_e == CplrDetStatus_e::e_Cplr_Detected )
                {
                    v_UsrSelPnt_s32 = v_CplrBallPix;
                            v_CplrBallOffset = static_cast<uint8_t>( v_CplrBallBB.width ) / 2;
                }

                uint8_t v_LatOffPerc = 5; // Allowed lateral offset percentage 10%
                v_TrailerCplrAng_f32 = ConventionalTrailerPose_Run( rectDetBB, v_UsrSelPnt_s32, v_LatOffPerc, v_CplrBallOffset );
                    m_InitCplrAng = m_InitCplrAng + v_TrailerCplrAng_f32;
                    m_WaitFrameCountAngle = m_WaitFrameCountAngle + 1;

                    if( m_WaitFrameCountAngle > 4 )
                    {
                            m_InitCplrAng = ( m_InitCplrAng / 5.0f );
                        m_InitCplrAngFound_b = true;
                    }
                }
                }
                #if ENABLE_DEBUG_THA
                //timeStamp = v_Time_o.getTimeMsec_u64();
                //ME_Debugger_F_Printf_v("\n ### StateProcess:Time:%lld,m_WaitFrameCountAngle:%d,m_InitCplrAngFound_b:%d,v_TrailerCplrAng_f32:%f,m_InitCplrAng:%f",timeStamp,m_WaitFrameCountAngle,m_InitCplrAngFound_b,v_TrailerCplrAng_f32,m_InitCplrAng);
                ME_Debugger_F_Printf_v("\n ### StateProcess:m_WaitFrameCountAngle:%d,m_InitCplrAngFound_b:%d,v_TrailerCplrAng_f32:%f,m_InitCplrAng:%f",m_WaitFrameCountAngle,m_InitCplrAngFound_b,v_TrailerCplrAng_f32,m_InitCplrAng);
                #endif //ENABLE_DEBUG_THA
        }

    //- Run Conventional Angle Detection

    // Verify initial detection frames and detection confidence
    if( v_return_b == false )
    {
        if( m_JobTHAInput.SMInput_s.UsrCplrSelected_b == true )
        {
                if( /*( m_IndxDetConf >= m_DetConfBuffSize ) && */( m_StatusCplrZone_b == false ) )
            {
                if( ( v_TrlrDetConf >= v_DetConfThrsh ) || ( v_CplrBallDetConf >= v_DetConfThrsh ) || ( v_CplrRegDetConf >= v_DetConfThrsh ) )
                {
                    m_StatusCplrZone_b = true;
                }
                else
                {
                    m_StatusCplrZone_b = false;
                }
            }
        }
	}
#endif //!THA_TRACKER_UT
    /*
    * Coupler Tracker for missed detection
    */
#if THA_TRACKER_UT
    v_return_b = false;
    static uint16_t u16SkipFrames = 0;
    u16SkipFrames++;
    if( (v_return_b == false) && (u16SkipFrames >= 333)) //~10seconds wait for execution
#else
	if(v_return_b == false)
#endif //THA_TRACKER_UT	
    {
#if THA_TRACKER_UT
        u16SkipFrames = 333;
#endif //THA_TRACKER_UT
#ifdef OD_TRACKER
        #if PROFILE_THA
        osal::Time v_Time_o;
        uint64_t v_StartTime_u64 = 0;
        uint64_t v_EndTime_u64 = 0;
        static uint64_t v_TotalTime_u64 = 0;
        v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
        #endif//PROFILE_THA
#if THA_TRACKER_UT
        m_JobTHAInput.SMInput_s.UsrCplrSelected_b = UsrCplrSelected_b[u16FrameNo];
        m_Cfg.UtilizeTrailerTracker = UtilizeTrailerTracker[u16FrameNo];
        m_StatusCplrZone_b = m_StatusCplrZone_b_UT[u16FrameNo];
        v_CplrBallDetSts_e = (CplrDetStatus_e)v_CplrBallDetSts_e_UT[u16FrameNo];
        v_CplrBallPix.x = v_CplrPix_ix[u16FrameNo];
        v_CplrBallPix.y = v_CplrPix_iy[u16FrameNo];
        v_CplrBallLoc.x = v_CplrLoc_fx[u16FrameNo];
        v_CplrBallLoc.y = v_CplrLoc_fy[u16FrameNo];
        v_CplrBallLoc.z = v_CplrLoc_fz[u16FrameNo];
        v_CplrBallBB.x = v_CplrBB_ix[u16FrameNo];
        v_CplrBallBB.y = v_CplrBB_iy[u16FrameNo];
        v_CplrBallBB.width = v_CplrBB_iwidth[u16FrameNo];
        v_CplrBallBB.height = v_CplrBB_iheight[u16FrameNo];
        m_ObjTrackerStarted = (bool_t)m_ObjTrackerStarted_UT[u16FrameNo];
        m_CplrBallDetStsPrev_e = (CplrDetStatus_e)m_CplrBallDetStsPrev_e_UT[u16FrameNo];
        m_Cfg.CouplerHeight = (CplrDetStatus_e)CouplerHeight[u16FrameNo];
        v_CplrRegDetSts_e = (CplrDetStatus_e)v_CplrRegDetSts_e_UT[u16FrameNo];
        v_CplrRegPix.x = v_CplrRegPix_ix[u16FrameNo];
        v_CplrRegPix.y = v_CplrRegPix_iy[u16FrameNo];
        v_CplrRegLoc.x = v_CplrRegLoc_fx[u16FrameNo];
        v_CplrRegLoc.y = v_CplrRegLoc_fy[u16FrameNo];
        v_CplrRegLoc.z = v_CplrRegLoc_fz[u16FrameNo];
        v_CplrRegBB.x = v_CplrRegBB_ix[u16FrameNo];
        v_CplrRegBB.y = v_CplrRegBB_iy[u16FrameNo];
        v_CplrRegBB.width = v_CplrRegBB_iwidht[u16FrameNo];
        v_CplrRegBB.height = v_CplrRegBB_iheight[u16FrameNo];
        m_CplrRegDetStsPrev_e = (CplrDetStatus_e)m_CplrRegDetStsPrev_e_UT[u16FrameNo];
        v_TrlrDetSts_e = (TrlrDetStatus_e)v_TrlrDetSts_e_UT[u16FrameNo];
        m_TrlrDetStsPrev_e = (TrlrDetStatus_e)m_TrlrDetStsPrev_e_UT[u16FrameNo];
        m_JobTHAInput.HMIInput_s.CplrPixX_u16 = CplrPixX_u16[u16FrameNo];
        m_JobTHAInput.HMIInput_s.CplrPixY_u16 = CplrPixY_u16[u16FrameNo];
        v_TrlrPix.x = v_TrlrPix_x[u16FrameNo];
        v_TrlrPix.y = v_TrlrPix_y[u16FrameNo];
        v_CplrPix.x = v_CplrPix_x[u16FrameNo];
        v_CplrPix.y = v_CplrPix_y[u16FrameNo];
#endif  //THA_TRACKER_UT
        if( m_JobTHAInput.SMInput_s.UsrCplrSelected_b == true )
        {
                if( m_Cfg.getUtilizeTrailerTracker() == true )
            {
                if( m_StatusCplrZone_b == true )
                {
						//--- if coupler ball is detected
            #if ENABLE_DEBUG_THA
            timeStamp = v_Time_o.getTimeMsec_u64();
            ME_Debugger_F_Printf_v("\n ### StateProcess:Time:%lld,trlrpix:%d,%d,v_CplrPix:%d,%d,v_HitchPix:%d,%d",timeStamp,v_TrlrPix.x,v_TrlrPix.y,
            v_CplrPix.x,v_CplrPix.y,v_HitchPix.x,v_HitchPix.y);
            #endif //ENABLE_DEBUG_THA
                    if( v_CplrBallDetSts_e == CplrDetStatus_e::e_Cplr_Detected )
                    {
                        v_CplrPix = v_CplrBallPix;
                        v_CplrLoc = v_CplrBallLoc;
                        v_CplrBB = v_CplrBallBB;

                        if( m_ObjTrackerStarted == false )
                        {
                            if( SetupObjectTracker( v_CplrPix ) )
                            {
                                m_ObjTrackerStarted = true;
                                    v_ObjTrackConf = m_CouplerTrackerObj.m_kcfTrackerCObj.getPeakValue_c();
                                m_TrkdObjInfo = 3;
						    #if ENABLE_DEBUG_THA
                            ME_Debugger_F_Printf_v("\n ### StateProcess: ProcessTHASM m_ObjTrackerStarted true. ");
                            #endif //ENABLE_DEBUG_THA
                            }
                        }
                        else
                        {
                            if( ResetObjectTracker( v_CplrPix ) )
                            {
                                    v_ObjTrackConf = m_CouplerTrackerObj.m_kcfTrackerCObj.getPeakValue_c();
                                    m_TrkdObjInfo = 3;
                            }
                        }
                    }
                        else if( ( m_TrkdObjInfo == 3 ) && ( m_ObjTrackerStarted == true ) )
                    {
                        v_ObjTrackGoodConf_b = GetObjectTrackerConf( v_ObjTrackConf );
                        Point2i v_TempCplrGnd = Point2i( 0, 0 );

                        if( v_ObjTrackGoodConf_b )
                        {
                            GetObjectTrackedPoint(v_CplrPix.x, v_CplrPix.y);
                            #ifdef _WIN32
                            ConvertPointImage2WCS(v_CplrPix, v_CplrLoc, v_TempCplrGnd, static_cast<float32_t>(m_Cfg.getCouplerHeight()));
                            #else
                            Image2WorldCS( v_CplrPix, v_CplrLoc, static_cast<float32_t>( m_Cfg.getCouplerHeight()), m_CouplerTrackerObj.getImgWidth(), m_CouplerTrackerObj.getImgHeight() );
                            #endif
                            v_ObjTrkSts_e = ObjTrkStatus_e::e_Tracked;
                            m_TrkdObjInfo = 3;
                        }
                        else
                        {
                            // If this condition occurs, look for coupler region detection/tracking
                                v_ObjTrkSts_e = ObjTrkStatus_e::e_Not_Tracked;
                        }
                    }
                    else
                    {
                        // Do Nothing: MISRA 4070
                    }

                    // if coupler ball not detected neither tracked
                        if( ( v_CplrRegDetSts_e == CplrDetStatus_e::e_Cplr_Detected ) &&
                            ( v_CplrBallDetSts_e != CplrDetStatus_e::e_Cplr_Detected ) &&
                            ( v_ObjTrkSts_e == ObjTrkStatus_e::e_Not_Tracked ) )
                    {
                        v_CplrPix = v_CplrRegPix;
                        v_CplrLoc = v_CplrRegLoc;
                        v_CplrBB = v_CplrRegBB;

                        if( m_ObjTrackerStarted == false )
                        {
                            if( SetupObjectTracker( v_CplrPix ) )
                            {
                                m_ObjTrackerStarted = true;
                                    v_ObjTrackConf = m_CouplerTrackerObj.m_kcfTrackerCObj.getPeakValue_c();
                                    m_TrkdObjInfo = 2;
                            }
                        }
                        else
                        {
                            if( ResetObjectTracker( v_CplrPix ) )
                            {
                                    v_ObjTrackConf = m_CouplerTrackerObj.m_kcfTrackerCObj.getPeakValue_c();
                                    m_TrkdObjInfo = 2;
                            }
                        }
                    }
                        else if( ( m_TrkdObjInfo == 2 ) &&
                                 ( v_CplrBallDetSts_e != CplrDetStatus_e::e_Cplr_Detected ) &&
                                 ( v_ObjTrkSts_e == ObjTrkStatus_e::e_Not_Tracked )  &&
                             ( m_ObjTrackerStarted == true ) )
                    {
                        v_ObjTrackGoodConf_b = GetObjectTrackerConf( v_ObjTrackConf );
                        Point2i v_TempCplrGnd = Point2i( 0, 0 );

                        if( v_ObjTrackGoodConf_b )
                        {
                            GetObjectTrackedPoint(v_CplrPix.x, v_CplrPix.y);
                            #ifdef _WIN32
                            ConvertPointImage2WCS(v_CplrPix, v_CplrLoc, v_TempCplrGnd, static_cast<float32_t>(m_Cfg.getCouplerHeight()));
                            #else
                            Image2WorldCS( v_CplrPix, v_CplrLoc, static_cast<float32_t>( m_Cfg.getCouplerHeight()), m_CouplerTrackerObj.getImgWidth(), m_CouplerTrackerObj.getImgHeight() );
                            #endif
                            v_ObjTrkSts_e = ObjTrkStatus_e::e_Tracked;
                            m_TrkdObjInfo = 2;
                        }
                        else
                        {
                                // If this condition occurs, look for trailer detection/tracking
                                v_ObjTrkSts_e = ObjTrkStatus_e::e_Not_Tracked;
                        }
                    }
                    else
                    {
                        // Do Nothing:MISRA 4070
                    }

                    /* For Toyota Demo Only*/
                        if( ( v_CplrBallDetSts_e != CplrDetStatus_e::e_Cplr_Detected ) &&
                            ( v_CplrRegDetSts_e != CplrDetStatus_e::e_Cplr_Detected ) &&
                            ( v_ObjTrkSts_e == ObjTrkStatus_e::e_Not_Tracked ) )
                    {
                        /* Start Trailer tracker */
                        if( v_TrlrDetSts_e == TrlrDetStatus_e::e_Trlr_Detected )
                        {
                            if( m_ObjTrackerStarted == false )
                            {
#ifdef USR_POINT_WITH_TRLRBB
                                Point2i v_UsrSelPnt_s32 = Point2i( 0, 0 );
#ifdef _WIN32
                                v_UsrSelPnt_s32 = Point2i( static_cast<int32_t>( m_JobTHAInput.HMIInput_s.CplrPixX_u16 ), static_cast<int32_t>( m_JobTHAInput.HMIInput_s.CplrPixY_u16 ) );
#else
#if THA_TRACKER_UT
                                v_UsrSelPnt_s32 = Point2i( static_cast<int32_t>( m_JobTHAInput.HMIInput_s.CplrPixX_u16 ), static_cast<int32_t>( m_JobTHAInput.HMIInput_s.CplrPixY_u16 ) );
#else
                                TransformHMICplrPnt( v_UsrSelPnt_s32, m_JobTHAInput.HMIInput_s.CplrPixX_u16, m_JobTHAInput.HMIInput_s.CplrPixY_u16 );
#endif //THA_TRACKER_UT
#endif //_WIN32
                                v_TrlrPix = v_UsrSelPnt_s32;

                                if( SetupObjectTracker( v_TrlrPix ) )
                                {
                                    m_ObjTrackerStarted = true;
                                        v_ObjTrackConf = m_CouplerTrackerObj.m_kcfTrackerCObj.getPeakValue_c();
                                    v_CplrPix = v_TrlrPix;
                                        v_ObjTrkSts_e = ObjTrkStatus_e::e_Tracked;
                                        m_TrkdObjInfo = 1;
                                }

#else

                                if( SetupObjectTracker( v_TrlrPix ) )
                                {
                                    m_ObjTrackerStarted = true;
                                        v_ObjTrackConf = m_CouplerTrackerObj.m_kcfTrackerCObj.getPeakValue_c();
                                        v_ObjTrkSts_e = ObjTrkStatus_e::e_Tracked;
                                    v_TrkdObjInfo = 1;
                                }

#endif //USR_POINT_WITH_TRLRBB
                            }
                            else
                            {
#ifdef USR_POINT_WITH_TRLRBB
                                v_ObjTrackGoodConf_b = GetObjectTrackerConf( v_ObjTrackConf );
                                Point2i v_TempCplrGnd = Point2i( 0, 0 );

                                if( v_ObjTrackGoodConf_b )
                                {
                                    GetObjectTrackedPoint( v_TrlrPix.x, v_TrlrPix.y );
                                    #ifdef _WIN32
                                    ConvertPointImage2WCS( v_TrlrPix, v_TrlrLoc, v_TempCplrGnd, static_cast<float32_t>( m_Cfg.getCouplerHeight() ) );
                                    #else
                                    Image2WorldCS( v_TrlrPix, v_TrlrLoc, 0, m_CouplerTrackerObj.getImgWidth(), m_CouplerTrackerObj.getImgHeight() );
                                    #endif
                                    v_ObjTrkSts_e = ObjTrkStatus_e::e_Tracked;
                                    v_CplrPix = v_TrlrPix;
                                        v_CplrLoc = v_TrlrLoc;
                                        m_TrkdObjInfo = 1;
                                }
                                else
                                    {
                                        if( IsPointInROI( v_TrlrBB, m_OpPixPrev ) )
                                        {
                                            if( ResetObjectTracker( m_OpPixPrev ) )
                                            {
                                                m_ObjTrackerStarted = true;
                                                v_ObjTrackConf = m_CouplerTrackerObj.m_kcfTrackerCObj.getPeakValue_c();
                                                #ifdef _WIN32
                                                ConvertPointImage2WCS( m_OpPixPrev, v_TrlrLoc, v_TempCplrGnd, static_cast<float32_t>( m_Cfg.getCouplerHeight() ) );
                                                #endif
                                                v_ObjTrkSts_e = ObjTrkStatus_e::e_Tracked;
                                                v_CplrPix = m_OpPixPrev;
                                                m_TrkdObjInfo = 1;
                                            }
                                        }
                                        else
                                        {
                                            v_ObjTrkSts_e = ObjTrkStatus_e::e_Not_Tracked;
                                        }
                                    }

#endif // !USR_POINT_WITH_TRLRBB
                            }
                        }
                            else if( ( m_TrkdObjInfo == 1 ) && ( m_ObjTrackerStarted == true ) )
                        {
                                v_ObjTrackGoodConf_b = GetObjectTrackerConf( v_ObjTrackConf );
                                Point2i v_TempCplrGnd = Point2i( 0, 0 );

                                if( v_ObjTrackGoodConf_b )
                                {
                                    GetObjectTrackedPoint( v_TrlrPix.x, v_TrlrPix.y );
                                    #ifdef _WIN32
                                    ConvertPointImage2WCS( v_TrlrPix, v_TrlrLoc, v_TempCplrGnd );
                                    #endif
                                    v_ObjTrkSts_e = ObjTrkStatus_e::e_Tracked;
                                    v_CplrPix = v_TrlrPix;
                                    v_CplrLoc = v_TrlrLoc;
                                    m_TrkdObjInfo = 1;
                                }
                                else
                                {
                                    v_ObjTrkSts_e = ObjTrkStatus_e::e_Not_Tracked;
                                }
                            }
                        else
                        {
                            // Do nothing
                        }
                    }
                }
            }
            else // If tracker is disbaled
            {
                if( v_CplrBallDetSts_e == CplrDetStatus_e::e_Cplr_Detected )
                {
                    v_CplrPix = v_CplrBallPix;
                    v_CplrLoc = v_CplrBallLoc;
                    v_CplrBB = v_CplrBallBB;
                    m_CplrPixPrev = v_CplrPix;
                }
                else if( v_CplrRegDetSts_e == CplrDetStatus_e::e_Cplr_Detected )
                {
                    v_CplrPix = v_CplrRegPix;
                    v_CplrLoc = v_CplrRegLoc;
                    v_CplrBB = v_CplrRegBB;
                    m_CplrRegPixPrev = v_CplrPix;
                }
                else if( v_TrlrDetSts_e == TrlrDetStatus_e::e_Trlr_Detected )
                {
                    v_CplrPix = v_TrlrPix;
                    v_CplrLoc = v_TrlrLoc;
                }
				else
                {
                	// Do Nothing: MISRA 4070
                }
            }
        }// User selected coupler end
#if THA_TRACKER_UT
        static uint8_t u8OnceHeader = 1;
        if(1 == u8OnceHeader)
        {
            printf("FrameNo, v_TrlrPix.x, v_TrlrPix.y, v_CplrPix.x, v_CplrPix.y\n");
            u8OnceHeader = 0;
        }        
        printf("%d, %d, %d, %d, %d\n", u16FrameNo, v_TrlrPix.x, v_TrlrPix.y, v_CplrPix.x, v_CplrPix.y );
        u16FrameNo++;
        if (u16FrameNo >= 283)
        {
            u16FrameNo = 0;
        }
#endif// THA_TRACKER_UT
#if PROFILE_THA
v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
ME_Debugger_F_Printf_v("\ntracker: %f ms ", (float32_t)(v_TotalTime_u64 * 1.0f));
#endif //PROFILE_THA
#endif // OD_TRACKER
    }
#if THA_TRACKER_UT
	v_return_b = true;
#endif	//THA_TRACKER_UT
#if !THA_TRACKER_UT
    #if ENABLE_DEBUG_THA
    timeStamp = v_Time_o.getTimeMsec_u64();
    ME_Debugger_F_Printf_v("\n ###After Tracker:time:%lld,trlrpix:%d,%d,v_CplrPix:%d,%d,v_HitchPix:%d,%d\n",timeStamp,v_TrlrPix.x,v_TrlrPix.y,
    v_CplrPix.x,v_CplrPix.y,v_HitchPix.x,v_HitchPix.y);
    #endif //ENABLE_DEBUG_THA
    // Update Hitch detection status and calculate real world distance
    if( m_HitchDetStsPrev_e == HitchDetStatus_e::e_Hitch_Detected )
    {
        v_HitchDetSts_e = m_HitchDetStsPrev_e;
        v_HitchBB = m_HitchBBPrev;
        v_HitchPix = m_HitchPixPrev;
        Point2i v_TempCplrGnd = Point2i( 0, 0 );
        #ifdef _WIN32
        ConvertPointImage2WCS(v_HitchPix, v_HitchLoc, v_TempCplrGnd, static_cast<float32_t>(m_Cfg.getCouplerHeight()));
        #else
        Image2WorldCS( v_HitchPix, v_HitchLoc, static_cast<float32_t>(m_Cfg.getCouplerHeight()), m_ImgWidth, m_ImgHeight );
        #endif
    }
    else
    {
        v_HitchDetSts_e = m_HitchDetStsPrev_e;
        Point2i v_TempCplrGnd = Point2i( 0, 0 );
        #ifdef _WIN32
        ConvertPointImage2WCS(v_HitchPix, v_HitchLoc, v_TempCplrGnd, static_cast<float32_t>(m_Cfg.getCouplerHeight()));
        #else
        Image2WorldCS( v_HitchPix, v_HitchLoc, static_cast<float32_t>(m_Cfg.getCouplerHeight()), m_ImgWidth, m_ImgHeight );
        #endif
    }

        // Update previous detection info
        m_CplrBallDetStsPrev_e = v_CplrBallDetSts_e;
        m_CplrRegDetStsPrev_e = v_CplrRegDetSts_e;
        m_TrlrDetStsPrev_e = v_TrlrDetSts_e;

    if( m_JobTHAInput.SMInput_s.UsrCplrSelected_b == true )
    {
            // Check average confidence and update status
            if( v_TrlrDetConf < v_DetConfThrsh )
            {
                v_TrlrDetSts_e = e_Trlr_Not_Detected;
            }
            else
            {
                v_TrlrDetSts_e = e_Trlr_Detected;
            }

            v_THAInfo_s.CplrDetctConf_u8 = static_cast<uint8_t>( v_TrlrDetConf * 10.0f );
            if( v_CplrRegDetConf < v_DetConfThrsh )
            {
                v_CplrRegDetSts_e = e_Cplr_Not_Detected;
            }
            else
            {
                v_CplrRegDetSts_e = e_Cplr_Detected;
            }
            if( v_CplrRegDetConf > 0.0f )
            {
                v_THAInfo_s.CplrDetctConf_u8 = static_cast<uint8_t>( ( v_CplrRegDetConf * 10.0f ) + 10.0f );
            }
            if( v_CplrBallDetConf < v_DetConfThrsh )
            {
                v_CplrBallDetSts_e = e_Cplr_Not_Detected;
            }
            else
            {
                v_CplrBallDetSts_e = e_Cplr_Detected;
            }

            if( v_CplrBallDetConf > 0.0f )
            {
                v_THAInfo_s.CplrDetctConf_u8 = static_cast<uint8_t>( ( v_CplrBallDetConf * 10.0f ) + 20.0f );
            }

            if( m_StatusCplrZone_b == true )
            {
                if( ( v_CplrBallDetSts_e == CplrDetStatus_e::e_Cplr_Detected ) ||
                    ( v_CplrRegDetSts_e == CplrDetStatus_e::e_Cplr_Detected ) ||
                    ( v_TrlrDetSts_e == TrlrDetStatus_e::e_Trlr_Detected ) ||
                    ( v_ObjTrkSts_e == ObjTrkStatus_e::e_Tracked ) )
                {
                    v_CplrDetSts_e = CplrDetStatus_e::e_Cplr_Detected;

                    // Update m_OpPixPrev if v_CplrPix is not default
                    if( v_CplrPix != v_DefaultPix )
                    {
                        m_OpPixPrev = v_CplrPix;
                    }
                }
                else if( ( v_CplrBallDetSts_e == CplrDetStatus_e::e_Cplr_Not_Detected ) &&
                         ( v_CplrRegDetSts_e == CplrDetStatus_e::e_Cplr_Not_Detected ) &&
                         ( v_TrlrDetSts_e == TrlrDetStatus_e::e_Trlr_Not_Detected ) &&
                         ( v_ObjTrkSts_e == ObjTrkStatus_e::e_Not_Tracked ) )
                {
                    v_CplrDetSts_e = CplrDetStatus_e::e_Cplr_Not_Detected;
                }
                else
                {
                    // Do Nothing: MISRA 4070
                }

                // Set CplrDetctStatus_e to e_Cplr_Not_Detected if no actual detections when v_CplrToHitch_f32 < CouplerNotDetThresh
                //if( v_TrlrDetSts_e == TrlrDetStatus_e::e_Trlr_Detected )
                //{
                //    // CouplerNotDetThresh in meter
                //    if( m_TrlrBaseLocPrev.x < m_Cfg.getCouplerNotDetThresh() )
                //    {
                //        if( ( v_CplrBallDetSts_e == CplrDetStatus_e::e_Cplr_Not_Detected ) &&
                //            ( v_CplrRegDetSts_e == CplrDetStatus_e::e_Cplr_Not_Detected ) )
                //        {
                //            v_CplrDetSts_e = CplrDetStatus_e::e_Cplr_Not_Detected;
                //        }
                //        else
                //        {
                //            // Do Nothing
                //        }
                //    }
                //    else
                //    {
                //        // Do Nothing
                //    }
                //}
                //else
                //{
                //    // Do Nothing
                //}
            }
            else if( ( m_StatusCplrZone_b == false )  && ( m_IndxDetConf >= m_DetConfBuffSize ) )
            {
                v_CplrDetSts_e = CplrDetStatus_e::e_Cplr_Not_Detected;
            }
            else
            {
                // Do nothing
            }
        }
        

    /*
    * Calculate distance from hitch to coupler
    */
    if( m_JobTHAInput.SMInput_s.UsrCplrSelected_b == true )
    {
        if( m_StatusCplrZone_b == true )
        {   
            float32_t v_CplrToHitchDistReal_f32 = 0.0f;
            if( m_Cfg.getIsCouplerToHitchThreshInPix() == true )
            {
                if( v_CplrDetSts_e == CplrDetStatus_e::e_Cplr_Detected )
                {
                    Point2i v_TempCplrGnd = Point2i( 0, 0 );
                    #ifdef _WIN32
                    ConvertPointImage2WCS( v_CplrPix, v_CplrLoc, v_TempCplrGnd, static_cast<float32_t>( m_Cfg.getCouplerHeight() ) );
                    #else
                    Image2WorldCS( v_CplrPix, v_CplrLoc, static_cast<float32_t>(m_Cfg.getCouplerHeight()), m_ImgWidth, m_ImgHeight );
                    #endif
                    v_CplrToHitchDistReal_f32 = v_CplrLoc.x - v_HitchLoc.x;

                    if( v_CplrToHitchDistReal_f32 < m_Cfg.getCouplerNotDetThresh() )
                    {
                        if( ( v_CplrBallDetSts_e == CplrDetStatus_e::e_Cplr_Not_Detected ) &&
                            ( v_CplrRegDetSts_e == CplrDetStatus_e::e_Cplr_Not_Detected ) )
                        {
                            v_CplrDetSts_e = CplrDetStatus_e::e_Cplr_Not_Detected;
                        }
                        else
                        {
                            // Do Nothing
                        }
                    }
                    else
                    {
                        // Do Nothing
                    }
                    
                    v_CplrToHitch_f32 = static_cast<float32_t>( v_HitchPix.y - m_OpPixPrev.y );
                    v_CplrToHitchLat_f32 = static_cast<float32_t>( v_HitchPix.x - m_OpPixPrev.x );
                    uint16_t v_CurrCplrHtichEucDist = static_cast<uint16_t>( getEuclideanDist( v_HitchPix, m_OpPixPrev ) );

                    // Update euclidean distance threshold dynamically based on distance covered
                    if( m_InitCplrHtichEucDist == 0 )
                    {
                        m_InitCplrHtichEucDist = v_CurrCplrHtichEucDist;
                            m_EucDistThrshTrlr = v_MinEucDistThrshTrlr;
                            m_EucDistThrshCplrReg = v_MinEucDistThrshCplrReg;
                            m_EucDistThrshCplrBall = v_MinEucDistThrshCplrBall;
                    }
                    else
                    {
                        if( m_EucDistThrshTrlr >= v_MaxEucDistThrshTrlr )
                        {
                            m_EucDistThrshTrlr = v_MaxEucDistThrshTrlr;
                        }
                        else
                        {
                                m_EucDistThrshTrlr = static_cast<uint16_t>( static_cast<float32_t>( v_MinEucDistThrshTrlr ) + ( ( static_cast<float32_t>( m_InitCplrHtichEucDist - v_CurrCplrHtichEucDist ) / 100.0f ) * static_cast<float32_t>( v_MinEucDistThrshTrlr ) ) );
                        }

                        if( m_EucDistThrshCplrReg >= v_MaxEucDistThrshCplrReg )
                        {
                            m_EucDistThrshCplrReg = v_MaxEucDistThrshCplrReg;
                        }
                        else
                        {
                                m_EucDistThrshCplrReg = static_cast<uint16_t>( static_cast<float32_t>( v_MinEucDistThrshCplrReg ) + ( ( static_cast<float32_t>( m_InitCplrHtichEucDist - v_CurrCplrHtichEucDist ) / 100.0f ) * static_cast<float32_t>( v_MinEucDistThrshCplrReg ) ) );
                        }

                        if( m_EucDistThrshCplrBall >= v_MaxEucDistThrshCplrBall )
                        {
                            m_EucDistThrshCplrBall = v_MaxEucDistThrshCplrBall;
                        }
                        else
                        {
                                m_EucDistThrshCplrBall = static_cast<uint16_t>( static_cast<float32_t>( v_MinEucDistThrshCplrBall ) + ( ( static_cast<float32_t>( m_InitCplrHtichEucDist - v_CurrCplrHtichEucDist ) / 100.0f ) * static_cast<float32_t>( v_MinEucDistThrshCplrBall ) ) );
                        }
                    }
                }
                else
                {
                    v_CplrToHitch_f32 = static_cast<float32_t>( v_HitchPix.y - m_OpPixPrev.y );
                    v_CplrToHitchLat_f32 = static_cast<float32_t>( v_HitchPix.x - m_OpPixPrev.x );
                }
            }
            else
            {
                if( v_CplrDetSts_e == CplrDetStatus_e::e_Cplr_Detected )
                {
                    v_CplrToHitch_f32 = v_HitchLoc.x - v_CplrLoc.x;
                    v_CplrToHitchLat_f32 = v_HitchLoc.y - v_CplrLoc.y;
                }
                else
                {
                    // Do nothing
                }
            }
            /*
            * Check trailer coupler is reached
            */
                if( v_CplrToHitch_f32 <= m_Cfg.getCouplerToHitchThresh() )
            {
                m_CplrToHitchReachStatus_b = true;
            }
            else
            {
                m_CplrToHitchReachStatus_b = false;
            }
        }
    }

    #if ENABLE_DEBUG_THA
    timeStamp = v_Time_o.getTimeMsec_u64();
    ME_Debugger_F_Printf_v("\n ###Time:%lld,CplrStat:%d,HitchStat:%d,v_TrlrStat:%d\n",timeStamp,v_CplrDetSts_e,v_HitchDetSts_e,v_TrlrDetSts_e);
    #endif //ENABLE_DEBUG_THA
    /*
    * Update detection info
    */
    // --- Update Hitch detection info
    v_THAInfo_s.HitchDetctStatus_e = v_HitchDetSts_e;
    v_THAInfo_s.HitchLoc_p3f = v_HitchLoc;
    v_THAInfo_s.HitchPix_p2d = v_HitchPix;
    v_THAInfo_s.CplrDetctStatus_e = v_CplrDetSts_e;
    v_THAInfo_s.CplrPix_p2d = v_CplrPix;
    v_THAInfo_s.CplrLoc_p3f = v_CplrLoc;
#if ENABLE_SMOOTH_OP

    // --- Update Coupler detection info
    if( v_CplrDetSts_e == CplrDetStatus_e::e_Cplr_Not_Detected )
    {
        memset( m_CplrXBuff, 0, sizeof( uint32_t )*m_CplrPntBuffSize );
        memset( m_CplrYBuff, 0, sizeof( uint32_t )*m_CplrPntBuffSize );
        m_IndxCplrPnt = 0;
    }
    else
    {
        v_CplrPix = getMovingAvg( v_CplrPix );
        v_THAInfo_s.CplrDetctStatus_e = v_CplrDetSts_e;
        v_THAInfo_s.CplrPix_p2d = v_CplrPix;
        v_THAInfo_s.CplrLoc_p3f = v_CplrLoc;
    }

#endif // ENABLE_SMOOTH_OP
    v_THAInfo_s.CplrDist_f32 = v_CplrToHitch_f32;
    v_THAInfo_s.HitchCplrPixDiffLongY_s32 = static_cast<int32_t>( v_CplrToHitch_f32 );
    v_THAInfo_s.HitchCplrPixDiffLatX_s32 = static_cast<int32_t>( v_CplrToHitchLat_f32 );

    //v_THAInfo_s.CplrDetctConf_u8 = static_cast<uint8_t>( v_CplrBallDetConf * 100.0f );
        switch( static_cast<int32_t>( m_TrkdObjInfo ) )
    {
        // Trailer
        case 1:
            {
                //v_THAInfo_s.CplrDetctConf_u8 = static_cast<uint8_t>( v_TrlrDetConf * 10.0f );
                v_THAInfo_s.CplrTrackConf_u8 = static_cast<uint8_t>( v_ObjTrackConf  * 10.0f );
                break;
            }

        // Coupler region
        case 2:
            {
                //v_THAInfo_s.CplrDetctConf_u8 = static_cast<uint8_t>( ( v_CplrRegDetConf * 10.0f ) + 10.0f );
                v_THAInfo_s.CplrTrackConf_u8 = static_cast<uint8_t>( v_ObjTrackConf  * 10.0f ) + 10.0f ;
                break;
            }

        // Coupler ball
        case 3:
            {
                //v_THAInfo_s.CplrDetctConf_u8 = static_cast<uint8_t>( ( v_CplrBallDetConf * 10.0f ) + 20.0f );
                v_THAInfo_s.CplrTrackConf_u8 = static_cast<uint8_t>( v_ObjTrackConf  * 10.0f ) + 20.0f;
                break;
            }

        default:
            {
                v_THAInfo_s.CplrTrackConf_u8 = 0;
                break;
            }
        }

        //v_THAInfo_s.CplrTrackConf_u8 = static_cast<uint8_t>( v_ObjTrackConf * 100.0f );

    // --- Update Coupler angle detection info
    if( m_InitCplrAngFound_b == true )
    {
        v_THAInfo_s.CplrAngFound_b = m_InitCplrAngFound_b;
        v_THAInfo_s.CplrAng_f32 = m_InitCplrAng;
    }
    else
    {
        v_THAInfo_s.CplrAngFound_b = m_InitCplrAngFound_b;
            v_THAInfo_s.CplrAng_f32 = m_Cfg.getDefaultTrailerAngle_deg();
    }

        v_CplrAngSteep_b = ( v_THAInfo_s.CplrAng_f32 <= m_Cfg.getTrailerAngleThreshDeg() ) ? true : false;
    // --- Update trailer coupler alignment status info
    v_THAInfo_s.TrlrCplrStatus_b = m_CplrToHitchReachStatus_b;
    v_THAInfo_s.StatusCplrZone_b = m_StatusCplrZone_b;
    v_THAInfoDebug_s.TrlrDetctStatus_e = v_TrlrDetSts_e;
    v_THAInfoDebug_s.TrlrPnt_p2d = v_TrlrPix;
#ifdef _WIN32
    // --- update output debug info
    v_THAInfoDebug_s.TrlrBasePnt_p2d = v_TrlrBasePix;
    v_THAInfoDebug_s.TrlrBaseLoc_p3f = m_TrlrBaseLocPrev;
    v_THAInfoDebug_s.TrlrLoc_p3f = v_TrlrLoc;
    v_THAInfoDebug_s.TrlrBB = v_TrlrBB;
    v_THAInfoDebug_s.CplrBB = v_CplrBB;
    v_THAInfoDebug_s.HitchBB = v_HitchBB;
    v_THAInfoDebug_s.DynCrpStartX = m_DynCrpStartX;
    v_THAInfoDebug_s.DynCrpStartY = m_DynCrpStartY;
    v_THAInfoDebug_s.CplrRegBB = v_CplrRegBB;
    v_THAInfoDebug_s.CplrBallDetctStatus_e = v_CplrBallDetSts_e;
    v_THAInfoDebug_s.CplrRegDetctStatus_e = v_CplrRegDetSts_e;
    v_THAInfoDebug_s.CplrRegPnt_p2d = v_CplrRegPix;
    v_THAInfoDebug_s.TrlrDetConf = static_cast<uint8_t>( v_TrlrDetConf * 100.0f );
    v_THAInfoDebug_s.CplrRegDetConf = static_cast<uint8_t>( v_CplrRegDetConf * 100.0f );
        v_THAInfoDebug_s.TrkdObjInfo = m_TrkdObjInfo;
	v_THAInfoDebug_s.EucDistThrshTrlr = m_EucDistThrshTrlr;
	v_THAInfoDebug_s.EucDistThrshCplrReg = m_EucDistThrshCplrReg;
    v_THAInfoDebug_s.EucDistThrshCplrBall = m_EucDistThrshCplrBall;
#endif // _WIN32    
#if DUMP_OUTPUT_CSV
// Dipti : Output should be dumped only when in following state to be in sync with algo view dumps
    if(( m_JobTHAInput.SMInput_s.THASmState_e == THAState_e::e_EnabledSelection ||
          m_JobTHAInput.SMInput_s.THASmState_e == THAState_e::e_Engaged ||
          m_JobTHAInput.SMInput_s.THASmState_e == THAState_e::e_EngagedDelta ||
          m_JobTHAInput.SMInput_s.THASmState_e == THAState_e::e_EngagedInquiry ))
    {
        static uint8_t u8Once = 1;
        static FILE *THA_Det_Output = NULL;
        if(u8Once)
        {
            THA_Det_Output = fopen( "/ti_sd/fp_THA_Det_Output_Vehicle.csv", "w" );
            if(NULL == THA_Det_Output)
                ME_Debugger_F_Printf_v("Failed to create file /ti_sd/fp_THA_Det_Output_Vehicle.csv\n");
        
            fprintf(THA_Det_Output, "CplrDetctStatus_e, CplrPix_p2d_x, CplrPix_p2d_y, HitchDetctStatus_e, HitchPix_p2d_x, HitchPix_p2d_y, CplrAng_f32, HitchCplrPixDiffLongY_s32, HitchCplrPixDiffLatX_s32, CplrDetctConf_u8, CplrTrackConf_u8, CplrAngFound_b, TrlrDetctStatus_e, TrlrPnt_p2d_x,TrlrPnt_p2d_y, TrlrBB_width, TrlrBB_height, CplrBB_width, CplrBB_height,");
            fprintf(THA_Det_Output, "\n");
            u8Once = 0;
        }
        fprintf(THA_Det_Output, "%d, %d, %d, %d, %d, %d, %f, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
        v_THAInfo_s.CplrDetctStatus_e,v_THAInfo_s.CplrPix_p2d.x,v_THAInfo_s.CplrPix_p2d.y,
        v_THAInfo_s.HitchDetctStatus_e,v_THAInfo_s.HitchPix_p2d.x,v_THAInfo_s.HitchPix_p2d.y,
        v_THAInfo_s.CplrAng_f32,v_THAInfo_s.HitchCplrPixDiffLongY_s32,v_THAInfo_s.HitchCplrPixDiffLatX_s32,
        v_THAInfo_s.CplrDetctConf_u8,v_THAInfo_s.CplrTrackConf_u8,v_THAInfo_s.CplrAngFound_b,
        v_THAInfoDebug_s.TrlrDetctStatus_e,v_THAInfoDebug_s.TrlrPnt_p2d.x,v_THAInfoDebug_s.TrlrPnt_p2d.y,
        v_THAInfoDebug_s.TrlrBB.width,v_THAInfoDebug_s.TrlrBB.height,v_THAInfoDebug_s.CplrBB.width,
        v_THAInfoDebug_s.CplrBB.height);
        
        fprintf(THA_Det_Output, "\n");
        fflush(THA_Det_Output);
    }
#endif //DUMP_OUTPUT_CSV
    SetupTHADetOutput( v_THAInfo_s ); //set THA detection output
    SetupTHADetDebugOutput( v_THAInfoDebug_s ); //set THA detection Debug output
    #if ENABLE_DEBUG_THA
    ME_Debugger_F_Printf_v("\n ### THA: StateProcess:: ProcessTHASM 2 ### \n ");
    #endif //ENABLE_DEBUG_THA
#endif //!THA_TRACKER_UT
}
#ifdef OD_ONNX
#ifdef _WIN32
    /*
    * Name: Onnx_CD_HD_Run
    * Remarks: DD-ID: {6A27CF5F-C6DE-4881-96BF-988A37CD6D9D}
    * Remarks: DD-ID: {9DBCDCBF-0796-4a5c-9482-DD3F99343B47}
    */
bool_t StateProcess::Onnx_CD_HD_Run()
{
    bool_t ValidResultFound_b = false;
    uint32_t ObjCnt_u8 = 0;
    //+ Adding dynamic crop changes
        int32_t v_rectStartX = 0;
        int32_t v_rectStartY = 0;
        uint16_t v_cropImageW = m_Cfg.getDetDNNInputDimW(); // Dipti : This should be set according to the model used
        uint16_t v_cropImageH = m_Cfg.getDetDNNInputDimH(); // Dipti : This should be set according to the model used
    Point2i v_cropCentrePoint = Point2i( 0, 0 );
#ifdef DynamicCrop640
    // Do nothing
#elif defined(IMGCROP640)
    // Do nothing
#else
    v_cropImageW = m_ImgHeight;
    v_cropImageH = m_ImgHeight;
#endif //DynamicCrop640

        if( m_Cfg.getEnableODONNXCrop() == true )
    {
        // ROI for Coupler
        if( m_JobTHAInput.SMInput_s.UsrCplrSelected_b == true )
        {
#ifdef _WIN32
            v_cropCentrePoint = Point2i( static_cast<int32_t>( m_JobTHAInput.HMIInput_s.CplrPixX_u16 ), static_cast<int32_t>( m_JobTHAInput.HMIInput_s.CplrPixY_u16 ) );
#else
            TransformHMICplrPnt( v_cropCentrePoint, m_JobTHAInput.HMIInput_s.CplrPixX_u16, m_JobTHAInput.HMIInput_s.CplrPixY_u16 );
#endif // _WIN32
                v_rectStartX = v_cropCentrePoint.x - ( static_cast<int32_t>( v_cropImageW ) / 2 );
                v_rectStartY = v_cropCentrePoint.y - ( static_cast<int32_t>( v_cropImageH ) / 2 );

            if( m_StatusCplrZone_b == true )
            {
                        v_rectStartX = m_OpPixPrev.x - ( static_cast<int32_t>( v_cropImageW ) / 2 );
                        v_rectStartY = m_OpPixPrev.y - ( static_cast<int32_t>( v_cropImageH ) / 2 );
                }
            }
        // ROI for Hitch
        else
        {
                v_rectStartX = ( static_cast<int32_t>( m_ImgWidth ) / 2 ) - ( static_cast<int32_t>( v_cropImageW ) / 2 );
                v_rectStartY = static_cast<int32_t>( m_ImgHeight ) - static_cast<int32_t>( v_cropImageH );
        }

        if( v_rectStartX < 0 )
        {
            v_rectStartX = 0;
        }

        if( v_rectStartY < 0 )
        {
            v_rectStartY = 0;
        }

            if( ( v_rectStartX + static_cast<int32_t>( v_cropImageW ) ) > static_cast<int32_t>( m_ImgWidth ) )
            {
                v_rectStartX = static_cast<int32_t>( m_ImgWidth ) - static_cast<int32_t>( v_cropImageW );
            }

            if( ( v_rectStartY + static_cast<int32_t>( v_cropImageH ) ) > static_cast<int32_t>( m_ImgHeight ) )
            {
                v_rectStartY = static_cast<int32_t>( m_ImgHeight ) - static_cast<int32_t>( v_cropImageH );
            }

#ifdef _WIN32
            m_DynCrpStartX = static_cast<int16_t>( v_rectStartX );
            m_DynCrpStartY = static_cast<int16_t>( v_rectStartY );
#endif // _WIN32
    }

    //- Adding dynamic crop changes
    ObjCnt_u8 = m_pOnnxDetector->Detect( m_JobTHAInput.InputImgColor_pu8, m_ImgWidth, m_ImgHeight, v_rectStartX, v_rectStartY, m_JobTHAInput.SMInput_s.UsrCplrSelected_b );
    m_ObjList.copyAll_v( m_pOnnxDetector->m_Result );
    ObjCnt_u8 = m_ObjList.size_u32();

    for( uint32_t i = 0; i < ObjCnt_u8; i++ )
    {
            Point2i PntTemp = m_ObjList[i].getPoint_2D(); /* Center point for Rect */
            float32_t v_ObjHeight = 0.0f;

            if( m_ObjList[i].getType() == ODType::Obj_Trailer )
        {
            v_ObjHeight = 0.0f;
        }
            else if( m_ObjList[i].getType() == ODType::Obj_Coupler )
            {
                v_ObjHeight = static_cast<float32_t>( m_Cfg.getCouplerHeight() );
            }
            else if( m_ObjList[i].getType() == ODType::Obj_Hitch )
            {
                v_ObjHeight = static_cast<float32_t>( m_Cfg.getDefaultHitchZ_mm() );
        }
        else
        {
            //Do Nothing
        }

        Point3f v_PntLoc( 0.0f, 0.0f, 0.0f );
        Point2i v_PntGrnd( 0, 0 );
        ConvertPointImage2WCS( PntTemp, v_PntLoc, v_PntGrnd, v_ObjHeight );
            m_ObjList[i].setPoint_3D( v_PntLoc );
            m_ObjList[i].setPoint_2D_Ground( v_PntGrnd );
    }

    if( ObjCnt_u8 > 0 )
    {
        ValidResultFound_b = true;
    }
    else
    {
        ValidResultFound_b = false;
    }

    return ValidResultFound_b;
}
    /*
    * Name: Onnx_TrailerPose_Run
    * Remarks: DD-ID: {56B6B261-38D6-4fc6-BDB4-87D8BF52394A}
    * Remarks: DD-ID: {F68511FB-0006-43ee-A835-72A96906C33C}
    */
bool_t StateProcess::Onnx_TrailerPose_Run( const uint8_t* i_InputImg, float32_t& o_trailerAngDeg, Recti& i_rectTrailer, uint16_t i_ImgWidth, uint16_t i_ImgHeight )
{
    bool_t ValidResultFound_b = false;
    float32_t v_classProb = 0.0f;
    uint32_t v_classId = 0;
    v_classId = m_pOnnxClassifier->Classify( i_InputImg, v_classProb, i_rectTrailer, i_ImgWidth, i_ImgHeight );

    if( v_classProb > 0.5 )
    {
        o_trailerAngDeg = static_cast<float32_t>( atoi( m_pOnnxClassifier->classList[v_classId].c_str() ) );
        ValidResultFound_b = true;
    }
    else
    {
        ValidResultFound_b = false;
    }

    return ValidResultFound_b;
}
#else
#if ENABLE_CD_HD
bool_t StateProcess::Onnx_CD_HD_Run(AppObj_CD_HD* obj)
{
    uint8_t numObject = 0; //TBD: Temporarily to get number of objects detected
    DNN_CDHD_out data_arr[50]; //TBD: Temporarily making it for 50 objects
    memset(data_arr, 0, (50*sizeof(DNN_CDHD_out)));

    bool_t ValidResultFound_b = false;
    uint32_t ObjCnt_u8 = 0;

    #if ENABLE_DEBUG_THA
        ME_Debugger_F_Printf_v("\n\n\n ###### StateProcess: Onnx_CD_HD_Run start ###### \n\n\n ");
    #endif //ENABLE_DEBUG_THA

    vx_status v_status_b = VX_SUCCESS;
        int32_t v_rectStartX = 0;
        int32_t v_rectStartY = 0;
        uint16_t v_cropImageW = m_Cfg.getDetDNNInputDimW(); // Dipti : This should be set according to the model used
        uint16_t v_cropImageH = m_Cfg.getDetDNNInputDimH(); // Dipti : This should be set according to the model used
    Point2i v_cropCentrePoint = Point2i(0,0);

    if (NULL != m_JobTHAInput.InputImgColor_pu8)
    {
        #if ENABLE_DEBUG_THA
            ME_Debugger_F_Printf_v("\n ### StateProcess: Memcpy\n");
        #endif //ENABLE_DEBUG_THA
        // Run DNN model on C7x for interleaved RGB image
        #if PROFILE_THA
        osal::Time v_Time_o;
        uint64_t v_StartTime_u64 = 0;
        uint64_t v_EndTime_u64 = 0;
        uint64_t v_cropTime_u64 = 0;
        static uint64_t v_cropTotalTime_u64 = 0;
        static uint64_t v_TotalTime_u64 = 0;
        v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
        #endif //PROFILE_THA
        
        if( m_Cfg.getEnableODONNXCrop() == true )
        {
            // ROI for Coupler
            if( m_JobTHAInput.SMInput_s.UsrCplrSelected_b == true )
            {
#ifdef _WIN32
            v_cropCentrePoint = Point2i( static_cast<int32_t>( m_JobTHAInput.HMIInput_s.CplrPixX_u16 ), static_cast<int32_t>( m_JobTHAInput.HMIInput_s.CplrPixY_u16 ) );
#else
                TransformHMICplrPnt( v_cropCentrePoint, m_JobTHAInput.HMIInput_s.CplrPixX_u16, m_JobTHAInput.HMIInput_s.CplrPixY_u16);
#endif // _WIN32
                v_rectStartX = v_cropCentrePoint.x - ( static_cast<int32_t>( v_cropImageW ) / 2 );
                v_rectStartY = v_cropCentrePoint.y - ( static_cast<int32_t>( v_cropImageH ) / 2 );

                if (m_StatusCplrZone_b == true)
                {
                    v_rectStartX = m_OpPixPrev.x - (static_cast<int32_t>(v_cropImageW) / 2);
                    v_rectStartY = m_OpPixPrev.y - (static_cast<int32_t>(v_cropImageH) / 2);
                }
            }
            // ROI for Hitch
            else
            {
                v_rectStartX = ( static_cast<int32_t>( m_ImgWidth ) / 2 ) - ( static_cast<int32_t>( v_cropImageW ) / 2 );
                v_rectStartY = static_cast<int32_t>( m_ImgHeight ) - static_cast<int32_t>( v_cropImageH );
            }
            
            if( v_rectStartX < 0 )
            {
                v_rectStartX = 0;
            }

            if( v_rectStartY < 0 )
            {
                v_rectStartY = 0;
            }

            if( ( v_rectStartX + static_cast<int32_t>( v_cropImageW ) ) > static_cast<int32_t>( m_ImgWidth ) )
            {
                v_rectStartX = static_cast<int32_t>( m_ImgWidth ) - static_cast<int32_t>( v_cropImageW );
            }

            if( ( v_rectStartY + static_cast<int32_t>( v_cropImageH ) ) > static_cast<int32_t>( m_ImgHeight ) )
            {
                v_rectStartY = static_cast<int32_t>( m_ImgHeight ) - static_cast<int32_t>( v_cropImageH );
            }
            #if ENABLE_DEBUG_THA
            ME_Debugger_F_Printf_v("\ncrop co-or : %d %d ", v_rectStartX, v_rectStartY);
            #endif
        }
        #if PROFILE_THA
        v_cropTime_u64 = v_Time_o.getTimeMsec_u64();
        #endif //PROFILE_THA
        v_status_b = app_run_graph_for_one_frame_sequential_CD_HD(obj, m_JobTHAInput.InputImgColor_pu8);
        #if PROFILE_THA
        v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
        v_cropTotalTime_u64 = v_cropTime_u64 - v_StartTime_u64;
        v_TotalTime_u64 = v_EndTime_u64 - v_cropTime_u64;
        ME_Debugger_F_Printf_v("\ncrop: %fms, 16bGraph:%fms ", (float32_t)(v_cropTotalTime_u64 * 1.0f),(float32_t)(v_TotalTime_u64 * 1.0f));
        #endif//PROFILE_THA
        
        // Output dumping functionality
        if(v_status_b == VX_SUCCESS)
        {
            WriteOutput_CDHD(obj, obj->input_width, obj->input_height, data_arr, &numObject);
        }
        //Dump output for unit testing
        #if DUMP_OUTPUT_CSV
        static uint8_t u8Once = 1;
        static FILE *THA_Det_Output = NULL;
        static uint8_t frameNum = 0;
        if(u8Once)
        {
            THA_Det_Output = fopen( "/ti_sd/f_THA_Det_Output_Vehicle.csv", "w" );
            if(NULL == THA_Det_Output)
                ME_Debugger_F_Printf_v("Failed to create file /ti_sd/fp_THA_Det_Output_Vehicle.csv\n");
        
            fprintf(THA_Det_Output, "FrameNum, ObjId, v_ClassID, score, xmin, ymin, xmax, ymax,");
            fprintf(THA_Det_Output, "\n");
            u8Once = 0;
        }
        if(numObject == 0)
        {
            fprintf(THA_Det_Output, "%d, %d, %d, %f, %d, %d, %d, %d",
            frameNum, 0, 0, 0.0000, 0, 0, 0, 0);
            fprintf(THA_Det_Output, "\n");
            fflush(THA_Det_Output);
        }
        for(int i =0; i < numObject; i++)
        {
            fprintf(THA_Det_Output, "%d, %d, %d, %f, %d, %d, %d, %d",
            frameNum,data_arr[i].ObjId,data_arr[i].v_ClassID,data_arr[i].v_prob,
            data_arr[i].xmin, data_arr[i].ymin,data_arr[i].xmax, data_arr[i].ymax);
            fprintf(THA_Det_Output, "\n");
            fflush(THA_Det_Output);
        }
        frameNum = frameNum +1;
        #endif //DUMP_OUTPUT_CSV

        #if ENABLE_DEBUG_THA
            ME_Debugger_F_Printf_v("\n ### StateProcess: After WriteOutput_CDHD\n");
        #endif //ENABLE_DEBUG_THA
    }
    else
    {
      ME_Debugger_F_Printf_v("\n ### No Valid Image... Aborting the run function... ### \n ");
    }
    float32_t v_resizeFactorW = static_cast<float32_t>( v_cropImageW ) / static_cast<float32_t>( m_Cfg.getDetDNNInputDimW() );
    float32_t v_resizeFactorH = static_cast<float32_t>( v_cropImageH ) / static_cast<float32_t>( m_Cfg.getDetDNNInputDimH() );

    // Populate object list with Detected ouput data
    for(uint8_t i=0; i < numObject; i++)
    {
        ODInfo objInfo;
        /* Update rectangle */
        //objInfo.Rect = Recti(data_arr[i].xmin, data_arr[i].ymin, ( data_arr[i].xmax - data_arr[i].xmin ) + 1, ( data_arr[i].ymax - data_arr[i].ymin ) + 1);
        //objInfo.Rect.x = ( objInfo.Rect.x * v_resizeFactorW ) + 0.5f;
       // objInfo.Rect.y = ( objInfo.Rect.y * v_resizeFactorH ) + 0.5f;
        //objInfo.Rect.width = ( objInfo.Rect.width * v_resizeFactorW ) + 0.5f;
        //objInfo.Rect.height = ( objInfo.Rect.height * v_resizeFactorH ) + 0.5f;
        //objInfo.DetConf = data_arr[i].v_prob;
        //int32_t v_ClassID = data_arr[i].v_ClassID;
	
	
	
	    int32_t v_X = ( (data_arr[i].xmin * v_resizeFactorW ) + 0.5f);
        int32_t v_Y = (( data_arr[i].ymin * v_resizeFactorH ) + 0.5f);
	    int32_t v_W = ( (( data_arr[i].xmax - data_arr[i].xmin ) + 1) * v_resizeFactorW ) + 0.5f;
        int32_t v_H = ( (( data_arr[i].ymax - data_arr[i].ymin ) + 1) * v_resizeFactorH ) + 0.5f;
        v_X = ( v_X * v_resizeFactorW ) + 0.5f;
        v_Y = ( v_Y * v_resizeFactorH ) + 0.5f;
        v_W = ( v_W * v_resizeFactorW ) + 0.5f;
        v_H = ( v_H * v_resizeFactorH ) + 0.5f;
        objInfo.setRect( Recti( v_X, v_Y, v_W, v_H ) );
        objInfo.setDetConf( data_arr[i].v_prob );
        int32_t v_ClassID = data_arr[i].v_ClassID;
        switch( v_ClassID )
        {
            // --- Trailer
            case 1:
            {
                objInfo.setType(ODType::Obj_Trailer);
                if( m_Cfg.getEnableODONNXCrop() == true )
                {
                        v_X = v_X + v_rectStartX;
                        v_Y = v_Y + v_rectStartY;
                        objInfo.setRect( Recti( v_X, v_Y, v_W, v_H ) );
                }
                /* Update rectangle */
                Recti v_objInfoRect = objInfo.getRect(); 
                if( ValidateAndUpdateBB( v_objInfoRect, m_ImgWidth, m_ImgHeight ) )
                {
		            // objInfo.setPoint_2D( Point2i( v_X + ( 0.5f * v_W ), v_Y + v_H ) );
                    objInfo.setPoint_2D( Point2i( v_objInfoRect.x + ( 0.5f * v_objInfoRect.width ), v_objInfoRect.y + v_objInfoRect.height ) );
                    objInfo.setRect( Recti( v_objInfoRect.x, v_objInfoRect.y, v_objInfoRect.width, v_objInfoRect.height ) );
                    #if ENABLE_DEBUG_THA
                    ME_Debugger_F_Printf_v("Trailer:%d,%d,%d,%d\n",v_objInfoRect.x, v_objInfoRect.y, v_objInfoRect.width, v_objInfoRect.height);
                    #endif
                    m_ObjList.pushBack_v( objInfo );
                }
		        //objInfo.setRect( Recti( v_objInfoRect.x, v_objInfoRect.y, v_objInfoRect.width, v_objInfoRect.height ) );
                    break;
            }

            // --- Coupler ball
            case 2:
            {
                objInfo.setType( ODType::Obj_Coupler );
                if( m_Cfg.getEnableODONNXCrop() == true )
                {
                    v_X = v_X + v_rectStartX;
                    v_Y = v_Y + v_rectStartY;
                    objInfo.setRect( Recti( v_X, v_Y, v_W, v_H ) );
                }
                /* Update rectangle */
                Recti v_objInfoRect = objInfo.getRect(); 
                if( ValidateAndUpdateBB( v_objInfoRect, m_ImgWidth, m_ImgHeight ) )
                {
                    // objInfo.setPoint_2D( Point2i( v_X + ( 0.5f * v_W ), v_Y + ( 0.5f * v_H ) ) );
                    objInfo.setPoint_2D( Point2i( v_objInfoRect.x + ( 0.5f * v_objInfoRect.width ), v_objInfoRect.y + ( 0.5f * v_objInfoRect.height ) ) );
                    objInfo.setRect( Recti( v_objInfoRect.x, v_objInfoRect.y, v_objInfoRect.width, v_objInfoRect.height ) );
                    #if ENABLE_DEBUG_THA
                    ME_Debugger_F_Printf_v("couplerBall:%d,%d,%d,%d\n",v_objInfoRect.x, v_objInfoRect.y, v_objInfoRect.width, v_objInfoRect.height);
                    #endif
                    m_ObjList.pushBack_v( objInfo );
                }
		        //objInfo.setRect( Recti( v_objInfoRect.x, v_objInfoRect.y, v_objInfoRect.width, v_objInfoRect.height ) );
                break;
            }

            // --- Hitch ball
            case 3:
            {
                objInfo.setType( ODType::Obj_Hitch );
                if( m_Cfg.getEnableODONNXCrop() == true )
                {
                    v_X = v_X + v_rectStartX;
                    v_Y = v_Y + v_rectStartY;
                    objInfo.setRect( Recti( v_X, v_Y, v_W, v_H ) );
                }
                /* Update rectangle */
                Recti v_objInfoRect = objInfo.getRect();
                if( ValidateAndUpdateBB( v_objInfoRect, m_ImgWidth, m_ImgHeight ) )
                {
                    // objInfo.setPoint_2D( Point2i( v_X + ( 0.5f * v_W ), v_Y + ( 0.5f * v_H ) ) );
                    objInfo.setPoint_2D( Point2i( v_objInfoRect.x + ( 0.5f * v_objInfoRect.width ), v_objInfoRect.y + ( 0.5f * v_objInfoRect.height ) ) );
                    objInfo.setRect( Recti( v_objInfoRect.x, v_objInfoRect.y, v_objInfoRect.width, v_objInfoRect.height ));
                    #if ENABLE_DEBUG_THA
                    ME_Debugger_F_Printf_v("Hitch:%d,%d,%d,%d\n",v_objInfoRect.x, v_objInfoRect.y, v_objInfoRect.width, v_objInfoRect.height);
                    #endif
                    m_ObjList.pushBack_v( objInfo );
                }
		        // objInfo.setRect( Recti( v_objInfoRect.x, v_objInfoRect.y, v_objInfoRect.width, v_objInfoRect.height) );
                break;
            }

            // --- Coupler region
            case 4:
            {
                objInfo.setType( ODType::Obj_CouplerReg );
                if( m_Cfg.getEnableODONNXCrop() == true )
                {
                    v_X = v_X + v_rectStartX;
                    v_Y = v_Y + v_rectStartY;
                    objInfo.setRect( Recti( v_X, v_Y, v_W, v_H ) );
                }
                /* Update rectangle */
                Recti v_objInfoRect = objInfo.getRect(); 
                if( ValidateAndUpdateBB( v_objInfoRect, m_ImgWidth, m_ImgHeight ) )
                {
                    // objInfo.setPoint_2D( Point2i( v_X + ( 0.5f * v_W ), v_Y + ( 0.5f * v_H ) ) );
                    objInfo.setPoint_2D( Point2i( v_objInfoRect.x + ( 0.5f * v_objInfoRect.width ), v_objInfoRect.y + ( 0.5f * v_objInfoRect.height ) ) );
                    objInfo.setRect( Recti( v_objInfoRect.x, v_objInfoRect.y, v_objInfoRect.width, v_objInfoRect.height ) );
                    #if ENABLE_DEBUG_THA
                    ME_Debugger_F_Printf_v("CplrReg:%d,%d,%d,%d\n",v_objInfoRect.x, v_objInfoRect.y, v_objInfoRect.width, v_objInfoRect.height);
                    #endif
                    m_ObjList.pushBack_v( objInfo );
                }
		        //objInfo.setRect( Recti( v_objInfoRect.x, v_objInfoRect.y, v_objInfoRect.width, v_objInfoRect.height ) ) ;                break;
                break;
            }
            default:
            {
                break;
            }
        }
    }
    ObjCnt_u8 = m_ObjList.size_u32();

    #if ENABLE_DEBUG_THA
        ME_Debugger_F_Printf_v("\n ### StateProcess: Onnx_CD_HD_Run ObjCnt_u8=%d in objlist \n\n",ObjCnt_u8);
    #endif //ENABLE_DEBUG_THA

    for( uint32_t i = 0; i < ObjCnt_u8; i++ )
    {
            Point2i PntTemp = m_ObjList[i].getPoint_2D(); /* Center point for Rect */
        float32_t v_ObjHeight = 0.0f;

            if( m_ObjList[i].getType() == ODType::Obj_Trailer )
        {
            v_ObjHeight = 0.0f;
        }
            else if( m_ObjList[i].getType() == ODType::Obj_Coupler )
        {
                v_ObjHeight = static_cast<float32_t>( m_Cfg.getCouplerHeight() );
        }
            else if( m_ObjList[i].getType() == ODType::Obj_Hitch )
        {
                v_ObjHeight = static_cast<float32_t>( m_Cfg.getDefaultHitchZ_mm() );
        }
        else
        {
            //Do Nothing
        }

        Point3f v_PntLoc( 0.0f, 0.0f, 0.0f );
        Point2i v_PntGrnd( 0, 0 );
        #ifdef _WIN32
        ConvertPointImage2WCS( PntTemp, v_PntLoc, v_PntGrnd, v_ObjHeight );
        #else
        Image2WorldCS( PntTemp, v_PntLoc, v_ObjHeight, m_ImgWidth, m_ImgHeight );
        #endif
        if( m_ObjList[i].getType() == ODType::Obj_Trailer )
        {
            //ME_Debugger_F_Printf_v("THA:loc: %f, %f\n",v_PntLoc.x,v_PntLoc.y);
        }
            m_ObjList[i].setPoint_3D( v_PntLoc );
            m_ObjList[i].setPoint_2D_Ground( v_PntGrnd );
    }
    if( ObjCnt_u8 > 0 )
    {
        ValidResultFound_b = true;
    }
    else
    {
        ValidResultFound_b = false;
    }
    #if ENABLE_DEBUG_THA
      ME_Debugger_F_Printf_v("\n ### StateProcess: Onnx_CD_HD_Run end  ValidResultFound_b = %d \n ",ValidResultFound_b);
    #endif //ENABLE_DEBUG_THA
    return ValidResultFound_b;
}

#endif//ENABLE_CD_HD

#if ENABLE_TrailerPose
bool_t StateProcess::Onnx_TrailerPose_Run(AppObj_TrailerPose* obj, const uint8_t* i_InputImg, float32_t& o_trailerAngDeg, Recti& i_rectTrailer, uint16_t i_ImgWidth, uint16_t i_ImgHeight )
{
    #if ENABLE_DEBUG_THA
        ME_Debugger_F_Printf_v("\n ### StateProcess TrailerPose: Onnx_TrailerPose_Run start \n ");
    #endif //ENABLE_DEBUG_THA
    Recti v_RectTrailerBB      = i_rectTrailer;
    bool_t ValidResultFound_b  = false;
    float32_t v_classProb      = 0.0f;
    uint32_t v_classId         = 0;
    vx_status status           = VX_SUCCESS;
    int32_t topX               = v_RectTrailerBB.x;
    int32_t topY               = v_RectTrailerBB.y;
    uint32_t cropSize          = (((v_RectTrailerBB.width)*(v_RectTrailerBB.height)*3));
    uint8_t* croppedImg        = (uint8_t *)tivxMemAlloc(cropSize, TIVX_MEM_EXTERNAL);
    uint8_t* v_inputImgCropPtr = TrailerPoseDNNInput_img;
    if(croppedImg != NULL)
    {
        #if ENABLE_DEBUG_THA
        ME_Debugger_F_Printf_v("\n ### StateProcess TrailerPose: bufsize=%d \ttopX=%d \ttopY=%d \twidth=%d \theight=%d \t ############\n", cropSize,topX,topY,v_RectTrailerBB.width,v_RectTrailerBB.height);
        #endif //ENABLE_DEBUG_THA

        // Expects RGB Planar image as input and outputs cropped RGB planar image of size trailer BB
        matrixUtil::cropRGBplanar(i_InputImg, i_ImgHeight, i_ImgWidth, croppedImg, v_RectTrailerBB.height, v_RectTrailerBB.width, topX, topY);
        #if ENABLE_DEBUG_THA
            ME_Debugger_F_Printf_v("\n ### StateProcess TrailerPose: cropRGBplanar \n ");
        #endif
        if(v_inputImgCropPtr != NULL)
        {
            // Resize cropped image to 112*112*3 as required dimension for trailerPose model
            matrixUtil::RGBPlanarBiLinearResize(croppedImg, v_RectTrailerBB.width, v_RectTrailerBB.height, v_inputImgCropPtr, obj->input_width, obj->input_height);
            // Run DNN model on C7x for interleaved RGB image
            #if PROFILE_THA
            osal::Time v_Time_o;
            uint64_t v_StartTime_u64 = 0;
            uint64_t v_EndTime_u64 = 0;
            static uint64_t v_TotalTime_u64 = 0;
            v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
            #endif
            status = app_run_graph_for_one_frame_TrailerPose(obj, v_inputImgCropPtr, &v_classProb, &v_classId);
            #if PROFILE_THA
            v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
            v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
            ME_Debugger_F_Printf_v("\ntrailer_graph: %f ms ", (float32_t)(v_TotalTime_u64 * 1.0f));
            #endif//PROFILE_THA
            tivxMemFree(croppedImg, cropSize, TIVX_MEM_EXTERNAL);
        }
        else
        {
            ME_Debugger_F_Printf_v("\n ### StateProcess TrailerPose:Resize img ptr is NULL\n ");
        }
    }
    else
    {
        ME_Debugger_F_Printf_v("\n ### StateProcess TrailerPose:Cropped img ptr is NULL\n ");
    }

    if( v_classProb > 0.5 )
    {
        o_trailerAngDeg = static_cast<float32_t>(atoi(classList[v_classId]));
        ValidResultFound_b = true;
    }
    else
    {
        ValidResultFound_b = false;
    }
    #if ENABLE_DEBUG_THA
      ME_Debugger_F_Printf_v("\n ### StateProcess: Onnx_TrailerPose_Run end \n ");
    #endif //ENABLE_DEBUG_THA
    return ValidResultFound_b;
}

#endif//ENABLE_TrailerPose

#endif//#ifdef _WIN32
#endif// OD_ONNX

#ifdef OD_TRACKER

    /*
    * Name: SetupObjectTracker
    * Remarks: DD-ID: {AF9B792F-B1E9-4387-A797-31A2BDB65A66}
    * Remarks: DD-ID: {65A84507-80C1-488d-9920-0EC7C21EDC4B}
    */
bool_t StateProcess::SetupObjectTracker( Point2i i_Pix_Detected )
{
    #if PROFILE_THA
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = 0;
    uint64_t v_EndTime_u64 = 0;
    static uint64_t v_TotalTime_u64 = 0;
    v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
    #endif //PROFILE_THA
#if THA_TRACKER_UT
    m_TrackerResizeFactorW = 3.0f;
    m_TrackerResizeFactorH = 2.74f;
    i_Pix_Detected.x = static_cast<int32_t>( static_cast<float32_t>( i_Pix_Detected.x ) / 3.0f );
    i_Pix_Detected.y = static_cast<int32_t>( static_cast<float32_t>( i_Pix_Detected.y ) / 2.74f );
#else
    i_Pix_Detected.x = static_cast<int32_t>( static_cast<float32_t>( i_Pix_Detected.x ) / m_TrackerResizeFactorW );
    i_Pix_Detected.y = static_cast<int32_t>( static_cast<float32_t>( i_Pix_Detected.y ) / m_TrackerResizeFactorH );
#endif //THA_TRACKER_UT    
	#if ENABLE_DEBUG_THA
    ME_Debugger_F_Printf_v("\n ### StateProcess:SetupObjectTracker(): i_Pix_Detected:%d,%d",i_Pix_Detected.x,i_Pix_Detected.y);
    #endif //ENABLE_DEBUG_THA
    bool_t v_TrackStart = false;

    if( m_CouplerTrackerObj.StartTrack( i_Pix_Detected ) )
    {
        v_TrackStart = true;
        #if ENABLE_DEBUG_THA
        ME_Debugger_F_Printf_v("\n ### StateProcess: SetupObjectTracker(): StartTrack true \n");
        #endif //ENABLE_DEBUG_THA
    }
    #if PROFILE_THA
    v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("\nSetTrk: %f ms ", (float32_t)(v_TotalTime_u64 * 1.0f));
    #endif//PROFILE_THA
    return v_TrackStart;
}
    /*
    * Name: ResetObjectTracker
    * Fucntion: Function to reset KCF object tracker
    * Remarks: DD-ID: {7AEBC4D1-FF05-457b-89B2-0B73325868D1}
    * Remarks: DD-ID: {1A4E766F-5A17-419d-BE9D-B662EA667B11}
    */
bool_t StateProcess::ResetObjectTracker( Point2i i_Pix_Detected )
{
    #if ENABLE_DEBUG_THA
    ME_Debugger_F_Printf_v("\n ### StateProcess: In ResetObjectTracker()");
    #endif //ENABLE_DEBUG_THA
    #if PROFILE_THA
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = 0;
    uint64_t v_EndTime_u64 = 0;
    static uint64_t v_TotalTime_u64 = 0;
    v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
    #endif //PROFILE_THA
	#if THA_TRACKER_UT
	i_Pix_Detected.x = static_cast<int32_t>( static_cast<float32_t>( i_Pix_Detected.x ) / 3.0f );
	i_Pix_Detected.y = static_cast<int32_t>( static_cast<float32_t>( i_Pix_Detected.y ) / 2.74f );
	#else
    i_Pix_Detected.x = static_cast<int32_t>( static_cast<float32_t>( i_Pix_Detected.x ) / m_TrackerResizeFactorW );
    i_Pix_Detected.y = static_cast<int32_t>( static_cast<float32_t>( i_Pix_Detected.y ) / m_TrackerResizeFactorH );
    #endif //THA_TRACKER_UT
	bool_t v_ResetTrack = false;

    if( m_CouplerTrackerObj.ResetTrack( i_Pix_Detected ) )
    {
        v_ResetTrack = true;
    }
    #if PROFILE_THA
    v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("\nResetTrk: %f ms ", (float32_t)(v_TotalTime_u64 * 1.0f));
    #endif//PROFILE_THA
    return v_ResetTrack;
}

    /*
    * Name: GetObjectTrackerConf
    * Function: Function to get KCF tracker confidence
    * Remarks: DD-ID: {DD12FAD4-1A4D-46fc-80BA-E8198412651A}
    * Remarks: DD-ID: {6C33D330-AD73-453d-9FE2-D96E5730B497}
    */
bool_t StateProcess::GetObjectTrackerConf( float32_t& i_TrkConf_rf32 )
{
    #if PROFILE_THA
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = 0;
    uint64_t v_EndTime_u64 = 0;
    static uint64_t v_TotalTime_u64 = 0;
    v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
    #endif //PROFILE_THA
    bool_t v_IsPointTracked_b = m_CouplerTrackerObj.UpdateTrackedObjectInfo();
    bool_t v_Success_b = true;

    if( v_IsPointTracked_b == true )
    {
        //Get KCF tracker peak value
            float32_t v_CurrPeakVal_f32 = m_CouplerTrackerObj.m_kcfTrackerCObj.getPeakValue_c();
        i_TrkConf_rf32 = v_CurrPeakVal_f32;//PRQA S 3706
    }
    else
    {
        i_TrkConf_rf32 = 0.0f;
        v_Success_b = false;
    }
    #if PROFILE_THA
    v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("\nconfTrk: %f ms ", (float32_t)(v_TotalTime_u64 * 1.0f));
    #endif//PROFILE_THA
    return v_Success_b;
}

void StateProcess::GetObjectTrackedPoint( int32_t& i_TrkdPntX_s32, int32_t& i_TrkdPntY_s32 ) const
{
        Point2i v_TrkdPix_s32 = m_CouplerTrackerObj.m_pTrackedInfoObj.getTrkdPix_s32();
        i_TrkdPntX_s32 = v_TrkdPix_s32.x;//PRQA S 3706
        i_TrkdPntY_s32 = v_TrkdPix_s32.y;//PRQA S 3706

#if THA_TRACKER_UT
    i_TrkdPntX_s32 = static_cast<int32_t>( static_cast<float32_t>( i_TrkdPntX_s32 ) * 3.0f );
    i_TrkdPntY_s32 = static_cast<int32_t>( static_cast<float32_t>( i_TrkdPntY_s32 ) * 2.74f );
#else
    i_TrkdPntX_s32 = static_cast<int32_t>( static_cast<float32_t>( i_TrkdPntX_s32 ) * m_TrackerResizeFactorW );
    i_TrkdPntY_s32 = static_cast<int32_t>( static_cast<float32_t>( i_TrkdPntY_s32 ) * m_TrackerResizeFactorH );
#endif //THA_TRACKER_UT
}

#endif // OD_TRACKER
/*
* Function to estimate trailer pose - conventional method
*/
float32_t StateProcess::EstimateTrailerAngle( Recti& i_rectTrailer, Point2i& i_CplrPix )
{
    int16_t v_MaxAngle = 50;
        int16_t v_Mid = static_cast<int16_t>( i_rectTrailer.x ) + ( static_cast<int16_t>( i_rectTrailer.width ) / 2 );
        float32_t v_res = static_cast<float32_t>( v_MaxAngle ) / ( static_cast<float32_t>( i_rectTrailer.width ) / 2.0f ); // resolution in deg/pix
    float32_t v_TrlrAngle = static_cast<float32_t>( v_Mid - i_CplrPix.x ) * v_res;
    return v_TrlrAngle;
}
    /*
    * Name: ConventionalTrailerPose_Run
    * Function: Function to estimate trailer angle is too steep based on point's lateral position check
    * Remarks: DD-ID: {28EB977D-470D-4cfb-A15D-929F0D342D58}
    * Remarks: DD-ID: {504D5750-5F3E-4d31-B177-E1C57BEA579E}
    */
float32_t StateProcess::ConventionalTrailerPose_Run( Recti& i_Rect, Point2i& i_PointPix, uint8_t i_LatOffPerc, uint8_t i_CplrBallOffset )
{
    bool_t v_AngleSteep_b = false;
    float32_t v_TrlrAngle = 0.0f;
        int32_t v_LatPixOffset = static_cast<int32_t>( static_cast<float32_t>( i_Rect.width ) * ( static_cast<float32_t>( i_LatOffPerc ) / 100.0f ) + 0.5f ) + static_cast<int32_t>( i_CplrBallOffset );
    int32_t v_CplrTrlrLatXDiffLeft_pix = i_PointPix.x - i_Rect.tl().x;
    int32_t v_CplrTrlrLatXDiffRight_pix = i_Rect.br().x - i_PointPix.x;

    if( ( v_CplrTrlrLatXDiffLeft_pix < v_LatPixOffset ) ||
        ( v_CplrTrlrLatXDiffRight_pix < v_LatPixOffset ) )
    {
        v_AngleSteep_b = true;
        v_TrlrAngle = 90.0f;
    }

    if( v_AngleSteep_b == false )
    {
        v_TrlrAngle = EstimateTrailerAngle( i_Rect, i_PointPix );
    }

    return v_TrlrAngle;
}
/*
* Functions to validate and correct bounding box w.r.t. image size
*/
bool StateProcess::ValidateAndUpdateBB( Recti& io_BB, int32_t i_imgW, int32_t i_imgH )
{
    bool_t v_ValidBB_b = false;
    io_BB.x = ( io_BB.x < 0 ) ? 0 : io_BB.x;
    io_BB.y = ( io_BB.y < 0 ) ? 0 : io_BB.y;
    io_BB.x = ( io_BB.x < i_imgW ) ? io_BB.x : ( i_imgW - 1 );
    io_BB.y = ( io_BB.y < i_imgH ) ? ( io_BB.y ) : ( i_imgH - 1 );
    io_BB.width = ( ( io_BB.x + io_BB.width ) < i_imgW ) ?
                  io_BB.width : ( i_imgW - io_BB.x );
    io_BB.height = ( ( io_BB.y + io_BB.height ) < i_imgH ) ?
                   io_BB.height : ( i_imgH - io_BB.y );

    if( ( io_BB.width < 2 ) || ( io_BB.height < 2 ) )
    {
        v_ValidBB_b = false;
    }
    else
    {
        v_ValidBB_b = true;
    }

    return v_ValidBB_b;
}

    /*
    * Name: IsCouplerInsideTrailer
    * Function: Function to verify detected coupler ball is inside trailer bounding box
    * Remarks: DD-ID: {B2A6FB15-8F6C-4174-BEE2-FD05D323958C}
    * Remarks: DD-ID: {5DAF6171-4602-470c-8AD4-C2403109912E}
    */
bool_t StateProcess::IsCouplerInsideTrailer( Recti& i_TrlrBB, Point2i& i_CplrPix )
{
    bool_t v_CplrInTrlr_b = true;
    // Dynamic padding offset
    Recti v_TrlrBBPad = i_TrlrBB;
        uint32_t v_PadPerc = 10; // Padding percentage for the BB
        uint32_t v_BBPadW = ( v_TrlrBBPad.width * v_PadPerc ) / 100;
        uint32_t v_BBPadH = ( v_TrlrBBPad.height * v_PadPerc ) / 100;
    v_TrlrBBPad.x = v_TrlrBBPad.x - v_BBPadW;
    v_TrlrBBPad.y = v_TrlrBBPad.y - v_BBPadH;
    v_TrlrBBPad.width = v_TrlrBBPad.width + ( v_BBPadW * 2 );
    v_TrlrBBPad.height = v_TrlrBBPad.height + ( v_BBPadH * 2 );
    v_CplrInTrlr_b = IsPointInROI( v_TrlrBBPad, i_CplrPix );
    return v_CplrInTrlr_b;
}

    /*
    * Name: IsPointInROI
    * Function: Function to check it point is within given ROI
    * Remarks: DD-ID: {512B76AC-C4C2-4023-B6A7-627F24B77BB4}
    * Remarks: DD-ID: {E43400B7-5B6B-44eb-87BA-0298D509E500}
    */
bool_t StateProcess::IsPointInROI( Recti& i_RectBB, Point2i& i_Pix )
{
    bool_t v_IsInROI_b = true;
    int32_t v_LongYDiffTop_pix = i_Pix.y - i_RectBB.tl().y;
    int32_t v_LongYDiffBot_pix = i_RectBB.br().y - i_Pix.y;
    int32_t v_LatXDiffLeft_pix = i_Pix.x - i_RectBB.tl().x;
    int32_t v_LatXDiffRight_pix = i_RectBB.br().x - i_Pix.x;

    if( ( v_LongYDiffTop_pix < 0 ) ||
        ( v_LongYDiffBot_pix < 0 ) ||
        ( v_LatXDiffLeft_pix < 0 ) ||
        ( v_LatXDiffRight_pix < 0 ) )
    {
        v_IsInROI_b = false;
    }

    return v_IsInROI_b;
}
    /*
    * Name: IsDetectedPointInsideROI
    * Function: Function to check if detected point is within some ROI of User selected point
    * Remarks: DD-ID: {E590DE4C-0E97-42e6-895E-F8311681BAA3}
    * Remarks: DD-ID: {C7138069-ACE5-4b6e-901B-B8DCA9FE32E2}
    */
bool_t StateProcess::IsDetectedPointInsideROI( Point2i& i_DetCplrPix, Point2i& i_SelectedCplrPix, uint16_t i_ROIWidth, uint16_t i_ROIHeight )
{
    bool_t v_IsInROI_b = true;
    // Define ROI with seleted point as center
    Recti v_ROI = Recti( i_SelectedCplrPix.x - ( static_cast<int32_t>( i_ROIWidth ) / 2 ), i_SelectedCplrPix.y - ( static_cast<int32_t>( i_ROIHeight ) / 2 ), static_cast<int32_t>( i_ROIWidth ), static_cast<int32_t>( i_ROIHeight ) );
    // Check if selected point is within ROI
    v_IsInROI_b = IsPointInROI( v_ROI, i_DetCplrPix );
    return v_IsInROI_b;
}

/*
    * Name: TransformHMICplrPnt
    * Function: Transform HMI Cplr Pnt in 640x400 resolution
    * Remarks: DD-ID: {D1328BB4-0171-4ced-B673-43624ACD1C0F}
    * Remarks: DD-ID: {732FF73B-49FE-48da-AFA2-D589E2CBDEA0}
    */
    void StateProcess::TransformHMICplrPnt( Point2i& b_UsrSelCplrPnt_rs32, uint16_t& i_HMICplrX_ru16, uint16_t& i_HMICplrY_ru16 ) const
{
    //Transform on embedded
    uint16_t v_TransW_u16 = m_ImgWidth;
    uint16_t v_TransH_u16 = m_ImgHeight;
        b_UsrSelCplrPnt_rs32 = Point2i( ( static_cast<int32_t>( v_TransW_u16 ) - static_cast<int32_t>( i_HMICplrX_ru16 ) ), static_cast<int32_t>( v_TransH_u16 ) - static_cast<int32_t>( i_HMICplrY_ru16 ) );

    if( b_UsrSelCplrPnt_rs32.x < 0 )
    {
        b_UsrSelCplrPnt_rs32.x = 0;
    }

    if( b_UsrSelCplrPnt_rs32.y < 0 )
    {
        b_UsrSelCplrPnt_rs32.y = 0;
    }

    if( b_UsrSelCplrPnt_rs32.x >= static_cast<int32_t>( v_TransW_u16 ) )
    {
        b_UsrSelCplrPnt_rs32.x = static_cast<int32_t>( v_TransW_u16 ) - 1;
    }

    if( b_UsrSelCplrPnt_rs32.y >= static_cast<int32_t>( v_TransH_u16 ) )
    {
        b_UsrSelCplrPnt_rs32.y = static_cast<int32_t>( v_TransH_u16 ) - 1;
    }
}
    /*
    * Name: IsObjectFound
    * Function: Function to verify detected object list with the specified object detected only once or multiple or not any instance found
    * Remarks: DD-ID: {70C1E6E0-1D98-440c-B497-3255B59F46EC}
    * Remarks: DD-ID: {05D9FA83-848A-4a97-B257-E666CCC942D0}
    */

bool_t StateProcess::IsObjectFound( mecl::core::ArrayList<ODInfo, MAX_DETECTIONS>& i_ODList,
                                    ODType i_ObjType,
                                    ODInfo& o_ObjInfo )
{
    bool_t v_success_b = false;
    bool_t v_isValObjFnd_b = false;
    uint32_t v_TotalObj_u32 = static_cast<uint32_t>( i_ODList.size_u32() );
    const uint32_t v_MaxObjIns_u32 = 5;
    uint16_t v_EucDistThresh = 0;
        float32_t v_EucDistWidthThrsh = 0.5f;
    mecl::core::ArrayList<ODInfo, v_MaxObjIns_u32> v_ObjList_s;

    for( uint32_t i = 0; i < v_TotalObj_u32; i++ )
    {
            if( ( i_ODList[i].getType() == i_ObjType ) && !v_ObjList_s.isFull_b() )
        {
            v_ObjList_s.pushBack_v( i_ODList[i] );
        }
    }

    // For Multiple objects
    if( v_ObjList_s.size_u32() > 1 )
    {
        // For Hitch - Select hitch near to the center of image
        if( i_ObjType == Obj_Hitch )
        {
            uint16_t v_MinLatDist_16 = UINT16_MAX;
            uint16_t v_MinLatDistIndx_u16 = 0;
            //TODO: Check tranformations in embedded code and use correct width below
            uint16_t v_HalfImgWidth_u16 = m_ImgWidth / 2;

            for( uint16_t v_Indx_u16 = 0; v_Indx_u16 < v_ObjList_s.size_u32(); v_Indx_u16++ )
            {
                uint16_t v_LatDist_u16 = 0;
                    v_LatDist_u16 = static_cast<uint16_t>( mecl::math::abs_x( static_cast<int32_t>( v_HalfImgWidth_u16 ) - v_ObjList_s[v_Indx_u16].getPoint_2D().x ) );

                if( v_LatDist_u16 < v_MinLatDist_16 )
                {
                    v_MinLatDist_16 = v_LatDist_u16;
                    v_MinLatDistIndx_u16 = v_Indx_u16;
                }
            }

            o_ObjInfo = v_ObjList_s[v_MinLatDistIndx_u16];
            v_success_b = true;
        }
        // For Trailer/Coupler region/Coupler ball
        else
        {
                uint16_t v_MinEucDist_u16 = UINT16_MAX;
            uint16_t v_MinEucDistIndx_u16 = 0;

            for( uint16_t v_Indx_u16 = 0; v_Indx_u16 < v_ObjList_s.size_u32(); v_Indx_u16++ )
            {
                v_isValObjFnd_b = false;

                // For multiple objects on 1st detection
                if( m_StatusCplrZone_b == false )
                {
                        uint16_t v_EucDist_u16 = 0;
                    Point2i v_UsrSelPnt_s32 = Point2i( 0, 0 );
#ifdef _WIN32
                    v_UsrSelPnt_s32 = Point2i( static_cast<int32_t>( m_JobTHAInput.HMIInput_s.CplrPixX_u16 ), static_cast<int32_t>( m_JobTHAInput.HMIInput_s.CplrPixY_u16 ) );
#else
                    TransformHMICplrPnt( v_UsrSelPnt_s32, m_JobTHAInput.HMIInput_s.CplrPixX_u16, m_JobTHAInput.HMIInput_s.CplrPixY_u16 );
#endif // _WIN32
#ifdef USR_POINT_WITH_TRLRBB

                    // Check user selected point is inside trailer BB
                    if( i_ObjType == Obj_Trailer )
                    {
                            Recti v_objList_rect = v_ObjList_s[v_Indx_u16].getRect();
                            v_isValObjFnd_b = IsCouplerInsideTrailer( v_objList_rect, v_UsrSelPnt_s32 );
                    }

                    if( i_ObjType == Obj_CouplerReg )
                    {
                        if( m_ValidTrlrRectCurr_b == true )
                        {
                                Point2i v_objList_point2D = v_ObjList_s[v_Indx_u16].getPoint_2D();
                                v_isValObjFnd_b = IsCouplerInsideTrailer( m_ValidTrlrRectCurr, v_objList_point2D );
                            }
                            else
                            {
                                Recti v_objList_rect = v_ObjList_s[v_Indx_u16].getRect();
                                v_isValObjFnd_b = IsCouplerInsideTrailer( v_objList_rect, v_UsrSelPnt_s32 );
                        }
                    }

                    if( i_ObjType == Obj_Coupler )
                    {
                        if( m_ValidCplrRegRectCurr_b == true )
                        {
                                Point2i v_objList_point2D = v_ObjList_s[v_Indx_u16].getPoint_2D();
                                v_isValObjFnd_b = IsCouplerInsideTrailer( m_ValidCplrRegRectCurr, v_objList_point2D );
                        }
                        else
                        {
                            if( m_ValidTrlrRectCurr_b == true )
                            {
                                    Point2i v_objList_point2D = v_ObjList_s[v_Indx_u16].getPoint_2D();
                                    v_isValObjFnd_b = IsCouplerInsideTrailer( m_ValidTrlrRectCurr, v_objList_point2D );
                            }
                            else
                            {
                                    Point2i v_objList_point2D = v_ObjList_s[v_Indx_u16].getPoint_2D();
                                    v_isValObjFnd_b = IsDetectedPointInsideROI( v_objList_point2D, v_UsrSelPnt_s32, m_Cfg.getROIWidth(), m_Cfg.getROIHeight() );
                            }
                        }
                    }

                    if( v_isValObjFnd_b == true )
                    {
                        // Euclidean distance check for user selected point in multiple trailers
                            Point2i v_objList_point2D = v_ObjList_s[v_Indx_u16].getPoint_2D();
                            v_EucDist_u16 = static_cast<uint16_t>( getEuclideanDist( v_UsrSelPnt_s32, v_objList_point2D ) );

                            if( v_EucDist_u16 < v_MinEucDist_u16 )
                            {
                                v_MinEucDist_u16 = v_EucDist_u16;
                            v_MinEucDistIndx_u16 = v_Indx_u16;
                            o_ObjInfo = v_ObjList_s[v_MinEucDistIndx_u16];
                            v_success_b = true;
                        }
                    }

#endif // USR_POINT_WITH_TRLRBB
                }
                // For multiple objects after 1st detection
                else
                {
                    uint16_t v_EucDist_u16 = UINT16_MAX;

                    if( ( i_ObjType == Obj_Trailer ) )
                    {
                        v_EucDistThresh = m_EucDistThrshTrlr;

                        Recti v_objList_rect = v_ObjList_s[v_Indx_u16].getRect();
                        Point2i v_objList_point2D = v_ObjList_s[v_Indx_u16].getPoint_2D();
                        if( m_TrlrDetStsPrev_e == TrlrDetStatus_e::e_Trlr_Detected )
                        {
                                v_EucDist_u16 = static_cast<uint16_t>( getEuclideanDist( v_objList_point2D, m_TrlrPixPrev ) );
                        }
                            else if( IsCouplerInsideTrailer( v_objList_rect, m_OpPixPrev ) )
                        {
                                v_EucDistThresh = static_cast<uint16_t>( static_cast<float32_t>( v_ObjList_s[v_Indx_u16].getRect().width ) * v_EucDistWidthThrsh );
                                v_EucDist_u16 = static_cast<uint16_t>( getEuclideanDist( v_objList_point2D, m_OpPixPrev ) );
                        }
                        else
                        {
                            // Do Nothing
                        }
                    }

                    if( i_ObjType == Obj_CouplerReg )
                    {
                        Point2i v_objList_point2D = v_ObjList_s[v_Indx_u16].getPoint_2D();
                        v_EucDistThresh = m_EucDistThrshCplrReg;

                            Recti v_objList_rect = v_ObjList_s[v_Indx_u16].getRect();
                            if( m_CplrRegDetStsPrev_e == CplrDetStatus_e::e_Cplr_Detected )
                        {
                                v_EucDist_u16 = static_cast<uint16_t>( getEuclideanDist( v_objList_point2D, m_CplrRegPixPrev ) );
                        }
                            else if( IsCouplerInsideTrailer( v_objList_rect, m_OpPixPrev ) )
                        {
                                v_EucDistThresh = static_cast<uint16_t>( static_cast<float32_t>( v_ObjList_s[v_Indx_u16].getRect().width ) * v_EucDistWidthThrsh );
                                v_EucDist_u16 = static_cast<uint16_t>( getEuclideanDist( v_objList_point2D, m_OpPixPrev ) );
                        }
                        else if( ( m_ValidTrlrRectCurr_b == true ) && IsCouplerInsideTrailer( m_ValidTrlrRectCurr, v_objList_point2D ) )
                        {   
                            v_EucDistThresh = static_cast<uint16_t>( static_cast<float32_t>( v_ObjList_s[v_Indx_u16].getRect().width ) * v_EucDistWidthThrsh );
                            v_EucDist_u16 = static_cast<uint16_t>( getEuclideanDist( v_objList_point2D, m_OpPixPrev ) );
                        }
                        else
                        {
                            // Do Nothing
                        }
                    }

                    if( i_ObjType == Obj_Coupler )
                    {
                        Point2i v_objList_point2D = v_ObjList_s[v_Indx_u16].getPoint_2D();
                        v_EucDistThresh = m_EucDistThrshCplrBall;

                        if( m_CplrBallDetStsPrev_e == CplrDetStatus_e::e_Cplr_Detected )
                        {
                                v_EucDist_u16 = static_cast<uint16_t>( getEuclideanDist( v_objList_point2D, m_CplrPixPrev ) );
                        }
                            else if( ( m_ValidCplrRegRectCurr_b == true ) && ( IsCouplerInsideTrailer( m_ValidCplrRegRectCurr, v_objList_point2D ) ) )
                        {
                                v_EucDistThresh = static_cast<uint16_t>( static_cast<float32_t>( m_ValidCplrRegRectCurr.width ) * v_EucDistWidthThrsh );
                                v_EucDist_u16 = static_cast<uint16_t>( getEuclideanDist( v_objList_point2D, m_OpPixPrev ) );
                        }
                            else if( ( m_ValidTrlrRectCurr_b == true ) && ( IsCouplerInsideTrailer( m_ValidTrlrRectCurr, v_objList_point2D ) ) )
                        {
                                v_EucDistThresh = static_cast<uint16_t>( static_cast<float32_t>( m_ValidTrlrRectCurr.width ) * v_EucDistWidthThrsh );
                                v_EucDist_u16 = static_cast<uint16_t>( getEuclideanDist( v_objList_point2D, m_OpPixPrev ) );
                        }
                        else
                        {
                            // Do Nothing
                        }
                    }

                        if( v_EucDist_u16 < v_MinEucDist_u16 )
                    {
                            v_MinEucDist_u16 = v_EucDist_u16;
                        v_MinEucDistIndx_u16 = v_Indx_u16;

                        if( v_EucDist_u16 < v_EucDistThresh )
                        {
                            o_ObjInfo = v_ObjList_s[v_MinEucDistIndx_u16];
                            v_success_b = true;
                        }
                    }
                }
            }
        }
    }
    // For single object
    else if( v_ObjList_s.size_u32() == 1 )
    {
        v_isValObjFnd_b = false;

        // For Hitch
        if( i_ObjType == Obj_Hitch )
        {
            o_ObjInfo = v_ObjList_s[0];
            v_success_b = true;
        }
        // For Trailer/Coupler region/Coupler ball
        else
        {
            // For single object on 1st detection
            if( m_StatusCplrZone_b == false )
            {
                Point2i v_UsrSelPnt_s32 = Point2i( 0, 0 );
#ifdef _WIN32
                v_UsrSelPnt_s32 = Point2i( static_cast<int32_t>( m_JobTHAInput.HMIInput_s.CplrPixX_u16 ), static_cast<int32_t>( m_JobTHAInput.HMIInput_s.CplrPixY_u16 ) );
#else
                TransformHMICplrPnt( v_UsrSelPnt_s32, m_JobTHAInput.HMIInput_s.CplrPixX_u16, m_JobTHAInput.HMIInput_s.CplrPixY_u16 );
#endif //_WIN32
#ifdef USR_POINT_WITH_TRLRBB

                // Check user selected point is inside trailer BB
                if( i_ObjType == Obj_Trailer )
                {
                        Recti v_objList_rect = v_ObjList_s[0].getRect();
                        v_isValObjFnd_b = IsCouplerInsideTrailer( v_objList_rect, v_UsrSelPnt_s32 );
                }

                if( i_ObjType == Obj_CouplerReg )
                {
                    if( m_ValidTrlrRectCurr_b == true )
                    {
                            Point2i v_objList_point2D = v_ObjList_s[0].getPoint_2D();
                            v_isValObjFnd_b = IsCouplerInsideTrailer( m_ValidTrlrRectCurr, v_objList_point2D );
                    }
                    else
                    {
                            Recti v_objList_rect = v_ObjList_s[0].getRect();
                            v_isValObjFnd_b = IsCouplerInsideTrailer( v_objList_rect, v_UsrSelPnt_s32 );
                    }
                }

                if( i_ObjType == Obj_Coupler )
                {
                    Point2i v_objList_point2D = v_ObjList_s[0].getPoint_2D();
                    if( m_ValidCplrRegRectCurr_b == true )
                    {
                            v_isValObjFnd_b = IsCouplerInsideTrailer( m_ValidCplrRegRectCurr, v_objList_point2D );
                    }
                    else
                    {
                        if( m_ValidTrlrRectCurr_b == true )
                        {
                                v_isValObjFnd_b = IsCouplerInsideTrailer( m_ValidTrlrRectCurr, v_objList_point2D );
                        }
                        else
                        {
                                v_isValObjFnd_b = IsDetectedPointInsideROI( v_objList_point2D, v_UsrSelPnt_s32, m_Cfg.getROIWidth(), m_Cfg.getROIHeight() );
                        }
                    }
                }

                if( v_isValObjFnd_b == true )
                {
                    v_success_b = true;
                    o_ObjInfo = v_ObjList_s[0];
                }

#endif // USR_POINT_WITH_TRLRBB
            }
            // For single object after 1st detection
            else
            {
                uint16_t v_EucDist_u16 = UINT16_MAX;

                if( ( i_ObjType == Obj_Trailer ) )
                {
                    Recti v_objList_rect = v_ObjList_s[0].getRect();
                    v_EucDistThresh = m_EucDistThrshTrlr;

                    if( m_TrlrDetStsPrev_e == TrlrDetStatus_e::e_Trlr_Detected )
                    {
                            Point2i v_objList_point2D = v_ObjList_s[0].getPoint_2D();
                            v_EucDist_u16 = static_cast<uint16_t>( getEuclideanDist( v_objList_point2D, m_TrlrPixPrev ) );
                        }
                        else if( IsCouplerInsideTrailer( v_objList_rect, m_OpPixPrev ) )
                        {
                            v_EucDist_u16 = 0;
                        }
                        else
                        {
                            // Do Nothing
                        }
                    }
                    if( i_ObjType == Obj_CouplerReg )
                    {
                        Point2i v_objList_point2D = v_ObjList_s[0].getPoint_2D();
                        Recti v_objList_rect = v_ObjList_s[0].getRect();
                        v_EucDistThresh = m_EucDistThrshCplrReg;

                        if( m_CplrRegDetStsPrev_e == CplrDetStatus_e::e_Cplr_Detected )
                        {
                            v_EucDist_u16 = static_cast<uint16_t>( getEuclideanDist( v_objList_point2D, m_CplrRegPixPrev ) );
                        }
                        else if( IsCouplerInsideTrailer( v_objList_rect, m_OpPixPrev ) )
                        {
                            v_EucDist_u16 = 0;
                        }
                        else if( ( m_ValidTrlrRectCurr_b == true ) && IsCouplerInsideTrailer( m_ValidTrlrRectCurr, v_objList_point2D ) )
                        {
                            v_EucDist_u16 = 0;
                        }
                        else
                        {
                            // Do Nothing
                        }
                    }

                if( i_ObjType == Obj_Coupler )
                {
                    Point2i v_objList_point2D = v_ObjList_s[0].getPoint_2D();
                    v_EucDistThresh = m_EucDistThrshCplrBall;

                    if( m_CplrBallDetStsPrev_e == CplrDetStatus_e::e_Cplr_Detected )
                    {
                            v_EucDist_u16 = static_cast<uint16_t>( getEuclideanDist( v_objList_point2D, m_CplrPixPrev ) );
                    }
                        else if( ( m_ValidCplrRegRectCurr_b == true ) && ( IsCouplerInsideTrailer( m_ValidCplrRegRectCurr, v_objList_point2D ) ) )
                    {
                        v_EucDist_u16 = 0;
                    }
                        else if( ( m_ValidTrlrRectCurr_b == true ) && ( IsCouplerInsideTrailer( m_ValidTrlrRectCurr, v_objList_point2D ) ) )
                    {
                        v_EucDist_u16 = 0;
                    }
                    else
                    {
                        // Do Nothing
                    }
                }

                if( v_EucDist_u16 < v_EucDistThresh )
                {
                    o_ObjInfo = v_ObjList_s[0];
                    v_success_b = true;
                }
            }
        }
    }
    else
    {
        // Do Nothing
    }

    return v_success_b;
}

/*
* Functions to convert image 2D point to world 3D point
*/
// #ifdef _WIN32
void StateProcess::ConvertPointImage2WCS( Point2i i_Point2D, Point3f& o_Dist3D, Point2i& o_Point2DGround, float32_t i_Point2DHeight )
{
    bool_t b_OrginCamWCSDifferent = true;
    o_Point2DGround.x = i_Point2D.x;
    o_Point2DGround.y = i_Point2D.y;
    o_Dist3D = Point3f( 0, 0, 0 );
    //find X,Y with x,y,Z known
    Point2f tempPoint2D = Point2f( static_cast<float32_t>( i_Point2D.x ), static_cast<float32_t>( i_Point2D.y ) );
    Point2f point2DUnwarpGround = m_IDataProvider->pixel_unwarp( &tempPoint2D );

    if( i_Point2DHeight > 0.0f )
    {
        float32_t A[2][2];
        float32_t b[2];
        float32_t interimX;
        float32_t interimY;
        float32_t tempx;
        float32_t tempy;
        float32_t P_MECL[3][4];
        Point3f point3D;
        m_IDataProvider->getP_MECL( P_MECL ); //PRQA S 3840
        //Project back to 3D
        tempx = point2DUnwarpGround.x;
        tempy = point2DUnwarpGround.y;
        A[0][0] = P_MECL[0][0] - tempx * P_MECL[2][0];//PRQA S 3708
        A[0][1] = P_MECL[0][1] - tempx * P_MECL[2][1];//PRQA S 3708
        b[0] = ( tempx * P_MECL[2][2] - P_MECL[0][2] ) * i_Point2DHeight + tempx * P_MECL[2][3] - P_MECL[0][3]; //PRQA S 3708
        A[1][0] = P_MECL[1][0] - tempy * P_MECL[2][0];//PRQA S 3708
        A[1][1] = P_MECL[1][1] - tempy * P_MECL[2][1];//PRQA S 3708
        b[1] = ( tempy * P_MECL[2][2] - P_MECL[1][2] ) * i_Point2DHeight + tempy * P_MECL[2][3] - P_MECL[1][3]; //PRQA S 3708
        interimX = ( A[1][1] * b[0] - A[0][1] * b[1] ) / ( A[0][0] * A[1][1] - A[0][1] * A[1][0] ); //PRQA S 3708
        interimY = ( -A[1][0] * b[0] + A[0][0] * b[1] ) / ( A[0][0] * A[1][1] - A[0][1] * A[1][0] ); //PRQA S 3708
        point3D.x = static_cast<float32_t>( interimX );
        point3D.y = static_cast<float32_t>( interimY );
        point3D.z = 0;
        //--- For reprojection on image
        point2DUnwarpGround = m_IDataProvider->ProjectTo2D( point3D );
        Point2f point2DWarpGround = m_IDataProvider->pixel_warp( point2DUnwarpGround );
        o_Point2DGround.x = static_cast<int32_t>( point2DWarpGround.x );
        o_Point2DGround.y = static_cast<int32_t>( point2DWarpGround.y );

        // If WCS origin is not at camera's center position
        if( b_OrginCamWCSDifferent )
        {
            o_Dist3D.x = point3D.x - m_IDataProvider->getDeltaX();//PRQA S 3708
            o_Dist3D.y = point3D.y - m_IDataProvider->getDeltaY();//PRQA S 3708
        }
    }
    else
    {
        Point2f temp;
        temp = m_IDataProvider->unwarped_distance( point2DUnwarpGround );

        if( b_OrginCamWCSDifferent )
        {
            o_Dist3D.x = temp.x - m_IDataProvider->getDeltaX();//PRQA S 3708
            o_Dist3D.y = temp.y - m_IDataProvider->getDeltaY();//PRQA S 3708
        }
    }

    /*
    * Convert object distance from mm to meter
    */
    o_Dist3D.x = o_Dist3D.x / 1000.0f;
    o_Dist3D.y = o_Dist3D.y / 1000.0f;
    o_Dist3D.z = o_Dist3D.z / 1000.0f;
}
// #else 
extern "C"
{
    extern void view_manager_raw_2_world_3D_rear_for_tha( float32_t raw_x, float32_t raw_y, int32_t refWorld_z, float32_t result_xyz[3]);
}
//(0,1) Normalization
void StateProcess::convert_pixel_to_raw_coordinates(int32_t pixel_x, int32_t pixel_y, int32_t width, int32_t height,
                                      float32_t *x1, float32_t *y1)
{
    *x1 = (float32_t)pixel_x / (float32_t)width;
    *y1 = (float32_t)pixel_y / (float32_t)height;
}

void StateProcess::Image2WorldCS( Point2i i_Point2D, Point3f& o_Dist3D, float32_t i_Point2DHeight, uint32_t width, uint32_t Height )
{
    float32_t real_xyz[3] = {0.0f, 0.0f, 0.0f};
    float32_t norm_xy[2] = {0.0f, 0.0f};
    float32_t uv[2] = {0.0f, 0.0f}; 
    uv[0] = (float32_t)i_Point2D.x;
    uv[1] = (float32_t)i_Point2D.y;
    
    //Flip co-ordinates
    //i_Point2D.x = width - i_Point2D.x;
    i_Point2D.y = Height - i_Point2D.y;
    // Normailze;
    convert_pixel_to_raw_coordinates(i_Point2D.x, i_Point2D.y, width, Height, &norm_xy[0], &norm_xy[1]);
    view_manager_raw_2_world_3D_rear_for_tha( norm_xy[0], norm_xy[1], (int32_t)i_Point2DHeight, real_xyz);
    o_Dist3D.x = real_xyz[0];
    o_Dist3D.y = real_xyz[1];
    o_Dist3D.z = real_xyz[2];

    /*
     * Convert object distance from mm to meter
     */
    o_Dist3D.x = real_xyz[0] / 1000.0f;
    o_Dist3D.y = real_xyz[1] / 1000.0f;
    o_Dist3D.z = real_xyz[2] / 1000.0f;

    // Magna THA ;
    o_Dist3D.x = o_Dist3D.x * (-1);
    o_Dist3D.y = o_Dist3D.y * (-1);

    // printf("Pixel 2D Points = (%f, %f)\n", uv[0], uv[1]);
    // printf("Norm 2D Points = (%f, %f),\n", norm_xy[0], norm_xy[1]);
    // printf("Real 3D Points (x, y, z) = (%f, %f, %f)\n", o_Dist3D.x, o_Dist3D.y, o_Dist3D.z);
    // printf("THA Real 3D Points (x, y, z) = (%f, %f, %f)\n", o_Dist3D.x * -1.0, o_Dist3D.y * -1.0, o_Dist3D.z);
}

/*
* Function to convert world 3D point to image 2D point
*/
void StateProcess::ConvertWCS2PointImage( Point3f& i_Dist3Dm, Point2i& o_Point2D )
{
    Point3f v_Dist3Dm = i_Dist3Dm;
    bool_t b_OrginCamWCSDifferent = true;
    v_Dist3Dm.x = v_Dist3Dm.x * 1000.0f;
    v_Dist3Dm.y = v_Dist3Dm.y * 1000.0f;
    v_Dist3Dm.z = v_Dist3Dm.z * 1000.0f;

    if( b_OrginCamWCSDifferent )
    {
        v_Dist3Dm.x = v_Dist3Dm.x + m_IDataProvider->getDeltaX();//PRQA S 3708
        v_Dist3Dm.y = v_Dist3Dm.y + m_IDataProvider->getDeltaY();//PRQA S 3708
    }

    Point2f PointUnwarped = m_IDataProvider->ProjectTo2D( v_Dist3Dm );
    Point2f PointWarped = m_IDataProvider->pixel_warp( PointUnwarped );
    o_Point2D.x = static_cast<int32_t>( PointWarped.x );
    o_Point2D.y = static_cast<int32_t>( PointWarped.y );
}

#if ENABLE_SMOOTH_OP
/*
* Kalman filter based 1D value estimation
*/
float32_t StateProcess::KFSmooth1D( float32_t i_Value )
{
    float32_t v_ValueSmooth = i_Value;

    if( !KF_Ang.is_filter_ready() )
    {
        KF_Ang.gather_initial_measurements( i_Value );

        if( KF_Ang.is_filter_ready() )
        {
            v_ValueSmooth = KF_Ang.kalman_process();
        }
    }
    else
    {
        KF_Ang.update_measurements_array( i_Value );
        v_ValueSmooth = KF_Ang.kalman_process();
    }

    return v_ValueSmooth;
}
#endif //ENABLE_SMOOTH_OP

/*
* Kalman filter based Hitch point estimation
*/
Recti StateProcess::KFSmoothHitchBB( Recti i_BB )
{
    Recti v_BBSmooth = i_BB;

    if( !KF_HitchX.is_filter_ready() )
    {
        KF_HitchX.gather_initial_measurements( static_cast<float32_t>( i_BB.x ) );

        if( KF_HitchX.is_filter_ready() )
        {
            v_BBSmooth.x = static_cast<int32_t>( KF_HitchX.kalman_process() );
        }
    }
    else
    {
        KF_HitchX.update_measurements_array( static_cast<float32_t>( i_BB.x ) );
        v_BBSmooth.x = static_cast<int32_t>( KF_HitchX.kalman_process() );
    }

    if( !KF_HitchY.is_filter_ready() )
    {
        KF_HitchY.gather_initial_measurements( static_cast<float32_t>( i_BB.y ) );

        if( KF_HitchY.is_filter_ready() )
        {
            v_BBSmooth.y = static_cast<int32_t>( KF_HitchY.kalman_process() );
        }
    }
    else
    {
        KF_HitchY.update_measurements_array( static_cast<float32_t>( i_BB.y ) );
        v_BBSmooth.y = static_cast<int32_t>( KF_HitchY.kalman_process() );
    }

    if( !KF_HitchH.is_filter_ready() )
    {
        KF_HitchH.gather_initial_measurements( static_cast<float32_t>( i_BB.height ) );

        if( KF_HitchH.is_filter_ready() )
        {
            v_BBSmooth.height = static_cast<int32_t>( KF_HitchH.kalman_process() );
        }
    }
    else
    {
        KF_HitchH.update_measurements_array( static_cast<float32_t>( i_BB.height ) );
        v_BBSmooth.height = static_cast<int32_t>( KF_HitchH.kalman_process() );
    }

    if( !KF_HitchW.is_filter_ready() )
    {
        KF_HitchW.gather_initial_measurements( static_cast<float32_t>( i_BB.width ) );

        if( KF_HitchW.is_filter_ready() )
        {
            v_BBSmooth.width = static_cast<int32_t>( KF_HitchW.kalman_process() );
        }
    }
    else
    {
        KF_HitchW.update_measurements_array( static_cast<float32_t>( i_BB.width ) );
        v_BBSmooth.width = static_cast<int32_t>( KF_HitchW.kalman_process() );
    }

    return v_BBSmooth;
}
    /*
    * Kalman filter based Hitch point estimation
    */
    void StateProcess::KFSmoothTrlrBasePoint( Point3f& i_Point_3f )
    {
        if( !KF_TrlrBaseX.is_filter_ready() )
        {
            KF_TrlrBaseX.gather_initial_measurements( i_Point_3f.x );

            if( KF_TrlrBaseX.is_filter_ready() )
            {
                i_Point_3f.x = KF_TrlrBaseX.kalman_process();
            }
        }
        else
        {
            KF_TrlrBaseX.update_measurements_array( i_Point_3f.x );
            i_Point_3f.x = KF_TrlrBaseX.kalman_process();
        }

        if( !KF_TrlrBaseY.is_filter_ready() )
        {
            KF_TrlrBaseY.gather_initial_measurements( i_Point_3f.y );

            if( KF_TrlrBaseY.is_filter_ready() )
            {
                i_Point_3f.y = KF_TrlrBaseY.kalman_process();
            }
        }
        else
        {
            KF_TrlrBaseY.update_measurements_array( i_Point_3f.y );
            i_Point_3f.y = KF_TrlrBaseY.kalman_process();
        }
    }
/*
* Coupler Ball location approximation based on coupler region and trailer bounding box
*/
Point2i StateProcess::getApproxCoupler( Recti& i_CplrRegBB, Recti& i_TrlrBB, uint16_t i_ImgHeight, uint32_t i_isHitchPresent, uint32_t i_hitchY )
{
    Point2i retPoint;
    // calculate X value from trailer and coupler reg
        Point2i v_CplrRegMidPix;
        Point2i v_TrlrBaseMidPix;
        uint32_t v_topThreshold_U32;
        uint32_t v_botThreshold_U32;
    float32_t v_topThreshFactor_F32 = 0.4f; // start approximation at 60% height from image bottom
    float32_t v_botThreshFactor_F32 = 0.7f; // end approximation and use base pt at 30% height from image bottom
    v_CplrRegMidPix.x = i_CplrRegBB.x + static_cast<int32_t>( 0.5f * static_cast<float32_t>( i_CplrRegBB.width ) );
    v_TrlrBaseMidPix.x = i_TrlrBB.x + static_cast<int32_t>( 0.5f * static_cast<float32_t>( i_TrlrBB.width ) );
    float32_t v_lat_offset_F32 = static_cast<float32_t>( v_CplrRegMidPix.x - v_TrlrBaseMidPix.x ) / ( static_cast<float32_t>( i_TrlrBB.width ) / 2.0f );
    retPoint.x = v_CplrRegMidPix.x + static_cast<int32_t>( v_lat_offset_F32 * ( static_cast<float32_t>( i_CplrRegBB.width ) / 2.0f ) );
    // calculate Y value from set thresholds
    v_CplrRegMidPix.y = i_CplrRegBB.y + static_cast<int32_t>( 0.5f * static_cast<float32_t>( i_CplrRegBB.height ) );
    v_TrlrBaseMidPix.y = i_TrlrBB.y + i_TrlrBB.height;
    uint32_t v_CplrBaseY_U32 = i_CplrRegBB.y + i_CplrRegBB.height;
    // Assign value to v_topThreshold_U32 and v_botThreshold_U32 below using i_ImgHeight
    v_topThreshold_U32 = static_cast<int32_t>( v_topThreshFactor_F32 * static_cast<float32_t>( i_ImgHeight ) );

    if( i_isHitchPresent > 1 )
    {
        v_botThreshold_U32 = i_hitchY;
    }
    else
    {
        v_botThreshold_U32 = static_cast<int32_t>( v_botThreshFactor_F32 * static_cast<float32_t>( i_ImgHeight ) );
    }

    if( v_botThreshold_U32 > v_topThreshold_U32 )
    {
        if( v_CplrBaseY_U32 < v_topThreshold_U32 )
        {
            // keeping Y approximation to mid point of coupler region
            retPoint.y = v_CplrRegMidPix.y;
                /*
                 * 1/3rd height from coupler base
                 * retPoint.y = i_CplrRegBB.y + static_cast<int32_t>(2.0f * static_cast<float32_t>(i_CplrRegBB.height) / 3.0f);
                 */
        }
            else if( ( v_CplrBaseY_U32 >= v_topThreshold_U32 ) && ( v_CplrBaseY_U32 <= v_botThreshold_U32 ) )
        {
            // write logic to move the coupler ball down
            uint32_t v_range_U32 = v_botThreshold_U32 - v_topThreshold_U32;
            float32_t v_cplr_long_off_F32 = static_cast<float32_t>( v_CplrBaseY_U32 - v_topThreshold_U32 ) / static_cast<float32_t>( v_range_U32 );
            retPoint.y = v_CplrRegMidPix.y + static_cast<int32_t>( v_cplr_long_off_F32 * ( static_cast<float32_t>( i_CplrRegBB.height ) / 2.0f ) );
        }
        else
        {
            // coupler region base Y value
            retPoint.y = i_CplrRegBB.y + i_CplrRegBB.height;
        }
    }
    else
    {
        // coupler region base Y value
        retPoint.y = i_CplrRegBB.y + i_CplrRegBB.height;
    }

    return retPoint;
}

/*
* Average Detection Confidence Calculation
*/
    float32_t StateProcess::getAvgDetConfidence( CplrDetStatus_e i_DetStatus, float32_t i_CurrentDetConf, float32_t* i_DetConfBuff_pf32 ) const
{
    float32_t confSum = 0;
    float32_t AvgConf = 0;

    if( m_IndxDetConf < m_DetConfBuffSize )
    {
        if( i_DetStatus == e_Cplr_Detected )
        {
                i_DetConfBuff_pf32[m_IndxDetConf] = i_CurrentDetConf; //PRQA S 3706
        }
        else
        {
                i_DetConfBuff_pf32[m_IndxDetConf] = 0; //PRQA S 3706
        }
    }
    else
    {
        for( uint16_t i = 0; i < m_DetConfBuffSize; i++ )
        {
            i_DetConfBuff_pf32[i] = i_DetConfBuff_pf32[static_cast<int32_t>( i ) + 1];
        }

        if( i_DetStatus == e_Cplr_Detected )
        {
            i_DetConfBuff_pf32[static_cast<int32_t>( m_DetConfBuffSize ) - 1] = i_CurrentDetConf;
        }
        else
        {
            i_DetConfBuff_pf32[static_cast<int32_t>( m_DetConfBuffSize ) - 1] = 0.0f;
        }
    }

        //if( m_IndxDetConf >= ( m_DetConfBuffSize - 1 ) )
    {
        for( uint16_t i = 0; i < m_DetConfBuffSize; i++ )
        {
                confSum = confSum + i_DetConfBuff_pf32[i]; //PRQA S 3706
        }

        AvgConf = confSum / static_cast<float32_t>( m_DetConfBuffSize );
    }

    return AvgConf;
}

float32_t StateProcess::getEuclideanDist( const Point2i& i_Point1_rs32, const Point2i& i_Point2_rs32 )
{
        float32_t v_dx = static_cast<float32_t>( i_Point1_rs32.x ) - static_cast<float32_t>( i_Point2_rs32.x );
        float32_t v_dy = static_cast<float32_t>( i_Point1_rs32.y ) - static_cast<float32_t>( i_Point2_rs32.y );
    // Calculate the Euclidean distance
    return mecl::math::algebra<float32_t>::sqrt_x( v_dx * v_dx + v_dy * v_dy );
}

#if ENABLE_SMOOTH_OP
Point2i StateProcess::getMovingAvg( const Point2i& i_CplrPnt_rs32 )
{
    uint16_t v_SumX_u16 = 0;
    uint16_t v_AvgX_u16 = 0;
    uint16_t v_SumY_u16 = 0;
    uint16_t v_AvgY_u16 = 0;
    Point2i v_OutCplrPnt_s32 = i_CplrPnt_rs32;

    if( m_IndxCplrPnt != m_CplrPntBuffSize )
    {
        m_CplrXBuff[m_IndxCplrPnt] = i_CplrPnt_rs32.x;
        m_CplrYBuff[m_IndxCplrPnt] = i_CplrPnt_rs32.y;
        m_IndxCplrPnt = m_IndxCplrPnt + 1;
    }
    else
    {
        for( uint16_t v_Indx_u16 = 0; v_Indx_u16 < ( m_CplrPntBuffSize - 1 ); v_Indx_u16++ )
        {
            m_CplrXBuff[v_Indx_u16] = m_CplrXBuff[static_cast<int32_t>( v_Indx_u16 ) + 1];
            m_CplrYBuff[v_Indx_u16] = m_CplrYBuff[static_cast<int32_t>( v_Indx_u16 ) + 1];
        }

        m_CplrXBuff[m_CplrPntBuffSize - 1] = i_CplrPnt_rs32.x;
        m_CplrYBuff[m_CplrPntBuffSize - 1] = i_CplrPnt_rs32.y;

        for( uint16_t v_Indx_u16 = 0; v_Indx_u16 < m_CplrPntBuffSize; v_Indx_u16++ )
        {
            v_SumX_u16 = v_SumX_u16 + m_CplrXBuff[v_Indx_u16];
            v_SumY_u16 = v_SumY_u16 + m_CplrYBuff[v_Indx_u16];
        }

        v_AvgX_u16 = v_SumX_u16 / m_CplrPntBuffSize;
        v_AvgY_u16 = v_SumY_u16 / m_CplrPntBuffSize;
        v_OutCplrPnt_s32 = Point2i( v_AvgX_u16, v_AvgY_u16 );
    }

    return v_OutCplrPnt_s32;
}
#endif // ENABLE_SMOOTH_OP

/*
* Set THA detection output
*/
void StateProcess::SetupTHADetOutput( JobTHAAlgoDetOutput_t& i_THAInfo_s )
{
    m_THADetOutput = i_THAInfo_s;
}
void StateProcess::SetupTHADetDebugOutput( JobTHAAlgoDetDebug_t& i_THAInfoDebug_s )
{
    m_THADetDebugOutput = i_THAInfoDebug_s;
}

/*
* Input Get function for THA  detection algorithm
*/
void StateProcess::getTHAInputAlgo( JobTHAInput_t& o_THAInput )const
{
    o_THAInput = m_JobTHAInput;
}

/* get function for THA detection output*/
void StateProcess::getTHADetOutputAlgo( JobTHAAlgoDetOutput_t& o_THADetOutput )const
{
    o_THADetOutput = m_THADetOutput;
}
void StateProcess::getTHADetDebugOutputAlgo( JobTHAAlgoDetDebug_t& o_THADetDebugOutput )const
{
    o_THADetDebugOutput = m_THADetDebugOutput;
}
    void StateProcess::initStateData( StateProcessConfig i_stateProcessCfg, TrailerTrackCfg i_trailerTrackConfig, uint16_t i_ImgWidth_u16, uint16_t i_ImgHeight_u16 )
    {
        m_Cfg = i_stateProcessCfg;
        m_TrailerTrackConfig = i_trailerTrackConfig;
        m_ImgWidth = i_ImgWidth_u16;
        m_ImgHeight = i_ImgHeight_u16;

        if( m_ImgWidth <= 640 )
        {
            m_KFSmoothThresh = 10;
        }
        else if( m_ImgWidth <= 1280 )
        {
            m_KFSmoothThresh = 20;
        }
        else
        {
            m_KFSmoothThresh = 30;
        }

#ifdef OD_ONNX
#ifdef _WIN32
        bool_t v_EnableGPU = m_Cfg.getEnableGPU();

        if( m_pOnnxEnv != NULL )
        {
            delete m_pOnnxEnv;
            m_pOnnxEnv = NULL;
        }

        if( m_pOnnxEnv == NULL )
        {
            m_pOnnxEnv = new Ort::Env( ORT_LOGGING_LEVEL_WARNING, "" );
        }

        /* CD_HD detector */
        if( m_pOnnxDetector != NULL )
        {
            delete m_pOnnxDetector;
            m_pOnnxDetector = NULL;
        }

        if( m_pOnnxDetector == NULL )
        {
            m_pOnnxDetector = new COdOnnx;
            m_pOnnxDetector->Init( m_pOnnxEnv, m_Cfg.getOnnxDet_Weights_file() );
            std::ifstream fileLabelMap( m_Cfg.getOnnxDet_Labelmap() );
            std::string str;

            while( !str.empty() )
            {
                std::getline( fileLabelMap, str );
                m_pOnnxDetector->classList.push_back( str );
            }

            m_pOnnxDetector->classList.shrink_to_fit();
            m_pOnnxDetector->numClasses = m_pOnnxDetector->classList.size();
            m_pOnnxDetector->EnableGPU_b = v_EnableGPU;
            m_pOnnxDetector->m_EnableODONNXCrop = m_Cfg.getEnableODONNXCrop();
        }
        /* Trailer Pose classifier */
        if( m_pOnnxClassifier != NULL )
        {
            delete m_pOnnxClassifier;
            m_pOnnxClassifier = NULL;
        }

        if( m_pOnnxClassifier == NULL )
        {
            m_pOnnxClassifier = new COdOnnx;
            m_pOnnxClassifier->Init( m_pOnnxEnv, m_Cfg.getOnnxPose_Weights_file() );
            std::ifstream fileLabelMap( m_Cfg.getOnnxPose_Labelmap() );
            std::string str;

            while( !str.empty() )
            {
                std::getline( fileLabelMap, str );
                m_pOnnxClassifier->classList.push_back( str );
            }

            m_pOnnxClassifier->classList.shrink_to_fit();
            m_pOnnxClassifier->numClasses = m_pOnnxClassifier->classList.size();
            m_pOnnxClassifier->EnableGPU_b = v_EnableGPU;
            m_pOnnxClassifier->m_EnableODONNXCrop = m_Cfg.getEnableODONNXCrop();
        }

#endif // _WIN32
#endif //OD_ONNX
    }
    void StateProcess::getJobTHAInput( JobTHAInput_t& m_jobTHAInput )
    {
        m_JobTHAInput = m_jobTHAInput;
    }
    void StateProcess::getTHADataProvider( IDataProviderTHA* m_IDataProvide )
    {
        m_IDataProvider = m_IDataProvide;
    }
#ifdef OD_ONNX
#ifdef _WIN32
    void StateProcess::initTHADNNModels()
    {
        m_pOnnxEnv = NULL;
        m_pOnnxDetector = NULL;
        m_pOnnxClassifier = NULL;
    }
#endif //_WIN32
#endif // OD_ONNX
}