{
 ***************************************************************************
 *                                                                         *
 *   This source is free software; you can redistribute it and/or modify   *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This code is distributed in the hope that it will be useful, but      *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   General Public License for more details.                              *
 *                                                                         *
 *   A copy of the GNU General Public License is available on the World    *
 *   Wide Web at <http://www.gnu.org/copyleft/gpl.html>. You can also      *
 *   obtain it by writing to the Free Software Foundation,                 *
 *   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.        *
 *                                                                         *
 ***************************************************************************
}

unit UnitCmocIDE;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, ComCtrls, Controls, Dialogs, ExtCtrls, FileUtil, Forms, Graphics,
  LCLIntf, Menus, MouseAndKeyInput, process, StreamIO, SynEdit, SynHighlighterAny,
  SysUtils, UCmocIDE, UCmocSynEdit, UCmocUtils, UnitCmocIDESynEdit;

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
    MenuHelpCmocOnline: TMenuItem;
    MenuHelpCoCoArchive: TMenuItem;
    MenuHelpFatCowIconsOnline: TMenuItem;
    MenuHelpOpenRomFolder: TMenuItem;
    MenuHelpSep1: TMenuItem;
    MenuHelpSep2: TMenuItem;
    MenuHelpSep3: TMenuItem;
    MenuHelpWinCmocOnline: TMenuItem;
    MenuRun: TMenuItem;
    MenuRunBuild: TMenuItem;
    MenuRunBuildAndRun: TMenuItem;
    MenuRunCompile: TMenuItem;
    MenuRunSep1: TMenuItem;
    MenuRunSyntaxCheck: TMenuItem;
    MenuXRoar: TMenuItem;
    MenuXRoarColourComputerNTSC: TMenuItem;
    MenuXRoarColourComputerPAL: TMenuItem;
    MenuXRoarDragon200E: TMenuItem;
    MenuXRoarDragon32: TMenuItem;
    MenuXRoarDragon64: TMenuItem;
    MenuXRoarDynacmoMX1600: TMenuItem;
    MenuXRoarTanoDragon: TMenuItem;
    OpenDialog: TOpenDialog;
    Process: TProcess;
    SaveDialog: TSaveDialog;
    SplitterBottom: TSplitter;
    StatusBar: TStatusBar;
    SynAnySyn: TSynAnySyn;
    SynEditLog: TSynEdit;
    ToolBar: TToolBar;
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
    procedure MenuHelpCoCoArchiveClick(ASender: TObject);
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
    procedure MenuHelpFatCowIconsOnlineClick(ASender: TObject);
    procedure MenuHelpOpenRomFolderClick(ASender: TObject);
    procedure MenuHelpCmocOnlineClick(ASender: TObject);
    procedure MenuHelpWinCmocOnlineClick(ASender: TObject);
    procedure MenuRunCompileClick(ASender: TObject);
    procedure MenuRunBuildAndRunClick(ASender: TObject);
    procedure MenuXRoarClick(ASender: TObject);
    procedure SynEditLogChangeUpdating(ASender: TObject; AIsUpdating: boolean);
    procedure MenuHelpAboutClick(ASender: TObject);
    procedure MenuRunBuildClick(ASender: TObject);
    procedure MenuRunSyntaxCheckClick(ASender: TObject);
    procedure ToolBarPaint(ASender: TObject);
  strict private
    FSynEditLinesCount: integer;
    FTarget: string;
    FOrigin: cardinal;
  strict private
    function FileNameSrc: TFileName;
    function FileNameSrcExists: TFileName;
    function FileNameObj: TFileName;
    function FileNameBin: TFileName;
  strict private
    procedure CheckRoms;
  strict private
    procedure XRoar(const AMachine: string; const AFileName: TFileName);
    function Execute(const AExecutable: string; const AParameters: array of string;
      const AExternal: boolean): integer;
    function RunTool(const ATool: string; const AParameters: array of string;
      const AExternal: boolean): integer;
  strict private
    function BeginProcess(const ADst, ASrc: TFileName): boolean;
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
  LStream := CStringsStream.Create(SynEditLog.Lines);
  AssignStream(Output, LStream);
  Rewrite(Output);
  LStream := CStringsStream.Create(SynEditLog.Lines);
  LStream.Task := 'Error';
  AssignStream(StdErr, LStream);
  Rewrite(StdErr);

  SetBounds(Left, Top, 640, 480);
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
    Font.Name := 'Courier New';
    Font.Size := 8;
    BracketMatchColor.Background := clAqua;
    BracketMatchColor.Style := [];
    LineHighlightColor.Background := $E6FFFA;
  end;
  OpenDialog.Filter := FormCmocIDESynEdit.SynAnySyn.DefaultFilter;
  SaveDialog.Filter := FormCmocIDESynEdit.SynAnySyn.DefaultFilter;
  SaveDialog.DefaultExt := '.c';

  FormCmocIDESynEdit.Clear;

  if (ParamCount > 0) and FileExists(ParamStr(ParamCount)) then begin
    FormCmocIDESynEdit.LoadFromFile(ParamStr(ParamCount));
  end else if not Application.HasOption('nocode') then begin
    with FormCmocIDESynEdit.SynEdit.Lines do begin
      Add('#include <math.h>');
      Add('#include <ctype.h>');
      Add('#include <stdio.h>');
      Add('#include <string.h>');
      Add('#include <conio.h>');
      Add(EmptyStr);
      Add('#include <basic.h>');
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

  WriteLn('// Welcome to ' + Application.Title);

  try
    CheckRoms;
  except
  end;
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
    WriteLn('# Source must be saved before being processed');
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

