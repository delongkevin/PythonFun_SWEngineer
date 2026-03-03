// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [05-Dec-2018]
// --- Last Modified by Joshua Teichroeb [17-Dec-2018]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifdef _WIN32
    #include "stdafx.h"
#endif
#include "stdtad.h"
#include "MemoryPool.h"
#ifdef DIAGNOSTICS
    #include "db.h"
    #include "fo.h"
#endif


namespace block
{
    static uint8_t g__Block400x640_F32C1[4 * 1 * memory::NUM_IMAGES_400x640_F32C1 * 400 * 640 + 1];
    static uint8_t g__Block400x640_S32C1[4 * 3 * memory::NUM_IMAGES_400x640_S32C1 * 400 * 640 + 1];
    static uint8_t g__Block400x640_U32C1[4 * 1 * memory::NUM_IMAGES_400x640_U32C1 * 400 * 640 + 1];
    static uint8_t g__Block400x640_U8C1[1 * 1 * memory::NUM_IMAGES_400x640_U8C1 *  400 * 640 + 1];
    static uint8_t g__Block400x640_U8C3[1 * 3 * memory::NUM_IMAGES_400x640_U8C3 *  400 * 640 + 1];
    static uint8_t g__BlockTopView_F32C1[4 * 1 * memory::NUM_IMAGES_TOPVIEW_F32C1 * global::TOPVIEW_IMAGE_SIZE + 1];
    static uint8_t g__BlockTopView_S32C1[4 * 3 * memory::NUM_IMAGES_TOPVIEW_S32C1 * global::TOPVIEW_IMAGE_SIZE + 1];
    static uint8_t g__BlockTopView_U32C1[4 * 1 * memory::NUM_IMAGES_TOPVIEW_U32C1 * global::TOPVIEW_IMAGE_SIZE + 1];
    static uint8_t g__BlockTopView_U16C1[2 * 1 * memory::NUM_IMAGES_TOPVIEW_U16C1 * global::TOPVIEW_IMAGE_SIZE + 1];
    static uint8_t g__BlockTopView_U8C1[1 * 1 * memory::NUM_IMAGES_TOPVIEW_U8C1 * global::TOPVIEW_IMAGE_SIZE + 1];
    static uint8_t g__BlockTopView_U8C3[1 * 3 * memory::NUM_IMAGES_TOPVIEW_U8C3 * global::TOPVIEW_IMAGE_SIZE + 1];
    static uint8_t g__BlockTemplate_F32C1[4 * 1 * memory::NUM_IMAGES_TEMPLATE_F32C1 * global::TEMPLATE_IMAGE_SIZE + 1];
    static uint8_t g__BlockTemplate_S32C1[4 * 3 * memory::NUM_IMAGES_TEMPLATE_S32C1 * global::TEMPLATE_IMAGE_SIZE + 1];
    static uint8_t g__BlockTemplate_U32C1[4 * 1 * memory::NUM_IMAGES_TEMPLATE_U32C1 * global::TEMPLATE_IMAGE_SIZE + 1];
    static uint8_t g__BlockTemplate_U8C1[1 * 1 * memory::NUM_IMAGES_TEMPLATE_U8C1 * global::TEMPLATE_IMAGE_SIZE + 1];
    static uint8_t g__BlockTemplate_U8C3[1 * 3 * memory::NUM_IMAGES_TEMPLATE_U8C3 * global::TEMPLATE_IMAGE_SIZE + 1];

    static memory::MemoryPool g__memoryPool;
}
memory::MemoryPool* memory::MemoryPool::s_instance = NULL;


///------------------------------------------------------------------------------
/// MemoryBlock function definitions.
///------------------------------------------------------------------------------

/**
* Null constructor.
*/
memory::MemoryBlock::MemoryBlock() :
    m_data( NULL ),
    m_free( true ),
    m_nextBlock( NULL )
{
}

/**
* Regular constructor.
*/
memory::MemoryBlock::MemoryBlock( uint8_t* i_data ) :
    m_data( i_data ),
    m_free( true ),
    m_nextBlock( NULL )
{
}

///------------------------------------------------------------------------------
/// MemoryArena function definitions.
///------------------------------------------------------------------------------

/**
* Initializing constructor.
*/
memory::MemoryArena::MemoryArena( uint32_t i_numBlocks, uint32_t i_blockSize, uint8_t* i_data ) :
    m_blockSize( i_blockSize ),
    m_numBlocks( i_numBlocks ),
    m_numBlocksAllocated( 0 ),
    m_dataptr( &m_data ),
    m_data( i_data ),
    m_head( NULL )
