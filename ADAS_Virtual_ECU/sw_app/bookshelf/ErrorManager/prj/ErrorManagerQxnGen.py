import pandas as pd
import os
import sys
from ErrorMgr_ArxmlGen import GenerateArxml
from ErrorMgrCommon import coreList,AsilList,CoreDefEnums,ERRORMGR_ADDITIONALDATASIZE_COUNT_VALUE,qnxCoreLists,qnxAsilLists,ErrorMgr_Qnx_DevicePathBase ,DebugPrintWrap,PrintGenerated_NonModifyisclaimer,AddVersionInfo
from ErrorMgrExcelDataParser import ParseErrorManagerExcelfile
from DegradationMgr_Gen import Generate_DegardationMatrix
from ErrorMgrCommon import GenerateIncludeGaurds,CloseIncludeGaurds,AddFileHeaders
from GenInfoEmbedder import EmbedGenInfo




def GenerateFunctionBlock(errorEnum):

    sc=""
    fptr=("ErrorMgrQnx_io_write_" + errorEnum );
    hdef=("\tint ErrorMgrQnx_io_write_" + errorEnum + " (resmgr_context_t *ctp, io_write_t *msg, RESMGR_OCB_T *ocb);\n");
    sc+=("int ErrorMgrQnx_io_write_" + errorEnum + " (resmgr_context_t *ctp, io_write_t *msg, RESMGR_OCB_T *ocb){\n");
    sc+=("\tint status=0;BaseSWCommon_QNX_ReturnType sRet;size_t nbytes;ldef_ErrorMgr_QnxErrorStatus mTempData; bool_t bTemp;\n");
    sc+=(DebugPrintWrap("appLogPrintf(\"\\nErrorMgrQnx__Write ::"+errorEnum+"  \");",1));
    sc+=("\tsRet=BaseSWCommon_qnx_Write_CheckConditions(ctp,msg,ocb,&status);\n");
    sc+=("\tif(sRet == BaseSWCommon_QNX_Ret_Success) {\n");
    sc+=("\t\tnbytes = _IO_WRITE_GET_NBYTES(msg);\n");
    sc+=("\t\tif(nbytes == sizeof(ldef_ErrorMgr_QnxErrorStatus)){\n");
    sc+=("\t\t\t_IO_SET_WRITE_NBYTES (ctp, nbytes);\n");
    sc+=("\t\t\tresmgr_msgread(ctp, &mTempData, nbytes, sizeof(msg->i));\n");
    sc+=("\t\t\tbTemp=ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_"+ errorEnum+",mTempData.enErrorStatus,&mTempData.AddData);\n");
    sc+=("\t\t\tif(bTemp == FALSE) { \n");
    sc+=(DebugPrintWrap("\tappLogPrintf(\"\\ErrorMgrSatellite_ReportErrorStatus::Returned Failurew ::"+errorEnum+"  \");",4));
    sc+=("\t\t\t\treturn EBADMSG; \n\t\t\t}\n");
    sc+=("\t\t\tocb->attr->flags |= IOFUNC_ATTR_MTIME | IOFUNC_ATTR_CTIME;\n");
    sc+=("\t\t\treturn (_RESMGR_NPARTS (0));\n");
    sc+=("\t\t} else {\n");
    sc+=(DebugPrintWrap("\tappLogPrintf(\"\\nErrorMgrQnx_Write::Size Mismatch ::"+errorEnum+" \");",3));
    sc+=("\t\t\treturn EBADMSG; \n\t\t}\n");
    sc+=("\t} else {\n");
    sc+=(DebugPrintWrap("\tappLogPrintf(\"\\nErrorMgrQnx_Write::Conditions check Failed ::"+errorEnum+"  \");",2));
    sc+=("\t\treturn status; \n\t}\n");                
    sc+=("}\n");

    return (sc,hdef,fptr)

def Generate_AppAccessFunctions(write_fptr_list):
    sstream=""
    for wptrs in write_fptr_list:
        (errEnum,wfptr)=wptrs
        sstream+="static BaseSw_Qnx_DataIf_MetaData ErrorMgr_MetaData_"+errEnum+"={\""+ErrorMgr_Qnx_DevicePathBase+errEnum+"\",Bsw_TRUE,-1,Bsw_FALSE};\n"

    sstream+="\n\n"
    sstream+="bool_t ErrorMgrSatelliteQnx_ReportErrorStatus(ldef_ErrorMgr_enErrorNo err, ldef_ErrorMgr_enErrorStatus enErrorStatus,const ldef_ErrorMgr_stAddData *AddData)\n"
    sstream+="{\n"
    sstream+="\t"+"bool_t bRet=FALSE;\n"
    sstream+="\t"+"switch(err) {\n"
    for wptrs in write_fptr_list:
        (errEnum,wfptr)=wptrs
        sstream+="\t\t"+"case ldef_ErrorMgr_Error_"+errEnum+":"+"{ \n"
        sstream+="\t\t\t"+"bRet= ErrorMgrSatelliteQnx_Write(&ErrorMgr_MetaData_"+errEnum+",enErrorStatus,AddData);"+"\n"
        sstream+="\t\t"+"}"+"\n";
        sstream+="\t\t"+"break;"+"\n";

    sstream+="\t\t"+"default: \n"
    sstream+="\t\t\t"+"break;   \n"
    sstream+="\t"+"}"+"\n"
    sstream+="\t"+"return bRet;\n"
    sstream+="}\n"

    return sstream



