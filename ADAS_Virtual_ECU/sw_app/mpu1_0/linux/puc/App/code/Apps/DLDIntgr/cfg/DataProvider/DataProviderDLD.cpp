//--------------------------------------------------------------------------
/// @file DataProviderDLD.cpp
/// @brief Contains implementation of DLD Dataprovider interface
///
/// DataProvider is an interface between DLD module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
//  --------------------------------------------------------------------------

#include "DataProviderDLD.h"
#if ENABLE_DLD_OFFLINE_TEST
  #include <fstream>
  #include <string>
#endif

namespace dld
{

// Get RGB image for DNN models
#define frame_size ((uint32_t)(DLD_INPUT_WIDTH * DLD_INPUT_HEIGHT)) // (320w x 320h)
#define rgb_img_size ((uint32_t)(frame_size * DLD_INPUT_CHANNELS)) // (320w x 320h x 3c)
#define rgb_img_max_size ((uint32_t)(rgb_img_size + frame_size)) // (320w x 320h x 3c) + (320h x 320w)
static uint8_t rgbimage_padded[rgb_img_max_size];

#if ENABLE_DLD_OFFLINE_TEST
  static uint8_t rawimage[rgb_img_size]; // RGB = (320w x 320h) * 3
#endif

DataProviderDLD::DataProviderDLD(container::IDataProvider &b_DataProvider_ro):
  IDataProviderDLD(),
  m_dataProvider_ro(b_DataProvider_ro),
  m_tiovxConsumer(),
  m_jobDLDInput(),
  m_vehicleInput(),
  m_dldFIDs(),
  m_inputPadL(1U),
  m_inputPadT(1U),
  m_inputPadR(0U),
  m_inputPadB(2U)
{
  m_paddedInputSize = (m_inputPadL + DLD_INPUT_WIDTH + m_inputPadR) * (m_inputPadT + DLD_INPUT_HEIGHT + m_inputPadB) * DLD_INPUT_CHANNELS;
  m_jobDLDInput.InputImgColor_pu8 = rgbimage_padded;
  memset(m_jobDLDInput.InputImgColor_pu8, 0, rgb_img_max_size);
  memset(&prevJobDLDOutput, 0, sizeof(JobDLDOutput_t));
#if ENABLE_DLD_OFFLINE_TEST
  ut_numInputs = 0;
  std::ifstream file("/ti_sd/dld_inputs.txt");
  if(file.is_open()) {
    std::string file_name;
    while(file >> file_name) {
      snprintf(ut_inputName[ut_numInputs], 64, "%s", file_name.c_str());
      ut_numInputs++;
    }
    ME_Debugger_F_Printf_v("[DLD] Found %d input files in /ti_sd/dld_inputs.txt\n", ut_numInputs);
  } else {
    ME_Debugger_F_Printf_v("[DLD Error] Unable to locate input file - /ti_sd/dld_inputs.txt\n");
  }
#endif
}

DataProviderDLD::~DataProviderDLD() {
}

void DataProviderDLD::createAlgoViewDescriptors() {
  static char algoViewId[DLD_Camera_ID::DLD_NUM_CAMS][25] = {
     {"algo-fisheye-dld-rear"}  /* DLD_Camera_ID::DLD_Rear  */
    ,{"algo-fisheye-dld-front"} /* DLD_Camera_ID::DLD_Front */
    ,{"algo-fisheye-dld-left"}  /* DLD_Camera_ID::DLD_Left  */
    ,{"algo-fisheye-dld-right"} /* DLD_Camera_ID::DLD_Right */
#if ENABLE_DLD_CHMSL_CAMERA
    ,{"algo-fisheye-dld-chmsl"}  /* DLD_Camera_ID::DLD_Chmsl */
#endif
  };
  container::OVL3DData *v_ovl3d_po = getOVL3DData_po();
  bsp::TIOVXHost &v_tiovx_ro = getTIOVX_ro();

  for(uint8_t camId = DLD_Camera_ID::DLD_Rear; camId < DLD_Camera_ID::DLD_NUM_CAMS; camId++) {
    m_algoView[camId].createAlgoView(v_ovl3d_po, v_tiovx_ro, algoViewId[camId]);
  }
}

void DataProviderDLD::c_getInputcolorImage_pu8(DLD_Camera_ID camId)
{
#if ENABLE_DLD_OFFLINE_TEST
  static int idx = 0;
  static int count_idx = 0;
  count_idx++;
  if(count_idx == 12) {
    idx++;
    if(idx == ut_numInputs) {
      idx = 0;
      ME_Debugger_F_Printf_v("##########################################\n");
      ME_Debugger_F_Printf_v("[DLD] Finished all %d images, looping back\n", ut_numInputs);
      ME_Debugger_F_Printf_v("##########################################\n");
    }
    count_idx = 0;
  }
  
  FILE * f = fopen(ut_inputName[idx], "rb");
  if(f != NULL) {
    fread(rawimage, sizeof(uint8_t), rgb_img_size, f); // RGB planar
    fclose(f);
    copyInputWithPadding(&rawimage[0], &rawimage[frame_size], &rawimage[2*frame_size]);
    ME_Debugger_F_Printf_v("[DLD] Input: %s, %d\n", ut_inputName[idx], count_idx);

    #if ENABLE_DLD_DEBUG_DUMP
      char FileName[100];
      sprintf(FileName, "%s_%02d.rgb", ut_inputName[idx], count_idx);
      FILE * fp = fopen(FileName, "wb");
      fwrite(m_jobDLDInput.InputImgColor_pu8, m_paddedInputSize, 1, fp);
      fclose(fp);
    #endif
  }
  else {
    DLD_DEBUG_PRINT_ERROR("Algo: Could not open file - %s", ut_inputName[idx]);
  }
#else
  static uint8 m_InitOnce = 1;

  if (m_InitOnce) {
    // create AlgoView descriptor
    createAlgoViewDescriptors();
    m_InitOnce = 0;
  }
  else {
    // set first frame number
    static uint32_t v_frameNum_u32 = 0;
    static uint32_t last_v_frameNum_u32 = 0;
    static container::OVL3DData *v_ovl3d_po = getOVL3DData_po();
    v_ovl3d_po->updateFrame_v(v_frameNum_u32);
    if(last_v_frameNum_u32 < v_frameNum_u32) {
      last_v_frameNum_u32 = v_frameNum_u32;
#if ENABLE_DLD_PROFILE
      osal::Time v_Time_o;
      uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
#endif
      bsp::VideoInputBufferDesc2_t v_bufferDesc_t = m_algoView[camId].getAlgoFrame();
#if ENABLE_DLD_PROFILE
      uint64_t v_FetchTime_u64 = v_Time_o.getTimeMsec_u64();
#endif
      copyInputWithPadding(static_cast<uint8_t*>(v_bufferDesc_t.buffers_apv[0]),
                            static_cast<uint8_t*>(v_bufferDesc_t.buffers_apv[1]),
                            static_cast<uint8_t*>(v_bufferDesc_t.buffers_apv[2]));
#if ENABLE_DLD_PROFILE
    uint64_t v_PadTime_u64 = v_Time_o.getTimeMsec_u64();
    ME_Debugger_F_Printf_v("[DLD Profile] algoFetch time : %u ms, pad time : %u ms\n",
      (v_FetchTime_u64 - v_StartTime_u64), (v_PadTime_u64 - v_FetchTime_u64));
#endif
      #if ENABLE_DLD_DEBUG_DUMP
        char FileName[64];
        static uint32_t u32FrameNum = 0;
        static uint32_t u32FrameIdx = 0;
        if(camId == 0) u32FrameNum++;
        if((u32FrameNum % 50) == 0)
        {
          if(camId == 0) u32FrameIdx++;
          sprintf(FileName, "/ti_sd/dld/DLDAlgoView_%d_%05d.rgb", camId, u32FrameIdx);
          FILE * fp = fopen(FileName, "wb");
          fwrite(m_jobDLDInput.InputImgColor_pu8, m_paddedInputSize, 1, fp);
          fclose(fp);
        }
      #endif
    }
  }
#endif
}

