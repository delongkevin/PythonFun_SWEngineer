//--------------------------------------------------------------------------
/// @file DataProviderTHA.cpp
/// @brief Contains implementation of THA Dataprovider interface
///
/// DataProvider is an interface between THA module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
//  --------------------------------------------------------------------------

#include "DataProviderTHA.h"
#include "../../THA/algo/inc/MatrixUtils.h"
#include "variants/VariantHelper.h"

// Dipti : Global structure for using Calib data
THA_Calibration_data_MPU1_0_t thaDetCalibData;

extern "C"
{
    extern void view_manager_raw_2_world_3D_rear_for_tha( float32_t raw_x, float32_t raw_y, int32_t refWorld_z, float32_t result_xyz[3]);
    extern int32_t view_manager_world_2_raw_v_rear_tha(const float32_t world_xyz[3], float32_t raw_coords[2]);
}

namespace tha
{

DataProviderTHA::DataProviderTHA(container::IDataProvider &b_DataProvider_ro):
    IDataProviderTHA(), dataProvider_ro(b_DataProvider_ro),
    tiovxConsumer()
{

}

DataProviderTHA::~DataProviderTHA()
{

}

// Get RGB image for original input image
#define algo_view_width ((uint32_t)1920)   //Algo view width as received
#define algo_view_height ((uint32_t)1280)  //Algo view height as received
#define algo_view_size ((uint32_t)2457600) // RGB = 1920*1280
//static uint8_t rawCam_image[algo_view_width*algo_view_height*3];// RGB = (1920w x 1280h )*3
//static uint8_t algoView_image[algo_view_width*algo_view_height*3];// RGB = (1920w x 1280h )*3
static uint8_t rawCam_image[640*640*3];// RGB = (640w x 640h )*3
static uint8_t algoView_image[640*640*3];// RGB = (640w x 640h )*3

// Get Grey image for tracker
#define grey_image_width ((uint32_t)640)
#define grey_image_height ((uint32_t)400)
#define grey_image_size ((uint32_t)256000)// Y = (640w * 400h)
static uint8_t yimage[grey_image_size];

static ME_VehInp_to_IpcSignals_t ipc_VcanData = {};

// Get m_THADetEnable value
bool_t DataProviderTHA::getTHADetEnableFlag()
{
    return m_THADetEnable;
}

/* Get function for THA detection output*/
const JobTHAInput_t DataProviderTHA::getTHAInput()
{
  // Get HMI signals
  getSVSHMIdata();

  // Get THA SM VC output
  getTHAsmVCdata();

  // Get Vehicle CAN signals
  getVCANdata();

  // Get Kinematic data
  getKMdata();

  //Condition to check if Rear Algo view fetch
   if((m_THAInput.SMInput_s.THASmState_e == THAState_e::e_EnabledSelection) || 
   (m_THAInput.SMInput_s.THASmState_e == THAState_e::e_Engaged) ||
   (m_THAInput.SMInput_s.THASmState_e == THAState_e::e_EngagedDelta))
   {

    if( ( m_THAInput.SMInput_s.UsrCplrSelected_b == false ) &&
    ( m_THADetOutput.HitchDetctStatus_e != e_Hitch_Not_Valid ) )
    {
        m_THADetEnable = false;
        dataProvider_ro.getTHAData_po()->set_THA_SM_status(m_THADetEnable);
        return m_THAInput;
    }
    #if PROFILE_THA
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = 0;
    uint64_t v_time1_u64 = 0;
    uint64_t v_EndTime_u64 = 0;
    static uint64_t v_TotalTime_u64 = 0;
    static uint64_t v_algoRGBTime_u64 = 0;
    v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
    #endif
    // Get Rear fisheye RGB input image data for DNN models
    c_getInputcolorImage_pu8();
    #if PROFILE_THA
    v_time1_u64 = v_Time_o.getTimeMsec_u64();
    v_algoRGBTime_u64 = v_time1_u64 - v_StartTime_u64;
    ME_Debugger_F_Printf_v("\nRGBView: %f ms ", (float32_t)(v_algoRGBTime_u64 * 1.0f));
    #endif//PROFILE_THA
    // Get gray scale image needed for Tracker
    get_grayFisheye_Image();
    #if PROFILE_THA
    v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    v_TotalTime_u64 = v_EndTime_u64 - v_time1_u64;
    ME_Debugger_F_Printf_v("\nGrayView: %f ms ", (float32_t)(v_TotalTime_u64 * 1.0f));
    #endif//PROFILE_THA
    m_THADetEnable = true;
   }
   else
   {
    m_THADetEnable = false;
   }
   dataProvider_ro.getTHAData_po()->set_THA_SM_status(m_THADetEnable);
  return m_THAInput;
}

void DataProviderTHA::c_getInputcolorImage_pu8()
{
#if WINDOWS_IMG
    cv::Mat m_pInputTVGImg = cv::Mat(cv::Size(640, 640), CV_8UC1, (unsigned char *)m_THAInput.InputImgColor_pu8, cv::Mat::AUTO_STEP);
#endif
    m_THAInput.InputImgColor_pu8 = (uint8_t *)algoView_image;
    uint8_t* rawCameraImg_pu8  = (uint8_t *)rawCam_image;
    /*Added by Afshan S to get rear view fisheye image buffer */
    static container::OVL3DData *v_ovl3d_po = getOVL3DData_po();
    static bsp::TIOVXHost &v_tiovx_ro = getTIOVX_ro();

    static uint32_t v_width_u32;
    static uint32_t v_height_u32;

    static algo_view_t *v_algoView_pv;
    static Condvar_s v_condvar_s;
    static bsp::VideoInputBufferDesc2_t v_bufferDesc_t;
    static texture_data_t *v_textures_apo[3];

    static uint8 m_InitOnce = 1;

    if (m_InitOnce)
    {
        // create AlgoView descriptor
        if ((v_algoView_pv = v_ovl3d_po->algoViewCreate_po((char*)"algo-fisheye-rgb", ALGO_VIEW_RGB_PLANAR_RAW, v_width_u32, v_height_u32)) == NULL)
        {
            ME_Debugger_F_Printf_v("failed to create algo-view\n");
        }
        else if (v_tiovx_ro.allocVideoBuffer_b(v_width_u32, v_height_u32, SCREEN_FORMAT_BYTE, 3, v_bufferDesc_t) == false)
        {
            ME_Debugger_F_Printf_v("failed to allocate buffer\n");
        }
        else if (v_ovl3d_po->algoViewBuffersPrepare_b(v_bufferDesc_t, v_textures_apo) == false)
        {
            ME_Debugger_F_Printf_v("failed to prepare buffers\n");
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

            uint32_t t0 = __get_time_usec();

            if (v_ovl3d_po->algoViewJobSubmit_b(&v_job_t) == true)
            {
                // wait for job completion (explicitly)
                ME_Condvar_Wait_t(&v_condvar_s);
            }

            uint32_t t1 = __get_time_usec();
            ME_Mutex_UnLock_t(&v_condvar_s.MEMutex_po);

            uint8_t* v_data_pu32[3] = {
            static_cast<uint8_t*>(v_bufferDesc_t.buffers_apv[0]),
            static_cast<uint8_t*>(v_bufferDesc_t.buffers_apv[1]),
            static_cast<uint8_t*>(v_bufferDesc_t.buffers_apv[2]),
                                       };
            //Reading input image from SD card for offline testing
            #if ENABLE_OFFLINE_TEST_THA
            vx_char input_file_name[256];
            static uint32_t number = 0;
            #if !UNIT_TESTING
            static char rgb_path[256];
            static uint8_t rgb_once = 0;
            if(rgb_once == 0)
            {
                //read config
                FILE *fp = fopen("/ti_sd/unit_testing_cfg.txt", "r");
                char line_str[1024];
                char *token;
                if(fp==NULL)
                {
                    ME_Debugger_F_Printf_v("app_tidl: ERROR: Unable to open config file \n");
                }

                while(fgets(line_str, sizeof(line_str), fp)!=NULL)
                {
                    char s[]=" \t";

                    /* get the first token */
                    token = strtok(line_str, s);

                    if(token != NULL)
                    {
                        if(strcmp(token, "rgb_path")==0)
                        {
                            token = strtok(NULL, s);
                            if(token != NULL)
                                {
                                    token[strlen(token)-1]=0;
                                    strcpy(rgb_path, token);
                                }
                        }
                    }
                }
                rgb_once = 1;
            }
            sprintf(input_file_name,"%s_%dRGB.bin",rgb_path,number++);
            #endif
            //Dipti : If hardcode image needs to be given use below paths:
            //sprintf(input_file_name,"/ti_sd/THA_RGB/resized_algo_fisheye_rear_%dRGB.bin",number++);
            //sprintf(input_file_name,"/ti_fs/vision_apps/cdhd_rgbp_v1.bin");
            FILE * f1 = fopen(input_file_name, "rb");
            if(f1 == NULL)
            {
                ME_Debugger_F_Printf_v("Could not open file\n");
            }
            int ret_status = fseek(f1, 0, SEEK_SET);
            size_t bytesRead = fread(v_data_pu32[0],1,1920*1280, f1);
            bytesRead = fread(v_data_pu32[1],1,1920*1280, f1);
            bytesRead = fread(v_data_pu32[2],1,1920*1280, f1);
            fclose(f1);
            #endif

            //TBD : Changes for flip and crop combine
            int16_t v_rectStartX = 0;
            int16_t v_rectStartY = 0;

            uint16_t v_cropImageW = m_THAStateConfig.getDetDNNInputDimW(); // Dipti : This should be set according to the model used
            uint16_t v_cropImageH = m_THAStateConfig.getDetDNNInputDimH(); // Dipti : This should be set according to the model used
            Point2i v_cropCentrePoint = Point2i(0,0);
            Point2i v_cropPoint = Point2i(0,0);
            // ROI for Coupler
            if( m_THAInput.SMInput_s.UsrCplrSelected_b == true )
            {
                v_cropCentrePoint.x = m_THAInput.HMIInput_s.CplrPixX_u16;
                v_cropCentrePoint.y = m_THAInput.HMIInput_s.CplrPixY_u16;
                v_rectStartX = v_cropCentrePoint.x - ( v_cropImageW / 2 );
                v_rectStartY = v_cropCentrePoint.y - ( v_cropImageH / 2 );

                if( m_THADetOutput.CplrDetctStatus_e == CplrDetStatus_e::e_Cplr_Detected )
                {
                    uint16_t Pnt_x = (uint16_t)m_THADetOutput.CplrPix_p2d.x;
                    uint16_t Pnt_y = (uint16_t)m_THADetOutput.CplrPix_p2d.y;
                    TransformFlipPntInp( v_cropCentrePoint, Pnt_x, Pnt_y);
                    v_rectStartX = v_cropCentrePoint.x - ( v_cropImageW / 2 );
                    v_rectStartY = v_cropCentrePoint.y - ( v_cropImageH / 2 );
                }
                else if( m_JobTHADetDebugOutput.TrlrDetctStatus_e == TrlrDetStatus_e::e_Trlr_Detected )
                {
                    uint16_t Pnt_x = (uint16_t)m_JobTHADetDebugOutput.TrlrPnt_p2d.x;
                    uint16_t Pnt_y = (uint16_t)m_JobTHADetDebugOutput.TrlrPnt_p2d.y;
                    TransformFlipPntInp( v_cropCentrePoint, Pnt_x, Pnt_y);
                    v_rectStartX = v_cropCentrePoint.x - ( v_cropImageW / 2 );
                    v_rectStartY = v_cropCentrePoint.y - ( v_cropImageH / 2 );
                }
            }
            // ROI for Hitch
            else
            {
                v_rectStartX = ( algo_view_width / 2 ) - ( v_cropImageW / 2 );
                v_rectStartY = 0;
            }
            
            if( v_rectStartX < 0 )
            {
                v_rectStartX = 0;
            }

            if( v_rectStartY < 0 )
            {
                v_rectStartY = 0;
            }

            if( v_rectStartX + v_cropImageW > (uint16_t)algo_view_width )
            {
                v_rectStartX = algo_view_width - v_cropImageW;
            }

            if( v_rectStartY + v_cropImageH > (uint16_t)algo_view_height )
            {
                v_rectStartY = algo_view_height - v_cropImageH;
            }
            //Sasha's function with crop and vertical flip combined
            #if PROFILE_THA
            osal::Time v_Time_o;
            uint64_t v_StartTime_u64 = 0;
            uint64_t v_EndTime_u64 = 0;
            static uint64_t v_TotalTime_u64 = 0;
            v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
            #endif
            uint32_t v_row_u32;
            uint32_t i_cropWidth_u16  =  640;
            uint32_t i_cropHeight_u16 =  640;
            uint32_t v_crop_index_u32; // iterator variables
            uint32_t v_cropOffset_u32 = ( i_cropWidth_u16 * i_cropHeight_u16 );
            uint32_t v_imgOffset_u32  = ( algo_view_width * algo_view_height );
            #if 1
            uint8_t* dst_Rptr = rawCameraImg_pu8 + (v_cropOffset_u32 * 0) + (i_cropWidth_u16 * (i_cropHeight_u16 - 1));
            uint8_t* rawR_pu8 = v_data_pu32[0] + ((v_rectStartY * algo_view_width) + v_rectStartX); //R plane
            for( v_row_u32 = 0; v_row_u32 < i_cropHeight_u16; v_row_u32++ )//640
            {   
                memcpy(dst_Rptr, rawR_pu8, i_cropWidth_u16);
                dst_Rptr -= i_cropWidth_u16;
                rawR_pu8 += algo_view_width;
            }
            #endif

            #if 1
            uint8_t* dst_Gptr = rawCameraImg_pu8 + (v_cropOffset_u32 * 1) + (i_cropWidth_u16 * (i_cropHeight_u16 - 1));
            uint8_t* rawG_pu8 = v_data_pu32[1] + ((v_rectStartY * algo_view_width) + v_rectStartX); //G plane
            for( v_row_u32 = 0; v_row_u32 < i_cropHeight_u16; v_row_u32++ )//640
            {
                memcpy(dst_Gptr, rawG_pu8, i_cropWidth_u16);
                dst_Gptr -= i_cropWidth_u16;
                rawG_pu8 += algo_view_width;
            }
            #endif

            #if 1            
            uint8_t* dst_Bptr = rawCameraImg_pu8 + (v_cropOffset_u32 * 2) + (i_cropWidth_u16 * (i_cropHeight_u16 - 1));
            uint8_t* rawB_pu8 = v_data_pu32[2] + ((v_rectStartY * algo_view_width) + v_rectStartX); //B plane
            for( v_row_u32 = 0; v_row_u32 < i_cropHeight_u16; v_row_u32++ )//640
            {
                memcpy(dst_Bptr, rawB_pu8, i_cropWidth_u16);
                dst_Bptr -= i_cropWidth_u16;
                rawB_pu8 += algo_view_width;
            }
            #endif
            #if PROFILE_THA
            v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
            v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
            ME_Debugger_F_Printf_v("\nvFlipCrop: %f ms ", (float32_t)(v_TotalTime_u64 * 1.0f));
            #endif//PROFILE_THA

            #if ENABLE_VIEW_WORKAROUND
            #if PROFILE_THA
            //osal::Time v_Time_o;
            //uint64_t v_StartTime_u64 = 0;
            //uint64_t v_EndTime_u64 = 0;
            //static uint64_t v_TotalTime_u64 = 0;
            v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
            #endif
            //Dipti : Funtion for Algo view RGB horizontal flip
            matrixUtil::vid_copyRearMirrorImageInPlace(rawCameraImg_pu8);
            m_THAInput.InputImgColor_pu8 = rawCameraImg_pu8;
            #if PROFILE_THA
            v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
            v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
            ME_Debugger_F_Printf_v("\nRGBFlip: %f ms ", (float32_t)(v_TotalTime_u64 * 1.0f));
            #endif//PROFILE_THA
            #endif
            
            #if DUMP_THA_ALGO_VIEW
            //Dipti : Logic to dump algo view images in SD card
            char FileName[64];
            static uint32_t u32FrmaeNum = 0;
            if(u32FrmaeNum <= 10)
            {
                sprintf(FileName, "/ti_sd/THAAlgoViewRGB_%d.bin", u32FrmaeNum++);
                FILE * fp = fopen(FileName, "wb");
                fwrite(m_THAInput.InputImgColor_pu8,640*640*3,1,fp);
                fclose(fp);
            }
            #endif
            uint32_t t2 = __get_time_usec();
            v_THAFrameNum_u32 = v_frameNum_u32;
            #if ENABLE_DEBUG_THA
            ME_Debugger_F_Printf_v("#### RGB:THA frame-%u: job processed: %u\n", v_frameNum_u32, t1 - t0);
            #endif
        }
    }

}

void DataProviderTHA::get_grayFisheye_Image()
{
#if WINDOWS_IMG
    cv::Mat m_pInputRGBImg = cv::Mat(cv::Size(640, 400), CV_8UC1, (unsigned char *)m_THAInput.InputImgGray_pu8, cv::Mat::AUTO_STEP);
#endif
    m_THAInput.InputImgGray_pu8 = (unsigned char *)yimage;
    /*Added by Afshan S to get rear view fisheye image buffer */
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
        if ((v_algoView_pv = v_ovl3d_po->algoViewCreate_po((char *)"algo-fisheye-y", ALGO_VIEW_GRAYSCALE_RAW, v_width_u32, v_height_u32)) == NULL)
        {
            ME_Debugger_F_Printf_v("failed to create algo-view\n");
        }
        else if (v_tiovx_ro.allocVideoBuffer_b(v_width_u32, v_height_u32, SCREEN_FORMAT_BYTE, 1, v_bufferDesc_t) == false)
        {
            ME_Debugger_F_Printf_v("failed to allocate buffer\n");
        }
        else if (v_ovl3d_po->algoViewBuffersPrepare_b(v_bufferDesc_t, v_textures_apo) == false)
        {
            ME_Debugger_F_Printf_v("failed to prepare buffers\n");
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

            uint32_t t0 = __get_time_usec();

            if (v_ovl3d_po->algoViewJobSubmit_b(&v_job_t) == true)
            {
                // wait for job completion (explicitly)
                ME_Condvar_Wait_t(&v_condvar_s);
            }

            uint32_t t1 = __get_time_usec();

            ME_Mutex_UnLock_t(&v_condvar_s.MEMutex_po);

            uint32_t *v_data_pu32 = static_cast<uint32_t *>(v_bufferDesc_t.buffers_apv[0]);
            memcpy(m_THAInput.InputImgGray_pu8, v_data_pu32, grey_image_size);

            //Reading input image from SD card for offline testing
            #if ENABLE_OFFLINE_TEST_THA
            vx_char input_file_name[256];
            int32_t imageSize = 640*400;
            static uint32_t ImgNum = 0;
            #if !UNIT_TESTING
            static char gray_path[256];
            static uint8_t gray_once = 0;
            if(gray_once == 0)
            {
                //read config
                FILE *fp = fopen("/ti_sd/unit_testing_cfg.txt", "r");
                char line_str[1024];
                char *token;
                if(fp==NULL)
                {
                    ME_Debugger_F_Printf_v("app_tidl: ERROR: Unable to open config file \n");
                }

                while(fgets(line_str, sizeof(line_str), fp)!=NULL)
                {
                    char s[]=" \t";

                    /* get the first token */
                    token = strtok(line_str, s);

                    if(token != NULL)
                    {
                        if(strcmp(token, "gray_path")==0)
                        {
                            token = strtok(NULL, s);
                            if(token != NULL)
                                {
                                    token[strlen(token)-1]=0;
                                    strcpy(gray_path, token);
                                }
                        }
                    }
                }
                gray_once = 1;
            }
            
            sprintf(input_file_name,"%s_%dRGB.bin",gray_path,ImgNum++);
            #endif
            //Dipti : If hardcode image needs to be given use below paths:
            //sprintf(input_file_name,"/ti_sd/Muledeg0resized_gray/resized_gray_algo_fisheye_rear_%dRGB.bin",ImgNum++);
            //sprintf(input_file_name,"/ti_fs/vision_apps/gray_image.bin");
            FILE * f2 = fopen(input_file_name, "rb");
            if(f2 == NULL)
            {
                ME_Debugger_F_Printf_v("Could not open file\n");
            }
            if(NULL != m_THAInput.InputImgGray_pu8 )
            {
                int ret_status = fseek(f2, 0, SEEK_SET);
                size_t bytesRead = fread(m_THAInput.InputImgGray_pu8, 1, imageSize, f2);
                fclose(f2);
            }
            else
            {
                ME_Debugger_F_Printf_v("Could not read file in imagePtr\n");
            }
            #endif

            #if ENABLE_VIEW_WORKAROUND
            #if PROFILE_THA
            osal::Time v_Time_o;
            uint64_t v_StartTime_u64 = 0;
            uint64_t v_EndTime_u64 = 0;
            static uint64_t v_TotalTime_u64 = 0;
            v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
            #endif
            // Dipti : Diagonal Flip function for gray algo view
            matrixUtil::FlipDiagGray( m_THAInput.InputImgGray_pu8, grey_image_width, grey_image_height );
            #if PROFILE_THA
            v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
            v_TotalTime_u64 = v_EndTime_u64 - v_StartTime_u64;
            ME_Debugger_F_Printf_v("\nGrayFlip: %f ms ", (float32_t)(v_TotalTime_u64 * 1.0f));
            #endif//PROFILE_THA
            #endif

            #if DUMP_THA_ALGO_VIEW
            // Dipti : Logic to dump GrayImage(640*400) continuously in SD card,add counter otherwise
            static char FileName[64] = {0};
            static uint32_t v_FrameCounter_u32 = 0;
            if(v_FrameCounter_u32 <= 20)
            {
              sprintf(FileName, "/ti_sd/THA_AlgoViewGray_%d.bin", v_FrameCounter_u32++);
              FILE *fptr = fopen(FileName, "w");
              if (NULL != fptr)
              {
                (void)fwrite(m_THAInput.InputImgGray_pu8, 1, (640*400), fptr);
                fclose(fptr);
                fptr = NULL;
              }
            }
            #endif

            uint32_t t2 = __get_time_usec();
            v_THAFrameNum_u32 = v_frameNum_u32;
            #if ENABLE_DEBUG_THA
            ME_Debugger_F_Printf_v("\n #### Gray: THA frame-%u: job processed: %u\n", v_frameNum_u32, t1 - t0);
            #endif
        }
    }
}

