// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [17-Jan-2019]
// --- Last Modified by Joshua Teichroeb [17-Jan-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "WindowManager.h"

#ifdef WINDOWS_DEBUGGING

#include <functional>

db::WindowManager::WindowManager() :
    m_level( 0 ),
    m_curFrameNum( 0 )
{
}

db::WindowManager::~WindowManager()
{
    Reset();
}

void db::WindowManager::Run( int frameNum )
{
    m_curFrameNum = frameNum;
    Run();
}

void db::WindowManager::Run()
{
    for( std::map<std::string, db::Plotter*>::iterator it = m_plotters.begin(); it != m_plotters.end(); ++it )
    {
        if( m_enabled.find( it->first )->second )
        {
            it->second->update();
        }
    }

    for( std::map<std::string, cv::Window*>::iterator it = m_windows.begin(); it != m_windows.end(); ++it )
    {
        // --- Check if window has been closed
        if( cv::getWindowProperty( it->first, cv::WND_PROP_AUTOSIZE ) == -1 )
        {
            m_enabled.find( it->first )->second = false;
        }

        // --- Update if enabled
        if( m_enabled.find( it->first )->second )
        {
            it->second->refresh();
            it->second->show();
        }

        //std::unordered_map<std::string, bool>::iterator en_it = m_enabled.find( it->first );
        //bool en;
        //
        //if( en_it == m_enabled.end() )
        //{
        //    bool en = defaultSetting( it->first.c_str() );
        //    m_enabled.insert( std::pair<std::string, bool>( it->first, en ) );
        //}
        //else
        //{
        //    en = en_it->second;
        //}
        //
        //if( en && it->second.data != NULL )
        //{
        //    cv::namedWindow( it->first, CV_WINDOW_NORMAL | CV_WINDOW_KEEPRATIO | CV_GUI_EXPANDED );
        //    cv::imshow( it->first, it->second );
        //}
    }

    cv::waitKey( 1 );
}

void db::WindowManager::Reset()
{
    for( std::map<std::string, db::Plotter*>::iterator it = m_plotters.begin(); it != m_plotters.end(); ++it )
    {
        if( m_enabled.find( it->first )->second )
        {
            it->second->clear();
        }

        delete it->second;
    }

    for( std::map<std::string, cv::Window*>::iterator it = m_windows.begin(); it != m_windows.end(); ++it )
    {
        delete it->second;
    }

    m_enabled.clear();
    m_windows.clear();
    m_views.clear();
    m_plotters.clear();
    cv::destroyAllWindows();
    m_curFrameNum = 0;
}

void db::WindowManager::AddPlotter( std::string winname, db::Plotter* pPlotter )
{
    winname = trim( winname );
    m_plotters.insert( std::pair<std::string, db::Plotter*>( winname, pPlotter ) );
}

void db::WindowManager::AddWindow( std::string winname, cv::Window* pWindow )
{
    winname = trim( winname );
    m_windows.insert( std::pair<std::string, cv::Window*>( winname, pWindow ) );
    cv::namedWindow( winname, CV_WINDOW_NORMAL | CV_WINDOW_KEEPRATIO | CV_GUI_EXPANDED );
    //cv::setWindowProperty(winname, cv::WindowPropertyFlags::WND_PROP_AUTOSIZE, cv::WindowFlags::WINDOW_NORMAL);
}

void db::WindowManager::AddView( std::string viewname, cv::View* pView )
{
    viewname = trim( viewname );
    m_views.insert( std::pair<std::string, cv::View*>( viewname, pView ) );
}

void db::WindowManager::RemovePlotter( std::string winname )
{
    std::map<std::string, db::Plotter*>::iterator it = m_plotters.find( winname );

    if( it != m_plotters.end() )
    {
        delete it->second;
        m_plotters.erase( winname );
    }
}

