program pic2raw;

{$mode objfpc}{$H+}

uses
  Classes,
  FPImage,
  GraphType,
  Interfaces,
  IntfGraphics,
  SysUtils,
  UCmocImage;

{$R *.res}

  function EnforeRange(const A, ALow, AHigh: integer): integer;
  begin
    Result := A;
    if (Result < ALow) or (Result > AHigh) then begin
      raise Exception.Create('Number out of range');
    end;
  end;

  procedure Main;
  var
    LWidth, LHeight: integer;
    LParams: TStrings;
    LSrc, LDst: TLazIntfImage;
  begin
    LWidth := 0;
    LHeight := 0;
    LParams := TStringList.Create;
    try
      LParams.CommaText := CmdLine;
      LParams.Add('-o=crap.raw');
      LParams.Add('image.jpg');
      if LParams.Count < 2 then begin
        raise Exception.Create('missing parameters');
      end;
      LDst := TLazIntfImage.Create(0, 0, [riqfRGB]);
      try
        LSrc := TLazIntfImage.Create(0, 0, [riqfRGB]);
        try
          LSrc.LoadFromFile(LParams[LParams.Count - 1]);
          if LParams.IndexOfName('-w') >= 0 then begin
            LWidth := EnforeRange(StrToInt(LParams.Values['-w']), 8, 256);
          end;
          if LParams.IndexOfName('-h') >= 0 then begin
            LHeight := EnforeRange(StrToInt(LParams.Values['-h']), 8, 256);
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
          OImage.ResampleAndDither(LDst, LSrc);
          OImage.SaveToRawFile(LDst, LParams.Values['-o']);
        finally
          FreeAndNil(LSrc);
        end;
      finally
        FreeAndNil(LDst);
      end;
    finally
      FreeAndNil(LParams);
    end;
  end;

begin
  try
    Main;
  except
    on LException: Exception do WriteLn(LException.Message);
  end;
  ReadLn;
end.
