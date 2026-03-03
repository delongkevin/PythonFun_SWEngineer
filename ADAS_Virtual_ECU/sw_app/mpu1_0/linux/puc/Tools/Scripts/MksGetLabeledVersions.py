'''
Created on 11.03.2015

@author: MEE_MiSch
'''
import CommonScript
import os
import tempfile
from ScriptLib.Mks import execCmd
from ScriptLib.Mks import rlog
from datetime import datetime, date

class MksGetLabeledVersions:

    def __init__(self):
        self.cpid = 1
        self.notFoundArchs = {}
        self.foundArchs = []
        self.searchedDirs = set()

        self.fileLocs = {} # filename -> directories 
        self.localSandbox = {} # URL -> local sandbox

    
    def chkError(self, line):
        if 'change package id not found' in line:
            self.cpid = -1
    
    
    def isBigger(self, newRev, oldRev):
        n = newRev.split('.')
        o = oldRev.split('.')
        for i in range(0,min(len(n), len(o))):
            n1 = int(n[i])
            o1 = int(o[i])
            if n1 != o1:
                if n1 < o1:
                    return False
                else:
                    return True
        return len(n) > len(o)


    def storeFileLocs(self, startDir):
        ''' Search for _all_ files recursively in a given start directory and store all their locations '''
        for root, _, files in os.walk(startDir):
            for f in files:
                loc = self.fileLocs.get(f)
                if not loc:
                    self.fileLocs[f] = [root]
                else:
                    loc.append(root)

    def getRefPath(self, projectDir):
            cmd = 'si sandboxinfo --noassociatedIssues --noattributes --noshowCheckpointDescription'
            for line in execCmd(cmd, cwd=projectDir):
                if line.startswith('Repository Location'):
                    line = line[line.index('/'):]
                    if line.endswith('/project.pj'):
                        line = line[:-11]
                    return line
        
        
   
    def getLocalPath(self, fileUrl):
        ''' Searches for the file location in the local sandbox.
            @param fileUrl: URL of searched file in repository
            @return: local filename in sandbox
        '''
        searchedFile = os.path.basename(fileUrl)
        repoUrl = os.path.dirname(fileUrl)
            
        fileLoc = self.localSandbox.get(repoUrl)
        if not fileLoc:
            srcDirs = self.fileLocs.get(searchedFile)
            if srcDirs:
                for srcDir in srcDirs:
                    # search project.pj files for referenced repo location
                    refPath = self.getRefPath(srcDir)
                    if refPath and refPath == repoUrl:
                        self.localSandbox[repoUrl] = srcDir
                        fileLoc = srcDir
                        break

        if fileLoc:
            return os.path.join(fileLoc, searchedFile)

        return None


    
    def getLabeledRevisions(self, startDir, label, taskid):
        self.fileLocs = {}
        self.localSandbox = {}

        self.storeFileLocs(startDir)
            
        if None != label:
            # log all files with the given label: member (path) + revision number
            l = list(rlog(startDir, ['revision', 'membername', 'labels', 'date'], params='--rfilter=labellike:%s' % (label)))
            return l
        else:
            #lnames = list(rlog(startDir, ['archivename', 'workingfile'], params='--revision=:head')) # referenceproject <-> archivename?
            revisions = []
            filelocations = []
            l = []
            
            for tid in taskid.split(','):
                tid = tid.strip()
                cpid = 1
                while True:
                    cpidtxt = tid
                    if ':' not in tid:
                        cpidtxt = '%s:%d' % (tid, cpid)                    
                    lines = list(execCmd('viewcp %s' % (cpidtxt), startDir, chkError=self.chkError))
                    if cpid == -1:
                        break
                    if len(lines) == 0:
                        break
                    for line in lines:
                        if line.startswith('Update Archive') or line.startswith('Add'): # TODO 'drop' or 'remove': delete file(s)
                            items = line.split('\t')
                            if len(items) >= 4:
                                fileUrl = items[4].replace('project.pj', items[2])
                                fileloc = self.getLocalPath(fileUrl)
                                if fileloc == None:
                                    rev = items[3]
                                    cmpRev = self.notFoundArchs.get(fileUrl)
                                    if not cmpRev or self.isBigger(rev, cmpRev):
                                        self.notFoundArchs[fileUrl] = rev
                                else:
                                    if fileloc not in filelocations:
                                        filelocations.append(fileloc)
                                        revisions.append(items[3])
                                        self.foundArchs.append(fileUrl)
                                    else:
                                        idx = filelocations.index(fileloc)
                                        newRev = items[3]
                                        if self.isBigger(newRev, revisions[idx]):
                                            revisions[idx] = newRev
                    if ':' in tid:
                        break
                    cpid += 1
                    
            for f,rev in zip(filelocations, revisions):
                l.append((rev, f, '', ''))
            return l
    
    def getLatest(self, revisions):
        revs = {}
        dates = {}
    
        for revision,membername,_,date in revisions:
            if date != '':
                dt = datetime.strptime(date, '%b %d, %Y %I:%M:%S %p')
                date = int(dt.strftime('%Y%m%d%H%M%S'))
            else:
                date = 0
            # use path + revision number to resync the files        
            if membername in dates:
                if dates[membername] < date:
                    dates[membername] = date
                    revs[membername] = revision
            else:
                dates[membername] = date
                revs[membername] = revision
    
        for revision,membername,label,date in revisions:
            if revision == revs[membername]:
                yield revision,membername,label,date
    
    
    def updateLabeledRevisions(self, startDir, label, taskid):
        for revision,localMember,_,_ in self.getLatest(self.getLabeledRevisions(startDir, label, taskid)):
            if not os.path.exists(localMember):
                # TODO checkout from another branch?
                #cmd = 'si resync --noconfirm --batch --nomerge --nooverwriteChanged --nooverwriteDeferred --nooverwriteUnchanged'
                #for line in execCmd(cmd, cwd=startDir):
                #    print line
                pass
            cmd = 'si co --nolock -Y --batch --mergeType=automatic --onMergeConflict=launchtool --revision %s %s' % (revision, localMember)
            print('co %s %s' % (localMember, revision))
            for line in execCmd(cmd, cwd=startDir):
                print line
    
    def showLabeledRevisions(self, startDir, label, taskid, showLabel):
        # log all files with the given label: member (path) + revision number
        for revision,membername,label,date in self.getLabeledRevisions(startDir, label, taskid):
            if date != '':
                if showLabel:
                    print("%s\t%s\t%s - %s" % (membername, revision, label, date))
                else:
                    print("%s\t%s - %s" % (membername, revision, date))
            else:
                if showLabel:
                    print("%s\t%s\t%s" % (membername, revision, label))
                else:
                    print("%s\t%s" % (membername, revision))
                
    
    def mergeLabeledRevisions(self, startDir, label, taskid):
        fd, tmpfile = tempfile.mkstemp(suffix='.bat')
        
        for labeledrev,membername,labels,_ in self.getLatest(self.getLabeledRevisions(startDir, label, taskid)):
            lastrev = labeledrev[:labeledrev.rfind('.')] + '.99'
            rev = (list(rlog(startDir, ['revision'], params='--range=%s-%s' % (labeledrev, lastrev))))[0]
            mainrev = labeledrev[:labeledrev.find('.', 2)]
            print('found: %s %s - %s' % (membername, rev, labels))
            if rev != mainrev:
                f = os.path.join(startDir, membername)
                #os.write(fd, 'si resync --yes --revision %s %s\n' % (rev, f))
                os.write(fd, 'attrib -R %s\n' % f)
                cmd = 'si merge --batch --mergeType=automatic --onMergeConflict=launchtool -r %s -r %s %s\n' % (mainrev, rev, f)
                os.write(fd, cmd)
            else:
                print("rev = mainrev...")
        
        os.write(fd, "exit\n")
        os.close(fd)
        os.system("cmd /c start /wait %s" % tmpfile)
        
        
    def labelRevisions(self, startDir, taskid, newLabel):
        for revision,membername,_,_ in self.getLatest(self.getLabeledRevisions(startDir, None, taskid)):
            cmd = ['si', 'addlabel', '--label=' + newLabel, '--revision', revision, membername]
            print(' '.join(cmd))
            for line in execCmd(cmd, cwd=startDir):
                print line
    
    
    def main(self, args):
        label = args.label
        taskid = args.taskId
        if None == label and None == taskid:
            print("Please enter Task or CP ids (separated by comma)")
            print("    task = number, cp = number:number")
            print("    Example: 123456,789123:1")
            taskid = raw_input("Enter IDs: ")
            
        for prjdir in args.dir.split(','):
            startDir = os.path.abspath(prjdir)
            print("Synchronizing in %s" % (startDir))
            if args.addLabel:
                self.updateLabeledRevisions(startDir, None, taskid)
                self.labelRevisions(startDir, taskid, args.addLabel)
            elif args.showOnly or args.showWithLabel:
                self.showLabeledRevisions(startDir, label, taskid, args.showWithLabel)
            elif args.merge:
                self.mergeLabeledRevisions(startDir, label, taskid)
            else:
                self.updateLabeledRevisions(startDir, label, taskid)
                
        if len(self.notFoundArchs) > 0:
            print("########################")
            print("%d files were not found" % (len(self.notFoundArchs))) 
            print("- reasons may be that new directories were added -> then perform a resync")
            print("- or: files were not on the search path of local directories")
            print("- or: files were added to another branch -> then switch to that branch")
            print("Please update manually: ")
            for arch,rev in self.notFoundArchs.iteritems():
                if arch not in self.foundArchs:                
                    print("  %s:%s" % (arch,rev))
        else:
            print("Done.\n")

    
if __name__ == '__main__':
    parser = CommonScript.createParser('Updates files to a specific label', ["-d"])
    parser.add_argument("-l", "--label", dest="label", help="label to search", required = False)
    parser.add_argument("-t", "--taskid", dest="taskId", help="Task or change package Id(s)", required = False)
    parser.add_argument("-s", "--showOnly", dest="showOnly", help="Only print the file names and their revisions",
                        required=False, default=False, action='store_const', const=True )
    parser.add_argument("-S", "--showWithLabel", dest="showWithLabel", help="Only print the file names, revisions and their labels",
                        required=False, default=False, action='store_const', const=True )
    parser.add_argument("-m", "--merge", dest="merge", help="Merge to main branch",
                        required=False, default=False, action='store_const', const=True )
    parser.add_argument("-a", "--addLabel", dest="addLabel", required=False, default=None)
    
    mksRev = MksGetLabeledVersions()    
    CommonScript.callMainWithParser(parser, mksRev.main)
  
