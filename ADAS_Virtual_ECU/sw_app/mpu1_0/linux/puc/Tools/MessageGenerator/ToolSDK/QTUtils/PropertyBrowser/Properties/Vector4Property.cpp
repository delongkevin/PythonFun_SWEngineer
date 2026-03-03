#include "Vector4Property.h"

#include <qtpropertybrowser.h>
#include <qtpropertymanager.h>
#include <qttreepropertybrowser.h>

#include "QtUtils/PropertyBrowser/PropertyFactory.h"
#include "QtUtils/PropertyBrowser/Properties/FloatProperty.h"
#include "QtUtils/PropertyBrowser/Properties/GroupProperty.h"

namespace tsdk
{

Vector4Property::Vector4Property()
  : BaseProperty()
  , groupProp_po(NULL)
  , xProp_po(NULL)
  , yProp_po(NULL)
  , zProp_po(NULL)
  , wProp_po(NULL)
  , ignoreValueChanged_b(false)
  , value_o()
{

}

Vector4Property::~Vector4Property()
{
}

void Vector4Property::init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b)
{
  BaseProperty::init_v(b_PropFactory_po, i_GroupName_po, b_Parent_po, i_ReadOnly_b);

  groupProp_po = propFactory_po->createProperty_po<GroupProperty>(i_GroupName_po, b_Parent_po, false);

  xProp_po     = propFactory_po->createProperty_po<FloatProperty>("X", groupProp_po->getTopLevelProperty(), i_ReadOnly_b);
  yProp_po     = propFactory_po->createProperty_po<FloatProperty>("Y", groupProp_po->getTopLevelProperty(), i_ReadOnly_b);
  zProp_po     = propFactory_po->createProperty_po<FloatProperty>("Z", groupProp_po->getTopLevelProperty(), i_ReadOnly_b);
  wProp_po     = propFactory_po->createProperty_po<FloatProperty>("W", groupProp_po->getTopLevelProperty(), i_ReadOnly_b);
  
  xProp_po->addTopLevelProperty_v();
  yProp_po->addTopLevelProperty_v();
  zProp_po->addTopLevelProperty_v();
  wProp_po->addTopLevelProperty_v();

  connect(xProp_po, SIGNAL(floatChanged(double)), this, SLOT(xChanged(double)));
  connect(yProp_po, SIGNAL(floatChanged(double)), this, SLOT(yChanged(double)));
  connect(zProp_po, SIGNAL(floatChanged(double)), this, SLOT(zChanged(double)));
  connect(wProp_po, SIGNAL(floatChanged(double)), this, SLOT(wChanged(double)));
}

QtProperty* Vector4Property::getTopLevelProperty() const
{
  return groupProp_po->getTopLevelProperty();
}

void Vector4Property::setValue_v(const mecl::core::Point4D<float32_t>& i_Position_ro)
{
  value_o = i_Position_ro;

  ignoreValueChanged_b = true;

  xProp_po->setValue_v(i_Position_ro(0));
  yProp_po->setValue_v(i_Position_ro(1));
  zProp_po->setValue_v(i_Position_ro(2));
  wProp_po->setValue_v(i_Position_ro(3));

  ignoreValueChanged_b = false;
}

void Vector4Property::xChanged(double i_Value_f32)
{
  value_o(0) = i_Value_f32;

  if (ignoreValueChanged_b)
  {
    return;
  }

  emit vector4Changed(value_o);
}

void Vector4Property::yChanged(double i_Value_f32)
{
  value_o(1) = i_Value_f32;

  if (ignoreValueChanged_b)
  {
    return;
  }

  emit vector4Changed(value_o);
}

void Vector4Property::zChanged(double i_Value_f32)
{
  value_o(2) = i_Value_f32;

  if (ignoreValueChanged_b)
  {
    return;
  }

  emit vector4Changed(value_o);
}

void Vector4Property::wChanged(double i_Value_f32)
{
  value_o(3) = i_Value_f32;

  if (ignoreValueChanged_b)
  {
    return;
  }

  emit vector4Changed(value_o);
}

void Vector4Property::updatePropertyName_v()
{
  QString stringValues;
  stringValues.sprintf(" (%.1f %.1f %.1f %1f) ", value_o(0), value_o(1), value_o(2), value_o(3));

  QString combinedName;
  combinedName.append(groupName_o);
  combinedName.append(stringValues);

  groupProp_po->getTopLevelProperty()->setPropertyName(combinedName);
}

} // namespace ce