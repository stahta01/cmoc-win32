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

unit UCmocSynEditFindDialog;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, Dialogs, Forms, SynEdit, SysUtils, UCmocSynEdit;

procedure SynEditFind(const ASynEdit: TSynEdit);
procedure SynEditFindNext(const ASynEdit: TSynEdit);
procedure SynEditReplace(const ASynEdit: TSynEdit);

implementation

type

  CSynEditFindDialog = class(TFindDialog)
  strict private
    FSynEdit: TSynEdit;
  protected
    procedure Find; override;
  public
    constructor Create(AOwner: TComponent); override;
  public
    function Execute(const ASynEdit: TSynEdit): boolean; reintroduce;
    procedure FindNext(const ASynEdit: TSynEdit);
  end;

  CSynEditReplaceDialog = class(TReplaceDialog)
  strict private
    FSynEdit: TSynEdit;
  protected
    procedure Find; override;
    procedure Replace; override;
  public
    constructor Create(AOwner: TComponent); override;
  public
    function Execute(const ASynEdit: TSynEdit): boolean; reintroduce;
  end;

constructor CSynEditFindDialog.Create(AOwner: TComponent);
begin
  inherited;
  Options := Options + [frEntireScope];
end;

function CSynEditFindDialog.Execute(const ASynEdit: TSynEdit): boolean;
begin
  Assert(Assigned(ASynEdit));
  FSynEdit := ASynEdit;
  Result := inherited Execute;
end;

procedure CSynEditFindDialog.FindNext(const ASynEdit: TSynEdit);
begin
  Assert(Assigned(ASynEdit));
  FSynEdit := ASynEdit;
  Find;
end;

procedure CSynEditFindDialog.Find;
begin
  if Length(FindText) = 0 then begin
    Execute(FSynEdit);
  end else begin
    CloseDialog;
    FSynEdit._Find(Self);
  end;
end;

constructor CSynEditReplaceDialog.Create(AOwner: TComponent);
begin
  inherited;
  Options := Options + [frEntireScope];
end;

function CSynEditReplaceDialog.Execute(const ASynEdit: TSynEdit): boolean;
begin
  Assert(Assigned(ASynEdit));
  FSynEdit := ASynEdit;
  Result := inherited Execute;
end;

procedure CSynEditReplaceDialog.Find;
begin
  if Length(FindText) = 0 then begin
    Execute(FSynEdit);
  end else begin
    FSynEdit._Find(Self);
  end;
end;

procedure CSynEditReplaceDialog.Replace;
var
  LCount: integer;
begin
  if Length(FindText) = 0 then begin
    Execute(FSynEdit);
  end else begin
    LCount := FSynEdit._Replace(Self);
    if (frReplaceAll in Options) and (LCount <> 0) then begin
      CloseDialog;
    end;
  end;
end;

var
  GFindDialog: CSynEditFindDialog;
  GReplaceDialog: CSynEditReplaceDialog;

procedure SynEditFind(const ASynEdit: TSynEdit);
begin
  if not Assigned(GFindDialog) then begin
    GFindDialog := CSynEditFindDialog.Create(Application);
  end;
  GFindDialog.Execute(ASynEdit);
end;

procedure SynEditFindNext(const ASynEdit: TSynEdit);
begin
  if not Assigned(GFindDialog) then begin
    GFindDialog := CSynEditFindDialog.Create(Application);
  end;
  GFindDialog.FindNext(ASynEdit);
end;

procedure SynEditReplace(const ASynEdit: TSynEdit);
begin
  if not Assigned(GReplaceDialog) then begin
    GReplaceDialog := CSynEditReplaceDialog.Create(Application.MainForm);
  end;
  GReplaceDialog.Execute(ASynEdit);
end;

end.
