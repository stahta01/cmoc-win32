unit MainForm;

{$mode objfpc}{$H+}

interface

uses Classes, ComCtrls, Controls, CustomForms, Dialogs, Documents, FatCowIcons,
  FileUtils, FindForms, Forms, Graphics, GraphTypes, LclType,
  Memos, Menus, Process, ProcessUtils, Programs, Splitters, StdCtrls, StrUtils, SysUtils;

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
    procedure Execute(const AExecutable: string; const AParameters: array of string;
      const AConsole: boolean);
    procedure AddEditMenuItems(const A: TAbstractMenuItem);
    procedure LogMessage(const A: string);
    procedure LogFileName(const A, AFileName: string);
    procedure SetFileName(const A: TFileName); override;
    procedure SaveToFile(const A: TFileName); override;
    procedure LoadFromFile(const A: TFileName); override;
    procedure OpenMESSImage(const A: TFileName);
  public
    procedure ListBoxInserted(A: TObject; AIndex: integer);
  public
    procedure FormShow(A: TObject);
    procedure FormCloseQuery(A: TObject; var ACanClose: boolean);
  public
    procedure FileNew(A: TObject);
    procedure FileNewWindow(A: TObject);
    procedure FileOpen(A: TObject);
    procedure FileOpenInNewWindow(A: TObject);
    procedure FileSave(A: TObject);
    procedure FileSaveAs(A: TObject);
    procedure FileExit(A: TObject);
  public
    procedure EditUndo(A: TObject);
    procedure EditRedo(A: TObject);
    procedure EditCut(A: TObject);
    procedure EditCopy(A: TObject);
    procedure EditPaste(A: TObject);
    procedure EditDelete(A: TObject);
    procedure EditSelectAll(A: TObject);
    procedure EditFind(A: TObject);
    procedure EditFindNext(A: TObject);
    procedure EditReplace(A: TObject);
    procedure EditUpperCase(A: TObject);
    procedure EditLowerCase(A: TObject);
    procedure EditFormatSource(A: TObject);
  public
    procedure RunSyntaxCheck(A: TObject);
    procedure RunCompile(A: TObject);
    procedure RunBuild(A: TObject);
    procedure RunBuildAndRun(A: TObject);
  public
    procedure ToolsOpenConsole(A: TObject);
    procedure ToolsMessImageTool(A: TObject);
    procedure ToolsOpenDisk0(A: TObject);
    procedure ToolsOpenDisk1(A: TObject);
    procedure ToolsOpenDisk2(A: TObject);
  end;

var
  FormMain: TForm;
  FormFind: TFormFind;

implementation

