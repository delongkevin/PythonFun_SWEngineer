import shutil
import pandas as pd
import os
import openpyxl
from openpyxl import load_workbook

from ErrorMgrCommon import coreList,AsilList,CoreDefEnums,ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE,ErrorMgr_enErrorStatus
from ErrorMgrCommon import Deg_ModuleList , GetMinUint32Satisfying_PackedAsBits


def UpdateSheet(fname,dataTowWrite,sheetName):
    book = load_workbook(fname)
    writer = pd.ExcelWriter(fname, engine='openpyxl')
    writer.book = book
    writer.sheets = dict((ws.title, ws) for ws in book.worksheets)
    dataTowWrite.to_excel(writer, sheetName,index=False)
    writer.save()

def Update_Deg_CSSheet(fHandle,sm):
    CS_Cols = ['Port_Name','Port_Interface_Type','Port_Interface_Name','Is_Service',
               'Operations_Prototypes','Operations_Argument_Direction','Operations_Arguments_Data_Type',
               'Operations_Arguments_Name','Application_Errors_Code','Application_Errors_Error',
               'Runnable_Name','Port_Interface_Reference','Comments']
    CS_Sheet_Name='CS_Ports'
    DataList=[]
    DataList.append(
            ['R_IPC', 'Client', '', '', 'IPC_Write_v', '', '', '', '',
             '',
             'RE_Periodic_'+sm, '/IPC_SWC/PortInterfaces/IF_IpcTxData', 'Clien connection to connect to IPC'])


    df = pd.DataFrame(DataList, columns=CS_Cols)
    UpdateSheet(fHandle, df, CS_Sheet_Name)


def Update_Deg_SenderReciever(ModuleAsilLevel,fhandle,sm,CombinedErrorInputApplicable,lenErrorOutput_byAsil,len_CombinedList):

    ConstantDefs=[]

    Fid_ErrorInputApplicable,Res_ErrorApplicable=CombinedErrorInputApplicable
    len_FidList,len_ResList=len_CombinedList

    SR_Cols = ['Port_Name','Port_Interface_Type','Port_Interface_Name','Is_Service','Rx_Filter','Tx_Acknoledge/Timeout','End_to_End_Protection','Handle_Never_Received','Handle_Out_Of_Range','Handle_Timeout_Type','Enable_Update','Alive_Timeout','Mode_Group_Name',
'Element','Calibration_Access','Data_Type','Init_Value','Runnable_Name','Port_Access_MS','Port_Interface_Reference','Comments']
    SR_Sheet_Name='SR_Ports'
    DataList = []

    #inputs
    for asil_isApplicable,isApplicable in Fid_ErrorInputApplicable.items():
        #if that partiuclar asil input is needed as an input for calculation of FID
        if (isApplicable == True) or (Res_ErrorApplicable[asil_isApplicable] == True):
            InitVal = "{"
            for i in range(0, lenErrorOutput_byAsil[asil_isApplicable]):
                InitVal += '0'
                if (i < lenErrorOutput_byAsil[asil_isApplicable] - 1):
                    InitVal += ','
            InitVal+='}'
            DataList.append(
                ['R_Errors_'+asil_isApplicable, 'Receiver', '', '', '', '', '', '', '', '', '', '', '', 'Errors_'+asil_isApplicable, '', '',
                 InitVal,
                 'RE_Periodic_' + sm, '', '/Pkg_ErrorMgrAgg_1_0_'+asil_isApplicable+"/PortInterfaces/P_Errors_"+asil_isApplicable+"_SR", 'Input'])

    #Outputs

    if(len_FidList > 0):
        InitVal = "{"
        for i in range(0, GetMinUint32Satisfying_PackedAsBits(len_FidList)):
            InitVal += '0'
            if (i < len_FidList - 1):
                InitVal += ','
        InitVal += '}'
        DataList.append(
            ['P_FID_Output_' + ModuleAsilLevel, 'Sender', '', '', '', '', '', '', '', '', '', '', '', 'FID_' + ModuleAsilLevel, '',
            'FIDOutputArr_' + ModuleAsilLevel + '[' + str(GetMinUint32Satisfying_PackedAsBits(len_FidList)) + ']',
            InitVal,
            'RE_Periodic_' + sm, '', '', 'Output'])

    if(len_ResList > 0):
        InitVal = "{"
        for i in range(0, GetMinUint32Satisfying_PackedAsBits(len_ResList)):
            InitVal += '0'
            if (i < len_ResList - 1):
                InitVal += ','
        InitVal += '}'
        DataList.append(
            ['P_RES_Output_' + ModuleAsilLevel, 'Sender', '', '', '', '', '', '', '', '', '', '', '', 'RES_' + ModuleAsilLevel, '',
            'RESOutputArr_' + ModuleAsilLevel + '[' + str(GetMinUint32Satisfying_PackedAsBits(len_ResList)) + ']',
            InitVal,
            'RE_Periodic_' + sm, '', '', 'Output'])


    df = pd.DataFrame(DataList, columns=SR_Cols)
    UpdateSheet(fhandle, df, SR_Sheet_Name)

    return ConstantDefs


