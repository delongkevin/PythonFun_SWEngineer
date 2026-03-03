#include "Common/ResourceHandler/ResourceHandler.h"

#include <osal/io/File.h>
#include "Utilities/InOut.h"
#include "Utilities/FileUtils.h"
#include "Utilities/Directory.h"
#include "Common/ResourceHandler/KTXFile.h"


// PRQA S 5118 EOF // c++14 autosar standard permits
// PRQA S 4243 EOF // this is how iterators work
// PRQA S 3223 EOF // fine here
// PRQA S 3710 EOF // flag handling
// PRQA S 5127 EOF // not using cstdio here...

namespace me3d
{


  ResourceHandler* ResourceHandler::s_Instance_po = NULL;

  ResourceHandler::ResourceHandler()
    : guidGenerator_o()
  {
  }

  ResourceHandler::~ResourceHandler()
  {
  }

  ResourceHandler* ResourceHandler::get_po()
  {
    if (NULL == s_Instance_po)
    {
      s_Instance_po = new ResourceHandler();
    }

    return s_Instance_po;
  }

  void ResourceHandler::release_v()
  {
    ResourceMap_t::iterator v_It_t = resourceMap_t.begin();
    while (v_It_t != resourceMap_t.end())
    {
      Resource_s* v_Resource_ps = (*v_It_t);

      guidGenerator_o.releaseID_v(v_Resource_ps->resourceID_t);
      v_Resource_ps->release_v();
      delete v_Resource_ps;
      v_It_t = resourceMap_t.erase(std::remove(resourceMap_t.begin(), resourceMap_t.end(), v_Resource_ps), resourceMap_t.end());
    }

    resourceMap_t.clear();
  }

  void ResourceHandler::serialize_v(InOut& b_IO_ro)
  {
    if (true == b_IO_ro.isLoading_b())
    {
      release_v();
    }

    guidGenerator_o.serialize_v(b_IO_ro);

    uint32_t v_Size_u32 = resourceMap_t.size();
    b_IO_ro.serialize_v(v_Size_u32);

   if (true == b_IO_ro.isLoading_b())
   {
     resourceMap_t.resize(v_Size_u32);

      for (uint32_t v_I_t = 0; v_I_t < v_Size_u32; ++v_I_t)
      {
        ResourceType_e v_ResType_e = e_ResourceTypeCount;
        b_IO_ro.serializeEnum_v(v_ResType_e);
        Assert(v_ResType_e != e_ResourceTypeCount);

        Resource_s* v_Resource_ps = NULL;

        switch (v_ResType_e)
        {
		case e_ResourceTypeModel:     {v_Resource_ps = new ModelResource_s();    break;}
        case e_ResourceTypeFont:     {v_Resource_ps = new FontResource_s();     break;}
        case e_ResourceTypeMaterial: {v_Resource_ps = new MaterialResource_s(); break;}
        case e_ResourceTypeTexture:  {v_Resource_ps = new TextureResource_s();  break;}
        case e_ResourceTypeCount:     // fall through
        default:
			{
			Assert(false);
			break;
			}
        }

        Assert(NULL != v_Resource_ps);
        v_Resource_ps->serialize_v(b_IO_ro);

        resourceMap_t[v_I_t] = v_Resource_ps;
      }
    }
    else
    {
      for (uint32_t v_I_t = 0; v_I_t < v_Size_u32; ++v_I_t)
      {
        Resource_s* v_Resource_ps = resourceMap_t[v_I_t];
        b_IO_ro.serializeEnum_v(v_Resource_ps->resourceType_e);

        v_Resource_ps->serialize_v(b_IO_ro);

      }
    }
  }

  bool_t ResourceHandler::exportResources_b(const MEString& i_FileName_ro)
  {
    osal::File v_File_o;
    bool_t v_Success_b = v_File_o.open_b(i_FileName_ro.getString_pc(), e_FomWrite | e_FomBinary);

    if (true == v_Success_b)
    {
      // create IO
      me3d::InOut io;
      io.create_b(&v_File_o, false);

      serialize_v(io);
    }

    // always close file
    v_File_o.close_b();

    return v_Success_b;
  }

  bool_t ResourceHandler::importResources_b(const MEString& i_FileName_ro)
  {
    osal::File v_File_o;
    bool_t v_Success_b = v_File_o.open_b(i_FileName_ro.getString_pc(), e_FomRead | e_FomBinary);

    if (true == v_Success_b)
    {
      // create IO
      me3d::InOut io;
      io.create_b(&v_File_o, true);

      serialize_v(io);
    }
    else
    {
      ME_Debugger_F_Printf_v("Failed to Load Resource File: %s", me3d::Directory::getResourceFile_pc());
    }

    // always close file
    v_File_o.close_b();
  
    return v_Success_b;
  }

