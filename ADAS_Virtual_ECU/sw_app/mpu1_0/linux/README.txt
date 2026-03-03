Setup and build BSP, puc_app, mcu2_0 and A72 IPC manager process:

Note: 
Run the below scripts from ubuntu 18.04.5
Need Access to Magna VPN
Install the following QNX SDP 7.1 libraries in /home/$user/qnx710
https://software-dl.ti.com/jacinto7/esd/processor-sdk-qnx-jacinto7/07_03_00_02/exports/docs/release_notes_07_03_00_j721e.html

Setup and build bsp:
Steps
1) Navigate to 20_Construction/Application/linux/bsp
2) Run ./setup.sh
3) Ensure there is no error when downloading and extracting by checking the logs for 'fail' and 'error' text. 
   Repeat step2 after deleting the Downloads folder or the apprpriate folder based on the error
4) Run ./build.sh

Rebuild PuC

Note:
Build BSP or download the precompiled binaries from Jfrog using setup_binaries.sh

Steps
1) Run /20_Construction/Application/linux/puc/Tools/cmake_buildsys/app/build_hydra3_qnx_debug.sh for debug build
2) Run /20_Construction/Application/linux/puc/Tools/cmake_buildsys/app/build_hydra3_qnx.sh for release build

The puc_app.out will be generated in /20_Construction/Application/linux/puc/App/build/libs/qnx/debug


Build IPC Manager

Note : 
Before Building IPC Run setup.sh to create Softlink to IPC Common Files.

Source Path : 
/20_Construction/Application/linux/bsp/rtos/psdkqa/qnx/resmgr/ipc_qnx_ipcmgr/ipcmgr/src

Steps
1) Navigate to /20_Construction/Application/linux/bsp/rtos/psdkqa/qnx/
2) run 'make ipc_a72' command to build IPC Manager for A72 Core

 The mpu10ipc-ipcmgr will be generated in /20_Construction/Application/linux/bsp/rtos/psdkqa/qnx/resmgr/ipc_qnx_ipcmgr/ipcmgr/aarch64/o.le

* Debuging Log Enable :
	- Updated IPC Debug Messages in IPC Manager A72
* To Enable Logs  -> Open Respective File /20_Construction/Application/linux/bsp/rtos/psdkqa/qnx/resmgr/ipc_qnx_ipcmgr/ipcmgr/src/os/
		-> Change DEBUG_MSG to DEBUG_INFO

Note - 
- IPC Make Commands
	make ipc_a72
	make ipc_a72_clean

Build mcu2_0
1) Run ./hydra3_mcu2_0_build.sh
2) lateapp1 will be generated at /20_Construction/Application/linux/bsp/images/sbl_bootfiles/hydra3 folder 

Pack Final Firmware
Run ./build.sh the efs and other images will be available in /20_Construction/Application/linux/bsp/images folder

To create efs after modification of puc_app
1) Build puc_app.out following the above steps
2) Run ./create_bootimage.sh
3) the efs and other images will be available in /20_Construction/Application/linux/bsp/images/sbl_bootfiles/ folder

Flash Software
Open Trace32 and run the following scripts
1) To flash the Apps with DMS and C7x \30_Tools\00_TRACE32\mcu-r5\burn_flash\dra82x-ospi-MT35XU1G-snor_ospi_PROD_APPS_DMS_C7X.cmm

To Stop git Tracking libraries Without Removing It From the Repository
 Run ./git_stop_tracking_libraries.sh
To enable git tracking for the libraries that was disabled from the earlier step
 Run ./git_stop_tracking_libraries.sh no
