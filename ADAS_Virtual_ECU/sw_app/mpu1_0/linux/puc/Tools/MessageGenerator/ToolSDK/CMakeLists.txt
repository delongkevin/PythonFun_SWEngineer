INCLUDE("${PROJECT_SOURCE_DIR}/CMakeUtils.txt")

# add sources to project
GET_SOURCE_FILES("")
message(STATUS "  found source file(s):")
FOREACH(SourceFile ${SourceFiles})
	get_filename_component(FileName ${SourceFile} NAME)
	message(STATUS "    ${FileName}")
ENDFOREACH(SourceFile)


include_directories("${PROJECT_SOURCE_DIR}/libsExt/DevIL/include")
include_directories("${PROJECT_SOURCE_DIR}/libsExt/FreeType/include")
include_directories("${PROJECT_SOURCE_DIR}/libsExt/FreeType/include/freetype2")
include_directories("${PROJECT_SOURCE_DIR}/libs/pvs/mecl")
include_directories("${PROJECT_SOURCE_DIR}/libs/pvs/platform")
include_directories("${PROJECT_SOURCE_DIR}/libs/pvs/osal")
include_directories("${PROJECT_SOURCE_DIR}/tools/QtPropertyBrowser")

#add qt
set(CMAKE_AUTOMOC ON)
find_package(Qt4 4.7.1 REQUIRED QtGui QtCore)
INCLUDE(${QT_USE_FILE})
FILE(GLOB_RECURSE uis  *.ui )
#FILE(GLOB_RECURSE res  *.rc )
QT4_WRAP_UI(UISrcs  ${uis})
QT4_ADD_RESOURCES(CE_QRC ${res})
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})


add_definitions(-DNOMINMAX)

add_library(ToolSDK STATIC ${SourceFiles} ${UISrcs} ${CE_QRC})