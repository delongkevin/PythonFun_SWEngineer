import shutil
import pandas as pd
import os
import openpyxl
from openpyxl import load_workbook

from ErrorMgrCommon import coreList,AsilList,CoreDefEnums,ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE,ErrorMgr_enErrorStatus,ErrorMgr_GlobalPadding
from ErrorMgrCommon import Satellite_ModuleList, Agg_ModuleList ,GetMinUint32Satisfying_PackedAsBits


def UpdateSheet(fname,dataTowWrite,sheetName):
    book = load_workbook(fname)
    writer = pd.ExcelWriter(fname, engine='openpyxl')
    writer.book = book
    writer.sheets = dict((ws.title, ws) for ws in book.worksheets)
    dataTowWrite.to_excel(writer, sheetName,index=False)
    writer.save()

def AddSRPort_DTCOutputs(DataList,DtcStructInfo,ConstantDefs,sm):

    addDataInit = '{'
    for j in range(0, ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE):
        addDataInit += '0'
        if (j < ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE - 1):
            addDataInit += ','
    addDataInit += '}'

    #Dtc Data
    (stName,stDef,Count) = DtcStructInfo[0]
    InitVal="{"
    #Error Values
    for i in range(0,Count):
        InitVal += '0'
        if(i <Count -1):
            InitVal+=','
    InitVal += '}'

    #ConstantDefs.append(('Data_'+stName,stName,InitVal))
    DataList.append(['P_DtcData','Sender','','','','','','','','','','','','Data_'+stName,'',stName,InitVal,'RE_Periodic_'+sm,'','','Port for reading DTC Data'])
     
    #DTC Additional Data
    (stName,stDef,Count) = DtcStructInfo[1]
    InitVal="{"
    #Error Values
    for i in range(0,Count):
        InitVal += addDataInit
        if(i <Count -1):
            InitVal+=','
    InitVal += '}'
    #ConstantDefs.append(('Data_'+stName,stName,InitVal))
    DataList.append(['P_DtcData','Sender','','','','','','','','','','','','Data_'+stName,'',stName,InitVal,'RE_Periodic_'+sm,'','','Port for reading DTC Data'])
    

def AddSRData_ErrorCommMessages(DataList,ErrorInputList,ConstantDefs,sm,suffix,isReciever):

    stdata = '{'
    for j in range(0, ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE):
        stdata += '0'
        if (j < ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE - 1):
            stdata += ','
    stdata += '}'

    for stName,stDef,Count in ErrorInputList:
        InitVal="{0,0,{"
        #Error Values
        for i in range(0,Count):
            InitVal += '0'
            if(i <Count -1):
                InitVal+=','
        InitVal += '},{'
        #Padding  
        Padding_Count=ErrorMgr_GlobalPadding-(Count%ErrorMgr_GlobalPadding)
        if(Padding_Count < ErrorMgr_GlobalPadding):
            for i in range(0,Padding_Count):
                InitVal += '0'
                if(i <Padding_Count -1):
                    InitVal+=','
            InitVal += '},{'
        #Additional Data
        for i in range(0,Count):
            InitVal += stdata
            if(i <Count -1):
                InitVal+=','
        InitVal += '}}'

        ConstantDefs.append(('Data_'+stName,stName,InitVal))
        if(isReciever== True):
            DataList.append(['R_SatError','Receiver','','','','','','','','','','','','Data_'+stName,'',stName,InitVal,'RE_Periodic_'+sm,'','','Comments'])
        else:
            DataList.append(
                ['P_SatError', 'Sender', '', '','', '', '', '', '', '', '', '', '', 'Data_' + stName, '', stName,
                 '/Pkg_ErrorMgrAgg_'+suffix+'/Constant/init_Data_'+stName, 'RE_Periodic_' + sm,'','/Pkg_ErrorMgrAgg_'+suffix+'/PortInterfaces/R_SatError_SR', 'Comments'])

