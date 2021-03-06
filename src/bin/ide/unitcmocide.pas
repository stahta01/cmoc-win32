(*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

Derek John Evans <https://sourceforge.net/u/buzzphp/profile/>
*)

unit UnitCmocIDE;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, ComCtrls, Controls, Dialogs, ExtCtrls, FileUtil, Forms, Graphics, LCLIntf, Math,
  Menus, MouseAndKeyInput, process, StreamIO, StrUtils, SynEdit, SynHighlighterAny,
  SysUtils, Types, UCmocDefs, UCmocIDE, UCmocMenuItem, UCmocPlatform, UCmocRbs,
  UCmocStringDynArray, UCmocSynEdit, UCmocUtils, UCmocXRoar, UnitCmocIDESynEdit;

type

  { TFormCmocIDE }

  TFormCmocIDE = class(TForm)
    AppProps: TApplicationProperties;
    ButtonBuild: TToolButton;
    ButtonCompile: TToolButton;
    ButtonCopy: TToolButton;
    ButtonCut: TToolButton;
    ButtonDelete: TToolButton;
    ButtonNew: TToolButton;
    ButtonOpen: TToolButton;
    ButtonPaste: TToolButton;
    ButtonRedo: TToolButton;
    ButtonRun: TToolButton;
    ButtonSave: TToolButton;
    ButtonSyntaxCheck: TToolButton;
    ButtonUndo: TToolButton;
    ImageList16: TImageList;
    MainMenu: TMainMenu;
    MenuEdit: TMenuItem;
    MenuEditCopy: TMenuItem;
    MenuEditCut: TMenuItem;
    MenuEditDelete: TMenuItem;
    MenuEditFind: TMenuItem;
    MenuEditFindNext: TMenuItem;
    MenuEditFormatSourceCode: TMenuItem;
    MenuEditLowercaseSelection: TMenuItem;
    MenuEditPaste: TMenuItem;
    MenuEditRedo: TMenuItem;
    MenuEditReplace: TMenuItem;
    MenuEditSelectAll: TMenuItem;
    MenuEditSep1: TMenuItem;
    MenuEditSep2: TMenuItem;
    MenuEditSep3: TMenuItem;
    MenuEditSep4: TMenuItem;
    MenuEditSep5: TMenuItem;
    MenuEditUndo: TMenuItem;
    MenuEditUppercaseSelection: TMenuItem;
    MenuEmulators: TMenuItem;
    MenuEmulatorsCoCo3: TMenuItem;
    MenuEmulatorsCoCo1: TMenuItem;
    MenuEmulatorsDragon200E: TMenuItem;
    MenuEmulatorsDragon32: TMenuItem;
    MenuEmulatorsDragon64: TMenuItem;
    MenuEmulatorsDynacmoMX1600: TMenuItem;
    MenuEmulatorsTanoDragon: TMenuItem;
    MenuFile: TMenuItem;
    MenuFileExit: TMenuItem;
    MenuFileNew: TMenuItem;
    MenuFileNewEditor: TMenuItem;
    MenuFileNewWindow: TMenuItem;
    MenuFileOpen: TMenuItem;
    MenuFileOpenInNewEditor: TMenuItem;
    MenuFileOpenInNewWindow: TMenuItem;
    MenuFileSave: TMenuItem;
    MenuFileSaveAs: TMenuItem;
    MenuFileSep1: TMenuItem;
    MenuFileSep2: TMenuItem;
    MenuFileSep3: TMenuItem;
    MenuHelp: TMenuItem;
    MenuHelpAbout: TMenuItem;
    MenuHelpCMOCManual: TMenuItem;
    MenuHelpCmocOnline: TMenuItem;
    MenuHelpCoCoArchive: TMenuItem;
    MenuHelpColorBasicSummary: TMenuItem;
    MenuHelpDiskBasicSummary: TMenuItem;
    MenuHelpExtendedBasicSummary: TMenuItem;
    MenuHelpFatCowIconsOnline: TMenuItem;
    MenuHelpLocalDocuments: TMenuItem;
    MenuHelpLWTools: TMenuItem;
    MenuHelpLWToolsManual: TMenuItem;
    MenuHelpMCPP: TMenuItem;
    MenuHelpOnlineHelp: TMenuItem;
    MenuHelpOpenRomFolder: TMenuItem;
    MenuHelpSep3: TMenuItem;
    MenuHelpVccEmulator: TMenuItem;
    MenuHelpWinCmocOnline: TMenuItem;
    MenuHelpXRoarEmulator: TMenuItem;
    MenuHelpSep1: TMenuItem;
    MenuEmulatorsCoCo2: TMenuItem;
    MenuEditSep6: TMenuItem;
    MenuItem1: TMenuItem;
    MenuItem3: TMenuItem;
    MenuEmulatorsEDTASM: TMenuItem;
    MenuEmulatorsSep2: TMenuItem;
    MenuToolsSep2: TMenuItem;
    MenuToolsDisassemble: TMenuItem;
    MenuToolsOpenDisk0: TMenuItem;
    MenuEmulatorsSep1: TMenuItem;
    MenuToolsOpenDisk1: TMenuItem;
    MenuToolsOpenDisk2: TMenuItem;
    MenuToolsSep1: TMenuItem;
    MenuTools: TMenuItem;
    MenuToolsMessImageTool: TMenuItem;
    MenuToolsConsole: TMenuItem;
    MenuRun: TMenuItem;
    MenuRunBuild: TMenuItem;
    MenuRunBuildAndRun: TMenuItem;
    MenuRunCompile: TMenuItem;
    MenuRunSep1: TMenuItem;
    MenuRunSyntaxCheck: TMenuItem;
    OpenDialog: TOpenDialog;
    OpenASM: TOpenDialog;
    Process: TProcess;
    SaveDialog: TSaveDialog;
    SplitterBottom: TSplitter;
    StatusBar: TStatusBar;
    SynAnySyn: TSynAnySyn;
    SynEditLog: TSynEdit;
    ToolBar: TToolBar;
    ToolButton1: TToolButton;
    ToolButton2: TToolButton;
    ToolButton4: TToolButton;
    procedure AppPropsException(ASender: TObject; AException: Exception);
    procedure ButtonCopyClick(ASender: TObject);
    procedure ButtonCutClick(ASender: TObject);
    procedure ButtonDeleteClick(ASender: TObject);
    procedure ButtonPasteClick(ASender: TObject);
    procedure ButtonRedoClick(ASender: TObject);
    procedure ButtonUndoClick(ASender: TObject);
    procedure FormCloseQuery(ASender: TObject; var ACanClose: boolean);
    procedure FormCreate(ASender: TObject);
    procedure FormShow(ASender: TObject);
    procedure MenuHelpClick(ASender: TObject);
    procedure MenuEditClick(ASender: TObject);
    procedure MenuEditFindClick(ASender: TObject);
    procedure MenuEditFindNextClick(ASender: TObject);
    procedure MenuEditFormatSourceCodeClick(ASender: TObject);
    procedure MenuEditLowercaseSelectionClick(ASender: TObject);
    procedure MenuEditReplaceClick(ASender: TObject);
    procedure MenuEditUndoClick(ASender: TObject);
    procedure MenuFileNewClick(ASender: TObject);
    procedure MenuFileNewWindowClick(ASender: TObject);
    procedure MenuFileOpenClick(ASender: TObject);
    procedure MenuFileExitClick(ASender: TObject);
    procedure MenuFileSaveAsClick(ASender: TObject);
    procedure MenuFileSaveClick(ASender: TObject);
    procedure MenuFileOpenInNewWindowClick(ASender: TObject);
    procedure MenuEditUppercaseSelectionClick(ASender: TObject);
    procedure MenuHelpOpenRomFolderClick(ASender: TObject);
    procedure MenuEmulatorsEDTASMClick(ASender: TObject);
    procedure MenuToolsDisassembleClick(ASender: TObject);
    procedure MenuRunCompileClick(ASender: TObject);
    procedure MenuRunBuildAndRunClick(ASender: TObject);
    procedure MenuEmulatorsClick(ASender: TObject);
    procedure MenuToolsConsoleClick(ASender: TObject);
    procedure MenuToolsMessImageToolClick(ASender: TObject);
    procedure SynEditLogChangeUpdating(ASender: TObject; AIsUpdating: boolean);
    procedure MenuHelpAboutClick(ASender: TObject);
    procedure MenuRunBuildClick(ASender: TObject);
    procedure MenuRunSyntaxCheckClick(ASender: TObject);
    procedure ToolBarPaint(ASender: TObject);
  strict private
    FSynEditLinesCount: integer;
    FTarget: string;
    FOptions, FLinkin: TStrings;
    FOrigin: cardinal;
  strict private
    function FileNameSrc: TFileName;
    function FileNameSrcExists: TFileName;
    function FileNameObj: TFileName;
    function FileNameOut: TFileName;
  strict private
    procedure CheckRoms;
  strict private
    procedure OpenBrowser(AURL: string);
    procedure ExecuteEmulator(AFileName: TFileName);
    procedure ExecuteMachine(const AName: string; const AFileName: TFileName);
    function Execute(const AExecutable: string; const AParameters: array of string;
      const AExternal: boolean): integer;
    function ExecuteTool(const ATool: string; const AParameters: array of string;
      const AExternal: boolean): integer;
  strict private
    function BeginProcess(const ADst: TFileName; const ASrc: array of TFileName): boolean;
    procedure EndProcess(const AMessage: string);
  public
    { public declarations }
  end;