  /*
	*	Name: setInputPadSizes
	*	Remarks: DD-ID: {5CAB8B44-4218-4da9-A3A2-38B3560A7488}
	*	Remarks: DD-ID: {FE16DDDE-A020-4f7b-916E-FBD0D5617222}
	*	Remarks: DD-ID: {A1397B2B-3BBE-415c-B5B0-23857F6207B8}
  */
void DataProviderDLD::setInputPadSizes(uint32_t inPadL, uint32_t inPadT, uint32_t inPadR, uint32_t inPadB) {
  uint32_t newInputSize = (inPadL + DLD_INPUT_WIDTH + inPadR) * (inPadT + DLD_INPUT_HEIGHT + inPadB) * DLD_INPUT_CHANNELS;
  if(newInputSize <= rgb_img_max_size) {
    m_inputPadL = inPadL;
    m_inputPadT = inPadT;
    m_inputPadR = inPadR;
    m_inputPadB = inPadB;
    m_paddedInputSize = newInputSize;
    memset(m_jobDLDInput.InputImgColor_pu8, 0, rgb_img_max_size);
    DLD_DEBUG_PRINT(DLD_TRACE_HIGH, "[DLD] Input padding: L=%d, T=%d, R=%d, B=%d\n", inPadL, inPadT, inPadR, inPadB);
  }
  else {
    DLD_DEBUG_PRINT_ERROR("Exceeds maximum frame size - requested=%d, available=%d, padding(%d, %d, %d, %d)",
      newInputSize, rgb_img_max_size, inPadL, inPadT, inPadR, inPadB);
  }
}