def UpdateAggSRTab(AsilRating,fhandle,sm,suffix,AggCommStList,SafeStateList,lenAsilErrors,DtcStructDefs):

    ConstantDefs=[]
    ErrorInputList=AggCommStList.copy()



    SR_Cols = ['Port_Name','Port_Interface_Type','Port_Interface_Name','Is_Service','Rx_Filter','Tx_Acknoledge/Timeout','End_to_End_Protection','Handle_Never_Received','Handle_Out_Of_Range','Handle_Timeout_Type','Enable_Update','Alive_Timeout','Mode_Group_Name',
'Element','Calibration_Access','Data_Type','Init_Value','Runnable_Name','Port_Access_MS','Port_Interface_Reference','Comments']
    SR_Sheet_Name='SR_Ports'
    DataList = []

    AddSRData_ErrorCommMessages(DataList,ErrorInputList,ConstantDefs,sm,suffix,True)
    AddSRPort_DTCOutputs(DataList,DtcStructDefs,ConstantDefs,sm)

    #Safe State Output
    (SN,SDef,SCount)=SafeStateList
    InitVal = "{"
    for i in range(0, SCount):
        InitVal += '0'
        if (i < SCount - 1):
            InitVal += ','
    InitVal+='}'
    #ConstantDefs.append(('SafeStateOp','SafeStateOpDef', InitVal))  Not needed for sender port
    DataList.append(
        ['P_SafeState', 'Sender', '','', '', '', '', '', '', '', '', '', '', 'SafeStateOp', '', 'SafeStateOpDef', InitVal,
          'RE_Periodic_' + sm, '','', 'Safe State Outputs'])

    InitVal = "{"
    for i in range(0, GetMinUint32Satisfying_PackedAsBits(lenAsilErrors)):
        InitVal += '0'
        if (i < lenAsilErrors - 1):
            InitVal += ','
    InitVal+='}'
    DataList.append(
        ['P_Errors_'+AsilRating, 'Sender', '', '', '', '', '', '', '', '', '', '', '', 'Errors_'+AsilRating, '', 'ErrorListArr_'+AsilRating+ '[' + str(GetMinUint32Satisfying_PackedAsBits(lenAsilErrors)) + ']',
         InitVal,
         'RE_Periodic_' + sm, '', '', 'Status of Errors'])


    df = pd.DataFrame(DataList, columns=SR_Cols)
    UpdateSheet(fhandle, df, SR_Sheet_Name)

    return ConstantDefs

def UpdateSatSRTab(fHandle,CommMsgList,suffix,sm):
    SR_Cols = ['Port_Name', 'Port_Interface_Type','Port_Interface_Name', 'Is_Service', 'Rx_Filter', 'Tx_Acknoledge/Timeout',
               'End_to_End_Protection', 'Handle_Never_Received', 'Handle_Out_Of_Range', 'Handle_Timeout_Type',
               'Enable_Update', 'Alive_Timeout', 'Mode_Group_Name',
               'Element', 'Calibration_Access', 'Data_Type', 'Init_Value', 'Runnable_Name','', 'Port_Interface_Reference',
               'Comments']
    SR_Sheet_Name = 'SR_Ports'
    DataList=[]

    SatSpecificList=[]
    for stName,stDef,Count in  CommMsgList:
        if suffix in stName:
            SatSpecificList.append((stName,stDef,Count))

    AddSRData_ErrorCommMessages(DataList,SatSpecificList,[],sm,suffix,False)

    df = pd.DataFrame(DataList, columns=SR_Cols)
    UpdateSheet(fHandle, df, SR_Sheet_Name)


