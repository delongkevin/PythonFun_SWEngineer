/// @file CodeFile.h
/// @brief code-file handling
/// 
/// This class encapsulates file handling and provides functionality
/// to to write strings, newlines, comments and code blocks.
/// Indentation is automatically applied.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Michael Lehmann (Michael.Lehmann@partner.magna.com)

#pragma once

#include <string>

namespace mg
{

class CodeFile
{
  public:
    CodeFile( std::string fileName = "", std::string fileExtension = "" );

    void                setFileName( const std::string& fileName, const std::string& fileExtension );
    const std::string&  getFileName( ) const;
    std::string         getCompleteFileName( ) const;
    bool                writeToDisk( const std::string& path, bool clearGeneratedCode = true );
    void                clear( );

    void                addString( const std::string& content );
    void                addNewLine( unsigned int count = 1 );
    void                addOneLineComment( const std::string& commentContent );
    void                addBlank( unsigned int count = 1 );
    void                addTabulator( unsigned int count = 1 );
    void                addCurrentIndentation( );
    void                increaseIndentation( unsigned int count = 1 );
    void                decreaseIndentation( unsigned int count = 1 );
    void                openBlock( bool withNewLine = false );
    void                closeBlock( bool withSemicolon = true );

  protected:
    std::string         m_generatedCode;
    unsigned int        m_indentation;
    std::string         m_fileName;
    std::string         m_fileExtension;
};

} // namespace mg
