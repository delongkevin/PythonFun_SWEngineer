#pragma once

#include <QList>
#include "qtpropertybrowser.h"

class QDockWidget;
class QString;
class QtProperty;

class QtTreePropertyBrowser;

class QtVariantPropertyManager;
class QtGroupPropertyManager;
class QtDoublePropertyManager;
class QtColorPropertyManager;
class QtEnumPropertyManager;
class QtIntPropertyManager;
class QtBoolPropertyManager;
class QtStringPropertyManager;

// Extensions
class FilePathManager;
class VectorPropertyManager;
class ListChoiceManager;

class QtVariantEditorFactory;
class QtDoubleSpinBoxFactory;
class QtSpinBoxFactory;
class QtEnumEditorFactory;
class QtColorEditorFactory;
class QtCheckBoxFactory;
class QtLineEditFactory;

// Extensions
class FileEditFactory;
class VectorFactory;
class ListChoiceFactory;

class PropertyManager;

namespace tsdk
{

class BaseProperty;

class PropertyFactory
{
public:
  PropertyFactory();
  ~PropertyFactory();

  void init_v(QDockWidget* b_Parent_po);

  template <class T>
  T* createProperty_po(const char* i_GroupName_pc, QtProperty* b_Parent_po, bool i_ReadOnly_b)
  {
    BaseProperty* v_Property_po = new T();
    v_Property_po->init_v(this, i_GroupName_pc, b_Parent_po, i_ReadOnly_b);
    baseProps.push_back(v_Property_po);
    return static_cast<T*>(v_Property_po);
  }

  void deleteProperty_po(BaseProperty* prop);

  QtTreePropertyBrowser*    getPropEditor_po()                          const { return propertyEditor_po; }
  QtGroupPropertyManager*   getGroupManager_po()                        const { return groupManager_po; }
  QtVariantPropertyManager* getVariantManager_po(bool i_ReadOnly_b)     const { return i_ReadOnly_b ? variantManagerReadOnly_po     : variantManager_po;    }
  QtDoublePropertyManager*  getDoubleManager_po(bool i_ReadOnly_b)      const { return i_ReadOnly_b ? doubleManagerReadOnly_po      : doubleManager_po;     }
  QtColorPropertyManager*   getColorManager_po(bool i_ReadOnly_b)       const { return i_ReadOnly_b ? colorManagerReadOnly_po       : colorManager_po;      }
  QtEnumPropertyManager*    getEnumManager_po(bool i_ReadOnly_b)        const { return i_ReadOnly_b ? enumManagerReadOnly_po        : enumManager_po;       }
  QtIntPropertyManager*     getIntManager_po(bool i_ReadOnly_b)         const { return i_ReadOnly_b ? intManagerReadOnly_po         : intManager_po;        }
  QtBoolPropertyManager*    getBoolManager_po(bool i_ReadOnly_b)        const { return i_ReadOnly_b ? boolManagerReadOnly_po        : boolManager_po;       }
  QtStringPropertyManager*  getStringManager_po(bool i_ReadOnly_b)      const { return i_ReadOnly_b ? stringManagerReadOnly_po      : stringManager_po;     }
  FilePathManager*          getFileManager_po(bool i_ReadOnly_b)        const { return i_ReadOnly_b ? filePathManagerReadOnly_po    : filePathManager_po;   }
  VectorPropertyManager*    getVectorManager_po(bool i_ReadOnly_b)      const { return i_ReadOnly_b ? vectorManagerReadOnly_po      : vectorManager_po;     }
  ListChoiceManager*        getListChoiceManager_po(bool i_ReadOnly_b)  const { return i_ReadOnly_b ? listChoiceManagerReadOnly_po  : listChoiceManager_po; }

  const QList<BaseProperty*>& getPropList_ro() const { return baseProps; }

private:
  QtTreePropertyBrowser*    propertyEditor_po;

  QtGroupPropertyManager*   groupManager_po;
  QtVariantPropertyManager* variantManager_po;
  QtVariantPropertyManager* variantManagerReadOnly_po;
  QtDoublePropertyManager*  doubleManager_po;
  QtDoublePropertyManager*  doubleManagerReadOnly_po;
  QtColorPropertyManager*   colorManager_po;
  QtColorPropertyManager*   colorManagerReadOnly_po;
  QtEnumPropertyManager*    enumManager_po;
  QtEnumPropertyManager*    enumManagerReadOnly_po;
  QtIntPropertyManager*     intManager_po;
  QtIntPropertyManager*     intManagerReadOnly_po;
  QtBoolPropertyManager*    boolManager_po;
  QtBoolPropertyManager*    boolManagerReadOnly_po;
  QtStringPropertyManager*  stringManager_po;
  QtStringPropertyManager*  stringManagerReadOnly_po;

  // Extensions
  FilePathManager*          filePathManager_po;
  FilePathManager*          filePathManagerReadOnly_po;
  VectorPropertyManager*    vectorManager_po;
  VectorPropertyManager*    vectorManagerReadOnly_po;
  ListChoiceManager*        listChoiceManager_po;
  ListChoiceManager*        listChoiceManagerReadOnly_po;


  QtVariantEditorFactory*   variantFactory_po;
  QtColorEditorFactory*     colorFactory_po;
  QtDoubleSpinBoxFactory*   doubleSpinBoxFactory_po;
  QtSpinBoxFactory*         spinBoxFactory_po;
  QtEnumEditorFactory*      comboBoxFactory_po;
  QtCheckBoxFactory*        checkBoxFactory_po;
  QtLineEditFactory*        lineFactory_po;

  // Extensions
  FileEditFactory*          fileFactory_po;
  VectorFactory*            vectorFactory_po;
  ListChoiceFactory*        listChoiceFactory_po;

  QList<BaseProperty*>      baseProps;
};

} // namespace ce

#pragma once