void db::WindowManager::RemoveWindow( std::string winname )
{
    std::map<std::string, cv::Window*>::iterator it = m_windows.find( winname );

    if( it != m_windows.end() )
    {
        cv::Window* pWindow = it->second;

        // --- Delete views from manager
        for( cv::View* pView : pWindow->getViews() )
        {
            for( std::map<std::string, cv::View*>::iterator it2 = m_views.begin(); it2 != m_views.end(); ++it2 )
            {
                if( pView == it2->second )
                {
                    m_views.erase( it2->first );
                    break;
                }
            }
        }

        delete pWindow;
        m_windows.erase( winname );
        cv::destroyWindow( winname );
    }
}

void db::WindowManager::RemoveView( std::string viewname )
{
    m_views.erase( viewname );
}

db::Plotter* db::WindowManager::GetPlotter( std::string winname )
{
    winname = trim( winname );

    if( DoesPlotterExist( winname ) )
    {
        return m_plotters.find( winname )->second;
    }
    else
    {
        return NULL;
    }
}

cv::Window* db::WindowManager::GetWindow( std::string winname )
{
    winname = trim( winname );

    if( DoesWindowExist( winname ) )
    {
        return m_windows.find( winname )->second;
    }
    else
    {
        return NULL;
    }
}

cv::View* db::WindowManager::GetView( std::string viewname )
{
    viewname = trim( viewname );

    if( DoesViewExist( viewname ) )
    {
        return m_views.find( viewname )->second;
    }
    else
    {
        return NULL;
    }
}

bool db::WindowManager::DoesPlotterExist( std::string winname )
{
    std::string winnameStr = trim( winname );
    return ( m_plotters.find( winnameStr ) != m_plotters.end() );
}

bool db::WindowManager::DoesWindowExist( std::string winname )
{
    std::string winnameStr = trim( winname );
    return ( m_windows.find( winnameStr ) != m_windows.end() );
}

bool db::WindowManager::DoesViewExist( std::string viewname )
{
    std::string viewnameStr = trim( viewname );
    return ( m_views.find( viewnameStr ) != m_views.end() );
}

bool db::WindowManager::IsEnabled( std::string winname )
{
    std::string winnameStr = trim( winname );
    std::unordered_map<std::string, bool>::iterator it = m_enabled.find( winnameStr );

    if( it == m_enabled.end() )
    {
        bool en = defaultSetting( winname );
        m_enabled.insert( std::pair<std::string, bool>( winnameStr, en ) );
        return en;
    }
    else
    {
        return it->second;
    }
}

void db::WindowManager::SetDebugLevel( int level )
{
    m_level = ( level < 1 ) ? 0 : level;

    for( std::unordered_map<std::string, bool>::iterator it = m_enabled.begin(); it != m_enabled.end(); ++it )
    {
        it->second = ( getLevel( it->first ) <= level );
    }
}

void db::WindowManager::DisableWindow( std::string winname )
{
    std::string winnameStr = trim( winname );
    std::unordered_map<std::string, bool>::iterator it = m_enabled.find( winnameStr );

    if( it != m_enabled.end() )
    {
        it->second = false;
    }
    else
    {
        m_enabled.insert( std::pair<std::string, bool>( winnameStr, false ) );
    }
}

void db::WindowManager::SetCategoryLevel( std::string category, int level )
{
    std::map<std::string, int>::iterator it1 = m_levelSets.find( category );

    if( level < 0 )
    {
        level = 0;
    }

    if( it1 != m_levelSets.end() )
    {
        it1->second = level;
    }
    else
    {
        m_levelSets.insert( std::pair<std::string, int>( category, level ) );
    }

    for( std::unordered_map<std::string, bool>::iterator it = m_enabled.begin(); it != m_enabled.end(); ++it )
    {
        if( getCategory( it->first ) == category )
        {
            it->second = ( getLevel( it->first ) <= level );
        }
    }
}

