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
#    Created on: 22.11.2019                                                      #
#        Author: Roman Berngardt (Roman.Berngardt@magna.com)                     #
#--------------------------------------------------------------------------------#

import os
import sys
from subprocess import Popen
import CommonScript

def check_dirs(wrk_spce_dir, qnxbase_path):
    if not os.path.isdir(wrk_spce_dir):
        raise BaseException("ERROR: '%s' is not a directory!" % wrk_spce_dir)
    if not os.path.isdir(qnxbase_path):
        raise BaseException("ERROR: '%s' is not a directory!" % qnxbase_path)
    return

def checkt_exec_file(exec_file):
    if not os.path.isfile(exec_file):
        raise BaseException("ERROR: '%s' is not a file!" % exec_file)
    if not os.path.exists(exec_file):
        raise BaseException("ERROR: The QDE executable '%s' is not found!" % exec_file)
    return

def main(args):
    try:
        wrkspce_path = os.path.abspath(args.dir)
        qnxbase_path = os.path.abspath(args.qnxbase)
        check_dirs(wrkspce_path, qnxbase_path)
        exec_file = os.path.join(qnxbase_path, 'QNX Momentics\\qde.exe')
        checkt_exec_file(exec_file)
        exec_cmd = [exec_file, '-data', wrkspce_path]
        sys.stdout.write("\r\nStarting QNX Momentics IDE...\r\n")
        Popen(exec_cmd)
    except BaseException as ex:
        sys.stderr.write("\r\n{0} \r\n\n".format(ex.message))
    return

if '__main__' == __name__:
    parser = CommonScript.createParser('Runs the QNX Momentics IDE', ["-d"])
    parser.add_argument("-q", "--qnxbase", dest="qnxbase", help="QNX base directory", default='C:/QNX', required=True)
    CommonScript.callMainWithParser(parser, main)
