//--------------------------------------------------------------------------                                                                                                           
/// @file GizmoObject.h                                                                         
/// @brief Gizmo Object                                                
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef GIZMO_OBJECT_H
#define GIZMO_OBJECT_H

#include "Transform.h"
#include "BBox3D.h"
#include "Color.h"

namespace me3d
{
  class RenderInterface;
}

namespace me3d
{

enum GizmoObjectType_e
{
  e_GOT_Arrow,
  e_GOT_Corner,
  e_GOT_Circle,
  e_GOT_ScaleBar,
  e_GOT_ScaleCenter
};

class GizmoObject
{
public:
  GizmoObject();
  ~GizmoObject();

  void create_v(me3d::RenderInterface* i_RenderInterface_po, const Transform& i_Transform_ro, GizmoObjectType_e i_Type_e, const Color& i_Color_ro);
  void setColor_v(const Color& i_Color_ro);
  void highLight_v(bool i_highlight);
  Transform* getTransform_po();


  bool intersect_b(const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayEnd_ro, Vector3f& o_Intersection_ro)const;

  void render_v();


private:
  me3d::RenderInterface* renderInterface_po;

  Transform transformation_o;

  const float32_t c_ArrowLength_f32;
  const float32_t c_CircleRadius_f32;

  GizmoObjectType_e objectType_e;

  BBox3D_s boundingBox_o;
  Color color_o;
  bool isHighlighted_b;
};

} // namespace me3d

#endif
