//--------------------------------------------------------------------------
/// @file JobOC.h
/// @brief Contains the definition of OC = Online Calibration
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Nikhil Parlapalli
///
//  --------------------------------------------------------------------------

#include "DataProviderOC.h"
#include "XilinxAtsBr_ZurichLite_Rr70.h"
#include "DataVariantProviderOc.h"
#include "configuration.h"
#include "CalSmMData.h"
#include "variants/VariantHelper.h"

#define MAX_VALID_FEATURES  (200.0) //used for sending progress to HMI

#if !OC_ALGO_VIEW_ENABLE
#define IMAGE_WIDTH_RAW 1920U
#define IMAGE_HEIGHT_RAW 1280U
#endif

#define OC_INPUT_IMAGE_DUMP    0
#define OC_INPUT_IMAGE_PROFILE 0

#if !OC_ALGO_VIEW_ENABLE
uint8_t m_MemoryPool_ua8_front[IMAGE_WIDTH_RAW*IMAGE_HEIGHT_RAW];
uint8_t m_MemoryPool_ua8_left[IMAGE_WIDTH_RAW*IMAGE_HEIGHT_RAW];
uint8_t m_MemoryPool_ua8_rear[IMAGE_WIDTH_RAW*IMAGE_HEIGHT_RAW];
uint8_t m_MemoryPool_ua8_right[IMAGE_WIDTH_RAW*IMAGE_HEIGHT_RAW];
#else
uint8_t m_MemoryPool_ua8_front[IMAGE_WIDTH*IMAGE_HEIGHT];
uint8_t m_MemoryPool_ua8_left[IMAGE_WIDTH*IMAGE_HEIGHT];
uint8_t m_MemoryPool_ua8_rear[IMAGE_WIDTH*IMAGE_HEIGHT];
uint8_t m_MemoryPool_ua8_right[IMAGE_WIDTH*IMAGE_HEIGHT];
#endif

unsigned long frameNum_processed = 0;

extern "C" bool_t ME_VariantHelper_GetVariantID_b(uint8_t* var_id);

