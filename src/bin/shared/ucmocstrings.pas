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

unit UCmocStrings;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, SysUtils;

type
  TStringsHelper = class helper for TStrings
  public
    function _GetString(const AName, ADefault: string): string;
    procedure _InsertStrings(const AIndex: integer; const AStrings: array of string);
  end;

implementation

function TStringsHelper._GetString(const AName, ADefault: string): string;
var
  LIndex: integer;
begin
  LIndex := IndexOfName(AName);
  if LIndex < 0 then begin
    Result := ADefault;
  end else begin
    Result := ValueFromIndex[LIndex];
  end;
end;

procedure TStringsHelper._InsertStrings(const AIndex: integer; const AStrings: array of string);
var
  LIndex: integer;
begin
  for LIndex := 0 to High(AStrings) do begin
    Insert(AIndex + LIndex, AStrings[LIndex]);
  end;
end;

end.
