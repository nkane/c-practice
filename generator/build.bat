IF NOT EXIST .\build mkdir .\build
pushd .\build

cl /Od /MTd /Zi /nologo ..\win32_generator.cpp  /link /SUBSYSTEM:CONSOLE

popd

