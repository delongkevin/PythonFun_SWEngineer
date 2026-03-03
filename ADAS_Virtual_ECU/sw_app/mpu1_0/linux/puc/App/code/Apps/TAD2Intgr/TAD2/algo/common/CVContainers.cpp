// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [10-Sep-2018]
// --- Copyright (c) Magna Electronics - Brampton 2018
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "CVContainers.h"

#ifdef WINDOWS_DEBUGGING

using namespace cv;

#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

////////////////////////////////////////////
//////////////// ViewProxy /////////////////
////////////////////////////////////////////

ViewProxy::ViewProxy( float i_x, float i_y, float i_width, float i_height ) :
    x( i_x ),
    y( i_y ),
    width( i_width ),
    height( i_height ),
    view( NULL )
{
}

ViewProxy::ViewProxy() :
    ViewProxy( 0.0f, 0.0f, 0.0f, 0.0f )
{
}

ViewProxy::~ViewProxy()
{
}

void ViewProxy::refreshView( cv::Mat& parentImg )
{
    cv::Rect viewRect = cv::Rect( ( int )( x * parentImg.cols ), ( int )( y * parentImg.rows ), ( int )( width * parentImg.cols ), ( int )( height * parentImg.rows ) );
    cv::Rect rectInParent = viewRect & cv::Rect( 0, 0, parentImg.cols, parentImg.rows );
    cv::Mat matInParent = cv::Mat( parentImg, rectInParent );

    if( viewRect.width != rectInParent.width || viewRect.height != rectInParent.height )
    {
        cv::Mat viewMat = cv::Mat( viewRect.height, viewRect.width, parentImg.type() );
        cv::Rect roi = cv::Rect( rectInParent.x - viewRect.x, rectInParent.y - viewRect.y, rectInParent.width, rectInParent.height );
        matInParent.copyTo( viewMat( roi ) );
        view->refresh( viewMat );
        viewMat( roi ).copyTo( matInParent );
    }
    else
    {
        view->refresh( matInParent );
    }
}
#if DISABLED_CODE
vector<ViewProxy*> ViewProxy::getChildren()
{
    if( view != NULL )
    {
        return view->getChildren();
    }
}
#endif

////////////////////////////////////////////
/////////////////// View ///////////////////
////////////////////////////////////////////


View::View( ViewParameters viewParams, eViewType i_viewType ) :
    parent( NULL ),
    invalid( true ),
    refreshRequested( true ),
    borderWidth( viewParams.borderWidth ),
    colour( viewParams.colour ),
    borderColour( viewParams.borderColour ),
    horMargin( viewParams.horMargin ),
    verMargin( viewParams.verMargin ),
    viewType( i_viewType )
{
}

/**
 * Constructor.
 *
 * @param i_width width of view
 * @param i_height height of view
 */
View::View() :
    parent( NULL ),
    invalid( true ),
    refreshRequested( true ),
    borderWidth( 1 ),
    colour( 255, 255, 255 ),
    borderColour( 0, 0, 0 ),
    horMargin( 1 ),
    verMargin( 1 ),
    viewType( eUndefinedView )
{
}

/**
* Constructor.
*
* @param i_rect input rectangle that determines size of view
*/
//View::View( const cv::Rect i_rect ) :
//    View( i_rect.width, i_rect.height )
//{
//}

/**
* Constructor.
*
* @param i_size desired size of view
*/
//View::View( const cv::Size i_size ) :
//    View( i_size.width, i_size.height )
//{
//}

/**
* Constructor.
*/
//View::View() :
//    View( 0, 0 )
//{
//}

/**
* Destructor. Derived classes are responsible for deleting their children if
* they are defined.
*/
View::~View()
{
}

void View::Uninit()
{
    for( ViewProxy* child : getProxies() )
    {
        if( child != NULL )
        {
            if( child->view != NULL )
            {
                child->view->Uninit();
                delete child->view;
                child->view = NULL;
            }

            delete child;
            child = NULL;
        }
    }
}

/**
* Invalidate this view and all of its children views. Also sets refreshRequested
* so that each child view will be refreshed.
*/
void View::invalidate()
{
    invalid = true;
    refreshRequested = true;

    for( View* child : getChildren() )
    {
        if( child != NULL )
        {
            child->invalidate();
        }
    }
}

/**
* Request a refresh. Tells the parent view that we need to be refreshed.
*/
void View::requestRefresh()
{
    refreshRequested = true;

    if( parent != NULL )
    {
        parent->requestRefresh();
    }
}

/**
* Refresh this view and possibly its children
*
* @param img image confining this view
*/
void View::refresh( cv::Mat& img )
{
    if( invalid )
    {
        drawView( img );
    }

    if( refreshRequested )
    {
        refreshChildren( img );
        drawOverlay( img );
    }

    invalid = false;
    refreshRequested = false;
}

/**
* Refresh each of this views children.
*
* @param img image confining this view
*/
void View::refreshChildren( cv::Mat& img )
{
    for( ViewProxy* child : getProxies() )
    {
        if( child->view != NULL && isChildInView( child ) )
        {
            cv::Rect childRect = cv::Rect( ( int )( child->x * img.cols ), ( int )( child->y * img.rows ), ( int )( child->width * img.cols ), ( int )( child->height * img.rows ) );
            cv::Rect rectInView = childRect & cv::Rect( 0, 0, img.cols, img.rows );
            cv::Mat matInView = cv::Mat( img, rectInView );

            if( rectInView.width != childRect.width || rectInView.height != childRect.height )
            {
                cv::Mat childMat = cv::Mat( childRect.height, childRect.width, img.type() );
                cv::Rect roi = cv::Rect( rectInView.x - childRect.x, rectInView.y - childRect.y,  rectInView.width, rectInView.height );
                matInView.copyTo( childMat( roi ) );
                child->view->refresh( childMat );
                childMat( roi ).copyTo( matInView );
            }
            else
            {
                child->view->refresh( matInView );
            }
        }
    }
}

/**
* Manually draw this view on a given image.
*
* @param img image confining this view
*/
void View::drawView( cv::Mat& img )
{
    if( colour != CV_TRANSPARENT )
    {
        rectangle( img, cv::Point( 0, 0 ), cv::Point( img.cols - 1, img.rows - 1 ), colour, -1 );
        //rectangle( img, cv::Point( borderWidth, borderWidth ), cv::Point( img.cols - 1 - borderWidth, img.rows - 1 - borderWidth ), colour, -1 );
    }
}

/**
* Draw the overlay of this view. Called after children are drawn.
*
* @param img image confining this view
*/
void View::drawOverlay( cv::Mat& img )
{
    if( borderColour != CV_TRANSPARENT )
    {
        rectangle( img, cv::Point( 0, 0 ), cv::Point( img.cols - 1, img.rows - 1 ), borderColour, borderWidth );
    }
}

