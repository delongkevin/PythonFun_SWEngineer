
#include <iostream>

#include "MessageGenerator.h"

int main(int argc, char** argv) 
{
  std::cout << "Found " << argc << " arguments:" << std::endl;
  for (int i = 0; i < argc; ++i) 
  {
    std::cout << argv[i] << std::endl;
  }

  if (argc >= 5)
  {
    mg::MessageGenerator messageGen;
    if (!messageGen.load(argv[1]))
    {
      std::cout << "Error occurred when Loading XML File" << std::endl;
      return 1;
    }

    if (!messageGen.generate(argv[2], argv[3], argv[4]))
    {
      std::cout << "Error occurred when Generating code" << std::endl;
      return 2;
    }
  }
  else
  {
    std::cout << "Invalid number of arguments. Usage:" << std::endl;
    std::cout << "Argument 1: FilePath to Input XML File (e.g. C:\\Signals\\Input\\MessageModel.xml)" << std::endl;
    std::cout << "Argument 2: Path to Output Source File (e.g. C:\\Signals\\Output " << std::endl;
    std::cout << "Argument 3: Source FileName Output path(e.g. Messages -> results in C:\\Signals\\Output\\Messages.h)" << std::endl;
    std::cout << "Argument 4: NetworkEndianness (LittleEndian = 0, BigEndian = 1)" << std::endl;

    return 3;
  }

  std::cout << "Success" << std::endl;

  return 0;

}