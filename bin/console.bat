@echo off
color A0

set PATH=%CD%\;%PATH%
set PATH=%CD%\..\xroar;%PATH%
set PATH=%CD%\..\vcc;%PATH%

echo WinCMOC Build Environment
echo -------------------------
echo. 
echo BUILD COMMANDS:
echo. 
echo   cmoc2 INPUTFILE ...
echo   lwasm [OPTION...] INPUTFILE or --help
echo   lwlink [OPTION...] INPUTFILE or --help
echo   lwar [OPTION...] ARCHIVE [FILE ...] or --help
echo   astyle --help
echo   cmoc --help
echo   writecocofile IMAGE.DSK [NATIVE_FILE] or --help
echo   mcpp --help
echo   cas2wav [OPTION]... INFILE OUTFILE
echo   wimgtool [INFILE]
echo. 

cmd /k



