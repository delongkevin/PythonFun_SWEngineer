import pandas as pd
import os
import sys

CAdapter=None
HAdaper=None

SenderList=[]
RecvList=[]

def IPCAdapterCodeGen_Setup(CurrentPath):
    COutputPath = os.path.join(CurrentPath, ".\\..\\gen\\", "SigMgr_IpcBridge.c")
    HOutputPath = os.path.join(CurrentPath, ".\\..\\gen\\", "SigMgr_IpcBridge.h")
    CAdapter=open(COutputPath,"w")
    HAdaper=open(HOutputPath,"w")

    IPCAdapterCodeGen_GenerateIncludeGaurds(HAdaper)
    IPCAdapterCodeGen_AddCFileHeaders(CAdapter)

    return (CAdapter,HAdaper)

def IPCAdapterCodeGen_Close(handle):

    (cf,hf)=handle

    IPCAdapterCodeGen_CloseIncludeGaurds(hf)

    cf.close();
    hf.close();

def IPCAdapterCodeGen_Gen(handle,core):

    (cf,hf)=handle

    hf.write("\n\n#ifdef BUILD_"+core +"\n\n")
    cf.write("\n\n#ifdef BUILD_" + core+"\n\n")

    IPCAdapterCodeGen_GenerateCallBacks(cf)
    IPCAdapterCodeGen_GenerateInit(cf,hf)


    hf.write("\n\n#endif /*" + core + "*/\n\n")
    cf.write("\n\n#endif /*" + core + "*/\n\n")



def IPCAdapterCodeGen_GenerateIncludeGaurds(hf):
    hf.write("#ifndef SigMgr_IpcBridge_H_INCGUARD \n")
    hf.write("#define SigMgr_IpcBridge_H_INCGUARD \n")

def IPCAdapterCodeGen_CloseIncludeGaurds(hf):
    hf.write("#endif \n")


def IPCAdapterCodeGen_AddCFileHeaders(cf):
    cf.write("#include \"SignalMgr.cfg\"\n")
    cf.write("#include \"SignalDef.h\"\n")
    cf.write("#include \"SigMgr_IpcBridge.h\"\n")
    cf.write("#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED\n");
    cf.write("#include \"ipc_manager.h\"\n")
    cf.write("#endif\n");
    cf.write("\n\n");

def IPCAdapterCodeGen_Clear():
    SenderList.clear()
    RecvList.clear()

def IPCAdapterCodeGen_AddSender(DataType,DataObject,MsgId):
    SenderList.append((DataType,DataObject,MsgId))

def IPCAdapterCodeGen_AddRecv(DataType,DataObject):
    RecvList.append((DataType,DataObject))

def IPCAdapterCodeGen_GenerateCallBacks(cf):
    for s in SenderList:
        (s_dt, s_do, s_mid) = s
        cf.write("static void SigMgr_IpcBridge_" + s_do + "_callback(const "+s_dt+ "* const dataptr)\n");
        cf.write("{\n");
        cf.write("\t#ifndef SUPPRESS_IPCCALLS_IPCNOTINTEGRATED\n");        
        cf.write("\tuint32_t  err=D_IPC_NO_ERROR;\n");
        cf.write("\tIPCMessage_Params_t params={(uint16_t) "+str(((s_mid)))+",(uint16_t)sizeof("+s_dt+"),(uint8_t*)dataptr,(uint16_t)0};\n\n");
        cf.write("\terr=IPC_F_WrapperSend_u32(&params);\n");
        cf.write("\tif(err != D_IPC_NO_ERROR) { /* Do Nothing */} \n");
        cf.write("\t#endif\n");
        cf.write("}\n\n");

def IPCAdapterCodeGen_GenerateInit(cf,hf):
    #init
    hf.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
    hf.write("bool_t SigMgr_IpcBridge_Init(void);\n");
    hf.write("#ifdef __cplusplus\n}\n#endif\n");
    cf.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
    cf.write("bool_t SigMgr_IpcBridge_Init(void)\n");
    cf.write("{\n");
    cf.write("\tbool_t bRet=TRUE;\n\n");

    if(SenderList != None):
        for s in SenderList:
            (s_dt,s_do,s_mid)=s
            cf.write("\tbRet &= SigMgr_" + s_do + "_RegisterCallback(SigMgr_IpcBridge_"+s_do+"_callback);\n");

    cf.write("\n\treturn bRet;\n");
    cf.write("}\n\n");
    cf.write("#ifdef __cplusplus\n}\n#endif\n");