constructor TFormIDE.Create(A: TComponent);
begin
  inherited;

  OnShow := @FormShow;
  OnCloseQuery := @FormCloseQuery;

  SetSize(720, 500);
  Position := poScreenCenter;
  WindowState := wsMaximized;

  FProcess := TProcess.Create(Self);
  FIcons := TFatCowIcons.Create(ProgramDirectory + 'images');

  with StatusBar.AddPanel do begin
    Width := 100;
  end;
  with StatusBar.AddPanel do begin
    Width := 100;
  end;
  with StatusBar.AddPanel do begin
    Align := alClient;
  end;
  with MainMenu do begin
    with AddMenuItem('&File') do begin
      AddMenuItem('&New', @FileNew, FIcons.New);
      AddMenuItem('New Window', @FileNewWindow, FIcons.NewWindow);
      AddMenuItem(cLineCaption);
      AddMenuItem('&Open ...', @FileOpen, FIcons.Open);
      AddMenuItem('Open New Window ...', @FileOpenInNewWindow, FIcons.FolderGo);
      AddMenuItem(cLineCaption);
      AddMenuItem('&Save', @FileSave, FIcons.Save).ShortCut := scCtrl + VK_S;
      AddMenuItem('Save &As ...', @FileSaveAs, FIcons.FileSaveAs);
      AddMenuItem(cLineCaption);
      AddMenuItem('E&xit', @FileExit, FIcons.Door);
    end;
    AddEditMenuItems(AddMenuItem('&Edit'));
    with AddMenuItem('&Run') do begin
      AddMenuItem('&Syntax Check', @RunSyntaxCheck, FIcons.TickButton);
      AddMenuItem('&Compile', @RunCompile, FIcons.Compile);
      AddMenuItem(cLineCaption);
      AddMenuItem('&Build', @RunBuild, FIcons.Bricks);
      AddMenuItem('Build and &Run ...', @RunBuildAndRun, FIcons.BrickGo);
    end;
    with AddMenuItem('E&mulators') do begin
      AddMenuItem('Colour Computer 1 (Color BASIC 1.0)', nil, FIcons.BulletRight);
      AddMenuItem('Colour Computer 1 (Disk Extended Color BASIC 1.0)', nil, FIcons.BulletRight);
      AddMenuItem('Colour Computer 2 (Disk Extended Color BASIC 1.1)', nil, FIcons.BulletRight);
      AddMenuItem('Colour Computer 3 (Disk Extended Color BASIC 2.1)', nil, FIcons.BulletRight);
      AddMenuItem(cLineCaption);
      AddMenuItem('Dragon 32 (PAL)', nil, FIcons.BulletRight);
      AddMenuItem('Dragon 64 (PAL)', nil, FIcons.BulletRight);
      AddMenuItem('Dragon 200-E (PAL)', nil, FIcons.BulletRight);
      AddMenuItem('Tano Dragon (NTSC)', nil, FIcons.BulletRight);
      AddMenuItem('Dynacom MX-1600 (PAL-M)', nil, FIcons.BulletRight);
      AddMenuItem(cLineCaption);
      AddMenuItem('EDTASM++ 1.1 ...', nil, FIcons.BulletRight);
    end;
    with AddMenuItem('&Tools') do begin
      AddMenuItem('WinCMOC Console ...', @ToolsOpenConsole);
      AddMenuItem(cLineCaption);
      AddMenuItem('Disassemble 6809 Binary ...');
      AddMenuItem(cLineCaption);
      AddMenuItem('MESS Image Tool ...', @ToolsMessImageTool);
      AddMenuItem('Open Disk #0 ...', @ToolsOpenDisk0);
      AddMenuItem('Open Disk #1 ...', @ToolsOpenDisk1);
      AddMenuItem('Open Disk #2 ... (EDTASM++)', @ToolsOpenDisk2);
    end;
    with AddMenuItem('&Help') do begin
      AddMenuItem('&About WinCMOC ...');
    end;
  end;
  ToolBar.Height := 44;
  ToolBar.AddToolBarButton('New', @FileNew, FIcons.New);
  ToolBar.AddToolBarButton('Open', @FileOpen, FIcons.Open);
  ToolBar.AddToolBarButton('Save', @FileSave, FIcons.Save);
  ToolBar.AddToolBarButton('Undo', @EditUndo, FIcons.Undo);
  ToolBar.AddToolBarButton('Redo', @EditRedo, FIcons.Redo);
  ToolBar.AddToolBarButton('Cut', @EditCut, FIcons.Cut);
  ToolBar.AddToolBarButton('Copy', @EditCopy, FIcons.Copy);
  ToolBar.AddToolBarButton('Paste', @EditPaste, FIcons.Paste);
  ToolBar.AddToolBarButton('Delete', @EditDelete, FIcons.Cross);
  ToolBar.AddToolBarButton('Syntax Check', @RunSyntaxCheck, FIcons.TickButton);
  ToolBar.AddToolBarButton('Compile', @RunCompile, FIcons.Compile);
  ToolBar.AddToolBarButton('Build', @RunBuild, FIcons.Bricks);
  ToolBar.AddToolBarButton('Build and Run', @RunBuildAndRun, FIcons.BrickGo);

  FSplitter := TPairSplitter.Create(Self);
  FSplitter.Widget.setResizeWeight(1);
  FSplitter.SplitterType := pstVertical;
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
    FMemo.Lines.Add('apple orange pair');
    FMemo.Lines.Add('#include <math.h>');
    FMemo.Lines.Add('#include <ctype.h>');
    FMemo.Lines.Add('#include <stdio.h>');
    FMemo.Lines.Add('#include <stdlib.h>');
    FMemo.Lines.Add('#include <string.h>');
    FMemo.Lines.Add('#include <conio.h>');
    FMemo.Lines.Add(EmptyStr);
    FMemo.Lines.Add('int main(void)');
    FMemo.Lines.Add('{');
    FMemo.Lines.Add('    puts("WELCOME TO ' + UpperCase(Application.Title) + '!");');
    FMemo.Lines.Add('    return 0;');
    FMemo.Lines.Add('}');
    FMemo.ClearUndo;
    FileName := EmptyStr;
  end;
