#include "IndexBuffer.h"

namespace me3d
{

IndexBuffer::IndexBuffer()
  : desc_s()
{
}

IndexBuffer::~IndexBuffer()
{
  // PRQA S 4261 2 // This function doesn't throw exceptions
  // PRQA S 4631 1 // This function doesn't throw exceptions
  release_v();
}

bool_t IndexBuffer::create_b(const IndexBufferDesc_s& i_Desc_rs, const void* i_InitialData_pv /*= NULL*/)
{
  release_v();

  desc_s    = i_Desc_rs;

  return true;
}

void IndexBuffer::release_v()
{
  // release map buffer
}

void IndexBuffer::set_v()
{
  
}

} // namespace me3d
