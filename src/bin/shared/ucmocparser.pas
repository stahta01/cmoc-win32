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
