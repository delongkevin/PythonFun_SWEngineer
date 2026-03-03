import shutil
import pandas as pd
import os
import openpyxl
from openpyxl import load_workbook
from ErrorMgrCommon import GenerateIncludeGaurds,CloseIncludeGaurds,AddFileHeaders,DummyGenerationAsilList
from io import StringIO
from DegradationManager_ArxmlGen import DegManager_GenerateArxml

from ErrorMgrCommon import coreList,AsilList,CoreDefEnums,ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE,ErrorMgr_enErrorStatus
from GenInfoEmbedder import EmbedGenInfo


Degradation_GenCFile= "DegManagerDef.c";
Degradation_GenHFile=  "DegManagerDef.h";
CurrentFolderPath=""
Degradarion_HelperFunctionsFile="DegManagerApp_HelperFuncs.h"
Degradarion_GenEntypes="DegManagerGenEnTypes.h"



def CreateFiles():
    Deg_Def_H = os.path.join(CurrentFolderPath,"./../gen/", Degradation_GenHFile)
    Deg_Def_C = os.path.join(CurrentFolderPath, "./../gen/",Degradation_GenCFile)
    Deg_Def_Helper = os.path.join(CurrentFolderPath, "./../gen/",Degradarion_HelperFunctionsFile)
    Deg_Def_GenEnTypes = os.path.join(CurrentFolderPath, "./../gen/",Degradarion_GenEntypes)

    Hdl_Deg_Def_H=open(Deg_Def_H,"w")
    Hdl_Deg_Def_C = open(Deg_Def_C, "w")
    #Hdl_Deg_Def_Helper = open(Deg_Def_Helper, "w")
    Hdl_Deg_Def_Helper = None
    Hdl_Deg_Def_GenEntypes = open(Deg_Def_GenEnTypes, "w")

    GenerateIncludeGaurds(Hdl_Deg_Def_H, "DEGMANAGER_GEN_DEF")
    #GenerateIncludeGaurds(Hdl_Deg_Def_Helper, "DEGMANAGER_HELPERFUNC_DEF")
    GenerateIncludeGaurds(Hdl_Deg_Def_GenEntypes, "DEGMANAGER_GENENTYPES_DEF")

    return((Hdl_Deg_Def_H,Hdl_Deg_Def_C,Hdl_Deg_Def_Helper,Hdl_Deg_Def_GenEntypes))

def Generate_DependencyList(InhibitList,GlobErrorData,IdSelection):
    errApplicable=dict([(asil2, dict([(asil, False) for asil in AsilList]) ) for asil2 in AsilList])
    OutputLengths=dict([(asil, len(InhibitList[asil])) for asil in AsilList])

    #print(OutputLengths)

    id_Lookup= dict([(asil, []) for asil in AsilList])
    for asil in AsilList:
        id_Dep = dict([(id_x, dict([(asil_rat, []) for asil_rat in AsilList])) for id_x in InhibitList[asil]])
        for id_x in InhibitList[asil]:
            for Core, Value in GlobErrorData.items():
                for Ratings, errorlist in Value.items():
                    for e in errorlist:
                        (ErrorEnum, MaturationTime_ms, DematurationTime_ms, Description, SafeState, DtcInfo,(Fid_Map,Reasons_Map,Features_Map)) = e
                        if(IdSelection == 'FID'):
                            Id_Map=Fid_Map
                        elif(IdSelection == 'RES'):
                            Id_Map=Reasons_Map

                        if(Id_Map[id_x] == 1):
                            id_Dep[id_x][Ratings].append("ldef_"+Ratings+"_ErrorMgr_Error_" + ErrorEnum)
                            errApplicable[asil][Ratings]=True
        id_Lookup[asil]=id_Dep
    return id_Lookup,errApplicable,OutputLengths

def Add_DegManagerGenCode(C_Handle,H_Handle):
    with open("Gen_"+Degradation_GenCFile, "r") as firstfile:
        for line in firstfile:
            C_Handle.write(line)

    C_Handle.write("\n")

    with open("Gen_"+Degradation_GenHFile, "r") as firstfile:
        for line in firstfile:
            H_Handle.write(line)

    H_Handle.write("\n")

