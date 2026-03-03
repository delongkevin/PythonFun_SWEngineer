/// --------------------------------------------------------------------------
/// @file THAConfig.h
/// @brief Contains the config paramaters for the THA
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Jignesh Vasoya (jignesh.vasoya@magna.com) [20-05-2022]
/// --------------------------------------------------------------------------

#ifndef THA_CONFIG_H
#define THA_CONFIG_H

#ifdef _WIN32
    #include "Point.h"
#else
    #include "meal/camera/core/inc/CameraPoint.h"
#endif // _WIN32



// --- Enable/Disable Opencv Draw
/*
 * #define CV_DRAW
 */

// --- To enable/disable object tracker
#define OD_TRACKER
#define OD_ONNX
// --- To enable/disable DNN based object detector if not windows platform
#ifdef _WIN32
    #include <string>
    // --- To enable/disable ONNX based object detection
    #define OD_ONNX

    // --- To enable/disable DNN input image write
    /*
    * #define DNN_IN_IMG_WRITE
    */
#endif // _WIN32

#define USR_POINT_WITH_TRLRBB

#define ENABLE_SMOOTH_OP 0 //PRQA S 1025

namespace tha
{
    struct StateProcessConfig
    {
    private:
        // Start: Cal bin parameter list
        /*
        @@ ELEMENT = THAVehSpeedThresh
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = FLOAT
        @@ END
        */
        float32_t THAVehSpeedThresh;
        /*
        @@ ELEMENT = DefaultHitchX_mm
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = SLONG
        @@ END
        */
        int32_t DefaultHitchX_mm;
        /*
        @@ ELEMENT = DefaultHitchY_mm
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = SLONG
        @@ END
        */
        int32_t DefaultHitchY_mm;
        /*
        @@ ELEMENT = DefaultHitchZ_mm
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = SLONG
        @@ END
        */
        int32_t DefaultHitchZ_mm;
        /*
        @@ ELEMENT = DefaultHitchX_pix
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = SLONG
        @@ END
        */
        int32_t DefaultHitchX_pix;
        /*
        @@ ELEMENT = DefaultHitchY_pix
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = SLONG
        @@ END
        */
        int32_t DefaultHitchY_pix;
        /*
        @@ ELEMENT = DefaultTrailerAngle_deg
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = FLOAT
        @@ END
        */
        float32_t DefaultTrailerAngle_deg;
        /*
        @@ ELEMENT = CouplerHeight
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = SLONG
        @@ END
        */
        int32_t CouplerHeight;
        /*
        @@ ELEMENT = UtilizeTrailerTracker
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = UBYTE [0 ... 1]
        @@ END
        */
        bool_t UtilizeTrailerTracker;
        /*
        @@ ELEMENT = CouplerToHitchThresh
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = FLOAT
        @@ END
        */
        float32_t CouplerToHitchThresh;     /* Coupler to Hitch reached threshold (in pixel or meter) */
        /*
        @@ ELEMENT = CouplerNotDetThresh
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = FLOAT
        @@ END
        */
        float32_t CouplerNotDetThresh;     /* Threshold to set coupler not detected if no actual detections */
        /*
        @@ ELEMENT = IsCouplerToHitchThreshInPix
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = UBYTE [0 ... 1]
        @@ END
        */
        bool_t IsCouplerToHitchThreshInPix;
        /*
        @@ ELEMENT = CouplerConfThresh
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = FLOAT
        @@ END
        */
        float32_t CouplerConfThresh;        /*Coupler confidence threshold*/
        /*
        @@ ELEMENT = TrailerAngleThreshDeg
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = FLOAT
        @@ END
        */
        float32_t TrailerAngleThreshDeg;        /* Initial Trailer coupler angle threshold */
        /*
        @@ ELEMENT = EnableKFSmooth
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = UBYTE [0 ... 1]
        @@ END
        */
        bool_t EnableKFSmooth;
        /*
        @@ ELEMENT = EnableODONNXCrop
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = UBYTE [0 ... 1]
        @@ END
        */
        bool_t EnableODONNXCrop;
        // End: Cal bin parameter list

#ifdef OD_ONNX
#ifdef _WIN32
        std::string OnnxDet_Weights_file;
        std::string OnnxDet_Labelmap;
        std::string OnnxDet_Weights_file_Crop;
        std::string OnnxDet_Labelmap_Crop;
        std::string OnnxPose_Weights_file;
        std::string OnnxPose_Labelmap;

