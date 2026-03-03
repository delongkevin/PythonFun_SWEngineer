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

import os
import sys
import subprocess
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
import CommonScript

_TCL_SCRIPT_PATH_       = "./Deployment/Deploy_SW.tcl"
_PSU_INIT_TCL_FILENAME_ = "psu_init.tcl"

_pmu_img_file  = "<UNKNOWN>"
_fsbl_img_file = "<UNKNOWN>"
_atf_img_file  = "<UNKNOWN>"
_qnx_img_file  = "<UNKNOWN>"
_hdf_img_file  = "<UNKNOWN>"
_fpga_bit_file = "<UNKNOWN>"
    
def check_mode(mode):
    if mode != "JTAG":
        raise BaseException("ERROR: Unsupported mode '{0}'".format(mode))
    return

def check_file(filename):
    full_path = os.path.abspath(filename)
    if not os.path.exists(full_path):
        raise BaseException("ERROR: The file '%s' is not found!" % full_path)
    if not os.path.isfile(full_path):
        raise BaseException("ERROR: '%s' is not a file!" % full_path)
    return full_path

def check_files(args):
    global _pmu_img_file
    global _fsbl_img_file
    global _atf_img_file
    global _qnx_img_file
    global _hdf_img_file
    global _fpga_bit_file
    
    # chek PMU image file
    _pmu_img_file = check_file(args.pmuimg)
    # chek FSBL image file
    _fsbl_img_file = check_file(args.fsblimg)
    # chek ATF image file
    _atf_img_file = check_file(args.atfimg)
    # chek QNX image file
    _qnx_img_file = check_file(args.qnximg)
    # chek HDF image file
    _hdf_img_file = check_file(args.hdffile)
    # chek FPGA bit file
    _fpga_bit_file = check_file(args.fpgafile)
    return

def extract_psu_init_tcl_file(hdf_file):
    global _PSU_INIT_TCL_FILENAME_
    try:
        CommonScript.extractFromZipFile(_PSU_INIT_TCL_FILENAME_, hdf_file)
        dir_path = os.path.dirname(os.path.realpath(hdf_file))
        dir_path = dir_path + '/' + _PSU_INIT_TCL_FILENAME_
        _PSU_INIT_TCL_FILENAME_ = os.path.abspath(dir_path)
    except KeyError as ex:
        sys.stderr.write("ERROR: {0} \r\n\n".format(ex.message))
        raise BaseException("ERROR: The file '{0}' could not be extracted from '{1}'!".format(_PSU_INIT_TCL_FILENAME_, hdf_file))
    return

def main(args):
    try:
        sdk_dir = CommonScript.find_Xilinx_SDK_dir()
        CommonScript.check_env(sdk_dir)
        check_mode(args.mode)
        check_files(args)
        extract_psu_init_tcl_file(_hdf_img_file)
        exec_cmd = ['xsct.bat', os.path.abspath(_TCL_SCRIPT_PATH_)]
        #add TCL script param with index 0
        exec_cmd.extend(["mode:"+args.mode])
        #add TCL script param with index 1
        exec_cmd.extend([_PSU_INIT_TCL_FILENAME_])
        #add TCL script param with index 2
        exec_cmd.extend([_pmu_img_file])
        #add TCL script param with index 3
        exec_cmd.extend([_fsbl_img_file])
        #add TCL script param with index 4
        exec_cmd.extend([_fpga_bit_file])
        #add TCL script param with index 5
        exec_cmd.extend([_atf_img_file])
        #add TCL script param with index 6
        exec_cmd.extend([_qnx_img_file])
        #sys.stdout.write("INFO: Calling '" + ' '.join(exec_cmd) + "'...\r\n\n")
        subprocess.call(exec_cmd, shell=True)
    except BaseException as ex:
        sys.stderr.write("\r\n{0} \r\n\n".format(ex.message))
    return

if __name__ == '__main__':
    parser = CommonScript.createParser('deploy current SW stack to the target HW over JTAG')
    parser.add_argument("--mode",       dest="mode",     help="SW deployment mode", default='JTAG', required=True)
    parser.add_argument("--pmu_image",  dest="pmuimg",   help="Path to the PMU FW ELF file", required=True)
    parser.add_argument("--fsbl_image", dest="fsblimg",  help="Path to the FSBL ELF file", required=True)
    parser.add_argument("--atf_image",  dest="atfimg",   help="Path to the ATF ELF file", required=True)
    parser.add_argument("--qnx_image",  dest="qnximg",   help="Path to the QNX ELF file", required=True)
    parser.add_argument("--hdf_file",   dest="hdffile",  help="Path to the HDF file", required=True)
    parser.add_argument("--fpga_file",  dest="fpgafile", help="Path to the FPGA bit file", required=True)
    
    CommonScript.callMainWithParser(parser, main)
#------------------------------------- EOF --------------------------------------#
