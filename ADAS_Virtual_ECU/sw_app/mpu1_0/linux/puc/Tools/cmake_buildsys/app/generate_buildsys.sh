#!/bin/bash
# ********************************************************************************************
#  $Copyright: $
#            MAGNA Electronics - C O N F I D E N T I A L
#            This document in its entirety is CONFIDENTIAL and may not be
#            disclosed, disseminated or distributed to parties outside MAGNA
#            Electronics without written permission from MAGNA Electronics.
# ********************************************************************************************
#  $Id: generate_buildsys.sh 1.1 2019/11/02 21:44:26EDT Gopinath Ramanathan (gopirama) draft  $
# ********************************************************************************************
#

echo
s_timestart=$(date)
echo "$0 started at: $s_timestart"
echo
echo "+------------------------------------------------"
echo "+   Envrionment for PSA PVS PuC Build Process"
echo "+------------------------------------------------"


echo
echo "*********************"
echo "* PSA PVS PuC Build *"
echo "*********************"
echo

echo Switch to cmake build system dir..

s_scriptabs=$(readlink -f $0)
s_scriptdir=$(dirname $s_scriptabs)

cd $s_scriptdir
s_cd=$(pwd)
echo "working dir is '$s_cd'"


CMAKE_EXE=cmake
TOOLCHAIN=$s_cd/../addons/toolchain_hydra3_qnx.cmake
SRC_DIR=$s_cd/../../../App/code

BUILD_BASE_DIR=""
BUILD_SYS=""

if [ "$1" == "" ] 
then
  echo
  echo INFO: Please choose target build system.
  echo
  echo "0.  MinGW Makefiles"
  echo "1.  MinGW Makefiles (x86_64)"
  echo "2.  Unix Makefiles [**default**]"
  echo "3.  Visual Studio 15 2017"
  echo "4.  Visual Studio 14 2015"
  echo "5.  Visual Studio 10 2010"
  echo "6.  Visual Studio 9 2008"
  echo "7.  Green Hills MULTI"
  echo "8.  MSYS Makefiles"
  echo "9.  Unix Makefiles"
  echo "10.  Ninja"
  echo "11. Eclipse CDT4 - MinGW Makefile"
  echo "12. Eclipse CDT4 - Ninja"
  echo
  echo "Please enter [0 to 12]: "
  read s_choice
  [ "$s_choice" == "" ] && s_choice="2"
else 
  s_choice="$1"
fi


[ "$s_choice" == "1" ] && TOOLCHAIN=$s_cd/../addons/toolchain_x86_x64.cmake

EXTRA=""
[ "$s_choice" == "0" ] && BUILD_SYS="MinGW Makefiles" && BUILD_BASE_DIR=./qnxbuild && EXTRA="-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON -DCMAKE_RULE_MESSAGES:BOOL=ON -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN"
[ "$s_choice" == "1" ] && BUILD_SYS="MinGW Makefiles" && BUILD_BASE_DIR=./qnxbuild && EXTRA="-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON -DCMAKE_RULE_MESSAGES:BOOL=ON -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN"
[ "$s_choice" == "2" ] && BUILD_SYS="Unix Makefiles" && BUILD_BASE_DIR=./qnxbuild && EXTRA="-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON -DCMAKE_RULE_MESSAGES:BOOL=ON -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN"
[ "$s_choice" == "3" ] && BUILD_SYS="Visual Studio 15 2017" && BUILD_BASE_DIR=./vs15build
[ "$s_choice" == "4" ] && BUILD_SYS="Visual Studio 14 2015" && BUILD_BASE_DIR=./vs14build
[ "$s_choice" == "5" ] && BUILD_SYS="Visual Studio 10 2010" && BUILD_BASE_DIR=./vs10build
[ "$s_choice" == "6" ] && BUILD_SYS="Visual Studio 9 2008" && BUILD_BASE_DIR=./vs9build
[ "$s_choice" == "7" ] && BUILD_SYS="Green Hills MULTI"
[ "$s_choice" == "8" ] && BUILD_SYS="MSYS Makefiles"
[ "$s_choice" == "9" ] && BUILD_SYS="Unix Makefiles" && BUILD_BASE_DIR=./unxbuild
[ "$s_choice" == "10" ] && BUILD_SYS="Ninja"
[ "$s_choice" == "11" ] && BUILD_SYS="Eclipse CDT4 - MinGW Makefile"
[ "$s_choice" == "12" ] && BUILD_SYS="Eclipse CDT4 - Ninja"

