#include "DataType.h"

#include <iostream>
#include <string>
#include <assert.h>

namespace mg
{

  DataType::DataType()
    : m_Type_e(e_DataTypeInvalid)
    , m_TypeString("")
    , m_Name("")
    , m_Comment("")
    , m_ArraySizeName("")
    , m_ArrayLength(0)
    , m_BitLength(0)
    , m_SizeInBytes(0)
    , m_StructName("")
  {
    m_StructMembers.clear();
  }

  DataType::~DataType()
  {

  }

  bool DataType::load(tinyxml2::XMLElement* elem, DataType* parent)
  {
    // load type
    m_TypeString = elem->Attribute("Type");
    if (m_TypeString.empty())
    {
      std::cout << "DataType.cpp - Failed to load Type" <<  std::endl;
      return false;
    }

    m_Type_e = getDataType(m_TypeString);
    if (m_Type_e == e_DataTypeInvalid)
    {
      std::cout << "DataType.cpp - Unsupported Data Type" <<  std::endl;
      return false;
    }

    // load name
    m_Name.clear();
    m_Name = elem->Attribute("Name");
    if (m_Name.empty())
    {
      std::cout << "DataType.cpp - Missing Name Attribute" <<  std::endl;
      return false;
    }

    // load Array length (optional)
    m_ArrayLength = 0;
    elem->QueryUnsignedAttribute("ArrayLength", &m_ArrayLength);

    m_ArraySizeName.clear();
    if (isArray())
    {
      m_ArraySizeName = elem->Attribute("ArraySizeName");
      if (m_ArraySizeName.empty())
      {
        std::cout << "DataType.cpp - Missing ArraySizeName Attribute" <<  std::endl;
        return false;
      }
    }

    // load Bit Length (optional)
    m_BitLength = 0;
    elem->QueryUnsignedAttribute("BitLength", &m_BitLength);

    // this case does not make sense
    if (isArray() && isBitField())
    {
      std::cout << "DataType.cpp - Error: Array length AND BitLength are set!" <<  std::endl;
      return false;
    }

    //check if user commented this data type
    m_Comment.clear();
    const char* comment = elem->Attribute("Comment");
    if (comment)
    {
      m_Comment = std::string(comment);
    }

    // set the name conformant to our code convention
    m_Name += "_";

    if (isArray())
    {
      m_Name += "a";
    }

    // spcial case due to our code convention!
    if (!isStruct())
    {
      m_Name += getDataTypeSuffix(m_Type_e);
    }

    // todo correct count
    uint32_t sizeInBytes = getDataTypeSize(m_Type_e);
    if (isArray())
      sizeInBytes *= m_ArrayLength;
    m_SizeInBytes = sizeInBytes;

    //special case for structs
    if (isStruct())
    {
      m_StructName = elem->Attribute("StructName");
      if (m_StructName.empty())
      {
        std::cout << "DataType.cpp - Error: No StructName set but DataType is struct. use StructName=\"BitFieldStructName\" in DataType node!" <<  std::endl;
        return false;
      }

      elem = elem->FirstChildElement("DataType");

      uint32_t structBitSize = 0U;
      while (elem != nullptr)
      {
        DataType dataType;
        dataType.load(elem, this);
        m_StructMembers.push_back(dataType);
        structBitSize += dataType.m_BitLength;

        elem = elem->NextSiblingElement("DataType");
      }
      m_SizeInBytes = structBitSize / 8;

      if (structBitSize % 8 != 0)
      {
        std::cout << "DataType.cpp - Error: Number of struct members must be dividable by eight!" <<  std::endl;
        return false;
      }

      for (size_t i = 0; i < m_StructMembers.size(); ++i)
      {
        if (m_StructMembers[i].getBitLength() != 1)
        {
          std::cout << "DataType.cpp - Error: Only bit lengths of 1 is supported right now!" <<  std::endl;
          return false;
        }
      }

    }


    return true;
  }

  bool DataType::generate(CodeFile& codeFile, bool lastEntry) const
  {
    if (isStruct())
    {
      codeFile.addString(m_Name + "t" + " ");
      codeFile.addString(m_StructName);
    }
    else
    {
      codeFile.addString(m_TypeString + " ");
      codeFile.addString(m_Name);

      if (isArray())
      {
        codeFile.addString("[" + m_ArraySizeName + "]");
      }

      if (isBitField())
      {
        codeFile.addString(" : " + ItoA(m_BitLength));
      }
    }

    codeFile.addString(";");

    if (isCommented())
    {
      codeFile.addString(" ");
      codeFile.addOneLineComment(m_Comment);
    }

    if (!lastEntry)
    {
      codeFile.addNewLine();
    }


    return true;
  }

