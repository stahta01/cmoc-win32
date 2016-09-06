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
  try
    SynAnySyn.KeyWords.LoadFromFile(ProgramDirectory + 'cmocide/keywords.txt');
  except
  end;
  try
    SynAnySyn.Constants.LoadFromFile(ProgramDirectory + 'cmocide/constants.txt');
  except
  end;
  try
    SynAnySyn.Objects.LoadFromFile(ProgramDirectory + 'cmocide/objects.txt');
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
