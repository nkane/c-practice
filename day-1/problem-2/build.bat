IF NOT EXIST .\build mkdir .\build
pushd .\build 

cl -Od -MTd -nologo -Zi ..\main.c

dir

popd
