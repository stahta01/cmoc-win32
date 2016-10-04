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
    function _IndexOfName(const AName: string): integer;
    function _GetString(const AName, ADefault: string): string;
    procedure _InsertStrings(const AIndex: integer; const AStrings: array of string);
  public
    procedure _MergeValues(const AStrings: TStrings);
    procedure _MergeValues(const ACommaText: string);
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

procedure NameValueSplit(const A: string; var AName, AValue: string);
var
  LPos: integer;
begin
  LPos := Pos('=', A);
  if LPos = 0 then begin
    AName := A;
    AValue := EmptyStr;
  end else begin
    AName := Copy(A, 1, LPos - 1);
    AValue := Copy(A, LPos + 1, MaxInt);
  end;
end;

function TStringsHelper._IndexOfName(const AName: string): integer;
var
  LName, LValue: string;
begin
  for Result := 0 to Count - 1 do begin
    NameValueSplit(Strings[Result], LName, LValue);
    if AnsiSameText(LName, AName) then begin
      Exit;
    end;
  end;
  Result := -1;
end;

procedure TStringsHelper._MergeValues(const AStrings: TStrings);
var
  LIndex, LPos: integer;
  LNameValue, LName, LValue: string;
begin
  for LIndex := 0 to AStrings.Count - 1 do begin
    NameValueSplit(AStrings[LIndex], LName, LValue);
    LNameValue := LName + '=' + LValue;
    LPos := _IndexOfName(LName);
    if LPos < 0 then begin
      Add(LNameValue);
    end else begin
      Strings[LPos] := LNameValue;
    end;
  end;
end;

procedure TStringsHelper._MergeValues(const ACommaText: string);
var
  LStrings: TStrings;
begin
  LStrings := TStringList.Create;
  try
    LStrings.CommaText := ACommaText;
    _MergeValues(LStrings);
  finally
    FreeAndNil(LStrings);
  end;
end;

end.
