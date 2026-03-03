#include "CodeWriter.h"

#include <fstream>
#include <iomanip>    // Needed for stream modifiers fixed and setprecision
#include <algorithm>

namespace tsdk
{

CodeWriter::CodeWriter()
  : stream()
  , fileName()
  , nameSpace()
  , numSpaces(0U)
  , maxArrayEntriesPerRow(0U)
  , isHeader_b(false)
  , fileType_e(e_FT_None)
{

}

CodeWriter::~CodeWriter()
{

}

void CodeWriter::begin_b(const std::string& i_FileName_ro, const std::string& i_NameSpace_ro, bool i_IsHeader_b, std::vector<std::string>* i_Includes_po)
{
  fileName    = i_FileName_ro;
  nameSpace   = i_NameSpace_ro;
  isHeader_b  = i_IsHeader_b;

  // Generate file
  std::string generatedFileName = fileName;
  if (i_IsHeader_b)
  {
    generatedFileName += ".h";
  }
  else
  {
    generatedFileName += ".cpp";
  }
  stream = std::ofstream(generatedFileName);
  
  // write includes if we have any
  if (NULL != i_Includes_po)
  {
    for (uint32_t i = 0; i < i_Includes_po->size(); ++i)
    {
      const std::string& current = i_Includes_po->at(i);
      stream << current.c_str() << std::endl;
    }

    newLine();
  }

  // write ifndef define if this is a header
  if (isHeader_b)
  {
    std::string upperFileName = fileName;
    std::transform(upperFileName.begin(), upperFileName.end(), upperFileName.begin(), ::toupper);
    stream << "#ifndef " << upperFileName.c_str() << "_H" << std::endl;
    stream << "#define " << upperFileName.c_str() << "_H" << std::endl << std::endl;
  }

  stream << "namespace " << nameSpace.c_str() << std::endl;
  stream << "{" << std::endl << std::endl;
}

void CodeWriter::writeClassName()
{
  fileType_e = e_FT_Class;

  stream << "class " << fileName.c_str() << std::endl;
  stream << "{" << std::endl;

  stream << "public:" << std::endl;

  numSpaces += 2;
}

void CodeWriter::writeStructName()
{
  fileType_e = e_FT_Struct;

  stream << "struct " << fileName.c_str() << std::endl;
  stream << "{" << std::endl;

  numSpaces += 2;
}

void CodeWriter::write(const std::string& i_String_ro, bool i_NewLine_b /*= false*/)
{
  writeSpaces();
  stream << i_String_ro.c_str();
  
  if (i_NewLine_b)
  {
    stream << std::endl;
  }
}

void CodeWriter::newLine()
{
  stream << std::endl;
}

void CodeWriter::declareVariable(const std::string& i_Name, const std::string& i_Type_ro, std::vector<std::string>* i_Parameters_po, bool i_Const /*= false*/, bool i_Static /*= false*/)
{
  writeSpaces();

  if (i_Static)
  {
    stream << "static ";
  }

  if (i_Const)
  {
    stream << "const ";
  }

  stream << i_Type_ro.c_str();
  stream << " " << i_Name.c_str();

  if (NULL != i_Parameters_po)
  {
    stream << +"(";

    for (uint32_t i = 0; i < i_Parameters_po->size(); ++i)
    {
      stream << i_Parameters_po->at(i).c_str();

      if (i != i_Parameters_po->size() - 1)
      {
        stream << ", ";
      }
    }

    stream << ")";

  }

  stream << ";" << std::endl;
}

void CodeWriter::end_b()
{
  if (fileType_e == e_FT_Class || 
      fileType_e == e_FT_Struct)
  {
    stream << "};" << std::endl;
  }

  stream << std::endl << "} // namespace " << nameSpace.c_str() << std::endl << std::endl;

  if (isHeader_b)
  {
    stream << "#endif" << std::endl;
  }
  
  stream.close();
}

void CodeWriter::setMaxArrayEntriesPerRow(unsigned int val)
{
  maxArrayEntriesPerRow = val;
}

void CodeWriter::addOrRemoveSpaces(int i_Val)
{
  numSpaces += i_Val;
}

void CodeWriter::writeSpaces()
{
  for (unsigned int i = 0; i < numSpaces; ++i)
  {
    stream << " ";
  }
}

} // namespace tsdk