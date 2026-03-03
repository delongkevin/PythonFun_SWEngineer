HOW TO BUILD DOXYGEN DOCUMENTATION
----------------------------------
This following paragraphs describes prerequisites and instructions related to building Doxygen HTML documention for the
MECL library. 

Conventions:
All subsequent instructions in this guide assume the MECL library is located in the following folder:

C:\_mks\Projects\Magna_Bookshelf_Library\Software\10_PlatformFeatures_MultiCamera\MagnaElectronicsCommonLibrary_MECL


1. Prerequisites:
-----------------

1.1 Installation
----------------
Prior to building the documentation the following tools must be installed:

- Doxygen		  (1.8.7)
- GraphViz	  (2.38)

All installers can be located in the following folder:

T:\10_Development_DAS\80_Library\Tools\Standardtools\Doxygen\Install

No specific installation order applies.


1.2 Configuration
-----------------
The following steps must be performed prior to building the documentation:

- Add the GraphViz binaries folder to the PATH environment variable
	GraphViz:		  C:\Program Files (x86)\Graphviz2.38\bin
  
- Make sure Doxygen binaries folders is present in the PATH environment variable
	Doxygen: 		  C:\Program Files\doxygen\bin

- Make sure there is a symbolic link named "mecl"	point to the "/src" subfolder in MECL 
  Command:      mklink /D mecl .\src
  Note: The command must be performed from a command console window in the MECL root folder.

Note: Paths may differ based on whether x64 or x86 versions of the tools are installed.


2. Build
--------
The following section describes how to build the Doxygen HTML documentation.

- Open the doxygen configuration file in your MECL library "/doc" source subfolder in Doxywizard
  File:       Doxyfile
- Generate HTML documentation by pressing "Run doxygen" on the "Run" tab.
  