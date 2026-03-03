#pragma once

#include <qtpropertybrowser.h>
#include <qteditorfactory.h>

#include "ListChoiceManager.h"
#include "ListChoiceWidget.h"

class ListChoiceFactory : public QtAbstractEditorFactory<ListChoiceManager>
{
  Q_OBJECT
public:
  ListChoiceFactory(QWidget *parent = 0);
  ~ListChoiceFactory();

  //  The opposite relation is kept in the createdEditors map, where properties are related to editors. 
  // Since it is possible that two or more property browsers are displaying the same instance of a property, 
  // we may need to create many editors for the same property instance, so we keep a list of editors for each property.
  virtual QWidget* createEditor(ListChoiceManager* manager, QtProperty* property, QWidget* parent);
  virtual void connectPropertyManager(ListChoiceManager *manager);
  virtual void disconnectPropertyManager(ListChoiceManager *manager);

  // Combined with the private slots, these data structures allow us to inform the framework that an editor value has been changed, 
  // and let us update all relevant editors whenever the framework changes any of the properties.
  // When the factory is destroyed, the state of the properties is no longer synchronized, and the data shown by the editors is no longer valid.
  // For that reason, all the editors created by the factory are deleted in the factory's destructor. 
  // Therefore, when an editor is destroyed, we must ensure that it is removed from the internal maps. 
  private slots:
    void slotPropertyChanged(QtProperty* property, const QString &value);
    void slotEditorDestroyed(QObject* object);
    void slotSelectionChanged(const QVariant& value);

private:
  typedef QList<ListChoiceWidget*> ChoiceEditorList;
  typedef QMap<QtProperty*, ChoiceEditorList> PropertyToListChoiceEditorMap;
  typedef QMap<ListChoiceWidget*, QtProperty*> ListChoiceEditorToPropertyMap;

  PropertyToListChoiceEditorMap m_CreatedEditors;
  ListChoiceEditorToPropertyMap m_EditorToProperty;
};