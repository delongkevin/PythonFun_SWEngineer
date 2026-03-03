#ifndef ME3D_MATERIAL_INTERFACE_H
#define ME3D_MATERIAL_INTERFACE_H

#include "MeclTypeDefs.h"
#include "Common/Device/Device3DTypes.h"
#include "Common/Materials/MaterialTypes.h"

namespace me3d
{
  class RenderInterface;

  class MaterialInterface
  {
  public:
    MaterialInterface();
    ~MaterialInterface();

    void create_v(RenderInterface* b_RenderInterface_po);

  private:
    RenderInterface* renderInterface_po;
  };

} // namespace me3d

#endif
