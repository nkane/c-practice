IF NOT EXIST .\build mkdir .\build
pushd .\build

cl -Od -MTd -Zi -nologo ..\main.c

xcopy /S /I /Q /Y ..\data .\data

popd

