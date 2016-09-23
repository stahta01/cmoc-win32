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

unit UCmocStrings;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, SysUtils;

type
  TStringsHelper = class helper for TStrings
  public
    function _GetString(const AName, ADefault: string): string;
    procedure _InsertStrings(const AIndex: integer; const AStrings: array of string);
  end;

implementation

function TStringsHelper._GetString(const AName, ADefault: string): string;
var
  LIndex: integer;
begin
  LIndex := IndexOfName(AName);
  if LIndex < 0 then begin
    Result := ADefault;
  end else begin
    Result := ValueFromIndex[LIndex];
  end;
end;

procedure TStringsHelper._InsertStrings(const AIndex: integer; const AStrings: array of string);
var
  LIndex: integer;
begin
  for LIndex := 0 to High(AStrings) do begin
    Insert(AIndex + LIndex, AStrings[LIndex]);
  end;
end;

end.
