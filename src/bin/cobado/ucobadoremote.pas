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

unit UCobadoRemote;

{$INCLUDE cobado.inc}

interface

uses
  Classes, StrUtils, SysUtils, UCobadoStream;

type

  CCobadoRemote = class(CCobadoStream)
  public
    procedure PrintChar(const A: char);
    procedure PrintString(const A: string);
    procedure PrintColumn(const A: string);
    procedure PrintCurrentDir;
  public
    procedure Poke(const ADst: word; const AVal: byte);
    procedure PokeW(const ADst, AVal: word);
  public
    function Peek(const ASrc: word): byte;
    function PeekW(const ASrc: word): word;
  public
    function GetMem(const ASrc, ASize: word): string;
    procedure SetMem(const ADst: word; const ASrc: string);
  public
    procedure JsrMem(const AAddr: word);
  public
    procedure ClearLineBuffer;
  end;

implementation

procedure CCobadoRemote.PrintChar(const A: char);
begin
  SendCode(ccChrOut);
  SendByte(byte(A));
end;

function CCobadoRemote.GetMem(const ASrc, ASize: word): string;
var
  LIndex: integer;
begin
  SetLength(Result, ASize);
  if ASize > 0 then begin
    SendCode(ccGetMem);
    SendWord(ASrc);
    SendWord(ASize);
    for LIndex := 1 to ASize do begin
      Result[LIndex] := char(RecvByte);
    end;
  end;
end;

procedure CCobadoRemote.SetMem(const ADst: word; const ASrc: string);
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

procedure CCobadoRemote.JsrMem(const AAddr: word);
begin
  SendCode(ccJsrMem);
  SendWord(AAddr);
end;

procedure CCobadoRemote.Poke(const ADst: word; const AVal: byte);
begin
  SetMem(ADst, Chr(AVal));
end;

procedure CCobadoRemote.PokeW(const ADst, AVal: word);
begin
  SetMem(ADst, Chr(AVal shr 8) + Chr(AVal));
end;

function CCobadoRemote.Peek(const ASrc: word): byte;
begin
  Result := byte(GetMem(ASrc, 1)[1]);
end;

function CCobadoRemote.PeekW(const ASrc: word): word;
var
  LString: string;
begin
  LString := GetMem(ASrc, 1);
  Result := (word(LString[1]) shl 8) or word(LString[2]);
end;

procedure CCobadoRemote.PrintString(const A: string);
var
  LIndex: integer;
begin
  for LIndex := 1 to Length(A) do begin
    PrintChar(A[LIndex]);
  end;
end;

procedure CCobadoRemote.PrintColumn(const A: string);
begin
  PrintString(PadRight(A, (Length(A) + 15) div 16 * 16));
end;

procedure CCobadoRemote.PrintCurrentDir;
begin
  PrintString(#13 + GetCurrentDir + '>');
end;

procedure CCobadoRemote.ClearLineBuffer;
begin
  Poke(733, 0);
end;

end.
