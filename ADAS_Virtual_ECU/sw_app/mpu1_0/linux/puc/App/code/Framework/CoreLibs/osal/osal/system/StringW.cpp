#include "StringW.h"

#include "platform/stdlib/ME_Assert.h"

namespace osal
{
  StringW::StringW()
    : data_t(L"")
  {
  }

  StringW::~StringW()
  {
  }

  StringW::StringW(const wchar_t* i_StringW_pc)
    : data_t(i_StringW_pc)
  {
    if (NULL != i_StringW_pc)
    {
      data_t = i_StringW_pc;
    }
  }

  StringW::StringW(const wchar_t* i_StringW_pc, size_t i_Length_t)
    : data_t(L"")
  {
    if (NULL != i_StringW_pc)
    {
      data_t = DataType_t(i_StringW_pc, i_Length_t);
    }
  }

  const wchar_t* StringW::getString_pc() const
  {
    return data_t.c_str();
  }

  StringW::DataType_t& StringW::getData_ro()
  {
    return data_t;
  }

  const StringW::DataType_t& StringW::getData_ro() const
  {
    return data_t;
  }

  size_t StringW::getLength_t() const
  {
    return data_t.length();
  }

  size_t StringW::getSize_t() const
  {
    return ( data_t.length() * sizeof(wchar_t) );
  }

  size_t StringW::getAllocSize_t() const
  {
    return ( (data_t.length() + 1) * sizeof(wchar_t) );
  }

  void StringW::clear_v()
  {
    data_t.clear();
  }

  bool_t StringW::isEmpty_b() const
  {
    return (data_t.length() == 0);
  }

  wchar_t StringW::getAt_c(uint32_t i_Index_u32) const
  {
    Assert(data_t.length() > i_Index_u32);
    return data_t[i_Index_u32];
  }

  void StringW::setAt_v(uint32_t i_Index_u32, wchar_t i_Char_c)
  {
    Assert(data_t.length() > i_Index_u32);
    data_t[i_Index_u32] = i_Char_c;
  }

  uint32_t StringW::find_u32(wchar_t i_Char_c, uint32_t i_Start_u32) const
  {
    return data_t.find(i_Char_c, i_Start_u32);
  }

  uint32_t StringW::find_u32(const StringW& i_StringW_ro, uint32_t i_Start_u32) const
  {
    return data_t.find(i_StringW_ro.getData_ro(), i_Start_u32);
  }

  uint32_t StringW::reverseFind_u32(wchar_t i_Char_c) const
  {
    return data_t.find_last_of(i_Char_c);
  }

  uint32_t StringW::reverseFind_u32(const wchar_t* i_StringW_pc, uint32_t i_Endpos_u32 /*= StringW::c_Npos_u32*/) const
  {
    return data_t.rfind(i_StringW_pc, i_Endpos_u32);
  }

  uint32_t StringW::findFirstOf_u32(const wchar_t* i_StringW_pc, uint32_t i_Start_u32 /*= 0*/) const
  {
    return data_t.find_first_of(i_StringW_pc, i_Start_u32);
  }

  StringW& StringW::operator+=(char_t i_Other_c)
  {
    data_t.append(1, i_Other_c);

    return *this;
  }

  StringW& StringW::operator+=(const wchar_t* i_Other_pc)
  {
    data_t.append(i_Other_pc);

    return *this;
  }

  StringW& StringW::operator+=(const StringW& i_Other_ro)
  {
    data_t.append(i_Other_ro.data_t);

    return *this;
  }

  bool StringW::operator==(wchar_t i_Other_c) const
  {
    return ( (getLength_t() == 1) && 
             (getAt_c(0) == i_Other_c) );
  }

  bool StringW::operator!=(wchar_t i_Other_c) const
  {
    return ( (getLength_t() != 1) || 
             (getAt_c(0) != i_Other_c) );
  }

} // namespace osal
