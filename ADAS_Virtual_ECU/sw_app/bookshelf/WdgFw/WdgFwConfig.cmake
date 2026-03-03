include("${CMAKE_CURRENT_LIST_DIR}/cmake/WdgFw.cmake")

get_target_property(WdgFw_INCLUDES      WdgFw::WdgFw   INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(WdgFw_LIBRARIES     WdgFw::WdgFw   INTERFACE_LINK_LIBRARIES)

include_directories(${WdgFw_INCLUDES}/cfg)
include_directories(${WdgFw_INCLUDES}/cfg/MCU3_0)
include_directories(${WdgFw_INCLUDES}/Wdg/inc)
include_directories(${WdgFw_INCLUDES}/WdgIf/inc)
include_directories(${WdgFw_INCLUDES}/WdgM/inc)
include_directories(${WdgFw_INCLUDES}/WdgSlave/inc)
