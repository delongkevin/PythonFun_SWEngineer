//--------------------------------------------------------------------------
/// @file TIOVXVideoOutput.cpp
/// @brief Implementation of TIOVX Video Output interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
//  --------------------------------------------------------------------------

#include <platform/PlatformAPI.h>
#include "variants/VariantHelper.h"

#include <bsp/io/tiovx/TIOVXVideoOutput.h>

#include <logging/Logger.h>

#include <VX/vx.h>
#include <VX/vxu.h>
#include <VX/vx_khr_pipelining.h>
#include <TI/tivx_task.h>
#include <TI/tivx.h>
#include <TI/j7_csitx.h>
#include <TI/tivx_obj_desc.h>
#include <../../utils/include/tivx_utils_graph_perf.h>



class ImageGetter
{
    public:
        ImageGetter()
        {
            img = 0;
        }

        ImageGetter(vx_reference arr)
        {
            img = (vx_image)vxGetObjectArrayItem((vx_object_array)arr, 0);
        }

        ~ImageGetter()
        {
            vxReleaseImage(&img);            
        }

        void attach(vx_reference arr)
        {
            img = (vx_image)vxGetObjectArrayItem((vx_object_array)arr, 0);
        }

        vx_image get()
        {
            return img;
        }

        vx_reference* get_reference()
        {
            return (vx_reference*)&img;
        }

    private:
        ImageGetter(const ImageGetter&);
        ImageGetter& operator=(const ImageGetter&);

        vx_image img;
};

extern "C" {

// Private TI API that allows to get access to storage buffer
extern uint16_t ownReferenceGetObjDescId(vx_reference ref);

// internal TIOVX function
extern vx_status ownReferenceAllocMem(vx_reference ref);
}

namespace bsp
{

#undef USE_HDMI

#define POS_X               0
#define POS_Y               0
#define PIPE_ID             0

// Enable buffers order debugging
#define DEBUG_TEST_BUFFERS      0

// Timing debug
#define DEBUG_TIMING            1

extern "C" bool_t ME_VariantHelper_GetRadioDisp_b(uint8_t* radio_val);

/// @brief  Logging function
static bool_t log_b(logging::LogLevel_e i_level_e, const char *i_format_pc, ...)
{
    char        v_buffer_ac[256];
    va_list     v_args_pt;

    va_start(v_args_pt, i_format_pc);

    vsnprintf(v_buffer_ac, sizeof(v_buffer_ac) - 1, i_format_pc, v_args_pt);

    return logging::Logger::log_b(i_level_e, logging::e_LogModeMaskPrintf, "tiovx-output: %s\n", v_buffer_ac);
}

/*
 * Utility API used to add a graph parameter from a node, node parameter index
 */
static inline void add_graph_parameter_by_node_index(vx_graph graph, vx_node node, vx_uint32 node_parameter_index)
{
    vx_parameter    parameter = vxGetParameterByIndex(node, node_parameter_index);
    vx_status       status;

    if ((status = vxGetStatus((vx_reference)parameter)) != VX_SUCCESS)
    {
        log_b(logging::e_LogLvlError, "failed to get parameter-%u from node %p: %X", node_parameter_index, node, status);
    }

    status = vxAddParameterToGraph(graph, parameter);
    if (status != VX_SUCCESS)
    {
        log_b(logging::e_LogLvlError, "failed to add graph parameter-%u to node %p: %X", node_parameter_index, node, status);
    }

    log_b(logging::e_LogLvlDebug, "add param-%u: node=%p", node_parameter_index, node);

    vxReleaseParameter(&parameter);
}

vx_node TIOVXVideoOutput::tivxHwaDisplayM2M()
{
    ImageGetter getter_src(outputImage_apv[0]);
    ImageGetter getter_dst(outputImage_bpv[0]);
    vx_node m2m_node = 0;
    vx_user_data_object m2m_config;
    tivx_display_m2m_params_t local_m2m_config;
    vx_graph m2m_graph = 0;

    /* DSS M2M initialization */
    tivx_display_m2m_params_init(&local_m2m_config);
    local_m2m_config.instId     = 0;
    local_m2m_config.numPipe    = 1;
    local_m2m_config.pipeId[0U] = 3;
    local_m2m_config.overlayId  = 3;

    m2m_config = vxCreateUserDataObject(context_pv, "tivx_display_m2m_params_t", sizeof(tivx_display_m2m_params_t), &local_m2m_config);
    m2m_node = tivxDisplayM2MNode(display_pv, m2m_config, getter_src.get(), getter_dst.get());
    vxSetNodeTarget(m2m_node, VX_TARGET_STRING, TIVX_TARGET_DISPLAY_M2M1);

    vxReleaseUserDataObject(&m2m_config);

    return m2m_node;
}

/// @brief  Video output graph constructor
TIOVXVideoOutput::TIOVXVideoOutput()
    :resolutionVariant_u8(0)
{
    memset(&condvar_s, 0, sizeof(condvar_s));

    Assert(e_PeOk == ME_Condvar_Init_t(&condvar_s));

    initDone_b = false;
}

/// @brief  Video output graph destructor
TIOVXVideoOutput::~TIOVXVideoOutput()
{
}

/// @brief  Create display node
vx_status TIOVXVideoOutput::createDisplayNode()
{
    vx_status   v_status_t;

    uint32_t width_u32, height_u32;
    getResolutionInfo_v(width_u32, height_u32);

    // output buffers creation
    for (uint32_t v_bufId_u32 = 0U; v_bufId_u32 < c_MaxDispBuffer_u32; v_bufId_u32++)
    {
        outputImage_apv[v_bufId_u32] = (vx_reference)vxCreateImage(context_pv, width_u32, height_u32, TIVX_DF_IMAGE_BGRX);
        if ((v_status_t = vxGetStatus(outputImage_apv[v_bufId_u32])) != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "failed to create output-%u: %X", v_bufId_u32, v_status_t);
            return v_status_t;
        }

        // force buffer allocation right away
        if ((v_status_t = ownReferenceAllocMem(outputImage_apv[v_bufId_u32])) != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "failed to allocate output-%u: %X", v_bufId_u32, v_status_t);
            return v_status_t;
        }