#ifdef ME_PLATFORM_QNX
    , m_mutex()
#endif
{
}

/**
* Default Constructor.
*/
memory::MemoryArena::MemoryArena() :
    m_blockSize( 0 ),
    m_numBlocks( 0 ),
    m_numBlocksAllocated( 0 ),
    m_maxNumBlocksAllocated( 0 ),
    m_dataptr( &m_data ),
    m_data( NULL ),
    m_head( NULL )
#ifdef ME_PLATFORM_QNX
    , m_mutex()
#endif
{
}

/**
* Destructor.
*/
memory::MemoryArena::~MemoryArena()
{
}

/**
* Grab the block of memory at the top of the stack, and return its pointer.
*
* Return a null pointer if there are no free memory blocks.
*/
uint8_t* memory::MemoryArena::Grab()
{
#ifdef ME_PLATFORM_QNX
    m_mutex.take_b();
#endif
    uint8_t* ret_val;

    if( m_head != NULL )
    {
        uint8_t* mag_block = m_head->getM_Data();
        m_head->setM_Free( false );
        m_head = m_head->getM_NextBlock();
        m_numBlocksAllocated++;

        if( m_numBlocksAllocated > m_maxNumBlocksAllocated )
        {
            m_maxNumBlocksAllocated = m_numBlocksAllocated;
        }

#ifdef ME_PLATFORM_QNX
        m_mutex.give_v();
#endif
        ret_val = mag_block;
    }
    else
    {
#ifdef ME_PLATFORM_QNX
        m_mutex.give_v();
#endif
        ret_val = NULL;
    }

    return ret_val;
}

/**
* Release the block of memory pointed to by the given pointer.
*
* Does nothing if 'block' is not within the memory controlled by this arena,
* or if the block is already freed.
*/
void memory::MemoryArena::Release( uint8_t* mar_block )
{
#ifdef ME_PLATFORM_QNX
    m_mutex.take_b();
#endif
    int32_t ind = ( mar_block - m_data ) / m_blockSize; /*PRQA S 3705*/

    if( ( mar_block < m_data ) || ( mar_block >= ( m_data + m_blockSize * m_numBlocks ) ) || ( m_blocks[ind].getM_Free() ) ) /* PRQA S 3705*/
    {
    }
    else
    {
        // push block to top of stack
        memset( mar_block, 0, m_blockSize );
        m_blocks[ind].setM_Free( true );
        m_blocks[ind].setM_NextBlock( m_head );
        m_head = &m_blocks[ind];
        m_numBlocksAllocated--;
    }

#ifdef ME_PLATFORM_QNX
    m_mutex.give_v();
#endif
    return;
}

/**
* Initialize this arena.
*
* @param i_numBlocks    number of blocks this arena holds
* @param i_blockSize    size of each block of memory
* @param i_data         pointer to start of (i_numBlocks * i_blockSize) bytes of memory
*/
void memory::MemoryArena::Init( uint32_t i_numBlocks, uint32_t i_blockSize, uint8_t& i_data )
{
    if( i_numBlocks > memory::MAX_NUM_IMAGES )
    {
        assert( 0 );
    }

    m_numBlocks = i_numBlocks;
    m_blockSize = i_blockSize;

    if( i_numBlocks > 0 )
    {
        m_head = &m_blocks[0];

        // --- Initialize linked list of free blocks
        for( uint32_t i = 0; i < ( m_numBlocks - 1 ); i++ )
        {
            MemoryBlock* curBlock = &m_blocks[i];
            curBlock->setM_Data( &i_data + ( i * i_blockSize ) ); /* PRQA S 3705*/
            curBlock->setM_Free( true );
            curBlock->setM_NextBlock( &m_blocks[i + 1] );
        }

        MemoryBlock* tail = &m_blocks[i_numBlocks - 1];
        tail->setM_Data( &i_data + ( ( i_numBlocks - 1 ) * i_blockSize ) ); /* PRQA S 3705*/
        tail->setM_NextBlock( NULL );
    }
}
uint8_t** memory::MemoryArena::getDataPtr( void ) const
{
    return m_dataptr;
}

uint32_t memory::MemoryArena::MaxBlocksAllocated() const
{
    return m_maxNumBlocksAllocated;
}

/**
* Return the number of blocks allocated by this memory arena.
*/
uint32_t memory::MemoryArena::BlocksAllocated() const
{
    return m_numBlocksAllocated;
}

/**
* Return the number of free blocks in this memory arena.
*/
uint32_t memory::MemoryArena::BlocksFree() const
{
    return m_numBlocks - m_numBlocksAllocated;
}

