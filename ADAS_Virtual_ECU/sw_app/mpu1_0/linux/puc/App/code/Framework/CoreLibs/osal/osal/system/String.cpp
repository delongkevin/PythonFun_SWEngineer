#include "String.h"

#include "platform/stdlib/ME_Assert.h"

// PRQA S 5029 EOF // okay when using in string class

namespace osal
{
  String::String()
    : data_t("")
  {
  }

  // PRQA S 4054 1 // fine here, because we call operator=
  String::String(const String& i_String_ro)
  {
    // call operator=
    *this = i_String_ro;
  }

  String::~String()
  {
  }

  String::String(const char_t* i_String_pc)
    : data_t("")
  {
    if (NULL != i_String_pc)
    {
      data_t = i_String_pc;
    }
  }

  String::String(const char_t* i_String_pc, size_t i_Length_t)
    : data_t("")
  {
    if (NULL != i_String_pc)
    {
      data_t = DataType_t(i_String_pc, i_Length_t);
    }
  }

  String::String(char_t i_Char_c)
    : data_t("")
  {
    char_t v_TmpChar_ac[2];
    v_TmpChar_ac[0] = i_Char_c;
    v_TmpChar_ac[1] = 0;
    data_t.insert(0, &v_TmpChar_ac[0]);
  }

  const char_t* String::getString_pc() const
  {
    return data_t.c_str();
  }

  String::DataType_t& String::getData_ro()
  {
    return data_t;
  }

  const String::DataType_t& String::getData_ro() const
  {
    return data_t;
  }

  uint32_t String::getLength_u32() const
  {
    uint32_t v_Count_u32 = 0;
    size_t v_Length_t = data_t.length();
    const char_t* c_String_pc = data_t.data();

    for (uint32_t i = 0; i < v_Length_t; ++i)
    {
      // counting single byte chars and sequence starts see http://wikipedia.org/wiki/Utf8
      // PRQA S 3706 3 // iterating over each character necessary here
      // PRQA S 3003 2 // just masking and comparing. the result isn't used anymore
      // PRQA S 3711 1 // we have to handle the character like a normal integer value
      if ((c_String_pc[i] & 0xC0) != 0x80)
      {
        v_Count_u32++;
      }
    }
    return v_Count_u32;
  }

  size_t String::getSize_t() const
  {
    return data_t.length();
  }

  size_t String::getAllocSize_t() const
  {
    return (data_t.length() + 1);
  }

  void String::clear_v()
  {
    data_t.clear();
  }

  bool_t String::isEmpty_b() const
  {
    return (data_t.length() == 0);
  }

  char_t String::getAt_c(uint32_t i_Index_u32) const
  {
    Assert(data_t.capacity() > i_Index_u32);
    return data_t[i_Index_u32];
  }

  void String::setAt_v(uint32_t i_Index_u32, char_t i_Char_c)
  {
    if (data_t.capacity() <= i_Index_u32)
    {
      data_t.resize(i_Index_u32 + 1);
    }

    Assert(data_t.capacity() > i_Index_u32);
    data_t.insert(data_t.begin() + i_Index_u32, i_Char_c);
  }

  uint32_t String::find_u32(char_t i_Char_c, uint32_t i_Start_u32 /*= 0*/) const
  {
    return data_t.find(i_Char_c, i_Start_u32);
  }

  uint32_t String::find_u32(const String& i_String_ro, uint32_t i_Start_u32 /*= 0*/) const
  {
    return data_t.find(i_String_ro.getData_ro(), i_Start_u32);
  }

  uint32_t String::reverseFind_u32(char_t i_Char_c) const
  {
    return data_t.find_last_of(i_Char_c);
  }

  uint32_t String::reverseFind_u32(const char_t* i_String_pc, uint32_t i_Endpos_u32 /*= String::c_Npos_u32*/) const
  {
    return data_t.rfind(i_String_pc, i_Endpos_u32);
  }

  uint32_t String::findFirstOf_u32(const char_t* i_String_pc, uint32_t i_Start_u32 /*= 0*/) const
  {
    return data_t.find_first_of(i_String_pc, i_Start_u32);
  }

  String String::tokenize_o(const char_t i_Token_c, uint32_t& i_Start_u32) const
  {
    String v_RetString_o;

    if (i_Start_u32 != String::c_Npos_u32)
    {
      uint32_t tokenStart = static_cast<uint32_t>(data_t.find_first_not_of(i_Token_c, i_Start_u32));

      if (tokenStart != String::c_Npos_u32)
      {
        // found token start; now find the next speparator char
        uint32_t tokenEnd = static_cast<uint32_t>(data_t.find_first_of(i_Token_c, tokenStart));

        if (tokenEnd == String::c_Npos_u32)
        {
          // rest of the string is a single token
          i_Start_u32 = String::c_Npos_u32;

          v_RetString_o = mid_o(tokenStart);
        }
        else
        {
          // found separated token
          i_Start_u32 = tokenEnd;

          v_RetString_o = mid_o(tokenStart, tokenEnd - tokenStart);
        }
      }
    }

    return v_RetString_o;
  }

