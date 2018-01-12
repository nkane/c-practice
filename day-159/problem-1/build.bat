IF NOT EXIST .\build MKDIR .\build
PUSHD .\build

cl /MTd /Zi /Od /nologo ..\main.c

POPD
