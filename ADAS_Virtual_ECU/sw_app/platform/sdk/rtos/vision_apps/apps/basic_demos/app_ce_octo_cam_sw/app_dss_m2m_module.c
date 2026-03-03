
#include "app_dss_m2m_module.h"

DssM2MObj gTestParams;

static void tivxTask_m2m(vx_context context, DssM2MObj *testParams, vx_image in_image, vx_image out_image)
{
    vx_node m2m_node = 0;
//    vx_image in_image = 0;
//    vx_image out_image = 0;
    vx_user_data_object m2m_config;
    tivx_display_m2m_params_t local_m2m_config;
//    vx_imagepatch_addressing_t image_addr;
//    vx_rectangle_t rect;
    vx_graph m2m_graph = 0;
    vx_status status = VX_SUCCESS;

    m2m_graph = vxCreateGraph(context);
    if (vxGetStatus((vx_reference)m2m_graph) != VX_SUCCESS)
    {
        APP_PRINTF("m2m_graph create failed\n");
//        return VX_FAILURE;
    }

    /* allocate Input and Output frame refs */
//    in_image = vxCreateImage(context, testParams->inWidth, testParams->inHeight, testParams->inFmt);
//    out_image = vxCreateImage(context, testParams->outWidth, testParams->outHeight, testParams->outFmt),

#if 0
    image_addr.dim_x    = testParams->inWidth;
    image_addr.dim_y    = testParams->inHeight;
    image_addr.stride_x = testParams->inBpp;
    image_addr.stride_y = testParams->inPitch;
    image_addr.scale_x  = VX_SCALE_UNITY;
    image_addr.scale_y  = VX_SCALE_UNITY;
    image_addr.step_x   = 1;
    image_addr.step_y   = 1;
    rect.start_x        = 0;
    rect.start_y        = 0;
    rect.end_x          = testParams->inWidth;
    rect.end_y          = testParams->inHeight;

    /* Copy reference input image to input buffer */
    vxCopyImagePatch(in_image, &rect, 0, &image_addr,
                      NULL,//(void *)gTiovxCtDisplayArrayYUV422,
                     VX_WRITE_ONLY, VX_MEMORY_TYPE_HOST);
#endif

    /* DSS M2M initialization */
    tivx_display_m2m_params_init(&local_m2m_config);
    local_m2m_config.instId     = testParams->instId;
    /* Only one pipeline is supported */
    local_m2m_config.numPipe    = testParams->numPipe;
    local_m2m_config.pipeId[0U] = testParams->pipeId[0U];
    local_m2m_config.overlayId  = testParams->overlayId;

    m2m_config = vxCreateUserDataObject(context, "tivx_display_m2m_params_t",
                                        sizeof(tivx_display_m2m_params_t), &local_m2m_config);

    m2m_node = tivxDisplayM2MNode(m2m_graph, m2m_config, in_image, out_image);

    vxSetNodeTarget(m2m_node, VX_TARGET_STRING, TIVX_TARGET_DISPLAY_M2M1);

    status = vxVerifyGraph(m2m_graph);
    if(status != VX_SUCCESS)
    {
        printf("Graph: verify done failed...\n");
    }

    vxProcessGraph(m2m_graph); //??

    vxReleaseNode(&m2m_node);
//    vxReleaseImage(&in_image);
//    vxReleaseImage(&out_image);
    vxReleaseUserDataObject(&m2m_config);

    vxReleaseGraph(&m2m_graph);

//    printf("Graph: released...\n");
}

void tivxHwaDisplayM2M(vx_context context, vx_image in_image, vx_image out_image)
{
    DssM2MObj *testParams;

    if (vx_true_e == tivxIsTargetEnabled(TIVX_TARGET_DISPLAY_M2M1)) {
//        printf("Error: Target Display M2M1 already enabled....\n");
    }

    /* Initialize global test parameters structure to '0' */
    memset(&gTestParams, 0, sizeof(gTestParams));
    testParams         = &gTestParams;

    testParams->instId     = DSS_M2M_WB_PIPE_INST_ID;
    testParams->numPipe    = DSS_M2M_PIPE_NUM;
    /* Note: Directly assigning as only one pipe is supported currently */
    testParams->pipeId[0U] = DSS_M2M_PIPE_INST_ID;
    testParams->overlayId  = DSS_M2M_OVERLAY_ID;
    testParams->inFmt      = DSS_M2M_IN_FRAME_FORMAT;

    /* Initialize test parameters for task 0 */
    testParams->inWidth      = DSS_M2M_IN_FRAME_WIDTH;
    testParams->inHeight     = DSS_M2M_IN_FRAME_HEIGHT;
    testParams->inBpp        = DSS_M2M_IN_FRAME_BPP;
    testParams->inPitch      = DSS_M2M_IN_FRAME_PITCH;
    testParams->outFmt       = DSS_M2M_OUT_FRAME_FORMAT;
    testParams->outWidth     = DSS_M2M_OUT_FRAME_WIDTH;
    testParams->outHeight    = DSS_M2M_OUT_FRAME_HEIGHT;

    tivxTask_m2m(context, testParams, in_image, out_image);
}
