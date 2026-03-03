// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Dec-2018]
// --- Last Modified by Joshua Teichroeb [17-Dec-2018]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __MEMORY_POOL__H_
#define __MEMORY_POOL__H_
#ifndef WIN_2015_CODE
    #include <common/Image.h>
    #include "osal/threading/mutex.h"
#else
    #include "Image.h"
#endif

#ifdef __QNX__
    #include <osal/threading/Mutex.h>
#endif

namespace memory
{
    /* Macros defining the max number of images to allocate space for. */
    const int32_t NUM_IMAGES_400x640_F32C1 = 0;
    const int32_t NUM_IMAGES_400x640_S32C1 = 0;
    const int32_t NUM_IMAGES_400x640_U32C1 = 0;
    const int32_t NUM_IMAGES_400x640_U8C1 = 0;
    const int32_t NUM_IMAGES_400x640_U8C3 = 0;


    const int32_t NUM_IMAGES_TOPVIEW_F32C1 = 0;
    const int32_t NUM_IMAGES_TOPVIEW_S32C1 = 0;
    const int32_t NUM_IMAGES_TOPVIEW_U32C1 = 4;
    const int32_t NUM_IMAGES_TOPVIEW_U16C1 = 4;
    const int32_t NUM_IMAGES_TOPVIEW_U8C1 = 20;
    const int32_t NUM_IMAGES_TOPVIEW_U8C3 = 0;

    const int32_t NUM_IMAGES_TEMPLATE_F32C1 = 0;
    const int32_t NUM_IMAGES_TEMPLATE_S32C1 = 0;
    const int32_t NUM_IMAGES_TEMPLATE_U32C1 = 0;
    const int32_t NUM_IMAGES_TEMPLATE_U8C1 = 14; // increased 1 for adding one extra trailer
    const int32_t NUM_IMAGES_TEMPLATE_U8C3 = 0;

    const int32_t MAX_NUM_IMAGES = 20;
    /**
    * Memory Block node used in class 'MemoryArena'.
    */
    struct MemoryBlock
    {
    private:
        uint8_t* m_data;
        bool_t m_free;
        MemoryBlock* m_nextBlock;
    public:
        MemoryBlock();
        explicit MemoryBlock( uint8_t* i_data );
        inline uint8_t* getM_Data() const
        {
            return m_data;
        }
        inline bool_t getM_Free() const
        {
            return m_free;
        }
        inline MemoryBlock* getM_NextBlock() const
        {
            return m_nextBlock;
        }
        inline void setM_Free( bool m_free_val )
        {
            m_free = m_free_val;
        }
        inline void setM_NextBlock( MemoryBlock* m_nextBlock_val )
        {
            m_nextBlock = m_nextBlock_val;
        }
        inline void setM_Data( uint8_t* m_data_val )
        {
            m_data = m_data_val;
        }
    };


    /**
    * Arena of memory blocks of a specific type/size. Has constant-time
    * allocating and freeing functions.
    */
    class MemoryArena
    {
    public:
        MemoryArena( uint32_t i_numBlocks, uint32_t i_blockSize, uint8_t* i_data );
        MemoryArena();
        ~MemoryArena();

        uint8_t* Grab();
        void Release( uint8_t* mar_block );

        void Init( uint32_t i_numBlocks, uint32_t i_blockSize, uint8_t& i_data );

        uint32_t MaxBlocksAllocated() const;
        uint32_t BlocksAllocated() const;
        uint32_t BlocksFree() const;
        uint8_t** getDataPtr( void ) const;

    private:
        uint32_t m_blockSize;
        uint32_t m_numBlocks;
        uint32_t m_numBlocksAllocated;
        uint32_t m_maxNumBlocksAllocated;
        uint8_t** m_dataptr;
        uint8_t* m_data;

        MemoryBlock m_blocks[memory::MAX_NUM_IMAGES];
        MemoryBlock* m_head;
#ifdef ME_PLATFORM_QNX
        osal::Mutex m_mutex;
#endif
    };

    /**
    * Singleton Memory Pool class to store images.
    */
    class MemoryPool
    {
    public:
        MemoryPool();
        ~MemoryPool();

        static bool_t Init();
        static bool_t Uninit();

        template<typename T>
        static image::Image<T> GetImage( itype::eImageType i_type, uint32_t i_width = 0, uint32_t i_height = 0, uint32_t i_numChannels = 0 );
        template<typename T>
        static void ReleaseImage( image::Image<T>& i_image );

        static int32_t ImagesAllocated( itype::eImageType i_type );
        static int32_t FreeImages( itype::eImageType i_type );
        static bool_t CheckForMemoryLeak();
        static void OutputMemoryPoolSize( const char* filename );

    private:
        MemoryArena m_mem[itype::IMTP_MAX_TYPES];

        static MemoryPool* s_instance;
    };
}
///------------------------------------------------------------------------------
/// MemoryPool template function definitions.
///------------------------------------------------------------------------------

/**
* Allocate an image block from the memory pool, of the specified type.
*
* Returns 'null' image if unsuccessful.
*/
template<typename T>
inline image::Image<T> memory::MemoryPool::GetImage( itype::eImageType i_type, uint32_t i_width, uint32_t i_height, uint32_t i_numChannels )
{
    image::Image<T> ret_val;
    bool_t isReturned = true;

    if( !s_instance )
    {
        ret_val = image::Image<T>();
        isReturned = false;
    }

    if( isReturned )
    {
        // --- Get copy of image type definition
        image::Image<T> gi_image = image::Image<T>( i_type );

        // --- Re-assign dimensions if necessary
        if( ( i_width != 0 ) || ( i_height != 0 ) || ( i_numChannels != 0 ) )
        {
            gi_image = image::Image<T>( i_width, i_height, NULL, i_numChannels, gi_image.getStep(), i_type );
        }

        // --- Get memory block
        gi_image.setData( reinterpret_cast<T*>( s_instance->m_mem[i_type].Grab() ) );
        assert( gi_image.getData() != NULL );
        ret_val = gi_image;
    }

    return ret_val;
}

/**
* Release the block of memory held by the given image to the memory pool.
*/
template<typename T>
inline void memory::MemoryPool::ReleaseImage( image::Image<T>& i_image )
{
    bool_t ret_val = true;

    if( !s_instance )
    {
        ret_val = false;
    }

    if( ret_val )
    {
        if( i_image.getType() < itype::IMTP_MAX_TYPES )
        {
            //This is freeing bytes of data so reinterpreting from other types is correct
            s_instance->m_mem[i_image.getType()].Release( reinterpret_cast<uint8_t*>( ( i_image.getData() ) ) ); //PRQA S 3017
            i_image.setData( NULL );
        }
    }

    return;
}

#endif // !__MEMORY_POOL__H_
