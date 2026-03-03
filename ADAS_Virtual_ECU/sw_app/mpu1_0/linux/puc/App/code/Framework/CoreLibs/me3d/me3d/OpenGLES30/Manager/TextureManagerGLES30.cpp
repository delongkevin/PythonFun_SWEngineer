#ifdef RE_USE_OPENGLES30

#include "OpenGLES30/Manager/TextureManagerGLES30.h"
#include "OpenGLES30/Resources/TextureGLES30.h"
#include "OpenGL/Resources/RenderTargetGL.h"
#include "OpenGL/Resources/MultipleRenderTargetGL.h"


// PRQA S 5118 EOF // C++ 14 Autosar standard permits

namespace me3d
{

TextureManagerGLES30::TextureManagerGLES30()
  : TextureManagerGL()
{
}

TextureManagerGLES30::~TextureManagerGLES30()
{
}

Texture* TextureManagerGLES30::createTexture_po()
{
  // return special GLES 30 texture object with pixel buffer object support
  return new TextureGLES30();
}


} // namespace me3d


#endif // RE_USE_OPENGLES30