var
  FormCmocIDE: TFormCmocIDE;

implementation

{$R *.lfm}

procedure TFormCmocIDE.FormCreate(ASender: TObject);
var
  LStream: CStringsStream;
begin
  FOptions := TStringList.Create;
  FLinkin := TStringList.Create;

  LStream := CStringsStream.Create(SynEditLog.Lines);
  AssignStream(Output, LStream);
  Rewrite(Output);
  LStream := CStringsStream.Create(SynEditLog.Lines);
  LStream.Task := 'Error';
  AssignStream(StdErr, LStream);
  Rewrite(StdErr);

  SetBounds(Left, Top, 640, 480);

  MenuEmulatorsCoCo3._SetVisible(OPlatform.IsWindows);
  MenuToolsConsole._SetVisible(OPlatform.IsWindows);
  MenuToolsDisassemble._SetVisible(OPlatform.IsWindows);
  MenuToolsMessImageTool._SetVisible(OPlatform.IsWindows);
end;

procedure TFormCmocIDE.FormShow(ASender: TObject);
begin
  FormCmocIDESynEdit.BorderStyle := bsNone;
  FormCmocIDESynEdit.Align := alClient;
  FormCmocIDESynEdit.Parent := Self;
  FormCmocIDESynEdit.Show;
  FormCmocIDESynEdit.SynEdit.SetFocus;

  with SynEditLog do begin
    Options := Options + [eoTabIndent, eoHideRightMargin];
    Options := Options - [eoSmartTabs];
    TabWidth := 2;
    Font.Quality := fqCleartype;
    Font.Name := FormCmocIDESynEdit.SynEdit.Font.Name;
    Font.Size := 8;
    BracketMatchColor.Background := clAqua;
    BracketMatchColor.Style := [];
    LineHighlightColor.Background := FormCmocIDESynEdit.SynEdit.LineHighlightColor.Background;
  end;
  OpenDialog.Filter := FormCmocIDESynEdit.SynAnySyn.DefaultFilter;
  SaveDialog.Filter := FormCmocIDESynEdit.SynAnySyn.DefaultFilter;
  SaveDialog.DefaultExt := FileExt_C;

  FormCmocIDESynEdit.Clear;

  if (ParamCount > 0) and FileExists(ParamStr(ParamCount)) then begin
    FormCmocIDESynEdit.LoadFromFile(ParamStr(ParamCount));
  end else if not Application.HasOption('nocode') then begin
    with FormCmocIDESynEdit.SynEdit.Lines do begin
      Add(EmptyStr);
      Add('#include <math.h>');
      Add('#include <ctype.h>');
      Add('#include <stdio.h>');
      Add('#include <stdlib.h>');
      Add('#include <string.h>');
      Add('#include <conio.h>');
      Add(EmptyStr);
      Add('int main(void)');
      Add('{');
      Add(StringOfChar(Char_SPC, FormCmocIDESynEdit.SynEdit.TabWidth) +
        'puts("WELCOME TO ' + UpperCase(Application.Title) + '!");');
      Add(StringOfChar(Char_SPC, FormCmocIDESynEdit.SynEdit.TabWidth) + 'return 0;');
      Add('}');
    end;
  end;
  if not Application.HasOption('nomaximize') then begin
    WindowState := wsMaximized;
  end;

  WriteLn('// Welcome to ', Application.Title);
  WriteLn('// Using: CMOC v', Ver_CMOC, ' + LWTOOLS v', Ver_LWTOOLS);
