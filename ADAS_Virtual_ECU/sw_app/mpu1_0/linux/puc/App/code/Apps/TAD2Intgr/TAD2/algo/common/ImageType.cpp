// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [20-Dec-2018]
// --- Last Modified by Joshua Teichroeb [Jul-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
#include  "stdafx.h"
#endif
#include <ImageType.h>

namespace g_image
{
    static itype::ImageTypeDef g__imageTypeDefs[itype::IMTP_MAX_TYPES];
}

/*
* Initialize the definitions stored for each image type.
*/
void imtp::init()
{
    // --- 400x640
    g_image::g__imageTypeDefs[itype::IMTP_400x640_F32C1] = itype::ImageTypeDef( 640, 400, 1, 4 );
    g_image::g__imageTypeDefs[itype::IMTP_400x640_S32C1] = itype::ImageTypeDef( 640, 400, 1, 4 );
    g_image::g__imageTypeDefs[itype::IMTP_400x640_U32C1] = itype::ImageTypeDef( 640, 400, 1, 4 );
    g_image::g__imageTypeDefs[itype::IMTP_400x640_U8C1] = itype::ImageTypeDef( 640, 400, 1, 1 );
    g_image::g__imageTypeDefs[itype::IMTP_400x640_U8C3] = itype::ImageTypeDef( 640, 400, 3, 1 );
    // --- TopView
    g_image::g__imageTypeDefs[itype::IMTP_TopView_F32C1] = itype::ImageTypeDef( global::TOPVIEW_IMAGE_WIDTH, global::TOPVIEW_IMAGE_HEIGHT, 1, 4 );
    g_image::g__imageTypeDefs[itype::IMTP_TopView_S32C1] = itype::ImageTypeDef( global::TOPVIEW_IMAGE_WIDTH, global::TOPVIEW_IMAGE_HEIGHT, 1, 4 );
    g_image::g__imageTypeDefs[itype::IMTP_TopView_U32C1] = itype::ImageTypeDef( global::TOPVIEW_IMAGE_WIDTH, global::TOPVIEW_IMAGE_HEIGHT, 1, 4 );
    g_image::g__imageTypeDefs[itype::IMTP_TopView_U16C1] = itype::ImageTypeDef( global::TOPVIEW_IMAGE_WIDTH, global::TOPVIEW_IMAGE_HEIGHT, 1, 2 );
    g_image::g__imageTypeDefs[itype::IMTP_TopView_U8C1] = itype::ImageTypeDef( global::TOPVIEW_IMAGE_WIDTH, global::TOPVIEW_IMAGE_HEIGHT, 1, 1 );
    g_image::g__imageTypeDefs[itype::IMTP_TopView_U8C3] = itype::ImageTypeDef( global::TOPVIEW_IMAGE_WIDTH, global::TOPVIEW_IMAGE_HEIGHT, 3, 1 );
    // --- Template
    g_image::g__imageTypeDefs[itype::IMTP_Template_F32C1] = itype::ImageTypeDef( global::TEMPLATE_IMAGE_WIDTH, global::TEMPLATE_IMAGE_HEIGHT, 1, 4 );
    g_image::g__imageTypeDefs[itype::IMTP_Template_S32C1] = itype::ImageTypeDef( global::TEMPLATE_IMAGE_WIDTH, global::TEMPLATE_IMAGE_HEIGHT, 1, 4 );
    g_image::g__imageTypeDefs[itype::IMTP_Template_U32C1] = itype::ImageTypeDef( global::TEMPLATE_IMAGE_WIDTH, global::TEMPLATE_IMAGE_HEIGHT, 1, 4 );
    g_image::g__imageTypeDefs[itype::IMTP_Template_U8C1] = itype::ImageTypeDef( global::TEMPLATE_IMAGE_WIDTH, global::TEMPLATE_IMAGE_HEIGHT, 1, 1 );
    g_image::g__imageTypeDefs[itype::IMTP_Template_U8C3] = itype::ImageTypeDef( global::TEMPLATE_IMAGE_WIDTH, global::TEMPLATE_IMAGE_HEIGHT, 3, 1 );
}

/*
* Get the size of the given image type, in bytes.
*/
uint32_t imtp::GetImageSizeBytes( itype::eImageType type )
{
    return g_image::g__imageTypeDefs[type].getWidth() * g_image::g__imageTypeDefs[type].getHeight() * g_image::g__imageTypeDefs[type].getnumChannels() * g_image::g__imageTypeDefs[type].getDataSize();
}

/*
* Get the width of the given image type.
*/
uint32_t imtp::GetImageWidth( itype::eImageType type )
{
    return g_image::g__imageTypeDefs[type].getWidth();
}

/*
* Get the height of the given image type.
*/
uint32_t imtp::GetImageHeight( itype::eImageType type )
{
    return g_image::g__imageTypeDefs[type].getHeight();
}

/*
* Get the number of channels of the given image type.
*/
uint32_t imtp::GetImageNumChannels( itype::eImageType type )
{
    return g_image::g__imageTypeDefs[type].getnumChannels();
}

/*
* Get the size of type size of the given image type.
*/
uint8_t imtp::GetImageDataTypeSize( itype::eImageType type )
{
    return g_image::g__imageTypeDefs[type].getDataSize();
}
