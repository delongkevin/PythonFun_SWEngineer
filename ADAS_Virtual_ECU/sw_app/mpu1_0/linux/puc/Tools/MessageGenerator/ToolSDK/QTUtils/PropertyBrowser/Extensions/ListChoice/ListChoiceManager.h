#pragma once

#include <qtpropertybrowser.h>

#include <QMap>
#include <platform/PlatformAPI.h>
#include <QTUtils/Dialogs/ListDialog.h>

class ListChoiceManager : public QtAbstractPropertyManager
{
  Q_OBJECT
public:
  ListChoiceManager(QObject* parent = 0);
  ~ListChoiceManager();

  QString listName(const QtProperty* property) const;
  QList<ListDialogItemData> listItems(const QtProperty* property) const;
  QVariant selectionData(const QtProperty* property) const;

public slots:
  void setListName(QtProperty* property, const QString& listName);
  void setListItems(QtProperty* property, const QList<ListDialogItemData>& listItems);
  void setSelectionData(QtProperty* property, const QVariant& value);

signals:
  void listNameChanged(QtProperty* property, const QString& listName);
  void listItemsChanged(QtProperty* property, const QList<ListDialogItemData>& listItems);
  void selectionChanged(QtProperty* property, const QVariant& val);

protected:
  QString valueText(const QtProperty *property) const
  {
    return listName(property);
  }
  void initializeProperty(QtProperty *property)
  {
    Data data;
    data.ListName = "List";
    data.UserData = QVariant();

    theValues[property] = data;
  }
  void uninitializeProperty(QtProperty *property)
  {
    theValues.remove(property);
  }
private:
  struct Data 
  {
    QString ListName;
    QList<ListDialogItemData> ListItems;
    QVariant UserData;
  };
  QMap<const QtProperty*, Data> theValues;
};

