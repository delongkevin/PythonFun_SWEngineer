#pragma once

#include <platform/PlatformAPI.h>

#include "QtUtils/PropertyBrowser/Properties/BaseProperty.h"

class QtProperty;
class QtDoublePropertyManager;

namespace tsdk
{

class PropertyFactory;

class FloatProperty : public BaseProperty
{
  Q_OBJECT

public:
  FloatProperty();
  virtual ~FloatProperty();

  virtual void init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b) override;
  virtual QtProperty* getTopLevelProperty() const;

  void setSingleStep_v(double i_Value_f32);
  void setMinMax_v(double i_Min_f32, double i_Max_f32);
  void setMin_v(double i_Val_f32);
  void setMax_v(double i_Val_f32);
  void setValue_v(double i_Value_f32);
  void setDecimals_v(sint32_t i_NumDecimals_s32);

  float32_t getValue_f32() const;

signals:
  void floatChanged(double i_Value_f32);
  void minChanged(double val);
  void maxChanged(double val);

private slots:
  void valueChanged(QtProperty* i_Property_po, double i_Value_f64);
  void configValueChanged(QtProperty* i_Property_po, double i_Value_f64);

protected:
  virtual void onShowConfigValues() override;

private:
  QtProperty*               doubleProp_po;
  QtDoublePropertyManager*  doubleManager_po;
  QtDoublePropertyManager*  doubleManagerConfig_po;
  bool                      ignoreUpdates_b;
  QtProperty*               minProp_po;
  QtProperty*               maxProp_po;
};


} // namespace ce

