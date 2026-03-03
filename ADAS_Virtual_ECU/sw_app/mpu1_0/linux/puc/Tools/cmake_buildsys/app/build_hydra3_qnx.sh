#!/bin/bash
RUNTIMESTATS_ENABLE="$1"

#source /opt/qnx710/qnxsdp-env.sh
source ~/qnx710/qnxsdp-env.sh
mkdir -p hydra_build_qnx
cd hydra_build_qnx
echo tests
# Handle RUNTIMESTATS_ENABLE flag
if [ "$RUNTIMESTATS_ENABLE" == "RT_DISABLE" ]; then
    RUNTIME_STATS_FLAG="-DENABLE_RUNTIME_STATS=OFF"
else
    RUNTIME_STATS_FLAG="-DENABLE_RUNTIME_STATS=ON"
fi
cmake -DCMAKE_TOOLCHAIN_FILE=../../addons/toolchain_hydra3_stellantis_qnx.cmake  $RUNTIME_STATS_FLAG ../../../../App/code/
make -j $(nproc)
