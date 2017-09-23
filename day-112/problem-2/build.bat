IF NOT EXIST .\build mkdir .\build
pushd .\build

IF NOT EXIST .\data mkdir .\data

cl -Od -MTd -Zi -nologo ..\main.c

popd