def Generate_DepencyLookupTable(Cfile,Id_List,Prefix):
    SS_Handle = ""
    SS_Handle+="\n"

    FW_DECL_ARRS =""


    for asil,Fid_Det in Id_List.items():
        if asil != 'MAX':
            SS_Handle+="\n\n/* Data Structure lists for the "+Prefix+ " for ASIL "+asil+" */\n"
            const_varname = Prefix+"_ErrorDef_" + asil + "_data"
            SS_Handle+="static const "+"DegMgr_ErrorDef " + const_varname + "["+asil+"_"+Prefix+"_MAX>0 ?"+asil+"_"+Prefix+"_MAX:1] = {\n"
            if(len(Fid_Det)== 0):
                SS_Handle+="\t/* Dummy Entry */\n"
                #SS_Handle+="\t{"+asil+"_"+Prefix+"_MAX,{\n"
                SS_Handle+="\t{{\n"
                for asil_rat in AsilList:
                    if(asil_rat != 'MAX'):
                        SS_Handle+="\t\t0,NULL,\n"
                SS_Handle+="\t}}\n"
                SS_Handle+="};\n"
            else:
                for fid,fid_err_map in Fid_Det.items():
                    SS_Handle+="\t/*"+Prefix+" ="+asil+"_"+fid+"*/\n\n"
                    #SS_Handle+="\t{"+asil+"_"+fid + ",{\n"
                    SS_Handle+="\t{{\n"
                    for asil_rat,error_enums in fid_err_map.items():
                        if(asil_rat != 'MAX'):
                            max_len=len(error_enums)
                            if(max_len == 0):
                                SS_Handle+="\t\t0,NULL,\n"
                            else:
                                FW_DECL_ARRS += "static const ErrorMgr_enErrorNo_" + asil_rat + "  " + asil + "_" + fid + asil_rat + "[] = {"
                                SS_Handle+="\t\t"+str(max_len) + ","+ asil + "_" + fid + asil_rat+",\n"
                                count=0

                                for err in error_enums:
                                    FW_DECL_ARRS+=err
                                    if(count < max_len -1):
                                        FW_DECL_ARRS +=","
                                    count+=1
                                FW_DECL_ARRS+="\t};\n"
                    SS_Handle+="\t}},\n"
                SS_Handle+="};\n"

    SS_Handle+="\n"

    Cfile.write(FW_DECL_ARRS)
    Cfile.write(SS_Handle)



