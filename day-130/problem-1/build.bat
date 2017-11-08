@ECHO OFF
IF NOT EXIST .\build MKDIR .\build
pushd .\build

cl /Od /MTd /Zi /nologo ..\main.c

popd
