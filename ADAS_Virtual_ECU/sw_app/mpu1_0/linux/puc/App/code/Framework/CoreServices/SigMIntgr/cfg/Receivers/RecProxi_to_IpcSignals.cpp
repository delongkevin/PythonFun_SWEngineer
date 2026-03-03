/**
 * -------------------------------------------------------------------------
 *  @file ***.cpp/***.h
 *  @brief Contains
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 *
/// @author sagar.saste@magna.com

 *  --------------------------------------------------------------------------*/
#include "RecProxi_to_IpcSignals.h"
#include "variants/Enums.h"
#include "variants/VariantHelper.h"
#include "fsdata/fsdata.h"

namespace sigm
{

Proxi_to_IpcSignals::Proxi_to_IpcSignals()
   : BaseReceiver(e_IpcMsgId_Data_ME_ProxiToMPU1_0_Def_t,50){
	is_Prev_Req_Completed = true;
}

Proxi_to_IpcSignals::~Proxi_to_IpcSignals(){}

bool_t Proxi_to_IpcSignals::handleSpecificReceiver_b()
{
    if (true == handle_Proxi_to_IpcSignalsReceiver_b())
    {
    }
    return true;
}

e_VarIdStoreErrorCode_t Proxi_to_IpcSignals::store_rcvd_variant_id(uint8_t var_id,uint8_t radio_b)
{
	FILE *fp;
	e_VarIdStoreErrorCode_t ret_result = e_VarID_No_Error;
	ME_Proxi_MPU1_0_to_MCU1_0_t proxi_req;
	ME_Proxi_MPU1_0_to_MCU1_0_t prev_proxi_req;
	uint8_t etfs_status = 0;
	uint8_t reset_req = 0;

	if(variants::e_VariantIdsCount > var_id)
	{
		proxi_req.PRX_variantID_u8 = var_id;
		proxi_req.PRX_RadioDispTyp_u8 = radio_b;
		prev_proxi_req = dataProvider_po->getME_Proxi_MPU1_0_to_MCU1_0();
		if(prev_proxi_req.state == QNX_ETFS_NOT_READY_STATE)
		{
			reset_req = 1;
		}
		else
		{
			proxi_req.state = QNX_RUNNING_PROXI_WAITING_TO_WRITE_STATE;
		}

		dataProvider_po->setVariantID(proxi_req.PRX_variantID_u8);
		dataProvider_po->setRadioDisp(proxi_req.PRX_RadioDispTyp_u8);
		prev_proxi_req = {0.0f,QNX_IDLE_STATE,0,0};

		fsdata::fsdata_read_data("/tmp/etfs_status", (char*)&etfs_status, sizeof(etfs_status));
		dataProvider_po->setETFS_mount_status(etfs_status);
		etfs_status = dataProvider_po->getETFS_mount_status();
		if(etfs_status == 1)
		{
			if(false == fsdata::fsdata_read_data(variants::ME_VariantHelper_GetVariantIdFilePath_pc(),(char*)&prev_proxi_req,sizeof(prev_proxi_req)))
			{
				ret_result = e_VarID_Old_Read_failed;
				printf("SIGM: Read from file failed\n");
			}
			else
			{
				//do nothing
			}

			if((prev_proxi_req.PRX_variantID_u8== proxi_req.PRX_variantID_u8) && (prev_proxi_req.PRX_RadioDispTyp_u8== proxi_req.PRX_RadioDispTyp_u8))
			{
				printf("SIGM: Prev VarID: %d, RadioType: %d\t Received VarID: %d, RadioType: %d is same, Write is skipped !!!\n",prev_proxi_req.PRX_variantID_u8,prev_proxi_req.PRX_RadioDispTyp_u8,proxi_req.PRX_variantID_u8,proxi_req.PRX_RadioDispTyp_u8);
				proxi_req.state = QNX_RUNNING_PROXI_WRITTEN_SKIPPED_STATE;
			}
			else
			{
				if(false == fsdata::fsdata_store_data(variants::ME_VariantHelper_GetVariantIdFilePath_pc(),(char*)&proxi_req,sizeof(proxi_req)))
				{
					printf("SIGM: File %s open failed\n",variants::ME_VariantHelper_GetVariantIdFilePath_pc());
					ret_result = e_VarId_Write_Failed;
					proxi_req.state = QNX_RUNNING_PROXI_WRITTEN_FAILED_STATE;
				}
				else
				{
					printf("SIGM: Written to ETFS - VarID: %d, RadioType: %d\n",proxi_req.PRX_variantID_u8,proxi_req.PRX_RadioDispTyp_u8);
					proxi_req.state = QNX_RUNNING_PROXI_WRITTEN_PASS_STATE;
				}
			}
		}
		else
		{
			printf("SIGM: ETFS Mount is failed. received proxi data will be discarded..\n");
			ret_result = e_VarID_ETFS_MOUNT_FAILED;
			proxi_req.state = QNX_RESTART_REQ_STATE;
		}
		if(reset_req == 1)
		{
			reset_req = 0;
			proxi_req.state = QNX_RESTART_REQ_STATE;
			printf("SIGM_PROXI: Restart is requested from proxi!!!\n");
		}
		dataProvider_po->setME_Proxi_MPU1_0_to_MCU1_0_v(proxi_req);
	}
	else
	{
		ret_result = e_VarID_Rcvd_Invalid_ID;
		printf("SIGM: Received Invalid Variant ID\n");
	}
	return ret_result;
}


bool_t Proxi_to_IpcSignals::handle_Proxi_to_IpcSignalsReceiver_b()
{
    bool_t v_RequestOk_b = false;
    uint32_t size_u32 =0;
    e_VarIdStoreErrorCode_t v_VarId_e = e_VarID_No_Error;
    size_u32 = BaseReceiver::getStructSize_u32<ME_ProxiToMPU1_0_Def_t>();
    if(size_u32 != m_MsgReceived.msgSize_u32)
    {
    	logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "Proxi_to_IpcSignals_t message  invalid  size actual %d and received %d \n",size_u32, m_MsgReceived.msgSize_u32);
    }
    else
    {
    	ME_ProxiToMPU1_0_Def_t v_NewRequest_t;
        if (m_MsgReceived.msgSize_u32 > 0)
        {
            v_RequestOk_b = true;
            memcpy(&v_NewRequest_t,&m_MsgReceived.data_t[0], m_MsgReceived.msgSize_u32);
            if(true == is_Prev_Req_Completed)
            {
            	is_Prev_Req_Completed = false;
            	dataProvider_po->setME_Proxi_to_IpcSignals_v(v_NewRequest_t);
//				printf("SIGM: Received- %s\n", __PRETTY_FUNCTION__);
				v_VarId_e = store_rcvd_variant_id(v_NewRequest_t.PRX_variantID_u8,v_NewRequest_t.PRX_RadioDispTyp_u8);
				is_Prev_Req_Completed = true;
            }
            else
            {
            	v_VarId_e = e_VarID_Multiple_Req_Rcvd;
            }

        	if(v_VarId_e > e_VarID_No_Error){
        		printf("SIGM: Requested Variant ID not Stored in flash [%d]\n",v_VarId_e);
        	}
        }
    }
    return v_RequestOk_b;
}

} /* namespace sigm */
