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

unit UCmocProcess_CMOC2;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, FileUtil, LazFileUtils, StrUtils, SysUtils, Types, UCmocProcess_ASM, UCmocUtils;

type

  CCmocProcess_CMOC2 = class(CCmocProcess_ASM)
  strict private
    FOutFile: TFileName;
    FDontAssemble, FDontLink, FVerbose, FWerror: boolean;
    FSrcFiles, FAsmFiles, FObjFiles: TFileNames;
  public
    constructor Create(AOwner: TComponent); override;
  strict private
    procedure SetOutFile(const AFileName: TFileName);
    procedure AddInputFile(AFileName: TFileName; const AMustExist: boolean);
  strict private
    procedure ParseCommandLine;
  strict private
    procedure DoCompile(const ADst, ASrc: TFileName; const AInitGL: string);
    procedure DoAssemble(const ADst, ASrc: TFileName);
    procedure DoCompileAssemble(const AObj, AAsm, ASrc: TFileName);
    procedure DoCompileAssembleAll;
    procedure DoLink;
  public
    procedure DoBuild;
  end;

implementation

constructor CCmocProcess_CMOC2.Create(AOwner: TComponent);
begin
  inherited;
  FTarget := Target_COCO;
  FOrigin := Origin_DEFAULT;
end;

procedure CCmocProcess_CMOC2.SetOutFile(const AFileName: TFileName);
begin
  if Length(FOutFile) <> 0 then begin
    OCmoc.RaiseError('Output file has already been selected', AFileName);
  end;
  FOutFile := OCmoc.DosToUnix(CleanAndExpandFileName(AFileName));
  case ExtractFileExt(AFileName) of
    FileExt_O: begin
      FDontLink := True;
    end;
    FileExt_BIN, FileExt_A: begin
    end else begin
      OCmoc.RaiseError('Unknown output file type', AFileName);
    end;
  end;
end;

procedure CCmocProcess_CMOC2.AddInputFile(AFileName: TFileName; const AMustExist: boolean);
var
  LSearchRec: TSearchRec;
begin
  AFileName := CleanAndExpandFileName(AFileName);
  if PosSet(['*', '?'], AFileName) > 0 then begin
    if FindFirst(AFileName, 0, LSearchRec) = 0 then begin
      try
        repeat
          if LSearchRec.Name[1] <> '.' then begin
            AddInputFile(ExtractFilePath(AFileName) + LSearchRec.Name, AMustExist);
          end;
        until FindNext(LSearchRec) <> 0;
      finally
        FindClose(LSearchRec);
      end;
    end;
  end else begin
    case ExtractFileExt(AFileName) of
      FileExt_O: begin
        OCmoc.FileNamesAppend(FObjFiles, AFileName, AMustExist);
      end;
      FileExt_C: begin
        OCmoc.FileNamesAppend(FSrcFiles, AFileName, AMustExist);
      end else begin
        OCmoc.RaiseError('Unknown file type', AFileName);
      end;
    end;
  end;
end;

procedure CCmocProcess_CMOC2.ParseCommandLine;
var
  LIndex: integer;
  LParam, LValue: string;
begin
  LIndex := 1;
  while LIndex <= ParamCount do begin
    LParam := ParamStr(LIndex);
    if AnsiStartsStr('-', LParam) then begin
      case LParam of
        Opt_Format2, Opt_Target2, Opt_Output2, Opt_Origin2: begin
          if LIndex = ParamCount then begin
            OCmoc.RaiseError('Option missing value', LParam);
          end;
          Inc(LIndex);
          LValue := ParamStr(LIndex);
          case LParam of
            Opt_Origin2: begin
              FOrigin := OCmoc.StringToInteger(LValue);
            end;
            Opt_Target2: begin
              FTarget := LValue;
              if not AnsiMatchStr(FTarget, TargetList) then begin
                OCmoc.RaiseError('Unknown target type', FTarget);
              end;
            end;
            Opt_Output2: begin
              SetOutFile(LValue);
            end;
          end;
        end else begin
          case LParam of
            Opt_Werror1: begin
              FWerror := True;
            end;
            Opt_Verbose1: begin
              FVerbose := True;
            end;
            Opt_DontAssemble1: begin
              FDontAssemble := True;
              FDontLink := True;
            end;
            Opt_DontLink1: begin
              FDontLink := True;
            end else begin
              OCmoc.RaiseError('Unknown option', LParam);
            end;
          end;
        end;
      end;
    end else begin
      AddInputFile(LParam, True);
    end;
    Inc(LIndex);
  end;
  if (Length(FSrcFiles) = 0) and (Length(FObjFiles) = 0) then begin
    OCmoc.RaiseError('No input files', 'cmoc2');
  end;
  if Length(FOutFile) = 0 then begin
    SetOutFile('a' + FileExt_BIN);
  end;
