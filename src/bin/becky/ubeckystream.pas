unit UBeckyStream;

{$mode objfpc}{$H+}

interface

uses
  SSockets;

type

  TBeckySocketStreamHelper = class helper for TSocketStream
    function RecvByte: byte;
    function RecvWord: word;
    function RecvString: string;
    function SendByte(const A: byte): boolean;
  end;

implementation

function TBeckySocketStreamHelper.RecvByte: byte;
begin
  Result := ReadByte;
  WriteByte(Result);
end;

function TBeckySocketStreamHelper.RecvWord: word;
begin
  Result := RecvByte;
  Result := (RecvByte shl 8) or Result;
end;

function TBeckySocketStreamHelper.RecvString: string;
var
  LIndex: integer;
begin
  SetLength(Result, RecvWord);
  for LIndex := 1 to Length(Result) do begin
    Result[LIndex] := char(RecvByte);
  end;
end;

function TBeckySocketStreamHelper.SendByte(const A: byte): boolean;
begin
  WriteByte(A);
  Result := ReadByte = A;
end;

end.

