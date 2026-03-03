import pandas as pd
import os
import sys
import openpyxl
from ErrorMgr_ArxmlGen import GenerateArxml
from ErrorMgrCommon import coreList,AsilList,CoreDefEnums,ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE, config_Generate_unitTestcases
from ErrorMgrExcelDataParser import ParseErrorManagerExcelfile ,ReadExcelFileVersion
from DegradationMgr_Gen import Generate_DegardationMatrix
from ErrorMgrCommon import GenerateIncludeGaurds,CloseIncludeGaurds,AddFileHeaders
from ErrorManagerDocGen import GenerateDocumentation
from ErrorManagerQxnGen import GenerateQNXFunctions
from ErrorManagerTestGen import CreateDegradationTestCaseDefinitions,Create_ErrorMgr_ErrorDtcStruct_RelationshipTable,Create_Error_SafeState_RelationshipTable,Create_Error_Fid_Res_ConvFunctionsTests
from ErrorMgr_GenerateFD56_DebugInfo import GenerateFD56_DebugInfo
from ErrorMgrCommon import config_GenerateFD56Files
from GenInfoEmbedder import EmbedGenInfo

# Below Global varaiable to generate ErrorData_B_QM.py file
Handle_ErrorDataPY=""            # Handler for ErrorData_B_QM.py
Fault_Data_Print =""             # to print data in ErrorData_B_QM.py
Handle_FD62_QM =""		 # Handler for FD62_data.xls data
Handle_FD64_B =""		 # Handler for FD64_data.xls data


def AddCommonFileHeaders(HFile):
    AddFileHeaders(HFile,["ErrorManagerTypes.h","ErrorManagercfg.h"])




def addEnumEntry(en,Value,Hfile,enList,Comment):
    enList.append(en)
    hList=[]
    hList.append("\tldef_" + en)
    if(Value != None):
         hList.append(" = "+str(Value));
    hList.append(" ,"+"/*"+Comment+"*/\n")
    if(Hfile != None):
        for s in hList:
            Hfile.write(s)
    return enList,hList



def CreateEnumDefinitions(HFile,ErrorList,SafeStateList,Handle_TestDefs):

    op_Errors_perCore_perAsilLevel = dict([(core,dict([(asil, []) for asil in AsilList])) for core in coreList])
    op_ErrorList=[]
    op_SafeStateList=[]
    op_ErrorList_Asil = dict([(asil, []) for asil in AsilList])
    Comment=""
    IsErrorsApplicableCoreAsil= dict([(core,dict([(asil, False) for asil in AsilList])) for core in coreList])

    #Safe State Definitions
    SafeStateCount=0;
    #HFile.write("\n#ifndef Rte_TypeDef_ErrorMgr_enSafeStates\n")
    HFile.write("\n\n/* Safe State Enum Definitions */\n")
    HFile.write("typedef enum {\n")
    for safeState in SafeStateList:
        en = "ErrorMgr_SafeState_" + safeState
        Comment=str(SafeStateCount)
        addEnumEntry(en, SafeStateCount,HFile, op_SafeStateList,Comment)
        SafeStateCount+=1;
    en='ErrorMgr_SafeState_Max'
    addEnumEntry(en,SafeStateCount,HFile,op_SafeStateList,Comment)
    HFile.write("}ldef_ErrorMgr_enSafeStates;\n\n\n");
    #HFile.write("\n#endif\n")

    HFile.write("\n\n/* DTC Related Struct Definition */")
    HFile.write("\ntypedef struct {")
    HFile.write("\n\tuint32_t DemEventId;")
    HFile.write("\n\tconst char *DTCNo;")
    HFile.write("\n\tuint8_t  DTCLow;")
    HFile.write("\n\tuint32_t ExtendedError;")
    HFile.write("\n}ErrorMgr_DiagDetails;\n")

    #basic enum definition for ErrorMapping
    HFile.write("\n\n/* ErrorMapping Structure Definition */")
    HFile.write("\ntypedef struct {")
    HFile.write("\n\tErrorMgr_CoreList enCore;")
    HFile.write("\n\tErrorMgr_AsilList enAsil;")
    HFile.write("\n\t#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE")
    HFile.write("\n\tuint32_t enAsilEnumVal;")   
    HFile.write("\n\tuint32_t SafeStateCount;")
    HFile.write("\n\tconst ldef_ErrorMgr_enSafeStates * const enSafeStates;")
    HFile.write("\n\tuint8 * const pDtcFlag;")
    HFile.write("\n\tldef_AdditionalData_arr * const pDtcAddData;")
    HFile.write("\n\t#endif")
    #HFile.write("\n\tErrorMgr_DiagDetails *DiagDetails;")
    HFile.write("\n}ErrorMgr_ErrorMapping;\n")


    TotalErrCount=0;
    
    #Error Global Enum No
    Handle_TestDefs.write("\nstatic std::vector<uint32_t> v_Test_AllErrors ={")
    #HFile.write("\n#ifndef Rte_TypeDef_ldef_ErrorMgr_enErrorNo\n")
    HFile.write("\n\n/* Errorlist Enum Definition */\n")
    HFile.write("typedef enum {\n")

    en_GlobErrEnumValue=0
    for Core,Value in ErrorList.items():
        HFile.write("\t/* Orginator: ErrorMgr_Core_"+Core+",*/\n")
        for Ratings, errorlist in Value.items():
            for e in errorlist:
                TotalErrCount=TotalErrCount+1
                (ErrorEnum, MaturationTime_ms, DematurationTime_ms, Description,SafeState,DtcInfo,_) = e
                en = "ErrorMgr_Error_" + ErrorEnum
                Handle_TestDefs.write("(uint32_t)ldef_"+en+",")
                Comment=str(TotalErrCount-1);
                addEnumEntry(en, en_GlobErrEnumValue,HFile, op_ErrorList,Comment)
                op_Errors_perCore_perAsilLevel[Core][Ratings].append((en,en_GlobErrEnumValue))
                en_GlobErrEnumValue+=1
    en='ErrorMgr_ErrorNum_Max'
    Handle_TestDefs.write("(uint32_t)ldef_"+en)
    Comment=str(TotalErrCount-1);
    addEnumEntry(en,en_GlobErrEnumValue,HFile,op_ErrorList,Comment)
    for c in coreList:
        for a in AsilList:
              op_Errors_perCore_perAsilLevel[c][a].append((en,en_GlobErrEnumValue))
    en_GlobErrEnumValue+=1
    Handle_TestDefs.write("};\n")
    HFile.write("}ldef_ErrorMgr_enErrorNo;\n");
    #HFile.write("\n#endif\n")


    #Error Definitions based on ASIL Level
    MatchedAsil_enumCode=[]
    MatchedAsil_structCode=[]
    MatchedAsil_debugCountCode=[]
    for MatchedAsilLevel in AsilList:
        Handle_TestDefs.write("\nstatic std::vector<uint32_t> v_Test_AllErrors_"+MatchedAsilLevel+" ={")
        CommentEnumCount=0;
        MatchedAsil_enumCode.append("\ntypedef enum {\n")
        MatchedAsil_structCode.append("\ntypedef struct {\n")
        MatchedAsil_debugCountCode.append("\ntypedef struct {\n")

		# To print Array Name ,Example - ErrorData_QM = [ or ErrorData_B = [
        Fault_Data_Print = "ErrorData_"+MatchedAsilLevel + " = ["                
        Commit_ErrorData_B_QM_PY(Handle_ErrorDataPY,Fault_Data_Print)

        for Core,Value in ErrorList.items():
            MatchedAsil_enumCode.append("\t/* Orginator: ErrorMgr_Core_"+Core+",*/\n")
            MatchedAsil_structCode.append("\t/* Orginator: ErrorMgr_Core_"+Core+",*/\n")
            MatchedAsil_debugCountCode.append("\t/* Orginator: ErrorMgr_Core_"+Core+",*/\n")
            for Ratings, errorlist in Value.items():
                if(Ratings == MatchedAsilLevel):
                    for e in errorlist:
                        #TotalErrCount=TotalErrCount+1                        
                        (ErrorEnum, MaturationTime_ms, DematurationTime_ms, Description,SafeState,DTCInfo,_) = e
                        en = MatchedAsilLevel+"_ErrorMgr_Error_" + ErrorEnum
                        Handle_TestDefs.write("(uint32_t)ldef_"+en+",")
                        Comment=str(CommentEnumCount)
                        _,tempCode=addEnumEntry(en, CommentEnumCount,None, op_ErrorList_Asil[MatchedAsilLevel],Comment)
                        MatchedAsil_enumCode=MatchedAsil_enumCode+tempCode
                        MatchedAsil_structCode.append("uint32_t "+en+" : 1;\n")
                        MatchedAsil_debugCountCode.append("uint32_t "+en+";\n")
						
						# To detect fault position
                        mod_var = int(CommentEnumCount % 8)              # Bit Position
                        reminder_var= int(CommentEnumCount / 8)          # Byte Position
						
                        CommentEnumCount=CommentEnumCount+1
						
						# To print Fault name as it's byte and Bit position ,Example : ["B_ErrorMgr_Error_Battery_UnderVoltage",0,0],
                        Fault_Data_Print = "["+'"'+en+'"'+","+str(reminder_var)+","+str(mod_var)+"],"
                        Commit_ErrorData_B_QM_PY(Handle_ErrorDataPY,Fault_Data_Print)
                        
                        if(MatchedAsilLevel == 'QM'):
                            write_ErrorData_QM_or_B_Excel(Handle_FD62_QM,en)		# Write QM data in FD62_data.xls file
                        if(MatchedAsilLevel == 'B'):
                            write_ErrorData_QM_or_B_Excel(Handle_FD64_B,en)		# Write QM data in FD64_data.xls file
                        
                        
						
	# To print closing Square bracket of Array -]
        Fault_Data_Print = " ]"
        Commit_ErrorData_B_QM_PY(Handle_ErrorDataPY,Fault_Data_Print)


        en=MatchedAsilLevel+'_ErrorMgr_ErrorNum_Max'
        Handle_TestDefs.write("(uint32_t)ldef_"+en)
        Comment=str(CommentEnumCount)
        _,tempCode=addEnumEntry(en,CommentEnumCount,None,op_ErrorList_Asil[MatchedAsilLevel],Comment)
        MatchedAsil_enumCode=MatchedAsil_enumCode+tempCode
        MatchedAsil_structCode.append("uint32_t "+en+" : 1 ;\n")
        MatchedAsil_debugCountCode.append("uint32_t "+en+"  ;\n")
        Handle_TestDefs.write("};\n")
        MatchedAsil_enumCode.append("\tldef_"+MatchedAsilLevel+"_ErrorMgr_ErrorNum_SizeSetter=2147483647U, /*0x7FFFFFFFU*/\n");
        MatchedAsil_enumCode.append("}ErrorMgr_enErrorNo_"+MatchedAsilLevel+";\n\n\n");
        MatchedAsil_structCode.append("}ErrorMgr_stErrorNo_"+MatchedAsilLevel+";\n\n\n");
        MatchedAsil_debugCountCode.append("}ErrorMgr_stErrorDbgCount_"+MatchedAsilLevel+";\n\n\n");



    #Create enums for  Core and ASIL Specific Error faults
    Handle_TestDefs.write("\nstatic std::vector<std::vector<std::vector<uint32_t>>> v_Test_AllErrors_CoreRatings = {\n")
    bCoreOnceIgn=True;
    for Core,Value in ErrorList.items():
        if bCoreOnceIgn == False:
            Handle_TestDefs.write(",")
        bCoreOnceIgn=False 
        Handle_TestDefs.write("\n{")
        bRatOnceIgn=True;
        for Ratings, errorlist in Value.items():   
            if bRatOnceIgn == False:
               Handle_TestDefs.write(",")
            bRatOnceIgn=False  
            Handle_TestDefs.write("\n{")        
            MatchedAsil_enumCode.append("\n\t/* Orginator: ErrorMgr_Core_"+Core+" Asil "+Ratings+",*/")
            MatchedAsil_structCode.append("\n\t/* Orginator: ErrorMgr_Core_"+Core+" Asil "+Ratings+",*/")
            MatchedAsil_enumCode.append("\ntypedef enum  {")
            if(len(errorlist)>0):
                MatchedAsil_structCode.append("\ntypedef struct  {")
            for e in errorlist:
                (ErrorEnum, _, _, _,_,_,_) = e
                en = "ErrorMgr_CoreAsilSpecific_" + ErrorEnum
                MatchedAsil_enumCode.append("\n\t"+en+",");
                MatchedAsil_structCode.append("\n\tldef_ErrorMgr_ErrorField "+ErrorEnum+";");
                Handle_TestDefs.write("(uint32_t)"+en+",")
            MatchedAsil_enumCode.append("\n\t"+"ErrorMgr_CoreAsilSpecific_"+Core+"_"+Ratings+"_MAX,");
            Handle_TestDefs.write("(uint32_t)"+"ErrorMgr_CoreAsilSpecific_"+Core+"_"+Ratings+"_MAX")
            MatchedAsil_enumCode.append("\n}ErrorMgr_CoreAsilSpecific_"+Core+"_"+Ratings+";\n")
            if (len(errorlist) > 0):
                MatchedAsil_structCode.append("\n}ErrorMgr_stCoreAsilSpecific_"+Core+"_"+Ratings+";\n")
                IsErrorsApplicableCoreAsil[Core][Ratings]= True

            Handle_TestDefs.write("\n}")
        Handle_TestDefs.write("\n}")
    Handle_TestDefs.write("\n};\n\n")



    #write the data to header file
    for s in MatchedAsil_enumCode:
        HFile.write(s)
    for s in MatchedAsil_structCode:
        HFile.write(s)
    for s in MatchedAsil_debugCountCode:
        HFile.write(s)

    #write Generate local definitions
    HFile.write("\n//Local Definitions for debugging\n")
    for Core in coreList:
        HFile.write("\n#if ERRORMGR_CURRENTCORE == ERRORMGRCORE_MCU"+Core+"\n")
        for Ratings in AsilList:
            if (IsErrorsApplicableCoreAsil[Core][Ratings] == True):
                HFile.write("\n\t#define ErrorMgr_LocalDef_ST_Core_Specific_"+Ratings+"  ErrorMgr_stCoreAsilSpecific_"+Core+"_"+Ratings+"\n")
            HFile.write("\n\t#define ErrorMgr_LocalDef_EN_Core_Specific_"+Ratings+"  ErrorMgr_CoreAsilSpecific_"+Core+"_"+Ratings+"\n")
        HFile.write("\n#endif /* ERRORMGR_CURRENTCORE == ERRORMGRCORE_"+Core+" */\n")

    HFile.write("\n\n/* Total Error Count */\n#define ErrorMgr_TotalErrCount (" + str(TotalErrCount) + "u)\n\n")

    HFile.write("typedef struct {\n");
    HFile.write("\tErrorMgr_RuntimeStateDef *RamDef;\n");
    HFile.write("\tldef_ErrorMgr_enErrorNo enError;\n");
    HFile.write("\tuint16_t MaturationTime_ms;\n");
    HFile.write("\tuint16_t DematurationTime_ms;\n");
    HFile.write("}ErrorMgr_ErrorDesc;\n\n");


    HFile.write("typedef struct {\n");
    HFile.write("\tconst ErrorMgr_ErrorDesc* ErrorDesc;\n");
    HFile.write("\tuint16_t Count;\n");
    HFile.write("}ErrorMgr_ErrorDescExt;\n\n\n");

    return (op_ErrorList,op_SafeStateList,op_ErrorList_Asil,op_Errors_perCore_perAsilLevel),IsErrorsApplicableCoreAsil


