cl /I..\..\Headers /I..\..\Experiments\Win32\SQLite3 /GR /EHsc /FeOVIMGenericSQLite.DLL /LD OVIMGenericSQLite.cpp /link /DEF:..\..\Experiments\Win32\OVModule.DEF ..\..\Experiments\Win32\SQLite3\sqlite3.lib
pause