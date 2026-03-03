#!/bin/bash
#set -xv
# ********************************************************************************************
#  $Copyright: $
#            MAGNA Electronics - C O N F I D E N T I A L
#            This document in its entirety is CONFIDENTIAL and may not be
#            disclosed, disseminated or distributed to parties outside MAGNA
#            Electronics without written permission from MAGNA Electronics.
# ********************************************************************************************
# $Id: build.sh 1.1 2019/11/02 21:44:26EDT Gopinath Ramanathan (gopirama) draft  $
# ********************************************************************************************
# 
echo
date
echo
echo "+------------------------------------------------"
echo "+   Envrionment for PSA PVS PuC Build Process    "  
echo "+------------------------------------------------"
echo
echo Title PSA PVS PuC Build
s_timestart=$(date)
echo "$0 started at: $s_timestart"

# ******************************************
#     GLOBAL SWITCHES
# ******************************************

source ~/qnx710/qnxsdp-env.sh


#set BUILD_TOOLS_SETUP=TRUE
#set BUILD_TOOLS_LIST="cmake,mingw32,qacx,qacpp,qnx,amap"
#set SUPPLIER_DELIVERY=FALSE
#set CUSTOMER_DELIVERY=FALSE

s_scriptabs=$(readlink -f $0)
s_scriptdir=$(dirname $s_scriptabs)

cd $s_scriptdir
s_cd=$(pwd)
echo "working dir is '$s_cd'"

ORIGDIR=$s_scriptdir
cd $ORIGDIR
BUILD_BASE_DIR=$s_cd/qnxbuild


#:SKIP_TOOLS_SETUP
#REM ******************************************
#REM Generate build system
#REM ******************************************
#cd /D %ORIGDIR%
s_gen="N"
[ ! -r $BUILD_BASE_DIR/Release/Makefile ] && s_gen="Y"
[ ! -r $BUILD_BASE_DIR/Debug/Makefile ] && s_gen="Y"
if [ "$s_gen" == "Y" ]
then
  ./generate_buildsys.sh 2
fi

# Check for build system
[ ! -r $BUILD_BASE_DIR/Release/Makefile ] && echo "ERROR in Release Build System Generation" && exit 1
[ ! -r $BUILD_BASE_DIR/Debug/Makefile ] && echo "ERROR in Debug Build System Generation" && exit 1


# ******************************************
# Build
# ******************************************

#set custom-make="MAKE=mingw32-make -j -l%NUMBER_OF_PROCESSORS%"

BIN_NAME=puc_app
BIN_EXTN=out

if [ "$1" == "" ]
then
	echo "WARNING: Parameter 1 missing. Default is 'debug' build mode"
	BUILD_MODE=deb 
else
	BUILD_MODE=$1
fi

if [ "$2" == "" ]
then
	echo "WARNING: Parameter 2 missing. Default is build 'all'"
	TARGET=all
else
	TARGET=$2
fi


set QNX_HOST="~/qnx710/target/qnx7/host/win64/x86_64"
set QNX_TARGET="~/qnx710/target/qnx7/target/qnx7"

echo
echo

echo Switch to Build dir..
cd $ORIGDIR
echo Build dir is $ORIGDIR
echo
echo


#REM Get ABS Path of output dir
OUTPUT_BASE=$ORIGDIR/../../../App/build
#pushd %OUTPUT_BASE%
#set OUTPUT_BASE=%CD%
#popd

# TODO
#REM Make output dir writable
#if exist %OUTPUT_BASE% (attrib -r %OUTPUT_BASE%\* /s /d)
	
if [ "$BUILD_MODE" == "rel" ]
then
    OUTPATH=$OUTPUT_BASE/out/release
    LIBPATH=$OUTPUT_BASE/libs/qnx/release
    BUILD_DIR=$BUILD_BASE_DIR/Release
    MODE=RELEASE
fi

if [ "$BUILD_MODE" == "deb" ]
then
    OUTPATH=$OUTPUT_BASE/out/debug
    LIBPATH=$OUTPUT_BASE/libs/qnx/debug
    BUILD_DIR=$BUILD_BASE_DIR/Debug
    MODE=DEBUG
fi

if [ "$BUILD_MODE" == "pro" ]
then
    OUTPATH=$OUTPUT_BASE/out/profile
    LIBPATH=$OUTPUT_BASE/libs/qnx/profile
    BUILD_DIR=$BUILD_BASE_DIR/profile
    MODE=PROFILE
fi

#REM Remove previous lib files
[ -r $LIBPATH/$BIN_NAME.$BIN_EXTN ]    && /bin/rm -f  $LIBPATH/$BIN_NAME.$BIN_EXTN

