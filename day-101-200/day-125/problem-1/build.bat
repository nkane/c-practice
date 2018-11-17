IF NOT EXIST .\build mkdir .\build
pushd .\build

cl /Od /MTd /Zi /nologo ..\main.c
xcopy /Y /Q /S /I  ..\data .\data

popd
