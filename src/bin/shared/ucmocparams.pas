{
 ***************************************************************************
 *                                                                         *
 *   This source is free software; you can redistribute it and/or modify   *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This code is distributed in the hope that it will be useful, but      *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   General Public License for more details.                              *
 *                                                                         *
 *   A copy of the GNU General Public License is available on the World    *
 *   Wide Web at <http://www.gnu.org/copyleft/gpl.html>. You can also      *
 *   obtain it by writing to the Free Software Foundation,                 *
 *   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.        *
 *                                                                         *
 ***************************************************************************
}

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
