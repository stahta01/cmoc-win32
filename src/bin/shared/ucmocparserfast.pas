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

unit UCmocParserFast;

{$INCLUDE cmoc.inc}

interface

uses
  SysUtils, UCmocCharSet;



type
  TParserFast = object
  strict private
    FBeg, FTok, FPos: pchar;
  public
    procedure SetParser(const A: pchar);
    procedure Rewind;
    procedure TokenClear;
    function Done: boolean;
    function TokenAsString: string;
  public
    procedure ParseWhile(A: TSysCharSet);
    procedure ParseUntil(A: TSysCharSet);
  public
    procedure ParseParameter;
  end;

implementation

procedure TParserFast.SetParser(const A: pchar);
begin
  FBeg := A;
  Rewind;
end;

procedure TParserFast.Rewind;
begin
  FPos := FBeg;
  TokenClear;
end;

procedure TParserFast.TokenClear;
begin
  FTok := FPos;
end;

function TParserFast.Done: boolean;
begin
  Result := FPos^ = #0;
end;

function TParserFast.TokenAsString: string;
begin
  SetString(Result, FTok, FPos - FTok);
end;

procedure TParserFast.ParseWhile(A: TSysCharSet);
begin
  Exclude(A, #0);
  while FPos^ in A do begin
    Inc(FPos);
  end;
end;

procedure TParserFast.ParseUntil(A: TSysCharSet);
begin
  Include(A, #0);
  while not (FPos^ in A) do begin
    Inc(FPos);
  end;
end;

procedure TParserFast.ParseParameter;
begin
  while FPos^ in OCharSet.Graph do begin
    if FPos^ = '''' then begin
      repeat
        Inc(FPos);
      until FPos^ in [#0, ''''];
      if FPos^ <> #0 then begin
        Inc(FPos);
      end;
    end else begin
      Inc(FPos);
    end;
  end;
end;

end.
