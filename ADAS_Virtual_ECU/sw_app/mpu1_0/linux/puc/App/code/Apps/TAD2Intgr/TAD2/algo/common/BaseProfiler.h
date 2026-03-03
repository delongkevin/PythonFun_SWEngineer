// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [02-Aug-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------
#ifdef _WIN32

#ifndef __BASE_PROFILER__H_
#define __BASE_PROFILER__H_

#ifdef __QNX__
    #include "mecl/mecl.h"
#else
    #include "MECL\mecl.h"
#endif


///------------------------------------------------------------------------------
/// The diagnostics library namespace.
///------------------------------------------------------------------------------
namespace diag
{
    /*
    * Default profiler for diagnostics library.
    *
    * This class is to remain free from OpenCV and std library functions/classes.
    */
    class BaseProfiler
    {
    public:
        // --- Constructor/Destructor
        BaseProfiler();
        virtual ~BaseProfiler();

        // --- Initialize/Uninitialize functions
        virtual bool_t Init( const char* outputFilename );
        virtual void Finish();
        virtual void Reset();

        // --- Profiling functions
        virtual void BeginFrame( int framenumber );
        virtual void EndFrame();
        virtual void NewSession( const char* title );

        virtual void Start( const char* name );
        virtual void Stop();

    private:

    };
}

#endif // !__BASE_PROFILER__H_
#endif //_WIN32