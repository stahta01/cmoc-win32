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
  Classes, SSockets;

type

  TBeckySocketStreamHelper = class helper for TSocketStream
  public
    function RecvByte: byte;
    function RecvWord: word;
    function RecvDWord: dword;
    function RecvString: string;
  public
    function SendByte(const A: byte): boolean;
    function SendWord(const A: word): boolean;
    function SendDWord(const A: dword): boolean;
    function SendString(const A: string): boolean;
    function SendStream(const A: TStream): boolean;
  end;

implementation

function TBeckySocketStreamHelper.RecvByte: byte;
begin
  Result := ReadByte;
  WriteByte(Result);
end;

function TBeckySocketStreamHelper.RecvWord: word;
begin
  Result := (RecvByte shl 8) or RecvByte;
end;

function TBeckySocketStreamHelper.RecvDWord: dword;
begin
  Result := (RecvByte shl 24) or (RecvByte shl 16) or (RecvByte shl 8) or RecvByte;
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

function TBeckySocketStreamHelper.SendWord(const A: word): boolean;
begin
  Result := SendByte(A shr 8) and SendByte(A);
end;

function TBeckySocketStreamHelper.SendDWord(const A: dword): boolean;
begin
  Result := SendByte(A shr 24) and SendByte(A shr 16) and SendByte(A shr 8) and SendByte(A);
end;

function TBeckySocketStreamHelper.SendString(const A: string): boolean;
var
  LIndex: integer;
begin
  Result := SendWord(Length(A));
  if Result then begin
    for LIndex := 1 to Length(A) do begin
      Result := SendByte(byte(A[LIndex]));
      if not Result then begin
        Break;
      end;
    end;
  end;
end;

function TBeckySocketStreamHelper.SendStream(const A: TStream): boolean;
begin
  SendDWord(A.Size);
  A.Position := 0;
  while A.Position < A.Size do begin
    if not SendByte(A.ReadByte) then begin
      Exit(False);
    end;
  end;
  Result := True;
end;

end.
