#pragma once

#include <platform/PlatformAPI.h>

#include "QtUtils/PropertyBrowser/Properties/BaseProperty.h"
#include "QTUtils/Dialogs/ListDialog.h"

class QtProperty;
class ListChoiceManager;

namespace tsdk
{

class PropertyFactory;

class ListChoiceProperty : public BaseProperty
{
  Q_OBJECT

public:
  ListChoiceProperty();
  virtual ~ListChoiceProperty();

  virtual void init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b) override;
  virtual QtProperty* getTopLevelProperty() const;

  void setValues(const QList<ListDialogItemData>& listItems);
  void setUserData(const QVariant& val);
  void setName(const QString& val);

signals:
  void selectionChanged(const QVariant& value);

private slots:
  void selectionChanged(QtProperty* i_Property_po, const QVariant& value);

private:
  QtProperty*         choiceProp_po;
  ListChoiceManager*  choiceManager_po;
  bool                ignoreUpdates_b;
};


} // namespace ce

