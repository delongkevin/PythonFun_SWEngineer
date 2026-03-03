#pragma once

#include "TreeItemBase.h"

#include <QtUtils/Resources/Icons.h>

class FolderItem : public TreeItemBase
{
public:
  FolderItem() { setIcon(0, tsdk::Icons::Get()->Folder); }
  virtual ~FolderItem() {}

  virtual void onExpand()   override { setIcon(0, tsdk::Icons::Get()->FolderOpen); }
  virtual void onCollapse() override { setIcon(0, tsdk::Icons::Get()->Folder);     }

  virtual std::string getSerializeTagName() override;
};