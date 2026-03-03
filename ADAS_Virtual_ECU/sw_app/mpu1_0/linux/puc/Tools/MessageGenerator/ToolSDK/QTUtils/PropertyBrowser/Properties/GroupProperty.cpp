#include "QtUtils/PropertyBrowser/Properties/GroupProperty.h"

#include <platform/PlatformAPI.h>

#include <qtpropertybrowser.h>
#include <qtpropertymanager.h>
#include <qttreepropertybrowser.h>

#include "QtUtils/PropertyBrowser/PropertyFactory.h"

namespace tsdk
{

  GroupProperty::GroupProperty()
    : BaseProperty()
    , groupProp_po(NULL)
  {
  }

  GroupProperty::~GroupProperty()
  {

  }

  void GroupProperty::init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b)
  {
    BaseProperty::init_v(b_PropFactory_po, i_GroupName_po, b_Parent_po, i_ReadOnly_b);

    groupProp_po = propFactory_po->getGroupManager_po()->addProperty(i_GroupName_po);
  }

  QtProperty* GroupProperty::getTopLevelProperty() const
  {
    Assert(NULL != groupProp_po);
    return groupProp_po;
  }


} // namespace ce