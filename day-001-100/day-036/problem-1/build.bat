IF NOT EXIST .\build mkdir build
pushd .\build

cl -MTd -Od -nologo -Zi ..\main.cpp

dir

popd

