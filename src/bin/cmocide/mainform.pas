unit MainForm;

{$mode objfpc}{$H+}

interface

uses Classes, ComCtrls, Controls, CustomForms, Dialogs, Documents, FatCowIcons, FileUtils, Forms,
  Graphics, Java, LCLIntf, Memos, Menus, Process, ProcessUtils, Programs, Splitters,
  StdCtrls, StrUtils, SysUtils;

type

  TFormIDE = class(TFormSDI)
  strict private
    FIcons: TFatCowIcons;
    FSplitter: TPairSplitter;
    FProcess: TProcess;
    FMemo: TRichMemo;
    FListBox: TListBox;
    FDocument: TDocumentSyntaxHighlighter;
  public
    constructor Create(A: TComponent); override;
  public
    procedure Execute(const AExecutable: string; const AParameters: array of string; const AConsole: boolean);
    procedure AddEditMenuItems(const A: TAbstractMenuItem);
    procedure LogMessage(const A: string);
    procedure LogFileName(const A, AFileName: string);
    procedure SetFileName(const A: TFileName); override;
    procedure SaveToFile(const A: TFileName); override;
    procedure LoadFromFile(const A: TFileName); override;
    procedure OpenMESSImage(const A: TFileName);
  public
    procedure ListBoxInserted(A: TSender; AIndex: integer);
  public
    procedure FormShow(A: TSender);
    procedure FormCloseQuery(A: TSender; var ACanClose: boolean);
  public
    procedure FileNew(A: TSender);
    procedure FileNewWindow(A: TSender);
    procedure FileOpen(A: TSender);
    procedure FileOpenInNewWindow(A: TSender);
    procedure FileSave(A: TSender);
    procedure FileSaveAs(A: TSender);
    procedure FileExit(A: TSender);
  public
    procedure EditUndo(A: TSender);
    procedure EditRedo(A: TSender);
    procedure EditCut(A: TSender);
    procedure EditCopy(A: TSender);
    procedure EditPaste(A: TSender);
    procedure EditDelete(A: TSender);
    procedure EditSelectAll(A: TSender);
    procedure EditFind(A: TSender);
    procedure EditFindNext(A: TSender);
    procedure EditReplace(A: TSender);
    procedure EditUpperCase(A: TSender);
    procedure EditLowerCase(A: TSender);
    procedure EditFormatSource(A: TSender);
  public
    procedure RunSyntaxCheck(A: TSender);
    procedure RunCompile(A: TSender);
    procedure RunBuild(A: TSender);
    procedure RunBuildAndRun(A: TSender);
  public
    procedure ToolsOpenConsole(A: TSender);
    procedure ToolsMessImageTool(A: TSender);
    procedure ToolsOpenDisk0(A: TSender);
    procedure ToolsOpenDisk1(A: TSender);
    procedure ToolsOpenDisk2(A: TSender);
  end;

var
  FormMain: TForm;

implementation

