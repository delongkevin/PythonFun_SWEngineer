import pandas as pd
import os
import sys
import SignalMgr_IPCAdapater
import shutil , pickle, copy


coreList = ['MPU1_0','MCU1_0', 'MCU2_0', 'MCU2_1', 'MCU3_0', 'MCU3_1']
coreList_SelectedValue=['1.0','1']


def GenerateSigDefInit(CFile,HFile,ListOfInitFunctions):
    CFile.write("// *********************************************************************\n")
    CFile.write("// ****************** SignalDef LocalData ******************************\n")
    CFile.write("// *********************************************************************\n")
    CFile.write("static bool_t SigDef_Init_state=FALSE;\n");

    CFile.write("// *********************************************************************\n")
    CFile.write("// ****************** SignalDef Const Init Data ************************\n")
    CFile.write("// *********************************************************************\n")
    if(ListOfInitFunctions != None):
        for (s,hasInit,dType,InitialVal,ExtendedInitSignature) in ListOfInitFunctions:
            if hasInit == True:
                CFile.write("static const "+dType+" SigMgr_InitValue_" + s + "="+InitialVal+";\n");

    HFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
    HFile.write("bool_t SigDef_Init();\n");
    HFile.write("#ifdef __cplusplus\n}\n#endif\n");
    CFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
    CFile.write("bool_t SigDef_Init()\n");
    CFile.write("{\n");
    CFile.write("\tbool_t bRet=TRUE;\n\n");

    if(ListOfInitFunctions != None):
        for (s,hasInit,dType,InitialVal,ExtendedInitSignature) in ListOfInitFunctions:
            if(ExtendedInitSignature == True):
                if(InitialVal == "ZeroMemory"):
                    CFile.write("\tbRet &= SigMgr_" + s + "_Init(\"" + s + "_uid\",NULL,TRUE);\n");
                else:
                    CFile.write("\tbRet &= SigMgr_" + s + "_Init(\"" + s + "_uid\",&SigMgr_InitValue_"+s+",FALSE);\n");
            else:
                CFile.write("\tbRet &= SigMgr_" + s + "_Init(\""+s+"_uid\");\n");

    CFile.write("\n\tif((bRet != FALSE))\n");
    CFile.write("\t\t{SigDef_Init_state=TRUE;}\n");
    CFile.write("\n\treturn bRet;\n");
    CFile.write("}\n\n");
    CFile.write("#ifdef __cplusplus\n}\n#endif\n");


    #get init state
    CFile.write("static bool_t SigDef_GetInitState()\n");
    CFile.write("{\n");
    CFile.write("\treturn SigDef_Init_state;\n");
    CFile.write("}\n");


