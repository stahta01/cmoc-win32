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

unit UCmocAsmParser;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, StrUtils, SysUtils;

type

  OAsmItem = object
  public
    Deleted: boolean;
    Sym, Cmd, Par: string;
  public
    function IsSym(const A: string): boolean;
    function IsCmd(const A: string): boolean;
    function AsString: string;
  end;

  OAsmItems = object
  public
    Items: array of OAsmItem;
  public
    function Count: integer;
  public
    procedure Insert(const APos: integer; const ASym, ACmd, APar: string);
    procedure Add(const ASym, ACmd, APar: string);
  public
    procedure AddSource(const A: string);
    procedure AddSourceLines(const A: TStrings);
  public
    procedure SaveToStrings(const A: TStrings);
    procedure SaveToFile(const A: TFileName);
  end;

function SymbolIsPublic(const A: string): boolean;

implementation

function SymbolIsPublic(const A: string): boolean;
begin
  Result := Length(A) >= 2;
  if Result then begin
    Result := (A[1] = '_') and (A[2] in ['a'..'z', 'A'..'Z', '_']) and not
      AnsiStartsStr('__static_', A);
  end;
end;

function OAsmItem.IsSym(const A: string): boolean;
begin
  Result := AnsiSameStr(A, Sym);
end;

function OAsmItem.IsCmd(const A: string): boolean;
begin
  Result := AnsiSameText(A, Cmd);
end;

function OAsmItem.AsString: string;
begin
  if Length(Sym) = 0 then begin
    Result := EmptyStr;
  end else begin
    Result := Sym;
  end;
  if Length(Cmd) > 0 then begin
    Result += #9 + Cmd;
    if Length(Par) > 0 then begin
      Result += #9 + Par;
    end;
  end;
end;

function OAsmItems.Count: integer;
begin
  Result := Length(Items);
end;

procedure OAsmItems.Insert(const APos: integer; const ASym, ACmd, APar: string);
var
  LIndex: integer;
begin
  SetLength(Items, Length(Items) + 1);
  for LIndex := High(Items) - 1 downto APos do begin
    Items[LIndex + 1] := Items[LIndex];
  end;
  with Items[APos] do begin
    Deleted := False;
    Sym := ASym;
    Cmd := ACmd;
    Par := APar;
  end;
end;

procedure OAsmItems.Add(const ASym, ACmd, APar: string);
begin
  SetLength(Items, Length(Items) + 1);
  with Items[High(Items)] do begin
    Deleted := False;
    Sym := ASym;
    Cmd := ACmd;
    Par := APar;
  end;
end;

procedure OAsmItems.AddSource(const A: string);
var
  LItem: OAsmItem;
  LBeg, LEnd, LTok: pchar;

  procedure LNextToken;
  begin
    while LEnd^ in [#1..#32] do begin
      Inc(LEnd);
    end;
    LTok := LEnd;
    if LTok^ in ['"'] then begin
      repeat
        Inc(LEnd);
      until LEnd^ in [#0, LTok^];
      if LEnd^ <> #0 then begin
        Inc(LEnd);
      end;
    end else begin
      while not (LEnd^ in [#0..#32]) do begin
        Inc(LEnd);
      end;
    end;
  end;

  function LTokenEmpty: boolean;
  begin
    Result := (LTok^ in [#0, '#', ';']) or
      ((LTok[0] = '/') and (LTok[1] = '/')) or
      ((LTok[0] = '*') and not (LTok[1] in [#0..#32]));
  end;

begin
  LItem := default(OAsmItem);
  LBeg := PChar(A);
  LEnd := LBeg;
  LNextToken;
  if not LTokenEmpty then begin
    if (LTok = LBeg) or (LEnd[-1] = ':') then begin
      if LEnd[-1] = ':' then begin
        SetString(LItem.Sym, LTok, LEnd - LTok - 1);
      end else begin
        SetString(LItem.Sym, LTok, LEnd - LTok);
      end;
      LNextToken;
    end;
    if LTok^ in ['a'..'z', 'A'..'Z', '.'] then begin
      SetString(LItem.Cmd, LTok, LEnd - LTok);
      LNextToken;
      if (LTok^ = '#') or not LTokenEmpty then begin
        SetString(LItem.Par, LTok, LEnd - LTok);
      end;
    end;
    SetLength(Items, Length(Items) + 1);
    Items[High(Items)] := LItem;
  end;
end;

procedure OAsmItems.AddSourceLines(const A: TStrings);
var
  LIndex: integer;
begin
  for LIndex := 0 to A.Count - 1 do begin
    AddSource(A[LIndex]);
  end;
end;

procedure OAsmItems.SaveToStrings(const A: TStrings);
var
  LIndex: integer;
begin
  A.Clear;
  for LIndex := Low(Items) to High(Items) do begin
    if not Items[LIndex].Deleted then begin
      A.Add(Items[LIndex].AsString);
    end;
  end;
end;

procedure OAsmItems.SaveToFile(const A: TFileName);
var
  LStrings: TStrings;
begin
  LStrings := TStringList.Create;
  try
    SaveToStrings(LStrings);
    LStrings.SaveToFile(A);
  finally
    FreeAndNil(LStrings);
  end;
end;

end.
