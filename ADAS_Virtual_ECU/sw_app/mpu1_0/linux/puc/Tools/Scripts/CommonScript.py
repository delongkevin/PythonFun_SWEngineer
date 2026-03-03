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
#      Author: Roman Berngardt (Roman.Berngardt@magna.com)                       #
#--------------------------------------------------------------------------------#

__XILINX_SDK_BASE_DIR__ = 'C:\\Xilinx';

import os
import sys
from zipfile import ZipFile
from argparse import ArgumentParser
from argparse import RawDescriptionHelpFormatter

def check_python_version():
    if sys.version_info >= (3, 0):
        sys.stdout.write("\r\nFAILURE: requires Python 2.x, not Python 3.x! \r\n\n")
        sys.exit(-1)
    return

def check_env(xsdk_path):
    my_env = os.environ
    if xsdk_path not in my_env['PATH']:
        my_env['PATH'] = xsdk_path + ";" + my_env['PATH']
        sys.stdout.write("INFO: '{0}' added to the PATH environment variable. \r\n".format(xsdk_path))
    else:
        sys.stdout.write("INFO: '{0}' is found in the PATH environment variable. \r\n".format(xsdk_path))
    return

def find_Xilinx_SDK_dir(xilMainDir = __XILINX_SDK_BASE_DIR__):
    sdk_dir = os.path.join(xilMainDir, "SDK")
    sdk_paths = []
    if os.path.exists(sdk_dir):
        for path in os.listdir(sdk_dir):
            if path.startswith("20"):
                path = os.path.join(sdk_dir, path, "bin")
                if os.path.isdir(path):
                    sdk_paths.append(path)
        if len(sdk_paths) == 0:
            raise BaseException("ERROR: No supported SDK directory found in '%s'" % sdk_dir)
        else:
            # use the highest/newest entry if possible
            sdk_paths = sorted(sdk_paths, reverse=True)
            return sdk_paths[0]
    else:
        raise BaseException("ERROR: Xilinx SDK base directory is not found!")
    return

def extractFromZipFile(fileToExtract=None, zipFileName=None):
    if not os.path.exists(zipFileName):
        raise BaseException("ERROR: File '{0}' is not found!".format(zipFileName))
    print("Extract %s from %s..." % (fileToExtract, zipFileName))
    sys.stdout.write("INFO: Extracting '{0}'... \r\n".format(fileToExtract))
    zFile = ZipFile(zipFileName)
    hd, fileName = os.path.split(fileToExtract)
    return zFile.extract(fileName, os.path.dirname(zipFileName))
    
def createParser(shortDescription, withArgs=[]):
    check_python_version()
    programDescription = '%s' % (shortDescription)
    parser = ArgumentParser(description=programDescription, formatter_class=RawDescriptionHelpFormatter)

    args=[]
    args.extend(withArgs)
    if "-d" in args:
        parser.add_argument("-d", "--dir", dest="dir", help="directory to start from")
        args.remove("-d")
    return parser

def callMainWithParser(parser, mainFun):
    args = parser.parse_args()
    mainFun(args)
    return
