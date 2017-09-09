IF NOT EXIST .\build mkdir .\build
pushd .\build

cl -MTd -Od -Zi -nologo ..\main.cpp

popd
