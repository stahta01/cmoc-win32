
[Setup]
OutputBaseFilename=WinCMOC v0.6
AppName=WinCMOC
AppVersion=0.6
AppVerName=WinCMOC v0.6
AppPublisher=Geep Software
AppPublisherURL=https://sourceforge.net/projects/cmoc-win32/
AppSupportURL=https://sourceforge.net/projects/cmoc-win32/
AppUpdatesURL=https://sourceforge.net/projects/cmoc-win32/
DefaultDirName={sd}\cmoc-win32
DisableDirPage=no
DefaultGroupName=WinCMOC
DisableProgramGroupPage=yes
LicenseFile=COPYING
InfoBeforeFile=README
Compression=lzma
SolidCompression=yes
WizardImageFile=install.bmp
SetupIconFile=src\bin\ide\ide.ico

AppId={{809260E7-0DB2-4822-9044-8B044660922D}

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; 

[Files]
Source: "bin\astyle.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\bin2c.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\cas2wav.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\cmoc2.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\cmoc.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\cmocide.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\console.bat"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\cpp.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\exomizer.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\f9dasm.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\lwar.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\lwasm2.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\lwasm.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\lwlink.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\lwobjdump.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\lzss.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\mcpp.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\pic2raw.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\runwild.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\wimgtool.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\imgtool.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\writecocofile.exe"; DestDir: "{app}\bin"; Flags: ignoreversion

Source: "bin\cmocide\*.txt"; DestDir: "{app}\bin\cmocide"; Flags: ignoreversion onlyifdoesntexist

Source: "lib\liball.a"; DestDir: "{app}\lib"; Flags: ignoreversion
Source: "lib\*.o"; DestDir: "{app}\lib"; Flags: ignoreversion
Source: "lib\*.txt"; DestDir: "{app}\lib"; Flags: ignoreversion

Source: "include\*.h"; DestDir: "{app}\include"; Flags: ignoreversion recursesubdirs

Source: "doc\*.*"; DestDir: "{app}\doc"; Flags: ignoreversion recursesubdirs
Source: "dsk\disk0.dsk"; DestDir: "{app}\dsk"; Flags: ignoreversion onlyifdoesntexist
Source: "dsk\disk1.dsk"; DestDir: "{app}\dsk"; Flags: ignoreversion 
Source: "dsk\disk2.dsk"; DestDir: "{app}\dsk"; Flags: ignoreversion 
Source: "examples\*.c"; DestDir: "{app}\examples"; Flags: ignoreversion recursesubdirs

Source: "vcc\Vcc.exe"; DestDir: "{app}\vcc"; Flags: ignoreversion
Source: "vcc\Welcome to Vcc.pdf"; DestDir: "{app}\vcc"; Flags: ignoreversion
Source: "vcc\Vcc.ini"; DestDir: "{app}\vcc"; Flags: ignoreversion
Source: "vcc\orch90.dll"; DestDir: "{app}\vcc"; Flags: ignoreversion
Source: "vcc\mpi.dll"; DestDir: "{app}\vcc"; Flags: ignoreversion
Source: "vcc\IDE.dll"; DestDir: "{app}\vcc"; Flags: ignoreversion
Source: "vcc\harddisk.dll"; DestDir: "{app}\vcc"; Flags: ignoreversion
Source: "vcc\fd502.dll"; DestDir: "{app}\vcc"; Flags: ignoreversion

Source: "xroar\xroar.exe"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\coco.bat"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\dragon32.bat"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\dragon64.bat"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\xroar.pdf"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\xroar.conf"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\README"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\COPYING.GPL"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\ChangeLog"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\roms\*.rom"; DestDir: "{app}\xroar\roms"; Flags: ignoreversion
Source: "xroar\roms\readme.txt"; DestDir: "{app}\xroar\roms"; Flags: ignoreversion

[Icons]
Name: "{group}\WinCMOC Editor"; Filename: "{app}\bin\cmocide.exe"
Name: "{group}\{cm:UninstallProgram,WinCMOC}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\WinCMOC Editor"; Filename: "{app}\bin\cmocide.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\bin\cmocide.exe"; Description: "{cm:LaunchProgram,WinCMOC Editor}"; Flags: nowait postinstall skipifsilent

