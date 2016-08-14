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

unit UCmocProcess_TOOLS;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, StrUtils, SysUtils, Types, UCmocAsm, UCmocUtils;

type

  CCmocProcess_TOOLS = class(CCmocProcess)
  public
    FOrigin: cardinal;
    FTarget: string;
  strict private
    procedure LWLINK(const ADst, ASrc, AMap: TFileName; const ATarget: string);
  protected
    procedure MCCP(const ADst, ASrc: TFileName; AParams: TStringDynArray);
    procedure CMOC(const ADst, ASrc: TFileName; const AWerror, AVerbose: boolean);
    procedure LWAR(const AMode: string; const ADst: TFileName; ASrc: TFileNames);
    procedure LWASM(const ADst, ASrc: TFileName; const APreprocess: boolean);
    procedure LWLINK(const ADst: TFileName; const ASrc: TFileNames;
      const ATarget: string; const AOrigin: cardinal);
  public
    function LWASM_INITGL(const AMapFile: TFileName): TFileName;
  end;

implementation

procedure CCmocProcess_TOOLS.MCCP(const ADst, ASrc: TFileName; AParams: TStringDynArray);
begin
  if OCMOC.FileChanged(ADst, ASrc) then begin
    OCMOC.StringDynArrayInsert(AParams, 0, Opt_Output2);
    OCMOC.StringDynArrayInsert(AParams, 1, ADst);
    OCMOC.StringDynArrayInsert(AParams, 2, Opt_NoLineInfo1);
    OCMOC.StringDynArrayInsert(AParams, 3, '-a');
    OCMOC.StringDynArrayAppend(AParams, ASrc);
    Execute(OCMOC.FileNameTool(Tool_MCPP), AParams);
  end;
end;

procedure CCmocProcess_TOOLS.CMOC(const ADst, ASrc: TFileName; const AWerror, AVerbose: boolean);
var
  LPre: TFileName;
  LParams: TStringDynArray;
begin
  if OCMOC.FileChanged(ADst, ASrc) then begin
    LPre := ASrc + FileExt_I;

    MCCP(LPre, ASrc, TStringDynArray.Create(Opt_Define2,
      Def_CMOC_VERSION, Opt_Define2, Def_6809, Opt_Define2, '__' + UpperCase(FTarget) + '__',
      Opt_Define2, 'const=', Opt_Define2, '__fastcall__=', Opt_Define2,
      'long=int', Opt_Define2, 'restrict=', Opt_Include2,
      OCMOC.DosToUnix(OCMOC.PathToPackage + 'include')));

    OCMOC.ExtractPragmas(LPre, LPre, FOrigin, FTarget);

    LParams := TStringDynArray.Create(Opt_EmitUncalled1, Opt_DontLink1);
    if AWerror then begin
      OCMOC.StringDynArrayAppend(LParams, Opt_Werror1);
    end;
    if AVerbose then begin
      OCMOC.StringDynArrayAppend(LParams, Opt_Verbose1);
    end;
    //StringDynArrayAppend(LParams, Opt_Optimize0);
    OCMOC.StringDynArrayAppend(LParams, ExtractFileName(LPre));
    Execute(OCMOC.FileNameTool(Tool_CMOC), LParams, ExtractFilePath(LPre));
    DeleteFile(ADst);
    RenameFile(LPre + FileExt_ASM, ADst);
  end;
end;

function CCmocProcess_TOOLS.LWASM_INITGL(const AMapFile: TFileName): TFileName;
var
  LPos, LEnd: integer;
  LTmpFile: TFileName;
  LString, LSymbol: string;
  LAsmFile, LMapFile: TStringList;