end;

procedure TFormIDE.AddEditMenuItems(const A: TAbstractMenuItem);
begin
  with A do begin
    AddMenuItem('&Undo', @EditUndo, FIcons.Undo);
    AddMenuItem('&Redo', @EditRedo, FIcons.Redo);
    AddMenuItem(cLineCaption);
    AddMenuItem('Cu&t', @EditCut, FIcons.Cut);
    AddMenuItem('&Copy', @EditCopy, FIcons.Copy);
    AddMenuItem('&Paste', @EditPaste, FIcons.Paste);
    AddMenuItem('&Delete', @EditDelete, FIcons.Cross);
    AddMenuItem(cLineCaption);
    AddMenuItem('Select &All', @EditSelectAll, FIcons.LayerSelect);
    AddMenuItem(cLineCaption);
    AddMenuItem('&Find ...', @EditFind, FIcons.Find).ShortCut := scCtrl + VK_F;
    AddMenuItem('Find Next', @EditFindNext);
    AddMenuItem(cLineCaption);
    AddMenuItem('Replace', @EditReplace).ShortCut := scCtrl + VK_R;
    AddMenuItem(cLineCaption);
    AddMenuItem('Uppercase Selection', @EditUpperCase).ShortCut := scAlt + VK_UP;
    AddMenuItem('Lowercase Selection', @EditLowerCase).ShortCut := scAlt + VK_DOWN;
    AddMenuItem(cLineCaption);
    AddMenuItem('Format Source Code (AStyle)', @EditFormatSource).ShortCut := scCtrl + VK_D;
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
  FMemo.ClearUndo;
  FMemo.SelStart := 0;
  inherited;
end;

procedure TFormIDE.Execute(const AExecutable: string; const AParameters: array of string;
  const AConsole: boolean);
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

procedure TFormIDE.ListBoxInserted(A: TObject; AIndex: integer);
begin
  FListBox.ItemIndex := AIndex;
  FListBox.MakeCurrentVisible;
end;

procedure TFormIDE.FormShow(A: TObject);
begin
  LogMessage('Welcome to ' + Application.Title);
  FSplitter.Position := Height - 256;
end;

procedure TFormIDE.FormCloseQuery(A: TObject; var ACanClose: boolean);
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

procedure TFormIDE.FileNew(A: TObject);
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

procedure TFormIDE.FileNewWindow(A: TObject);
begin
  LogMessage('Opening New WinCMOC IDE Window');
  Execute('javaw', ['-cp', TProgram.FileName, 'cmocide'], True);
  FProcess.Environment.Values['FILENAME'] := EmptyStr;
end;

procedure TFormIDE.FileOpen(A: TObject);
begin
  OpenDialog.FileName := FileName;
  if OpenDialog.Execute then begin
    LoadFromFile(OpenDialog.FileName);
  end else begin
    Abort;
  end;
end;

procedure TFormIDE.FileOpenInNewWindow(A: TObject);
begin
  if OpenDialog.Execute then begin
    FProcess.Environment.Values['FILENAME'] := OpenDialog.FileName;
    FileNewWindow(A);
  end else begin
    Abort;
  end;
end;

procedure TFormIDE.FileSave(A: TObject);
begin
  try
    SaveToFile(FileName);
  except
    FileSaveAs(A);
  end;
end;

