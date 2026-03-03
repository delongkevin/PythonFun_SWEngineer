#!/bin/bash
#set -xv
# ********************************************************************************************
#  $Copyright: $
#            MAGNA Electronics - C O N F I D E N T I A L
#            This document in its entirety is CONFIDENTIAL and may not be
#            disclosed, disseminated or distributed to parties outside MAGNA
#            Electronics without written permission from MAGNA Electronics.
# ********************************************************************************************
# $Id: build_linux.sh 1.1 2018/09/15 11:05:20CEST Hudson BatchUser (HudsonBatch) draft  $
# ********************************************************************************************
# 
echo
date
echo
echo "+---------------------------------------------------------------"
echo "+   Environment for PSA PVS PuC Embedded Linux Build Process    "
echo "+---------------------------------------------------------------"
echo
echo Title PSA PVS PuC Linux Build
s_timestart=$(date)
echo "$0 started at: $s_timestart"

# ******************************************
#     GLOBAL SWITCHES
# ******************************************



s_scriptabs=$(readlink -f $0)
s_scriptdir=$(dirname $s_scriptabs)

cd $s_scriptdir
s_cd=$(pwd)
echo "working dir is '$s_cd'"

ORIGDIR=$s_scriptdir
cd $ORIGDIR
BUILD_BASE_DIR=$s_cd/linuxbuild


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

echo
echo


#REM Get ABS Path of output dir
OUTPUT_BASE=$ORIGDIR/../../../App/build
#pushd %OUTPUT_BASE%
#set OUTPUT_BASE=%CD%
#popd


#REM Make output dir writable
#if exist %OUTPUT_BASE% (attrib -r %OUTPUT_BASE%\* /s /d)
	
if [ "$BUILD_MODE" == "rel" ]
then
    OUTPATH=$OUTPUT_BASE/out/release
    LIBPATH=$OUTPUT_BASE/libs/unx/release
    BUILD_DIR=$BUILD_BASE_DIR/Release
    MODE=RELEASE
fi

if [ "$BUILD_MODE" == "deb" ]
then
    OUTPATH=$OUTPUT_BASE/out/debug
    LIBPATH=$OUTPUT_BASE/libs/unx/debug
    BUILD_DIR=$BUILD_BASE_DIR/Debug
    MODE=DEBUG
fi

if [ "$BUILD_MODE" == "pro" ]
then
    OUTPATH=$OUTPUT_BASE/out/profile
    LIBPATH=$OUTPUT_BASE/libs/unx/profile
    BUILD_DIR=$BUILD_BASE_DIR/profile
    MODE=PROFILE
fi



PVS_SDK=/opt/poky/2.1.3
PVS_LIBSV=L2G8970/KP03_ProductEngineering/40_Software/20_Construction/L2G8970_PVS/PuC/App/code/libsv_engine

#  source $PVS_SDK/environment-setup-aarch64-poky-linux
s_envfile=$PVS_SDK/environment-setup-aarch64-poky-linux
if [ ! -r $s_envfile ]
then
    >&2 echo "[$0] ERROR - Missing environment file '$s_envfile'" 
    exit 1
fi

echo "Reading environment from '$s_envfile'"
source $s_envfile

echo "Using libsv_engine from"
echo $PVS_LIBSV
echo
echo "Adding libsv_engine to SV_FLAGS"
export SV_FLAGS=" -I/media/sf__mks/$PVS_LIBSV -L/media/sf__mks/$PVS_LIBSV -Wl,-Map=output.map "
echo 
echo
echo "BEGIN ENVIRONMENT ---------------------"
env
echo "END ENVIRONMENT ---------------------"
echo

s_out1=$BUILD_BASE_DIR/Framework/CoreServices/SysIntgr/puc_app.out
s_out2=$BUILD_BASE_DIR/Framework/CoreServices/SysIntgr/output.map
s_out3=/media/sf__mks/L2G8970/KP03_ProductEngineering/40_Software/20_Construction/L2G8970_PVS/PuC/Tools/cmake_buildsys/app/linuxbuild/Apps/TestTarget64/TestTarget64.out
s_out4=/media/sf__mks/L2G8970/KP03_ProductEngineering/40_Software/20_Construction/L2G8970_PVS/PuC/Tools/cmake_buildsys/app/linuxbuild/Apps/TestTarget64/output.map
   
echo Switch to Build dir..
mkdir -p $BUILD_BASE_DIR
echo Build dir is $BUILD_BASE_DIR
echo
echo
cd $BUILD_BASE_DIR

if [ "$TARGET" == "clean" ]
then
    rm -rf $BUILD_BASE_DIR/*
fi

if [ "$TARGET" == "all" ]
then
    /usr/bin/cmake -DCMAKE_TOOLCHAIN_FILE=$PVS_SDK/sysroots/x86_64-pokysdk-linux/usr/share/cmake/OEToolchainConfig.cmake ~/PuC/App/code
   [ -r $s_out1 ] && rm $s_out1
   [ -r $s_out2 ] && rm $s_out2
   [ -r $s_out3 ] && rm $s_out3
   [ -r $s_out4 ] && rm $s_out4
   make -j
fi

echo Listing generated files ...
ls -las $s_out1
ls -las $s_out2
ls -las $s_out3
ls -las $s_out4

[ ! -r $s_out1 ] && echo "[$0] ERROR - No puc_app.out file created" && exit 1
[ ! -r $s_out2 ] && echo "[$0] ERROR - No puc_app.map file created" && exit 1
[ ! -r $s_out3 ] && echo "[$0] ERROR - No TestTarget64.out file created" && exit 1
[ ! -r $s_out4 ] && echo "[$0] ERROR - No TestTarget64.map file created" && exit 1

exit 0


