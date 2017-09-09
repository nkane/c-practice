IF NOT EXIST .\bulid mkdir build
pushd .\build

cl -Od -MTd -nologo -Zi ..\main.cpp

dir

popd