        uint16_t                v_objID_u16 = ownReferenceGetObjDescId(outputImage_apv[v_bufId_u32]);
        tivx_obj_desc_image_t*  v_desc_po;
        tivxGetObjDescList(&v_objID_u16, (tivx_obj_desc_t **)&v_desc_po, 1);

        videoBuffer_apv[v_bufId_u32] = (uint8_t*)tivxMemShared2TargetPtr(&v_desc_po->mem_ptr[0]);
    }

    tivx_display_params_t   v_displayParams_t;
    memset(&v_displayParams_t, 0, sizeof(tivx_display_params_t));
    v_displayParams_t.opMode = TIVX_KERNEL_DISPLAY_ZERO_BUFFER_COPY_MODE;
    v_displayParams_t.pipeId = PIPE_ID;
    v_displayParams_t.outWidth = width_u32;
    v_displayParams_t.outHeight = height_u32;
    v_displayParams_t.posX = POS_X;//posX;
    v_displayParams_t.posY = POS_Y;//posY;

    vx_user_data_object     v_displayParamsObj_pv;
    v_displayParamsObj_pv = vxCreateUserDataObject(context_pv, "tivx_display_params_t", sizeof(tivx_display_params_t), &v_displayParams_t);
    if ((v_status_t = vxGetStatus((vx_reference)v_displayParamsObj_pv)) != VX_SUCCESS)
    {
        log_b(logging::e_LogLvlError, "failed to create display params: %X", v_status_t);
        return v_status_t;
    }

    displayNode_pv = tivxDisplayNode(display_pv, v_displayParamsObj_pv, (vx_image)outputImage_apv[0]);
    if ((v_status_t = vxGetStatus((vx_reference)displayNode_pv)) != VX_SUCCESS)
    {
        log_b(logging::e_LogLvlError, "displayNode create failed: %X", v_status_t);
        return v_status_t;
    }

    vxSetNodeTarget(displayNode_pv, VX_TARGET_STRING, TIVX_TARGET_DISPLAY1);
    vxSetReferenceName((vx_reference)displayNode_pv, "Display_node");
    vxReleaseUserDataObject(&v_displayParamsObj_pv);

    // add graph parameter
    add_graph_parameter_by_node_index(display_pv, displayNode_pv, 1);

    return v_status_t;
}