/// @brief  Get AlgoView processor data
container::OVL3DData* DataProviderTHA::getOVL3DData_po()
{
    return dataProvider_ro.getOVL3DData_po();
}

/// @brief  Get TIOVX host handle
bsp::TIOVXHost& DataProviderTHA::getTIOVX_ro()
{
    return dataProvider_ro.getTIOVXData_po()->getTIOVX_ro();
}

void DataProviderTHA::getCalibData()
{
  //Get call for calib data structure THA_Calibration_data_MPU1_0_t
    for(int32_t i = 0; i < 1000; i++)
    {
        /* Sleep for preemption to free CPU*/
        ME_Thread_Sleep_t(30); /*30 msec sleep for 30fps no need to read fast*/
        thaDetCalibData = dataProvider_ro.getSigMData_po()->getTHA_Calibration_data_MPU1_0();
        if (TRUE == thaDetCalibData.bValid)
        {
            // Input calibration data
#if ENABLE_DEBUG_THA
            ME_Debugger_F_Printf_v("*********************************** THA Calib start ***********************************");
            ME_Debugger_F_Printf_v("THA_CalibData : %f,%f,%f,%f,%f,%f,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
              thaDetCalibData.CalData.THAVehSpeedThresh_f32,thaDetCalibData.CalData.DefaultTrailerAngleDeg_f32,
              thaDetCalibData.CalData.CouplerConfThresh_f32,thaDetCalibData.CalData.CouplerToHitchThresh_f32,
              thaDetCalibData.CalData.TrailerAngleThreshDeg_f32,thaDetCalibData.CalData.KcfMinPeakValueThresh_f32,
              thaDetCalibData.CalData.DefaultHitchXmm_s32,thaDetCalibData.CalData.DefaultHitchYmm_s32,
              thaDetCalibData.CalData.DefaultHitchZmm_s32,thaDetCalibData.CalData.DefaultHitchXpix_s32,
              thaDetCalibData.CalData.DefaultHitchYpix_s32,thaDetCalibData.CalData.CouplerHeight_s32,
              thaDetCalibData.CalData.UtilizeTrailerTracker_b,thaDetCalibData.CalData.IsCouplerToHitchThreshInPix_b,
              thaDetCalibData.CalData.EnableKFSmooth_b,thaDetCalibData.CalData.EnableODONNXCrop_b);
            ME_Debugger_F_Printf_v("*********************************** THA Calib end ***********************************");  
#endif
        }
    }
}