echo BUILD_SYS:$BUILD_SYS
echo BUILD_BASE_DIR:$BUILD_BASE_DIR

if [ "$BUILD_BASE_DIR" != "" ]
then
    if [ -d $BUILD_BASE_DIR ]
    then
        echo Clean previous build..
        rm -r $BUILD_BASE_DIR
    fi

    echo "Creating directory BUILD_BASE_DIR at '$BUILD_BASE_DIR'"
    mkdir $BUILD_BASE_DIR
fi

echo
echo Generate Build System for: $BUILD_SYS
echo

#echo INFO: Remove shell from path. cmake dont want it.
#cd \
#setlocal enableDelayedExpansion
#for /f "TOKENS=3,4* DELIMS= " %%A in ('dir sh.exe /s /X') DO (
#    IF EXIST %%A (
#        set PATH=!PATH:%%A;=!
#    )
#)
#endlocal & set PATH=%PATH%
#cd %~dp0


#echo INFO: Adding mingw32 to path..
#set PATH=%TOOLS_DIR%\mingw32\ver_3.82.90\bin;%PATH%
#echo. & echo.

echo $EXTRA

s_makegen="N"
[ "$s_choice" == "0" ] && s_makegen="Y"
[ "$s_choice" == "1" ] && s_makegen="Y"
[ "$s_choice" == "2" ] && s_makegen="Y"

# debug and release build wanted at UNIX? If not remove line below...
[ "$s_choice" == "8" ] && s_makegen="Y"
if [ "$s_makegen" == "Y" ]
then
    echo "Generating Release Build.."
    echo && echo && echo && echo
    $CMAKE_EXE "-DCMAKE_BUILD_TYPE=Release" "-G${BUILD_SYS}" "-H${SRC_DIR}" "-B${BUILD_BASE_DIR}/Release" $EXTRA
    echo && echo && echo && echo
    
    echo Generating Debug Build..
    echo && echo && echo && echo
    $CMAKE_EXE "-DCMAKE_BUILD_TYPE=Debug" "-G${BUILD_SYS}" "-H${SRC_DIR}" "-B${BUILD_BASE_DIR}/Debug" $EXTRA
    echo && echo && echo && echo
    
	echo Generating Profiling Build..
    echo && echo && echo && echo
    $CMAKE_EXE "-DCMAKE_BUILD_TYPE=Profile" "-G${BUILD_SYS}" "-H${SRC_DIR}" "-B${BUILD_BASE_DIR}/Profile" $EXTRA
    echo && echo 

	# Check for build system
    [ ! -r $BUILD_BASE_DIR/Release/Makefile ] && echo "ERROR: Release Build System Generation failed! Missing '$BUILD_BASE_DIR/Release/Makefile'" && exit 1
    [ ! -r $BUILD_BASE_DIR/Debug/Makefile ]   && echo "ERROR: Debug Build System Generation failed! Missing '$BUILD_BASE_DIR/Debug/Makefile'" && exit 1
else
    $CMAKE_EXE "-G${BUILD_SYS}" "-H${SRC_DIR}" "-B${BUILD_BASE_DIR}" $EXTRA
fi

# Eclipse project generation
#"C:\Program Files\CMake\bin\cmake.exe" -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON -DCMAKE_RULE_MESSAGES:BOOL=ON -G"Eclipse CDT4 - MinGW Makefiles" -D_ECLIPSE_VERSION=4.5 -H"C:\_mks\L2-G8800\KP03_ProductEngineering\40_Software\20_Construction\Infineon_AURIX_TC397x\App\vSG-A\code" -B"C:\_mks\L2-G8800\KP03_ProductEngineering\40_Software\20_Construction\Infineon_AURIX_TC397x\Tools\eclipse\vSG-A"  -DCMAKE_TOOLCHAIN_FILE="C:\_mks\L2-G8800\KP03_ProductEngineering\40_Software\20_Construction\Infineon_AURIX_TC397x\Tools\cmake_build_system\cmakemodules\toolchain.cmake"


echo && echo 



s_timeend=$(date)
echo "$0 started at: $s_timestart"
echo "$0 ended at  : $s_timeend"
echo
