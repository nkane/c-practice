IF NOT EXIST .\build mkdir .\build

pushd .\build

cl -Od -MTd -nologo ..\main.cpp

popd

