IF NOT EXIST ..\build MKDIR .\build
PUSHD .\build

cl /Od /MTd /Zi /nologo ..\main.c

XCOPY /Y /I /Q /S ..\data .\data

POPD