def Generate_GenericStructDefs(H_Handle,Fid_Asil_List,RES_ASIL_List):
    #Structure defintions for FID
    H_Handle.write("\n\n")

    hsection_fid_bit=[]
    hsection_res_bit = []
    hsection_fid_byte=[]
    hsection_res_byte = []


    for asil in AsilList:
        if (asil != 'MAX'):
            hsection_fid_bit.append("/* Fid Output Definition for ASIL  :" + asil +" Controls */\n")
            hsection_fid_byte.append("/* Fid Output Definition for ASIL  :" + asil + " Controls */\n")
            hsection_fid_bit.append("typedef struct  {\n")
            hsection_fid_byte.append("typedef struct  {\n")
            for Fid in Fid_Asil_List[asil]:
                hsection_fid_bit.append("\tuint32_t m_"+asil+"_"+Fid+" : 1;\n")
                hsection_fid_byte.append("\tuint8_t m_" + asil + "_" + Fid + " ;\n")
            if(len(Fid_Asil_List[asil]) == 0):
                hsection_fid_bit.append("\tuint32_t m_" + asil + "_" + "FID_MAX :1" + ";\n")
                hsection_fid_byte.append("\tuint8_t m_" + asil + "_" + "FID_MAX " + ";\n")
            hsection_fid_bit.append("}FID_BIT_STRUCT_"+asil+";\n")
            hsection_fid_byte.append("}FID_BYTE_STRUCT_" + asil + ";\n")





    for asil in AsilList:
        if (asil != 'MAX'):
            hsection_res_bit.append("/* Reason Output Definition for ASIL  :" + asil +" Controls */\n")
            hsection_res_byte.append("/* Reason Output Definition for ASIL  :" + asil + " Controls */\n")
            hsection_res_bit.append("typedef struct  {\n")
            hsection_res_byte.append("typedef struct  {\n")
            for Res in RES_ASIL_List[asil]:
                hsection_res_bit.append("\tuint32_t m_"+asil+"_"+Res+": 1;\n")
                hsection_res_byte.append("\tuint8_t m_" + asil + "_" + Res + ";\n")
            if(len(RES_ASIL_List[asil]) == 0):
                hsection_res_bit.append("\tuint32_t m_" + asil + "_" + "RES_FEATURES_MAX" + ":1 ;\n")
                hsection_res_byte.append("\tuint8_t m_" + asil + "_" + "RES_FEATURES_MAX" + ";\n")
            hsection_res_bit.append("}RES_BIT_STRUCT_FEATURES_"+asil+";\n")
            hsection_res_byte.append("}RES_BYTE_STRUCT_FEATURES_" + asil + ";\n")


    H_Handle.write("\n\n")
    for s in hsection_fid_bit:
        H_Handle.write(s)
    H_Handle.write("\n\n")
    for s in hsection_res_bit:
        H_Handle.write(s)
    H_Handle.write("\n\n")
    for s in hsection_fid_byte:
        H_Handle.write(s)
    H_Handle.write("\n\n")
    for s in hsection_res_byte:
        H_Handle.write(s)
    H_Handle.write("\n\n")

    # Todo: Temporary: Need to remove it later.
    for asil in AsilList:
        H_Handle.write("\n//Todo Temporary: Users should switch to using the bit structure . Adding byte structure as default to continue compilation with existing code")
        H_Handle.write("\ntypedef FID_BYTE_STRUCT_"+asil+" FID_STRUCT_"+asil+";")
        H_Handle.write("\ntypedef RES_BYTE_STRUCT_FEATURES_" + asil + " RES_STRUCT_FEATURES_" + asil + ";")
    H_Handle.write("\n\n")





    #ASIL based specific struct removed
    #for asil in AsilList:
    #    if (asil != 'MAX'):
    #        H_Handle.write("typedef struct {\n")
    #        for asil_rat in AsilList:
    #            if (asil_rat != 'MAX'):
    #                H_Handle.write("\tuint16_t Dep_Error_Count_" + asil_rat + ";\n")
    #                H_Handle.write("\tconst ErrorMgr_enErrorNo_" + asil_rat + " *Error_List_" + asil_rat + ";\n")
    #        H_Handle.write("}ErrorDep_" + asil + ";\n")
    #        H_Handle.write("\n\n")

    #for asil in AsilList:
    #    if (asil != 'MAX'):
    #        H_Handle.write("typedef struct {\n")
    #        #H_Handle.write("\tFID_ENUM_"+asil+" FID;\n")
    #        H_Handle.write("\tDegMgr_ErrorDep  errDep;\n")
    #        H_Handle.write("}FID_ErrorDef_"+asil+";\n")
    #        H_Handle.write("\n\n")

    #for asil in AsilList:
    #    if (asil != 'MAX'):
    #        H_Handle.write("typedef struct {\n")
    #       #H_Handle.write("\tRES_ENUM_" + asil + " RES;\n")
    #        H_Handle.write("\tDegMgrErrorDep  errDep;\n")
    #        H_Handle.write("}RES_ErrorDef_" + asil + ";\n")
    #        H_Handle.write("\n\n")



    H_Handle.write("typedef struct {\n")
    for asil_rat in AsilList:
        if (asil_rat != 'MAX'):
            H_Handle.write("\tuint16_t Dep_Error_Count_" + asil_rat + ";\n")
            H_Handle.write("\tconst ErrorMgr_enErrorNo_" + asil_rat + " *Error_List_" + asil_rat + ";\n")
    H_Handle.write("}DegMgr_ErrorDep;\n")
    H_Handle.write("\n\n")



    H_Handle.write("typedef struct {\n")
    #H_Handle.write("\tFID_ENUM_"+asil+" FID;\n")
    H_Handle.write("\tDegMgr_ErrorDep  errDep;\n")
    H_Handle.write("}DegMgr_ErrorDef;\n")
    H_Handle.write("\n\n")






