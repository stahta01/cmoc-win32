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

var
  LIndex: integer;
  LBitmap: TBitmap;
begin
  try
    try
      FileCopyPictureToCpp('charset_6x8.c', 'charset_6x8.bmp');
      FileCopyPictureToCpp('image256x192.c', 'image256x192.png');
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
      BitmapSaveToCpp(LBitmap, LBitmap.Canvas.Font.Name + '.c');

      LBitmap.Canvas.Font.Name := 'C64 Pro';
      LBitmap.Canvas.FillRect(0, 0, LBitmap.Width, LBitmap.Height);
      for LIndex := 0 to 255 do begin
        LBitmap.Canvas.TextOut(1, LIndex * 8, CocoChar(char(LIndex)));
      end;
      BitmapSaveToCpp(LBitmap, LBitmap.Canvas.Font.Name + '.c');
    except
      on E: Exception do WriteLn(E.Message);
    end;
  finally
    ReadLn;
  end;

end.