/**
* Return whether the rectangle is overlapping this view.
*
* @param rect rectangle to check
*/
//bool View::isRectInView( const cv::Rect& rect )
//{
//    cv::Rect roi = *this & rect;
//    return roi.width > 0 && roi.height > 0;
//}

/**
* Return whether the child is actually inside this view at all.
*
* @param child child to check
*/
bool View::isChildInView( const ViewProxy* child )
{
    if( child->x + child->width <= 0.0f )
    {
        return false;
    }
    else if( child->x >= 1.0f )
    {
        return false;
    }
    else if( child->y + child->height <= 0.0f )
    {
        return false;
    }
    else if( child->y >= 1.0f )
    {
        return false;
    }
    else
    {
        return true;
    }
}

/**
* Return whether the point is inside the child view.
*
* @param child child to check
* @param i_x x position relative to this view
* @param i_y y position relative to this view
*/
bool View::doesChildContainPoint( const ViewProxy* child, float i_x, float i_y )
{
    if( i_x < child->x )
    {
        return false;
    }
    else if( i_x > child->x + child->width )
    {
        return false;
    }
    else if( i_y < child->y )
    {
        return false;
    }
    else if( i_y > child->y + child->height )
    {
        return false;
    }
    else
    {
        return true;
    }
}

/**
* Process a mouse event.
*
* @param e the mouse event
* @param i_x x position relative to this view of the mouse event
* @param i_y y position relative to this view of the mouse event
*/
void View::processMouseEvent( MouseEvent e, float i_x, float i_y )
{
    if( i_x < 0.0f || i_x > 1.0f || i_y < 0.0f || i_y > 1.0f )
    {
        return;
    }

    for( ViewProxy* child : getProxies() )
    {
        if( child->view != NULL && isChildInView( child ) && doesChildContainPoint( child, i_x, i_y ) )
        {
            float rel_x = ( i_x - child->x ) / child->width;
            float rel_y = ( i_y - child->y ) / child->height;
            child->view->processMouseEvent( e, rel_x, rel_y );
        }
    }
}

/**
* Set new dimensions for this view, as well as perform any operations necessary
* when the size of the view is changed. Safer option than setting width and height
* explicitly using setters.
*
* @param i_width desired width
* @param i_height desired height
*/
//void View::resize(float i_width, float i_height )
//{
//    width *= i_width;
//    height *= i_height;
//
//    for( View* child : getChildren() )
//    {
//        if( child != NULL )
//        {
//            float w = child->getWidth() / width;
//            float h = child->getHeight() / height;
//
//            if( w == 0.0f )
//            {
//                w = (width - child->x) / width;
//            }
//
//            if( h == 0.0f)
//            {
//                h = (height - child->getY()) / height;
//            }
//
//            child->resize( w, h );
//        }
//    }
//}

/**
* Resize according to the current state of the view.
*/
//void View::resize()
//{
//    resize( width, height );
//}

//int View::getX() const
//{
//    return x;
//}
//
//int View::getY() const
//{
//    return y;
//}
//
//int View::getWidth() const
//{
//    return width;
//}
//
//int View::getHeight() const
//{
//    return height;
//}
//
//void View::setX( int i_x )
//{
//    x = i_x;
//}
//
//void View::setY( int i_y )
//{
//    y = i_y;
//}
//
//void View::setWidth( int i_width )
//{
//    width = i_width;
//}
//
//void View::setHeight( int i_height )
//{
//    height = i_height;
//}

eViewType cv::View::getViewType()
{
    return viewType;
}

void View::setParent( View& parentView )
{
    parent = &parentView;
}

/**
* Set the colour of the inside of this view (BGR).
*
* @param b blue component
* @param g green component
* @param r red component
*/
void View::setColour( int b, int g, int r )
{
    colour = Scalar( b, g, r );
}

/**
* Set the colour of the inside of this view.
*
* @param i_colour colour
*/
void View::setColour( cv::Scalar i_colour )
{
    colour = i_colour;
}

/**
* Set the colour of the border of this view (BGR).
*
* @param b blue component
* @param g green component
* @param r red component
*/
void View::setBorderColour( int b, int g, int r )
{
    borderColour = Scalar( b, g, r );
}

/**
* Set the colour of the border of this view.
*
* @param i_colour colour
*/
void View::setBorderColour( cv::Scalar i_colour )
{
    borderColour = i_colour;
}

/**
* Set the width of this views border.
*
* @param thickness desired thickness/width
*/
void View::setBorderThickness( int thickness )
{
    borderWidth = thickness;
}

void View::setMargins( int i_horMargin, int i_verMargin )
{
    horMargin = i_horMargin;
    verMargin = i_verMargin;
}


////////////////////////////////////////////
/////////////// AbstractView ///////////////
////////////////////////////////////////////
AbstractView::AbstractView( ViewParameters viewParams ) :
    View( viewParams, eAbstractView )
{
}

AbstractView::AbstractView( )
{
}

AbstractView::~AbstractView()
{
    //for( ViewProxy* child : children )
    //{
    //    if( child != NULL )
    //    {
    //        if( child->view != NULL )
    //        {
    //            delete child->view;
    //        }
    //
    //        delete child;
    //    }
    //}
}

std::vector<View*> AbstractView::getChildren()
{
    std::vector<View*> childViews;

    for( ViewProxy* child : children )
    {
        childViews.push_back( child->view );
    }

    return childViews;
}

std::vector<ViewProxy*> AbstractView::getProxies()
{
    return children;
}

ViewProxy* AbstractView::getChildPos( View* childView )
{
    cv::Rect_<float> pos;

    for( ViewProxy* child : children )
    {
        if( child->view == childView )
        {
            return child;
        }
    }

    return NULL;
}

/**
* Add another view inside this view. The added child view will be relative
* to this view and not this views parent, etc. If the child view does not
* have a size, this will set its size to fill the rest of this view.
*
* @param i_x the X-position of the top-left corner of the child view,
*            relative to this view
* @param i_y the Y-position of the top-left corner of the child view,
*            relative to this view
* @param childView the view to be added
*/
void AbstractView::addChildView( View* childView, float i_x, float i_y, float i_width, float i_height )
{
    //float w = childView->getWidth() / width;
    //float h = childView->getHeight() / height;
    //
    if( i_width == 0.0f )
    {
        i_width = 1.0f - i_x;
    }

    if( i_height == 0.0f )
    {
        i_height = 1.0f - i_y;
    }

    //
    //childView->resize( w, h );
    //childView->setX(i_xPos * width);
    //childView->setY(i_yPos * height);
    childView->setParent( *this );
    ViewProxy* child = new ViewProxy( i_x, i_y, i_width, i_height );
    child->view = childView;
    children.push_back( child );
}

/**
* Shorthand for addChildView(int i_x, int i_y, View& childView).
*/
void AbstractView::addChildView( View* childView )
{
    addChildView( childView, 0.0f, 0.0f, 0.0f, 0.0f );
}

