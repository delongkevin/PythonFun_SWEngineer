#ifndef CODE_WRITER_H
#define CODE_WRITER_H

#include <platform/PlatformAPI.h>

#include <iostream>
#include <fstream>
#include <vector>

#include <ios>
#include <iomanip>

struct ImageHexValue_s
{
  uint8_t val;
};

static std::ostream& operator<<(std::ostream& os, const ImageHexValue_s& data)
{
  os << "0x" << std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(data.val) << std::dec;

  return os;
}



namespace tsdk
{



class CodeWriter
{
public:
  CodeWriter();
  ~CodeWriter();

  void begin_b(const std::string& i_FileName_ro, const std::string& i_NameSpace_ro, bool i_IsHeader_b, std::vector<std::string>* i_Includes_po);
  void writeClassName();
  void writeStructName();
  void write(const std::string& i_String_ro, bool i_NewLine_b = false);

  void newLine();

  template <typename T>
  void writeArray(const std::string& i_Name_o, const T* i_Values_px, uint32_t i_Size, std::string* i_ArrayType = NULL, bool i_Const = false, bool i_Static = false, std::string* i_SizeVariableName = NULL)
  {
    writeSpaces();

    if (i_Static)
    {
      stream << "static ";
    }

    if (i_Const)
    {
      stream << "const ";
    }

    std::string arrayType;

    if (NULL != i_ArrayType)
    {
      arrayType = *i_ArrayType;
      arrayType += " ";
    }
    else
    {
      arrayType = getTypeString<T>();
    }

    // write array type and name
    stream << arrayType.c_str() << i_Name_o.c_str() << "[";
     
    // write size, either by variable name or explicit index
    if (NULL != i_SizeVariableName)
    {
      stream << i_SizeVariableName->c_str();
    }
    else
    {
      stream << i_Size;
    }
      
    stream << "]";

    if (NULL == i_Values_px)
    {
      // just declare the array
      stream << ";" << std::endl;
      return;
    }
    else
    {
      stream << " = " << std::endl;
    }

    // set all the values
    writeSpaces();
    stream << "{" << std::endl;

    numSpaces += 2;
    writeSpaces();

    for (size_t i = 0; i < i_Size; ++i)
    {
      stream << i_Values_px[i];

      bool endOfArray = (i == i_Size - 1);

      if (!endOfArray)
      {
        stream << ", ";
      }
      else
      {
        bool tst  = true;
      }

      if (maxArrayEntriesPerRow != 0 && !endOfArray)
      {
        if ((i + 1) != 0 && 
           ((i + 1) % maxArrayEntriesPerRow == 0))
        {
          stream << std::endl;
          writeSpaces();
        }
      }
      else if (!endOfArray)
      {
        stream << std::endl;
        writeSpaces();
      }
    }

    numSpaces -= 2;

    stream << std::endl;
    stream << "};" << std::endl;

    newLine();
  }

  // write array with std::vector
  template <typename T>
  void writeArray(const std::string& i_Name, const std::vector<T>& i_Values, std::string* i_ArrayType = NULL, bool i_Const = false, bool i_Static = false, std::string* i_SizeVariableName = NULL)
  {
    writeArray<T>(i_Name, i_Values.data(), i_Values.size(), i_ArrayType, i_Const, i_Static, i_SizeVariableName);
  }

  template<typename T>
  void writeValue(const std::string& i_Name_ro, T i_Value, bool i_Const_b = false, bool i_Static_b = false)
  {
    writeSpaces();

    if (i_Static_b)
    {
      stream << "static ";
    }

    if (i_Const_b)
    {
      stream << "const ";
    }

    std::string typeString = getTypeString<T>();
    std::string typePrefix = getTypePrefix<T>();
    std::string typeSuffix = getTypeSuffix<T>();
    
    stream << typeString.c_str() << i_Name_ro.c_str() << " = " << typePrefix.c_str() << i_Value << typeSuffix.c_str() << ";" <<std::endl;
  }

  void declareVariable(const std::string& i_Name, const std::string& i_Type_ro, std::vector<std::string>* i_Parameters_po, bool i_Const = false, bool i_Static = false);

  void end_b();

  void setMaxArrayEntriesPerRow(unsigned int val);
  void addOrRemoveSpaces(int i_Val);
  void writeSpaces();

private:
  template <typename T>
  std::string getTypeString() const
  {
    if (typeid(T) == typeid(sint8_t))     return "sint8_t "  ;
    if (typeid(T) == typeid(sint16_t))    return "sint16_t " ;
    if (typeid(T) == typeid(sint32_t))    return "sint32_t " ;
    if (typeid(T) == typeid(sint64_t))    return "sint64_t " ;
    if (typeid(T) == typeid(uint8_t))     return "uint8_t "  ;
    if (typeid(T) == typeid(uint16_t))    return "uint16_t " ;
    if (typeid(T) == typeid(uint32_t))    return "uint32_t " ;
    if (typeid(T) == typeid(uint64_t))    return "uint64_t " ;
    if (typeid(T) == typeid(float32_t))   return "float32_t "; 
    if (typeid(T) == typeid(float64_t))   return "float64_t ";
    if (typeid(T) == typeid(const char*)) return "char* ";
    if (typeid(T) == typeid(bool))        return "bool ";

    return "";
  }


  template <typename T>
  std::string getTypePrefix() const
  {
    if (typeid(T) == typeid(sint8_t))      return "";   
    if (typeid(T) == typeid(sint16_t))     return "";   
    if (typeid(T) == typeid(sint32_t))     return "";   
    if (typeid(T) == typeid(sint64_t))     return ""; 
    if (typeid(T) == typeid(uint8_t))     return "";  
    if (typeid(T) == typeid(uint16_t))    return "";  
    if (typeid(T) == typeid(uint32_t))    return ""; 
    if (typeid(T) == typeid(uint64_t))    return "";
    if (typeid(T) == typeid(float32_t))   return "";  
    if (typeid(T) == typeid(float64_t))   return "";   
    if (typeid(T) == typeid(const char*)) return "\"";

    return "";
  }

  template <typename T>
  std::string getTypeSuffix() const
  {
    if (typeid(T) == typeid(sint8_t))    return "";   
    if (typeid(T) == typeid(sint16_t))   return "";   
    if (typeid(T) == typeid(sint32_t))   return "";   
    if (typeid(T) == typeid(sint64_t))   return "LL"; 
    if (typeid(T) == typeid(uint8_t))   return "U";  
    if (typeid(T) == typeid(uint16_t))  return "U";  
    if (typeid(T) == typeid(uint32_t))  return "UL"; 
    if (typeid(T) == typeid(uint64_t))  return "ULL";
    if (typeid(T) == typeid(float32_t)) return "F";  
    if (typeid(T) == typeid(float64_t)) return "";   
    if (typeid(T) == typeid(const char*)) return "\"";

    return "";
  }

private:
  std::ofstream stream;
  std::string fileName;
  std::string nameSpace;
  unsigned int numSpaces;
  unsigned int maxArrayEntriesPerRow;
  bool isHeader_b;

  enum FileType
  {
    e_FT_Class = 0,
    e_FT_Struct,
    e_FT_None
  };
  FileType fileType_e;

};


} // namespace tsdk

#endif