  /*
	*	Name: copyInputWithPadding
	*	Remarks: DD-ID: {DB925CF7-E927-4421-834A-745EF8E21AA1}
	*	Remarks: DD-ID: {204106F2-DF47-4bc8-984F-22C5E2039657}
	*	Remarks: DD-ID: {78A7BE0C-B788-4a9a-BA5B-A71D0E269963}
  */
void DataProviderDLD::copyInputWithPadding(uint8_t *src_r, uint8_t *src_g, uint8_t *src_b) {
  const uint32_t src_buffer_h = DLD_INPUT_HEIGHT;
  const uint32_t src_buffer_w = DLD_INPUT_WIDTH;
  const uint32_t dst_buffer_w = m_inputPadL + src_buffer_w + m_inputPadR;
  const uint32_t dst_buffer_h = m_inputPadT + src_buffer_h + m_inputPadB;
  const uint32_t dst_buffer_area = dst_buffer_h * dst_buffer_w;

  for (uint32_t y = 0; y < src_buffer_h; y++) { // 320
    const uint32_t src_buffer_index = (y * src_buffer_w);
    // Copy R frame
    uint32_t dst_buffer_index = (0U * dst_buffer_area) + (y + m_inputPadT) * dst_buffer_w + (m_inputPadL);
    memcpy(&m_jobDLDInput.InputImgColor_pu8[dst_buffer_index], &src_r[src_buffer_index], src_buffer_w);
    // Copy G frame
    dst_buffer_index = (1U * dst_buffer_area) + (y + m_inputPadT) * dst_buffer_w + (m_inputPadL);
    memcpy(&m_jobDLDInput.InputImgColor_pu8[dst_buffer_index], &src_g[src_buffer_index], src_buffer_w);
    // Copy B frame
    dst_buffer_index = (2U * dst_buffer_area) + (y + m_inputPadT) * dst_buffer_w + (m_inputPadL);
    memcpy(&m_jobDLDInput.InputImgColor_pu8[dst_buffer_index], &src_b[src_buffer_index], src_buffer_w);
  }
}

/// @brief  Get AlgoView processor data
container::OVL3DData* DataProviderDLD::getOVL3DData_po() {
  return m_dataProvider_ro.getOVL3DData_po();
}

/// @brief  Get TIOVX host handle
bsp::TIOVXHost& DataProviderDLD::getTIOVX_ro() {
  return m_dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
}

