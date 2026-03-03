#pragma once

#include <QObject.h>
#include <QString.h>
#include <QList.h>
#include <platform/PlatformAPI.h>

#include "QtUtils/PropertyBrowser/Properties/BaseProperty.h"

class QtProperty;
class QtEnumPropertyManager;

namespace tsdk
{

class PropertyFactory;

class ComboBoxProperty : public BaseProperty
{
  Q_OBJECT

public:
  ComboBoxProperty();
  virtual ~ComboBoxProperty();

  virtual void init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b) override;
  virtual QtProperty* getTopLevelProperty() const;

  void setValues_v(const QList<QString>& i_Values_ro);
  void select_v(const QString& i_Value_ro);

signals:
  void enumSelectionChanged(const QString& i_Value_ro);

private slots:
  void valueChanged(QtProperty* i_Property_po, int i_Value_s32);

private:
  sint32_t findIndex_s32(const QString& i_Name_ro);


private:
  QtEnumPropertyManager* enumManager_po;
  QtProperty* enumProperty_po;
  bool ignoreValueChanged_b;

};


} // namespace ce

