#include "Math/GizmoObject.h"

#include "MathLib.h"
#include "Common/RenderInterface.h"

// PRQA S 3223 EOF // no modification here

namespace me3d
{

GizmoObject::GizmoObject()
  : renderInterface_po(NULL)
  , c_ArrowLength_f32(25.0F)
  , c_CircleRadius_f32(25.0F)
  , objectType_e(e_GOT_Arrow)
  , isHighlighted_b(false)
{

}

GizmoObject::~GizmoObject()
{

}

void GizmoObject::create_v(me3d::RenderInterface* i_RenderInterface_po, const Transform& i_Transform_ro, GizmoObjectType_e i_Type_e, const Color& i_Color_ro)
{
  renderInterface_po  = i_RenderInterface_po;
  objectType_e        = i_Type_e;
  transformation_o    = i_Transform_ro;
  color_o             = i_Color_ro;

  if (e_GOT_Arrow == objectType_e)
  {
    boundingBox_o = BBox3D_s(Vector3f(-0.5F, 0.0F, -0.5F), Vector3f(0.5F, c_ArrowLength_f32, 0.5F));
  }
  else if (e_GOT_Corner == objectType_e)
  {
    boundingBox_o = BBox3D_s(Vector3f(-0.5F, 0.5F, 0.5F), Vector3f(0.5F, c_ArrowLength_f32 * 0.33F, c_ArrowLength_f32 * 0.33F));
  }
  else if (e_GOT_Circle == objectType_e)
  {
    boundingBox_o = BBox3D_s(Vector3f(-c_CircleRadius_f32, -0.5F, -c_CircleRadius_f32), Vector3f(c_CircleRadius_f32, 0.5F, c_CircleRadius_f32));
  }
  else if (e_GOT_ScaleBar == objectType_e)
  {
    boundingBox_o = BBox3D_s(Vector3f(-0.5F, 0.0F, -0.5F), Vector3f(0.5F, c_ArrowLength_f32, 0.5F));
  }
  else if (e_GOT_ScaleCenter == objectType_e)
  {
    float32_t v_ScaleCenterDims_f32 = c_ArrowLength_f32 * 0.12F;

    boundingBox_o = BBox3D_s(Vector3f(-v_ScaleCenterDims_f32), Vector3f(v_ScaleCenterDims_f32));
  }
  else
  {
	  //Do Nothing
  }
  boundingBox_o.transformMinMax_v(transformation_o.getWorldMatrix_ro());
}

void GizmoObject::setColor_v(const Color& i_Color_ro)
{
  color_o = i_Color_ro;
}

void GizmoObject::highLight_v(bool i_highlight)
{
  isHighlighted_b = i_highlight;
}

Transform* GizmoObject::getTransform_po()
{
  return &transformation_o;
}

bool GizmoObject::intersect_b(const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayEnd_ro, Vector3f& o_Intersection_ro)const
{
  bool v_Intersection_b = false;
  Vector3f v_RayDir_o = normalize_o(static_cast<Vector3f>(i_RayEnd_ro - i_RayOrigin_ro));

  if (e_GOT_Circle == objectType_e)
  {
    float32_t v_Distance_f32;
    if (intersectRayAABB_b(i_RayOrigin_ro, v_RayDir_o, boundingBox_o.min_o, boundingBox_o.max_o, &v_Distance_f32, &o_Intersection_ro))
    {
      Vector3f v_DistanceToCenter_o = static_cast<Vector3f>(boundingBox_o.getCenter_o() - o_Intersection_ro);

      // add a little offset to the radius
      float32_t v_OffsettedRadius_f32 = c_CircleRadius_f32 * 1.1F;

      if (v_DistanceToCenter_o.norm2() <= (v_OffsettedRadius_f32 * v_OffsettedRadius_f32 ))
      {
        v_Intersection_b = intersectRaySphere_b(i_RayOrigin_ro, v_RayDir_o, boundingBox_o.getCenter_o(), v_OffsettedRadius_f32, NULL, &o_Intersection_ro);
      }
    }
  }
  else
  {
    float32_t v_Distance_f32;
    v_Intersection_b = intersectRayAABB_b(i_RayOrigin_ro, v_RayDir_o, boundingBox_o.min_o, boundingBox_o.max_o, &v_Distance_f32, &o_Intersection_ro);
  }
  
  return v_Intersection_b;

}

void GizmoObject::render_v()
{
  Color v_Color_o = isHighlighted_b ? Color::White : color_o;

  if (e_GOT_Arrow == objectType_e)
  {
    boundingBox_o = BBox3D_s(Vector3f(-0.5F, 0.0F, -0.5F), Vector3f(0.5F, c_ArrowLength_f32, 0.5F));
    boundingBox_o.transformMinMax_v(transformation_o.getWorldMatrix_ro());

    renderInterface_po->getDebugInterface_po()->msgDrawLine_v(transformation_o.getWorldMatrix_ro(), Vector3f(0.0F), Vector3f(0.0F, c_ArrowLength_f32, 0.0F), v_Color_o);

    Matrix4f translation = Matrix4f::createTranslation_o(0.0F, c_ArrowLength_f32, 0.0F);
    translation = translation.mmulFast(transformation_o.getWorldMatrix_ro());

    renderInterface_po->getDebugInterface_po()->msgDrawCone_v(translation, 0.25F, 1.0F, v_Color_o);
  }
  else if (e_GOT_Corner == objectType_e)
  {
    boundingBox_o = BBox3D_s(Vector3f(-0.5F, 0.5F, 0.5F), Vector3f(0.5F, c_ArrowLength_f32 * 0.33F, c_ArrowLength_f32 * 0.33F));
    boundingBox_o.transformMinMax_v(transformation_o.getWorldMatrix_ro());

    renderInterface_po->getDebugInterface_po()->msgDrawBoxSolid_v(Matrix4f(), boundingBox_o.min_o, boundingBox_o.max_o, v_Color_o);
  
  }

  else if (e_GOT_Circle == objectType_e)
  {
    boundingBox_o = BBox3D_s(Vector3f(-c_CircleRadius_f32, -0.5F, -c_CircleRadius_f32), Vector3f(c_CircleRadius_f32, 0.5F, c_CircleRadius_f32));
    boundingBox_o.transformMinMax_v(transformation_o.getWorldMatrix_ro());

    renderInterface_po->getDebugInterface_po()->msgDrawCircle_v(transformation_o.getWorldMatrix_ro(), c_CircleRadius_f32, v_Color_o); 
  }
  else if (e_GOT_ScaleBar == objectType_e)
  {
    boundingBox_o = BBox3D_s(Vector3f(-0.5F, 0.0F, -0.5F), Vector3f(0.5F, c_ArrowLength_f32, 0.5F));
    boundingBox_o.transformMinMax_v(transformation_o.getWorldMatrix_ro());

    renderInterface_po->getDebugInterface_po()->msgDrawLine_v(transformation_o.getWorldMatrix_ro(), Vector3f(0.0F), Vector3f(0.0F, c_ArrowLength_f32, 0.0F), v_Color_o);

    Matrix4f translation = Matrix4f::createTranslation_o(0.0F, c_ArrowLength_f32, 0.0F);
    translation = translation.mmulFast(transformation_o.getWorldMatrix_ro());

    renderInterface_po->getDebugInterface_po()->msgDrawBoxSolid_v(translation, Vector3f(-1.0F), Vector3f(1.0F), v_Color_o);
  }
  else if (e_GOT_ScaleCenter == objectType_e)
  {
    float32_t v_ScaleCenterDims_f32 = c_ArrowLength_f32 * 0.12F;

    boundingBox_o = BBox3D_s(Vector3f(-v_ScaleCenterDims_f32), Vector3f(v_ScaleCenterDims_f32));
    boundingBox_o.transformMinMax_v(transformation_o.getWorldMatrix_ro());

    renderInterface_po->getDebugInterface_po()->msgDrawBoxSolid_v(Matrix4f(), boundingBox_o.min_o, boundingBox_o.max_o, v_Color_o);
  }
  else
  {
	  //Do Nothing
  }
}

} // namespace me3d