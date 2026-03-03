#pragma once

#include <QObject.h>
#include <platform/PlatformAPI.h>

class QtProperty;
class QtBrowserItem;

namespace tsdk
{

class PropertyFactory;

class BaseProperty : public QObject
{
  Q_OBJECT

public:
  BaseProperty();
  virtual ~BaseProperty();

  virtual void init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b);
  virtual void addTopLevelProperty_v();
  virtual QtProperty* getTopLevelProperty() const = 0;

  // set whether to show additional sub-properties which allow the user to set additional values (like min-max, etc)
  void showConfigValues(bool show);

  void removeSubProperty(BaseProperty* prop);

  void setVisible_v(bool i_Visible_b);

  void setBrowserItem_v(QtBrowserItem* item);

protected:
  virtual void onShowConfigValues();

private:
  void setBrowserItem_v(QtBrowserItem* i_Item_o, QtProperty* i_Prop_po);

public:
  PropertyFactory*  propFactory_po;
  QtProperty*       parent_po;
  QString           groupName_o;
  QtBrowserItem*    browserItem_po;
  bool              readOnly_b;
  bool              showConfigValues_b;
};


} // namespace ce
