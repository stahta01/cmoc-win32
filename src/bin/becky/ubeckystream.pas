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

unit UBeckyStream;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, SSockets, SysUtils;

type

  TBeckySocketStreamHelper = class helper for TSocketStream
  public
    function RecvByte: byte;
    function RecvWord: word;
    function RecvDWord: dword;
    function RecvData: rawbytestring;
  public
    procedure SendByte(const A: byte);
    procedure SendWord(const A: word);
    procedure SendDWord(const A: dword);
    procedure SendString(const A: string);
    procedure SendStream(const A: TStream; const ASize: integer);
  end;

implementation

function TBeckySocketStreamHelper.RecvByte: byte;
begin
  Result := ReadByte;
end;

function TBeckySocketStreamHelper.RecvWord: word;
begin
  Result := (RecvByte shl 8) or RecvByte;
end;

function TBeckySocketStreamHelper.RecvDWord: dword;
begin
  Result := (RecvByte shl 24) or (RecvByte shl 16) or (RecvByte shl 8) or RecvByte;
end;

function TBeckySocketStreamHelper.RecvData: rawbytestring;
var
  LIndex: integer;
begin
  SetLength(Result, RecvWord);
  for LIndex := 1 to Length(Result) do begin
    Result[LIndex] := char(RecvByte);
  end;
end;

procedure TBeckySocketStreamHelper.SendByte(const A: byte);
begin
  WriteByte(A);
  ReadByte;
end;

procedure TBeckySocketStreamHelper.SendWord(const A: word);
begin
  SendByte(A shr 8);
  SendByte(A);
end;

procedure TBeckySocketStreamHelper.SendDWord(const A: dword);
begin
  SendByte(A shr 24);
  SendByte(A shr 16);
  SendByte(A shr 8);
  SendByte(A);
end;

procedure TBeckySocketStreamHelper.SendString(const A: string);
var
  LIndex: integer;
begin
  SendWord(Length(A));
  for LIndex := 1 to Length(A) do begin
    SendByte(byte(A[LIndex]));
  end;
end;

procedure TBeckySocketStreamHelper.SendStream(const A: TStream; const ASize: integer);
var
  LIndex: integer;
begin
  for LIndex := 1 to ASize do begin
    SendByte(A.ReadByte);
  end;
end;

end.