def UpdateCSPorTab(af,dtcwithlowdefs,suffix):
    CS_Cols = ['Port_Name', 'Port_Interface_Type', 'Port_Interface_Name', 'Is_Service',
               'Operations_Prototypes', 'Operations_Argument_Direction', 'Operations_Arguments_Data_Type',
               'Operations_Arguments_Name', 'Application_Errors_Code', 'Application_Errors_Error',
               'Runnable_Name', 'Port_Interface_Reference', 'Comments']
    CS_Sheet_Name = 'CS_Ports'
    DataList=[]
    for dtcdef in dtcwithlowdefs:
        DataList.append(
            ['R_'+dtcdef, 'Client', '', 'Yes', 'dTCinfo_v', '', '', '', '', '', 'RE_Periodic_ErrorMgrAgg_'+suffix,
             '/PortInterfaces/IF_dataDTC_CS', ''])
    df = pd.DataFrame(DataList, columns=CS_Cols)
    UpdateSheet(af, df, CS_Sheet_Name)

def UpdateSatCSTab(fHandle,sm,suffix,UseIpc):
    CS_Cols = ['Port_Name','Port_Interface_Type','Port_Interface_Name','Is_Service',
               'Operations_Prototypes','Operations_Argument_Direction','Operations_Arguments_Data_Type',
               'Operations_Arguments_Name','Application_Errors_Code','Application_Errors_Error',
               'Runnable_Name','Port_Interface_Reference','Comments']
    CS_Sheet_Name='CS_Ports'
    DataList=[['P_Error','Server','','','ReportErrorStatus'+suffix,'IN','ErrorMgr_enErrorNo','err','E_NOK','1','','','']]
    DataList.append(['P_Error', 'Server', '', '', 'ReportErrorStatus'+suffix, 'IN', 'ErrorMgr_enErrorStatus', 'errStatus', 'E_NOK','1',
                '', '', ''])
    DataList.append(
        ['P_Error', 'Server', '', '', 'ReportErrorStatus'+suffix, 'IN', 'ErrorMgr_stAddData', 'addData', 'E_NOK','1',
         '', '', ''])
    if(UseIpc == True):
        DataList.append(
            ['R_IPC', 'Client', '', '', 'IPC_Write_v', '', '', '', '',
             '',
             'RE_Periodic_'+sm, '/IPC_SWC/PortInterfaces/IF_P_IPC_CS', 'Clien connection to connect to IPC'])


    df = pd.DataFrame(DataList, columns=CS_Cols)
    UpdateSheet(fHandle, df, CS_Sheet_Name)

def UpdateComponentType(fHandle,ComponentName):
    Comp_Cols = ['SWC_Name', 'SWC_Type', 'Package_Name', 'Data_Type_Mapping_Set', 'Data_Type_Mapping_Set_Ref', 'Comments',
                 ]
    Component_Sheet_Name='Component_Type'
    DataList=[[ComponentName,'APPSWC','Pkg_'+ComponentName,'','','Error Manager Satellite']]
    df = pd.DataFrame(DataList, columns=Comp_Cols)
    UpdateSheet(fHandle, df, Component_Sheet_Name)

def UpdateSatRunnableTab(fHandle,ComponentName,suffix):
    Runnable_Cols = ['Runnable_Name','Invoked_Concurrently','Trigger','Trigger_Parameter','Event_Name','Parameter_Access_Element','Parameter_Access_Name','Inter_Runnable_Variables','Communication','Access_Mode','Calibration_Access','Data_Type','Init_Value','Comments'
 ]
    Component_Sheet_Name='Runnables'
    DataList=[['RE_Periodic_'+ComponentName,'FALSE','Timing','10ms','','','','','','','','','','Periodic Runnable of Satellite']]
    DataList.append(['RE_'+'ReportErrorStatus'+suffix, 'TRUE', 'OIT', 'P_Error/ReportErrorStatus'+suffix, '', '', '', '', '', '', '', '', '',
                 'Server Runnable for handling the error reporting'])
    DataList.append(['RE_Init_' + ComponentName, 'FALSE', 'Init', '', '', '', '', '', '', '', '', '', '',
                 'Init Runnable'])
    df = pd.DataFrame(DataList, columns=Runnable_Cols)
    UpdateSheet(fHandle, df, Component_Sheet_Name)

