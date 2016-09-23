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

unit UCmocParams;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, StrUtils, SysUtils, UCmocUtils;

type
  TCmocParams = class(TStringList)
  public
  const
    OptWidth = 'w';
    OptHeight = 'h';
    OptOutput = 'o';
  private
    procedure Error(const AMessage: string);
  public
    constructor Create;
  public
    function HasOption(const AName: string): boolean;
    function IndexOfOption(const AName: string): integer;
    function GetOptString(const AName: string): string;
    function GetOptInteger(const AName: string; const ALow, AHigh: integer): integer;
  public
    function GetFileNameInput: TFileName;
    function GetFileNameOutput: TFileName;
  end;

implementation

constructor TCmocParams.Create;
var
  LIndex: integer;
  S1, S2: string;
begin
  inherited;
  CommaText := CmdLine;
  Delete(0);
  for LIndex := Count - 3 downto 0 do begin
    S1 := Strings[LIndex];
    S2 := Strings[LIndex + 1];
    if AnsiStartsStr('-', S1) and not AnsiStartsStr('-', S2) then begin
      Strings[LIndex] := S1 + '=' + S2;
      Delete(LIndex + 1);
    end;
  end;
end;

procedure TCmocParams.Error(const AMessage: string);
begin
  OCmoc.RaiseError(AMessage);
end;

function TCmocParams.HasOption(const AName: string): boolean;
begin
  Result := IndexOfName('-' + AName) >= 0;
end;

function TCmocParams.IndexOfOption(const AName: string): integer;
begin
  Result := IndexOfName('-' + AName);
  if Result < 0 then begin
    Error(Format('Unable to find option "-%s"', [AName]));
  end;
end;

function TCmocParams.GetOptString(const AName: string): string;
begin
  Result := Trim(ValueFromIndex[IndexOfOption(AName)]);
end;

function TCmocParams.GetOptInteger(const AName: string; const ALow, AHigh: integer): integer;
begin
  Result := StrToInt(GetOptString(AName));
  if (Result < ALow) or (Result > AHigh) then begin
    Error(Format('%s is out of range (range=%d..%d)', [AName, ALow, AHigh]));
  end;
end;

function TCmocParams.GetFileNameInput: TFileName;
begin
  if Count = 0 then begin
    Error('Input file not selected');
  end;
  Result := ExpandFileName(Strings[Count - 1]);
  if not FileExists(Result) then begin
    //Error('Unable to find input filename ' + OCmoc.StringQuoted(Result));
  end;
end;

function TCmocParams.GetFileNameOutput: TFileName;
begin
  Result := GetOptString(OptOutput);
  if Length(Result) = 0 then begin
    Error('Output file not selected');
  end;
  Result := ExpandFileName(Result);
end;

end.
