// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [17-Jan-2019]
// --- Last Modified by Joshua Teichroeb [17-Jan-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------


#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "Plotter.h"

#ifdef WINDOWS_DEBUGGING

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
    #define min(a,b) ((a) < (b) ? (a) : (b))
#endif

///------------------------------------------------------------------------------
/// Plotter function definitions.
///------------------------------------------------------------------------------

db::Plotter::Plotter( std::string winname, cv::Mat& _window ) :
    winname( winname ),
    window( _window )
{
}

void db::Plotter::plot( double val, Colour colour, int shift )
{
    double vald = Shift( val, shift );
    UpdateMinMax( curFrameNum, vald );
    minX = curFrameNum - timeFrame;
    //
    Graph& graph = GetGraph( colour );
    graph.push_back( PlotPoint( ( cast_type )curFrameNum, ( cast_type )vald ) );
    //
    PlotPoint first = graph.front();

    while( ( graph.size() > 1 ) && ( first.x < ( curFrameNum - timeFrame ) ) )
    {
        graph.pop_front();
        first = graph.front();
    }

    curFrameNum++;
    isUpToDate = false;
}

void db::Plotter::plot( double x, double y, Colour colour, int shift )
{
    double xd = Shift( x, shift );
    double yd = Shift( y, shift );
    Graph& graph = GetGraph( colour );
    graph.push_back( PlotPoint( ( cast_type )xd, ( cast_type )yd ) );
    UpdateMinMax( xd, yd );
    isUpToDate = false;
}

void db::Plotter::clear()
{
    graphs.clear();
    isUpToDate = false;
}

void db::Plotter::reset()
{
    clear();
    minX = 0.0;
    minY = 0.0;
    maxX = 0.0;
    maxY = 0.0;
    border1X = 0.0;
    border2X = 0.0;
    border1Y = 1.0;
    border2Y = 1.0;
}

void db::Plotter::update( )
{
    if( isUpToDate )
    {
        return;
    }

    isUpToDate = true;

    if( window.data == NULL )
    {
        return;
        //window = cv::Mat( height, width, CV_8UC3 );
    }

    // --- Set borders and resolution
    if( !xLimSet )
    {
        if( graphs.size() == 0 )
        {
            border1X = 0.0;
            border2X = 1.0;
        }
        else if( maxX == minX )
        {
            border1X = minX - 1.0;
            border2X = maxX + 1.0;
        }
        else
        {
            border1X = minX - ( maxX - minX ) * gapRatio;
            border2X = maxX + ( maxX - minX ) * gapRatio;
        }
    }

    if( !yLimSet )
    {
        if( graphs.size() == 0 )
        {
            border1Y = 0.0;
            border2Y = 1.0;
        }
        else if( maxY == minY )
        {
            border1Y = minY - 1.0;
            border2Y = maxY + 1.0;
        }
        else
        {
            border1Y = minY - ( maxY - minY ) * gapRatio;
            border2Y = maxY + ( maxY - minY ) * gapRatio;
        }
    }

    x_res = ( border2X - border1X ) / width;
    y_res = ( border2Y - border1Y ) / height;
    //
    // --- Draw background
    DrawGrid();

    // --- Draw graphs
    for( std::list<Graph>::iterator it = graphs.begin(); it != graphs.end(); ++it )
    {
        DrawGraph( *it );
    }

    //cv::imshow( winname, graph );
}

void db::Plotter::rollback()
{
    isUpToDate = false;
}

void db::Plotter::setXLim( double low, double high )
{
    border1X = low;
    border2X = high;
    xLimSet = true;
    isUpToDate = false;
}

void db::Plotter::setYLim( double low, double high )
{
    border1Y = low;
    border2Y = high;
    yLimSet = true;
    isUpToDate = false;
}

void db::Plotter::setTimeFrame( int numFrames )
{
    timeFrame = numFrames;
}

void db::Plotter::setPlotType( ePlotType type, Colour colour )
{
    if( colour == Colour( -1, -1, -1 ) )
    {
        for( std::list<Graph>::iterator it = graphs.begin(); it != graphs.end(); ++it )
        {
            it->type = type;
        }
    }
    else
    {
        GetGraph( colour ).type = type;
    }
}

void db::Plotter::setLineThickness( int thickness, Colour colour )
{
    if( colour == Colour( -1, -1, -1 ) )
    {
        for( std::list<Graph>::iterator it = graphs.begin(); it != graphs.end(); ++it )
        {
            it->thickness = thickness;
        }
    }
    else
    {
        GetGraph( colour ).thickness = thickness;
    }
}

void db::Plotter::setDotRadius( int radius, Colour colour )
{
    if( colour == Colour( -1, -1, -1 ) )
    {
        for( std::list<Graph>::iterator it = graphs.begin(); it != graphs.end(); ++it )
        {
            it->thickness = radius;
        }
    }
    else
    {
        GetGraph( colour ).thickness = radius;
    }
}
cv::Point db::Plotter::GetPixelLocation( PlotPoint p )
{
    return GetPixelLocation( p.x, p.y );
}

cv::Point db::Plotter::GetPixelLocation( double x, double y )
{
    int x_px = ( int )( ( x - border1X ) / x_res );
    int y_px = height - ( int )( ( y - border1Y ) / y_res );
    return cv::Point( x_px, y_px );
}

double db::Plotter::Shift( double val, int shift )
{
    return ( double )val / pow( 10, shift );
}

