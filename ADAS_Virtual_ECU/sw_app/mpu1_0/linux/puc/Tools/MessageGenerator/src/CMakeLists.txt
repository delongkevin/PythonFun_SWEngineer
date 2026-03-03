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


# add sources to project
GET_SOURCE_FILES("")
message(STATUS "  found source file(s):")
FOREACH(SourceFile ${SourceFiles})
  get_filename_component(FileName ${SourceFile} NAME)
  message(STATUS "    ${FileName}")
ENDFOREACH(SourceFile)

add_executable(MessageGenerator ${SourceFiles})