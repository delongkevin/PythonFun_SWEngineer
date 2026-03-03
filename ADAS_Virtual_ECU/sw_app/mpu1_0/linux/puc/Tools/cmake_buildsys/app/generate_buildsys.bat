@echo off
color 0F
setlocal ENABLEDELAYEDEXPANSION

echo.
echo %date% - %time:~0,2%:%time:~3,2%:%time:~6,2%
echo.

Title Fisker Hydra3 (PuC) Application Build
set h=%TIME:~0,2%
set m=%TIME:~3,2%
set s=%TIME:~6,2%

echo.
echo ========================================================================================================
echo SET parameters
echo ========================================================================================================
:: Set environment variable
echo Using Env: %1
call %1

:: Set script parameter
if "%2"=="clean" (
    if exist %BUILD_BASE_DIR% (rmdir /s /q %BUILD_BASE_DIR%)
    
    echo %BUILD_BASE_DIR%
    echo.
    goto :SKIP_BUILDINDG
)

echo.
echo ========================================================================================================
echo TOOL Installation
echo ========================================================================================================
if not exist "%TOOLS_DIR%" md %TOOLS_DIR%
  copy %REMOTE_PACKAGER_EXE% %TOOLS_DIR% /Y >nul
if not exist "%PACKAGER_EXE%" copy %REMOTE_PACKAGER_EXE% %TOOLS_DIR% /Y >nul  
if exist "%PACKAGER_EXE%" goto MAKE_UPDATE
  echo ERROR: Environment update/installation failed
  echo  - Packager required at %PACKAGER_EXE%
  echo  - Copy from ^"%REMOTE_PACKAGER_EXE%^" failed
  echo  - Please contact Integration Team
  pause
  exit
:MAKE_UPDATE
:: Update tool environment with using packager
pushd %~dp0\config\Packager
  call %PACKAGER_EXE% -c %PACKAGER_CONFIG% install
popd

echo.
echo ========================================================================================================
echo Generate CMAKE environment
echo ========================================================================================================
set BUILD_CMAKE_CONFIG=%WORKSPACE_DIR%\..\..\..\App\code
pushd %~dp0\config\Build\Cmake
  
  if "%BUILD_MODES%"=="" (goto CmakeSingleConfig) else (goto CmakeMultiConfig)
  
:CmakeSingleConfig
  %CMAKE_EXE% .  -G%BUILD_SYS% -H"%BUILD_CMAKE_CONFIG%" -B"%BUILD_BASE_DIR%" %CMAKE_EXTRA%
  goto FinishCmake

:CmakeMultiConfig
  echo %CMAKE_EXE% . -G%BUILD_SYS% -H"%BUILD_CMAKE_CONFIG%" -B"%BUILD_BASE_DIR%" %CMAKE_EXTRA%
  for %%a in (%BUILD_MODES%) do (
    %CMAKE_EXE% . -DCMAKE_BUILD_TYPE=%%a -G%BUILD_SYS% -H"%BUILD_CMAKE_CONFIG%" -B"%BUILD_BASE_DIR%\%%a" %CMAKE_EXTRA%
  )

:FinishCmake
  call :ReturnExitcode !ERRORLEVEL!
popd


:SKIP_BUILDINDG
echo Script start at: %h%:%m%:%s%
set h=%TIME:~0,2%
set m=%TIME:~3,2%
set s=%TIME:~6,2%
echo Script ended at: %h%:%m%:%s%

color 2F
exit /b 0

:ReturnExitcode
echo ExitCode: %~1.
if %~1==0 call exit /b 0
color 4F
cd %WORKSPACE_DIR%
call :__SetErrorLevel %~1
call :__ErrorExit 2>nul

:__ErrorExit
:: Creates a syntax error, stops immediately
()
goto :eof

:__SetErrorLevel
exit /b %~1
endlocal
goto :eof