/// @brief  Create display node
vx_status TIOVXVideoOutput::createCsiTxNode()
{
    vx_status   v_status_t;

    uint32_t width_u32, height_u32;
    getResolutionInfo_v(width_u32, height_u32);

    // output buffers creation
    vx_image    v_sampleImage_pv;
    //v_sampleImage_pv = vxCreateImage(context_pv, width_u32, height_u32, VX_DF_IMAGE_RGBX);
	v_sampleImage_pv = vxCreateImage(context_pv, width_u32, height_u32, TIVX_DF_IMAGE_BGRX);
#if 1
    vx_image    v_sampleImage_bpv;
    v_sampleImage_bpv = vxCreateImage(context_pv, width_u32, height_u32, VX_DF_IMAGE_YUYV);
#endif

    for (uint32_t v_bufId_u32 = 0U; v_bufId_u32 < c_MaxDispBuffer_u32; v_bufId_u32++)
    {
        outputImage_apv[v_bufId_u32] = (vx_reference)vxCreateObjectArray(context_pv, (vx_reference)v_sampleImage_pv, 1);
        if ((v_status_t = vxGetStatus(outputImage_apv[v_bufId_u32])) != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "failed to create output-%u: %X", v_bufId_u32, v_status_t);
            return v_status_t;
        }

        // force buffer allocation right away
        if ((v_status_t = ownReferenceAllocMem((vx_reference)outputImage_apv[v_bufId_u32])) != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "failed to allocate output-%u: %X", v_bufId_u32, v_status_t);
            return v_status_t;
        }

        ImageGetter getter(outputImage_apv[v_bufId_u32]);
        vx_reference    v_outFrame_pv = *getter.get_reference();
        if ((v_status_t = vxGetStatus(v_outFrame_pv)) != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "%s: failed to get output frame-%u", "csiTx", v_bufId_u32);
            return v_status_t;
        }

        uint16_t                v_objID_u16 = ownReferenceGetObjDescId(v_outFrame_pv);
        tivx_obj_desc_image_t*  v_desc_po;
        tivxGetObjDescList(&v_objID_u16, (tivx_obj_desc_t **)&v_desc_po, 1);

        videoBuffer_apv[v_bufId_u32] = (uint8_t*)tivxMemShared2TargetPtr(&v_desc_po->mem_ptr[0]);

        logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                               "output buffer-%d: %d * %d: %p\n", v_bufId_u32,
                               v_desc_po->width, v_desc_po->height, videoBuffer_apv[v_bufId_u32]);
#if 1
        outputImage_bpv[v_bufId_u32] = (vx_reference)vxCreateObjectArray(context_pv, (vx_reference)v_sampleImage_bpv, 1);
        if ((v_status_t = vxGetStatus(outputImage_bpv[v_bufId_u32])) != VX_SUCCESS)
        {
            logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                                   "failed to create m2m output-%u: %X\n", v_bufId_u32, v_status_t);
            return v_status_t;
        }

        // force buffer allocation right away
        if ((v_status_t = ownReferenceAllocMem((vx_reference)outputImage_bpv[v_bufId_u32])) != VX_SUCCESS)
        {
            logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                                   "failed to allocate m2m output-%u: %X\n", v_bufId_u32, v_status_t);
            return v_status_t;
        }

        ImageGetter getter2(outputImage_bpv[v_bufId_u32]);
        vx_reference    v_outFrame_bpv = *getter2.get_reference();
        if ((v_status_t = vxGetStatus(v_outFrame_bpv)) != VX_SUCCESS)
        {
            logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                                   "%s: failed to get output m2m frame-%u\n", "DSS_M2M", v_bufId_u32);
            return v_status_t;
        }

        uint16_t                v_objID_b_u16 = ownReferenceGetObjDescId(v_outFrame_bpv);
        tivx_obj_desc_image_t*  v_desc_b_po;
        tivxGetObjDescList(&v_objID_b_u16, (tivx_obj_desc_t **)&v_desc_b_po, 1);

        videoBuffer_bpv[v_bufId_u32] = (uint8_t*)tivxMemShared2TargetPtr(&v_desc_b_po->mem_ptr[0]);

        logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                               "output m2m buffer-%d: %d * %d: %p\n", v_bufId_u32,
                               v_desc_b_po->width, v_desc_b_po->height, videoBuffer_bpv[v_bufId_u32]);
