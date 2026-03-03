import pandas as pd
from numpy import *
from ErrorMgrCommon import coreList,AsilList,CoreDefEnums,ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE,User_Cols_ErrorDefSheet,User_Cols_FidSheet,User_Cols_RESSheet , CheckAsilDependecy
import warnings
import re
import sys

def EliminateFloatPart(inp):
    if '.' in inp:
        inp=inp.split('.',1)[0]
    return inp

def Parse_Fid_Sheet(ExcelFilePath):

    Fid_Asil_List=dict([(asil, []) for asil in AsilList])

    # Open the excel
    DataDefworkbook = pd.read_excel(ExcelFilePath, sheet_name='FIDDef', usecols=User_Cols_FidSheet,engine='openpyxl');
    DataDefworkbook.head()
    (rows, col) = DataDefworkbook.shape

    for i in range(0, rows):
        FID=" Blank "
        FID_ASIL=' Blank '
        try:
            FID = str(DataDefworkbook['FID'].loc[i]).strip()
            FID_ASIL = str((DataDefworkbook['ASIL'].loc[i])).strip()
            Fid_Asil_List[FID_ASIL].append(FID)
        except KeyError:
            print("Error Parsing FID Sheet row:" + str(i) +" Fid:"+FID+" FidAsil::"+FID_ASIL)


    return Fid_Asil_List;

def Parse_RES_Sheet(ExcelFilePath):

    RES_ASIL_List=dict([(asil, []) for asil in AsilList])
    DEG_REASONS_List=dict([(asil, []) for asil in AsilList])

    # Open the excel
    DataDefworkbook = pd.read_excel(ExcelFilePath, sheet_name='RES_DEF', usecols=User_Cols_RESSheet,engine='openpyxl');
    DataDefworkbook.head()
    (rows, col) = DataDefworkbook.shape

    #Forward fill since there are merged cells
    DataDefworkbook.loc[:,['Feature','ASIL']] = DataDefworkbook.loc[:,['Feature','ASIL']].ffill(axis=0)
    for i in range(0, rows):
        try:
            RES = str(DataDefworkbook['Feature'].loc[i]).strip()
            RES_ASIL = str((DataDefworkbook['ASIL'].loc[i])).strip()
            DEG_REASONS = str((DataDefworkbook['Degradation Reasons'].loc[i])).strip()
            if(RES != 'nan'):
                RES_ASIL_List[RES_ASIL].append(RES) if RES not in RES_ASIL_List[RES_ASIL] else RES_ASIL_List[RES_ASIL]
            if (DEG_REASONS != 'nan'):
                DEG_REASONS_List[RES_ASIL].append(DEG_REASONS) if DEG_REASONS not in DEG_REASONS_List[RES_ASIL] else DEG_REASONS_List
        except KeyError:
            print("Error Parsing RES Sheet")


    return (RES_ASIL_List,DEG_REASONS_List);

def CheckString_CoreList(tstStr):
    try:
        if(not tstStr in coreList):
            raise Exception("Error: Invalid Core  " + tstStr)
    except Exception  as e:
            print(e)


def CheckStringFor_InvalidChars(tstStr):
    try:
        InvalidChars=[' ','-',')','(']
        for invalid_char in InvalidChars:
            if tstStr.count(invalid_char):
                raise Exception("Error: Space in string    " + tstStr)
    except Exception  as e:
            print(e)

    try:
        regex = '^[A-Za-z_][A-Za-z0-9_]*'
        if(not re.search(regex, tstStr)):
            raise Exception("Error: Invalid Character in String   " + tstStr)
    except Exception  as e:
            print(e)
        
    
    

def CheckDuplicateDefintions(tstStr,tstList):
    try:
        if tstStr in tstList:
            raise Exception("Error: Duplicate Entry    " + tstStr)
    except Exception  as e:
            print(e)


def ReadExcelFileVersion(ExcelFilePath):
    warnings.simplefilter(action='ignore', category=UserWarning)
    warnings.simplefilter(action='ignore', category=FutureWarning)
    DataDefworkbook = pd.read_excel(ExcelFilePath, sheet_name='Gen_History', usecols='A:F',engine='openpyxl')
    DataDefworkbook.head()
    (rows, col) = DataDefworkbook.shape
    long_version=str(DataDefworkbook['No'].loc[rows-1]).strip()+"_"+str(DataDefworkbook['Date'].loc[rows-1]).strip()+"_"+str(DataDefworkbook['Version'].loc[rows-1]).strip()
    short_version=str(DataDefworkbook['Version'].loc[rows-1]).strip()
    return (long_version,short_version)