  uint32_t String::tokenize_o(const char_t i_Token_c, mepl::vector<String>& o_Result_ro) const
  {
    uint32_t v_CurPos_u32 = 0;

    String v_ResToken_o = tokenize_o(i_Token_c, v_CurPos_u32);

    while (!v_ResToken_o.isEmpty_b())
    {
      o_Result_ro.push_back(v_ResToken_o);

      v_ResToken_o = tokenize_o(i_Token_c, v_CurPos_u32);
    };

    return static_cast<uint32_t>(o_Result_ro.size());
  }

  String String::mid_o(uint32_t start, uint32_t count) const
  {
    return String(data_t.substr(start, count).c_str());
  }

  String String::mid_o(uint32_t start) const
  {
    String v_RetString_o;
    if (start > 0)
    {
      v_RetString_o = String(data_t.substr(start, data_t.length() - start).c_str());
    }
    else
    {
      v_RetString_o = String(*this);
    }

    return v_RetString_o;
  }

  void String::trimRight_v(const String& i_String_ro)
  {
    std::string::size_type v_Pos_t = data_t.find_last_not_of(i_String_ro.data_t);

    if (v_Pos_t != String::c_Npos_u32)
    {
      data_t.erase(v_Pos_t + 1);
    }
    else
    {
      data_t.clear();
    }
  }

  uint32_t String::replace_u32(const char_t* i_OldStr_pc, uint32_t i_LenOldStr_u32, const char_t* o_NewStr_pc, uint32_t i_LenNewStr_u32)
  {
    uint32_t v_Count_u32 = 0;
    uint32_t v_Start_u32 = static_cast<uint32_t>(data_t.find(i_OldStr_pc, 0));

    while (v_Start_u32 != String::c_Npos_u32)
    {
      data_t.replace(v_Start_u32, i_LenOldStr_u32, o_NewStr_pc, 0, i_LenNewStr_u32);

      v_Start_u32 = static_cast<uint32_t>(data_t.find(i_OldStr_pc, v_Start_u32 + i_LenNewStr_u32));

      v_Count_u32++;
    }

    return v_Count_u32;
  }

  uint32_t String::replace_u32(const char_t* i_OldStr_pc, const char_t* o_NewStr_pc)
  {
    return replace_u32(i_OldStr_pc, strlen(i_OldStr_pc), o_NewStr_pc, strlen(o_NewStr_pc));
  }

  void String::appendChar_v(char_t i_Char_c)
  {
    data_t.append(1, i_Char_c);
  }

  void String::appendString_v(const char_t* i_String_pc)
  {
    data_t.append(i_String_pc);
  }

  void String::appendString_v(const String& i_String_ro)
  {
    data_t.append(i_String_ro.getString_pc());
  }

  bool_t String::compare_b(const String& i_Other_ro) const
  {
    return compare_b(i_Other_ro.getString_pc());
  }

  bool_t String::compare_b(const char_t* i_Other_pc) const
  {
    return strcmp(getString_pc(), i_Other_pc) == 0;
  }

  bool_t String::compare_b(char_t i_Other_c) const
  {
    return ( (getLength_u32() == 1) && (getAt_c(0) == i_Other_c) );
  }

  String& String::operator = (const String& i_Other_ro)
  {
    data_t = DataType_t(i_Other_ro.getString_pc(), i_Other_ro.getSize_t());
    return *this;
  }

  String& String::operator = (const char_t* i_Other_pc)
  {
    data_t = DataType_t(i_Other_pc);
    return *this;
  }

  String& String::operator = (char_t i_Other_c)
  {
    char_t v_TmpChar_ac[] = {i_Other_c, 0};
    data_t.insert(0, &v_TmpChar_ac[0]);
    return *this;
  }


  String String::operator + (const String& i_Other_ro) const
  {
    return String(*this) += i_Other_ro;
  }

  String String::operator + (const char_t* i_Other_pc) const
  {

    return String(*this) += i_Other_pc;
  }

  String String::operator + (char_t i_Other_c) const
  {
    return String(*this) += i_Other_c;
  }

  bool_t String::operator!=(const String& i_Other_ro) const
  {
    return this->data_t != i_Other_ro.data_t;
  }

  bool_t String::operator!=(const char_t* i_Other_ro) const
  {
    return !compare_b(i_Other_ro);
  }

  //PRQA S 1503 1 // could be used in the future, don't must be removed
  String operator + (char_t i_Other_c, const String& i_String_ro)
  {
    return String(i_Other_c) += i_String_ro;
  }

  String& String::operator+=(char_t i_Other_c)
  {
    appendChar_v(i_Other_c);

    return *this;
  }

  String& String::operator+=(const char_t* i_Other_pc)
  {
    appendString_v(i_Other_pc);

    return *this;
  }

  String& String::operator+=(const String& i_Other_ro)
  {
    appendString_v(i_Other_ro);

    return *this;
  }

  bool_t String::operator==(const String& i_Other_ro) const
  {
    return this->compare_b(i_Other_ro);
  }

  bool_t String::operator == (const char_t* i_Other_ro) const
  {
    return this->compare_b(i_Other_ro);
  }

  bool_t String::operator==(char_t i_Other_c) const
  {
    return compare_b(i_Other_c);
  }

  bool_t String::operator!=(char_t i_Other_c) const
  {
    return !compare_b(i_Other_c);
  }

} // namespace osal
