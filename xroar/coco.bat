@echo off
set curdir=%cd%
set binary=%~f1
cd %~dp0
start xroar.exe -machine cocous %binary% 
cd %curdir%
