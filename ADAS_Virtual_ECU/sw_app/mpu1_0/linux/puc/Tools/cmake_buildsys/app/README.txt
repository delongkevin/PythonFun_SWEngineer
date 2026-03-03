

How to build:

1. Drag 'n drop "setenv_xxx.bat" onto "generate_buildsys.bat"
  This will install all necessary tools into "C:\prjtools"
  and creates the corresponding makefile environment or Visual Studio environment, using the CMakeLists.txt in "code"
2. Run "build.bat" to run QNX puc_app.out compilation
or
3. If you created the environment with "setenv_win.bat", you can find the .sln file in "./build/vs10build"