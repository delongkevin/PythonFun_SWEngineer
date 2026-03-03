#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "FileOutput.h"

using namespace std;

unordered_map<string, FileOutput*> FileOutput::s_map;

//------------------------------------------------------------------------------
// FileOutput function definitions.
//------------------------------------------------------------------------------

FileOutput::FileOutput( string filename, ios_base::openmode mode ) :
    ofstream( filename, mode ),
    m_filename( filename )
{
}

FileOutput::FileOutput( const char* filename, ios_base::openmode mode ) :
    ofstream( filename, mode ),
    m_filename( filename )
{
}

FileOutput::FileOutput()
{
}

FileOutput::~FileOutput()
{
}

void FileOutput::open( std::string filename, std::ios_base::openmode mode )
{
    m_filename = filename;
    ofstream::open( filename, mode );
}

void FileOutput::open( const char* filename, ios_base::openmode mode )
{
    m_filename = filename;
    ofstream::open( filename, mode );
}

void FileOutput::close()
{
    if( is_open() )
    {
        ofstream::close();
    }

    unordered_map<string, FileOutput*>::iterator stream = s_map.find( m_filename );

    if( stream != s_map.end() )
    {
        s_map.erase( m_filename );
        delete this;
    }
}

FileOutput* FileOutput::GetStream( std::string filename )
{
    std::unordered_map<std::string, FileOutput*>::iterator stream = s_map.find( filename );

    if( stream != s_map.end() )
    {
        return stream->second;
    }
    else
    {
        FileOutput* fo = new FileOutput( filename );
        s_map.insert( std::pair<std::string, FileOutput*>( filename, fo ) );
        return fo;
    }
}

FileOutput* FileOutput::GetStream( const char* filename )
{
    return GetStream( std::string( filename ) );
}

void FileOutput::CloseAllStreams()
{
    for( unordered_map<std::string, FileOutput*>::iterator it = s_map.begin(); it != s_map.end(); ++it )
    {
        delete( it->second );
    }

    s_map.clear();
}

//------------------------------------------------------------------------------
// CSVOutput function definitions.
//------------------------------------------------------------------------------

CSVOutput::CSVOutput( string filename, ios_base::openmode mode ) :
    FileOutput( filename, mode )
{
}

CSVOutput::CSVOutput( const char* filename, ios_base::openmode mode ) :
    FileOutput( filename, mode )
{
}

CSVOutput::CSVOutput()
{
}

CSVOutput::~CSVOutput()
{
}

CSVOutput& CSVOutput::operator<<( char arg )
{
    FileOutput* fo = ( FileOutput* )this;
    *fo << arg;

    if( arg != '\n' )
    {
        *fo << ',';
    }

    return *this;
}

CSVOutput* CSVOutput::GetStream( std::string filename )
{
    std::unordered_map<std::string, FileOutput*>::iterator stream = s_map.find( filename );

    if( stream != s_map.end() )
    {
        return dynamic_cast<CSVOutput*>( stream->second );
    }
    else
    {
        CSVOutput* fo = new CSVOutput( filename );
        s_map.insert( std::pair<std::string, FileOutput*>( filename, fo ) );
        return fo;
    }
}

CSVOutput* CSVOutput::GetStream( const char* filename )
{
    return GetStream( std::string( filename ) );
}