function TFormCmocIDE.FileNameBin: TFileName;
begin
  Result := ChangeFileExt(FileNameSrc, ExtensionSeparator + FTarget + FileExt_BIN);
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
  RunTool('cmocide', ['-nocode', '-nomaximize'], True);
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
    RunTool('cmocide', ['-nomaximize', OpenDialog.FileName], True);
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

procedure TFormCmocIDE.MenuHelpAboutClick(ASender: TObject);
begin
  MessageDlg(
    Application.Title + LineEnding +
    'Copyright (C) 2015-2016 Derek John Evans' + LineEnding + LineEnding +
    'http://www.wascal.com' + LineEnding + LineEnding +
    'This source is free software; you can redistribute it and/or modify' + LineEnding +
    'it under the terms of the GNU General Public License as published by' + LineEnding +
    'the Free Software Foundation; either version 2 of the License, or' + LineEnding +
    '(at your option) any later version.' + LineEnding + LineEnding +
    'This code is distributed in the hope that it will be useful, but' + LineEnding +
    'WITHOUT ANY WARRANTY; without even the implied warranty of' + LineEnding +
    'MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.' + LineEnding +
    'See the GNU General Public License for more details.' + LineEnding + LineEnding +
    'A copy of the GNU General Public License is available on the World' + LineEnding +
    'Wide Web at <http://www.gnu.org/copyleft/gpl.html>. You can also' + LineEnding +
    'obtain it by writing to the Free Software Foundation,' + LineEnding +
    'Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.', mtInformation, [mbOK], 0);
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

function TFormCmocIDE.RunTool(const ATool: string; const AParameters: array of string;
  const AExternal: boolean): integer;
begin
  Result := Execute(ProgramDirectory + ATool + FileExt_EXE, AParameters, AExternal);
end;

procedure TFormCmocIDE.MenuEditFormatSourceCodeClick(ASender: TObject);
var
  LTmpFile: TFileName;
begin
  if MessageDlg('Do you want to format current file?', mtConfirmation, [mbYes, mbNo], 0) =
    mrYes then begin
    LTmpFile := GetTempDir(False) + 'astyle.c';
    FormCmocIDESynEdit.SynEdit.Lines.SaveToFile(LTmpFile);
    try
      RunTool(Tool_ASTYLE, ['-A8', '-xC100', '-k1', '-w', '-U', '-H', '-j', '-s' +
        IntToStr(FormCmocIDESynEdit.SynEdit.TabWidth),
        LTmpFile], False);
      with TStringList.Create do begin
        try
          LoadFromFile(LTmpFile);
          while (Count > 0) and (Length(Trim(Strings[0])) = 0) do begin
            Delete(0);
          end;
          while (Count > 0) and (Length(Trim(Strings[Count - 1])) = 0) do begin
            Delete(Count - 1);
          end;
          Insert(0, EmptyStr);
          FormCmocIDESynEdit.SynEdit._ChangeText(Text);
          FormCmocIDESynEdit.SynEdit._SetCaretYCentered(FormCmocIDESynEdit.SynEdit.CaretY);
        finally
          Free;
        end;
      end;
    finally
      DeleteFile(LTmpFile);
    end;
    WriteLn('// Formatting complete');
  end;
