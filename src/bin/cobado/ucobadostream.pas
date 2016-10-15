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

unit UCobadoStream;

{$INCLUDE cobado.inc}

interface

uses
  SSockets;

type

  TCobadoCode = (ccNothing, ccChrOut, ccGetMem, ccSetMem, ccPoke, ccPokeW,
    ccPeek, ccPeekW, ccMemSet, ccMemCpy, ccJsrMem);


  CCobadoStream = class helper for TSocketStream
  public
    procedure SendByte(const A: byte);
    procedure SendCode(const A: TCobadoCode);
    procedure SendWord(const A: word);
  public
    procedure ChrOut(const A: char);
    procedure StrOut(const A: string);
  public
    procedure Poke(const ADst: word; const AVal: byte);
    procedure PokeW(const ADst, AVal: word);
  public
    function Peek(const ASrc: word): byte;
    function PeekW(const ASrc: word): word;
  public
    function GetMem(const ASrc, ASize: word): rawbytestring;
    procedure SetMem(const ADst: word; const ASrc: rawbytestring);
  public
    procedure MemSet(const ADst: word; const AVal: byte; const ASize: word);
    procedure MemCpy(const ADst, ASrc, ASize: word);
  public
    procedure JsrMem(const AAddr: word);
  end;

implementation

procedure CCobadoStream.SendByte(const A: byte);
begin
  WriteByte(A);
  ReadByte;
end;

procedure CCobadoStream.SendCode(const A: TCobadoCode);
begin
  SendByte(Ord(A));
end;

procedure CCobadoStream.SendWord(const A: word);
begin
  SendByte(A and $ff);
  SendByte(A shr 8);
end;

procedure CCobadoStream.ChrOut(const A: char);
begin
  SendCode(ccChrOut);
  SendByte(byte(A));
end;

function CCobadoStream.GetMem(const ASrc, ASize: word): rawbytestring;
var
  LIndex: integer;
begin
  SetLength(Result, ASize);
  if ASize > 0 then begin
    SendCode(ccGetMem);
    SendWord(ASrc);
    SendWord(ASize);
    for LIndex := 1 to ASize do begin
      Result[LIndex] := char(ReadByte);
    end;
  end;
end;

procedure CCobadoStream.SetMem(const ADst: word; const ASrc: rawbytestring);
var
  LIndex: integer;
begin
  if Length(ASrc) > 0 then begin
    SendCode(ccSetMem);
    SendWord(ADst);
    SendWord(Length(ASrc));
    for LIndex := 1 to Length(ASrc) do begin
      SendByte(byte(ASrc[LIndex]));
    end;
  end;
end;

procedure CCobadoStream.JsrMem(const AAddr: word);
begin
  SendCode(ccJsrMem);
  SendWord(AAddr);
end;

procedure CCobadoStream.Poke(const ADst: word; const AVal: byte);
begin
  SendCode(ccPoke);
  SendWord(ADst);
  SendByte(AVal);
end;

procedure CCobadoStream.PokeW(const ADst, AVal: word);
begin
  SendCode(ccPokeW);
  SendWord(ADst);
  SendWord(AVal);
end;

function CCobadoStream.Peek(const ASrc: word): byte;
begin
  SendCode(ccPeek);
  SendWord(ASrc);
  Result := ReadByte;
end;

function CCobadoStream.PeekW(const ASrc: word): word;
begin
  SendCode(ccPeekW);
  SendWord(ASrc);
  Result := ReadWord;
end;

procedure CCobadoStream.MemSet(const ADst: word; const AVal: byte; const ASize: word);
begin
  SendCode(ccMemSet);
  SendWord(ADst);
  SendByte(AVal);
  SendWord(ASize);
end;

procedure CCobadoStream.MemCpy(const ADst, ASrc, ASize: word);
begin
  SendCode(ccMemCpy);
  SendWord(ADst);
  SendWord(ASrc);
  SendWord(ASize);
end;

procedure CCobadoStream.StrOut(const A: string);
var
  LIndex: integer;
begin
  for LIndex := 1 to Length(A) do begin
    ChrOut(A[LIndex]);
  end;
end;

end.
