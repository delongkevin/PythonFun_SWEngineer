#--------------------------------------------------------------------------------#
#              __                                                                #
#             //\\               (C) Copyright 2019                              #
#             \\//                                                               #
#                                Magna Electronics Europe GmbH & Co. OHG         #
#          \\\\\ \\\\\                                                           #
#        /\ \\\\\ \\\\\          Am Saegewerk 10                                 #
#       //\\ \\\\\ \\\\\         63773 Goldbach, Germany                         #
#      ///\\\ \\\\\ \\\\\        All rights reserved.                            #
#     ////\\\\ \\\\\ \\\\\                                                       #
#    /////\\\\\ \\\\\ \\\\\      http://www.magna.com                            #
#                                                                                #
#--------------------------------------------------------------------------------#
#    MAGNA Electronics - C O N F I D E N T I A L                                 #
#      This document in its entirety is CONFIDENTIAL and may not be              #
#      disclosed, disseminated or distributed to parties outside MAGNA           #
#      Electronics without written permission from MAGNA Electronics.            #
#--------------------------------------------------------------------------------#
#    Created on: 19.03.2019                                                      #
#        Author: Roman Berngardt (Roman.Berngardt@magna.com)                     #
#--------------------------------------------------------------------------------#

#---------------------------- SCRIPT CONFIG PARAMS ------------------------------#
set CONNECTION_STRING             tcp:127.0.0.1:3121
set DEVICE_NAME_FILTER_STR        "*JTAG-*"
set JTAG_MAX_FREQUENCY            30000000
set PSU_FILTER_STR                "PSU*"
set APU_FILTER_STR                "APU*"
set PMU_FILTER_STR                "MicroBlaze*PMU*"
set A53_0_FILTER_STR              "*A53*0"
set FPGA_FILTER_STR               "PL*"

set QNX_IMAGE_LOAD_ADDR           0x100000
set QNX_IMAGE_ENTRY_POINT         0x101950

#------------------ FIRMWARE FILES TO BE LOADED TO THE TARGET -------------------#
set DEPLOYMENT_MODE               [lindex $argv 0]
set PSU_INIT_TCL_PATH             [lindex $argv 1]
set PMUFW_PATH                    [lindex $argv 2]
set FSBL_FILE_PATH                [lindex $argv 3]
set FPGA_BIT_FILE_PATH            [lindex $argv 4]
set ATF_FILE_PATH                 [lindex $argv 5]
set QNX_IMAGE_FILE_PATH           [lindex $argv 6]

#---------------------------- BEGIN OF THE SCRIPT -------------------------------#

# Load the PSU_INIT.TCL script in order to be able to
# init FPGA configuration
source $PSU_INIT_TCL_PATH

# Check the deployment mode and call the corresponding method
# @param[in/out] void
# @return void
proc check_mode_and_deploy { } {
   global DEPLOYMENT_MODE
   
   switch $DEPLOYMENT_MODE {
      "mode:JTAG" {
         deploy_jtag
      }
      default {
         puts [format %s%s%s "\nERROR: Unsupported deployment mode '" $DEPLOYMENT_MODE "'! \n"]
         exit -1
      }
   }
}
#--------------------------------------------------------------------------------#

# Connect to the target
# @param[in/out] void
# @return void
 proc target_connect { } {
    puts "----> Connecting to the target..."
    global CONNECTION_STRING
    connect -url $CONNECTION_STRING
    puts "<---- Done. \n"
 }
#--------------------------------------------------------------------------------#
 
# Set maximum JTAG frequency to speed up the booting process
# @param[in/out] void
# @return void
proc set_max_jtag_freq { } {
    global DEVICE_NAME_FILTER_STR
    global JTAG_MAX_FREQUENCY
    puts [format %s%s%s "----> Set JTAG frquency to " $JTAG_MAX_FREQUENCY " Hz..."]
    jtag targets -set -nocase -filter {name =~ $DEVICE_NAME_FILTER_STR}
    puts [format %s%s%s "INFO: JTAG frequency is set to " [jtag frequency $JTAG_MAX_FREQUENCY] " Hz."]
    puts "<---- Done. \n";
 }
#--------------------------------------------------------------------------------#

# Check the MPSoC boot mode (should be JTAG boot mode)
# @param[in/out] void
# @return void
proc check_boot_mode { } {
   puts "----> Check the MPSoC boot mode..."
   global PSU_FILTER_STR
   targets -set -nocase -filter {name =~ $PSU_FILTER_STR}
   set mask 0x0F
   set curval "0x[string range [mrd -force 0xFF5E0200] end-8 end]"
   set boot_mode [expr {$curval & $mask}]
   if {0x0 != $boot_mode} {
     puts "ERROR: Wrong value of MPSoC boot mode!"
	 puts "       Please select the JTAG boot mode ->"
     puts "       (all DIP-switches should be switched ON).\n"
   } else {
     puts "INFO: The SoC is in JTAG boot mode."
   }
   puts "<---- Done. \n";
   if {0x0 != $boot_mode} {
     exit -1
   }
}
#--------------------------------------------------------------------------------#

# Reset the target system
# @param[in/out] void
# @return void
proc target_reset { } {
   global PSU_FILTER_STR
   global APU_FILTER_STR
   puts "----> Reseting target...";
   puts "INFO: reseting PSU..."
   targets -set -nocase -filter {name =~ $PSU_FILTER_STR};
   rst -system;
   puts "INFO: reseting APU..."
   targets -set -nocase -filter {name =~ $APU_FILTER_STR};
   rst -system;
   puts "<---- Done. \n";
}
#--------------------------------------------------------------------------------#

