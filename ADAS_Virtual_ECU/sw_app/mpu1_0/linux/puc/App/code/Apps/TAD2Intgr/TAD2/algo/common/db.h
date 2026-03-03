// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [17-Jan-2019]
// --- Last Modified by Joshua Teichroeb [02-Aug-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------
#ifdef _WINDOWS_
#ifndef __DB__H_
#define __DB__H_

#include "dbTypes.h"
#include "Image.h"

#ifdef __QNX__
    #include "../inc/FeatureExtraction.h"
#else
    #include "FeatureExtraction.h"
#endif

///------------------------------------------------------------------------------
/// Debugging library
///
/// This header is to remain free from OpenCV and std library functions/classes.
///------------------------------------------------------------------------------
namespace db
{
    /*
    * Initialize the debugger.
    */
    void init();

    /*
    * Uninitialize the debugger.
    */
    void uninit();

    /*
    * Check if the debugger is running.
    */
    bool isRunning();

    /*
    * Run the debugger. Updates all invalidated debugging windows and then calls 'cv::waitKey()'.
    */
    void run( int frameNum = -1 );

    /*
    * Reset the debugger.
    */
    void reset();


    ///------------------------------------------------------------------------------
    /// Window functions
    ///
    /// Debugging windows are created whenever a plotting or "imshow" function is
    /// called, or when created manually using "createWindow()". Windows are defined
    /// by their names and each hold one or more "Views".
    ///
    /// There are two types of windows: those created by the 'createWindow()' function
    /// which can hold other views, and those created by the 'imshow()' and plotting
    /// functions which hold a single view. When a window is created using
    /// 'createWindow()', you may create your own views (using 'createView()') and then
    /// insert them into the window. These views can then be updated using the
    /// 'imshow()' or plotting functions. However, if an 'imshow()' or plotting function
    /// is called before 'createView()', then a default window is created which will
    /// hold a single view with the same name.
    ///
    /// Each window is given a debugging category and level based on the prefix of
    /// its name. These prefixes have the form "(CAT-N)" where "CAT" is the category
    /// assigned to the window and "N" is its debugging level. Lower numbered levels
    /// indicate higher prominence with "1" being the most prominent. Windows without
    /// a prefix are given level "1" by default.
    ///------------------------------------------------------------------------------

    /*
    * Set the debugging level.
    *
    * 0 => No windows enabled by default.
    * 1+ => All windows with 'level' or higher prominence enabled by default.
    */
    void setDebugLevel( int level );

    /*
    * Enable the given window.
    */
    void enableWindow( const char* winname );

    /*
    * Disable the given window.
    */
    void disableWindow( const char* winname );

    /*
    * Set the debugging level for a particular category of windows.
    */
    void setCategoryLevel( const char* category, int level );

    /*
    * Create a blank window.
    */
    void createWindow( const char* winname, int width = 0, int height = 0 );

    /*
    * Create a view, free of any window.
    */
    void createView( const char* viewname, int width = 0, int height = 0 );

    /*
    * Add the given view to the given window. 'row' and 'col' specify where in the window
    * grid to place the view (will expand to fit).
    *
    * This will destroy the window with the name 'viewname' if it exists.
    */
    void addViewToWindow( const char* winname, const char* viewname, int row, int col );

    /*
    * Return a pointer to the underlying data structure of a window/view.
    *
    * If the window/view was created using a plotting or "imshow" function, then a
    * cv::Mat* will be returned.
    */
    void* getHandle( const char* winname );


    ///------------------------------------------------------------------------------
    /// Plotting functions
    ///
    /// Plotting data creates a Plotter object and displays it in a Window with a
    /// single view. The windows created by these functions can be further drawn upon
    /// or inserted into other windows. Multiple data sets can be plotted in the same
    /// window/view by plotting the different sets in different colours.
    ///------------------------------------------------------------------------------

    /*
    * Plot the given value along a default axis which increments every time the function is
    * called.
    */
    void plot( const char* winname, double val, Colour colour = Colour( 0, 0, 0 ), int shift = 0 );

    /*
    * Plot the point (x, y).
    *
    * Unless "setPlotXLim()" or "setPlotYLim()" have been called, the window will expand to fit
    * all data given to it.
    */
    void plot( const char* winname, double x, double y, Colour colour = Colour( 0, 0, 0 ), int shift = 0 );

    /*
    * Plot the given array of points (x[i], y[i]).
    *
    * See "plot(winname, x, y, colour, shift)".
    */
    template<typename T>
    void plot( const char* winname, T* x, T* y, int numPoints, Colour colour = Colour( 0, 0, 0 ), int shift = 0 );

    /*
    * Clear the given plotting window.
    */
    void clearPlot( const char* winname );

    /*
    * Reset the given plotting window.
    *
    * Clears the data in the window, and also resets the X and Y limits.
    */
    void resetPlot( const char* winname );

    /*
    * Set the visible X range for the given plotting window.
    */
    void setPlotXLim( const char* winname, double low, double high );

    /*
    * Set the visible Y range for the given plotting window.
    */
    void setPlotYLim( const char* winname, double low, double high );

    /*
    * Set the time-frame used when plotting by value only.
    */
    void setPlotTimeFrame( const char* winname, int timeframe );

    /*
    * Set the time-frame used when plotting by value only.
    */
    void setPlotType( const char* winname, db::ePlotType type, Colour colour = Colour( -1, -1, -1 ) );

    /*
    * Set the thickness of the line with the given colour.
    */
    void setPlotLineThickness( const char* winname, int thickness, Colour colour = Colour( -1, -1, -1 ) );

    /*
    * Set the radius of the dots with the given colour.
    */
    void setPlotDotRadius( const char* winname, int radius, Colour colour = Colour( -1, -1, -1 ) );

