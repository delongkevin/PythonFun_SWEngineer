#include "IndexBufferGL.h"

#include "OpenGL/Device/DeviceGLTypes.h"

namespace me3d
{

  IndexBufferGL::IndexBufferGL()
    : IndexBuffer()
    , bufferID_u32(0U)
  {
  }

  IndexBufferGL::~IndexBufferGL()
  {
    // PRQA S 4261 2 // This function doesn't throw exceptions
    // PRQA S 4631 1 // This function doesn't throw exceptions
    release_v();
  }

  bool_t IndexBufferGL::create_b(const IndexBufferDesc_s& i_Desc_rs, const void* i_InitialData_pv /*= NULL*/)
  {
    bool v_Success_b = IndexBuffer::create_b(i_Desc_rs);

    if (true == v_Success_b)
    {
      glGenBuffers(1, static_cast<GLuint*>(&bufferID_u32));
      Assert(getGLError_b() == false);

      // Create buffer via first binding
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID_u32);
      Assert(getGLError_b() == false);

      if (bufferID_u32 == 0U)
      {
        v_Success_b = false;
        Assert(false);
      }

      glBufferData(GL_ELEMENT_ARRAY_BUFFER, desc_s.size_u32, i_InitialData_pv, getGLResourceUsage_e(i_Desc_rs.resourceUsage_e));
      Assert(getGLError_b() == false);
    }

    return v_Success_b;
  }

  uint32_t IndexBufferGL::getID_u32() const
  {
    return bufferID_u32;
  }

  void IndexBufferGL::set_v()
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID_u32);
    Assert(getGLError_b() == false);
  }

  void IndexBufferGL::release_v()
  {
    IndexBuffer::release_v();

    if (bufferID_u32 != 0U)
    {
      glDeleteBuffers(1, static_cast<GLuint*>(&bufferID_u32));
      Assert(getGLError_b() == false);

      bufferID_u32 = 0U;
    }
  }


  void IndexBufferGL::updateSubData_v(uint32_t i_Offset_u32, uint32_t i_Size_u32, const void* i_Data_pv)
  {
    // bind buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID_u32);
    Assert(getGLError_b() == false);

    // update data
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, i_Offset_u32, i_Size_u32, i_Data_pv);
    Assert(getGLError_b() == false);
  }

} // namespace me3d