void DataProviderTHA::getSVSHMIdata()
{
  static SvsToTHADet_t ipc_svsTHAData;
  ipc_svsTHAData = dataProvider_ro.getSigMData_po()->getSvsToTHADet_t();
  #if ENABLE_OFFLINE_TEST_THA
  m_THAInput.HMIInput_s.CplrPixX_u16                = 943;
  m_THAInput.HMIInput_s.CplrPixY_u16                = 827;
  #else
  m_THAInput.HMIInput_s.CplrPixX_u16                = ipc_svsTHAData.MeSVS_px_THACplrPosX;
  m_THAInput.HMIInput_s.CplrPixY_u16                = ipc_svsTHAData.MeSVS_px_THACplrPosY;
  #endif
  #if ENABLE_DEBUG_THA
  /*ME_Debugger_F_Printf_v("\n\n #################################### THA getTHAInput(): HMI SVS \n CplrPixX_u16 = %d \n CplrPixY_u16 = %d \n #################################### \n \n",\
                       m_THAInput.HMIInput_s.CplrPixX_u16, m_THAInput.HMIInput_s.CplrPixY_u16);*/
  #endif
}

bool_t DataProviderTHA::isTHAFeatureAllowedToRun(void)
{
  bool isAllowed = TRUE;
  /*
   * SC - Service Calibration
   * EOL - End Of Line
   */

  /* Check for SC */
  TbSVS_e_SVSCalibSMToAlgoCamCalib_t i_SMToAlgo = dataProvider_ro.getCalSmMData_po()->getSVSCalibSMToAlgoCamCalib();
  if (TRUE == i_SMToAlgo.AlgoCntrlData_t.data[SC_ALGO_ACTIVE_BYTE]) {
    isAllowed &= FALSE;
  }

  /* Check for EOL */
  if (TRUE == i_SMToAlgo.AlgoCntrlData_t.data[EOL_ALGO_ACTIVE_BYTE]) {
    isAllowed &= FALSE;
  }

  return isAllowed;
}