void AbstractView::resizeChild( View* childView, float i_width, float i_height )
{
    ViewProxy* childPos = getChildPos( childView );

    if( i_width == 0.0f )
    {
        i_width = 1.0f - childPos->x;
    }

    if( i_height == 0.0f )
    {
        i_height = 1.0f - childPos->y;
    }

    childPos->height = i_height;
    childPos->width = i_width;
    //if( fitTextSet )
    //{
    //    fitText( 0.05, textRatio );
    //}
    //else if( textRatio != -1.0 )
    //{
    //    resizeText();
    //}
}

////////////////////////////////////////////
///////////////// TextView /////////////////
////////////////////////////////////////////

TextView::TextView( std::string i_text, TextViewParameters params ) :
    AbstractView( params.viewParams ),
    text( i_text ),
    font( params.font ),
    textThickness( params.textThickness ),
    fontScale( params.fontScale ),
    textRatio( params.textRatio ),
    fitTextSet( params.fitTextSet ),
    textColour( params.textColour ),
    alignment( params.alignment )
{
    viewType = eTextView;
}

TextView::TextView( std::string i_text ) :
    AbstractView( ),
    text( i_text ),
    font( FONT_HERSHEY_SIMPLEX ),
    textThickness( 1 ),
    fontScale( 1.0 ),
    textRatio( 1.0 ),
    fitTextSet( true ),
    textColour( 0, 0, 0 ),
    alignment( AlignLeft )
{
    viewType = eTextView;
}

TextView::~TextView()
{
}

void TextView::drawView( cv::Mat& img )
{
    //cv::Mat roi = cv::Mat( img, *this & cv::Rect( 0, 0, img.cols, img.rows ) );
    // --- Draw background
    if( colour != CV_TRANSPARENT )
    {
        rectangle( img, cv::Point( 0, 0 ), cv::Point( img.cols - 1, img.rows - 1 ), colour, -1 );
    }

    // --- Get text size
    if( fitTextSet )
    {
        fitText( img.cols, img.rows, 0.05, textRatio );
    }
    else if( textRatio != -1.0 )
    {
        resizeText( img.rows );
    }

    cv::Size textSize = cv::getTextSize( text, font, fontScale, textThickness, NULL );

    // --- Draw text
    switch( alignment )
    {
        default:
        case AlignLeft:
            cv::putText( img, text, cv::Point( horMargin, img.rows / 2 + textSize.height / 2 ), font, fontScale, textColour, textThickness, 8, false );
            break;

        case AlignRight:
            cv::putText( img, text, cv::Point( img.cols - horMargin - textSize.width, img.rows / 2 + textSize.height / 2 ), font, fontScale, textColour, textThickness, 8, false );
            break;

        case AlignCentre:
            cv::putText( img, text, cv::Point( img.cols / 2 - textSize.width / 2, img.rows / 2 + textSize.height / 2 ), font, fontScale, textColour, textThickness, 8, false );
            break;
    }
}

/**
* Resize text based on current textRatio amd given height.
*/
void TextView::resizeText( int height )
{
    cv::Size textSize = cv::getTextSize( text, font, fontScale, textThickness, 0 );

    while( ( double )textSize.height > textRatio * ( ( double )height / 2.0 ) )
    {
        fontScale -= 0.025;
        textSize = cv::getTextSize( text, font, fontScale, textThickness, 0 );
    }

    while( ( double )textSize.height < textRatio * ( ( double )height / 2.0 ) )
    {
        fontScale += 0.025;
        textSize = cv::getTextSize( text, font, fontScale, textThickness, 0 );
    }

    fitTextSet = false;
}

/**
* Set text to fit into the given dimensions. (See setTextRatio(...) for ratio definition.)
*
* @param i_maxRatio the starting/desired ratio
* @param i_minRatio the minimum ratio
*/
void TextView::fitText( int width, int height, double i_minRatio, double i_maxRatio )
{
    setTextRatio( i_maxRatio );
    resizeText( height );
    cv::Size textSize = cv::getTextSize( text, font, fontScale, textThickness, 0 );

    while( ( double )( textSize.width + 2 * horMargin ) > width && i_minRatio < ( ( double )textSize.height * 2.0 ) / ( double )height )
    {
        fontScale -= 0.025;
        textSize = cv::getTextSize( text, font, fontScale, textThickness, 0 );
    }

    fitTextSet = true;
}


std::string TextView::getText()
{
    return text;
}

void TextView::setText( std::string i_text )
{
    text = i_text;
}

void TextView::setFont( int i_font )
{
    font = i_font;
}

void TextView::setTextThickness( int i_thickness )
{
    textThickness = i_thickness;
}

/**
* Set fontScale explicitly. (Not recommended. See setTextRatio().)
*
*@param i_fontScale the desired pixel scale of this views text - argument
*                   passed into cv::putText()
*/
void TextView::setFontScale( double i_fontScale )
{
    fontScale = i_fontScale;
    textRatio = -1.0;
}

/**
* Set text ratio. Also resizes text by calling resizeText().
*
*@param i_ratio the ratio of the size of the text to the height of the view
*                multipliyed by 2
*/
void TextView::setTextRatio( double i_ratio )
{
    textRatio = i_ratio;
    fitTextSet = false;
}

void TextView::setTextColour( int b, int g, int r )
{
    textColour = cv::Scalar( b, g, r );
}

void TextView::setTextColour( cv::Scalar i_colour )
{
    textColour = i_colour;
}

void TextView::setTextAlignment( eTextAlignment i_alignment )
{
    alignment = i_alignment;
}

////////////////////////////////////////////
//////////////// ScrollView ////////////////
////////////////////////////////////////////
ScrollView::ScrollView( ) :
    scrollAmount( 1.0f ),
    top( 0.0f ),
    height( 1.0f )
{
    colour = cv::Scalar( 255, 255, 255 );
    viewType = eScrollView;
}

ScrollView::~ScrollView()
{
}

/**
* Draw this ScrollView. Note: ScrollViews cannot be transparent.
*
*  @param img image this view will be drawn on
*/
void ScrollView::drawView( cv::Mat& img )
{
    //cv::Mat roi = cv::Mat( img, *this & cv::Rect( 0, 0, img.cols, img.rows ) );
    rectangle( img, cv::Point( 0, 0 ), cv::Point( img.cols - 1, img.rows - 1 ), colour, -1 );
}

void ScrollView::processMouseEvent( MouseEvent e, float i_x, float i_y )
{
    View::processMouseEvent( e, i_x, i_y );

    if( i_x < 0.0f || i_x > 1.0f || i_y < 0.0f || i_y > 1.0f )
    {
        return;
    }

    if( e.op == EventMouseWheel )
    {
        scroll( ( float )e.dy * scrollAmount );
        invalidate();
        requestRefresh();
    }
}

