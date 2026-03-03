#include "RenderEngineGL.h"

#include "OpenGL/Device/DeviceGLES.h"
#include "OpenGL/Manager/ShaderManagerGL.h"
#include "OpenGL/Manager/TextureManagerGL.h"
#include "OpenGL/Manager/BufferManagerGL.h"


// PRQA S 5118 EOF // c++14 autosar standard permits

namespace me3d
{

RenderEngineGL::RenderEngineGL()
  : RenderEngine()
{

}

RenderEngineGL::~RenderEngineGL()
{

}

Device3D* RenderEngineGL::createDevice_po()
{
  return new DeviceGLES();
}

IManager* RenderEngineGL::createManager_po(ManagerType_e i_Type_e)
{
  IManager* v_Manager_po = NULL;

  switch (i_Type_e)
  {
    case e_MtBuffer:    { v_Manager_po = new BufferManagerGL();   break;    }
    case e_MtTexture:   { v_Manager_po = new TextureManagerGL();  break;    }
    case e_MtShader:    { v_Manager_po = new ShaderManagerGL();   break;	}
    case e_MtConstants: { v_Manager_po = NULL;                    break;	}
    case e_MtLight:     { v_Manager_po = NULL;                    break;	}
    case e_MtCamera:    { v_Manager_po = NULL;                    break;	}
    case e_MtMaterial:  { v_Manager_po = NULL;                    break;	}
    case e_MtModel:     { v_Manager_po = NULL;                    break;	}
    case e_MtView:      { v_Manager_po = NULL;                    break;	}
    case e_MtGui:       { v_Manager_po = NULL;                    break;	}
    case e_MtGuideLine: { v_Manager_po = NULL;                    break;	}
    case e_MtCount:     { v_Manager_po = NULL; Assert(false);     break;	}
  }

  if (NULL == v_Manager_po)
  {
    v_Manager_po = RenderEngine::createManager_po(i_Type_e);
  }

  Assert(NULL != v_Manager_po);
  return v_Manager_po;
}

} // namespace me3d


