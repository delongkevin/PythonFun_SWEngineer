#pragma once

#include <platform/PlatformAPI.h>

#include "QtUtils/PropertyBrowser/Properties/BaseProperty.h"

class QtProperty;
class QtBoolPropertyManager;

namespace tsdk
{

class PropertyFactory;

class BoolProperty : public BaseProperty
{
  Q_OBJECT

public:
  BoolProperty();
  virtual ~BoolProperty();

  virtual void init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b) override;
  virtual QtProperty* getTopLevelProperty() const;

  void setValue_v(bool i_Value_b);
  bool_t getValue_b() const;

signals:
  void boolChanged(bool i_Value_b);

private slots:
  void valueChanged(QtProperty* i_Property_po, bool i_Value_b);

private:
  QtProperty*             boolProp_po;
  QtBoolPropertyManager*  boolManager_po;
  bool                    ignoreUpdates_b;
};


} // namespace ce