def Generate_VirtualDeviceList(write_fptr_list):
    WriteOnlyPermission="0666"
    itemCount=len(write_fptr_list)
    sstream="static const BaseSWCommon_VirtualDeviceDef ErrorMgr_VirtualDevDefs[ErrorMgr_VirtualDevDefs_Count]= {\n"
    for wptrs in write_fptr_list:
        (errEnum,wfptr)=wptrs
        sstream+="{\""+ErrorMgr_Qnx_DevicePathBase+errEnum+"\","+WriteOnlyPermission+",sizeof(ldef_ErrorMgr_QnxErrorStatus),NULL,&"+wfptr+"},\n"
    sstream+="};\n\n"

    sstream+="\nconst BaseSWCommon_VirtualDeviceDef * ErrorMgr_GetqnxVirtualDeviceList() {\n"
    sstream+="\n\treturn &ErrorMgr_VirtualDevDefs[0];\n"
    sstream+="\n}\n"

    hstream="\nconst BaseSWCommon_VirtualDeviceDef * ErrorMgr_GetqnxVirtualDeviceList();"

    return (sstream,itemCount,hstream)

def GenerateQNXFunctions(mParsedData,CurrentPath,QnxFolder,version_info):


    QNXApp_GenC=os.path.join(CurrentPath,QnxFolder,"src/ErrorManagerQNXAppGen.c")
    QNXBase_GenC=os.path.join(CurrentPath,QnxFolder,"src/ErrorManagerQNXBase.c")
    QNXBase_GenH=os.path.join(CurrentPath,QnxFolder,"inc/ErrorManagerQNXBase.h")

    Handle_QNXBase_GenH = open(QNXBase_GenH, "w")
    Handle_QNXBase_GenC = open(QNXBase_GenC, "w")
    Handle_QNXApp_GenC = open(QNXApp_GenC, "w")
    GenerateIncludeGaurds(Handle_QNXBase_GenH, "ERRORMGR_QNXBASE_DEFS")
    AddFileHeaders(Handle_QNXBase_GenH, ["unix.h","errno.h","unistd.h","sys/iofunc.h","sys/dispatch.h"])
    AddFileHeaders(Handle_QNXBase_GenC, ["basesw_qnx_virtualdevicedefs.h","basesw_qnx_common.h","ErrorManagerQNXBase.h","ErrorManagerSatellite.h","ErrorManagerQNX_Types.h"])
    AddFileHeaders(Handle_QNXApp_GenC, ["basesw_qnx_common.h","ErrorManagerDef.h","ErrorManagerQNX_Types.h"])



    PrintGenerated_NonModifyisclaimer(Handle_QNXApp_GenC)
    PrintGenerated_NonModifyisclaimer(Handle_QNXBase_GenC)
    PrintGenerated_NonModifyisclaimer(Handle_QNXBase_GenH)

    EmbedGenInfo(Handle_QNXApp_GenC,version_info)
    EmbedGenInfo(Handle_QNXBase_GenC, version_info)
    EmbedGenInfo(Handle_QNXBase_GenH, version_info)

    (GlobalErrorList,ParsedEnumLists,ParsedCommStructDefs,ParsedAdditionalArrayDataTypes,FidResDetails)=mParsedData
    

    #FDefList=dict([(core,dict([(asil, []) for asil in qnxAsilLists])) for core in qnxCoreLists])
    #CodeList=dict([(core,dict([(asil, []) for asil in qnxAsilLists])) for core in qnxCoreLists])

    for core in qnxCoreLists:
        write_fptr_list=[]
        Handle_QNXBase_GenH.write("\n#if ERRORMGR_CURRENTCORE == " + CoreDefEnums[core]+"\n")
        Handle_QNXBase_GenC.write("\n#if ERRORMGR_CURRENTCORE == " + CoreDefEnums[core]+"\n")
        Handle_QNXApp_GenC.write("\n#if ERRORMGR_CURRENTCORE == " + CoreDefEnums[core]+"\n")
        for asil in qnxAsilLists:
            for errGroup in GlobalErrorList[core][asil]:
                errEnum,_,_,_,_,_,_=errGroup
                (sc,hdef,wfptr)=GenerateFunctionBlock(errEnum)
                write_fptr_list.append((errEnum,wfptr))          
                Handle_QNXBase_GenH.write(hdef)
                Handle_QNXBase_GenC.write(sc)
                Handle_QNXBase_GenC.write("\n")
        (sstream,itemCount,hstream)= Generate_VirtualDeviceList(write_fptr_list)
        Handle_QNXBase_GenH.write(hstream+"\n")
        Handle_QNXBase_GenH.write("#define ErrorMgr_VirtualDevDefs_Count "+str(itemCount))
        for s in sstream:
            Handle_QNXBase_GenC.write(s)

        #Generate and write the functions related for application access
        sstream=Generate_AppAccessFunctions(write_fptr_list)
        for s in sstream:
            Handle_QNXApp_GenC.write(s)

        Handle_QNXBase_GenH.write("\n#endif //if ERRORMGR_CURRENTCORE == " + CoreDefEnums[core])
        Handle_QNXBase_GenC.write("\n#endif //if ERRORMGR_CURRENTCORE == " + CoreDefEnums[core])
        Handle_QNXApp_GenC.write("\n#endif //if ERRORMGR_CURRENTCORE == " + CoreDefEnums[core])


    CloseIncludeGaurds(Handle_QNXBase_GenH);
    Handle_QNXBase_GenC.close();
    Handle_QNXBase_GenH.close();
    Handle_QNXApp_GenC.close();