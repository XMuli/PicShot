@echo off

::delete build dir
if "%1"=="delete" goto _DEL

if not exist build md build

cd build
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -G "Visual Studio 15 2017" -A Win32 ../src
goto _END

:_DEL
rd build/s/q
goto _END

:_END