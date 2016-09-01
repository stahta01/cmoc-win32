program project;

{$mode objfpc}{$H+}

uses
  Classes,
  Graphics,
  Interfaces,
  Math,
  SysUtils,
  UCmocBitmap;

{$R *.res}

  function CocoChar(const AIndex: char): char;
  begin
    Result := AIndex;
    Inc(Result, 32);
  end;

  function BitmapEncodeSource(const ABitmap: TBitmap; const AName: string): string;
  var
    LY: integer;
  begin
    Result := '#include <charset.h>' + LineEnding + 'unsigned char ' + AName +
      '[CHARSET_SIZE] = {';
    for LY := 0 to ABitmap.Height - 1 do begin
      if LY > 0 then begin
        Result += ',';
      end;
      if (LY and 15) = 0 then begin
        Result += LineEnding;
      end;
      Result += '0x' + IntToHex(BitmapPixelByte(ABitmap, 0, LY), 2);
    end;
    Result += LineEnding + '};' + LineEnding;
  end;

  procedure BitmapEncodeAndSave(const ABitmap: TBitmap; const AFileName: TFileName);
  begin
    with TStringList.Create do begin
      try
        Text := BitmapEncodeSource(ABitmap, ChangeFileExt(ExtractFileName(AFileName), EmptyStr));
        SaveToFile(AFileName);
      finally
        Free;
      end;
    end;
    //ABitmap.SaveToFile(ABitmap.Canvas.Font.Name + '.bmp');
  end;

  procedure BitmapEncodeAndSave(const ADst, ASrc: TFileName);
  var
    LBitmap: TBitmap;
  begin
    LBitmap := TBitmap.Create;
    try
      LBitmap.LoadFromFile(ASrc);
      BitmapEncodeAndSave(LBitmap, ADst);
    finally
      FreeAndNil(LBitmap);
    end;
  end;

var
  LIndex: integer;
  LBitmap: TBitmap;
begin
  try
    try
      BitmapEncodeAndSave('charset_6x8.c', 'charset_6x8.bmp');
      Exit;

      LBitmap := TBitmap.Create;
      LBitmap.SetSize(8, 256 * 8);
      LBitmap.Canvas.Font.Height := 8;
      LBitmap.Canvas.Brush.Color := clBlack;
      LBitmap.Canvas.Font.Color := clWhite;
      LBitmap.Canvas.Font.Quality := fqNonAntialiased;


      LBitmap.Canvas.Font.Name := 'Atari';
      for LIndex := 0 to 127 do begin
        LBitmap.Canvas.TextOut(0, LIndex * 8, CocoChar(char(LIndex)));
      end;
      for LIndex := 0 to 127 do begin
        LBitmap.Canvas.TextOut(4, (LIndex + 128) * 8, CocoChar(char(LIndex)));
      end;
      BitmapEncodeAndSave(LBitmap, LBitmap.Canvas.Font.Name + '.c');

      LBitmap.Canvas.Font.Name := 'C64 Pro';
      LBitmap.Canvas.FillRect(0, 0, LBitmap.Width, LBitmap.Height);
      for LIndex := 0 to 255 do begin
        LBitmap.Canvas.TextOut(1, LIndex * 8, CocoChar(char(LIndex)));
      end;
      BitmapEncodeAndSave(LBitmap, LBitmap.Canvas.Font.Name + '.c');
    except
      on E: Exception do WriteLn(E.Message);
    end;
  finally
    ReadLn;
  end;

end.