end;

procedure TFormCmocIDE.FormCloseQuery(ASender: TObject; var ACanClose: boolean);
var
  LFileName: TFileName;
begin
  ACanClose := not FormCmocIDESynEdit.Modified;
  if not ACanClose then begin
    LFileName := FormCmocIDESynEdit.FileName;
    if Length(LFileName) = 0 then begin
      LFileName := 'untitled';
    end;
    case MessageDlg(Format('Save changes to "%s"?', [LFileName]),
        mtConfirmation, [mbYes, mbNo, mbCancel], 0) of
      mrYes: begin
        MenuFileSave.Click;
        ACanClose := not FormCmocIDESynEdit.Modified;
      end;
      mrNo: begin
        ACanClose := True;
      end;
      mrCancel: begin
        Abort;
      end;
    end;
  end;
end;

procedure TFormCmocIDE.AppPropsException(ASender: TObject; AException: Exception);
begin
  MessageDlg(AException.Message, mtError, [mbOK], 0);
end;

function TFormCmocIDE.FileNameSrc: TFileName;
begin
  Result := FormCmocIDESynEdit.FileName;
end;

function TFormCmocIDE.FileNameSrcExists: TFileName;
begin
  if Length(FileNameSrc) = 0 then begin
    WriteLn('# Source must be saved before being compiled/processed');
    MenuFileSaveAs.Click;
  end;
  if not FileExists(FileNameSrc) then begin
    OCmoc.RaiseError('File does not exist', FileNameSrc);
  end;
  Result := FileNameSrc;
