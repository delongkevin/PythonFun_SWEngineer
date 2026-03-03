from numpy import append
import pandas as pd
import os
import sys
import SignalMgr_IPCAdapater
import shutil , pickle, copy
from pathlib import Path


coreList = ['MPU1_0','MCU1_0', 'MCU2_0', 'MCU2_1', 'MCU3_0', 'MCU3_1']
coreList_SelectedValue=['1.0','1']
AsilList = ['QM', 'B', 'C']
TableEntry_MagicVar = {'MPU1_0':'0xAABBCCDD','MCU1_0':'0xDDBBAA11', 'MCU2_0':'0x55AA4590', 'MCU2_1':'0x99885544', 'MCU3_0':'0x6655AACC', 'MCU3_1':'0x774499EE'}


def Generate_InitFunction(CodeSec,HeadSec,VarName,DataType,asil,RecvCount,StaticForwardInits):
    StaticForwardInits[asil].append("static bool_t SigMgr_" + VarName + "_Init(const "+DataType+" *InitVal,bool_t ZeroOut);\n");
    CodeSec.append("static bool_t SigMgr_" + VarName + "_Init(const "+DataType+" *InitVal,bool_t ZeroOut) {\n");

    CodeSec.append("\tbool_t bRet=FALSE;\n");
    CodeSec.append("\tbRet=SigMgr_DataInit(&SigMgr_Meta_"+VarName+",(const void *)InitVal,ZeroOut);\n");
    CodeSec.append("\treturn bRet;\n");

    CodeSec.append("}\n");

def Generate_LockFunction(CodeSec,HeadSec,VarName,asil):
    CodeSec.append("\n")
    HeadSec.append("bool_t SigMgr_" + VarName + "_Lock();\n");
    CodeSec.append("bool_t SigMgr_" + VarName + "_Lock() {\n");

    CodeSec.append("\tbool_t bRet=FALSE;\n");
    CodeSec.append("\tif(SigDef_GetInitState_"+asil+"() == TRUE )\n");
    CodeSec.append("\t{\n");

    CodeSec.append("\t\tbRet=SigMgr_Data_Lock(&SigMgr_Meta_"+VarName+");\n");

    CodeSec.append("\t}\n");

    CodeSec.append("}\n");

def Generate_UnLockFunction(CodeSec,HeadSec,VarName,asil):
    CodeSec.append("\n")
    HeadSec.append("bool_t SigMgr_" + VarName + "_UnLock();\n");
    CodeSec.append("bool_t SigMgr_" + VarName + "_UnLock() {\n");

    CodeSec.append("\tbool_t bRet=FALSE;\n");
    CodeSec.append("\tif(SigDef_GetInitState_"+asil+"() == TRUE )\n");
    CodeSec.append("\t{\n");

    CodeSec.append("\t\tbRet=SigMgr_Data_UnLock(&SigMgr_Meta_"+VarName+");\n");

    CodeSec.append("\t}\n");

    CodeSec.append("}\n");


def Generate_PutFunction(CodeSec,HeadSec,VarName,DataType,asil,RecvCount):
    CodeSec.append("\n")
    HeadSec.append("bool_t SigMgr_" + VarName + "_Put(const "+DataType+" * const data);\n");
    CodeSec.append("bool_t SigMgr_" + VarName + "_Put(const "+DataType+" * const data) {\n");

    CodeSec.append("\tbool_t bRet=FALSE;\n");
    if(RecvCount > 0):
        CodeSec.append("\tuint32_t i;\n");
    CodeSec.append("\tconst SigMgr_MetaData *pData=&SigMgr_Meta_"+VarName+";\n");
    CodeSec.append("\tif(SigDef_GetInitState_"+asil+"() == TRUE )\n");
    CodeSec.append("\t{\n");

    CodeSec.append("\t\tbRet=SigMgr_Data_Put(pData,(const void *)data);\n");

    if(RecvCount > 0):
        
        CodeSec.append("\t\tif(bRet == TRUE) {\n");
        CodeSec.append("\t\t\tfor(i=0;((i<pData->extData->RegisteredNotifiers) && (i<pData->MaxNotifierCount));i++){\n");
        CodeSec.append("\t\t\t\tSigMgr_pCallback_"+VarName+"[i](data);\n");
        CodeSec.append("\t\t\t}\n");
        CodeSec.append("\t\t}\n");

    CodeSec.append("\t}\n");

    CodeSec.append("\treturn bRet;\n");
    CodeSec.append("}\n");

def Generate_GetFunction(CodeSec,HeadSec,VarName,DataType,AccessType,RecvCount,asil):
    if AccessType != "SigMgr_DA_NoStorage":

        CodeSec.append("\n")
        HeadSec.append("bool_t SigMgr_" + VarName + "_Get(const "+DataType+" *  data);\n");
        CodeSec.append("bool_t SigMgr_" + VarName + "_Get(const "+DataType+" *  data) {\n");

        CodeSec.append("\tbool_t bRet=FALSE;\n");
        CodeSec.append("\tconst SigMgr_MetaData *pData=&SigMgr_Meta_"+VarName+";\n");
        CodeSec.append("\tif(SigDef_GetInitState_"+asil+"() == TRUE ){\n");
        CodeSec.append("\t\tbRet=SigMgr_Data_Get(pData,(void *)data);\n");
        CodeSec.append("\t}\n");
        CodeSec.append("\treturn bRet;\n");
        CodeSec.append("}\n");

