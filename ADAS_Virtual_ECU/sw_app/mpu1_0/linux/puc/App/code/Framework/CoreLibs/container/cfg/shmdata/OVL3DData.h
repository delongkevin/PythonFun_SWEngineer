//--------------------------------------------------------------------------
/// @file OVL3DData.h
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_OVL3D_DATA_H
#define CONTAINER_OVL3D_DATA_H

#include <osal/threading/Mutex.h>

#include "container/DataContainer.h"

#include <logging/Logger.h>

#include "bsp/io/tiovx/TIOVXHost.h"

#include "../../../Apps/OVL3DIntgr/sv/inc/sv_api.h"

/// @brief	AlgoView job descriptor
struct AlgoViewJob_s
{
    // Algo-view handle
    algo_view_t*        algoView_po;

    // Conditional variable for notification
    Condvar_s*          condvar_po;

    // Output textures array
    texture_data_t**    output_apo;

    // Synchronization object
    sync_data_t**       sync_ppo;

    //added for DLD
    uint32_t           timestamp_us;

};

namespace container
{

class OVL3DData : public DataContainer
{
public:

    OVL3DData();

    virtual ~OVL3DData();

public:
    /// @brief  Initialize shared data
    bool_t          init_b(cfg_data_t* i_cfg_po, screen_context_t i_screen_pv);

    /// @brief  Wait for a new input frame
    bool_t          waitFrame_b(uint32_t& io_frameNum_u32);

    /// @brief  Get latest Frame Number
    void            updateFrame_v(uint32_t& io_frameNum_u32);
    
    /// @brief  Notify input frame latching
    void            notifyFrame_v(uint32_t i_frameNum_u32);

    /// @brief Prepare buffers for operation
    bool_t          algoViewBuffersPrepare_b(bsp::VideoInputBufferDesc2_t& i_desc_ro, texture_data_t** o_texture_apo);

    /// @brief  Create generic fisheye view
    algo_view_t*    algoViewCreate_po(char* i_id_pc, algo_view_type_t i_type_e, uint32_t& o_width_u32, uint32_t& o_height_u32);

    /// @brief  Destroy algo-view
    void            algoViewDestroy_po(algo_view_t* i_algo_po);

    /// @brief  Create Fisheye-Y AlgoView processor
    algo_view_t*    algoViewFisheyeYCreate_po(uint32_t i_width_u32, uint32_t i_height_u32);

    /// @brief Create Rear-TV AlgoView processor
    algo_view_t*    algoViewRearTvCreate_po(uint32_t i_width_u32, uint32_t i_height_u32);

    /// @brief  Create Rear-Cylindric AlgoView processor
    algo_view_t*    algoViewRearCylindricCreate_po(uint32_t i_width_u32, uint32_t i_height_u32);

    /// @brief  Create Top-View AlgoView processor
    algo_view_t*    algoViewTopViewCreate_po(uint32_t i_width_u32, uint32_t i_height_u32);

    /// @brief  Submit job for execution
    bool_t          algoViewJobSubmit_b(AlgoViewJob_s* i_job_po);

    /// @brief  Retrieve next pending job
    AlgoViewJob_s*  algoViewJobGet_po();

    /// @brief  Wait for job processing
    bool_t          algoViewJobWait_b(AlgoViewJob_s* i_job_po);
    uint32_t getOVL3DRuntime(void);

    void setOVL3DRuntime(uint32_t u_Runtime_u32);

    uint32_t getRenderThreadRuntime(void);

    void setRenderThreadRuntime(uint32_t u_Runtime_u32);

    uint32_t getAlgoViewRuntime(void);
    void setAlgoViewRuntime(uint32_t u_Runtime_u32);

private:

    /// @brief  Algo-view jobs list
    std::queue<AlgoViewJob_s*>      algoViewJob_t;

    /// @brief  Global configuration pointer
    cfg_data_t*                     cfg_po;

    /// @brief  Screen context handle
    screen_context_t                screen_pv;

    /// @brief  Asynchronous notification object
    Condvar_s                       condvar_s;

    /// @brief  Frame-trigger notification object
    Condvar_s                       frameTrigger_s;

    /// @brief  Current intput frame number
    uint32_t                        frameNumber_u32;

    /// @brief  Wait for readiness
    void            waitReady_v();
    osal::Mutex mutex_o;

    uint32_t m_OVL3D_rt_data;
    uint32_t m_RenderThrd_rt_data;
    uint32_t m_AlgoViewThrd_rt_data;
};

} // namespace container

#endif // CONTAINER_OVL3D_DATA_H
