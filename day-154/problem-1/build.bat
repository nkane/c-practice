IF NOT EXIST .\build MKDIR .\build
PUSHD .\build

cl /MTd /Od /Zi /nolog ..\main.c

POPD
