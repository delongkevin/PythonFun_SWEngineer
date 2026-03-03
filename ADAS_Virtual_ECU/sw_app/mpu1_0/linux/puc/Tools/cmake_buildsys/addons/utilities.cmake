##********************************************************************************************
## $Copyright: $
##           MAGNA Electronics - C O N F I D E N T I A L
##           This document in its entirety is CONFIDENTIAL and may not be
##           disclosed, disseminated or distributed to parties outside MAGNA
##           Electronics without written permission from MAGNA Electronics.
##********************************************************************************************
## $Id: utilities.cmake 1.1.2.1 2021/08/18 12:11:13CEST Martin Rachor (MEE_MRACHO) draft  $
##********************************************************************************************


MACRO(GET_SOURCE_FILES _RootFolderName)
    message(STATUS "Scanning source files...")
    set(SourceFiles "")
    file(GLOB TXTs "${CMAKE_CURRENT_SOURCE_DIR}/*.txt" )
    set(SourceFiles ${SourceFiles} ${TXTs})
    GET_SOURCE_FILES_FROM_DIR("${CMAKE_CURRENT_SOURCE_DIR}" "${_RootFolderName}")
    PRINT_SRC_FILES("${SourceFiles}")
ENDMACRO()


MACRO(GET_SOURCE_FILES_FROM_DIR _Directory _NodeName)
    file(GLOB Cpps "${_Directory}/*.cpp" "${_Directory}/*.c") 
    file(GLOB Hpps "${_Directory}/*.hpp" ) 
    file(GLOB Headers "${_Directory}/*.h")
    string(REPLACE "/" "\\" Node "${_NodeName}")
    source_group("${Node}" FILES ${Cpps} ${Hpps} ${Headers})
    set(SourceFiles ${SourceFiles} ${Cpps} ${Hpps} ${Headers})
    
    SUBDIRLIST("${_Directory}")
    FOREACH(SubDir ${SubDirectoryList})
        GET_SOURCE_FILES_FROM_DIR("${_Directory}/${SubDir}" "${_NodeName}/${SubDir}")
    ENDFOREACH()
ENDMACRO()


MACRO(SUBDIRLIST _CurDir)
    FILE(GLOB children RELATIVE ${_CurDir} ${_CurDir}/*)
    SET(SubDirectoryList "")
    FOREACH(child ${children})
        IF(IS_DIRECTORY "${_CurDir}/${child}")
            SET(SubDirectoryList ${SubDirectoryList} ${child})
        ENDIF()
    ENDFOREACH()
ENDMACRO()

MACRO(PRINT_SRC_FILES _VarName)
    set(temp_str "")
    foreach(srcfile ${_VarName})
        set(temp_out "")
        get_filename_component(temp_out ${srcfile} NAME)
        if(${temp_out} MATCHES "^.*.cpp$" OR ${temp_out} MATCHES "^.*.hpp$" OR ${temp_out} MATCHES "^.*.c$")
            set(temp_str "${temp_str} ${temp_out}")
        endif()
    endforeach()
    message(STATUS "FOUND: ${temp_str}")
    message(STATUS "")
    message(STATUS "")
ENDMACRO()


MACRO(SET_ABS_PATH uservariable relpath)
    #MESSAGE(STATUS "${uservariable}: ${relpath}")
    get_filename_component(abspath ${relpath} ABSOLUTE)
    set(${uservariable} ${abspath})
    #MESSAGE(STATUS "${uservariable}: ${abspath}")
ENDMACRO()






