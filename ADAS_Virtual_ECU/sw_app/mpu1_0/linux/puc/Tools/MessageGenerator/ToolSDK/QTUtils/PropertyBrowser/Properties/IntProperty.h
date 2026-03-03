#pragma once

#include <platform/PlatformAPI.h>

#include "QtUtils/PropertyBrowser/Properties/BaseProperty.h"

class QtProperty;
class QtIntPropertyManager;

namespace tsdk
{

class PropertyFactory;

class IntProperty : public BaseProperty
{
  Q_OBJECT

public:
  IntProperty();
  virtual ~IntProperty();

  virtual void init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b) override;
  virtual QtProperty* getTopLevelProperty() const;

  void setMin_v(sint32_t i_Min_s32);
  void setMax_v(sint32_t i_Max_s32);
  void setMinMax_v(sint32_t i_Min_s32, sint32_t i_Max_s32);
  void setValue_v(int i_Value_b);
  int getValue_s32() const;

signals:
  void intChanged(int i_Value_s32);
  void minChanged(int i_Value_s32);
  void maxChanged(int i_Value_s32);

private slots:
  void valueChanged(QtProperty* i_Property_po, int i_Value_s32);
  void configValueChanged(QtProperty* i_Property_po, int i_Value_s32);

protected:
  virtual void onShowConfigValues() override;

private:
  QtProperty*             intProp_po;
  QtIntPropertyManager*   intManager_po;
  QtIntPropertyManager*   intManagerConfig_po;
  bool                    ignoreUpdates_b;

  QtProperty*             minProp_po;
  QtProperty*             maxProp_po;
};


} // namespace ce
