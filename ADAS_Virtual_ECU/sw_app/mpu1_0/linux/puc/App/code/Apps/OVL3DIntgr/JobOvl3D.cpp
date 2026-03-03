//--------------------------------------------------------------------------
/// @file JobOvl3D.cpp
/// @brief Contains the Ovl 3D job implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#include "JobOvl3D.h"
#include <fstream>
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_OVL3D     (1u)
#endif
#if PROFILE_OVL3D
#include "osal/system/Clock.h"
static uint32_t v_AvgOVL3DRuntime_u32 = 0;
static uint32_t v_OVL3DRunCntr_u32 = 0;
static uint32_t v_AvgOVL3DPeriodicity_u32 = 0;
static uint32_t v_PreviousTime_u32 = 0;
static uint32_t v_OVL3DRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsEnable_dp;
#endif
//setting default values
char algo_view_id[100] = {'\0'};
algo_view_type_t view_type = ALGO_VIEW_GRAYSCALE;

void strcpy(char* dest, char* src)
{
    int temp_index = 0;

    while(src[temp_index] != '\0')
        {
            dest[temp_index] = src[temp_index];
            temp_index++;
        }
        dest[temp_index] = '\0';
}
// This function should be called to create the dump file of the buffer data
void dump_to_file(bsp::VideoInputBufferDesc2_t* buffer, uint32_t buffer_indx, char* path, algo_view_type_t view_type_local)
{
    /*
        DT buffers
        26 to 29 front
        30 t0 33 left
        34 to 37 rear
        38 to 41 right
    */
    
    //Code to automatically make algo view id as bin file name.
    char path_temp[100] = {'\0'};
    strcpy(path_temp, path);

    path[0] = '/';
    path[1] = 't';
    path[2] = 'i';
    path[3] = '_';
    path[4] = 's';
    path[5] = 'd';
    path[6] = '/';

    int str_index = 7;

    while(path_temp[str_index-7] != '\0')
    {   
        if(path_temp[str_index-7] == '-')
            path_temp[str_index-7] = '_';
        
        path[str_index] = path_temp[str_index-7];
        str_index++;
    }

    FILE* file = NULL;
    int open_file = 1;
    
    do
    { 
        if(open_file)
        {

            if((view_type_local == ALGO_VIEW_RGB_PLANAR_RAW) || (view_type_local == ALGO_VIEW_RGB_PLANAR))
            {              
                path[str_index+0] = 'R';
                path[str_index+1] = 'G';
                path[str_index+2] = 'B';
                path[str_index+3] = '.';
                path[str_index+4] = 'b';
                path[str_index+5] = 'i';
                path[str_index+6] = 'n';
                path[str_index+7] = '\0';
            }
            else
            {
                path[str_index+0] = 'Y';
                path[str_index+1] = '.';
                path[str_index+2] = 'b';
                path[str_index+3] = 'i';
                path[str_index+4] = 'n';
                path[str_index+5] = '\0';
            }

            file = fopen(path, "wb");
            open_file = 0;
        }



        if (file != NULL)
        {
            // ME_Debugger_F_Printf_v("size[0] %u \n",buffer->size_au32[0]);
            // ME_Debugger_F_Printf_v("size[1] %u \n",buffer->size_au32[1]);
            
            //dump the first plane /*GREYSCALE*/
            for (uint32_t y = 0; y < buffer->size_au32[1]; y++)
            {
                uint8_t* ptr = (uint8_t*)buffer->buffers_apv[buffer_indx] + buffer->offset_aau32[buffer_indx][0] + y * buffer->stride_au32[0];
                fwrite(ptr, 1, buffer->size_au32[0], file);      
            }
            // ME_Debugger_F_Printf_v("Plane   %u \n",0);
            // ME_Debugger_F_Printf_v("stride  %u \n",buffer->stride_au32[0]);
            // ME_Debugger_F_Printf_v("offset  %u \ndone\n",buffer->offset_aau32[buffer_indx][0]);

            uint32_t k;

           for (k = 1; k < 3; k++)
           {
               if ((buffer->offset_aau32[buffer_indx][k] > 0 && buffer->stride_au32[k] > 0))
               {
                   for (uint32_t y = 0; y < buffer->size_au32[1]; y++)
                   {
                       uint8_t* ptr = (uint8_t*)buffer->buffers_apv[buffer_indx] + buffer->offset_aau32[buffer_indx][k] + y * buffer->stride_au32[k];
                       fwrite(ptr, 1, buffer->size_au32[0], file);
                   }
               }

                //ME_Debugger_F_Printf_v("Plane   %u \n",k);
                //ME_Debugger_F_Printf_v("stride  %u \n",buffer->stride_au32[k]);
                //ME_Debugger_F_Printf_v("offset  %u \ndone\n",buffer->offset_aau32[buffer_indx][k]);
           }
        }
       
        buffer_indx++;
    }while((buffer_indx < 3) && (view_type_local != ALGO_VIEW_GRAYSCALE) && (view_type_local != ALGO_VIEW_GRAYSCALE_RAW));

    if(file != NULL)
    {   
        fclose(file);
        ME_Debugger_F_Printf_v("File %s done\n",path);
    }
    else
    {
        ME_Debugger_F_Printf_v("File %s failed\n",path);
    }
}
namespace ovl3d
{

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
JobOvl3D::JobOvl3D(container::JobDesc_s& b_JobDesc_rs, IDataProviderOvl3D& b_DPOvl_ro)
  : JobBase(b_JobDesc_rs, b_DPOvl_ro)
  , renderThread_o("RenderThread")
  , renderThreadRunnable_o(b_DPOvl_ro)
  , dataProvider_ro(b_DPOvl_ro)
{
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
JobOvl3D::~JobOvl3D()
{
}

/// @brief  Rear-TV-Algo-View
static void* algoViewGRAY_pv(void *i_Args_pv)
{
    IDataProviderOvl3D*     v_dataProvider_po = reinterpret_cast<IDataProviderOvl3D*>(i_Args_pv);
    container::OVL3DData*   v_ovl3d_po = v_dataProvider_po->getOVL3DData_po();
    bsp::TIOVXHost&         v_tiovx_ro = v_dataProvider_po->getTIOVX_ro();

    uint32_t  v_width_u32;
    uint32_t  v_height_u32;

    algo_view_t  *v_algoView_pv;
    Condvar_s    v_condvar_s;
    bsp::VideoInputBufferDesc2_t v_bufferDesc_t;
    texture_data_t*  v_textures_apo[3];

    //Copy contexts into local container
    char algo_view_id_local[100] = {'\0'};
    strcpy(algo_view_id_local, algo_view_id);
    algo_view_type_t view_type_local = view_type;

    // create AlgoView descriptor
    if ((v_algoView_pv = v_ovl3d_po->algoViewCreate_po(algo_view_id_local, view_type_local, v_width_u32, v_height_u32)) == NULL)
    {
        ME_Debugger_F_Printf_v("failed to create algo-view: %s \n", view_type_local);
    }
    else if (v_tiovx_ro.allocVideoBuffer_b(v_width_u32, v_height_u32, SCREEN_FORMAT_BYTE, 1, v_bufferDesc_t) == false)
    {
        ME_Debugger_F_Printf_v("failed to allocate buffer: %s \n", view_type_local);
    }
    else if (v_ovl3d_po->algoViewBuffersPrepare_b(v_bufferDesc_t, v_textures_apo) == false)
    {
        ME_Debugger_F_Printf_v("failed to prepare buffers: %s \n", view_type_local);
    }

    memset(&v_condvar_s, 0, sizeof(v_condvar_s));
    ME_Condvar_Init_t(&v_condvar_s);

    // set first frame number
    uint32_t v_frameNum_u32 = 0;

    while (v_algoView_pv != NULL)
    {
        AlgoViewJob_s   v_job_t;

        // wait for next input frame (use every frame nominally)
        v_ovl3d_po->waitFrame_b(v_frameNum_u32);

        v_job_t.algoView_po = v_algoView_pv;
        v_job_t.condvar_po = &v_condvar_s;
        v_job_t.output_apo = v_textures_apo;
        v_job_t.sync_ppo = NULL;

        ME_Mutex_Lock_t(&v_condvar_s.MEMutex_po);

        uint32_t    t0 = __get_time_usec();

        if (v_ovl3d_po->algoViewJobSubmit_b(&v_job_t) == true)
        {
            // wait for job completion (explicitly)
            ME_Condvar_Wait_t(&v_condvar_s);
        }

        uint32_t    t1 = __get_time_usec();

        ME_Mutex_UnLock_t(&v_condvar_s.MEMutex_po);

        // calculate CRC out of output frame?
        uint32_t  v_sum_u32 = 0U;
        uint32_t* v_data_pu32 = static_cast<uint32_t*>(v_bufferDesc_t.buffers_apv[0]);
        for (uint32_t v_idx_u32 = 0; v_idx_u32 < v_bufferDesc_t.bufsize_au32[0] / 4; v_idx_u32++)
        {
            v_sum_u32 ^= *v_data_pu32++;
        }
    
    static int loopOnce = 1;
        if(loopOnce && (v_frameNum_u32 >= 50u))
            {
                //Always put 0 as 2nd argument
                dump_to_file(&v_bufferDesc_t, 0, algo_view_id_local, view_type_local);
                loopOnce = 0;
            }

        uint32_t  t2 = __get_time_usec();

        //ME_Debugger_F_Printf_v("frame-%u: job processed: sum=%X, %u/%u (%u)\n", v_frameNum_u32, v_sum_u32, t1 - t0, t2 - t1, t2 - t0);
    }

    return NULL;
}

/// @brief  Rear-TV-Algo-View
static void* algoViewRGB_pv(void *i_Args_pv)
{
    IDataProviderOvl3D*     v_dataProvider_po = reinterpret_cast<IDataProviderOvl3D*>(i_Args_pv);
    container::OVL3DData*   v_ovl3d_po = v_dataProvider_po->getOVL3DData_po();
    bsp::TIOVXHost&         v_tiovx_ro = v_dataProvider_po->getTIOVX_ro();

    uint32_t  v_width_u32;
    uint32_t  v_height_u32;

    algo_view_t  *v_algoView_pv;
    Condvar_s    v_condvar_s;
    bsp::VideoInputBufferDesc2_t v_bufferDesc_t;
    texture_data_t*  v_textures_apo[3];

    //Copy contexts into local container
    char algo_view_id_local[100] = {'\0'};
    strcpy(algo_view_id_local, algo_view_id);
    algo_view_type_t view_type_local = view_type;

    // create AlgoView descriptor
    if ((v_algoView_pv = v_ovl3d_po->algoViewCreate_po(algo_view_id_local, view_type_local, v_width_u32, v_height_u32)) == NULL)
    {
        ME_Debugger_F_Printf_v("failed to create algo-view: %s \n", view_type_local);
    }
    else if (v_tiovx_ro.allocVideoBuffer_b(v_width_u32, v_height_u32, SCREEN_FORMAT_BYTE, 3, v_bufferDesc_t) == false)
    {
        ME_Debugger_F_Printf_v("failed to allocate buffer: %s \n", view_type_local);
    }
    else if (v_ovl3d_po->algoViewBuffersPrepare_b(v_bufferDesc_t, v_textures_apo) == false)
    {
        ME_Debugger_F_Printf_v("failed to prepare buffers: %s \n", view_type_local);
    }

    memset(&v_condvar_s, 0, sizeof(v_condvar_s));
    ME_Condvar_Init_t(&v_condvar_s);

    // set first frame number
    uint32_t v_frameNum_u32 = 0;

    while (v_algoView_pv != NULL)
    {
        sync_data_t*    v_sync_po = NULL;
        AlgoViewJob_s   v_job_t;

        // wait for next input frame (use every frame nominally)
        v_ovl3d_po->waitFrame_b(v_frameNum_u32);

        v_job_t.algoView_po = v_algoView_pv;
        v_job_t.condvar_po = &v_condvar_s;
        v_job_t.output_apo = v_textures_apo;
        v_job_t.sync_ppo = &v_sync_po;

        ME_Mutex_Lock_t(&v_condvar_s.MEMutex_po);

        uint32_t    t0 = __get_time_usec();

        if (v_ovl3d_po->algoViewJobSubmit_b(&v_job_t) == true)
        {
            // wait for job completion (using "sync" API)
            v_ovl3d_po->algoViewJobWait_b(&v_job_t);
        }

        uint32_t    t1 = __get_time_usec();

        ME_Mutex_UnLock_t(&v_condvar_s.MEMutex_po);

        // calculate CRC out of output frame?
        uint32_t  v_sum_u32[3] = {};
        uint32_t* v_data_pu32[3] = {
            static_cast<uint32_t*>(v_bufferDesc_t.buffers_apv[0]),
            static_cast<uint32_t*>(v_bufferDesc_t.buffers_apv[1]),
            static_cast<uint32_t*>(v_bufferDesc_t.buffers_apv[2]),
        };

        for (uint32_t v_idx_u32 = 0; v_idx_u32 < v_bufferDesc_t.bufsize_au32[0] / 4; v_idx_u32++)
        {
            v_sum_u32[0] ^= *v_data_pu32[0]++;
            v_sum_u32[1] ^= *v_data_pu32[1]++;
            v_sum_u32[2] ^= *v_data_pu32[2]++;
        }

        static int loopOnce = 1;
        if(loopOnce && (v_frameNum_u32 >= 100u))
            {
                //Always put 0 as 2nd argument
                dump_to_file(&v_bufferDesc_t, 0, algo_view_id_local, view_type_local);
                loopOnce = 0;
            loopOnce = 0;
            }

        uint32_t  t2 = __get_time_usec();

        //ME_Debugger_F_Printf_v("frame-%u: job processed: sum=%08x/%08x/%08x, %u/%u (%u)\n", v_frameNum_u32, v_sum_u32[0], v_sum_u32[1], v_sum_u32[2], t1 - t0, t2 - t1, t2 - t0);

        // skip next 2 frames (every third frame is processed)
        v_frameNum_u32 += 2U;
    }

    return NULL;
}

// #define THA
// #define OC
// #define EOL
// #define DLD
// #define PLD
// #define TAD
// define ALL
// #define RAW

bool_t JobOvl3D::onInit_b()
{
    // start thread here
    renderThread_o.start_v(&renderThreadRunnable_o);
    renderThread_o.setPriority_v(e_PriorityRealtime);
    #if defined(RAW) || defined(ALL)  

        {
        strcpy(algo_view_id,"algo-fisheye-rear");
        view_type = ALGO_VIEW_RGB_PLANAR_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewRGB_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

        {
        strcpy(algo_view_id,"algo-fisheye-front");
        view_type = ALGO_VIEW_RGB_PLANAR_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewRGB_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

        {
        strcpy(algo_view_id,"algo-fisheye-right");
        view_type = ALGO_VIEW_RGB_PLANAR_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewRGB_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

        {
        strcpy(algo_view_id,"algo-fisheye-left");
        view_type = ALGO_VIEW_RGB_PLANAR_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewRGB_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }
        
    #endif

    #if defined(PLD) || defined(ALL)

        {
        strcpy(algo_view_id,"algo-tv-pld-y");
        view_type = ALGO_VIEW_GRAYSCALE;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewGRAY_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

    #endif

    #if defined(TAD) || defined(ALL)

        {
        strcpy(algo_view_id,"algo-rear-tv-y");
        view_type = ALGO_VIEW_GRAYSCALE;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewGRAY_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

    #endif

    #if defined(THA) || defined(ALL)  

        {
        strcpy(algo_view_id,"algo-fisheye-rgb");
        view_type = ALGO_VIEW_RGB_PLANAR_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewRGB_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

        {
        strcpy(algo_view_id,"algo-fisheye-y");
        view_type = ALGO_VIEW_GRAYSCALE_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewGRAY_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

    #endif

    // stubs for a AlgoViews testing

    #if defined(DLD) || defined(ALL)  
        {
        strcpy(algo_view_id,"algo-fisheye-dld-rear");
        view_type = ALGO_VIEW_RGB_PLANAR_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewRGB_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

        {
        strcpy(algo_view_id,"algo-fisheye-dld-front");
        view_type = ALGO_VIEW_RGB_PLANAR_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewRGB_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

        {
        strcpy(algo_view_id,"algo-fisheye-dld-right");
        view_type = ALGO_VIEW_RGB_PLANAR_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewRGB_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

        {
        strcpy(algo_view_id,"algo-fisheye-dld-left");
        view_type = ALGO_VIEW_RGB_PLANAR_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewRGB_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

    #endif

    #if defined(OC) || defined(ALL) 
        
        {
        strcpy(algo_view_id,"algo-fisheye-oc-rear");
        view_type = ALGO_VIEW_GRAYSCALE_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewGRAY_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

        {
        strcpy(algo_view_id,"algo-fisheye-oc-front");
        view_type = ALGO_VIEW_GRAYSCALE_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewGRAY_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

        {
        strcpy(algo_view_id,"algo-fisheye-oc-right");
        view_type = ALGO_VIEW_GRAYSCALE_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewGRAY_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

        {
        strcpy(algo_view_id,"algo-fisheye-oc-left");
        view_type = ALGO_VIEW_GRAYSCALE_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewGRAY_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

    #endif

    #if defined(EOL) || defined(ALL)  

        {
        strcpy(algo_view_id,"algo-fisheye-rear");
        view_type = ALGO_VIEW_GRAYSCALE_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewGRAY_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

        {
        strcpy(algo_view_id,"algo-fisheye-front");
        view_type = ALGO_VIEW_GRAYSCALE_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewGRAY_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

        {
        strcpy(algo_view_id,"algo-fisheye-right");
        view_type = ALGO_VIEW_GRAYSCALE_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewGRAY_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }

        {
        strcpy(algo_view_id,"algo-fisheye-left");
        view_type = ALGO_VIEW_GRAYSCALE_RAW;
        // create graph processing thread
        ThreadHandle_s v_Thread_s;
        ME_Thread_Create_t(&v_Thread_s, algoViewGRAY_pv, &dataProvider_ro, ME_Thread_C_DefaultStackSize_t);
        ME_Thread_SetPriority_t(&v_Thread_s, e_PriorityRealtime);
        ME_Thread_SetName_t(&v_Thread_s, algo_view_id);
        }
        
    #endif

    return true;
}

void JobOvl3D::onVariantChanged_v(bool_t i_FirstTime_b)
{
}

bool_t JobOvl3D::onRun_b()
{
    // function is no-op; why do we need that? - tbd
//    ME_Debugger_F_Printf_v("ONRUN_B- %s\n", __PRETTY_FUNCTION__);
#if PROFILE_OVL3D
        PerformanceStatsEnable_dp = dataProvider_ro.get_PerformanceStatsEnable();
        static osal::Time start;
        volatile uint32_t v_Start_t = 0;
        volatile uint32_t v_End_t = 0;
        volatile uint32_t currPeriodicity = 0;
        if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
        {
            v_Start_t = __get_time_usec();
            currPeriodicity = v_Start_t - v_PreviousTime_u32;
        }
#endif
	ME_Thread_Sleep_t(5);
#if PROFILE_OVL3D
        if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
        {
            v_End_t = __get_time_usec();
            //ME_Debugger_F_Printf_v("OVL3D: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
            v_OVL3DRunCntr_u32++; //Increment the run counter for averaging purpose
            v_AvgOVL3DPeriodicity_u32 = ((v_AvgOVL3DPeriodicity_u32 * (v_OVL3DRunCntr_u32 -1)) + currPeriodicity)/v_OVL3DRunCntr_u32; //Average Periodicity
            v_AvgOVL3DRuntime_u32 = ((v_AvgOVL3DRuntime_u32 * (v_OVL3DRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_OVL3DRunCntr_u32; //New Average  
            v_OVL3DRuntimeData = (((v_AvgOVL3DRuntime_u32/1000U)<<16U) | ((v_AvgOVL3DPeriodicity_u32/1000U) & 0xFFFF));
            dataProvider_ro.setOVL3DRuntime(v_OVL3DRuntimeData);
            //ME_Debugger_F_Printf_v("OVL3D: E: %lld P: %lld \n", v_AvgOVL3DRuntime_u32, v_AvgOVL3DPeriodicity_u32);
            v_PreviousTime_u32 = v_Start_t;
        }
#endif
    return true;
}

void JobOvl3D::onCleanup_v()
{
    renderThreadRunnable_o.stop_v();
    renderThread_o.terminate_v();
    renderThread_o.join_v();
}


}; //namespace ovl
