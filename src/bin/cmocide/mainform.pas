unit MainForm;

{$mode objfpc}{$H+}

interface

uses BaseTypes, Classes, ComCtrls, CustomForms, Dialogs, ExtCtrls, FileUtils, Forms, Graphics,
  Java, LCLType, Math, Menus, Process, ProcessUtils, StdCtrls, StrTools, StrUtils, SysUtils,
  UEditor, UEditorPageControl, UFatCow, UHighlighterCpp, UPairSplitter, UProgram;

type

  TFormMain = class(TFormToolStatusBar)
  strict private
    FIcons: TFatCow;
    FSplitter: TPairSplitter;
    FProcess: TProcess;
    FListBox: TListBox;
    FEditors: TEditorPageControl;
    FEditorPopupMenu: TPopupMenu;
    FFindDialog: TFindDialog;
    FReplaceDialog: TReplaceDialog;
    FButtonUndo, FButtonRedo, FButtonCut, FButtonCopy, FButtonPaste, FButtonDelete: TButton;
  public
    constructor Create(A: TComponent); override;
  public
    procedure CloseQueryDlg;
    procedure Execute(const AExecutable: string; const AParameters: array of string;
      const AConsole: boolean);
    procedure AddEditMenuItems(const A: TCustomMenuItem);
    procedure LogMessage(const A: string);
    procedure LogFileName(const A, AFileName: string);
    procedure OpenMESSImage(const A: TFileName);
  public
    procedure ListBoxInsert(A: TObject; const AIndex: integer);
    procedure MemoChange(A: TObject);
    procedure MemoCaretUpdate(A: TObject);
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
    procedure FileClose(A: TObject);
    procedure FilePrint(A: TObject);
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
    procedure EditReplaceNext(A: TObject);
    procedure EditUpperCase(A: TObject);
    procedure EditLowerCase(A: TObject);
    procedure EditFormatSource(A: TObject);
    procedure EditPopupMenuShow(A: TObject);
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
  public
    procedure CreateStatusBar;
    procedure CreateMainMenu;
    procedure CreateToolBar;
    procedure CreateSpliter;
    procedure CreateLog;
  end;

var
  FormMain: TFormMain;

implementation

constructor TFormMain.Create(A: TComponent);
begin
  inherited;

  OnShow := @FormShow;
  OnCloseQuery := @FormCloseQuery;

  SetSize(720, 500);
  Position := poScreenCenter;
  WindowState := wsMaximized;
  SizeConstraints.MinWidth := 200;
  SizeConstraints.MinHeight := 200;

  OpenDialog.Filter := 'C/C++ Files (*.c)|*.c;*.h;*.cpp;*.hpp|All Files (*.*)|*.*';
  SaveDialog.Filter := OpenDialog.Filter;


  FFindDialog := TFindDialog.Create(Self);
  FFindDialog.OnFind := @EditFindNext;
  FReplaceDialog := TReplaceDialog.Create(Self);
  FReplaceDialog.OnReplace := @EditReplaceNext;

  FProcess := TProcess.Create(Self);
  FIcons := TFatCow.Create(ProgramDirectory + 'images');

  CreateStatusBar;
  CreateMainMenu;
  CreateToolBar;
  CreateSpliter;
  CreateLog;

  FEditorPopupMenu := TPopupMenu.Create(Self);
  FEditorPopupMenu.OnPopup := @EditPopupMenuShow;
  AddEditMenuItems(FEditorPopupMenu);

  FEditors := TEditorPageControl.Create(Self);
  FEditors.Align := alClient;
  FEditors.Focusable := False;
  FEditors.Parent := FSplitter.Sides[0];

  FileNew(nil);
end;

procedure TFormMain.FormShow(A: TObject);
begin
  LogMessage('Welcome to ' + Application.Title);
  FSplitter.Position := Height - 256;
end;