end;

function TFormCmocIDE.FileNameObj: TFileName;
begin
  Result := ChangeFileExt(FileNameSrc, FileExt_O);
end;

function TFormCmocIDE.FileNameOut: TFileName;
var
  LString: TFileName;
begin
  LString := LowerCase(Trim(FOptions.Values[Opt_Format2]));
  case LString of
    Format_WAV, Format_CAS, Format_SREC: begin
      LString := ExtensionSeparator + LString;
    end;
    Format_DECB: begin
      LString := FileExt_BIN;
    end else begin
      OCmoc.RaiseError('Unknown output format', LString);
    end;
  end;
  Result := ChangeFileExt(FileNameSrc, ExtensionSeparator + FTarget + LString);
end;

procedure TFormCmocIDE.MenuFileNewClick(ASender: TObject);
var
  LCanClose: boolean;
begin
  LCanClose := True;
  FormCloseQuery(Self, LCanClose);
  if LCanClose then begin
    FormCmocIDESynEdit.Clear;
  end;
end;

procedure TFormCmocIDE.MenuFileNewWindowClick(ASender: TObject);
begin
  ExecuteTool(Tool_CMOCIDE, [Opt_NoCode1, Opt_NoMaximize1], True);
end;

procedure TFormCmocIDE.MenuFileOpenClick(ASender: TObject);
begin
  if FormCmocIDESynEdit.Modified then begin
    MenuFileOpenInNewWindow.Click;
  end else begin
    if OpenDialog.Execute then begin
      FormCmocIDESynEdit.LoadFromFile(OpenDialog.FileName);
    end else begin
      Abort;
    end;
  end;
end;

procedure TFormCmocIDE.MenuFileOpenInNewWindowClick(ASender: TObject);
begin
  if OpenDialog.Execute then begin
    ExecuteTool(Tool_CMOCIDE, [Opt_NoMaximize1, OpenDialog.FileName], True);
  end else begin
    Abort;
  end;
end;

procedure TFormCmocIDE.MenuFileSaveAsClick(ASender: TObject);
begin
  if SaveDialog.Execute then begin
    FormCmocIDESynEdit.SaveToFile(SaveDialog.FileName);
  end else begin
    Abort;
  end;
end;

procedure TFormCmocIDE.MenuFileSaveClick(ASender: TObject);
begin
  if FormCmocIDESynEdit.Modified or not FileExists(FormCmocIDESynEdit.FileName) then begin
    try
      FormCmocIDESynEdit.SaveToFile(FileNameSrc);
    except
      MenuFileSaveAs.Click;
    end;
  end;
end;

procedure TFormCmocIDE.SynEditLogChangeUpdating(ASender: TObject; AIsUpdating: boolean);
begin
  with ASender as TSynEdit do begin
    if not AIsUpdating then begin
      if FSynEditLinesCount <> Lines.Count then begin
        FSynEditLinesCount := Lines.Count;
        if FSynEditLinesCount > 0 then begin
          if CaretY <> FSynEditLinesCount then begin
            CaretY := FSynEditLinesCount;
            Application.ProcessMessages;
          end;
        end;
      end;
    end;
  end;
end;

function TFormCmocIDE.Execute(const AExecutable: string; const AParameters: array of string;
  const AExternal: boolean): integer;
var
  LCount: integer;
  LBuffer: array[byte] of byte;
  LString: string;
