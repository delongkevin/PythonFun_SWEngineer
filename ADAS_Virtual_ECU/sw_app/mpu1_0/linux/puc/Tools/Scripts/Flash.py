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
#    Created on: 21.11.2019                                                      #
#        Author: Roman Berngardt (Roman.Berngardt@magna.com)                     #
#--------------------------------------------------------------------------------#

__XILINX_FLASH_TOOL__ = 'program_flash'

import os
import sys
import subprocess
import CommonScript

def check_files(img_path, fsbl_path):
    if not os.path.exists(img_path):
        raise BaseException("ERROR: '%s' does not exists!" % img_path)
    if not os.path.exists(fsbl_path):
        raise BaseException("ERROR: '%s' does not exists!" % fsbl_path)
    if not os.path.isfile(img_path):
        raise BaseException("ERROR: '%s' is not a file!" % img_path)
    if not os.path.isfile(fsbl_path):
        raise BaseException("ERROR: '%s' is not a file!" % fsbl_path)
    return

def perform_flash(img_path, fsbl_path):
    try:
        check_files(img_path, fsbl_path)
        sdk_dir = CommonScript.find_Xilinx_SDK_dir()
        CommonScript.check_env(sdk_dir)
        flash_tool = __XILINX_FLASH_TOOL__
        exec_cmd = [flash_tool, '-f', img_path]
        exec_cmd.extend(['-fsbl', fsbl_path])
        exec_cmd.extend(['-flash_type', 'qspi_single'])
        exec_cmd.extend(['-cable', 'type xilinx_tcf url TCP:127.0.0.1:3121'])
        sys.stdout.write("INFO: Calling '" + ' '.join(exec_cmd) + "'...\r\n\n")
        subprocess.call(exec_cmd, shell=True)
    except BaseException as ex:
        sys.stderr.write("\r\n{0} \r\n\n".format(ex.message))
    return

def main(args):
    boot_img_path = os.path.abspath(args.image)
    fsbl_elf_path = os.path.abspath(args.fsbl)
    perform_flash(boot_img_path, fsbl_elf_path)
    return

if __name__ == '__main__':
    parser = CommonScript.createParser('flash current BIN image file')
    parser.add_argument("-i", "--image", dest="image", help="Binary image file to flash (*.bin)", default='boot.bin', required=True)
    parser.add_argument("-f", "--fsbl", dest="fsbl", help="First stage boot loader ELF file", default='zynqmp_fsbl.elf', required=True)
    CommonScript.callMainWithParser(parser, main)