	/*
	*	Name: getDLDInput
	*	Function: Get function for DLD
	*	Remarks: DD-ID: {B2269FEB-A6EE-49eb-95B3-0319E7FE415B}
	*	Remarks: DD-ID: {81843939-7A88-411b-99B4-4251485AAF78}
	*	Remarks: DD-ID: {2D18507E-EFF1-41bc-8F14-41B0B1341347}
	*/
const JobDLDInput_s DataProviderDLD::getDLDInput(DLD_Camera_ID camId) {
  if(camId < DLD_Camera_ID::DLD_NUM_CAMS) {
    c_getInputcolorImage_pu8(camId);
  }
  else {
    memset(m_jobDLDInput.InputImgColor_pu8, 0u, rgb_img_max_size);
  }
  return m_jobDLDInput;
}
	/*
	*	Name: getDLDFIDs
	*	Remarks: DD-ID: {CB9B85CE-5505-4cca-9D74-658F0D449508}
	*	Remarks: DD-ID: {54EA9A0C-5E47-4ae0-BC9F-00ACA4F5302E}
	*	Remarks: DD-ID: {D9EAAE84-DEE1-4c7a-B2A5-735F2C95D4BB}
	*/
const JobDLDFIDs_t DataProviderDLD::getDLDFIDs(void) {
  FID_STRUCT_QM v_FID_struct_QM = m_dataProvider_ro.getSigMData_po()->getFID_STRUCT_QM();
  m_dldFIDs.FID_DLD_FRONT_DISABLED = v_FID_struct_QM.m_QM_FID_DLD_FRONT_DISABLED;
  m_dldFIDs.FID_DLD_REAR_DISABLED = v_FID_struct_QM.m_QM_FID_DLD_REAR_DISABLED;
  m_dldFIDs.FID_DLD_LEFT_DISABLED = v_FID_struct_QM.m_QM_FID_DLD_LEFT_DISABLED;
  m_dldFIDs.FID_DLD_RIGHT_DISABLED = v_FID_struct_QM.m_QM_FID_DLD_RIGHT_DISABLED;
#if ENABLE_DLD_CHMSL_CAMERA
  m_dldFIDs.FID_DLD_CHMSL_DISABLED = v_FID_struct_QM.m_QM_FID_DLD_CARGO_DISABLED;
#endif

#if ENABLE_DLD_DEBUG_PRINT
  FID_STRUCT_B v_FID_struct_B = m_dataProvider_ro.getSigMData_po()->getfid_struct();
  DLD_DEBUG_PRINT(DLD_TRACE_MID, "[DLD] FIDs QM - DLD<Fr=%d,Rr=%d,Lt=%d,Rt=%d> THA<%d> TRSC<%d> B - PPPA<%d>\n",
    v_FID_struct_QM.m_QM_FID_DLD_FRONT_DISABLED, v_FID_struct_QM.m_QM_FID_DLD_REAR_DISABLED,
    v_FID_struct_QM.m_QM_FID_DLD_LEFT_DISABLED, v_FID_struct_QM.m_QM_FID_DLD_RIGHT_DISABLED,
    v_FID_struct_QM.m_QM_FID_THA_DLD_ABORT, v_FID_struct_QM.m_QM_FID_TRSC_DLD_DISABLED,
    v_FID_struct_B.m_B_FID_PPPA_DLD_DISABLED);
#endif
  return m_dldFIDs;
}

ME_ProxiToMPU1_0_Def_t* DataProviderDLD::getProxiSettings(void)
{
  proxy_s = m_dataProvider_ro.getSigMData_po()->getME_Proxi_to_IpcSignals_t();
  return &proxy_s;
}

#if ENABLE_DLD_DEBUG_PRINT
const char* DataProviderDLD::getDldCameraString(DLD_Camera_ID camId) {
  switch(camId) {
    case DLD_Camera_ID::DLD_Rear:  return "Rr";
    case DLD_Camera_ID::DLD_Front: return "Fr";
    case DLD_Camera_ID::DLD_Left:  return "Le";
    case DLD_Camera_ID::DLD_Right: return "Rt";
#if ENABLE_DLD_CHMSL_CAMERA
    case DLD_Camera_ID::DLD_Chmsl: return "Ch";
#endif
    default : break;
  }
  return "";
}
#endif

#if ENABLE_DLD_DEBUG_PRINT
const char* DataProviderDLD::getDldStatusString(DLDCamSts_t status) {
  switch(status) {
    case DLD_Normal:        return "Norm";
	  case DLD_Blockage:      return "Occl";
	  case DLD_Low_Luminance: return "LowL";
	  case DLD_BackLit:       return "BckL";
	  case DLD_Unknown:       return "Unkn";
  }
  return "";
}
#endif

/* Put function for DLD detection output */
  /*
	*	Name: setDLDOutput
	*	Remarks: DD-ID: {4C2539DC-04D4-4996-A7FF-5FCD97E3ADE3}
	*	Remarks: DD-ID: {E702F804-5303-45ae-B146-A0AD6CE70033}
	*	Remarks: DD-ID: {9E13E8AA-3EC8-432e-A7B5-1647D27EA095}
  */
void DataProviderDLD::setDLDOutput(DLDOutput_s& i_detectionOutput) {
#if ENABLE_DLD_DEBUG_PRINT
  DLD_DEBUG_PRINT(DLD_TRACE_HIGH, "[DLD] ");
  for(uint8_t camId = DLD_Camera_ID::DLD_Rear; camId < DLD_Camera_ID::DLD_NUM_CAMS; camId++) {
    DLD_DEBUG_PRINT(DLD_TRACE_HIGH, " <%s=%s,%0.2f,%0.2f>",
      getDldCameraString((DLD_Camera_ID)camId),
      getDldStatusString(i_detectionOutput.DldCameraStatus[camId].DLD_CamSts_e),
      i_detectionOutput.DldCameraStatus[camId].OccludedBinPerc,
      i_detectionOutput.DldCameraStatus[camId].LowlightPerc);
  }
  DLD_DEBUG_PRINT(DLD_TRACE_HIGH, "\n");
#endif

  bool_t SVC_DLD_Occlusion_Front = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Front].OcclusionStatus;
  bool_t SVC_DLD_Low_light_Front = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Front].LowlightStatus;
  bool_t SVC_DLD_Occlusion_Rear  = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Rear].OcclusionStatus;
  bool_t SVC_DLD_Low_light_Rear  = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Rear].LowlightStatus;
  bool_t SVC_DLD_Occlusion_Left  = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Left].OcclusionStatus;
  bool_t SVC_DLD_Low_light_Left  = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Left].LowlightStatus;
  bool_t SVC_DLD_Occlusion_Right = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Right].OcclusionStatus;
  bool_t SVC_DLD_Low_light_Right = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Right].LowlightStatus;
