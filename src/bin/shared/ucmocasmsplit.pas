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

unit UCmocAsmSplit;

{$INCLUDE cmoc.inc}

interface

uses
  SysUtils;

function AsmSplit(const ALine: string; var ASym, ACmd, APar: string): boolean;

implementation

const
  CharSetEOL = ['#', '*', ';', #0];

function AsmSplit(const ALine: string; var ASym, ACmd, APar: string): boolean;
var
  LBeg, LEnd, LTok: pchar;

  procedure LNextToken;
  begin
    while LEnd^ in [#1..#32] do begin
      Inc(LEnd);
    end;
    LTok := LEnd;
    if LTok^ in ['''', '"'] then begin
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

begin
  ASym := EmptyStr;
  ACmd := EmptyStr;
  APar := EmptyStr;
  LBeg := PChar(ALine);
  LEnd := LBeg;
  LNextToken;
  Result := not (LTok^ in CharSetEOL);
  if Result then begin
    if (LTok = LBeg) or (LEnd[-1] = ':') then begin
      SetString(ASym, LTok, LEnd - LTok);
      LNextToken;
    end;
    if not (LTok^ in CharSetEOL) then begin
      SetString(ACmd, LTok, LEnd - LTok);
      LNextToken;
      if not (LTok^ in CharSetEOL) then begin
        SetString(APar, LTok, LEnd - LTok);
      end;
    end;
  end;
end;

end.
