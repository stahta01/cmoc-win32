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

// INCOMPLETE TOOL

program project;

{$mode objfpc}{$H+}

uses
  Classes,
  Graphics,
  Interfaces,
  Math,
  SysUtils,
  UCmocBitmap;

{$R *.res}

  function CocoChar(const AIndex: char): char;
  begin
    Result := AIndex;
    Inc(Result, 32);
  end;

var
  LIndex: integer;
  LBitmap: TBitmap;
begin
  try
    try
      FileCopyPictureToCpp('../../lib/libcharset/charset_6x8.c', 'charset_6x8.bmp', 'charset_6x8');
      //FileCopyPictureToCpp('../../../examples/image256x192.c', 'image256x192.png');
      //Exit;

      LBitmap := TBitmap.Create;
      LBitmap.SetSize(8, 256 * 8);
      LBitmap.Canvas.Font.Height := 8;
      LBitmap.Canvas.Brush.Color := clBlack;
      LBitmap.Canvas.Font.Color := clWhite;
      LBitmap.Canvas.Font.Quality := fqNonAntialiased;


      LBitmap.Canvas.Font.Name := 'Atari';
      for LIndex := 0 to 127 do begin
        LBitmap.Canvas.TextOut(0, LIndex * 8, CocoChar(char(LIndex)));
      end;
      for LIndex := 0 to 127 do begin
        LBitmap.Canvas.TextOut(4, (LIndex + 128) * 8, CocoChar(char(LIndex)));
      end;
      BitmapSaveToCpp(LBitmap, '../../lib/libcharset/charset_atari_small.c',
        'charset_atari_small');

      LBitmap.SetSize(8, 128 * 8);
      LBitmap.Canvas.Font.Name := 'C64 Pro';
      LBitmap.Canvas.FillRect(0, 0, LBitmap.Width, LBitmap.Height);
      for LIndex := 0 to 127 do begin
        LBitmap.Canvas.TextOut(1, LIndex * 8, CocoChar(char(LIndex)));
      end;
      BitmapSaveToCpp(LBitmap, '../../lib/libcharset/charset_c64.c', 'charset_c64');
    except
      on E: Exception do WriteLn(E.Message);
    end;
  finally
    ReadLn;
  end;

end.
