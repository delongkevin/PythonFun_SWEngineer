// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [01-Feb-2019]
// --- Last Modified by Joshua Teichroeb [01-Feb-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#include "diag.h"
#include "Defines.h"

#ifdef WINDOWS_DIAGNOSTICS
    #include "WindowsProfiler.h"
    diag::WindowsProfiler g__profilerObj;
    diag::WindowsProfiler* g__pProfiler = NULL;
#else
    #include "BaseProfiler.h"
    diag::BaseProfiler g__profilerObj;
    diag::BaseProfiler* g__pProfiler = NULL;
#endif

using namespace diag;

void diag::init( const char* outputFilename )
{
#ifdef ENABLE_DIAGNOSTICS

    if( g__pProfiler == NULL )
    {
        g__pProfiler = &g__profilerObj;
        g__pProfiler->Init( outputFilename );
    }

#endif
}

void diag::finish()
{
#ifdef ENABLE_DIAGNOSTICS

    if( isRunning() )
    {
        g__pProfiler->Finish();
    }

    if( g__pProfiler != NULL )
    {
        g__pProfiler = NULL;
    }

#endif
}

inline bool diag::isRunning()
{
#ifdef ENABLE_DIAGNOSTICS
    return true;
#else
    return false;
#endif
}

void diag::beginFrame( int framenumber )
{
#ifdef ENABLE_DIAGNOSTICS

    if( isRunning() )
    {
        g__pProfiler->BeginFrame( framenumber );
    }

#endif
}

void diag::endFrame()
{
#ifdef ENABLE_DIAGNOSTICS

    if( isRunning() )
    {
        g__pProfiler->EndFrame();
    }

#endif
}

void diag::beginNewSession( const char* title )
{
    if( isRunning() )
    {
        g__pProfiler->NewSession( title );
    }
}

void diag::start( const char* name )
{
#ifdef ENABLE_DIAGNOSTICS

    if( isRunning() )
    {
        g__pProfiler->Start( name );
    }

#endif
}

void diag::stop()
{
#ifdef ENABLE_DIAGNOSTICS

    if( isRunning() )
    {
        g__pProfiler->Stop();
    }

#endif
}
#endif // _WIN32