def Generate_FidEnums(H_Handle,Fid_Asil_List):
    H_Handle.write("\n\n")
    for asil in AsilList:
        if (asil != 'MAX'):
            H_Handle.write("/* Fid Output Definition for ASIL  :" + asil +" Controls */\n")
            count_value=0
            H_Handle.write("typedef enum  {\n")
            for Fid in Fid_Asil_List[asil]:
                H_Handle.write("\t"+asil+"_"+Fid+"="+str(count_value)+",\n")
                count_value+=1
            H_Handle.write("\t" + asil + "_" + "FID_MAX" + ",\n")
            H_Handle.write("}FID_ENUM_"+asil+";\n")
            if count_value == 0:
                H_Handle.write("\t#define FID_ENUM_" + asil + "_HAS_NO_ELEMENTS   1 \n")
    H_Handle.write("\n\n")

def Generate_Reason_Enums(H_Handle,RES_ASIL_List, DEG_REASONS_List):
    H_Handle.write("\n\n")
    for asil in AsilList:
        if (asil != 'MAX'):
            count_value = 0
            H_Handle.write("/* Reason Output Definition for ASIL  :" + asil +" Controls */\n")
            H_Handle.write("typedef enum  {\n")
            for Res in RES_ASIL_List[asil]:
                H_Handle.write("\t"+asil+"_"+Res+"="+str(count_value)+",\n")
                count_value+=1
            H_Handle.write("\t" + asil + "_" + "RES_FEATURES_MAX" + ",\n")
            H_Handle.write("}RES_FEATURES_"+asil+";\n")
            if count_value == 0:
                H_Handle.write("\t#define RES_FEATURES_ENUM_" + asil + "_HAS_NO_ELEMENTS   1 \n")

    H_Handle.write("/* Actual Possible Reasons */\n")
    for asil in AsilList:
        if (asil != 'MAX'):
            count_value = 0
            H_Handle.write("/* Reason Output Definition for ASIL  :" + asil +" Controls */\n")
            H_Handle.write("typedef enum  {\n")
            for Res in DEG_REASONS_List[asil]:
                H_Handle.write("\t"+asil+"_"+Res+"="+str(count_value)+",\n")
                count_value += 1
            H_Handle.write("\t" + asil + "_" + "RES_MAX" + ",\n")            
            #H_Handle.write("\t" + asil + "_" + "RES_EXPLICIT_NONE" + ",\n")
            #H_Handle.write("\t" + asil + "_" + "RES_EXPLICIT_MULTIPLE" + ",\n")
            #H_Handle.write("\t" + asil + "_" + "RES_MAX_INCLUDING_EXPLICIT" + ",\n")
            
            H_Handle.write("}RES_ENUM_"+asil+";\n")
            if count_value == 0:
                H_Handle.write("\t#define RES_ENUM_" + asil + "_HAS_NO_ELEMENTS   1 \n")

# def Generate_DegradationMgr_EnumStruct_ConversionFunction(H_Handle):
#     for asil in AsilList:
#         if (asil != 'MAX'):
#             H_Handle.write("\n\n");
#             H_Handle.write("/* Function to translate array into Structure representation  :" + asil +" Controls */\n")
#             H_Handle.write("static inline void DegManagerApp_ConvStruct_"+asil+"(FID_STRUCT_"+asil+" *pOutputFidStruct,RES_STRUCT_FEATURES_"+asil+" *pOutputResStruct,DegManager_Output_"+asil+"_t *pInputDegMgrArray) { \n")
#             H_Handle.write("\tstatic_assert(sizeof(FID_STRUCT_"+asil+") == sizeof(pInputDegMgrArray->FID_Output), \" FID Struct Size mismatch : Inconsistent data defintions \");  \n");
#             H_Handle.write("\tstatic_assert(sizeof(RES_STRUCT_FEATURES_"+asil+") == sizeof(pInputDegMgrArray->RES_Output), \" FID Struct Size mismatch : Inconsistent data defintions \");  \n");
#             H_Handle.write("\tmemcpy(pOutputFidStruct,pInputDegMgrArray->FID_Output,sizeof(pInputDegMgrArray->FID_Output));  \n");
#             H_Handle.write("\tmemcpy(pOutputResStruct,pInputDegMgrArray->RES_Output,sizeof(pInputDegMgrArray->RES_Output));  \n");
#             H_Handle.write("}\n\n");
#
#     for asil in AsilList:
#         if (asil != 'MAX'):
#             H_Handle.write("\n\n");
#             H_Handle.write("/* Function to translate array into Structure representation  :" + asil +" Controls */\n")
#             H_Handle.write("static inline void DegManagerApp_ConvStruct_Type2_"+asil+"(FID_STRUCT_"+asil+" *pOutputFidStruct,RES_STRUCT_FEATURES_"+asil+" *pOutputResStruct,uint8 *pInpFidBool,uint8 *pInpfidRes) { \n")
#             H_Handle.write("\tmemcpy(pOutputFidStruct,pInpfidRes,sizeof(FID_STRUCT_"+asil+"));  \n");
#             H_Handle.write("\tmemcpy(pOutputResStruct,pInpfidRes,sizeof(RES_STRUCT_FEATURES_"+asil+"));  \n");
#             H_Handle.write("}\n\n");