# Initialise the Zynq MPSoC device
# @param[in/out] void
# @return void
proc target_init { } {
   global PSU_FILTER_STR
   puts "---> Initialise the Zynq MPSoC device..."
   targets -set -nocase -filter {name =~ $PSU_FILTER_STR}
   mwr 0XFFD80118 0x00800000
   mwr 0XFFD80120 0x00800000
   mwr 0xffff0000 0x14000000
   mwr 0xffca0038 0x1FF
   mwr 0xFD1A0104 0x380E
   mask_write 0xFD1A0104 0x501 0x0 
   mask_write 0xFD1A0104 0x902 0x0
   mask_write 0xFD1A0104 0x1104 0x0
   mask_write 0xFD1A0104 0x2108 0x0
   puts "<--- Done. \n"
}
#--------------------------------------------------------------------------------#

# Load and run the PMU Firmware
# @param[in/out] void
# @return void
proc target_run_pmufw { } {
   global PMU_FILTER_STR
   global PMUFW_PATH
   puts "---> Load and run PMU Firmware..."
   targets -set -nocase -filter {name =~ $PMU_FILTER_STR};
   dow $PMUFW_PATH
   con
   puts "<--- Done. \n"
}
#--------------------------------------------------------------------------------#

# Load and run the FSBL
# @param[in/out] void
# @return void
proc target_run_fsbl { } {
   global FSBL_FILE_PATH
   global A53_0_FILTER_STR
   puts "---> Load and run FSBL..."
   targets -set -nocase -filter {name =~ $A53_0_FILTER_STR};
   dow $FSBL_FILE_PATH
   con
   puts "<--- Done. \n"
}
#--------------------------------------------------------------------------------#

# Load the BIT file image to the FPGA (PL part)
# @param[in/out] void
# @return void
proc target_load_fpga { } {
   global FPGA_FILTER_STR
   global FPGA_BIT_FILE_PATH
   global A53_0_FILTER_STR
   puts "---> Transfering the FPGA bitstream..."
   targets -set -nocase -filter {name =~ $FPGA_FILTER_STR};
   fpga -file $FPGA_BIT_FILE_PATH
   targets -set -nocase -filter {name =~ $A53_0_FILTER_STR};
   puts "     INFO: PS/PL isolation removal..."
   psu_ps_pl_isolation_removal
   puts "     INFO: PS/PL reset config..."
   psu_ps_pl_reset_config
   puts "     INFO: PL is online."
   puts "<--- Done."
}
#--------------------------------------------------------------------------------#

# Load and run the ATF
# @param[in/out] void
# @return void
proc target_run_atf { } {
   global A53_0_FILTER_STR
   global ATF_FILE_PATH
   puts "----> Loading ARM Trusted Firmware..."
   targets -set -nocase -filter {name =~ $A53_0_FILTER_STR}
   dow $ATF_FILE_PATH
   con
   puts "INFO: ARM Trusted Firmware loaded and executed."
   puts "<---- Done. \n"
}
#--------------------------------------------------------------------------------#

# Start the APU core.
# @param[in] core_idx number of the APU core
# @return void
proc start_core {core_idx} {
   set core_name [format %s%d "*A5*" $core_idx];
   targets -set -nocase -filter {name =~ $core_name};
   puts [format %s%d%s "INFO: Starting the APU core Cortex-A53 #" $core_idx "..."];
   #after 250;
   if {[catch con res]} {
      puts [format %s%s "WARNING: con -> " $res]
   }
}
#--------------------------------------------------------------------------------#

# Load the QNX ELF image
# @param[in/out] void
# @return void
proc target_run_qnx_image {} {
  global APU_FILTER_STR
  global A53_0_FILTER_STR
  global QNX_IMAGE_FILE_PATH
  global QNX_IMAGE_LOAD_ADDR
  global QNX_IMAGE_ENTRY_POINT
    
  puts [format %s "----> Loading the QNX image..."]
  targets -set -nocase -filter {name =~ $APU_FILTER_STR}
  stop
  dow -data $QNX_IMAGE_FILE_PATH $QNX_IMAGE_LOAD_ADDR
  targets -set -nocase -filter {name =~ $A53_0_FILTER_STR}
  rwr pc $QNX_IMAGE_ENTRY_POINT
  for {set i 0} {$i < 4} {incr i} {
     start_core $i;
  }
  puts "<---- Done.\n"
}
#--------------------------------------------------------------------------------#

# Disconnect from the target
# @param[in/out] void
# @return void
proc target_disconnect { } {
   puts "----> Disconnecting from the target..."
   disconnect
   puts "<---- Done. \n"
}
#--------------------------------------------------------------------------------#

# Load the Toyota software stack over JTAG
# @param[in/out] void
# @return void
proc deploy_jtag { } {
   puts "\n----> Loading of Toyota software stack over JTAG..."
   target_connect
   set_max_jtag_freq
   check_boot_mode
   target_reset
   target_init
   target_run_pmufw
   target_run_fsbl
   target_load_fpga
   target_run_atf
   target_run_qnx_image
   target_disconnect
   puts "<---- Loading of Toyota software stack over JTAG is successfully finished.\n"
}
#--------------------------------------------------------------------------------#

# The main function.
# @param[in] arg_c -> count of arguments
# @param[in] arg_v -> array of arguments
# @return void
proc main { arg_c arg_v } {
   puts "----> Starting deployment of the SW stack..."
   check_mode_and_deploy
   puts "<---- DONE. \n"
   
   exit 0
}

##################################################################################
###                     Calling of the main() function                         ###
##################################################################################

main $argc $argv;

#-------------------------------- END OF SCRIPT ---------------------------------#