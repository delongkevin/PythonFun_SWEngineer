// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [01-Feb-2019]
// --- Last Modified by Joshua Teichroeb [01-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __WINDOWS_PROFILER__H_
#define __WINDOWS_PROFILER__H_

#include "Defines.h"
#ifdef WINDOWS_DIAGNOSTICS

#include "BaseProfiler.h"
#include "MECL\mecl.h"



#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <assert.h>

///------------------------------------------------------------------------------
/// The diagnostics library namespace.
///------------------------------------------------------------------------------
namespace diag
{
    /*
    * Timer used in WindowsProfiler.
    *
    * Modify this to change which timing function is used for profiling.
    */
    class WindowsTimer
    {
    public:
        const char* name;
        uint32_t start_time;
        uint32_t stop_time;

        explicit WindowsTimer( const char* name );

        WindowsTimer& Start();
        WindowsTimer& Stop();
    };

    /*
    * Windows profiler implementation for diagnostics library.
    */
    class WindowsProfiler : public BaseProfiler
    {
    public:
        /*
        * Struct to store data regarding a single timed event.
        */
        struct Spec
        {
            uint32_t total_time;
            uint32_t total_time_sqrd;
            uint32_t num_times_run;
            uint32_t frames_run_in;
            uint32_t last_frame_run_in;
            uint32_t max_time;
            uint32_t min_time;
        };

        // --- Constructor/Destructor
        WindowsProfiler();
        virtual ~WindowsProfiler();

        // --- Initialize/Uninitialize functions
        virtual bool_t Init( const char* outputFilename ) override;
        virtual void Finish() override;
        virtual void Reset() override;

        // --- Profiling functions
        virtual void BeginFrame( int framenumber ) override;
        virtual void EndFrame() override;
        virtual void NewSession( const char* title ) override;

        virtual void Start( const char* name ) override;
        virtual void Stop() override;

        // --- Constants
        const std::string NONE = "None";
        constexpr static double c_clocksPerMS = 1000.0f / CLOCKS_PER_SEC;

    private:
        std::string m_filename;
        bool_t m_isRunning;

        // --- Global specs
        uint32_t m_framesRun;
        uint32_t m_curFrame;
        uint32_t m_frameStart;
        uint32_t m_totalRunTime;
        uint32_t m_minRunTime;
        uint32_t m_maxRunTime;

        uint32_t m_maxStackSize;
        uint32_t m_maxBufSize;

        // --- Timers and stored results
        std::vector<WindowsTimer> m_timers;
        std::vector<WindowsTimer> m_finishedTimers;
        std::unordered_map<std::string, Spec> m_specs;

        // --- Helper functions
        void Flush();
        void OutputResults( std::ofstream& fo );

    };
}

#endif // !WINDOWS_DIAGNOSTICS

#endif // !__WINDOWS_PROFILER__H_