constructor TFormIDE.Create(A: TComponent);
begin
  inherited;

  OnShow := @FormShow;
  OnCloseQuery := @FormCloseQuery;

  Width := 720;
  Height := 500;
  Position := poScreenCenter;

  FProcess := TProcess.Create(Self);
  FIcons := TFatCowIcons.Create(ProgramDirectory + 'images');

  with MainMenu do begin
    with AddMenuItem('File') do begin
      AddMenuItem('New', @FileNew).Icon := FIcons.New;
      AddMenuItem('New Window', @FileNewWindow).Icon := FIcons.NewWindow;
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('Open ...', @FileOpen).Icon := FIcons.Open;
      AddMenuItem('Open New Window ...', @FileOpenInNewWindow).Icon := FIcons.FolderGo;
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('Save', @FileSave).Icon := FIcons.Save;
      AddMenuItem('Save As ...', @FileSaveAs).Icon := FIcons.FileSaveAs;
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('Exit', @FileExit).Icon := FIcons.Door;
    end;
    AddEditMenuItems(AddMenuItem('Edit'));
    with AddMenuItem('Run') do begin
      AddMenuItem('Syntax Check', @RunSyntaxCheck).Icon := FIcons.TickButton;
      AddMenuItem('Compile', @RunCompile).Icon := FIcons.Compile;
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('Build', @RunBuild).Icon := FIcons.Bricks;
      AddMenuItem('Build and Run ...', @RunBuildAndRun).Icon := FIcons.BrickGo;
    end;
    with AddMenuItem('Emulators') do begin
      AddMenuItem('Colour Computer 1 (Color BASIC 1.0)').Icon := FIcons.BulletRight;
      AddMenuItem('Colour Computer 1 (Disk Extended Color BASIC 1.0)').Icon := FIcons.BulletRight;
      AddMenuItem('Colour Computer 2 (Disk Extended Color BASIC 1.1)').Icon := FIcons.BulletRight;
      AddMenuItem('Colour Computer 3 (Disk Extended Color BASIC 2.1)').Icon := FIcons.BulletRight;
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('Dragon 32 (PAL)').Icon := FIcons.BulletRight;
      AddMenuItem('Dragon 64 (PAL)').Icon := FIcons.BulletRight;
      AddMenuItem('Dragon 200-E (PAL)').Icon := FIcons.BulletRight;
      AddMenuItem('Tano Dragon (NTSC)').Icon := FIcons.BulletRight;
      AddMenuItem('Dynacom MX-1600 (PAL-M)').Icon := FIcons.BulletRight;
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('EDTASM++ 1.1 ...').Icon := FIcons.BulletRight;
    end;
    with AddMenuItem('Tools') do begin
      AddMenuItem('WinCMOC Console ...', @ToolsOpenConsole);
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('Disassemble 6809 Binary ...');
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('MESS Image Tool ...', @ToolsMessImageTool);
      AddMenuItem('Open Disk #0 ...', @ToolsOpenDisk0);
      AddMenuItem('Open Disk #1 ...', @ToolsOpenDisk1);
      AddMenuItem('Open Disk #2 ... (EDTASM++)', @ToolsOpenDisk2);
    end;
    with AddMenuItem('Help') do begin
      AddMenuItem('About WinCMOC ...');
    end;
  end;
  ToolBar.Height := 44;
  ToolBar.AddToolBarButton('New', @FileNew).Icon := FIcons.New;
  ToolBar.AddToolBarButton('Open', @FileOpen).Icon := FIcons.Open;
  ToolBar.AddToolBarButton('Save', @FileSave).Icon := FIcons.Save;
  ToolBar.AddToolBarButton('Undo', @EditUndo).Icon := FIcons.Undo;
  ToolBar.AddToolBarButton('Redo', @EditRedo).Icon := FIcons.Redo;
  ToolBar.AddToolBarButton('Cut', @EditCut).Icon := FIcons.Cut;
  ToolBar.AddToolBarButton('Copy', @EditCopy).Icon := FIcons.Copy;
  ToolBar.AddToolBarButton('Paste', @EditPaste).Icon := FIcons.Paste;
  ToolBar.AddToolBarButton('Delete', @EditDelete).Icon := FIcons.Cross;
  ToolBar.AddToolBarButton('Syntax Check', @RunSyntaxCheck).Icon := FIcons.TickButton;
  ToolBar.AddToolBarButton('Compile', @RunCompile).Icon := FIcons.Compile;
  ToolBar.AddToolBarButton('Build', @RunBuild).Icon := FIcons.Bricks;
  ToolBar.AddToolBarButton('Build and Run', @RunBuildAndRun).Icon := FIcons.BrickGo;

  FSplitter := TPairSplitter.Create(Self);
  FSplitter.Handle.setResizeWeight(1);
  FSplitter.SplitterType := pstVertical;
  FSplitter.Position := Height - 250;
  FSplitter.Align := alClient;
  FSplitter.Parent := Self;

  FDocument := TDocumentSyntaxHighlighter.Create;
  FDocument.Objects.LoadFromFile(ProgramDirectory + 'cmocide\objects.txt');
  FDocument.Keywords.LoadFromFile(ProgramDirectory + 'cmocide\keywords.txt');
  FDocument.Constants.LoadFromFile(ProgramDirectory + 'cmocide\constants.txt');

  FMemo := TRichMemo.Create(Self);
  FMemo.BevelOuter := bvNone;
  FMemo.BevelInner := bvNone;
  FMemo.Document := FDocument;
  FMemo.Align := alClient;
  FMemo.Parent := FSplitter.Sides[0];

  FMemo.PopupMenu := TPopupMenu.Create(FMemo);
  AddEditMenuItems(FMemo.PopupMenu);

  FListBox := TListBox.Create(Self);
  FListBox.BevelOuter := bvNone;
  FListBox.BevelInner := bvNone;
  FListBox.Align := alClient;
  FListBox.Items.OnInserted := @ListBoxInserted;
  FListBox.Color := clInfoBk;
  FListBox.Font.Name := 'Courier New';
  FListBox.Font.Size := 10;
  FListBox.Parent := FSplitter.Sides[1];

  OpenDialog.Filter := 'C/C++ Files|*.c;*.h;*.cpp;*.hpp|All Files|*.*';
  SaveDialog.Filter := OpenDialog.Filter;
  try
    LoadFromFile(GetEnvironmentVariable('FILENAME'));
  except
    FMemo.Lines.Add(EmptyStr);
    FMemo.Lines.Add('#include <math.h>');
    FMemo.Lines.Add('#include <ctype.h>');
    FMemo.Lines.Add('#include <stdio.h>');
    FMemo.Lines.Add('#include <stdlib.h>');
    FMemo.Lines.Add('#include <string.h>');
    FMemo.Lines.Add('#include <conio.h>');
    FMemo.Lines.Add(EmptyStr);
    FMemo.Lines.Add('int main(void)');
    FMemo.Lines.Add('{');
    FMemo.Lines.Add('    puts("WELCOME TO WINCMOC IDE V0.7!");');
    FMemo.Lines.Add('    return 0;');
    FMemo.Lines.Add('}');
    FMemo.ClearUndoBuffer;
    FileName := EmptyStr;
  end;
