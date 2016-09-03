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
  Process,
  StrUtils,
  SysUtils,
  UCmocRbs;

{$R *.res}

type

  TProcessRunWild = class(TProcess)
  strict private
    procedure ValidateExitCode(const AExitCode: longint);
  public
    constructor Create(AOwner: TComponent); override;
    procedure Execute; override;
  end;

  constructor TProcessRunWild.Create(AOwner: TComponent);
  begin
    inherited;
    ShowWindow := swoHIDE;
    Options := [poUsePipes, poStderrToOutput];
  end;

  procedure TProcessRunWild.ValidateExitCode(const AExitCode: longint);
  begin
    if AExitCode <> 0 then begin
      raise Exception.CreateFmtHelp('%s failed with exit code #%d',
        [Executable, AExitCode], AExitCode);
    end;
  end;

  procedure TProcessRunWild.Execute;
  var
    LIndex: integer;
    LParameter, LNewCommandLine: string;
    LSearchRec: TSearchRec;
    LBuffer: array[byte] of byte;
    LArgs: TStrings;
  begin
    LBuffer[0] := 0;
    LArgs := TStringList.Create;
    try
      LArgs.CommaText := CmdLine;
      if LArgs.Count < 2 then begin
        WriteLn(RbsLoadFromResource('HELP'));
        raise Exception.Create('missing executable parameter');
      end;
      Executable := LArgs[1];
      for LIndex := 2 to LArgs.Count - 1 do begin
        LParameter := LArgs[LIndex];
        if Length(LParameter) > 0 then begin
          if (LParameter[1] <> '-') and (PosSet(['*', '?'], LParameter) > 0) then begin
            if FindFirst(LParameter, 0, LSearchRec) = 0 then begin
              try
                repeat
                  Parameters.Add(ExtractFilePath(LParameter) + LSearchRec.Name);
                until FindNext(LSearchRec) <> 0;
              finally
                FindClose(LSearchRec);
              end;
            end;
          end else begin
            Parameters.Add(LParameter);
          end;
        end;
      end;
      LNewCommandLine := ChangeFileExt(ExtractFileName(Executable), default(string));
      for LParameter in Parameters do begin
        if PosSet(AllowDirectorySeparators + [#32], LParameter) = 0 then begin
          LNewCommandLine += #32 + LParameter;
        end else begin
          LNewCommandLine += #32 + AnsiQuotedStr(LParameter, '"');
        end;
      end;
      WriteLn('>> ', LNewCommandLine);
      try
        inherited Execute;
      except
        ValidateExitCode(2);
      end;
      Sleep(20);
      while (Running or (Output.NumBytesAvailable > 0)) do begin
        if Output.NumBytesAvailable > 0 then begin
          while Output.NumBytesAvailable > 0 do begin
            FileWrite(StdOutputHandle, LBuffer, Output.Read(LBuffer, SizeOf(LBuffer)));
          end;
        end else begin
          Sleep(100);
        end;
      end;
      ValidateExitCode(ExitCode);
    finally
      FreeAndNil(LArgs);
    end;
  end;

begin
  with TProcessRunWild.Create(nil) do begin
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
  ReadLn;
end.
