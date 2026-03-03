//--------------------------------------------------------------------------                                                                                                           
/// @file ResourceTypes.h                                                                         
/// @brief Defines the different Resources used by the ResourceHandler
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef ME3D_RESOURCES_H
#define ME3D_RESOURCES_H

#include "Common/Model/ModelTypes.h"
#include "Common/GUI/FontTypes.h"
#include "Common/Device/Device3DTypes.h"
#include "Utilities/InOut.h"
#include "RenderEngineCfg.h"
#include "Common/ResourceHandler/ResourceTypes.h"

// PRQA S 2100 EOF // public members used here by design.
// PRQA S 5118 EOF // autosar c++14 standard permits

namespace me3d
{
  struct Resource_s
  {
    ResourceType_e resourceType_e;
    ResourceID_t   resourceID_t;

    explicit Resource_s(ResourceType_e i_Type_e)
      : resourceType_e(i_Type_e)
      , resourceID_t(c_InvalidResourceID_u32)
    {
    }

    virtual ~Resource_s()
    {

    }

    void serialize_v(InOut& b_IO_ro)
    {
      b_IO_ro.serializeEnum_v(resourceType_e);
      b_IO_ro.serialize_v(resourceID_t);

      onSerialize_v(b_IO_ro);
    }

    virtual void release_v() = 0;
    // get resource name, no extension
    virtual const MEString& getResourceName_ro() = 0;

  protected:
    virtual void onSerialize_v(InOut& b_IO_ro) = 0;
  };

  struct TextureResource_s : Resource_s
  {
    TextureDesc_s texDesc_s;
    uint8_t*      data_pu8;
    uint32_t      dataSize_u32;

    TextureResource_s() 
      : Resource_s(e_ResourceTypeTexture) 
      , texDesc_s()
      , data_pu8(NULL)
      , dataSize_u32(0U)
    { 
    }

    virtual void release_v()
    {
      if (NULL != data_pu8)
      {
        delete[] data_pu8;
        data_pu8 = NULL;
      }

      dataSize_u32 = 0U;
    }

    virtual const MEString& getResourceName_ro() { return texDesc_s.fileName_o; }

  protected:
    virtual void onSerialize_v(InOut& b_IO_ro) ME_OVERRIDE
    {
      // only serialize filename, we will load special KTX file format.
      //b_IO_ro.serialize_v(texDesc_s.fileName_o);

      texDesc_s.serialize_v(b_IO_ro);


      b_IO_ro.serialize_v(dataSize_u32);
      // TODO: 
      //Texture::getImageSize_u32(texDesc_s.width_u32, texDesc_s.height_u32, texDesc_s.depth_u32, texDesc_s.format_e);

      // allocate memory for image data
      //uint32_t v_Size_u32 = texDesc_s.getSize_u32();
      if (b_IO_ro.isLoading_b())
      {
        data_pu8 = new uint8_t[dataSize_u32];
        Assert(NULL != data_pu8);
      }

      // serialize image data
      b_IO_ro.serializeFixedArray_v(data_pu8, dataSize_u32);
    }
  };

  struct ModelResource_s : Resource_s
  {
    ModelDesc_s desc_s;

    ModelResource_s() 
      : Resource_s(e_ResourceTypeModel)
      , desc_s()
    { 
    }

    virtual void release_v()
    {
    }

    virtual const MEString& getResourceName_ro() { return desc_s.fileName_o; }

  protected:
    virtual void onSerialize_v(InOut& b_IO_ro) ME_OVERRIDE
    {
      desc_s.serialize_v(b_IO_ro);
    }

  };

  struct FontResource_s : Resource_s
  {

    MEString          fileName_o;
    CharacterInfo_s*  characters_ps;
    uint32_t          numCharacters_u32;
    uint32_t          width_u32;
    uint32_t          height_u32;

    FontResource_s()
      : Resource_s(e_ResourceTypeFont)
      , fileName_o("")
      , characters_ps(NULL)
      , numCharacters_u32(0U)
      , width_u32(0U)
      , height_u32(0U)
    {
    }


    virtual void release_v()
    {
      if (NULL != characters_ps)
      {
        delete[] characters_ps;
        characters_ps = NULL;
      }
    }

    virtual const MEString& getResourceName_ro() { return fileName_o; }

  protected:
    virtual void onSerialize_v(InOut& b_IO_ro) ME_OVERRIDE
    {
      Assert(false);
    }
  };

  struct MaterialResource_s : Resource_s
  {
    MaterialDesc_s desc_s;

    MaterialResource_s()
    : Resource_s(e_ResourceTypeMaterial)
    , desc_s()
    {
    }

    virtual void release_v()
    {

    }

    virtual const MEString& getResourceName_ro() { return desc_s.name_o; }


  protected:
    virtual void onSerialize_v(InOut& b_IO_ro) ME_OVERRIDE
    {
      desc_s.serialize_v(b_IO_ro);
    }
  };

} // namespace me3d

#endif
