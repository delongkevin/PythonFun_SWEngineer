#pragma once

#include <qtpropertybrowser.h>
#include <qteditorfactory.h>
#include "FilePathManager.h"
#include "FileEditWidget.h"



// provide a factory which is able to produce FileEdit editors for our property manager: 
// The FileEditFactory is derived from the QtAbstractEditorFactory template class, using our FilePathManager class as the template argument. 
// This means that our factory is only able to create editors for our custom manager while allowing it to access the manager's enriched interface. 

// Internally, the task of each factory is to synchronize the state of the editors with the state of the properties. 
// Whenever an editor changes its value we need to tell the framework about it, and vice versa. 
// In our editor factory's editorToProperty map, we relate every editor created by the factory to the property it was created to edit. 
class FileEditFactory : public QtAbstractEditorFactory<FilePathManager>
{
	Q_OBJECT
public:
	FileEditFactory(QWidget *parent = 0);
	~FileEditFactory();

	//  The opposite relation is kept in the createdEditors map, where properties are related to editors. 
	// Since it is possible that two or more property browsers are displaying the same instance of a property, 
	// we may need to create many editors for the same property instance, so we keep a list of editors for each property.
	virtual QWidget* createEditor(FilePathManager* manager, QtProperty* property, QWidget* parent);
	virtual void connectPropertyManager(FilePathManager *manager);
	virtual void disconnectPropertyManager(FilePathManager *manager);

	// Combined with the private slots, these data structures allow us to inform the framework that an editor value has been changed, 
	// and let us update all relevant editors whenever the framework changes any of the properties.
	// When the factory is destroyed, the state of the properties is no longer synchronized, and the data shown by the editors is no longer valid.
	// For that reason, all the editors created by the factory are deleted in the factory's destructor. 
	// Therefore, when an editor is destroyed, we must ensure that it is removed from the internal maps. 
private slots:
	void slotPropertyChanged(QtProperty* property, const QString &value);
	void slotFilterChanged(QtProperty* property, const QString &filter);
	void slotSetValue(const QString& value);
	void slotEditorDestroyed(QObject* object);

private:
  typedef QList<FileEditWidget*> FileEditorList;
  typedef QMap<QtProperty*, FileEditorList> PropertyToFileEditorListMap;
  typedef QMap<FileEditWidget*, QtProperty*> FileEditorToPropertyMap;


	PropertyToFileEditorListMap m_CreatedEditors;
	FileEditorToPropertyMap m_EditorToProperty;
};