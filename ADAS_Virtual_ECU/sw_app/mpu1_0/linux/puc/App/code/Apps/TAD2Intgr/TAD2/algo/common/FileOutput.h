// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [15-Jan-2019]
// --- Last Modified by Joshua Teichroeb [07-Jan-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __FILE_OUTPUT__H_
#define __FILE_OUTPUT__H_

#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

/**
* General file Output class with static storing.
*/
class FileOutput : public std::ofstream
{
public:
    explicit FileOutput( std::string filename, std::ios_base::openmode mode = std::ios_base::out );
    explicit FileOutput( const char* filename, std::ios_base::openmode mode = std::ios_base::out );
    FileOutput();
    virtual ~FileOutput();

    virtual void open( std::string filename, std::ios_base::openmode mode = std::ios_base::out );
    virtual void open( const char* filename, std::ios_base::openmode mode = std::ios_base::out );
    virtual void close();

    template<typename T>
    FileOutput& operator<<( T arg );

    static FileOutput* GetStream( std::string filename );
    static FileOutput* GetStream( const char* filename );
    static void CloseAllStreams();

protected:
    std::string m_filename;

    static std::unordered_map<std::string, FileOutput*> s_map;

};

/**
* CSV Output class.
*/
class CSVOutput : public FileOutput
{
public:
    explicit CSVOutput( std::string filename, ios_base::openmode mode = ios_base::out );
    explicit CSVOutput( const char* filename, ios_base::openmode mode = ios_base::out );
    CSVOutput();
    virtual ~CSVOutput();

    template<typename T>
    CSVOutput& operator<<( T arg );
    CSVOutput& operator<<( char arg );

    static CSVOutput* GetStream( std::string filename );
    static CSVOutput* GetStream( const char* filename );

};

//------------------------------------------------------------------------------
// FileOutput template function definitions.
//------------------------------------------------------------------------------

template<typename T>
inline FileOutput& FileOutput::operator<<( T arg )
{
    std::ofstream* fo = ( std::ofstream* )this;
    *fo << arg;
    return *this;
}

//------------------------------------------------------------------------------
// CSVOutput template function definitions.
//------------------------------------------------------------------------------

template<typename T>
inline CSVOutput& CSVOutput::operator<<( T arg )
{
    FileOutput* fo = ( FileOutput* )this;
    *fo << arg << ',';
    return *this;
}

#endif // !__FILE_OUTPUT__H_
