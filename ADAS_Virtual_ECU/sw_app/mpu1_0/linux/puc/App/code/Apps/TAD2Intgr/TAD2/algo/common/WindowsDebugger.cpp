// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [01-Aug-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "WindowsDebugger.h"
#include "MemoryPool.h"
#include "ImageProcessing.h"

#ifdef WINDOWS_DEBUGGING

db::WindowsDebugger::WindowsDebugger()
{
    m_pWindowManager = new WindowManager();
}

db::WindowsDebugger::~WindowsDebugger()
{
    delete m_pWindowManager;
}

void db::WindowsDebugger::Run( int frameNum )
{
    m_pWindowManager->Run( frameNum );
}

void db::WindowsDebugger::Reset()
{
    m_pWindowManager->Reset();
}

void db::WindowsDebugger::SetDebugLevel( int level )
{
    m_pWindowManager->SetDebugLevel( level );
}

void db::WindowsDebugger::SetCategoryLevel( const char* category, int level )
{
    m_pWindowManager->SetCategoryLevel( category, level );
}

void db::WindowsDebugger::EnableWindow( const char* winname )
{
    m_pWindowManager->EnableWindow( winname );
}

void db::WindowsDebugger::DisableWindow( const char* winname )
{
    m_pWindowManager->DisableWindow( winname );
}

void db::WindowsDebugger::CreateNewWindow( const char* winname, int width, int height )
{
    if( m_pWindowManager->IsEnabled( winname ) )
    {
        if( !m_pWindowManager->DoesWindowExist( winname ) )
        {
            cv::Window* pWindow = new cv::Window( winname, width, height, CV_8UC3 );
            cv::GridView2* pView = new cv::GridView2();
            pWindow->addView( pView );
            m_pWindowManager->AddWindow( winname, pWindow );
            m_pWindowManager->AddView( winname, pView );
        }
    }
}

void db::WindowsDebugger::CreateView( const char* viewname, int width, int height )
{
    if( m_pWindowManager->IsEnabled( viewname ) )
    {
        if( !m_pWindowManager->DoesViewExist( viewname ) )
        {
            cv::ImageView* pView = new cv::ImageView( cv::Mat( height, width, CV_8UC3 ) );
            m_pWindowManager->AddView( viewname, pView );
        }
    }
}

void db::WindowsDebugger::AddViewToWindow( const char* winname, const char* viewname, int row, int col )
{
    if( m_pWindowManager->IsEnabled( winname ) )
    {
        cv::View* pView = m_pWindowManager->GetView( viewname );

        if( pView == NULL )
        {
            return;
        }

        if( !m_pWindowManager->DoesWindowExist( winname ) )
        {
            CreateNewWindow( winname );
        }

        if( !m_pWindowManager->DoesViewExist( winname ) )
        {
            return;
        }

        //cv::Window* pWindow = m_pWindowManager->GetWindow( winname );
        cv::View* pWindowIView = m_pWindowManager->GetView( winname );

        if( pWindowIView->getViewType() != cv::eGridView2 )
        {
            return;
        }

        cv::GridView2* pWindowView = ( cv::GridView2* )pWindowIView;

        if( pWindowView->getChildPos( pView ) != NULL )
        {
            return;
        }

        m_pWindowManager->RemoveWindow( viewname );
        pWindowView->insert( row, col, pView );
        pView->setBorderColour( 255, 255, 255 );
    }
}

void* db::WindowsDebugger::GetHandle( const char* winname )
{
    if( !m_pWindowManager->IsEnabled( winname ) )
    {
        return nullptr;
    }

    cv::View* pView = m_pWindowManager->GetView( winname );

    if( pView->getViewType() == cv::eImageView )
    {
        return &( ( cv::ImageView* )( pView ) )->getMat();
    }
    else
    {
        return pView;
    }
}

void db::WindowsDebugger::Line( const char* winname, Point2i p1, Point2i p2, db::Colour colour, int thickness )
{
    if( !m_pWindowManager->IsEnabled( winname ) )
    {
        return;
    }

    cv::ImageView* pView = getImageView( winname );
    cv::line( pView->getMat(), cv::Point( p1.x, p1.y ), cv::Point( p2.x, p2.y ), cvColour( colour ), thickness );
    pView->invalidate();
    pView->requestRefresh();
}

void db::WindowsDebugger::Circle( const char* winname, db::Point centre, int radius, db::Colour colour, int thickness )
{
    if( !m_pWindowManager->IsEnabled( winname ) )
    {
        return;
    }

    cv::ImageView* pView = getImageView( winname );
    cv::circle( pView->getMat(), cvPoint( centre ), radius, cvColour( colour ), thickness );
    pView->invalidate();
    pView->requestRefresh();
}

