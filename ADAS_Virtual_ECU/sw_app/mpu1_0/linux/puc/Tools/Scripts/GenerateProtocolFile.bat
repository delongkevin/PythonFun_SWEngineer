set INPUT_MODELFILE=..\..\App\code\Framework\CoreServices\SigMIntgr\cfg\SigM_PVS_MessageModel.xml
set OUTPUT_GENDIR=..\..\App\code\Framework\CoreLibs\container\cfg\shmdata

set OUTPUT_FILENAME=SigM_Messages
set NETWORK_ENDIANNESS=1 REM we want big endianness

REM remove write protection of output dir:
attrib -r %OUTPUT_GENDIR%\*.* /S

"../MessageGenerator/build/src/Release/MessageGenerator.exe" %INPUT_MODELFILE% %OUTPUT_GENDIR% %OUTPUT_FILENAME% %NETWORK_ENDIANNESS%