void db::Plotter::UpdateMinMax( double x, double y )
{
    if( firstInput )
    {
        minX = x;
        maxX = x;
        minY = y;
        maxY = y;
        firstInput = false;
    }
    else
    {
        minX = min( x, minX );
        maxX = max( x, maxX );
        minY = min( y, minY );
        maxY = max( y, maxY );
    }
}

void db::Plotter::DrawGrid()
{
    window.setTo( backgroundColour );

    if( showAxes )
    {
        if( border1X < 0.0 && border2X > 0.0 )
        {
            cv::line( window, GetPixelLocation( 0.0, border1Y ), GetPixelLocation( 0.0, border2Y ), axisColour, axisThickness );
        }

        if( border1Y < 0.0 && border2Y > 0.0 )
        {
            cv::line( window, GetPixelLocation( border1X, 0.0 ), GetPixelLocation( border2X, 0.0 ), axisColour, axisThickness );
        }
    }

    int font = 0;
    double fontScale = 0.4;
    int thickness = 1;
    int markerLen = 5;
    int offset = 3;
    int precision = 2 - digits( border2X - border1X );
    double inc = round( ( border2X - border1X ) / numLines, precision );

    for( double val = round( border1X, precision ); val <= border2X; val += inc )
    {
        cv::Point pixel = GetPixelLocation( val, border1Y );
        char text[64];

        if( precision > 0 )
        {
            sprintf( text, "%0.*f", precision, val );
        }
        else
        {
            sprintf( text, "%d", ( int )val );
        }

        int textWidth = cv::getTextSize( std::string( text ), font, fontScale, thickness, 0 ).width;
        cv::putText( window, std::string( text ), cv::Point( pixel.x - textWidth / 2, pixel.y - markerLen - offset ), font, fontScale, axisColour, thickness );
        cv::line( window, pixel, cv::Point( pixel.x, pixel.y - markerLen ), axisColour, thickness );
    }

    precision = 2 - digits( border2Y - border1Y );
    inc = round( ( border2Y - border1Y ) / numLines, precision );

    for( double val = round( border1Y, precision ); val <= border2Y; val += inc )
    {
        cv::Point pixel = GetPixelLocation( border1X, val );
        char text[64];

        if( precision > 0 )
        {
            sprintf( text, "%0.*f", precision, val );
        }
        else
        {
            sprintf( text, "%d", ( int )val );
        }

        int textHeight = cv::getTextSize( std::string( text ), font, fontScale, thickness, 0 ).height;
        cv::putText( window, std::string( text ), cv::Point( pixel.x + markerLen + offset, pixel.y + textHeight / 2 ), font, fontScale, axisColour, thickness );
        cv::line( window, pixel, cv::Point( pixel.x + markerLen, pixel.y ), axisColour, thickness );
    }
}

void db::Plotter::DrawGraph( Graph& graph )
{
    cv::Scalar colour = cvColour( graph.colour );

    if( graph.size() == 0 )
    {
        return;
    }
    else if( graph.size() == 1 )
    {
        cv::Point p = GetPixelLocation( graph.front() );
        cv::circle( window, p, 2, colour, -1 );
        return;
    }

    switch( graph.type )
    {
        case PlotLines:
        {
            cv::Point prevPoint = GetPixelLocation( graph.front() );
            std::list<PlotPoint>::iterator it = graph.begin();
            ++it;

            for( ; it != graph.end(); ++it )
            {
                cv::Point p = GetPixelLocation( *it );
                cv::line( window, prevPoint, p, colour, graph.thickness );
                prevPoint = p;
            }

            break;
        }

        case PlotDots:
            for( std::list<PlotPoint>::iterator it = graph.begin(); it != graph.end(); ++it )
            {
                cv::Point p = GetPixelLocation( *it );
                cv::circle( window, p, graph.thickness, colour, -1 );
            }

            break;
    }
}

db::Plotter::Graph& db::Plotter::GetGraph( db::Colour colour )
{
    std::list<Graph>::iterator it = graphs.begin();

    for( ; it != graphs.end(); ++it )
    {
        if( it->colour == colour )
        {
            return *it;
        }
    }

    graphs.push_back( Graph( colour ) );
    return GetGraph( colour );
}

cv::Scalar db::Plotter::cvColour( db::Colour colour )
{
    return cv::Scalar( ( double )colour.b, ( double )colour.g, ( double )colour.r );
}

double db::Plotter::round( double val, int decimal_places, bool trunc )
{
    double result;
    double factor = pow( 10, decimal_places );

    if( trunc )
    {
        modf( val * factor, &result );
    }
    else
    {
        modf( ( val * factor ) + 0.5, &result );
    }

    result /= factor;
    return result;
}

int db::Plotter::digits( double val )
{
    if( isinf( val ) )
    {
        return -1;
    }

    int result = 0;

    while( val >= 1 )
    {
        val /= 10.0;
        result++;
    }

    while( val < 0.1 )
    {
        val *= 10.0;
        result--;
    }

    return result;
}

double db::Plotter::getInc( double gap, double& precision )
{
    gap;
    precision;
    double nums[5] = { 0.0099, 0.099, 0.99, 9.9, 99.0 };
    double results1[5] = { 0.0 };
    double results2[5] = { 0.0 };

    for( int i = 0; i < 5; i++ )
    {
        results1[i] = digits( nums[i] );
        results2[i] = round( nums[i] / 5, 2 - ( int )results1[i] );
    }

    return 1.0;
    //precision = 2 - digits( gap );
    //double inc = round( gap / numLines, (int)precision );
}

#endif // !WINDOWS_DEBUGGING
