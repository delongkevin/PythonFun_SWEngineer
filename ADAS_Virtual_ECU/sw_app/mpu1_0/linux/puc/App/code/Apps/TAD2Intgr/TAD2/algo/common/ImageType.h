// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [20-Dec-2018]
// --- Last Modified by Joshua Teichroeb [Jul-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __IMAGE_TYPE__H_
#define __IMAGE_TYPE__H_

#ifdef __QNX__
    #include "mecl/mecl.h"
#else
    #include "MECL/mecl.h"
#endif
#include "Defines.h"

namespace itype
{
    /**
    * Memory Pool supported image types.
    */
    enum eImageType
    {
        IMTP_400x640_F32C1,
        IMTP_400x640_S32C1,
        IMTP_400x640_U32C1,
        IMTP_400x640_U8C1,
        IMTP_400x640_U8C3,
        IMTP_TopView_F32C1,
        IMTP_TopView_S32C1,
        IMTP_TopView_U32C1,
        IMTP_TopView_U16C1,
        IMTP_TopView_U8C1,
        IMTP_TopView_U8C3,
        IMTP_Template_F32C1,
        IMTP_Template_S32C1,
        IMTP_Template_U32C1,
        IMTP_Template_U8C1,
        IMTP_Template_U8C3,
        IMTP_MAX_TYPES,
        IMTP_ANY_TYPE
    };

    /**
    * Image type definition.
    */
    struct ImageTypeDef
    {
        inline uint32_t getWidth() const
        {
            return width;
        }

        inline uint32_t getHeight() const
        {
            return height;
        }

        inline uint32_t getnumChannels() const
        {
            return numChannels;
        }

        inline uint32_t getDataSize() const
        {
            return dataSize;
        }

        ImageTypeDef( uint32_t i_width, uint32_t i_height, uint32_t i_numChannels, uint32_t i_dataSize ) : width( i_width ), height( i_height ), \
            numChannels( i_numChannels ), dataSize( i_dataSize )
        {
        }
        ImageTypeDef() : width( 0 ), height( 0 ), numChannels( 0 ), dataSize( 0 )
        {
        }
    private:
        uint32_t    width;
        uint32_t    height;
        uint8_t     numChannels;
        uint32_t     dataSize;
    };
}

/// imtp
namespace imtp
{
    void init();

    // --- Functions defining the attributes of each image type
    uint32_t GetImageSizeBytes( itype::eImageType type );
    uint32_t GetImageWidth( itype::eImageType type );
    uint32_t GetImageHeight( itype::eImageType type );
    uint32_t GetImageNumChannels( itype::eImageType type );
    uint8_t GetImageDataTypeSize( itype::eImageType type );
} /// imtp

#endif // !__IMAGE_TYPE__H_
