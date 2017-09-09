IF NOT EXIST .\build mkdir .\build
pushd .\build

:: optimizations turned off!
::cl -Od -MTd -Zi -nologo ..\main.cpp

:: optimizations turned on!
cl -Ox -MTd -Zi -nologo ..\main.cpp

popd

