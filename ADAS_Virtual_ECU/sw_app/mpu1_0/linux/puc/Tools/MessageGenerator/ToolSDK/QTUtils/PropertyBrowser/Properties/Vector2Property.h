#pragma once

#include <QString.h>

#include <mecl/core/Point.h>

#include "QtUtils/PropertyBrowser/Properties/BaseProperty.h"

class QtProperty;

namespace tsdk
{

class PropertyFactory;
class FloatProperty;
class GroupProperty;

class Vector2Property : public BaseProperty
{
  Q_OBJECT

public:
  Vector2Property();
  virtual ~Vector2Property();

  virtual void init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b) override;
  virtual QtProperty* getTopLevelProperty() const;

  void setValue_v(const mecl::core::Point2D<float32_t>& i_Position_ro);
  void setSingleStep_v(double i_Value_f32);
  void setMinMax_v(double i_Min_f32, double i_Max_f32);
  void setDecimals_v(sint32_t i_NumDecimals_s32);

signals:
  void vector2Changed(const mecl::core::Point2D<float32_t>& value);

private slots:
  void xChanged(double i_Value_f32);
  void yChanged(double i_Value_f32);

private:
  void updatePropertyName_v();


private:
  GroupProperty* groupProperty_po;
  FloatProperty* xProp_po;
  FloatProperty* yProp_po;

  bool ignoreValueChanged_b;
  mecl::core::Point2D<float32_t> value_o;
};


} // namespace ce
