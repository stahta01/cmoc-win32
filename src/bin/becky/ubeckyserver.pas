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
  Classes, FpHttpClient, FPImage, Graphics, IntfGraphics, Math, SSockets, SysUtils,
  UBeckySession, UBeckyStream, UCmocRbs;

var
  BeckyTitle: string = 'BECKY SERVER V0.1';

const

  BECKY_MAGIC = 0;
  BECKY_TITLE = 1;
  BECKY_HTTP = 2;
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
  strict private
    procedure HandleRequest(const AMessage: string; const AResponse: TMemoryStream);
  protected
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
  LType, LSize: word;
  LData: rawbytestring;

  procedure LSetResponse(const A: rawbytestring);
  begin
    LSession.SetResponse(A);
    ASocket.SendDWord(LSession.FResponse.Size);
  end;

begin
  WriteLn('Connected');
  LSession := CBeckySession.Create;
  try
    ASocket.Size := 0;
    while True do begin
      LType := ASocket.RecvWord;
      LData := ASocket.RecvData;
      //WriteLn('REQUEST');
      case LType of
        BECKY_MAGIC: begin
          ASocket.SendDWord(1234);
        end;
        BECKY_TITLE: begin
          LSetResponse(BeckyTitle);
        end;
        BECKY_FLUSH_SOCKET: begin
          ASocket.Size := 0;
          ASocket.SendDWord(0);
        end;
        BECKY_FLUSH_RESPONSE: begin
          LSession.FResponse.Size := 0;
          ASocket.SendDWord(LSession.FResponse.Size);
        end;
        BECKY_FLUSH_REQUEST: begin
          LSession.FRequest.Size := 0;
          ASocket.SendDWord(LSession.FResponse.Size);
        end;
        BECKY_HTTP: begin
          HandleRequest(LData, LSession.FResponse);
          ASocket.SendDWord(LSession.FResponse.Size);
        end;
        BECKY_RESPONSE: begin
          LSize := Min(RbsWord(LData, 0), LSession.FResponse.Size - LSession.FResponse.Position);
          ASocket.SendDWord(LSize);
          ASocket.SendStream(LSession.FResponse, LSize);
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
          ASocket.SendDWord(LSession.FResponse.Size);
        end;
        BECKY_IMAGE_SAVE_RAW: begin
          LSession.ImageSaveRaw;
          ASocket.SendDWord(LSession.FResponse.Size);
        end;
        BECKY_IMAGE_RESAMPLE: begin
          LSession.ImageResample(RbsWord(LData, 0), RbsWord(LData, 2));
          ASocket.SendWord(LSession.FImage.Width);
          ASocket.SendWord(LSession.FImage.Height);
        end else begin
          ASocket.SendDWord(0);
        end;
      end;
    end;
  finally
    FreeAndNil(LSession);
  end;
end;

end.
