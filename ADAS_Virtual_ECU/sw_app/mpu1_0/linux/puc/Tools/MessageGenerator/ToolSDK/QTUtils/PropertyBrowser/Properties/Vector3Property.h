#pragma once

#include <QObject.h>
#include <QString.h>
#include <mecl/core/Point.h>

#include "QtUtils/PropertyBrowser/Properties/BaseProperty.h"

class QtProperty;

namespace tsdk
{

class PropertyFactory;
class FloatProperty;
class GroupProperty;

class Vector3Property : public BaseProperty
{
  Q_OBJECT

public:
  Vector3Property();
  virtual ~Vector3Property();

  virtual void init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b) override;
  virtual QtProperty* getTopLevelProperty() const;

  void setValue_v(const mecl::core::Point3D<float32_t>& i_Position_ro);
  void setSingleStep_v(double i_Value_f32);
  void setMinMax_v(double i_Min_f32, double i_Max_f32);

signals:
  void vector3Changed(const mecl::core::Point3D<float32_t>& value);

private slots:
  void xChanged(double i_Value_f32);
  void yChanged(double i_Value_f32);
  void zChanged(double i_Value_f32);

private:
  void updatePropertyName_v();


private:
  GroupProperty* groupProperty_po;
  FloatProperty* xProp_po;
  FloatProperty* yProp_po;
  FloatProperty* zProp_po;

  bool ignoreValueChanged_b;
  mecl::core::Point3D<float32_t> value_o;
};


} // namespace ce