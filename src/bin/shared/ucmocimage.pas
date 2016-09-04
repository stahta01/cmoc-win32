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

unit UCmocImage;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, extinterpolation, FPDitherer, FPImage, FPImgCanv, GraphType, IntfGraphics, SysUtils;

type
  OImage = object
  public
    class function Palette2: TFPPalette;
    class function Palette4: TFPPalette;
  public
    class procedure Resample(const ADst, ASrc: TFPCustomImage);
    class procedure Dither(const ADst, ASrc: TFPCustomImage; const APalette: TFPPalette);
    class procedure Dither2(const ADst, ASrc: TFPCustomImage);
  public
    class procedure ResampleAndDither(const ADst, ASrc: TFPCustomImage;
      const APalette: TFPPalette);
    class procedure SaveToRawFile(const A: TFPCustomImage; const AStream: TStream;
      const APalette: TFPPalette);
    class procedure SaveToRawFile(const A: TFPCustomImage; const AFileName: TFileName;
      const APalette: TFPPalette);
  end;

implementation

type
  CImageResample = class(TBilineairInterpolation)
  public
    procedure Resample(const ADst, ASrc: TFPCustomImage);
  end;

procedure CImageResample.Resample(const ADst, ASrc: TFPCustomImage);
var
  LCanvas: TFPImageCanvas;
begin
  LCanvas := TFPImageCanvas.Create(ADst);
  try
    Initialize(ASrc, LCanvas);
    Execute(0, 0, ADst.Width, ADst.Height);
  finally
    FreeAndNil(LCanvas);
  end;
end;

class function OImage.Palette2: TFPPalette;
begin
  Result := TFPPalette.Create(0);
  Result.Add(FPColor(0, 0, 0));
  Result.Add(FPColor($FFFF, $FFFF, $FFFF));
end;

class function OImage.Palette4: TFPPalette;
begin
  Result := TFPPalette.Create(0);
  Result.Add(FPColor(0, 0, 0));
  Result.Add(FPColor($FFFF, $FFFF, $FFFF));
end;

class procedure OImage.Resample(const ADst, ASrc: TFPCustomImage);
var
  LResample: CImageResample;
begin
  LResample := CImageResample.Create;
  try
    LResample.Resample(ADst, ASrc);
  finally
    FreeAndNil(LResample);
  end;
end;

class procedure OImage.Dither(const ADst, ASrc: TFPCustomImage; const APalette: TFPPalette);
var
  LDitherer: TFPFloydSteinbergDitherer;
begin
  LDitherer := TFPFloydSteinbergDitherer.Create(APalette);
  try
    LDitherer.Dither(ASrc, ADst);
  finally
    FreeAndNil(LDitherer);
  end;
end;

class procedure OImage.Dither2(const ADst, ASrc: TFPCustomImage);
var
  LPalette: TFPPalette;
begin
  LPalette := Palette2;
  try
    Dither(ADst, ASrc, LPalette);
  finally
    FreeAndNil(LPalette);
  end;
end;

class procedure OImage.ResampleAndDither(const ADst, ASrc: TFPCustomImage;
  const APalette: TFPPalette);
var
  LTmp: TFPCustomImage;
begin
  LTmp := TLazIntfImage.Create(0, 0, [riqfRGB]);
  try
    LTmp.SetSize(ADst.Width, ADst.Height);
    OImage.Resample(LTmp, ASrc);
    OImage.Dither(ADst, LTmp, APalette);
  finally
    FreeAndNil(LTmp);
  end;
end;

type
  TBytePixelDitherer = class(TFPBaseDitherer)
  public
    function GetColorByte(const A: TFPCustomImage; var AX: integer; const AY: integer): integer;
  end;

function TBytePixelDitherer.GetColorByte(const A: TFPCustomImage; var AX: integer;
  const AY: integer): integer;
var
  LPixIndex, LPalIndex, LBitsPerPixel: integer;
begin
  Result := 0;
  if Palette.Count = 4 then begin
    LBitsPerPixel := 2;
  end else begin
    LBitsPerPixel := 1;
  end;
  for LPixIndex := 1 to (8 div LBitsPerPixel) do begin
    LPalIndex := 0;
    if AX < A.Width then begin
      FindBestColor(A.Colors[AX, AY], LPalIndex);
    end;
    Result := (Result shl LBitsPerPixel) or LPalIndex;
    Inc(AX);
  end;
end;

class procedure OImage.SaveToRawFile(const A: TFPCustomImage; const AStream: TStream;
  const APalette: TFPPalette);
var
  LX, LY: integer;
  LDitherer: TBytePixelDitherer;
begin
  LDitherer := TBytePixelDitherer.Create(APalette);
  try
    AStream.WriteByte(APalette.Count);
    AStream.WriteWord(A.Width);
    AStream.WriteWord(A.Height);
    for LY := 0 to A.Height - 1 do begin
      LX := 0;
      while LX < A.Width do begin
        AStream.WriteByte(LDitherer.GetColorByte(A, LX, LY));
      end;
    end;
  finally
    FreeAndNil(LDitherer);
  end;
end;

class procedure OImage.SaveToRawFile(const A: TFPCustomImage; const AFileName: TFileName;
  const APalette: TFPPalette);
var
  LStream: TStream;
begin
  LStream := TFileStream.Create(AFileName, fmCreate);
  try
    SaveToRawFile(A, LStream, APalette);
  finally
    FreeAndNil(LStream);
  end;
end;

end.
