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
  UCmocRbs;

{$R *.res}

  procedure Main;
  var
    LDstFile: TFileName;
    LName, LBuffer: string;
    LOutput: TStrings;

    procedure FlushBuffer;
    begin
      if Length(LBuffer) > 0 then begin
        LOutput.Add(LBuffer);
        LBuffer := EmptyStr;
      end;
    end;

  begin
    with TStringList.Create do begin
      try
        CommaText := cmdline;
        LDstFile := Trim(Values['-o']);
        LName := Trim(Values['-v']);
      finally
        Free;
      end;
    end;
    if (ParamCount = 0) or (Length(LDstFile) = 0) then begin
      WriteLn(RbsLoadFromResource('HELP'));
      raise Exception.Create('Output filename missing');
    end;
    if Length(LName) = 0 then begin
      LName := '_array';
    end;
    with TFileStream.Create(ParamStr(ParamCount), fmOpenRead) do begin
      try
        LOutput := TStringList.Create;
        try
          LOutput.Add(Format('unsigned byte %s[%d] = {', [LName, Size]));
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
  end;

begin
  try
    Main;
  except
    on LException: Exception do WriteLn(LException.Message);
  end;
end.
