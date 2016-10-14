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
  Classes, FpHttpClient, SSockets, SysUtils, UBeckyStream;

const

  BECKY_STRING = 10;
  BECKY_BUFFER = 20;

type

  TBeckyServer = class(TINetServer)
  protected
    procedure HandleRequest(const AMessage: string; const AStream: TMemoryStream);
    procedure DoConnect(ASocket: TSocketStream); override;
  end;

implementation

procedure TBeckyServer.HandleRequest(const AMessage: string; const AStream: TMemoryStream);
var
  LPos: integer;
begin
  LPos := Pos(#32, AMessage);
  with TFPHTTPClient.Create(nil) do begin
    try
      WriteLn('Requesting ', AMessage);
      AStream.Clear;
      HTTPMethod(Copy(AMessage, 1, LPos - 1), Copy(AMessage, LPos + 1, MaxInt),
        AStream, [200]);
    finally
      Free;
    end;
  end;
  AStream.Position := 0;
end;

procedure TBeckyServer.DoConnect(ASocket: TSocketStream);
var
  FMemory: TMemoryStream;
begin
  WriteLn('Connected');
  FMemory := TMemoryStream.Create;
  try
    ASocket.Size := 0;
    while True do begin
      case ASocket.RecvWord of
        BECKY_STRING: begin
          HandleRequest(ASocket.RecvString, FMemory);
        end;
        BECKY_BUFFER: begin
          while (FMemory.Position < FMemory.Size) and ASocket.SendByte(FMemory.ReadByte) do begin
          end;
        end;
      end;
    end;
  finally
    FreeAndNil(FMemory);
  end;
end;

end.