def CreateErrorMappingTable(CFile,HFile,ErrorList,Handle_TestDefs):
    SafeState_CodeList=[]
    ErrorMapCodeList=[]
    SafeState_DefineList=[]

    CFile.write("\n#if ERRORMGR_CURRENTCORE  == ERRORMGR_AGGREGATORCORE \n")
    for asil in AsilList:
        
        CFile.write("\n\textern const ldef_DtcStatus_"+asil+" ErrorMgr_DtcStatus_"+asil+';')
        CFile.write("\n\textern const ldef_DtcAddData_"+asil+" ErrorMgr_DtcAddData_"+asil+";")
    CFile.write("\n#endif \n")

    ErrorMapCodeList.append("\n/* Error to Core Mapping */\n")
    ErrorMapCodeList.append("\nconst ErrorMgr_ErrorMapping ErrorMgr_ErrorMap [ErrorMgr_TotalErrCount]  ERRMANAGER_ATTR_CONST_HIGHPERF = {\n")
    for Core, Value in ErrorList.items():
        for Ratings, errorlist in Value.items():
            for e in errorlist:
                (ErrorEnum, MaturationTime_ms, DematurationTime_ms, Description, SafeStates, DtcInfo,_) = e
                if(len(SafeStates) > 0):
                    str_safestate_start="&cSafeStates_"+ErrorEnum+"[0]"
                else:
                    str_safestate_start="NULL"
                ErrorMapCodeList.append("/* "+ErrorEnum+" */")
                ErrorMapCodeList.append("{\tErrorMgr_Core_"+Core+","+"ErrorMgr_Asil_"+Ratings+"\n")
                ErrorMapCodeList.append("\t\t#if ERRORMGR_CURRENTCORE  == ERRORMGR_AGGREGATORCORE \n")
                ErrorMapCodeList.append("\t\t\t,ldef_"+Ratings+"_ErrorMgr_Error_" + ErrorEnum +",D_COUNT_cSafeStates_"+ErrorEnum+" ,"+str_safestate_start)
                CommaCount=0
                SafeState_DefineList.append("#define D_COUNT_cSafeStates_"+ErrorEnum+" " +str(len(SafeStates))+"\n")
                if(len(SafeStates) > 0):
                    SafeState_CodeList.append("const ldef_ErrorMgr_enSafeStates cSafeStates_"+ErrorEnum+"[D_COUNT_cSafeStates_"+ErrorEnum+"] = {")
                    for SafeState in SafeStates:
                        if(CommaCount != 0):
                            SafeState_CodeList.append(",")
                        CommaCount+=1
                        SafeState_CodeList.append("ldef_ErrorMgr_SafeState_"+SafeState)
                    SafeState_CodeList.append("};\n")
                (dem,dtc,extdata,dtc_low)=DtcInfo
                #ErrorMapCodeList.append(",{0x"+str(dem)+",\""+str(dtc)+"\",0x"+str(dtc_low)+",0x"+str(extdata)+"}")
                str_DtcString=str_DtcString=str(dtc)+"_"+str(dtc_low)+"_"+str(extdata)
                str_DtcString=str_DtcString.lower()
                if(str_DtcString != '0_0_0'):                
                    ErrorMapCodeList.append(",(uint8 * const)&ErrorMgr_DtcStatus_"+Ratings+"."+str_DtcString)
                    ErrorMapCodeList.append(",(ldef_AdditionalData_arr * const)&ErrorMgr_DtcAddData_"+Ratings+"."+str_DtcString)
                else:
                    ErrorMapCodeList.append(",NULL")
                    ErrorMapCodeList.append(",NULL")
                ErrorMapCodeList.append("\n\t\t#endif \n")
                ErrorMapCodeList.append("},\n");
    ErrorMapCodeList.append("};\n");

    HFile.write("//Defines for the MAx values of Safestates for each of the errors\n\n")
    for s in SafeState_DefineList:
        HFile.write(s);
    HFile.write("\n\n//End::Defines for the MAx values of Safestates for each of the errors\n\n")

    CFile.write(" \n\t #ifndef ERROR_MAPPING_NULL_PTR")
    CFile.write(" \n\t #define ERROR_MAPPING_NULL_PTR  ((ErrorMgr_ErrorMapping const *)0)")
    CFile.write(" \n\t #endif \n")
       
    CFile.write("//List of Safe States for each of the errors \n\n")
    for s in SafeState_CodeList:
        CFile.write(s);
    CFile.write("\n\n//End ::List of Safe States for each of the errors \n\n")    

    CFile.write("//Error Mapping Table \n\n")
    for s in ErrorMapCodeList:
        CFile.write(s);
    CFile.write("\n\n//End::Error Mapping Table \n\n")




    #Test Definition Creation


    Test_Vector_ListOf_TestDetails=[]
    Test_Array_SafeState_Error=[]

    
    tabs="\t"
    for Core, Value in ErrorList.items():
        for Ratings, errorlist in Value.items():
            for e in errorlist:
                TestDetails=""                
                (ErrorEnum, MaturationTime_ms, DematurationTime_ms, Description, SafeStates, DtcInfo,_) = e
                TestDetails+=tabs+"{\n"
                tabs+="\t"
                TestDetails+=(tabs+"ldef_ErrorMgr_Error_"+ErrorEnum+",\n")
                TestDetails+=(tabs+"ErrorMgr_Core_"+Core+",\n"+tabs+"ErrorMgr_Asil_"+Ratings+",\n"+tabs+"ldef_"+Ratings+"_ErrorMgr_Error_" + ErrorEnum +",\n"+tabs+str(len(SafeStates))+",\n")
                if(len(SafeStates) > 0):
                    ss_string=tabs+"{"
                    for ss_state in SafeStates:
                        ss_string+="ldef_ErrorMgr_SafeState_"+ss_state+","
                    #print (ss_string)
                    ss_string=ss_string[:-1]+"};\n"
                    Test_Array_SafeState_Error.append("const ldef_ErrorMgr_enSafeStates TestSafeState_"+ErrorEnum+"[]="+ss_string)
                    TestDetails+=(tabs+"&TestSafeState_"+ErrorEnum+"[0],\n")
                else:
                    TestDetails+=(tabs+"NULL,\n")
                TestDetails+=(tabs+"{"+MaturationTime_ms+","+DematurationTime_ms+"},\n")
                (dem,dtc,extdata,dtc_low)=DtcInfo
                TestDetails+=(tabs+"{0x"+str(dem)+",\""+str(dtc)+"\",0x"+str(dtc_low)+",0x"+str(extdata)+"},\n")
                TestDetails+=(tabs+"ErrorMgr_CoreAsilSpecific_"+ErrorEnum+"\n")
                #Handle_TestDefs.write(",0")
                #Handle_TestDefs.write("}},\n");
                tabs=tabs[:-1]
                TestDetails+=(tabs+"},\n");
                Test_Vector_ListOf_TestDetails.append(TestDetails)


    for tempstr in Test_Array_SafeState_Error:
        Handle_TestDefs.write(tempstr)

    #Handle_TestDefs.write("static std::vector<ErrorMgr_stTestErrorSpecs> ErrorMgr_TestDefs {\n")
    Handle_TestDefs.write("static ErrorMgr_stTestErrorSpecs ErrorMgr_TestDefs [ldef_ErrorMgr_ErrorNum_Max]= {\n")
    for tempstr in Test_Vector_ListOf_TestDetails:        
        if tempstr != Test_Vector_ListOf_TestDetails[-1]:
            Handle_TestDefs.write(tempstr);
        else:
            Handle_TestDefs.write(tempstr[:-2]+"\n");
    Handle_TestDefs.write("};\n");




