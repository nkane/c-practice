IF NOT EXIST .\build MKDIR .\build
PUSHD .\build 

cl /MTd /Od /Zi /nologo ..\main.c

POPD
