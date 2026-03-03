#include "QtUtils/PropertyBrowser/Properties/StringProperty.h"

#include <platform/PlatformAPI.h>

#include <qtpropertybrowser.h>
#include <qtpropertymanager.h>
#include <qttreepropertybrowser.h>

#include "QtUtils/PropertyBrowser/PropertyFactory.h"

namespace tsdk
{

StringProperty::StringProperty()
  : BaseProperty()
  , stringProp_po(NULL)
  , stringManager_po(NULL)
  , ignoreUpdates_b(false)
{
}

StringProperty::~StringProperty()
{
}

void StringProperty::init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b)
{
  BaseProperty::init_v(b_PropFactory_po, i_GroupName_po, b_Parent_po, i_ReadOnly_b);

  stringManager_po = propFactory_po->getStringManager_po(i_ReadOnly_b);
  stringProp_po    = stringManager_po->addProperty(i_GroupName_po);

  connect(stringManager_po, SIGNAL(valueChanged(QtProperty*, const QString&)), this, SLOT(valueChanged(QtProperty*, const QString&)));
}

QtProperty* StringProperty::getTopLevelProperty() const
{
  Assert(NULL != stringProp_po);
  return stringProp_po;
}

void StringProperty::setValue_v(const QString& i_Value_ro)
{
  ignoreUpdates_b = true;

  stringManager_po->setValue(stringProp_po, i_Value_ro);

  ignoreUpdates_b = false;
}

void StringProperty::valueChanged(QtProperty* i_Property_po, const QString& i_Value_ro)
{
  if (ignoreUpdates_b)
  {
    return;
  }

  if (stringProp_po == i_Property_po)
  {
    emit stringChanged(i_Value_ro);
  }
}

} // namespace ce