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