def Generate_DegardationMatrix(RootFolderPath,FidResDetails,GlobErrorData,ParsedEnumList,version_info):
    (Fid_Asil_List,RES_Details)=FidResDetails
    (RES_ASIL_List, DEG_REASONS_List)=RES_Details

    CurrentFolderPath=RootFolderPath;
    (_,_,ErrorList_Asil,_)=ParsedEnumList

    (Hdl_Deg_Def_H, Hdl_Deg_Def_C,Hdl_Deg_Def_Helper,Hdl_Deg_Def_GenEntypes)=CreateFiles()

    AddFileHeaders(Hdl_Deg_Def_H,["DegManagercfg.h","ErrorManagerDef.h",Degradarion_GenEntypes])
    AddFileHeaders(Hdl_Deg_Def_C, [Degradation_GenHFile, "DegManager_Common_Memmap_adapt.h"])
    #AddFileHeaders(Hdl_Deg_Def_Helper,["string.h","DegManagerDef.h","DegManagerTypes.h","assert.h"])

    EmbedGenInfo(Hdl_Deg_Def_H,version_info)
    EmbedGenInfo(Hdl_Deg_Def_C, version_info)
    #EmbedGenInfo(Hdl_Deg_Def_Helper, version_info)
    EmbedGenInfo(Hdl_Deg_Def_GenEntypes, version_info)

    Generate_FidEnums(Hdl_Deg_Def_GenEntypes,Fid_Asil_List)
    Generate_Reason_Enums(Hdl_Deg_Def_GenEntypes, RES_ASIL_List, DEG_REASONS_List)

    Generate_GenericStructDefs(Hdl_Deg_Def_H,Fid_Asil_List,DEG_REASONS_List)


    Fid_Lookup,Fid_ErrorInputApplicable,FidOutputLengths=Generate_DependencyList(Fid_Asil_List,GlobErrorData,'FID')
    RES_Lookup, Res_ErrorInputApplicable, RESOutputLengths = Generate_DependencyList(DEG_REASONS_List, GlobErrorData,'RES')

    Generate_DepencyLookupTable(Hdl_Deg_Def_C,Fid_Lookup,'FID')
    Generate_DepencyLookupTable(Hdl_Deg_Def_C, RES_Lookup,'RES')

    Add_DegManagerGenCode(Hdl_Deg_Def_C,Hdl_Deg_Def_H)


    #Generate_DegradationMgr_EnumStruct_ConversionFunction(Hdl_Deg_Def_Helper)

    CloseIncludeGaurds(Hdl_Deg_Def_H)
    #CloseIncludeGaurds(Hdl_Deg_Def_Helper)
    CloseIncludeGaurds(Hdl_Deg_Def_GenEntypes)


    #Generate Degradation Matrix Arxml
    DegManager_GenerateArxml(ErrorList_Asil,CurrentFolderPath,(Fid_ErrorInputApplicable,Res_ErrorInputApplicable),(FidOutputLengths,RESOutputLengths))


