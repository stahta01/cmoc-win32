program pic2raw;

{$mode objfpc}{$H+}

uses
  Classes,
  FPImage,
  GraphType,
  Interfaces,
  IntfGraphics,
  Math,
  SysUtils,
  UCmocImage,
  UCmocParams,
  UCmocUtils;

{$R *.res}

  procedure Main;
  var
    LWidth, LHeight: integer;
    LParams: TCmocParams;
    LSrc, LDst: TLazIntfImage;
    LPalette: TFPPalette;
  begin
    LWidth := 0;
    LHeight := 0;
    LPalette := nil;
    LParams := TCmocParams.Create;
    try
      LParams.Add('-o=crap.raw');
      LParams.Add('-w=256');
      LParams.Add('image.jpg');
      LDst := TLazIntfImage.Create(0, 0, [riqfRGB]);
      try
        LSrc := TLazIntfImage.Create(0, 0, [riqfRGB]);
        try
          LSrc.LoadFromFile(LParams.GetFileNameInput);
          if LParams.HasOption(LParams.OptWidth) then begin
            LWidth := LParams.GetOptInteger(LParams.OptWidth, 8, 256);
          end;
          if LParams.HasOption(LParams.OptHeight) then begin
            LHeight := LParams.GetOptInteger(LParams.OptHeight, 8, 256);
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
          LPalette := OImage.Palette4;
          OImage.ResampleAndDither(LDst, LSrc, LPalette);
          LDst.SaveToFile('crap.bmp');
          OImage.SaveToRawFile(LDst, LParams.GetFileNameOutput, LPalette);
        finally
          FreeAndNil(LSrc);
        end;
      finally
        FreeAndNil(LDst);
      end;
    finally
      FreeAndNil(LParams);
    end;
    FreeAndNil(LPalette);
  end;

begin
  try
    Main;
  except
    ReadLn;
  end;
end.
