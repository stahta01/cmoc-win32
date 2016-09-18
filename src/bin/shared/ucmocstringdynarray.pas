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

unit UCmocStringDynArray;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, StrUtils, SysUtils, Types, UCmocDefs;

type

  OStringDynArray = object
  public
    class procedure Add(var A: TStringDynArray; const S: string);
    class procedure Insert(var A: TStringDynArray; const I: integer; const S: string);
    class procedure AddStrings(var A: TStringDynArray; const AStrings: array of string);
    class procedure AddOption(var A: TStringDynArray; const AOption, AValue: string;
      const ASingleEntry: boolean);
    class procedure AddDefine(var A: TStringDynArray; const AName, AValue: string;
      const ASingleEntry: boolean);
    class procedure AddInclude(var A: TStringDynArray; const AFilePath: TFileName;
      const ASingleEntry: boolean);
    class procedure AddLib(var A: TStringDynArray; const AName: string);
    class procedure AddLibs(var A: TStringDynArray);
    class procedure AddOptions(var A: TStringDynArray; const AOptions: TStrings;
      const AInclude: array of string);
  end;

implementation

class procedure OStringDynArray.Add(var A: TStringDynArray; const S: string);
begin
  SetLength(A, Length(A) + 1);
  A[High(A)] := S;
end;

class procedure OStringDynArray.Insert(var A: TStringDynArray; const I: integer; const S: string);
var
  LIndex: integer;
begin
  SetLength(A, Length(A) + 1);
  for LIndex := High(A) - 1 downto I do begin
    A[LIndex + 1] := A[LIndex];
  end;
  A[I] := S;
end;

class procedure OStringDynArray.AddStrings(var A: TStringDynArray;
  const AStrings: array of string);
var
  LString: string;
begin
  for LString in AStrings do begin
    Add(A, LString);
  end;
end;

class procedure OStringDynArray.AddOption(var A: TStringDynArray;
  const AOption, AValue: string; const ASingleEntry: boolean);
begin
  if ASingleEntry then begin
    Add(A, AOption + AValue);
  end else begin
    Add(A, AOption);
    Add(A, AValue);
  end;
end;

class procedure OStringDynArray.AddInclude(var A: TStringDynArray;
  const AFilePath: TFileName; const ASingleEntry: boolean);
begin
  AddOption(A, Opt_Include2, AFilePath, ASingleEntry);
end;

class procedure OStringDynArray.AddDefine(var A: TStringDynArray;
  const AName, AValue: string; const ASingleEntry: boolean);
begin
  AddOption(A, Opt_Define2, AName + '=' + AValue, ASingleEntry);
end;

class procedure OStringDynArray.AddLib(var A: TStringDynArray; const AName: string);
begin
  Add(A, Opt_LibInclude2);
  Add(A, AName);
end;

class procedure OStringDynArray.AddLibs(var A: TStringDynArray);
begin
  AddLib(A, 'all');
  (*
  AddLib(A, '6809');
  AddLib(A, 'basic');
  AddLib(A, 'c');
  AddLib(A, 'charset');
  AddLib(A, 'cmoc');
  AddLib(A, 'coco');
  AddLib(A, 'conio');
  AddLib(A, 'ctype');
  AddLib(A, 'disk');
  AddLib(A, 'exomizer');
  AddLib(A, 'fast');
  AddLib(A, 'graph');
  AddLib(A, 'kreider');
  AddLib(A, 'lzss');
  AddLib(A, 'malloc');
  AddLib(A, 'memory');
  AddLib(A, 'motorola');
  AddLib(A, 'stdio');
  AddLib(A, 'string');
  AddLib(A, 'system');
  AddLib(A, 'unistd');
  AddLib(A, 'varptr');
  AddLib(A, 'rma');
  *)
end;

class procedure OStringDynArray.AddOptions(var A: TStringDynArray;
  const AOptions: TStrings; const AInclude: array of string);
var
  LIndex, LPos: integer;
  LName, LValue: string;
  LValues: TStrings;
begin
  LValues := TStringList.Create;
  try
    for LIndex := 0 to AOptions.Count - 1 do begin
      LName := Trim(AOptions[LIndex]);
      LPos := Pos('=', LName);
      if LPos = 0 then begin
        LPos := Length(LName) + 1;
      end;
      LValue := Trim(Copy(LName, LPos + 1, MaxInt));
      LName := Trim(Copy(LName, 1, LPos - 1));
      if AnsiMatchText(LName, AInclude) then begin
        if Length(LValue) = 0 then begin
          Add(A, LName);
        end else begin
          LValues.CommaText := LValue;
          for LValue in LValues do begin
            Add(A, LName);
            if Length(LValue) > 0 then begin
              Add(A, LValue);
            end;
          end;
        end;
      end;
    end;
  finally
    FreeAndNil(LValues);
  end;
end;

end.

