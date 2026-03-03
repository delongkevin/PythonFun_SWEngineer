#include "FileEditFactory.h"
#include "FileEditWidget.h"


FileEditFactory::FileEditFactory(QWidget* parent /* = 0*/)
  : QtAbstractEditorFactory(parent)
{

}

FileEditFactory::~FileEditFactory()
{

}


QWidget* FileEditFactory::createEditor(FilePathManager *manager, QtProperty *property, QWidget *parent)
{
	// The createEditor() function creates and initializes a FileEdit widget, adds the editor to the internal maps: 
	FileEditWidget *editor = new FileEditWidget(parent);
	editor->setFilePath(manager->value(property));
	editor->setFilter(manager->filter(property));

  PropertyToFileEditorListMap::iterator it = m_CreatedEditors.find(property);
  if (it == m_CreatedEditors.end())
    it = m_CreatedEditors.insert(property, FileEditorList());
  it.value().append(editor);
  m_EditorToProperty.insert(editor, property);

	connect(editor, SIGNAL(filePathChanged(const QString&)), this, SLOT(slotSetValue(const QString&)));
	connect(editor, SIGNAL(destroyed(QObject*)), this, SLOT(slotEditorDestroyed(QObject*)));
	return editor;
}


void FileEditFactory::connectPropertyManager(FilePathManager *manager)
{
	connect(manager, SIGNAL(valueChanged(QtProperty*, const QString&)),
		this, SLOT(slotPropertyChanged(QtProperty*, const QString&)));
}

void FileEditFactory::disconnectPropertyManager(FilePathManager *manager)
{
	disconnect(manager, SIGNAL(valueChanged(QtProperty*, const QString&)),
		this, SLOT(slotPropertyChanged(QtProperty*, QString&)));
}

void FileEditFactory::slotPropertyChanged(QtProperty *property, const QString &value)
{
  const PropertyToFileEditorListMap::iterator it = m_CreatedEditors.find(property);
  if (it == m_CreatedEditors.end())
    return;
  QListIterator<FileEditWidget*> itEditor(it.value());

  while (itEditor.hasNext())
    itEditor.next()->setFilePath(value);
}

void FileEditFactory::slotFilterChanged(QtProperty *property, const QString &filter)
{
  const PropertyToFileEditorListMap::iterator it = m_CreatedEditors.find(property);
  if (it == m_CreatedEditors.end())
    return;
  QListIterator<FileEditWidget*> itEditor(it.value());

  while (itEditor.hasNext())
    itEditor.next()->setFilter(filter);
}

void FileEditFactory::slotSetValue(const QString &value)
{
  QObject *object = sender();
  const FileEditorToPropertyMap::ConstIterator ecend = m_EditorToProperty.constEnd();
  for (FileEditorToPropertyMap::ConstIterator itEditor = m_EditorToProperty.constBegin(); itEditor != ecend; ++itEditor)
    if (itEditor.key() == object) {
      QtProperty *property = itEditor.value();
      FilePathManager* manager = propertyManager(property);
      if (!manager)
        return;
      manager->setValue(property, value);
      return;
    }
}

void FileEditFactory::slotEditorDestroyed(QObject *object)
{
  const FileEditorToPropertyMap::iterator ecend = m_EditorToProperty.end();
  for (FileEditorToPropertyMap::iterator itEditor = m_EditorToProperty.begin(); itEditor !=  ecend; ++itEditor) {
    if (itEditor.key() == object) {
      FileEditWidget* editor = itEditor.key();
      QtProperty* property = itEditor.value();
      const PropertyToFileEditorListMap::iterator pit = m_CreatedEditors.find(property);
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

