
#ifdef RE_USE_OPENGLES30

#include "RenderEngineGLES30.h"

#include "OpenGL/Device/DeviceGLES.h"

#include "OpenGL/Manager/ShaderManagerGL.h"
#include "OpenGL/Manager/BufferManagerGL.h"
#include "OpenGLES30/Manager/TextureManagerGLES30.h"


// PRQA S 5118 EOF // c++14 autosar standard permits

namespace me3d
{

  RenderEngineGLES30::RenderEngineGLES30()
    : RenderEngineGL()
  {

  }

  RenderEngineGLES30::~RenderEngineGLES30()
  {

  }


  IManager* RenderEngineGLES30::createManager_po(ManagerType_e i_Type_e)
  {
    IManager* v_Manager_po = NULL;

    switch (i_Type_e)
    {
    case e_MtBuffer:  v_Manager_po = new BufferManagerGL();   break;
    case e_MtTexture: v_Manager_po = new TextureManagerGLES30();  break;
    case e_MtShader:  v_Manager_po = new ShaderManagerGL();   break;
    }

    if (NULL == v_Manager_po)
    {
      v_Manager_po = RenderEngine::createManager_po(i_Type_e);
    }

    Assert(NULL != v_Manager_po);
    return v_Manager_po;
  }

} // namespace me3d

#endif // RE_USE_OPENGLES30
