
INCLUDE("${PROJECT_SOURCE_DIR}/CMakeUtils.txt")

# add sources to project
GET_SOURCE_FILES("")
message(STATUS "  found source file(s):")
FOREACH(SourceFile ${SourceFiles})
	get_filename_component(FileName ${SourceFile} NAME)
	message(STATUS "    ${FileName}")
ENDFOREACH(SourceFile)

include_directories("${PROJECT_SOURCE_DIR}/libsExt/OpenGL/include")
include_directories("${PROJECT_SOURCE_DIR}/libsExt/DevIL/include")
include_directories("${PROJECT_SOURCE_DIR}/libs/pvs/mecl")
include_directories("${PROJECT_SOURCE_DIR}/libs/pvs/osal")
include_directories("${PROJECT_SOURCE_DIR}/libs/pvs/platform")
include_directories("${PROJECT_SOURCE_DIR}/src")
include_directories("${PROJECT_SOURCE_DIR}/tools/ToolSDK")

if (Vulkan)
	include_directories("${Vulkan_INCLUDE_DIR}")
else ()

endif()


if (BuildEditor)
	add_definitions(-DNOMINMAX -D_CRT_SECURE_NO_WARNINGS -DUSE_DIRECTORY_WATCHER)
else (BuildEditor)
	add_definitions(-DNOMINMAX -D_CRT_SECURE_NO_WARNINGS)
endif (BuildEditor)


add_library(me3d ${SourceFiles})
