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

unit UCmocAsmSource;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, StrUtils, SysUtils, UCmocAsmLine;

type

  OAsmSource = object
  public
    Lines: array of OAsmLine;
  public
    function Count: integer;
  public
    procedure Insert(const APos: integer; const ASym, AIns, APar: string);
    procedure Add(const ASym, AIns, APar: string);
  public
    function AsmParse(const ASrc: string; var ADst: OAsmLine): boolean;
    function AsmAdd(const A: string): boolean;
    function AsmInsert(const APos: integer; const A: string): boolean;
  public
    procedure AsmAddStrings(const A: TStrings);
  public
    procedure SaveToStrings(const A: TStrings);
    procedure SaveToFile(const A: TFileName);
  end;

implementation

function OAsmSource.Count: integer;
begin
  Result := Length(Lines);
end;

procedure OAsmSource.Insert(const APos: integer; const ASym, AIns, APar: string);
var
  LIndex: integer;
begin
  SetLength(Lines, Length(Lines) + 1);
  for LIndex := High(Lines) - 1 downto APos do begin
    Lines[LIndex + 1] := Lines[LIndex];
  end;
  Lines[APos].SetLine(ASym, AIns, APar);
end;

procedure OAsmSource.Add(const ASym, AIns, APar: string);
begin
  SetLength(Lines, Length(Lines) + 1);
  Lines[High(Lines)].SetLine(ASym, AIns, APar);
end;

function OAsmSource.AsmParse(const ASrc: string; var ADst: OAsmLine): boolean;
var
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
  Result := False;
  ADst := default(OAsmLine);
  LBeg := PChar(ASrc);
  LEnd := LBeg;
  LNextToken;
  if not ((LTok^ in ['*', '#']) or LIsComment) then begin
    if (LTok = LBeg) or (LEnd[-1] = ':') then begin
      Result := True;
      if LEnd[-1] = ':' then begin
        SetString(ADst.Symbol, LTok, LEnd - LTok - 1);
      end else begin
        SetString(ADst.Symbol, LTok, LEnd - LTok);
      end;
      LNextToken;
    end;
    if LTok^ in ['a'..'z', 'A'..'Z', '.'] then begin
      Result := True;
      SetString(ADst.Instruction, LTok, LEnd - LTok);
      LNextToken;
      if not LIsComment then begin
        SetString(ADst.Parameters, LTok, LEnd - LTok);
      end;
    end;
  end;
end;

function OAsmSource.AsmAdd(const A: string): boolean;
var
  LLine: OAsmLine;
begin
  Result := AsmParse(A, LLine);
  if Result then begin
    Add(LLine.Symbol, LLine.Instruction, LLine.Parameters);
  end;
end;

function OAsmSource.AsmInsert(const APos: integer; const A: string): boolean;
var
  LLine: OAsmLine;
begin
  Result := AsmParse(A, LLine);
  if Result then begin
    Insert(APos, LLine.Symbol, LLine.Instruction, LLine.Parameters);
  end;
end;

procedure OAsmSource.AsmAddStrings(const A: TStrings);
var
  LIndex: integer;
begin
  for LIndex := 0 to A.Count - 1 do begin
    AsmAdd(A[LIndex]);
  end;
end;

procedure OAsmSource.SaveToStrings(const A: TStrings);
var
  LIndex: integer;
begin
  A.Clear;
  for LIndex := Low(Lines) to High(Lines) do begin
    if not Lines[LIndex].IsDeleted then begin
      A.Add(Lines[LIndex].AsString);
    end;
  end;
end;

procedure OAsmSource.SaveToFile(const A: TFileName);
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