end;

procedure TFormIDE.AddEditMenuItems(const A: TAbstractMenuItem);
begin
  with A do begin
    AddMenuItem('Undo', @EditUndo).Icon := FIcons.Undo;
    AddMenuItem('Redo', @EditRedo).Icon := FIcons.Redo;
    AddMenuItem(MenuItemSeparator);
    AddMenuItem('Cut', @EditCut).Icon := FIcons.Cut;
    AddMenuItem('Copy', @EditCopy).Icon := FIcons.Copy;
    AddMenuItem('Paste', @EditPaste).Icon := FIcons.Paste;
    AddMenuItem('Delete', @EditDelete).Icon := FIcons.Cross;
    AddMenuItem(MenuItemSeparator);
    AddMenuItem('Select All', @EditSelectAll).Icon := FIcons.LayerSelect;
    AddMenuItem(MenuItemSeparator);
    AddMenuItem('Find ...', @EditFind).Icon := FIcons.Find;
    AddMenuItem('Find Next', @EditFindNext);
    AddMenuItem(MenuItemSeparator);
    AddMenuItem('Replace', @EditReplace);
    AddMenuItem(MenuItemSeparator);
    AddMenuItem('Uppercase Selection', @EditUpperCase);
    AddMenuItem('Lowercase Selection', @EditLowerCase);
    AddMenuItem(MenuItemSeparator);
    AddMenuItem('Format Source Code (AStyle)', @EditFormatSource);
  end;
end;

procedure TFormIDE.LogMessage(const A: string);
begin
  FListBox.Items.Add(A);
end;

procedure TFormIDE.LogFileName(const A, AFileName: string);
begin
  if Length(AFileName) = 0 then begin
    LogMessage(A);
  end else begin
    LogMessage(A + ' - [' + AFileName + ']');
  end;
end;

procedure TFormIDE.SetFileName(const A: TFileName);
begin
  FMemo.Modified := False;
  inherited;
end;

procedure TFormIDE.SaveToFile(const A: TFileName);
begin
  LogFileName('Saving', A);
  FMemo.Lines.SaveToFile(A);
  inherited;
end;

procedure TFormIDE.LoadFromFile(const A: TFileName);
begin
  LogFileName('Loading', A);
  FMemo.Text := AnsiLoadFromFile(A);
  FMemo.ClearUndoBuffer;
  FMemo.SelStart := 0;
  inherited;
end;

procedure TFormIDE.Execute(const AExecutable: string; const AParameters: array of string; const AConsole: boolean);
begin
  with FProcess do begin
    if AConsole then begin
      Options := [];
    end else begin
      Options := [poUsePipes];
    end;
    Executable := AExecutable;
    if Length(ExtractFileExt(Executable)) > 0 then begin
      if not FileExists(Executable) and not DirectoryExists(Executable) then begin
        Executable := ExeSearch(AExecutable);
      end;
    end;
    CurrentDirectory := ExtractFileDir(Executable);
    Parameters.LoadFromStrings(AParameters);
    Execute;
    if not AConsole then begin
      ProcessOutputTo(FProcess, FListBox.Items);
    end;
  end;
end;

procedure TFormIDE.ListBoxInserted(A: TSender; AIndex: integer);
begin
  FListBox.ItemIndex := AIndex;
  FListBox.MakeCurrentVisible;
end;

procedure TFormIDE.FormShow(A: TSender);
begin
  LogMessage('Welcome to ' + Application.Title);
  WindowState := wsMaximized;
end;

procedure TFormIDE.FormCloseQuery(A: TSender; var ACanClose: boolean);
begin
  if FMemo.Modified then begin
    case MessageDlg('Do you want to save changes?', mtConfirmation, mbYesNoCancel, 0) of
      mrYes: begin
        FileSave(Self);
      end;
      mrCancel: begin
        ACanClose := False;
      end;
    end;
  end;
end;

procedure TFormIDE.FileNew(A: TSender);
var
  LCanClose: boolean;
begin
  LCanClose := True;
  FormCloseQuery(A, LCanClose);
  if LCanClose then begin
    FMemo.Lines.Clear;
    FileName := EmptyStr;
  end;
end;

