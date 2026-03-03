cmake_minimum_required(VERSION 2.8.8)





add_subdirectory(src)

# Messenger
if(${EXE_TO_BUILD} MATCHES "MessageTester")
	add_subdirectory(MessageTester)
ENDIF()
add_subdirectory(test)
