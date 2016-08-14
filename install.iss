; NOTE: asmtoh is not needed for a working install. Remember to delete from bin before build

[Setup]
OutputBaseFilename=WinCMOC v0.1
AppName=WinCMOC
AppVersion=0.1
AppVerName=WinCMOC 0.1
AppPublisher=Geep Software
AppPublisherURL=https://sourceforge.net/projects/cmoc-win32/
AppSupportURL=https://sourceforge.net/projects/cmoc-win32/
AppUpdatesURL=https://sourceforge.net/projects/cmoc-win32/
DefaultDirName=\cmoc-win32
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
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "bin\cmocide.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "bin\*.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: "lib\*.a"; DestDir: "{app}\lib"; Flags: ignoreversion
Source: "lib\*.o"; DestDir: "{app}\lib"; Flags: ignoreversion
Source: "lib\*.txt"; DestDir: "{app}\lib"; Flags: ignoreversion
Source: "include\*.h"; DestDir: "{app}\include"; Flags: ignoreversion recursesubdirs
Source: "examples\*.c"; DestDir: "{app}\examples"; Flags: ignoreversion recursesubdirs

[Icons]
Name: "{group}\WinCMOC Editor"; Filename: "{app}\bin\cmocide.exe"
Name: "{group}\{cm:UninstallProgram,WinCMOC}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\WinCMOC Editor"; Filename: "{app}\bin\cmocide.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\bin\cmocide.exe"; Description: "{cm:LaunchProgram,WinCMOC Editor}"; Flags: nowait postinstall skipifsilent