def GenerateInterfacesAndProtoypes(DataType,VarName,CFile,HFile,GenerateGet,GenerateCallbackRegister=False,GenerateLockUnlock=False,hasInit=False):

    if  hasInit == False:
        # HFile.write("static bool_t SigMgr_" + VarName + "_Init(const char *uid_name);\n");
        CFile.write("static bool_t SigMgr_" + VarName + "_Init(const char *uid_name)\n");
    else:
        # HFile.write("static bool_t SigMgr_" + VarName + "_Init(const char *uid_name,const "+DataType+" *InitVal,bool_t ZeroOut);\n");
        CFile.write("static bool_t SigMgr_" + VarName + "_Init(const char *uid_name,const "+DataType+" *InitVal,bool_t ZeroOut)\n");
    CFile.write("{\n");
    CFile.write("\tbool_t bRet=FALSE;\n");
    CFile.write("\tif((uid_name != NULL) && (SigDef_GetInitState() == FALSE))\n");
    CFile.write("\t{\n");
    if hasInit == False:
        CFile.write("\t\tbRet=SigMgr_" + VarName + ".Init(uid_name);\n");
    else:
        CFile.write("\t\tbRet=SigMgr_" + VarName + ".Init(uid_name,InitVal,ZeroOut);\n");
    CFile.write("\t}\n");
    CFile.write("\treturn bRet;\n");
    CFile.write("}\n");

    HFile.write("\n#ifdef SIGMGR_GENERATE_RTE_INTERFACES");
    HFile.write("\n#define Rte_Write_" + VarName +"(data) SigMgr_" + VarName + "_Put(data)");
    HFile.write("\n#endif\n");
    HFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
    HFile.write("bool_t SigMgr_" + VarName + "_Put("+DataType+" *data);\n");
    HFile.write("#ifdef __cplusplus\n}\n#endif\n");
    CFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
    CFile.write("bool_t SigMgr_" + VarName + "_Put("+DataType+" *data)\n");
    CFile.write("{\n");
    CFile.write("\tbool_t bRet=FALSE;\n");
    CFile.write("\tif((data != NULL) && (SigDef_GetInitState() == TRUE))\n");
    CFile.write("\t{\n");
    CFile.write("\t\tbRet=SigMgr_"+VarName+".Set(data);\n");
    CFile.write("\t}\n");
    CFile.write("\treturn bRet;\n");
    CFile.write("}\n");
    CFile.write("#ifdef __cplusplus\n}\n#endif\n");

    if(GenerateGet == True):
        HFile.write("\n#ifdef SIGMGR_GENERATE_RTE_INTERFACES");
        HFile.write("\n#define Rte_Read_" + VarName +"(data) SigMgr_" + VarName + "_Get(data)");
        HFile.write("\n#endif\n");
        HFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
        HFile.write("void SigMgr_" + VarName + "_Get("+DataType+" *data);\n");
        HFile.write("#ifdef __cplusplus\n}\n#endif\n");
        CFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
        CFile.write("void SigMgr_" + VarName + "_Get("+DataType+" *data)\n");
        CFile.write("{\n");
        CFile.write("\tSigMgr_"+VarName+".Get(data);\n");
        CFile.write("}\n");
        CFile.write("#ifdef __cplusplus\n}\n#endif\n");

        HFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
        HFile.write(DataType +"  * SigMgr_" + VarName + "_GetDataObjRef();\n");
        HFile.write("#ifdef __cplusplus\n}\n#endif\n");
        CFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
        CFile.write(DataType+" * SigMgr_" + VarName + "_GetDataObjRef()\n");
        CFile.write("{\n");
        CFile.write("\treturn SigMgr_"+VarName+".GetDataObjRef();\n");
        CFile.write("}\n");
        CFile.write("#ifdef __cplusplus\n}\n#endif\n");

    if(GenerateLockUnlock == True):
        HFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
        HFile.write("void SigMgr_" + VarName + "_Lock();\n");
        HFile.write("#ifdef __cplusplus\n}\n#endif\n");
        CFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
        CFile.write("void SigMgr_" + VarName + "_Lock()\n");
        CFile.write("{\n");
        CFile.write("\tSigMgr_"+VarName+".lock();\n");
        CFile.write("}\n");
        CFile.write("#ifdef __cplusplus\n}\n#endif\n");

        HFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
        HFile.write("void SigMgr_" + VarName + "_UnLock();\n");
        HFile.write("#ifdef __cplusplus\n}\n#endif\n");
        CFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
        CFile.write("void SigMgr_" + VarName + "_UnLock()\n");
        CFile.write("{\n");
        CFile.write("\tSigMgr_" + VarName + ".unlock();\n");
        CFile.write("}\n");
        CFile.write("#ifdef __cplusplus\n}\n#endif\n");

    if(GenerateCallbackRegister == True):
        HFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
        HFile.write("bool_t SigMgr_" + VarName + "_RegisterCallback(void (*Callback)(const "+DataType+" * const));\n");
        HFile.write("#ifdef __cplusplus\n}\n#endif\n");
        CFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
        CFile.write("bool_t SigMgr_" + VarName + "_RegisterCallback(void (*Callback)(const "+DataType+" * const))\n");
        CFile.write("{\n\tbool_t bRet;\n");
        CFile.write("\tbRet=SigMgr_"+VarName+".RegisterCallback(Callback);\n");
        CFile.write("\treturn bRet;\n}\n");
        CFile.write("#ifdef __cplusplus\n}\n#endif\n");


def GenerateComment1(DataType,VarName,CFile,HFile):
    HFile.write("// *********************************************************************\n")
    HFile.write("// ****************** Start SignalData : " + DataType + " :: " + VarName + " \n")
    HFile.write("// *********************************************************************\n")
    CFile.write("// *********************************************************************\n")
    CFile.write("// ****************** Start SignalData : " + DataType + " :: " + VarName + " \n")
    CFile.write("// *********************************************************************\n")

def GenerateComment2(DataType,VarName,CFile,HFile):
    HFile.write("// *********************************************************************\n")
    HFile.write("// ****************** End SignalData : " + DataType + " :: " + VarName + " \n")
    HFile.write("// *********************************************************************\n")
    CFile.write("// *********************************************************************\n")
    CFile.write("// ****************** EndSignalData : " + DataType + " :: " + VarName + " \n")
    CFile.write("// *********************************************************************\n")
    HFile.write("\n\n")
    CFile.write("\n\n")

def NoStorageSignalData(DataType,VarName,CFile,HFile,RecvCount):

    GenerateComment1(DataType,VarName,CFile,HFile)

    CFile.write("static SignalMgr_Notifier<" + DataType +","+str(RecvCount)+ "> SigMgr_" + VarName + ";\n");
    GenerateInterfacesAndProtoypes(DataType, VarName, CFile, HFile, False,True,False)
    GenerateComment2(DataType,VarName,CFile,HFile)