def CreateForwardAndReverseLookup(CFile,HFile,ErrorList,OrderedList):
    #ROM Sections
    CFile.write("\n/* Reverese Local to Global lookup */\n")
    CFile.write("\nconst ldef_ErrorMgr_enErrorNo ErrorMgr_ReverseLookup[ldef_ErrorMgr_ErrorNum_Max] = {")
    for val in OrderedList:
        CFile.write(str(val)+",")
    CFile.write("};\n")

    #Create enums for  Core and ASIL Specific Error faults
    for Core,Value in ErrorList.items():
        for Ratings, errorlist in Value.items():
            HFile.write("\n\t/* Orginator: ErrorMgr_Core_"+Core+" Asil "+Ratings+",*/")
            HFile.write("\ntypedef enum  {")
            for e in errorlist:
                (ErrorEnum, _, _, _,_,_,_) = e
                en = "ErrorMgr_CoreAsilSpecific_" + ErrorEnum
                HFile.write("\n\t"+en+",");
            HFile.write("\n\t"+"ErrorMgr_CoreAsilSpecific_"+Core+"_"+Ratings+",");
            HFile.write("\n}ErrorMgr_CoreAsilSpecific_"+Core+"_"+Ratings+";\n")
    


def CreateErrorDesc(HFile,ErrorList,Rating,Core,SuffixHandlePair,SatH):
    #ROM Sections

    HFile.write("#define ErrorMgr_ErrorDesc_Count_"  + Rating + "_"+ Core + "  (" + str(len(ErrorList)) + ")\n")
    for (Suffix,CFile,bCoreSpecific) in SuffixHandlePair:
        if(len(ErrorList) > 0):
            CFile.write("/* Todo: Pragma to put into correct ASIL Rated Memory section */\n")
            CFile.write("static ErrorMgr_RuntimeStateDef ErrorMgr_RunState" + Core + "_" + Rating +"_"+Suffix+ " [ErrorMgr_ErrorDesc_Count_"  + Rating + "_"+ Core +"]; \n")
            CFile.write("/* Todo: Pragma to put into correct ASIL Rated Memory section */\n")
            HFile.write("\nextern const ErrorMgr_ErrorDesc ErrorMgr_ErrorDesc_"+Core+"_"+Rating+"_"+Suffix+" [ErrorMgr_ErrorDesc_Count_"  + Rating + "_"+ Core +"];\n")
            CFile.write("const ErrorMgr_ErrorDesc ErrorMgr_ErrorDesc_"+Core+"_"+Rating+"_"+Suffix+" [ErrorMgr_ErrorDesc_Count_"  + Rating + "_"+ Core +"] = { \n")
            Count=0;
            for e in ErrorList:
                if(Count !=0):
                    CFile.write(",\n");
                Count+=1;
                (ErrorEnum, MaturationTime_ms, DematurationTime_ms, Description,SafeState, DtcInfo,_)=e
                CFile.write("\t\t/*  "+Description+" */\n");
                CFile.write("\t\t{&ErrorMgr_RunState" + Core + "_" + Rating +"_"+Suffix+"["+str(Count-1)+"] , ldef_ErrorMgr_Error_" + ErrorEnum+" , "+ MaturationTime_ms+" , "+ DematurationTime_ms+"}")
            CFile.write("\n};\n\n")




def CreateDescExt(ErrorListPerCore,Core,SuffixHandlePair):
    #ROM Sections
    for (Suffix, CFile,bCoreSpecific) in SuffixHandlePair:
        if(Core != 'CORE_MAX'):
            if bCoreSpecific == True:
                CFile.write("#if ERRORMGR_CURRENTCORE == " + CoreDefEnums[Core])
            CFile.write("\n\tconst ErrorMgr_ErrorDescExt    pErrorMgr_CoreErrorDesc_"+Core+"_"+Suffix+"[ErrorMgr_Asil_MAX] = {\n")
            for Ratings, errorlist in ErrorListPerCore.items():
                if(len(errorlist) > 0):
                    CFile.write("\t\t{&ErrorMgr_ErrorDesc_" + Core + "_" + Ratings +"_"+Suffix+ "[0],"+str(len(errorlist))+"u },\n")
                else:
                    CFile.write("\t\t{NULL,0},\n")
            CFile.write("\n\t};\n")

            if bCoreSpecific == True:
                CFile.write("\t#if ERRORMGR_CURRENTCORE == " + CoreDefEnums[Core] +"\n")
                CFile.write("\t\t#define ErrorMgr_ErrorDesc_LocalRef (&pErrorMgr_CoreErrorDesc_"+Core+"_"+Suffix+"[0])\n")
                CFile.write("\t#endif\n")

            if bCoreSpecific == True:
                CFile.write("#endif\n\n")

def CreateCommunicationStructure(CommonHFile,SatHFile,SatCFile,ErrorList,CommStrDefs,lAddArrayDataTypes,SatCommonC):

    #Common structure
    CommonHFile.write("\ntypedef struct {\n")
    CommonHFile.write("\tuint32_t             *RunningCounter;\n")
    CommonHFile.write("\tuint32_t             *Checksum;\n")
    CommonHFile.write("\tldef_ErrorMgr_ErrorField  *Error;\n")
    CommonHFile.write("\tldef_ErrorMgr_stAddData   *Data;\n")
    CommonHFile.write("\tuint16_t             Count;\n")
    CommonHFile.write("\tvoid                 *pCommData;\n")
    CommonHFile.write("}ldef_ErrorMgr_ErrorCommPack;\n\n")





    for Core, Value in ErrorList.items():
        if (Core != 'CORE_MAX'):
            for Ratings, errorlist in Value.items():
                if Ratings != "MAX":
                    ComStDef_Core=[]
                    CommonHFile.write("\ntypedef struct {\n")
                    CommonHFile.write("\tuint32_t RunningCounter;\n")
                    ComStDef_Core.append('uint32 RunningCounter')
                    CommonHFile.write("\tuint32_t Checksum;\n")
                    ComStDef_Core.append('uint32 Checksum')
                    lError=len(errorlist)
                    if(len(errorlist) == 0):
                        lError=1
                    
                    Padding=lError%4;

                    varName = "Error"
                    newDataType=varName+ Core + Ratings+"_arr"
                    newDataType_arrDef=newDataType+"["+str(lError)+"]"


                    lAddArrayDataTypes.append(('ErrorMgr_ErrorField',newDataType,newDataType_arrDef,lError))
                    ComStDef_Core.append(newDataType + "  " + varName)
                    CommonHFile.write("\tldef_"+newDataType+ "  "+varName+";\n")

                    #Since we are going intercore with varying compiler optimizations. Force size to align
                    if(Padding > 0):
                        Padding_Len=4-Padding;
                        varName = "Padding"
                        newDataType=varName+ Core + Ratings+"_arr"
                        newDataType_arrDef=newDataType+"["+str(Padding_Len)+"]"

                        lAddArrayDataTypes.append(('ErrorMgr_ErrorField',newDataType,newDataType_arrDef,lError))
                        ComStDef_Core.append(newDataType + "  " + varName)
                        CommonHFile.write("\tldef_"+newDataType+ "  "+varName+";\n")

                    varName = "Data"
                    newDataType = varName + Core + Ratings + "_arr"
                    newDataType_arrDef = newDataType + "[" + str(lError) + "]"

                    lAddArrayDataTypes.append(('ErrorMgr_stAddData',newDataType,newDataType_arrDef,lError))
                    ComStDef_Core.append(newDataType + "  " + varName)
                    CommonHFile.write("\tldef_"+newDataType+ "  "+varName+";\n")


                    ComStrName="ErrorMgr_ErrorCommPack_"+Core+"_"+Ratings;
                    CommonHFile.write("}ldef_"+ComStrName+";\n\n")
                    CommonHFile.write("\n#ifndef Rte_TypeDef_"+ComStrName)
                    CommonHFile.write("\n\ttypedef ldef_"+ComStrName+" "+ComStrName+";")
                    CommonHFile.write("\n#endif\n")

                    
                    CommStrDefs[Ratings].append((ComStrName,ComStDef_Core,lError))

            SatHFile.write("#if ERRORMGR_CURRENTCORE == " + CoreDefEnums[Core] + "\n")
            SatCommonC.write("#if ERRORMGR_CURRENTCORE == " + CoreDefEnums[Core] + "\n")

            for Ratings, errorlist in Value.items():
                if Ratings != "MAX":
                    SatCFile[Ratings].write("#if ERRORMGR_CURRENTCORE == " + CoreDefEnums[Core] + "\n")
                    SatCFile[Ratings].write("\tldef_ErrorMgr_ErrorCommPack_"+Core+"_"+Ratings+" ldef_ErrorMgr_ErrorCommPack_"+Core+"_"+Ratings+"_obj;\n")
                    SatCFile[Ratings].write("\t#define ldef_Sat_ErrorCommPack_Def_Current_Core  ldef_ErrorMgr_ErrorCommPack_"+Core+"_"+Ratings+"\n")
                    SatCFile[Ratings].write("\t#define ldef_Sat_ErrorCommPack_Current_Core  ldef_ErrorMgr_ErrorCommPack_"+Core+"_"+Ratings+"_obj\n")
                    SatHFile.write("extern ldef_ErrorMgr_ErrorCommPack_"+Core+"_"+Ratings+" ldef_ErrorMgr_ErrorCommPack_"+Core+"_"+Ratings+"_obj;\n\n")
                    SatCFile[Ratings].write("#endif\n")



            SatCommonC.write("const ldef_ErrorMgr_ErrorCommPack  ldef_ErrorMgr_ErrorCommPackRef[ErrorMgr_Asil_MAX] = {\n")
            for Ratings, errorlist in Value.items():
                if Ratings != "MAX":
                    shortStr="&ldef_ErrorMgr_ErrorCommPack_"+Core+"_"+Ratings+"_obj"
                    SatCommonC.write("\t{"+shortStr+".RunningCounter,"+shortStr+".Checksum,(ldef_ErrorMgr_ErrorField *)"+shortStr+".Error,(ldef_ErrorMgr_stAddData *)"+shortStr+".Data,ErrorMgr_ErrorDesc_Count_"+Ratings+"_"+Core+",(void *)"+shortStr+"},\n")
            SatCommonC.write("};\n")
            

            SatCommonC.write("\n#endif\n")
            SatHFile.write("\n#endif\n")

    return CommStrDefs,lAddArrayDataTypes




