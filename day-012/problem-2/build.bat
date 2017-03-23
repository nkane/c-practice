IF NOT EXIST .\build mkdir .\build
pushd .\build

cl -Od -nologo -Zi ..\main.cpp

dir 

popd
