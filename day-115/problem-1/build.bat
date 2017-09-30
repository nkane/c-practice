IF NOT EXIST .\build mkdir .\build
pushd .\build

cl -Od -MTd -Zi -nologo ..\main.c

xcopy /Q /E /I /Y ..\data .\data

popd

