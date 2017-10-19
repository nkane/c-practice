IF NOT EXIST .\build mkdir .\build
pushd .\build

cl /Od /MTd /Zi /nologo ..\main.c

xcopy /S /Q /Y /I ..\data .\data

popd