def ProtectedSignalData(DataType,VarName,CFile,HFile,RecvCount):
    GenerateComment1(DataType,VarName,CFile,HFile)
    bCallBackGeneration=False;
    if(RecvCount > 0):
        CFile.write("static SignalMgr_ProtectedData_WithNotifier<" + DataType +","+str(RecvCount)+ "> SigMgr_" + VarName + ";\n");
        bCallBackGeneration=True;
    else:
        CFile.write("static SignalMgr_ProtectedData<" + DataType +"> SigMgr_" + VarName + ";\n");
    GenerateInterfacesAndProtoypes(DataType, VarName, CFile, HFile, True,GenerateCallbackRegister=bCallBackGeneration,GenerateLockUnlock=True,hasInit=True)

    GenerateComment2(DataType,VarName,CFile,HFile)

def SignalData(DataType,VarName,CFile,HFile,RecvCount):
    GenerateComment1(DataType, VarName, CFile, HFile)
    bCallBackGeneration = False;
    if(RecvCount > 0):
        CFile.write("static SignalMgr_BasicData_WithNotifier<" + DataType +","+str(RecvCount)+ "> SigMgr_" + VarName + ";\n");
        bCallBackGeneration = True;
    else:
        CFile.write("static SignalMgr_BasicData<" + DataType +"> SigMgr_" + VarName + ";\n");
    GenerateInterfacesAndProtoypes(DataType, VarName, CFile, HFile, True,GenerateCallbackRegister=bCallBackGeneration,GenerateLockUnlock=False,hasInit=True)

    GenerateComment2(DataType, VarName, CFile, HFile)


def GenerateIncludeGaurds(HFile):
    HFile.write("#ifndef SIGNALDATA_H_INCGUARD \n")
    HFile.write("#define SIGNALDATA_H_INCGUARD \n")

def CloseIncludeGaurds(HFile):
    HFile.write("#endif \n")


def AddHFileHeaders(HFile):
    HFile.write("\n#include \"PlatformDataTypes.h\"")
    HFile.write("\n#include \"SignalMgrSigTypes.h\"")
    nothing=0

def AddCFileHeaders(CFile):
    CFile.write("\n#include \"SignalDef.h\"\n")
    CFile.write("#include \"SignalMgrBase.h\"\n")

    CFile.write("using namespace SignalMgr;\n")

    CFile.write("\n\n");
    CFile.write("static bool_t SigDef_GetInitState();\n")

            
def ProcessSheet(ExcelFilePath,HFile):

    g_SignalData = dict([(core,[]) for core in coreList])

    #Open the excel
    DataDefworkbook=pd.read_excel(ExcelFilePath, sheet_name = 'IPC_LookupTable',usecols = 'A:Z');
    DataDefworkbook.head()
    (rows,col)=DataDefworkbook.shape

    for i in range(0,rows):

        currentRowSignalDef= dict()

        try:
            currentRowSignalDef['VarName']=str(DataDefworkbook['Variable_Port_Name'].loc[i]).strip()
            if(currentRowSignalDef['VarName'] == "" or currentRowSignalDef['VarName'] == None or currentRowSignalDef['VarName'] == 'nan'):
                #ignore if its an empty row
                bIgnore=True;
            else:

                #parse all columns
                currentRowSignalDef['hasInit'] = True;
                currentRowSignalDef['DataType']=str(DataDefworkbook['Data_Type'].loc[i]).strip()
                currentRowSignalDef['Type']=str(DataDefworkbook['Type'].loc[i]).strip()
                currentRowSignalDef['InitValue'] = str(DataDefworkbook['InitValue'].loc[i]).strip()
                if(currentRowSignalDef['InitValue'] == "nan"):
                    currentRowSignalDef['InitValue'] = "ZeroMemory"
                if(currentRowSignalDef['InitValue'] == "ZeroMemory"):
                    currentRowSignalDef['hasInit'] = False;
                currentRowSignalDef['RecvCount'] = str(DataDefworkbook['Notifiers'].loc[i]).strip()
                if (currentRowSignalDef['RecvCount'] != "nan"):
                    currentRowSignalDef['RecvCount'] = int(DataDefworkbook['Notifiers'].loc[i])
                else:
                    currentRowSignalDef['RecvCount']=0

                currentRowSignalDef['IPCMsgId'] = "e_IpcMsgId_"+currentRowSignalDef['VarName']
                currentRowSignalDef['Source']= str(DataDefworkbook['Source'].loc[i]).strip()

                AtleastOneReciever=False;
                for core in coreList:
                    currentRowSignalDef[core]=str(DataDefworkbook[core].loc[i]).strip()
                    if(currentRowSignalDef[core] in coreList_SelectedValue) and (currentRowSignalDef['Source'] != str(core)):
                        AtleastOneReciever=True
                
                if(AtleastOneReciever == False):
                    #this signal is local to the core
                    currentRowSignalDef['IPC']='NA'
                    g_SignalData[currentRowSignalDef['Source']].append(currentRowSignalDef)
                else:                    
                    currentRowSignalDef_Reciever=copy.deepcopy(currentRowSignalDef)

                    currentRowSignalDef_Reciever['IPC']='Recv'
                    currentRowSignalDef['IPC']='Send'
                    
                    g_SignalData[currentRowSignalDef['Source']].append(currentRowSignalDef)
                    for core in coreList:
                        if(currentRowSignalDef[core] in coreList_SelectedValue):
                            g_SignalData[core].append(currentRowSignalDef_Reciever)                           
        except KeyError:
            print("Key Error")



    return g_SignalData