end;

procedure CCmocProcess_CMOC2.DoCompile(const ADst, ASrc: TFileName; const AInitGL: string);
var
  LTmp: TFileName;
begin
  LTmp := OCmoc.FileNameTemp(FileExt_ASM);
  try
    CMOC(LTmp, ASrc, FWerror, FVerbose);
    CMOC2(ADst, LTmp, AInitGL);
    OCmoc.FileNamesAppend(FAsmFiles, ADst, True);
  finally
    DeleteFile(LTmp);
  end;
end;

procedure CCmocProcess_CMOC2.DoAssemble(const ADst, ASrc: TFileName);
begin
  LWASM(ADst, ASrc, True);
  OCmoc.FileNamesAppend(FObjFiles, ADst, True);
end;

procedure CCmocProcess_CMOC2.DoCompileAssemble(const AObj, AAsm, ASrc: TFileName);
begin
  DoCompile(AAsm, ASrc, OCmoc.FileNameToInitGlobals(AObj));
  if not FDontAssemble then begin
    DoAssemble(AObj, AAsm);
  end;
end;

procedure CCmocProcess_CMOC2.DoCompileAssembleAll;
var
  LSrcFile: TFileName;
begin
  case ExtractFileExt(FOutFile) of
    FileExt_ASM: begin
      if Length(FSrcFiles) <> 1 then begin
        OCmoc.RaiseError('Only one source file can be selected', FOutFile);
      end;
      DoCompile(FOutFile, FSrcFiles[0], OCmoc.FileNameToInitGlobals(
        ChangeFileExt(FOutFile, FileExt_O)));
    end;
    FileExt_O: begin
      if Length(FSrcFiles) <> 1 then begin
        OCmoc.RaiseError('Only one source file can be selected', FOutFile);
      end;
      DoCompileAssemble(FOutFile, ChangeFileExt(FSrcFiles[0], FileExt_ASM), FSrcFiles[0]);
    end else begin
      for LSrcFile in FSrcFiles do begin
        DoCompileAssemble(ChangeFileExt(LSrcFile, FileExt_O), ChangeFileExt(LSrcFile,
          FileExt_ASM), LSrcFile);
      end;
    end;
  end;
end;

procedure CCmocProcess_CMOC2.DoLink;
begin
  if not FDontLink then begin
    case ExtractFileExt(FOutFile) of
      FileExt_A: begin
        LWAR(Opt_Create1, FOutFile, FObjFiles);
      end;
      FileExt_BIN: begin
        LWLINK(FOutFile, FObjFiles, FTarget, FOrigin);
      end else begin
        OCmoc.RaiseError('Unable to link to file type', FOutFile);
      end;
    end;
  end;
end;

procedure CCmocProcess_CMOC2.DoBuild;
var
  LSayings: TStringDynArray;
begin
  ParseCommandLine;
  DoCompileAssembleAll;
  DoLink;
  LSayings := TStringDynArray.Create('Woo hoo', 'zipple wanoo', 'are you wearing my pants?',
    'you look funnier than my left nostrel', 'carrots are for mice',
    'today im riding the cannon', 'horses smell like uncle betty',
    'one day you will look as hansom as me', 'frogs are just little boogers with legs',
    'my hair feels like jam donuts', 'squeeze my nose before I get angry',
    'sunshine is clown makeups worst enermy', 'friday I eat chicken. Is it friday?',
    'one day ill be smarter than I think', 'will you be my daddy',
    'give me youre money or Ill date your mum', 'fuzzy orange hair is the shizz!',
    'all the other clowns at clown school kept kicking my bottom',
    'smell my flower', 'Bobo is my mothers aunty',
    'if it were not for my socks, id look normal');
  Randomize;
  WriteLn('# Coco the clown says ' + LSayings[Random(Length(LSayings))]);
end;

end.
