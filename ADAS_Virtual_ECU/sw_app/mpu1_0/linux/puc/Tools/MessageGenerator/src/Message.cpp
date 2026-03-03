#include "Message.h"

#include <iostream>
#include <set>

namespace mg
{

  Message::Message()
    : m_Name("")
    , m_Id("-1")
    , m_SizeInBytes(0)
  {
    m_DataTypes.clear();
  }

  Message::~Message()
  {

  }

  bool Message::load(tinyxml2::XMLElement* elem)
  {
    m_DataTypes.clear();

    using namespace tinyxml2;

    m_Id.clear();
    m_Id = elem->Attribute("ID");
    if (m_Id.empty())
    {
      std::cout << "Message.cpp - Failed Querying ID" << std::endl;
      return false;
    }

    m_Name.clear();
    m_Name = elem->Attribute("Name");

    if (m_Name.empty())
    {
      std::cout << "Message.cpp - Failed Querying Name" << std::endl;
      return false;
    }

    // load Data Types.
    XMLElement* dataTypeElem = elem->FirstChildElement("DataType");
    if (!dataTypeElem)
    {
      std::cout << "Message.cpp - Error! No DataTypes Exist" << std::endl;
      return false;
    }

    bool loadOk = loadDataTypes(dataTypeElem);
    if (loadOk)
    {
      std::cout << "Message.cpp - Loaded Message: ID=" << m_Id << " Name= " << m_Name.c_str() << std::endl;
    }
    else
    {
      std::cout << "Message.cpp - Failed loading data types" << std::endl;
    }


    return loadOk;
  }

  bool Message::generate(CodeFile& codeFile)
  {
    // generate struct definitions used in the messages
    for (size_t i = 0; i < m_DataTypes.size(); ++i)
    {
      if (m_DataTypes[i].isStruct())
      {
        generateStruct(codeFile, m_DataTypes[i]);
      }
    }

    // first, generate array size constants
    generateSizeConstants(codeFile, m_DataTypes);


    // open struct
    codeFile.addString("typedef struct " + getName() + "_s");
    codeFile.openBlock();
    codeFile.addNewLine();

     // add data types
    bool dataTypeOk = true;
    for (size_t i = 0; i < m_DataTypes.size(); ++i)
    {
      bool lastEntry = (i == m_DataTypes.size() - 1);
      dataTypeOk &= m_DataTypes[i].generate(codeFile, lastEntry);
    }

    // close
    codeFile.closeBlock(false);
    codeFile.addString(" " + getStructName() + ";");
    codeFile.addNewLine();
    
    codeFile.addNewLine();

    return dataTypeOk;
  }

  bool Message::generateSizeConstants(CodeFile& codeFile, const DataTypeVector_t& dataTypes)
  {
    // generate Array Size Constants
    for (size_t i = 0; i < dataTypes.size(); ++i)
    {
      const DataType& dataType = dataTypes[i];
      if (dataType.isArray())
      {
        codeFile.addString("static const " + DataType::getDataType(e_Uint32_t) + " " + dataType.getArraySizeName() + " = " + dataType.getArrayLengthString() + ";");
        codeFile.addNewLine();
      }
    }

    return true;
  }

  bool Message::generateStruct(CodeFile& codeFile, DataType& dataType)
  {
    static std::set<std::string> generatedStructs;
    if (generatedStructs.find(dataType.getName()) == generatedStructs.end())
    {
      generatedStructs.insert(dataType.getName());
    }
    else
    {
      // already generated, we want to re-use this struct
      return true;
    }


    // open struct
    codeFile.addString("typedef struct " + dataType.getName() + "s");
    codeFile.openBlock();
    codeFile.addNewLine();

    // add data types
    bool dataTypeOk = true;
    for (size_t i = 0; i < dataType.getStructMembers().size(); ++i)
    {
      bool lastEntry = (i == dataType.getStructMembers().size() - 1);
      dataTypeOk &= dataType.getStructMembers().at(i).generate(codeFile, lastEntry);
    }

    // close
    codeFile.closeBlock(false);
    codeFile.addString(" " + dataType.getName() + "t" + ";");
    codeFile.addNewLine();

    codeFile.addNewLine();

    return dataTypeOk;
  }

  bool Message::loadDataTypes(tinyxml2::XMLElement* elem)
  {
    m_SizeInBytes = 0;

    while (elem != nullptr)
    {
      DataType dataType;

      dataType.load(elem, NULL);
      m_DataTypes.push_back(dataType);

      m_SizeInBytes += dataType.getSize();

      elem = elem->NextSiblingElement("DataType");
    }

    return true;
  }

} // namespace mg