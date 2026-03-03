// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [17-Jan-2019]
// --- Last Modified by Joshua Teichroeb [17-Jan-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------


#ifndef __PLOTTER__H_
#define __PLOTTER__H_

#include "Defines.h"
#include "dbTypes.h"
#ifdef __QNX__
    #include "mecl/mecl.h"
    #include "meal/camera/core/inc/CameraPoint.h"
#else
    #include "MECL\mecl.h"
    #include "Point.h"
#endif

#ifdef WINDOWS_DEBUGGING

#include <list>
#ifdef ENABLE_OPENCV
    #include "highgui/highgui.hpp"
    #include "imgcodecs.hpp"
    #include "imgproc/imgproc.hpp"
#endif // !ENABLE_OPENCV

///------------------------------------------------------------------------------
/// The debugging library namespace.
///------------------------------------------------------------------------------
namespace db
{
    /**
    * Graph plotting class used in debugging library.
    */
    class Plotter
    {
    public:
        typedef float32_t cast_type;
        typedef Point2f PlotPoint;

        struct Graph : public std::list<PlotPoint>
        {
            Colour colour;
            ePlotType type;
            int thickness;
            Graph( Colour colour, ePlotType type = PlotLines, int thickness = 1 ) :
                colour( colour ),
                type( type ),
                thickness( thickness )
            {};
        };

        explicit Plotter( std::string winname, cv::Mat& _window );

        void plot( double val, Colour colour, int shift = 0 );
        void plot( double x, double y, Colour colour, int shift = 0 );
        template<typename T>
        void plot( T* x, T* y, int numPoints, Colour colour, int shift = 0 );
        void clear();
        void reset();
        void update( );
        void rollback();

        void setXLim( double low, double high );
        void setYLim( double low, double high );
        void setTimeFrame( int numFrames );
        void setPlotType( ePlotType type, Colour colour = Colour( -1, -1, -1 ) );
        void setLineThickness( int thickness, Colour colour = Colour( -1, -1, -1 ) );
        void setDotRadius( int radius, Colour colour = Colour( -1, -1, -1 ) );

    private:
        std::list<Graph> graphs;
        std::string winname;
#ifdef ENABLE_OPENCV
        cv::Mat& window;
#endif // !ENABLE_OPENCV
        int width = 640;
        int height = 400;
        double x_res;
        double y_res;
        double minX = 0.0;
        double minY = 0.0;
        double maxX = 0.0;
        double maxY = 0.0;
        double border1X = 0.0;
        double border2X = 0.0;
        double border1Y = 1.0;
        double border2Y = 1.0;
        double gapRatio = 0.2;
        //bool connectDots = false;
        bool showAxes = true;
        bool firstInput = true;
        bool xLimSet = false;
        bool yLimSet = false;
        int axisThickness = 1;
#ifdef ENABLE_OPENCV
        cv::Scalar backgroundColour = cv::Scalar( 255, 255, 255 );
        cv::Scalar axisColour = cv::Scalar( 0, 0, 0 );
        cv::Scalar textColour = cv::Scalar( 0, 0, 0 );
#endif // !ENABLE_OPENCV
        bool isUpToDate = false;
        int curFrameNum = 0;
        int timeFrame = 100;
        int numLines = 5;

#ifdef ENABLE_OPENCV
        cv::Point GetPixelLocation( PlotPoint p );
        cv::Point GetPixelLocation( double x, double y );
#endif // !ENABLE_OPENCV
        double Shift( double val, int shift );
        void UpdateMinMax( double x, double y );
        //void UpdatePrecision( int shift );
        void DrawGrid();
        void DrawGraph( Graph& graph );
        Graph& GetGraph( Colour );
#ifdef ENABLE_OPENCV
        cv::Scalar cvColour( db::Colour colour );
#endif // !ENABLE_OPENCV
        double round( double val, int decimal_places, bool trunc = false );
        int digits( double val );
        double getInc( double gap, double& precision );

    };

    ///------------------------------------------------------------------------------
    /// Plotter template function definitions.
    ///------------------------------------------------------------------------------

    template<typename T>
    void Plotter::plot( T* x, T* y, int numPoints, Colour colour, int shift )
    {
        Graph& graph = GetGraph( colour );

        for( int i = 0; i < numPoints; i++ )
        {
            double xd = Shift( ( double )x[i], shift );
            double yd = Shift( ( double )y[i], shift );
            graph.push_back( PlotPoint( ( cast_type )xd, ( cast_type )yd ) );
            UpdateMinMax( xd, yd );
        }

        isUpToDate = false;
    }
}

#endif // !WINDOWS_DEBUGGING

#endif // !__PLOTTER__H_
