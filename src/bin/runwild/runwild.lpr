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

program runwild;

{$mode objfpc}{$H+}

uses
  Classes,
  StrUtils,
  SysUtils,
  Types,
  UCmocRbs,
  UCmocUtils;

{$R *.res}

type

  CRunWild = class
  strict private
    FExecutable: string;
  strict private
    procedure ValidateExitCode(const AExitCode: longint);
  public
    procedure Execute;
  end;

  procedure CRunWild.ValidateExitCode(const AExitCode: longint);
  begin
    if AExitCode <> 0 then begin
      raise Exception.CreateFmtHelp('%s failed with exit code #%d',
        [FExecutable, AExitCode], AExitCode);
    end;
  end;

  procedure CRunWild.Execute;
  var
    LIndex: integer;
    LParameter, LNewCommandLine: string;
    LParameters: TStringDynArray;
    LSearchRec: TSearchRec;
    LArgs: TStrings;
  begin
    LParameters := default(TStringDynArray);
    LArgs := TStringList.Create;
    try
      LArgs.CommaText := CmdLine;
      if LArgs.Count < 2 then begin
        WriteLn(RbsLoadFromResource('HELP'));
        OCmoc.RaiseError('missing executable parameter');
      end;
      FExecutable := LArgs[1];
      for LIndex := 2 to LArgs.Count - 1 do begin
        LParameter := LArgs[LIndex];
        if Length(LParameter) > 0 then begin
          if (LParameter[1] <> '-') and (PosSet(['*', '?'], LParameter) > 0) then begin
            if FindFirst(LParameter, 0, LSearchRec) = 0 then begin
              try
                repeat
                  OCmoc.StringDynArrayAppend(LParameters, ExtractFilePath(LParameter) +
                    LSearchRec.Name);
                until FindNext(LSearchRec) <> 0;
              finally
                FindClose(LSearchRec);
              end;
            end;
          end else begin
            OCmoc.StringDynArrayAppend(LParameters, LParameter);
          end;
        end;
      end;
      LNewCommandLine := ChangeFileExt(ExtractFileName(FExecutable), default(string));
      for LParameter in LParameters do begin
        if PosSet(AllowDirectorySeparators + [#32], LParameter) = 0 then begin
          LNewCommandLine += #32 + LParameter;
        end else begin
          LNewCommandLine += #32 + AnsiQuotedStr(LParameter, '"');
        end;
      end;
      WriteLn('>> ', LNewCommandLine);
      try
        ValidateExitCode(ExecuteProcess(FExecutable, LParameters, [ExecInheritsHandles]));
      except
        ValidateExitCode(2);
      end;
    finally
      FreeAndNil(LArgs);
    end;
  end;

begin
  with CRunWild.Create do begin
    try
      try
        Execute;
      except
        on E: Exception do begin
          WriteLn(System.StdErr, E.Message);
          System.ExitCode := ExitCode;
        end;
      end;
    finally
      Free;
    end;
  end;
end.