void DataProviderTHA::getTHAsmVCdata()
{
  static TbTHASmVc_FeatureOutputs_t ipc_thasmvcData;
  ipc_thasmvcData = dataProvider_ro.getSigMData_po()->getTbTHASmVc_FeatureOutputs_t();
  #if ENABLE_OFFLINE_TEST_THA
  m_THAInput.SMInput_s.THASmState_e                   = THAState_e::e_EnabledSelection;
  m_THAInput.SMInput_s.UsrHitchCnfm_b                 = FALSE;
  m_THAInput.SMInput_s.UsrCplrSelected_b              = TRUE;
  #else
  m_THAInput.SMInput_s.THASmState_e                   = (THAState_e)ipc_thasmvcData.MeTHA_e_THAStateInfo;
  m_THAInput.SMInput_s.THATrgTypeScrReq_e           = (aSigConverter_E_THAScreenRequest_t)ipc_thasmvcData.MeTHA_e_ScreenRequest;
  m_THAInput.SMInput_s.UsrHitchCnfm_b               = ipc_thasmvcData.MeTHA_b_UsrHitchCnfm;
  m_THAInput.SMInput_s.UsrCplrSelected_b            = ipc_thasmvcData.MeTHA_b_UsrCplrSelCnfm;
  #endif
  #if ENABLE_DEBUG_THA
/*   ME_Debugger_F_Printf_v("\n\n #################################### THA getTHAInput(): THA SM VC \n THASmState_e = %d \n THATrgTypeScrReq_e = %d \n UsrHitchCnfm_b = %d  UsrCplrSelected_b = %d \n #################################### \n \n", \
//                         m_THAInput.SMInput_s.THASmState_e,
//                         m_THAInput.SMInput_s.THATrgTypeScrReq_e,
//                         m_THAInput.SMInput_s.UsrHitchCnfm_b,
                         m_THAInput.SMInput_s.UsrCplrSelected_b);*/               
  #endif
}

