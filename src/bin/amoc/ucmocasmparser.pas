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

  OAsmLine = object
  public
    Sym, Ins, Par: string;
  public
    procedure SetLine(const ASym, AIns, APar: string);
  public
    function IsSym(const A: string): boolean;
    function IsIns(const A: string): boolean;
    function AsString: string;
  public
    Deleted: boolean;
  end;

  OAsmLines = object
  public
    Line: array of OAsmLine;
  public
    function Count: integer;
  public
    procedure Insert(const APos: integer; const ASym, AIns, APar: string);
    procedure Add(const ASym, AIns, APar: string);
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

procedure OAsmLine.SetLine(const ASym, AIns, APar: string);
begin
  Deleted := False;
  Sym := ASym;
  Ins := UpperCase(AIns);
  Par := APar;
end;

function OAsmLine.IsSym(const A: string): boolean;
begin
  Result := AnsiSameStr(A, Sym);
end;

function OAsmLine.IsIns(const A: string): boolean;
begin
  Result := AnsiSameText(A, Ins);
end;

function OAsmLine.AsString: string;
begin
  if Length(Sym) = 0 then begin
    Result := EmptyStr;
  end else begin
    Result := Sym;
  end;
  if Length(Ins) > 0 then begin
    Result += #9 + Ins;
    if Length(Par) > 0 then begin
      Result += #9 + Par;
    end;
  end;
end;

function OAsmLines.Count: integer;
begin
  Result := Length(Line);
end;

procedure OAsmLines.Insert(const APos: integer; const ASym, AIns, APar: string);
var
  LIndex: integer;
begin
  SetLength(Line, Length(Line) + 1);
  for LIndex := High(Line) - 1 downto APos do begin
    Line[LIndex + 1] := Line[LIndex];
  end;
  Line[APos].SetLine(ASym, AIns, APar);
end;

procedure OAsmLines.Add(const ASym, AIns, APar: string);
begin
  SetLength(Line, Length(Line) + 1);
  Line[High(Line)].SetLine(ASym, AIns, APar);
end;

procedure OAsmLines.AddSource(const A: string);
var
  LLine: OAsmLine;
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

  function LIsComment: boolean;
  begin
    Result := (LTok^ in [#0, ';']) or
      ((LTok[0] = '/') and (LTok[1] = '/')) or
      ((LTok[0] = '#') and (LTok[1] in [#0..#32])) or
      ((LTok[0] = '*') and not (LTok[1] in [#0..#32]));
  end;

begin
  LLine := default(OAsmLine);
  LBeg := PChar(A);
  LEnd := LBeg;
  LNextToken;
  if not ((LTok^ in ['*', '#']) or LIsComment) then begin
    if (LTok = LBeg) or (LEnd[-1] = ':') then begin
      if LEnd[-1] = ':' then begin
        SetString(LLine.Sym, LTok, LEnd - LTok - 1);
      end else begin
        SetString(LLine.Sym, LTok, LEnd - LTok);
      end;
      LNextToken;
    end;
    if LTok^ in ['a'..'z', 'A'..'Z', '.'] then begin
      SetString(LLine.Ins, LTok, LEnd - LTok);
      LNextToken;
      if not LIsComment then begin
        SetString(LLine.Par, LTok, LEnd - LTok);
      end;
    end;
    SetLength(Line, Length(Line) + 1);
    Line[High(Line)].SetLine(LLine.Sym, LLine.Ins, LLine.Par);
  end;
end;

procedure OAsmLines.AddSourceLines(const A: TStrings);
var
  LIndex: integer;
begin
  for LIndex := 0 to A.Count - 1 do begin
    AddSource(A[LIndex]);
  end;
end;

procedure OAsmLines.SaveToStrings(const A: TStrings);
var
  LIndex: integer;
begin
  A.Clear;
  for LIndex := Low(Line) to High(Line) do begin
    if not Line[LIndex].Deleted then begin
      A.Add(Line[LIndex].AsString);
    end;
  end;
end;

procedure OAsmLines.SaveToFile(const A: TFileName);
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
