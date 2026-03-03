#pragma once

#include <IO/XML/tinyxml2.h>
#include <string>
#include <platform/PlatformAPI.h>

#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <platform/PlatformAPI.h>

namespace tsdk
{
/*

//usercode generic :

variants::serialize_b(IInOut inOut);

//usercode generic 
variants::serialize_b(InOutBinary inOut);


class IInOutElement
{

};

// ELements:
class IInOut
{
public:
	IInOut(osal::IFile* i_File_po, bool i_IsLoading_b);

	virtual void serialize_v(IInOutElement* b_Element_po, const char_t* i_Value_pc) = 0;
	virtual void serialize_v(IInOutElement* b_Element_po, sint8_t* i_Value_pc) = 0;
	//...

	// check if template works here
	template<typename T>
	virtual void serializeArray_v(IInOutElement* b_Element_po, T* b_Array_pt, size_t i_ArraySize_t) = 0;

	// if not..
	virtual void serializeArray_v(IInOutElement* b_Element_po, sint8_t* b_Array_ps8, size_t i_ArraySize_t) = 0;



};
*/

class InOutXml
{
public:
  InOutXml();
  ~InOutXml();

  bool create_b(const char* i_FileName_pc, bool i_IsLoading_b);
  bool isLoading_b() const;
  bool save_b();

  tinyxml2::XMLElement* newElement_po(const std::string& i_Name_ro);
  tinyxml2::XMLElement* firstChildElement_po(const char* i_Name_pc = 0);
  tinyxml2::XMLNode* insertEndChild(tinyxml2::XMLElement* i_Elem_po);

