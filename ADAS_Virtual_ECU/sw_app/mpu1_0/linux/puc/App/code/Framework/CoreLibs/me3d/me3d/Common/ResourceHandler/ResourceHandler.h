//--------------------------------------------------------------------------                                                                                                           
/// @file ResourceHandler.h                                                                         
/// @brief Used to register resources like textures, fonts, models or materials
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 


// PRQA S 1051 EOF // Still working on this feature
// PRQA S 5118 EOF // Autosar c++14 standard permits

#ifndef RESOURCE_HANDLER_H
#define RESOURCE_HANDLER_H

#include "RenderEngineCfg.h"
#include "Common/Model/ModelTypes.h"
#include "Common/Materials/Material.h"
#include "Common/Device/Device3DTypes.h"
#include "Common/ResourceHandler/ResourceTypes.h"
#include "Common/ResourceHandler/Resources.h"
#include "Utilities/GUIDGenerator.h"

namespace me3d
{
  static const char* c_TextureFileExtension_pc = "Me3dTex";
  static const char* c_ModelFileExtension_pc = "Me3dModel";
  static const char* c_MaterialFileExtension_pc = "Me3dMat";
  static const char* c_FontFileExtension_pc = "Me3dFont";
  static const char* c_KTXFileExtension_pc    = "ktx";

//typedef mepl::map<ResourceID_t, Resource_s*> ResourceMap_t;
typedef mepl::vector<Resource_s*> ResourceMap_t;

class ResourceHandler
{

public:
  ~ResourceHandler();
  // singleton access
  static ResourceHandler* get_po();

  void release_v();
  void serialize_v(InOut& b_IO_ro);
  bool_t exportResources_b(const MEString& i_FileName_ro);
  bool_t importResources_b(const MEString& i_FileName_ro);

  ResourceID_t        createTexture_t(const TextureDesc_s& i_TexDesc_rs, uint8_t* i_Data_pu8, uint32_t i_DataSize_u32);
  TextureResource_s*  loadTexture_ps(const MEString& i_FilePath_ro);

  ResourceID_t        createModel_t(const ModelDesc_s& i_ModelDesc_rs);
  ModelResource_s*    loadModel_ps(const MEString& i_FilePath_ro);

  ResourceID_t        createMaterial_t(const MaterialDesc_s& i_MaterialDesc_rs);
  MaterialResource_s* loadMaterial_ps(const MEString& i_FilePath_ro);


//   bool_t releaseResourceByName_b(const MEString& i_Name_ro)
//   {
//     bool_t v_Released_b = false;
//     // find allocated resource in the list by name
//     for (ResourceMap_t::iterator v_It_t = resourceMap_t.begin(); v_It_t != resourceMap_t.end(); ++v_It_t)
//     {
//       if (v_It_t->getResourceName_ro() == i_Name_ro)
//       {
//         guidGenerator_o.releaseID_v(v_It_t->resourceID_t);
//         v_It_t->release_v();
//         delete (*v_It_t);
// 
//         v_It_t = resourceMap_t.erase(std::remove(resourceMap_t.begin(), resourceMap_t.end(), v_It_t), resourceMap_t.end());
// 
//         v_Released_b = true;
// 
//         break;
//       }
//     }
// 
//     return v_Released_b;
//   }

//   bool_t releaseResourceByID_b(ResourceID_t i_ID_t)
//   {
//     bool_t v_Released_b = false;
//     ResourceMap_t::iterator v_It_t = resourceMap_t.find(i_ID_t);
//     if (v_It_t != resourceMap_t.end())
//     {
//       guidGenerator_o.releaseID_v(v_It_t->resourceID_t);
//       v_It_t->release_v();
//       delete (*v_It_t);
//       v_It_t = resourceMap_t.erase(std::remove(resourceMap_t.begin(), resourceMap_t.end(), v_It_t), resourceMap_t.end());
// 
//       v_Released_b = true;
//     }
// 
//     return v_Released_b;
//   }


  template<typename T>
  T* findResourceByName_po(const MEString& i_Name_ro)
  {
    T* v_FoundResource_px = NULL;

    // find allocated resource in the list by name
        // PRQA S 4243 1 // this is how iterators work... c++14 autosar standard allows usage of stl.
    for (ResourceMap_t::iterator v_It_t = resourceMap_t.begin(); v_It_t != resourceMap_t.end(); ++v_It_t)
    {
      if ( (*v_It_t)->getResourceName_ro() == i_Name_ro)
      {
        // we have the same resource name, but be sure the type matches
        // PRQA S 3077 1 // definitely need the checked downcast here.
        T* v_CurrentResource_px = dynamic_cast<T*>((*v_It_t));

        if (NULL != v_CurrentResource_px)
        {
          v_FoundResource_px = v_CurrentResource_px;
          break;
        }
        
      }
    }

    return v_FoundResource_px;
  }

  template<typename T>
  T* findResourceByID_po(ResourceID_t i_ID_t)
  {
    T* v_FoundResource_px = NULL;

    // find allocated resource in the list by name
        // PRQA S 4243 1 // this is how iterators work... c++14 autosar standard allows usage of stl.
    for (ResourceMap_t::iterator v_It_t = resourceMap_t.begin(); v_It_t != resourceMap_t.end(); ++v_It_t)
    {
      if ((*v_It_t)->resourceID_t == i_ID_t)
      {
        // found it
        // PRQA S 3077 1 // definitely need the checked downcast here.
        v_FoundResource_px = dynamic_cast<T*>((*v_It_t));

        break;
      }
    }

    return v_FoundResource_px;
  }

  const ResourceMap_t& getResoureMap_ro() const { return resourceMap_t; }

  static const char_t* getResourceExtension_pc(ResourceType_e i_Type_e);
  static const char_t* getResourcePath_pc(ResourceType_e i_Type_e);

private:
  ResourceHandler(); // Prevent construction
  ResourceHandler(const ResourceHandler&); // Prevent construction by copying
  ResourceHandler& operator=(const ResourceHandler&); // Prevent assignment

  // find free resource and set allocated state
  template<typename T>
  T* createResource_ps()
  {
    T* v_NewResource = new T();
    ResourceID_t v_ID_t = guidGenerator_o.getFreeID_u32();

    Assert(NULL == findResourceByID_po<T>(v_ID_t));

    v_NewResource->resourceID_t = v_ID_t;

    resourceMap_t.push_back(v_NewResource);

    return v_NewResource;
  }


  static MEString getResourceFileName_o(Resource_s* b_Resource_ps);
  static void exportResource_v(Resource_s* b_Resource_ps);

private:
  static ResourceHandler* s_Instance_po;
  GUIDGenerator<>         guidGenerator_o;
  ResourceMap_t           resourceMap_t;
};

} // namespace me3d


#endif
