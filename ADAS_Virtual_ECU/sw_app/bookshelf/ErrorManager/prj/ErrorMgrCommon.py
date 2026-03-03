ErrorManager_GeneratorVersion="23.04.20"



config_Generate_unitTestcases=True
config_Check_AsilDependecy=True
config_GenerateFD56Files=False

coreList = ['1_0', '2_0', '2_1', 'QNX']
AsilList = ['QM', 'B']
DummyGenerationAsilList = ['A', 'C', 'D']
qnxCoreLists = ['QNX']
qnxAsilLists = ['QM']
CoreDefEnums = {'1_0': 'ERRORMGRCORE_MCU1_0', '2_0': 'ERRORMGRCORE_MCU2_0', '2_1': 'ERRORMGRCORE_MCU2_1', 'QNX': 'ERRORMGRCORE_MCUQNX', 'CORE_MAX':'ERRORMGRCORE_CORE_MAX'}
ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE=4
ErrorMgr_enErrorStatus = ['ErrorMgr_Invalid', 'ErrorMgr_ErrorInactive', 'ErrorMgr_ErrorActive']

Satellite_ModuleList=[
        ("ErrorMgrSat_1_0_QM",'1_0','QM',False),
        ("ErrorMgrSat_1_0_B",'1_0','B',False),
        ("ErrorMgrSat_2_0_QM",'1_0','QM',True),
        ("ErrorMgrSat_2_0_B",'1_0','B',True),
        ("ErrorMgrSat_2_1_QM",'2_1','QM',True),
        ("ErrorMgrSat_2_1_B",'2_1','B',True)
    ]
Agg_ModuleList = [("ErrorMgrAgg_1_0_QM",'QM'), ("ErrorMgrAgg_1_0_B",'B')]
Deg_ModuleList = [("DegManager_QM",'QM'),  ("DegManager_B",'B')]

ErrorMgr_GlobalPadding = 4 
ErrorMgr_Qnx_DevicePathBase="/dev/Err_"


User_Cols_ErrorDefSheet='A:FF'
User_Cols_FidSheet='A:Z'
User_Cols_RESSheet='A:Z'


def GenerateIncludeGaurds(HFile,Name):
    HFile.write("#ifndef "+Name+"_H_INCGUARD \n")
    HFile.write("#define "+Name+"_H_INCGUARD \n\n\n\n")

def CloseIncludeGaurds(HFile):
    HFile.write("\n\n#endif /* End Include Guard */\n")

def AddFileHeaders(CFile,ListofHeaders):
    for h in ListofHeaders:
        CFile.write("#include \""+h+"\"\n")
    CFile.write("\n\n");

def AddVersionInfo(fd,identifier,identifierversion):
    fd.write("\n/**************************************************************************************************")
    fd.write("\n          version Info   ")
    fd.write("\n***************************************************************************************************/")
    fd.write("\n#define ERROMANAGER_"+identifier+"_VERSION              "+identifierversion)
    fd.write("\n#define ERROMANAGER_"+identifier+"_GENERATOR_VERSION    "+ErrorManager_GeneratorVersion)
    fd.write("\n\n")

def PrintGenerated_NonModifyisclaimer(fd):
    fd.write("\n/**************************************************************************************************")
    fd.write("\n          This file is generated. Any changes will be overwritten. No handmodifications allowed   ")
    fd.write("\n          ErrorManager generator version used"+ErrorManager_GeneratorVersion+"                     ")
    fd.write("\n***************************************************************************************************/")
    fd.write("\n\n")



def DebugPrintWrap(str,tabcount=0):
    tabstr=""
    for i in range (0,tabcount):
        tabstr+='\t'
    strOuput="\n"+tabstr+"#ifdef ErrorMgr_QNX_Enable_DebugPrints\n"
    strOuput+=tabstr+"\t"+str+"\n"
    strOuput +=tabstr+"#endif\n"
    return strOuput

def CheckAsilDependecy(outputAsil, SourceAsil):
    if config_Check_AsilDependecy == True :
        AsilDependecy_Check=False
        if(outputAsil not in AsilList) or (SourceAsil not in AsilList):
            AsilDependecy_Check=False
        elif(outputAsil == SourceAsil):
            AsilDependecy_Check=True
        elif (outputAsil == 'QM' and SourceAsil == "B"):
            AsilDependecy_Check = True
    else:
        AsilDependecy_Check = True
    return AsilDependecy_Check


def GetMinUint32Satisfying_PackedAsBits(InputSize):
    if(InputSize%32 == 0):
        output=InputSize/32
    else:
        output=(InputSize/32)+1

    return int(output)


