#pragma once

#include <platform/PlatformAPI.h>

#include "QtUtils/PropertyBrowser/Properties/BaseProperty.h"

class QtProperty;
class QtStringPropertyManager;

namespace tsdk
{

class PropertyFactory;

class StringProperty : public BaseProperty
{
  Q_OBJECT

public:
  StringProperty();
  virtual ~StringProperty();

  virtual void init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b) override;
  virtual QtProperty* getTopLevelProperty() const;

  void setValue_v(const QString& i_Value_ro);

signals:
  void stringChanged(const QString& i_Value_ro);

private slots:
  void valueChanged(QtProperty* i_Property_po, const QString& i_Value_ro);

private:
  QtProperty*               stringProp_po;
  QtStringPropertyManager*  stringManager_po;
  bool                      ignoreUpdates_b;
};


} // namespace ce
