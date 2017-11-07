@ECHO OFF
IF NOT EXIST .\build MKDIR .\build
PUSHD .\build

IF NOT EXIST .\data MKDIR .\data

cl /Od /MTd /Zi /nologo ..\main.c 

POPD
