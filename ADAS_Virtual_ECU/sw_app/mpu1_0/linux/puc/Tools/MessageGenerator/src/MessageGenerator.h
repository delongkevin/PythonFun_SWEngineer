#pragma once

#include "Message.h"
#include <vector>
#include "tinyxml2.h"
#include "CodeFile.h"

namespace mg
{

typedef std::vector<std::string> StringVector_t;

struct EnumToId_s
{
  std::string Name;
  std::string Value;

  EnumToId_s(const std::string& i_Name, const std::string& i_Value)
  {
    Name = i_Name;
    Value = i_Value;
  }
};
typedef std::vector<EnumToId_s> EnumVector_t;

class MessageGenerator
{
public:
  MessageGenerator();
  ~MessageGenerator();

  // load xml file
  bool load(const char* xmlFile);

  // generate source code
  bool generate(const char* outPath, const char* fileName, const char* networkendianness);

private:
  void loadMessageElement(tinyxml2::XMLElement* elem);
  void loadConfiguration(tinyxml2::XMLElement* elem);
  void loadIncludes(tinyxml2::XMLElement* elem);
  
  bool generateIncludeGuardBegin();
  bool generateIncludes();
  bool generateEnum();
  bool generateEnumToMsgIdMapping();
  bool generateAddHeaderToMessage();
  bool generateRead();
  bool generateWrite();
  bool generateIncludeGuardEnd();

  std::string m_FileName;
  std::string m_networkendianness;
  CodeFile m_CodeFile;
  StringVector_t m_AdditionalIncludes;
  std::vector<Message> m_Messages;
  EnumVector_t m_Enums;
  std::string  m_EnumName;
  tinyxml2::XMLDocument m_Doc;
};

} // namespace mg