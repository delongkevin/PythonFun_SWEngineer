
#ifndef _APP_DSS_M2M_MODULE
#define _APP_DSS_M2M_MODULE

#include "app_common.h"

#define DSS_M2M_WB_PIPE_INST_ID                     (0U)
#define DSS_M2M_PIPE_NUM                            (1U)
#define DSS_M2M_PIPE_INST_ID                        (3U)
/* Currently Only Overlay2 can be used for M2M operations,
   this can be changed through DSS initialization API available in vision_apps */
#define DSS_M2M_OVERLAY_ID                          (3U)

/* Channel configurations */
#define DSS_M2M_IN_FRAME_FORMAT                 (VX_DF_IMAGE_NV12)
#define DSS_M2M_IN_FRAME_WIDTH                  (1216U)
#define DSS_M2M_IN_FRAME_HEIGHT                 (900U)
#define DSS_M2M_IN_FRAME_BPP                    (1U)
#define DSS_M2M_IN_FRAME_PITCH                  (DSS_M2M_IN_FRAME_WIDTH * DSS_M2M_IN_FRAME_BPP)
#define DSS_M2M_OUT_FRAME_FORMAT                (VX_DF_IMAGE_YUYV)
#define DSS_M2M_OUT_FRAME_WIDTH                 (1216U)
#define DSS_M2M_OUT_FRAME_HEIGHT                (900)

typedef struct {
    uint32_t instId;
    uint32_t numPipe;
    uint32_t pipeId[TIVX_DISPLAY_M2M_MAX_PIPE];
    uint32_t overlayId;
    vx_df_image inFmt;
    uint32_t inWidth;
    uint32_t inHeight;
    uint32_t inBpp;
    uint32_t inPitch;
    vx_df_image outFmt;
    uint32_t outWidth;
    uint32_t outHeight;
    uint32_t posX;
    uint32_t posY;
} DssM2MObj;

#endif