void db::WindowsDebugger::Rect( const char* winname, _roi::ROI roi, db::Colour colour, int thickness )
{
    if( m_pWindowManager->IsEnabled( winname ) )
    {
        cv::ImageView* pView = getImageView( winname );
        cv::Rect rect = cv::Rect( roi.getX(), roi.getY(), roi.getWidth(), roi.getHeight() );
        cv::rectangle( pView->getMat(), rect, cvColour( colour ), thickness );
        pView->invalidate();
        pView->requestRefresh();
    }
}

void db::WindowsDebugger::Plot( const char* winname, double val, db::Colour colour, int shift )
{
    if( m_pWindowManager->IsEnabled( winname ) )
    {
        //if (!m_pWindowManager->DoesPlotterExist(winname))
        //{
        //  cv::Window* pWindow = new cv::Window(winname, 640, 400, CV_8UC3);
        //  cv::ImageView* pView = new cv::ImageView();
        //  Plotter* pPlotter = new Plotter(winname, pView->getMat());
        //  pWindow->addView(pView);
        //  m_pWindowManager->AddWindow(winname, pWindow);
        //  m_pWindowManager->AddView(winname, pView);
        //  m_pWindowManager->AddPlotter(winname, pPlotter);
        //}
        getPlotter( winname )->plot( val, colour, shift );
        cv::ImageView* pView = getImageView( winname );
        pView->invalidate();
        pView->requestRefresh();
    }
}

void db::WindowsDebugger::Plot( const char* winname, double x, double y, db::Colour colour, int shift )
{
    if( m_pWindowManager->IsEnabled( winname ) )
    {
        getPlotter( winname )->plot( x, y, colour, shift );
        cv::ImageView* pView = getImageView( winname );
        pView->invalidate();
        pView->requestRefresh();
    }
}

void db::WindowsDebugger::ClearPlot( const char* winname )
{
    if( m_pWindowManager->IsEnabled( winname ) )
    {
        getPlotter( winname )->clear();
    }
}

void db::WindowsDebugger::ResetPlot( const char* winname )
{
    if( m_pWindowManager->IsEnabled( winname ) )
    {
        getPlotter( winname )->reset();
    }
}

void db::WindowsDebugger::SetPlotXLim( const char* winname, double low, double high )
{
    if( m_pWindowManager->IsEnabled( winname ) )
    {
        getPlotter( winname )->setXLim( low, high );
    }
}

void db::WindowsDebugger::SetPlotYLim( const char* winname, double low, double high )
{
    if( m_pWindowManager->IsEnabled( winname ) )
    {
        getPlotter( winname )->setYLim( low, high );
    }
}

void db::WindowsDebugger::SetPlotTimeFrame( const char* winname, int timeframe )
{
    if( m_pWindowManager->IsEnabled( winname ) )
    {
        getPlotter( winname )->setTimeFrame( timeframe );
    }
}

void db::WindowsDebugger::SetPlotLineThickness( const char* winname, int thickness, db::Colour colour )
{
    if( m_pWindowManager->IsEnabled( winname ) )
    {
        getPlotter( winname )->setLineThickness( thickness, colour );
    }
}

void db::WindowsDebugger::SetPlotDotRadius( const char* winname, int radius, db::Colour colour )
{
    if( m_pWindowManager->IsEnabled( winname ) )
    {
        getPlotter( winname )->setDotRadius( radius, colour );
    }
}

void db::WindowsDebugger::SetPlotType( const char* winname, db::ePlotType type, Colour colour )
{
    if( m_pWindowManager->IsEnabled( winname ) )
    {
        getPlotter( winname )->setPlotType( type, colour );
    }
}

void db::WindowsDebugger::Imshow( const char* winname, cv::Mat mat )
{
    if( m_pWindowManager->IsEnabled( winname ) )
    {
        cv::ImageView* pView = getImageView( winname, mat.cols, mat.rows, mat.type() );
        mat.copyTo( pView->getMat() );
        pView->invalidate();
        pView->requestRefresh();
    }
}

void db::WindowsDebugger::DebugMemoryPool( int frame )
{
    if( !m_pWindowManager->IsEnabled( "(MEM-3) Memory Allocation" ) )
    {
        return;
    }

    Plot( "(MEM-3) Memory Allocation", frame, memory::MemoryPool::ImagesAllocated( itype::IMTP_TopView_U8C1 ), db::Colour( 255, 0, 0 ) );
    Plot( "(MEM-3) Memory Allocation", frame, memory::MemoryPool::ImagesAllocated( itype::IMTP_TopView_U32C1 ), db::Colour( 255, 255, 0 ) );
    Plot( "(MEM-3) Memory Allocation", frame, memory::MemoryPool::ImagesAllocated( itype::IMTP_TopView_F32C1 ), db::Colour( 0, 0, 255 ) );
}