void ScrollView::scroll( float dy )
{
    if( dy == 0 )
    {
        return;
    }
    else if( dy > 0 )
    {
        if( distanceFromTop() >= 0.0f )
        {
            return;
        }
        else
        {
            dy = min( dy, -distanceFromTop() );
        }
    }
    else if( dy < 0 )
    {
        if( distanceFromBottom() <= 0.0f )
        {
            return;
        }
        else
        {
            dy = max( dy, -distanceFromBottom() );
        }
    }

    for( ViewProxy* child : getProxies() )
    {
        child->y += dy;
    }

    setTop( top + dy );
}

void ScrollView::scrollToBottom()
{
    //float maxY = 0.0f;
    //
    //for( ViewProxy* child : getProxies() )
    //{
    //    if( child->y + child->height > maxY )
    //    {
    //        maxY = child->y + child->height;
    //    }
    //}
    //
    //if( maxY > 1.0f )
    //{
    //    scroll( 1.0f - maxY );
    //}
    if( distanceFromBottom() > 0.0f )
    {
        scroll( -distanceFromBottom() );
    }
}

float ScrollView::distanceFromBottom()
{
    return top + height - 1.0f;
}

float ScrollView::distanceFromTop()
{
    return top;
}

void ScrollView::setScrollAmount( float i_amt )
{
    scrollAmount = i_amt;
}

void ScrollView::setTop( float i_top )
{
    top = i_top;
}

void ScrollView::setHeight( float i_height )
{
    height = i_height;
}

////////////////////////////////////////////
///////////////// ListView /////////////////
////////////////////////////////////////////
ListView::ListView( int i_rows ) :
    cellHeight( 0.0f ),
    gridThickness( 1 ),
    gridColour( 0, 0, 0 ),
    children( i_rows ),
    rows( i_rows )
{
    viewType = eListView;

    if( rows > 0 )
    {
        cellHeight = 1.0f / ( float )rows;
    }

    for( int i = 0; i < rows; i++ )
    {
        children[i] = new ViewProxy();
        children[i]->x = 0.0f;
        children[i]->y = ( 1.0f / ( float )rows ) * ( float )i;
        children[i]->width = 1.0f;
        children[i]->height = 1.0f / ( float )rows;
    }
}

ListView::ListView() :
    ListView( 0 )
{
}

ListView::~ListView()
{
    //for( ViewProxy* child : children )
    //{
    //    if( child != NULL )
    //    {
    //        if( child->view != NULL )
    //        {
    //            delete child->view;
    //        }
    //
    //        delete child;
    //    }
    //}
}

void ListView::drawOverlay( cv::Mat& img )
{
    //cv::Mat roi = cv::Mat( img, *this & cv::Rect( 0, 0, img.cols, img.rows ) );

    // --- Draw grid
    if( gridColour != CV_TRANSPARENT )
    {
        float p_y = 0;

        for( size_t i = 0; i < children.size() + 1; i++ )
        {
            cv::line( img, cv::Point( 0, ( int )p_y ), cv::Point( img.cols - 1, ( int )p_y ), gridColour, gridThickness );
            p_y += cellHeight;
        }
    }

    // --- Draw border
    if( borderColour != CV_TRANSPARENT )
    {
        rectangle( img, cv::Point( 0, 0 ), cv::Point( img.cols - 1, img.rows - 1 ), borderColour, borderWidth );
    }
}

///**
//* Overrides View::addChildView(int i_x, int i_y, View& childView) to
//* disallow child views from being added other than in list fashion;
//*/
//void ListView::addChildView( int i_x, int i_y, View& childView )
//{
//    i_x;
//    i_y;
//    addChildView( childView );
//}

/**
* Appends the given view to the bottom of the list of child views.
*/
void ListView::addChildView( View* childView )
{
    //if( children.size() == 0 && cellHeight == 0 && childView->getHeight() != 0 )
    //{
    //    cellHeight = childView->getHeight();
    //}
    //
    //int w = childView->getWidth();
    //int h = childView->getHeight();
    ////if( children.size() != 0 )
    ////{
    ////    childView.setY( children[children.size() - 1]->getY() + children[children.size() - 1]->getHeight() );
    ////}
    ////else
    ////{
    ////    childView.setY( 0 );
    ////}
    //childView->resize( width, cellHeight );
    //childView->setX( 0 );
    //childView->setY( cellHeight * children.size() );
    //childView->setParent( *this );
    //children.push_back( childView );
    //resize();
    ////if( childView.getY() + childView.getHeight() > height )
    ////{
    ////    height = childView.getY() + childView.getHeight();
    ////}
    ViewProxy* child = new ViewProxy();

    if( rows > 0 )
    {
        child->y = children[rows - 1]->y + cellHeight;
    }
    else
    {
        child->y = 0.0f;
    }

    child->x = 0.0f;
    child->width = 1.0f;
    child->height = cellHeight;
    child->view = childView;
    childView->setParent( *this );
    children.push_back( child );
    rows++;
}

void ListView::insert( int row, View* childView )
{
    if( row < 0 )
    {
        row += rows;
    }

    if( row < 0 || row > rows )
    {
        delete childView;
        return;
    }

    if( children[row]->view != NULL )
    {
        delete children[row]->view;
    }

    childView->setParent( *this );
    children[row]->view = childView;
}

/**
* Sets new dimensions for this view. Also adjusts width and height
* of each cell.
*/
//void ListView::resize( float i_width, float i_height )
//{
//    width *= i_width;
//    height *= i_height;
//  cellHeight = height / rows;
//    updateCells();
//}

/**
* Resizes this ListView to fit around its cells.
*/
//void ListView::resize()
//{
//    //if( children.size() > 0 )
//    //{
//    //    width = children[0]->getWidth();
//    //}
//    rows = children.size();
//    height = cellHeight * rows;
//}

std::vector<ViewProxy*> ListView::getProxies()
{
    return children;
}

std::vector<View*> ListView::getChildren()
{
    std::vector<View*> childViews;

    for( ViewProxy* child : children )
    {
        if( child != NULL )
        {
            childViews.push_back( child->view );
        }
    }

    return childViews;
}

ViewProxy* ListView::getChildPos( View* childView )
{
    cv::Rect_<float> pos;

    for( ViewProxy* child : children )
    {
        if( child->view == childView )
        {
            return child;
        }
    }

    return NULL;
}

void ListView::fitCells()
{
    cellHeight = 1.0f / ( float )rows;
    updateCells();
}

void ListView::updateCells( int startIndex )
{
    if( startIndex <= 0 )
    {
        assert( 0 );
    }

    float _y = children[startIndex - 1]->y + cellHeight;

    for( size_t i = startIndex; i < children.size(); i++ )
    {
        if( i > 0 )
        {
            _y = children[i - 1]->y + cellHeight;
        }

        children[i]->height = cellHeight;
        children[i]->y  = _y;
    }
}

void ListView::setCellHeight( float i_height )
{
    cellHeight = i_height;
}

