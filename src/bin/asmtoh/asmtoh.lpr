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

program asmtoh;

{$INCLUDE cmoc.inc}

uses
  Classes,
  StrUtils,
  SysUtils,
  Types,
  UCmocUtils;

{$R *.res}

type

  CCmocProcess_ASMTOH = class(CCmocProcess)
  public
    procedure ProcessFile(const ADst, ASrc: TStrings; const AFileName: TFileName);
    procedure ProcessFile(const ADst, ASrc: TFileName);
  end;

  procedure CCmocProcess_ASMTOH.ProcessFile(const ADst, ASrc: TStrings;
  const AFileName: TFileName);

    procedure LDefine(const AName, AValue: string);
    begin
      ADst.Add('#ifndef ' + AName);
      ADst.Add(Format('#define %s %s', [AName, AValue]));
      ADst.Add('#endif');
    end;

  var
    LValue, LSize: integer;
    LLine, LIdent, LComment: string;
    LParser: OAsmParser;
  begin
    ADst.Add('#ifndef _' + OCMOC.FileNameToIdent(AFileName));
    ADst.Add('#define _' + OCMOC.FileNameToIdent(AFileName) + LineEnding);

    for LLine in ASrc do begin
      LParser.SetString('$' + Trim(LLine));
      if LParser.Next and TryStrToInt(LParser.Token, LValue) and
        LParser.NextAndTokenIs('(') then begin
        LParser.IncludeUntil([')']);
        if LParser.NextAndTokenIs(')') and LParser.NextAndTokenIs(':') and
          LParser.Next and LParser.Next then begin
          LIdent := OCMOC.StringToIdent('_' + UpperCase(LParser.Token));
          if LParser.Next then begin
            LSize := -1;
            if LParser.SameText('EQU') or LParser.SameText('RMB') then begin
              if LParser.SameText('EQU') then begin
                if LParser.Next then begin
                  LParser.IncludeUntil(CharSet_Space);
                end;
              end else if LParser.SameText('RMB') then begin
                if LParser.Next then begin
                  LSize := StrToIntDef(LParser.Token, 0);
                end;
              end;
              LComment := Trim(LParser.Remaining);
              if Length(LComment) > 0 then begin
                ADst.Add(Format('/* %s */', [TrimSet(LParser.Remaining, [#0..#32, '*', ';'])]));
              end;
              LDefine(LIdent, IntToStr(LValue));
              if LSize >= 0 then begin
                if LSize = 1 then begin
                  LDefine(LowerCase(LIdent), '*((unsigned char*)' + LIdent + ')');
                end else if LSize = 2 then begin
                  LDefine(LowerCase(LIdent), '*((unsigned*)' + LIdent + ')');
                end else begin
                  LDefine(LowerCase(LIdent), '((char*)' + LIdent + ')');
                end;
              end;
              ADst.Add(EmptyStr);
            end;
          end;
        end;
      end;
    end;
    ADst.Add(LineEnding + '#endif');
  end;

  procedure CCmocProcess_ASMTOH.ProcessFile(const ADst, ASrc: TFileName);
  var
    LSrc, LDst: TStrings;
  begin
    LSrc := TStringList.Create;
    try
      LSrc.LoadFromFile(ASrc);
      LDst := TStringList.Create;
      try
        ProcessFile(LDst, LSrc, ADst);
        LDst.SaveToFile(ADst);
      finally
        FreeAndNil(LDst);
      end;
    finally
      FreeAndNil(LSrc);
    end;
  end;

  procedure Main(const ADstPath, ASrc: TFileName);
  var
    LTmpFile: TFileName;
  begin
    LTmpFile := OCMOC.FileNameTemp(ExtractFileName(ASrc), '.lst');
    try
      with CCmocProcess_ASMTOH.Create(nil) do begin
        try
          Execute(OCMOC.FileNameTool(Tool_LWASM), TStringDynArray.Create('-s',
            '--depend', '--list=' + LTmpFile, ASrc));
          ProcessFile(ADstPath + ChangeFileExt(ExtractFileName(ASrc), '.h'),
            LTmpFile);
        finally
          Free;
        end;
      end;
    finally
      DeleteFile(LTmpFile);
    end;
  end;

var
  LDstPath: TFileName;

begin
  try
    LDstPath := OCMOC.PathToInclude + 'coco/';
    Main(LDstPath, OCMOC.PathToSrcLib + 'libcoco/asm/equates.asm');
    Main(LDstPath, OCMOC.PathToSrcLib + 'libcoco/asm/cocodefs.asm');
    Main(LDstPath, OCMOC.PathToSrcLib + 'libcoco/asm/coco3defs.asm');

    LDstPath := OCMOC.PathToInclude + 'vectrex/';
    Main(LDstPath, OCMOC.PathToSrcLib + 'libvectrex/asm/vectrexdefs.asm');
    Main(LDstPath, OCMOC.PathToSrcLib + 'libvectrex/asm/vectrexbios.asm');

    WriteLn;
    WriteLn('Done');
  except
    on LException: Exception do begin
      WriteLn(StdErr, LException.Message);
      ExitCode := LException.HelpContext;
    end;
  end;
  ReadLn;
end.
