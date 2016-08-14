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

unit UCmocIDE;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, KeyInputIntf, SysUtils;

type

  TStringsHelper = class helper for TStrings
  public
    procedure _Write(const AString: string; const APrefix: string = default(string));
    procedure _WriteLn(const AString: string; const APrefix: string = default(string));
  end;

  TKeyInputHelper = class helper for TKeyInput
    procedure _ApplyShortCut(const AShortCut: TShortCut);
  end;

  CStringsStream = class(TStream)
  strict private
    FStrings: TStrings;
  public
    Task: string;
  public
    constructor Create(const AStrings: TStrings);
  public
    function Write(const ABuffer; ACount: longint): longint; override;
  end;

implementation

procedure TStringsHelper._Write(const AString, APrefix: string);
var
  LLastLine: string;
begin
  BeginUpdate;
  try
    if Count = 0 then begin
      LLastLine := APrefix;
    end else begin
      LLastLine := APrefix + Strings[Count - 1];
      Delete(Count - 1);
    end;
    AddText(LLastLine + AString + LineEnding);
  finally
    EndUpdate;
  end;
end;

procedure TStringsHelper._WriteLn(const AString, APrefix: string);
begin
  _Write(AString + LineEnding, APrefix);
end;

procedure TKeyInputHelper._ApplyShortCut(const AShortCut: TShortCut);
var
  LShiftState: TShiftState;
begin
  LShiftState := default(TShiftState);
  if (AShortCut and scShift) <> 0 then begin
    Include(LShiftState, ssShift);
  end;
  if (AShortCut and scAlt) <> 0 then begin
    Include(LShiftState, ssAlt);
  end;
  if (AShortCut and scCtrl) <> 0 then begin
    Include(LShiftState, ssCtrl);
  end;
  Apply(LShiftState);
  Press(AShortCut and $FF);
  Unapply(LShiftState);
end;

constructor CStringsStream.Create(const AStrings: TStrings);
begin
  inherited Create;
  FStrings := AStrings;
end;

function CStringsStream.Write(const ABuffer; ACount: longint): longint;
var
  LString: string;
begin
  SetString(LString, @ABuffer, ACount);
  if Length(Task) = 0 then begin
    FStrings._Write(LString);
  end else begin
    FStrings._Write(LString, Task + ': ');
  end;
  Result := ACount;
end;

end.

