#include "VertexBufferGL.h"

#include "OpenGL/GLIncludes.h"
#include "OpenGL/Device/DeviceGLTypes.h"


namespace me3d
{

VertexBufferGL::VertexBufferGL()
  : VertexBuffer()
  , bufferID_u32(0U)
{
}

VertexBufferGL::~VertexBufferGL()
{
  // PRQA S 4261 2 // This function doesn't throw exceptions
  // PRQA S 4631 1 // This function doesn't throw exceptions
  release_v();
}

bool VertexBufferGL::create_b(RenderEngine* b_RenderEngine_po, const VertexBufferDesc_s& i_Desc_rs, const void* i_InitialData_pv /*= NULL*/)
{
  bool v_Success_b = VertexBuffer::create_b(b_RenderEngine_po, i_Desc_rs);

  if (true == v_Success_b)
  {
    // generate buffer id
    glGenBuffers(1, static_cast<GLuint*>(&bufferID_u32));
    Assert(getGLError_b() == false);

    // create vertex buffer via first bind
    glBindBuffer(GL_ARRAY_BUFFER, bufferID_u32);
    Assert(getGLError_b() == false);

    if (bufferID_u32 == 0U)
    {
      v_Success_b = false;
      Assert(false);
    }

    if (true == v_Success_b)
    {
      // copy initial data
      glBufferData(GL_ARRAY_BUFFER, desc_s.size_u32, i_InitialData_pv, getGLResourceUsage_e(i_Desc_rs.resourceUsage_e));
      Assert(getGLError_b() == false);
    }

  }
  else
  {
    v_Success_b = false;
    Assert(false);
  }

  return v_Success_b;
}

void VertexBufferGL::release_v()
{
  VertexBuffer::release_v();

  if (bufferID_u32 != 0U)
  {
    glDeleteBuffers(1, static_cast<GLuint*>(&bufferID_u32));
    Assert(getGLError_b() == false);

    bufferID_u32 = 0U;
  }
}

void VertexBufferGL::bind_v() const
{
  Assert(bufferID_u32 != 0U);
  glBindBuffer(GL_ARRAY_BUFFER, bufferID_u32);
  Assert(getGLError_b() == false);
}

uint32_t VertexBufferGL::getID_u32() const
{
  return bufferID_u32;
}

void VertexBufferGL::updateSubData_v(uint32_t i_Offset_u32, uint32_t i_Size_u32, const void* i_Data_pv)
{
  bind_v();

  glBufferSubData(GL_ARRAY_BUFFER, i_Offset_u32, i_Size_u32, i_Data_pv);
  Assert(getGLError_b() == false);
}

} // namespace me3d