void ListView::setGridThickness( unsigned int thickness )
{
    gridThickness = ( int )thickness;
}

void ListView::setGridColour( int b, int g, int r )
{
    gridColour = cv::Scalar( b, g, r );
}

////////////////////////////////////////////
///////////////// GridView /////////////////
////////////////////////////////////////////
GridView::GridView( int i_cols, int i_rows ) :
    //children( i_rows, std::vector<View * >( i_cols, NULL ) ),
    children( i_rows, std::vector<ViewProxy * >( i_cols ) ),
    defaultCellWidth( 0 ),
    defaultCellHeight( 0 ),
    rows( i_rows ),
    cols( i_cols ),
    gridThickness( 1 ),
    gridColour( 0, 0, 0 )
{
    viewType = eGridView;

    if( i_cols != 0 )
    {
        cellWidths.assign( i_cols, 1.0f / ( float )i_cols );
        defaultCellWidth = 1.0f / ( float )i_cols;
    }

    if( i_rows != 0 )
    {
        cellHeights.assign( i_rows, 1.0f / ( float )i_rows );
        defaultCellHeight = 1.0f / ( float )i_rows;
        setScrollAmount( defaultCellHeight );
    }

    for( int i = 0; i < rows; i++ )
    {
        for( int j = 0; j < cols; j++ )
        {
            children[i][j] = new ViewProxy();
            children[i][j]->x = ( 1.0f / ( float )cols ) * ( float )j;
            children[i][j]->y = ( 1.0f / ( float )rows ) * ( float )i;
            children[i][j]->width = 1.0f / ( float )cols;
            children[i][j]->height = 1.0f / ( float )rows;
        }
    }
}

GridView::GridView() :
    GridView( 0, 0 )
{
}

GridView::~GridView()
{
    //for( int i = 0; i < rows; i++ )
    //{
    //    for( int j = 0; j < cols; j++ )
    //    {
    //        ViewProxy* child = children[i][j];
    //
    //        if( child != NULL )
    //        {
    //            if( child->view != NULL )
    //            {
    //                delete child->view;
    //            }
    //
    //            delete child;
    //        }
    //    }
    //}
}

//void GridView::refreshChildren( cv::Mat& img )
//{
//    for( int i = 0; i < rows; i++ )
//    {
//        for( int j = 0; j < cols; j++ )
//        {
//            View* child = children[i][j];
//
//            if( child != NULL && isInView( *child ) )
//            {
//                child->refresh( cv::Mat( img, *this & cv::Rect( 0, 0, img.cols, img.rows ) ) );
//            }
//        }
//    }
//}

void GridView::drawOverlay( cv::Mat& img )
{
    //cv::Mat roi = cv::Mat( img, *this & cv::Rect( 0, 0, img.cols, img.rows ) );

    // --- Draw grid
    if( gridColour != CV_TRANSPARENT )
    {
        float p_x = 0.0f;
        float p_y = 0.0f;
        cv::line( img, cv::Point( ( int )p_x, 0 ), cv::Point( ( int )p_x, img.rows - 1 ), gridColour, gridThickness );

        for( int i = 0; i < cols; i++ )
        {
            p_x += cellWidths[i];
            cv::line( img, cv::Point( ( int )p_x, 0 ), cv::Point( ( int )p_x, img.rows - 1 ), gridColour, gridThickness );
        }

        cv::line( img, cv::Point( 0, ( int )p_y ), cv::Point( img.cols - 1, ( int )p_y ), gridColour, gridThickness );

        for( int i = 0; i < rows; i++ )
        {
            p_y += cellHeights[i];
            cv::line( img, cv::Point( 0, ( int )p_y ), cv::Point( img.cols - 1, ( int )p_y ), gridColour, gridThickness );
        }
    }

    // --- Draw border
    if( borderColour != CV_TRANSPARENT )
    {
        rectangle( img, cv::Point( 0, 0 ), cv::Point( img.cols - 1, img.rows - 1 ), borderColour, borderWidth );
    }
}

void GridView::insert( int row, int col, View* childView )
{
    if( col < 0 )
    {
        col += children[0].size();
    }

    if( row < 0 )
    {
        row += children.size();
    }

    if( col < 0 || col >= ( int )children[0].size() || row < 0 || row >= ( int )children.size() )
    {
        delete childView;
        return;
    }

    if( children[row][col]->view != NULL )
    {
        delete children[row][col]->view;
    }

    //ViewProxy child;
    //
    //if( col > 0 )
    //{
    //    child.x = children[row][col - 1].x + children[row][col - 1].width ;
    //}
    //else
    //{
    //    int _x = 0;
    //
    //    for( int i = 0; i < col; i++ )
    //    {
    //        _x += cellWidths[i];
    //    }
    //
    //    child.x = _x;
    //}
    //
    //if( row > 0  )
    //{
    //    child.y = children[row - 1][col].y + children[row - 1][col].height ;
    //}
    //else
    //{
    //    int _y = 0;
    //
    //    for( int i = 0; i < row; i++ )
    //    {
    //        _y += cellHeights[i];
    //    }
    //
    //  child.y = _y;
    //}
    //childView->resize( cellWidths[col], cellHeights[row] );
    childView->setParent( *this );
    children[row][col]->view = childView;
}

//void GridView::addChildView( int col, int row, View& childView )
//{
//  if (col >= cols || row >= rows || children[row][col] != NULL)
//  {
//      delete &childView;
//      return;
//  }
//      childView.setWidth(cellWidths[col]);
//
//      childView.setHeight(cellHeights[row]);
//
//        childView.setX(children[row][col - 1]->x + children[row][col - 1]->getWidth());
//        childView.setY(children[row - 1][col]->getY() + children[row - 1][col]->getHeight());
//        children[row][col] = &childView;
//
//      for (View* child : children[rows - 1])
//      {
//          if (childView.getY() + childView.getHeight() > height)
//          {
//              height = childView.getY() + childView.getHeight();
//          }
//      }
//
//      for (View* child : children[cols - 1])
//      {
//          if (childView.x + childView.getWidth() > width)
//          {
//              width = childView.x + childView.getWidth();
//          }
//      }
//}

//void GridView::addChildView( View& childView )
//{
//    delete &childView;
//}

//void GridView::resize(float i_width, float i_height )
//{
//    width *= i_width;
//    height *= i_height;
//}

void GridView::fitCells()
{
    //int sumX = 0, sumY = 0;
    //
    //for( int i = 0; i < cellWidths.size(); i++ )
    //{
    //    sumX += cellWidths[i];
    //}
    //
    //for( int i = 0; i < cellHeights.size(); i++ )
    //{
    //    sumY += cellHeights[i];
    //}
    float sumX = 0.0f;
    float sumY = 0.0f;

    for( int i = 0; i < cols; i++ )
    {
        sumX += cellWidths[i];
    }

    for( int i = 0; i < cols; i++ )
    {
        cellWidths[i] /= sumX;;
    }

    for( int i = 0; i < rows; i++ )
    {
        sumY += cellHeights[i];
    }

    for( int i = 0; i < rows; i++ )
    {
        cellHeights[i] /= sumY;
    }

    updateCells();
    setTop( 0.0f );
    setHeight( rows == 0 ? 0.0f : 1.0f );
}

