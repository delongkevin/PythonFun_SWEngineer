#include "Vector3Property.h"

#include <qtpropertybrowser.h>
#include <qtpropertymanager.h>
#include <qttreepropertybrowser.h>

#include "QtUtils/PropertyBrowser/PropertyFactory.h"
#include "QtUtils/PropertyBrowser/Properties/FloatProperty.h"
#include "QtUtils/PropertyBrowser/Properties/GroupProperty.h"

namespace tsdk
{

Vector3Property::Vector3Property()
  : BaseProperty()
  , groupProperty_po(NULL)
  , xProp_po(NULL)
  , yProp_po(NULL)
  , zProp_po(NULL)
  , ignoreValueChanged_b(false)
  , value_o()
{

}

Vector3Property::~Vector3Property()
{
}

void Vector3Property::init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b)
{
  BaseProperty::init_v(b_PropFactory_po, i_GroupName_po, b_Parent_po, i_ReadOnly_b);

  groupProperty_po = propFactory_po->createProperty_po<GroupProperty>(i_GroupName_po, b_Parent_po, false);

  xProp_po         = propFactory_po->createProperty_po<FloatProperty>("X", groupProperty_po->getTopLevelProperty(), i_ReadOnly_b);
  yProp_po         = propFactory_po->createProperty_po<FloatProperty>("Y", groupProperty_po->getTopLevelProperty(), i_ReadOnly_b);
  zProp_po         = propFactory_po->createProperty_po<FloatProperty>("Z", groupProperty_po->getTopLevelProperty(), i_ReadOnly_b);
  
  xProp_po->addTopLevelProperty_v();
  yProp_po->addTopLevelProperty_v();
  zProp_po->addTopLevelProperty_v();

  connect(xProp_po, SIGNAL(floatChanged(double)), this, SLOT(xChanged(double)));
  connect(yProp_po, SIGNAL(floatChanged(double)), this, SLOT(yChanged(double)));
  connect(zProp_po, SIGNAL(floatChanged(double)), this, SLOT(zChanged(double)));
}

QtProperty* Vector3Property::getTopLevelProperty() const
{
  return groupProperty_po->getTopLevelProperty();
}

void Vector3Property::setValue_v(const mecl::core::Point3D<float32_t>& i_Position_ro)
{
  value_o = i_Position_ro;

  ignoreValueChanged_b = true;

  xProp_po->setValue_v(i_Position_ro(0));
  yProp_po->setValue_v(i_Position_ro(1));
  zProp_po->setValue_v(i_Position_ro(2));

  ignoreValueChanged_b = false;
}

void Vector3Property::setSingleStep_v(double i_Value_f32)
{
  xProp_po->setSingleStep_v(i_Value_f32);
  yProp_po->setSingleStep_v(i_Value_f32);
  zProp_po->setSingleStep_v(i_Value_f32);
}

void Vector3Property::setMinMax_v(double i_Min_f32, double i_Max_f32)
{
  xProp_po->setMinMax_v(i_Min_f32, i_Max_f32);
  yProp_po->setMinMax_v(i_Min_f32, i_Max_f32);
  zProp_po->setMinMax_v(i_Min_f32, i_Max_f32);
}

void Vector3Property::xChanged(double i_Value_f32)
{
  value_o(0) = i_Value_f32;

  if (ignoreValueChanged_b)
  {
    return;
  }

  emit vector3Changed(value_o);
}

void Vector3Property::yChanged(double i_Value_f32)
{
  value_o(1) = i_Value_f32;

  if (ignoreValueChanged_b)
  {
    return;
  }

  emit vector3Changed(value_o);
}

void Vector3Property::zChanged(double i_Value_f32)
{
  value_o(2) = i_Value_f32;

  if (ignoreValueChanged_b)
  {
    return;
  }

  emit vector3Changed(value_o);
}

void Vector3Property::updatePropertyName_v()
{
  QString stringValues;
  stringValues.sprintf(" (%.1f %.1f %.1f) ", value_o(0), value_o(1), value_o(2));

  QString combinedName;
  combinedName.append(groupName_o);
  combinedName.append(stringValues);

  groupProperty_po->getTopLevelProperty()->setPropertyName(combinedName);
}

} // namespace ce