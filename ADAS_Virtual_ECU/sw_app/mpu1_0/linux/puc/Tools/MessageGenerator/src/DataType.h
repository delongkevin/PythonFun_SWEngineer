#pragma once

#include <string>
#include <vector>
#include "tinyxml2.h"
#include "CodeFile.h"


namespace mg
{

enum DataTypes_e
{
  e_DataTypeInvalid = -1,
  
  e_Bool_t,
  e_Uint8_t,
  e_Uint16_t,
  e_Uint32_t,
  e_Uint64_t,

  e_Sint8_t,
  e_Sint16_t,
  e_Sint32_t,
  e_Sint64_t,
  
  e_Float32_t,
  e_Float64_t,

  e_Struct,
  
  e_DataTypeCount
};

class DataType
{
public:
  DataType();
  virtual ~DataType();

  bool load(tinyxml2::XMLElement* elem, DataType* parent);  
  bool generate(CodeFile& codeFile, bool lastEntry) const;

  inline bool isArray() const                             { return m_ArrayLength > 0;     }
  inline bool isBitField() const                          { return m_BitLength > 0;       }
  inline bool isStruct() const                            { return m_Type_e == e_Struct;  }
  inline unsigned int getArrayLength() const              { return m_ArrayLength;         }
  inline std::string getArrayLengthString() const         { return ItoA(m_ArrayLength);   }
  inline const std::string& getArraySizeName() const      { return m_ArraySizeName;       }
  inline unsigned int getBitLength() const                { return m_BitLength;           }
  inline const std::string& getName() const               { return m_Name;                }
  inline const std::string& getStructName() const         { return m_StructName;          }
  inline DataTypes_e getDataType() const                  { return m_Type_e;              }
  inline bool isCommented() const                         { return !m_Comment.empty();    }
  inline unsigned int getSize() const                     { return m_SizeInBytes;         }
  inline std::vector<DataType>& getStructMembers()        { return m_StructMembers;       }


  static std::string getDataType(DataTypes_e dataType);
  static std::string getDataTypeSuffix(DataTypes_e dataType);
  uint32_t    getDataTypeSize(DataTypes_e dataType);
  std::string getDataTypeSizeString(DataTypes_e dataType);
  static DataTypes_e getDataType(const std::string& dataType);
  static std::string ItoA(unsigned int value);
  static std::string ItoA(int value);

private:
  DataTypes_e m_Type_e;
  std::string m_TypeString;
  std::string m_Name;
  std::string m_Comment;       // optional, Comment
  std::string m_ArraySizeName; // optional, bust must be set if arrayLength > 0
  unsigned int m_ArrayLength;  // optional
  unsigned int m_BitLength;    // optional
  unsigned int m_SizeInBytes;
  std::string m_StructName; // optional, bust must be set if contains struct members
  std::vector<DataType> m_StructMembers;
};


} // namespace mg