#endif
    }

    vx_node m2m_node = tivxHwaDisplayM2M();

    if (m2m_node)
    {
        add_graph_parameter_by_node_index(display_pv, m2m_node, 1);
        add_graph_parameter_by_node_index(display_pv, m2m_node, 2);
    }

    // CSITX Config initialization
    tivx_csitx_params_t     v_csiTxParams_t;
    tivx_csitx_params_init(&v_csiTxParams_t);

    
    v_csiTxParams_t.numInst                          = 1U;
    v_csiTxParams_t.numCh                            = 1U;
    v_csiTxParams_t.instId[0U]                       = 0U;
    v_csiTxParams_t.instCfg[0U].rxCompEnable         = (uint32_t)vx_true_e;
    v_csiTxParams_t.instCfg[0U].rxv1p3MapEnable      = (uint32_t)vx_true_e;
    v_csiTxParams_t.instCfg[0U].laneBandSpeed        = TIVX_CSITX_LANE_BAND_SPEED_390_TO_450_MBPS;
    v_csiTxParams_t.instCfg[0U].numDataLanes         = 2U;
    for (uint32_t v_loopCnt_u32 = 0U; v_loopCnt_u32 < v_csiTxParams_t.instCfg[0U].numDataLanes; v_loopCnt_u32++)
    {
        v_csiTxParams_t.instCfg[0U].lanePolarityCtrl[v_loopCnt_u32] = 0U;
    }

    for (uint32_t v_loopCnt_u32 = 0U; v_loopCnt_u32 < 1; v_loopCnt_u32++)
    {
        v_csiTxParams_t.chVcNum[v_loopCnt_u32] = v_loopCnt_u32;
        v_csiTxParams_t.chInstMap[v_loopCnt_u32] = 0U;
    }

    vx_user_data_object v_csiTxCfg_pv;
    v_csiTxCfg_pv = vxCreateUserDataObject(context_pv, "tivx_csitx_params_t", sizeof(tivx_csitx_params_t), &v_csiTxParams_t);
    if ((v_status_t = vxGetStatus((vx_reference)v_csiTxCfg_pv)) != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "failed to create CSI TX configuration: %X\n", v_status_t);
        return v_status_t;
    }

#if 0
    displayNode_pv = tivxCsitxNode(display_pv, v_csiTxCfg_pv, (vx_object_array)outputImage_apv[0]);
#else
    displayNode_pv = tivxCsitxNode(display_pv, v_csiTxCfg_pv, (vx_object_array)outputImage_bpv[0]);
#endif
    if ((v_status_t = vxGetStatus((vx_reference)displayNode_pv)) != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "failed to create CSI TX node: %X\n", v_status_t);
        return v_status_t;
    }

    vxSetNodeTarget(displayNode_pv, VX_TARGET_STRING, TIVX_TARGET_CSITX);
    vxSetReferenceName((vx_reference)displayNode_pv, "Display_node");
    vxReleaseUserDataObject(&v_csiTxCfg_pv);

    log_b(logging::e_LogLvlInfo, "CSI-TX display node created");

    return v_status_t;
}

