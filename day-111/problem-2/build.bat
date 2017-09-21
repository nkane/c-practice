IF NOT EXIST .\build mkdir .\build
pushd .\build

cl -Od -MTd -Zi -nologo ..\main.c

copy ..\prices.dat .\

popd
