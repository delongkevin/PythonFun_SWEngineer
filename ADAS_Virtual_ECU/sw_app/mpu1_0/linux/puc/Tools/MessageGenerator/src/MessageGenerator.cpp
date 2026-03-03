#include "MessageGenerator.h"

#include <string.h>
#include <iostream>
#include <cctype>
#include <algorithm>



namespace mg
{

MessageGenerator::MessageGenerator()
  : m_FileName("")
{
  m_CodeFile.clear();
  m_AdditionalIncludes.clear();
  m_Messages.clear();

  m_EnumName = "MessageID";
  m_Enums.clear();
}

MessageGenerator::~MessageGenerator()
{
  m_Messages.clear();
}

bool MessageGenerator::load(const char* xmlFile)
{
  m_Messages.clear();

  bool success = (m_Doc.LoadFile(xmlFile) == tinyxml2::XML_SUCCESS);

  if (!success)
  {
    std::cout << "Error parsing XML File" << std::endl;
    return false;
  }

  tinyxml2::XMLElement* configRoot = m_Doc.FirstChildElement("Configuration");
  if (configRoot)
  {
    std::cout << "Configuration Tag found, loading config..." << std::endl;
    loadConfiguration(configRoot);
  }
  else
  {
    std::cout << "No Config found. Processing further..." << std::endl;
  }


  tinyxml2::XMLElement* messagesRoot = m_Doc.FirstChildElement("Messages");
  if (!messagesRoot)
  {
    std::cout << "No Messages Root Tag found" << std::endl;
    return false;
  }
  
  tinyxml2::XMLElement* messageElem = messagesRoot->FirstChildElement("Message");
  if (!messageElem)
  {
    std::cout << "No Message Tag found" << std::endl;
    return false;
  }
  else
  {
    loadMessageElement(messageElem);
  }

  return true;
}

void MessageGenerator::loadMessageElement(tinyxml2::XMLElement* elem)
{
  while (elem != nullptr)
  {
    Message msg;
    msg.load(elem);
    m_Messages.push_back(msg);

    // check for further messages
    elem = elem->NextSiblingElement("Message");
  }
}

void MessageGenerator::loadConfiguration(tinyxml2::XMLElement* elem)
{
  tinyxml2::XMLElement* addIncludesElem = elem->FirstChildElement("AdditionalIncludes");
  if (addIncludesElem)
  {
    std::cout << "found additional includes" << std::endl;
    loadIncludes(addIncludesElem->FirstChildElement("Include"));
  }
}

void MessageGenerator::loadIncludes(tinyxml2::XMLElement* elem)
{
  while (elem != nullptr)
  {
    const char* includeText = elem->Attribute("Text");

    if (includeText)
    {
      m_AdditionalIncludes.push_back(std::string(includeText));
    }

    // check for further includes
    elem = elem->NextSiblingElement("Include");
  }
}

bool MessageGenerator::generateIncludeGuardBegin()
{
  std::string fileNameCopy = m_FileName;
  std::transform(fileNameCopy.begin(), fileNameCopy.end(), fileNameCopy.begin(), toupper);

  std::string includeGuardName = fileNameCopy + "_H";

  m_CodeFile.addString("#ifndef " + includeGuardName);
  m_CodeFile.addNewLine();
  m_CodeFile.addString("#define " + includeGuardName);
  m_CodeFile.addNewLine();
  m_CodeFile.addNewLine();

  return true;
}


bool MessageGenerator::generateIncludes()
{
  // add the header needed for read/write functions for supported data types
  for (size_t i = 0; i < m_AdditionalIncludes.size(); ++i)
  {
    m_CodeFile.addString("#include \""+ m_AdditionalIncludes[i] + "\"");
    
    m_CodeFile.addNewLine();
  }

  m_CodeFile.addNewLine();
  m_CodeFile.addNewLine();

  return true;
}

bool MessageGenerator::generate(const char* outPath, const char* fileName, const char* networkendianness)
{
  // configure file name
  m_FileName = fileName;
  m_CodeFile.setFileName(m_FileName, "h");

  int v_networkendianness = atoi(networkendianness);
  
  if(0 == v_networkendianness)
  {
    // little
    m_networkendianness = "false";
  }
  else
  {
    // big
    m_networkendianness = "true";
  }

  generateIncludeGuardBegin();

  generateIncludes();

  m_CodeFile.addString("#pragma pack(1) // exact fit - no padding // PRQA S 1040 // pragma needed for structures");
  m_CodeFile.addNewLine();

  m_CodeFile.addString("// PRQA S 2000 EOF // global scope, this is a header file");
  m_CodeFile.addNewLine();

  m_CodeFile.addString("// PRQA S 2400 EOF // global scope, this is a header file");
  m_CodeFile.addNewLine();

  m_CodeFile.addString("// PRQA S 2300 EOF // global scope, this is a header file");
  m_CodeFile.addNewLine();

  m_CodeFile.addNewLine();

  // write structs for all messages
  m_CodeFile.addOneLineComment(" --- Structs ---");
  
  m_CodeFile.addNewLine();
  for (size_t i = 0; i < m_Messages.size(); ++i)
  {
    m_Messages[i].generate(m_CodeFile);
  }

  // generate the enum mapping enum entry to ID
  generateEnum();
  generateEnumToMsgIdMapping();

  // generates a function to write the MessageID enum value to message.
  generateAddHeaderToMessage();

  // generate the serializer for reading and writing data
  generateRead();
  generateWrite();

  m_CodeFile.addNewLine();
  m_CodeFile.addString("#pragma pack() //back to whatever the previous packing mode was // PRQA S 1040 // pragma needed for structures");
  m_CodeFile.addNewLine();

  generateIncludeGuardEnd();

  return m_CodeFile.writeToDisk(outPath, false);
}

bool MessageGenerator::generateEnum()
{
  m_CodeFile.addNewLine();
  m_CodeFile.addOneLineComment(" --- Message Type to ID Mapping ---");
  m_CodeFile.addNewLine();

  m_CodeFile.addString("typedef enum " + m_EnumName + "_e");
  m_CodeFile.openBlock();
  m_CodeFile.addNewLine();

  std::string unknownEnumEntry = "e_Unknown";
  m_CodeFile.addString(unknownEnumEntry + " = 0x0,");
  m_CodeFile.addNewLine();

  m_Enums.push_back(EnumToId_s(unknownEnumEntry, "0"));

  // now create all enums
  for (size_t i = 0; i < m_Messages.size(); ++i)
  {
    std::string enumName = "e_" + m_Messages[i].getName();
    m_CodeFile.addString(enumName);

    // add id to enum
    std::string hex = "0x";
    m_CodeFile.addString(" = " + hex + m_Messages[i].getId());

    m_Enums.push_back(EnumToId_s(enumName, m_Messages[i].getId()));

    // only add new line and ,if no last Entry
    if (i != m_Messages.size() -1)
    {
      m_CodeFile.addString(",");
      m_CodeFile.addNewLine();
    }
  }

  m_CodeFile.closeBlock(false);
  m_CodeFile.addString(" " + m_EnumName + "_t;");
  m_CodeFile.addNewLine();

  return true;
}

bool MessageGenerator::generateEnumToMsgIdMapping()
{
  m_CodeFile.addNewLine();

  std::string dataType = "uint8_t*";
  std::string dataParam = "b_data_pu8";
  std::string dataType1 = "uint32_t*";
  std::string dataParam1 = "b_IDLength_pu32";
  std::string enumDataType = m_EnumName + "_t";
  
  m_CodeFile.addOneLineComment("Advances data pointer and returns the message ID");
  m_CodeFile.addNewLine();
  m_CodeFile.addString("ME_INLINE " + enumDataType + " getMessageId_e(const " + dataType + " " + dataParam + ", " + dataType1 + " " + dataParam1 + ")");
  m_CodeFile.openBlock();
  m_CodeFile.addNewLine();

  std::string enumVariable = "v_Enum_e";
  m_CodeFile.addString(enumDataType + " " + enumVariable + " = " + m_Enums[0].Name + ";");
  m_CodeFile.addNewLine();

  std::string dataIdType = "uint16_t";
  std::string dataIdVariable = "v_DataId_u16";

  std::string IndexVariable = "v_Index_u32";
  m_CodeFile.addString("uint32_t " + IndexVariable + " = 0;");
  m_CodeFile.addNewLine();
  m_CodeFile.addNewLine();

  m_CodeFile.addOneLineComment("Read Id from Data Pointer");
  m_CodeFile.addNewLine();
  m_CodeFile.addString(dataIdType + " " + dataIdVariable + " = " + "ME_DataSerializer_Read_u16(" + dataParam + ", " + "&" + IndexVariable + ", " + m_networkendianness + ");");
  m_CodeFile.addNewLine();
  m_CodeFile.addNewLine();

  /*
  m_CodeFile.addOneLineComment("Advance Data Pointer");
  m_CodeFile.addNewLine();
  m_CodeFile.addString("*" + dataParam + " += " + IndexVariable + ";");
  m_CodeFile.addNewLine();
  m_CodeFile.addNewLine();
  */

  // get switch statement
  m_CodeFile.addString("switch ("+ dataIdVariable + ")");
  m_CodeFile.openBlock();
  m_CodeFile.addNewLine();

  // first entry is unknown enum, so skip it
  for (size_t i = 1; i < m_Enums.size(); ++i)
  {
    //case e_BootState: v_Enum_e = e_BootState; break;
    m_CodeFile.addString("case " + m_Enums[i].Name + ":");
    m_CodeFile.openBlock();
    m_CodeFile.addNewLine();
    m_CodeFile.addString(enumVariable + " = " + m_Enums[i].Name + ";");
    m_CodeFile.addNewLine();
    m_CodeFile.addString("break;");
    m_CodeFile.closeBlock(false);
    m_CodeFile.addNewLine();
  }

  m_CodeFile.addString("default:");
  m_CodeFile.openBlock();
  m_CodeFile.addNewLine();
  //m_CodeFile.addString(enumVariable + " = " + dataIdVariable + ";");
  m_CodeFile.addString("break;");
  m_CodeFile.closeBlock(false);


  m_CodeFile.closeBlock(false);
  m_CodeFile.addNewLine();
  m_CodeFile.addNewLine();


  // New if statement
  m_CodeFile.addString("if (NULL != " + dataParam1 + ")");
  
  m_CodeFile.openBlock();
    m_CodeFile.addNewLine();
    m_CodeFile.addString("if(" + m_Enums[0].Name + " != " + enumVariable + ")");
    m_CodeFile.openBlock();
      m_CodeFile.addNewLine();
      m_CodeFile.addString("*" + dataParam1 + " = " + IndexVariable + ";");
    m_CodeFile.closeBlock(false);
    m_CodeFile.addNewLine();
    m_CodeFile.addString("else");
    m_CodeFile.openBlock();
      m_CodeFile.addNewLine();
      m_CodeFile.addString("*" + dataParam1 + " = " + "0" + ";");
    m_CodeFile.closeBlock(false);
  m_CodeFile.closeBlock(false);
  m_CodeFile.addNewLine();
  // End of if statement

  m_CodeFile.addNewLine();
  m_CodeFile.addString("return " + enumVariable + ";");
  m_CodeFile.closeBlock(false);
  m_CodeFile.addNewLine();

  return true;
}



bool MessageGenerator::generateAddHeaderToMessage()
{
	m_CodeFile.addNewLine();
	m_CodeFile.addOneLineComment(" --- AddHeaderToMessage ---");

  m_CodeFile.addNewLine();
  m_CodeFile.addOneLineComment(" --- Usage: &array[0] and for further read/write use array[2] index 2 is returned by this function because we write 2 bytes in this protocol ---");
  m_CodeFile.addNewLine();

  std::string dataNameType = "uint8_t* ";
  std::string dataName = "b_Data_pc";
  std::string returnDataType = "uint32_t";
  std::string indexName = "v_Index_u32";
  std::string enumDataType = m_EnumName + "_t";
  std::string enumName = "i_MessageID_t";

  m_CodeFile.addString("ME_INLINE " + returnDataType + " addHeaderToMessage_u32(" + dataNameType + dataName + ", " + enumDataType + " " + enumName + ")");

  m_CodeFile.openBlock();
  m_CodeFile.addNewLine();

  // Generate : uint32_t v_Index_u32 = 0;
  m_CodeFile.addString(DataType::getDataType(e_Uint32_t) + " " + indexName + " = 0;");
  m_CodeFile.addNewLine();
  m_CodeFile.addNewLine();


  // now start writing the function code to serialize the enum
  std::string writeFunction = "ME_DataSerializer_Write_" + DataType::getDataTypeSuffix(e_Uint16_t) + "(" + 
    dataName + ", " + 
    "&" + indexName + ", " + 
    "(uint16_t)" + enumName + ", " + 
    m_networkendianness + ");";
  
  m_CodeFile.addString(writeFunction);

  m_CodeFile.addNewLine();
  m_CodeFile.addNewLine();

  m_CodeFile.addString("return " + indexName + ";");

  m_CodeFile.closeBlock();
  m_CodeFile.addNewLine();

  return true;
}

bool MessageGenerator::generateRead()
{
  m_CodeFile.addNewLine();
  m_CodeFile.addOneLineComment(" --- Read Functions ---");
  m_CodeFile.addNewLine();

  std::string dataNameType = "const uint8_t* ";
  std::string dataName = "i_Data_pc";
  std::string dataLengthNameType = "uint32_t ";
  std::string dataLengthName = "i_DataLength_u32";
  std::string returnDataType = "bool_t";
  std::string returnDataName = "v_Valid_b";
  std::string indexName = "v_Index_u32";
  std::string bitfieldDataName = "v_BitFieldData_u8";

  for (size_t i = 0; i < m_Messages.size(); ++i)
  {
    Message& msg = m_Messages[i];

    // start function for read
    std::string structParamName = "b_" + msg.getName() + "_ps";
    std::string structNameType = msg.getStructName() + "* ";

    m_CodeFile.addString("ME_INLINE " + returnDataType + " read" + msg.getName() + "_b(" + 
      dataNameType + dataName + ", " + 
      dataLengthNameType + dataLengthName + ", " + 
      structNameType + structParamName + ")");
    m_CodeFile.openBlock();

    // now start writing the function code
    m_CodeFile.addNewLine();

    // generate bool_t v_Valid_b = ( struct length < dataLengthName)
    m_CodeFile.addString(returnDataType + " " + returnDataName + " = (" + dataLengthName + " >= " + DataType::ItoA(msg.getSize()) + ");");
    m_CodeFile.addNewLine();
    m_CodeFile.addNewLine();

    // generate if (true == v_Valid_b)
    m_CodeFile.addString("if (true == " + returnDataName + ")");
    m_CodeFile.openBlock();
    m_CodeFile.addNewLine();

    // Generate : uint32_t v_Index_u32 = 0;
    m_CodeFile.addString(DataType::getDataType(e_Uint32_t) + " " + indexName + " = 0;");
    m_CodeFile.addNewLine();
    m_CodeFile.addNewLine();

    // Generate: b_TestAllDataTypes_ps->Test_u8 = read_u8(i_Data_pc, &v_Index_u32); for all data Types
    DataTypeVector_t& dataTypes = msg.getDataTypes();
    for (size_t j = 0; j < dataTypes.size(); ++j)
    {
      DataType& currData = dataTypes[j];

      std::string readFunction = "ME_DataSerializer_Read_" + DataType::getDataTypeSuffix(currData.getDataType()) + "(" + dataName + ", " + "&" + indexName + ", " + m_networkendianness + ");";
      std::string structParamDeref = structParamName + "->" + currData.getName();

      // special case for array
      if (currData.isArray())
      {
        m_CodeFile.addNewLine();

        std::string arrayLengthNumber = currData.getArraySizeName();
        std::string forIndexVariable = "v_I_u32";
        std::string indexDataType = DataType::getDataType(e_Uint32_t);

        m_CodeFile.addString("for (" + indexDataType + " " + forIndexVariable + " = 0; " + forIndexVariable + " < " + arrayLengthNumber + "; ++" + forIndexVariable + ")");
        m_CodeFile.openBlock();

        m_CodeFile.addNewLine();
        m_CodeFile.addString(structParamDeref + "[" + forIndexVariable + "] = " + readFunction);

        m_CodeFile.closeBlock(false);
      }
      else if (currData.isStruct())
      {
        std::string structParamDerefStruct = structParamName + "->" + currData.getStructName();
        
        size_t structBitIdx = 0;
        for (size_t k = 0; k < currData.getStructMembers().size(); ++k)
        {
          DataType structDataType = currData.getStructMembers().at(k); 
          std::string structParamDerefStructMember = structParamDerefStruct + "." + structDataType.getName();

          size_t bitStartIdx = 0;
          for(size_t i = 0; i < structDataType.getBitLength(); ++i)
          { 
            std::string shiftOpTxt("<<");
            size_t bitIndex = structBitIdx % 8;
            int bitShift = 0;

            if (bitIndex == 0)
            {
              if (structBitIdx == 0)
              {
                m_CodeFile.addString(DataType::getDataType(e_Uint8_t) + " ");
              }
              else
              {
                m_CodeFile.addNewLine();
              }

              std::string readbitFieldFunction = bitfieldDataName + " = ME_DataSerializer_Read_u8(" + dataName + ", " + "&" + indexName + ", " + m_networkendianness + ");";

              m_CodeFile.addString(bitfieldDataName + " = 0;");
              m_CodeFile.addNewLine();

              m_CodeFile.addString(readbitFieldFunction);
              m_CodeFile.addNewLine();
            }

            // do the bit shift compare stuff
            if(structDataType.getBitLength() == 1U)
            {
              m_CodeFile.addString(structParamDerefStructMember + " = ( (" + bitfieldDataName + " & (1 << " + DataType::ItoA((unsigned int)bitIndex) + ")) != 0);");
            }
            else if(i == 0)
            {
              bitStartIdx = bitIndex;
              bitShift = (i/8U * 8U) - bitStartIdx;
              if(bitShift < 0)
              {
                shiftOpTxt.assign(">>");
              }
              m_CodeFile.addString(structParamDerefStructMember + " = ((" + bitfieldDataName + " & (1 << " + DataType::ItoA((unsigned int)bitIndex) + ")) " + shiftOpTxt + " " + DataType::ItoA(abs(bitShift)) + ");");
            }
            else
            {
              bitShift = (i/8U * 8U) - bitStartIdx;  
              if(bitShift < 0)
              {
                shiftOpTxt.assign(">>");
              }
              m_CodeFile.addString(structParamDerefStructMember + " |= ((" + bitfieldDataName + " & (1 << " + DataType::ItoA((unsigned int)bitIndex) + ")) "+ shiftOpTxt + " " + DataType::ItoA(abs(bitShift)) + ");");
            }
            
            m_CodeFile.addNewLine();

            structBitIdx++;
          }
        }
      }
      else
      {
        m_CodeFile.addString(structParamDeref + " = " + readFunction);
      }

      if (j != dataTypes.size() - 1)
      {
        m_CodeFile.addNewLine();
      }
    }

    //close if
    m_CodeFile.closeBlock(false);

    m_CodeFile.addNewLine();
    m_CodeFile.addNewLine();
    m_CodeFile.addString("return " + returnDataName + ";");

    m_CodeFile.closeBlock(false);
    m_CodeFile.addNewLine();
    m_CodeFile.addNewLine();
  }

  return true;
}

bool MessageGenerator::generateWrite()
{
  m_CodeFile.addNewLine();
  m_CodeFile.addOneLineComment(" --- Write Functions ---");
  m_CodeFile.addNewLine();

  std::string dataNameType = "uint8_t* ";
  std::string dataName = "b_Data_pc";
  std::string dataLengthNameType = "uint32_t ";
  std::string dataLengthName = "i_DataLength_u32";
  std::string returnDataType = "bool_t";
  std::string returnDataName = "v_Valid_b";
  std::string bitfieldDataName = "v_BitFieldData_u8";

  for (size_t i = 0; i < m_Messages.size(); ++i)
  {
    Message& msg = m_Messages[i];

    std::string structParamName = "b_" + msg.getName() + "_ps";
    std::string structNameType = msg.getStructName() + "* ";

    // start function
    m_CodeFile.addString("ME_INLINE bool_t write" + msg.getName() + "_b(" + 
      dataNameType + dataName + ", " + 
      dataLengthNameType + dataLengthName + ", const " + 
      structNameType + structParamName + ")");
    m_CodeFile.openBlock();

    // now start writing the function code
    m_CodeFile.addNewLine();

    // generate bool_t v_Valid_b = ( struct length < dataLengthName)
    m_CodeFile.addString(returnDataType + " " + returnDataName + " = (" + dataLengthName + " >= " + DataType::ItoA(msg.getSize()) + ");");
    m_CodeFile.addNewLine();
    m_CodeFile.addNewLine();

    // generate if (true == v_Valid_b) 
    m_CodeFile.addString("if (true == " + returnDataName + ")");
    m_CodeFile.openBlock();
    m_CodeFile.addNewLine();

    // Generate : uint32_t v_Index_u32 = 0;
    std::string indexName = "v_Index_u32";
    m_CodeFile.addString(DataType::getDataType(e_Uint32_t) + " " + indexName + " = 0;");
    m_CodeFile.addNewLine();
    m_CodeFile.addNewLine();

    // Generate: write_u8(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_u8);
    DataTypeVector_t& dataTypes = msg.getDataTypes();
    for (size_t j = 0; j < dataTypes.size(); ++j)
    {
      DataType& currData = dataTypes[j];

       std::string structParamDeref = structParamName + "->" + currData.getName();
       std::string writeFunction = "ME_DataSerializer_Write_" + DataType::getDataTypeSuffix(currData.getDataType()) + "(" + dataName + ", " + "&" + indexName + ", " + structParamDeref + ", " + m_networkendianness + ");";

      // special case for array
      if (currData.isArray())
      {
        m_CodeFile.addNewLine();

        std::string arrayLengthNumber = currData.getArrayLengthString();
        std::string forIndexVariable = "v_I_u32";
        std::string indexDataType = DataType::getDataType(e_Uint32_t);

        m_CodeFile.addString("for (" + indexDataType + " " + forIndexVariable + " = 0; " + forIndexVariable + " < " + arrayLengthNumber + "; ++" + forIndexVariable + ")");
        m_CodeFile.openBlock();

        m_CodeFile.addNewLine();
        m_CodeFile.addString("ME_DataSerializer_Write_" + DataType::getDataTypeSuffix(currData.getDataType()) + "(" + dataName + ", " + "&" + indexName + ", " + structParamDeref + "[" + forIndexVariable + "]" + ", " + m_networkendianness + ");");

        m_CodeFile.closeBlock(false);
      }
      else if (currData.isStruct())
      {
        std::string structParamDerefStruct = structParamName + "->" + currData.getStructName();

        size_t structBitIdx = 0;
        for (size_t k = 0; k < currData.getStructMembers().size(); ++k)
        {
          DataType structDataType = currData.getStructMembers().at(k); 
          std::string structParamDerefStructMember = structParamDerefStruct + "." + structDataType.getName();

          for(size_t i = 0; i < structDataType.getBitLength(); ++i)
          {            
            size_t bitIndex = structBitIdx % 8;

            if (bitIndex == 0)
            {
              if (structBitIdx == 0)
              {
                m_CodeFile.addString(DataType::getDataType(e_Uint8_t) + " ");
              }
              else
              {
                m_CodeFile.addNewLine();
              }

              m_CodeFile.addString(bitfieldDataName + " = 0;");
              m_CodeFile.addNewLine();

            }

            // pack into one byte
            m_CodeFile.addString(bitfieldDataName + " |= " + structParamDerefStructMember + " << " + DataType::ItoA((unsigned int)bitIndex) + ";");
            m_CodeFile.addNewLine();

            if (bitIndex == 7)
            {
              std::string writebitFieldFunction = "ME_DataSerializer_Write_u8(" + dataName + ", " + "&" + indexName + ", " + bitfieldDataName + ", " + m_networkendianness + ");";
              m_CodeFile.addString(writebitFieldFunction);
              m_CodeFile.addNewLine();
            }

            structBitIdx++;
          }
        }
      }
      else
      {
        m_CodeFile.addString(writeFunction);
      }

      if (j != dataTypes.size() - 1)
      {
        m_CodeFile.addNewLine();
      }
    }

    //close if
    m_CodeFile.closeBlock(false);

    m_CodeFile.addNewLine();
    m_CodeFile.addNewLine();
    m_CodeFile.addString("return " + returnDataName + ";");

    m_CodeFile.closeBlock(false);
    m_CodeFile.addNewLine();
    m_CodeFile.addNewLine();
  }

  return true;
}

bool MessageGenerator::generateIncludeGuardEnd()
{
  m_CodeFile.addNewLine();
  m_CodeFile.addString("#endif");
  m_CodeFile.addNewLine();

  return true;
}

} // namespace mg