def ParseErrorManagerExcelfile(ExcelFilePath):
    warnings.simplefilter(action='ignore', category=UserWarning)
    warnings.simplefilter(action='ignore', category=FutureWarning)
    GErrorList = dict([(core, dict([(asil, []) for asil in AsilList])) for core in coreList])
    SafeStateList = [];
    ErrCountByAsilLevel = dict([(asil, 0) for asil in AsilList])
    DtcStruct = dict([(asil, []) for asil in AsilList])


    ConsistenctCheck_ErrorEnumList=[]


    #Read the FIDs
    Fid_Asil_List=Parse_Fid_Sheet(ExcelFilePath)
    RES_Details=Parse_RES_Sheet(ExcelFilePath)


    # Open the excel
    DataDefworkbook = pd.read_excel(ExcelFilePath, sheet_name='ErrorDef', usecols=User_Cols_ErrorDefSheet,engine='openpyxl');
    DataDefworkbook.head()
    (Errorrows, col) = DataDefworkbook.shape


    Fid_ErrorDependeny_Failures =[]
    Res_ErrorDependency_Failures=[]
    
    for i in range(0, Errorrows):
        try:
            ErrorEnum = str(DataDefworkbook['ErrorEnum'].loc[i]).strip()
            MaturationTime_ms = str(int(DataDefworkbook['MaturationTime(ms)'].loc[i])).strip()
            DematurationTime_ms = str(int(DataDefworkbook['DematurationTime(ms)'].loc[i])).strip()
            Description = str(DataDefworkbook['Description'].loc[i]).strip()
            Rating = str(DataDefworkbook['ASIL'].loc[i]).strip()
            SenderCore = str(DataDefworkbook['SenderCore'].loc[i]).strip()
            SafeStates = str(DataDefworkbook['SafeState'].loc[i]).strip().split(",")
            DemEvent = str(DataDefworkbook['DEMEvent_0x'].loc[i]).strip()
            DTC = str(DataDefworkbook['DTC_0x'].loc[i]).strip()
            DTC_LOW = str(DataDefworkbook['DTC_LOW_0x'].loc[i]).strip()
            ExtendedErrorId = str(DataDefworkbook['ExtendedErrorId_0x'].loc[i]).strip()
            SafeState_CurrentError_List=[]
            for SSState in SafeStates:
                SSStateStripped=SSState.strip().lower()
                if(SSStateStripped != None) and (SSStateStripped != "") and (SSStateStripped != "nan"):
                    if (SSStateStripped not in SafeStateList):
                        #print(SSStateStripped)
                        SafeStateList.append(SSStateStripped)
                        CheckStringFor_InvalidChars(SSStateStripped)
                    if(SSStateStripped not in SafeState_CurrentError_List):
                        SafeState_CurrentError_List.append(SSStateStripped)
            if (DemEvent == "nan"):
                DemEvent = '0'
            DemEvent = EliminateFloatPart(DemEvent)
            if (DTC_LOW == "nan"):
                DTC_LOW = '0'
            DTC_LOW = EliminateFloatPart(DTC_LOW)
            if (DTC == "nan"):
                DTC = '0'
            DTC = EliminateFloatPart(DTC)
            if (ExtendedErrorId == "nan"):
                ExtendedErrorId = '0'
            ExtendedErrorId = EliminateFloatPart(ExtendedErrorId)


            CheckDuplicateDefintions(ErrorEnum.lower(),ConsistenctCheck_ErrorEnumList)
            ConsistenctCheck_ErrorEnumList.append(ErrorEnum.lower())

            #Check if any of these strings read are malformed
            CheckStringFor_InvalidChars(ErrorEnum)
            CheckStringFor_InvalidChars(Rating)
            CheckString_CoreList(SenderCore)            

            try:
            #Dictionary of FID
                Fid_Map = {}
                for fid_asil,fid_sublist in Fid_Asil_List.items():
                    for fid in fid_sublist:
                        #print("\n"+fid)
                        if not( fid in DataDefworkbook.columns):
                            print("Fid"+ fid+" column  is missing in Errordef sheet")
                        else:
                            FidSelection = str(DataDefworkbook[fid].loc[i]).strip()
                            Fid_Map[FidSelection] = 0
                            if(FidSelection == '*' or FidSelection == 'x' or  FidSelection == 'X'):
                                Fid_Map.update({fid:1})
                                #make sure the ASIL rating of the FID matches that of Error:
                                if(CheckAsilDependecy(fid_asil,Rating) == False):
                                    dep_err=(fid,fid_asil,ErrorEnum,Rating)
                                    if(dep_err not in Fid_ErrorDependeny_Failures):
                                        Fid_ErrorDependeny_Failures.append(dep_err)
                                    #sys.stderr.write("Error :: FID "+fid+"with Asil Rating :-> "+fid_asil+" dependant on error "+ErrorEnum+ " with rating"+Rating+ "\n")
                            elif FidSelection == '' or FidSelection == 'nan' or FidSelection =='NA' or FidSelection =='TBD':
                                Fid_Map.update({fid: 0})
                            else:
                                print("Unrecognized selection on Fid :" + FidSelection + ":" + fid + ":" + str(i))
            except KeyError as e:
                print("Key Error reading FID value from ErrorDef :: " + str(fid))
                _debug=2

            # Dictionary of RES
            (RES_ASIL_List, DEG_REASONS_List) = RES_Details
            Features_Map ={}
            Reasons_Map = {}

            try:
                for res_asil,res_sublist in RES_ASIL_List.items():
                    for res in res_sublist:
                        #print("\n"+fid)
                        if not( res in DataDefworkbook.columns):
                            print(res+" reason is missing in ErrorDef sheet")
                        else:
                            ResSelection = str(DataDefworkbook[res].loc[i]).strip()
                            if(ResSelection == '' or ResSelection == 'nan' or ResSelection =='NA' or ResSelection =='TBD'):
                                Ignore_Intentionally_unused=True;
                            elif(ResSelection  not in DEG_REASONS_List[res_asil]) :
                                print("Unrecognized value for Reason with the correct ASIL Classification :" + ResSelection + " in " +str(i))
                            else:
                                Features_Map.update({res: ResSelection})
                                Reasons_Map.update({ResSelection: 1})
                                if (CheckAsilDependecy(res_asil, Rating) == False):
                                    dep_err = (res,ResSelection, res_asil, ErrorEnum, Rating)
                                    if (dep_err not in Res_ErrorDependency_Failures):
                                        Res_ErrorDependency_Failures.append(dep_err)
                                    #sys.stderr.write(
                                    #    "Error: Res " + res + "with Asil Rating :-> " + res_asil + " dependant on error " + ErrorEnum + " with rating" + Rating + "\n")

                    #For all the reasons possibly in the same category that are not referenced: Set them to 0
                    for res2 in DEG_REASONS_List[res_asil]:
                        Reasons_Map.setdefault(res2,0)

            except KeyError as e:
                print("Key Error :: " + str(ResSelection))
                _debug=2
            
            str_DtcString=DTC+"_"+DTC_LOW+"_"+ExtendedErrorId
            str_DtcString=str_DtcString.lower()
            if(str_DtcString != '0_0_0'):
                if(str_DtcString not in DtcStruct[Rating]):
                    DtcStruct[Rating].append(str_DtcString)

            
            GErrorList[SenderCore][Rating].append((ErrorEnum, MaturationTime_ms, DematurationTime_ms, Description,
                                                   SafeState_CurrentError_List, (DemEvent, DTC, ExtendedErrorId, DTC_LOW),(Fid_Map,Reasons_Map,Features_Map)))
            ErrCountByAsilLevel[Rating] = ErrCountByAsilLevel[Rating] + 1;
        except Exception  as e:
            print(e)
            _debug=2


    for dep_err in Fid_ErrorDependeny_Failures:
        (err_fid, err_fid_asil, err_ErrorEnum, err_Rating)=dep_err
        print(
            "Error :: FID " + err_fid + "with Asil :-> " + err_fid_asil +  "depends on :-> " + err_ErrorEnum + " Asil:-> " + err_Rating + "\n")

    for dep_err in Res_ErrorDependency_Failures:
        (err_res,err_ResSelection, err_res_asil, err_ErrorEnum, err_Rating)=dep_err
        print(
            "Error: Res :->" + err_res + "with Asil :-> " + err_res_asil + " Reason:-> "+err_ResSelection+" depends on :-> " + err_ErrorEnum + " Asil:-> " + err_Rating + "\n")

    return (GErrorList,SafeStateList,ErrCountByAsilLevel,(Fid_Asil_List,RES_Details),DtcStruct)