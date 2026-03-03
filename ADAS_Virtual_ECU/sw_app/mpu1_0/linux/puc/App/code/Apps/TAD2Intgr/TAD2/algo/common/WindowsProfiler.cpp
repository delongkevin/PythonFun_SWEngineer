// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [01-Feb-2019]
// --- Last Modified by Joshua Teichroeb [01-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "WindowsProfiler.h"

#ifdef WINDOWS_DIAGNOSTICS

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
    #define min(a,b) ((a) < (b) ? (a) : (b))
#endif

/*
* Constructor.
*/
diag::WindowsProfiler::WindowsProfiler() :
    m_isRunning( false ),
    m_framesRun( 0 ),
    m_curFrame( 0 ),
    m_frameStart( 0 ),
    m_totalRunTime( 0 ),
    m_minRunTime( ( ~0U ) ),
    m_maxRunTime( 0 ),
    m_maxStackSize( 0 ),
    m_maxBufSize( 0 ),
    m_timers(),
    m_finishedTimers()
{
}

/*
* Destructor.
*/
diag::WindowsProfiler::~WindowsProfiler()
{
    Finish();
}

/*
* Initialize the profiler.
*/
bool_t diag::WindowsProfiler::Init( const char* outputFilename )
{
    m_filename = std::string( outputFilename ) + ".csv";
    m_timers.reserve( 10 );
    m_finishedTimers.reserve( 75 );
    //
    // --- Clear output file and initialize
    std::ofstream fo;
    fo.open( m_filename, std::ofstream::out | std::ofstream::trunc );

    if( fo.is_open() )
    {
        fo << "Session" << ',' << "Title" << ",,";
        //fo << ',' << "Times Run";
        //fo << ',' << "Total Time";
        fo << ',' << "Avg Time";
        fo << ',' << "Min Time";
        fo << ',' << "Max Time";
        fo << ',' << "Time Variance";
        fo << ',' << "Per Frame";
        fo << ',' << "Frames Run";
        fo << '\n';
        fo.close();
        m_isRunning = true;
        return true;
    }
    else
    {
        m_isRunning = false;
        return false;
    }
}

/*
* Finish profiling and output final results to a file.
*/
void diag::WindowsProfiler::Finish()
{
    if( !m_isRunning )
    {
        return;
    }

    std::ofstream fo;
    fo.open( m_filename, std::ofstream::out | std::ofstream::app );

    if( fo.is_open() )
    {
        OutputResults( fo );
        fo << '\n';
#ifdef _DEBUG
        fo << "Run in Debug." << '\n';
#else
        fo << "Run in Release." << '\n';
#endif
        fo.close();
    }

    m_isRunning = false;
}

/*
* Reset profiler.
*/
void diag::WindowsProfiler::Reset()
{
    m_framesRun = 0;
    m_totalRunTime = 0;
    m_minRunTime = ( ~0U );
    m_maxRunTime = 0;
    m_maxStackSize = 0;
    m_maxBufSize = 0;
    m_specs.clear();
}

/*
* Begin a new frame.
*/
void diag::WindowsProfiler::BeginFrame( int framenumber )
{
    if( !m_isRunning )
    {
        return;
    }

    m_curFrame = framenumber;
    m_timers.clear(); // timers only allowed inside begin and end of frame
    m_frameStart = ( uint32_t )clock();
}

/*
* End frame.
*/
void diag::WindowsProfiler::EndFrame()
{
    if( !m_isRunning )
    {
        return;
    }

    uint32_t time = ( uint32_t )clock() - m_frameStart;
    m_totalRunTime += time;
    m_minRunTime = min( m_minRunTime, time );
    m_maxRunTime = max( m_maxRunTime, time );
    ++m_framesRun;

    if( m_timers.size() > 0 )
    {
        // more starts than stops
        assert( 0 );
    }

    m_timers.clear(); // timers only allowed inside begin and end of frame
    Flush();
}

/*
* Output results up until now and begin a new profiling session.
*/
void diag::WindowsProfiler::NewSession( const char* title )
{
    if( !m_isRunning )
    {
        return;
    }

    std::ofstream fo;
    fo.open( m_filename, std::ofstream::out | std::ofstream::app );

    if( fo.is_open() )
    {
        OutputResults( fo );
        fo << '\n' << title << '\n';
        fo.close();
    }

    Reset();
}