  ResourceID_t ResourceHandler::createTexture_t(const TextureDesc_s& i_TexDesc_rs, uint8_t* i_Data_pu8, uint32_t i_DataSize_u32)
  {
    TextureResource_s* v_Resource_ps = findResourceByName_po<TextureResource_s>(i_TexDesc_rs.fileName_o);

    // nothing found
    if (NULL == v_Resource_ps)
    {
      v_Resource_ps = createResource_ps<TextureResource_s>();
      v_Resource_ps->texDesc_s = i_TexDesc_rs;
      v_Resource_ps->data_pu8  = i_Data_pu8;
      v_Resource_ps->dataSize_u32 = i_DataSize_u32;
    }

    Assert(NULL != v_Resource_ps);
    return v_Resource_ps->resourceID_t;
  }

  TextureResource_s* ResourceHandler::loadTexture_ps(const MEString& i_FilePath_ro)
  {
    MEString v_ResourceName_o = FileUtils::getFileName_o(i_FilePath_ro, true, c_PathSeparator_c);
   MEString v_FileExtension_o = me3d::FileUtils::getExtension_o(i_FilePath_ro);

    TextureResource_s* v_Resource_ps = findResourceByName_po<TextureResource_s>(v_ResourceName_o);

    // nothing found
    if (NULL == v_Resource_ps)
    {

      if (v_FileExtension_o == me3d::c_TextureFileExtension_pc)
      {
        // and load the data
        osal::File v_File_o;
        if (v_File_o.open_b(i_FilePath_ro.getString_pc(), e_FomRead | e_FomBinary))
        {
          me3d::InOut v_InOut_o;
          v_InOut_o.create_b(&v_File_o, true);

          // allocate new resource
          v_Resource_ps = new TextureResource_s();

          // TODO: Set datasize!

          v_Resource_ps->serialize_v(v_InOut_o);
          

          //Assert(NULL == findResourceByID_po<TextureResource_s>(v_Resource_ps->resourceID_t));

          v_File_o.close_b();
        }
        else
        {
          Assert(false);
        }
      }
      else if (v_FileExtension_o == me3d::c_KTXFileExtension_pc)
      {
        me3d::KTXFile v_Loader_po;

        v_Loader_po.load_b(i_FilePath_ro.getString_pc());


        // allocate new resource
        v_Resource_ps = createResource_ps<TextureResource_s>();

        v_Loader_po.getTextureDesc_v(v_Resource_ps->texDesc_s);

        // copy data
        v_Resource_ps->dataSize_u32 = v_Loader_po.getDataSize_u32();
        v_Resource_ps->data_pu8 = new uint8_t[v_Resource_ps->dataSize_u32];
        memcpy(v_Resource_ps->data_pu8, v_Loader_po.getData_pu8(), v_Resource_ps->dataSize_u32);

        v_Resource_ps->texDesc_s.fileName_o = v_ResourceName_o;

        // KTX file will release here
      }
	  else
	  {
		  //Do nothing
	  }

    }

    return v_Resource_ps;
  }

  ResourceID_t ResourceHandler::createModel_t(const ModelDesc_s& i_ModelDesc_rs)
  {
    ModelResource_s* v_Resource_ps = findResourceByName_po<ModelResource_s>(i_ModelDesc_rs.fileName_o);

    if (NULL == v_Resource_ps)
    {
      v_Resource_ps = createResource_ps<ModelResource_s>();
      v_Resource_ps->desc_s = i_ModelDesc_rs;
    }

    Assert(NULL != v_Resource_ps);
    return v_Resource_ps->resourceID_t;
  }

  ModelResource_s* ResourceHandler::loadModel_ps(const MEString& i_FilePath_ro)
  {
    MEString v_ResourceName_o = FileUtils::getFileName_o(i_FilePath_ro, true, c_PathSeparator_c);

    ModelResource_s* v_Resource_ps = findResourceByName_po<ModelResource_s>(v_ResourceName_o);

    // nothing found
    if (NULL == v_Resource_ps)
    {
      // allocate new resource
      v_Resource_ps = new ModelResource_s();

      // and load the data
      osal::File v_File_o;
      if (v_File_o.open_b(i_FilePath_ro.getString_pc(), e_FomRead | e_FomBinary))
      {
        me3d::InOut v_InOut_o;
        v_InOut_o.create_b(&v_File_o, true);

        v_Resource_ps->serialize_v(v_InOut_o);

        // set resource file name
        v_Resource_ps->desc_s.fileName_o = v_ResourceName_o;

        Assert(NULL == findResourceByID_po<Resource_s>(v_Resource_ps->resourceID_t));


        // add to map
        resourceMap_t.push_back(v_Resource_ps);

        // Materials are loaded separately, before models
        v_File_o.close_b();
      }
      else
      {
        Assert(false);
      }
    }

    return v_Resource_ps;
  }