std::vector<View*> GridView::getChildren()
{
    //std::vector<View*> vecChildren = std::vector<View*>( children.size() * children[0].size(), NULL );
    std::vector<View*> childViews;

    for( int i = 0; i < rows; i++ )
    {
        for( int j = 0; j < cols; j++ )
        {
            if( children[i][j]->view != NULL )
            {
                childViews.push_back( children[i][j]->view );
            }
        }
    }

    return childViews;
}

std::vector<ViewProxy*> GridView::getProxies()
{
    //std::vector<View*> vecChildren = std::vector<View*>( children.size() * children[0].size(), NULL );
    std::vector<ViewProxy*> childProxies;

    for( int i = 0; i < rows; i++ )
    {
        for( int j = 0; j < cols; j++ )
        {
            childProxies.push_back( children[i][j] );
        }
    }

    return childProxies;
}

/**
* Not efficient!
*/
ViewProxy* GridView::getChildPos( View* childView )
{
    cv::Rect_<float> pos;

    for( int i = 0; i < rows; i++ )
    {
        for( int j = 0; j < cols; j++ )
        {
            if( children[i][j]->view == childView )
            {
                return children[i][j];
            }
        }
    }

    return NULL;
}

//void GridView::scroll( int dy )
//{
//    for( int i = 0; i < rows; i++ )
//    {
//        for( int j = 0; j < cols; j++ )
//        {
//            View* child = children[i][j];
//
//            if( child != NULL )
//            {
//                child->setY( child->getY() + dy );
//            }
//        }
//    }
//}
//
//void GridView::scrollToBottom()
//{
//    View* child = NULL;
//    int i = rows - 1, j = cols - 1;
//    int maxY = 0;
//
//    while( child == NULL && i >= 0 && j >= 0 )
//    {
//        child = children[ i][j];
//        i--;
//        j--;
//    }
//
//    if( child != NULL )
//    {
//        maxY = child->getY();
//    }
//
//    for( ; i < rows; i++ )
//    {
//        maxY += cellHeights[i];
//    }
//
//    if( maxY > height )
//    {
//        scroll( height - maxY );
//    }
//}

void GridView::clearCells()
{
    for( int i = 0; i < rows; i++ )
    {
        for( int j = 0; j < cols; j++ )
        {
            ViewProxy* child = children[i][j];

            if( child != NULL )
            {
                if( child->view != NULL )
                {
                    delete child->view;
                }

                delete child;
            }
        }

        children[i].clear();
    }

    children.clear();
    cellHeights.clear();
    rows = 0;
    setTop( 0.0f );
    setHeight( 0.0f );
}

void GridView::updateCells( int startRow, int startCol )
{
    float _y = 0.0f;

    for( size_t i = startRow; i < children.size(); i++ )
    {
        float _x = 0.0f;

        if( i > 0 )
        {
            _y = children[i - 1][0]->y + cellHeights[i - 1];
        }

        for( size_t j = startCol; j < children[0].size(); j++ )
        {
            if( j > 0 )
            {
                _x = children[i][j - 1]->x + cellWidths[j - 1];
            }

            children[i][j]->x = _x;
            children[i][j]->y = _y;
            children[i][j]->width = cellWidths[j];
            children[i][j]->height = cellHeights[i];
        }
    }
}

void GridView::addRow( float rowHeight )
{
    children.push_back( std::vector<ViewProxy*>( cols ) );

    // --- Check for error
    if( rows != ( int )children.size() - 1 )
    {
        return;
    }

    if( rows != 0 )
    {
        for( int i = 0; i < cols; i++ )
        {
            ViewProxy* child = new ViewProxy();
            child->x = children[rows - 1][i]->x;
            child->width = cellWidths[i];
            child->y = children[rows - 1][i]->y + children[rows - 1][i]->height;
            child->height = rowHeight;
            children[rows][i] = child;
        }
    }
    else
    {
        float _x = 0.0f;

        for( int i = 0; i < cols; i++ )
        {
            ViewProxy* child = new ViewProxy();
            child->x = _x;
            child->width = cellWidths[i];
            child->y = 0.0f;
            child->height = rowHeight;
            _x += cellWidths[i];
            children[rows][i] = child;
        }
    }

    cellHeights.push_back( rowHeight );
    rows++;
    setHeight( height + rowHeight );
    //height += rowHeight;
}

void GridView::addRow( )
{
    addRow( defaultCellHeight );
}

void GridView::deleteRow( int row )
{
    std::vector<std::vector<ViewProxy*>>::iterator it = children.begin();
    std::advance( it, row );
    children.erase( it );
}

//bool GridView::isChildInView( int row, int col )
//{
//    //cv::Rect roi = *this & *children[row][col];
//    //return roi.width > 0 && roi.height > 0;
//}

//void GridView::addCol( View* childView, int colWidth )
//{
//    cellWidths.push_back( colWidth );
//
//    for( int i = 0; i < rows; i++ )
//    {
//        children[i].push_back( &childView[i] );
//    }
//
//    //if( width < children[0][cols]->x + children[0][cols]->getWidth() )
//    //{
//    //    width = children[0][cols]->x + children[0][cols]->getWidth();
//    //}
//    cols++;
//}

//void GridView::addCol( View* childView )
//{
//    addCol( childView, cellWidths[cols - 1] );
//}

View* GridView::getCell( int row, int col )
{
    return children[row][col]->view;
}

std::vector<View*> GridView::getRow( int row )
{
    std::vector<View*> childViews = std::vector<View*>( rows );

    for( int i = 0; i < cols; i++ )
    {
        childViews[i] = children[row][i]->view;
    }

    return childViews;
}

std::vector<View*> GridView::getCol( int col )
{
    std::vector<View*> childViews = std::vector<View*>( rows );

    for( int i = 0; i < rows; i++ )
    {
        childViews[i] = children[i][col]->view;
    }

    return childViews;
}

void GridView::setRowHeight( float i_height )
{
    for( size_t i = 0; i < ( int )cellHeights.size(); i++ )
    {
        cellHeights[i] = i_height;
    }

    defaultCellHeight = i_height;
    setScrollAmount( defaultCellHeight );
    setHeight( i_height * rows );
}

void GridView::setRowHeight( int index, float i_height )
{
    if( index < 0 )
    {
        index += rows;
    }

    if( index < 0 || index >= ( int )cellHeights.size() )
    {
        return;
    }

    setHeight( height - cellHeights[index] + i_height );
    cellHeights[index] = i_height;
}