void db::WindowsDebugger::ShowAngleDetection( const image::Image<uint8_t>& inputImage, image::Image<uint8_t>& trailerTemplate, image::Image<uint8_t>& trailerTemplate2, image::Image<uint8_t>& matchedTemplate, float curAngle, int angleXPos, int templateYOffset, float tmFactor )
{
    char* winname = "(TAD-1) Trailer Angle";

    if( !m_pWindowManager->IsEnabled( winname ) )
    {
        return;
    }

    curAngle;
    cv::ImageView* pView = getImageView( winname, inputImage.getWidth(), inputImage.getHeight(), CV_8UC3 );
    cv::Mat& img = pView->getMat();
    //cv::Mat img = cv::Mat( inputImage.height, inputImage.width, CV_8UC3 );
    processing::ImageProcessing::CopyToCV<uint8_t>( inputImage, img );
    cv::rectangle( img, cv::Rect( angleXPos - trailerTemplate.getWidth() / 2, templateYOffset, trailerTemplate.getWidth(), trailerTemplate.getHeight() ), cv::Scalar( 255, 0, 0 ), 1 );
    cv::Point P1 = cv::Point( angleXPos, templateYOffset );
    cv::Point P2 = cv::Point( angleXPos, templateYOffset + trailerTemplate.getHeight() );
    cv::line( img, P1, P2, cv::Scalar( 255, 120, 120 ), 1 );
    pView->invalidate();
    pView->requestRefresh();
    //
    Imshow( "(TAD-1) Trailer Angle (Warped)", img );
    Imshow( "(TAD-1) Dynamic Template", trailerTemplate2, db::ImShow_Binary );
    Imshow_templateOverlap( "(TAD-2) TemplateMatching 1", trailerTemplate, matchedTemplate, tmFactor );
    Imshow_templateOverlap( "(TAD-2) TemplateMatching 2", trailerTemplate2, matchedTemplate, tmFactor );
}

void db::WindowsDebugger::ShowMirrorOverlap( const image::Image<uint8_t>& templateImage )
{
    char* winname = "(TCA-2) Template Matching";

    if( !m_pWindowManager->IsEnabled( winname ) )
    {
        return;
    }

    cv::ImageView* pView = getImageView( winname, templateImage.getWidth() / 2, templateImage.getHeight(), CV_8UC3 );
    cv::Mat& result = pView->getMat();
    //cv::Mat result = cv::Mat( templateImage.height, templateImage.width / 2, CV_8UC3 );
    uint8_t* rslt_ptr = result.data;
    uint8_t* le_row = templateImage.getData();
    uint8_t* ri_row = templateImage.getData() + templateImage.getWidth() - 1;
    int32_t step = templateImage.getStep();
    uint8_t* le_ptr;
    uint8_t* ri_ptr;

    for( uint32_t y = 0; y < templateImage.getHeight(); ++y )
    {
        le_ptr = le_row;
        ri_ptr = ri_row;

        for( uint32_t x = 0; x < ( templateImage.getWidth() / 2 ); ++x )
        {
            if( *le_ptr > 0 && *ri_ptr == 0 )
            {
                rslt_ptr[0] = 255;
                rslt_ptr[1] = 0;
                rslt_ptr[2] = 0;
            }
            else if( *le_ptr == 0 && *ri_ptr > 0 )
            {
                rslt_ptr[0] = 0;
                rslt_ptr[1] = 0;
                rslt_ptr[2] = 255;
            }
            else if( *le_ptr == 0 && *ri_ptr == 0 )
            {
                rslt_ptr[0] = 0;
                rslt_ptr[1] = 0;
                rslt_ptr[2] = 0;
            }
            else if( *le_ptr > 0 && *ri_ptr > 0 )
            {
                rslt_ptr[0] = 255;
                rslt_ptr[1] = 0;
                rslt_ptr[2] = 255;
            }

            ++le_ptr;
            --ri_ptr;
            rslt_ptr += 3;
        }

        le_row += step;
        ri_row += step;
    }

    cv::resize( result, result, cv::Size( templateImage.getWidth(), templateImage.getHeight() * 2 ) );
    pView->invalidate();
    pView->requestRefresh();
}

