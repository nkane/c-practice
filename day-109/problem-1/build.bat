IF NOT EXIST .\build mkdir .\build
pushd .\build

cl -Od -MTd -Zi -nologo ..\main.c

xcopy ..\data .\data /S /K /F /I /Y

popd