///------------------------------------------------------------------------------
/// MemoryPool function definitions.
///------------------------------------------------------------------------------

/**
* Constructor.
*/
memory::MemoryPool::MemoryPool() : m_mem()
{
}

/**
* Destructor.
*/
memory::MemoryPool::~MemoryPool()
{
}

/**
* Initialize the memory pool.
*/
bool_t memory::MemoryPool::Init()
{
    bool_t ret_val;

    if( s_instance != NULL )
    {
        ret_val = true;
    }
    else
    {
        // --- Initialize image type definitions
        imtp::init();
        //
        s_instance = &block::g__memoryPool;
        // --- Init memory blocks
        // 400x640
        *s_instance->m_mem[itype::IMTP_400x640_F32C1].getDataPtr() = block::g__Block400x640_F32C1;
        s_instance->m_mem[itype::IMTP_400x640_F32C1].Init( memory::NUM_IMAGES_400x640_F32C1, imtp::GetImageSizeBytes( itype::IMTP_400x640_F32C1 ), *block::g__Block400x640_F32C1 );
        *s_instance->m_mem[itype::IMTP_400x640_S32C1].getDataPtr() = block::g__Block400x640_S32C1;
        s_instance->m_mem[itype::IMTP_400x640_S32C1].Init( memory::NUM_IMAGES_400x640_S32C1, imtp::GetImageSizeBytes( itype::IMTP_400x640_S32C1 ), *block::g__Block400x640_S32C1 );
        *s_instance->m_mem[itype::IMTP_400x640_U32C1].getDataPtr() = block::g__Block400x640_U32C1;
        s_instance->m_mem[itype::IMTP_400x640_U32C1].Init( memory::NUM_IMAGES_400x640_U32C1, imtp::GetImageSizeBytes( itype::IMTP_400x640_U32C1 ), *block::g__Block400x640_U32C1 );
        *s_instance->m_mem[itype::IMTP_400x640_U8C1].getDataPtr() = block::g__Block400x640_U8C1;
        s_instance->m_mem[itype::IMTP_400x640_U8C1].Init( memory::NUM_IMAGES_400x640_U8C1, imtp::GetImageSizeBytes( itype::IMTP_400x640_U8C1 ), *block::g__Block400x640_U8C1 );
        *s_instance->m_mem[itype::IMTP_400x640_U8C3].getDataPtr() = block::g__Block400x640_U8C3;
        s_instance->m_mem[itype::IMTP_400x640_U8C3].Init( memory::NUM_IMAGES_400x640_U8C3, imtp::GetImageSizeBytes( itype::IMTP_400x640_U8C3 ), *block::g__Block400x640_U8C3 );
        // TopView
        *s_instance->m_mem[itype::IMTP_TopView_F32C1].getDataPtr() = block::g__BlockTopView_F32C1;
        s_instance->m_mem[itype::IMTP_TopView_F32C1].Init( memory::NUM_IMAGES_TOPVIEW_F32C1, imtp::GetImageSizeBytes( itype::IMTP_TopView_F32C1 ), *block::g__BlockTopView_F32C1 );
        *s_instance->m_mem[itype::IMTP_TopView_S32C1].getDataPtr() = block::g__BlockTopView_S32C1;
        s_instance->m_mem[itype::IMTP_TopView_S32C1].Init( memory::NUM_IMAGES_TOPVIEW_S32C1, imtp::GetImageSizeBytes( itype::IMTP_TopView_S32C1 ), *block::g__BlockTopView_S32C1 );
        *s_instance->m_mem[itype::IMTP_TopView_U32C1].getDataPtr() = block::g__BlockTopView_U32C1;
        s_instance->m_mem[itype::IMTP_TopView_U32C1].Init( memory::NUM_IMAGES_TOPVIEW_U32C1, imtp::GetImageSizeBytes( itype::IMTP_TopView_U32C1 ), *block::g__BlockTopView_U32C1 );
        *s_instance->m_mem[itype::IMTP_TopView_U16C1].getDataPtr() = block::g__BlockTopView_U16C1;
        s_instance->m_mem[itype::IMTP_TopView_U16C1].Init( memory::NUM_IMAGES_TOPVIEW_U16C1, imtp::GetImageSizeBytes( itype::IMTP_TopView_U16C1 ), *block::g__BlockTopView_U16C1 );
        *s_instance->m_mem[itype::IMTP_TopView_U8C1].getDataPtr() = block::g__BlockTopView_U8C1;
        s_instance->m_mem[itype::IMTP_TopView_U8C1].Init( memory::NUM_IMAGES_TOPVIEW_U8C1, imtp::GetImageSizeBytes( itype::IMTP_TopView_U8C1 ), *block::g__BlockTopView_U8C1 );
        *s_instance->m_mem[itype::IMTP_TopView_U8C3].getDataPtr() = block::g__BlockTopView_U8C3;
        s_instance->m_mem[itype::IMTP_TopView_U8C3].Init( memory::NUM_IMAGES_TOPVIEW_U8C3, imtp::GetImageSizeBytes( itype::IMTP_TopView_U8C3 ), *block::g__BlockTopView_U8C3 );
        // Template
        *s_instance->m_mem[itype::IMTP_Template_F32C1].getDataPtr() = block::g__BlockTemplate_F32C1;
        s_instance->m_mem[itype::IMTP_Template_F32C1].Init( memory::NUM_IMAGES_TEMPLATE_F32C1, imtp::GetImageSizeBytes( itype::IMTP_Template_F32C1 ), *block::g__BlockTemplate_F32C1 );
        *s_instance->m_mem[itype::IMTP_Template_S32C1].getDataPtr() = block::g__BlockTemplate_S32C1;
        s_instance->m_mem[itype::IMTP_Template_S32C1].Init( memory::NUM_IMAGES_TEMPLATE_S32C1, imtp::GetImageSizeBytes( itype::IMTP_Template_S32C1 ), *block::g__BlockTemplate_S32C1 );
        *s_instance->m_mem[itype::IMTP_Template_U32C1].getDataPtr() = block::g__BlockTemplate_U32C1;
        s_instance->m_mem[itype::IMTP_Template_U32C1].Init( memory::NUM_IMAGES_TEMPLATE_U32C1, imtp::GetImageSizeBytes( itype::IMTP_Template_U32C1 ), *block::g__BlockTemplate_U32C1 );
        *s_instance->m_mem[itype::IMTP_Template_U8C1].getDataPtr() = block::g__BlockTemplate_U8C1;
        s_instance->m_mem[itype::IMTP_Template_U8C1].Init( memory::NUM_IMAGES_TEMPLATE_U8C1, imtp::GetImageSizeBytes( itype::IMTP_Template_U8C1 ), *block::g__BlockTemplate_U8C1 );
        *s_instance->m_mem[itype::IMTP_Template_U8C3].getDataPtr() = block::g__BlockTemplate_U8C3;
        s_instance->m_mem[itype::IMTP_Template_U8C3].Init( memory::NUM_IMAGES_TEMPLATE_U8C3, imtp::GetImageSizeBytes( itype::IMTP_Template_U8C3 ), *block::g__BlockTemplate_U8C3 );
        ret_val = true;
    }

    return ret_val;
}

