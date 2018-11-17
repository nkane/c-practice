@ECHO OFF
IF NOT EXIST .\build MKDIR .\build
PUSHD .\build

cl /Od /MTd /Zi /nologo ..\main.c

POPD