procedure TFormIDE.FileSaveAs(A: TObject);
begin
  SaveDialog.FileName := FileName;
  if SaveDialog.Execute then begin
    SaveToFile(SaveDialog.FileName);
  end else begin
    Abort;
  end;
end;

procedure TFormIDE.FileExit(A: TObject);
begin
  Close;
end;

procedure TFormIDE.EditUndo(A: TObject);
begin
  FMemo.Undo;
end;

procedure TFormIDE.EditRedo(A: TObject);
begin
  FMemo.Redo;
end;

procedure TFormIDE.EditCut(A: TObject);
begin
  FMemo.CutToClipboard;
end;

procedure TFormIDE.EditCopy(A: TObject);
begin
  FMemo.CopyToClipboard;
end;

procedure TFormIDE.EditPaste(A: TObject);
begin
  FMemo.PasteFromClipboard;
end;

procedure TFormIDE.EditDelete(A: TObject);
begin
  FMemo.ClearSelection;
end;

procedure TFormIDE.EditSelectAll(A: TObject);
begin
  FMemo.SelectAll;
end;

procedure TFormIDE.EditFind(A: TObject);
begin
  FormFind.OnFind := @EditFindNext;
  FormFind.Search.Text := FMemo.SelText;
  FormFind.ShowModal;
end;

procedure TFormIDE.EditFindNext(A: TObject);
begin
  FormFind.Search.Text := Trim(FormFind.Search.Text);
  if Length(FormFind.Search.Text) = 0 then begin
    EditFind(A);
  end else begin
    if FMemo.SearchReplace(FormFind.Search.Text, EmptyStr, []) < 0 then begin
      if MessageDlg('Search from the beginning?', mtConfirmation, mbYesNo, 0) = mrYes then begin
        FMemo.SelStart := 0;
        if FMemo.SearchReplace(FormFind.Search.Text, EmptyStr, []) < 0 then begin
          ShowMessage('Search complete');
        end;
      end;
    end;
  end;
end;

procedure TFormIDE.EditReplace(A: TObject);
begin
end;

procedure TFormIDE.EditUpperCase(A: TObject);
begin
  FMemo.ReplaceSelectedText(AnsiUpperCase(FMemo.SelText));
end;

procedure TFormIDE.EditLowerCase(A: TObject);
begin
  FMemo.ReplaceSelectedText(AnsiLowerCase(FMemo.SelText));
end;

procedure TFormIDE.EditFormatSource(A: TObject);
var
  LDst, LSrc: TStringStream;
begin
  if MessageDlg('Do you want to format the source code?', mtConfirmation, mbYesNo, 0) = mrYes then begin
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
end;

procedure TFormIDE.RunSyntaxCheck(A: TObject);
begin
  Execute(ProgramDirectory + 'cmoc.exe', ['--help'], False);
end;

procedure TFormIDE.RunCompile(A: TObject);
begin

end;

procedure TFormIDE.RunBuild(A: TObject);
begin

end;

procedure TFormIDE.RunBuildAndRun(A: TObject);
begin

end;

procedure TFormIDE.ToolsOpenConsole(A: TObject);
begin
  LogMessage('Opening WinCMOC Console');
  Execute(ProgramDirectory + 'console.bat', [], True);
end;

procedure TFormIDE.OpenMESSImage(const A: TFileName);
begin
  LogFileName('Opening MESS Image Tool', A);
  Execute(ProgramDirectory + 'wimgtool.exe', [A], True);
end;

procedure TFormIDE.ToolsMessImageTool(A: TObject);
begin
  OpenMESSImage(EmptyStr);
end;

procedure TFormIDE.ToolsOpenDisk0(A: TObject);
begin
  OpenMESSImage(ProgramDirectory + '..\dsk\disk0.dsk');
end;

procedure TFormIDE.ToolsOpenDisk1(A: TObject);
begin
  OpenMESSImage(ProgramDirectory + '..\dsk\disk1.dsk');
end;

procedure TFormIDE.ToolsOpenDisk2(A: TObject);
begin
  OpenMESSImage(ProgramDirectory + '..\dsk\disk2.dsk');
end;

end.
