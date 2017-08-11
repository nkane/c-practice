IF NOT EXIST .\buid mkdir .\build
pushd .\build

cl -Od -MTd -Zi -nologo ..\main.cpp

popd
