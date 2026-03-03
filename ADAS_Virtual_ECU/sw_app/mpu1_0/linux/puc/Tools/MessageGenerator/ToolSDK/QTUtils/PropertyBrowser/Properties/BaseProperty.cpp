#include "QtUtils/PropertyBrowser/Properties/BaseProperty.h"

#include <qtpropertybrowser.h>
#include <qtpropertymanager.h>
#include <qttreepropertybrowser.h>

#include <platform/PlatformAPI.h>

#include "QtUtils/PropertyBrowser/PropertyFactory.h"


namespace tsdk
{

BaseProperty::BaseProperty()
  : propFactory_po(NULL)
  , parent_po(NULL)
  , groupName_o()
  , browserItem_po(NULL)
  , readOnly_b(false)
  , showConfigValues_b(false)
{

}

BaseProperty::~BaseProperty()
{
}

void BaseProperty::init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b)
{
  propFactory_po  = b_PropFactory_po;
  groupName_o     = i_GroupName_po;
  parent_po       = b_Parent_po;
  readOnly_b      = i_ReadOnly_b;
}

void BaseProperty::addTopLevelProperty_v()
{
  if (NULL != parent_po)
  {
    parent_po->addSubProperty(getTopLevelProperty());
  }
  else
  {
    browserItem_po = propFactory_po->getPropEditor_po()->addProperty(getTopLevelProperty());
    setBrowserItem_v(browserItem_po, getTopLevelProperty());
  }
}

void BaseProperty::showConfigValues(bool show)
{
  if (showConfigValues_b != show)
  {
    showConfigValues_b = show;
    onShowConfigValues();
  }
}

void BaseProperty::removeSubProperty(BaseProperty* prop)
{
  if (!prop)
  {
    return;
  }

  if (prop && prop->parent_po)
  {
    getTopLevelProperty()->removeSubProperty(prop->getTopLevelProperty());
    propFactory_po->deleteProperty_po(prop);
  }
  else
  {
    propFactory_po->deleteProperty_po(prop);
  }
}

void BaseProperty::setVisible_v(bool i_Visible_b)
{
  Assert(NULL != browserItem_po);
  propFactory_po->getPropEditor_po()->setItemVisible(browserItem_po, i_Visible_b);
}

void BaseProperty::setBrowserItem_v(QtBrowserItem* item)
{
  browserItem_po = item;
}

void BaseProperty::setBrowserItem_v(QtBrowserItem* i_Item_o, QtProperty* i_Prop_po)
{
  if (NULL == i_Item_o)
  {
    return;
  }

  for (int i = 0; i < propFactory_po->getPropList_ro().size(); ++i)
  {
    BaseProperty* baseProp = propFactory_po->getPropList_ro()[i];

    if (baseProp->getTopLevelProperty() == i_Item_o->property())
    {
      baseProp->setBrowserItem_v(i_Item_o);
    }
  }

  for (int j = 0; j < i_Item_o->children().size(); ++j)
  {
    setBrowserItem_v(i_Item_o->children()[j], i_Prop_po);
  }
}


void BaseProperty::onShowConfigValues()
{
}

} // namespace ce