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

unit UCmocUtils;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, FileUtil, LazFileUtils, Process, StrUtils, SysUtils, Types, UCmocDefs,
  UCmocParser, UCmocStringDynArray;

type
  ECmocException = EAbort;

type

  TFileNames = array of TFileName;

type

  TCmocGlobalValue = object
    Type_, Value, Offset: string;
  end;

  TCmocGlobalValues = array of TCmocGlobalValue;

type

  OAsmParser = object(OCmocParser)
  public
    function Next: boolean;
    function NextAndTokenIs(const AToken: string): boolean;
  end;

type

  CCmocProcess = class(TProcess)
  strict private
    procedure CheckExitCode(const AExitCode: longint);
  public
    constructor Create(AOwner: TComponent); override;
  public
    procedure Execute(const AExecutable: TFileName; const AParams: array of string;
      const ACurrentDirectory: TFileName = default(string)); reintroduce;
    procedure ExecuteTool(const ATool: string; const AParams: array of string;
      const ACurrentDirectory: TFileName = default(string));
  public
    procedure ExecuteTool_ASTYLE(const ADst, ASrc: TFileName; const ATabWidth: integer);
  end;

var

  TargetList: array[0..4] of string = ('coco', 'dragon', 'os9', 'flex', 'vectrex');

type

  OCmoc = object
  strict private
    class function PathToTemp: TFileName;
  public
    class function IsDev: boolean;
  public
    class function DosToUnix(const A: TFileName): TFileName;
    class function UnixToDos(const A: TFileName): TFileName;
  public
    class function FileChanged(const ADst, ASrc: TFileName): boolean;
    class function FileNameTemp(const APostfix: string): TFileName;
    class function FileNameTemp(const APrefix, APostfix: string): TFileName;
    class function FileNameToIdent(const A: TFileName): string;
    class function FileNameToInitGlobals(const A: TFileName): string;
    class function FileNameTool(const ATool: string): TFileName;
    class function FileNameTranslate(const A: TFileName): TFileName;
  public
    class function PathToInclude: TFileName;
    class function PathToLib: TFileName;
    class function PathToBin: TFileName;
    class function PathToDsk: TFileName;
    class function PathToPackage: TFileName;
    class function PathToXRoar: TFileName;
    class function PathToXRoarRoms: TFileName;
    class function PathToVcc: TFileName;
    class function PathToSrc: TFileName;
    class function PathToSrcAsm: TFileName;
    class function PathToSrcLib: TFileName;
  public
    class function IntegerToDisplay(const A: integer): string;
    class function AssertRange(const A, ALow, AHigh: integer;
      const AName: string = 'number'): integer;
  public
    class function StringQuoted(const A: string): string;
    class function StringToIdent(const A: string): string;
    class function StringToInteger(const A: string): longint;
    class function SymbolIsPublic(const A: string): boolean;
  public
    class procedure SourcePragmas(const ADst, ASrc: TFileName; var AOrigin: cardinal;
      var ATarget: string; var AOptions: string);
    class procedure SourcePragmas(const ADst, ASrc: TStrings; var AOrigin: cardinal;
      var ATarget: string; var AOptions: string);
  public
    class procedure FileNamesAppend(var A: TStringDynArray; AFileName: TFileName;
      const AMustExist: boolean);
    class procedure RaiseError(AMessage, ADetails: string; const AExitCode: integer = -1);
    class procedure RaiseError(AMessage: string; const AExitCode: integer = -1);
  public
    class procedure StringsInsertWinCMOCHeader(const A: TStrings; const ANoDate: boolean = False);
  end;

implementation

