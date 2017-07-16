IF NOT EXIST .\build mkdir .\build
pushd .\build

cl -Od -MTd -Zi ..\main.cpp

popd