  ResourceID_t ResourceHandler::createMaterial_t(const MaterialDesc_s& i_MaterialDesc_rs)
  {
    MaterialResource_s* v_Resource_ps = findResourceByName_po<MaterialResource_s>(i_MaterialDesc_rs.name_o);

    if (NULL == v_Resource_ps)
    {
      v_Resource_ps = createResource_ps<MaterialResource_s>();
      v_Resource_ps->desc_s = i_MaterialDesc_rs;
    }

    Assert(NULL != v_Resource_ps);
    return v_Resource_ps->resourceID_t;
  }

  MaterialResource_s* ResourceHandler::loadMaterial_ps(const MEString& i_FilePath_ro)
  {
    MEString v_ResourceName_o = FileUtils::getFileName_o(i_FilePath_ro, true, c_PathSeparator_c);

    MaterialResource_s* v_Resource_ps = findResourceByName_po<MaterialResource_s>(v_ResourceName_o);

    // nothing found
    if (NULL == v_Resource_ps)
    {
      // allocate new resource
      v_Resource_ps = new MaterialResource_s();

      // and load the data
      osal::File v_File_o;
      if (v_File_o.open_b(i_FilePath_ro.getString_pc(), e_FomRead | e_FomBinary))
      {
        me3d::InOut v_InOut_o;
        v_InOut_o.create_b(&v_File_o, true);

        v_Resource_ps->serialize_v(v_InOut_o);

        Assert(NULL == findResourceByID_po<Resource_s>(v_Resource_ps->resourceID_t));

        // set resource file name
        v_Resource_ps->desc_s.name_o = v_ResourceName_o;

        // add to map
        resourceMap_t.push_back(v_Resource_ps);

        v_File_o.close_b();
      }
      else
      {
        Assert(false);
      }
    }

    return v_Resource_ps;
  }

  const char_t* ResourceHandler::getResourceExtension_pc(ResourceType_e i_Type_e)
  {
    const char_t* v_FileExt_pc = NULL;

    switch (i_Type_e)
    {
	case e_ResourceTypeModel:     {v_FileExt_pc = c_ModelFileExtension_pc;    break;}
    case e_ResourceTypeFont:      {v_FileExt_pc = c_FontFileExtension_pc;     break;}
    case e_ResourceTypeMaterial:  {v_FileExt_pc = c_MaterialFileExtension_pc; break;}
    case e_ResourceTypeTexture:   {v_FileExt_pc = c_TextureFileExtension_pc;  break;}
    case e_ResourceTypeCount: 
		{// fall through
		}
    default:
		{
		Assert(false);
		break;
		}
    }

    return v_FileExt_pc;
  }

  const char_t* ResourceHandler::getResourcePath_pc(ResourceType_e i_Type_e)
  {
    const char_t* v_Path_pc = NULL;

    switch (i_Type_e)
    {
	case e_ResourceTypeModel:    { v_Path_pc = Directory::getModelsPath_pc();      break;}
    case e_ResourceTypeFont:     { Assert(false);                                  break;}
    case e_ResourceTypeMaterial: { v_Path_pc = Directory::getMaterialsPath_pc();   break;}
    case e_ResourceTypeTexture:  { v_Path_pc = Directory::getTexturePath_pc();     break;}
    case e_ResourceTypeCount:
		{ // fall through
		}
    default:
		{
		Assert(false);
		break;
		}
								 
    }

    return v_Path_pc;
  }


  MEString ResourceHandler::getResourceFileName_o(Resource_s* b_Resource_ps)
  {
    MEString v_ResourceFileName_o;
    
    v_ResourceFileName_o = getResourcePath_pc(b_Resource_ps->resourceType_e);
    v_ResourceFileName_o += me3d::c_PathSeparator_c;
    v_ResourceFileName_o += b_Resource_ps->getResourceName_ro();
    v_ResourceFileName_o += ".";
    v_ResourceFileName_o += getResourceExtension_pc(b_Resource_ps->resourceType_e);

    return v_ResourceFileName_o;
  }

  void ResourceHandler::exportResource_v(Resource_s* b_Resource_ps)
  {
    osal::File v_File_o;
    MEString v_ResourceFileName_o = getResourceFileName_o(b_Resource_ps);

    bool_t v_Success_b = v_File_o.open_b(v_ResourceFileName_o.getString_pc(), e_FomWrite | e_FomBinary);
    if (true == v_Success_b)
    {
      // create IO
      me3d::InOut io;
      io.create_b(&v_File_o, false);

      // serialize guid generator
      b_Resource_ps->serialize_v(io);
    }

    // always close file
    v_File_o.close_b();
  }

} // namespace me3d