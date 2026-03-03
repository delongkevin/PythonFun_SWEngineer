
GenerateBuildsys: RemoveWriteProtection.bat AutoBuild.bat
	AutoBuild.bat -gb

AutoBuildRelease: RemoveWriteProtection.bat AutoBuild.bat
	RemoveWriteProtection.bat
	AutoBuild.bat rel

AutoBuildDebug: RemoveWriteProtection.bat AutoBuild.bat
	RemoveWriteProtection.bat
	AutoBuild.bat deb

Flash: RemoveWriteProtection.bat Flash.bat
	RemoveWriteProtection.bat
	Flash.bat

FlashDebug: RemoveWriteProtection.bat FlashDebug.bat
	RemoveWriteProtection.bat
	FlashDebug.bat