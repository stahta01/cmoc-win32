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

unit UnitCmocIDESynEdit;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, Controls, Dialogs, FileUtil, Forms, Graphics, Menus, MouseAndKeyInput,
  StrUtils, SynEdit, SynEditTypes, SynHighlighterAny, SysUtils, UCmocSynEditFindDialog;

type

  { TFormCmocIDESynEdit }

  TFormCmocIDESynEdit = class(TForm)
    ImageList16: TImageList;
    MenuCut: TMenuItem;
    MenuDelete: TMenuItem;
    MenuItem1: TMenuItem;
    MenuItem12: TMenuItem;
    MenuFind: TMenuItem;
    MenuFindNext: TMenuItem;
    MenuCopy: TMenuItem;
    MenuItem2: TMenuItem;
    MenuReplace: TMenuItem;
    MenuItem5: TMenuItem;
    MenuPaste: TMenuItem;
    MenuRedo: TMenuItem;
    MenuSelectAll: TMenuItem;
    MenuUndo: TMenuItem;
    SynAnySyn: TSynAnySyn;
    SynEdit: TSynEdit;
    SynEditMenu: TPopupMenu;
    procedure FormCreate(ASender: TObject);
    procedure MenuCopyClick(ASender: TObject);
    procedure MenuCutClick(ASender: TObject);
    procedure MenuDeleteClick(ASender: TObject);
    procedure MenuFindClick(ASender: TObject);
    procedure MenuFindNextClick(ASender: TObject);
    procedure MenuPasteClick(ASender: TObject);
    procedure MenuRedoClick(ASender: TObject);
    procedure MenuReplaceClick(ASender: TObject);
    procedure MenuSelectAllClick(ASender: TObject);
    procedure MenuUndoClick(ASender: TObject);
    procedure SynEditStatusChange(ASender: TObject; AChanges: TSynStatusChanges);
  strict private
    FFileName: TFileName;
    procedure SetFileName(const AFileName: TFileName);
    procedure LoadKeyWordFile(const AStrings: TStrings; const AFileName: TFileName);
  public
    function GetDisplayName: string;
    function Modified: boolean;
    procedure Clear;
    procedure LoadFromFile(const AFileName: TFileName);
    procedure SaveToFile(const AFileName: TFileName);
  public
    property FileName: TFileName read FFileName write SetFileName;
  end;

var
  FormCmocIDESynEdit: TFormCmocIDESynEdit;

implementation

{$R *.lfm}

uses UnitCmocIDE;

procedure TFormCmocIDESynEdit.FormCreate(ASender: TObject);
begin
  with SynEdit do begin
    TabWidth := 4;
    Font.Quality := fqCleartype;
    Font.Name := 'Courier New';
    Font.Size := 10;
    BracketMatchColor.Background := clAqua;
    BracketMatchColor.Style := [];
    LineHighlightColor.Background := $E6FFFA;
    OnStatusChange := @SynEditStatusChange;
  end;
  LoadKeyWordFile(SynAnySyn.KeyWords, 'keywords.txt');
  LoadKeyWordFile(SynAnySyn.Constants, 'constants.txt');
  LoadKeyWordFile(SynAnySyn.Objects, 'objects.txt');
end;

procedure TFormCmocIDESynEdit.LoadKeyWordFile(const AStrings: TStrings;
  const AFileName: TFileName);
begin
  try
    AStrings.LoadFromFile(ProgramDirectory + 'cmocide/' + AFileName);
  except
  end;
end;

procedure TFormCmocIDESynEdit.MenuCopyClick(ASender: TObject);
begin
  SynEdit.CopyToClipboard;
end;

procedure TFormCmocIDESynEdit.SetFileName(const AFileName: TFileName);
begin
  FFileName := AFileName;
  FormCmocIDE.Caption := Application.Title + ' - [' + GetDisplayName + ']';
  SynEdit.Modified := False;
  SynEditStatusChange(SynEdit, scTextCleared + [scInsertMode]);
  case LowerCase(ExtractFileExt(AFileName)) of
    '.asm', '.as', '.a': begin
      SynEdit.Options := SynEdit.Options - [eoShowSpecialChars, eoTabsToSpaces];
      SynEdit.Options2 := SynEdit.Options2 + [eoCaretSkipTab];
      SynEdit.TabWidth := 8;
    end else begin
      SynEdit.Options := SynEdit.Options + [eoShowSpecialChars, eoTabsToSpaces];
      SynEdit.Options2 := SynEdit.Options2 - [eoCaretSkipTab];
      SynEdit.TabWidth := 4;
    end;
  end;
