import pandas as pd
import os
import sys
from ErrorMgrCommon import coreList,AsilList,CoreDefEnums,ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE,User_Cols_ErrorDefSheet
from ErrorMgrCommon import GenerateIncludeGaurds,CloseIncludeGaurds,AddFileHeaders
import numpy as np


def createEmptyOutMatrix(ParsedEnumLists,fid_list):
    fid_Err_Mat=  dict([(fid,dict([(err, False) for err in ParsedEnumLists])) for fid in fid_list])
    Err_Fid_Mat=  dict([(err,dict([(fid, False) for fid in fid_list])) for err in ParsedEnumLists])
    return (fid_Err_Mat,Err_Fid_Mat)


def GetErrorIndex(ErrorEnum,max,dataworkbook):
    for index in range(0,max):
        readvalue = str(dataworkbook['ErrorEnum'].loc[index]).strip()
        if(("ErrorMgr_Error_"+readvalue) == ErrorEnum):
            return index
    print("\nError Enum not found : Something is messed up: Cannot generate"+ErrorEnum)
    return None

def GetOutputMatrix(ParsedEnumLists,fid_list,ExcelFilePath):
    (fid_Err_Mat,Err_Fid_Mat)=createEmptyOutMatrix(ParsedEnumLists,fid_list)
    DataDefworkbook = pd.read_excel(ExcelFilePath, sheet_name='ErrorDef', usecols=User_Cols_ErrorDefSheet , engine='openpyxl');
    (Errorrows, col) = DataDefworkbook.shape

    for ErrorEnum in ParsedEnumLists:
        err=GetErrorIndex(ErrorEnum,Errorrows,DataDefworkbook)
        for fid in fid_list:            
            value=str(DataDefworkbook[fid].loc[err]).strip()
            if(value == '*' or value == 'x' or  value == 'X'):
                fid_Err_Mat[fid][ErrorEnum]=True
                Err_Fid_Mat[ErrorEnum][fid]=True
    return (fid_Err_Mat,Err_Fid_Mat)


def GetOutputMatrix_Res(ParsedEnumLists,id_list,res_list,ExcelFilePath):
    (fid_Err_Mat,Err_Fid_Mat)=createEmptyOutMatrix(ParsedEnumLists,id_list)
    DataDefworkbook = pd.read_excel(ExcelFilePath, sheet_name='ErrorDef', usecols=User_Cols_ErrorDefSheet);
    (Errorrows, col) = DataDefworkbook.shape

    for ErrorEnum in ParsedEnumLists:
        err=GetErrorIndex(ErrorEnum,Errorrows,DataDefworkbook)
        for fid in id_list:
            for res_res in res_list:            
                value=str(DataDefworkbook[res_res].loc[err]).strip()
                if(value == fid.strip()):
                    fid_Err_Mat[fid][ErrorEnum]=True
                    Err_Fid_Mat[ErrorEnum][fid]=True
    return (fid_Err_Mat,Err_Fid_Mat)

def Write_Debug_OnlySatisfiedDependencies(mat,rows,columns,fd,prefix):
    fd.write("/*\n")
    for row in rows:
        fd.write(row +"  ::   ")
        for column in columns:
            if(mat[row][column] == True):
                fd.write(","+column)
        fd.write("\n")
    fd.write("*/\n")

def Write_Debug(mat,rows,columns,fd):
    fd.write("/*\n")
    fd.write("\t\t")
    for column in columns:
        fd.write(column)
    fd.write("\n")
    for row in rows:
        fd.write(row)
        for column in columns:
            fd.write("\t"+str(mat[row][column]))
        fd.write("\n")
    fd.write("*/\n")

def Write_TestMatrix(mat,rows,columns,fd,asil,str,rowmax,columnmax,prefix):

    if((len(columns)==0)  or (len (rows) == 0)):
        fd.write("#define "+prefix+"_DEGRADATION_TESTCASE_MATRIX_"+asil+"_INVALID    1 \n")
    fd.write("\n#ifndef "+prefix+"_DEGRADATION_TESTCASE_MATRIX_"+asil+"_INVALID\n")
    fd.write("\nbool_t TestErrorMap_"+str+"_"+asil+"_"+prefix+"["+rowmax+"]"+"["+columnmax+"] = { \n")
    for row in rows:
        fd.write("\t\t")
        for column in columns:
            if(mat[row][column] == True):
                fd.write("TRUE,")
            else:
                fd.write("FALSE,")
        fd.write("\n")
    fd.write("};\n")
    fd.write("#endif\n\n")

