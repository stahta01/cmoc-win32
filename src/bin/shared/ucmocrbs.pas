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

unit UCmocRbs;

{$INCLUDE cmoc.inc}

interface

uses
  Classes;

function RbsLoadFromFile(const AFileName: string): rawbytestring;
procedure RbsSaveToFile(const A: rawbytestring; const AFileName: string);
function RbsByte(const A: byte): rawbytestring;
function RbsWord(const A: word): rawbytestring;
function RbsByte(const A: rawbytestring; const AIndex: integer): byte;
function RbsWord(const A: rawbytestring; const AIndex: integer): word;

function RbsDecbLength(const A: rawbytestring): word;
function RbsDecbBegin(const A: rawbytestring): word;

function RbsDecb(const A: rawbytestring; const AAddr: word): rawbytestring;
function RbsDecb(const A: rawbytestring; const AAddr, AExec: word): rawbytestring;

function RbsVideo(const A: rawbytestring): rawbytestring;

implementation

function RbsLoadFromFile(const AFileName: string): rawbytestring;
begin
  with TFileStream.Create(AFileName, fmOpenRead) do begin
    try
      SetLength(Result, Size);
      ReadBuffer(Result[1], Size);
    finally
      Free;
    end;
  end;
end;

procedure RbsSaveToFile(const A: rawbytestring; const AFileName: string);
begin
  with TFileStream.Create(AFileName, fmCreate) do begin
    try
      WriteBuffer(A[1], Length(A));
    finally
      Free;
    end;
  end;
end;

function RbsByte(const A: byte): rawbytestring;
begin
  Result := char(A);
end;

function RbsWord(const A: word): rawbytestring;
begin
  Result := RbsByte(A shr 8) + RbsByte(A);
end;

function RbsByte(const A: rawbytestring; const AIndex: integer): byte;
begin
  Result := pbyte(@A[AIndex + 1])^;
end;

function RbsWord(const A: rawbytestring; const AIndex: integer): word;
begin
  Result := swap(pword(@A[AIndex + 1])^);
end;

function RbsDecbLength(const A: rawbytestring): word;
begin
  Result := RbsWord(A, 1);
end;

function RbsDecbBegin(const A: rawbytestring): word;
begin
  Result := RbsWord(A, 3);
end;

function RbsDecb(const A: rawbytestring; const AAddr: word): rawbytestring;
begin
  Result := RbsByte(0) + RbsWord(Length(A)) + RbsWord(AAddr) + A;
end;

function RbsDecb(const A: rawbytestring; const AAddr, AExec: word): rawbytestring;
begin
  Result := RbsDecb(A, AAddr) + RbsByte(255) + RbsWord(0) + RbsWord(AExec);
end;

function RbsVideo(const A: rawbytestring): rawbytestring;
var
  LIndex: integer;
begin
  Result := A;
  for LIndex := 1 to Length(Result) do begin
    if Result[LIndex] in [#96..#127] then begin
      Result[LIndex] := char(byte(Result[LIndex]) - 96);
    end else if Result[LIndex] in [#32..#63] then begin
      Result[LIndex] := char(byte(Result[LIndex]) + 64);
    end;
  end;
end;


end.
