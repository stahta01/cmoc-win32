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
  Classes, FpHttpClient, FPImage, Graphics, IntfGraphics, SSockets, SysUtils,
  UBeckySession, UBeckyStream;

const

  BECKY_NULL = 0;
  BECKY_TITLE = 1;
  BECKY_REQUEST = 2;
  BECKY_RESPONSE = 3;
  BECKY_FLUSH_SOCKET = 4;
  BECKY_FLUSH_RESPONSE = 5;
  BECKY_FLUSH_REQUEST = 6;

  BECKY_IMAGE_WIDTH = 10;
  BECKY_IMAGE_HEIGHT = 11;
  BECKY_IMAGE_LOAD = 12;
  BECKY_IMAGE_RESAMPLE = 13;
  BECKY_IMAGE_SAVE_BMP = 14;
  BECKY_IMAGE_SAVE_RAW = 15;

type

  CBeckyServer = class(TINetServer)
  protected
    procedure HandleRequest(const AMessage: string; const AResponse: TMemoryStream);
    procedure DoConnect(ASocket: TSocketStream); override;
  end;

implementation

procedure CBeckyServer.HandleRequest(const AMessage: string; const AResponse: TMemoryStream);
var
  LPos: integer;
  LName, LValue: string;
begin
  LPos := Pos(#32, AMessage);
  if LPos > 0 then begin
    LName := Trim(Copy(AMessage, 1, LPos - 1));
    LValue := Trim(Copy(AMessage, LPos + 1, MaxInt));
    with TFPHTTPClient.Create(nil) do begin
      try
        WriteLn('Requesting ', AMessage);
        AResponse.Clear;
        try
          HTTPMethod(LName, LValue, AResponse, [200]);
        except
          on E: Exception do begin
            WriteLn(E.Message);
          end;
        end;
      finally
        Free;
      end;
    end;
  end;
  AResponse.Position := 0;
end;

procedure CBeckyServer.DoConnect(ASocket: TSocketStream);
var
  LSession: CBeckySession;
begin
  WriteLn('Connected');
  LSession := CBeckySession.Create;
  try
    ASocket.Size := 0;
    while True do begin
      case ASocket.RecvWord of
        BECKY_NULL: begin
        end;
        BECKY_TITLE: begin
          ASocket.SendString('Becky Server v0.1');
        end;
        BECKY_FLUSH_SOCKET: begin
          ASocket.Size := 0;
        end;
        BECKY_FLUSH_RESPONSE: begin
          LSession.FResponse.Size := 0;
        end;
        BECKY_FLUSH_REQUEST: begin
          LSession.FRequest.Size := 0;
        end;
        BECKY_REQUEST: begin
          HandleRequest(ASocket.RecvString, LSession.FResponse);
        end;
        BECKY_RESPONSE: begin
          ASocket.SendStream(LSession.FResponse);
        end;
        BECKY_IMAGE_WIDTH: begin
          ASocket.SendWord(LSession.FImage.Width);
        end;
        BECKY_IMAGE_HEIGHT: begin
          ASocket.SendWord(LSession.FImage.Height);
        end;
        BECKY_IMAGE_LOAD: begin
          LSession.PictureLoad;
        end;
        BECKY_IMAGE_SAVE_BMP: begin
          LSession.PictureSaveBmp;
        end;
        BECKY_IMAGE_SAVE_RAW: begin
          LSession.PictureSaveRaw;
        end;
        BECKY_IMAGE_RESAMPLE: begin
          LSession.PictureResample(ASocket.RecvWord, ASocket.RecvWord);
        end else begin
          ASocket.Size := 0;
        end;
      end;
    end;
  finally
    FreeAndNil(LSession);
  end;
end;

end.
