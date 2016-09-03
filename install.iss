
[Setup]
OutputBaseFilename=WinCMOC v0.5
AppName=WinCMOC
AppVersion=0.5
AppVerName=WinCMOC v0.5
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
Source: "bin\*.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\console.bat"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\cmocide\*.txt"; DestDir: "{app}\bin\cmocide"; Flags: ignoreversion onlyifdoesntexist

Source: "lib\*.a"; DestDir: "{app}\lib"; Flags: ignoreversion
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
Source: "xroar\xroar.pdf"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\xroar.conf"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\README"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\COPYING.GPL"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\ChangeLog"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\roms\readme.txt"; DestDir: "{app}\xroar\roms"; Flags: ignoreversion

[Icons]
Name: "{group}\WinCMOC Editor"; Filename: "{app}\bin\cmocide.exe"
Name: "{group}\{cm:UninstallProgram,WinCMOC}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\WinCMOC Editor"; Filename: "{app}\bin\cmocide.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\bin\cmocide.exe"; Description: "{cm:LaunchProgram,WinCMOC Editor}"; Flags: nowait postinstall skipifsilent

