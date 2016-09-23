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
