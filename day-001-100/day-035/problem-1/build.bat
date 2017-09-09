IF NOT EXIST .\build mkdir build
pushd .\build

cl -nologo -MTd -Od -Zi ..\main.cpp

dir

popd
