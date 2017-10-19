IF NOT .\build mkdir .\build
pushd .\build

cl /Od /MTd /Zi /nologo ..\main.c

popd
