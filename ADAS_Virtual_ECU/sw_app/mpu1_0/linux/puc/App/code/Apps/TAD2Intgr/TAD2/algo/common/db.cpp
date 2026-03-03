// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [17-Jan-2019]
// --- Last Modified by Joshua Teichroeb [02-Aug-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------
#ifndef __QNX__
#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "Defines.h"
#include "db.h"

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
    #define min(a,b) ((a) < (b) ? (a) : (b))
#endif

using namespace db;

#ifdef WINDOWS_DEBUGGING
    #include "WindowsDebugger.h"
    db::WindowsDebugger g__DebuggerObj;
    db::WindowsDebugger* g__pDebugger = NULL;
#else
    #include "BaseDebugger.h"
    db::BaseDebugger g__DebuggerObj;
    db::BaseDebugger* g__pDebugger = NULL;
#endif

///------------------------------------------------------------------------------
/// Logic for the debugging library is placed in a separate class so that
/// if certain libraries were to be disabled (e.g. if OpenCV or std libraries
/// were to be removed), then we can simply switch to an implementation which
/// does not use these libraries.
///
/// There is no interface for this implementation class due to the fact that some
/// of the functions are template functions (virtual template functions are not
/// yet supported in C++), however, this library serves as a reference and any
/// implementation of the "debugger" class should implement all the functions in
/// this library, with the exception of "init()", "uninit()", and "isRunning()".
/// ------------------------------------------------------------------------------

void db::init()
{
    if( g__pDebugger == NULL )
    {
        g__pDebugger = &g__DebuggerObj;
    }
}

void db::uninit()
{
    if( g__pDebugger )
    {
        g__pDebugger = NULL;
    }
}

bool db::isRunning()
{
#ifdef ENABLE_DEBUGGING
    return true;
#else
    return false;
#endif
}

void db::run( int frameNum )
{
    if( isRunning() )
    {
        if( frameNum < 0 )
        {
            g__pDebugger->Run();
        }
        else
        {
            g__pDebugger->Run( frameNum );
        }
    }
}

void db::reset()
{
    if( isRunning() )
    {
        g__pDebugger->Reset();
    }
}

void db::setDebugLevel( int level )
{
    if( isRunning() )
    {
        g__pDebugger->SetDebugLevel( level );
    }
}

void db::enableWindow( const char* winname )
{
    if( isRunning() )
    {
        g__pDebugger->EnableWindow( winname );
    }
}

void db::disableWindow( const char* winname )
{
    if( isRunning() )
    {
        g__pDebugger->DisableWindow( winname );
    }
}

void db::setCategoryLevel( const char* category, int level )
{
    if( isRunning() )
    {
        g__pDebugger->SetCategoryLevel( category, level );
    }
}

void db::createWindow( const char* winname, int width, int height )
{
    if( isRunning() )
    {
        g__pDebugger->CreateNewWindow( winname, width, height );
    }
}

void db::createView( const char* viewname, int width, int height )
{
    if( isRunning() )
    {
        g__pDebugger->CreateView( viewname, width, height );
    }
}

void db::addViewToWindow( const char* winname, const char* viewname, int row, int col )
{
    if( isRunning() )
    {
        g__pDebugger->AddViewToWindow( winname, viewname, row, col );
    }
}

void* db::getHandle( const char* winname )
{
    if( isRunning() )
    {
        return g__pDebugger->GetHandle( winname );
    }
    else
    {
        return nullptr;
    }
}

void db::plot( const char* winname, double val, Colour colour, int shift )
{
    if( isRunning() )
    {
        g__pDebugger->Plot( winname,  val,  colour,  shift );
    }
}

void db::plot( const char* winname, double x, double y, Colour colour, int shift )
{
    if( isRunning() )
    {
        g__pDebugger->Plot( winname, x, y,  colour, shift );
    }
}

void db::clearPlot( const char* winname )
{
    if( isRunning() )
    {
        g__pDebugger->ClearPlot( winname );
    }
}

void db::resetPlot( const char* winname )
{
    if( isRunning() )
    {
        g__pDebugger->ResetPlot( winname );
    }
}

void db::setPlotXLim( const char* winname, double low, double high )
{
    if( isRunning() )
    {
        g__pDebugger->SetPlotXLim( winname, low, high );
    }
}

void db::setPlotYLim( const char* winname, double low, double high )
{
    if( isRunning() )
    {
        g__pDebugger->SetPlotYLim( winname, low, high );
    }
}

void db::setPlotTimeFrame( const char* winname, int timeframe )
{
    if( isRunning() )
    {
        g__pDebugger->SetPlotTimeFrame( winname, timeframe );
    }
}

void db::setPlotType( const char* winname, db::ePlotType type, Colour colour )
{
    if( isRunning() )
    {
        g__pDebugger->SetPlotType( winname, type, colour );
    }
}

void db::setPlotLineThickness( const char* winname, int thickness, Colour colour )
{
    if( isRunning() )
    {
        g__pDebugger->SetPlotLineThickness( winname, thickness, colour );
    }
}

void db::setPlotDotRadius( const char* winname, int radius, Colour colour )
{
    if( isRunning() )
    {
        g__pDebugger->SetPlotDotRadius( winname, radius, colour );
    }
}

void db::line( const char* winname, Point2i p1, Point2i p2, db::Colour colour, int thickness )
{
    if( isRunning() )
    {
        g__pDebugger->Line( winname,  p1,  p2,  colour,  thickness );
    }
}

void db::circle( const char* winname, db::Point centre, int radius, db::Colour colour, int thickness )
{
    if( isRunning() )
    {
        g__pDebugger->Circle( winname, centre, radius, colour, thickness );
    }
}

void db::rect( const char* winname, _roi::ROI i_roi, db::Colour colour, int thickness )
{
    if( isRunning() )
    {
        g__pDebugger->Rect( winname, i_roi, colour, thickness );
    }
}

void db::debugMemoryPool( int frame )
{
    if( isRunning() )
    {
        g__pDebugger->DebugMemoryPool( frame );
    }
}

void db::showAngleDetection( const image::Image<uint8_t> inputImage, image::Image<uint8_t> trailerTemplate, image::Image<uint8_t> trailerTemplate2, image::Image<uint8_t> matchedTemplate, float curAngle, int angleXPos, int templateYOffset, float tmFactor )
{
    if( isRunning() )
    {
        g__pDebugger->ShowAngleDetection( inputImage, trailerTemplate, trailerTemplate2, matchedTemplate, curAngle, angleXPos, templateYOffset, tmFactor );
    }
}

void db::showMirrorOverlap( const image::Image<uint8_t> templateImage )
{
    if( isRunning() )
    {
        g__pDebugger->ShowMirrorOverlap( templateImage );
    }
}

void db::showFeatures( const char* category, const image::Image<TAD2::FeatureExtraction::Feature>& featureImage )
{
    if( isRunning() )
    {
        g__pDebugger->ShowFeatures( category, featureImage );
    }
}
#endif // _WINDOWS_