def Create_HandleNotifications(CFile,HFile,ErrorList):

    #HFile.write("\n\n#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE\n")
    #CFile.write("\n\n#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE\n")
    #CFile[asil].write("\n\n/* Todo : PutPragma for allocating this to correct RAM Section */\n")
    #CFile.write("static ldef_ErrorMgr_ErrorField m_AggregatedErrors[ErrorMgr_ErrorNum_Max];\n\n")

    for Core, Value in ErrorList.items():
        if (Core != 'CORE_MAX'):
            for asil in AsilList:
                if asil != 'MAX':
                    HFile.write("void ErrorMgrAggregator_HandleNotification_" + Core +"_"+asil+ "( ldef_ErrorMgr_ErrorCommPack_" + Core +"_"+asil+ " *data);\n")

                    CFile[asil].write("void ErrorMgrAggregator_HandleNotification_" + Core +"_"+asil+ "( ldef_ErrorMgr_ErrorCommPack_" + Core +"_"+asil+ " *data)\n{\n")
                    CFile[asil].write("\tconst ErrorMgr_ErrorDescExt* DescExt= ErrorMgr_getGetErrorDesc(ErrorMgr_Core_" + Core + ");\n")
                    CFile[asil].write("\tconst ErrorMgr_ErrorDesc* errDescAsil= NULL;\n")
                    CFile[asil].write("\tldef_ErrorMgr_ErrorField* SrcPtr = NULL;\n")
                    CFile[asil].write("\tuint16_t j;\n")
                    CFile[asil].write("\tbool_t dataGood = TRUE;\n\n")
                    CFile[asil].write("\tdataGood &= ErrorMgrAggregator_HandleandVerifyRunningCount(ErrorMgr_Core_"+Core+",data->RunningCounter,ErrorMgr_Asil_"+asil+");\n")
                    #CFile.write("\tfor (i = 0; i < ErrorMgr_Asil_MAX; i++) {\n")

                    CFile[asil].write("\t\terrDescAsil = DescExt[ErrorMgr_Asil_"+asil+"].ErrorDesc;\n")


                    CFile[asil].write("#if ERRORMGR_E2EPROTECTIONTYPE == ERRORMGR_E2EPROTECTIONTYPE_LOCAL\n")
                    CFile[asil].write("\t\tif (dataGood == TRUE) {\n")
                    CFile[asil].write("\t\t\tdataGood &= ErrorMgrAggregator_VerifyCRC(SrcPtr, DescExt[ErrorMgr_Asil_"+asil+"].Count, data->Checksum);\n")
                    CFile[asil].write("\t\t\t\n\t\t}\n")
                    CFile[asil].write("#endif\n")

                    CFile[asil].write("\t\tif (dataGood == TRUE) {\n")
                    CFile[asil].write("\t\t\tfor (j = 0; j < DescExt[ErrorMgr_Asil_"+asil+"].Count; j++) {\n")
					#the Reason the Core had to be appended to Error Name is because of ARXML need unique fields apparently
                    CFile[asil].write("\t\t\t\terrDescAsil[j].RamDef->bErrorActive = data->Error[j];\n")
                    CFile[asil].write("\t\t\t\tmemcpy((void*)(&errDescAsil[j].RamDef->stAddData), (void *)&data->Data[j], sizeof(ldef_ErrorMgr_stAddData));\n")
                    CFile[asil].write("\t\t\t}\n")
                    #CFile.write("\t\t}\n")

                    CFile[asil].write("\t}\n")

                    CFile[asil].write("}\n\n\n")

    #CreateAccessFunction_AccessingAggregateErrors(CFile, HFile)
    #HFile.write("#endif\n\n")
    #CFile.write("#endif\n\n")


def CreateCommonAccessFunctions(CFile,HFile):
    #ErrortoCoreMapping
    CFile.write("\n\n/* Todo: Pragma to put into correct Highest ASIL Rated Memory section */\n")
    CFile.write("/* Access function for mapping error to Core*/\n")
    CFile.write("\n\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n")
    CFile.write("ErrorMgr_ErrorMapping const *ErrorMgr_getErrorMapping(ldef_ErrorMgr_enErrorNo err) \n");
    CFile.write("{\n\tErrorMgr_ErrorMapping const *map;\n\t//map->enCore=ErrorMgr_Core_CORE_MAX;\n\t//map->enAsil=ErrorMgr_Asil_MAX;\n")
    CFile.write(" \n\tif(err < ldef_ErrorMgr_ErrorNum_Max)\n\t{\n\t\tmap=&ErrorMgr_ErrorMap[err];\n\t}\n\telse\n\t{\n\t\tmap=ERROR_MAPPING_NULL_PTR;\n\t}\n\treturn map;\n}\n")
    CFile.write("\n\n#ifdef __cplusplus\n}\n#endif\n\n")

    HFile.write("/* Access function for mapping error to Core*/\n")
    HFile.write("\n\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n")
    HFile.write("ErrorMgr_ErrorMapping const  *ErrorMgr_getErrorMapping(ldef_ErrorMgr_enErrorNo err); \n");
    HFile.write("\n\n#ifdef __cplusplus\n}\n#endif\n\n")

def CreateSatelliteAccessFunctions(CFile,HFile):

    #ErrorDesc
    CFile.write("\n\n/* Todo: Pragma to put into correct Highest ASIL Rated Memory section */\n")
    CFile.write("/* Access function for accessing the pointer to the ROM structure for ErrorMgr list*/\n")
    CFile.write("const ErrorMgr_ErrorDescExt *  ErrorMgr_getGetErrorLocalDesc(void) \n");
    CFile.write("{\n\treturn  ErrorMgr_ErrorDesc_LocalRef;\n}\n");

    HFile.write("/* Access function for accessing the pointer to the ROM structure for ErrorMgr list*/\n")
    HFile.write("const ErrorMgr_ErrorDescExt *  ErrorMgr_getGetErrorLocalDesc(void); \n");

    #ErrorComPackRef
    CFile.write("\n\n/* Todo: Pragma to put into correct Highest ASIL Rated Memory section */\n")
    CFile.write("/* Access function for accessing the pointer to the ROM structure for ErrorMgr list*/\n")
    CFile.write("const ldef_ErrorMgr_ErrorCommPack *  ErrorMgr_getErrorCommPack(ErrorMgr_AsilList asil) \n");
    CFile.write("{\n\tconst ldef_ErrorMgr_ErrorCommPack *Ret=NULL;\n");
    CFile.write("\tif(asil<ErrorMgr_Asil_MAX){\n\t\t Ret=&ldef_ErrorMgr_ErrorCommPackRef[asil];\n\t}\n");
    CFile.write("\treturn  Ret;\n}\n");

    HFile.write("/* Access function for accessing the pointer to the ROM structure for ErrorMgr list*/\n")
    HFile.write("const ldef_ErrorMgr_ErrorCommPack *  ErrorMgr_getErrorCommPack(ErrorMgr_AsilList asil); \n");

def CreateAggregatorAccessFunctions(CFile,HFile):

    #HFile.write("\n\n#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE \n");
    HFile.write("const ErrorMgr_ErrorDescExt * ErrorMgr_getGetErrorDesc(ErrorMgr_CoreList  Core);\n");
    #HFile.write("#endif \n");

    #CFile.write("\n\n#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE \n");
    CFile.write("const ErrorMgr_ErrorDescExt * ErrorMgr_getGetErrorDesc(ErrorMgr_CoreList  Core)\n");
    CFile.write("{\n");
    CFile.write("\tconst ErrorMgr_ErrorDescExt * Ret = NULL;\n");
    CFile.write("\tswitch(Core)\n");
    CFile.write("\t{\n");
    for core in coreList:
        if core != 'CORE_MAX':
            CFile.write("\t\tcase ErrorMgr_Core_" + core + ":\n");
            CFile.write("\t\t\tRet= pErrorMgr_CoreErrorDesc_"+core+"_Agg;\n");
            CFile.write("\t\t\tbreak;\n");

    CFile.write("\t\tdefault :\n");
    CFile.write("\t\t\tRet= NULL;\n");
    CFile.write("\t\t\tbreak;\n");

    CFile.write("\t}\n\treturn Ret;\n}\n");
    #CFile.write("#endif \n");

    HFile.write("\n\nbool_t ErrorMgrAggregator_VerifyCRC(ldef_ErrorMgr_ErrorField* Start, uint16_t Count, uint32_t Checksum);\n")
    HFile.write("bool_t ErrorMgrAggregator_HandleandVerifyRunningCount(ErrorMgr_CoreList Core,uint32_t RunningCount, ErrorMgr_AsilList AsilLevel);\n");


def PrintTotalErrorCountByAsilLevels(CFile,HFile,ErrCountByAsilLevel):
    HFile.write("\n\n\n")
    CFile.write("\n\n\n")
    for asil,count  in ErrCountByAsilLevel.items():
        if(asil != 'MAX'):
            HFile.write("#define ERRORMGR_COUNT_ASIL_"+asil+"   ("+str(count)+")\n")
    CFile.write("\n\nconst ErrorMgr_Count_AsilLevel [ErrorMgr_Asil_MAX] = {")
    for asil, count in ErrCountByAsilLevel.items():
        if (asil != 'MAX'):
            CFile.write("ERRORMGR_COUNT_ASIL_"+asil+",")
    CFile.write("};")
    HFile.write("\n\n")
    CFile.write("\n\n")

