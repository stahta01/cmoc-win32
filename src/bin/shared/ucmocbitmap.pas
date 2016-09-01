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

function BitmapGetPixelByte(const ABitmap: TBitmap; const AX, AY: integer): byte;
function BitmapToCppString(const ABitmap: TBitmap; const AName: string): string;
procedure BitmapSaveToCpp(const ABitmap: TBitmap; const AFileName: TFileName;
  const AVarName: string);
procedure FileCopyPictureToCpp(const ADst, ASrc: TFileName; const AVarName: string);

implementation

function BitmapGetPixelByte(const ABitmap: TBitmap; const AX, AY: integer): byte;
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

function BitmapToCppString(const ABitmap: TBitmap; const AName: string): string;
var
  LCol, LRow, LSize: integer;
begin
  Result := default(string);
  LSize := 0;
  for LRow := 0 to ABitmap.Height - 1 do begin
    for LCol := 0 to ((ABitmap.Width + 7) div 8) - 1 do begin
      if Length(Result) > 0 then begin
        Result += ',';
      end;
      if (LSize and 15) = 0 then begin
        Result += LineEnding + StringOfChar(#32, 4);
      end;
      Result += '0x' + IntToHex(BitmapGetPixelByte(ABitmap, LCol * 8, LRow), 2);
      Inc(LSize);
    end;
  end;
  Result := Format(#13'extern unsigned char %s[%d];'#13#13'unsigned char %s[%d] = {%s'#13'};',
    [AName, LSize, AName, LSize, Result]);
end;

procedure BitmapSaveToCpp(const ABitmap: TBitmap; const AFileName: TFileName;
  const AVarName: string);
begin
  with TStringList.Create do begin
    try
      Text := BitmapToCppString(ABitmap, AVarName);
      SaveToFile(AFileName);
    finally
      Free;
    end;
  end;
end;

procedure FileCopyPictureToCpp(const ADst, ASrc: TFileName; const AVarName: string);
var
  LPicture: TPicture;
begin
  LPicture := TPicture.Create;
  try
    LPicture.LoadFromFile(ASrc);
    BitmapSaveToCpp(LPicture.Bitmap, ADst, AVarName);
  finally
    FreeAndNil(LPicture);
  end;
end;

end.
