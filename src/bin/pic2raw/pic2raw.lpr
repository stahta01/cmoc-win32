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