#if ENABLE_DLD_CHMSL_CAMERA
  bool_t SVC_DLD_Occlusion_Chmsl = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Chmsl].OcclusionStatus;
  bool_t SVC_DLD_Low_light_Chmsl = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Chmsl].LowlightStatus;
#endif

  ErrorMgr_ErrorCommPack_QNX_B Err_QNX_B_DLD = m_dataProvider_ro.getSigMData_po()->getErrorMgr_ErrorCommPack_QNX_B();
  if((Err_QNX_B_DLD.Error[0] != SVC_DLD_Occlusion_Front) 
  || (Err_QNX_B_DLD.Error[1] != SVC_DLD_Low_light_Front)
  || (Err_QNX_B_DLD.Error[2] != SVC_DLD_Occlusion_Rear)
  || (Err_QNX_B_DLD.Error[3] != SVC_DLD_Low_light_Rear)
  || (Err_QNX_B_DLD.Error[4] != SVC_DLD_Occlusion_Left)
  || (Err_QNX_B_DLD.Error[5] != SVC_DLD_Low_light_Left)
  || (Err_QNX_B_DLD.Error[6] != SVC_DLD_Occlusion_Right)
  || (Err_QNX_B_DLD.Error[7] != SVC_DLD_Low_light_Right)
#if ENABLE_DLD_CHMSL_CAMERA
  //|| (Err_QNX_B_DLD.Error[8] != SVC_DLD_Occlusion_Chmsl) // todo chmsl
  //|| (Err_QNX_B_DLD.Error[9] != SVC_DLD_Low_light_Chmsl) // todo chmsl
#endif
  ) {
    Err_QNX_B_DLD.Error[0] = SVC_DLD_Occlusion_Front;
    Err_QNX_B_DLD.Error[1] = SVC_DLD_Low_light_Front;
    Err_QNX_B_DLD.Error[2] = SVC_DLD_Occlusion_Rear;
    Err_QNX_B_DLD.Error[3] = SVC_DLD_Low_light_Rear;
    Err_QNX_B_DLD.Error[4] = SVC_DLD_Occlusion_Left;
    Err_QNX_B_DLD.Error[5] = SVC_DLD_Low_light_Left;
    Err_QNX_B_DLD.Error[6] = SVC_DLD_Occlusion_Right;
    Err_QNX_B_DLD.Error[7] = SVC_DLD_Low_light_Right;
#if ENABLE_DLD_CHMSL_CAMERA
    //Err_QNX_B_DLD.Error[8] = SVC_DLD_Occlusion_Chmsl; // todo chmsl
    //Err_QNX_B_DLD.Error[9] = SVC_DLD_Low_light_Chmsl; // todo chmsl
#endif
    Err_QNX_B_DLD.RunningCounter++;

    bool hasChange = (memcmp(&prevErr_QNX_B_DLD, &Err_QNX_B_DLD, sizeof(ErrorMgr_ErrorCommPack_QNX_B)) == 0) ? false : true;
    if(hasChange) {
      m_dataProvider_ro.getSigMData_po()->setErrorMgr_ErrorCommPack_QNX_B_v(Err_QNX_B_DLD);
      memcpy((void*)&prevErr_QNX_B_DLD, (void*)&Err_QNX_B_DLD, sizeof(ErrorMgr_ErrorCommPack_QNX_B));
    }
  }

  /* Set the data for DID status */
  static JobDLDOutput_t jobDLDOutput;
  jobDLDOutput.IeDLD_e_FrCamSts = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Front].DLD_CamSts_e;
  jobDLDOutput.IeDLD_p_FrCamOcclnPerc = static_cast<uint8_t>(i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Front].OccludedBinPerc * 100);
  jobDLDOutput.IeDLD_p_FrCamLoLumPerc = static_cast<uint8_t>(i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Front].LowlightPerc * 100);
  jobDLDOutput.IeDLD_b_FrCamOcclnSts = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Front].OcclusionStatus;
  jobDLDOutput.IeDLD_b_FrCamLoLumSts = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Front].LowlightStatus;

  jobDLDOutput.IeDLD_e_RrCamSts = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Rear].DLD_CamSts_e;
  jobDLDOutput.IeDLD_p_RrCamOcclnPerc = static_cast<uint8_t>(i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Rear].OccludedBinPerc * 100);
  jobDLDOutput.IeDLD_p_RrCamLoLumPerc = static_cast<uint8_t>(i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Rear].LowlightPerc * 100);
  jobDLDOutput.IeDLD_b_RrCamOcclnSts = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Rear].OcclusionStatus;
  jobDLDOutput.IeDLD_b_RrCamLoLumSts = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Rear].LowlightStatus;

  jobDLDOutput.IeDLD_e_LyCamSts = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Left].DLD_CamSts_e;
  jobDLDOutput.IeDLD_p_LyCamOcclnPerc = static_cast<uint8_t>(i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Left].OccludedBinPerc * 100);
  jobDLDOutput.IeDLD_p_LyCamLoLumPerc = static_cast<uint8_t>(i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Left].LowlightPerc * 100);
  jobDLDOutput.IeDLD_b_LyCamOcclnSts = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Left].OcclusionStatus;
  jobDLDOutput.IeDLD_b_LyCamLoLumSts = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Left].LowlightStatus;

  jobDLDOutput.IeDLD_e_RyCamSts = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Right].DLD_CamSts_e;
  jobDLDOutput.IeDLD_p_RyCamOcclnPerc = static_cast<uint8_t>(i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Right].OccludedBinPerc * 100);
  jobDLDOutput.IeDLD_p_RyCamLoLumPerc = static_cast<uint8_t>(i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Right].LowlightPerc * 100);
  jobDLDOutput.IeDLD_b_RyCamOcclnSts = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Right].OcclusionStatus;
  jobDLDOutput.IeDLD_b_RyCamLoLumSts = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Right].LowlightStatus;

