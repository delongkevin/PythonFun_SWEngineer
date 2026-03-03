/// --------------------------------------------------------------------------
/// @file StateProcess.h
/// @brief Contains THA detection state machine, Detection calling functions
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Jignesh Vasoya (jignesh.vasoya@magna.com)
/// --------------------------------------------------------------------------

#ifndef STATE_PROCESS_H
#define STATE_PROCESS_H

#ifdef _WIN32
    #include "stdafx.h"
    #include <MECL/mecl.h>
#else
    #include "mecl/mecl.h"
#endif // _WIN32
#include "../common/THAConfig.h"
#include "../common/THAParams.h"
#include "JobTHADetOutput.h"
#include "../../IDataProviderTHA.h"
#include "KalmanFilter1D.h"

extern "C" {
#include "../../modules/include/THA_TI.h"
}

#ifdef OD_ONNX
    #ifdef _WIN32
        #include "OdOnnx.h"
    #endif
#endif // OD_ONNX

#ifdef OD_TRACKER
    #include "ObjectTracker.h"
#endif // OD_TRACKER

namespace tha
{
class StateProcess
{

private:
    mecl::core::ArrayList<ODInfo, MAX_DETECTIONS> m_ObjList;

    tha::IDataProviderTHA* m_IDataProvider;

    /*
    * Coupler tracker para
    */
#ifdef OD_TRACKER
    bool_t m_ObjTrackerStarted = false;
    float32_t m_TrackerResizeFactorW = 1.0f;
    float32_t m_TrackerResizeFactorH = 1.0f;
        uint8_t m_TrkdObjInfo = 0; // 3: Coupler Ball , 2: Coupler region, 1: User selected point/Trailer
#endif // OD_TRACKER
    /*
    * User point selection parameters
    */
    bool_t m_StatusCplrZone_b;
    /*
    * Current detection object BB and status
    */
    Recti m_ValidTrlrRectCurr;
    Recti m_ValidCplrRegRectCurr;
    Recti m_ValidCplrBallRectCurr;
    bool_t m_ValidTrlrRectCurr_b;
    bool_t m_ValidCplrRegRectCurr_b;
    bool_t m_ValidCplrBallRectCurr_b;
    /*
    * Detection parameter
    */
    CplrDetStatus_e m_CplrBallDetStsPrev_e = e_Cplr_Not_Valid;
    CplrDetStatus_e m_CplrRegDetStsPrev_e = e_Cplr_Not_Valid;
    TrlrDetStatus_e m_TrlrDetStsPrev_e = e_Trlr_Not_Valid;
    HitchDetStatus_e m_HitchDetStsPrev_e = e_Hitch_Not_Valid;

    Point2i m_HitchPixPrev;
    Point2i m_CplrPixPrev;
    Point2i m_CplrRegPixPrev;
    Point2i m_TrlrPixPrev;
    Point2i m_OpPixPrev;
        Point3f m_TrlrBaseLocPrev;
    bool_t m_InitCplrAngFound_b;
    bool_t m_InitHitchFound_b;
    bool_t m_CplrToHitchReachStatus_b = false;
    float32_t m_InitCplrAng;
    Recti m_HitchBBPrev = Recti( 0, 0, 0, 0 );
    // Initial hitch to coupler euclidean distance
    uint16_t m_InitCplrHtichEucDist = 0;
    // EucDist Thresholds for all classess
    uint16_t m_EucDistThrshCplrBall = 0;
    uint16_t m_EucDistThrshCplrReg = 0;
    uint16_t m_EucDistThrshTrlr = 0;
#if ENABLE_SMOOTH_OP
    static const uint16_t m_CplrPntBuffSize = 3;
    uint32_t m_CplrXBuff[m_CplrPntBuffSize] = { 0 };
    uint32_t m_CplrYBuff[m_CplrPntBuffSize] = { 0 };
    uint16_t m_IndxCplrPnt = 0;
#endif