void DataProviderTHA::getVCANdata()
{
  // Get Vehicle CAN signals
  ipc_VcanData = dataProvider_ro.getSigMData_po()->getME_VehInp_to_IpcSignals_t();
  m_THAInput.VehInput_s.VehSpeed_f32     = ipc_VcanData.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig;
  m_THAInput.VehInput_s.GearDirection_e  = (GearValuesDsply)ipc_VcanData.CAN2_to_IPC.DataInp_TRANSM_FD_2.GearEngagedForDisplay;
  #if ENABLE_OFFLINE_TEST_THA
  m_THAInput.VehInput_s.VehSpeed_f32     = 5.0f;
  m_THAInput.VehInput_s.GearDirection_e  = GEAR_DISP_REVERSE;
  #endif
  #if ENABLE_DEBUG_THA
  /*ME_Debugger_F_Printf_v("\n\n #################################### THA getTHAInput(): VEHCILE \n VehSpeed_f32 = %d \n GearDirection_e = %d \n #################################### \n \n", \
                    //    m_THAInput.VehInput_s.VehSpeed_f32,
                    //    m_THAInput.VehInput_s.GearDirection_e);*/
  #endif
}

void DataProviderTHA::getKMdata()
{
  static IKinematicData_t ipc_KMData;
  ipc_KMData = dataProvider_ro.getSigMData_po()->getIKinematicData_t();
  m_THAInput.KMInput_s.KMDataInfo_s.dx_m_f32        = ipc_KMData.dx_m;
  m_THAInput.KMInput_s.KMDataInfo_s.dy_m_f32        = ipc_KMData.dy_m;
  m_THAInput.KMInput_s.KMDataInfo_s.dyaw_rad_f32    = ipc_KMData.dyaw_rad;
  m_THAInput.KMInput_s.KMDataInfo_s.timestamp_s_f32 = ipc_KMData.timestamp_s;
  #if ENABLE_DEBUG_THA
  /*ME_Debugger_F_Printf_v("\n\n ################ THA getTHAInput(): KM DATA ####################\n dx_m_f32 = %f \n dy_m_f32 = %f \n dyaw_rad_f32 = %f \n timestamp_s_f32 = %f \n #################################### \n \n", \
                    //    m_THAInput.KMInput_s.KMDataInfo_s.dx_m_f32,
                    //    m_THAInput.KMInput_s.KMDataInfo_s.dy_m_f32,
                    //    m_THAInput.KMInput_s.KMDataInfo_s.dyaw_rad_f32,
                    //    m_THAInput.KMInput_s.KMDataInfo_s.timestamp_s_f32);*/
  #endif
}

