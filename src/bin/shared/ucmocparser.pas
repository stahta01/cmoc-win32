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

unit UCmocParser;

{$INCLUDE cmoc.inc}

interface

uses
  SysUtils;

type

  OCmocParser = object
  strict private
    FString: string;
    FPos, FEnd: integer;
  public
    procedure SetString(const ALine: string);
    procedure ClearToken;
  public
    function PeekChar: char; inline;
    function Done: boolean; inline;
  public
    function TokenLength: integer; inline;
    function Token: string; inline;
    function Remaining: string; inline;
    function SameText(const AToken: string): boolean; inline;
  public
    procedure IncludeChar;
    procedure IncludeWhile(const A: TSysCharSet);
    procedure IncludeUntil(const A: TSysCharSet);
  end;

implementation

procedure OCmocParser.SetString(const ALine: string);
begin
  FString := ALine;
  FPos := 1;
  FEnd := 1;
end;

procedure OCmocParser.ClearToken;
begin
  FPos := FEnd;
end;

function OCmocParser.PeekChar: char;
begin
  if Done then begin
    Result := #0;
  end else begin
    Result := FString[FEnd];
  end;
end;

function OCmocParser.TokenLength: integer;
begin
  Result := FEnd - FPos;
end;

function OCmocParser.Token: string;
begin
  Result := Copy(FString, FPos, FEnd - FPos);
end;

function OCmocParser.Remaining: string;
begin
  Result := Copy(FString, FEnd, MaxInt);
end;

function OCmocParser.SameText(const AToken: string): boolean;
begin
  Result := SysUtils.SameText(AToken, Token);
end;

function OCmocParser.Done: boolean;
begin
  Result := FEnd > Length(FString);
end;

procedure OCmocParser.IncludeChar;
begin
  if not Done then begin
    Inc(FEnd);
  end;
end;

procedure OCmocParser.IncludeWhile(const A: TSysCharSet);
begin
  while not Done and (FString[FEnd] in A) do begin
    Inc(FEnd);
  end;
end;

procedure OCmocParser.IncludeUntil(const A: TSysCharSet);
begin
  while not Done and not (FString[FEnd] in A) do begin
    Inc(FEnd);
  end;
end;

end.