#REM Remove previous output files
[ -r $OUTPATH/$BIN_NAME.$BIN_EXTN ]    && /bin/rm -f  $OUTPATH/$BIN_NAME.$BIN_EXTN
[ -r $OUTPATH/$BIN_NAME.map ]          && /bin/rm -f  $OUTPATH/$BIN_NAME.map
[ -r $OUTPATH/$BIN_NAME.$BIN_EXTN ]    && /bin/rm -f  $OUTPATH/$BIN_NAME.$BIN_EXTN

#REM Create the out folder if missing
[ ! -d $OUTPATH ] && mkdir -p $OUTPATH 
[ ! -d $LIBPATH ] && mkdir -p $LIBPATH 

echo
echo
echo INFO: Used Compiler version
echo
$compiler --version

echo
echo
echo INFO: Start $MODE Build
cd $BUILD_DIR
s_cd=$(pwd)
echo $MODE Build dir is $s_cd
echo
echo

if [ "$TARGET" == "clean" ]
then
    echo INFO: Clean previous build artifacts
    rm $LIBPATH/*.*
    # ping 1.1.1.1 -n 1 -w 500> nul
else
    echo INFO: Build new artifacts
fi

echo
echo

# TODO: faster builds for users
#[ "$USERNAME" != "srv_hudsonci" ] && set MAKEFLAGS=sj%NUMBER_OF_PROCESSORS%)
#mingw32-make %custom-make% %TARGET%
make -j 16 -i -k $TARGET
echo
echo

if [ "$TARGET" == "all" ]
then
    echo INFO: Test Build Results
    if [ -r $LIBPATH/$BIN_NAME.$BIN_EXTN ]
	then
        echo INFO: Build Successful
        echo INFO: Copy binaries...
        echo
        cp $LIBPATH/$BIN_NAME.$BIN_EXTN $OUTPATH
        cp $LIBPATH/$BIN_NAME.$BIN_EXTN.map $OUTPATH/$BIN_NAME.map
        cp $LIBPATH/TestTarget64.$BIN_EXTN $OUTPATH
        echo
        echo Files copied to: $OUTPATH
    else
		echo File missing: $LIBPATH/$BIN_NAME.$BIN_EXTN
		echo ERROR: build failed. please check.
    fi
fi
echo
echo


# set end=%time%
# set options="tokens=1-4 delims=:.,"
# for /f %options% %%a in ("%start%") do set start_h=%%a&set /a start_m=100%%b %% 100&set /a start_s=100%%c %% 100&set /a start_ms=100%%d %% 100
# for /f %options% %%a in ("%end%") do set end_h=%%a&set /a end_m=100%%b %% 100&set /a end_s=100%%c %% 100&set /a end_ms=100%%d %% 100

# set /a hours=%end_h%-%start_h%
# set /a mins=%end_m%-%start_m%
# set /a secs=%end_s%-%start_s%
# set /a ms=%end_ms%-%start_ms%
# if %ms% lss 0 set /a secs = %secs% - 1 & set /a ms = 100%ms%
# if %secs% lss 0 set /a mins = %mins% - 1 & set /a secs = 60%secs%
# if %mins% lss 0 set /a hours = %hours% - 1 & set /a mins = 60%mins%
# if %hours% lss 0 set /a hours = 24%hours%
# if 1%ms% lss 100 set ms=0%ms%
# 
# set /a totalsecs = %hours%*3600 + %mins%*60 + %secs%
# ::echo Build took %hours%:%mins%:%secs%.%ms% (%totalsecs%.%ms%s total)
# echo Build took %hours%:%mins%:%secs% (%totalsecs%.%ms%s total)
# echo. & echo.

# cd /D %ORIGDIR%
# REM dont close when started with double click
# if %0 == "%~0"  pause

# REM mingw32 with -j call occasionally modifies color. to reset color must be called again.
# color
# 
# endlocal
# goto :EOF
# 
# 
# :MY_DELAY
# ::usage --> Call with no.of seconds
# 
# setlocal
# REM Backspace Alt-08
# SET BKSPC=
# SET /a WAIT=%1
# REM echo Received %1 and Wait will be %WAIT%	& echo %TIME% & echo %WAIT%
# 
# FOR /L %%J IN (1 1 %WAIT%) DO (
# 	SET/P Z=^|<NUL
# 	ping 1.1.1.1 -n 1 -w 250> nul
#     SET/P Z=%BKSPC%<NUL
#     SET/P Z=/<NUL
# 	ping 1.1.1.1 -n 1 -w 250> nul
#     SET/P Z=%BKSPC%<NUL
#     SET/P Z=-<NUL
# 	ping 1.1.1.1 -n 1 -w 250> nul
#     SET/P Z=%BKSPC%<NUL
#     SET/P Z=\<NUL
#     ping 1.1.1.1 -n 1 -w 250> nul
# 	SET/P Z=%BKSPC%<NUL
# )
# SET/P Z=%BKSPC%<NUL
# ::echo COMPLETED
# 
# endlocal
# goto :EOF