def UpdateConstantDefsTab(fHandle,CDefs):
    Runnable_Cols = ['Name', 'Data_Type', 'Init_Value']
    Component_Sheet_Name = 'Constants'
    DataList=[]
    for elementName,datType,InitVal in CDefs:
        DataList.append(['init_' + elementName, datType, InitVal])
    df = pd.DataFrame(DataList, columns=Runnable_Cols)
    UpdateSheet(fHandle, df, Component_Sheet_Name)

def UpdateAggRunnableTab(fHandle,ComponentName):
    Runnable_Cols = ['Runnable_Name','Invoked_Concurrently','Trigger','Trigger_Parameter','Event_Name','Parameter_Access_Element','Parameter_Access_Name','Inter_Runnable_Variables','Communication','Access_Mode','Calibration_Access','Data_Type','Init_Value','Comments'
 ]
    Component_Sheet_Name='Runnables'
    DataList=[['RE_Periodic_'+ComponentName,'FALSE','Timing','10ms','','','','','','','','','','Periodic Runnable of Satellite']]
    DataList.append(['RE_Init_' + ComponentName, 'FALSE', 'Init', '', '', '', '', '', '', '', '', '', '',
                 'Init Runnable'])
    df = pd.DataFrame(DataList, columns=Runnable_Cols)
    UpdateSheet(fHandle, df, Component_Sheet_Name)


def AddImplementtionDataTypeDef(fHandle,ValueDefinedEnumLists,OpenValueEnumLists,sdef,NewDataTypes):
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

    #Add the enum definitions with fixed values
    if ValueDefinedEnumLists != None:
        for (enumname,en) in ValueDefinedEnumLists:
            first_element=True;
            enlist='['
            #print(en)
            for val,count in en:
                if(first_element == False):
                    enlist+=' '
                else:
                    first_element=False
                enlist += str(count)+": \'"+val+"\'"
            enlist+=']'
            DataList.append([enumname,'uint32',enlist])

    #Add the enum definitions for open Values Enum entries
    if OpenValueEnumLists != None:
        for (enumname,en) in OpenValueEnumLists:
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


def ARXMLGen_Agg_UpdateDataTypes(sf,SSList,CommList,SafeStateStDef,ErrorMgr_stAddData_Def,Dtypes,DtcStructDef):

    mComMsgStructs_updated=CommList.copy()

    mComMsgStructs_updated.append(SafeStateStDef)
    mComMsgStructs_updated.append(ErrorMgr_stAddData_Def)
    mComMsgStructs_updated+=DtcStructDef

    ValueDefinedEnumLists= None
    OpenValueEnumLists=   [('ErrorMgr_enSafeStates', SSList),
                                             ('ErrorMgr_enErrorStatus', ErrorMgr_enErrorStatus)]    

    AddImplementtionDataTypeDef(sf, ValueDefinedEnumLists,OpenValueEnumLists, mComMsgStructs_updated,Dtypes)


def ARXMLGen_Satellite_UpdateDataTypes(OutputPath,ErrList, SSList,mComMsgStructs,ErrorMgr_stAddData_Def,NewDataTypes):
    mComMsgStructs_updated = mComMsgStructs.copy()
    mComMsgStructs_updated.append(ErrorMgr_stAddData_Def)

    ValueDefinedEnumLists=[('ErrorMgr_enErrorNo',ErrList)]
    OpenValueEnumLists=   [('ErrorMgr_enSafeStates',SSList),
                                            ('ErrorMgr_enErrorStatus',ErrorMgr_enErrorStatus)]                                       

    AddImplementtionDataTypeDef(OutputPath,ValueDefinedEnumLists,OpenValueEnumLists,mComMsgStructs_updated,NewDataTypes)

