IF NOT EXIST .\build MKDIR .\build
PUSHD .\build 

cl /Od /Zi /MTd /nologo ..\main.c

POPD