def Write_TestVector(mat,rows,cols,str,asil,deptype,fd,colprepend,rowprepend,prefix):
    if((len(cols)==0)  or (len (rows) == 0)):
        fd.write("#define "+prefix+"_DEGRADATION_TESTCASE_VECT_"+asil+"_INVALID    1 \n")
    fd.write("\n#ifndef "+prefix+"_DEGRADATION_TESTCASE_VECT_"+asil+"_INVALID\n")
    fd.write("\nstd::vector<std::tuple<uint32_t,std::vector<uint32_t>>> TestErrormap_vect_"+str+"_"+asil+"_"+prefix+ " = { \n")
    for row in rows:
        fd.write("{"+rowprepend+row+",{")
        first=True
        for column in cols:
            if(mat[row][column] == True):
                if(first == False):
                    fd.write(",")
                first=False
                fd.write(colprepend+column)
        fd.write("}},\n")
    fd.write("};\n")
    fd.write("#endif\n\n")


def Write_Matrix(fid_Err_Mat,Err_Fid_Mat,asil,TestDefFile,ParsedEnumLists,fids,prefix):
    #Fidvs_Error
    #TestDefFile.write("\n/* Fid vs Error dependency */")
    #Write_Debug(fid_Err_Mat,fids,ParsedEnumLists,TestDefFile)
    TestDefFile.write("\n/* "+prefix+" vs Error Only saisified dependency list "+asil+" */")
    Write_Debug_OnlySatisfiedDependencies(fid_Err_Mat,fids,ParsedEnumLists,TestDefFile,prefix)
    Write_TestMatrix(fid_Err_Mat,fids,ParsedEnumLists,TestDefFile,asil,""+prefix+"ToError",asil+"_"+prefix+"MAX","ldef_ErrorMgr_ErrorNum_Max",prefix)
    Write_TestVector(fid_Err_Mat,fids,ParsedEnumLists,"FidToError",asil,"ldef_ErrorMgr_enErrorNo",TestDefFile,"ldef_",asil+"_",prefix)

    #Errs_vs Fid Dependency
    #TestDefFile.write("\n/* Error vs Fid dependency */")
    #Write_Debug(Err_Fid_Mat,ParsedEnumLists,fids,TestDefFile)
    TestDefFile.write("\n/* Error vs "+prefix+" Only saisified dependency list */")
    Write_Debug_OnlySatisfiedDependencies(Err_Fid_Mat,ParsedEnumLists,fids,TestDefFile,prefix)
    Write_TestMatrix(Err_Fid_Mat,ParsedEnumLists,fids,TestDefFile,asil,"ErrorTo"+prefix+"","ldef_ErrorMgr_ErrorNum_Max",asil+"_"+prefix+"MAX",prefix)
    Write_TestVector(Err_Fid_Mat,ParsedEnumLists,fids,"ErrorToFid",asil,""+prefix+"_ENUM_"+asil,TestDefFile,asil+"_","ldef_",prefix)



def Generate_EnumStringLookup(mParsedData,TestDefFile):
    (_,Gerror,_,_,FidResDetails)=mParsedData
    (fid_det,(res_det,deg_reasons))=FidResDetails
    (list_ErrurEnums,_,_,_)=Gerror

    TestDefFile.write("std::string mErrurEnumStringLookup [ldef_ErrorMgr_ErrorNum_Max]= {\n")
    for err in list_ErrurEnums[:-1]:
        TestDefFile.write("\""+err+"\",\n")
    TestDefFile.write("};\n")

    TestDefFile.write("std::map<uint32_t,std::string> mFidStringLookup= {\n")
    for asil in AsilList:
        for fid in fid_det[asil]:
            TestDefFile.write("std::pair<uint32_t,std::string>("+asil+"_"+fid+",\""+asil+"_"+fid+"\"),\n")
    TestDefFile.write("};\n")

    TestDefFile.write("std::map<uint32_t,std::string> mResStringLookup= {\n")
    for asil in AsilList:
        for fid in deg_reasons[asil]:
            TestDefFile.write("std::pair<uint32_t,std::string>("+asil+"_"+fid+",\""+asil+"_"+fid+"\"),\n")
    TestDefFile.write("};\n")