  void serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, std::string& b_Value_ro);
  void serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, uint8_t&     b_Value_ru8);
  void serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, sint8_t&     b_Value_rs8);
  void serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, uint16_t&     b_Value_ru16);
  void serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, sint16_t&     b_Value_rs16);
  void serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, uint32_t&    b_Value_ru32);
  void serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, sint32_t&    b_Value_rs32);
  void serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, uint64_t&    b_Value_u64);
  void serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, sint64_t&    b_Value_s64);
  void serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, float32_t&   b_Value_f32);
  void serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, float64_t&   b_Value_f64);
  void serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, bool&        b_Value_b);

  template<typename T>
  void serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, T& b_Value_ro)
  {
    serialize_v(i_Elem_po, i_Name_pc, b_Value_ro);
  }

  template<typename T>
  void serializeVector_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, std::vector<T>& b_Values_ro)
  {
    tinyxml2::XMLElement* vectorElement = nullptr;

    if (true == Loading_b)
    {
      vectorElement = i_Elem_po->FirstChildElement(i_Name_pc);

      if (vectorElement)
      {
        uint32_t vectorSize = 0;
        serialize_v(vectorElement, "Size", vectorSize);
        b_Values_ro.resize(vectorSize);

        tinyxml2::XMLElement* itElement = vectorElement->FirstChildElement("Entry");

        uint32_t idx = 0;
        while (itElement)
        {
          Assert(idx < vectorSize);
          serialize_v(itElement, "Value", b_Values_ro[idx]);
          ++idx;

          itElement = itElement->NextSiblingElement("Entry");
        }
      }
      else
      {
        bool tst = true;
      }

    }
    else
    {
      bool isEmpty = b_Values_ro.empty();

      if (!isEmpty)
      {
        vectorElement = doc_o.NewElement(i_Name_pc);
        uint32_t vectorSize = (uint32_t)b_Values_ro.size();
        serialize_v(vectorElement, "Size", vectorSize);

        for (size_t i = 0; i < b_Values_ro.size(); ++i)
        {
          tinyxml2::XMLElement* itElement = doc_o.NewElement("Entry");
          serialize_v(itElement, "Value", b_Values_ro[i]);
          vectorElement->InsertEndChild(itElement);
        }

        i_Elem_po->InsertEndChild(vectorElement);
      }
    }
  }

  template<typename T>
  void serializeList_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, std::list<T>& b_Values_ro)
  {
    tinyxml2::XMLElement* listElement = nullptr;

    if (true == Loading_b)
    {
      listElement = i_Elem_po->FirstChildElement(i_Name_pc);

      b_Values_ro.clear();

      if (listElement)
      {
        tinyxml2::XMLElement* itElement = listElement->FirstChildElement("Entry");

        while (itElement)
        {
          T value;
          serialize_v(itElement, "Value", value);
          b_Values_ro.push_back(value);

          itElement = itElement->NextSiblingElement("Entry");
        }
      }
      else
      {
        bool tst = true;
      }

    }
    else
    {
      if (!b_Values_ro.empty())
      {
        listElement = doc_o.NewElement(i_Name_pc);

        for (auto&& it = b_Values_ro.begin(); it != b_Values_ro.end(); ++it)
        {
          tinyxml2::XMLElement* itElement = doc_o.NewElement("Entry");

          T& value = (*it);
          serialize_v(itElement, "Value", value);
          listElement->InsertEndChild(itElement);
        }

        i_Elem_po->InsertEndChild(listElement);
      }
    }
  }


  template<typename T, typename U>
  void serialize_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, std::pair<T, U>& b_Value_ro)
  {
    serialize_v(i_Elem_po, "PairFirst", static_cast<T&>(b_Value_ro.first));
    serialize_v(i_Elem_po, "PairSecond", static_cast<U&>(b_Value_ro.second));
  }

  template<typename T, typename U>
  void serializeMap_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, std::map<T, U>& b_Values_ro)
  {
    tinyxml2::XMLElement* mapElement = nullptr;

    if (true == Loading_b)
    {
      mapElement = i_Elem_po->FirstChildElement(i_Name_pc);

      if (mapElement)
      {
        tinyxml2::XMLElement* itElement = mapElement->FirstChildElement();
        while (itElement)
        {
          T first;
          serialize_v<T>(itElement, "First", first);

          U second;
          serialize_v<U>(itElement, "Second", second);

          b_Values_ro[first] = second;

          itElement = itElement->NextSiblingElement();
        }
      }
    }
    else
    {
      bool isEmpty = b_Values_ro.empty();

      if (!isEmpty)
      {
        mapElement = doc_o.NewElement(i_Name_pc);

        uint32_t index = 0;
        for (auto&& it = b_Values_ro.begin(); it != b_Values_ro.end(); ++it)
        {
          tinyxml2::XMLElement* itElement = doc_o.NewElement("Entry");

          serialize_v(itElement, "First", static_cast<T>(it->first));
          serialize_v(itElement, "Second", static_cast<U>(it->second));

          mapElement->InsertEndChild(itElement);
        }

        i_Elem_po->InsertFirstChild(mapElement);

      }
    }
  }

  template<typename T, typename U>
  void serializeMap_v(tinyxml2::XMLElement* i_Elem_po, const char* i_Name_pc, std::unordered_map<T, U>& b_Values_ro)
  {
    tinyxml2::XMLElement* mapElement = nullptr;

    if (true == Loading_b)
    {
      mapElement = i_Elem_po->FirstChildElement(i_Name_pc);

      if (mapElement)
      {
        tinyxml2::XMLElement* itElement = mapElement->FirstChildElement();
        while (itElement)
        {
          T first;
          serialize_v<T>(itElement, "First", first);

          U second;
          serialize_v<U>(itElement, "Second", second);

          b_Values_ro[first] = second;

          itElement = itElement->NextSiblingElement();
        }
      }
    }
    else
    {
      bool isEmpty = b_Values_ro.empty();

      if (!isEmpty)
      {
        mapElement = doc_o.NewElement(i_Name_pc);

        uint32_t index = 0;
        for (auto&& it = b_Values_ro.begin(); it != b_Values_ro.end(); ++it)
        {
          tinyxml2::XMLElement* itElement = doc_o.NewElement("Entry");

          serialize_v(itElement, "First", static_cast<T>(it->first));
          serialize_v(itElement, "Second", static_cast<U>(it->second));

          mapElement->InsertEndChild(itElement);
        }

        i_Elem_po->InsertFirstChild(mapElement);

      }
    }
  }

private:
  bool Loading_b;
  std::string fileName_o;
  tinyxml2::XMLDocument doc_o;
};


} // namespace tsdk