def Generate_SatelliteMonitoringStructures(CFile,HFile):
    #HFile.write("\n\n#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE\n")
    #CFile.write("\n\n#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE\n")

    #RamDef
    for asil in AsilList:
        if asil != 'MAX':
            CFile[asil].write("/* Todo: Put in the correct ASIL Memory */\n");
            CFile[asil].write("ErrorMgrAggregator_SatelliteMonitorConf_RamDef ErrorMgrAggregator_mSatelliteMonitorConf_RamDef_"+asil+";\n");

    #cons
    for asil in AsilList:
        if asil != 'MAX':
            CFile[asil].write("/*Todo: Put in the correct ASIL Memory */\n");
            CFile[asil].write("ErrorMgrAggregator_SatelliteMonitorConf ErrorMgrAggregator_mSatelliteMonitorConf_"+asil+"={\n");
            CFile[asil].write("\t&ErrorMgrAggregator_mSatelliteMonitorConf_RamDef_"+asil+",\n");
            CFile[asil].write("\t{\n")
            for core in coreList:
                if(core != 'CORE_MAX'):
                    CFile[asil].write("\t\tERRORMGR_TIMEOUT_CORE_"+core+"_ASIL_"+asil+"_VALUE_MS,\n")
            CFile[asil].write("\t},\n")
            CFile[asil].write("\tERRORMGR_AGGREGATORMONITOR_TASKPERIOD_ASIL_"+asil+"_MS,\n")
            CFile[asil].write("\t{\n")
            for core in coreList:
                if(core != 'CORE_MAX'):
                    CFile[asil].write("\t\tERRORMGR_TIMEOUT_CORE_"+core+"_ASIL_"+asil+"_VALUE_MS/"+"ERRORMGR_AGGREGATORMONITOR_TASKPERIOD_ASIL_"+asil+"_MS,\n")
            CFile[asil].write("\t},\n")
            CFile[asil].write("\t&ErrorMgrAggregator_Callback_HandleError_LossOfCommm_" + asil + "\n")
            CFile[asil].write("};\n\n")


            HFile.write("\n\nconst ErrorMgrAggregator_SatelliteMonitorConf * ErrorMgrAggregator_GetMonitorConf_"+asil+"(void);\n")

            CFile[asil].write("\n\nconst ErrorMgrAggregator_SatelliteMonitorConf * ErrorMgrAggregator_GetMonitorConf_"+asil+"(void) {\n")
            CFile[asil].write("\tconst ErrorMgrAggregator_SatelliteMonitorConf* Ret =&ErrorMgrAggregator_mSatelliteMonitorConf_" + asil +";\n")
            CFile[asil].write("\t\n\treturn Ret;\n}\n")

    #CFile.write("const ErrorMgrAggregator_SatelliteMonitorConf*  ErrorMgrAggregator_mSatelliteMonitorConf[ErrorMgr_Asil_MAX] = {\n")
    #for asil in AsilList:
    #    if asil != 'MAX':
    #        CFile.write(
    #            "\t&ErrorMgrAggregator_mSatelliteMonitorConf_" + asil + ",\n");
    #CFile.write("};\n")

    
    

    #for asil in AsilList:
    #    if asil != 'MAX':
    #        for core in coreList:
    #            if(core != 'CORE_MAX'):
    #                HFile.write("#define ERRORMGR_TIMEOUT_CORE_"+core+"_ASIL_"+asil+"_VALUE_MS  (50)\n")


    #HFile.write("#endif\n\n")
    #CFile.write("#endif\n\n")


def Generate_Aggregator_CallBack_Clear_Func(CallBackFile,H_Handle):
    for asil in AsilList:
        H_Handle.write("\n\nvoid ErrorMgrAggregator_Callback_Clear_" + asil + "(void);\n")
        CallBackFile[asil].write("\n\nvoid ErrorMgrAggregator_Callback_Clear_"+asil+"(void){\n")
        CallBackFile[asil].write("\n\t(void)memset((void *)&ErrorMgr_DtcStatus_"+asil+",0,sizeof(ErrorMgr_DtcStatus_"+asil+"));\n")
        CallBackFile[asil].write("\n\t(void)memset((void *)&ErrorMgr_DtcAddData_"+asil+",0,sizeof(ErrorMgr_DtcAddData_"+asil+"));\n")
        CallBackFile[asil].write("\n}\n")


def Generate_Aggregator_CallBack_Send_Func(CallBackFile):
    for asil in AsilList:
        CallBackFile[asil].write("\n\nvoid ErrorMgrAggregator_Callback_WriteDtcData_"+asil+"(void){\n")
        CallBackFile[asil].write("\n\tRte_Call_DtcData_stub_"+asil+"(&ErrorMgr_DtcStatus_"+asil+",&ErrorMgr_DtcAddData_"+asil+");\n")
        CallBackFile[asil].write("\n}\n")