def UpdateComponentType(fHandle,ComponentName):
    Comp_Cols = ['SWC_Name', 'SWC_Type', 'Package_Name', 'Data_Type_Mapping_Set', 'Data_Type_Mapping_Set_Ref', 'Comments',
                 ]
    Component_Sheet_Name='Component_Type'
    DataList=[[ComponentName,'APPSWC','Pkg_'+ComponentName,'','','Error Manager Satellite']]
    df = pd.DataFrame(DataList, columns=Comp_Cols)
    UpdateSheet(fHandle, df, Component_Sheet_Name)

def Update_DegRunnableTab(fHandle,ComponentName):
    Runnable_Cols = ['Runnable_Name','Invoked_Concurrently','Trigger','Trigger_Parameter','Event_Name','Parameter_Access_Element','Parameter_Access_Name','Inter_Runnable_Variables','Communication','Access_Mode','Calibration_Access','Data_Type','Init_Value','Comments'
 ]
    Component_Sheet_Name='Runnables'
    DataList=[['RE_Periodic_'+ComponentName,'FALSE','Timing','10ms','','','','','','','','','','Periodic Runnable of Satellite']]
    DataList.append(['RE_Init_' + ComponentName, 'FALSE', 'Init', '', '', '', '', '', '', '', '', '', '',
                 'Init Runnable'])
    df = pd.DataFrame(DataList, columns=Runnable_Cols)
    UpdateSheet(fHandle, df, Component_Sheet_Name)


def AddImplementtionDataTypeDef(fHandle,eDef,sdef,NewDataTypes):
    Impl_Cols = ['Implementation_Data_Types_Name', 'Data_Type', 'Enum', 'Struct', 'Void_Reference', 'Type_Reference',
                 'Comments']
    Impl_DefaultData = [
        ['BOOL', 'boolean', '', '', '', '', ''],
        ['UINT8', 'uint8', '', '', '', '', ''],
        ['UINT16', 'uint16', '', '', '', '', ''],
        ['UINT32', 'uint32', '', '', '', '', ''],
        ['UINT64', 'uint64', '', '', '', '', ''],
        ['SINT8', 'sint8', '', '', '', '', ''],
        ['SINT16', 'sint16', '', '', '', '', ''],
        ['SINT32', 'sint32', '', '', '', '', ''],
        ['FLOAT32', 'float32', '', '', '', '', ''],
        ['FLOAT64', 'float64', '', '', '', '', ''],
        ['ErrorMgr_ErrorField', 'uint8', '', '', '', '', ''],
    ]
    Impl_DataTypes_Sheet_ = 'Implementation_Data_Types'

    #additional Data Types
    DataList=Impl_DefaultData.copy();
    for base, ntype, ntypearrdef,count in NewDataTypes:
        DataList.append([ntypearrdef, base, '', '', '', '', ''])

    #Add the enDef
    for (enumname,en) in eDef:
        enlist='['
        count=0
        for val in en:
            if(count >0):
                enlist+=' '
            enlist += str(count)+": \'"+val+"\'"
            count+=1
        enlist+=']'
        DataList.append([enumname,'uint32',enlist])

    for (sname,sd,count) in sdef:
        sdlist='{\n'
        for val in sd:
            sdlist += ' '+val+";\n"
        sdlist+='}'
        DataList.append([sname,'','',sdlist])

    df= pd.DataFrame(DataList,columns=Impl_Cols)
    UpdateSheet(fHandle,df,Impl_DataTypes_Sheet_)


