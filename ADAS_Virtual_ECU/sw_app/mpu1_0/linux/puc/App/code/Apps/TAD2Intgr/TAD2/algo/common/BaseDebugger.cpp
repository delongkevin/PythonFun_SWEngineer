// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [01-Aug-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------
#ifdef _WIN32
#include "stdafx.h"

#include "BaseDebugger.h"

void db::BaseDebugger::Run( int frameNum )
{
    frameNum;
}

void db::BaseDebugger::Reset()
{
}

void db::BaseDebugger::SetDebugLevel( int level )
{
    level;
}

void db::BaseDebugger::SetCategoryLevel( const char* category, int level )
{
    category;
    level;
}

void db::BaseDebugger::EnableWindow( const char* winname )
{
    winname;
}

void db::BaseDebugger::DisableWindow( const char* winname )
{
    winname;
}

void db::BaseDebugger::CreateNewWindow( const char* winname, int width, int height )
{
    winname;
    width;
    height;
}

void db::BaseDebugger::CreateView( const char* viewname, int width, int height )
{
    viewname;
    width;
    height;
}

void db::BaseDebugger::AddViewToWindow( const char* winname, const char* viewname, int row, int col )
{
    winname;
    viewname;
    row;
    col;
}

void* db::BaseDebugger::GetHandle( const char* winname )
{
    winname;
    return nullptr;
}

void db::BaseDebugger::Line( const char* winname, Point2i p1, Point2i p2, db::Colour colour, int thickness )
{
    winname;
    p1;
    p2;
    colour;
    thickness;
}

void db::BaseDebugger::Circle( const char* winname, db::Point centre, int radius, db::Colour colour, int thickness )
{
    winname;
    centre;
    radius;
    colour;
    thickness;
}

void db::BaseDebugger::Rect( const char* winname, _roi::ROI roi, db::Colour colour, int thickness )
{
    winname;
    roi;
    colour;
    thickness;
}

void db::BaseDebugger::Plot( const char* winname, double val, db::Colour colour, int shift )
{
    winname;
    val;
    colour;
    shift;
}

void db::BaseDebugger::Plot( const char* winname, double x, double y, db::Colour colour, int shift )
{
    winname;
    x;
    y;
    colour;
    shift;
}

void db::BaseDebugger::ClearPlot( const char* winname )
{
    winname;
}

void db::BaseDebugger::ResetPlot( const char* winname )
{
    winname;
}

void db::BaseDebugger::SetPlotXLim( const char* winname, double low, double high )
{
    winname;
    low;
    high;
}

void db::BaseDebugger::SetPlotYLim( const char* winname, double low, double high )
{
    winname;
    low;
    high;
}

void db::BaseDebugger::SetPlotTimeFrame( const char* winname, int timeframe )
{
    winname;
    timeframe;
}

void db::BaseDebugger::SetPlotType( const char* winname, db::ePlotType type, Colour colour )
{
    winname;
    colour;
    type;
}

void db::BaseDebugger::SetPlotLineThickness( const char* winname, int thickness, db::Colour colour )
{
    winname;
    colour;
    thickness;
}

void db::BaseDebugger::SetPlotDotRadius( const char* winname, int radius, db::Colour colour )
{
    winname;
    colour;
    radius;
}

void db::BaseDebugger::Imshow_edges( const char* winname, image::Image<uint8_t>& edges )
{
    winname;
    edges;
}

void db::BaseDebugger::DebugMemoryPool( int frame )
{
    frame;
}

void db::BaseDebugger::ShowAngleDetection( const image::Image<uint8_t>& inputImage, image::Image<uint8_t>& trailerTemplate, image::Image<uint8_t>& trailerTemplate2, image::Image<uint8_t>& matchedTemplate, float curAngle, int angleXPos, int templateYOffset, float tmFactor )
{
    inputImage;
    trailerTemplate;
    trailerTemplate2;
    matchedTemplate;
    curAngle;
    angleXPos;
    templateYOffset;
    tmFactor;
}

void db::BaseDebugger::ShowMirrorOverlap( const image::Image<uint8_t>& templateImage )
{
    templateImage;
}

void db::BaseDebugger::ShowFeatures( const char* category, const image::Image<TAD2::FeatureExtraction::Feature>& featureImage )
{
    category;
    featureImage;
}
#endif