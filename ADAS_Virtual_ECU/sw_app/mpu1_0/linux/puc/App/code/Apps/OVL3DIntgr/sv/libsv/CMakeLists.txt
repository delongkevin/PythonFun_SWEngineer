#******************************************************************************
# CMake Build configuration for Surround View Video I/O library
#
# Copyright: Cogent Embedded Inc. 2016-2017
# All Rights Reserved
#
# This file is part of Surround View
#
# It is subject to the license terms in the LICENSE file found in the top-level
# directory of this distribution or by request via http://cogentembedded.com
#
# *****************************************************************************/

cmake_minimum_required (VERSION 2.8)


project("libsv" C CXX)

#------------------------------------------------------------------------------
# Dependencies
#------------------------------------------------------------------------------
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# search for additional CMake modules
list(APPEND CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/../cmake
)

list(APPEND CMAKE_FIND_ROOT_PATH
    ${CMAKE_INSTALL_PREFIX}
)

set(CMAKE_THREAD_PREFER_PTHREAD true)

#------------------------------------------------------------------------------
# Mandatory includes and libraries
#------------------------------------------------------------------------------

if(CMAKE_BUILD_TOOL MATCHES "(msdev|devenv|nmake|MSBuild)")
  add_definitions("/W2")
else()
  add_definitions("-O3 -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-local-typedefs -Wno-unused-variable -Wno-unused-but-set-variable -Wno-strict-aliasing")
endif()

# ...add extra definition (for native building)
if (CMAKE_SYSTEM_NAME MATCHES "QNX")
  add_definitions("-ggdb -Wno-unused-function -Wno-sign-compare -Wno-sequence-point -Wno-unused-result -Wno-deprecated-declarations")
  set(PLATFORM_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../platform/qnx)
else()
  # ...set native building flag
  add_definitions("-DBUILD_NATIVE")
  add_definitions("-ggdb -msse4.1 -Wno-unused-function -Wno-sign-compare -Wno-sequence-point -Wno-unused-result -Wno-deprecated-declarations")
endif()

# ...enable tweak-tool interface
add_definitions("-DUSE_TWEAK")

# ...specify sources
file(GLOB LIB_C_SRC
  "camera.c"
  "mesh-gen.c"
  "mesh-render.c"
  "view-manager.c"
  "scene.c"
  "ui.c"
  "guidelines.c"
  "icons.c"
  "odo.c"
  "aiming.c"
  "cc.c"
  "algo.c"
  "vm-tweak.c"
#  ${PLATFORM_SRC_DIR}/stub.c
  ${PLATFORM_SRC_DIR}/display.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../src/png-load.c
  ${CMAKE_CURRENT_SOURCE_DIR}/../src/bmp-load.c
)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/../inc" "${PLATFORM_SRC_DIR}/inc")

# ...include directories
if (NOT CMAKE_SYSTEM_NAME MATCHES "QNX")
  include_directories(${GSTREAMER_INCLUDE_DIRS})
endif()

# ...build library
add_library(sv ${LIB_C_SRC})

target_link_libraries(sv tweak)

# ...installation
if (NOT BINARY_DIR)
  set(BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../output)
endif()

message(STATUS "Installation directory: ${BINARY_DIR}")

install(
  TARGETS sv
  DESTINATION ${BINARY_DIR}
  LIBRARY DESTINATION ${BINARY_DIR}
  ARCHIVE DESTINATION ${BINARY_DIR}
)
