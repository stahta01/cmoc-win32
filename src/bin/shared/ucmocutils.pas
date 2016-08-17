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
  Classes, FileUtil, LazFileUtils, Process, StrUtils, SysUtils, Types, UCmocParser;

const

  Char_SPC = char(#32);
  Char_TAB = char(#9);

  CharSet_Space = [#0..#32, #127..#255];
  CharSet_Alpha = ['a'..'z', 'A'..'Z'];
  CharSet_Digit = ['0'..'9'];
  CharSet_XDigit = CharSet_Digit + ['a'..'f', 'A'..'F'];
  CharSet_IdentHead = CharSet_Alpha + ['_'];
  CharSet_IdentBody = CharSet_IdentHead + CharSet_Digit;
  CharSet_SymbolHead = CharSet_IdentHead + ['.'];
  CharSet_SymbolBody = CharSet_IdentBody + ['.', '$'];

  FileExt_O = '.o';
  FileExt_I = '.i';
  FileExt_OBJ = '.obj';
  FileExt_C = '.c';
  FileExt_A = '.a';
  FileExt_BIN = '.bin';
  FileExt_ASM = '.asm';
  FileExt_EXE = '.exe';

  Tool_CMOC = 'cmoc';
  Tool_CMOC2 = 'cmoc2';
  Tool_MCPP = 'mcpp';
  Tool_LWASM = 'lwasm';
  Tool_LWASM2 = 'lwasm2';
  Tool_LWLINK = 'lwlink';
  Tool_LWAR = 'lwar';
  Tool_ASTYLE = 'astyle';

  Origin_DEFAULT = $2800;

  Target_COCO = 'coco';
  Target_DRAGON = 'dragon';

  Format_OBJ = 'obj';
  Format_RAW = 'raw';
  Format_DECB = 'decb';

  Opt_ScriptFile2 = '-s';
  Opt_MapFile2 = '-m';
  Opt_6809 = '--6809';
  Opt_DontLink1 = '-c';
  Opt_Create1 = '--create';
  Opt_Add1 = '--add';
  Opt_Define2 = '-D';
  Opt_EmitUncalled1 = '--emit-uncalled';
  Opt_Entry2 = '-e';
  Opt_Format2 = '-f';
  Opt_Help1 = '--help';
  Opt_Include2 = '-I';
  Opt_Optimize0 = '-O0';
  Opt_Origin2 = '--org';
  Opt_LibPath2 = '-L';
  Opt_LibInclude2 = '-l';
  Opt_Output2 = '-o';
  Opt_Target2 = '-t';
  Opt_Verbose1 = '-V';
  Opt_Werror1 = '-Werror';
  Opt_NoLineInfo1 = '-P';
  Opt_DontAssemble1 = '-S';

  Def_CMOC = '__CMOC__';
  Def_CMOC_VERSION = Def_CMOC + '=1.28';
  Def_DATE = '__DATE__';
  Def_FILE = '__FILE__';
  Def_6809 = '__6809__';

  Sym_ProgramStart = 'program_start';
  Sym_ProgramEnd = 'program_end';
  Sym_FunctionsStart = 'functions_start';
  Sym_WritableGlobalsStart = 'writable_globals_start';
  Sym_INITGL = 'INITGL';
  Sym_INITLIB = 'INITLIB';

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
    procedure Execute(const AExecutable: TFileName; const AParams: TStringDynArray;
      const ACurrentDirectory: TFileName); reintroduce;
    procedure Execute(const AExecutable: TFileName; const AParams: TStringDynArray);
  end;

var

  TargetList: array[0..4] of string = ('coco', 'dragon', 'os9', 'flex', 'vectrex');

type

  OCmoc = object
  strict private
    class function PathToTemp: TFileName;
  public
  const
    _UrlCmoc = 'http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html';
    _UrlWinCmoc = 'https://sourceforge.net/projects/cmoc-win32/';
    _UrlFatCowFreeIcons = 'http://www.fatcow.com/free-icons';
  public
    class function DosToUnix(const A: TFileName): TFileName;
    class function UnixToDos(const A: TFileName): TFileName;
    class function FileChanged(const ADst, ASrc: TFileName): boolean;
    class function FileNameTemp(const APostfix: string): TFileName;
    class function FileNameTemp(const APrefix, APostfix: string): TFileName;
    class function FileNameToIdent(const A: TFileName): string;
    class function FileNameToInitGlobals(const A: TFileName): string;
    class function FileNameTool(const ATool: string): TFileName;
    class function PathToInclude: TFileName;
    class function PathToLib: TFileName;
    class function PathToPackage: TFileName;
    class function PathToXroar: TFileName;
    class function PathToXroarRoms: TFileName;
    class function PathToSrc: TFileName;
    class function PathToSrcAsm: TFileName;
    class function PathToSrcLib: TFileName;
    class function StringQuoted(const A: string): string;
    class function StringToIdent(const A: string): string;
    class function StringToInteger(const A: string): longint;
    class function SymbolIsPublic(const A: string): boolean;
    class procedure ExtractPragmas(const ADst, ASrc: TFileName; var AOrigin: cardinal;
      var ATarget: string);
    class procedure ExtractPragmas(const ADst, ASrc: TStrings; out AOrigin: cardinal;
      out ATarget: string);
    class procedure FileNamesAppend(var A: TStringDynArray; AFileName: TFileName;
      const AMustExist: boolean);
    class procedure RaiseError(AMessage, ADetails: string; const AExitCode: integer = -1);
    class procedure RaiseError(AMessage: string; const AExitCode: integer = -1);
    class procedure StringDynArrayAppend(var A: TStringDynArray; const S: string);
    class procedure StringDynArrayInsert(var A: TStringDynArray; const I: integer;
      const S: string);
  end;

implementation

class function OCmoc.StringQuoted(const A: string): string;
begin
  Result := '"' + A + '"';
end;

class function OCmoc.StringToInteger(const A: string): longint;
begin
  if AnsiStartsStr('0x', A) then begin
    Result := StrToInt('$' + Copy(A, 3, MaxInt));
  end else begin
    Result := StrToInt(A);
  end;
end;

class procedure OCmoc.RaiseError(AMessage: string; const AExitCode: integer);
begin
  WriteLn('Error: ' + AMessage);
  raise EAbort.CreateHelp(AMessage, AExitCode);
end;

class procedure OCmoc.RaiseError(AMessage, ADetails: string; const AExitCode: integer);
begin
  RaiseError(AMessage + ' # ' + StringQuoted(ADetails), AExitCode);
end;

class function OCmoc.FileChanged(const ADst, ASrc: TFileName): boolean;
begin
  if not FileExists(ASrc) then begin
    RaiseError('Source file does not exist', ASrc);
  end;
  Result := FileAge(ADst) <= FileAge(ASrc);
end;

class procedure OCmoc.StringDynArrayAppend(var A: TStringDynArray; const S: string);
begin
  SetLength(A, Length(A) + 1);
  A[High(A)] := S;
end;

class procedure OCmoc.StringDynArrayInsert(var A: TStringDynArray; const I: integer;
  const S: string);
var
  LIndex: integer;
begin
  SetLength(A, Length(A) + 1);
  for LIndex := High(A) - 1 downto I do begin
    A[LIndex + 1] := A[LIndex];
  end;
  A[I] := S;
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
  StringDynArrayAppend(A, AFileName);
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

class function OCmoc.PathToXroar: TFileName;
begin
  Result := PathToPackage + 'xroar/';
end;

class function OCmoc.PathToXroarRoms: TFileName;
begin
  Result := PathToXroar + 'roms/';
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
  Result := AnsiStartsStr('_', A) and not AnsiStartsStr('___', A);
end;

class procedure OCmoc.ExtractPragmas(const ADst, ASrc: TStrings; out AOrigin: cardinal;
  out ATarget: string);
var
  LIndex: integer;
  LName: string;
  LParser: OAsmParser;
begin
  LParser := default(OAsmParser);
  ATarget := Target_COCO;
  AOrigin := Origin_DEFAULT;
  if Assigned(ADst) then begin
    ADst.Clear;
  end;
  LIndex := 0;
  for LIndex := 0 to ASrc.Count - 1 do begin
    LParser.SetString(ASrc[LIndex]);
    if LParser.NextAndTokenIs('#') and LParser.NextAndTokenIs('pragma') and LParser.Next then begin
      LName := LParser.Token;
      if not LParser.Next then begin
        RaiseError('missing pragma value');
      end;
      case LName of
        'org': begin
          AOrigin := OCmoc.StringToInteger(LParser.Token);
        end;
        'target': begin
          ATarget := LParser.Token;
          if not AnsiMatchStr(ATarget, TargetList) then begin
            RaiseError('Unknown target', ATarget);
          end;
        end else begin
          RaiseError('Unknown pragma name');
        end;
      end;
    end else begin
      if Assigned(ADst) then begin
        ADst.Add(ASrc[LIndex]);
      end;
    end;
  end;
end;

class procedure OCmoc.ExtractPragmas(const ADst, ASrc: TFileName; var AOrigin: cardinal;
  var ATarget: string);
var
  LDst, LSrc: TStrings;
begin
  LSrc := TStringList.Create;
  try
    LSrc.LoadFromFile(ASrc);
    LDst := TStringList.Create;
    try
      ExtractPragmas(LDst, LSrc, AOrigin, ATarget);
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
begin
  inherited;
  ShowWindow := swoHIDE;
  Options := [poUsePipes, poStderrToOutput];
end;

procedure CCmocProcess.Execute(const AExecutable: TFileName; const AParams: TStringDynArray;
  const ACurrentDirectory: TFileName);
var
  LBuffer: array[byte] of byte;
  LParam, LCommandLine: string;
begin
  LBuffer[0] := 0;
  Executable := AExecutable;
  CurrentDirectory := ACurrentDirectory;
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
    CheckExitCode(-1);
  end;
  Sleep(20);
  while (Running or (Output.NumBytesAvailable > 0)) do begin
    while Output.NumBytesAvailable > 0 do begin
      FileWrite(StdOutputHandle, LBuffer, Output.Read(LBuffer, SizeOf(LBuffer)));
    end;
    Sleep(100);
  end;
  CheckExitCode(ExitCode);
end;

procedure CCmocProcess.Execute(const AExecutable: TFileName; const AParams: TStringDynArray);
begin
  Execute(AExecutable, AParams, ExtractFileDir(AExecutable));
end;

procedure CCmocProcess.CheckExitCode(const AExitCode: longint);
begin
  if AExitCode <> 0 then begin
    OCmoc.RaiseError(Format('Failed with exit code #%d', [AExitCode]), Executable, AExitCode);
  end;
end;

end.