#if ENABLE_DLD_CHMSL_CAMERA
  jobDLDOutput.IeDLD_e_ChCamSts = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Chmsl].DLD_CamSts_e;
  jobDLDOutput.IeDLD_p_ChCamOcclnPerc = static_cast<uint8_t>(i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Chmsl].OccludedBinPerc * 100);
  jobDLDOutput.IeDLD_p_ChCamLoLumPerc = static_cast<uint8_t>(i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Chmsl].LowlightPerc * 100);
  jobDLDOutput.IeDLD_b_ChCamOcclnSts = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Chmsl].OcclusionStatus;
  jobDLDOutput.IeDLD_b_ChCamLoLumSts = i_detectionOutput.DldCameraStatus[DLD_Camera_ID::DLD_Chmsl].LowlightStatus;
#endif
  
  bool hasChange = (memcmp(&prevJobDLDOutput, &jobDLDOutput, sizeof(jobDLDOutput)) == 0) ? false : true;
  if(hasChange) {
    m_dataProvider_ro.getSigMData_po()->setJobDLDOutput_v(jobDLDOutput);
    memcpy((void*)&prevJobDLDOutput, (void*)&jobDLDOutput, sizeof(JobDLDOutput_t));
  }
}

	/*
	*	Name: getVehicleInput
	*	Remarks: DD-ID: {4AE634A2-09FC-4f4e-9808-F4F6778F6E50}
	*	Remarks: DD-ID: {E0A42BED-153B-4a8a-917E-6BCCC6F5358C}
	*	Remarks: DD-ID: {7D41D357-8A14-4800-9138-9B856773CC98}
	*/