    /*
    * Kalman Filter Parameters
    */
#if ENABLE_SMOOTH_OP
        Kalman_Filter_1D KF_Ang { 5.0f, 10.0f, 5.0f };
#endif
        Kalman_Filter_1D KF_HitchX { 0.1f, 1.0f, 1.0f };
        Kalman_Filter_1D KF_HitchW{ 0.1f, 1.0f, 1.0f };
        Kalman_Filter_1D KF_HitchH{ 0.1f, 1.0f, 1.0f };
        Kalman_Filter_1D KF_HitchY{ 0.1f, 1.0f, 1.0f };
        Kalman_Filter_1D KF_TrlrBaseX{ 0.1f, 0.1f, 1.0f };
        Kalman_Filter_1D KF_TrlrBaseY{ 0.1f, 0.1f, 1.0f };
    int32_t m_KFSmoothThresh = 0;
    static const uint16_t m_DetConfBuffSize = 5;
    float32_t m_CplrBallDetConfBuffer[m_DetConfBuffSize] = { 0.0f };
    float32_t m_CplrRegDetConfBuffer[m_DetConfBuffSize] = { 0.0f };
    float32_t m_TrlrDetConfBuffer[m_DetConfBuffSize] = { 0.0f };
    uint16_t  m_IndxDetConf = 0;
#ifdef _WIN32
    /*
    Dynamic crop display debug parameters
    */
    int16_t m_DynCrpStartX;
    int16_t m_DynCrpStartY;
#endif // _WIN32    
    /*
    * Job Input parameter
    */
    JobTHAInput_t m_JobTHAInput;

    /*
    * Job Output parameter
    */
    JobTHAAlgoDetOutput_t m_THADetOutput;
    JobTHAAlgoDetDebug_t m_THADetDebugOutput;
#ifdef OD_ONNX
    /*
    * ONNX based detection objects for coupler ball, Hitch ball
    */
#ifdef _WIN32
    class COdOnnx* m_pOnnxDetector;
    class COdOnnx* m_pOnnxClassifier;
    /* onnxruntime environment */
    Ort::Env* m_pOnnxEnv;
#endif
#endif // OD_ONNX

    /*
    * Detected object list and its label
    */
    //mecl::core::ArrayList<ODInfo, MAX_DETECTIONS> m_ObjList; //Made this variable private to resolve pushback issue

    //--- Algo variables ---
    uint32_t m_WaitFrameCountAngle;
    uint32_t m_WaitFrameCountHitchBB;
    uint32_t m_WaitFrameCount;

    //--- image size
    uint16_t m_ImgWidth;//Use m_Cfg.CamResoW and remove dependency of this variable
    uint16_t m_ImgHeight;//Use m_Cfg.CamResoH and remove dependency of this variable
    //--- Configuration
    StateProcessConfig m_Cfg;
    TrailerTrackCfg m_TrailerTrackConfig;
public:
        /*
        * Coupler tracker para
        */
#ifdef OD_TRACKER
        ObjectTracker m_CouplerTrackerObj; //PRQA S 2100
#endif // OD_TRACKER

    //--- State process main functions
    StateProcess();
    ~StateProcess();
    void Init();
    void Reset();     //PRQA S 2504

    //--- Algo processing functions
#ifdef _WIN32
    void ProcessTHASM();
#else
    void ProcessTHASM( AppObj_CD_HD* TIObj_s_CD_HD, AppObj_TrailerPose* TIObj_s_TrailerPose );
#endif
    //--- ONNX detection functions
#ifdef OD_ONNX
#ifdef _WIN32
    bool_t Onnx_CD_HD_Run();
    bool_t Onnx_TrailerPose_Run( const uint8_t* i_InputImg,
                                 float32_t& o_trailerAngDeg,
                                 Recti& i_rectTrailer,
                                 uint16_t i_ImgWidth,
                                 uint16_t i_ImgHeight );
#else
    bool_t Onnx_CD_HD_Run( AppObj_CD_HD* TIObj_s_CD_HD );
    bool_t Onnx_TrailerPose_Run( AppObj_TrailerPose* TIObj_s_TrailerPose, \
                                 const uint8_t* i_InputImg, \
                                 float32_t& o_trailerAngDeg, \
                                 Recti& i_rectTrailer, \
                                 uint16_t i_ImgWidth, \
                                 uint16_t i_ImgHeight );
#endif // _WIN32
#endif // OD_ONNX

    static bool ValidateAndUpdateBB( Recti& io_BB,
                                     int32_t i_imgW,
                                     int32_t i_imgH );

    static bool_t IsCouplerInsideTrailer( Recti& i_TrlrBB,
                                          Point2i& i_CplrPix );