/* Put function for THA detection output*/
void DataProviderTHA::putTHADetOutput( JobTHAAlgoDetOutput_t i_detectionOutput )
{
    m_THADetOutput = i_detectionOutput;
    JobTHADetOutput_t v_THADetOutput;
    // Expected output image resolution
    uint16_t v_OutImage_width = 640;
    uint16_t v_OutImage_height = 400;
    float32_t v_resizeFactorW = static_cast<float32_t>( algo_view_width ) / static_cast<float32_t>( v_OutImage_width );
    float32_t v_resizeFactorH = static_cast<float32_t>( algo_view_height ) / static_cast<float32_t>( v_OutImage_height );

    i_detectionOutput.HitchPix_p2d.x            = (i_detectionOutput.HitchPix_p2d.x / v_resizeFactorW);
    i_detectionOutput.HitchPix_p2d.y            = (i_detectionOutput.HitchPix_p2d.y / v_resizeFactorH);
    i_detectionOutput.CplrPix_p2d.x             = (i_detectionOutput.CplrPix_p2d.x / v_resizeFactorW);
    i_detectionOutput.CplrPix_p2d.y             = (i_detectionOutput.CplrPix_p2d.y / v_resizeFactorH);
    i_detectionOutput.HitchCplrPixDiffLongY_s32 = (i_detectionOutput.HitchCplrPixDiffLongY_s32 / v_resizeFactorH);
    i_detectionOutput.HitchCplrPixDiffLatX_s32  = (i_detectionOutput.HitchCplrPixDiffLatX_s32 / v_resizeFactorW);
    //TODO: Map output sturucutr from algo to interface ie. JobTHADetOutput_t = JobTHAAlgoDetOutput_t
    memcpy(&v_THADetOutput, &i_detectionOutput, sizeof(JobTHAAlgoDetOutput_t));
    dataProvider_ro.getSigMData_po()->setJobTHADetOutput_v(v_THADetOutput);
}

