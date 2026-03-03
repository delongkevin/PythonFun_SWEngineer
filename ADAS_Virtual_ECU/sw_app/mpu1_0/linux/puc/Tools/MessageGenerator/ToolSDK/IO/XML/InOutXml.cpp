#include "InOutXml.h"

namespace tsdk
{

InOutXml::InOutXml()
  : Loading_b(false)
{

}

InOutXml::~InOutXml()
{

}

bool InOutXml::create_b(const char* i_FileName_pc, bool i_IsLoading_b)
{
  Loading_b   = i_IsLoading_b;
  fileName_o  = i_FileName_pc;

  tinyxml2::XMLError v_Error_e = tinyxml2::XML_SUCCESS; 

  if (false == Loading_b)
  {
    tinyxml2::XMLDeclaration* decl = doc_o.NewDeclaration();
    doc_o.InsertFirstChild(decl);
  }
  else
  {
    v_Error_e = doc_o.LoadFile(i_FileName_pc);
  }

  bool v_Success_b = (v_Error_e == tinyxml2::XML_SUCCESS);
  Assert(v_Success_b);

  return v_Success_b;
}

bool InOutXml::isLoading_b() const
{
  return Loading_b;
}

bool InOutXml::save_b()
{
  tinyxml2::XMLError v_Error_e = doc_o.SaveFile(fileName_o.c_str());

  bool v_Success_b = (v_Error_e == tinyxml2::XML_SUCCESS);
  Assert(v_Success_b);

  return v_Success_b;
}

tinyxml2::XMLElement* InOutXml::newElement_po(const std::string& i_Name_ro)
{
  return doc_o.NewElement(i_Name_ro.c_str());
}

tinyxml2::XMLElement* InOutXml::firstChildElement_po(const char* i_Name_pc /*= 0*/)
{
  return doc_o.FirstChildElement(i_Name_pc);
}

tinyxml2::XMLNode* InOutXml::insertEndChild(tinyxml2::XMLElement* i_Elem_po)
{
  return doc_o.InsertEndChild(i_Elem_po);
}

void InOutXml::serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, std::string& b_Value_ro)
{
  if (true == Loading_b)
  {
    const char* v_name_pc = i_Elem_po->Attribute(i_Name_pc);

    if (v_name_pc)
    {
      b_Value_ro = v_name_pc;
    }
  }
  else
  {
    i_Elem_po->SetAttribute(i_Name_pc, b_Value_ro.c_str());
  }
}

void InOutXml::serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, uint8_t& b_Value_ru8)
{
	if (true == Loading_b)
	{
		unsigned int tmpValue;
		i_Elem_po->QueryUnsignedAttribute(i_Name_pc, &tmpValue);
		b_Value_ru8 = tmpValue;	// possible loss, but this will not happen if xml file is not changed outside of GDE
	}
	else
	{
		i_Elem_po->SetAttribute(i_Name_pc, b_Value_ru8);
	}
}

void InOutXml::serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, sint8_t& b_Value_rs8)
{
	if (true == Loading_b)
	{
		int tmpValue;
		i_Elem_po->QueryAttribute(i_Name_pc, &tmpValue);
		b_Value_rs8 = tmpValue;	// possible loss, but this will not happen if xml file is not changed outside of GDE
	}
	else
	{
		i_Elem_po->SetAttribute(i_Name_pc, b_Value_rs8);
	}
}

void InOutXml::serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, uint16_t& b_Value_ru16)
{
	if (true == Loading_b)
	{
		unsigned int tmpValue;
		i_Elem_po->QueryUnsignedAttribute(i_Name_pc, &tmpValue);
		b_Value_ru16 = tmpValue;
	}
	else
	{
		i_Elem_po->SetAttribute(i_Name_pc, b_Value_ru16);
	}
}

void InOutXml::serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, sint16_t& b_Value_rs16)
{
	if (true == Loading_b)
	{
		int tmpValue;
		i_Elem_po->QueryAttribute(i_Name_pc, &tmpValue);
		b_Value_rs16 = tmpValue;
	}
	else
	{
		i_Elem_po->SetAttribute(i_Name_pc, b_Value_rs16);
	}
}

void InOutXml::serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, uint32_t& b_Value_ru32)
{
  if (true == Loading_b)
  {
    i_Elem_po->QueryUnsignedAttribute(i_Name_pc, &b_Value_ru32);
  }
  else
  {
    i_Elem_po->SetAttribute(i_Name_pc, b_Value_ru32);
  }
}

void InOutXml::serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, sint32_t& b_Value_rs32)
{
  if (true == Loading_b)
  {
    i_Elem_po->QueryIntAttribute(i_Name_pc, &b_Value_rs32);
  }
  else
  {
    i_Elem_po->SetAttribute(i_Name_pc, b_Value_rs32);
  }
}

void InOutXml::serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, uint64_t& b_Value_u64)
{
  if (true == Loading_b)
  {
    i_Elem_po->QueryInt64Attribute(i_Name_pc, reinterpret_cast<sint64_t*>(&b_Value_u64));
  }
  else
  {
    i_Elem_po->SetAttribute(i_Name_pc, reinterpret_cast<sint64_t&>(b_Value_u64));
  }
}

void InOutXml::serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, sint64_t& b_Value_s64)
{
  if (true == Loading_b)
  {
    i_Elem_po->QueryInt64Attribute(i_Name_pc, &b_Value_s64);
  }
  else
  {
    i_Elem_po->SetAttribute(i_Name_pc, b_Value_s64);
  }
}

void InOutXml::serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, float32_t& b_Value_f32)
{
  if (true == Loading_b)
  {
    i_Elem_po->QueryFloatAttribute(i_Name_pc, &b_Value_f32);
  }
  else
  {
    i_Elem_po->SetAttribute(i_Name_pc, b_Value_f32);
  }
}

void InOutXml::serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, float64_t& b_Value_f64)
{
  if (true == Loading_b)
  {
    i_Elem_po->QueryDoubleAttribute(i_Name_pc, &b_Value_f64);
  }
  else
  {
    i_Elem_po->SetAttribute(i_Name_pc, b_Value_f64);
  }
}


void InOutXml::serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, bool& b_Value_b)
{
  if (true == Loading_b)
  {
    i_Elem_po->QueryBoolAttribute(i_Name_pc, &b_Value_b);
  }
  else
  {
    i_Elem_po->SetAttribute(i_Name_pc, b_Value_b);
  }
}

} // namespace tsdk

