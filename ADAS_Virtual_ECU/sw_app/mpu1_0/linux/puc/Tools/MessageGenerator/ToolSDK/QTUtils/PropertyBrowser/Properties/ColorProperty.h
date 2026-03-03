#pragma once

#include <QObject.h>

#include "QtUtils/PropertyBrowser/Properties/BaseProperty.h"

class QColor;
class QtProperty;
class QtColorPropertyManager;

namespace tsdk
{
  class PropertyFactory;
}

namespace ce
{


class ColorProperty : public tsdk::BaseProperty
{
  Q_OBJECT

public:
  ColorProperty();
  virtual ~ColorProperty();

  virtual void init_v(tsdk::PropertyFactory* b_PropFactory_po, const char* i_GroupName_po, QtProperty* b_Parent_po, bool i_ReadOnly_b) override;
  virtual QtProperty* getTopLevelProperty() const;

  void setColor(const QColor& i_Color_ro);

signals:
  void colorChanged(const QColor& i_Value_ro);

private slots:
  void valueChanged(QtProperty* i_Property_po, const QColor& i_Color_ro);

private:
  QtProperty*             colorProp_po;
  QtColorPropertyManager* colorManager_po;
  bool                    ignoreUpdates_b;
};


} // namespace ce