const JobDLDVehicleInput_s DataProviderDLD::getVehicleInput(void)
{
  /* Receiving bus signals */ 
  ME_VehInp_to_IpcSignals_t v_vehData = m_dataProvider_ro.getSigMData_po()->getME_VehInp_to_IpcSignals_t();

  /* Required vehicle signal for DLD activation */
  m_vehicleInput.DriverDoorSts = v_vehData.CAN2_to_IPC.DataInp_BCM_FD_9.DriverDoorSts;
  m_vehicleInput.LHRDoorSts = v_vehData.CAN2_to_IPC.DataInp_BCM_FD_9.LHRDoorSts;
  m_vehicleInput.PsngrDoorSts = v_vehData.CAN2_to_IPC.DataInp_BCM_FD_9.PsngrDoorSts;
  m_vehicleInput.RHRDoorSts = v_vehData.CAN2_to_IPC.DataInp_BCM_FD_9.RHRDoorSts;
  m_vehicleInput.RHatchSts = v_vehData.CAN2_to_IPC.DataInp_BCM_FD_9.RHatchSts;

  m_vehicleInput.CmdIgnSts = (TeVBII_e_CmdIgnSts)v_vehData.CAN2_to_IPC.DataInp_BCM_FD_10.CmdIgnSts;

  return m_vehicleInput;
}
	/*
	*	Name: isFeatureAllowedToRun
  * Remarks: DD-ID: {481C6CFD-08DA-4841-BD29-641095DCA79D}
	*	Remarks: DD-ID: {2F91959E-DD7F-4c1d-8DFD-7B81C43571F7} 
	*	Remarks: DD-ID: {8FDFB315-ED59-4c57-A112-FCFC21E5DD23} 
	*/
