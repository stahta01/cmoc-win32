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
