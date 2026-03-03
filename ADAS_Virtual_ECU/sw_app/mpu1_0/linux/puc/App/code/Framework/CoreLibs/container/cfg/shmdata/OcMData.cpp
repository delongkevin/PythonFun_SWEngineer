#include "OcMData.h"

namespace container
{
    OcMData::OcMData() : DataContainer(), 
        mutex_o()
    {
        memset(getImageBuffer_pu8(variants::e_CameraFront), 0, c_ImgLength_u32);
        memset(getImageBuffer_pu8(variants::e_CameraLeft), 0, c_ImgLength_u32);
        memset(getImageBuffer_pu8(variants::e_CameraRear), 0, c_ImgLength_u32);
        memset(getImageBuffer_pu8(variants::e_CameraRight), 0, c_ImgLength_u32);
        memset(&oc_hmi_info, 0, sizeof(oc_hmi_info));
    }

    OcMData::~OcMData()
    {

    }
    int16_t OcMData::getFeatureProgress()
    {
        int16_t v_DataCopy_s32 = 0;
        mutex_o.take_b();
        v_DataCopy_s32 = ocshmdata.validFeaturesCount_u32 * 100.0 / (MAX_VALID_FEATURES) ;
        mutex_o.give_v();
        return v_DataCopy_s32;
    }

    Oc_hmi_data_s* OcMData::get_oc_hmi_info()
    {
        mutex_o.take_b();
        mutex_o.give_v();
        return &oc_hmi_info;
    }

    void OcMData::set_oc_hmi_info(Oc_hmi_data_s* i_oc_hmi_data_p)
    {
        mutex_o.take_b();
        memcpy(&oc_hmi_info,i_oc_hmi_data_p, sizeof(Oc_hmi_data_s));
//        ME_Debugger_F_Printf_v("number of features image %d\n", oc_hmi_info.ocProgress_u16[0]);
        mutex_o.give_v();
    }

	    void OcMData::set_ocm_data (container::OcData_s data)
    {
    	mutex_o.take_b();
    	ocshmdata = data;
    	mutex_o.give_v();
    }
	    OcData_s *OcMData::get_ocm_data()
	    {
	        mutex_o.take_b();
	        mutex_o.give_v();
	        return &ocshmdata;
	    }
    uint32_t OcMData::getOCRuntime(void)
    {
        uint32_t v_DataCopy_u32 = 0;
        mutex_o.take_b();
        v_DataCopy_u32 = m_OC_rt_data;
        mutex_o.give_v();

        return v_DataCopy_u32;  
    }

    void OcMData::setOCRuntime(uint32_t u_Runtime_u32)
    {
        mutex_o.take_b();
        m_OC_rt_data = u_Runtime_u32;
        mutex_o.give_v();
    }

    uint32_t OcMData::getOCThreadRuntime(void)
    {
        uint32_t v_DataCopy_u32 = 0;
        mutex_o.take_b();
        v_DataCopy_u32 = m_OCThread_rt_data;
        mutex_o.give_v();

        return v_DataCopy_u32;  
    }

    void OcMData::setOCThreadRuntime(uint32_t u_Runtime_u32)
    {
        mutex_o.take_b();
        m_OCThread_rt_data = u_Runtime_u32;
        mutex_o.give_v();
    }          
}   //namespace container
