//--------------------------------------------------------------------------
/// @file OVL3DData.cpp
/// @brief Contains the data for overlays
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
///
//  --------------------------------------------------------------------------

#include "OVL3DData.h"

namespace container
{

/// @brief  Class constructor
OVL3DData::OVL3DData()
    : DataContainer()
    , algoViewJob_t()
    , cfg_po(NULL)
{
    ME_Condvar_Init_t(&condvar_s);
    ME_Condvar_Init_t(&frameTrigger_s);
}

/// @brief  Class destructor
OVL3DData::~OVL3DData()
{
}

/// @brief  Initialization function
bool_t OVL3DData::init_b(cfg_data_t* i_cfg_po, screen_context_t i_screen_pv)
{
    ME_Mutex_Lock_t(&condvar_s.MEMutex_po);

    cfg_po = i_cfg_po;
    screen_pv = i_screen_pv;

    ME_Condvar_Broadcast_t(&condvar_s);

    ME_Mutex_UnLock_t(&condvar_s.MEMutex_po);

    return true;
}

/// @brief  Wait for a new input frame
bool_t OVL3DData::waitFrame_b(uint32_t& io_frameNum_u32)
{
    ME_Mutex_Lock_t(&frameTrigger_s.MEMutex_po);

    while ((int32_t)(io_frameNum_u32 - frameNumber_u32) >= 0)
    {
        ME_Condvar_Wait_t(&frameTrigger_s);
    }

    io_frameNum_u32 = frameNumber_u32;

    ME_Mutex_UnLock_t(&frameTrigger_s.MEMutex_po);

    return true;
}

void OVL3DData::updateFrame_v(uint32_t& io_frameNum_u32)
{
    io_frameNum_u32 = frameNumber_u32;
}

/// @brief  Notify input frame latching
void   OVL3DData::notifyFrame_v(uint32_t i_frameNum_u32)
{
    ME_Mutex_Lock_t(&frameTrigger_s.MEMutex_po);

    // update current frame number
    frameNumber_u32 = i_frameNum_u32;

    ME_Condvar_Broadcast_t(&frameTrigger_s);

    ME_Mutex_UnLock_t(&frameTrigger_s.MEMutex_po);
}

/// @brief Prepare buffers for operation
bool_t OVL3DData::algoViewBuffersPrepare_b(bsp::VideoInputBufferDesc2_t& i_desc_ro, texture_data_t** o_texture_apo)
{
    screen_pixmap_t v_pixmap_apo[i_desc_ro.numOfBuffer_u32];
    bool_t  v_result_b = true;

    // wait readiness
    waitReady_v();

    if (CreateVideoBufferPixmap_b(screen_pv, i_desc_ro, v_pixmap_apo) == false)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf, "Failed to create pixmaps");
        v_result_b = false;
    }

    for (uint32_t v_idx_u32 = 0U; v_result_b == true && v_idx_u32 < i_desc_ro.numOfBuffer_u32; v_idx_u32++)
    {
        if ((*o_texture_apo++ = texture_create_native(v_pixmap_apo[v_idx_u32], 0)) == NULL)
        {
            logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf, "Failed to create texture-%u", v_idx_u32);
            v_result_b = false;
        }
    }

    if (v_result_b == true)
    {
        logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "Allocated %u textures", i_desc_ro.numOfBuffer_u32);
    }

    return v_result_b;
}

/// @brief  Submit job for execution
bool_t OVL3DData::algoViewJobSubmit_b(AlgoViewJob_s* v_job_po)
{
    bool_t  v_result_b = true;

    if (cfg_po != NULL)
    {
        ME_Mutex_Lock_t(&condvar_s.MEMutex_po);
        algoViewJob_t.push(v_job_po);
        ME_Condvar_Broadcast_t(&condvar_s);
        ME_Mutex_UnLock_t(&condvar_s.MEMutex_po);
    }
    else
    {
        v_result_b = false;
    }

    return v_result_b;
}

/// @brief  Retrieve next pending job
AlgoViewJob_s* OVL3DData::algoViewJobGet_po()
{
    AlgoViewJob_s*  v_job_po;

    ME_Mutex_Lock_t(&condvar_s.MEMutex_po);

    while (algoViewJob_t.empty())
    {
        ME_Condvar_Wait_t(&condvar_s);
    }

    // get item from the list
    v_job_po = algoViewJob_t.front();
    algoViewJob_t.pop();

    ME_Mutex_UnLock_t(&condvar_s.MEMutex_po);

    return v_job_po;
}

