#include "Common/Interfaces/MaterialInterface.h"
#include "Common/RenderInterface.h"
#include "Common/Manager/MaterialManager.h"
#include "Common/Materials/Material.h"

namespace me3d
{

  MaterialInterface::MaterialInterface()
    : renderInterface_po(NULL)
  {

  }

  MaterialInterface::~MaterialInterface()
  {

  }

  void MaterialInterface::create_v(RenderInterface* b_RenderInterface_po)
  {
    renderInterface_po = b_RenderInterface_po;
    Assert(NULL != renderInterface_po);
  }



} // namespace me3d