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

unit UBeckyServer;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, FPImage, Graphics, IntfGraphics, Math, SSockets, SysUtils,
  UBeckySession, UBeckyStream, UCmocRbs;

var
  BeckyTitle: string = 'BECKY SERVER V0.1';

const

  BECKY_MAGIC = 0;
  BECKY_TITLE = 1;
  BECKY_ERROR = 2;

  BECKY_HTTP = 10;
  BECKY_READ = 11;
  BECKY_WRITE = 12;
  BECKY_REWIND = 13;
  BECKY_REWRITE = 14;
  BECKY_LOAD = 15;
  BECKY_SAVE = 16;

  BECKY_IMAGE_WIDTH = 20;
  BECKY_IMAGE_HEIGHT = 21;
  BECKY_IMAGE_LOAD = 22;
  BECKY_IMAGE_RESAMPLE = 23;
  BECKY_IMAGE_SAVE_BMP = 24;
  BECKY_IMAGE_SAVE_RAW = 25;

type

  CBeckyServer = class(TINetServer)
  protected
    procedure DoConnect(ASocket: TSocketStream); override;
  end;

implementation

procedure CBeckyServer.DoConnect(ASocket: TSocketStream);

var
  LSession: CBeckySession;
  LType, LSize: word;
  LError: string;
  LData: rawbytestring;

  procedure LSetResponse(const A: rawbytestring);
  begin
    LSession.SetResponse(A);
    ASocket.SendDWord(LSession.FStream.Size);
  end;

begin
  LError := EmptyStr;
  WriteLn('Connected');
  LSession := CBeckySession.Create(nil);
  try
    ASocket.Size := 0;
    while True do begin
      LType := ASocket.RecvWord;
      LData := ASocket.RecvData;
      //WriteLn('REQUEST');
      try
        case LType of
          BECKY_MAGIC: begin
            ASocket.SendDWord(1234);
          end;
          BECKY_TITLE: begin
            LSetResponse(BeckyTitle);
          end;
          BECKY_ERROR: begin
            LSetResponse(LError);
          end;
          BECKY_HTTP: begin
            LSession.Http(LData);
            ASocket.SendDWord(LSession.FStream.Size);
          end;
          BECKY_READ: begin
            LSize := Min(RbsWord(LData, 0), LSession.FStream.Size - LSession.FStream.Position);
            ASocket.SendDWord(LSize);
            ASocket.SendStream(LSession.FStream, LSize);
          end;
          BECKY_WRITE: begin
            LSession.FStream.WriteBuffer(LData[1], Length(LData));
            ASocket.SendDWord(LSession.FStream.Size);
          end;
          BECKY_REWIND: begin
            LSession.FStream.Position := 0;
            ASocket.SendDWord(LSession.FStream.Size);
          end;
          BECKY_REWRITE: begin
            LSession.FStream.Size := 0;
            ASocket.SendDWord(LSession.FStream.Size);
          end;
          BECKY_LOAD: begin
            LSession.FStream.LoadFromFile(LData);
            ASocket.SendDWord(LSession.FStream.Size);
          end;
          BECKY_SAVE: begin
            LSession.FStream.SaveToFile(LData);
            ASocket.SendDWord(LSession.FStream.Size);
          end;
          BECKY_IMAGE_WIDTH: begin
            ASocket.SendDWord(LSession.FImage.Width);
          end;
          BECKY_IMAGE_HEIGHT: begin
            ASocket.SendDWord(LSession.FImage.Height);
          end;
          BECKY_IMAGE_LOAD: begin
            LSession.ImageLoad;
            ASocket.SendWord(LSession.FImage.Width);
            ASocket.SendWord(LSession.FImage.Height);
          end;
          BECKY_IMAGE_SAVE_BMP: begin
            LSession.ImageSaveBmp;
            ASocket.SendDWord(LSession.FStream.Size);
          end;
          BECKY_IMAGE_SAVE_RAW: begin
            LSession.ImageSaveRaw;
            ASocket.SendDWord(LSession.FStream.Size);
          end;
          BECKY_IMAGE_RESAMPLE: begin
            LSession.ImageResample(RbsWord(LData, 0), RbsWord(LData, 2));
            ASocket.SendWord(LSession.FImage.Width);
            ASocket.SendWord(LSession.FImage.Height);
          end else begin
            raise Exception.Create('UNKNOWN TYPE');
          end;
        end;
      except
        on LException: Exception do begin
          LError := LException.Message;
          ASocket.SendDWord(DWord(-1));
        end;
      end;
    end;
  finally
    FreeAndNil(LSession);
  end;
end;

end.