        /*
        @@ ELEMENT = EnableGPU
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = UBYTE [0 ... 1]
        @@ END
        */
        bool_t EnableGPU;
#endif
#endif // OD_ONNX


        /*
        @@ ELEMENT = ROIWidth
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = UWORD
        @@ END
        */
        uint16_t ROIWidth;
        /*
        @@ ELEMENT = ROIHeight
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = UWORD
        @@ END
        */
        uint16_t ROIHeight;
        /*
        @@ ELEMENT = DetDNNInputDimW
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = UWORD
        @@ END
        */
        uint16_t DetDNNInputDimW;
        /*
        @@ ELEMENT = DetDNNInputDimH
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = UWORD
        @@ END
        */
        uint16_t DetDNNInputDimH;
        /*
        @@ ELEMENT = DetLatPixThresh
        @@ STRUCTURE = StateProcessConfig
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = UWORD
        @@ END
        */
        uint16_t  DetLatPixThresh;

    public:
        StateProcessConfig()
        {
            THAVehSpeedThresh = 8.0f;
            DefaultHitchX_mm = 5096;
            DefaultHitchY_mm = 0;
            DefaultHitchZ_mm = 477; //477.58
            DefaultHitchX_pix = 319;
            DefaultHitchY_pix = 294;
            DefaultTrailerAngle_deg = 0.0f;
            CouplerHeight = 530;
            UtilizeTrailerTracker = true;
            CouplerToHitchThresh = 11.0f;
            CouplerNotDetThresh = 2.5f;
            IsCouplerToHitchThreshInPix = true;
            CouplerConfThresh = 0.5f;
            TrailerAngleThreshDeg = 60.0f;
            EnableKFSmooth = true;
            EnableODONNXCrop = true;
#ifdef OD_ONNX
#ifdef _WIN32
            EnableGPU = false;
#endif
#endif // OD_ONNX
            ROIWidth = 150;
            ROIHeight = 150;
            DetDNNInputDimW = 640;
            DetDNNInputDimH = 640;
            DetLatPixThresh = 75;
        }
        float32_t getTHAVehSpeedThresh() const
        {
            return THAVehSpeedThresh;
        }
        void setTHAVehSpeedThresh( float32_t i_THAVehSpeedThresh )
        {
            THAVehSpeedThresh = i_THAVehSpeedThresh;
        }
        int32_t getDefaultHitchX_mm() const
        {
            return DefaultHitchX_mm;
        }
        void setDefaultHitchX_mm( int32_t i_DefaultHitchX_mm )
        {
            DefaultHitchX_mm = i_DefaultHitchX_mm;
        }
        int32_t getDefaultHitchY_mm() const
        {
            return DefaultHitchY_mm;
        }
        void setDefaultHitchY_mm( int32_t i_DefaultHitchY_mm )
        {
            DefaultHitchY_mm = i_DefaultHitchY_mm;
        }
        int32_t getDefaultHitchZ_mm() const
        {
            return DefaultHitchZ_mm;
        }
        void setDefaultHitchZ_mm( int32_t i_DefaultHitchZ_mm )
        {
            DefaultHitchZ_mm = i_DefaultHitchZ_mm;
        }
        int32_t getDefaultHitchX_pix() const
        {
            return DefaultHitchX_pix;
        }
        void setDefaultHitchX_pix( int32_t i_DefaultHitchX_pix )
        {
            DefaultHitchX_pix = i_DefaultHitchX_pix;
        }
        int32_t getDefaultHitchY_pix() const
        {
            return DefaultHitchY_pix;
        }
        void setDefaultHitchY_pix( int32_t i_DefaultHitchY_pix )
        {
            DefaultHitchY_pix = i_DefaultHitchY_pix;
        }
        float32_t getDefaultTrailerAngle_deg() const
        {
            return DefaultTrailerAngle_deg;
        }
        void setDefaultTrailerAngle_deg( float32_t i_DefaultTrailerAngle_deg )
        {
            DefaultTrailerAngle_deg = i_DefaultTrailerAngle_deg;
        }
        int32_t getCouplerHeight() const
        {
            return CouplerHeight;
        }
        void setCouplerHeight( int32_t i_CouplerHeight )
        {
            CouplerHeight = i_CouplerHeight;
        }
        bool_t getUtilizeTrailerTracker() const
        {
            return UtilizeTrailerTracker;
        }
        void setUtilizeTrailerTracker( bool_t i_UtilizeTrailerTracker )
        {
            UtilizeTrailerTracker = i_UtilizeTrailerTracker;
        }
        float32_t getCouplerToHitchThresh() const
        {
            return CouplerToHitchThresh;
        }
        void setCouplerToHitchThresh( float32_t i_CouplerToHitchThresh )
        {
            CouplerToHitchThresh = i_CouplerToHitchThresh;
        }
        float32_t getCouplerNotDetThresh() const
        {
            return CouplerNotDetThresh;
        }
        void setCouplerNotDetThresh( float32_t i_CouplerNotDetThresh )
        {
            CouplerNotDetThresh = i_CouplerNotDetThresh;
        }
        bool_t getIsCouplerToHitchThreshInPix() const
        {
            return IsCouplerToHitchThreshInPix;
        }
        void setIsCouplerToHitchThreshInPix( bool_t i_IsCouplerToHitchThreshInPix )
        {
            IsCouplerToHitchThreshInPix = i_IsCouplerToHitchThreshInPix;
        }
        float32_t getCouplerConfThresh() const
        {
            return CouplerConfThresh;
        }
        void setCouplerConfThresh( float32_t i_CouplerConfThresh )
        {
            CouplerConfThresh = i_CouplerConfThresh;
        }
        float32_t getTrailerAngleThreshDeg() const
        {
            return TrailerAngleThreshDeg;
        }
        void setTrailerAngleThreshDeg( float32_t i_TrailerAngleThreshDeg )
        {
            TrailerAngleThreshDeg = i_TrailerAngleThreshDeg;
        }
        bool_t getEnableKFSmooth() const
        {
            return EnableKFSmooth;
        }
        void setEnableKFSmooth( bool_t i_EnableKFSmooth )
        {
            EnableKFSmooth = i_EnableKFSmooth;
        }
        bool_t getEnableODONNXCrop() const
        {
            return EnableODONNXCrop;
        }
        void setEnableODONNXCrop( bool_t i_EnableODONNXCrop )
        {
            EnableODONNXCrop = i_EnableODONNXCrop;
        }
#ifdef OD_ONNX
#ifdef _WIN32
        std::string getOnnxDet_Weights_file() const
        {
            return OnnxDet_Weights_file;
        }
        void setOnnxDet_Weights_file( std::string i_OnnxDet_Weights_file )
        {
            OnnxDet_Weights_file = i_OnnxDet_Weights_file;
        }
        std::string getOnnxDet_Labelmap() const
        {
            return OnnxDet_Labelmap;
        }
        void setOnnxDet_Labelmap( std::string i_OnnxDet_Labelmap )
        {
            OnnxDet_Labelmap = i_OnnxDet_Labelmap;
        }
        std::string getOnnxDet_Weights_file_Crop() const
        {
            return OnnxDet_Weights_file_Crop;
        }
        void setOnnxDet_Weights_file_Crop( std::string i_OnnxDet_Weights_file_Crop )
        {
            OnnxDet_Weights_file_Crop = i_OnnxDet_Weights_file_Crop;
        }
        std::string getOnnxDet_Labelmap_Crop() const
        {
            return OnnxDet_Labelmap_Crop;
        }
        void setOnnxDet_Labelmap_Crop( std::string i_OnnxDet_Labelmap_Crop )
        {
            OnnxDet_Labelmap_Crop = i_OnnxDet_Labelmap_Crop;
        }
        std::string getOnnxPose_Weights_file() const
        {
            return OnnxPose_Weights_file;
        }
        void setOnnxPose_Weights_file( std::string i_OnnxPose_Weights_file )
        {
            OnnxPose_Weights_file = i_OnnxPose_Weights_file;
        }
        std::string getOnnxPose_Labelmap() const
        {
            return OnnxPose_Labelmap;
        }
        void setOnnxPose_Labelmap( std::string i_OnnxPose_Labelmap )
        {
            OnnxPose_Labelmap = i_OnnxPose_Labelmap;
        }
        bool_t getEnableGPU() const
        {
            return EnableGPU;
        }
        void setEnableGPU( bool_t i_EnableGPU )
        {
            EnableGPU = i_EnableGPU;
        }
#endif
#endif // OD_ONNX
        uint16_t getROIWidth() const
        {
            return ROIWidth;
        }
        void setROIWidth( uint16_t i_ROIWidth )
        {
            ROIWidth = i_ROIWidth;
        }
        uint16_t getROIHeight() const
        {
            return ROIHeight;
        }
        void setROIHeight( uint16_t i_ROIHeight )
        {
            ROIHeight = i_ROIHeight;
        }
        uint16_t getDetDNNInputDimW() const
        {
            return DetDNNInputDimW;
        }
        void setDetDNNInputDimW( uint16_t i_DetDNNInputDimW )
        {
            DetDNNInputDimW = i_DetDNNInputDimW;
        }
        uint16_t getDetDNNInputDimH() const
        {
            return DetDNNInputDimH;
        }
        void setDetDNNInputDimH( uint16_t i_DetDNNInputDimH )
        {
            DetDNNInputDimH = i_DetDNNInputDimH;
        }
        uint16_t getDetLatPixThresh() const
        {
            return DetLatPixThresh;
        }
        void setDetLatPixThresh( uint16_t i_DetLatPixThresh )
        {
            DetLatPixThresh = i_DetLatPixThresh;
        }
    };

