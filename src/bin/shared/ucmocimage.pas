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
  Classes, extinterpolation, FPDitherer, FPImage, FPImgCanv, GraphType,
  IntfGraphics, SysUtils, UCmocRbs, UCmocUtils;

type
  OImage = object
  public
    class function CreatePalette(const APalCode: integer): TFPPalette;
  public
    class procedure Resample(const ADst, ASrc: TLazIntfImage);
    class procedure Dither(const ADst, ASrc: TLazIntfImage; const APalette: TFPPalette);
  public
    class procedure ResampleAndDither(const ADst, ASrc: TLazIntfImage;
      const APalette: TFPPalette);
    class function SaveToCoCoPic(const A: TLazIntfImage; const APalCode: byte;
      const APalette: TFPPalette): rawbytestring;
    class procedure SaveToCoCoPic(const A: TLazIntfImage; const AFileName: TFileName;
      const APalCode: byte; const APalette: TFPPalette);
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

function MakeColor(const R, G, B: byte): TFPColor;
begin
  Result.red := R * 257;
  Result.green := G * 257;
  Result.blue := B * 257;
  Result.alpha := 0;
end;

class function OImage.CreatePalette(const APalCode: integer): TFPPalette;
begin
  Result := TFPPalette.Create(0);
  case APalCode of
    0: begin
      Result.Add(MakeColor(0, 0, 0)); // Black
      Result.Add(MakeColor(0, 255, 0)); // Green
    end;
    1: begin
      Result.Add(MakeColor(0, 0, 0)); // Black
      Result.Add(MakeColor(255, 255, 255)); // Buff
    end;
    2: begin
      Result.Add(MakeColor(0, 255, 0)); // Green
      Result.Add(MakeColor(255, 255, 66)); // Yellow
      Result.Add(MakeColor(33, 16, 189)); //Blue
      Result.Add(MakeColor(189, 0, 33)); // Red
    end;
    3: begin
      Result.Add(MakeColor(255, 255, 255)); // Buff
      Result.Add(MakeColor(0, 222, 115)); // Cyan
      Result.Add(MakeColor(255, 16, 255)); //Magenta
      Result.Add(MakeColor(255, 66, 0)); // Orange
    end;
    4: begin
      Result.Add(MakeColor(0, 0, 0)); // Black
      Result.Add(MakeColor(255, 0, 0)); // Red
      Result.Add(MakeColor(0, 0, 255)); // Blue
      Result.Add(MakeColor(255, 255, 255)); // Buff
    end;
    5: begin
      Result.Add(MakeColor(0, 0, 0)); // Black
      Result.Add(MakeColor(0, 0, 255)); // Blue
      Result.Add(MakeColor(255, 0, 0)); // Red
      Result.Add(MakeColor(255, 255, 255)); // Buff
    end else begin
      OCmoc.RaiseError('Invalid palette code');
    end;
  end;
end;

class procedure OImage.Resample(const ADst, ASrc: TLazIntfImage);
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

class procedure OImage.Dither(const ADst, ASrc: TLazIntfImage; const APalette: TFPPalette);
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

class procedure OImage.ResampleAndDither(const ADst, ASrc: TLazIntfImage;
  const APalette: TFPPalette);
var
  LTmp: TLazIntfImage;
begin
  if (ADst.Width = ASrc.Width) and (ADst.Height = ASrc.Height) then begin
    ADst.CopyPixels(ASrc);
  end else begin
    LTmp := TLazIntfImage.Create(0, 0, [riqfRGB]);
    try
      LTmp.SetSize(ADst.Width, ADst.Height);
      OImage.Resample(LTmp, ASrc);
      OImage.Dither(ADst, LTmp, APalette);
    finally
      FreeAndNil(LTmp);
    end;
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

class function OImage.SaveToCoCoPic(const A: TLazIntfImage; const APalCode: byte;
  const APalette: TFPPalette): rawbytestring;
var
  LX, LY: integer;
  LDitherer: TBytePixelDitherer;
begin
  Result := default(rawbytestring);
  LDitherer := TBytePixelDitherer.Create(APalette);
  try
    for LY := 0 to A.Height - 1 do begin
      LX := 0;
      while LX < A.Width do begin
        Result += RbsByte(LDitherer.GetColorByte(A, LX, LY));
      end;
    end;
  finally
    FreeAndNil(LDitherer);
  end;
  Result := RbsByte(APalCode) + RbsWord(A.Width) + RbsWord(A.Height) + RbsCompressBlock(Result, 1);
end;

class procedure OImage.SaveToCoCoPic(const A: TLazIntfImage; const AFileName: TFileName;
  const APalCode: byte; const APalette: TFPPalette);
var
  LStream: TStream;
  LData: string;
begin
  LStream := TFileStream.Create(AFileName, fmCreate);
  try
    LData := SaveToCoCoPic(A, APalCode, APalette);
    LStream.WriteBuffer(LData[1], Length(LData));
  finally
    FreeAndNil(LStream);
  end;
end;

end.
