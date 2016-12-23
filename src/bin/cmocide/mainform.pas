unit MainForm;

{$mode objfpc}{$H+}

interface

uses Classes, ComCtrls, Controls, CustomForms, Documents, FileUtils, Forms, IdeIcons, Java, LCLIntf, Memos,
  Menus, Process, ProcessUtils, Splitters, StdCtrls, StrUtils, SysUtils;

type

  TFormIDE = class(TFormSDI)
  strict private
    FIcons: TIdeIcons;
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
    procedure SetFileName(const A: TFileName); override;
    procedure SaveToFile(const A: TFileName); override;
    procedure LoadFromFile(const A: TFileName); override;
  public
    procedure ListBoxInserted(A: TSender; AIndex: integer);
  public
    procedure FormShow(A: TSender);
  public
    procedure FileNew(A: TSender);
    procedure FileOpen(A: TSender);
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
    procedure EditFormatSource(A: TSender);
  public
    procedure ToolsOpenConsole(A: TSender);
    procedure ToolsMessImageTool(A: TSender);
  end;

var
  FormMain: TForm;

implementation

constructor TFormIDE.Create(A: TComponent);
begin
  inherited;

  OnShow := @FormShow;

  Width := 720;
  Height := 500;
  Position := poScreenCenter;

  FProcess := TProcess.Create(Self);
  FIcons := TIdeIcons.Create;

  with MainMenu do begin
    with AddMenuItem('File') do begin
      AddMenuItem('New', @FileNew).Icon := FIcons.New;
      AddMenuItem('New Window');
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('Open ...', @FileOpen).Icon := FIcons.Open;
      AddMenuItem('Open New Window ...');
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('Save', @FileSave).Icon := FIcons.Save;
      AddMenuItem('Save As ...', @FileSaveAs);
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('Exit', @FileExit);
    end;
    AddEditMenuItems(AddMenuItem('Edit'));
    with AddMenuItem('Run') do begin
      AddMenuItem('Syntax Check').Icon := FIcons.SyntaxCheck;
      AddMenuItem('Compile').Icon := FIcons.Compile;
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('Build').Icon := FIcons.Build;
      AddMenuItem('Build and Run ...').Icon := FIcons.BuildAndRun;
    end;
    with AddMenuItem('Emulators') do begin
      AddMenuItem('Colour Computer 1 (Color BASIC 1.0)');
      AddMenuItem('Colour Computer 1 (Disk Extended Color BASIC 1.0)');
      AddMenuItem('Colour Computer 2 (Disk Extended Color BASIC 1.1)');
      AddMenuItem('Colour Computer 3 (Disk Extended Color BASIC 2.1)');
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('Dragon 32 (PAL)');
      AddMenuItem('Dragon 64 (PAL)');
      AddMenuItem('Dragon 200-E (PAL)');
      AddMenuItem('Tano Dragon (NTSC)');
      AddMenuItem('Dynacom MX-1600 (PAL-M)');
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('EDTASM++ 1.1 ...');
    end;
    with AddMenuItem('Tools') do begin
      AddMenuItem('WinCMOC Console ...', @ToolsOpenConsole);
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('Disassemble 6809 Binary ...');
      AddMenuItem(MenuItemSeparator);
      AddMenuItem('MESS Image Tool ...', @ToolsMessImageTool);
      AddMenuItem('Open Disk #0 ...');
      AddMenuItem('Open Disk #1 ...');
      AddMenuItem('Open Disk #2 ... (EDTASM++)');
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
  ToolBar.AddToolBarButton('Delete', @EditDelete).Icon := FIcons.Delete;
  ToolBar.AddToolBarButton('Syntax Check').Icon := FIcons.SyntaxCheck;
  ToolBar.AddToolBarButton('Compile').Icon := FIcons.Compile;
  ToolBar.AddToolBarButton('Build').Icon := FIcons.Build;
  ToolBar.AddToolBarButton('Build and Run').Icon := FIcons.BuildAndRun;

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
  FListBox.Parent := FSplitter.Sides[1];

  OpenDialog.Filter := 'C/C++ Files|*.c;*.h;*.cpp;*.hpp|All Files|*.*';
  SaveDialog.Filter := OpenDialog.Filter;
  FileName := EmptyStr;

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
    AddMenuItem('Delete', @EditDelete).Icon := FIcons.Delete;
    AddMenuItem(MenuItemSeparator);
    AddMenuItem('Select All', @EditSelectAll).Icon := FIcons.Delete;
    AddMenuItem(MenuItemSeparator);
    AddMenuItem('Find ...');
    AddMenuItem('Find Next');
    AddMenuItem(MenuItemSeparator);
    AddMenuItem('Replace');
    AddMenuItem(MenuItemSeparator);
    AddMenuItem('Uppercase Selection');
    AddMenuItem('Lowercase Selection');
    AddMenuItem(MenuItemSeparator);
    AddMenuItem('Format Source Code (AStyle)', @EditFormatSource);
  end;
end;

procedure TFormIDE.LogMessage(const A: string);
begin
  FListBox.Items.Add(A);
end;

procedure TFormIDE.SetFileName(const A: TFileName);
begin
  FMemo.Modified := False;
  inherited;
end;

procedure TFormIDE.SaveToFile(const A: TFileName);
begin
  FMemo.Lines.SaveToFile(A);
  inherited;
end;

procedure TFormIDE.LoadFromFile(const A: TFileName);
begin
  FMemo.Text := AnsiLoadFromFile(A);
  FMemo.ClearUndoBuffer;
  FMemo.SelStart := 0;
  inherited;
end;

procedure TFormIDE.Execute(const AExecutable: string; const AParameters: array of string;
  const AConsole: boolean);
begin
  FListBox.Items.Clear;
  with FProcess do begin
    if AConsole then begin
      Options := [];
    end else begin
      Options := [poUsePipes];
    end;
    Executable := AExecutable;
    if not FileExists(Executable) then begin
      Executable := ExeSearch(AExecutable);
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

procedure TFormIDE.FileNew(A: TSender);
begin
  FMemo.Lines.Clear;
  FileName := EmptyStr;
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
  //Execute(ProgramDirectory + 'cmoc.exe', ['--help'], False);
end;

procedure TFormIDE.ToolsOpenConsole(A: TSender);
begin
  Execute(ProgramDirectory + 'console.bat', [], True);
end;

procedure TFormIDE.ToolsMessImageTool(A: TSender);
begin
  Execute(ProgramDirectory + 'wimgtool.exe', [], True);
end;

end.