namespace oc
{

#if !OC_ALGO_VIEW_ENABLE
static uint32_t decimateMap[IMAGE_HEIGHT * IMAGE_WIDTH] = {
        #include "Map.h"
    };
#endif

int OCCamIdMapper [5]= {-1, variants::e_CameraFront, variants::e_CameraLeft, variants::e_CameraRear, variants::e_CameraRight};

DataProviderOC::DataProviderOC(container::IDataProvider& b_DataProvider_ro): IDataProviderOC()
, dataProvider_ro(b_DataProvider_ro) ,tiovxConsumer(), ProcessedFrameNum(frameNum_processed)
{
    OC_DEBUG_PRINTF(("\n*JobOC::DataproviderOC constructor* \n"));
    ME_Debugger_F_Printf_v("\n*JobOC::DataproviderOC constructor*\n");

    // initialize the data here
    m_pFrontInputImage = m_MemoryPool_ua8_front;
    m_pLeftInputImage = m_MemoryPool_ua8_left;
    m_pRearInputImage = m_MemoryPool_ua8_rear;
    m_pRightInputImage = m_MemoryPool_ua8_right;
    memset(&cameraVersion_t, 0xFF, sizeof(cameraVersion_t));
    memset(&oc_hmi_info, 0, sizeof(oc_hmi_info));
    u_frameNo = 0;
}

DataProviderOC::~DataProviderOC()
{

}

#ifdef dump_image_oc
int vid_save_bmp(char *input_filename, char *img, int h, int w)
{
  FILE *f;
  // int filesize = 54 + 3*w*h;  //w is your image width, h is image height, both int
  int filesize = 54 + w * h;  // w is your image width, h is image height, both int
  int i;
  unsigned int image_offset = 54 + 4 * 256; /* offset is file header + Dib header + colormap */
  unsigned char bmpfileheader[14] = { 'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0 };
  unsigned char bmpinfoheader[40] = { 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0 };
  unsigned char bmppad[3] = { 0, 0, 0 };
  bmpfileheader[2] = (unsigned char) (filesize);
  bmpfileheader[3] = (unsigned char) (filesize >> 8);
  bmpfileheader[4] = (unsigned char) (filesize >> 16);
  bmpfileheader[5] = (unsigned char) (filesize >> 24);
  bmpfileheader[0xA] = (unsigned char) (image_offset >> 0); /* set offset of image */
  bmpfileheader[0xB] = (unsigned char) (image_offset >> 8);
  bmpfileheader[0xC] = (unsigned char) (image_offset >> 16);
  bmpfileheader[0xD] = (unsigned char) (image_offset >> 24);
  bmpinfoheader[4] = (unsigned char) (w);
  bmpinfoheader[5] = (unsigned char) (w >> 8);
  bmpinfoheader[6] = (unsigned char) (w >> 16);
  bmpinfoheader[7] = (unsigned char) (w >> 24);
  bmpinfoheader[8] = (unsigned char) (h);
  bmpinfoheader[9] = (unsigned char) (h >> 8);
  bmpinfoheader[10] = (unsigned char) (h >> 16);
  bmpinfoheader[11] = (unsigned char) (h >> 24);
  f = fopen(input_filename, "wb");
  fwrite(bmpfileheader, 1, 14, f);
  fwrite(bmpinfoheader, 1, 40, f);
  // write out 256 entry grayscale
  unsigned char bgr_[4];

  for (i = 0; i < 256; i++)
  {
    bgr_[0] = (char) i;
    bgr_[1] = (char) i;
    bgr_[2] = (char) i;
    bgr_[3] = 0;
    fwrite(bgr_, 1, 4, f);
  }

  for (i = 0; i < h; i++)
  {
    fwrite(img + (w * (h - i - 1)), 1, w, f);
    fwrite(bmppad, 1, (4 - (w) % 4) % 4, f);
    //    fwrite(img+(w*(h-i-1)*3),3,w,f);
    //    fwrite(bmppad,1,(4-(w*3)%4)%4,f);
  }

  fclose(f);
  return (0);
}
#endif

/// @brief  Get AlgoView processor data
container::OVL3DData* DataProviderOC::getOVL3DData_po()
{
  /* DD-ID: {36193577-66B5-4d3b-8438-8A51BB2F3766}*/
  return dataProvider_ro.getOVL3DData_po();
}

/// @brief  Get TIOVX host handle
bsp::TIOVXHost& DataProviderOC::getTIOVX_ro()
{
  /* DD-ID: {950A0AFC-ED18-42ac-B4A8-74533F101734}*/
  return dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
}

void DataProviderOC::setFrontInputImage()
{
  /* DD-ID: {B479FE5E-E333-4a78-A1DB-675C7009FC21}*/
  #if OC_INPUT_IMAGE_PROFILE
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
  #endif
  
#if !OC_ALGO_VIEW_ENABLE
  bsp::VideoInputBufferDesc2_t ro_desc_t;
  bsp::TIOVXHost &v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
  bsp::TIOVXVideoInput &v_videoInput_ro = v_host_ro.getVideoInput_ro();
  uint32_t o_inputBufIdx_u32;
  // wait for input buffers readiness
  bool_t v_result_b = tiovxConsumer.waitSvsVideoBuffer_b(v_videoInput_ro, o_inputBufIdx_u32);
  if(v_result_b)
  {
    /* For front cam */
    v_videoInput_ro.getVideoInputBuffer_b( variants::e_CameraFront, ro_desc_t);
    memcpy(m_MemoryPool_ua8_front, ro_desc_t.buffers_apv[o_inputBufIdx_u32], IMAGE_WIDTH_RAW*IMAGE_HEIGHT_RAW);

	//decimate image
	for (int k = 0; k < IMAGE_HEIGHT*IMAGE_WIDTH; k++)
	{
	  m_pFrontInputImage[k] = m_MemoryPool_ua8_front[decimateMap[k]];
	}
  }
#else
  /* Get the image buffer pointer */
  static container::OVL3DData *v_ovl3d_po = getOVL3DData_po();
  static bsp::TIOVXHost &v_tiovx_ro = getTIOVX_ro();

  uint32_t v_width_u32;
  uint32_t v_height_u32;

  static algo_view_t *v_algoView_pv;
  static Condvar_s v_condvar_s;
  static bsp::VideoInputBufferDesc2_t v_bufferDesc_t;
  static texture_data_t *v_textures_apo[3];

  static uint8 m_InitOnce = 1;

  if (m_InitOnce)
  {
    // create AlgoView descriptor
    if ((v_algoView_pv = v_ovl3d_po->algoViewCreate_po((char *)"algo-fisheye-oc-front", ALGO_VIEW_GRAYSCALE_RAW, v_width_u32, v_height_u32)) == NULL)
    {
        ME_Debugger_F_Printf_v("failed to create OC front algo-view\n");
    }
    else if (v_tiovx_ro.allocVideoBuffer_b(v_width_u32, v_height_u32, SCREEN_FORMAT_BYTE, 1, v_bufferDesc_t) == false)
    {
        ME_Debugger_F_Printf_v("failed to allocate OC front video buffer\n");
    }
    else if (v_ovl3d_po->algoViewBuffersPrepare_b(v_bufferDesc_t, v_textures_apo) == false)
    {
        ME_Debugger_F_Printf_v("failed to prepare OC front image buffers\n");
    }

    memset(&v_condvar_s, 0, sizeof(v_condvar_s));
    ME_Condvar_Init_t(&v_condvar_s);

    m_InitOnce = 0;
  }
  else if(v_algoView_pv != NULL)
  {
    // set first frame number
    static uint32_t v_frameNum_u32 = 0;
    static uint32_t last_v_frameNum_u32 = 0;

    v_ovl3d_po->updateFrame_v(v_frameNum_u32);
    if(last_v_frameNum_u32 < v_frameNum_u32)
    {
      last_v_frameNum_u32 = v_frameNum_u32;
      AlgoViewJob_s v_job_t;

     // wait for next input frame (use every frame nominally)
      // v_ovl3d_po->waitFrame_b(v_frameNum_u32);

      v_job_t.algoView_po = v_algoView_pv;
      v_job_t.condvar_po = &v_condvar_s;
      v_job_t.output_apo = v_textures_apo;
      v_job_t.sync_ppo = NULL;

      ME_Mutex_Lock_t(&v_condvar_s.MEMutex_po);

      if (v_ovl3d_po->algoViewJobSubmit_b(&v_job_t) == true)
      {
        // wait for job completion (explicitly)
        ME_Condvar_Wait_t(&v_condvar_s);
      }

      ME_Mutex_UnLock_t(&v_condvar_s.MEMutex_po);

      uint32_t *v_data_pu32 = static_cast<uint32_t *>(v_bufferDesc_t.buffers_apv[0]);
      memcpy(m_pFrontInputImage, v_data_pu32, IMAGE_WIDTH*IMAGE_HEIGHT);
    }
  }

#endif

  #if OC_INPUT_IMAGE_PROFILE
    static uint64_t v_PrevTimeFront_u64 = 0;
    uint64_t v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    uint64_t v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("setFrontInputImage: TimeElapsed: %lld, TotalTime: %f \n", v_Time_o.getTimeMsec_u64() - v_PrevTimeFront_u64, (float32_t)(v_TotalTime_u64 * 1.0f));
    v_PrevTimeFront_u64 = v_Time_o.getTimeMsec_u64();
  #endif
  
  #if OC_INPUT_IMAGE_DUMP
    static char FileName[64] = {0};
    static uint8_t v_cntr = 0;
    static uint32_t v_FrameCounter_u32 = 0;

    sprintf(FileName, "/ti_sd/FrontImage_%d.bin", v_FrameCounter_u32++);

    if (v_FrameCounter_u32 > 1)
    {
      if (0 == v_FrameCounter_u32 % 50u)
      {
        if (v_cntr < 2)
    	{
          FILE *fptr = fopen(FileName, "w");
          if (NULL != fptr)
          {
            ME_Debugger_F_Printf_v("Dumping OC Front algo view :: frameCntr : %d, WhlAngl : %f, Speed : %f \n", v_FrameCounter_u32, getWheelAngle_f32(), getSpeed_f32());
        	(void)fwrite(m_pFrontInputImage, 1, IMAGE_WIDTH*IMAGE_HEIGHT, fptr);
        	fclose(fptr);
        	fptr = NULL;
        	v_cntr++;
          }
    	}
      }
    }
  #endif

  #ifdef dump_image_oc
    char img[200];
    sprintf (img, "/tmp/img_%d.bmp",(int)variants ::e_CameraFront);
    vid_save_bmp(img, m_pFrontInputImage, IMAGE_HEIGHT, IMAGE_WIDTH);
  #endif

}

void DataProviderOC::setLeftInputImage() 
{
  /* DD-ID: {9860CAF9-B0A2-4130-8F25-244BBA0DE5FA}*/
  #if OC_INPUT_IMAGE_PROFILE
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
  #endif
  
#if !OC_ALGO_VIEW_ENABLE
  bsp::VideoInputBufferDesc2_t ro_desc_t;
  bsp::TIOVXHost &v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
  bsp::TIOVXVideoInput &v_videoInput_ro = v_host_ro.getVideoInput_ro();
  uint32_t o_inputBufIdx_u32;
  // wait for input buffers readiness
  bool_t v_result_b = tiovxConsumer.waitSvsVideoBuffer_b(v_videoInput_ro, o_inputBufIdx_u32);
  if(v_result_b)
  {
    /* For front cam */
    v_videoInput_ro.getVideoInputBuffer_b( variants::e_CameraLeft, ro_desc_t);
    memcpy(m_MemoryPool_ua8_left, ro_desc_t.buffers_apv[o_inputBufIdx_u32], IMAGE_WIDTH_RAW*IMAGE_HEIGHT_RAW);

    //decimate image
    for (int k = 0; k < IMAGE_HEIGHT*IMAGE_WIDTH; k++)
    {
      m_pLeftInputImage[k] = m_MemoryPool_ua8_left[decimateMap[k]];
    }
  }
#else
  /* Get the image buffer pointer */
  static container::OVL3DData *v_ovl3d_po = getOVL3DData_po();
  static bsp::TIOVXHost &v_tiovx_ro = getTIOVX_ro();

  uint32_t v_width_u32;
  uint32_t v_height_u32;

  static algo_view_t *v_algoView_pv;
  static Condvar_s v_condvar_s;
  static bsp::VideoInputBufferDesc2_t v_bufferDesc_t;
  static texture_data_t *v_textures_apo[3];

  static uint8 m_InitOnce = 1;

  if (m_InitOnce)
  {
    // create AlgoView descriptor
    if ((v_algoView_pv = v_ovl3d_po->algoViewCreate_po((char *)"algo-fisheye-oc-left", ALGO_VIEW_GRAYSCALE_RAW, v_width_u32, v_height_u32)) == NULL)
    {
        ME_Debugger_F_Printf_v("failed to create OC Left algo-view\n");
    }
    else if (v_tiovx_ro.allocVideoBuffer_b(v_width_u32, v_height_u32, SCREEN_FORMAT_BYTE, 1, v_bufferDesc_t) == false)
    {
        ME_Debugger_F_Printf_v("failed to allocate OC Left video buffer\n");
    }
    else if (v_ovl3d_po->algoViewBuffersPrepare_b(v_bufferDesc_t, v_textures_apo) == false)
    {
        ME_Debugger_F_Printf_v("failed to prepare OC Left image buffers\n");
    }

    memset(&v_condvar_s, 0, sizeof(v_condvar_s));
    ME_Condvar_Init_t(&v_condvar_s);

    m_InitOnce = 0;
  }
  else if(v_algoView_pv != NULL)
  {
    // set first frame number
    static uint32_t v_frameNum_u32 = 0;
    static uint32_t last_v_frameNum_u32 = 0;

    v_ovl3d_po->updateFrame_v(v_frameNum_u32);
    if(last_v_frameNum_u32 < v_frameNum_u32)
    {
      last_v_frameNum_u32 = v_frameNum_u32;
     AlgoViewJob_s v_job_t;

     // wait for next input frame (use every frame nominally)
      // v_ovl3d_po->waitFrame_b(v_frameNum_u32);

     v_job_t.algoView_po = v_algoView_pv;
     v_job_t.condvar_po = &v_condvar_s;
     v_job_t.output_apo = v_textures_apo;
     v_job_t.sync_ppo = NULL;

     ME_Mutex_Lock_t(&v_condvar_s.MEMutex_po);

     if (v_ovl3d_po->algoViewJobSubmit_b(&v_job_t) == true)
     {
       // wait for job completion (explicitly)
       ME_Condvar_Wait_t(&v_condvar_s);
     }

     ME_Mutex_UnLock_t(&v_condvar_s.MEMutex_po);

     uint32_t *v_data_pu32 = static_cast<uint32_t *>(v_bufferDesc_t.buffers_apv[0]);
     memcpy(m_pLeftInputImage, v_data_pu32, IMAGE_WIDTH*IMAGE_HEIGHT);
    }
  }
#endif

  #if OC_INPUT_IMAGE_PROFILE
    static uint64_t v_PrevTimeLeft_u64 = 0;
    uint64_t v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    uint64_t v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("setLeftInputImage: TimeElapsed: %lld, TotalTime: %f \n", v_Time_o.getTimeMsec_u64() - v_PrevTimeLeft_u64, (float32_t)(v_TotalTime_u64 * 1.0f));
    v_PrevTimeLeft_u64 = v_Time_o.getTimeMsec_u64();
  #endif
  
#if OC_INPUT_IMAGE_DUMP
  static char FileName[64] = {0};
  static uint8_t v_cntr = 0;
  static uint32_t v_FrameCounter_u32 = 0;

  sprintf(FileName, "/ti_sd/LeftImage_%d.bin", v_FrameCounter_u32++);

  if (v_FrameCounter_u32 > 1)
  {
    if (0 == v_FrameCounter_u32 % 50u)
    {
      if (v_cntr < 2)
  	  {
        FILE *fptr = fopen(FileName, "w");
        if (NULL != fptr)
        {
          ME_Debugger_F_Printf_v("Dumping OC Left algo view :: frameCntr : %d, WhlAngl : %f, Speed : %f \n", v_FrameCounter_u32, getWheelAngle_f32(), getSpeed_f32());
      	  (void)fwrite(m_pLeftInputImage, 1, IMAGE_WIDTH*IMAGE_HEIGHT, fptr);
      	  fclose(fptr);
      	  fptr = NULL;
      	  v_cntr++;
        }
  	  }
    }
  }
#endif

#ifdef dump_image_oc
  char img[200];
  sprintf (img, "/tmp/img_%d.bmp",(int)variants ::e_CameraLeft);
  vid_save_bmp(img, m_pLeftInputImage, IMAGE_HEIGHT, IMAGE_WIDTH);
#endif
}

void DataProviderOC::setRearInputImage()
{
  /* DD-ID: {EC670469-124F-4813-A30B-A1E0E38FDCA0}*/
  #if OC_INPUT_IMAGE_PROFILE
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
  #endif
  
#if !OC_ALGO_VIEW_ENABLE
  bsp::VideoInputBufferDesc2_t ro_desc_t;
  bsp::TIOVXHost &v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
  bsp::TIOVXVideoInput &v_videoInput_ro = v_host_ro.getVideoInput_ro();
  uint32_t o_inputBufIdx_u32;
  // wait for input buffers readiness
  bool_t v_result_b = tiovxConsumer.waitSvsVideoBuffer_b(v_videoInput_ro, o_inputBufIdx_u32);
  if(v_result_b)
  {
	 /* For front cam */
	 v_videoInput_ro.getVideoInputBuffer_b( variants::e_CameraRear, ro_desc_t);
	 memcpy(m_MemoryPool_ua8_rear, ro_desc_t.buffers_apv[o_inputBufIdx_u32], IMAGE_WIDTH_RAW*IMAGE_HEIGHT_RAW);

     //decimate image
     for (int k = 0; k < IMAGE_HEIGHT*IMAGE_WIDTH; k++)
     {
       m_pRearInputImage[k] = m_MemoryPool_ua8_rear[decimateMap[k]];
     }
  }
#else
  /* Get the image buffer pointer */
  static container::OVL3DData *v_ovl3d_po = getOVL3DData_po();
  static bsp::TIOVXHost &v_tiovx_ro = getTIOVX_ro();

  uint32_t v_width_u32;
  uint32_t v_height_u32;

  static algo_view_t *v_algoView_pv;
  static Condvar_s v_condvar_s;
  static bsp::VideoInputBufferDesc2_t v_bufferDesc_t;
  static texture_data_t *v_textures_apo[3];

  static uint8 m_InitOnce = 1;

  if (m_InitOnce)
  {
    // create AlgoView descriptor
    if ((v_algoView_pv = v_ovl3d_po->algoViewCreate_po((char *)"algo-fisheye-oc-rear", ALGO_VIEW_GRAYSCALE_RAW, v_width_u32, v_height_u32)) == NULL)
    {
        ME_Debugger_F_Printf_v("failed to create OC rear algo-view\n");
    }
    else if (v_tiovx_ro.allocVideoBuffer_b(v_width_u32, v_height_u32, SCREEN_FORMAT_BYTE, 1, v_bufferDesc_t) == false)
    {
        ME_Debugger_F_Printf_v("failed to allocate OC rear video buffer\n");
    }
    else if (v_ovl3d_po->algoViewBuffersPrepare_b(v_bufferDesc_t, v_textures_apo) == false)
    {
        ME_Debugger_F_Printf_v("failed to prepare OC rear image buffers\n");
    }

    memset(&v_condvar_s, 0, sizeof(v_condvar_s));
    ME_Condvar_Init_t(&v_condvar_s);

    m_InitOnce = 0;
  }
  else if(v_algoView_pv != NULL)
  {
    // set first frame number
    static uint32_t v_frameNum_u32 = 0;
    static uint32_t last_v_frameNum_u32 = 0;

    v_ovl3d_po->updateFrame_v(v_frameNum_u32);
    if(last_v_frameNum_u32 < v_frameNum_u32)
    {
      last_v_frameNum_u32 = v_frameNum_u32;
     AlgoViewJob_s v_job_t;

     // wait for next input frame (use every frame nominally)
      // v_ovl3d_po->waitFrame_b(v_frameNum_u32);

     v_job_t.algoView_po = v_algoView_pv;
     v_job_t.condvar_po = &v_condvar_s;
     v_job_t.output_apo = v_textures_apo;
     v_job_t.sync_ppo = NULL;

     ME_Mutex_Lock_t(&v_condvar_s.MEMutex_po);

     if (v_ovl3d_po->algoViewJobSubmit_b(&v_job_t) == true)
     {
       // wait for job completion (explicitly)
       ME_Condvar_Wait_t(&v_condvar_s);
     }

     ME_Mutex_UnLock_t(&v_condvar_s.MEMutex_po);

     uint32_t *v_data_pu32 = static_cast<uint32_t *>(v_bufferDesc_t.buffers_apv[0]);
     memcpy(m_pRearInputImage, v_data_pu32, IMAGE_WIDTH*IMAGE_HEIGHT);
    }
  }

#endif

  #if OC_INPUT_IMAGE_PROFILE
    static uint64_t v_PrevTimeRear_u64 = 0;
    uint64_t v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    uint64_t v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("setRearInputImage: TimeElapsed: %lld, TotalTime: %f \n", v_Time_o.getTimeMsec_u64() - v_PrevTimeRear_u64, (float32_t)(v_TotalTime_u64 * 1.0f));
    v_PrevTimeRear_u64 = v_Time_o.getTimeMsec_u64();
  #endif
  
#if OC_INPUT_IMAGE_DUMP
  static char FileName[64] = {0};
  static uint8_t v_cntr = 0;
  static uint32_t v_FrameCounter_u32 = 0;

  sprintf(FileName, "/ti_sd/RearImage_%d.bin", v_FrameCounter_u32++);

  if (v_FrameCounter_u32 > 1)
  {
    if (0 == v_FrameCounter_u32 % 50u)
    {
      if (v_cntr < 2)
  	  {
        FILE *fptr = fopen(FileName, "w");
        if (NULL != fptr)
        {
          ME_Debugger_F_Printf_v("Dumping OC Rear algo view :: frameCntr : %d, WhlAngl : %f, Speed : %f \n", v_FrameCounter_u32, getWheelAngle_f32(), getSpeed_f32());
      	  (void)fwrite(m_pRearInputImage, 1, IMAGE_WIDTH*IMAGE_HEIGHT, fptr);
      	  fclose(fptr);
      	  fptr = NULL;
      	  v_cntr++;
        }
  	  }
    }
  }
#endif

#ifdef dump_image_oc
    char img[200];
    sprintf (img, "/tmp/img_%d.bmp",(int)variants::e_CameraRear);
    vid_save_bmp(img, m_pRearInputImage, IMAGE_HEIGHT, IMAGE_WIDTH);
#endif

}

void DataProviderOC::setRightInputImage() 
{
  /* DD-ID: {82511D4F-4A5E-4a24-BD1E-9931948446BB}*/
  #if OC_INPUT_IMAGE_PROFILE
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
  #endif
  
#if !OC_ALGO_VIEW_ENABLE
  bsp::VideoInputBufferDesc2_t ro_desc_t;
  bsp::TIOVXHost &v_host_ro = dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
  bsp::TIOVXVideoInput &v_videoInput_ro = v_host_ro.getVideoInput_ro();
  uint32_t o_inputBufIdx_u32;
  // wait for input buffers readiness
  bool_t v_result_b = tiovxConsumer.waitSvsVideoBuffer_b(v_videoInput_ro, o_inputBufIdx_u32);
  if(v_result_b)
  {
    /* For front cam */
    v_videoInput_ro.getVideoInputBuffer_b( variants::e_CameraRight, ro_desc_t);
    memcpy(m_MemoryPool_ua8_right, ro_desc_t.buffers_apv[o_inputBufIdx_u32], IMAGE_WIDTH_RAW*IMAGE_HEIGHT_RAW);

    //decimate image
    for (int k = 0; k < IMAGE_HEIGHT*IMAGE_WIDTH; k++)
    {
      m_pRightInputImage[k] = m_MemoryPool_ua8_right[decimateMap[k]];
    }
  }

#else
    /* Get the image buffer pointer */
    static container::OVL3DData *v_ovl3d_po = getOVL3DData_po();
    static bsp::TIOVXHost &v_tiovx_ro = getTIOVX_ro();

    uint32_t v_width_u32;
    uint32_t v_height_u32;

    static algo_view_t *v_algoView_pv;
    static Condvar_s v_condvar_s;
    static bsp::VideoInputBufferDesc2_t v_bufferDesc_t;
    static texture_data_t *v_textures_apo[3];

    static uint8 m_InitOnce = 1;

    if (m_InitOnce)
    {
      // create AlgoView descriptor
      if ((v_algoView_pv = v_ovl3d_po->algoViewCreate_po((char *)"algo-fisheye-oc-right", ALGO_VIEW_GRAYSCALE_RAW, v_width_u32, v_height_u32)) == NULL)
      {
          ME_Debugger_F_Printf_v("failed to create OC right algo-view\n");
      }
      else if (v_tiovx_ro.allocVideoBuffer_b(v_width_u32, v_height_u32, SCREEN_FORMAT_BYTE, 1, v_bufferDesc_t) == false)
      {
          ME_Debugger_F_Printf_v("failed to allocate OC right video buffer\n");
      }
      else if (v_ovl3d_po->algoViewBuffersPrepare_b(v_bufferDesc_t, v_textures_apo) == false)
      {
          ME_Debugger_F_Printf_v("failed to prepare OC right image buffers\n");
      }

      memset(&v_condvar_s, 0, sizeof(v_condvar_s));
      ME_Condvar_Init_t(&v_condvar_s);

      m_InitOnce = 0;
    }
    else if(v_algoView_pv != NULL)
    {
      // set first frame number
      static uint32_t v_frameNum_u32 = 0;
      static uint32_t last_v_frameNum_u32 = 0;

      v_ovl3d_po->updateFrame_v(v_frameNum_u32);
      if(last_v_frameNum_u32 < v_frameNum_u32)
      {
        last_v_frameNum_u32 = v_frameNum_u32;
        AlgoViewJob_s v_job_t;

        // wait for next input frame (use every frame nominally)
         // v_ovl3d_po->waitFrame_b(v_frameNum_u32);

        v_job_t.algoView_po = v_algoView_pv;
        v_job_t.condvar_po = &v_condvar_s;
        v_job_t.output_apo = v_textures_apo;
        v_job_t.sync_ppo = NULL;

        ME_Mutex_Lock_t(&v_condvar_s.MEMutex_po);

        if (v_ovl3d_po->algoViewJobSubmit_b(&v_job_t) == true)
        {
          // wait for job completion (explicitly)
          ME_Condvar_Wait_t(&v_condvar_s);
        }

        ME_Mutex_UnLock_t(&v_condvar_s.MEMutex_po);

        uint32_t *v_data_pu32 = static_cast<uint32_t *>(v_bufferDesc_t.buffers_apv[0]);
        memcpy(m_pRightInputImage, v_data_pu32, IMAGE_WIDTH*IMAGE_HEIGHT);
      }
    }
#endif

  #if OC_INPUT_IMAGE_PROFILE
    static uint64_t v_PrevTimeRight_u64 = 0;
    uint64_t v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    uint64_t v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("setRightInputImage: TimeElapsed: %lld, TotalTime: %f \n", v_Time_o.getTimeMsec_u64() - v_PrevTimeRight_u64, (float32_t)(v_TotalTime_u64 * 1.0f));
    v_PrevTimeRight_u64 = v_Time_o.getTimeMsec_u64();
  #endif

#if OC_INPUT_IMAGE_DUMP
  static char FileName[64] = {0};
  static uint8_t v_cntr = 0;
  static uint32_t v_FrameCounter_u32 = 0;

  sprintf(FileName, "/ti_sd/RightImage_%d.bin", v_FrameCounter_u32++);

  if (v_FrameCounter_u32 > 1)
  {
    if (0 == v_FrameCounter_u32 % 50u)
    {
      if (v_cntr < 2)
  	  {
        FILE *fptr = fopen(FileName, "w");
        if (NULL != fptr)
        {
          ME_Debugger_F_Printf_v("Dumping OC Right algo view :: frameCntr : %d, WhlAngl : %f, Speed : %f \n", v_FrameCounter_u32, getWheelAngle_f32(), getSpeed_f32());
      	  (void)fwrite(m_pRightInputImage, 1, IMAGE_WIDTH*IMAGE_HEIGHT, fptr);
      	  fclose(fptr);
      	  fptr = NULL;
      	  v_cntr++;
        }
  	  }
    }
  }
#endif

#ifdef dump_image_oc
  char img[200];
  sprintf (img, "/tmp/img_%d.bmp",(int)variants ::e_CameraRight);
  vid_save_bmp(img, m_pRightInputImage, IMAGE_HEIGHT, IMAGE_WIDTH);
#endif

}

void DataProviderOC::setFrameNum_u32()
{
  /* DD-ID: {458D27D7-01F0-4c50-868C-C2A81F4DA503}*/
  u_frameNo++;
}

uint32_t DataProviderOC::getFrameNum_u32() const // <<framenum should be coming from BSW
{
  /* DD-ID: {4DD7A72C-0330-416d-A29A-ADECDC2C795A}*/
   return u_frameNo; 
}

void DataProviderOC::dump_FrontAlgoViewImages()
{
  /* DD-ID: {296559BC-2BB1-4c6d-BDCC-9F5DCBE90849}*/
  static char FileName[64] = {0};
  static uint8_t v_cntr = 0;
  static uint32_t v_FrameCounter_u32 = 0;

  sprintf(FileName, "/ti_sd/FrontImage_%d.bin", v_FrameCounter_u32++);

  /* Capturing the CAN Data */
  ME_Debugger_F_Printf_v("CAN Data :: frameCntr : %d, WhlAngl : %f, Speed : %f \n", v_FrameCounter_u32, getWheelAngle_f32(), getSpeed_f32() );

  FILE *fptr = fopen(FileName, "w");
  if (NULL != fptr)
  {
    ME_Debugger_F_Printf_v("Dumping OC Front algo view :: frameCntr : %d \n", v_FrameCounter_u32);
  (void)fwrite(m_pFrontInputImage, 1, IMAGE_WIDTH*IMAGE_HEIGHT, fptr);
  fclose(fptr);
  fptr = NULL;
  v_cntr++;
  }
}

void DataProviderOC::dump_LeftAlgoViewImages()
{
  /* DD-ID: {4583E8D5-29AE-489c-8594-B32BEBA7D294}*/
  static char FileName[64] = {0};
  static uint8_t v_cntr = 0;
  static uint32_t v_FrameCounter_u32 = 0;

  sprintf(FileName, "/ti_sd/LeftImage_%d.bin", v_FrameCounter_u32++);

  FILE *fptr = fopen(FileName, "w");

  if (NULL != fptr)
  {
    ME_Debugger_F_Printf_v("Dumping OC Left algo view :: frameCntr : %d \n", v_FrameCounter_u32);
    (void)fwrite(m_pLeftInputImage, 1, IMAGE_WIDTH*IMAGE_HEIGHT, fptr);
    fclose(fptr);
    fptr = NULL;
    v_cntr++;
  }
}

void DataProviderOC::dump_RearAlgoViewImages()
{
  /* DD-ID: {5D0C755C-6D67-4339-8DEB-D99B8DA28134}*/
	static char FileName[64] = {0};
	static uint8_t v_cntr = 0;
	static uint32_t v_FrameCounter_u32 = 0;

	sprintf(FileName, "/ti_sd/RearImage_%d.bin", v_FrameCounter_u32++);

	FILE *fptr = fopen(FileName, "w");
	if (NULL != fptr)
	{
	  ME_Debugger_F_Printf_v("Dumping OC Rear algo view :: frameCntr : %d \n", v_FrameCounter_u32);
	 (void)fwrite(m_pRearInputImage, 1, IMAGE_WIDTH*IMAGE_HEIGHT, fptr);
	 fclose(fptr);
	 fptr = NULL;
	 v_cntr++;
	}
}

void DataProviderOC::dump_RightAlgoViewImages()
{
  /* DD-ID: {8F30016E-55C4-4ff3-8D4A-4D23C7461987}*/
  static char FileName[64] = {0};
  static uint8_t v_cntr = 0;
  static uint32_t v_FrameCounter_u32 = 0;

  sprintf(FileName, "/ti_sd/RightImage_%d.bin", v_FrameCounter_u32++);

  FILE *fptr = fopen(FileName, "w");
  if (NULL != fptr)
  {
    ME_Debugger_F_Printf_v("Dumping OC Right algo view :: frameCntr : %d \n", v_FrameCounter_u32);
    (void)fwrite(m_pRightInputImage, 1, IMAGE_WIDTH*IMAGE_HEIGHT, fptr);
    fclose(fptr);
    fptr = NULL;
    v_cntr++;
  }
}

float32_t DataProviderOC::getSpeed_f32() const
{
  /* DD-ID: {0B0D70A8-67DE-4270-824F-B240BE3E6C28}*/
  ME_VehInp_to_IpcSignals_t v_vehData = dataProvider_ro.getSigMData_po()->getME_VehInp_to_IpcSignals_t();
  float32_t v_speed_f32 = mecl::math::abs_x(v_vehData.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig);

  return v_speed_f32;
}

float32_t DataProviderOC::getWheelAngle_f32() const
{
  /* DD-ID: {CD6727FA-6BE4-4f1e-A13B-1814DB8EB489}*/
  /* Default variant */
  static uint8_t v_VarId_u8 = 8;

  static uint8_t v_PrevVarId_u8;
  static uint8_t v_VariantReadRetryCnt = 0u;
  static bool_t VariantReadSuccess_b = false;

  static bool_t result_b = false;
  float32_t v_wheelAngle_f32;

  ME_VehInp_to_IpcSignals_t v_vehData = dataProvider_ro.getSigMData_po()->getME_VehInp_to_IpcSignals_t();
  
  if ( (false == VariantReadSuccess_b) && (v_VariantReadRetryCnt < 5u) )
  {
    /* Current wheel angle is for 60cf. In future the wheel angle needs to be adopted based on variant
     * details for 55cf and 63cf */
    result_b = ME_VariantHelper_GetVariantID_b(&v_VarId_u8);

    /* 5 times retry will be done to read the variant if the variant read failed for first time */
    v_VariantReadRetryCnt++;
  }

  if (true == result_b)
  {
    switch(v_VarId_u8)
    {
      case variants::e_VariantId1:
      case variants::e_VariantId2:
      case variants::e_VariantId6:
      case variants::e_VariantId8:
      case variants::e_VariantId12:
      case variants::e_VariantId13:
      case variants::e_VariantId14:
      case variants::e_VariantId15:
      case variants::e_VariantId16:
      case variants::e_VariantId17:
      {
        v_wheelAngle_f32 = v_vehData.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle * (-0.0640842f) + (-0.154752f);
        break;
      }
      case variants::e_VariantId3:
      case variants::e_VariantId7:
      case variants::e_VariantId9:
      case variants::e_VariantId10:
      case variants::e_VariantId11:
      case variants::e_VariantId18:
      {
        v_wheelAngle_f32 = v_vehData.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle * (-0.0670865f) + (-0.0129193f);
        break;
      }
      case variants::e_VariantId4:
      case variants::e_VariantId5:
      case variants::e_VariantId19:
      {
        v_wheelAngle_f32 = v_vehData.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle * (-0.0593083f) + (-0.0187606f);
        break;
      }

      default:
        v_wheelAngle_f32 = v_vehData.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle * (-0.0640842f) + (-0.154752f);
        break;
    }

    VariantReadSuccess_b = true;

  }
  else
  {
    /* Calculate the wheel angle for default variant */
    v_wheelAngle_f32 = v_vehData.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle * (-0.0640842f) + (-0.154752f);
  }

  /* 55cf : float32_t v_wheelAngle_f32 = v_vehData.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle * (-0.0593083f) + (-0.0187606f);
   * 63cf : float32_t v_wheelAngle_f32 = v_vehData.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle * (-0.0670865f) + (-0.0129193f);
   */
  if (v_VarId_u8 != v_PrevVarId_u8)
  {
    OC_DEBUG_PRINTF(("variant_id : %d, v_wheelAngle_f32 : %f\n",v_VarId_u8, v_wheelAngle_f32));
    v_PrevVarId_u8 = v_VarId_u8;
  }

  /* Converting the wheel angle to radian with multiplying factor 0.01745329 */
  v_wheelAngle_f32 = (v_wheelAngle_f32 * 0.01745329);//(v_wheelAngle_f32 * (3.14159265359/180));

  return v_wheelAngle_f32;
}

unsigned long& DataProviderOC::getProcessedFrameNum()
{
  /* DD-ID: {89AAD018-9474-43ee-928A-68941A2B84B0}*/
    return ProcessedFrameNum;
}

do_CameraParam& DataProviderOC::getFrontDoCameraParam()
{
  /* DD-ID: {ACA90FE5-6C62-4b6e-AEAF-8BAA49E5192B}*/
    return m_aFrontCameraInfo;
}

do_CameraParam& DataProviderOC::getLeftDoCameraParam()
{
  /* DD-ID: {9693A01C-9841-4015-9488-20A24A06688A}*/
    return m_aLeftCameraInfo;
}

do_CameraParam& DataProviderOC::getRearDoCameraParam()
{
  /* DD-ID: {4DE48667-6BBB-4798-9D52-1BC901A6BACC}*/
    return m_aRearCameraInfo;
}

do_CameraParam& DataProviderOC::getRightDoCameraParam()
{
  /* DD-ID: {21CBA910-9F6D-4952-B5FA-EC7F0AD4A6F5}*/
    return m_aRightCameraInfo;
}

const uint8_t* DataProviderOC::getFrontInputImage() const
{
  /* DD-ID: {07CF78CE-1ED2-4a26-B69C-3A1E6EEF354C}*/
     return m_pFrontInputImage; 

}

const uint8_t* DataProviderOC::getLeftInputImage() const
{
  /* DD-ID: {04969410-3129-477a-98C2-B25E3BE28472}*/

     return m_pLeftInputImage; 

}

const uint8_t* DataProviderOC::getRearInputImage() const
{
  /* DD-ID: {4565C5BB-1F0A-41dc-B0B0-49F47CD4BF9E}*/

     return m_pRearInputImage; 
}

const uint8_t* DataProviderOC::getRightInputImage() const
{
  /* DD-ID: {CA38E8DF-B2A7-45bd-AB7D-E52D592DAF81}*/

     return m_pRightInputImage; 
}


unsigned long DataProviderOC::getOCImpl() const
{
  /* DD-ID: {78B12267-8588-40b2-8A15-445BB9883DE2}*/
    return hOCImpl;
}

void DataProviderOC::getOCRequest_v( container::RequestOCCalibCmd_t& o_OCRequest_rt )
{
  /* DD-ID: {E987BCA4-5F08-409d-BAAD-0E63488FD0CD}*/
  i_SMToOCAlgo = dataProvider_ro.getCalSmMData_po()->getSVSCalibSMToAlgoCamCalib();

  static TbSVS_e_SVSCalibSMToAlgoCamCalib_t i_SMToOCAlgoPrev;
  if ( (i_SMToOCAlgo.AlgoCntrlHeader_t.AlgoCommand != i_SMToOCAlgoPrev.AlgoCntrlHeader_t.AlgoCommand) ||
	   (i_SMToOCAlgo.AlgoCntrlHeader_t.CurrentCamID != i_SMToOCAlgoPrev.AlgoCntrlHeader_t.CurrentCamID) ||
	   (i_SMToOCAlgo.AlgoCntrlHeader_t.AlgoID != i_SMToOCAlgoPrev.AlgoCntrlHeader_t.AlgoID))

  {
    OC_DEBUG_PRINTF(("OC AlgoId=%d,  CmdId =%d, CamId = %d\n",
                    i_SMToOCAlgo.AlgoCntrlHeader_t.AlgoID,
                    i_SMToOCAlgo.AlgoCntrlHeader_t.AlgoCommand,
                    i_SMToOCAlgo.AlgoCntrlHeader_t.CurrentCamID));

    i_SMToOCAlgoPrev = i_SMToOCAlgo;
  }

  o_OCRequest_rt.cmd_t = i_SMToOCAlgo.AlgoCntrlHeader_t.AlgoCommand; // Populate algo command request

  CalsmAlgoType = i_SMToOCAlgo.AlgoCntrlHeader_t.AlgoID;

  switch(i_SMToOCAlgo.AlgoCntrlHeader_t.AlgoID) //Populate Algo ID
  {
    case ME_Hydra3defs_E_AlgoID_e::AlgoID_SC:
    case ME_Hydra3defs_E_AlgoID_e::AlgoID_OC:
       o_OCRequest_rt.calibrationType_t = variants::e_CalibTypeSC;
     break;
    default:
       o_OCRequest_rt.calibrationType_t = variants::e_CalibTypeNONE;
     break;
  }

  switch (i_SMToOCAlgo.AlgoCntrlHeader_t.CurrentCamID) //Populate Current CAM ID
  {
    case CamID_Front:
       o_OCRequest_rt.camera_u32 = 0;
     break;

    case CamID_Left:
       o_OCRequest_rt.camera_u32 = 1;
     break;

    case CamID_Rear:
      o_OCRequest_rt.camera_u32 = 2;
     break;

    case CamID_Right:
       o_OCRequest_rt.camera_u32 = 3;
     break;

    default:
       o_OCRequest_rt.camera_u32 = 6;
     break;
  }
}

void DataProviderOC::getOCConfig_v ( uint32_t i_CamID, tscApi::tscPlatformExtConfigType * i_CamConfig_p )
{
  /* DD-ID: {1A5DA841-8974-4538-A852-2E69CF34C0E3}*/
    OCCameraCfg_t o_OCCameraCfg_pt;
    bool_t v_success = variantOc_GetCameraOCcalibration_b ( (variants::Camera_t)i_CamID , &o_OCCameraCfg_pt );
    if(v_success == true)
    {
        i_CamConfig_p->featureColExternalConfig_t.trajectoryFilterConfig_t.minPixelMotionThresh_u32            = o_OCCameraCfg_pt.m_ocTrajectory_t.m_MinimumPixelMotion_u32;
        i_CamConfig_p->featureColExternalConfig_t.trajectoryFilterConfig_t.slopeDifferenceThreshold_f64        = o_OCCameraCfg_pt.m_ocTrajectory_t.m_SlopeDifferenceThresh_f32;
        i_CamConfig_p->featureColExternalConfig_t.trajectoryFilterConfig_t.useSfmFilter_b                      = o_OCCameraCfg_pt.m_ocTrajectory_t.m_UseSfMFilter_u32;
        i_CamConfig_p->featureColExternalConfig_t.trajectoryFilterConfig_t.maxHeightDiffMm_f64                 = o_OCCameraCfg_pt.m_ocTrajectory_t.m_MaxHeightDiff_f32;
        i_CamConfig_p->featureColExternalConfig_t.trajectoryFilterConfig_t.angleThresholdDegIG_f64             = o_OCCameraCfg_pt.m_ocTrajectory_t.m_AngleThresh_f32;
        i_CamConfig_p->featureColExternalConfig_t.trajectoryFilterConfig_t.deviationPercentageIG_u32           = o_OCCameraCfg_pt.m_ocTrajectory_t.m_DeviationPercentage_f32;
        i_CamConfig_p->featureColExternalConfig_t.trajectoryFilterConfig_t.useCombinations_b                   = o_OCCameraCfg_pt.m_ocTrajectory_t.m_UseCombinations_u32;
        i_CamConfig_p->featureColExternalConfig_t.trajectoryFilterConfig_t.combinationsDiffThresholdDeg_f64    = o_OCCameraCfg_pt.m_ocTrajectory_t.m_CombinationsDiffThreshold_f32;
        // BMALFC
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[0] = o_OCCameraCfg_pt.m_ocBMALFC_t.m_SpeedRanges_af32[0];
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[1] = o_OCCameraCfg_pt.m_ocBMALFC_t.m_SpeedRanges_af32[1];
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[2] = o_OCCameraCfg_pt.m_ocBMALFC_t.m_SpeedRanges_af32[2];
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[3] = o_OCCameraCfg_pt.m_ocBMALFC_t.m_SpeedRanges_af32[3];
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[4] = o_OCCameraCfg_pt.m_ocBMALFC_t.m_SpeedRanges_af32[4];
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.speedRanges_au32[5] = o_OCCameraCfg_pt.m_ocBMALFC_t.m_SpeedRanges_af32[5];
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [0] = o_OCCameraCfg_pt.m_ocBMALFC_t.m_FrameSkips_au32[0];
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [1] = o_OCCameraCfg_pt.m_ocBMALFC_t.m_FrameSkips_au32[1];
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [2] = o_OCCameraCfg_pt.m_ocBMALFC_t.m_FrameSkips_au32[2];
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [3] = o_OCCameraCfg_pt.m_ocBMALFC_t.m_FrameSkips_au32[3];
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [4] = o_OCCameraCfg_pt.m_ocBMALFC_t.m_FrameSkips_au32[4];
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.frameSkips_au32 [5] = o_OCCameraCfg_pt.m_ocBMALFC_t.m_FrameSkips_au32[5];
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].x_s32 = o_OCCameraCfg_pt.m_ocBMALFC_t.m_OCroiSets_t.m_VarOCroiPool_at[0].m_VarOCRect_at[0].left;
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].y_s32 = o_OCCameraCfg_pt.m_ocBMALFC_t.m_OCroiSets_t.m_VarOCroiPool_at[0].m_VarOCRect_at[0].top;
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].width_s32 = o_OCCameraCfg_pt.m_ocBMALFC_t.m_OCroiSets_t.m_VarOCroiPool_at[0].m_VarOCRect_at[0].width;
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[0].height_s32 = o_OCCameraCfg_pt.m_ocBMALFC_t.m_OCroiSets_t.m_VarOCroiPool_at[0].m_VarOCRect_at[0].height;
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].x_s32 = o_OCCameraCfg_pt.m_ocBMALFC_t.m_OCroiSets_t.m_VarOCroiPool_at[1].m_VarOCRect_at[0].left;;
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].y_s32 = o_OCCameraCfg_pt.m_ocBMALFC_t.m_OCroiSets_t.m_VarOCroiPool_at[1].m_VarOCRect_at[0].top;
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].width_s32 = o_OCCameraCfg_pt.m_ocBMALFC_t.m_OCroiSets_t.m_VarOCroiPool_at[1].m_VarOCRect_at[0].width;
        i_CamConfig_p->featureColExternalConfig_t.bmalfcExtConfig_t.rois_at[1].height_s32 = o_OCCameraCfg_pt.m_ocBMALFC_t.m_OCroiSets_t.m_VarOCroiPool_at[1].m_VarOCRect_at[0].height;

    }
}