void GridView::setColWidth( float i_width )
{
    for( size_t i = 0; i < cellWidths.size(); i++ )
    {
        cellWidths[i] = i_width;
    }

    defaultCellWidth = i_width;
}

void GridView::setColWidth( int index, float i_width )
{
    if( index < 0 )
    {
        index += cols;
    }

    if( index < 0 || index >= ( int )cellWidths.size() )
    {
        return;
    }

    cellWidths[index] = i_width;
}

void GridView::setGridThickness( unsigned int thickness )
{
    gridThickness = ( int )thickness;
}

void GridView::setGridColour( int b, int g, int r )
{
    gridColour = cv::Scalar( b, g, r );
}

////////////////////////////////////////////
////////////////// GridView2 ///////////////
////////////////////////////////////////////

cv::GridView2::GridView2( int rows, int cols ) :
    m_children( rows, std::vector<ViewProxy * >( cols ) ),
    m_rows( rows ),
    m_cols( cols )
{
    viewType = eGridView2;

    for( int i = 0; i < rows; i++ )
    {
        for( int j = 0; j < cols; j++ )
        {
            m_children[i][j] = NULL;
        }
    }
}

cv::GridView2::GridView2() :
    GridView2( 0, 0 )
{
}

cv::GridView2::~GridView2()
{
}

std::vector<View*> cv::GridView2::getChildren()
{
    std::vector<View*> childViews;

    for( int i = 0; i < m_rows; i++ )
    {
        for( int j = 0; j < m_cols; j++ )
        {
            if( m_children[i][j] != NULL && m_children[i][j]->view != NULL )
            {
                childViews.push_back( m_children[i][j]->view );
            }
        }
    }

    return childViews;
}

std::vector<ViewProxy*> cv::GridView2::getProxies()
{
    std::vector<ViewProxy*> childProxies;

    for( int i = 0; i < m_rows; i++ )
    {
        for( int j = 0; j < m_cols; j++ )
        {
            if( m_children[i][j] != NULL )
            {
                childProxies.push_back( m_children[i][j] );
            }
        }
    }

    return childProxies;
}

ViewProxy* cv::GridView2::getChildPos( View* childView )
{
    cv::Rect_<float> pos;

    for( int i = 0; i < m_rows; i++ )
    {
        for( int j = 0; j < m_cols; j++ )
        {
            if( m_children[i][j] != NULL && m_children[i][j]->view == childView )
            {
                return m_children[i][j];
            }
        }
    }

    return NULL;
}

void cv::GridView2::insert( int row, int col, View* childView )
{
    if( col < 0 || row < 0 )
    {
        return;
    }

    // --- Increase grid size if out of bounds
    if( col >= m_cols || row >= m_rows )
    {
        if( col >= m_cols )
        {
            setNumCols( col + 1 );
        }

        if( row >= m_rows )
        {
            setNumRows( row + 1 );
        }

        for( int i = 0; i < m_rows; i++ )
        {
            for( int j = 0; j < m_cols; j++ )
            {
                if( m_children[i][j] != NULL )
                {
                    ViewProxy* proxy = m_children[i][j];
                    proxy->x = ( 1.0f / ( float )m_cols ) * ( float )j;
                    proxy->y = ( 1.0f / ( float )m_rows ) * ( float )i;
                    proxy->width = 1.0f / ( float )m_cols;
                    proxy->height = 1.0f / ( float )m_rows;
                }
            }
        }
    }

    // --- Delete child if exists
    if( m_children[row][col] != NULL )
    {
        if( m_children[row][col]->view != NULL )
        {
            delete m_children[row][col]->view;
        }

        delete m_children[row][col];
    }

    // --- Add new child and proxy
    ViewProxy* proxy = new ViewProxy();
    proxy->x = ( 1.0f / ( float )m_cols ) * ( float )col;
    proxy->y = ( 1.0f / ( float )m_rows ) * ( float )row;
    proxy->width = 1.0f / ( float )m_cols;
    proxy->height = 1.0f / ( float )m_rows;
    proxy->view = childView;
    childView->setParent( *this );
    m_children[row][col] = proxy;
    //
    // --- Request refresh
    requestRefresh();
}

void cv::GridView2::setNumRows( int numRows )
{
    m_children.resize( numRows, std::vector<ViewProxy*>( m_cols ) );
    m_rows = numRows;
}

void cv::GridView2::setNumCols( int numCols )
{
    for( int i = 0; i < m_rows; i++ )
    {
        m_children[i].resize( numCols );
    }

    m_cols = numCols;
}

////////////////////////////////////////////
//////////////// ButtonView ////////////////
////////////////////////////////////////////

template <class CallBackType>
ButtonView<CallBackType>::ButtonView()
{
    viewType = eButtonView;
}

template <class CallBackType>
ButtonView<CallBackType>::~ButtonView()
{
}

template <class CallBackType>
void ButtonView<CallBackType>::addListener( void ( CallBackType::* listener )( MouseEvent, float, float ) )
{
    listeners.push_back( listener );
}

template <class CallBackType>
std::vector<View*> ButtonView<CallBackType>::getChildren()
{
    return std::vector<View*>( 0 );
}

template <class CallBackType>
std::vector<ViewProxy*> ButtonView<CallBackType>::getProxies()
{
    return std::vector<ViewProxy*>( 0 );
}

template <class CallBackType>
ViewProxy* ButtonView<CallBackType>::getChildPos( View* childView )
{
    return NULL;
}

/*
* Process mouse event by calling listeners when mouse is left-clicked.
* No further children will process the mouse event.
*/
template <class CallBackType>
void ButtonView<CallBackType>::processMouseEvent( MouseEvent e, float i_x, float i_y )
{
    if( i_x < 0.0f || i_x > 1.0f || i_y < 0.0f || i_y > 1.0f )
    {
        return;
    }

    if( e.op == LeftClick )
    {
        for( void ( CallBackType::* listener )( float, float ) : listeners )
        {
            pObj->*listener( e, i_x, i_y );
        }
    }
}

////////////////////////////////////////////
////////////////// Window //////////////////
////////////////////////////////////////////

/**
* Constructor.
*
* @param i_width number of columns
* @param i_height number of rows
* @param i_type type of data stored in Mat
* @param i_name name of this window
*/
Window::Window( std::string i_name , int i_width, int i_height, int i_type ) :
    m_mat( i_height, i_width, i_type ),
    name( i_name ),
    m_colour( 255, 255, 255 )
{
    m_mat.setTo( m_colour );
}

/**
* Constructor.
*
* @param i_mat input matrix
* @param i_name name of this window
*/
Window::Window( std::string i_name, cv::Mat i_mat ) :
    m_mat( i_mat ),
    name( i_name )
{
}

/**
* Constructor.
*
* @param i_name name of this window
*/
Window::Window( std::string i_name ) :
    name( i_name )
{
}

/**
* Constructor.
*/
Window::Window() :
    name( "CV Window" )
{
}