    struct TrailerTrackCfg
    {
    private:
        /*
        * KCF tracker parameters
        */
        /*
        @@ ELEMENT = TrackBlockWidth
        @@ STRUCTURE = TrailerTrackCfg
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = SLONG
        @@ END
        */
        int32_t TrackBlockWidth;
        /*
        @@ ELEMENT = TrackBlockHeight
        @@ STRUCTURE = TrailerTrackCfg
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = SLONG
        @@ END
        */
        int32_t TrackBlockHeight;
        /*
        @@ ELEMENT = kcfMinPeakValue
        @@ STRUCTURE = TrailerTrackCfg
        @@ A2L_TYPE = PARAMETER WRITEABLE
        @@ DATA_TYPE = FLOAT
        @@ END
        */
        float32_t kcfMinPeakValue;

    public:
        TrailerTrackCfg()
        {
            TrackBlockWidth = 64;
            TrackBlockHeight = 64;
            kcfMinPeakValue = 0.2f;
        }
        int32_t getTrackBlockWidth() const
        {
            return TrackBlockWidth;
        }
        void setTrackBlockWidth( int32_t i_TrackBlockWidth )
        {
            TrackBlockWidth = i_TrackBlockWidth;
        }
        int32_t getTrackBlockHeight() const
        {
            return TrackBlockHeight;
        }
        void setTrackBlockHeight( int32_t i_TrackBlockHeight )
        {
            TrackBlockHeight = i_TrackBlockHeight;
        }
        float32_t getkcfMinPeakValue() const
        {
            return kcfMinPeakValue;
        }
        void setkcfMinPeakValue( float32_t i_kcfMinPeakValue )
        {
            kcfMinPeakValue = i_kcfMinPeakValue;
        }
    };
} // namespace tha
#endif // !THA_CONFIG_H