//void WindowsWindowManager::DisableWindowSet( const char* prefix )
//{
//#ifdef ENABLE_DEBUG_WINDOWS
//    m_sets.insert( std::pair<std::string, bool>(prefix, false ) );
//
//    for( std::unordered_map<std::string, bool>::iterator it = m_enabled.begin(); it != m_enabled.end(); ++it )
//    {
//        if( it->first.find(prefix, it->first.length() - strlen(prefix) ) )
//        {
//            it->second = false;
//        }
//    }
//
//#endif
//}

void db::WindowManager::EnableWindow( std::string winname )
{
    std::string winnameStr = trim( winname );
    std::unordered_map<std::string, bool>::iterator it = m_enabled.find( winnameStr );

    if( it != m_enabled.end() )
    {
        it->second = true;
    }
    else
    {
        m_enabled.insert( std::pair<std::string, bool>( winnameStr, true ) );
    }
}

///*
//* If the plotter does not yet exist in the db::WindowManager, a new one will be created,
//* and its reference returned.
//*/
//Plotter& WindowsWindowManager::GetPlotter( const char* winname )
//{
//    std::string winnameStr = trim( winname );
//    std::map<std::string, Plotter>::iterator it = m_plotters.find( winnameStr );
//
//    if( it != m_plotters.end() )
//    {
//        return it->second;
//    }
//    else
//    {
//        cv::Mat mat = cv::Mat( 400, 640, CV_8UC3 );
//        m_panels.insert( std::pair<std::string, cv::Mat>( winnameStr, mat ) );
//        cv::Mat& panelRef = m_panels.find( winnameStr )->second;
//        m_windows.insert( std::pair<std::string, cv::Mat&>( winnameStr, panelRef ) );
//        m_plotters.insert( std::pair<std::string, Plotter>( winnameStr, Plotter( winnameStr, panelRef ) ) );
//        Plotter& plotter = m_plotters.find( winnameStr )->second;
//        return plotter;
//    }
//}
//
///*
//* If the panel does not yet exist in the db::WindowManager, a new one will be created using the given
//* parameters. However, only enabled windows will be displayed.
//*/
//cv::Mat WindowsWindowManager::GetView( const char* winname, unsigned int rows, unsigned int cols, int type )
//{
//    std::string winnameStr = trim( winname );
//    std::map<std::string, cv::Mat>::iterator it = m_panels.find( winnameStr );
//
//    if( it != m_panels.end() )
//    {
//        if( it->second.data == NULL || it->second.rows != rows || it->second.cols != cols || it->second.type() != type )
//        {
//            it->second = cv::Mat( rows, cols, type );
//        }
//
//        return it->second;
//    }
//    else
//    {
//        cv::Mat mat = cv::Mat( rows, cols, type );
//        m_panels.insert( std::pair<std::string, cv::Mat>( winnameStr, mat ) );
//        cv::Mat& panelRef = m_panels.find( winnameStr )->second;
//        m_windows.insert( std::pair<std::string, cv::Mat&>( winnameStr, panelRef ) );
//        return mat;
//    }
//}
//
//cv::Mat WindowsWindowManager::GetView( const char* winname )
//{
//    std::string winnameStr = trim( winname );
//    std::map<std::string, cv::Mat>::iterator it = m_panels.find( winnameStr );
//
//    if( it != m_panels.end() )
//    {
//        return it->second;
//    }
//    else
//    {
//        cv::Mat mat = cv::Mat( 0, 0, CV_8UC3 );
//        m_panels.insert( std::pair<std::string, cv::Mat>( winnameStr, mat ) );
//        cv::Mat& panelRef = m_panels.find( winnameStr )->second;
//        m_windows.insert( std::pair<std::string, cv::Mat&>( winnameStr, panelRef ) );
//        return mat;
//    }
//}

