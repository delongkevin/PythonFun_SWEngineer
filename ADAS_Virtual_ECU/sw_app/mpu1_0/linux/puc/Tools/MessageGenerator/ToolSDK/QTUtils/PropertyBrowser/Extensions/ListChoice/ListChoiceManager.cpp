#include "ListChoiceManager.h"


ListChoiceManager::ListChoiceManager(QObject* parent /*= 0*/)
  : QtAbstractPropertyManager(parent)
{

}

ListChoiceManager::~ListChoiceManager()
{

}

QString ListChoiceManager::listName(const QtProperty *property) const
{
  if (!theValues.contains(property)) 
    return "";

  return theValues[property].ListName;
}

QList<ListDialogItemData> ListChoiceManager::listItems(const QtProperty* property) const
{
  if (!theValues.contains(property)) 
  {
    QList<ListDialogItemData> emptyDummy;
    return emptyDummy;
  }
  return theValues[property].ListItems;
}

QVariant ListChoiceManager::selectionData(const QtProperty* property) const
{
  if (!theValues.contains(property)) 
    return QVariant();

  return theValues[property].UserData;
}

void ListChoiceManager::setListName(QtProperty* property, const QString& listName)
{
  if (!theValues.contains(property)) 
    return;

  Data data = theValues[property];
  if (data.ListName == listName) 
    return;

  data.ListName = listName;
  theValues[property] = data;

  emit listNameChanged(property, data.ListName);
  emit propertyChanged(property);
}

void ListChoiceManager::setListItems(QtProperty* property, const QList<ListDialogItemData>& listItems)
{
  if (!theValues.contains(property)) 
    return;

  Data data = theValues[property];
  if (data.ListItems == listItems) 
    return;

  data.ListItems = listItems;
  theValues[property] = data;

  emit propertyChanged(property);
  emit listItemsChanged(property, data.ListItems);
}

void ListChoiceManager::setSelectionData(QtProperty* property, const QVariant& value)
{
  if (!theValues.contains(property)) 
    return;

  Data data = theValues[property];
  //if (data.UserData == value) 
  //  return;

  data.UserData = value;
  theValues[property] = data;

  emit propertyChanged(property);
  emit selectionChanged(property, data.UserData);
}

