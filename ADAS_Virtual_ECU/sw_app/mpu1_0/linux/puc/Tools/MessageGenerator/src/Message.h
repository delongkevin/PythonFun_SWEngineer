#pragma once

#include "DataType.h"
#include <vector>
#include "tinyxml2.h"
#include "CodeFile.h"

namespace mg
{

  typedef std::vector<DataType> DataTypeVector_t;

class Message
{
public:
  Message();
  ~Message();

  bool load(tinyxml2::XMLElement* elem);
  bool generate(CodeFile& codeFile);

  inline const std::string& getName()           { return m_Name;        }
  inline const std::string getStructName()      { return m_Name + "_t"; }
  inline const std::string getId()              { return m_Id;          }
  inline DataTypeVector_t& getDataTypes()       { return m_DataTypes;   }  
  inline unsigned int getSize() const           { return m_SizeInBytes; }

private:
  bool generateSizeConstants(CodeFile& codeFile, const DataTypeVector_t& dataTypes);
  bool generateStruct(CodeFile& codeFile, DataType& dataType);
  bool loadDataTypes(tinyxml2::XMLElement* elem);


private:
  std::string m_Name;
  std::string m_Id;
  unsigned int m_SizeInBytes;   // no alignment size, just sum size for each datatype
  DataTypeVector_t m_DataTypes;
};


} // namespace mg