bool_t memory::MemoryPool::Uninit()
{
    if( s_instance )
    {
        s_instance = NULL;
    }

    return true;
}

/**
* Return the total number of blocks allocated by the memory pool.
*/
int32_t memory::MemoryPool::ImagesAllocated( itype::eImageType i_type )
{
    int32_t ret_val;

    if( s_instance == NULL )
    {
        ret_val = -1;
    }
    else
    {
        ret_val = static_cast<int32_t>( s_instance->m_mem[i_type].BlocksAllocated() );
    }

    return ret_val;
}

/**
* Return the total number of free blocks in the memory pool.
*/
int32_t memory::MemoryPool::FreeImages( itype::eImageType i_type )
{
    int32_t ret_val;

    if( s_instance == NULL )
    {
        ret_val = -1;
    }
    else
    {
        ret_val = static_cast<int32_t>( s_instance->m_mem[i_type].BlocksFree() );
    }

    return ret_val;
}

bool_t memory::MemoryPool::CheckForMemoryLeak()
{
    bool_t result = false;

    for( int32_t i = 0; i < itype::IMTP_MAX_TYPES; i++ )
    {
        result = result || ( ImagesAllocated( static_cast<itype::eImageType>( i ) ) != 0 );
    }

    return result;
}
void memory::MemoryPool::OutputMemoryPoolSize( const char* filename )
{
    filename = filename;
#ifdef DIAGNOSTICS
    fo::filestream file = fo::getFileStream( filename );
    file << "Image Type" << ',' << "Num Images" << '\n';

    for( int32_t i = 0; i < itype::IMTP_MAX_TYPES; i++ )
    {
        file << i << ',' << s_instance->m_mem[i].MaxBlocksAllocated() << '\n';
    }

#endif
}