begin
  LTmpFile := OCMOC.FileNameTemp(Sym_INITGL, FileExt_ASM);
  Result := ChangeFileExt(LTmpFile, FileExt_O);
  try
    LMapFile := TStringList.Create;
    try
      LMapFile.LoadFromFile(AMapFile);
      LAsmFile := TStringList.Create;
      try
        LAsmFile.Add(Asm_SECTION);
        LAsmFile.Add(Asm_EXPORT(Sym_INITGL));
        LAsmFile.Add(Asm_SYMBOL(Sym_INITGL));
        for LString in LMapFile do begin
          LPos := Pos(Char_SPC + Sym_INITGL + '_', LString) + 1;
          if LPos > 1 then begin
            LEnd := PosEx(Char_SPC, LString, LPos);
            if LEnd > 0 then begin
              LSymbol := Copy(LString, LPos, LEnd - LPos);
              LAsmFile.Add(Asm_EXTERN(LSymbol));
              LAsmFile.Add(Char_TAB + 'LBSR' + Char_TAB + LSymbol);
            end;
          end;
        end;
        LAsmFile.Add(Char_TAB + 'RTS');
        LAsmFile.Add(Asm_ENDSECTION);
        LAsmFile.SaveToFile(LTmpFile);
        LWASM(Result, LTmpFile, False);
      finally
        FreeAndNil(LAsmFile);
      end;
    finally
      FreeAndNil(LMapFile);
    end;
  finally
    DeleteFile(LTmpFile);
  end;
end;

procedure CCmocProcess_TOOLS.LWAR(const AMode: string; const ADst: TFileName; ASrc: TFileNames);
begin
  OCMOC.StringDynArrayInsert(ASrc, 0, AMode);
  OCMOC.StringDynArrayInsert(ASrc, 1, ADst);
  Execute(OCMOC.FileNameTool(Tool_LWAR), ASrc);
end;

procedure CCmocProcess_TOOLS.LWASM(const ADst, ASrc: TFileName; const APreprocess: boolean);
begin
  if OCMOC.FileChanged(ADst, ASrc) then begin
    Execute(OCMOC.FileNameTool(IfThen(APreprocess, Tool_LWASM2, Tool_LWASM)),
      TStringDynArray.Create(Opt_6809, Opt_Format2, Format_OBJ, Opt_Output2, ADst, ASrc));
  end;
end;

procedure CCmocProcess_TOOLS.LWLINK(const ADst, ASrc, AMap: TFileName; const ATarget: string);
var
  LSrcLib: string;
begin
  if OCMOC.FileChanged(ADst, ASrc) then begin
    LSrcLib := Copy(ChangeFileExt(ExtractFileName(ASrc), EmptyStr), 4, MaxInt);

    Execute(OCMOC.FileNameTool(Tool_LWLINK), TStringDynArray.Create(Opt_Output2, ADst, Opt_Format2,
      Format_DECB, Opt_LibPath2, OCMOC.PathToLib, Opt_LibPath2, ExtractFilePath(ASrc),
      Opt_LibInclude2, LSrcLib, Opt_LibInclude2, ATarget, Opt_LibInclude2,
      '6809', Opt_LibInclude2, 'basic', Opt_LibInclude2, 'c', Opt_ScriptFile2,
      OCMOC.PathToLib + 'linkscript.txt', Opt_MapFile2, AMap, OCMOC.PathToLib +
      'program_start.o', OCMOC.PathToLib + 'program_end.o'));
  end;
end;

procedure CCmocProcess_TOOLS.LWLINK(const ADst: TFileName; const ASrc: TFileNames;
  const ATarget: string; const AOrigin: cardinal);
var
  LLibFile, LMapFile, LObjFile: TFileName;
begin
  LLibFile := OCMOC.FileNameTemp('libmain', FileExt_A);
  try
    LWAR(Opt_Create1, LLibFile, ASrc);
    LMapFile := OCMOC.FileNameTemp('lwlinkmap', '.txt');
    try
      LWLINK(ADst, LLibFile, LMapFile, ATarget);
      LObjFile := LWASM_INITGL(LMapFile);
      try
        LWAR(Opt_Add1, LLibFile, TFileNames.Create(LObjFile));
        LWLINK(ADst, LLibFile, LMapFile, ATarget);
      finally
        DeleteFile(LObjFile);
      end;
    finally
      DeleteFile(LMapFile);
    end;
  finally
    DeleteFile(LLibFile);
  end;
  WriteLn('ORIGIN: $', IntToHex(AOrigin, 4));
  with TMemoryStream.Create do begin
    try
      LoadFromFile(ADst);
      if Size >= 10 then begin
        PByte(Memory)[3] := byte(AOrigin shr 8);
        PByte(Memory)[4] := byte(AOrigin);
        PByte(Memory)[Size - 2] := byte(AOrigin shr 8);
        PByte(Memory)[Size - 1] := byte(AOrigin);
        SaveToFile(ADst);
      end;
    finally
      Free;
    end;
  end;
end;

end.
