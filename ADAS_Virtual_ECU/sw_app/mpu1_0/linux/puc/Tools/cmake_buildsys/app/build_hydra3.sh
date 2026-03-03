#!/bin/bash


mkdir -p hydra_build
cd hydra_build
cmake -DCMAKE_TOOLCHAIN_FILE=../../addons/toolchain_hydra3_linux.cmake  ../../../../App/code/

make -j 6

