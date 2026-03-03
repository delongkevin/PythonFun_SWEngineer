'''
Created on 13.03.2015

@author: MEE_MiSch
'''

import os
import getpass
import Exec
import time
import Queue
import sys
passwd = None
integrityRunning = None

def execCmd(cmd, cwd = os.getcwd(), passwd='Auto', echo=False, chkError = None):
    exitCode = None
    if isinstance(cmd, basestring):
        cmd = cmd.strip().split(' ')
    if (cmd[0] != 'si'):
        cmd = ['si'] + cmd
    if '--password' not in cmd and passwd != None:
        if (passwd == 'Auto'):
            passwd = getPasswd()
        cmd = cmd[0:2] + ['--password', passwd] + cmd[2:]
    
    class Callback():
        def __init__(self):
            self.restart = False
            self.queue = Queue.Queue()
            self.proc = None
        def run(self):
            self.lines = []
            if None != self.proc:
                self.proc.wait()
            self.proc = Exec.redirect(cmd, callbackStdout=self.appendLine, callbackStderr=self.chkRestart, cwd=cwd, echo=echo, wait=False)
        def appendLine(self, line):
            if (line.strip() != ''):
                self.queue.put(line)
        def chkRestart(self, line):
            if ('MKS124789' in line): # no license available
                self.restart = True
            elif line.strip() != '':
                if chkError:
                    chkError(line.rstrip())
                else:
                    sys.stderr.write(line.rstrip() + "\n")
            else:
                pass # ignore empty line
    
    cb = Callback()
    while True:
        cb.run()
        
        while True:
            while not cb.queue.empty():
                line = cb.queue.get()                    
                if line != '':
                    yield line
            exitCode = cb.proc.poll()
            if None != exitCode:
                break
            else:
                time.sleep(0.01)
        if cb.restart:
            print("*** no license - retry...")
            time.sleep(1) # no license -> retry
        else:
            break
        
            
        


def isServiceRunning():
    global integrityRunning
    if None == integrityRunning:
        for line in execCmd('servers', passwd=None):
            if '@' in line:
                integrityRunning = True
                break
        if None == integrityRunning:
            integrityRunning = False
    return integrityRunning


def getPasswd():
    global passwd
    if None == passwd:
        if isServiceRunning():
            passwd = 'dummyPasswd' # IntegrityClient.exe is running and connected? : no need to enter passwd (again)
        else:
            print('No open connection to Integrity detected\nYou can provide the password also with the --passwd parameter.\nPlease enter your Integrity password to proceed')
            passwd = getpass.getpass('Integrity password: ')
    return passwd


def rlog(startDir, fields, recurse=True, params='--revision=:working', divider=';'):
    isStr = isinstance(fields, basestring)    
    if not isStr:
        fields = divider.join(map (lambda field: "{" + field + "}", fields))
    cmd = 'rlog --format=%s\r\n --batch --noHeaderFormat --noTrailerFormat' % (fields)
    if (params):
        cmd += ' ' + params
    if recurse:
        cmd += ' -R'
    for line in execCmd(cmd, cwd = startDir):
        l = line.strip()
        if not isStr and divider in l:
            yield l.split(divider) # return a list of the items
        else:
            yield l

def currentRevisions(startDir):
    yield ["member name", "working revision", "member revision"]
    for items in rlog(startDir, ['membername', 'workingrev', 'memberrev']):
        if ((len(items) == 3) and (items[1] != items[2])): # different working and member revisions
            yield items

def updateRevisions(startDir, revisionItems, changePackageId):
    for (f,working,_) in revisionItems:
        for line in execCmd('updaterevision -r %s -N --changePackageId=%s %s' % (working, changePackageId, f)):
            print line
            

def diff(startDir):
    currentFile = None
    changedFiles = []
    
    diff = ''
    
    for line in execCmd('diff -R --batch --ignoreBlanks --filter=changed:working', cwd = startDir):
        diff += line
        line = line.rstrip()
        search = 'and working file '
        i = line.rfind(search)
        if i != -1:
            i += len(search)
            tstFile = line[i:]
            if os.path.exists(tstFile):
                currentFile = tstFile
                if currentFile.startswith('c:\\'):
                    currentFile = 'C' + currentFile[1:]
            else:
                currentFile = None
        if currentFile != None and currentFile not in changedFiles:
            if (line == '---' or line.startswith('>') or line.startswith('<')):
                changedFiles.append(os.path.abspath(currentFile))
                
    return (diff, changedFiles)
    

def newSrcFiles(startDir):
    fileEndings = ['h','c','hpp','cpp','xml','xmi', 'conf', 'rbx','.cproject','.project','Makefile','mak','doc','docx','xsl','xslx']
    for i in range(len(fileEndings)):
        f = fileEndings[i]
        if not f.startswith('.'): fileEndings[i] = '*.' + f
    cmd = ('viewnonmembers -R --exclude=dir:.metadata,dir:.settings,dir:temp,dir:RemoteSystemsTempFiles --include=' +
        ','.join(fileEndings))
    for line in execCmd(cmd, cwd = startDir):
        line = line.strip()
        if line.startswith('c:\\'):
            line = 'C' + line[1:]
        if os.path.exists(line):
            yield line
        


def getTextFiles(startDir):
    for line in execCmd('rlog --format={membername},{format}\n --batch --noHeaderFormat --noTrailerFormat --revision=:working -R', cwd = startDir):
        items = line.strip().split(',')
        if (len(items) == 2 and items[1] == '1'): # all text files --> '1'
            yield os.path.join(startDir, items[0])

