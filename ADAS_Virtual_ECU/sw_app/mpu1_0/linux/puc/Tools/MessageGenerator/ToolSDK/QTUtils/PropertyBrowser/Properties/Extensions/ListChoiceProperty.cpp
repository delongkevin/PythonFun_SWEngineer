#include "ListChoiceProperty.h"

#include <platform/PlatformAPI.h>

#include <qtpropertybrowser.h>
#include <qtpropertymanager.h>
#include <qttreepropertybrowser.h>

#include "QtUtils/PropertyBrowser/PropertyFactory.h"
#include "QtUtils/PropertyBrowser/Extensions/ListChoice/ListChoiceManager.h"

namespace tsdk
{

ListChoiceProperty::ListChoiceProperty()
  : BaseProperty()
  , choiceProp_po(NULL)
  , choiceManager_po(NULL)
  , ignoreUpdates_b(false)
{
}

ListChoiceProperty::~ListChoiceProperty()
{
}

void ListChoiceProperty::init_v(PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b)
{
  BaseProperty::init_v(b_PropFactory_po, i_GroupName_po, b_Parent_po, i_ReadOnly_b);

  choiceManager_po = propFactory_po->getListChoiceManager_po(i_ReadOnly_b);
  choiceProp_po    = choiceManager_po->addProperty(i_GroupName_po);

  connect(choiceManager_po, SIGNAL(selectionChanged(QtProperty*, const QVariant&)), this, SLOT(selectionChanged(QtProperty*, const QVariant&)));
}

QtProperty* ListChoiceProperty::getTopLevelProperty() const
{
  Assert(NULL != choiceProp_po);
  return choiceProp_po;
}

void ListChoiceProperty::setValues(const QList<ListDialogItemData>& listItems)
{
  ignoreUpdates_b = true;

  choiceManager_po->setListItems(choiceProp_po, listItems);

  ignoreUpdates_b = false;
}

void ListChoiceProperty::setUserData(const QVariant& val)
{
  ignoreUpdates_b = true;

  choiceManager_po->setSelectionData(choiceProp_po, val);

  ignoreUpdates_b = false;
}

void ListChoiceProperty::setName(const QString& val)
{
  ignoreUpdates_b = true;

  choiceManager_po->setListName(choiceProp_po, val);

  ignoreUpdates_b = false;
}

void ListChoiceProperty::selectionChanged(QtProperty* i_Property_po, const QVariant& value)
{
  if (ignoreUpdates_b)
  {
    return;
  }

  if (choiceProp_po == i_Property_po)
  {
    emit selectionChanged(value);
  }
}

} // namespace ce