end;

function TFormCmocIDESynEdit.GetDisplayName: string;
begin
  Result := FFileName;
  if Length(Result) = 0 then begin
    Result := 'untitled';
  end;
  if Modified then begin
    Insert('*', Result, 1);
  end;
end;

function TFormCmocIDESynEdit.Modified: boolean;
begin
  Result := SynEdit.Modified or ((Length(FFileName) > 0) and not FileExists(FFileName));
end;

procedure TFormCmocIDESynEdit.Clear;
begin
  FormCmocIDESynEdit.SynEdit.Clear;
  SetFileName(default(string));
end;

procedure TFormCmocIDESynEdit.LoadFromFile(const AFileName: TFileName);
begin
  SynEdit.Lines.LoadFromFile(AFileName);
  SetFileName(AFileName);
end;

procedure TFormCmocIDESynEdit.SaveToFile(const AFileName: TFileName);
begin
  SynEdit.Lines.SaveToFile(AFileName);
  SetFileName(AFileName);
end;

procedure TFormCmocIDESynEdit.SynEditStatusChange(ASender: TObject; AChanges: TSynStatusChanges);
var
  LSelAvail: boolean;
begin
  if (AChanges * [scCaretX, scCaretY]) <> [] then begin
    FormCmocIDE.StatusBar.Panels[0].Text := Format('%4d:%4d', [SynEdit.CaretY, SynEdit.CaretX]);
  end;
  if scModified in AChanges then begin
    FormCmocIDE.StatusBar.Panels[1].Text := IfThen(Modified, 'Modified', EmptyStr);
    FormCmocIDE.Caption := Application.Title + ' - [' + GetDisplayName + ']';
    FormCmocIDE.StatusBar.Panels[3].Text := GetDisplayName;
  end;
  if scInsertMode in AChanges then begin
    FormCmocIDE.StatusBar.Panels[2].Text := IfThen(SynEdit.InsertMode, 'INS', 'OVR');
  end;

  LSelAvail := SynEdit.SelAvail;

  MenuCopy.Enabled := LSelAvail;
  MenuCut.Enabled := LSelAvail;
  MenuDelete.Enabled := LSelAvail;
  MenuPaste.Enabled := SynEdit.CanPaste;
  MenuRedo.Enabled := SynEdit.CanRedo;
  MenuUndo.Enabled := SynEdit.CanUndo;

  FormCmocIDE.ButtonCopy.Enabled := LSelAvail;
  FormCmocIDE.ButtonCut.Enabled := LSelAvail;
  FormCmocIDE.ButtonDelete.Enabled := LSelAvail;
  FormCmocIDE.ButtonPaste.Enabled := SynEdit.CanPaste;
  FormCmocIDE.ButtonRedo.Enabled := SynEdit.CanRedo;
  FormCmocIDE.ButtonUndo.Enabled := SynEdit.CanUndo;
end;

procedure TFormCmocIDESynEdit.MenuFindClick(ASender: TObject);
begin
  SynEditFind(SynEdit);
end;

procedure TFormCmocIDESynEdit.MenuFindNextClick(ASender: TObject);
begin
  SynEditFindNext(SynEdit);
end;

procedure TFormCmocIDESynEdit.MenuReplaceClick(ASender: TObject);
begin
  SynEditReplace(SynEdit);
end;

procedure TFormCmocIDESynEdit.MenuPasteClick(ASender: TObject);
begin
  SynEdit.PasteFromClipboard;
end;

procedure TFormCmocIDESynEdit.MenuUndoClick(ASender: TObject);
begin
  SynEdit.Undo;
end;

procedure TFormCmocIDESynEdit.MenuRedoClick(ASender: TObject);
begin
  SynEdit.Redo;
end;

procedure TFormCmocIDESynEdit.MenuCutClick(ASender: TObject);
begin
  SynEdit.CutToClipboard;
end;

procedure TFormCmocIDESynEdit.MenuDeleteClick(ASender: TObject);
begin
  SynEdit.ClearSelection;
end;

procedure TFormCmocIDESynEdit.MenuSelectAllClick(ASender: TObject);
begin
  SynEdit.SelectAll;
end;

end.