def Generate_Aggregator_Notifiers_GroupedbyAsil(CallBackFile,CFile,HFile,ErrorList,Handle_RTE_OutStubsH,H_TestHandle,CommonC):
    #HFile.write("\n\n#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE\n")
    #CFile.write("\n\n#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE\n")
    #CallBackFile.write("\n\n#if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE\n")

    Defs_SS="\n\n";
    CodeSection_SS="\n\n"

    AlreadyCreatedList=[];

    Defs_SS+= "\n\n#ifdef ERRORMGR_RTESTUB_OUT_IFDEFS\n\n"


    for asil in AsilList:
        CallBackFile[asil].write("\n\n#define ERRORMGR_RTESTUB_OUT_IFDEFS\n")        
        CallBackFile[asil].write("\n\n#include \"ErrorManager_RteOutStubs.h\"\n")
        CallBackFile[asil].write("\n\n#ifdef ERRORMGR_ENABLESERIALPRINTOUT\n")
        CallBackFile[asil].write("\tconst char * ErrorMgr_enErrorStatus_String[] = {\"ErrorMgr_Invalid\",\"ErrorMgr_ErrorInactive\",\"ErrorMgr_ErrorActive\"};\n")
        CallBackFile[asil].write("#endif\n")
        CallBackFile[asil].write("ldef_DtcStatus_"+asil+"   ErrorMgr_DtcStatus_"+asil+" ERRMANAGER_ATTR_"+asil+"_HIGHPERF_BSS ;\n")
        CallBackFile[asil].write("ldef_DtcAddData_" + asil + "   ErrorMgr_DtcAddData_" + asil +" ERRMANAGER_ATTR_"+asil+"_HIGHPERF_BSS ;\n")
        CallBackFile[asil].write("\n\n#ifdef TEST_FRAMEWORK_ENABLED_RAND_42315ADdsf\n")
        CallBackFile[asil].write("\textern Std_ReturnType TEST_FRAMEWORK_DIAGMGR_CALLBACK(const char* DtcHigh, uint16_t DtcLow, uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, uint8* i_AdditionalData_pu8);\n")
        CallBackFile[asil].write("#endif\n")
        #Defs_SS+="\t\textern Std_ReturnType Rte_Call_DtcData_stub_"+asil+"(void * ErrorMgr_DtcStatus_"+asil+",void * ErrorMgr_DtcAddData_"+asil+");\n"

        #CodeSection_SS += "\n\n#ifdef RTE_ERRORMGRAGG_1_0_" + asil + "_H\n\n"

        #CodeSection_SS += "\n Std_ReturnType Rte_Call_DtcData_stub_" + asil + "(void * status,void * addData) {\n";
        #CodeSection_SS += "\t\t Rte_Write_ErrorMgrAgg_1_0_" + asil + "_P_DtcData_Data_DtcAddData_" + asil + "((DtcAddData_B *)addData);\n";
        #CodeSection_SS += "\t\t Rte_Write_ErrorMgrAgg_1_0_" + asil + "_P_DtcData_Data_DtcStatus_" + asil + "((DtcStatus_B *)status);\n";
        #CodeSection_SS += "\t\t }\n\n\n";

        #CodeSection_SS += "\n\n#endif // RTE_ERRORMGRAGG_1_0_" + asil + "_H\n\n"

    Generate_Aggregator_CallBack_Clear_Func(CallBackFile,HFile)
    Generate_Aggregator_CallBack_Send_Func(CallBackFile)

    

    """
    #Disabling the callback generation and handling it seperately for perfomance
    CommonC.write("const ErrorMgrAggregator_Callback_HandleError ErrorMgrAggregator_Notifiers[ldef_ErrorMgr_ErrorNum_Max] ={\n")
    for Core, Value in ErrorList.items():
        if (Core != 'CORE_MAX'):
            for Ratings, val2 in Value.items():
                CodeSection_SS +="\n\n#ifdef RTE_ERRORMGRAGG_1_0_"+Ratings+"_H\n\n"


                for e in val2:
                    (ErrorEnum, MaturationTime_ms, DematurationTime_ms, Description,SafeState, DtcInfo,_) = e
                    (dem,dtc,extdata,dtc_low)=DtcInfo

                    HFile.write("void ErrorMgrAggregator_Callback_HandleError_" + Ratings + "_" + Core + "_"+ErrorEnum+"(ldef_ErrorMgr_enErrorStatus status,uint8_t * AdditionalData,ErrorMgrAggregator_InternalRuntimeErrorDefs *RuntimeErr);\n")
                    CallBackFile[Ratings].write("\n\nvoid ErrorMgrAggregator_Callback_HandleError_"+ Ratings + "_" + Core + "_"+ErrorEnum+"(ldef_ErrorMgr_enErrorStatus status,uint8_t * AdditionalData,ErrorMgrAggregator_InternalRuntimeErrorDefs *RuntimeErr){\n")
                    CallBackFile[Ratings].write("\tstatic ldef_ErrorMgr_enErrorStatus PrevErrorStatus=ldef_ErrorMgr_ErrorInactive;\n")
                    dtc_str_sr=(dtc+"_"+dtc_low+"_"+extdata).lower();
                    if(dtc_str_sr != '0_0_0'):
                        CallBackFile[Ratings].write("\tif(status == ldef_ErrorMgr_ErrorActive) {\n");
                        CallBackFile[Ratings].write("\t\tErrorMgr_DtcStatus_"+Ratings+"."+dtc_str_sr+"= 0x01;\n");
                        CallBackFile[Ratings].write(
                            "\t\tmemcpy((void *)&ErrorMgr_DtcAddData_" + Ratings + "." + dtc_str_sr + ",AdditionalData,sizeof(ldef_AdditionalData_arr));\n")
                        CallBackFile[Ratings].write("\t}\n");
                    CallBackFile[Ratings].write("\tif((PrevErrorStatus != status) || (status == ldef_ErrorMgr_ErrorActive)) {\n")
                    CallBackFile[Ratings].write("\t\tPrevErrorStatus = status;\n")
                    CallBackFile[Ratings].write("\t\t// Custom error Handling\n")
                    CallBackFile[Ratings].write(
                        "\t\t#ifdef ERRORMGR_ENABLESERIALPRINTOUT\n")
                    CallBackFile[Ratings].write("\t\t\tERRORMGR_SERIALPRINTOUT_2P(\"\\nErrorstatus changed "+ErrorEnum+":: %s\",ErrorMgr_enErrorStatus_String[status]);\n")
                    CallBackFile[Ratings].write(
                        "\t\t#endif\n")
                    if(dtc != 0):                       
                        UniqueFunctionSig="Rte_Call_R_"+dtc+"_"+dtc_low+"_DTCInfo_v";
                        UniqueFunctionSig_Rating=UniqueFunctionSig+"_"+Ratings
                        if(UniqueFunctionSig_Rating not in AlreadyCreatedList):
                            AlreadyCreatedList.append(UniqueFunctionSig_Rating)
                            Defs_SS+="\t\textern Std_ReturnType "+UniqueFunctionSig_Rating+"_stub(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, uint8 * i_AdditionalData_pu8,ErrorMgrAggregator_InternalRuntimeErrorDefs *RuntimeErr);\n"
                            CodeSection_SS+="\tStd_ReturnType "+UniqueFunctionSig_Rating+"_stub(uint8 i_FaultStatus_u8, uint16 i_Fault_Flag_u16, uint8 * i_AdditionalData_pu8,ErrorMgrAggregator_InternalRuntimeErrorDefs *RuntimeErr) {\n"
                            CodeSection_SS+= "\t\t\tStd_ReturnType Ret=E_NOT_OK; \n"
                            CodeSection_SS+= "\t\t#ifdef TEST_FRAMEWORK_ENABLED_RAND_42315ADdsf\n"                           
                            CodeSection_SS+= "\t\t\tRet= TEST_FRAMEWORK_DIAGMGR_CALLBACK(\""+dtc+"\",0x"+dtc_low+",i_FaultStatus_u8, i_Fault_Flag_u16, i_AdditionalData_pu8);\n"
                            CodeSection_SS+= "\t\t#else\n"
                            CodeSection_SS+= "\t\t\t#ifdef "+UniqueFunctionSig+"\n"                            
                            CodeSection_SS+= "\t\t\t\tRet="+UniqueFunctionSig+"(i_FaultStatus_u8, i_Fault_Flag_u16, i_AdditionalData_pu8);\n"
                            CodeSection_SS+= "\t\t\t#endif\n"
                            CodeSection_SS+= "\t\t#endif\n"
                            
                            CodeSection_SS+= "\t\treturn Ret;\n\t}\n"

                        CallBackFile[Ratings].write("\t\t#ifdef ERRORMGR_ENABLE_DEM_CALLBACK\n")
                        CallBackFile[Ratings].write("\t\t\t"+UniqueFunctionSig_Rating+"_stub(status == ldef_ErrorMgr_ErrorActive?1:0,0x"+extdata+",AdditionalData,RuntimeErr);"+"\n")    
                        CallBackFile[Ratings].write("\t\t#endif\n")

                        #H_TestHandle.write("\n#define Rte_Call_R_"+dtc+"_"+dtc_low+"_DTCInfo_v_stub(x,y,z) UTEST_Rte_DTC_CALLBACK("+dtc+","+dtc_low+",x,y,z)")

                    CallBackFile[Ratings].write("\t}\n}\n")
                    CommonC.write("\t\t&ErrorMgrAggregator_Callback_HandleError_"+ Ratings + "_" + Core + "_"+ErrorEnum+",\n")
                CodeSection_SS +="\n\n#endif\n\n"
    CommonC.write("};\n")
    """

    

 
                          
     


    Defs_SS+= "\n\n#endif\n\n"

    for asil in AsilList:
        if (asil != 'MAX'):
            HFile.write("void ErrorMgrAggregator_Callback_HandleError_LossOfCommm_" + asil+"(ErrorMgr_CoreList core, ldef_ErrorMgr_enErrorStatus status);\n")
            CallBackFile[asil].write("\n\nvoid ErrorMgrAggregator_Callback_HandleError_LossOfCommm_" + asil+"(ErrorMgr_CoreList core, ldef_ErrorMgr_enErrorStatus status) {\n")
            CallBackFile[asil].write("\tstatic ldef_ErrorMgr_enErrorStatus PrevErrorStatus[ERRORMGRCORE_CORE_MAX]={")
            for C1 in coreList:
                if (C1 != 'CORE_MAX'):
                    CallBackFile[asil].write("ldef_ErrorMgr_ErrorInactive,");
            CallBackFile[asil].write("};\n")
            CallBackFile[asil].write("\tif(PrevErrorStatus[core] != status) {\n")
            CallBackFile[asil].write("\t\tPrevErrorStatus[core] = status;\n")
            CallBackFile[asil].write("\t\t// Custom error Handling\n")
            CallBackFile[asil].write("\t\tERRORMGR_SERIALPRINTOUT_3P(\"\\nErrorstatus changed LossOfComm asil "+asil+"  core:%d status:%s\",core,ErrorMgr_enErrorStatus_String[status]);\n")
            CallBackFile[asil].write("\t}\n}\n")


    #HFile.write("ErrorMgrAggregator_Callback_HandleError ErrorMgrAggregator_GetErrorHandler(ldef_ErrorMgr_enErrorNo enError);\n")
    #CommonC.write("ErrorMgrAggregator_Callback_HandleError ErrorMgrAggregator_GetErrorHandler(ldef_ErrorMgr_enErrorNo enError) {\n")
    #CommonC.write("\tErrorMgrAggregator_Callback_HandleError Ret=NULL;\n");
    #CommonC.write("\tif(enError < ldef_ErrorMgr_ErrorNum_Max) {\n");
    #CommonC.write("\t\tRet=ErrorMgrAggregator_Notifiers[enError];\n\t}\n");
    #CommonC.write("\treturn Ret;\n}\n");

    


    Handle_RTE_OutStubsH.write(Defs_SS);
    Handle_RTE_OutStubsH.write(CodeSection_SS);


    #HFile.write("#endif\n\n")
    #CFile.write("#endif\n\n")
    #CallBackFile.write("#endif\n\n")


def Generate_DTCRelated_Structs(Handle_AggregatorH,DtcStruct,structDefs):

    for asil in AsilList:
        dtc_asil=DtcStruct[asil]
        item_list=[]
        addData_list_arxml=[]
        addData_list_h=[]
        for dtc in dtc_asil:
            item_list.append("uint8 "+dtc)
            addData_list_arxml.append("AdditionalData_arr "+dtc)
            addData_list_h.append("ldef_AdditionalData_arr "+dtc)
        structDefs[asil].append(("DtcStatus_"+asil,item_list,len(item_list)))
        structDefs[asil].append(("DtcAddData_"+asil,addData_list_arxml,len(addData_list_arxml)))

        Handle_AggregatorH.write("\ntypedef struct { ")
        for s in item_list:
            Handle_AggregatorH.write("\n\t"+s+";")
        Handle_AggregatorH.write("\n}ldef_DtcStatus_"+asil+";\n");

        Handle_AggregatorH.write("\ntypedef struct { ")
        for s in addData_list_h:
            Handle_AggregatorH.write("\n\t"+s+";")
        Handle_AggregatorH.write("\n}ldef_DtcAddData_"+asil+";\n");




def ParseExcelAndGenerateData(ExcelFilePath,Handle_CommonH,Handle_CommonC,Handle_SatelliteC,Handle_SatelliteH,Handle_AggregatorC,Handle_AggregatorH,Handle_Callback,Handle_RTE_OutStubsH,Handle_TestDefs,AggCommonC,SatCommonC):
    SuffixPairs = dict([(asil, [("Sat", Handle_SatelliteC[asil],True),("Agg", Handle_AggregatorC[asil],False)]) for asil in AsilList])
    SuffixCommonPairs = [("Sat", SatCommonC,True),("Agg", AggCommonC,False)]
    AdditionalArrayDataTypes=[]
    CommStructDefs = dict([(asil, []) for asil in AsilList])
    DtcStructDefs=dict([(asil, []) for asil in AsilList])

    (GErrorList, SafeStateList, ErrCountByAsilLevel,FidResDetails,DtcStruct)=ParseErrorManagerExcelfile(ExcelFilePath)

    #Create Common Enum Definitions
    EnumLists,IsErrorsApplicableCoreAsil=CreateEnumDefinitions(Handle_CommonH,GErrorList,SafeStateList,Handle_TestDefs)
    #Create the Error Mapping Table
    CreateErrorMappingTable(Handle_CommonC,Handle_CommonH,GErrorList,Handle_TestDefs)

    #Create the ErrorDescription ROM and RAM Variables
    for Core,Value in GErrorList.items():
        if (Core != 'CORE_MAX'):
            Handle_SatelliteH.write("\n\n/* ErrorDefintions for Core" + Core + "    */\n")
            Handle_SatelliteH.write("#if ERRORMGR_CURRENTCORE == " + CoreDefEnums[Core] )
            for Ratings, errorlist in Value.items():
                Handle_AggregatorC[Ratings].write("\n\n/* ErrorDefintions for Core" + Core + "    */\n")
                Handle_SatelliteC[Ratings].write("\n\n/* ErrorDefintions for Core" + Core+"    */\n")
                Handle_SatelliteC[Ratings].write("#if ERRORMGR_CURRENTCORE == " + CoreDefEnums[Core])
                CreateErrorDesc(Handle_CommonH,errorlist,Ratings,Core,SuffixPairs[Ratings],Handle_SatelliteH)
                Handle_SatelliteC[Ratings].write("\n#endif\n\n\n");
            Handle_SatelliteH.write("\n#endif\n\n\n");
            
            #HFile.write("\n#endif\n\n\n");


    #Create the ErrorDescription ROM ExtLookup Tables
    for Core, Value in GErrorList.items():
        if (Core != 'CORE_MAX'):
            CreateDescExt(Value,Core,SuffixCommonPairs)


    CommStructDefs,AdditionalArrayDataTypes=CreateCommunicationStructure(Handle_CommonH,Handle_SatelliteH,Handle_SatelliteC,GErrorList,CommStructDefs,AdditionalArrayDataTypes,SatCommonC)
    
  

    Create_HandleNotifications(Handle_AggregatorC, Handle_AggregatorH, GErrorList)
    Generate_SatelliteMonitoringStructures(Handle_AggregatorC, Handle_AggregatorH)
    Generate_Aggregator_Notifiers_GroupedbyAsil(Handle_Callback,None,Handle_AggregatorH,GErrorList,Handle_RTE_OutStubsH,Handle_TestDefs,AggCommonC)
    #Create the structures related to DTC Output
    
    Generate_DTCRelated_Structs(Handle_AggregatorH,DtcStruct,DtcStructDefs)
    CreateCommonAccessFunctions(Handle_CommonC,Handle_CommonH)


    CreateAggregatorAccessFunctions(AggCommonC,Handle_AggregatorH)
    CreateSatelliteAccessFunctions(SatCommonC, Handle_SatelliteH)

    Add_Agg_RuntimDefs(Handle_AggregatorC,Handle_AggregatorH)
    Add_Sat_RuntimDefs(Handle_SatelliteC,Handle_SatelliteH)


    return ((GErrorList,EnumLists,CommStructDefs,AdditionalArrayDataTypes,FidResDetails),DtcStructDefs)




