// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [03-Apr-2019]
// --- Last Modified by Joshua Teichroeb [03-Apr-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "Defines.h"
#ifdef DIAGNOSTICS
#include "fo.h"


fo::filestream fo::getFileStream( const char* filename )
{
#ifdef ENABLE_FILE_OUTPUT
    return fo::filestream( FileOutput::GetStream( filename ) );
#else
    filename;
    return fo::filestream( NULL );
#endif // ENABLE_FILE_OUTPUT
}

fo::csvstream fo::getCSVStream( const char* filename )
{
#ifdef ENABLE_FILE_OUTPUT
    return fo::csvstream( CSVOutput::GetStream( filename ) );
#else
    filename;
    return fo::csvstream( NULL );
#endif // ENABLE_FILE_OUTPUT
}

void fo::closeAllStreams()
{
#ifdef ENABLE_FILE_OUTPUT
    FileOutput::CloseAllStreams();
#endif // ENABLE_FILE_OUTPUT
}

#endif