def CreateDegradationTestCaseDefinitions(mParsedData,ExcelFile,TestDefFile):
    (_,Gerror,_,_,FidResDetails)=mParsedData
    (fid_det,(res_det,deg_reasons))=FidResDetails
    (list_ErrurEnums,_,_,_)=Gerror

    Generate_EnumStringLookup(mParsedData,TestDefFile)
    
    #not including asil_max
    for asil in AsilList:
        print("Generating Fid TestDef for asil :" +asil)
        #no including the max
        (fid_Err_Mat,Err_Fid_Mat)=GetOutputMatrix(list_ErrurEnums[:-1],fid_det[asil],ExcelFile)
        Write_Matrix(fid_Err_Mat,Err_Fid_Mat,asil,TestDefFile,list_ErrurEnums[:-1],fid_det[asil],"FID_")
   
    #not including asil_max
    for asil in AsilList:
        print("Generating RES TestDef for asil :" +asil)
        #no including the max
        (res_Err_Mat,Err_res_Mat)=GetOutputMatrix_Res(list_ErrurEnums[:-1],deg_reasons[asil],res_det[asil],ExcelFile)
        Write_Matrix(res_Err_Mat,Err_res_Mat,asil,TestDefFile,list_ErrurEnums[:-1],deg_reasons[asil],"RES_")



def Create_ErrorMgr_ErrorDtcStruct_RelationshipTable(ErrList,TestDefFile):
    TestDefFile.write("\n#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE\n")
    TestDefFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n")
    for asil in AsilList:
        TestDefFile.write("\n\n\n")
        TestDefFile.write("\nextern DtcStatus_"+asil+" Rte_ErrorMgrAgg_1_0_"+asil+"_P_DtcData_Data_DtcStatus_"+asil+";\n");
        TestDefFile.write("\nconst uint8* ErrEnum_DtcStruct_"+asil+"[ldef_ErrorMgr_ErrorNum_Max] ={")
        for Core, Value in ErrList.items():
            for Ratings, errorlist in Value.items():
                for e in errorlist:
                    (ErrorEnum, MaturationTime_ms, DematurationTime_ms, Description, SafeState, DtcInfo, _) = e
                    (DemEvent, DTC, ExtendedErrorId, DTC_LOW)=DtcInfo
                    Dtcstr=(DTC+"_"+DTC_LOW+"_"+ExtendedErrorId).lower();
                    en = "ErrorMgr_Error_" + ErrorEnum
                    if(Dtcstr != "0_0_0") and (asil == Ratings):
                        TestDefFile.write("\n&Rte_ErrorMgrAgg_1_0_"+asil+"_P_DtcData_Data_DtcStatus_"+asil+"."+Dtcstr+",")
                    else:
                        TestDefFile.write("\nNULL,")
        TestDefFile.write("\n};")
    TestDefFile.write("\n\n#ifdef __cplusplus\n}\n#endif\n\n")
    TestDefFile.write("\n#endif\n")

