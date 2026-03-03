# DDR Eye Tool
### Built for running from the SD card.

1. Note that the TI provided pattern generator pre-compiled binary does not work
   - Memory allocation error?  wchar_t incompatibility?
   - Alternate static buffers were created
   - Filled with 4 different patterns
2. Build the DDREye tool and create the image (shown for Windows, Linux is make instead of gmake)
   ```
   cd /c/prjtools/sdk/pdk/packages/ti/board/diag/DDREye/build
   gmake CORE=mcu1_0 BUILD_OS_TYPE=baremetal BOARD=j721s2_hyd SOC=j721s2
   /c/prjtools/sdk/pdk/packages/ti/boot/sbl/tools/scripts/K3ImageGen.bat 4 /c/prjtools/sdk/pdk/packages/ti/binary/board_diag_DDREye/bin/j721s2/board_diag_DDREye_mcu1_0_release.xer5f
   ```
3. Copy to "app" to the SD card
4. Run the Read and Write tests, saving data for each to a file for later post-processing
   - Ctrl-A, L in minicom turns on (and off) file capture
5. Post-processing: Navigate to the tools folder and run:
   ```
   perl jacinto7_ddrss_tools_marginAnalysis.pl read_eye.txt
   ```
6. An Excel spreadsheet will be created with colorful plots
   - The script creates a pop-up menu where a label needs to be assigned to the spreadsheet.
   - The pop-up is behind everything, so if it seems like it is taking forever, go look for this.

