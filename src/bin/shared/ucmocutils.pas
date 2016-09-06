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

type
  ECmocException = EAbort;

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
  FileExt_ROM = '.rom';
  FileExt_WAV = '.wav';
  FileExt_CAS = '.cas';
  FileExt_BIN = '.bin';
  FileExt_ASM = '.asm';
  FileExt_EXE = '.exe';
  FileExt_RAW = '.raw';
  FileExt_SREC = '.srec';

  Tool_CMOC = 'cmoc';
  Tool_CMOC2 = 'cmoc2';
  Tool_MCPP = 'mcpp';
  Tool_LWASM = 'lwasm';
  Tool_LWASM2 = 'lwasm2';
  Tool_LWLINK = 'lwlink';
  Tool_LWAR = 'lwar';
  Tool_ASTYLE = 'astyle';
  Tool_WIMGTOOL = 'wimgtool';
  Tool_CMOCIDE = 'cmocide';
  Tool_F9DASM = 'f9dasm';

  Origin_DEFAULT = $2800;

  Target_COCO = 'coco';
  Target_DRAGON = 'dragon';

  Machine_COCOUS = 'cocous';
  Machine_COCO3 = 'coco3';
  Machine_DRAGON64 = 'dragon64';

  Format_OBJ = 'obj';
  Format_RAW = 'raw';
  Format_DECB = 'decb';
  Format_SREC = 'srec';
  Format_WAV = 'wav';
  Format_CAS = 'cas';

  Opt_ScriptFile2 = '-s';
  Opt_MapFile2 = '-m';
  Opt_6809 = '--6809';
  Opt_6800compat = '--6800compat';
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
  Opt_NoAddr1 = '-noaddr';
  Opt_Out2 = '-out';
  Opt_Verbose1 = '-V';
  Opt_Werror1 = '-Werror';
  Opt_NoLineInfo1 = '-P';
  Opt_DontAssemble1 = '-S';
  Opt_Machine2 = '-machine';
  Opt_NoTapeFast1 = '-no-tape-fast';
  Opt_NoDos1 = '-nodos';
  Opt_NoExtBas1 = '-noextbas';
  Opt_Offset2 = '-offset';
  Opt_Cart2 = '-cart';
  Opt_Bas2 = '-bas';
  Opt_Ram2 = '-ram';
  Opt_ExtBas2 = '-extbas';
  Opt_Dos2 = '-dos';
  Opt_Type2 = '-type';
  Opt_Load2 = '-load';
  Opt_NoCode1 = '-nocode';
  Opt_NoMaximize1 = '-nomaximize';

  Def_CMOC = '__CMOC__';
  Def_CMOC_VERSION = Def_CMOC + '=1.30';
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
    class procedure StringDynArrayAppend(var A: TStringDynArray; const S: string);
    class procedure StringDynArrayInsert(var A: TStringDynArray; const I: integer;
      const S: string);
    class procedure StringDynArrayAppendStrings(var A: TStringDynArray;
      const AStrings: array of string);
    class procedure StringDynArrayAppendLib(var A: TStringDynArray; const AName: string);
    class procedure StringDynArrayAppendLibs(var A: TStringDynArray);
    class procedure StringDynArrayAppendOptions(var A: TStringDynArray;
      const AOptions: TStrings; const AInclude: array of string);
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
  Result := AnsiStartsStr('_', A) and not AnsiStartsStr('___', A);
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

class procedure OCmoc.StringDynArrayAppendStrings(var A: TStringDynArray;
  const AStrings: array of string);
var
  LString: string;
begin
  for LString in AStrings do begin
    StringDynArrayAppend(A, LString);
  end;
end;

class procedure OCmoc.StringDynArrayAppendLib(var A: TStringDynArray; const AName: string);
begin
  StringDynArrayAppend(A, Opt_LibInclude2);
  StringDynArrayAppend(A, AName);
end;

class procedure OCmoc.StringDynArrayAppendLibs(var A: TStringDynArray);
begin
  StringDynArrayAppendLib(A, 'disk');
  StringDynArrayAppendLib(A, 'motorola');
  StringDynArrayAppendLib(A, 'cmoc');
  StringDynArrayAppendLib(A, 'lzss');
  StringDynArrayAppendLib(A, 'exomizer');
  StringDynArrayAppendLib(A, 'varptr');
  StringDynArrayAppendLib(A, '6809');
  StringDynArrayAppendLib(A, 'basic');
  StringDynArrayAppendLib(A, 'charset');
  StringDynArrayAppendLib(A, 'graph');
  StringDynArrayAppendLib(A, 'conio');
  StringDynArrayAppendLib(A, 'unistd');
  StringDynArrayAppendLib(A, 'ctype');
  StringDynArrayAppendLib(A, 'string');
  StringDynArrayAppendLib(A, 'c');
end;

class procedure OCmoc.StringDynArrayAppendOptions(var A: TStringDynArray;
  const AOptions: TStrings; const AInclude: array of string);
var
  LIndex, LPos: integer;
  LName, LValue: string;
  LValues: TStrings;
begin
  LValues := TStringList.Create;
  try
    for LIndex := 0 to AOptions.Count - 1 do begin
      LName := Trim(AOptions[LIndex]);
      LPos := Pos('=', LName);
      if LPos = 0 then begin
        LPos := Length(LName) + 1;
      end;
      LValue := Trim(Copy(LName, LPos + 1, MaxInt));
      LName := Trim(Copy(LName, 1, LPos - 1));
      if AnsiMatchText(LName, AInclude) then begin
        if Length(LValue) = 0 then begin
          StringDynArrayAppend(A, LName);
        end else begin
          LValues.CommaText := LValue;
          for LValue in LValues do begin
            StringDynArrayAppend(A, LName);
            if Length(LValue) > 0 then begin
              StringDynArrayAppend(A, LValue);
            end;
          end;
        end;
      end;
    end;
  finally
    FreeAndNil(LValues);
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
  StringDynArrayAppend(A, AFileName);
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
begin
  inherited;
  ShowWindow := swoHIDE;
  Options := [poUsePipes, poStderrToOutput];
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
          if LPos[0] = '/' then begin
            LSep := LPos - PChar(LLine) + 1;
            Strings[LIndex] := PadRight(TrimRight(Copy(LLine, 1, LSep - 1)), 43) + #32 +
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
