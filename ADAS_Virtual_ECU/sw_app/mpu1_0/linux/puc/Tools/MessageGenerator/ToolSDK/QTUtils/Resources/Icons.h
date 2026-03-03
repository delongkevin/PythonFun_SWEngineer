#pragma once

#include <QIcon>

namespace tsdk
{

class Icons
{
private:
  Icons();

public:
  static Icons* Get();

  const QIcon Folder;
  const QIcon FolderOpen;
  const QIcon Delete;
  const QIcon Enum;
  const QIcon EnumEntry;
  const QIcon Component; 
  const QIcon Template;
  const QIcon Asset;
  const QIcon AssetLink;
  const QIcon Float;
  const QIcon Float64;
  const QIcon SInt32;
  const QIcon UInt8;
  const QIcon SInt8;
  const QIcon UInt16;
  const QIcon SInt16;
  const QIcon UInt32;
  const QIcon UInt64;
  const QIcon SInt64;
  const QIcon String;
  const QIcon Array;
  const QIcon Vector;
  const QIcon Struct;
  const QIcon File;
};


} // namespace tsdk