procedure TFormMain.AddEditMenuItems(const A: TCustomMenuItem);
begin
  with A do begin
    with AddMenuItem('&Undo', @EditUndo, FIcons.Undo) do begin
      Name := 'undo';
      ShortCut := scCtrl + VK_Z;
    end;
    with AddMenuItem('&Redo', @EditRedo, FIcons.Redo) do begin
      Name := 'redo';
      ShortCut := scCtrl + scShift + VK_Z;
    end;
    AddMenuItem(cLineCaption);
    with AddMenuItem('Cu&t', @EditCut, FIcons.Cut) do begin
      ShortCut := scCtrl + VK_X;
    end;
    with AddMenuItem('&Copy', @EditCopy, FIcons.Copy) do begin
      ShortCut := scCtrl + VK_C;
    end;
    AddMenuItem('&Paste', @EditPaste, FIcons.Paste).ShortCut := scCtrl + VK_V;
    AddMenuItem('&Delete', @EditDelete, FIcons.Cross).ShortCut := VK_DELETE;
    AddMenuItem(cLineCaption);
    AddMenuItem('Select &All', @EditSelectAll, FIcons.LayerSelect).ShortCut := scCtrl + VK_A;
    AddMenuItem(cLineCaption);
    AddMenuItem('&Find ...', @EditFind, FIcons.Find).ShortCut := scCtrl + VK_F;
    AddMenuItem('Find Next', @EditFindNext).ShortCut := VK_F3;
    AddMenuItem(cLineCaption);
    AddMenuItem('Replace', @EditReplace).ShortCut := scCtrl + VK_R;
    AddMenuItem(cLineCaption);
    AddMenuItem('Uppercase Selection', @EditUpperCase).ShortCut := scAlt + VK_UP;
    AddMenuItem('Lowercase Selection', @EditLowerCase).ShortCut := scAlt + VK_DOWN;
    AddMenuItem(cLineCaption);
    AddMenuItem('Format Source Code (AStyle)', @EditFormatSource).ShortCut := scCtrl + VK_D;
  end;
end;

procedure TFormMain.LogMessage(const A: string);
begin
  FListBox.Items.Add(A);
end;

procedure TFormMain.LogFileName(const A, AFileName: string);
begin
  if Length(AFileName) = 0 then begin
    LogMessage(A);
  end else begin
    LogMessage(A + ' - [' + AFileName + ']');
  end;
end;

