#include "TextureManager.h"

 

#include "Common/Resources/Texture.h"
#include "Common/ResourceHandler/ResourceHandler.h"
#include "Utilities/Directory.h"
#include "Utilities/FileUtils.h"

#ifdef USE_DIRECTORY_WATCHER

#endif
#include "Common/Resources/RenderTarget.h"
#include "Common/Resources/MultipleRenderTarget.h"
#include "Common/Device/Device3D.h"
#include "Common/RenderEngine.h"


// PRQA S 5118 EOF // C++ 14 Autosar standard permits
// PRQA S 1051 EOF // Directory Watcher is work in progress
// PRQA S 4244 EOF // This is how stl works
// PRQA S 3222 EOF // This is how stl is designed
// PRQA S 3233 EOF // used by design
// PRQA S 3840 EOF // fine here

namespace me3d
{

TextureManager::TextureManager()
  : IManager()
  , renderEngine_po(NULL)
{

}

TextureManager::~TextureManager()
{

}

bool_t TextureManager::isEnabled_b()
{
  return true;
}

bool TextureManager::create_b(RenderEngine* b_RenderEngine_po)
{
  renderEngine_po = b_RenderEngine_po;

#ifdef USE_DIRECTORY_WATCHER
  InitializeCriticalSection(&criticalSection_o);
  directoryWatcher.watchDirectory_v(Directory::getTexturePath_pc());
#endif

  return true;
}

void TextureManager::release_v()
{
  // Release Textures
  size_t v_NumTextures_t = textures.size();
  for (size_t v_I_t = 0U; v_I_t < v_NumTextures_t; ++v_I_t)
  {
    Texture* v_Texture_po = textures[v_I_t];

    v_Texture_po->release_v();

    delete v_Texture_po;
  }
  textures.clear();


  // Release multiple render targets
  size_t v_size = multipleRenderTargets.size();
  for (size_t v_I_t = 0; v_I_t < v_size; ++v_I_t)
  {
    if (multipleRenderTargets[v_I_t])
    {
      // Free resources
      multipleRenderTargets[v_I_t]->release_v();

      // And delete the render target
      delete multipleRenderTargets[v_I_t];
    }
  }
  multipleRenderTargets.clear();


  // Release render targets
  for (size_t v_I_t = 0U; v_I_t < renderTargets.size(); ++v_I_t)
  {
    RenderTarget* v_RenderTarget_po = renderTargets[v_I_t];

    v_RenderTarget_po->delete_v();

    delete v_RenderTarget_po;
  }
  renderTargets.clear();

}

void TextureManager::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{

}

void TextureManager::beginFrame_v()
{
#ifdef USE_DIRECTORY_WATCHER
//   EnterCriticalSection(&criticalSection_o);
// 
//   const char* v_File_pc = directoryWatcher.getChangedFile();
//   if (v_File_pc[0] != '\0')
//   {
//     MEString v_fullFileName_o(v_File_pc);
// 
//     MEString v_FileNameNoExt_o = FileUtils::getFileName_o(v_fullFileName_o, true, me3d::c_PathSeparator_c);
//     
//     Texture* texture = findTexture_po(v_FileNameNoExt_o);
//     if (NULL != texture)
//     {
//       tsdk::ImageLoader imgLoader;
//       if (imgLoader.load_b(v_fullFileName_o.getString_pc(), texture->hasAlpha_b()))
//       {
//         texture->updateData_v(imgLoader.getData_pu8());
//       }
//     }
//   }
// 
//   directoryWatcher.consumeChangedFile();
// 
//   LeaveCriticalSection(&criticalSection_o);
#endif


  // tick RenderTargets to check for resize-needs
  size_t v_NumRenderTargets_t = renderTargets.size();
  for (size_t v_RenderTarget_t = 0U; v_RenderTarget_t < v_NumRenderTargets_t; ++v_RenderTarget_t)
  {
    renderTargets[v_RenderTarget_t]->onBeginFrame_v();
  }
}

void TextureManager::preRender_v()
{

}

Texture* TextureManager::createTexture_po(const MEString& i_Name_ro)
{
  Texture* v_Texture_po = NULL;

  if (false == i_Name_ro.isEmpty_b())
  {  
    TextureResource_s* v_TexRes_ps = me3d::ResourceHandler::get_po()->findResourceByName_po<TextureResource_s>(i_Name_ro);
    if (NULL != v_TexRes_ps)
    {
      v_Texture_po = createTexture_po(v_TexRes_ps->texDesc_s, v_TexRes_ps->data_pu8);
    }
  }

  return v_Texture_po;
}

Texture* TextureManager::createTexture_po(const TextureDesc_s& i_Desc_rs, const uint8_t* i_InitalData_pu8)
{
  // make sure we have not yet created the texture, use find texture instead
  Texture* v_Texture_po = findTexture_po(i_Desc_rs.fileName_o);

  if (NULL == v_Texture_po)
  {
    v_Texture_po = createTexture_po();

    v_Texture_po->create_b(renderEngine_po, i_Desc_rs, i_InitalData_pu8);

    textures.push_back(v_Texture_po);
  }

  Assert(NULL != v_Texture_po);

  return v_Texture_po;
}

RenderTarget* TextureManager::createRenderTarget_po(const RenderTargetDesc_s& i_Desc_rs)
{
  RenderTarget* v_RenderTarget_po = findRenderTarget_po(i_Desc_rs.name_o);

  // Render Target with same name already exists?
  if (NULL == v_RenderTarget_po)
  {
    // No render target with same name exists, so create new target.
    v_RenderTarget_po = createRenderTarget_po();
    Assert(NULL != v_RenderTarget_po);

    // Create the render target and add to list
    if (v_RenderTarget_po->create_b(renderEngine_po, i_Desc_rs))
    {
      renderTargets.push_back(v_RenderTarget_po);
    }
    else
    {
      // Something went wrong.
      Assert(false);

      delete v_RenderTarget_po;
      v_RenderTarget_po = NULL;
    }
  }


  // increase reference count, we either found or created a new render target if nothing went wrong
  Assert(NULL != v_RenderTarget_po);
  if (NULL != v_RenderTarget_po)
  {
    v_RenderTarget_po->addRef_v();
  }

  return v_RenderTarget_po;
}

void TextureManager::releaseTexture_v(Texture* b_Texture_po)
{
  size_t v_NumTextures_t = textures.size();
  for (uint32_t v_Texture_t = 0U; v_Texture_t < v_NumTextures_t; ++v_Texture_t)
  {
    Texture* v_Current_po = textures[v_Texture_t];

    if (textures[v_Texture_t] == b_Texture_po)
    {
      v_Current_po->release_v();

      // Erase from the list (replace with last list element)
      textures[v_Texture_t] = textures.back();
      textures.pop_back();

      delete b_Texture_po;

      break;
    }
  }
}

Texture* TextureManager::findTexture_po(const MEString& i_Name_ro)
{
  Texture* v_FoundTexture_po = NULL;

  size_t v_NumTextures_t = textures.size();
  for (size_t v_Texture_t = 0U; v_Texture_t < v_NumTextures_t; ++v_Texture_t)
  {
    Texture* v_Current_po = textures[v_Texture_t];

    bool v_HasFileName_b  = (false == v_Current_po->getFilename_ro().isEmpty_b());
    bool v_SameFileName_b = (i_Name_ro == v_Current_po->getFilename_ro());
    bool v_HasValidId_b   = v_Current_po->isValid_b();

    if (v_HasFileName_b && v_SameFileName_b && v_HasValidId_b)
    {
      v_FoundTexture_po = v_Current_po;
      Assert(v_FoundTexture_po->isValid_b());
      break;
    }
  }

  return v_FoundTexture_po;
}

void TextureManager::releaseRenderTarget_v(RenderTarget* i_RenderTarget_po)
{
  if (NULL != i_RenderTarget_po)
  {
    bool_t v_NeedsDelete_b = false;

    size_t v_NumRenderTargets_t = renderTargets.size();

    for (size_t v_RenderTarget_t = 0U; v_RenderTarget_t < v_NumRenderTargets_t; ++v_RenderTarget_t)
    {
      // check if other references exist
      v_NeedsDelete_b = renderTargets[v_RenderTarget_t]->release_b();

      if (true == v_NeedsDelete_b)
      {
        // Erase from the list (replace with last list element)
        renderTargets[v_RenderTarget_t] = renderTargets.back();
        renderTargets.pop_back();

        break;
      }
    }

    if (true == v_NeedsDelete_b)
    {
      // TODO: Set all constants to null which reference this render target

      i_RenderTarget_po->delete_v();

      delete i_RenderTarget_po;
    }

  } // if render target exists
}

RenderTarget* TextureManager::findRenderTarget_po(const MEString& i_Name_ro)
{
  RenderTarget* v_RenderTarget_po = NULL;

  if (false == i_Name_ro.isEmpty_b())
  {
    size_t v_NumRenderTargets_t = renderTargets.size();

    for (size_t v_I_t = 0; v_I_t < v_NumRenderTargets_t; ++v_I_t)
    {
      RenderTarget* v_Current_po = renderTargets[v_I_t];

      if (v_Current_po->getDesc_rs().name_o == i_Name_ro)
      {
        v_RenderTarget_po = v_Current_po;
        break;
      }
    }

  }

  return v_RenderTarget_po;
}

MultipleRenderTarget* TextureManager::createMultipleRenderTarget_po(RenderTargetDesc_s** i_ColorDescs_pps, RenderTargetDesc_s* i_DepthDesc_ps)
{
  MultipleRenderTarget* v_MRT_po = createMultipleRenderTarget_po();

  if (false == v_MRT_po->create_b(renderEngine_po, i_ColorDescs_pps, i_DepthDesc_ps))
  {
    v_MRT_po->release_v();
    delete v_MRT_po;
    v_MRT_po = NULL;
  }
  else
  {
    multipleRenderTargets.push_back(v_MRT_po);
  }

  return v_MRT_po;
}

MultipleRenderTarget* TextureManager::createMultipleRenderTarget_po(RenderTargetDesc_s* i_ColorDesc_ps, RenderTargetDesc_s* i_DepthDesc_ps)
{
  RenderTargetDesc_s* v_ColorDescs_pas[MAX_MRT_COLOR_RTS];

  memset(v_ColorDescs_pas, 0, sizeof(RenderTargetDesc_s*) * MAX_MRT_COLOR_RTS);

  v_ColorDescs_pas[0] = i_ColorDesc_ps;

  return createMultipleRenderTarget_po(v_ColorDescs_pas, i_DepthDesc_ps);
}

MultipleRenderTarget* TextureManager::createMultipleRenderTarget_po(RenderTargetDesc_s* i_ColorDesc0_ps, RenderTargetDesc_s* i_ColorDesc1_ps, RenderTargetDesc_s* i_ColorDesc2_ps, RenderTargetDesc_s* i_ColorDesc3_ps, RenderTargetDesc_s* i_DepthDesc_ps)
{
  RenderTargetDesc_s* v_ColorDescs_pas[MAX_MRT_COLOR_RTS];

  memset(v_ColorDescs_pas, 0, sizeof(RenderTargetDesc_s*) * MAX_MRT_COLOR_RTS);

  v_ColorDescs_pas[0] = i_ColorDesc0_ps;
  v_ColorDescs_pas[1] = i_ColorDesc1_ps;
  v_ColorDescs_pas[2] = i_ColorDesc2_ps;
  v_ColorDescs_pas[3] = i_ColorDesc3_ps;

  return createMultipleRenderTarget_po(v_ColorDescs_pas, i_DepthDesc_ps);
}

void TextureManager::releaseMultipleRenderTarget_v(MultipleRenderTarget* i_MultipleRenderTarget_po)
{
  if (NULL != i_MultipleRenderTarget_po)
  {
    //Find render target in the render target list
	size_t v_size = multipleRenderTargets.size();
    for (size_t v_I_t = 0; v_I_t < v_size; v_I_t++)
    {
      if (multipleRenderTargets[v_I_t] == i_MultipleRenderTarget_po)
      {
        //Erase render target from the list (replace with last list element)
        multipleRenderTargets[v_I_t] = multipleRenderTargets.back();
        multipleRenderTargets.pop_back();

        break;
      }
    }

    //And delete the render target
    i_MultipleRenderTarget_po->release_v();
    delete i_MultipleRenderTarget_po;
  }

}

} // namespace me3d
