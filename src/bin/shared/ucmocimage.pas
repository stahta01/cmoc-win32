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
    class procedure Resample(const ADst, ASrc: TFPCustomImage);
    class procedure Dither(const ADst, ASrc: TFPCustomImage; const APalette: TFPPalette);
    class procedure Dither2(const ADst, ASrc: TFPCustomImage);
  public
    class procedure ResampleAndDither(const ADst, ASrc: TFPCustomImage);
    class function GetTwoColorByte(const A: TFPCustomImage; var AX: integer;
      const AY: integer): byte;
    class procedure SaveToRawFile(const A: TFPCustomImage; const AStream: TStream);
    class procedure SaveToRawFile(const A: TFPCustomImage; const AFileName: TFileName);
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
  LPalette := TFPPalette.Create(0);
  try
    LPalette.Add(FPColor(0, 0, 0));
    LPalette.Add(FPColor($FFFF, $FFFF, $FFFF));
    Dither(ADst, ASrc, LPalette);
  finally
    FreeAndNil(LPalette);
  end;
end;

class procedure OImage.ResampleAndDither(const ADst, ASrc: TFPCustomImage);
var
  LTmp: TFPCustomImage;
begin
  LTmp := TLazIntfImage.Create(0, 0, [riqfRGB]);
  try
    LTmp.SetSize(ADst.Width, ADst.Height);
    OImage.Resample(LTmp, ASrc);
    OImage.Dither2(ADst, LTmp);
  finally
    FreeAndNil(LTmp);
  end;
end;

class function OImage.GetTwoColorByte(const A: TFPCustomImage; var AX: integer;
  const AY: integer): byte;
var
  LIndex: integer;
begin
  Result := 0;
  for LIndex := 1 to 8 do begin
    if (AX >= A.Width) or (A.Pixels[AX, AY] = 0) then begin
      Result := (Result shl 1) or 0;
    end else begin
      Result := (Result shl 1) or 1;
    end;
    Inc(AX);
  end;
end;

class procedure OImage.SaveToRawFile(const A: TFPCustomImage; const AStream: TStream);
var
  LX, LY: integer;
begin
  AStream.WriteWord(A.Width);
  AStream.WriteWord(A.Height);
  for LY := 0 to A.Height - 1 do begin
    LX := 0;
    while LX < A.Width do begin
      AStream.WriteByte(GetTwoColorByte(A, LX, LY));
    end;
  end;
end;

class procedure OImage.SaveToRawFile(const A: TFPCustomImage; const AFileName: TFileName);
var
  LStream: TStream;
begin
  LStream := TFileStream.Create(AFileName, fmCreate);
  try
    SaveToRawFile(A, LStream);
  finally
    FreeAndNil(LStream);
  end;
end;

end.