/// @brief  Initialize output graph
bool_t TIOVXVideoOutput::initVideoOutput_b(vx_context i_context_pv)
{
    bool_t      v_result_b = true;
    vx_status   v_status_t;

    // create OpenVX context (no way to legally create a new reference? - tbd)
    context_pv = i_context_pv;

    // create output processing graph
    if (v_result_b == true)
    {
        display_pv = vxCreateGraph(context_pv);
        if ((v_status_t = vxGetStatus((vx_reference)display_pv)) != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "failed to create output graph: %X", v_status_t);
            v_result_b = false;
        }
    }

    // create display node
    if (v_result_b == true)
    {
#ifdef  USE_HDMI
        v_status_t = createDisplayNode();
#else
        v_status_t = createCsiTxNode();
#endif
        if (v_status_t != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "failed to create display node: %X", v_status_t);
            v_result_b = false;
        }
    }

    if (v_result_b == true)
    {
        // setup graph parameters
        vx_graph_parameter_queue_params_t   v_graphParamsQueue_ao[2];

        ImageGetter getter_apv0(outputImage_apv[0]);
        ImageGetter getter_apv1(outputImage_apv[1]);
        ImageGetter getter_apv2(outputImage_apv[2]);
        ImageGetter getter_bpv0(outputImage_bpv[0]);
        ImageGetter getter_bpv1(outputImage_bpv[1]);
        ImageGetter getter_bpv2(outputImage_bpv[2]);

        vx_image    outputImage_apv_img[c_MaxDispBuffer_u32] = {getter_apv0.get(), getter_apv1.get(), getter_apv2.get()};
        vx_image    outputImage_bpv_img[c_MaxDispBuffer_u32] = {getter_bpv0.get(), getter_bpv1.get(), getter_bpv2.get()};

        v_graphParamsQueue_ao[0].graph_parameter_index = 0;
        v_graphParamsQueue_ao[0].refs_list_size = c_MaxDispBuffer_u32;
        v_graphParamsQueue_ao[0].refs_list = (vx_reference*)outputImage_apv_img;

        v_graphParamsQueue_ao[1].graph_parameter_index = 1;
        v_graphParamsQueue_ao[1].refs_list_size = c_MaxDispBuffer_u32;
        v_graphParamsQueue_ao[1].refs_list = (vx_reference*)outputImage_bpv_img;

        tivxSetGraphPipelineDepth(display_pv, c_MaxDispBuffer_u32);

        // Schedule mode auto is used, here we don't need to call vxScheduleGraph
        // Graph gets scheduled automatically as refs are enqueued to it
        vxSetGraphScheduleConfig(display_pv, VX_GRAPH_SCHEDULE_MODE_QUEUE_AUTO
            , sizeof(v_graphParamsQueue_ao) / sizeof(v_graphParamsQueue_ao[0])
            , v_graphParamsQueue_ao);

        // verify graph operation
        if ((v_status_t = vxVerifyGraph(display_pv)) != VX_SUCCESS)
        {
            log_b(logging::e_LogLvlError, "graph verification failed: %X", v_status_t);
            v_result_b = false;
        }
        else
        {
            log_b(logging::e_LogLvlInfo, "display graph created");

            tivxExportGraphToDot(display_pv, (char*)"/tmp", (char*)"display");
        }
    }

    if (v_result_b == true)
    {
        // set preroll counter
        prerollCount_u32 = c_MaxDispBuffer_u32;

        // mark initialization is completed
        initDone_b = true;

        // signal instantly - do we need dedicated start/stop probably? - tbd
        ME_Condvar_Broadcast_t(&condvar_s);
    }

    return v_result_b;
}

/// @brief  Retrieve individual render buffer descriptor
uint8_t* TIOVXVideoOutput::getVideoOutputBuffer_b(uint32_t i_Index_u32)
{
    // wait for module initialization completion
    ME_Mutex_Lock_t(&condvar_s.MEMutex_po);
    while (initDone_b != true)
    {
        ME_Condvar_Wait_t(&condvar_s);
    }
    ME_Mutex_UnLock_t(&condvar_s.MEMutex_po);

    return videoBuffer_apv[i_Index_u32];
}