  std::string DataType::getDataType(DataTypes_e dataType)
  {
    switch (dataType)
    {
    case e_Bool_t:    return "bool_t"; 
    case e_Uint8_t:   return "uint8_t"; 
    case e_Uint16_t:  return "uint16_t";
    case e_Uint32_t:  return "uint32_t";
    case e_Uint64_t:  return "uint64_t";
    case e_Sint8_t:   return "sint8_t";
    case e_Sint16_t:  return "sint16_t";
    case e_Sint32_t:  return "sint32_t";
    case e_Sint64_t:  return "sint64_t";
    case e_Float32_t: return "float32_t"; 
    case e_Float64_t: return "float64_t";
    case e_Struct:    return "struct";
    }

    std::cout << "DataType - getDataType: Failed to map enum to string" << std::endl;
    return std::string();
  }

  std::string DataType::getDataTypeSuffix(DataTypes_e dataType)
  {
    switch (dataType)
    {
    case e_Bool_t:    return "b"; 
    case e_Uint8_t:   return "u8"; 
    case e_Uint16_t:  return "u16";
    case e_Uint32_t:  return "u32";
    case e_Uint64_t:  return "u64";
    case e_Sint8_t:   return "s8";
    case e_Sint16_t:  return "s16";
    case e_Sint32_t:  return "s32";
    case e_Sint64_t:  return "s64";
    case e_Float32_t: return "f32"; 
    case e_Float64_t: return "f64";
    case e_Struct:    return "s";
    }

    std::cout << "DataType - getDataType: Failed to map enum to string" << std::endl;
    return std::string();
  }

  uint32_t DataType::getDataTypeSize(DataTypes_e dataType)
  {
    switch (dataType)
    {
    case e_Bool_t:    return 1; 
    case e_Uint8_t:   return 1; 
    case e_Uint16_t:  return 2;
    case e_Uint32_t:  return 4;
    case e_Uint64_t:  return 8;
    case e_Sint8_t:   return 1;
    case e_Sint16_t:  return 2;
    case e_Sint32_t:  return 4;
    case e_Sint64_t:  return 8;
    case e_Float32_t: return 4; 
    case e_Float64_t: return 8;
    case e_Struct:  
      {
        uint32_t structMemberSize = 0;
        for (size_t i = 0; i < m_StructMembers.size(); ++i)
        {
          structMemberSize += m_StructMembers[i].getDataTypeSize(m_StructMembers[i].getDataType());
        }
        return structMemberSize;
      }
    }

    std::cout << "DataType - getDataTypeSize: Failed to map enum to string" << std::endl;
    return 0;
  }

  std::string DataType::getDataTypeSizeString(DataTypes_e dataType)
  {
    return ItoA(getDataTypeSize(dataType));
  }

  DataTypes_e DataType::getDataType(const std::string& dataType)
  {
    if (dataType == "bool_t")
      return e_Bool_t;
    else if (dataType == "uint8_t")
      return e_Uint8_t;
    else if(dataType == "uint16_t")
      return e_Uint16_t;
    else if(dataType == "uint32_t")
      return e_Uint32_t;
    else if(dataType == "uint64_t")
      return e_Uint64_t;
    else if (dataType == "sint8_t")
      return e_Sint8_t;
    else if (dataType == "sint16_t")
      return e_Sint16_t;
    else if (dataType == "sint32_t")
      return e_Sint32_t;
    else if (dataType == "sint64_t")
      return e_Sint64_t;
    else if (dataType == "float32_t")
      return e_Float32_t;
    else if (dataType == "float64_t")
      return e_Float64_t;
    else if (dataType == "struct")
      return e_Struct;

    std::cout << "DataType - getDataType: Failed to map string to enum" << std::endl;
    return e_DataTypeInvalid;
  }

  std::string DataType::ItoA(unsigned int value)
  {
    char buffer[256];
    _itoa_s(value, &buffer[0], 256, 10);
    return std::string(&buffer[0]);
  }

  std::string DataType::ItoA(int value)
  {
    char buffer[256];
    _itoa_s(value, &buffer[0], 256, 10);
    return std::string(&buffer[0]);
  }

} // namespace mg