def ARXMLGen_Satellite_Create(TemplatePath,OutputPath):
    #Copy the template file
    shutil.copy2(TemplatePath,OutputPath);


def ARXMLGen_Agg_UpdateDataTypes(sf,Dtypes):
    AddImplementtionDataTypeDef(sf, [], [],Dtypes)


def ARXMLGen_Aggregator_Create(TemplatePath,OutputPath):
    #Copy the template file
    shutil.copy2(TemplatePath,OutputPath);


def DegManager_GenerateArxml(ErrEnumAsilBasedList,CurrentPath,CombinedErrorInputApplicable,OutputLengths):
    #Handle Satellite Arxml Generation
    (Fid_ErrorInputApplicable,Res_ErrorInputApplicable)=CombinedErrorInputApplicable
    (FidOutputLengths,RESOutputLengths)=OutputLengths

    DataTypes=[]
    lenErrorOutput_byAsil=dict([(asil, len(ErrEnumAsilBasedList[asil])) for asil in AsilList])
    for a in AsilList:
        if(lenErrorOutput_byAsil[a] > 1):
            #print("\n DebugPrint asil"+a+"::"+str(lenErrorOutput_byAsil[a]))
            lenErrorOutput_byAsil[a]=lenErrorOutput_byAsil[a]-1
            
    
    DegModlists = list(
        [(os.path.join(CurrentPath, ".\\..\\gen\\" + mod + ".xlsx"), (mod,Rat)) for mod,Rat in Deg_ModuleList])
    for af,ag in DegModlists:

        #Only if there is a FID in thas asil category only then
        am,asil=ag
        if (FidOutputLengths[asil] > 0) or (RESOutputLengths[asil] > 0):
            suffix = am.split('_', 1)[1]

            ARXMLGen_Aggregator_Create("arxml_template_all_features.xlsx", af)
            UpdateComponentType(af,am)
            App_Dtypes = DataTypes.copy();
            App_Dtypes.append(('uint32', 'ErrorListArr_' + asil,
                               'ErrorListArr_' + asil + '[' + str(GetMinUint32Satisfying_PackedAsBits(lenErrorOutput_byAsil[asil])) + ']', str(GetMinUint32Satisfying_PackedAsBits(lenErrorOutput_byAsil[asil]))))

            if(FidOutputLengths[asil] > 0):
                App_Dtypes.append(('uint32', 'FIDOutputArr_' + asil,
                               'FIDOutputArr_' + asil + '[' + str(GetMinUint32Satisfying_PackedAsBits(FidOutputLengths[asil])) + ']', str(GetMinUint32Satisfying_PackedAsBits(FidOutputLengths[asil]))))
            if(RESOutputLengths[asil] > 0):
                App_Dtypes.append(('uint32', 'RESOutputArr_' + asil,
                               'RESOutputArr_' + asil + '[' + str(GetMinUint32Satisfying_PackedAsBits(RESOutputLengths[asil])) + ']', str(GetMinUint32Satisfying_PackedAsBits(RESOutputLengths[asil]))))

            ARXMLGen_Agg_UpdateDataTypes(af,App_Dtypes)

            ConstDefs=Update_Deg_SenderReciever (asil,af,am,(Fid_ErrorInputApplicable[asil],Res_ErrorInputApplicable[asil]),lenErrorOutput_byAsil,(FidOutputLengths[asil],RESOutputLengths[asil]))

            Update_DegRunnableTab(af,am)
            Update_Deg_CSSheet(af,am)