procedure TFormIDE.FileNewWindow(A: TSender);
begin
  LogMessage('Opening New WinCMOC IDE Window');
  Execute('javaw', ['-cp', TProgram.FileName, 'cmocide'], True);
  FProcess.Environment.Values['FILENAME'] := EmptyStr;
end;

procedure TFormIDE.FileOpen(A: TSender);
begin
  OpenDialog.FileName := FileName;
  if OpenDialog.Execute then begin
    LoadFromFile(OpenDialog.FileName);
  end else begin
    Abort;
  end;
end;

procedure TFormIDE.FileOpenInNewWindow(A: TSender);
begin
  if OpenDialog.Execute then begin
    FProcess.Environment.Values['FILENAME'] := OpenDialog.FileName;
    FileNewWindow(A);
  end else begin
    Abort;
  end;
end;

procedure TFormIDE.FileSave(A: TSender);
begin
  try
    SaveToFile(FileName);
  except
    FileSaveAs(A);
  end;
end;

procedure TFormIDE.FileSaveAs(A: TSender);
begin
  SaveDialog.FileName := FileName;
  if SaveDialog.Execute then begin
    SaveToFile(SaveDialog.FileName);
  end else begin
    Abort;
  end;
end;

procedure TFormIDE.FileExit(A: TSender);
begin
  Close;
end;

procedure TFormIDE.EditUndo(A: TSender);
begin
  FMemo.Undo;
end;

procedure TFormIDE.EditRedo(A: TSender);
begin
  FMemo.Redo;
end;

procedure TFormIDE.EditCut(A: TSender);
begin
  FMemo.CutToClipboard;
end;

procedure TFormIDE.EditCopy(A: TSender);
begin
  FMemo.CopyToClipboard;
end;

procedure TFormIDE.EditPaste(A: TSender);
begin
  FMemo.PasteFromClipboard;
end;

procedure TFormIDE.EditDelete(A: TSender);
begin
  FMemo.ClearSelection;
end;

procedure TFormIDE.EditSelectAll(A: TSender);
begin
  FMemo.SelectAll;
end;

procedure TFormIDE.EditFind(A: TSender);
begin

end;

procedure TFormIDE.EditFindNext(A: TSender);
begin

end;

procedure TFormIDE.EditReplace(A: TSender);
begin

end;

procedure TFormIDE.EditUpperCase(A: TSender);
begin
  FMemo.ReplaceSelectedText(AnsiUpperCase(FMemo.SelText));
end;

procedure TFormIDE.EditLowerCase(A: TSender);
begin
  FMemo.ReplaceSelectedText(AnsiLowerCase(FMemo.SelText));
end;

procedure TFormIDE.EditFormatSource(A: TSender);
var
  LDst, LSrc: TStringStream;
begin
  LSrc := TStringStream.Create(FMemo.Text);
  try
    LDst := TStringStream.Create(EmptyStr);
    try
      ProcessPipe(LDst, LSrc, ProgramDirectory + 'astyle.exe', EmptyStr, ['-A8', '-xC100', '-k1', '-w',
        (*'-U',*) '-H', '-j', '-s' + IntToStr(4)], []);
      FMemo.Text := LDst.DataString;
    finally
      FreeAndNil(LDst);
    end;
  finally
    FreeAndNil(LSrc);
  end;
end;

procedure TFormIDE.RunSyntaxCheck(A: TSender);
begin
  Execute(ProgramDirectory + 'cmoc.exe', ['--help'], False);
end;

procedure TFormIDE.RunCompile(A: TSender);
begin

end;

procedure TFormIDE.RunBuild(A: TSender);
begin

end;

procedure TFormIDE.RunBuildAndRun(A: TSender);
begin

end;

procedure TFormIDE.ToolsOpenConsole(A: TSender);
begin
  LogMessage('Opening WinCMOC Console');
  Execute(ProgramDirectory + 'console.bat', [], True);
end;

procedure TFormIDE.OpenMESSImage(const A: TFileName);
begin
  LogFileName('Opening MESS Image Tool', A);
  Execute(ProgramDirectory + 'wimgtool.exe', [A], True);
end;

procedure TFormIDE.ToolsMessImageTool(A: TSender);
begin
  OpenMESSImage(EmptyStr);
end;

procedure TFormIDE.ToolsOpenDisk0(A: TSender);
begin
  OpenMESSImage(ProgramDirectory + '..\dsk\disk0.dsk');
end;

procedure TFormIDE.ToolsOpenDisk1(A: TSender);
begin
  OpenMESSImage(ProgramDirectory + '..\dsk\disk1.dsk');
end;

procedure TFormIDE.ToolsOpenDisk2(A: TSender);
begin
  OpenMESSImage(ProgramDirectory + '..\dsk\disk2.dsk');
end;

end.