def Generate_GetObjRefFunction(CodeSec,HeadSec,VarName,DataType,AccessType,RecvCount,asil):
    if AccessType != "SigMgr_DA_NoStorage":

        CodeSec.append("\n")
        HeadSec.append("const "+DataType+" * SigMgr_" + VarName + "_GetDataObjRef();\n");
        CodeSec.append("const "+DataType+" * SigMgr_" + VarName + "_GetDataObjRef() {\n");

        CodeSec.append("\tconst "+DataType+" * Ret=NULL;\n");
        CodeSec.append("\tconst SigMgr_MetaData *pData=&SigMgr_Meta_"+VarName+";\n");
        CodeSec.append("\tRet=(const "+DataType+" *)pData->MemDetail->DataPtr;\n");
        CodeSec.append("\treturn Ret;\n");
        CodeSec.append("}\n");


def Generate_RegisterCallbackFunction(CodeSec,HeadSec,VarName,asil,RecvCount):
    if(RecvCount > 0):
        CodeSec.append("\n")
        #HeadSec.append("typedef void (*SigMgr_" + VarName + "_CallbackType)(const "+DataType+"* const pData);\n");
        HeadSec.append("bool_t SigMgr_" + VarName + "_RegisterCallback(SigMgr_" + VarName + "_CallbackType pFuncPointer);\n");
        CodeSec.append("bool_t SigMgr_" + VarName + "_RegisterCallback(SigMgr_" + VarName + "_CallbackType pFuncPointer) {\n");

        CodeSec.append("\tbool_t bRet=FALSE;\n");
        CodeSec.append("\tconst SigMgr_MetaData *pData=&SigMgr_Meta_"+VarName+";\n");
        CodeSec.append("\tif(SigDef_GetInitState_"+asil+"() == TRUE )\n");
        CodeSec.append("\t{\n");

        #Get the Semaphore
        #Get the Semphore: For Registering RaceCondition
        CodeSec.append("\t\tSigMgr_Core_Lock();\n");

        #If Storage : Copy to local Memory
        CodeSec.append("\t\tif(pData->extData->RegisteredNotifiers <  pData->MaxNotifierCount) {\n");
        CodeSec.append("\t\t\tSigMgr_pCallback_"+VarName+"[pData->extData->RegisteredNotifiers]=pFuncPointer;\n");
        CodeSec.append("\t\t\tpData->extData->RegisteredNotifiers+=1;\n");
        CodeSec.append("\t\t\tbRet=TRUE;\n\t\t}\n");

        #Release the semaphore
        CodeSec.append("\t\tSigMgr_Core_UnLock();\n");

        CodeSec.append("\t}\n");
        CodeSec.append("\treturn bRet;\n");
        CodeSec.append("}\n");


