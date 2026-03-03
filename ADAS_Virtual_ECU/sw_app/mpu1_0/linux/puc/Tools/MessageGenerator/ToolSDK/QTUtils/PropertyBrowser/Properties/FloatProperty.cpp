#include "QtUtils/PropertyBrowser/Properties/FloatProperty.h"

#include <platform/PlatformAPI.h>

#include <qtpropertybrowser.h>
#include <qtpropertymanager.h>
#include <qttreepropertybrowser.h>

#include "QtUtils/PropertyBrowser/PropertyFactory.h"

namespace tsdk
{

FloatProperty::FloatProperty()
  : BaseProperty()
  , doubleProp_po(NULL)
  , doubleManager_po(NULL)
  , doubleManagerConfig_po(NULL)
  , ignoreUpdates_b(false)
  , minProp_po(NULL)
  , maxProp_po(NULL)
{
}

FloatProperty::~FloatProperty()
{
}

void FloatProperty::init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b)
{
  BaseProperty::init_v(b_PropFactory_po, i_GroupName_po, b_Parent_po, i_ReadOnly_b);

  doubleManager_po = propFactory_po->getDoubleManager_po(i_ReadOnly_b);
  doubleProp_po    = doubleManager_po->addProperty(i_GroupName_po);

  connect(doubleManager_po, SIGNAL(valueChanged(QtProperty*, double)), this, SLOT(valueChanged(QtProperty*, double)));

  doubleManagerConfig_po = propFactory_po->getDoubleManager_po(false);

  connect(doubleManagerConfig_po, SIGNAL(valueChanged(QtProperty*, double)), this, SLOT(configValueChanged(QtProperty*, double)));
}

QtProperty* FloatProperty::getTopLevelProperty() const
{
  Assert(NULL != doubleProp_po);
  return doubleProp_po;
}

void FloatProperty::setSingleStep_v(double i_Value_f32)
{
  doubleManager_po->setSingleStep(doubleProp_po, i_Value_f32);
}

void FloatProperty::setMinMax_v(double i_Min_f32, double i_Max_f32)
{
  setMin_v(i_Min_f32);
  setMax_v(i_Max_f32);
}

void FloatProperty::setMin_v(double i_Val_f32)
{
  ignoreUpdates_b = true;

  doubleManager_po->setMinimum(doubleProp_po, i_Val_f32);

  if (minProp_po)
  {
    doubleManagerConfig_po->setValue(minProp_po, i_Val_f32);
  }

  ignoreUpdates_b = false;
}

void FloatProperty::setMax_v(double i_Val_f32)
{
  ignoreUpdates_b = true;

  doubleManager_po->setMaximum(doubleProp_po, i_Val_f32);

  if (maxProp_po)
  {
    doubleManagerConfig_po->setValue(maxProp_po, i_Val_f32);
  }

  ignoreUpdates_b = false;
}

void FloatProperty::setValue_v(double i_Value_f32)
{
  ignoreUpdates_b = true;

  doubleManager_po->setValue(doubleProp_po, i_Value_f32);
  
  ignoreUpdates_b = false;
}

void FloatProperty::setDecimals_v(sint32_t i_NumDecimals_s32)
{
  doubleManager_po->setDecimals(doubleProp_po, i_NumDecimals_s32);
}

float32_t FloatProperty::getValue_f32() const
{
  return doubleManager_po->value(doubleProp_po);
}

void FloatProperty::valueChanged(QtProperty* i_Property_po, double i_Value_f64)
{
  if (ignoreUpdates_b)
  {
    return;
  }

  if (doubleProp_po == i_Property_po)
  {
    emit floatChanged(i_Value_f64);
  }

}

void FloatProperty::configValueChanged(QtProperty* i_Property_po, double i_Value_f64)
{
  if (ignoreUpdates_b)
  {
    return;
  }

  if (minProp_po == i_Property_po)
  {
    emit minChanged(i_Value_f64);
  }
  else if (maxProp_po == i_Property_po)
  {
    emit maxChanged(i_Value_f64);
  }
}

void FloatProperty::onShowConfigValues()
{
  if (showConfigValues_b)
  {
    minProp_po = doubleManagerConfig_po->addProperty("Min Value");
    maxProp_po = doubleManagerConfig_po->addProperty("Max Value");

    doubleProp_po->addSubProperty(minProp_po);
    doubleProp_po->addSubProperty(maxProp_po);
  }
  else
  {
    doubleProp_po->removeSubProperty(minProp_po);
    doubleProp_po->removeSubProperty(maxProp_po);
  }
}

} // namespace ce