const StateProcessConfig DataProviderTHA::getStateProcessConfig()
{
    ME_Debugger_F_Printf_v("DataProviderTHA::getStateProcessConfig:\n");
    if(thaDetCalibData.bValid == 1)
    {
        m_THAStateConfig.setTHAVehSpeedThresh(thaDetCalibData.CalData.THAVehSpeedThresh_f32);
        m_THAStateConfig.setDefaultHitchX_mm(thaDetCalibData.CalData.DefaultHitchXmm_s32);
        m_THAStateConfig.setDefaultHitchY_mm(thaDetCalibData.CalData.DefaultHitchYmm_s32);
        m_THAStateConfig.setDefaultHitchZ_mm(thaDetCalibData.CalData.DefaultHitchZmm_s32);
        Point3f thaDefaultHitchReal = { (float32_t)thaDetCalibData.CalData.DefaultHitchXmm_s32, \
                                        (float32_t)thaDetCalibData.CalData.DefaultHitchYmm_s32, \
                                        (float32_t)thaDetCalibData.CalData.DefaultHitchZmm_s32 };
        ME_Debugger_F_Printf_v("DataProviderTHA::getStateProcessConfig:thaDetCalibData.bValid == 1\n");
        Point2i thaHitchPixel = {0,0};
        PointWorld2ImagePixel(thaDefaultHitchReal, thaHitchPixel);
        thaDetCalibData.CalData.DefaultHitchXpix_s32 = thaHitchPixel.x;
        thaDetCalibData.CalData.DefaultHitchYpix_s32 = thaHitchPixel.y;
        m_THAStateConfig.setDefaultHitchX_pix(thaDetCalibData.CalData.DefaultHitchXpix_s32);
        m_THAStateConfig.setDefaultHitchY_pix(thaDetCalibData.CalData.DefaultHitchYpix_s32);
        m_THAStateConfig.setDefaultTrailerAngle_deg(thaDetCalibData.CalData.DefaultTrailerAngleDeg_f32);
        m_THAStateConfig.setCouplerHeight(thaDetCalibData.CalData.DefaultHitchZmm_s32);
        m_THAStateConfig.setUtilizeTrailerTracker(thaDetCalibData.CalData.UtilizeTrailerTracker_b);
        m_THAStateConfig.setCouplerToHitchThresh(thaDetCalibData.CalData.CouplerToHitchThresh_f32);
        m_THAStateConfig.setIsCouplerToHitchThreshInPix(thaDetCalibData.CalData.IsCouplerToHitchThreshInPix_b);
        m_THAStateConfig.setCouplerConfThresh(thaDetCalibData.CalData.CouplerConfThresh_f32);
        m_THAStateConfig.setTrailerAngleThreshDeg(thaDetCalibData.CalData.TrailerAngleThreshDeg_f32);
        m_THAStateConfig.setEnableKFSmooth(thaDetCalibData.CalData.EnableKFSmooth_b);
        m_THAStateConfig.setEnableODONNXCrop(thaDetCalibData.CalData.EnableODONNXCrop_b);
        #ifdef _WIN32
        m_THAStateConfig.EnableGPU                   = 0;
        #endif
        m_THAStateConfig.setROIWidth(150);
        m_THAStateConfig.setROIHeight(150);
        m_THAStateConfig.setDetDNNInputDimW(640);
        m_THAStateConfig.setDetDNNInputDimH(640);
        m_THAStateConfig.setDetLatPixThresh(75);
    }
    else
    {
        m_THAStateConfig.setTHAVehSpeedThresh(8.0f);
        m_THAStateConfig.setDefaultHitchX_mm(5096);
        m_THAStateConfig.setDefaultHitchY_mm(0);
        m_THAStateConfig.setDefaultHitchZ_mm(477.58);
        m_THAStateConfig.setDefaultHitchX_pix(319);
        m_THAStateConfig.setDefaultHitchY_pix(294);
        m_THAStateConfig.setDefaultTrailerAngle_deg(0.0f);
        m_THAStateConfig.setCouplerHeight(530);
        m_THAStateConfig.setUtilizeTrailerTracker(true);
        m_THAStateConfig.setCouplerToHitchThresh(11.0f);
        m_THAStateConfig.setCouplerNotDetThresh(2.5f);
        m_THAStateConfig.setIsCouplerToHitchThreshInPix(true);
        m_THAStateConfig.setCouplerConfThresh(0.5f);
        m_THAStateConfig.setTrailerAngleThreshDeg(60.0f);
        m_THAStateConfig.setEnableKFSmooth(true);
        m_THAStateConfig.setEnableODONNXCrop(true);
        #ifdef _WIN32
        m_THAStateConfig.setEnableGPU(0);
        #endif
        m_THAStateConfig.setROIWidth(150);
        m_THAStateConfig.setROIHeight(150);
        m_THAStateConfig.setDetDNNInputDimW(640);
        m_THAStateConfig.setDetDNNInputDimH(640);
        m_THAStateConfig.setDetLatPixThresh(75);
    }
    return m_THAStateConfig;
}

const TrailerTrackCfg DataProviderTHA::getTrailerTrackCfg()
{
    if(thaDetCalibData.bValid == 1)
    {
        m_TrailerTrackConfig.setTrackBlockWidth(64);
        m_TrailerTrackConfig.setTrackBlockHeight(64);
        m_TrailerTrackConfig.setkcfMinPeakValue(thaDetCalibData.CalData.KcfMinPeakValueThresh_f32);
    }
    else
    {
        m_TrailerTrackConfig.setTrackBlockWidth(64);
        m_TrailerTrackConfig.setTrackBlockHeight(64);
        m_TrailerTrackConfig.setkcfMinPeakValue(0.2f);
    }
    return m_TrailerTrackConfig;
}

void DataProviderTHA::putTHADetDebugOutput( JobTHAAlgoDetDebug_t i_detectionDebugOutput )
{
    m_JobTHADetDebugOutput = i_detectionDebugOutput;
}