void DataProviderOC::setOCRuntime(uint32_t u_Runtime_u32)
{
  dataProvider_ro.getOcMData_po()->setOCRuntime(u_Runtime_u32);
}

void DataProviderOC::setOCThreadRuntime(uint32_t u_Runtime_u32)
{
  dataProvider_ro.getOcMData_po()->setOCThreadRuntime(u_Runtime_u32);
}

PerformanceStatsEnable_t DataProviderOC::get_PerformanceStatsEnable(void)
{
	return dataProvider_ro.getSigMData_po()->getPerformanceStatsEnable_t();
}

void DataProviderOC::getOCKMConfig_v (tscApi::tscPlatformExtConfigType * i_OCKMConfig_p )
{
  /* DD-ID: {A83B5D2A-FAC9-453f-9669-6354D34AA959}*/
    VarOCKinematics_t v_OCKMcfg;
    bool_t v_status = variantOc_GetOCKinematics_b(&v_OCKMcfg);
    if( true == v_status)
    {
        i_OCKMConfig_p->kinematicModelExternalConfig_t.tireCircumferencePerPulseMM_f32 = v_OCKMcfg.tireCircumferencePerPulse_f32;
        i_OCKMConfig_p->kinematicModelExternalConfig_t.distanceCoG2FrontAxisMM_f64 = v_OCKMcfg.distanceCoG2FrontAxis_f32;
        i_OCKMConfig_p->kinematicModelExternalConfig_t.distanceCoG2RearAxisMM_f64 = v_OCKMcfg.distanceCoG2RearAxis_f32;
    }
}