begin
  LBuffer[0] := 0;
  with Process do begin
    if AExternal then begin
      ShowWindow := swoNone;
      Options := [];
    end else begin
      ShowWindow := swoHIDE;
      Options := [poUsePipes, poStderrToOutput];
    end;
    Executable := AExecutable;
    if not FileExists(Executable) then begin
      Executable := ExeSearch(AExecutable);
      if not FileExists(Executable) then begin
        OCmoc.RaiseError('Unable to locate', AExecutable);
      end;
    end;
    CurrentDirectory := ExtractFileDir(Executable);
    Parameters.Clear;
    Parameters.AddStrings(AParameters);
    WriteLn('# ', Executable, ' ', Parameters.CommaText);
    try
      Execute;
    except
      on LException: Exception do begin
        OCmoc.RaiseError(Format('%s failed with exit code %d',
          [ExtractFileName(Executable), ExitCode]), ExitCode);
      end
    end;
    if not AExternal then begin
      LCount := 0;
      while (Running or (Output.NumBytesAvailable > 0)) and not Application.Terminated do begin
        Sleep(100);
        if Output.NumBytesAvailable > 0 then begin
          while Output.NumBytesAvailable > 0 do begin
            SetString(LString, PChar(@LBuffer), Output.Read(LBuffer, SizeOf(LBuffer)));
            Write(LString);
          end;
        end else begin
          Sleep(200);
          Inc(LCount);
          if LCount > 10 then begin
            Write('#');
            Application.ProcessMessages;
            Sleep(300);
          end;
        end;
      end;
      if LCount > 10 then begin
        WriteLn;
      end;
    end;
    Result := ExitCode;
    if Result <> 0 then begin
      OCmoc.RaiseError(Format('%s failed with exit code %d',
        [ExtractFileName(Executable), ExitCode]), ExitCode);
    end;
  end;
end;

function TFormCmocIDE.ExecuteTool(const ATool: string; const AParameters: array of string;
  const AExternal: boolean): integer;
begin
  Result := Execute(OCmoc.PathToBin + ATool + FileExt_EXE, AParameters, AExternal);
end;

procedure TFormCmocIDE.MenuEditFormatSourceCodeClick(ASender: TObject);
begin
  if MessageDlg('Do you want to format current file?', mtConfirmation, [mbYes, mbNo], 0) =
    mrYes then begin
    with CCmocProcess.Create(Self) do begin
      try
        FormCmocIDESynEdit.SynEdit._ChangeText(OCmoc.StringAStyle(
          FormCmocIDESynEdit.SynEdit.Text, FormCmocIDESynEdit.SynEdit.TabWidth));
      finally
        Free;
      end;
    end;
    with FormCmocIDESynEdit.SynEdit do begin
      if not InRange(CaretY, TopLine, TopLine + LinesInWindow) then begin
        _SetCaretYCentered(TopLine + (LinesInWindow div 2));
      end;
    end;
    WriteLn('// Formatting complete');
  end;
end;

function TFormCmocIDE.BeginProcess(const ADst: TFileName; const ASrc: array of TFileName): boolean;
var
  LFileName: TFileName;
begin
  MenuFileSave.Click;
  for LFileName in ASrc do begin
    if not FileExists(LFileName) then begin
      OCmoc.RaiseError('File does not exist', LFileName);
    end;
  end;
  while SynEditLog.Lines.Count > 500 do begin
    SynEditLog.Lines.Delete(0);
  end;
  Result := False;
  for LFileName in ASrc do begin
    Result := FileAge(ADst) < FileAge(LFileName);
    if Result then begin
      Break;
    end;
  end;
  if not Result then begin
    WriteLn(OCmoc.StringQuoted(ADst) + ' is unchanged. # No processing required');
  end;
end;

procedure TFormCmocIDE.EndProcess(const AMessage: string);
begin
  WriteLn('// ' + AMessage);
end;

procedure TFormCmocIDE.MenuRunSyntaxCheckClick(ASender: TObject);
begin
  if BeginProcess(EmptyStr, [FileNameSrcExists]) then begin
    ExecuteTool(Tool_CMOC2, [Opt_DontAssemble1, FileNameSrc], False);
    EndProcess('No syntax error were found');
  end;
end;

procedure TFormCmocIDE.MenuRunCompileClick(ASender: TObject);
begin
  SynEditLog.Clear;
  FTarget := Target_COCO;
  FOrigin := Origin_DEFAULT;
  OCmoc.ExtractPragmas(nil, FormCmocIDESynEdit.SynEdit.Lines, FOrigin, FTarget, FOptions);
  if FOptions.IndexOfName(Opt_Format2) < 0 then begin
    FOptions.Values[Opt_Format2] := Format_DECB;
  end;
  FLinkin.CommaText := FOptions.Values[Opt_Linkin1];
  if BeginProcess(FileNameObj, [FileNameSrcExists]) then begin
    ExecuteTool(Tool_CMOC2, [Opt_DontLink1, Opt_Output2, FileNameObj, Opt_Target2,
      FTarget, Opt_Origin2, IntToStr(FOrigin), FileNameSrc], False);
    EndProcess('Compilation complete');
  end;
end;

procedure TFormCmocIDE.MenuRunBuildClick(ASender: TObject);
var
  LIndex: integer;
  LObjFiles: TStringDynArray;
