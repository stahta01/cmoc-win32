@echo off
color A0

set PATH=%CD%\;%PATH%
set PATH=%CD%\..\xroar;%PATH%
set PATH=%CD%\..\vcc;%PATH%
set PKGDATADIR=%CD%\..\include\

echo WinCMOC Build Environment
echo -------------------------
echo. 
echo BUILD COMMANDS:
echo. 
echo   cmoc          [OPTION...] INPUTFILE or --help
echo   cmoc2         INPUTFILE ...
echo   lwasm         [OPTION...] INPUTFILE or --help
echo   lwasm2        [OPTION...] INPUTFILE or --help
echo   lwlink        [OPTION...] INPUTFILE or --help
echo   lwar          [OPTION...] ARCHIVE [FILE ...] or --help
echo   writecocofile IMAGE.DSK [NATIVE_FILE] or --help
echo   cas2wav       [OPTION]... INPUTFILE OUTFILE
echo   wimgtool      [INPUTFILE]
echo   coco          [INPUTFILE] (xroar batch file)
echo   vcc           [INPUTFILE]
echo   astyle        --help
echo   mcpp          --help
echo. 

cmd /k



