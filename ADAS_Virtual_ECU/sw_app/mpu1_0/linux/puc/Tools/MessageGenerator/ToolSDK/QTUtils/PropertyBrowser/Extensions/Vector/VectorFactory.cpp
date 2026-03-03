#include "VectorFactory.h"


VectorFactory::VectorFactory(QWidget *parent /*= 0*/)
  : QtAbstractEditorFactory(parent)
{

}

VectorFactory::~VectorFactory()
{

}

QWidget* VectorFactory::createEditor(VectorPropertyManager* manager, QtProperty* property, QWidget* parent)
{
  // The createEditor() function creates and initializes a widget, adds the editor to the internal maps: 
  VectorEditWidget *editor = new VectorEditWidget(parent);
  editor->setNumValues(manager->numValues(property));
  editor->setVectorName(manager->vectorName(property));
  editor->setPropertyWidget(manager->propertyWidget(property));

  PropertyToVectorEditorListMap::iterator it = m_CreatedEditors.find(property);
  if (it == m_CreatedEditors.end())
    it = m_CreatedEditors.insert(property, VectorEditorList());
  it.value().append(editor);
  m_EditorToProperty.insert(editor, property);

  connect(editor, SIGNAL(destroyed(QObject*)), this, SLOT(slotEditorDestroyed(QObject*)));

  connect(editor, SIGNAL(signalAddItem()), this, SLOT(slotAddValue()));
  connect(editor, SIGNAL(signalDeleteItem(uint32_t)), this, SLOT(slotDeleteValue(uint32_t)));
  connect(editor, SIGNAL(signalDeleteAll()), this, SLOT(slotDeleteAll()));

  return editor;
}

void VectorFactory::connectPropertyManager(VectorPropertyManager *manager)
{
}

void VectorFactory::disconnectPropertyManager(VectorPropertyManager *manager)
{
}

void VectorFactory::slotEditorDestroyed(QObject* object)
{
  const VectorEditorToPropertyMap::iterator ecend = m_EditorToProperty.end();
  for (VectorEditorToPropertyMap::iterator itEditor = m_EditorToProperty.begin(); itEditor !=  ecend; ++itEditor) {
    if (itEditor.key() == object) {
      VectorEditWidget* editor = itEditor.key();
      QtProperty* property = itEditor.value();
      const PropertyToVectorEditorListMap::iterator pit = m_CreatedEditors.find(property);
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

void VectorFactory::slotAddValue()
{
  QObject *object = sender();
  const VectorEditorToPropertyMap::ConstIterator ecend = m_EditorToProperty.constEnd();
  for (VectorEditorToPropertyMap::ConstIterator itEditor = m_EditorToProperty.constBegin(); itEditor != ecend; ++itEditor)
    if (itEditor.key() == object) {
      QtProperty *property = itEditor.value();
      VectorPropertyManager* manager = propertyManager(property);
      if (!manager)
        return;
      manager->addValue(property);
      return;
    }
}

void VectorFactory::slotDeleteValue(uint32_t index)
{
  QObject *object = sender();
  const VectorEditorToPropertyMap::ConstIterator ecend = m_EditorToProperty.constEnd();
  for (VectorEditorToPropertyMap::ConstIterator itEditor = m_EditorToProperty.constBegin(); itEditor != ecend; ++itEditor)
    if (itEditor.key() == object) {
      QtProperty *property = itEditor.value();
      VectorPropertyManager* manager = propertyManager(property);
      if (!manager)
        return;
      manager->deleteValue(property, index);
      return;
    }
}

void VectorFactory::slotDeleteAll()
{
  QObject *object = sender();
  const VectorEditorToPropertyMap::ConstIterator ecend = m_EditorToProperty.constEnd();
  for (VectorEditorToPropertyMap::ConstIterator itEditor = m_EditorToProperty.constBegin(); itEditor != ecend; ++itEditor)
    if (itEditor.key() == object) {
      QtProperty *property = itEditor.value();
      VectorPropertyManager* manager = propertyManager(property);
      if (!manager)
        return;
      manager->deleteAll(property);
      return;
    }
}

