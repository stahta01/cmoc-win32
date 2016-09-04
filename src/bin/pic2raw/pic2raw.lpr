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

program pic2raw;

{$mode objfpc}{$H+}

uses
  FPImage,
  GraphType,
  Interfaces,
  IntfGraphics,
  SysUtils,
  UCmocImage,
  UCmocMain,
  UCmocParams;

{$R *.res}

  procedure Main(const A: TCmocParams);
  var
    LWidth, LHeight: integer;
    LSrc, LDst: TLazIntfImage;
    LPalette: TFPPalette;
  begin
    LWidth := 0;
    LHeight := 0;
    LPalette := OImage.Palette4(A.GetOptInteger('css', 0, 1));
    LDst := TLazIntfImage.Create(0, 0, [riqfRGB]);
    try
      LSrc := TLazIntfImage.Create(0, 0, [riqfRGB]);
      try
        LSrc.LoadFromFile(A.GetFileNameInput);
        if A.HasOption(A.OptWidth) then begin
          LWidth := A.GetOptInteger(A.OptWidth, 8, 256);
        end;
        if A.HasOption(A.OptHeight) then begin
          LHeight := A.GetOptInteger(A.OptHeight, 8, 256);
        end;
        if (LWidth = 0) and (LHeight > 0) then begin
          LWidth := LSrc.Width * LHeight div LSrc.Height;
        end else if (LHeight = 0) and (LWidth > 0) then begin
          LHeight := LSrc.Height * LWidth div LSrc.Width;
        end else if (LWidth = 0) and (LHeight = 0) then begin
          LWidth := LSrc.Width;
          LHeight := LSrc.Height;
        end;
        LDst.SetSize(LWidth, LHeight);
        OImage.ResampleAndDither(LDst, LSrc, LPalette);
        LDst.SaveToFile('crap.bmp');
        OImage.SaveToRawFile(LDst, A.GetFileNameOutput, LPalette);
      finally
        FreeAndNil(LSrc);
      end;
    finally
      FreeAndNil(LDst);
      FreeAndNil(LPalette);
    end;
  end;

begin
  CmocMain(@Main);
end.