def Commit_SharedTypes_H(HFile,ArrDatTypes):

    HFile.write("\n#define ERRORMGR_ADDITIONALDATASIZE_COUNT	("+str(ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE)+")\n")

    HFile.write("\ntypedef  bool_t  ldef_ErrorMgr_ErrorField;\n")

    HFile.write(
        "\ntypedef uint8_t ldef_AdditionalData_arr[ERRORMGR_ADDITIONALDATASIZE_COUNT]; \n")
    HFile.write(
        "\ntypedef struct {\n\tldef_AdditionalData_arr AdditionalData; \n}ldef_ErrorMgr_stAddData;\n")

    #HFile.write("\n#ifndef Rte_TypeDef_ErrorMgr_enErrorStatus\n")
    HFile.write("\n\ttypedef enum {\n\tldef_ErrorMgr_Invalid,\n\tldef_ErrorMgr_ErrorInactive,\n\tldef_ErrorMgr_ErrorActive\n}ldef_ErrorMgr_enErrorStatus;\n")
    #HFile.write("\n#endif\n")

    for baseDType,arrDtype,ArrrDef,Count in ArrDatTypes:
        HFile.write("\ntypedef ldef_"+baseDType+" ldef_"+ArrrDef+";\n")

# Function defined to print data in ErrorData_B_QM.py file
def Commit_ErrorData_B_QM_PY(HFile,Fault_Data):
    HFile.write(Fault_Data)
    HFile.write("\n")

# Function defined to print data in FD62_data.xls or FD64_data.xls file
def write_ErrorData_QM_or_B_Excel(HFile,Fault_Data):
        my_wb = openpyxl.Workbook(HFile)
        mysheet = my_wb.active      
        HFile.write(Fault_Data)
        HFile.write("\n")
    
        


def GenerateDigListPerAsil(exData):
    DemDefs = dict([(asil, []) for asil in AsilList])
    DtcDefs = dict([(asil, []) for asil in AsilList])
    ExDtcData = dict([(asil, []) for asil in AsilList])
    DTCWithLowData = dict([(asil, []) for asil in AsilList])
    for Core, Value in exData.items():
        if (Core != 'CORE_MAX'):
            for Ratings, errorlist in Value.items():
                for e in errorlist:
                    (ErrorEnum, MaturationTime_ms, DematurationTime_ms, Description, SafeState, DiagList,_) = e
                    (dem, dtc, extdata, dtc_low) = DiagList
                    if (dem not in DemDefs[Ratings]) and (dem != '0'):
                        DemDefs[Ratings].append(dem)
                    if dtc not in DtcDefs[Ratings] and (dtc != '0'):
                        DtcDefs[Ratings].append(dtc)
                    if extdata not in ExDtcData[Ratings] and (extdata != '0'):
                        ExDtcData[Ratings].append(extdata)
                    dlowCombined=dtc+"_"+dtc_low
                    if dlowCombined not in DTCWithLowData[Ratings] and (dtc != '0'):
                        DTCWithLowData[Ratings].append(dlowCombined)
    return(DemDefs,DtcDefs,ExDtcData,DTCWithLowData)


Gen_ErrorManagerSatellite_GenCFile= "ErrorManagerSatelliteDef";
Gen_ErrorManagerSatellite_GenHFile=  "ErrorManagerSatelliteDef";
Gen_ErrorManagerAggregator_GenCFile= "ErrorManagerAggregatorDef";
Gen_ErrorManagerAggregator_GenHFile=  "ErrorManagerAggregatorDef";

def Add_AggErrManagerGenCode(C_Handle,H_Handle):
    for asil in AsilList:
        with open("Gen_"+Gen_ErrorManagerAggregator_GenCFile+"_"+asil+".c", "r") as firstfile:
            for line in firstfile:
                C_Handle[asil].write(line)

        C_Handle[asil].write("\n")

        with open("Gen_"+Gen_ErrorManagerAggregator_GenHFile+"_"+asil+".h", "r") as firstfile:
            for line in firstfile:
                H_Handle.write(line)

    H_Handle.write("\n")

def Add_SatErrManagerGenCode(C_Handle,H_Handle):

    for asil in AsilList:
        with open("Gen_"+Gen_ErrorManagerSatellite_GenCFile+"_"+asil+".c", "r") as firstfile:
            for line in firstfile:
                C_Handle[asil].write(line)

        C_Handle[asil].write("\n")

        with open("Gen_"+Gen_ErrorManagerSatellite_GenHFile+"_"+asil+".h", "r") as firstfile:
            for line in firstfile:
                H_Handle.write(line)

    H_Handle.write("\n")


def Add_Agg_RuntimDefs(C_Handle,H_Handle):

    for asil in AsilList:
        C_Handle[asil].write("\n\nErrorManagerAggregator_RuntimeDefs ErrorMgrAgg_RamDef_"+asil+";\n")
        H_Handle.write("\n\nextern ErrorManagerAggregator_RuntimeDefs ErrorMgrAgg_RamDef_"+asil+";\n")

    for asil in AsilList:
        C_Handle[asil].write("\n\n#ifdef ERROR_MANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION\n")
        C_Handle[asil].write("\tvolatile ErrorMgr_stErrorNo_"+asil+"   Debug_ErrMgr_"+asil+";\n")
        C_Handle[asil].write("\tErrorMgr_stErrorNo_" + asil + "* ErrorMgrAgg_GetDebug_ErrMgrSt_" + asil + "() { return (ErrorMgr_stErrorNo_" + asil + "* )&Debug_ErrMgr_"+asil+"; }\n")
        C_Handle[asil].write(
            "\tuint32_t ErrorMgrAgg_GetDebug_ErrMgrStSize_" + asil + "() { return sizeof(Debug_ErrMgr_" + asil + "); }\n")

        C_Handle[asil].write("#endif\n")
        C_Handle[asil].write("\tvolatile ErrorMgr_stErrorDbgCount_" + asil + "   Debug_ErrCount_" + asil + ";\n")
        C_Handle[asil].write("\tErrorMgr_stErrorDbgCount_" + asil + "* ErrorMgrAgg_GetDebug_ErrCount_" + asil + "() { return (ErrorMgr_stErrorDbgCount_" + asil + "*)&Debug_ErrCount_" + asil + ";}\n")
        H_Handle.write("\n\n#ifdef ERROR_MANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION\n")
        #H_Handle.write("\textern volatile ErrorMgr_stErrorNo_"+asil+"   Debug_ErrMgr_"+asil+";\n")
        #H_Handle.write("\textern volatile ErrorMgr_stErrorDbgCount_" + asil + "   Debug_ErrCount_" + asil + ";\n")
        H_Handle.write(
            "\tErrorMgr_stErrorNo_" + asil + "* ErrorMgrAgg_GetDebug_ErrMgrSt_" + asil + " (void);\n")
        H_Handle.write(
            "\tuint32_t ErrorMgrAgg_GetDebug_ErrMgrStSize_" + asil + "(void); \n")
        H_Handle.write("#endif\n")
        H_Handle.write(
            "\tErrorMgr_stErrorDbgCount_" + asil + "* ErrorMgrAgg_GetDebug_ErrCount_" + asil + "(void);\n")

def Add_Sat_RuntimDefs(C_Handle,H_Handle):

    for asil in AsilList:
        C_Handle[asil].write("\n\nuint32_t ErrorMgr_Satellite_"+asil+"_RunningCount;\n")
        H_Handle.write("\n\nextern uint32_t ErrorMgr_Satellite_"+asil+"_RunningCount;\n")

    for asil in AsilList:
        C_Handle[asil].write("\n\n#ifdef ERROR_MANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION\n")
        C_Handle[asil].write("\t#ifdef ErrorMgr_LocalDef_ST_Core_Specific_" + asil + " \n")
        C_Handle[asil].write("\t\tvolatile ErrorMgr_LocalDef_ST_Core_Specific_"+asil+" Debug_Sat_"+asil+"_Output;\n")
        C_Handle[asil].write("\t#endif\n")
        C_Handle[asil].write("#endif\n")
        H_Handle.write("\n\n#ifdef ERROR_MANAGER_DEBUG_ENABLEREADABLESTRUCT_REPRESENTATION\n")
        H_Handle.write("\t#ifdef ErrorMgr_LocalDef_ST_Core_Specific_" + asil + " \n")
        H_Handle.write("\t\textern volatile ErrorMgr_LocalDef_ST_Core_Specific_"+asil+" Debug_Sat_"+asil+"_Output;\n")
        H_Handle.write("\t#endif\n")
        H_Handle.write("#endif\n")

    


def AddMemmapHeader(fHandle,memapFile):
    fHandle.write("\n/* MeMmap File */\n")
    fHandle.write("\n#include \""+memapFile+"\"\n\n\n")