/// @brief  Wait until output buffer is available (frame triggered)
bool_t TIOVXVideoOutput::waitFrameBuffer_b(uint32_t& o_bufferIdx_u32, uint64_t* o_timestamp_pu64)
{
    vx_status       v_status_t;
    vx_reference    v_outputImage_pv  = NULL;
    vx_reference    v_outputImage_pv1 = NULL;
    vx_reference    v_outputImage_pv2 = NULL;
    vx_uint32       v_numRefs_t;

    if (prerollCount_u32 == 0)
    {
        // Get output reference; wait for buffer availablity
        v_status_t = vxGraphParameterDequeueDoneRef(display_pv, 0, &v_outputImage_pv1, 1, &v_numRefs_t);
        v_status_t |= vxGraphParameterDequeueDoneRef(display_pv, 1, &v_outputImage_pv2, 1, &v_numRefs_t);

        if (v_status_t != VX_SUCCESS)
        {
            ME_Debugger_F_Printf_v("failed to dequeue output buffer: %X", v_status_t);
            return false;
        }
#ifndef USE_HDMI
        uint16_t                v_objID_u16 = ownReferenceGetObjDescId(v_outputImage_pv2);
        tivx_obj_desc_t*        v_desc_po;
        tivxGetObjDescList(&v_objID_u16, &v_desc_po, 1);
        (o_timestamp_pu64 ? *o_timestamp_pu64 = v_desc_po->timestamp : 0);

        v_outputImage_pv = v_outputImage_pv2;
#else
        uint16_t                v_objID_u16 = ownReferenceGetObjDescId(v_outputImage_pv);
        tivx_obj_desc_t*        v_desc_po;
        tivxGetObjDescList(&v_objID_u16, &v_desc_po, 1);
        (o_timestamp_pu64 ? *o_timestamp_pu64 = v_desc_po->timestamp : 0);
#endif
    }
    else
    {
        // Graph is not running yet; decrement preroll counter (here or at submission? - tbd)
        prerollCount_u32--;
        (o_timestamp_pu64 ? *o_timestamp_pu64 = 0UL : 0);
    }

    // compare buffer index validity
    if (DEBUG_TEST_BUFFERS && v_outputImage_pv != NULL)
    {
        uint16_t                v_objID_u16 = ownReferenceGetObjDescId(v_outputImage_pv);
        tivx_obj_desc_image_t*  v_desc_po;
        tivxGetObjDescList(&v_objID_u16, (tivx_obj_desc_t **)&v_desc_po, 1);

        void*       v_bufAddr_pv = tivxMemShared2TargetPtr(&v_desc_po->mem_ptr[0]);
        uint32_t    v_bufId_u32;

        log_b(logging::e_LogLvlInfo, "output-buf: %p", v_bufAddr_pv);

        for (v_bufId_u32 = 0U; v_bufId_u32 < c_MaxDispBuffer_u32; v_bufId_u32++)
        {
            if (v_bufAddr_pv == videoBuffer_apv[v_bufId_u32])
                break;
        }

        // check buffer index is sane
        if (v_bufId_u32 < c_MaxDispBuffer_u32)
        {
            if (v_bufId_u32 != readBufferIdx_u32)
            {
                log_b(logging::e_LogLvlError, "display-buf: %u != %u", v_bufId_u32, readBufferIdx_u32);
            }
            else
            {
                log_b(logging::e_LogLvlInfo, "display-buf: %u", v_bufId_u32);
            }
        }
        else
        {
            log_b(logging::e_LogLvlError, "buffer not found");
        }
    }

    // Get index of the buffer that should be filled
    ME_Mutex_Lock_t(&condvar_s.MEMutex_po);
    o_bufferIdx_u32 = readBufferIdx_u32;
    readBufferIdx_u32 = (readBufferIdx_u32 + 1) % c_MaxDispBuffer_u32;
    ME_Mutex_UnLock_t(&condvar_s.MEMutex_po);

    return true;
}

