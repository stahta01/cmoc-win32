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

unit UCmocMain;

{$INCLUDE cmoc.inc}

interface

uses
  SysUtils, UCmocParams, UCmocRbs;

type
  TMainProcedure = procedure(const AParams: TCmocParams);

procedure CmocMain(AMainProcedure: TMainProcedure);

implementation

procedure CmocMain(AMainProcedure: TMainProcedure);
var
  LParams: TCmocParams;
begin
  LParams := TCmocParams.Create;
  try
    try
      AMainProcedure(LParams);
    except
      on LException: Exception do begin
        WriteLn(StdErr, LineEnding + Trim(RbsLoadFromResource('USAGE')) + LineEnding + LineEnding +
          'Copyright (C) 2016 Derek John Evans' + LineEnding + LineEnding +
          'This program is free software; you may redistribute it under the terms of' +
          LineEnding +
          'the GNU General Public License, either version 3 or later.' + LineEnding +
          'This program comes with absolutely no warranty.' + LineEnding);
        WriteLn(StdErr, 'Error: ' + LException.Message);
        if (startupinfo.dwFlags and 1) <> 0 then begin
          WriteLn;
          WriteLn('Press enter to exit');
          ReadLn;
        end;
      end;
    end;
  finally
    FreeAndNil(LParams);
  end;
end;

end.
