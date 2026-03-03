#include "QtUtils/PropertyBrowser/Properties/IntProperty.h"

#include <platform/PlatformAPI.h>

#include <qtpropertybrowser.h>
#include <qtpropertymanager.h>
#include <qttreepropertybrowser.h>

#include "QtUtils/PropertyBrowser/PropertyFactory.h"

namespace tsdk
{

IntProperty::IntProperty()
  : BaseProperty()
  , intProp_po(NULL)
  , intManager_po(NULL)
  , intManagerConfig_po(NULL)
  , ignoreUpdates_b(false)
  , minProp_po(NULL)
  , maxProp_po(NULL)
{
}

IntProperty::~IntProperty()
{
}

void IntProperty::init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b)
{
  BaseProperty::init_v(b_PropFactory_po, i_GroupName_po, b_Parent_po, i_ReadOnly_b);

  intManager_po = propFactory_po->getIntManager_po(i_ReadOnly_b);
  intProp_po    = intManager_po->addProperty(i_GroupName_po);

  connect(intManager_po, SIGNAL(valueChanged(QtProperty*, int)), this, SLOT(valueChanged(QtProperty*, int)));

  intManagerConfig_po = propFactory_po->getIntManager_po(false);

  connect(intManager_po, SIGNAL(valueChanged(QtProperty*, int)), this, SLOT(configValueChanged(QtProperty*, int)));
}

QtProperty* IntProperty::getTopLevelProperty() const
{
  Assert(NULL != intProp_po);
  return intProp_po;
}

void IntProperty::setMin_v(sint32_t i_Min_s32)
{
  ignoreUpdates_b = true;

  intManager_po->setMinimum(intProp_po, i_Min_s32);

  if (minProp_po)
  {
    intManagerConfig_po->setValue(minProp_po, i_Min_s32);
  }

  ignoreUpdates_b = false;
}

void IntProperty::setMax_v(sint32_t i_Max_s32)
{
  ignoreUpdates_b = true;

  intManager_po->setMaximum(intProp_po, i_Max_s32);

  if (maxProp_po)
  {
    intManagerConfig_po->setValue(maxProp_po, i_Max_s32);
  }

  ignoreUpdates_b = false;
}

void IntProperty::setMinMax_v(sint32_t i_Min_s32, sint32_t i_Max_s32)
{
  setMin_v(i_Min_s32);
  setMax_v(i_Max_s32);
}

void IntProperty::setValue_v(int i_Value_s32)
{
  ignoreUpdates_b = true;

  intManager_po->setValue(intProp_po, i_Value_s32);
  
  ignoreUpdates_b = false;
}

int IntProperty::getValue_s32() const
{
  return intManager_po->value(intProp_po);
}

void IntProperty::valueChanged(QtProperty* i_Property_po, int i_Value_s32)
{
  if (ignoreUpdates_b)
  {
    return;
  }

  if (intProp_po == i_Property_po)
  {
    emit intChanged(i_Value_s32);
  }
}

void IntProperty::configValueChanged(QtProperty* i_Property_po, int i_Value_s32)
{
  if (ignoreUpdates_b)
  {
    return;
  }

  if (minProp_po == i_Property_po)
  {
    emit minChanged(i_Value_s32);
  }
  else if (maxProp_po == i_Property_po)
  {
    emit maxChanged(i_Value_s32);
  }
}

void IntProperty::onShowConfigValues()
{
  if (showConfigValues_b)
  {
    minProp_po = intManagerConfig_po->addProperty("Min Value");
    maxProp_po = intManagerConfig_po->addProperty("Max Value");

    intProp_po->addSubProperty(minProp_po);
    intProp_po->addSubProperty(maxProp_po);
  }
  else
  {
    intProp_po->removeSubProperty(minProp_po);
    intProp_po->removeSubProperty(maxProp_po);
  }
}

} // namespace ce