def ARXMLGen_Aggregator_Create(TemplatePath,OutputPath):
    #Copy the template file
    shutil.copy2(TemplatePath,OutputPath);


def GenerateArxml(pEnumList,CurrentPath,MaxDebugBytes,ComMsgStructs,DataTypes,DiagDefDicts,DtcStructDefs):
    #Handle Satellite Arxml Generation
    (ErrEnumList, SafeStateList,ErrEnumAsilBasedList,ErrEnumAsilAndCoreWise)=pEnumList

    DataTypes.append(('uint8','AdditionalData_arr','AdditionalData_arr['+str(ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE)+']',ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE))
    ErrorMgr_stAddData_OpStruct=['AdditionalData_arr AdditionalData']
    ErrorMgr_stAddData_Def=('ErrorMgr_stAddData', ErrorMgr_stAddData_OpStruct, ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE)


    Satellitelists= list([(os.path.join(CurrentPath,".\\..\\gen\\"+mod+".xlsx"),(mod,core,Rat,UseIpc)) for mod,core,Rat,UseIpc in Satellite_ModuleList])
    for sf,sg in Satellitelists:
        sm, core,asil, UseIpc = sg
        suffix=sm.split('_',1)[1]
        ARXMLGen_Satellite_Create("arxml_template_all_features.xlsx", sf)
        UpdateComponentType(sf,sm)
        ARXMLGen_Satellite_UpdateDataTypes(sf, ErrEnumAsilAndCoreWise[core][asil], SafeStateList,ComMsgStructs[asil],ErrorMgr_stAddData_Def,DataTypes)
        UpdateSatCSTab(sf,sm,suffix,UseIpc)
        if( UseIpc == False):
            UpdateSatSRTab(sf,ComMsgStructs[asil],suffix,sm)
        UpdateSatRunnableTab(sf,sm,suffix)


    #New Data Types applicable to aggregator : Safe State Defs, Additional Data Struct
    DataTypes.append(('uint8','SafeStateActive_arr','SafeStateActive_arr['+str(len(SafeStateList))+']',len(SafeStateList)))


    SafeStateOpStruct=['SafeStateActive_arr SafeStateActive']
    SafeStateStDef=('SafeStateOpDef', SafeStateOpStruct, len(SafeStateList))




    (DemDefs, DtcDefs, ExDtcDataDefs, DTCWithLowDataDefs) = DiagDefDicts

    Agglists = list(
        [(os.path.join(CurrentPath, ".\\..\\gen\\" + mod + ".xlsx"), (mod,Rat)) for mod,Rat in Agg_ModuleList])
    for af,ag in Agglists:
        am,asil=ag
        len_asil_errors=len(ErrEnumAsilBasedList[asil])-1  #-1 because the max value is included in the def
        if(len_asil_errors == 0):
            #since autosar needs atleast one element
            len_asil_errors=1
        suffix = am.split('_', 1)[1]
        ARXMLGen_Aggregator_Create("arxml_template_all_features.xlsx", af)
        UpdateComponentType(af,am)
        App_Dtypes = DataTypes.copy();
        App_Dtypes.append(('uint32', 'ErrorListArr_' + asil,
                           'ErrorListArr_' + asil + '[' + str(GetMinUint32Satisfying_PackedAsBits(len_asil_errors)) + ']', str(GetMinUint32Satisfying_PackedAsBits(len_asil_errors))))
        ARXMLGen_Agg_UpdateDataTypes(af,SafeStateList,ComMsgStructs[asil],SafeStateStDef,ErrorMgr_stAddData_Def,App_Dtypes,DtcStructDefs[asil])
        ConstDefs=UpdateAggSRTab(asil,af,am,suffix,ComMsgStructs[asil],SafeStateStDef,len_asil_errors,DtcStructDefs[asil])
        UpdateConstantDefsTab(af,ConstDefs)
        UpdateAggRunnableTab(af,am)
        UpdateCSPorTab(af,DTCWithLowDataDefs[asil],suffix)
