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

program cmoc2;

{$INCLUDE cmoc.inc}

uses
  SysUtils,
  UCmocProcess_ASM,
  UCmocProcess_CMOC2,
  UCmocProcess_TOOLS;

{$R *.res}

begin
  try
    with CCmocProcess_CMOC2.Create(nil) do begin
      try
        DoBuild;
      finally
        Free;
      end;
    end;
  except
    on LException: Exception do begin
      WriteLn(StdErr, LException.Message);
      ExitCode := LException.HelpContext;
    end;
  end;
end.
