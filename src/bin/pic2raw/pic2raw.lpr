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
  UCmocParams,
  UCmocRbs;

{$R *.res}

  procedure Main(const A: TCmocParams);
  var
    LWidth, LHeight, LPalCode: integer;
    LPalette: TFPPalette;
    LSrcImage, LDstImage: TLazIntfImage;
  begin
    LWidth := 0;
    LHeight := 0;
    LPalCode := A.GetOptInteger('pal', 0, 5);
    LPalette := OImage.CreatePalette(LPalCode);
    try
      LDstImage := TLazIntfImage.Create(0, 0, [riqfRGB]);
      try
        LSrcImage := TLazIntfImage.Create(0, 0, [riqfRGB]);
        try
          LSrcImage.LoadFromFile(A.GetFileNameInput);
          if A.HasOption(A.OptWidth) then begin
            LWidth := A.GetOptInteger(A.OptWidth, 8, 256);
          end;
          if A.HasOption(A.OptHeight) then begin
            LHeight := A.GetOptInteger(A.OptHeight, 8, 256);
          end;
          if (LWidth = 0) and (LHeight > 0) then begin
            LWidth := LSrcImage.Width * LHeight div LSrcImage.Height;
          end else if (LHeight = 0) and (LWidth > 0) then begin
            LHeight := LSrcImage.Height * LWidth div LSrcImage.Width;
          end else if (LWidth = 0) and (LHeight = 0) then begin
            LWidth := LSrcImage.Width;
            LHeight := LSrcImage.Height;
          end;
          LDstImage.SetSize(LWidth, LHeight);
          OImage.ResampleAndDither(LDstImage, LSrcImage, LPalette);
          OImage.SaveToCoCoPic(LDstImage, A.GetFileNameOutput, LPalCode, LPalette);
        finally
          FreeAndNil(LSrcImage);
        end;
      finally
        FreeAndNil(LDstImage);
      end;
    finally
      FreeAndNil(LPalette);
    end;
  end;

begin
  CmocMain(@Main);
end.
