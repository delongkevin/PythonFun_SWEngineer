#!/bin/bash
echo $(git describe --tags) $(git log --pretty=oneline -1) > version_info.txt
xxd -i version_info.txt > ./version_new.h
cp version_info.txt /tmp/
rm version_info.txt

if [[ $(cmp ./version.h ./version_new.h 2>&1) ]]; then
    cp ./version_new.h ./version.h
    echo cp ./version_new.h ./version.h
else
    echo "version up to date"
fi

rm ./version_new.h
