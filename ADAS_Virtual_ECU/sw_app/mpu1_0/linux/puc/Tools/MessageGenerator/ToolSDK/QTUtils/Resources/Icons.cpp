#include "Icons.h"

namespace tsdk
{

  Icons::Icons()
    : Folder    (":/Common/Icons/Folder.png")
    , FolderOpen(":/Common/Icons/FolderOpen.png")
    , Delete    (":/Common/Icons/Delete.png")
    , Enum      (":/Common/Icons/enumeration.png")
    , EnumEntry (":/Common/Icons/enumEntry.png")
    , Component (":/Common/Icons/component.png")
    , Template  (":/Common/Icons/template.png")
    , Asset     (":/Common/Icons/asset.png")
	, AssetLink (":/Common/Icons/assetLink.png")
    , Float     (":/Common/Icons/float32.png")
	, Float64   (":/Common/Icons/float64.png")
    , SInt32    (":/Common/Icons/int32.png")
    , UInt8     (":/Common/Icons/uint8.png")
	, SInt8     (":/Common/Icons/int8.png")
	, UInt16    (":/Common/Icons/uint16.png")
	, SInt16    (":/Common/Icons/int16.png")
	, UInt32    (":/Common/Icons/uint32.png")
	, UInt64    (":/Common/Icons/uint64.png")
	, SInt64    (":/Common/Icons/int64.png")
    , String    (":/Common/Icons/string.png")
    , Array     (":/Common/Icons/array.png")
    , Vector    (":/Common/Icons/vector.png")
    , Struct    (":/Common/Icons/struct.png")
    , File      (":/Common/Icons/File.png")
  {
  }

  Icons* Icons::Get()
  {
    static Icons* instance = new Icons();
    return instance;
  }

} // namespace tsdk