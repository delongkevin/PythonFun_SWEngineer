cmake_minimum_required(VERSION 2.8.8)
###################################################################################################

MESSAGE(STATUS)
MESSAGE(STATUS "-------------------------------------------------------------------------------")
MESSAGE(STATUS "MODULE NAME                 : ${PROJECT_NAME}")
MESSAGE(STATUS "CMAKE_CURRENT_LIST_DIR      : ${CMAKE_CURRENT_LIST_DIR}")
MESSAGE(STATUS "-------------------------------------------------------------------------------")
MESSAGE(STATUS)

###################################################################################################

INCLUDE("${PROJECT_SOURCE_DIR}/CMakeUtils.txt")

# add definitions
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

#include libs
include_directories("${PROJECT_SOURCE_DIR}/libs/pvs/mecl")
include_directories("${PROJECT_SOURCE_DIR}/libs/pvs/platform")
include_directories("${PROJECT_SOURCE_DIR}/libs/pvs/osal")
include_directories("${PROJECT_SOURCE_DIR}/tools/src")
include_directories("${PROJECT_SOURCE_DIR}/tools/ToolSDK")
include_directories("${PROJECT_SOURCE_DIR}/tools/messenger/UI/Trees")
include_directories("${PROJECT_SOURCE_DIR}/tools/QtPropertyBrowser")


# add sources to project
GET_SOURCE_FILES("")
message(STATUS "  found source file(s):")
FOREACH(SourceFile ${SourceFiles})
  get_filename_component(FileName ${SourceFile} NAME)
  message(STATUS "    ${FileName}")
ENDFOREACH(SourceFile)

set (SourceMessageGenerator
    ${PROJECT_SOURCE_DIR}/tools/src/CodeFile.h
    ${PROJECT_SOURCE_DIR}/tools/src/CodeFile.cpp
    ${PROJECT_SOURCE_DIR}/tools/src/DataType.h
    ${PROJECT_SOURCE_DIR}/tools/src/DataType.cpp
    ${PROJECT_SOURCE_DIR}/tools/src/Message.h
    ${PROJECT_SOURCE_DIR}/tools/src/Message.cpp
    ${PROJECT_SOURCE_DIR}/tools/src/tinyxml2.h
    ${PROJECT_SOURCE_DIR}/tools/src/tinyxml2.cpp
    ${PROJECT_SOURCE_DIR}/tools/src/MessageGenerator.h
    ${PROJECT_SOURCE_DIR}/tools/src/MessageGenerator.cpp
)


# add the UI stuff
FILE(GLOB_RECURSE uis  *.ui )
QT4_WRAP_UI(UISrcs  ${uis})
#QT4_ADD_RESOURCES(TOOLSDK_QRC "${PROJECT_SOURCE_DIR}/tools/ToolSDK/QtUtils/Resources/ToolSDK.qrc")
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

#add the executable
add_executable(MessageTester ${SourceFiles} ${UISrcs} ${TOOLSDK_QRC} ${SourceMessageGenerator} )

#link libs to executable
target_link_libraries(MessageTester Qt4::QtGui)
target_link_libraries(MessageTester ToolSDK)
target_link_libraries(MessageTester QtPropertyBrowser)
target_link_libraries(MessageTester mecl)
target_link_libraries(MessageTester Platform)
target_link_libraries(MessageTester Osal)