bool_t DataProviderDLD::isFeatureAllowedToRun(void) {
  bool isAllowed = TRUE;
  /*
   * DLD is not allowed to run when any of the following features are running
   * SC - Service Calibration
   * EOL - End Of Line Calibration
   * THA - Trailer Hitch Assist
   * APA (Parking) - Auto Park Assist in parkign mode
   */

  /* Check for SC */
  TbSVS_e_SVSCalibSMToAlgoCamCalib_t i_SMToAlgo = m_dataProvider_ro.getCalSmMData_po()->getSVSCalibSMToAlgoCamCalib();
  if (TRUE == i_SMToAlgo.AlgoCntrlData_t.data[SC_ALGO_ACTIVE_BYTE]) {
    isAllowed &= FALSE;
    DLD_DEBUG_PRINT(DLD_TRACE_HIGH, "[DLD] Disabled by SC\n");
  }

  /* Check for EOL */
  if (TRUE == i_SMToAlgo.AlgoCntrlData_t.data[EOL_ALGO_ACTIVE_BYTE]) {
    DLD_DEBUG_PRINT(DLD_TRACE_HIGH, "[DLD] Disabled by EOL\n");
    isAllowed &= FALSE;
  }

  /* Check for THA */
  bool_t m_THADetEnabled = m_dataProvider_ro.getTHAData_po()->get_THA_SM_status();
  if(m_THADetEnabled)
  {
    isAllowed &= FALSE;
    DLD_DEBUG_PRINT(DLD_TRACE_HIGH, "[DLD] Disabled by THA\n");
  }

  /* Check for APA Parking */
  TbAP_DriveAssistStatOut_t i_apData = m_dataProvider_ro.getSigMData_po()->getTbAP_DriveAssistStatOut();
	eAutoParkingState_t eAutoParkingState = (eAutoParkingState_t)i_apData.IeAP_e_AlgoState;
  if((eAutoParkingState_E_PW_APS_IDLE != eAutoParkingState) &&
     (eAutoParkingState_E_PW_APS_SCANNING != eAutoParkingState))
  {
    isAllowed &= FALSE;
    DLD_DEBUG_PRINT(DLD_TRACE_HIGH, "[DLD] Disabled by Autopark - %d\n", eAutoParkingState);
  }

  /*ME_VehInp_to_IpcSignals_t v_vehData = m_dataProvider_ro.getSigMData_po()->getME_VehInp_to_IpcSignals_t();
  uint8 GearEngaged = (m_GearValues_t)v_vehData.CAN2_to_IPC.DataInp_TRANSM_FD_4.GearEngaged;
  if(14 == GearEngaged)
  {
    isAllowed &= FALSE;
    DLD_DEBUG_PRINT(DLD_TRACE_HIGH, "[DLD] Disabled in Reverse Gear\n");
  }*/

  return isAllowed;
}

void DataProviderDLD::setDLDThreadRuntime(uint32_t u_Runtime_u32)
{
  m_dataProvider_ro.getDLDData_po()->setDLDThreadRuntime(u_Runtime_u32);
}

void DataProviderDLD::setDLDRuntime(uint32_t u_Runtime_u32)
{
  m_dataProvider_ro.getDLDData_po()->setDLDRuntime(u_Runtime_u32);
}

PerformanceStatsEnable_t DataProviderDLD::get_PerformanceStatsEnable(void)
{
	return m_dataProvider_ro.getSigMData_po()->getPerformanceStatsEnable_t();
}

} // namespace DLD
