'''
Created on 13.03.2015

@author: MEE_MiSch
'''
import os
import subprocess
import sys
from threading import Thread
import traceback


def readLines(cmd, cwd=os.getcwd(), shell=False):
    if isinstance(cmd, basestring):
        cmd = cmd.strip().split()
    proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, cwd=cwd, shell=shell)
    for line in iter(proc.stdout.readline,''):
        yield line.rstrip()


def runParallel(fun, parItems, numThreads = 8):
    '''
    Helper method that bundles a function call in several threads.
    
    @param fun: function to call
    @param parItems: list of tuples, each tuple containing the items of the function call
    @param numThreads: number of threads to run in parallel  
    '''            
    n = (len(parItems)+numThreads-1) / numThreads
    chunks = [parItems[i:i+n] for i in xrange(0, len(parItems), n)]
    exceptions = []
    
    def doAction(i, ex):
        try:
            for item in chunks[i]:
                if not isinstance(item, tuple):
                    # the call below uses unpacking of tuples (default)
                    # when no tuple is given, the (one) item is packed as a tuple
                    item  = (item,)
                if isinstance(fun, list):
                    fun[i](*item)
                else:
                    fun(*item)
        except BaseException as ex:
            exceptions.append(ex)
            raise(ex)
        
    threads = []
    for i in range(len(chunks)):
        t = Thread(target = doAction, args = [i, exceptions])
        threads.append(t)
        t.start()
        
    for t in threads:
        t.join()
    
    if len(exceptions) > 0:
        raise exceptions[0]
        
        
class CollectCalls:
    ''' Helper class to collect calls.
    
    Example:
    
        from ScriptLib.Exec import CollectCalls
        col = CollectCalls()
        col.add(longRunning1, (par1, par2))
        col.add(longRunning2, par1)
        col.add(longRunning3, (par1, par2, par3))
        col.add(longRunning4, (par1))
        col.call()
    '''            
    def __init__(self):
        self.funs = []
        self.params = []
    
    def add(self, funCall, params):
        self.funs.append(funCall)
        self.params.append(params)
    
    def call(self, numThreads = 8):
        if len(self.funs) > 0:
            if len(self.funs) == 1 or numThreads == 1:
                for idx in range(0, len(self.funs)):
                    self.funs[idx](*self.params[idx])
            else:
                runParallel(self.funs, self.params, numThreads)
        


class RedirectOutput:

    def __init__(self, proc, stream, callback, echo):
        '''
        stream: the stream to read from.
                Usually a process' stdout or stderr.
        '''

        self.stream = stream
        self.callback = callback
        self.proc = proc

        def __callCallback(proc, stream, queue):
            '''
            Collect lines from 'stream' and put them in 'queue'.
            '''

            try:
                while proc.poll() is None:
                    line = stream.readline()
                    if None != line:
                        if None != echo:
                            echo.write(line)
                        if None != self:
                            self.callback(line.rstrip())
                    else:
                        break
            except BaseException:
                pass

        self._t = Thread(target = __callCallback,
                args = (self.proc, self.stream, self.callback))
        self._t.daemon = True
        self._t.start() #start collecting lines from the stream

def redirectProcAsync(proc, callbackStdout=None, callbackStderr=None, echo=True):
    RedirectOutput(proc, proc.stdout, callbackStdout, sys.stdout if echo else None)
    RedirectOutput(proc, proc.stderr, callbackStderr, sys.stderr if echo else None)
    
    return proc


def redirectProc(proc, callbackStdout=None, callbackStderr=None, echo=True):
    return redirectProcAsync(proc, callbackStdout, callbackStderr, echo).wait()

def redirect(cmd, callbackStdout=None, callbackStderr=None, cwd=os.getcwd(), echo=True, shell=False, wait=True):
    if isinstance(cmd, basestring):
        cmd = cmd.strip().split()
        
    if (wait):
        return redirectProc(subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, cwd=cwd, shell=shell),
                        callbackStdout, callbackStderr, echo)
    else:
        return redirectProcAsync(subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, cwd=cwd, shell=shell),
                        callbackStdout, callbackStderr, echo)
    


def asyncCall(asyncFun, threadName="AsyncFunCall", errorOut=sys.stderr, stackTraceLimit=1):
    '''
    Starts a thread and executes the given function.
    If the function (from a previous call) is still running, false is returned.
    Otherwise the function execution in the thread is started and the function returns immediately with true.
    The thread is stored as internal attribute to the function. It is named _fun_Thread_ to prevent naming clashes.
    
    @param asyncFun the fun to be executed asynchronously
    @param threadName name of the thread to start. Default: "AsyncFunCall".
    @param errorOut file to report exceptions to. Default: stderr.
    @param stackTraceLimit number of stack trace elements to print
    '''
    if None == getattr(asyncFun, '_fun_Thread_', None): # either attribute was not set or was set to None
        # create the thread
        def funCall():
            try:
                asyncFun()
            except:
                # we are in a thread, so there is no 'main' function to report the error to
                traceback.print_exc(limit=stackTraceLimit, file=errorOut)
            finally:
                # reset the attribute with None when the execution of fun has finished
                asyncFun._fun_Thread_ = None
        asyncFun._fun_Thread_ = Thread(target=funCall, name=threadName)
        asyncFun._fun_Thread_.start()
        return True
    else:
        return False # thread with fun already started and not finished yet
