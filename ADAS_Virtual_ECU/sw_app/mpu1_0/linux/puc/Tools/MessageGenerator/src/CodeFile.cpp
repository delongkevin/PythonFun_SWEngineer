#include "CodeFile.h"
#include <iostream>
#include <fstream>

namespace mg
{

CodeFile::CodeFile( std::string fileName, std::string fileExtension )
  : m_generatedCode()
  , m_indentation(0)
  , m_fileName(fileName)
  , m_fileExtension(fileExtension)
{
}

/// the path and filename for the file to be created
void CodeFile::setFileName( const std::string& fileName, const std::string& fileExtension )
{
  m_fileName = fileName;
  m_fileExtension = fileExtension;
}

/// just the filename without the path
const std::string& CodeFile::getFileName( ) const
{
  return m_fileName;
}

/// filename together with the extension
std::string CodeFile::getCompleteFileName( ) const
{
  return m_fileName + '.' + m_fileExtension;
}

/// generate code from the AST and write it to the specified file
bool CodeFile::writeToDisk( const std::string& path, bool clearGeneratedCode )
{
  if(clearGeneratedCode)
    m_generatedCode.clear();

  // trigger code generation at the root of the AST
  // all child nodes generate their code recursively
  //if(m_rootElement)
  //  m_rootElement->generateCode(*this);

  // the generated result is contained in m_generatedCode
  // just write it to a file
  std::string completePath = path + '\\' + getCompleteFileName();
//  std::cout << "write generated code file: " << completePath << " ... ";
  std::ofstream fileStream;
  fileStream.open(completePath, std::ios::binary);
  if(fileStream.is_open())
  {
    fileStream << m_generatedCode;
    fileStream.close();
//    std::cout << "OK" << std::endl;
  }
  else
  {
//    std::cout << "could not write file!" << std::endl;
  }

//  std::cout << m_generatedCode;

  return true;
}

/// clear the AST
void CodeFile::clear( )
{

}

/// add a string to the generation output string
void CodeFile::addString( const std::string& content )
{
  m_generatedCode += content;
}

/// add a newline to the generation output string
/// indentation is added too
void CodeFile::addNewLine(unsigned int count /*= 1*/ )
{
  for (unsigned int i = 0; i < count; i++)
  {
    m_generatedCode += "\n";
  }

  addCurrentIndentation();
}

/// add a one-line-comment according to the configured style to the generation output string
void CodeFile::addOneLineComment( const std::string& commentContent )
{
  //CodeConfiguration::enuOneLineCommentStyle commentStyle = CodeConfiguration::instance()->getOneLineCommentStyle();

  //if(CodeConfiguration::c_style == commentStyle)
  //{
    m_generatedCode += "/* " + commentContent + " */";
  //}
  //else if(CodeConfiguration::cpp_style == commentStyle)
  //{
  //  m_generatedCode += "// " + commentContent;
  //}
}

void CodeFile::addBlank( unsigned int count)
{
  for (unsigned int index = 0; index < count; index++)
  {
    m_generatedCode += " ";
  }
}

/// add as much tab chars as required to reach the next tab-stop position
void CodeFile::addTabulator( unsigned int count )
{
  size_t tabulatorWidth = 2;

  if(count)
  {
    size_t currentLinePos;

    // find line start
    size_t lastNewlinePos = m_generatedCode.find_last_of("\n");
    if(lastNewlinePos == std::string::npos)
    {
      lastNewlinePos = 0;
      currentLinePos = m_generatedCode.length();
    }
    else
    {
      currentLinePos = m_generatedCode.length() - (lastNewlinePos + 1);
    }
    //std::cout << currentLinePos << std::endl;

    size_t missingTabCharCount = tabulatorWidth - (currentLinePos % tabulatorWidth);

    if(missingTabCharCount == 0)
      missingTabCharCount = tabulatorWidth;

    std::string missingChars;
    //missingChars.assign(CodeConfiguration::instance()->getTabulator().c_str(), missingTabCharCount);
    missingChars.assign(missingTabCharCount, ' ');

    m_generatedCode += missingChars;

    addTabulator(count - 1);
  }
}

/// add the actual indentation to the generation output string
void CodeFile::addCurrentIndentation( )
{
  //m_generatedCode += CodeConfiguration::instance()->getTabulator(m_indentation);

  addTabulator(m_indentation);
}

/// increase current indentation
void CodeFile::increaseIndentation( unsigned int count )
{
  m_indentation += count;
}

/// decrease current indentation
void CodeFile::decreaseIndentation( unsigned int count )
{
  m_indentation -= count;
}

/// add a open block and increase indentation
void CodeFile::openBlock(bool withNewLine /*= false*/ )
{
  addNewLine();
  m_generatedCode += "{";
  m_indentation++;
  if (withNewLine)
  {
    addNewLine();
  }
}

/// add a close block and decrease indentation
void CodeFile::closeBlock( bool withSemicolon )
{
  m_indentation--;
  addNewLine();
  m_generatedCode += "}";
  
  if(withSemicolon)
    m_generatedCode += ";";
}

}