if __name__ == '__main__':

    #CurrentPath=os.path.abspath(os.getcwd())
    CurrentPath=os.path.dirname(os.path.realpath(__file__))
    ExcelFilePath=os.path.join(CurrentPath,"./../cfg/","ErrorManager - Degradation Matrix.xlsx")
    #ExcelFilePath = "C:\\Users\\bishrave\\Downloads\\ErrorManager - Degradation Matrix.xlsx"
    CallBackOutputpath = os.path.join(CurrentPath, "./../gen/", "ErrorManagerCallbacks.c")

    CommonH = os.path.join(CurrentPath, "./../gen/", "ErrorManagerDef.h")
    SatelliteH=os.path.join(CurrentPath,"./../gen/","ErrorManagerSatelliteDef.h")
    AggregatorH=os.path.join(CurrentPath,"./../gen/","ErrorManagerAggregatorDef.h")

    
    SharedH = os.path.join(CurrentPath, "./../gen/", "ErrorManagerShared.h")
    RTE_OutStubsH = os.path.join(CurrentPath, "./../gen/", "ErrorManager_RteOutStubs.h")
    TestDefs=os.path.join(CurrentPath,"./../test/support/","ErrorManagerTestDef.h")

    CommonC = os.path.join(CurrentPath, "./../gen/", "ErrorManagerDef.c")
    AggCommonC = os.path.join(CurrentPath, "./../gen/", "ErrorManagerAggDef.c")
    SatCommonC = os.path.join(CurrentPath, "./../gen/", "ErrorManagerSatDef.c")

    ErrorDataPY = os.path.join(CurrentPath, "./../gen/FD62_FD64_Data/", "ErrorData_B_QM.py")               # Where to generate file ErrorData_B_QM.py
    my_path_FD62_QM = os.path.join(CurrentPath, "./../gen/FD62_FD64_Data/","FD62_data.xls")		   # Where to generate file FD62_data.xls
    my_path_FD64_B = os.path.join(CurrentPath, "./../gen/FD62_FD64_Data/","FD64_data.xls")		   # Where to generate file FD64_data.xls	

    SatelliteC=dict([(asil, os.path.join(CurrentPath, "./../gen/", "ErrorManagerSatelliteDef_"+asil+".c")) for asil in AsilList])    
    AggregatorC=dict([(asil, os.path.join(CurrentPath, "./../gen/", "ErrorManagerAggregatorDef_"+asil+".c")) for asil in AsilList])
    CallBackOutputpath = dict([(asil, os.path.join(CurrentPath, "./../gen/", "ErrorManagerCallbacks_"+asil+".c")) for asil in AsilList])
    


 

    #Open handles for C file and H file output
    Handle_CommonH=open(CommonH,"w")
    Handle_SatelliteH = open(SatelliteH, "w")
    Handle_AggregatorH = open(AggregatorH, "w")
    Handle_SharedH = open(SharedH, "w")
    Handle_RTE_OutStubsH = open(RTE_OutStubsH, "w")
    Handle_TestDefs = open(TestDefs, "w")

    Handle_CommonC = open(CommonC, "w")
    Handle_AggCommonC = open(AggCommonC, "w")
    Handle_SatCommonC = open(SatCommonC, "w")

    Handle_ErrorDataPY = open(ErrorDataPY, "w")				
    Handle_FD62_QM = open(my_path_FD62_QM, "w")
    Handle_FD64_B = open(my_path_FD64_B, "w")	
    

    Handle_SatelliteC = dict([(asil, open(SatelliteC[asil], "w") ) for asil in AsilList])
    Handle_AggregatorC = dict([(asil, open(AggregatorC[asil], "w") ) for asil in AsilList])
    Handle_Callback=dict([(asil, open(CallBackOutputpath[asil], "w") ) for asil in AsilList])
    


    GenerateIncludeGaurds(Handle_CommonH,"ERRORMGR_COMMON_GEN_DEF")
    GenerateIncludeGaurds(Handle_SatelliteH, "ERRORMGR_SATELLITE_GEN_DEF")
    GenerateIncludeGaurds(Handle_AggregatorH, "ERRORMGR_AGGREGATOR_GEN_DEF")
    GenerateIncludeGaurds(Handle_SharedH, "ERRORMGR_ADDDTYPES_GEN_DEF")
    GenerateIncludeGaurds(Handle_RTE_OutStubsH, "ERRORMGR_RTE_OUT_STUB_DEFS")
    GenerateIncludeGaurds(Handle_TestDefs, "ERRORMGR_TESTDEFS_DEFS")

    AddCommonFileHeaders(Handle_CommonH)
    AddCommonFileHeaders(Handle_SatelliteH)
    AddCommonFileHeaders(Handle_AggregatorH)

    #AddFileHeaders(Handle_CommonH, ["ErrorManagerShared.h"])
    AddFileHeaders(Handle_SatelliteH,["ErrorManagerDef.h"])
    AddFileHeaders(Handle_AggregatorH, ["ErrorManagerDef.h"])
    AddFileHeaders(Handle_TestDefs, ["vector"])

    Handle_AggregatorH.write("\n #if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE \n")

    AddFileHeaders(Handle_CommonC, ["ErrorManagerDef.h","ErrorManagerAggregatorDef.h"])
    AddFileHeaders(Handle_AggCommonC, ["ErrorManagerDef.h","ErrorManagerAggregatorDef.h"])
    AddFileHeaders(Handle_SatCommonC, ["ErrorManagerDef.h","ErrorManagerSatelliteDef.h"])
    

    for asil in AsilList:
        
        AddFileHeaders(Handle_SatelliteC[asil],["ErrorManagerDef.h","ErrorManagerSatelliteDef.h","string.h"])
        Handle_Callback[asil].write( "\n #define RTE_ERRORMGRAGG_RTE_STUB_IFDEFS \n")
        AddFileHeaders(Handle_Callback[asil], ["ErrorManagerDef.h","ErrorManagerAggregatorDef.h","ErrorManager_Rte.h","string.h"])
        AddFileHeaders(Handle_AggregatorC[asil], ["ErrorManagerDef.h", "ErrorManagerAggregatorDef.h","string.h"])

        Handle_AggregatorC[asil].write("\n #if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE \n")
        Handle_Callback[asil].write("\n #if ERRORMGR_CURRENTCORE == ERRORMGR_AGGREGATORCORE \n")

    version_info=ReadExcelFileVersion(ExcelFilePath)
    #Add version info to generated files
    EmbedGenInfo(Handle_CommonC,version_info)
    EmbedGenInfo(Handle_AggCommonC, version_info)
    EmbedGenInfo(Handle_SatCommonC, version_info)
    EmbedGenInfo(Handle_SatelliteH, version_info)
    EmbedGenInfo(Handle_AggregatorH, version_info)
    EmbedGenInfo(Handle_TestDefs, version_info)
    EmbedGenInfo(Handle_SharedH, version_info)
    EmbedGenInfo(Handle_RTE_OutStubsH, version_info)
    EmbedGenInfo(Handle_CommonH, version_info)
    for asil in AsilList:
        EmbedGenInfo(Handle_SatelliteC[asil], version_info)
        EmbedGenInfo(Handle_AggregatorC[asil], version_info)
        EmbedGenInfo(Handle_Callback[asil], version_info)

    #Add Memap
    AddMemmapHeader(Handle_CommonC,"ErrorManager_Common_Memmap.h")
    AddMemmapHeader(Handle_AggCommonC, "ErrorManager_Common_Memmap.h")
    AddMemmapHeader(Handle_SatCommonC, "ErrorManager_Common_Memmap.h")
    for asil in AsilList:
        AddMemmapHeader(Handle_SatelliteC[asil], "ErrorManagerSat_"+asil+"_Memap.h")
        AddMemmapHeader(Handle_AggregatorC[asil], "ErrorManagerAgg_"+asil+"_Memap.h")
        AddMemmapHeader(Handle_Callback[asil], "ErrorManagerAgg_"+asil+"_Memap.h")


    (mParsedData,DtcStructDefs) = ParseExcelAndGenerateData(ExcelFilePath,Handle_CommonH,Handle_CommonC,Handle_SatelliteC,Handle_SatelliteH,Handle_AggregatorC,Handle_AggregatorH,Handle_Callback,Handle_RTE_OutStubsH,Handle_TestDefs,Handle_AggCommonC,Handle_SatCommonC)
    (GlobalErrorList,ParsedEnumLists,ParsedCommStructDefs,ParsedAdditionalArrayDataTypes,FidResDetails) = mParsedData



    #Generate the QNX Access Functions
    GenerateQNXFunctions(mParsedData,CurrentPath,"./../adapt/qnx/",version_info)
    
    Commit_SharedTypes_H(Handle_SharedH, ParsedAdditionalArrayDataTypes)

    
    Add_SatErrManagerGenCode(Handle_SatelliteC,Handle_SatelliteH)
    Add_AggErrManagerGenCode(Handle_AggregatorC,Handle_AggregatorH)


    #Generate TestDefinitions for Degradation Manager
    if(config_Generate_unitTestcases == True):
        CreateDegradationTestCaseDefinitions(mParsedData,ExcelFilePath,Handle_TestDefs)
        Create_ErrorMgr_ErrorDtcStruct_RelationshipTable(GlobalErrorList,Handle_TestDefs)
        Create_Error_SafeState_RelationshipTable(GlobalErrorList,ParsedEnumLists,Handle_TestDefs)
        Create_Error_Fid_Res_ConvFunctionsTests(mParsedData,Handle_TestDefs)


    Handle_AggregatorH.write("\n #endif \n")
    for asil in AsilList:
        Handle_AggregatorC[asil].write("\n #endif \n")    
        Handle_Callback[asil].write("\n #endif \n")

    CloseIncludeGaurds(Handle_SatelliteH);
    CloseIncludeGaurds(Handle_AggregatorH);
    CloseIncludeGaurds(Handle_CommonH);
    CloseIncludeGaurds(Handle_SharedH);
    CloseIncludeGaurds(Handle_RTE_OutStubsH);
    CloseIncludeGaurds(Handle_TestDefs);

    

    #close the file handles
    Handle_CommonH.close()    
    Handle_SatelliteH.close()    
    Handle_AggregatorH.close()    
    Handle_SharedH.close()
    Handle_RTE_OutStubsH.close();
    Handle_TestDefs.close();
    Handle_CommonC.close()
    Handle_AggCommonC.close()
    Handle_SatCommonC.close()
    Handle_ErrorDataPY.close()			
    Handle_FD62_QM.close()
    Handle_FD64_B.close()	

    for asil in AsilList:
        
        Handle_SatelliteC[asil].close()
        Handle_Callback[asil].close()
        Handle_AggregatorC[asil].close()

    #Generate Data for Degradation Manager

    #Generate ARXML
    DiagDefDicts=GenerateDigListPerAsil(GlobalErrorList)
    GenerateArxml(ParsedEnumLists,CurrentPath,ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE,ParsedCommStructDefs,ParsedAdditionalArrayDataTypes,DiagDefDicts,DtcStructDefs)

    #Genarate Degradation Matrix
    Generate_DegardationMatrix(CurrentPath,FidResDetails,GlobalErrorList,ParsedEnumLists,version_info)



    DocumentationFolder = os.path.join(CurrentPath, "./../doc/")
    GenerateDocumentation(DocumentationFolder,mParsedData)

    if(config_GenerateFD56Files == True):
        (_,_,asilenums,_)=ParsedEnumLists
        GenerateFD56_DebugInfo(asilenums,os.path.join(CurrentPath, "./../tools/FD56"))

    
