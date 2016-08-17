
[Setup]
OutputBaseFilename=WinCMOC v0.1
AppName=WinCMOC
AppVersion=0.1
AppVerName=WinCMOC 0.1
AppPublisher=Geep Software
AppPublisherURL=https://sourceforge.net/projects/cmoc-win32/
AppSupportURL=https://sourceforge.net/projects/cmoc-win32/
AppUpdatesURL=https://sourceforge.net/projects/cmoc-win32/
DefaultDirName={drive:{win}}cmoc-win32
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
Source: "bin\cmocide.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\astyle.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\cmoc2.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\cmoc.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\lwar.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\lwasm2.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\lwasm.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\lwlink.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\lwobjdump.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\mcpp.exe"; DestDir: "{app}\bin"; Flags: ignoreversion

Source: "lib\*.a"; DestDir: "{app}\lib"; Flags: ignoreversion
Source: "lib\*.o"; DestDir: "{app}\lib"; Flags: ignoreversion
Source: "lib\*.txt"; DestDir: "{app}\lib"; Flags: ignoreversion

Source: "include\*.h"; DestDir: "{app}\include"; Flags: ignoreversion recursesubdirs
Source: "examples\*.c"; DestDir: "{app}\examples"; Flags: ignoreversion recursesubdirs

Source: "xroar\xroar.exe"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\xroar.pdf"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\README"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\COPYING.GPL"; DestDir: "{app}\xroar"; Flags: ignoreversion
Source: "xroar\ChangeLog"; DestDir: "{app}\xroar"; Flags: ignoreversion

[Icons]
Name: "{group}\WinCMOC Editor"; Filename: "{app}\bin\cmocide.exe"
Name: "{group}\{cm:UninstallProgram,WinCMOC}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\WinCMOC Editor"; Filename: "{app}\bin\cmocide.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\bin\cmocide.exe"; Description: "{cm:LaunchProgram,WinCMOC Editor}"; Flags: nowait postinstall skipifsilent

