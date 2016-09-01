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

unit UCmocBitmap;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, Graphics, SysUtils;

function BitmapPixelByte(const ABitmap: TBitmap; const AX, AY: integer): byte;

implementation

function BitmapPixelByte(const ABitmap: TBitmap; const AX, AY: integer): byte;
var
  LBit: integer;
begin
  Result := 0;
  for LBit := AX to AX + 7 do begin
    if ABitmap.Canvas.Pixels[LBit, AY] = clBlack then begin
      Result := (Result shl 1) or 0;
    end else begin
      Result := (Result shl 1) or 1;
    end;
  end;
end;

end.

