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


project("libhv" C CXX)

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
  add_definitions("-DBUILD_NATIVE")
  add_definitions("-ggdb -msse4.1 -Wno-unused-function -Wno-sign-compare -Wno-sequence-point -Wno-unused-result -Wno-deprecated-declarations")
  include_directories(${GSTREAMER_INCLUDE_DIRS})
endif()

# ...source files
file(GLOB LIB_C_SRC "wf.c" "vp1_ackermann_model.c" "hv.c")

# ...include directories
include_directories(
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "${CMAKE_CURRENT_SOURCE_DIR}/../platform/qnx/inc"
  "${CMAKE_CURRENT_SOURCE_DIR}/../inc"
)

# ...build library
add_library(hv ${LIB_C_SRC})

# ...installation
if (NOT BINARY_DIR)
  set(BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../output)
endif()

message(STATUS "Installation directory: ${BINARY_DIR}")

install(
  TARGETS hv
  DESTINATION ${BINARY_DIR}
  LIBRARY DESTINATION ${BINARY_DIR}
  ARCHIVE DESTINATION ${BINARY_DIR}
)
