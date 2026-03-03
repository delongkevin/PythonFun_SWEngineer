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

#ifndef RESOURCE_TYPES_H
#define RESOURCE_TYPES_H

// PRQA S 2100 EOF // public members used here by design.

namespace me3d
{

typedef uint32_t ResourceID_t;
static const ResourceID_t c_InvalidResourceID_u32 = static_cast<ResourceID_t>(-1);

enum ResourceType_e
{
  e_ResourceTypeModel = 0,
  e_ResourceTypeFont,
  e_ResourceTypeMaterial,
  e_ResourceTypeTexture,
  e_ResourceTypeCount
};

} // namespace me3d

#endif
