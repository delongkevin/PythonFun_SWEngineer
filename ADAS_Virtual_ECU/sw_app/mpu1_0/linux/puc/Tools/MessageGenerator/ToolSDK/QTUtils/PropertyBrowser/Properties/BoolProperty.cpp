#include "QtUtils/PropertyBrowser/Properties/BoolProperty.h"

#include <platform/PlatformAPI.h>

#include <qtpropertybrowser.h>
#include <qtpropertymanager.h>
#include <qttreepropertybrowser.h>

#include "QtUtils/PropertyBrowser/PropertyFactory.h"

namespace tsdk
{

BoolProperty::BoolProperty()
  : BaseProperty()
  , boolProp_po(NULL)
  , boolManager_po(NULL)
  , ignoreUpdates_b(false)
{
}

BoolProperty::~BoolProperty()
{
}

void BoolProperty::init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b)
{
  BaseProperty::init_v(b_PropFactory_po, i_GroupName_po, b_Parent_po, i_ReadOnly_b);

  boolManager_po = propFactory_po->getBoolManager_po(i_ReadOnly_b);
  boolProp_po    = boolManager_po->addProperty(i_GroupName_po);

  connect(boolManager_po, SIGNAL(valueChanged(QtProperty*, bool)), this, SLOT(valueChanged(QtProperty*, bool)));
}

QtProperty* BoolProperty::getTopLevelProperty() const
{
  Assert(NULL != boolProp_po);
  return boolProp_po;
}

void BoolProperty::setValue_v(bool i_Value_b)
{
  ignoreUpdates_b = true;

  boolManager_po->setValue(boolProp_po, i_Value_b);

  ignoreUpdates_b = false;
}

bool_t BoolProperty::getValue_b() const
{
  return boolManager_po->value(boolProp_po);
}

void BoolProperty::valueChanged(QtProperty* i_Property_po, bool i_Value_b)
{
  if (ignoreUpdates_b)
  {
    return;
  }

  if (boolProp_po == i_Property_po)
  {
    emit boolChanged(i_Value_b);
  }
}

} // namespace ce