/**
* Destructor.
*/
Window::~Window()
{
    for( ViewProxy* viewProxy : m_views )
    {
        if( viewProxy != NULL )
        {
            if( viewProxy->view != NULL )
            {
                viewProxy->view->Uninit();
                delete viewProxy->view;
                viewProxy->view = NULL;
            }

            delete viewProxy;
            viewProxy = NULL;
        }
    }
}

/**
* Refresh this window along with any views inside of it.
*/
void Window::refresh()
{
    //if (colour != CV_TRANSPARENT)
    //{
    //  setTo(colour);
    //}
    for( ViewProxy* viewProxy : m_views )
    {
        if( viewProxy->view != NULL && isViewInWindow( viewProxy ) )
        {
            viewProxy->refreshView( m_mat );
            //cv::Rect viewRect = cv::Rect( viewProxy->x * cols, viewProxy->y * rows, viewProxy->width * cols, viewProxy->height * rows );
            //cv::Mat viewMat = cv::Mat( *this, viewRect & cv::Rect( 0, 0, cols, rows ) );
            //cv::copyMakeBorder( viewMat, viewMat, max( 0, -viewRect.y ), max( 0, viewRect.y + viewRect.height - rows ), max( 0, -viewRect.x ), max( 0, viewRect.x + viewRect.width - cols ), BORDER_CONSTANT );
            //viewProxy->view->refresh( cv::Mat( *this, viewRect & cv::Rect( 0, 0, cols, rows ) ) );
            //viewProxy->view->refresh( viewMat );
        }
    }
}

/**
* Process a mouse event.
*
* @param e the mouse event
* @param i_x x pixel relative to this window of the mouse event
* @param i_y y pixel relative to this window of the mouse event
*/
void Window::processMouseEvent( MouseEvent e, int i_x, int i_y )
{
    if( i_x < 0 || i_x > m_mat.cols || i_y < 0 || i_y > m_mat.rows )
    {
        return;
    }

    for( ViewProxy* viewProxy : m_views )
    {
        if( viewProxy->view != NULL && isViewInWindow( viewProxy ) )
        {
            cv::Rect viewRect = cv::Rect( ( int )( viewProxy->x * m_mat.cols ), ( int )( viewProxy->y * m_mat.rows ), ( int )( viewProxy->width * m_mat.cols ), ( int )( viewProxy->height * m_mat.rows ) );

            if( viewRect.contains( cv::Point( i_x, i_y ) ) )
            {
                float rel_x = ( float )( i_x - viewRect.x ) / ( float )viewRect.width;
                float rel_y = ( float )( i_y - viewRect.y ) / ( float )viewRect.height;
                viewProxy->view->processMouseEvent( e, rel_x, rel_y );
            }
        }
    }
}

/**
* Show this window.
*/
void Window::show()
{
    if( m_mat.data != NULL )
    {
        cv::imshow( name, m_mat );
    }
}

/**
* Add a view to this window. If the view does not have a size, this
* will set its size to fill the rest of the window.
*
* @param i_x the X-position of the top-left corner of the added view
* @param i_y the Y-position of the top-left corner of the added view
* @param view the view to be added
*/
void Window::addView( View* view, float i_x, float i_y, float i_width, float i_height )
{
    //float width = view->getWidth() / cols;
    //float height = view->getHeight() / rows;
    //
    //if( width == 0.0f )
    //{
    //    width = 1.0 - i_xPos;
    //}
    //
    //if( height == 0.0f )
    //{
    //    height = 1.0f- i_yPos;
    //}
    //
    //view->resize( width, height );
    //view->setX(i_xPos * width);
    //view->setY(i_yPos * height);
    //views.push_back( view );
    if( i_width == 0.0f )
    {
        i_width = 1.0f - i_x;
    }

    if( i_height == 0.0f )
    {
        i_height = 1.0f - i_y;
    }

    ViewProxy* viewProxy = new ViewProxy( i_x, i_y, i_width, i_height );
    viewProxy->view = view;
    m_views.push_back( viewProxy );
}

/**
* Shorthand for addView(int i_x, int i_y, View& view).
*/
void Window::addView( View* view )
{
    addView( view, 0.0f, 0.0f, 0.0f, 0.0f );
}

/**
* Return whether the view is actually inside this window.
*
* @param view view to check
*/
bool Window::isViewInWindow( const ViewProxy* view )
{
    if( view->x + view->width <= 0.0f )
    {
        return false;
    }
    else if( view->x >= 1.0f )
    {
        return false;
    }
    else if( view->y + view->height <= 0.0f )
    {
        return false;
    }
    else if( view->y >= 1.0f )
    {
        return false;
    }
    else
    {
        return true;
    }
}

void cv::Window::resize( int i_width, int i_height )
{
    //cv::Mat::assignTo( cv::Mat( i_height, i_width, cv::Mat::type() ) );
    m_mat = cv::Mat( i_height, i_width, m_mat.type() );
}

/**
* Set the colour of the inside of this window (BGR).
*
* @param b blue component
* @param g green component
* @param r red component
*/
void Window::setColour( int b, int g, int r )
{
    m_colour = Scalar( b, g, r );
}

/**
* Set the colour of the inside of this window.
*
* @param i_colour colour
*/
void Window::setColour( cv::Scalar i_colour )
{
    m_colour = i_colour;
}

cv::Size cv::Window::getSize()
{
    return m_mat.size();
}

std::vector<View*> cv::Window::getViews()
{
    std::vector<View*> viewArr;

    for( ViewProxy* viewProxy : m_views )
    {
        viewArr.push_back( viewProxy->view );
    }

    return viewArr;
}

////////////////////////////////////////////
////////////////// ImageView ///////////////
////////////////////////////////////////////

cv::ImageView::ImageView( cv::Mat img ) :
    mat( img )
{
    viewType = eImageView;
    borderColour = CV_TRANSPARENT;
}

cv::ImageView::ImageView()
{
    viewType = eImageView;
    borderColour = CV_TRANSPARENT;
}

cv::ImageView::~ImageView()
{
}

void cv::ImageView::drawView( cv::Mat& img )
{
    if( mat.data == NULL )
    {
        return;
    }

    //if (mat.data == img.data && mat.cols == img.cols && mat.rows == img.rows && mat.step == img.step && mat.type() == img.type())
    //{
    //  return;
    //}
    cv::Mat out = mat;

    if( img.size() != mat.size() )
    {
        cv::resize( mat, out, cv::Size( img.cols, img.rows ) );
    }

    out.copyTo( img );
}

cv::Mat& cv::ImageView::getMat()
{
    return mat;
}

void cv::ImageView::resize( int i_width, int i_height )
{
    //mat.assignTo(cv::Mat(i_height, i_width, mat.type()));
    //cv::resize(mat, mat, cv::Size(i_width, i_height));
    mat = cv::Mat( i_height, i_width, mat.type() );
}

#endif // !WINDOWS_DEBUGGING