begin
  MenuRunCompile.Click;
  LObjFiles := default(TStringDynArray);
  OStringDynArray.Add(LObjFiles, FileNameObj);
  for LIndex := 0 to FLinkin.Count - 1 do begin
    OStringDynArray.Add(LObjFiles, FLinkin[LIndex]);
  end;
  if BeginProcess(FileNameOut, LObjFiles) then begin
    OStringDynArray.InsertStrings(LObjFiles, 0, [Opt_Output2, FileNameOut, Opt_Target2, FTarget,
      Opt_Origin2, IntToStr(FOrigin)]);
    ExecuteTool(Tool_CMOC2, LObjFiles, False);
    EndProcess('Build complete');
  end;
end;

procedure TFormCmocIDE.OpenBrowser(AURL: string);
begin
  AURL := OCmoc.FileNameTranslate(AURL);
  if not LCLIntf.OpenURL(AURL) then begin
    OCmoc.RaiseError('Unable to open', AURL);
  end;
end;

procedure TFormCmocIDE.CheckRoms;
var
  LIndex: integer;
  LMessage: string;
begin
  with FindAllFiles(OCmoc.PathToXroarRoms, AllFilesMask + FileExt_ROM, False) do begin
    try
      if Count = 0 then begin
        LMessage := 'Unable to locate XRoar ROM files' + LineEnding +
          'You must place ROM''s into the ROM path @ ' +
          OCmoc.StringQuoted(OCmoc.PathToXroarRoms);
        if MessageDlg(LMessage + LineEnding + LineEnding +
          'Would you like to explore the ROM folder?', mtInformation, [mbYes, mbNo], 0) =
          mrYes then begin
          MenuHelpOpenRomFolder.Click;
        end;
        OCmoc.RaiseError(LMessage);
      end;
      for LIndex := 0 to Count - 1 do begin
        Strings[LIndex] := ChangeFileExt(ExtractFileName(Strings[LIndex]), EmptyStr);
      end;
      WriteLn('# ', Count, ' XRoar ROM file(s) found.' + LineEnding + '# ' + CommaText);
    finally
      Free;
    end;
  end;
end;

procedure TFormCmocIDE.ExecuteEmulator(AFileName: TFileName);
var
  LIndex: integer;
  LParams: TStringDynArray;
  LBinFile: TFileName;
  LDecb: rawbytestring;
