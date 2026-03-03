#pragma once

#include <QTreeWidgetItem>
#include <QIcon>

#include <QtUtils/Resources/Icons.h>


class TreeItemBase : public QTreeWidgetItem
{
public:
  TreeItemBase() { }
  virtual ~TreeItemBase() { }

  virtual std::string getSerializeTagName() = 0;

  virtual void onAdd()      { }
  virtual void onDelete()   { }
  virtual void onExpand()   { }
  virtual void onCollapse() { }
  virtual void onChange()   { }
  virtual void onClicked()  { }
};