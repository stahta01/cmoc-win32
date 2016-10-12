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

const

  TCharSetRegA = ['a', 'A'];
  TCharSetRegB = ['b', 'B'];
  TCharSetRegD = ['d', 'D'];
  TCharSetRegX = ['x', 'X'];
  TCharSetRegY = ['y', 'Y'];
  TCharSetRegS = ['s', 'S'];
  TCharSetRegU = ['u', 'U'];

type

  OAsmLine = object
  public
    Symb, Inst, Args, Comm: string;
  public
    procedure SetLine(const ASymb, AInst, AArgs: string);
    function SetLine(const ASrcLine: string): boolean;
  public
    function Same(const AInst, AArgs: string): boolean; inline;
    function SameSymb(const A: string): boolean; inline;
    function SameInst(const A: string): boolean; inline;
    function SameArgs(const A: string): boolean; inline;
  public
    function HasSymb: boolean; inline;
    function HasInst: boolean; inline;
    function HasArgs: boolean; inline;
    function HasComm: boolean; inline;
    function HasRegs(const A: TSysCharSet): boolean;
  public
    function AsString: string;
  public
    Removed, Is6502: boolean;
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

function TokenIsComment(const A: pchar): boolean; inline;
begin
  Result := (A[0] in [#0, ';']) or
    ((A[0] = '/') and (A[1] = '/')) or
    ((A[0] = '#') and (A[1] in [#0..#32])) or
    ((A[0] = '*') and not (A[1] in [#0..#32]));
end;

procedure OAsmLine.SetLine(const ASymb, AInst, AArgs: string);
begin
  Removed := False;
  Symb := Trim(ASymb);
  Inst := LowerCase(Trim(AInst));
  Args := Trim(AArgs);
  if Length(Args) > 0 then begin
    // Compatiblity with the BBC assembler
    if Args[1] = '=' then begin
      Args[1] := '#';
    end;
  end;
end;

function OAsmLine.HasSymb: boolean;
begin
  Result := Length(Symb) > 0;
end;

function OAsmLine.HasInst: boolean;
begin
  Result := Length(Inst) > 0;
end;

function OAsmLine.HasArgs: boolean;
begin
  Result := Length(Args) > 0;
end;

function OAsmLine.HasComm: boolean;
begin
  Result := Length(Comm) > 0;
end;

function OAsmLine.SameSymb(const A: string): boolean;
begin
  Result := A = Symb;
end;

function OAsmLine.SameInst(const A: string): boolean;
begin
  Result := SameText(A, Inst);
end;

function OAsmLine.SameArgs(const A: string): boolean;
begin
  Result := SameText(A, Args);
end;

function OAsmLine.Same(const AInst, AArgs: string): boolean;
begin
  Result := SameText(AInst, Inst) and SameText(AArgs, Args);
end;

function OAsmLine.AsString: string;
begin
  if Removed then begin
    Result := '# REMOVED ';
  end else begin
    Result := EmptyStr;
  end;
  if HasSymb then begin
    Result += Symb;
  end;
  if HasInst then begin
    Result += #9 + Inst;
    if HasArgs then begin
      Result += #9 + Args;
    end;
  end;
  if HasComm then begin
    Result += #9 + '; ' + Comm;
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

begin
  Result := False;
  LBeg := PChar(ASrcLine);
  LPos := LBeg;
  LNextToken;
  if not ((LTok^ in ['*', '#']) or TokenIsComment(LTok)) then begin
    if (LTok = LBeg) or (LPos[-1] = ':') then begin
      Result := True;
      if LPos[-1] = ':' then begin
        SetString(Symb, LTok, LPos - LTok - 1);
      end else begin
        SetString(Symb, LTok, LPos - LTok);
      end;
      LNextToken;
    end;
    if LTok^ in ['a'..'z', 'A'..'Z', '.'] then begin
      Result := True;
      SetString(Inst, LTok, LPos - LTok);
      LNextToken;
      if not TokenIsComment(LTok) then begin
        SetString(Args, LTok, LPos - LTok);
      end;
    end;
  end;
end;

function RPosSet(const ASet: TSysCharSet; const A: string): integer;
begin
  for Result := Length(A) downto 1 do begin
    if A[Result] in ASet then begin
      Exit;
    end;
  end;
  Result := 0;
end;

function OAsmLine.HasRegs(const A: TSysCharSet): boolean;
var
  LPos, LLen: integer;
begin
  LLen := Length(Args);
  LPos := RPosSet(A, Args);
  Result :=
    ((LLen = 1) and (LPos = 1)) or
    ((LLen > 1) and (LPos > 1) and (Args[LPos - 1] = ',')) or
    ((LLen > 1) and (LPos = 1) and (Args[LPos + 1] = ',')) or
    ((LLen > 2) and (LPos < LLen) and (Args[LPos - 1] = ',') and (Args[LPos + 1] = ','));
end;

end.