    ///------------------------------------------------------------------------------
    /// Image display functions
    ///
    /// Calling one of these functions will create a window and display the given
    /// image in that window in a certain format. The window created will hold a
    /// a single view which can either be drawn upon or inserted into another window.
    ///
    /// The window will only be created the first time the function is called and
    /// every further call will simply update the view corresponding to it. If the
    /// view has been inserted into a different window (and thus this window
    /// destroyed), then further calls to the function will still only update the
    /// view (and not create a new window).
    ///
    /// The underlying data structure most of these windows is a cv::Mat of type
    /// CV_8UC3. By default the display matrix will be formatted as a BGR image.
    ///------------------------------------------------------------------------------

    /*
    * Show an image in a debugging window.
    *
    * 'maxVal' and 'minVal' determine the maximum and minimum values in the image when
    * converting to BGR. If set equal to each other, the actual min and max values will
    * be found and used.
    *
    * Available imshow options:
    *     ImShow_Grey2Colour    - Display a grey-scale image as a colour-scale image.
    *     ImShow_Binary         - Display '0' pixels as black, '> 0' pixels as white.
    *     ImShow_BGR            - Display a BGR (3-channel) image.
    *     ImShow_Grey           - Display a grey-scale (1-channel) image (still converts
    *                             to a 3-channel BGR underlying image).
    *     ImShow_Default        - The default display option.
    */
    template<typename T>
    void imshow( const char* winname, image::Image<T> image, imshow_options option = ImShow_Default, T maxVal = 255, T minVal = 0 );

    /*
    * Display and segment an image into 3 classes according to the given threshold images.
    *
    * Colour code:
    *     val < 'thresh_low'                    => Blue
    *     'thresh_low' < val < 'thresh_high'    => Green
    *     val > 'thresh_high'                   => Red
    */
    template<typename T, typename U>
    void imshow_segmented( const char* winname, image::Image<T> image, image::Image<U> thresh_low, image::Image<U> thresh_high );

    /*
    * Display and segment an image into 3 classes according to the given threshold values.
    *
    * Colour code:
    *     val < 'thresh_low'                    => Blue
    *     'thresh_low' < val < 'thresh_high'    => Green
    *     val > 'thresh_high'                   => Red
    */
    template<typename T>
    void imshow_segmented( const char* winname, image::Image<T> image, T thresh_low, T thresh_high );

    /*
    * Display an image so that it can easily be seen which values are above and which values
    * are below a given threshold.
    *
    * Colour code:
    *     White     => is threshold value
    *     Red       => intensity implies below threshold value
    *     Blue      => intensity implies above threshold value
    */
    template<typename T>
    void imshow_threshold( const char* winname, image::Image<T> image, T thresh, T maxVal = 255, T minVal = 0 );

    /*
    * Display an image so that the given range of values is magnified, or normalized. The
    * values above/below the range will be set to pure Red or pure Blue respectively.
    *
    * If neither 'maxVal' or 'minVal' are input, and the input image type is uint8, then
    * this function acts the same as 'imshow()'.
    *
    * Colour code:
    *     Grey      => in range with the intensity normalized between 'maxVal' and 'minVal'
    *     Red       => above 'maxVal'
    *     Blue      => below 'minVal'
    */
    template<typename T>
    void imshow_range( const char* winname, image::Image<T> image, T maxVal = 255, T minVal = 0 );

    /*
    * See 'imshow_threshold()' except 'maxVal' and 'minVal' need not be the actual maximum and
    * minimum image values as values above/below these values will be set to pure Blue or pure
    * Red respectively.
    */
    template<typename T>
    void imshow_threshold_and_range( const char* winname, image::Image<T> image, T thresh, T maxVal = 255, T minVal = 0 );

    /*
    * Display the overlap between two images.
    *
    * Colour code:
    *     Blue      - first input image value is above 0
    *     Red       - second input image value is above 0
    *     Magenta   - image overlap
    */
    template<typename T>
    void imshow_overlap( const char* winname, image::Image<T> image1, image::Image<T> image2 );

    /*
    * See 'imshow_overlap()' except the intensity implies the template matching weight of that
    * pixel.
    */
    template<typename T>
    void imshow_templateOverlap( const char* winname, image::Image<T> template1, image::Image<T> template2, float32_t tmFactor );


    ///------------------------------------------------------------------------------
    /// Drawing functions
    ///
    /// These functions wrap their equivalent opencv functions. They can only be
    /// used on windows which support drawing.
    ///------------------------------------------------------------------------------

    /*
    * Draw a line on a window/view.
    */
    void line( const char* winname, Point2i p1, Point2i p2, db::Colour colour, int thickness = 1 );

    /*
    * Draw a circle on a window/view.
    */
    void circle( const char* winname, db::Point centre, int radius, db::Colour colour, int thickness = 1 );

    /*
    * Draw a rectangle on a window/view.
    */
    void rect( const char* winname, _roi::ROI roi, db::Colour colour, int thickness = 1 );


    ///------------------------------------------------------------------------------
    /// Functions specific to TAD
    ///
    /// These functions were created to help the debugging of certain TAD algorithms.
    ///------------------------------------------------------------------------------

    void debugMemoryPool( int frame );
    void showAngleDetection( const image::Image<uint8_t> inputImage, image::Image<uint8_t> trailerTemplate, image::Image<uint8_t> trailerTemplate2, image::Image<uint8_t> matchedTemplate, float curAngle, int angleXPos, int templateYOffset, float tmFactor );
    void showMirrorOverlap( const image::Image<uint8_t> templateImage );
    void showFeatures( const char* category, const image::Image<TAD2::FeatureExtraction::Feature>& featureImage );

}

#include "db.hpp"

#endif // !__DB__H_
#endif //_WINDOWS_
