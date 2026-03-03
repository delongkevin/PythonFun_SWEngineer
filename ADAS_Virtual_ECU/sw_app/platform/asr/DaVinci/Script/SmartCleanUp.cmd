echo off
PUSHD ..\..\app_sip\GenData\mcu1_0

rmdir /s/q mak
rmdir /s/q Make
rmdir /s/q RteCache

POPD
PUSHD ..\..\..\..\mcu1_0\app
del /s/q *.bak
POPD

POPD
PUSHD ..\..\app_sip\GenData\mcu1_0\Components
del /s/q *.bak
POPD

POPD
PUSHD ..\..\app_sip\GenData\mcu1_0
del /s/q *.bak
POPD