
// ----------------------------------------------------------------------------
// --- Written by Sandip Suman Senapati [04-Feb-2025]
// ----------------------------------------------------------------------------
#pragma once
#ifndef TAD_OPTICAL_FLOW_H
#define TAD_OPTICAL_FLOW_H

#ifndef _WIN32
#include "meal/camera/core/inc/CameraPoint.h"
#else
#include "Point.h"
#endif
#include "Image.h"
#include "ImageProcessing.h"
#include "Utility.h"
#include "Pyramid.h"


#define MAX_LAYER 10
#define WIN_SIZE 11
#define SINGLE_CHANNEL 1
#define DOUBLE_CHANNEL 2
#define NO_OF_POINTS_TO_TRACK_PER_LAYER_OF_PYRAMID 1000
#define FRAME_THRESHOLD 10
#define DISTANT_THRESHOLD_INPIXEL 20
#define MAXIMUM_WIDTH 4000








struct  TermCriteria
{
public:
    /**
    Criteria type, can be one of: COUNT, EPS or COUNT + EPS
    */
    //enum Type
    //{
    //    COUNT = 1, //!< the maximum number of iterations or elements to compute
    //    MAX_ITER = COUNT, //!< ditto
    //    EPS = 2 //!< the desired accuracy or change in parameters at which the iterative algorithm stops
    //};

    //! default constructor
    //TermCriteria();
    /**
    @param type The type of termination criteria, one of TermCriteria::Type
    @param maxCount The maximum number of iterations or elements to compute.
    @param epsilon The desired accuracy or change in parameters at which the iterative algorithm stops.
    */
    //TermCriteria( int type, int maxCount, double epsilon );


    int type; //!< the type of termination criteria: COUNT, EPS or COUNT + EPS
    int maxCount; //!< the maximum number of iterations/elements
    double epsilon; //!< the desired accuracy
};





struct ScharrDerivInvoker
{
    ScharrDerivInvoker( image::Image<uint8_t>& _src, image::Image<int16_t>& _dst )
        : src( _src ), dst( _dst )
    { }

    //void operator()(const Range& range) const CV_OVERRIDE;
    void sequenceOperation( const Range& range );

    image::Image<uint8_t>& src;
    image::Image<int16_t>& dst;
};



struct LKTrackerInvoker
{
    LKTrackerInvoker( const image::Image<uint8_t>& _prevImg_App,  const image::Image<int16_t>& _prevDeriv, const image::Image<uint8_t>& _nextImg,
                      const Point2f* _prevPts, Point2f* _nextPts,
                      uint8_t* _status, float* _err,
                      size2i _winSize, TermCriteria _criteria,
                      int _level, int _maxLevel, int _flags, float _minEigThreshold );

    //void operator()(const Range& range) const CV_OVERRIDE;
    void sequenceOperation( const Range& range );

    //cv::Mat* prevImg;
    image::Image<uint8_t> prevImg_App;
    image::Image<uint8_t> nextImg_App;
    image::Image<int16_t> dervI_App;

    //const cv::Mat* nextImg;
    //const cv::Mat* prevDeriv;
    const Point2f* prevPts;
    Point2f* nextPts;
    uint8_t* status;
    float* err;
    size2i winSize;
    TermCriteria criteria;
    int level;
    int maxLevel;
    int flags;
    float minEigThreshold;
};
class OpticalFlow
{
public:
    OpticalFlow();
    ~OpticalFlow();
    void Run( image::Image<uint8_t> _prevImg, image::Image<uint8_t> _nextImg,
              Point2f* _prevPts, Point2f*& _nextPts, uint32_t featureSize,
              uint8_t*& _status, float*& _err );
    template <typename T>
    void mySwap( T& a, T& b );

    bool compareIntegersDescending( int a, int b );
    template <typename T>
    void genericSort( T arr[], int n );
    bool_t Init();
    bool_t Start();
    void Finish();
    void calcScharrDeriv( image::Image<uint8_t>& src, image::Image<int16_t>& dst );
    int buldOpticalFlowPyramid( image::Image<uint8_t> img, image::Image<uint8_t>( &pyramid_app )[MAX_LAYER],
                                size2i winSize, int maxLevel, bool withDerivatives = true,
                                int pyrBorder = APP_BORDER_REFLECT101,
                                int derivBorder = APP_BORDER_CONSTANT,
                                bool tryReuseInputImage = true );

    void lkopticalFlowCalc( image::Image<uint8_t> _prevImg, image::Image<uint8_t> _nextImg,
                            Point2f* _prevPts, Point2f*& _nextPts, uint32_t featureSize,
                            uint8_t*& _status, float*& _err,
                            size2i winSize = { WIN_SIZE, WIN_SIZE }, int maxLevel = 3,
                            int flags = 0, double minEigThreshold = 1e-4 );
    image::Image<uint8_t>  prevPyr_app[MAX_LAYER], nextPyr_app[MAX_LAYER];
private:
    bool_t m_initOK;
    bool_t m_isRunning;
    int32_t m_lastFrameRun;
};
#endif