//void WindowsWindowManager::CombineViews( const char* winname, const char* panels, int numRows, int type, char delimeter )
//{
//    std::string winnameStr = trim( winname );
//    //
//    // --- Parse panel string and collect panels
//    std::string panelStr = trim( panels );
//    std::vector<std::string> panelNames;
//    std::vector<cv::Mat*> panelMats;
//    size_t pos1 = 0;
//
//    while( pos1 != std::string::npos )
//    {
//        size_t pos2 = panelStr.find_first_of( delimeter, pos1 );
//        std::string panelNameStr;
//
//        if( pos2 == std::string::npos )
//        {
//            panelNameStr = panelStr.substr( pos1 );
//            pos1 = std::string::npos;
//        }
//        else
//        {
//            panelNameStr = panelStr.substr( pos1, pos2 - pos1 );
//            pos1 = pos2 + 1;
//        }
//
//        std::string panelNameStr2 = trim( panelNameStr.c_str() );
//
//        if( panelNameStr2.length() > 0 )
//        {
//            std::map<std::string, cv::Mat>::iterator it = m_panels.find( panelNameStr2 );
//
//            if( it != m_panels.end() )
//            {
//                panelNames.push_back( panelNameStr2 );
//                panelMats.push_back( &( it->second ) );
//            }
//        }
//    }
//
//    int numPanels = panelNames.size();
//    int numCols = ( int )ceil( ( float )numPanels / ( float )numRows );
//    int margin = 2;
//    //
//    // --- Function to calculate the minimum length the window can be
//    std::function<int ( int, int )> get_min_len;
//    get_min_len = [numPanels, numRows, margin, panelMats, &get_min_len]( int row, int ind )->int
//    {
//        int rowsLeft = numRows - row;
//        int min_len = -1;
//        int row_len = 0;
//
//        if( rowsLeft == 0 )
//        {
//            // last row must take all the rest (base case)
//            for( int i = ind; i < numPanels; i++ )
//            {
//                row_len += panelMats[ind]->cols + 2 * margin;
//            }
//
//            min_len = row_len;
//        }
//        else
//        {
//            // try all possible combinations of panels
//            for( int i = ind; i < numPanels; i++ )
//            {
//                row_len += panelMats[i]->cols + 2 * margin;
//                int min_len_of_rest = get_min_len( row + 1, i + 1 );
//                int total_len = ( min_len_of_rest > row_len ) ? min_len_of_rest : row_len;
//
//                if( total_len < min_len || min_len < 0 )
//                {
//                    min_len = total_len;
//                }
//            }
//        }
//
//        return min_len;
//    };
//    // --- Get width and height of window
//    int w = get_min_len( 1, 0 );
//
//    if( w < 0 )
//    {
//        w = 0;
//    }
//
//    int row = 0;
//    int cur_h = 0;
//    int row_height = 0;
//    int row_len = 0;
//    std::vector<int> rowHeights( numRows );
//
//    for( int i = 0; i < numPanels; i++ )
//    {
//        cv::Mat& panel = *panelMats[i];
//        row_len += panel.cols + 2 * margin;
//        row_height = ( row_height > panel.rows ) ? row_height : panel.rows + 2 * margin;
//
//        if( i == numPanels - 1 || row_len + panelMats[i + 1]->cols > w )
//        {
//            cur_h += row_height + 2 * margin;
//            rowHeights[row] = row_height + 2 * margin;
//            row_height = 0;
//            row_len = 0;
//            row++;
//        }
//    }
//
//    int h = cur_h;
//    // --- Create matrix and assign panels
//    cv::Mat mat = cv::Mat( h, w, type );
//    mat.setTo( cv::Scalar( 255, 255, 255 ) );
//    cur_h = 0;
//    row = 0;
//    row_len = 0;
//
//    for( int i = 0; i < numPanels; i++ )
//    {
//        int x = row_len + margin;
//        int y = cur_h + rowHeights[row] / 2 - panelMats[i]->rows / 2;
//        cv::Rect roi = cv::Rect( x, y, panelMats[i]->cols, panelMats[i]->rows );
//
//        if( panelMats[i]->data != NULL && panelMats[i]->data != mat( roi ).data )
//        {
//            panelMats[i]->copyTo( mat( roi ) );
//            *panelMats[i] = mat( roi );
//        }
//
//        row_len += panelMats[i]->cols + 2 * margin;
//
//        if( i == numPanels - 1 || row_len + panelMats[i + 1]->cols > w )
//        {
//            cur_h += rowHeights[row];
//            row_len = 0;
//            row++;
//        }
//    }
//
//    // --- Add window and remove previous panle windows
//    for( int i = 0; i < numPanels; i++ )
//    {
//        m_windows.erase( panelNames[i] );
//    }
//
//    if( m_panels.find( winnameStr ) != m_panels.end() )
//    {
//        m_panels.erase( winnameStr );
//    }
//
//    m_panels.insert( std::pair<std::string, cv::Mat>( winnameStr, mat ) );
//    cv::Mat& panelRef = m_panels.find( winnameStr )->second;
//    m_windows.insert( std::pair<std::string, cv::Mat&>( winnameStr, panelRef ) );
//}

