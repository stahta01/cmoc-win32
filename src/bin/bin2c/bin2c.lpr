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

program bin2c;

{$mode objfpc}{$H+}

uses
  Classes,
  SysUtils,
  UCmocParams,
  UCmocRbs;

{$R *.res}

  procedure Main;
  var
    LDstFile: TFileName;
    LBuffer: string;
    LOutput: TStrings;

    procedure FlushBuffer;
    begin
      if Length(LBuffer) > 0 then begin
        LOutput.Add(LBuffer);
        LBuffer := EmptyStr;
      end;
    end;

  begin
    with TCmocParams.Create do begin
      try
        LDstFile := GetFileNameOutput;
        with TFileStream.Create(GetFileNameOutput, fmOpenRead) do begin
          try
            LOutput := TStringList.Create;
            try
              LOutput.Add(Format('unsigned byte %s[%d] = {', [GetOptString('v'), Size]));
              LBuffer := EmptyStr;
              while Position < Size do begin
                if Length(LBuffer) > 0 then begin
                  LBuffer += ',';
                  if Length(LBuffer) > 75 then begin
                    FlushBuffer;
                  end;
                end;
                LBuffer += '0x' + IntToHex(ReadByte, 2);
              end;
              FlushBuffer;
              LOutput.Add('};');
              LOutput.SaveToFile(LDstFile);
            finally
              FreeAndNil(LOutput);
            end;
          finally
            Free;
          end;
        end;
      finally
        Free;
      end;
    end;
  end;

begin
  try
    Main;
  except
    ReadLn;
  end;
end.