/*
* Start a timed event.
*/
inline void diag::WindowsProfiler::Start( const char* name )
{
    if( m_isRunning )
    {
        m_timers.push_back( diag::WindowsTimer( name ).Start() );
    }
}

/*
* Stop a timed event.
*/
inline void diag::WindowsProfiler::Stop()
{
    if( m_isRunning )
    {
        if( m_timers.size() == 0 )
        {
            // Too many stops!
            assert( 0 );
        }

        m_finishedTimers.push_back( m_timers.back().Stop() );
        m_maxStackSize = max( m_maxStackSize, m_timers.size() );
        m_timers.pop_back();
    }
}

/*
* Flush all stopped timers, storing their results.
*/
inline void diag::WindowsProfiler::Flush()
{
    if( !m_isRunning )
    {
        return;
    }

    m_maxBufSize = max( m_maxBufSize, m_finishedTimers.size() );

    for( std::vector<diag::WindowsTimer>::iterator timer = m_finishedTimers.begin(); timer != m_finishedTimers.end(); ++timer )
    {
        uint32_t time = timer->stop_time - timer->start_time;
        std::unordered_map<std::string, Spec>::iterator it = m_specs.find( timer->name );

        if( it == m_specs.end() )
        {
            Spec spec;
            spec.total_time = time;
            spec.total_time_sqrd = time * time;
            spec.num_times_run = 1;
            spec.frames_run_in = 1;
            spec.last_frame_run_in = m_curFrame;
            spec.max_time = time;
            spec.min_time = time;
            m_specs.insert( std::pair<std::string, Spec>( timer->name, spec ) );
        }
        else
        {
            Spec& spec = it->second;
            spec.total_time += time;
            spec.total_time_sqrd += time * time;
            spec.num_times_run++;
            spec.max_time = max( spec.max_time, time );
            spec.min_time = min( spec.min_time, time );

            if( spec.last_frame_run_in != m_curFrame )
            {
                spec.last_frame_run_in = m_curFrame;
                spec.frames_run_in++;
            }
        }
    }

    m_finishedTimers.clear();
}

/*
* Output all tracked results to the given file stream.
*/
void diag::WindowsProfiler::OutputResults( std::ofstream& fo )
{
    if( m_framesRun == 0 || !m_isRunning )
    {
        return;
    }

    fo << std::fixed;
    fo << std::setprecision( 2 );

    for( std::unordered_map<std::string, Spec>::iterator it = m_specs.begin(); it != m_specs.end(); ++it )
    {
        Spec& spec = it->second;
        fo << ',' << it->first << ",,";
        fo << ',' << ( ( double )spec.total_time / ( double )spec.num_times_run ) * c_clocksPerMS;
        fo << ',' << ( double )spec.min_time* c_clocksPerMS;
        fo << ',' << ( double )spec.max_time* c_clocksPerMS;
        fo << ',' << sqrt( ( double )spec.total_time_sqrd - ( double )( spec.total_time * spec.total_time ) / ( double )( spec.num_times_run * spec.num_times_run ) ) * c_clocksPerMS;
        fo << ',' << ( double )spec.num_times_run / ( double )m_framesRun;
        fo << ',' << spec.frames_run_in;
        fo << '\n';
    }

    fo << '\n';
    fo << ',' << "TOTAL" << ",,";
    fo << ',' << ( ( double )m_totalRunTime / ( double )m_framesRun ) * c_clocksPerMS;
    fo << ',' << ( double )m_minRunTime* c_clocksPerMS;
    fo << ',' << ( double )m_maxRunTime* c_clocksPerMS;
    fo << ',' << -1.0;
    fo << ',' << 1.0;
    fo << ',' << m_framesRun;
    fo << ',' << m_maxStackSize;
    fo << ',' << m_maxBufSize;
    fo << '\n';
}

///------------------------------------------------------------------------------
/// WindowsTimer class function definitions.
///------------------------------------------------------------------------------

/*
* Create a timer.
*/
diag::WindowsTimer::WindowsTimer( const char* name ) :
    name( name )
{
}

/*
* Start timer.
*/
inline diag::WindowsTimer& diag::WindowsTimer::Start()
{
    start_time = clock();
    return ( *this );
}

/*
* Stop timer.
*/
inline diag::WindowsTimer& diag::WindowsTimer::Stop()
{
    stop_time = clock();
    return ( *this );
}

#endif //!WINDOWS_DIAGNOSTICS
