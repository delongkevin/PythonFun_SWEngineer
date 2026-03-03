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
#    Created on: 27.11.2019                                                      #
#        Author: Roman Berngardt (Roman.Berngardt@magna.com)                     #
#--------------------------------------------------------------------------------#

import os
import sys
import subprocess
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
import CommonScript

_BIF_FILE_NAME_ = "boot.bif"

_pmu_img_file      = "<UNKNOWN>"
_fsbl_img_file     = "<UNKNOWN>"
_atf_img_file      = "<UNKNOWN>"
_qnx_img_file      = "<UNKNOWN>"
_fpga_bit_file     = "<UNKNOWN>"
_boot_img_bin_file = "<UNKNOWN>"

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
    global _fpga_bit_file
    global _boot_img_bin_file
    
    # chek PMU image file
    _pmu_img_file = check_file(args.pmuimg)
    # chek FSBL image file
    _fsbl_img_file = check_file(args.fsblimg)
    # chek ATF image file
    _atf_img_file = check_file(args.atfimg)
    # chek QNX image file
    _qnx_img_file = check_file(args.qnximg)
    # chek FPGA bit file
    _fpga_bit_file = check_file(args.fpgafile)

    #set the boot image bin file name
    _boot_img_bin_file = os.path.abspath(args.bootimage)
    return

def create_bif_file():
    bif_file_body = "// ARCH = zynqmp; SPLIT = false; FORMAT = BIN\n" \
                    "The_ROM_Image:\n" \
                    "{\n" \
					"\t[fsbl_config]a53_x64\n" \
                    "\t[bootloader]{FSBL_IMG_PLACE_HOLDER}\n" \
                    "\t[destination_device = pl]{PL_IMG_PLACE_HOLDER}\n" \
                    "\t[destination_cpu = pmu]{PMU_IMG_PLACE_HOLDER}\n" \
                    "\t[destination_cpu = a53-0, exception_level=el-3, trustzone]{ATF_IMG_PLACE_HOLDER}\n" \
                    "\t[destination_cpu = a53-0, exception_level=el-2]{QNX_IMG_PLACE_HOLDER}\n" \
                    "}\n";

    bif_file_body = bif_file_body.replace("{FSBL_IMG_PLACE_HOLDER}", _fsbl_img_file)
    bif_file_body = bif_file_body.replace("{PL_IMG_PLACE_HOLDER}",   _fpga_bit_file)
    bif_file_body = bif_file_body.replace("{PMU_IMG_PLACE_HOLDER}",  _pmu_img_file)
    bif_file_body = bif_file_body.replace("{ATF_IMG_PLACE_HOLDER}",  _atf_img_file)
    bif_file_body = bif_file_body.replace("{QNX_IMG_PLACE_HOLDER}",  _qnx_img_file)
    
    bif_file = open(_BIF_FILE_NAME_, "w+")
    bif_file.write(bif_file_body)
    bif_file.close()
    return

def delete_bif_file():
    if os.path.exists(_BIF_FILE_NAME_):
        os.remove(_BIF_FILE_NAME_)
    return

def generate_bin_file():
    exec_cmd = ['bootgen', '-arch', 'zynqmp']
    exec_cmd.extend(['-image', _BIF_FILE_NAME_])
    exec_cmd.extend(['-w', 'on'])
    exec_cmd.extend(['-o', _boot_img_bin_file])
    subprocess.call(exec_cmd, shell=True)
    return

def main(args):
    try:
        sdk_dir = CommonScript.find_Xilinx_SDK_dir()
        CommonScript.check_env(sdk_dir)
        check_files(args)
        create_bif_file()
        generate_bin_file()
        delete_bif_file()
    except BaseException as ex:
        sys.stderr.write("\r\n{0} \r\n\n".format(ex.message))
    return

if __name__ == '__main__':
    parser = CommonScript.createParser('generate boot image for the target HW') 
    parser.add_argument("--fsbl_image", dest="fsblimg",  help="Path to the FSBL ELF file", required=True)
    parser.add_argument("--fpga_file",  dest="fpgafile", help="Path to the FPGA bit file", required=True)
    parser.add_argument("--pmu_image",  dest="pmuimg",   help="Path to the PMU FW ELF file", required=True)	
    parser.add_argument("--atf_image",  dest="atfimg",   help="Path to the ATF ELF file", required=True)
    parser.add_argument("--qnx_image",  dest="qnximg",   help="Path to the QNX ELF file", required=True)

    parser.add_argument("--boot_image",  dest="bootimage", help="Path to the boot image BIN file", required=True)
    CommonScript.callMainWithParser(parser, main)
#------------------------------------- EOF --------------------------------------#