end;

function TFormCmocIDE.BeginProcess(const ADst, ASrc: TFileName): boolean;
begin
  MenuFileSave.Click;
  if not FileExists(ASrc) then begin
    OCmoc.RaiseError('File does not exist', ASrc);
  end;
  while SynEditLog.Lines.Count > 500 do begin
    SynEditLog.Lines.Delete(0);
  end;
  Result := FileAge(ADst) < FileAge(ASrc);
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
  if BeginProcess(EmptyStr, FileNameSrcExists) then begin
    RunTool(Tool_CMOC2, [Opt_DontAssemble1, FileNameSrc], False);
    EndProcess('No syntax error were found');
  end;
end;

procedure TFormCmocIDE.MenuRunCompileClick(ASender: TObject);
begin
  SynEditLog.Clear;
  FTarget := Target_COCO;
  FOrigin := Origin_DEFAULT;
  OCmoc.SourcePragmas(nil, FormCmocIDESynEdit.SynEdit.Lines, FOrigin, FTarget);
  if BeginProcess(FileNameObj, FileNameSrcExists) then begin
    RunTool(Tool_CMOC2, [Opt_DontLink1, Opt_Output2, FileNameObj, Opt_Target2,
      FTarget, Opt_Origin2, IntToStr(FOrigin), FileNameSrc], False);
    EndProcess('Compilation complete');
  end;
end;

procedure TFormCmocIDE.MenuRunBuildClick(ASender: TObject);
begin
  MenuRunCompile.Click;
  if BeginProcess(FileNameBin, FileNameObj) then begin
    RunTool(Tool_CMOC2, [Opt_Output2, FileNameBin, Opt_Target2, FTarget,
      Opt_Origin2, IntToStr(FOrigin), FileNameObj], False);
    EndProcess('Build complete');
  end;
end;

procedure TFormCmocIDE.CheckRoms;
var
  LIndex: integer;
  LMessage: string;
begin
  with FindAllFiles(OCmoc.PathToXroarRoms, '*.rom', False) do begin
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

procedure TFormCmocIDE.XRoar(const AMachine: string; const AFileName: TFileName);
begin
  CheckRoms;
  WriteLn('// Running XRoar emulator. Machine=', AMachine);
  try
    Execute(OCmoc.PathToXroar + 'xroar.exe', ['-rompath', 'roms', '-machine', AMachine,
      '-joy-right', 'mjoy0', '-kbd-translate', '-nodos', AFileName], True);
  except
    OCmoc.RaiseError('XRoar failed to execute');
  end;
end;

procedure TFormCmocIDE.MenuRunBuildAndRunClick(ASender: TObject);
var
  LMachine: string;
begin
  MenuRunBuild.Click;
  case FTarget of
    Target_COCO: begin
      LMachine := 'cocous';
    end;
    Target_DRAGON: begin
      LMachine := 'dragon64';
    end else begin
      OCmoc.RaiseError('Unknown target machine');
    end;
  end;
  XRoar(LMachine, FileNameBin);
end;

procedure TFormCmocIDE.MenuXRoarClick(ASender: TObject);
var
  LMachine: string;
begin
  LMachine := (ASender as TMenuItem).Hint;
  if Length(LMachine) > 0 then begin
    XRoar(LMachine, EmptyStr);
  end;
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

procedure TFormCmocIDE.MenuHelpFatCowIconsOnlineClick(ASender: TObject);
begin
  OpenURL(OCmoc._UrlFatCowFreeIcons);
end;

procedure TFormCmocIDE.MenuHelpCoCoArchiveClick(ASender: TObject);
begin
  OpenURL(OCmoc._UrlCoCoArchive);
end;


procedure TFormCmocIDE.MenuHelpOpenRomFolderClick(ASender: TObject);
begin
  if not OpenURL(OCmoc.PathToXroarRoms) then begin
    OCmoc.RaiseError('Unable to open', OCmoc.PathToXroarRoms);
  end;
end;

procedure TFormCmocIDE.MenuHelpCmocOnlineClick(ASender: TObject);
begin
  OpenURL(OCmoc._UrlCmoc);
end;

procedure TFormCmocIDE.MenuHelpWinCmocOnlineClick(ASender: TObject);
begin
  OpenURL(OCmoc._UrlWinCmoc);
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

end.
