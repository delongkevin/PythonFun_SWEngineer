// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [01-Aug-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------
#ifdef _WIN32
#ifndef __I_DEBUGGER__H_
#define __I_DEBUGGER__H_

#include "dbTypes.h"
#include "Image.h"
#ifdef __QNX__
    #include "../inc/FeatureExtraction.h"
    #include "meal/camera/core/inc/CameraPoint.h"
#else
    #include "FeatureExtraction.h"
#endif


///------------------------------------------------------------------------------
/// The debugging library namespace.
///------------------------------------------------------------------------------
namespace db
{
    /**
    * WindowsDebugger class which implements logic for debugging library.
    *
    * Logic for the debugging library is placed in a separate class so that
    * if debugging were to be disabled (e.g. if OpenCV or std libraries were
    * to be removed), then we can modify the library files (add #if's) without
    * actually touching the implementation. We can also easily switch
    * implementations if we ever wanted to do so.
    */
    class BaseDebugger
    {
    public:
        BaseDebugger() {};
        virtual ~BaseDebugger() {};

        void Run( int frameNum = -1 );
        void Reset();

        void SetDebugLevel( int level );
        void SetCategoryLevel( const char* category, int level );

        void EnableWindow( const char* winname );
        void DisableWindow( const char* winname );
        void CreateNewWindow( const char* winname, int width = 0, int height = 0 );
        void CreateView( const char* viewname, int width = 0, int height = 0 );
        void AddViewToWindow( const char* winname, const char* viewname, int row, int col );
        void* GetHandle( const char* winname );

        void Line( const char* winname, Point2i p1, Point2i p2, db::Colour colour, int thickness = 1 );
        void Circle( const char* winname, db::Point centre, int radius, db::Colour colour, int thickness );
        void Rect( const char* winname, _roi::ROI roi, db::Colour colour, int thickness = 1 );

        void Plot( const char* winname, double val, db::Colour colour = db::Colour( 0, 0, 0 ), int shift = 0 );
        void Plot( const char* winname, double x, double y, db::Colour colour = db::Colour( 0, 0, 0 ), int shift = 0 );
        template<typename T>
        void Plot( const char* winname, T* x, T* y, int numPoints, db::Colour colour = db::Colour( 0, 0, 0 ), int shift = 0 );
        void ClearPlot( const char* winname );
        void ResetPlot( const char* winname );
        void SetPlotXLim( const char* winname, double low, double high );
        void SetPlotYLim( const char* winname, double low, double high );
        void SetPlotTimeFrame( const char* winname, int timeframe );
        void SetPlotType( const char* winname, db::ePlotType type, Colour colour = Colour( -1, -1, -1 ) );
        void SetPlotLineThickness( const char* winname, int thickness, db::Colour colour );
        void SetPlotDotRadius( const char* winname, int radius, db::Colour colour );

        template<typename T>
        void Imshow( const char* winname, image::Image<T>& image, db::imshow_options option = ImShow_Default, T maxVal = 255, T minVal = 0 );
        template<typename T>
        void Imshow_log( const char* winname, image::Image<T>& image, T maxVal = 255, T minVal = 0 );
        void Imshow_edges( const char* winname, image::Image<uint8_t>& edges );
        template<typename T, typename U>
        void Imshow_segmented( const char* winname, image::Image<T>& image, image::Image<U>& thresh_low, image::Image<U>& thresh_high );
        template<typename T>
        void Imshow_segmented( const char* winname, image::Image<T>& image, T thresh_low, T thresh_high );
        template<typename T>
        void Imshow_threshold( const char* winname, image::Image<T>& image, T thresh, T maxVal = 255, T minVal = 0 );
        template<typename T>
        void Imshow_range( const char* winname, image::Image<T>& image, T maxVal = 255, T minVal = 0 );
        template<typename T>
        void Imshow_threshold_and_range( const char* winname, image::Image<T>& image, T thresh, T maxVal = 255, T minVal = 0 );
        template<typename T>
        void Imshow_overlap( const char* winname, image::Image<T>& image1, image::Image<T>& image2 );
        template<typename T>
        void Imshow_templateOverlap( const char* winname, image::Image<T>& template1, image::Image<T>& template2, float32_t tmFactor );

        void DebugMemoryPool( int frame );
        void ShowAngleDetection( const image::Image<uint8_t>& inputImage, image::Image<uint8_t>& trailerTemplate, image::Image<uint8_t>& trailerTemplate2, image::Image<uint8_t>& matchedTemplate, float curAngle, int angleXPos, int templateYOffset, float tmFactor );
        void ShowMirrorOverlap( const image::Image<uint8_t>& templateImage );
        void ShowFeatures( const char* category, const image::Image<TAD2::FeatureExtraction::Feature>& featureImage );
    };
}

#include "BaseDebugger.hpp"

#endif // !__I_DEBUGGER__H_
#endif // _WIN32