void db::WindowsDebugger::ShowFeatures( const char* category, const image::Image<TAD2::FeatureExtraction::Feature>& featureImage )
{
    char winname[260];
    // --- Gradient
    sprintf( winname, "(%s-3) Gradient Magnitude", category );

    if( m_pWindowManager->IsEnabled( winname ) )
    {
        cv::ImageView* pView = getImageView( winname, featureImage.getWidth(), featureImage.getHeight(), CV_8UC3 );
        cv::Mat& result = pView->getMat();
        uint8_t* rslt_ptr = result.data;
        image::Image<TAD2::FeatureExtraction::Feature>::iterator ftr_it = featureImage.begin();
        image::Image<TAD2::FeatureExtraction::Feature>::iterator ftr_end = featureImage.end();

        for( ; ftr_it != ftr_end; ++ftr_it, rslt_ptr += 3 )
        {
            rslt_ptr[0] = ( uint8_t )ftr_it->edgeStrength;
            rslt_ptr[1] = ( uint8_t )ftr_it->edgeStrength;
            rslt_ptr[2] = ( uint8_t )ftr_it->edgeStrength;
        }

        pView->invalidate();
        pView->requestRefresh();
    }

    // --- Directions
    sprintf( winname, "(%s-3) Gradient Direction", category );

    if( m_pWindowManager->IsEnabled( winname ) )
    {
        cv::ImageView* pView = getImageView( winname, featureImage.getWidth(), featureImage.getHeight(), CV_8UC3 );
        cv::Mat& result = pView->getMat();
        uint8_t* rslt_ptr = result.data;
        image::Image<TAD2::FeatureExtraction::Feature>::iterator ftr_it = featureImage.begin();
        image::Image<TAD2::FeatureExtraction::Feature>::iterator ftr_end = featureImage.end();

        for( ; ftr_it != ftr_end; ++ftr_it, rslt_ptr += 3 )
        {
            uint8_t dist_from_0 = ( ftr_it->edgeDirection > 90 ) ? 180 - ftr_it->edgeDirection : ftr_it->edgeDirection;
            float32_t blue_factor = ( ( float32_t )dist_from_0 / 90.0f );
            rslt_ptr[0] = ( uint8_t )( blue_factor * 255.0f );
            rslt_ptr[1] = 0;
            rslt_ptr[2] = ( uint8_t )( ( 1.0f - blue_factor ) * 255.0f );
            rslt_ptr[0] *= ( uint8_t )( ftr_it->edgeStrength / 260.0f );
            rslt_ptr[1] *= ( uint8_t )( ftr_it->edgeStrength / 260.0f );
            rslt_ptr[2] *= ( uint8_t )( ftr_it->edgeStrength / 260.0f );
        }

        pView->invalidate();
        pView->requestRefresh();
    }
}

cv::Scalar db::WindowsDebugger::cvColour( db::Colour colour )
{
    return cv::Scalar( ( double )colour.b, ( double )colour.g, ( double )colour.r );
}

cv::Point db::WindowsDebugger::cvPoint( db::Point p )
{
    return cv::Point( ( int )p.x, ( int )p.y );
}

cv::ImageView* db::WindowsDebugger::getImageView( const char* winname, int width, int height, int type )
{
    cv::ImageView* pView;

    if( !m_pWindowManager->DoesViewExist( winname ) )
    {
        // --- Create window with single view
        pView = new cv::ImageView( cv::Mat( height, width, type ) );
        cv::Window* pWindow = new cv::Window( winname, width, height, type );
        pWindow->addView( pView );
        m_pWindowManager->AddView( winname, pView );
        m_pWindowManager->AddWindow( winname, pWindow );
    }
    else
    {
        // --- Get view
        cv::View* pIView = m_pWindowManager->GetView( winname );

        if( pIView->getViewType() != cv::eImageView )
        {
            pView = NULL;
        }
        else
        {
            pView = ( cv::ImageView* )( pIView );

            // --- Check view and window size
            if( ( width != 0 && width != pView->getMat().cols ) || ( height != 0 && height != pView->getMat().rows ) )
            {
                pView->resize( width, height );

                if( m_pWindowManager->DoesWindowExist( winname ) )
                {
                    cv::Window* pWindow = m_pWindowManager->GetWindow( winname );
                    pWindow->resize( width, height );
                }
            }
        }
    }

    return pView;
}

db::Plotter* db::WindowsDebugger::getPlotter( const char* winname )
{
    if( !m_pWindowManager->DoesPlotterExist( winname ) )
    {
        cv::ImageView* pView = getImageView( winname, 640, 400, CV_8UC3 );
        db::Plotter* pPlotter = new db::Plotter( winname, pView->getMat() );
        m_pWindowManager->AddPlotter( winname, pPlotter );
        return pPlotter;
    }
    else
    {
        return m_pWindowManager->GetPlotter( winname );
    }
}

#endif // !WINDOWS_DEBUGGING