class function OCmoc.IsDev: boolean;
begin
  Result := AnsiStartsText('c:\dev\', ParamStr(0));
end;

class function OCmoc.IntegerToDisplay(const A: integer): string;
begin
  Result := '$' + IntToHex(A, 4) + '(' + IntToStr(A) + ')';
end;

class function OCmoc.AssertRange(const A, ALow, AHigh: integer; const AName: string): integer;
begin
  Result := A;
  if (Result < ALow) or (Result > AHigh) then begin
    RaiseError(Format('%s is out of range (%d..%d)', [AName, ALow, AHigh]));
  end;
end;

class function OCmoc.StringQuoted(const A: string): string;
begin
  Result := '"' + A + '"';
end;

class function OCmoc.StringToInteger(const A: string): longint;
begin
  try
    if AnsiStartsStr('0x', A) then begin
      Result := StrToInt('$' + Copy(A, 3, MaxInt));
    end else begin
      Result := StrToInt(A);
    end;
  except
    RaiseError(StringQuoted(A) + ' is an invalid number');
  end;
end;

class procedure OCmoc.RaiseError(AMessage: string; const AExitCode: integer);
begin
  WriteLn('Error: ' + AMessage);
  raise ECmocException.CreateHelp(AMessage, AExitCode);
end;

class procedure OCmoc.RaiseError(AMessage, ADetails: string; const AExitCode: integer);
begin
  RaiseError(AMessage + ' -> ' + StringQuoted(ADetails), AExitCode);
end;

class function OCmoc.FileChanged(const ADst, ASrc: TFileName): boolean;
begin
  if not FileExists(ASrc) then begin
    RaiseError('Source file does not exist', ASrc);
  end;
  Result := FileAge(ADst) <= FileAge(ASrc);
end;

class function OCmoc.DosToUnix(const A: TFileName): TFileName;
begin
  Result := AnsiReplaceStr(A, '\', '/');
end;

class function OCmoc.UnixToDos(const A: TFileName): TFileName;
begin
  Result := AnsiReplaceStr(A, '/', '\');
end;

class function OCmoc.PathToPackage: TFileName;
begin
  Result := DosToUnix(ExtractFilePath(ExcludeTrailingPathDelimiter(ProgramDirectory)));
end;

class function OCmoc.PathToXRoar: TFileName;
begin
  Result := PathToPackage + 'xroar/';
end;

class function OCmoc.PathToXRoarRoms: TFileName;
begin
  Result := PathToXRoar + 'roms/';
end;

class function OCmoc.PathToVcc: TFileName;
begin
  Result := PathToPackage + 'vcc/';
end;

class function OCmoc.PathToBin: TFileName;
begin
  Result := PathToPackage + 'bin/';
end;

class function OCmoc.PathToDsk: TFileName;
begin
  Result := PathToPackage + 'dsk/';
end;

class function OCmoc.PathToLib: TFileName;
begin
  Result := PathToPackage + 'lib/';
end;

class function OCmoc.PathToSrc: TFileName;
begin
  Result := PathToPackage + 'src/';
end;

class function OCmoc.PathToSrcAsm: TFileName;
begin
  Result := PathToSrc + 'asm/';
end;

class function OCmoc.PathToSrcLib: TFileName;
begin
  Result := PathToSrc + 'lib/';
end;

class function OCmoc.PathToInclude: TFileName;
begin
  Result := PathToPackage + 'include/';
end;

var
  GPathToTemp: TFileName;

class function OCmoc.PathToTemp: TFileName;
begin
  if Length(GPathToTemp) = 0 then begin
    GPathToTemp := DosToUnix(GetTempDir(False));
  end;
  Result := GPathToTemp;
end;

class function OCmoc.FileNameTool(const ATool: string): TFileName;
begin
  Result := PathToPackage + 'bin/' + ATool + '.exe';
end;

class function OCmoc.FileNameTranslate(const A: TFileName): TFileName;
begin
  Result := A;
  Result := AnsiReplaceText(Result, '%PACKAGE%', ExtractFileDir(PathToPackage));
end;

var
  GTempCount: integer;

class function OCmoc.FileNameTemp(const APrefix, APostfix: string): TFileName;
begin
  Result := PathToTemp + APrefix + ' [' + IntToHex(GetProcessID, 0) + ',' +
    IntToHex(GTempCount, 0) + ']' + APostfix;
  Inc(GTempCount);
end;

class function OCmoc.FileNameTemp(const APostfix: string): TFileName;
begin
  Result := FileNameTemp('cmoctemp', APostfix);
end;

class function OCmoc.StringToIdent(const A: string): string;
var
  LIndex: integer;
begin
  Result := A;
  if Length(A) = 0 then begin
    RaiseError('Unable to create ident from string');
  end;
  if not (Result[1] in CharSet_IdentHead) then begin
    Result[1] := '_';
  end;
  for LIndex := 2 to Length(Result) do begin
    if not (Result[LIndex] in CharSet_IdentBody) then begin
      Result[LIndex] := '_';
    end;
  end;
end;

class function OCmoc.FileNameToIdent(const A: TFileName): string;
begin
  Result := StringToIdent(UpperCase(ExtractFileName(A)));
end;

class function OCmoc.FileNameToInitGlobals(const A: TFileName): string;
begin
  Result := Sym_INITGL + '_' + FileNameToIdent(A);
end;

class function OCmoc.SymbolIsPublic(const A: string): boolean;
begin
  Result := Length(A) >= 2;
  if Result then begin
    Result := (A[1] = '_') and (A[2] in CharSet_IdentHead) and not AnsiStartsStr('___', A);
  end;
end;

class procedure OCmoc.FileNamesAppend(var A: TStringDynArray; AFileName: string;
  const AMustExist: boolean);
var
  LFileName: TFileName;
begin
  AFileName := DosToUnix(CleanAndExpandFileName(AFileName));
  if AMustExist and not FileExists(AFileName) then begin
    RaiseError('Unable to find', AFileName);
  end;
  for LFileName in A do begin
    if SameText(LFileName, AFileName) then begin
      RaiseError('Duplicate filename', AFileName);
    end;
  end;
  OStringDynArray.Add(A, AFileName);
end;

class procedure OCmoc.StringsInsertWinCMOCHeader(const A: TStrings; const ANoDate: boolean);
begin
  A.Insert(0, EmptyStr);
  A.Insert(1, '// This file was created by WinCMOC (CMOC 6809 C Compiler for Windows)');
  if ANoDate then begin
    A.Insert(2, '//');
  end else begin
    A.Insert(2, '// Created: ' + DateTimeToStr(Now));
  end;
  A.Insert(3, '// WinCMOC:  https://sourceforge.net/projects/cmoc-win32/');
  A.Insert(4, '// CMOC:     http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html');
  A.Insert(5, EmptyStr);
end;

class procedure OCmoc.SourcePragmas(const ADst, ASrc: TStrings; var AOrigin: cardinal;
  var ATarget: string; var AOptions: string);
var
  LIndex: integer;
  LName: string;
  LParser: OAsmParser;
begin
  LParser := default(OAsmParser);
  if Assigned(ADst) then begin
    ADst.Clear;
  end;
  LIndex := 0;
  for LIndex := 0 to ASrc.Count - 1 do begin
    LParser.SetString(ASrc[LIndex]);
    if LParser.NextAndTokenIs('#') and LParser.NextAndTokenIs('pragma') and LParser.Next then begin
      LName := LParser.Token;
      case LName of
        'org': begin
          LParser.Next;
          AOrigin := OCmoc.StringToInteger(LParser.Token);
        end;
        'options': begin
          AOptions := Trim(LParser.Remaining);
        end;
        'target': begin
          LParser.Next;
          ATarget := LParser.Token;
          if not AnsiMatchStr(ATarget, TargetList) then begin
            RaiseError('Unknown target', ATarget);
          end;
        end else begin
          RaiseError('Unknown pragma name', LName);
        end;
      end;
    end else begin
      if Assigned(ADst) then begin
        ADst.Add(ASrc[LIndex]);
      end;
    end;
  end;
end;

class procedure OCmoc.SourcePragmas(const ADst, ASrc: TFileName; var AOrigin: cardinal;
  var ATarget: string; var AOptions: string);
var
  LDst, LSrc: TStrings;
begin
  LSrc := TStringList.Create;
  try
    LSrc.LoadFromFile(ASrc);
    LDst := TStringList.Create;
    try
      SourcePragmas(LDst, LSrc, AOrigin, ATarget, AOptions);
      LDst.SaveToFile(ADst);
    finally
      FreeAndNil(LDst);
    end;
  finally
    FreeAndNil(LSrc);
  end;
end;

function OAsmParser.Next: boolean;
begin
  IncludeWhile(CharSet_Space);
  ClearToken;
  if not Done then begin
    if PeekChar = '$' then begin
      IncludeChar;
      IncludeWhile(CharSet_XDigit);
    end else if PeekChar in CharSet_Digit then begin
      IncludeChar;
      if PeekChar = 'x' then begin
        IncludeChar;
        IncludeWhile(CharSet_XDigit);
      end else begin
        IncludeWhile(CharSet_Digit);
      end;
    end else if PeekChar in CharSet_SymbolHead then begin
      IncludeWhile(CharSet_SymbolBody);
    end else begin
      IncludeChar;
    end;
  end;
  Result := TokenLength > 0;
end;

function OAsmParser.NextAndTokenIs(const AToken: string): boolean;
begin
  Result := Next and SameText(AToken);
end;

constructor CCmocProcess.Create(AOwner: TComponent);
var
  LIndex: integer;
begin
  inherited;
  ShowWindow := swoHIDE;
  Options := [poUsePipes, poStderrToOutput];
  for LIndex := 0 to GetEnvironmentVariableCount - 1 do begin
    Environment.Add(GetEnvironmentString(LIndex));
  end;
  Environment.Values['path'] := OCmoc.PathToBin + PathSeparator + Environment.Values['path'];
end;

procedure CCmocProcess.CheckExitCode(const AExitCode: longint);
begin
  if AExitCode <> 0 then begin
    OCmoc.RaiseError(Format('Failed with exit code #%d', [AExitCode]), Executable, AExitCode);
  end;
end;

procedure CCmocProcess.Execute(const AExecutable: TFileName; const AParams: array of string;
  const ACurrentDirectory: TFileName);
var
  LBuffer: array[byte] of byte;
  LParam, LCommandLine: string;
begin
  LBuffer[0] := 0;
  Executable := AExecutable;
  if Length(ACurrentDirectory) > 0 then begin
    CurrentDirectory := ACurrentDirectory;
  end else begin
    CurrentDirectory := ExtractFileDir(Executable);
  end;
  Parameters.Clear;
  Parameters.AddStrings(AParams);
  LCommandLine := ChangeFileExt(ExtractFileName(Executable), default(string));
  for LParam in AParams do begin
    if PosSet(AllowDirectorySeparators + [Char_SPC], LParam) = 0 then begin
      LCommandLine += Char_SPC + LParam;
    end else begin
      LCommandLine += Char_SPC + OCmoc.StringQuoted(LParam);
    end;
  end;
  WriteLn(LCommandLine);
  try
    inherited Execute;
  except
    CheckExitCode(2);
  end;
  Sleep(20);
  while Running or (Output.NumBytesAvailable > 0) do begin
    while Output.NumBytesAvailable > 0 do begin
      FileWrite(StdOutputHandle, LBuffer, Output.Read(LBuffer, SizeOf(LBuffer)));
    end;
    Sleep(100);
  end;
  CheckExitCode(ExitCode);
end;

procedure CCmocProcess.ExecuteTool(const ATool: string; const AParams: array of string;
  const ACurrentDirectory: TFileName = default(string));
begin
  Execute(OCmoc.FileNameTool(ATool), AParams, ACurrentDirectory);
end;

procedure CCmocProcess.ExecuteTool_ASTYLE(const ADst, ASrc: TFileName; const ATabWidth: integer);
var
  LIndex, LSep: integer;
  LChar: char;
  LPos: pchar;
  LLine: string;
begin
  ExecuteTool(Tool_ASTYLE, ['-A8', '-xC100', '-k1', '-w', '-U', '-H', '-j',
    '-s' + IntToStr(ATabWidth), ASrc]);
  with TStringList.Create do begin
    try
      LoadFromFile(ASrc);
      while (Count > 0) and (Length(Trim(Strings[0])) = 0) do begin
        Delete(0);
      end;
      while (Count > 0) and (Length(Trim(Strings[Count - 1])) = 0) do begin
        Delete(Count - 1);
      end;
      Insert(0, default(string));
      for LIndex := 0 to Count - 1 do begin
        LLine := Strings[LIndex];
        LPos := PChar(LLine);
        while LPos[0] in [#1..#32] do begin
          Inc(LPos);
        end;
        if (LPos[0] <> '/') or (LPos[1] <> '/') then begin
          while (LPos[0] <> #0) and ((LPos[0] <> '/') or (LPos[1] <> '/')) do begin
            LChar := LPos[0];
            if LChar in ['"', ''''] then begin
              repeat
                Inc(LPos);
                if (LPos[0] = LChar) and (LPos[-1] = '\') then begin
                  Inc(LPos);
                end;
              until (LPos[0] = #0) or (LPos[0] = LChar);
            end;
            Inc(LPos);
          end;
          if (LPos[-1] = ' ') and (LPos[0] = '/') then begin
            LSep := LPos - PChar(LLine) + 1;
            Strings[LIndex] := PadRight(TrimRight(Copy(LLine, 1, LSep - 1)), 47) + #32 +
              Copy(LLine, LSep, MaxInt);
          end;
        end;
      end;
      SaveToFile(ADst);
    finally
      Free;
    end;
  end;
end;

end.
