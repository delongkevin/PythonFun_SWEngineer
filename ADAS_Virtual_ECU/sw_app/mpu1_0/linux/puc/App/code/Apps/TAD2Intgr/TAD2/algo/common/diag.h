// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [01-Feb-2019]
// --- Last Modified by Joshua Teichroeb [01-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
#ifndef __DIAG__H_
#define __DIAG__H_

///------------------------------------------------------------------------------
/// Diagnostics library
///
/// This wrapper is to remain free from OpenCV and std library functions/classes.
///------------------------------------------------------------------------------
namespace diag
{
    ///------------------------------------------------------------------------------
    /// Setup functions
    ///------------------------------------------------------------------------------

    /*
    * Call this at the begining of your program.
    */
    void init( const char* outputFilename );

    /*
    * Call this at the end of your program.
    */
    void finish();

    /*
    * Call this to check if the profiler is running.
    */
    bool isRunning();

    /*
    * Call this at the begining of every frame/loop.
    */
    void beginFrame( int framenumber );

    /*
    * Call this at the end of every frame/loop.
    */
    void endFrame();

    /*
    * Call this after calling endFrame to separate your profiling results.
    */
    void beginNewSession( const char* title );


    ///------------------------------------------------------------------------------
    /// Profiling functions
    ///------------------------------------------------------------------------------

    /*
    * Start timer.
    */
    void start( const char* name );

    /*
    * Stop most recent timer.
    */
    void stop();
}

#endif // !__DIAG__H_

#endif // _WIN32