void DataProviderTHA::TransformFlipPntInp( Point2i& b_UsrSelCplrPnt_rs32, uint16_t& i_HMICplrX_ru16, uint16_t& i_HMICplrY_ru16 )
{
    //Transform on embedded
    uint16_t v_TransW_u16 = algo_view_width; // Algo view width - 1920
    uint16_t v_TransH_u16 = algo_view_height; // Algo view height - 1280
    b_UsrSelCplrPnt_rs32 = Point2i( ( static_cast<int32_t>( v_TransW_u16 - i_HMICplrX_ru16 ) ), static_cast<int32_t>( v_TransH_u16 - i_HMICplrY_ru16 ) );

    if( b_UsrSelCplrPnt_rs32.x < 0 )
    {
        b_UsrSelCplrPnt_rs32.x = 0;
    }

    if( b_UsrSelCplrPnt_rs32.y < 0 )
    {
        b_UsrSelCplrPnt_rs32.y = 0;
    }

    if( b_UsrSelCplrPnt_rs32.x >= static_cast<int32_t>( v_TransW_u16 ) )
    {
        b_UsrSelCplrPnt_rs32.x = static_cast<int32_t>( v_TransW_u16 ) - 1;
    }

    if( b_UsrSelCplrPnt_rs32.y >= static_cast<int32_t>( v_TransH_u16 ) )
    {
        b_UsrSelCplrPnt_rs32.y = static_cast<int32_t>( v_TransH_u16 ) - 1;
    }
}


//--- do_CameraParam para and functions
float32_t DataProviderTHA::getDeltaX()
{
    return m_aCameraInfo.camera_param.getDeltaX();
}

float32_t DataProviderTHA::getDeltaY()
{
    return m_aCameraInfo.camera_param.getDeltaY();
}

void DataProviderTHA::getP_MECL( float32_t i_P[3][4] )
{
    ( void )memcpy( i_P, m_aCameraInfo.P_MECL, sizeof( m_aCameraInfo.P_MECL ) );
}

Point2f DataProviderTHA::pixel_warp( Point2f& pt )
{
    return m_aCameraInfo.camera_param.pixel_warp( pt );
}

Point2f DataProviderTHA::pixel_unwarp( const Point2f* pPtInput )
{
    return m_aCameraInfo.camera_param.pixel_unwarp( pPtInput );
}

Point2f DataProviderTHA::unwarped_distance( Point2f i_unwarp_pts )
{
    return m_aCameraInfo.camera_param.unwarped_distance( i_unwarp_pts );
}

Point2f DataProviderTHA::ProjectTo2D( Point3f i_3d_pts, const float32_t i_P[3][4], bool warp )
{
    return m_aCameraInfo.ProjectTo2D( i_3d_pts, i_P, warp );
}

Point2f DataProviderTHA::ProjectTo2D( Point3f i_3d_pts, bool warp )
{
    return m_aCameraInfo.ProjectTo2D( i_3d_pts, warp );
}

Point3f DataProviderTHA::BackProjectTo3D( const Point2f& pt, bool unwarp )
{
    return m_aCameraInfo.BackProjectTo3D( pt, unwarp );
}

void DataProviderTHA::setTHARuntime(uint32_t u_Runtime_u32)
{
  dataProvider_ro.getTHAData_po()->setTHARuntime(u_Runtime_u32);
}

void DataProviderTHA::setTHAThreadRuntime(uint32_t u_Runtime_u32)
{
  dataProvider_ro.getTHAData_po()->setTHAThreadRuntime(u_Runtime_u32);
}

PerformanceStatsEnable_t DataProviderTHA::get_PerformanceStatsEnable(void)
{
	return dataProvider_ro.getSigMData_po()->getPerformanceStatsEnable_t();
}

void DataProviderTHA::PointWorld2ImagePixel(Point3f i_World3D, Point2i& o_Pixel2D)
{
    float32_t world_xyz[3] = {i_World3D.x, i_World3D.y, i_World3D.z};
    float32_t raw_xy[2] = {0.0f, 0.0f};
    float32_t wheelbase_mm = 0.0f;

    variants::ME_VariantHelper_GetWheelBase_b(&wheelbase_mm);
    world_xyz[0] = (wheelbase_mm - world_xyz[0]); //Convert Front axle to ISO RearAxle format

    view_manager_world_2_raw_v_rear_tha(world_xyz,raw_xy);

    //Convert Raw (0,1) to pixel in 640 x 400 resolution (Width x Height)
    o_Pixel2D.x = (int32_t)(raw_xy[0] * 640);
    o_Pixel2D.y = (int32_t)(raw_xy[1] * 400);

    //Flip Pixel Cordinates for THA as Cogent API gives inverted image y cordiante
    o_Pixel2D.x = (640 - o_Pixel2D.x);
    o_Pixel2D.y = (400 - o_Pixel2D.y);

    ME_Debugger_F_Printf_v("PointWorld2ImagePixel(): Input Front Axle World: x=%f, y=%f, z=%f\n",i_World3D.x, i_World3D.y, i_World3D.z);
    ME_Debugger_F_Printf_v("Input Rear Axle World: x=%f, y=%f, z=%f\n",world_xyz[0], world_xyz[1], world_xyz[2]);
    ME_Debugger_F_Printf_v("Output Normalize Raw Pixel: x1=%f, y1=%f\n",raw_xy[0], raw_xy[0]);
    ME_Debugger_F_Printf_v("Output (640 X 400) Raw Pixel: x1=%d, y1=%d\n",o_Pixel2D.x, o_Pixel2D.y);
    ME_Debugger_F_Printf_v("wheelbase_mm=%f\n",wheelbase_mm);
}

} // namespace km
