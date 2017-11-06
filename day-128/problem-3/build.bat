@ECHO OFF
IF NOT EXIST .\build MKDIR .\build
PUSHD .\build

cl /Oz /MTd /Zi /nologo ..\main.c

POPD
