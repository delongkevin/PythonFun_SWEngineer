// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [02-Aug-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------
#ifdef _WIN32
#include  "stdafx.h"
#include "BaseProfiler.h"

/*
* Constructor.
*/
diag::BaseProfiler::BaseProfiler()
{
}

/*
* Destructor.
*/
diag::BaseProfiler::~BaseProfiler()
{
}

/*
* Initialize the profiler.
*/
bool_t diag::BaseProfiler::Init( const char* outputFilename )
{
    outputFilename;
    return true;
}

/*
* Finish profiling.
*/
void diag::BaseProfiler::Finish()
{
}

/*
* Reset profiler.
*/
void diag::BaseProfiler::Reset()
{
}

/*
* Begin a new frame.
*/
void diag::BaseProfiler::BeginFrame( int framenumber )
{
    framenumber;
}

/*
* End frame.
*/
void diag::BaseProfiler::EndFrame()
{
}

/*
* Begin a new profiling session.
*/
void diag::BaseProfiler::NewSession( const char* title )
{
    title;
}

/*
* Start a timed event.
*/
void diag::BaseProfiler::Start( const char* name )
{
    name;
}

/*
* Stop a timed event.
*/
void diag::BaseProfiler::Stop()
{
}
#endif