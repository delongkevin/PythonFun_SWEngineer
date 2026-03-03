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
#    Created on: 28.11.2019                                                      #
#        Author: Roman Berngardt (Roman.Berngardt@magna.com)                     #
#--------------------------------------------------------------------------------#

import os
import sys
import subprocess
import CommonScript

def main(args):
    start_dir = os.path.abspath(args.startdir)
    sys.stdout.write("INFO: Remove write protection attribute on '{0}'...\r\n\n".format(start_dir))
    exec_cmd = ['attrib', '-r', start_dir+'/*.*', '/S']
    #sys.stdout.write("INFO: Calling '" + ' '.join(exec_cmd) + "'...\r\n\n")
    subprocess.call(exec_cmd, shell=True)
    return

if __name__ == '__main__':
    parser = CommonScript.createParser('remove write protection')
    parser.add_argument("--start_dir", dest="startdir", help="Directory on with the Wp has to be removed", required=True)
    CommonScript.callMainWithParser(parser, main)