def GenerateSigDefInit(CodeSec,HeadSec,ListOfInitFunctions,StaticForwadDeclarations):

    for asil in AsilList:
        CodeSec[asil].append("// *********************************************************************\n")
        CodeSec[asil].append("// ****************** SignalDef LocalData ******************************\n")
        CodeSec[asil].append("// *********************************************************************\n")
        if((ListOfInitFunctions[asil] != None) and (len(ListOfInitFunctions[asil] )> 0)):
            CodeSec[asil].append("static bool_t SigDef_Init_state_"+asil+"=FALSE;\n");

        CodeSec[asil].append("// *********************************************************************\n")
        CodeSec[asil].append("// ****************** SignalDef Const Init Data ************************\n")
        CodeSec[asil].append("// *********************************************************************\n")
        if(ListOfInitFunctions[asil] != None):
            for (s,hasInit,dType,InitialVal,ExtendedInitSignature) in ListOfInitFunctions[asil]:
                if hasInit == True:
                    CodeSec[asil].append("static const "+dType+" SigMgr_InitValue_" + s + "="+InitialVal+";\n");

        HeadSec[asil].append("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
        HeadSec[asil].append("bool_t SigDef_Init_"+asil+"();\n");
        HeadSec[asil].append("#ifdef __cplusplus\n}\n#endif\n");
        CodeSec[asil].append("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
        CodeSec[asil].append("bool_t SigDef_Init_"+asil+"()\n");
        CodeSec[asil].append("{\n");
        CodeSec[asil].append("\tbool_t bRet=TRUE;\n\n");

        if(ListOfInitFunctions[asil] != None):
            for (s,hasInit,dType,InitialVal,ExtendedInitSignature) in ListOfInitFunctions[asil]:
                if(ExtendedInitSignature == True):
                    if(InitialVal == "ZeroMemory"):
                        CodeSec[asil].append("\tbRet &= SigMgr_" + s + "_Init(NULL,TRUE);\n");
                    else:
                        CodeSec[asil].append("\tbRet &= SigMgr_" + s + "_Init(&SigMgr_InitValue_"+s+",FALSE);\n");
                else:
                    CodeSec[asil].append("\tbRet &= SigMgr_" + s + "_Init(\""+s+"_uid\");\n");

        #for removing compiler warning
        if((ListOfInitFunctions[asil] != None) and (len(ListOfInitFunctions[asil] )> 0)):
            CodeSec[asil].append("\n\tif((bRet != FALSE))\n");
            CodeSec[asil].append("\t\t{SigDef_Init_state_"+asil+"=TRUE;}\n");

        CodeSec[asil].append("\n\treturn bRet;\n");
        CodeSec[asil].append("}\n\n");
        CodeSec[asil].append("#ifdef __cplusplus\n}\n#endif\n");


        #get init state

        if((ListOfInitFunctions[asil] != None) and (len(ListOfInitFunctions[asil] )> 0)):
            StaticForwadDeclarations[asil].append("static bool_t SigDef_GetInitState_"+asil+"();\n");
            CodeSec[asil].append("static bool_t SigDef_GetInitState_"+asil+"()\n");
            CodeSec[asil].append("{\n");
            CodeSec[asil].append("\treturn SigDef_Init_state_"+asil+";\n");
            CodeSec[asil].append("}\n");


def GenerateInterfacesAndProtoypes(DataType,VarName,CodeSec,HeadSec,asil,GenerateGet,GenerateLockUnlock,hasInit,AccessType,RecvCount,StaticForwardInits,Generateput):

    #If there are callbacks
    if(RecvCount > 0):
        Generate_RegisterCallbackFunction(CodeSec,HeadSec,VarName,asil,RecvCount)

    if  hasInit == False:
        Generate_InitFunction(CodeSec,HeadSec,VarName,DataType,asil,RecvCount,StaticForwardInits)
    else:
        Generate_InitFunction(CodeSec,HeadSec,VarName,DataType,asil,RecvCount,StaticForwardInits)

    if(Generateput == True):
        Generate_PutFunction(CodeSec,HeadSec,VarName,DataType,asil,RecvCount)

    if(GenerateGet == True):
        Generate_GetFunction(CodeSec,HeadSec,VarName,DataType,AccessType,RecvCount,asil)
        Generate_GetObjRefFunction(CodeSec,HeadSec,VarName,DataType,AccessType,RecvCount,asil)

    #if(GenerateLockUnlock == True):
    #    Generate_LockFunction(CodeSec,HeadSec,VarName,AccessType)
    #    Generate_UnLockFunction(CodeSec,HeadSec,VarName,AccessType)        

        


def GenerateComment1(DataType,VarName,CodeSec,HeadSec):
    HeadSec.append("// *********************************************************************\n")
    HeadSec.append("// ****************** Start SignalData : " + DataType + " :: " + VarName + " \n")
    HeadSec.append("// *********************************************************************\n")
    CodeSec.append("// *********************************************************************\n")
    CodeSec.append("// ****************** Start SignalData : " + DataType + " :: " + VarName + " \n")
    CodeSec.append("// *********************************************************************\n")

def GenerateComment2(DataType,VarName,CodeSec,HeadSec):
    HeadSec.append("// *********************************************************************\n")
    HeadSec.append("// ****************** End SignalData : " + DataType + " :: " + VarName + " \n")
    HeadSec.append("// *********************************************************************\n")
    CodeSec.append("// *********************************************************************\n")
    CodeSec.append("// ****************** EndSignalData : " + DataType + " :: " + VarName + " \n")
    CodeSec.append("// *********************************************************************\n")
    HeadSec.append("\n\n")
    CodeSec.append("\n\n")



def GenerateIncludeGaurds(HFil, st):
    HFil.write("#ifndef SIGNALDATA_H_INCGUARD"+st+" \n")
    HFil.write("#define SIGNALDATA_H_INCGUARD"+st+" \n")

def CloseIncludeGaurds(HFile):
    HFile.write("#endif \n")


def AddHFileHeaders(HFile):
    HFile.write("\n#include \"PlatformDataTypes.h\"")
    HFile.write("\n#include \"SignalMgrSigTypes.h\"")
    HFile.write("\n#include \"SignalgenTypes.h\"")
    nothing=0

def AddCFileHeaders(CFile):
    CFile.write("\n#include \"SignalDef.h\"\n")
    CFile.write("#include \"SignalMgr.h\"\n")
    CFile.write("\n\n");
    #CFile.write("static bool_t SigDef_GetInitState();\n")

            
def ProcessSheet(ExcelFilePath):

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
                currentRowSignalDef['UseInterCore_SharedMemory']=str(DataDefworkbook['UseInterCore_SharedMemory'].loc[i]).strip()
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
                currentRowSignalDef['ASIL']='B'

                AtleastOneReciever=False;
                for core in coreList:
                    currentRowSignalDef[core]=str(DataDefworkbook[core].loc[i]).strip()
                    if(currentRowSignalDef[core] in coreList_SelectedValue) and (currentRowSignalDef['Source'] != str(core)):
                        AtleastOneReciever=True
                
                if(AtleastOneReciever == False):

                    #this signal is local to the core
                    currentRowSignalDef['IPC']='NA'
                    if(str(DataDefworkbook['Type'].loc[i]).strip() == 'NoStorage'):
                        currentRowSignalDef['DataStore']= False
                        currentRowSignalDef['MutualExclusionAccess'] ='SigMgr_MutualExclusion_None'
                    else:
                        currentRowSignalDef['DataStore']= True
                        if(str(DataDefworkbook['Type'].loc[i]).strip() == 'Concurrent'):
                            currentRowSignalDef['MutualExclusionAccess'] ='SigMgr_MutualExclusion_Semaphore'
                        else:
                            currentRowSignalDef['MutualExclusionAccess'] ='SigMgr_MutualExclusion_None'

                    #add this to the list        
                    g_SignalData[currentRowSignalDef['Source']].append(currentRowSignalDef)

                else:
                    #this signal goes cross core 
                    if(currentRowSignalDef['UseInterCore_SharedMemory'] == 'Yes'):
                        #if usin shared memory
                        currentRowSignalDef['DataStore']= True
                        currentRowSignalDef['MutualExclusionAccess'] ='SigMgr_MutualExclusion_SpinLock'  
                    else:
                        #using Actual IPC for sending data
                        if(str(DataDefworkbook['Type'].loc[i]).strip() == 'NoStorage'):
                            currentRowSignalDef['DataStore']= False
                            currentRowSignalDef['MutualExclusionAccess'] ='SigMgr_MutualExclusion_None'
                        else:
                            currentRowSignalDef['DataStore']= True
                            if(str(DataDefworkbook['Type'].loc[i]).strip() == 'Concurrent'):
                                currentRowSignalDef['MutualExclusionAccess'] ='SigMgr_MutualExclusion_Semaphore'
                            else:
                                currentRowSignalDef['MutualExclusionAccess'] ='SigMgr_MutualExclusion_None'
                    currentRowSignalDef_Reciever=copy.deepcopy(currentRowSignalDef)
                    currentRowSignalDef_Reciever['IPC']='Recv'
                    currentRowSignalDef['IPC']='Send'
                    
                    #add this to the list
                    g_SignalData[currentRowSignalDef['Source']].append(currentRowSignalDef)
                    for core in coreList:
                        if(currentRowSignalDef[core] in coreList_SelectedValue):
                            g_SignalData[core].append(currentRowSignalDef_Reciever)                           
        except KeyError:
            print("Key Error")



    return g_SignalData


def AddExtern_C(dStr):
    dStr.append("\n")
    dStr.append("#ifdef __cplusplus\nextern \"C\" {\n#endif\n")

def CloseExtern_C(dStr):
    dStr.append("\n")
    dStr.append("#ifdef __cplusplus\n}\n#endif\n")


def AddComment_Divsion(h,st):
    h.write("\n\n\n/******************************************************************************************/")
    h.write("\n/*"+st+"*/")
    h.write("\n/********************************************************************************************/\n\n")


def AddLinkerSection_strlist(str_lst,var,sec):
    str_lst.append("#if SignalMGR_Build == SignalMgr_BUILD_AUTOSAR\n")
    str_lst.append("#pragma DATA_SECTION ("+var+",\""+sec+"\")\n")
    str_lst.append("#else\n")
    str_lst.append("#pragma DATA_SECTION (\""+sec+"\")\n")
    str_lst.append("#endif\n")
    str_lst.append("\n")

def AddLinkerSection_file(fhandle,var,sec):
    str_lst=[]
    AddLinkerSection_strlist(str_lst,var,sec)
    for s in str_lst:
        fhandle.write(s)


def GenerateCode(g_SigData,CFile,HFile,IpcAdapter,Handle_Linker_Defs,HFile_Types):

    Core_DataOriginLookup = dict()

    H_Linker_Local,H_Linker_Shared=Handle_Linker_Defs
    Const_Data_SectionDefs = dict([(asil, []) for asil in AsilList])
    RAM_Data_SectionDefs = dict([(asil, []) for asil in AsilList])


    LocalData_Data_SectionDefs = dict([(asil, []) for asil in AsilList])
    MultiCore_Shared_Data_SectionDefs = dict([(asil, []) for asil in AsilList])
    Write_SharedMem_EnumEtries=dict([(core,dict([(asil, []) for asil in AsilList])) for core in coreList])
    Local_SharedMem_EnumEtries=dict([(core,dict([(asil, []) for asil in AsilList])) for core in coreList])
    


    ListOfData = dict([(core,dict([(asil, []) for asil in AsilList])) for core in coreList])

    Write_SharedMem_Defs=dict([(core,dict([(asil, []) for asil in AsilList])) for core in coreList])
    
    Write_SharedMem_Refs=dict([(core,dict([(asil, []) for asil in AsilList])) for core in coreList])
    Write_Local_Refs=dict([(core,dict([(asil, []) for asil in AsilList])) for core in coreList])

    Write_Local_Refs_Count=dict([(core,dict([(asil, 0) for asil in AsilList])) for core in coreList])
    Write_SharedMem_Refs_Count=dict([(core,dict([(asil, 0) for asil in AsilList])) for core in coreList])
        

    Data_Declaration = dict([(core,dict([(asil, []) for asil in AsilList])) for core in coreList])

    RamMetaData_Declaration = dict([(core,dict([(asil, []) for asil in AsilList])) for core in coreList])
    ROMMetaData_Declaration = dict([(core,dict([(asil, []) for asil in AsilList])) for core in coreList])
    StaticForwadDeclarations = dict([(core,dict([(asil, []) for asil in AsilList])) for core in coreList])
    CSec = dict([(core,dict([(asil, []) for asil in AsilList])) for core in coreList])
    HSec = dict([(core,dict([(asil, []) for asil in AsilList])) for core in coreList])
    DefinesSec = dict([(core,dict([(asil, []) for asil in AsilList])) for core in coreList])
    TypesSec = dict([(core,dict([(asil, []) for asil in AsilList])) for core in coreList])


    AddComment_Divsion(HFile_Types,"Magic values indicating validity of the lookuptable entries")
    for core in coreList:
        HFile_Types.write("#define SIGMGR_MAGIC_ENTRYVALID_"+core+"  "+TableEntry_MagicVar[core]+"\n")
    HFile_Types.write("\n\n")
    

    for core  in coreList:
        for m_SigDef in g_SigData[core]:
            SignalHighestAsilLevel=m_SigDef['ASIL']
            if(m_SigDef['IPC'] == 'Send'):
                    if(m_SigDef['VarName'] in Core_DataOriginLookup):                            
                        print("ERROR in Generating code : Core_DataOriginLookup duplicate entry")
                        return
                    else:
                        Core_DataOriginLookup[m_SigDef['VarName']]=(core,SignalHighestAsilLevel)



    for core  in coreList:

        SignalMgr_IPCAdapater.IPCAdapterCodeGen_Clear();

        for asil in AsilList:

            AddLinkerSection_strlist(Write_SharedMem_Refs[core][asil],"SigMgr_SharedMemoryItemDetails_"+core+"_"+asil,"SIGMGR_SECTION_SHARED_LOOKUP_REF_TABLE_"+core+"_"+asil)
            Write_SharedMem_Refs[core][asil].append("const SigMgr_SharedMemoryItemDetail SigMgr_SharedMemoryItemDetails_"+core+"_"+asil+"[SigMgr_CoreSpecific_"+core+"_"+asil+"_MAX_SharedMem] ={ \n");
            AddLinkerSection_strlist(Write_Local_Refs[core][asil],"SigMgr_LocalMemoryItemDetails_"+core+"_"+asil,"SIGMGR_SECTION_LOCAL_LOOKUP_REF_TABLE_"+core+"_"+asil)
            Write_Local_Refs[core][asil].append("const SigMgr_SharedMemoryItemDetail SigMgr_LocalMemoryItemDetails_"+core+"_"+asil+"[SigMgr_CoreSpecific_"+core+"_"+asil+"_MAX_CoreLocal] ={ \n");      

        for m_SigDef in g_SigData[core]:

            coreLocalSignal=True;
            generate_put=True
            SignalHighestAsilLevel=m_SigDef['ASIL']
            

            if((m_SigDef['IPC'] == 'Send') and( m_SigDef['UseInterCore_SharedMemory'] != 'Yes')):
                SignalMgr_IPCAdapater.IPCAdapterCodeGen_AddSender(m_SigDef['DataType'],m_SigDef['VarName'],m_SigDef['IPCMsgId'])
                #an additional Notfier
                m_SigDef['RecvCount']+=1
            elif(m_SigDef['IPC'] == 'Recv'):                
                SignalMgr_IPCAdapater.IPCAdapterCodeGen_AddRecv(m_SigDef['DataType'], m_SigDef['VarName'])

            if(m_SigDef['DataStore'] == True):

                SectionName="SIGMGR_SECTION_"+m_SigDef['VarName']+"_"+SignalHighestAsilLevel              
                  
                if(m_SigDef['IPC'] == 'NA'):

                    Local_SharedMem_EnumEtries[core][SignalHighestAsilLevel].append(" SigMgr_en_" + m_SigDef['VarName'])
                    Data_Declaration[core][SignalHighestAsilLevel].append("#if SignalMGR_Build == SignalMgr_BUILD_AUTOSAR \n")                        
                    Data_Declaration[core][SignalHighestAsilLevel].append("#pragma DATA_SECTION (SigMgr_Data"+ m_SigDef['VarName'] + ",\"" + SectionName +"\")\n")
                    Data_Declaration[core][SignalHighestAsilLevel].append("#else\n")
                    Data_Declaration[core][SignalHighestAsilLevel].append("#pragma DATA_SECTION (\"" + SectionName +"\")\n")
                    Data_Declaration[core][SignalHighestAsilLevel].append("#endif\n")

                    LocalData_Data_SectionDefs[SignalHighestAsilLevel].append((SectionName,core))
                    Data_Declaration[core][SignalHighestAsilLevel].append("static " + m_SigDef['DataType'] + " SigMgr_Data" + m_SigDef['VarName'] + ";\n")

                    Write_Local_Refs[core][SignalHighestAsilLevel].append("\t{(void *)&SigMgr_Data" + m_SigDef['VarName']+",sizeof("+m_SigDef['DataType']+"),(void *)&SigMgr_Data" + m_SigDef['VarName']+",sizeof("+m_SigDef['DataType']+"),SIGMGR_MAGIC_ENTRYVALID_"+core+",0xBADC6C},\n")
                    Write_Local_Refs_Count[core][SignalHighestAsilLevel]=Write_Local_Refs_Count[core][SignalHighestAsilLevel]+1

                else:
                    coreLocalSignal=False

                    #its a multi core data
                    if(m_SigDef['IPC'] == 'Send'):



                        Write_SharedMem_EnumEtries[core][SignalHighestAsilLevel].append(" SigMgr_en_" + m_SigDef['VarName'])

                        Write_SharedMem_Defs[core][SignalHighestAsilLevel].append("#if SignalMGR_Build == SignalMgr_BUILD_AUTOSAR \n")                        
                        Write_SharedMem_Defs[core][SignalHighestAsilLevel].append("#pragma DATA_SECTION (SigMgr_Data"+ m_SigDef['VarName'] + ",\"" + SectionName +"\")\n")
                        Write_SharedMem_Defs[core][SignalHighestAsilLevel].append("#else\n")
                        Write_SharedMem_Defs[core][SignalHighestAsilLevel].append("#pragma DATA_SECTION (\"" + SectionName +"\")\n")
                        Write_SharedMem_Defs[core][SignalHighestAsilLevel].append("#endif\n")

                        MultiCore_Shared_Data_SectionDefs[SignalHighestAsilLevel].append((SectionName,core))
                        Write_SharedMem_Defs[core][SignalHighestAsilLevel].append("static volatile " + m_SigDef['DataType'] + " SigMgr_Data" + m_SigDef['VarName'] + ";\n")                        
                        Write_SharedMem_Refs[core][SignalHighestAsilLevel].append("\t{(void *)&SigMgr_Data" + m_SigDef['VarName']+",sizeof("+m_SigDef['DataType']+"),(void *)&SigMgr_Data" + m_SigDef['VarName']+",sizeof("+m_SigDef['DataType']+"),SIGMGR_MAGIC_ENTRYVALID_"+core+",0xBADC6C},\n")
                        Write_SharedMem_Refs_Count[core][SignalHighestAsilLevel]=Write_SharedMem_Refs_Count[core][SignalHighestAsilLevel]+1
                    
                    



            
            #exnded data is always needed
            RamMetaData_Declaration[core][SignalHighestAsilLevel].append("static SigMgr_ExtendedData SigMgr_ExtendedData_" + m_SigDef['VarName'] + "={0,0,0};\n");
            if(m_SigDef['MutualExclusionAccess'] == 'SigMgr_MutualExclusion_Semaphore'):
                RamMetaData_Declaration[core][SignalHighestAsilLevel].append("static SigMgr_SemaphoreMutualExclusion SigMgr_Semaphore_" + m_SigDef['VarName'] + ";\n");
            elif(m_SigDef['MutualExclusionAccess'] == 'SigMgr_MutualExclusion_SpinLock'):
                RamMetaData_Declaration[core][SignalHighestAsilLevel].append("static SigMgr_SpinLockMutualExclusion SigMgr_SpinLock_" + m_SigDef['VarName'] + "={0};\n");
            
            #if there are Notifiers
            if(m_SigDef['RecvCount'] > 0):
                DefinesSec[core][SignalHighestAsilLevel].append("#define SigMgr_" + m_SigDef['VarName'] + "_Callback_MaxCount ("+str(m_SigDef['RecvCount'])+")\n");
                TypesSec[core][SignalHighestAsilLevel].append("typedef void (*SigMgr_" + m_SigDef['VarName'] + "_CallbackType)(const "+m_SigDef['DataType']+" * const data);\n");
                RamMetaData_Declaration[core][SignalHighestAsilLevel].append("static SigMgr_" + m_SigDef['VarName'] + "_CallbackType SigMgr_pCallback_"+m_SigDef['VarName']+"[ SigMgr_" + m_SigDef['VarName'] + "_Callback_MaxCount];\n");



            SignalConstDeclarationString="";
            SignalConstDeclarationString+="static const SigMgr_MetaData SigMgr_Meta_" + m_SigDef['VarName'] + "={";
            #SigMgr_ExtendedData *extData;
            SignalConstDeclarationString+="&SigMgr_ExtendedData_" + m_SigDef['VarName']+","
            #uint8_t MaxNotifierCount;
            SignalConstDeclarationString+=str(m_SigDef['RecvCount'])+","
            #uint32_t size;t;
            SignalConstDeclarationString+="sizeof("+m_SigDef['DataType']+"),"

            #DatPtr;
            
            
            if(coreLocalSignal == False):
                (lookup_core,lookup_asil)=Core_DataOriginLookup[m_SigDef['VarName']]
                lookup="SigMgr_SharedMemoryItemDetails_"+lookup_core+"_"+lookup_asil+"[SigMgr_en_"+m_SigDef['VarName']+"]"
                Magic_Flag_string="SIGMGR_MAGIC_ENTRYVALID_"+lookup_core
                SigDataOwnerCore=lookup_core
            else:
                lookup="SigMgr_LocalMemoryItemDetails_"+core+"_"+SignalHighestAsilLevel+"[SigMgr_en_"+m_SigDef['VarName']+"]"
                Magic_Flag_string="SIGMGR_MAGIC_ENTRYVALID_"+core
                SigDataOwnerCore=core

            if(m_SigDef['DataStore'] == True):
                SignalConstDeclarationString+="&"+lookup+","
            else:
                SignalConstDeclarationString+="NULL,"

            #SigMgr_SemaphoreMutualExclusion *SemInfo;    
            if(m_SigDef['MutualExclusionAccess'] == 'SigMgr_MutualExclusion_Semaphore'):
                SignalConstDeclarationString+="&SigMgr_Semaphore_" + m_SigDef['VarName']+","
            else:
                SignalConstDeclarationString+="NULL,"

            #SigMgr_SpinLockMutualExclusion *SpinLock;    
            if(m_SigDef['MutualExclusionAccess'] == 'SigMgr_MutualExclusion_SpinLock'):
                SignalConstDeclarationString+="&SigMgr_SpinLock_" + m_SigDef['VarName']+",100,"
            else:
                SignalConstDeclarationString+="NULL,0,"

            #SigMgr_SemaphoreMutualExclusionType MutualExclusionType;  
            if(m_SigDef['MutualExclusionAccess'] == 'SigMgr_MutualExclusion_SpinLock'):
                SignalConstDeclarationString+="SigMgr_MutualExclusion_SpinLock"
            elif(m_SigDef['MutualExclusionAccess'] == 'SigMgr_MutualExclusion_Semaphore'):
                SignalConstDeclarationString+="SigMgr_MutualExclusion_Semaphore"
            else:
                SignalConstDeclarationString+="SigMgr_MutualExclusion_None"

            SignalConstDeclarationString+=","+Magic_Flag_string

            SignalConstDeclarationString+=",SigMgr_"+SigDataOwnerCore
            
            SignalConstDeclarationString+="};\n"




            ROMMetaData_Declaration[core][SignalHighestAsilLevel].append(SignalConstDeclarationString)


            GenerateComment1(m_SigDef['DataType'],m_SigDef['VarName'],CSec[core][SignalHighestAsilLevel], HSec[core][SignalHighestAsilLevel])

            ExtendedInitSignature=True;
            if (m_SigDef['Type'] == "NoStorage" ):
                hasInit = False;
                ExtendedInitSignature = True;         
                GenerateInterfacesAndProtoypes(m_SigDef['DataType'], m_SigDef['VarName'], CSec[core][SignalHighestAsilLevel], HSec[core][SignalHighestAsilLevel],SignalHighestAsilLevel, GenerateGet=False,GenerateLockUnlock=True,hasInit=False,AccessType=m_SigDef['Type'],RecvCount=m_SigDef['RecvCount'],StaticForwardInits=StaticForwadDeclarations[core],Generateput=generate_put)
            

            elif (m_SigDef['Type'] == "Concurrent"):
                GenerateInterfacesAndProtoypes(m_SigDef['DataType'], m_SigDef['VarName'], CSec[core][SignalHighestAsilLevel], HSec[core][SignalHighestAsilLevel],SignalHighestAsilLevel, GenerateGet=True,GenerateLockUnlock=True,hasInit=True,AccessType=m_SigDef['Type'],RecvCount=m_SigDef['RecvCount'],StaticForwardInits=StaticForwadDeclarations[core],Generateput=generate_put)
                ExtendedInitSignature=True;

            elif (m_SigDef['Type'] == "Simple"):
                GenerateInterfacesAndProtoypes(m_SigDef['DataType'], m_SigDef['VarName'], CSec[core][SignalHighestAsilLevel], HSec[core][SignalHighestAsilLevel],SignalHighestAsilLevel, GenerateGet=True,GenerateLockUnlock=False,hasInit=True,AccessType=m_SigDef['Type'],RecvCount=m_SigDef['RecvCount'],StaticForwardInits=StaticForwadDeclarations[core],Generateput=generate_put)
                ExtendedInitSignature=True;
            else:
                print("Error \n")
            
            GenerateComment2(m_SigDef['DataType'],m_SigDef['VarName'],CSec[core][SignalHighestAsilLevel],HSec[core][SignalHighestAsilLevel])


            ListOfData[core][SignalHighestAsilLevel].append((m_SigDef['VarName'],m_SigDef['hasInit'],m_SigDef['DataType'],m_SigDef['InitValue'],ExtendedInitSignature));

        GenerateSigDefInit(CSec[core], HSec[core],ListOfData[core],StaticForwadDeclarations[core]);

        for asil in AsilList:
            Write_SharedMem_Refs[core][asil].append("};\n")
            #Write_SharedMem_Refs[core][asil].append("#endif\n")
            Write_Local_Refs[core][asil].append("};\n")
            #Write_Local_Refs[core][asil].append("#endif\n")

         

        (CAdapter, HAdaper)=IpcAdapter
        SignalMgr_IPCAdapater.IPCAdapterCodeGen_Gen((CAdapter,HAdaper),core)


    for core in coreList:
        for asil in AsilList:

            temp=[]
            AddExtern_C(temp)
            for s in temp:
                CFile[asil].write(s)
                HFile.write(s)

            AddComment_Divsion(CFile[asil], "Pointers to access the data and its details for  " + core +" with asil "+asil)
            CFile[asil].write("extern const SigMgr_SharedMemoryItemDetail SigMgr_SharedMemoryItemDetails_"+core+"_"+asil+"[SigMgr_CoreSpecific_"+core+"_"+asil+"_MAX_SharedMem];\n");

            AddComment_Divsion(HFile, "Enum of variables written by intercore from " + core +" with asil "+asil)
            HFile_Types.write("\ntypedef enum {\n")
            for s in Write_SharedMem_EnumEtries[core][asil]:
                HFile_Types.write(s+",\n")
            HFile_Types.write("SigMgr_CoreSpecific_"+core+"_"+asil+"_MAX_SharedMem\n")
            HFile_Types.write("}SigMgr_CoreSpecific_"+core+"_"+asil+"_SharedMem;\n")
            
            AddComment_Divsion(HFile, "Enum of variables usd within  " + core +" with asil "+asil)
            HFile_Types.write("\ntypedef enum {\n")
            for s in Local_SharedMem_EnumEtries[core][asil]:
                HFile_Types.write(s+",\n")
            HFile_Types.write("SigMgr_CoreSpecific_"+core+"_"+asil+"_MAX_CoreLocal\n")
            HFile_Types.write("}SigMgr_CoreSpecific_"+core+"_"+asil+"_CoreLocal;\n")

            temp=[]
            CloseExtern_C(temp)
            for s in temp:
                CFile[asil].write(s)
                HFile.write(s)



            

    H_Linker_Shared.write("\n/* Lookup table sections */\n")
    for core in coreList:
        HFile.write("\n\n#ifdef BUILD_"+core +"\n\n")        
        for asil in AsilList:
            CFile[asil].write("\n\n#ifdef BUILD_" + core+"\n\n")

            temp=[]
            AddExtern_C(temp)
            for s in temp:
                CFile[asil].write(s)
                HFile.write(s)

            AddComment_Divsion(CFile[asil], "Shared Memory : Written by core :: " + core)
            for s in Write_SharedMem_Defs[core][asil]:
                CFile[asil].write(s)
            

            if(Write_SharedMem_Refs_Count[core][asil] > 0):                
                AddComment_Divsion(CFile[asil], "Pointer to Shared Memory data :: " + core)                
                for s in Write_SharedMem_Refs[core][asil]:
                    CFile[asil].write(s)
            else:
                AddComment_Divsion(CFile[asil], "No data to Shared Memory data from :: " + core)

            

            #Write the DataDeclarations
            AddComment_Divsion(CFile[asil], "Core Local data :: " + core)
            for s in Data_Declaration[core][asil]:
                CFile[asil].write(s)

            if(Write_Local_Refs_Count[core][asil] > 0):
                AddComment_Divsion(CFile[asil], "Core Local data Refs:: " + core)
                for s in Write_Local_Refs[core][asil]:
                    CFile[asil].write(s)
            else:
                AddComment_Divsion(CFile[asil], "No data for Core Local data Refs:: " + core)
            

            AddComment_Divsion(CFile[asil], "Other RAM structures  data :: " + core)
            for s in RamMetaData_Declaration[core][asil]:
                CFile[asil].write(s)

            AddComment_Divsion(CFile[asil], "Const Lookup data :: " + core)
            for s in ROMMetaData_Declaration[core][asil]:
                CFile[asil].write(s)


            for s in StaticForwadDeclarations[core][asil]:
                CFile[asil].write(s)

            for s in CSec[core][asil]:
                CFile[asil].write(s)

            for s in DefinesSec[core][asil]:
                HFile.write(s)
            
            for s in TypesSec[core][asil]:
                HFile.write(s)

            for s in HSec[core][asil]:
                HFile.write(s)

            temp=[]
            CloseExtern_C(temp)
            for s in temp:
                CFile[asil].write(s)
                HFile.write(s)

            CFile[asil].write("\n\n#endif\n\n")
        HFile.write("\n\n#endif\n\n")

        for asil in AsilList:
            x="#ifdef BUILD_"+core +"\n"
            H_Linker_Shared.write(x)
            x="    "+"SIGMGR_SECTION_SHARED_LOOKUP_REF_TABLE_"+core+"_"+asil+"\t\t: {}  > SIGMGR_MEM_MAP_SHARED_LOOKUP_RREFTABLE_"+core+"_"+asil+" \n"
            H_Linker_Shared.write(x)
            x="    "+"SIGMGR_SECTION_LOCAL_LOOKUP_REF_TABLE_"+core+"_"+asil+"\t\t: {}  > SIGMGR_CORELOCAL_SECTION \n"
            H_Linker_Shared.write(x)
            H_Linker_Shared.write("#else\n")
            x="    "+"SIGMGR_SECTION_SHARED_LOOKUP_REF_TABLE_"+core+"_"+asil+"\t\t (NOINIT) : {}  > SIGMGR_MEM_MAP_SHARED_LOOKUP_RREFTABLE_"+core+"_"+asil+" \n"
            H_Linker_Shared.write(x)
            H_Linker_Shared.write("#endif\n")

    H_Linker_Shared.write("\n/* Data variable location sections */\n\n\n")
    for asil in AsilList:        

        for (s,c) in LocalData_Data_SectionDefs[asil]:
            x="    "+s+"\t\t: {}  > SIGMGR_CORELOCAL_SECTION \n"
            H_Linker_Local.write(x)

        for (s,c) in MultiCore_Shared_Data_SectionDefs[asil]:
            H_Linker_Shared.write("#ifdef BUILD_"+c +"\n")
            x="    "+s+"\t\t: {}  > SIGMGR_MEM_MAP_MULTICORESHARED_"+c+"_"+asil+" \n"
            H_Linker_Shared.write(x)
            H_Linker_Shared.write("#else\n")
            x="    "+s+"\t\t (NOINIT) : {}  > SIGMGR_MEM_MAP_MULTICORESHARED_"+c+"_"+asil+" \n"
            H_Linker_Shared.write(x)
            H_Linker_Shared.write("#endif\n")
            
    
    


def GenerateSignalData(ExcelFilePath,COutputPath,HOutputPath,IpcAdapter,Linker_SharedSections,Linker_LocalSections,GenTypesOutputPath):

    #Open handles for C file and H file output
    CFile=dict([(asil, None) for asil in AsilList])

    for asil in AsilList:
        CFile[asil]=open(COutputPath[asil],"w")
    HFile=open(HOutputPath,"w")
    HFile_Types=open(GenTypesOutputPath,"w")

    GenerateIncludeGaurds(HFile,"SIGDEF")
    GenerateIncludeGaurds(HFile_Types,"SIGTYPES")

    AddHFileHeaders(HFile)
    for asil in AsilList:
        AddCFileHeaders(CFile[asil])

    H_Linker_Local=open(Linker_LocalSections,"w")
    H_Linker_Shared=open(Linker_SharedSections,"w")



    g_SigData=ProcessSheet(ExcelFilePath)
    GenerateCode(g_SigData,CFile, HFile,IpcAdapter,(H_Linker_Local,H_Linker_Shared),HFile_Types)



    CloseIncludeGaurds(HFile)
    CloseIncludeGaurds(HFile_Types)

    #close the file handles
    for asil in AsilList:
        CFile[asil].close();
    HFile.close();

    H_Linker_Local.close();
    H_Linker_Shared.close();





if __name__ == '__main__':
    CurrentPath=os.path.dirname(os.path.realpath(__file__))
    (CAdapter,HAdaper)=SignalMgr_IPCAdapater.IPCAdapterCodeGen_Setup(CurrentPath)
    ExcelFilePath=Path(os.path.join(CurrentPath,"./../../","Fisker_L2H5010_IPC_SignalDef.xlsm"))
    C_Outpath=dict([(asil, "") for asil in AsilList])
    for asil in AsilList:
        C_Outpath[asil]=Path(os.path.join(CurrentPath,"./../gen/","SignalDef_"+asil+".c"))
    GenTypesOutputPath=Path(os.path.join(CurrentPath,"./../gen/","SignalGenTypes.h"))
    HOutputPath=Path(os.path.join(CurrentPath,"./../gen/","SignalDef.h"))
    Linker_SharedSections=Path(os.path.join(CurrentPath,"./../../../main_domain/j721e/","SignalMgrSharedSectionDefs.lds"))
    Linker_LocalSections=Path(os.path.join(CurrentPath,"./../../../main_domain/j721e/","SignalMgrLocalSectionDefs.lds"))
    GenerateSignalData(ExcelFilePath,C_Outpath,HOutputPath,(CAdapter,HAdaper),Linker_SharedSections,Linker_LocalSections,GenTypesOutputPath)
    SignalMgr_IPCAdapater.IPCAdapterCodeGen_Close((CAdapter, HAdaper))