procedure TFormMain.Execute(const AExecutable: string; const AParameters: array of string;
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

procedure TFormMain.ListBoxInsert(A: TObject; const AIndex: integer);
begin
  FListBox.ItemIndex := AIndex;
  FListBox.MakeCurrentVisible;
end;

procedure TFormMain.MemoCaretUpdate(A: TObject);
begin
  with FEditors.ActiveEditor.CaretPos do begin
    StatusBar.Panels[0].Caption := IntToStr(X) + ':' + IntToStr(Y);
  end;
  FButtonCut.Enabled := FEditors.ActiveEditor.SelLength > 0;
  FButtonCopy.Enabled := FButtonCut.Enabled;
  FButtonDelete.Enabled := FButtonCut.Enabled;
end;

procedure TFormMain.MemoChange(A: TObject);
var
  LFileName: TFileName;
begin
  LFileName := FEditors.GetFileName;
  if Length(LFileName) = 0 then begin
    LFileName := 'untitled';
  end;
  Caption := Application.Title + ' - [' + LFileName + ']';
  StatusBar.Panels[1].Caption := IfThen(FEditors.ActiveEditor.Modified, 'Modified', EmptyStr);
  StatusBar.Panels[3].Caption := LFileName;
  FButtonUndo.Enabled := FEditors.ActiveEditor.CanUndo;
  FButtonRedo.Enabled := FEditors.ActiveEditor.CanRedo;
  MemoCaretUpdate(FEditors.ActiveEditor);
end;

procedure TFormMain.CloseQueryDlg;
begin
  case MessageDlg('Do you want to save changes?', mtConfirmation, mbYesNoCancel, 0) of
    mrYes: begin
      FileSave(nil);
    end;
    mrCancel: begin
      Abort;
    end;
  end;
end;

procedure TFormMain.FormCloseQuery(A: TObject; var ACanClose: boolean);
var
  LIndex: integer;
begin
  for LIndex := 0 to FEditors.PageCount - 1 do begin
    if FEditors.GetEditor(LIndex).Modified then begin
      FEditors.ActivePageIndex := LIndex;
      CloseQueryDlg;
    end;
  end;
end;

procedure TFormMain.FileNew(A: TObject);
var
  LEditor: TEditor;
  LDocument: THighlighterCpp;
begin
  LDocument := THighlighterCpp.Create;
  LDocument.Objects.LoadFromFile(ProgramDirectory + 'cmocide\objects.txt');
  LDocument.Keywords.LoadFromFile(ProgramDirectory + 'cmocide\keywords.txt');
  LDocument.Constants.LoadFromFile(ProgramDirectory + 'cmocide\constants.txt');

  LEditor := FEditors.AddEditor(TRichMemo);
  LEditor.BorderStyle := bsNone;
  LEditor.Document := LDocument;
  LEditor.OnChange := @MemoChange;
  LEditor.OnCaretUpdate := @MemoCaretUpdate;
  LEditor.OnCaretUpdate(LEditor);
  LEditor.UndoLimit := 1000;
  LEditor.PopupMenu := FEditorPopupMenu;

  if FEditors.PageCount = 1 then begin
    LEditor.Clear;
    LEditor.Lines.Add('#include <math.h>');
    LEditor.Lines.Add('#include <ctype.h>');
    LEditor.Lines.Add('#include <stdio.h>');
    LEditor.Lines.Add('#include <stdlib.h>');
    LEditor.Lines.Add('#include <string.h>');
    LEditor.Lines.Add('#include <conio.h>');
    LEditor.Lines.Add(EmptyStr);
    LEditor.Lines.Add('int main(void)');
    LEditor.Lines.Add('{');
    LEditor.Lines.Add('    puts("WELCOME TO ' + UpperCase(Application.Title) + '!");');
    LEditor.Lines.Add('    return 0;');
    LEditor.Lines.Add('}');
    LEditor.ClearUndo;
  end;
  FEditors.SetFileName(EmptyStr);
end;

procedure TFormMain.FileOpen(A: TObject);
var
  LText: TText;
begin
  if OpenDialog.Execute then begin
    LogFileName('Loading', OpenDialog.FileName);
    try
      LText := AnsiLoadFromFile(OpenDialog.FileName);
      FileNew(nil);
      FEditors.ActiveEditor.Text := LText;
      FEditors.ActiveEditor.SelStart := 0;
      FEditors.SetFileName(EmptyStr);
    except
      ShowMessageError('Unable to load file');
      Abort;
    end;
  end else begin
    Abort;
  end;
end;

procedure TFormMain.FileNewWindow(A: TObject);
begin
  LogMessage('Opening New WinCMOC IDE Window');
  Execute('javaw', ['-cp', TProgram.FileName, 'cmocide'], True);
  FProcess.Environment.Values['FILENAME'] := EmptyStr;
end;

procedure TFormMain.FileOpenInNewWindow(A: TObject);
begin
  if OpenDialog.Execute then begin
    FProcess.Environment.Values['FILENAME'] := OpenDialog.FileName;
    FileNewWindow(nil);
  end else begin
    Abort;
  end;
end;

procedure TFormMain.FileSave(A: TObject);
begin
  try
    FEditors.SaveToFile;
  except
    FileSaveAs(A);
  end;
end;

procedure TFormMain.FileSaveAs(A: TObject);
begin
  SaveDialog.FileName := FEditors.GetFileName;
  if SaveDialog.Execute then begin
    FEditors.SaveToFile(SaveDialog.FileName);
  end else begin
    Abort;
  end;
end;

procedure TFormMain.FileClose(A: TObject);
begin
  if FEditors.ActiveEditor.Modified then begin
    CloseQueryDlg;
  end;
  FEditors.ActivePage.Free;
  if FEditors.PageCount = 0 then begin
    Close;
  end;
end;

procedure TFormMain.FilePrint(A: TObject);
begin
  FEditors.ActiveEditor.Print;
end;

procedure TFormMain.FileExit(A: TObject);
begin
  Close;
end;

procedure TFormMain.EditUndo(A: TObject);
begin
  FEditors.ActiveEditor.Undo;
end;

procedure TFormMain.EditRedo(A: TObject);
begin
  FEditors.ActiveEditor.Redo;
end;

procedure TFormMain.EditCut(A: TObject);
begin
  FEditors.ActiveEditor.CutToClipboard;
end;

procedure TFormMain.EditCopy(A: TObject);
begin
  FEditors.ActiveEditor.CopyToClipboard;
end;

procedure TFormMain.EditPaste(A: TObject);
begin
  FEditors.ActiveEditor.PasteFromClipboard;
end;

procedure TFormMain.EditDelete(A: TObject);
begin
  FEditors.ActiveEditor.ClearSelection;
end;

procedure TFormMain.EditSelectAll(A: TObject);
begin
  FEditors.ActiveEditor.SelectAll;
end;

procedure TFormMain.EditFind(A: TObject);
begin
  FFindDialog.FindText := FEditors.ActiveEditor.SelText;
  FFindDialog.Execute;
end;

procedure TFormMain.EditFindNext(A: TObject);
begin
  FFindDialog.FindText := Trim(FFindDialog.FindText);
  if Length(FFindDialog.FindText) = 0 then begin
    EditFind(A);
  end else begin
    FEditors.ActiveEditor.ShowSearchReplace(FFindDialog.FindText, EmptyStr, []);
  end;
end;

procedure TFormMain.EditReplace(A: TObject);
begin
  FReplaceDialog.Execute;
end;

procedure TFormMain.EditReplaceNext(A: TObject);
begin
  FEditors.ActiveEditor.ShowSearchReplace(FReplaceDialog.FindText, FReplaceDialog.ReplaceText, [soReplace]);
end;

procedure TFormMain.EditUpperCase(A: TObject);
begin
  FEditors.ActiveEditor.ReplaceSelection(AnsiUpperCase(FEditors.ActiveEditor.SelText));
end;

procedure TFormMain.EditLowerCase(A: TObject);
begin
  FEditors.ActiveEditor.ReplaceSelection(AnsiLowerCase(FEditors.ActiveEditor.SelText));
end;

procedure TFormMain.EditFormatSource(A: TObject);
var
  LDst, LSrc: TStringStream;
begin
  if ShowMessageYesNo('Do you want to format the source code?') then begin
    LSrc := TStringStream.Create(FEditors.ActiveEditor.Text);
    try
      LDst := TStringStream.Create(EmptyStr);
      try
        ProcessPipe(LDst, LSrc, ProgramDirectory + 'astyle.exe', EmptyStr, ['-A8', '-xC100', '-k1', '-w',
          (*'-U',*) '-H', '-j', '-s' + IntToStr(4)], []);
        FEditors.ActiveEditor.Text := LDst.DataString;
      finally
        FreeAndNil(LDst);
      end;
    finally
      FreeAndNil(LSrc);
    end;
  end;
end;

procedure TFormMain.EditPopupMenuShow(A: TObject);
begin
  FEditorPopupMenu.FindElementByName('undo').Enabled := Self.FEditors.ActiveEditor.CanUndo;
end;

procedure TFormMain.RunSyntaxCheck(A: TObject);
begin
  Execute(ProgramDirectory + 'cmoc.exe', ['--help'], False);
end;

procedure TFormMain.RunCompile(A: TObject);
begin

end;

procedure TFormMain.RunBuild(A: TObject);
begin

end;

procedure TFormMain.RunBuildAndRun(A: TObject);
begin

end;

procedure TFormMain.ToolsOpenConsole(A: TObject);
begin
  LogMessage('Opening WinCMOC Console');
  Execute(ProgramDirectory + 'console.bat', [], True);
end;

procedure TFormMain.OpenMESSImage(const A: TFileName);
begin
  LogFileName('Opening MESS Image Tool', A);
  Execute(ProgramDirectory + 'wimgtool.exe', [A], True);
end;

procedure TFormMain.ToolsMessImageTool(A: TObject);
begin
  OpenMESSImage(EmptyStr);
end;

procedure TFormMain.ToolsOpenDisk0(A: TObject);
begin
  OpenMESSImage(ProgramDirectory + '..\dsk\disk0.dsk');
end;

procedure TFormMain.ToolsOpenDisk1(A: TObject);
begin
  OpenMESSImage(ProgramDirectory + '..\dsk\disk1.dsk');
end;

procedure TFormMain.ToolsOpenDisk2(A: TObject);
begin
  OpenMESSImage(ProgramDirectory + '..\dsk\disk2.dsk');
end;

procedure TFormMain.CreateStatusBar;
begin
  with StatusBar.AddPanel do begin
    Width := 70;
  end;
  with StatusBar.AddPanel do begin
    Width := 70;
  end;
  with StatusBar.AddPanel do begin
    Caption := 'INS';
    Width := 50;
  end;
  with StatusBar.AddPanel do begin
    Caption := 'FileName';
    Align := alClient;
  end;
end;

procedure TFormMain.CreateMainMenu;
begin
  with MainMenu do begin
    with AddMenuItem('&File') do begin
      AddMenuItem('&New', @FileNew, FIcons.New).ShortCut := scCtrl + VK_N;
      AddMenuItem('New Window', @FileNewWindow, FIcons.NewWindow);
      AddMenuItem(cLineCaption);
      AddMenuItem('&Open ...', @FileOpen, FIcons.Open).ShortCut := scCtrl + VK_O;
      AddMenuItem('Open New Window ...', @FileOpenInNewWindow, FIcons.FolderGo);
      AddMenuItem(cLineCaption);
      AddMenuItem('&Save', @FileSave, FIcons.Save).ShortCut := scCtrl + VK_S;
      AddMenuItem('Save &As ...', @FileSaveAs, FIcons.FileSaveAs);
      AddMenuItem('&Close Page ...', @FileClose, FIcons.FileSaveAs);
      AddMenuItem(cLineCaption);
      AddMenuItem('&Print ...', @FilePrint, FIcons.FileSaveAs);
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
end;

procedure TFormMain.CreateToolBar;
begin
  ToolBar.Height := 44;
  ToolBar.AddToolBarButton('New', @FileNew, FIcons.New);
  ToolBar.AddToolBarButton('Open', @FileOpen, FIcons.Open);
  ToolBar.AddToolBarButton('Save', @FileSaveAs, FIcons.Save);
  FButtonUndo := ToolBar.AddToolBarButton('Undo', @EditUndo, FIcons.Undo);
  FButtonRedo := ToolBar.AddToolBarButton('Redo', @EditRedo, FIcons.Redo);
  FButtonCut := ToolBar.AddToolBarButton('Cut', @EditCut, FIcons.Cut);
  FButtonCopy := ToolBar.AddToolBarButton('Copy', @EditCopy, FIcons.Copy);
  FButtonPaste := ToolBar.AddToolBarButton('Paste', @EditPaste, FIcons.Paste);
  FButtonDelete := ToolBar.AddToolBarButton('Delete', @EditDelete, FIcons.Cross);
  ToolBar.AddToolBarButton('Syntax Check', @RunSyntaxCheck, FIcons.TickButton);
  ToolBar.AddToolBarButton('Compile', @RunCompile, FIcons.Compile);
  ToolBar.AddToolBarButton('Build', @RunBuild, FIcons.Bricks);
  ToolBar.AddToolBarButton('Build and Run', @RunBuildAndRun, FIcons.BrickGo);
end;

procedure TFormMain.CreateSpliter;
begin
  FSplitter := TPairSplitter.Create(Self);
  FSplitter.Sides[0].BorderStyle := bsNone;
  FSplitter.Sides[0].BorderWidth := 4;
  FSplitter.Sides[1].BorderStyle := bsNone;
  FSplitter.ResizeWeight := 1;
  FSplitter.SplitterType := pstVertical;
  FSplitter.Align := alClient;
  FSplitter.Parent := Self;
end;

procedure TFormMain.CreateLog;
var
  LPageControl: TPageControl;
begin
  LPageControl := TPageControl.Create(Self);
  LPageControl.Align := alClient;
  LPageControl.Focusable := False;
  LPageControl.TabPosition := tpBottom;
  LPageControl.Parent := FSplitter.Sides[1];

  FListBox := TListBox.Create(Self);
  FListBox.BorderStyle := bsNone;
  FListBox.Align := alClient;
  FListBox.Items.OnInsert := @ListBoxInsert;
  FListBox.Color := clInfoBk;
  FListBox.Font.Name := 'Courier New';
  FListBox.Font.Height := 12;
  FListBox.Font.Color := clGreen;
  FListBox.ItemHeight := 14;
  FListBox.Parent := LPageControl.AddTabSheet('Messages');
end;

end.
