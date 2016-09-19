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

program cpp;

{$INCLUDE cmoc.inc}

uses
  Classes,
  FileUtil,
  SysUtils,
  Types,
  UCmocDefs,
  UCmocStringDynArray;

{$R *.res}

  procedure Main;
  var
    LIndex: integer;
    LParam: string;
    LParams: TStringDynArray;
    LToken, LPos: pchar;
  begin
    LParams := TStringDynArray.Create('-P', '-a', '-W', '0');
    LPos := CmdLine;
    LIndex := 0;
    while LPos^ <> #0 do begin
      while LPos^ in [#1..#32] do begin
        Inc(LPos);
      end;
      LToken := LPos;
      while not (LPos^ in [#0..#32]) do begin
        if LPos^ = '''' then begin
          repeat
            Inc(LPos);
          until LPos^ in [#0, ''''];
          if LPos^ <> #0 then begin
            Inc(LPos);
          end;
        end else begin
          Inc(LPos);
        end;
      end;
      if LIndex > 0 then begin
        SetString(LParam, LToken, LPos - LToken);
        if Length(LParam) > 0 then begin
          if LParam[1] = '-' then begin
            if (Length(LParam) > 1) and (LParam[2] in ['D', 'I', 'U']) then begin
              OStringDynArray.Add(LParams, '-' + LParam[2]);
              OStringDynArray.Add(LParams, AnsiDequotedStr(Copy(LParam, 3, MaxInt), ''''));
            end;
          end else begin
            OStringDynArray.Add(LParams, LParam);
          end;
        end;
      end;
      Inc(LIndex);
    end;
    ExecuteProcess(ProgramDirectory + Tool_MCPP, LParams, [ExecInheritsHandles]);
  end;

begin
  Main;
end.
