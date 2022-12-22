@echo off

if not exist out mkdir out
cd out

set argc=0
for %%x in (%*) do Set /A argc+=1

if %argc%==0 goto run

:: command line options
if %1==cfg goto config
if %1==cfnb goto config
if %1==make goto makefile
if %1==run goto run

:config
call cmake .. -DGLFW_BUILD_DOCS=OFF -G "Unix Makefiles"
if %1==cfnb goto end

:makefile
call make
goto end

:run
call NewTest

:end
cd ..