/// @brief  Submit buffer for visualization
bool_t TIOVXVideoOutput::submitBuffer_b()
{
    uint32_t    v_bufferIdx_u32;
    vx_status   v_status_t;

    // Get index of the buffer that we have just filled
    ME_Mutex_Lock_t(&condvar_s.MEMutex_po);
    v_bufferIdx_u32 = writeBufferIdx_u32;
    writeBufferIdx_u32 = (writeBufferIdx_u32 + 1) % c_MaxDispBuffer_u32;
    ME_Mutex_UnLock_t(&condvar_s.MEMutex_po);

    if (DEBUG_TIMING)
    {
        static uint32_t s_lastTimestamp_u32;
        static uint32_t s_deltaAcc_u32;
        static uint32_t s_counter_u32;

        uint32_t        v_timestamp_u32 = __get_time_usec();
        uint32_t        v_delta_u32 = (s_lastTimestamp_u32 ? v_timestamp_u32 - s_lastTimestamp_u32 : 0);

        s_lastTimestamp_u32 = v_timestamp_u32;

        if (v_delta_u32 > 66 * 1000)
        {
            log_b(logging::e_LogLvlInfo, "output buffer delay: %u", v_delta_u32);
        }

        if (s_deltaAcc_u32 == 0)
        {
            s_deltaAcc_u32 = v_delta_u32 << 4;
        }
        else
        {
            s_deltaAcc_u32 += v_delta_u32 - ((s_deltaAcc_u32 + 8) >> 4);
        }

        if ((++s_counter_u32 & 31) == 0)
        {
            log_b(logging::e_LogLvlDebug, "average output period: %u", (s_deltaAcc_u32 + 8) >> 4);
        }
    }

    ImageGetter getter_apv(outputImage_apv[v_bufferIdx_u32]);
    ImageGetter getter_bpv(outputImage_bpv[v_bufferIdx_u32]);

    v_status_t  = vxGraphParameterEnqueueReadyRef(display_pv, 1, getter_bpv.get_reference(), 1);
    v_status_t |= vxGraphParameterEnqueueReadyRef(display_pv, 0, getter_apv.get_reference(), 1);
    if (v_status_t != VX_SUCCESS)
    {
        logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                               "failed to enqueue output buffer-%u: %X\n", v_bufferIdx_u32, v_status_t);
        return false;
    }
    else if (DEBUG_TEST_BUFFERS)
    {
        logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                               "%s: enqueue buffer-%u\n", "csiTx", v_bufferIdx_u32);
    }

    return true;
}


void TIOVXVideoOutput::getResolutionInfo_v(uint32_t& i_width_u32, uint32_t& i_height_u32)
{
    static const uint32_t resolution_table[10][2] = {{0,0},
        {1280, 768}, //1
        {1024, 768}, //2
        {1920, 1200}, //3
        {1200, 1920}, //4
        {1920, 720}, //5
        {1920, 1200}, //6
        {1200, 900}, //7
        {1920, 720}, //8
        {1024, 768}  //9
        };

    bool_t result_b = true;

    if (resolutionVariant_u8 == 0)
    {
        result_b = mutex_o.take_b();

        if (result_b == true)
        {
            /// double check after locking to prevent concurency issues
            if (resolutionVariant_u8 == 0)
            {
                result_b = ME_VariantHelper_GetRadioDisp_b(&resolutionVariant_u8);
                ME_Debugger_F_Printf_v("Resolution TYPE Recieved: %d\n",resolutionVariant_u8);
            }

            mutex_o.give_v();
        }

        if (result_b && (resolutionVariant_u8 != 2 && resolutionVariant_u8 != 9 && resolutionVariant_u8 != 7))
        {
            result_b = false;
        }

        if (result_b == false)
        {
            resolutionVariant_u8 = 7;
            ME_Debugger_F_Printf_v("Resolution TYPE Invalid! Default Type: %d Loaded\n",resolutionVariant_u8);
            logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf,
                                   "failed to get resolution variant: %u DEFAULT will be used", resolutionVariant_u8);
        }
        else
        {
            ME_Debugger_F_Printf_v("Resolution Type: %d Loaded\n",resolutionVariant_u8);
            logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf,
                                   "resolution variant is chosen: %u", resolutionVariant_u8);
        }
    }

    if (result_b == false)
    {
        /// in case of error return default resolution
        i_width_u32 = 1200;
        i_height_u32 = 900;
    }
    else
    {
        i_width_u32 = resolution_table[resolutionVariant_u8][0];
        i_height_u32 = resolution_table[resolutionVariant_u8][1];
    }
}

} // namespace bsp