def GenerateCode(g_SigData,CFile,HFile,IpcAdapter):

    for core  in coreList:
        SignalMgr_IPCAdapater.IPCAdapterCodeGen_Clear();
        ListOfData = []

        HFile.write("\n\n#ifdef BUILD_"+core +"\n\n")
        CFile.write("\n\n#ifdef BUILD_" + core+"\n\n")

        for m_SigDef in g_SigData[core]:

            if(m_SigDef['IPC'] == 'Send'):
                SignalMgr_IPCAdapater.IPCAdapterCodeGen_AddSender(m_SigDef['DataType'],m_SigDef['VarName'],m_SigDef['IPCMsgId'])
                #an additional Notfier
                m_SigDef['RecvCount']+=1
            elif(m_SigDef['IPC'] == 'Recv'):
                SignalMgr_IPCAdapater.IPCAdapterCodeGen_AddRecv(m_SigDef['DataType'], m_SigDef['VarName'])

            ExtendedInitSignature=False;
            if (m_SigDef['Type'] == "NoStorage" ):
                NoStorageSignalData(m_SigDef['DataType'], m_SigDef['VarName'], CFile, HFile,m_SigDef['RecvCount'])
                hasInit = False;
                ExtendedInitSignature = False;

            elif (m_SigDef['Type'] == "Concurrent"):
                ProtectedSignalData(m_SigDef['DataType'], m_SigDef['VarName'], CFile, HFile,m_SigDef['RecvCount'])
                ExtendedInitSignature=True;

            elif (m_SigDef['Type'] == "Simple"):
                SignalData(m_SigDef['DataType'], m_SigDef['VarName'], CFile, HFile,m_SigDef['RecvCount'])
                ExtendedInitSignature=True;
            else:
                print("Error \n")


            ListOfData.append((m_SigDef['VarName'],m_SigDef['hasInit'],m_SigDef['DataType'],m_SigDef['InitValue'],ExtendedInitSignature));

        GenerateSigDefInit(CFile, HFile,ListOfData);

        HFile.write("\n\n#endif\n\n")
        CFile.write("\n\n#endif\n\n")

        (CAdapter, HAdaper)=IpcAdapter
        SignalMgr_IPCAdapater.IPCAdapterCodeGen_Gen((CAdapter,HAdaper),core)

def GenerateSignalData(ExcelFilePath,COutputPath,HOutputPath,IpcAdapter):

    #Open handles for C file and H file output
    CFile=open(COutputPath,"w")
    HFile=open(HOutputPath,"w")

    GenerateIncludeGaurds(HFile)

    AddHFileHeaders(HFile)
    AddCFileHeaders(CFile)


    g_SigData=ProcessSheet(ExcelFilePath, HFile)
    GenerateCode(g_SigData,CFile, HFile,IpcAdapter)



    CloseIncludeGaurds(HFile);

    #close the file handles
    CFile.close();
    HFile.close();





if __name__ == '__main__':
    CurrentPath=os.path.dirname(os.path.realpath(__file__))
    (CAdapter,HAdaper)=SignalMgr_IPCAdapater.IPCAdapterCodeGen_Setup(CurrentPath)
    ExcelFilePath=os.path.join(CurrentPath,".\\..\\..\\","Stellantis_L2H4060_IPC_SignalDef.xlsm")
    COutputPath=os.path.join(CurrentPath,".\\..\\gen\\","SignalDef.cpp")
    HOutputPath=os.path.join(CurrentPath,".\\..\\gen\\","SignalDef.h")
    GenerateSignalData(ExcelFilePath,COutputPath,HOutputPath,(CAdapter,HAdaper))
    SignalMgr_IPCAdapater.IPCAdapterCodeGen_Close((CAdapter, HAdaper))