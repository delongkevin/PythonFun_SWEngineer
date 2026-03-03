@ echo off
@ set PATH="%CD%.\SvgParse\";%PATH%
@ set SvgFile="%CD%\cfg\OverlayDictionary.svg"
@ set OutDir="%CD%\flashdata"

echo -------------------
echo Starting Svg Parser
echo -------------------
sleep 2
  

::SvgParse.exe %SvgFile% %OutDir% "/Debug" "/Clr" "/Format:0" "/Font"
SvgParse.exe %SvgFile% %OutDir% "/Clr" "/Format:2" "/Font"

pause