void DataProviderOC::setCameraparams(container::CameraId_e i_CamID_e, variants::CalibrationTypeE_t i_calibrationType_e)
{
  /* DD-ID: {4F488370-088A-4741-9E89-E9DA07B9A8CE}*/
#ifdef OC_SIMINP_DEBUG // Set to 1 for now until fix for getting live params works #ifdef OC_SIMINP_DEBUG // enable if want to hardcode camera params (set for PT38)
    switch (i_CamID_e)
    {
    case container::e_Front:
    {
        XilinxCamConfigOCFront cfg_front;
        cfg_front.loadCameraCfg();
        m_aFrontCameraInfo.camera_param.Init(IMAGE_WIDTH, IMAGE_HEIGHT, m_aFrontCameraInfo,Camera::MECL_Radial, &cfg_front.getCameraCfg());
        break;
    }

    case container::e_Left:
    {
        XilinxCamConfigOCLeft cfg_left;
        cfg_left.loadCameraCfg();
        m_aLeftCameraInfo.camera_param.Init(IMAGE_WIDTH, IMAGE_HEIGHT, m_aLeftCameraInfo,Camera::MECL_Radial, &cfg_left.getCameraCfg());
        break;
    }

    case container::e_Rear:
    {
        XilinxCamConfigOCRear cfg_rear;
        cfg_rear.loadCameraCfg();
        m_aRearCameraInfo.camera_param.Init(IMAGE_WIDTH, IMAGE_HEIGHT, m_aRearCameraInfo,Camera::MECL_Radial, &cfg_rear.getCameraCfg());
        break;
    }

    case container::e_Right:
    {
        XilinxCamConfigOCRight cfg_right;
        cfg_right.loadCameraCfg();
        m_aRightCameraInfo.camera_param.Init(IMAGE_WIDTH, IMAGE_HEIGHT, m_aRightCameraInfo,Camera::MECL_Radial, &cfg_right.getCameraCfg());
        break;
    }

    default:
    {
        XilinxCamConfigOCFront cfg_front;
        cfg_front.loadCameraCfg();
        m_aFrontCameraInfo.camera_param.Init(IMAGE_WIDTH, IMAGE_HEIGHT, m_aFrontCameraInfo,Camera::MECL_Radial, &cfg_front.getCameraCfg());
        break;
    }
    }

#else
    sensor::Pinhole_t::Config_s v_PinholeCfg_rs;
    sensor::LensRadial_t::Config_s v_LensRadialCfg_rs;
    sensor::Sensor_t::Config_s v_SensorCfg_rs;

    mecl::Pinhole_t::Config_s v_PinholeCfg_s;
    mecl::Sensor_t::Config_s   v_SensorCfg_s;
    mecl::LensRadial_t::Config_s v_LensCfg_s;

    switch (i_CamID_e)
    {
    case container::e_Front:
    {
        XilinxCamConfigOCFront cfgFront;

        sensor::CameraParams& meclCfg_o = dataProvider_ro.getCamMData_po()->getCamera_ro(variants::e_CameraFront).getCameraParams_ro();
        sensor::CameraBase& v_Cam_ro = dataProvider_ro.getCamMData_po()->getCamera_ro(variants::e_CameraFront);

        uint32_t  v_version_t = meclCfg_o.getRealCameraCfgVersion_t();
        if(v_version_t != cameraVersion_t[0])
        {
            meclCfg_o.getRealCameraCfg_b(v_PinholeCfg_rs, v_LensRadialCfg_rs, v_SensorCfg_rs);
            v_Cam_ro.getCameraParams_ro().getDesignCameraCfg_b(v_PinholeCfg_s, v_LensCfg_s, v_SensorCfg_s);
            cfgFront.loadCameraCfg();

            OC_DEBUG_PRINTF((" OC : Front Cam Params: \n"));
            OC_DEBUG_PRINTF(("Cam id: %d\n", i_CamID_e));

            OC_DEBUG_PRINTF(("For v_lensCfg_s: \n"));
            OC_DEBUG_PRINTF(("elevationMaxCfg: %f\n",v_LensRadialCfg_rs.elevationMaxCfg_x));
            OC_DEBUG_PRINTF(("image2world_x[0]: %f\n",v_LensRadialCfg_rs.image2world_x[0]));
            OC_DEBUG_PRINTF(("image2world_x[1]: %f\n",v_LensRadialCfg_rs.image2world_x[1]));
            OC_DEBUG_PRINTF(("image2world_x[2]: %f\n",v_LensRadialCfg_rs.image2world_x[2]));
            OC_DEBUG_PRINTF(("image2world_x[3]: %f\n",v_LensRadialCfg_rs.image2world_x[3]));
            OC_DEBUG_PRINTF(("image2world_x[4]: %f\n",v_LensRadialCfg_rs.image2world_x[4]));
            OC_DEBUG_PRINTF(("image2world_x[5]: %f\n",v_LensRadialCfg_rs.image2world_x[5]));
            OC_DEBUG_PRINTF(("world2image_x[0]: %f\n",v_LensRadialCfg_rs.world2image_x[0]));
            OC_DEBUG_PRINTF(("world2image_x[1]: %f\n",v_LensRadialCfg_rs.world2image_x[1]));
            OC_DEBUG_PRINTF(("world2image_x[2]: %f\n",v_LensRadialCfg_rs.world2image_x[2]));
            OC_DEBUG_PRINTF(("world2image_x[3]: %f\n",v_LensRadialCfg_rs.world2image_x[3]));
            OC_DEBUG_PRINTF(("world2image_x[4]: %f\n",v_LensRadialCfg_rs.world2image_x[4]));
            OC_DEBUG_PRINTF(("world2image_x[5]: %f\n",v_LensRadialCfg_rs.world2image_x[5]));

            OC_DEBUG_PRINTF(("For v_sensorCfg_s: \n"));
            OC_DEBUG_PRINTF(("pppCfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pppCfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pppCfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pppCfg_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("pszCfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pszCfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pszCfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pszCfg_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("pos1Cfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pos1Cfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pos1Cfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pos1Cfg_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("pos2Cfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pos2Cfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pos2Cfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pos2Cfg_x.cVal_ax[1]));

            OC_DEBUG_PRINTF(("For v_PinholeCfg_s: \n"));
            OC_DEBUG_PRINTF(("extrinsic_s.pos_x.cVal_ax[0]: %f\n",v_PinholeCfg_rs.extrinsic_s.pos_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("extrinsic_s.pos_x.cVal_ax[1]: %f\n",v_PinholeCfg_rs.extrinsic_s.pos_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("extrinsic_s.pos_x.cVal_ax[2]: %f\n",v_PinholeCfg_rs.extrinsic_s.pos_x.cVal_ax[2]));
            OC_DEBUG_PRINTF(("PitchDeg: %f\n",mecl::math::toDegrees_x(v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.pitch_x)));
            OC_DEBUG_PRINTF(("RollDeg: %f\n",mecl::math::toDegrees_x(v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x)));
            OC_DEBUG_PRINTF(("YawDeg: %f\n",mecl::math::toDegrees_x(v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x)));
            OC_DEBUG_PRINTF(("extrinsic_s.eulerAngles_s.pitch_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.pitch_x));
            OC_DEBUG_PRINTF(("extrinsic_s.eulerAngles_s.roll_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x));
            OC_DEBUG_PRINTF(("extrinsic_s.eulerAngles_s.yaw_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x));
            OC_DEBUG_PRINTF(("intrinsic_s.foclX_x: %f\n",v_PinholeCfg_rs.intrinsic_s.foclX_x));
            OC_DEBUG_PRINTF(("intrinsic_s.foclY_x: %f\n",v_PinholeCfg_rs.intrinsic_s.foclY_x));
            OC_DEBUG_PRINTF(("intrinsic_s.pppCfg_x.cVal_ax[0]: %f\n",v_PinholeCfg_rs.intrinsic_s.pppCfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("intrinsic_s.pppCfg_x.cVal_ax[1]: %f\n",v_PinholeCfg_rs.intrinsic_s.pppCfg_x.cVal_ax[1]));

            /* added these because camera init appies a negation which is already done in GDE */
            v_PinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x = -v_PinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x;
            v_PinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x = -v_PinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x;

            v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x = -v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x;
            v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x = -v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x;


            OC_DEBUG_PRINTF(("After negation extrinsic_s.eulerAngles_s.roll_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x));
            OC_DEBUG_PRINTF(("After negation extrinsic_s.eulerAngles_s.yaw_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x));

            cfgFront.setCameraCfg(&v_PinholeCfg_s, &v_PinholeCfg_rs, &v_LensRadialCfg_rs, &v_SensorCfg_rs, i_calibrationType_e);
            m_aFrontCameraInfo.camera_param.Init(IMAGE_WIDTH, IMAGE_HEIGHT, m_aFrontCameraInfo,Camera::MECL_Radial, &cfgFront.getCameraCfg());

            ME_Debugger_F_Printf_v("cfgFront %f %f %f\n", cfgFront.getCameraCfg().ang_alpha, cfgFront.getCameraCfg().ang_beta, cfgFront.getCameraCfg().ang_gamma);
            mecl::Camera_t *v_OcCamera_po = &m_aFrontCameraInfo.camera_param.m_realCam;
            mecl::Pinhole_t &v_PinHole_ro = dynamic_cast<mecl::Pinhole_t &>(v_OcCamera_po->getImager_rx());
            const mecl::model::Pinhole<float32_t>::Extrinsic_s* c_OcExtrinsics_ps;
            c_OcExtrinsics_ps = &v_PinHole_ro.getExtrinsic_rs();
            ME_Debugger_F_Printf_v("m_aFrontCameraInfo pitch %f yaw %f roll %f\n", c_OcExtrinsics_ps->eulerAngles_s.pitch_x, c_OcExtrinsics_ps->eulerAngles_s.yaw_x, c_OcExtrinsics_ps->eulerAngles_s.roll_x);

            cameraVersion_t[0] = v_version_t;
        }
        break;
    }
    case container::e_Left:
    {
        XilinxCamConfigOCLeft cfgLeft;

        sensor::CameraParams& meclCfg_o = dataProvider_ro.getCamMData_po()->getCamera_ro(variants::e_CameraLeft).getCameraParams_ro();
        sensor::CameraBase& v_Cam_ro = dataProvider_ro.getCamMData_po()->getCamera_ro(variants::e_CameraLeft);

        uint32_t  v_version_t = meclCfg_o.getRealCameraCfgVersion_t();
        if(v_version_t != cameraVersion_t[1])
        {
            meclCfg_o.getRealCameraCfg_b(v_PinholeCfg_rs, v_LensRadialCfg_rs, v_SensorCfg_rs);
            v_Cam_ro.getCameraParams_ro().getDesignCameraCfg_b(v_PinholeCfg_s, v_LensCfg_s, v_SensorCfg_s);
            cfgLeft.loadCameraCfg();

            OC_DEBUG_PRINTF((" OC : Left Cam Params: \n"));
            OC_DEBUG_PRINTF(("Cam id: %d\n", i_CamID_e));

            OC_DEBUG_PRINTF(("For v_lensCfg_s: \n"));
            OC_DEBUG_PRINTF(("elevationMaxCfg: %f\n",v_LensRadialCfg_rs.elevationMaxCfg_x));
            OC_DEBUG_PRINTF(("image2world_x[0]: %f\n",v_LensRadialCfg_rs.image2world_x[0]));
            OC_DEBUG_PRINTF(("image2world_x[1]: %f\n",v_LensRadialCfg_rs.image2world_x[1]));
            OC_DEBUG_PRINTF(("image2world_x[2]: %f\n",v_LensRadialCfg_rs.image2world_x[2]));
            OC_DEBUG_PRINTF(("image2world_x[3]: %f\n",v_LensRadialCfg_rs.image2world_x[3]));
            OC_DEBUG_PRINTF(("image2world_x[4]: %f\n",v_LensRadialCfg_rs.image2world_x[4]));
            OC_DEBUG_PRINTF(("image2world_x[5]: %f\n",v_LensRadialCfg_rs.image2world_x[5]));
            OC_DEBUG_PRINTF(("world2image_x[0]: %f\n",v_LensRadialCfg_rs.world2image_x[0]));
            OC_DEBUG_PRINTF(("world2image_x[1]: %f\n",v_LensRadialCfg_rs.world2image_x[1]));
            OC_DEBUG_PRINTF(("world2image_x[2]: %f\n",v_LensRadialCfg_rs.world2image_x[2]));
            OC_DEBUG_PRINTF(("world2image_x[3]: %f\n",v_LensRadialCfg_rs.world2image_x[3]));
            OC_DEBUG_PRINTF(("world2image_x[4]: %f\n",v_LensRadialCfg_rs.world2image_x[4]));
            OC_DEBUG_PRINTF(("world2image_x[5]: %f\n",v_LensRadialCfg_rs.world2image_x[5]));

            OC_DEBUG_PRINTF(("For v_sensorCfg_s: \n"));
            OC_DEBUG_PRINTF(("pppCfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pppCfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pppCfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pppCfg_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("pszCfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pszCfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pszCfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pszCfg_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("pos1Cfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pos1Cfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pos1Cfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pos1Cfg_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("pos2Cfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pos2Cfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pos2Cfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pos2Cfg_x.cVal_ax[1]));

            OC_DEBUG_PRINTF(("For v_PinholeCfg_s: \n"));
            OC_DEBUG_PRINTF(("extrinsic_s.pos_x.cVal_ax[0]: %f\n",v_PinholeCfg_rs.extrinsic_s.pos_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("extrinsic_s.pos_x.cVal_ax[1]: %f\n",v_PinholeCfg_rs.extrinsic_s.pos_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("extrinsic_s.pos_x.cVal_ax[2]: %f\n",v_PinholeCfg_rs.extrinsic_s.pos_x.cVal_ax[2]));
            OC_DEBUG_PRINTF(("PitchDeg: %f\n",mecl::math::toDegrees_x(v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.pitch_x)));
            OC_DEBUG_PRINTF(("RollDeg: %f\n",mecl::math::toDegrees_x(v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x)));
            OC_DEBUG_PRINTF(("YawDeg: %f\n",mecl::math::toDegrees_x(v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x)));
            OC_DEBUG_PRINTF(("extrinsic_s.eulerAngles_s.pitch_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.pitch_x));
            OC_DEBUG_PRINTF(("extrinsic_s.eulerAngles_s.roll_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x));
            OC_DEBUG_PRINTF(("extrinsic_s.eulerAngles_s.yaw_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x));
            OC_DEBUG_PRINTF(("intrinsic_s.foclX_x: %f\n",v_PinholeCfg_rs.intrinsic_s.foclX_x));
            OC_DEBUG_PRINTF(("intrinsic_s.foclY_x: %f\n",v_PinholeCfg_rs.intrinsic_s.foclY_x));
            OC_DEBUG_PRINTF(("intrinsic_s.pppCfg_x.cVal_ax[0]: %f\n",v_PinholeCfg_rs.intrinsic_s.pppCfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("intrinsic_s.pppCfg_x.cVal_ax[1]: %f\n",v_PinholeCfg_rs.intrinsic_s.pppCfg_x.cVal_ax[1]));

            /* added these because camera init appies a negation which is already done in GDE */
            v_PinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x = -v_PinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x;
            v_PinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x = -v_PinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x;

            v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x = -v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x;
            v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x = -v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x;

            OC_DEBUG_PRINTF(("After negation extrinsic_s.eulerAngles_s.roll_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x));
            OC_DEBUG_PRINTF(("After negation extrinsic_s.eulerAngles_s.yaw_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x));

            cfgLeft.setCameraCfg(&v_PinholeCfg_s, &v_PinholeCfg_rs, &v_LensRadialCfg_rs, &v_SensorCfg_rs, i_calibrationType_e);
            m_aLeftCameraInfo.camera_param.Init(IMAGE_WIDTH, IMAGE_HEIGHT, m_aLeftCameraInfo,Camera::MECL_Radial, &cfgLeft.getCameraCfg());

            ME_Debugger_F_Printf_v("cfgLeft %f %f %f\n", cfgLeft.getCameraCfg().ang_alpha, cfgLeft.getCameraCfg().ang_beta, cfgLeft.getCameraCfg().ang_gamma);
            mecl::Camera_t *v_OcCamera_po = &m_aLeftCameraInfo.camera_param.m_realCam;
            mecl::Pinhole_t &v_PinHole_ro = dynamic_cast<mecl::Pinhole_t &>(v_OcCamera_po->getImager_rx());
            const mecl::model::Pinhole<float32_t>::Extrinsic_s* c_OcExtrinsics_ps;
            c_OcExtrinsics_ps = &v_PinHole_ro.getExtrinsic_rs();
            ME_Debugger_F_Printf_v("m_aLeftCameraInfo pitch %f yaw %f roll %f\n", c_OcExtrinsics_ps->eulerAngles_s.pitch_x, c_OcExtrinsics_ps->eulerAngles_s.yaw_x, c_OcExtrinsics_ps->eulerAngles_s.roll_x);

            cameraVersion_t[1] = v_version_t;
        }
        break;
    }
    case container::e_Right:
    {
                XilinxCamConfigOCRight cfgRight;

        sensor::CameraParams& meclCfg_o = dataProvider_ro.getCamMData_po()->getCamera_ro(variants::e_CameraRight).getCameraParams_ro();
        sensor::CameraBase& v_Cam_ro = dataProvider_ro.getCamMData_po()->getCamera_ro(variants::e_CameraRight);

        uint32_t  v_version_t = meclCfg_o.getRealCameraCfgVersion_t();
        if(v_version_t != cameraVersion_t[3])
        {
            meclCfg_o.getRealCameraCfg_b(v_PinholeCfg_rs, v_LensRadialCfg_rs, v_SensorCfg_rs);
            v_Cam_ro.getCameraParams_ro().getDesignCameraCfg_b(v_PinholeCfg_s, v_LensCfg_s, v_SensorCfg_s);
            cfgRight.loadCameraCfg();

            OC_DEBUG_PRINTF((" OC : Right Cam Params: \n"));
            OC_DEBUG_PRINTF(("Cam id: %d\n", i_CamID_e));

            OC_DEBUG_PRINTF(("For v_lensCfg_s: \n"));
            OC_DEBUG_PRINTF(("elevationMaxCfg: %f\n",v_LensRadialCfg_rs.elevationMaxCfg_x));
            OC_DEBUG_PRINTF(("image2world_x[0]: %f\n",v_LensRadialCfg_rs.image2world_x[0]));
            OC_DEBUG_PRINTF(("image2world_x[1]: %f\n",v_LensRadialCfg_rs.image2world_x[1]));
            OC_DEBUG_PRINTF(("image2world_x[2]: %f\n",v_LensRadialCfg_rs.image2world_x[2]));
            OC_DEBUG_PRINTF(("image2world_x[3]: %f\n",v_LensRadialCfg_rs.image2world_x[3]));
            OC_DEBUG_PRINTF(("image2world_x[4]: %f\n",v_LensRadialCfg_rs.image2world_x[4]));
            OC_DEBUG_PRINTF(("image2world_x[5]: %f\n",v_LensRadialCfg_rs.image2world_x[5]));
            OC_DEBUG_PRINTF(("world2image_x[0]: %f\n",v_LensRadialCfg_rs.world2image_x[0]));
            OC_DEBUG_PRINTF(("world2image_x[1]: %f\n",v_LensRadialCfg_rs.world2image_x[1]));
            OC_DEBUG_PRINTF(("world2image_x[2]: %f\n",v_LensRadialCfg_rs.world2image_x[2]));
            OC_DEBUG_PRINTF(("world2image_x[3]: %f\n",v_LensRadialCfg_rs.world2image_x[3]));
            OC_DEBUG_PRINTF(("world2image_x[4]: %f\n",v_LensRadialCfg_rs.world2image_x[4]));
            OC_DEBUG_PRINTF(("world2image_x[5]: %f\n",v_LensRadialCfg_rs.world2image_x[5]));

            OC_DEBUG_PRINTF(("For v_sensorCfg_s: \n"));
            OC_DEBUG_PRINTF(("pppCfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pppCfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pppCfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pppCfg_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("pszCfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pszCfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pszCfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pszCfg_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("pos1Cfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pos1Cfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pos1Cfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pos1Cfg_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("pos2Cfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pos2Cfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pos2Cfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pos2Cfg_x.cVal_ax[1]));

            OC_DEBUG_PRINTF(("For v_PinholeCfg_s: \n"));
            OC_DEBUG_PRINTF(("extrinsic_s.pos_x.cVal_ax[0]: %f\n",v_PinholeCfg_rs.extrinsic_s.pos_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("extrinsic_s.pos_x.cVal_ax[1]: %f\n",v_PinholeCfg_rs.extrinsic_s.pos_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("extrinsic_s.pos_x.cVal_ax[2]: %f\n",v_PinholeCfg_rs.extrinsic_s.pos_x.cVal_ax[2]));
            OC_DEBUG_PRINTF(("PitchDeg: %f\n",mecl::math::toDegrees_x(v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.pitch_x)));
            OC_DEBUG_PRINTF(("RollDeg: %f\n",mecl::math::toDegrees_x(v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x)));
            OC_DEBUG_PRINTF(("YawDeg: %f\n",mecl::math::toDegrees_x(v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x)));
            OC_DEBUG_PRINTF(("extrinsic_s.eulerAngles_s.pitch_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.pitch_x));
            OC_DEBUG_PRINTF(("extrinsic_s.eulerAngles_s.roll_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x));
            OC_DEBUG_PRINTF(("extrinsic_s.eulerAngles_s.yaw_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x));
            OC_DEBUG_PRINTF(("intrinsic_s.foclX_x: %f\n",v_PinholeCfg_rs.intrinsic_s.foclX_x));
            OC_DEBUG_PRINTF(("intrinsic_s.foclY_x: %f\n",v_PinholeCfg_rs.intrinsic_s.foclY_x));
            OC_DEBUG_PRINTF(("intrinsic_s.pppCfg_x.cVal_ax[0]: %f\n",v_PinholeCfg_rs.intrinsic_s.pppCfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("intrinsic_s.pppCfg_x.cVal_ax[1]: %f\n",v_PinholeCfg_rs.intrinsic_s.pppCfg_x.cVal_ax[1]));

            /* added these because camera init appies a negation which is already done in GDE */
            v_PinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x = -v_PinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x;
            v_PinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x = -v_PinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x;

            v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x = -v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x;
            v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x = -v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x;

            OC_DEBUG_PRINTF(("After negation extrinsic_s.eulerAngles_s.roll_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x));
            OC_DEBUG_PRINTF(("After negation extrinsic_s.eulerAngles_s.yaw_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x));

            cfgRight.setCameraCfg(&v_PinholeCfg_s, &v_PinholeCfg_rs, &v_LensRadialCfg_rs, &v_SensorCfg_rs, i_calibrationType_e);
            m_aRightCameraInfo.camera_param.Init(IMAGE_WIDTH, IMAGE_HEIGHT, m_aRightCameraInfo,Camera::MECL_Radial, &cfgRight.getCameraCfg());

            ME_Debugger_F_Printf_v("cfgRight %f %f %f\n", cfgRight.getCameraCfg().ang_alpha, cfgRight.getCameraCfg().ang_beta, cfgRight.getCameraCfg().ang_gamma);
            mecl::Camera_t *v_OcCamera_po = &m_aRightCameraInfo.camera_param.m_realCam;
            mecl::Pinhole_t &v_PinHole_ro = dynamic_cast<mecl::Pinhole_t &>(v_OcCamera_po->getImager_rx());
            const mecl::model::Pinhole<float32_t>::Extrinsic_s* c_OcExtrinsics_ps;
            c_OcExtrinsics_ps = &v_PinHole_ro.getExtrinsic_rs();
            ME_Debugger_F_Printf_v("m_aRearCameraInfo pitch %f yaw %f roll %f\n", c_OcExtrinsics_ps->eulerAngles_s.pitch_x, c_OcExtrinsics_ps->eulerAngles_s.yaw_x, c_OcExtrinsics_ps->eulerAngles_s.roll_x);

            cameraVersion_t[3] = v_version_t;
        }
        break;
    }
    case container::e_Rear:
    {
                XilinxCamConfigOCRear cfgRear;

        sensor::CameraParams& meclCfg_o = dataProvider_ro.getCamMData_po()->getCamera_ro(variants::e_CameraRear).getCameraParams_ro();
        sensor::CameraBase& v_Cam_ro = dataProvider_ro.getCamMData_po()->getCamera_ro(variants::e_CameraRear);

        uint32_t  v_version_t = meclCfg_o.getRealCameraCfgVersion_t();
        if(v_version_t != cameraVersion_t[2])
        {
            meclCfg_o.getRealCameraCfg_b(v_PinholeCfg_rs, v_LensRadialCfg_rs, v_SensorCfg_rs);
            v_Cam_ro.getCameraParams_ro().getDesignCameraCfg_b(v_PinholeCfg_s, v_LensCfg_s, v_SensorCfg_s);
            cfgRear.loadCameraCfg();

            OC_DEBUG_PRINTF((" OC : Rear Cam Params: \n"));
            OC_DEBUG_PRINTF(("Cam id: %d\n", i_CamID_e));

            OC_DEBUG_PRINTF(("For v_lensCfg_s: \n"));
            OC_DEBUG_PRINTF(("elevationMaxCfg: %f\n",v_LensRadialCfg_rs.elevationMaxCfg_x));
            OC_DEBUG_PRINTF(("image2world_x[0]: %f\n",v_LensRadialCfg_rs.image2world_x[0]));
            OC_DEBUG_PRINTF(("image2world_x[1]: %f\n",v_LensRadialCfg_rs.image2world_x[1]));
            OC_DEBUG_PRINTF(("image2world_x[2]: %f\n",v_LensRadialCfg_rs.image2world_x[2]));
            OC_DEBUG_PRINTF(("image2world_x[3]: %f\n",v_LensRadialCfg_rs.image2world_x[3]));
            OC_DEBUG_PRINTF(("image2world_x[4]: %f\n",v_LensRadialCfg_rs.image2world_x[4]));
            OC_DEBUG_PRINTF(("image2world_x[5]: %f\n",v_LensRadialCfg_rs.image2world_x[5]));
            OC_DEBUG_PRINTF(("world2image_x[0]: %f\n",v_LensRadialCfg_rs.world2image_x[0]));
            OC_DEBUG_PRINTF(("world2image_x[1]: %f\n",v_LensRadialCfg_rs.world2image_x[1]));
            OC_DEBUG_PRINTF(("world2image_x[2]: %f\n",v_LensRadialCfg_rs.world2image_x[2]));
            OC_DEBUG_PRINTF(("world2image_x[3]: %f\n",v_LensRadialCfg_rs.world2image_x[3]));
            OC_DEBUG_PRINTF(("world2image_x[4]: %f\n",v_LensRadialCfg_rs.world2image_x[4]));
            OC_DEBUG_PRINTF(("world2image_x[5]: %f\n",v_LensRadialCfg_rs.world2image_x[5]));

            OC_DEBUG_PRINTF(("For v_sensorCfg_s: \n"));
            OC_DEBUG_PRINTF(("pppCfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pppCfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pppCfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pppCfg_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("pszCfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pszCfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pszCfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pszCfg_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("pos1Cfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pos1Cfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pos1Cfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pos1Cfg_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("pos2Cfg_x.cVal_ax[0]: %f\n",v_SensorCfg_rs.pos2Cfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("pos2Cfg_x.cVal_ax[1]: %f\n",v_SensorCfg_rs.pos2Cfg_x.cVal_ax[1]));

            OC_DEBUG_PRINTF(("For v_PinholeCfg_s: \n"));
            OC_DEBUG_PRINTF(("extrinsic_s.pos_x.cVal_ax[0]: %f\n",v_PinholeCfg_rs.extrinsic_s.pos_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("extrinsic_s.pos_x.cVal_ax[1]: %f\n",v_PinholeCfg_rs.extrinsic_s.pos_x.cVal_ax[1]));
            OC_DEBUG_PRINTF(("extrinsic_s.pos_x.cVal_ax[2]: %f\n",v_PinholeCfg_rs.extrinsic_s.pos_x.cVal_ax[2]));
            OC_DEBUG_PRINTF(("PitchDeg: %f\n",mecl::math::toDegrees_x(v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.pitch_x)));
            OC_DEBUG_PRINTF(("RollDeg: %f\n",mecl::math::toDegrees_x(v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x)));
            OC_DEBUG_PRINTF(("YawDeg: %f\n",mecl::math::toDegrees_x(v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x)));
            OC_DEBUG_PRINTF(("extrinsic_s.eulerAngles_s.pitch_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.pitch_x));
            OC_DEBUG_PRINTF(("extrinsic_s.eulerAngles_s.roll_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x));
            OC_DEBUG_PRINTF(("extrinsic_s.eulerAngles_s.yaw_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x));
            OC_DEBUG_PRINTF(("intrinsic_s.foclX_x: %f\n",v_PinholeCfg_rs.intrinsic_s.foclX_x));
            OC_DEBUG_PRINTF(("intrinsic_s.foclY_x: %f\n",v_PinholeCfg_rs.intrinsic_s.foclY_x));
            OC_DEBUG_PRINTF(("intrinsic_s.pppCfg_x.cVal_ax[0]: %f\n",v_PinholeCfg_rs.intrinsic_s.pppCfg_x.cVal_ax[0]));
            OC_DEBUG_PRINTF(("intrinsic_s.pppCfg_x.cVal_ax[1]: %f\n",v_PinholeCfg_rs.intrinsic_s.pppCfg_x.cVal_ax[1]));

            /* added these because camera init appies a negation which is already done in GDE */
            v_PinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x = -v_PinholeCfg_s.extrinsic_s.eulerAngles_s.yaw_x;
            v_PinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x = -v_PinholeCfg_s.extrinsic_s.eulerAngles_s.roll_x;

            v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x = -v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x;
            v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x = -v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x;

            OC_DEBUG_PRINTF(("After negation extrinsic_s.eulerAngles_s.roll_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.roll_x));
            OC_DEBUG_PRINTF(("After negation extrinsic_s.eulerAngles_s.yaw_x: %f\n",v_PinholeCfg_rs.extrinsic_s.eulerAngles_s.yaw_x));

            cfgRear.setCameraCfg(&v_PinholeCfg_s, &v_PinholeCfg_rs, &v_LensRadialCfg_rs, &v_SensorCfg_rs, i_calibrationType_e);
            m_aRearCameraInfo.camera_param.Init(IMAGE_WIDTH, IMAGE_HEIGHT, m_aRearCameraInfo,Camera::MECL_Radial, &cfgRear.getCameraCfg());

            ME_Debugger_F_Printf_v("cfgRear %f %f %f\n", cfgRear.getCameraCfg().ang_alpha, cfgRear.getCameraCfg().ang_beta, cfgRear.getCameraCfg().ang_gamma);
            mecl::Camera_t *v_OcCamera_po = &m_aRearCameraInfo.camera_param.m_realCam;
            mecl::Pinhole_t &v_PinHole_ro = dynamic_cast<mecl::Pinhole_t &>(v_OcCamera_po->getImager_rx());
            const mecl::model::Pinhole<float32_t>::Extrinsic_s* c_OcExtrinsics_ps;
            c_OcExtrinsics_ps = &v_PinHole_ro.getExtrinsic_rs();
            ME_Debugger_F_Printf_v("m_aRearCameraInfo pitch %f yaw %f roll %f\n", c_OcExtrinsics_ps->eulerAngles_s.pitch_x, c_OcExtrinsics_ps->eulerAngles_s.yaw_x, c_OcExtrinsics_ps->eulerAngles_s.roll_x);
        
            cameraVersion_t[2] = v_version_t;
        }
        break;
    }
    default:
      break;
    }
#endif

}

#ifndef _WINDOWS
void DataProviderOC::setOCResponse_v( const ME_Hydra3defs_E_AlgoCommand_t i_RequestCmd_t, tscApi::CalibrationParams_s* o_Output_ro, container::OcData_s *o_OCStatus_p)
{
  /* DD-ID: {EE4A8CF5-E947-4929-9E67-05B6568CD3D0}*/
    static variants::OCAlgoStateE_t  prev_algoState_t = variants::e_OCAlgoStateEInvalid;
    static uint32_t v_CurrentframeNum_u32 = 0;
    static uint32_t v_PrevframeNum_u32 = 0;
#if 1
    /* Below line is printing Cont */
    OcData_s.deltaPitch_f32 = o_OCStatus_p->deltaPitch_f32;
    OcData_s.deltaYaw_f32 = o_OCStatus_p->deltaYaw_f32;
    OcData_s.deltaRoll_f32 = o_OCStatus_p->deltaRoll_f32;
    OcData_s.ValidFeatures_u32 = o_OCStatus_p->validFeaturesCount_u32;
    OcData_s.IgnoredFeatures_u32 = o_OCStatus_p->ignoredFeaturesCount_u32;
    OcData_s.InvalidFeatures_u32 = o_OCStatus_p->invalidFeaturesCount_u32;
    OcData_s.algoState_e = static_cast<ME_Hydra3defs_E_OCAlgoState_t>(o_OCStatus_p->ocAlgoState_e);
    OcData_s.errorCode_e = static_cast<ME_Hydra3defs_E_OCErrorCode_t>(o_OCStatus_p->ocErrorCode_e); 
    OcData_s.camID_e = static_cast<ME_Hydra3defs_E_CameraID_t>(o_OCStatus_p->mcuCameraId_u8);
#endif
    OcData_s.algoState_e = static_cast<ME_Hydra3defs_E_OCAlgoState_t>(o_OCStatus_p->ocAlgoState_e);
    OcData_s.errorCode_e = static_cast<ME_Hydra3defs_E_OCErrorCode_t>(o_OCStatus_p->ocErrorCode_e);
    OcData_s.camID_e = static_cast<ME_Hydra3defs_E_CameraID_t>(o_OCStatus_p->mcuCameraId_u8);
    v_CurrentframeNum_u32 = getFrameNum_u32();
#if 0
    switch (OcData_s.camID_e) //Populate Current CAM ID
      {
        case CamID_Front:

        	/*  v_CurrentframeNum_u32 = 1381 v_PrevframeNum_u32 = 0*/
        	if (1390u < (v_CurrentframeNum_u32 - v_PrevframeNum_u32))
        	{
        	  OcData_s.deltaPitch_f32 = 1.91f;
        	  OcData_s.deltaYaw_f32 = 1.82;
        	  OcData_s.deltaRoll_f32 = -0.97;
        	  OcData_s.ValidFeatures_u32 = 206;
        	  OcData_s.IgnoredFeatures_u32 = 42;
        	  OcData_s.InvalidFeatures_u32 = 28;
        	  OcData_s.algoState_e = e_OC_CalibrationCompleted;
        	  OcData_s.errorCode_e = e_OC_NoError;

        	  v_PrevframeNum_u32 = v_CurrentframeNum_u32;
        	}
        	break;

        case CamID_Left:
            if (1400u < (v_CurrentframeNum_u32 - v_PrevframeNum_u32) )
            {
                OcData_s.deltaPitch_f32 = 1.34f;
                OcData_s.deltaYaw_f32 = 0.72f;
                OcData_s.deltaRoll_f32 = 0.82f;
                OcData_s.ValidFeatures_u32 = 200;
                OcData_s.IgnoredFeatures_u32 = 53;
                OcData_s.InvalidFeatures_u32 = 31;
                OcData_s.algoState_e = e_OC_CalibrationCompleted;
                OcData_s.errorCode_e = e_OC_NoError;

                v_PrevframeNum_u32 = v_CurrentframeNum_u32;
            }
         break;

        case CamID_Rear:
        	if(1400u < (v_CurrentframeNum_u32 - v_PrevframeNum_u32))
            {
                OcData_s.deltaPitch_f32 = 1.22f;
                OcData_s.deltaYaw_f32 = 0.32f;
                OcData_s.deltaRoll_f32 = -0.23f;
                OcData_s.ValidFeatures_u32 = 209;
                OcData_s.IgnoredFeatures_u32 = 49;
                OcData_s.InvalidFeatures_u32 = 38;
                OcData_s.algoState_e = e_OC_CalibrationCompleted;
                OcData_s.errorCode_e = e_OC_NoError;

                v_PrevframeNum_u32 = v_CurrentframeNum_u32;
            }
         break;

        case CamID_Right:
            if (1400u < (v_CurrentframeNum_u32 - v_PrevframeNum_u32) )
            {
                OcData_s.deltaPitch_f32 = 1.95f;
                OcData_s.deltaYaw_f32 = -0.89f;
                OcData_s.deltaRoll_f32 = -0.12;
                OcData_s.ValidFeatures_u32 = 200;
                OcData_s.IgnoredFeatures_u32 = 88;
                OcData_s.InvalidFeatures_u32 = 12;
                OcData_s.algoState_e = e_OC_CalibrationCompleted;
                OcData_s.errorCode_e = e_OC_NoError;

                v_PrevframeNum_u32 = v_CurrentframeNum_u32;
            }
         break;

        default:
         break;
      }
#endif

#if OC_LOG_PRINTF_ON
    if((OcData_s.algoState_e != prev_algoState_t))
    {
      prev_algoState_t = (variants::OCAlgoStateE_t)OcData_s.algoState_e;
        
      OC_DEBUG_PRINTF(("OcDataOut_s.camID_e = %d\n",(int)OcData_s.camID_e));
      OC_DEBUG_PRINTF(("OcDataOut_s.errorCode_e = %d\n",(int)OcData_s.errorCode_e));
      OC_DEBUG_PRINTF(("OcDataOut_s.InvalidFeatures_u32 = %d\n",(int)OcData_s.InvalidFeatures_u32));
      OC_DEBUG_PRINTF(("OcDataOut_s.algoState_e = %d\n",(int)OcData_s.algoState_e));
      OC_DEBUG_PRINTF(("OcDataOut_s.deltaPitch_f32 = %f\n",OcData_s.deltaPitch_f32));
      OC_DEBUG_PRINTF(("OcDataOut_s.deltaYaw_f32 = %f\n",OcData_s.deltaYaw_f32));
      OC_DEBUG_PRINTF(("OcDataOut_s.deltaRoll_f32 = %f\n",OcData_s.deltaRoll_f32));
      OC_DEBUG_PRINTF(("OcDataOut_s.ValidFeatures_u32 = %d\n",OcData_s.ValidFeatures_u32));
      OC_DEBUG_PRINTF(("OcDataOut_s.IgnoredFeatures_u32 = %d\n",OcData_s.IgnoredFeatures_u32));
    }
#endif
    dataProvider_ro.getCalSmMData_po()->setSVSCalibAlgoToSMCamCalib_OCStatus(OcData_s);
    dataProvider_ro.getCalSmMData_po()->setSVSCalibAlgoToSMCamCalib_OCStatus_AlgoType(CalsmAlgoType);
}
#endif

}