    static bool_t IsPointInROI( Recti& i_RectBB, Point2i& i_Pix );
    void TransformHMICplrPnt( Point2i& b_UsrSelCplrPnt_rs32,
                              uint16_t& i_HMICplrX_ru16,
                                  uint16_t& i_HMICplrY_ru16 ) const;
    static bool_t IsDetectedPointInsideROI( Point2i& i_DetCplrPix,
                                            Point2i& i_SelectedCplrPix,
                                            uint16_t i_ROIWidth,
                                            uint16_t i_ROIHeight );

    bool_t IsObjectFound( mecl::core::ArrayList<ODInfo, MAX_DETECTIONS>& i_ODList,
                          ODType i_ObjType,
                          ODInfo& o_ObjInfo );

    void ConvertPointImage2WCS( Point2i i_Point2D,
                                Point3f& o_Dist3D,
                                Point2i& o_Point2DGround,
                                float32_t i_Point2DHeight = 0.0f );
    void Image2WorldCS( Point2i i_Point2D, Point3f& o_Dist3D, float32_t i_Point2DHeight, uint32_t width, uint32_t Height );
    
    void convert_pixel_to_raw_coordinates(int32_t pixel_x, int32_t pixel_y, int32_t width, int32_t height,
                                      float32_t *x1, float32_t *y1);
    void ConvertWCS2PointImage( Point3f& i_Dist3Dm, Point2i& o_Point2D );
        static float32_t EstimateTrailerAngle( Recti& i_rectTrailer, Point2i& i_CplrPix );
        static float32_t ConventionalTrailerPose_Run( Recti& i_Rect, Point2i& i_PointPix, uint8_t i_LatOffPerc, uint8_t i_CplrBallOffset );
        static float32_t getEuclideanDist( const Point2i& i_Point1_rs32, const Point2i& i_Point2_rs32 );
#if ENABLE_SMOOTH_OP
    Point2i getMovingAvg( const Point2i& i_CplrPnt_rs32 );
    float32_t KFSmooth1D( float32_t i_Value );
#endif // ENABLE_SMOOTH_OP

#ifdef OD_TRACKER
    bool_t SetupObjectTracker( Point2i i_Pix_Detected );
    bool_t ResetObjectTracker( Point2i i_Pix_Detected );
    bool_t GetObjectTrackerConf( float32_t& i_TrkConf_rf32 );
    void GetObjectTrackedPoint( int32_t& i_TrkdPntX_s32, int32_t& i_TrkdPntY_s32 ) const;
#endif // OD_TRACKER

    Recti KFSmoothHitchBB( Recti i_BB );
        void KFSmoothTrlrBasePoint( Point3f& i_Point_3f );
        float32_t getAvgDetConfidence( CplrDetStatus_e i_DetStatus, float32_t i_CurrentDetConf, float32_t* i_DetConfBuff_pf32 ) const;

    //--- Set detection outputs
    void SetupTHADetOutput( JobTHAAlgoDetOutput_t& i_THAInfo_s );
    void SetupTHADetDebugOutput( JobTHAAlgoDetDebug_t& i_THAInfoDebug_s );

    //--- Pass data from algo to Ijob
    void getTHAInputAlgo( JobTHAInput_t& o_THAInput )const;

    static Point2i getApproxCoupler( Recti& i_CplrRegBB, Recti& i_TrlrBB, uint16_t i_ImgHeight, uint32_t i_isHitchPresent, uint32_t i_hitchY );
    void getTHADetOutputAlgo( JobTHAAlgoDetOutput_t& o_THADetOutput )const;
    void getTHADetDebugOutputAlgo( JobTHAAlgoDetDebug_t& o_THADetDebugOutput )const;

        //--- Get config data
        void initStateData( StateProcessConfig i_stateProcessCfg, TrailerTrackCfg i_trailerTrackConfig, uint16_t i_ImgWidth_u16, uint16_t i_ImgHeight_u16 );
        //--- Get job tha input
        void getJobTHAInput( JobTHAInput_t& m_jobTHAInput );
        //--- Get data provider input
        void getTHADataProvider( IDataProviderTHA* m_IDataProvide );
        //--- Init DNN Models
#ifdef OD_ONNX
        void initTHADNNModels();
#endif // OD_ONNX
    };
} // namespace tha
#endif // !STATE_PROCESS_H