/// @brief  Wait for job processing
bool_t  OVL3DData::algoViewJobWait_b(AlgoViewJob_s* i_job_po)
{
    bool_t  v_result_b = true;

    // wait for processing completion (mutex must be locked)
    ME_Condvar_Wait_t(i_job_po->condvar_po);

    if (i_job_po->sync_ppo != NULL)
    {
        //ME_Debugger_F_Printf_v("sync-wait %p(=%p) start...\n", i_job_po->sync_ppo, *i_job_po->sync_ppo);

        if (sync_wait(*i_job_po->sync_ppo, EGL_FOREVER_KHR) <= 0)
        {
            ME_Debugger_F_Printf_v("sync-wait %p(=%p) failed: %X\n", i_job_po->sync_ppo, *i_job_po->sync_ppo, eglGetError());

            v_result_b = false;
        }

        sync_destroy(*i_job_po->sync_ppo);
        *i_job_po->sync_ppo = NULL;
    }
    else
    {
        //ME_Condvar_Wait_t(i_job_po->condvar_po);
    }

    return v_result_b;
}

/// @brief  Create generic algo-view
algo_view_t* OVL3DData::algoViewCreate_po(char* i_id_pc, algo_view_type_t i_type_e, uint32_t& o_width_u32, uint32_t& o_height_u32)
{
    // wait for OVL3D bring-up
    waitReady_v();

    // create generic algo-view
    return algo_view_create(cfg_po, i_id_pc, i_type_e, reinterpret_cast<int*>(&o_width_u32), reinterpret_cast<int*>(&o_height_u32));
}

/// @brief  Destroy algo-view
void    OVL3DData::algoViewDestroy_po(algo_view_t* i_algo_po)
{
    algo_view_destroy(i_algo_po);
}

/// @brief  Create Fisheye-Y AlgoView processor
algo_view_t* OVL3DData::algoViewFisheyeYCreate_po(uint32_t i_width_u32, uint32_t i_height_u32)
{
    // wait for OVL3D bring-up
    waitReady_v();

    // create algo-view data
    return algo_fisheye_y_create(cfg_po, i_width_u32, i_height_u32);
}

/// @brief  Create Rear-Cylindric AlgoView processor
algo_view_t* OVL3DData::algoViewRearCylindricCreate_po(uint32_t i_width_u32, uint32_t i_height_u32)
{
    // wait for OVL3D bring-up
    waitReady_v();

    // create algo-view data
    return algo_cylindrical_rgb_create(cfg_po, i_width_u32, i_height_u32);
}

/// @brief  Create Top-View AlgoView processor
algo_view_t*  OVL3DData::algoViewTopViewCreate_po(uint32_t i_width_u32, uint32_t i_height_u32)
{
    // wait for OVL3D bring-up
    waitReady_v();

    // create algo-view data
    return algo_tv_y_create(cfg_po, i_width_u32, i_height_u32);
}

/// @brief  Wait for readiness
void  OVL3DData::waitReady_v()
{
    ME_Mutex_Lock_t(&condvar_s.MEMutex_po);

    while (cfg_po == NULL)
    {
        ME_Condvar_Wait_t(&condvar_s);
    }

    ME_Mutex_UnLock_t(&condvar_s.MEMutex_po);
}

uint32_t OVL3DData::getOVL3DRuntime(void)
{
    uint32_t v_DataCopy_u32 = 0;
    mutex_o.take_b();
    v_DataCopy_u32 = m_OVL3D_rt_data;
    mutex_o.give_v();

    return v_DataCopy_u32;  
}

void OVL3DData::setOVL3DRuntime(uint32_t u_Runtime_u32)
{
    mutex_o.take_b();
    m_OVL3D_rt_data = u_Runtime_u32;
    mutex_o.give_v();
}

uint32_t OVL3DData::getRenderThreadRuntime(void)
{
    uint32_t v_DataCopy_u32 = 0;
    mutex_o.take_b();
    v_DataCopy_u32 = m_RenderThrd_rt_data;
    mutex_o.give_v();

    return v_DataCopy_u32;  
}

void OVL3DData::setRenderThreadRuntime(uint32_t u_Runtime_u32)
{
    mutex_o.take_b();
    m_RenderThrd_rt_data = u_Runtime_u32;
    mutex_o.give_v();
}

uint32_t OVL3DData::getAlgoViewRuntime(void)
{
    uint32_t v_DataCopy_u32 = 0;
    mutex_o.take_b();
    v_DataCopy_u32 = m_AlgoViewThrd_rt_data;
    mutex_o.give_v();

    return v_DataCopy_u32;  
}

void OVL3DData::setAlgoViewRuntime(uint32_t u_Runtime_u32)
{
    mutex_o.take_b();
    m_AlgoViewThrd_rt_data = u_Runtime_u32;
    mutex_o.give_v();
}
} // namespace container
