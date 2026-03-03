#include "PropertyFactory.h"

#include "QtUtils/PropertyBrowser/Properties/BaseProperty.h"

#include <platform/PlatformAPI.h>

#include <QDockWidget>
#include <QString>

#include <qtpropertymanager.h>
#include <QtTreePropertyBrowser>
#include <qteditorfactory.h>
#include <QtVariantProperty.h>

// Extensions
#include "Extensions/File/FilePathManager.h"
#include "Extensions/File/FileEditFactory.h"
#include "Extensions/Vector/VectorPropertyManager.h"
#include "Extensions/Vector/VectorFactory.h"
#include "Extensions/ListChoice/ListChoiceManager.h"
#include "Extensions/ListChoice/ListChoiceFactory.h"

namespace tsdk
{

PropertyFactory::PropertyFactory()
  : propertyEditor_po(NULL)
  , groupManager_po(NULL)
  , variantManager_po(NULL)
  , variantManagerReadOnly_po(NULL)
  , doubleManager_po(NULL)
  , doubleManagerReadOnly_po(NULL)
  , colorManager_po(NULL)
  , colorManagerReadOnly_po(NULL)
  , enumManager_po(NULL)
  , enumManagerReadOnly_po(NULL)
  , intManager_po(NULL)
  , intManagerReadOnly_po(NULL)
  , boolManager_po(NULL)
  , boolManagerReadOnly_po(NULL)
  , stringManager_po(NULL)
  , stringManagerReadOnly_po(NULL)
  , filePathManager_po(NULL)
  , filePathManagerReadOnly_po(NULL)
  , vectorManager_po(NULL)
  , vectorManagerReadOnly_po(NULL)
  , listChoiceManager_po(NULL)
  , listChoiceManagerReadOnly_po(NULL)
  , variantFactory_po(NULL)
  , colorFactory_po(NULL)
  , doubleSpinBoxFactory_po(NULL)
  , spinBoxFactory_po(NULL)
  , comboBoxFactory_po(NULL)
  , checkBoxFactory_po(NULL)
  , lineFactory_po(NULL)
  , fileFactory_po(NULL)
  , vectorFactory_po(NULL)
  , listChoiceFactory_po(NULL)
{

}

PropertyFactory::~PropertyFactory()
{

}

void PropertyFactory::init_v(QDockWidget* b_Parent_po)
{
  propertyEditor_po = new QtTreePropertyBrowser(b_Parent_po);
  propertyEditor_po->setRootIsDecorated(true);

  if (b_Parent_po)
  {
    b_Parent_po->setWidget(propertyEditor_po);
  }
  
  // create managers
  groupManager_po             = new QtGroupPropertyManager();
  variantManager_po           = new QtVariantPropertyManager();
  variantManagerReadOnly_po   = new QtVariantPropertyManager();
  doubleManager_po            = new QtDoublePropertyManager();
  doubleManagerReadOnly_po    = new QtDoublePropertyManager();
  colorManager_po             = new QtColorPropertyManager();
  colorManagerReadOnly_po     = new QtColorPropertyManager();
  enumManager_po              = new QtEnumPropertyManager();
  enumManagerReadOnly_po      = new QtEnumPropertyManager();
  intManager_po               = new QtIntPropertyManager();
  intManagerReadOnly_po       = new QtIntPropertyManager();
  boolManager_po              = new QtBoolPropertyManager();
  boolManagerReadOnly_po      = new QtBoolPropertyManager();
  stringManager_po            = new QtStringPropertyManager();
  stringManagerReadOnly_po    = new QtStringPropertyManager();
  
  // Extensions
  filePathManager_po           = new FilePathManager();
  filePathManagerReadOnly_po   = new FilePathManager();
  vectorManager_po             = new VectorPropertyManager();
  vectorManagerReadOnly_po     = new VectorPropertyManager();
  listChoiceManager_po         = new ListChoiceManager();
  listChoiceManagerReadOnly_po = new ListChoiceManager();

  // create Factories
  variantFactory_po       = new QtVariantEditorFactory();
  doubleSpinBoxFactory_po = new QtDoubleSpinBoxFactory();
  spinBoxFactory_po       = new QtSpinBoxFactory();
  comboBoxFactory_po      = new QtEnumEditorFactory();
  colorFactory_po         = new QtColorEditorFactory();
  checkBoxFactory_po      = new QtCheckBoxFactory();
  lineFactory_po          = new QtLineEditFactory();

  // Extensions
  fileFactory_po          = new FileEditFactory();
  vectorFactory_po        = new VectorFactory();
  listChoiceFactory_po    = new ListChoiceFactory();

  // set factories for managers, set no factories for read only managers
  propertyEditor_po->setFactoryForManager(variantManager_po, variantFactory_po);
  propertyEditor_po->setFactoryForManager(doubleManager_po, doubleSpinBoxFactory_po);
  propertyEditor_po->setFactoryForManager(intManager_po, spinBoxFactory_po);
  propertyEditor_po->setFactoryForManager(colorManager_po, colorFactory_po);
  propertyEditor_po->setFactoryForManager(enumManager_po, comboBoxFactory_po);
  propertyEditor_po->setFactoryForManager(boolManager_po, checkBoxFactory_po);
  propertyEditor_po->setFactoryForManager(stringManager_po, lineFactory_po);

  // Extensions
  propertyEditor_po->setFactoryForManager(filePathManager_po, fileFactory_po);
  propertyEditor_po->setFactoryForManager(vectorManager_po, vectorFactory_po);
  propertyEditor_po->setFactoryForManager(listChoiceManager_po, listChoiceFactory_po);
}


void PropertyFactory::deleteProperty_po(BaseProperty* prop)
{
  baseProps.removeOne(prop);
  propertyEditor_po->removeProperty(prop->getTopLevelProperty());
}


} // namespace ce