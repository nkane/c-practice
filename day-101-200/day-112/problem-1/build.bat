IF NOT EXIST .\build mkdir .\build
pushd .\build

cl -Od -MTd -Zi -nologo ..\main.c

xcopy /Y /S /I ..\data .\data

popd
