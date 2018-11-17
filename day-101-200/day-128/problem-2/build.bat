@ECHO OFF
IF NOT EXIST .\build MKDIR .\build
PUSHD .\build

XCOPY ..\data /S /Q /I /Y .\data

cl /Od /MTd /Zi /nologo ..\main.c

POPD
