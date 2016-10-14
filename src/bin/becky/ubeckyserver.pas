unit UBeckyServer;

{$mode objfpc}{$H+}

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

