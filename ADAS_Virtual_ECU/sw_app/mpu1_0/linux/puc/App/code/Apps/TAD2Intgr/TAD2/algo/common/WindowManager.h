// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [17-Jan-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __DEBUGGER__H_
#define __DEBUGGER__H_

#include "Defines.h"
#include "Plotter.h"
#include "CVContainers.h"

#ifdef WINDOWS_DEBUGGING

#include <list>
#include <typeinfo>
#include <map>
#include <unordered_map>

#include "highgui/highgui.hpp"
#include "imgcodecs.hpp"
#include "imgproc/imgproc.hpp"

///------------------------------------------------------------------------------
/// The debugging library namespace.
///------------------------------------------------------------------------------
namespace db
{
    /**
    * WindowManager class which implements logic for debugging library.
    *
    * Logic for the debugging library is placed in a separate class so that
    * if debugging were to be disabled (e.g. if OpenCV or std libraries were
    * to be removed), then we can modify the library files (add #if's) without
    * actually touching the implementation. We can also easily switch
    * implementations if we ever wanted to do so.
    */
    class WindowManager
    {
    public:
        WindowManager();
        ~WindowManager();

        void Run( int frameNum );
        void Run();
        void Reset();

        void AddPlotter( std::string winname, db::Plotter* pPlotter );
        void AddWindow( std::string winname, cv::Window* pWindow );
        void AddView( std::string viewname, cv::View* pView );

        void RemovePlotter( std::string winname );
        void RemoveWindow( std::string winname );
        void RemoveView( std::string viewname );

        db::Plotter* GetPlotter( std::string winname );
        cv::Window* GetWindow( std::string winname );
        cv::View* GetView( std::string viewname );

        bool DoesPlotterExist( std::string winname );
        bool DoesWindowExist( std::string winname );
        bool DoesViewExist( std::string viewname );

        bool IsEnabled( std::string winname );
        void SetDebugLevel( int level );
        void EnableWindow( std::string winname );
        void DisableWindow( std::string winname );
        void SetCategoryLevel( std::string category, int level );

        int m_curFrameNum;

    private:
        int m_level;

        std::map<std::string, db::Plotter*> m_plotters;
        std::map<std::string, cv::View*> m_views;
        std::map<std::string, cv::Window*> m_windows;
        std::unordered_map<std::string, bool> m_enabled;
        std::map<std::string, int> m_levelSets;

        bool defaultSetting( std::string winname );
        bool isInCategory( const std::string& winname, const std::string& category );
        std::string getCategory( const std::string& winname );
        int getLevel( const std::string& winname );
        std::string trim( std::string str );
    };
}

#endif // !WINDOWS_DEBUGGING

#endif // !__DEBUGGER__H_
