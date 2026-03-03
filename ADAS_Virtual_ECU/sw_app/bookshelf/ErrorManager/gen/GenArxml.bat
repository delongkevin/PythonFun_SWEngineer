
for %%f in (*.xlsx) do (
    python C:\git\ARXML_Tool\ARXML.py "%%~nf.xlsx"
	del "%%~nf_ComponentTypes.arxml"
	del "%%~nf_ImplementationDataTypes.arxml"
	del "%%~nf_master_arxml.csv"
	del "%%~nf_PortInterfaces.arxml"
)

pause