bool db::WindowManager::defaultSetting( std::string winname )
{
    int level = getLevel( winname );
    std::string category = getCategory( winname );

    for( std::map<std::string, int>::iterator it = m_levelSets.begin(); it != m_levelSets.end(); ++it )
    {
        if( category == it->first )
        {
            return level <= it->second;
        }

        //std::string winnameStr( winname );
        //auto miss = std::mismatch(it->first.begin(), it->first.end(), winnameStr.begin());
        //
        //if(miss.first == it->first.end())
        //{
        //    return it->second;
        //}
    }

    return ( level <= m_level );
    //switch (m_mode)
    //{
    //case DM_AllDisabled:
    //  return false;
    //case DM_AutoEnable:
    //  return true;
    //case DM_AutoDisable:
    //  return false;
    //default:
    //  return false;
    //}
}

bool db::WindowManager::isInCategory( const std::string& winname, const std::string& category )
{
    std::string::const_iterator it1 = winname.begin();
    std::string::const_iterator it2 = category.begin();

    if( it1 == winname.end() || *it1 != '(' )
    {
        return false;
    }

    ++it1;

    while( it2 != category.end() && *it1 == *it2 && *it1 != '-' && *it1 != ' ' )
    {
        ++it1;
        ++it2;
    }

    if( it2 == category.end() )
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string db::WindowManager::getCategory( const std::string& winname )
{
    std::string::const_iterator it1 = winname.begin();
    std::string result;

    if( it1 == winname.end() || *it1 != '(' )
    {
        return "";
    }

    ++it1;

    if( !isalpha( *it1 ) )
    {
        return "";
    }

    while( it1 != winname.end() && *it1 != '-' && *it1 != ')' )
    {
        result.append( 1, *it1 );
        ++it1;
    }

    return result;
}

int db::WindowManager::getLevel( const std::string& winname )
{
    std::string::const_iterator it1 = winname.begin();

    if( it1 == winname.end() || *it1 != '(' )
    {
        return 1;
    }

    ++it1;

    if( !isalpha( *it1 ) )
    {
        int level = ( int )std::strtol( &( *it1 ), NULL, 0 );
        return ( level > 0 ) ? level : 1;
    }

    while( it1 != winname.end() && *it1 != '-' && *it1 != ')' )
    {
        ++it1;
    }

    if( *it1 == '-' )
    {
        ++it1;
        int level = ( int )std::strtol( &( *it1 ), NULL, 0 );
        return ( level > 0 ) ? level : 1;
    }

    return 1;
}

std::string db::WindowManager::trim( std::string str )
{
    size_t first = str.find_first_not_of( ' ' );

    if( std::string::npos == first )
    {
        return str;
    }

    size_t last = str.find_last_not_of( ' ' );
    return str.substr( first, ( last - first + 1 ) );
}

#endif // !WINDOWS_DEBUGGING