begin
  if Length(AFileName) > 0 then begin
    if not SameText(ExtractFileExt(AFileName), FileExt_BIN) then begin
      OCmoc.RaiseError('Only bin (DECB) files can be autoloaded by the emulator.');
    end;
    LDecb := RbsLoadFromFile(AFileName);
    LBinFile := GetTempDir(False) + 'cmocide' + FileExt_BIN;
    RbsSaveToFile(RbsDecb(RbsVideo(
      UpperCase(Format('%-32s   BEG=$%.4x END=$%.4x LEN=$%.4x%s', [ExtractFileName(AFileName),
      RbsDecbBegin(LDecb), RbsDecbBegin(LDecb) + RbsDecbLength(LDecb),
      RbsDecbLength(LDecb), StringOfChar(#131, 32)]))), 1024) + LDecb, LBinFile);
    AFileName := LBinFile;
  end;
  LParams := default(TStringDynArray);
  if SameText(FOptions.Values[Opt_XRoar_Machine], Machine_COCO3) then begin
    if not OPlatform.IsWindows then begin
      OCmoc.RaiseError('CoCo 3 emulation is Windows only. Try CoCo 2 emulation via XRoar.');
    end;
    WriteLn('// Running Vcc emulator');
    try
      Execute(OCmoc.PathToVcc + 'Vcc.exe', [AFileName], True);
    except
      OCmoc.RaiseError('Vcc failed to execute');
    end;
  end else begin
    CheckRoms;
    WriteLn('// Running XRoar emulator. Machine=', FOptions.Values[Opt_XRoar_Machine]);
    try
      OStringDynArray.AddOptions(LParams, FOptions, Opt_XRoar_All);
      if FOptions.IndexOfName(Opt_XRoar_Load) < 0 then begin
        OStringDynArray.AddStrings(LParams, [Opt_XRoar_Load, OCmoc.PathToDsk + 'disk0.dsk']);
        OStringDynArray.AddStrings(LParams, [Opt_XRoar_Load, OCmoc.PathToDsk + 'disk1.dsk']);
        OStringDynArray.AddStrings(LParams, [Opt_XRoar_Load, OCmoc.PathToDsk + 'disk2.dsk']);
      end else begin
        with TStringList.Create do begin
          try
            Delimiter := PathSeparator;
            DelimitedText := FOptions.Values[Opt_XRoar_Load];
            for LIndex := 0 to Count - 1 do begin
              OStringDynArray.AddStrings(LParams,
                [Opt_XRoar_Load, OCmoc.FileNameTranslate(Strings[LIndex])]);
            end;
          finally
            Free;
          end;
        end;
      end;
      if Length(AFileName) > 0 then begin
        OStringDynArray.AddStrings(LParams, [Opt_XRoar_Run, AFileName]);
      end;
      Execute(OCmoc.PathToXroar + 'xroar.exe', LParams, True);
    except
      OCmoc.RaiseError('XRoar failed to execute');
    end;
  end;
end;

procedure TFormCmocIDE.ExecuteMachine(const AName: string; const AFileName: TFileName);
begin
  case AName of
    'coco1': begin
      FOptions.Values[Opt_XRoar_Machine] := Machine_COCOUS;
      FOptions.Values[Opt_XRoar_Ram] := '16';
      FOptions.Values[Opt_XRoar_Bas] := 'bas10.rom';
      FOptions.Values[Opt_XRoar_NoExtBas] := EmptyStr;
      FOptions.Values[Opt_XRoar_NoDos] := EmptyStr;
    end;
    'coco1d': begin
      FOptions.Values[Opt_XRoar_Machine] := Machine_COCOUS;
      FOptions.Values[Opt_XRoar_Ram] := '64';
      FOptions.Values[Opt_XRoar_Bas] := 'bas10.rom';
      FOptions.Values[Opt_XRoar_ExtBas] := 'extbas10.rom';
      FOptions.Values[Opt_XRoar_Dos] := 'disk10.rom';
    end;
    'coco2d': begin
      FOptions.Values[Opt_XRoar_Machine] := Machine_COCOUS;
      FOptions.Values[Opt_XRoar_Ram] := '64';
      FOptions.Values[Opt_XRoar_Bas] := 'bas11.rom';
      FOptions.Values[Opt_XRoar_ExtBas] := 'extbas11.rom';
      FOptions.Values[Opt_XRoar_Dos] := 'disk11.rom';
    end else begin
      FOptions.Values[Opt_XRoar_Machine] := AName;
    end;
  end;
  ExecuteEmulator(AFileName);
end;

procedure TFormCmocIDE.MenuRunBuildAndRunClick(ASender: TObject);
begin
  MenuRunBuild.Click;
  if FOptions.IndexOfName(Opt_XRoar_Machine) < 0 then begin
    case FTarget of
      Target_COCO: begin
        if OPlatform.IsWindows then begin
          FOptions.Values[Opt_XRoar_Machine] := Machine_COCO3;
        end else begin
          FOptions.Values[Opt_XRoar_Machine] := Machine_COCOUS;
        end;
      end;
      Target_DRAGON: begin
        FOptions.Values[Opt_XRoar_Machine] := Machine_DRAGON64;
      end;
    end;
  end;
  ExecuteEmulator(FileNameOut);
end;

procedure TFormCmocIDE.MenuEmulatorsClick(ASender: TObject);
begin
  if ASender <> MenuEmulators then begin
    FOptions.Clear;
    ExecuteMachine((ASender as TMenuItem).Hint, default(string));
  end;
end;

procedure TFormCmocIDE.MenuToolsConsoleClick(ASender: TObject);
begin
  Execute(OCmoc.PathToBin + 'console.bat', [], True);
end;

procedure TFormCmocIDE.MenuToolsMessImageToolClick(ASender: TObject);
begin
  ExecuteTool(Tool_WIMGTOOL, [OCmoc.FileNameTranslate((ASender as TMenuItem).Hint)], True);
end;

procedure TFormCmocIDE.MenuFileExitClick(ASender: TObject);
begin
  Close;
end;

procedure TFormCmocIDE.MenuEditClick(ASender: TObject);
var
  LIndex: integer;
  LSelAvail: boolean;
begin
  for LIndex := 0 to MenuEdit.Count - 1 do begin
    MenuEdit.Items[LIndex].Enabled := Active;
  end;
  if Active then begin
    LSelAvail := FormCmocIDESynEdit.SynEdit.SelAvail;
    MenuEditCopy.Enabled := LSelAvail;
    MenuEditCut.Enabled := LSelAvail;
    MenuEditDelete.Enabled := LSelAvail;
    MenuEditLowercaseSelection.Enabled := LSelAvail;
    MenuEditPaste.Enabled := FormCmocIDESynEdit.SynEdit.CanPaste;
    MenuEditRedo.Enabled := FormCmocIDESynEdit.SynEdit.CanRedo;
    MenuEditUndo.Enabled := FormCmocIDESynEdit.SynEdit.CanUndo;
    MenuEditUppercaseSelection.Enabled := LSelAvail;
  end;
end;

procedure TFormCmocIDE.MenuEditUndoClick(ASender: TObject);
var
  LOnClick: TNotifyEvent;
begin
  with ASender as TMenuItem do begin
    LOnClick := OnClick;
    OnClick := nil;
    try
      KeyInput._ApplyShortCut(ShortCut);
    finally
      OnClick := LOnClick;
    end;
  end;
end;

procedure TFormCmocIDE.MenuEditFindClick(ASender: TObject);
begin
  FormCmocIDESynEdit.MenuFind.Click;
end;

procedure TFormCmocIDE.MenuEditFindNextClick(ASender: TObject);
begin
  FormCmocIDESynEdit.MenuFindNext.Click;
end;

procedure TFormCmocIDE.MenuEditReplaceClick(ASender: TObject);
begin
  FormCmocIDESynEdit.MenuReplace.Click;
end;

procedure TFormCmocIDE.ButtonCopyClick(ASender: TObject);
begin
  MenuEditCopy.Click;
end;

procedure TFormCmocIDE.ButtonCutClick(ASender: TObject);
begin
  MenuEditCut.Click;
end;

procedure TFormCmocIDE.ButtonDeleteClick(ASender: TObject);
begin
  MenuEditDelete.Click;
end;

procedure TFormCmocIDE.ButtonPasteClick(ASender: TObject);
begin
  MenuEditPaste.Click;
end;

procedure TFormCmocIDE.ButtonRedoClick(ASender: TObject);
begin
  MenuEditRedo.Click;
end;

procedure TFormCmocIDE.ButtonUndoClick(ASender: TObject);
begin
  MenuEditUndo.Click;
end;

procedure TFormCmocIDE.MenuEditUppercaseSelectionClick(ASender: TObject);
begin
  FormCmocIDESynEdit.SynEdit._UpperCaseSelText;
end;

procedure TFormCmocIDE.MenuHelpClick(ASender: TObject);
begin
  with ASender as TMenuItem do begin
    if (Parent = MenuHelp) and (Length(Hint) > 0) then begin
      OpenBrowser(Hint);
    end;
  end;
end;

procedure TFormCmocIDE.MenuHelpOpenRomFolderClick(ASender: TObject);
begin
  OpenBrowser(OCmoc.PathToXroarRoms);
end;

procedure TFormCmocIDE.MenuEmulatorsEDTASMClick(ASender: TObject);
begin
  FOptions.Clear;
  FOptions.Values[Opt_XRoar_Type] := 'LOADM"EDTASM++:2":EXEC\n';
  ExecuteMachine('coco2d', default(string));
end;

procedure TFormCmocIDE.MenuToolsDisassembleClick(ASender: TObject);
var
  LOrigin: cardinal;
  LSrc, LDst: TFileName;
  LString: string;
  LRawBytes: rawbytestring;
begin
  if OpenASM.Execute then begin
    LSrc := GetTempDir(False) + 'wincmoc.d9asm' + FileExt_BIN;
    LDst := GetTempDir(False) + 'wincmoc.d9asm' + FileExt_ASM;
    LRawBytes := RbsLoadFromFile(OpenASM.FileName);
    LOrigin := 0;
    if AnsiMatchText(ExtractFileExt(OpenASM.FileName), [FileExt_BIN]) then begin
      if (Length(LRawBytes) > 5) and (RbsByte(LRawBytes, 0) = 0) then begin
        LOrigin := RbsWord(LRawBytes, 3);
        Delete(LRawBytes, 1, 5);
      end;
    end;
    if LOrigin = 0 then begin
      LString := '$8000';
      if InputQuery('Disassemble ' + OCmoc.StringQuoted(ExtractFileName(OpenASM.FileName)),
        'Enter a binary offset for this disassembly.', LString) then begin
        LOrigin := OCmoc.StringToInteger(LString);
      end;
    end;
    RbsSaveToFile(LRawBytes, LSrc);
    ExecuteTool(Tool_F9DASM, [Opt_Offset2, IntToHex(LOrigin, 4), Opt_NoAddr1,
      Opt_Out2, LDst, LSrc], False);
    ExecuteTool(Tool_CMOCIDE, [LDst], True);
  end;
end;

procedure TFormCmocIDE.MenuEditLowercaseSelectionClick(ASender: TObject);
begin
  FormCmocIDESynEdit.SynEdit._LowerCaseSelText;
end;

procedure TFormCmocIDE.ToolBarPaint(ASender: TObject);
begin
  with ASender as TToolBar do begin
    Canvas.GradientFill(ClientRect, clMenu, clBtnFace, gdVertical);
  end;
end;

procedure TFormCmocIDE.MenuHelpAboutClick(ASender: TObject);
begin
  MessageDlg(Application.Title + LineEnding + LineEnding + RbsLoadFromResource('README'),
    mtInformation, [mbOK], 0);
end;

end.