def Create_Error_Fid_Res_ConvFunctionsTests(mParsedData,TestDefFile):
    (_,Gerror,_,_,FidResDetails)=mParsedData
    (fid_det,(res_det,deg_reasons))=FidResDetails
    (list_ErrurEnums,_,_,_)=Gerror


    TestDefFile.write("\n#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE\n")
    TestDefFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n")
    for asil in AsilList:
        TestDefFile.write("\n\n\n")
        TestDefFile.write("\nvoid TestFunction_Conv_" + asil + "(){\n");
        TestDefFile.write("\n\tFID_STRUCT_" + asil + " stFID;\n");
        TestDefFile.write("\n\tRES_STRUCT_FEATURES_" + asil + " stRES;\n");
        TestDefFile.write("\n\tFID_BIT_STRUCT_" + asil + " bit_stFID;\n");
        TestDefFile.write("\n\tRES_BIT_STRUCT_FEATURES_" + asil + " bit_stRES;\n");
        TestDefFile.write("\n\tDegManager_Output_" + asil + "_t stOut;\n");
        TestDefFile.write("\n\tuint32 *DegManager_Output_Fid= &stOut.FID_Output[0];\n");
        TestDefFile.write("\n\tuint32 *DegManager_Output_Res= &stOut.RES_Output[0];\n");
        for fid in fid_det[asil]:
            TestDefFile.write("\n\tmemset(DegManager_Output_Fid,0,sizeof(stOut));")
            TestDefFile.write("\n\tDEGSetError_BitPacked(DegManager_Output_Fid," + asil + "_"+fid+");")
            TestDefFile.write("\n\tDegManagerApp_ConvStruct_" + asil + "(&stFID,&stRES,&stOut);")
            TestDefFile.write("\n\tDegManagerApp_ConvStruct_BITARRAY_" + asil + "(&bit_stFID,&bit_stRES,&stOut);")
            for f_all in fid_det[asil]:
                if(f_all == fid):
                    TestDefFile.write("\n\tEXPECT_EQ(stFID.m_" + asil + "_"+fid+",1);")
                    TestDefFile.write("\n\tEXPECT_EQ(bit_stFID.m_" + asil + "_" + fid + ",1);")
                #else:
                    #TestDefFile.write("\n\tEXPECT_EQ(stFID.m_" + asil + "_" + f_all + ",0);")
                    #TestDefFile.write("\n\tEXPECT_EQ(bit_stFID.m_" + asil + "_" + f_all + ",0);")
            TestDefFile.write("\n\n")
        for fid in deg_reasons[asil]:
            TestDefFile.write("\n\tmemset(DegManager_Output_Fid,0,sizeof(stOut));")
            TestDefFile.write("\n\tDEGSetError_BitPacked(DegManager_Output_Res," + asil + "_"+fid+");")
            TestDefFile.write("\n\tDegManagerApp_ConvStruct_" + asil + "(&stFID,&stRES,&stOut);")
            TestDefFile.write("\n\tDegManagerApp_ConvStruct_BITARRAY_" + asil + "(&bit_stFID,&bit_stRES,&stOut);")
            for f_all in deg_reasons[asil]:
                if(f_all == fid):
                    TestDefFile.write("\n\tEXPECT_EQ(stRES.m_"+ asil + "_"+fid+",1);")
                    TestDefFile.write("\n\tEXPECT_EQ(bit_stRES.m_" + asil + "_" + fid + ",1);")
                #else:
                    #TestDefFile.write("\n\tEXPECT_EQ(stRES.m_" + asil + "_" + fid + ",0);")
                    #TestDefFile.write("\n\tEXPECT_EQ(bit_stRES.m_" + asil + "_" + fid + ",0);")
            TestDefFile.write("\n\n")

        TestDefFile.write("\n}\n");
    TestDefFile.write("\n\n#ifdef __cplusplus\n}\n#endif\n\n")
    TestDefFile.write("\n#endif//#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE\n")


def Create_Error_SafeState_RelationshipTable(ErrList,EnumList,TestDefFile):

    (_,SafeStateList,_,_)=EnumList
    SafeStateDict =  dict([(asil,dict([(safestate, []) for safestate in SafeStateList[:-1]])) for asil in AsilList])

    TestDefFile.write("\n#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE\n")

    TestDefFile.write("\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n")

    for asil in AsilList:
        for Core, Value in ErrList.items():
            for Ratings, errorlist in Value.items():
                for e in errorlist:
                    (ErrorEnum, MaturationTime_ms, DematurationTime_ms, Description, SafeState, DtcInfo, _) = e
                    for s in SafeState:
                        s_app="ErrorMgr_SafeState_"+s
                        SafeStateDict[asil][s_app].append("ldef_ErrorMgr_Error_"+ErrorEnum)

    for asil in AsilList:
        TestDefFile.write("\n\n\n")
        TestDefFile.write("\nextern SafeStateOpDef Rte_ErrorMgrAgg_1_0_" + asil + "_P_SafeState_SafeStateOp;\n");
        TestDefFile.write("\nstd::vector<uint32_t> ErrEnum_SafeState_"+asil+"[ldef_ErrorMgr_SafeState_Max] ={")
        for safestate in SafeStateList[:-1]:
            TestDefFile.write("\n{")
            for s in SafeStateDict[asil][safestate]:
                TestDefFile.write(s+",")
            TestDefFile.write("},")
        TestDefFile.write("\n};")







    TestDefFile.write("\n\n#ifdef __cplusplus\n}\n#endif\n\n")
    TestDefFile.write("\n#endif//#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE\n")


   
