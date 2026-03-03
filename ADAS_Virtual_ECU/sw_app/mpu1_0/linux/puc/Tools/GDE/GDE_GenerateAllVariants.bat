

REM -- Variant0 ---
set INPUT_VARIANT_DIR_0=C:\_mks\L2H0480\KP03_ProductEngineering\40_Software\20_Construction\L2H0480_780B\PuC\App\code\Framework\CoreLibs\variants\variants\Variant0
set INPUT_YEAR=%1
set INPUT_WEEK=%2
set INPUT_DAY=%3
set INPUT_BUILD=%4
GenericDataEditor.exe %INPUT_VARIANT_DIR_0% %INPUT_YEAR% %INPUT_WEEK% %INPUT_DAY% %INPUT_BUILD% 

REM once more variants are available, call GDE again for each variant
REM set INPUT_VARIANT_DIR_1=C:\_mks\L2H0480\KP03_ProductEngineering\40_Software\20_Construction\L2H0480_780B\PuC\App\code\Framework\CoreLibs\variants\variants\Variant1
REM GenericDataEditor.exe %INPUT_VARIANT_DIR_1%