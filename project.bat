@echo off

cd out
set argC=0
for %%x in (%*) do Set /A argC+=1

if %argC%==0 goto run

:: command line options
if %1==cfg goto config
if %1==make goto makefile
if %1==run goto run

echo Hello
:config
call cmake .. -DGLFW_BUILD_DOCS=OFF -G "Unix Makefiles"

:makefile
call make
goto end

:run
call NewTest

:end
cd ..