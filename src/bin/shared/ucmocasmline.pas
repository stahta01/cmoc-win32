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

unit UCmocAsmLine;

{$INCLUDE cmoc.inc}

interface

uses
  StrUtils, SysUtils;

type

  OAsmLine = object
  public
    Symbol, Instruction, Parameters: string;
  public
    procedure SetLine(const ASymbol, AInstruction, AParameters: string);
    function SetLine(const ASrcLine: string): boolean;
  public
    function SameSymbol(const A: string): boolean;
    function SameInstruction(const A: string): boolean;
    function SameParameters(const A: string): boolean;
  public
    function AsString: string;
  public
    IsDeleted, Is6502: boolean;
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

procedure OAsmLine.SetLine(const ASymbol, AInstruction, AParameters: string);
begin
  IsDeleted := False;
  Symbol := Trim(ASymbol);
  Instruction := UpperCase(Trim(AInstruction));
  Parameters := Trim(AParameters);
  if Length(Parameters) > 0 then begin
    // Compatiblity with the BBC assembler
    if Parameters[1] = '=' then begin
      Parameters[1] := '#';
    end;
  end;
end;

function OAsmLine.SetLine(const ASrcLine: string): boolean;
var
  LBeg, LTok, LPos: pchar;

  procedure LNextToken;
  begin
    while LPos^ in [#1..#32] do begin
      Inc(LPos);
    end;
    LTok := LPos;
    // Todo: what about /bla bla/ style strings?
    if LTok^ in ['"'] then begin
      repeat
        Inc(LPos);
      until LPos^ in [#0, LTok^];
      if LPos^ <> #0 then begin
        Inc(LPos);
      end;
    end else begin
      while not (LPos^ in [#0..#32]) do begin
        Inc(LPos);
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
  LBeg := PChar(ASrcLine);
  LPos := LBeg;
  LNextToken;
  if not ((LTok^ in ['*', '#']) or LIsComment) then begin
    if (LTok = LBeg) or (LPos[-1] = ':') then begin
      Result := True;
      if LPos[-1] = ':' then begin
        SetString(Symbol, LTok, LPos - LTok - 1);
      end else begin
        SetString(Symbol, LTok, LPos - LTok);
      end;
      LNextToken;
    end;
    if LTok^ in ['a'..'z', 'A'..'Z', '.'] then begin
      Result := True;
      SetString(Instruction, LTok, LPos - LTok);
      LNextToken;
      if not LIsComment then begin
        SetString(Parameters, LTok, LPos - LTok);
      end;
    end;
  end;
end;

function OAsmLine.SameSymbol(const A: string): boolean;
begin
  Result := A = Symbol;
end;

function OAsmLine.SameInstruction(const A: string): boolean;
begin
  Result := SameText(A, Instruction);
end;

function OAsmLine.SameParameters(const A: string): boolean;
begin
  Result := SameText(A, Parameters);
end;

function OAsmLine.AsString: string;
begin
  if Length(Symbol) = 0 then begin
    Result := EmptyStr;
  end else begin
    Result := Symbol;
  end;
  if Length(Instruction) > 0 then begin
    Result += #9 + Instruction;
    if Length(Parameters) > 0 then begin
      Result += #9 + Parameters;
    end;
  end;
end;

end.

