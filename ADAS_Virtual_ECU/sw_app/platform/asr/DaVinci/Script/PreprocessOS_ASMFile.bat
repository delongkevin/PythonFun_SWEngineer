@echo off
setlocal ENABLEDELAYEDEXPANSION

REM The path variables required for the script.
set TDM_GCC_DIR=C:\prjtools\compilerFisker\gcc-4.9.2-tdm-1-dw2-core\bin
set OS_SIPPATH=..\..\app_sip\Os\Implementation
set GENDATA_PATH=..\..\app_sip\GenData\mcu1_0

set AsmFile1=Os_Hal_Compiler_TiInt
set AsmFile2=Os_Hal_ContextAsm
set AsmFile3=Os_Hal_EntryAsm_Lcfg
set AsmFile4=Os_Hal_MemoryProtection_PMSAv7_CacheMaintenance

PUSHD %OS_SIPPATH%
del /q *_llvm.asm
POPD

PUSHD %GENDATA_PATH%
del /q Os_Hal_EntryAsm_Lcfg_llvm.asm
POPD

cpp.exe -P -DOS_CFG_COMPILER_TEXASINSTRUMENTS -I %OS_SIPPATH% -I %GENDATA_PATH% %OS_SIPPATH%\%AsmFile1%.asm -o %OS_SIPPATH%\%AsmFile1%_llvm.asm
cpp.exe -P -DOS_CFG_COMPILER_TEXASINSTRUMENTS -I %OS_SIPPATH% -I %GENDATA_PATH% %OS_SIPPATH%\%AsmFile2%.asm -o %OS_SIPPATH%\%AsmFile2%_llvm.asm
cpp.exe -P -DOS_CFG_COMPILER_TEXASINSTRUMENTS -I %OS_SIPPATH% -I %GENDATA_PATH% %OS_SIPPATH%\%AsmFile4%.asm -o %OS_SIPPATH%\%AsmFile4%_llvm.asm
cpp.exe -P -DOS_CFG_COMPILER_TEXASINSTRUMENTS -I %OS_SIPPATH% -I %GENDATA_PATH% %GENDATA_PATH%\%AsmFile3%.asm -o %GENDATA_PATH%\%AsmFile3%_llvm.asm