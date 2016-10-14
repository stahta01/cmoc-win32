(*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

Derek John Evans <https://sourceforge.net/u/buzzphp/profile/>
*)

unit UBeckySession;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, FPImage, Graphics, GraphType, IntfGraphics, SysUtils, UCmocImage;

type

  CBeckySession = class
  public
    FResponse, FRequest: TMemoryStream;
    FImage: TLazIntfImage;
    FPalette: TFPPalette;
  public
    constructor Create;
    destructor Destroy; override;
  public
    procedure ImageLoad;
    procedure ImageSaveBmp;
    procedure ImageSaveRaw;
    procedure ImageResample(const AWidth, AHeight: integer);
  end;

implementation

constructor CBeckySession.Create;
begin
  inherited;
  FResponse := TMemoryStream.Create;
  FRequest := TMemoryStream.Create;
  FImage := TLazIntfImage.Create(0, 0, [riqfRGB]);
  FPalette := OImage.CreatePalette(1);
end;

destructor CBeckySession.Destroy;
begin
  FreeAndNil(FPalette);
  FreeAndNil(FImage);
  FreeAndNil(FRequest);
  FreeAndNil(FResponse);
  inherited;
end;

procedure CBeckySession.ImageLoad;
begin
  FResponse.Position := 0;
  FImage.LoadFromStream(FResponse);
end;

procedure CBeckySession.ImageSaveBmp;
begin
  FResponse.Clear;
  try
    //FImage.SaveToStream(FResponse);     // TODO, Maybe
  except
  end;
  FResponse.Position := 0;
end;

procedure CBeckySession.ImageSaveRaw;
var
  LDst: rawbytestring;
begin
  LDst := OImage.SaveToRawPic(FImage, FPalette);
  FResponse.Clear;
  FResponse.WriteBuffer(LDst[1], Length(LDst));
  FResponse.Position := 0;
end;

procedure CBeckySession.ImageResample(const AWidth, AHeight: integer);
var
  LDst, LTmp: TLazIntfImage;
begin
  LDst := TLazIntfImage.Create(0, 0, [riqfRGB]);
  try
    LDst.SetSize(AWidth, AHeight); // Bug in FreePascal. We must set size here.
    OImage.ResampleAndDither(LDst, FImage, FPalette);
    LTmp := FImage;
    FImage := LDst;
    LDst := LTmp;
  finally
    FreeAndNil(LDst);
  end;
end;

end.

