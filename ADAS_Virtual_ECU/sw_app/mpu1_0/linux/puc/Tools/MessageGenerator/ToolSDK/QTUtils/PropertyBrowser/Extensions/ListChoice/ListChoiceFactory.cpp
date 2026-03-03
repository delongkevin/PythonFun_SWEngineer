#include "ListChoiceFactory.h"


ListChoiceFactory::ListChoiceFactory(QWidget *parent /*= 0*/)
  : QtAbstractEditorFactory(parent)
{

}

ListChoiceFactory::~ListChoiceFactory()
{

}

QWidget* ListChoiceFactory::createEditor(ListChoiceManager* manager, QtProperty* property, QWidget* parent)
{
  // The createEditor() function creates and initializes a widget, adds the editor to the internal maps: 
  ListChoiceWidget *editor = new ListChoiceWidget(parent);
  editor->setListName(manager->listName(property));
  editor->setListItems(manager->listItems(property));

  PropertyToListChoiceEditorMap::iterator it = m_CreatedEditors.find(property);
  if (it == m_CreatedEditors.end())
    it = m_CreatedEditors.insert(property, ChoiceEditorList());
  it.value().append(editor);
  m_EditorToProperty.insert(editor, property);

  connect(editor, SIGNAL(destroyed(QObject*)), this, SLOT(slotEditorDestroyed(QObject*)));
  connect(editor, SIGNAL(userDataChanged(const QVariant&)), this, SLOT(slotSelectionChanged(const QVariant&)));

  return editor;
}

void ListChoiceFactory::connectPropertyManager(ListChoiceManager* manager)
{
  connect(manager, SIGNAL(listNameChanged(QtProperty*, const QString&)),
    this, SLOT(slotPropertyChanged(QtProperty*, const QString&)));
}

void ListChoiceFactory::disconnectPropertyManager(ListChoiceManager* manager)
{
  disconnect(manager, SIGNAL(listNameChanged(QtProperty*, const QString&)),
    this, SLOT(slotPropertyChanged(QtProperty*, QString&)));
}

void ListChoiceFactory::slotSelectionChanged(const QVariant& value)
{
  QObject *object = sender();
  const ListChoiceEditorToPropertyMap::ConstIterator ecend = m_EditorToProperty.constEnd();
  for (ListChoiceEditorToPropertyMap::ConstIterator itEditor = m_EditorToProperty.constBegin(); itEditor != ecend; ++itEditor)
    if (itEditor.key() == object) {
      QtProperty *property = itEditor.value();
      ListChoiceManager* manager = propertyManager(property);
      if (!manager)
        return;
      manager->setSelectionData(property, value);
      return;
    }
}

void ListChoiceFactory::slotPropertyChanged(QtProperty* property, const QString &value)
{
  const PropertyToListChoiceEditorMap::iterator it = m_CreatedEditors.find(property);
  if (it == m_CreatedEditors.end())
    return;
  QListIterator<ListChoiceWidget*> itEditor(it.value());

  while (itEditor.hasNext())
    itEditor.next()->setListName(value);
}

void ListChoiceFactory::slotEditorDestroyed(QObject* object)
{
  const ListChoiceEditorToPropertyMap::iterator ecend = m_EditorToProperty.end();
  for (ListChoiceEditorToPropertyMap::iterator itEditor = m_EditorToProperty.begin(); itEditor !=  ecend; ++itEditor) {
    if (itEditor.key() == object) {
      ListChoiceWidget* editor = itEditor.key();
      QtProperty* property = itEditor.value();
      const PropertyToListChoiceEditorMap::iterator pit = m_CreatedEditors.find(property);
      if (pit != m_CreatedEditors.end()) {
        pit.value().removeAll(editor);
        if (pit.value().empty())
          m_CreatedEditors.erase(pit);
      }
      m_EditorToProperty.erase(itEditor);
      return;
    }
  }
}
