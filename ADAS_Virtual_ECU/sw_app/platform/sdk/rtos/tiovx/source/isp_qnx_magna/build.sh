#!/bin/bash
rm -rf ./b
mkdir b ; cd b
cmake -DUSE_TWEAK=1 -VERSION_GEN=1 -DCMAKE_TOOLCHAIN_FILE=../cmake/qnx.toolchain.cmake ..
make -j4 && cp ./libcogent_isp_tuning.so /nfs/qnxsk/lib/libcogent_isp_tuning.so.1 && cp ./libcogent_isp_tuning.so /nfs/qnxsk/lib/libcogent_isp_tuning.so
cd ..

