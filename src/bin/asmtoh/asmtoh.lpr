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
    procedure ProcessFile(const ADst, ASrc: TStrings; const AHeaderIdent: string;
      const AFilter: TStringDynArray);
    procedure ProcessFile(const ADst, ASrc: TFileName; const AHeaderIdent: string;
      const AFilter: TStringDynArray);
  end;

  procedure CCmocProcess_ASMTOH.ProcessFile(const ADst, ASrc: TStrings;
  const AHeaderIdent: string; const AFilter: TStringDynArray);

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
    ADst.Add('#ifndef ' + AHeaderIdent);
    ADst.Add('#define ' + AHeaderIdent + LineEnding);

    for LLine in ASrc do begin
      LParser.SetString('$' + Trim(LLine));
      if LParser.Next and TryStrToInt(LParser.Token, LValue) and
        LParser.NextAndTokenIs('(') then begin
        LParser.IncludeUntil([')']);
        if LParser.NextAndTokenIs(')') and LParser.NextAndTokenIs(':') and
          LParser.Next and LParser.Next then begin
          if (Length(AFilter) = 0) or AnsiMatchText(LParser.Token, AFilter) then begin
            LIdent := OCmoc.StringToIdent('_' + UpperCase(LParser.Token));
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
                  ADst.Add('// ' + TrimSet(LParser.Remaining, [#0..#32, '*', ';']));
                end;
                LDefine(LIdent, IntToStr(LValue));
                if LSize >= 0 then begin
                  if LSize = 1 then begin
                    LDefine(LowerCase(LIdent), '(*(unsigned char*)' + LIdent + ')');
                  end else if LSize = 2 then begin
                    LDefine(LowerCase(LIdent), '(*(unsigned*)' + LIdent + ')');
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
    end;
    ADst.Add(LineEnding + '#endif');
  end;

  procedure CCmocProcess_ASMTOH.ProcessFile(const ADst, ASrc: TFileName;
  const AHeaderIdent: string; const AFilter: TStringDynArray);
  var
    LSrc, LDst: TStrings;
  begin
    LSrc := TStringList.Create;
    try
      LSrc.LoadFromFile(ASrc);
      LDst := TStringList.Create;
      try
        ProcessFile(LDst, LSrc, AHeaderIdent, AFilter);
        LDst.SaveToFile(ADst);
      finally
        FreeAndNil(LDst);
      end;
    finally
      FreeAndNil(LSrc);
    end;
  end;

  procedure Main(const ADstPath, ASrc: TFileName; const AHeaderIdent: string;
  const AFilter: TStringDynArray);
  var
    LTmpFile: TFileName;
  begin
    LTmpFile := OCmoc.FileNameTemp(ExtractFileName(ASrc), '.lst');
    try
      with CCmocProcess_ASMTOH.Create(nil) do begin
        try
          Execute(OCmoc.FileNameTool(Tool_LWASM), TStringDynArray.Create('-s',
            '--depend', '--list=' + LTmpFile, ASrc));
          ProcessFile(ADstPath + ChangeFileExt(ExtractFileName(ASrc), '.h'),
            LTmpFile, AHeaderIdent, AFilter);
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
    LDstPath := OCmoc.PathToInclude + 'coco/';
    Main(LDstPath, OCmoc.PathToSrcLib + 'libcoco/asm/equates.asm',
      '_COCO_EQUATES_H', default(TStringDynArray));
    Main(LDstPath, OCmoc.PathToSrcLib + 'libcoco/asm/cocodefs.asm', '_COCO_DEFS_H',
      default(TStringDynArray));
    Main(LDstPath, OCmoc.PathToSrcLib + 'libcoco/asm/coco3defs.asm', '_COCO3_DEFS_H',
      default(TStringDynArray));

    LDstPath := OCmoc.PathToInclude + 'dragon/';

    Main(LDstPath, OCmoc.PathToSrcLib + 'libcoco/asm/equates.asm',
      '_DRAGON_EQUATES_H', TStringDynArray.Create('BS', 'CR', 'ESC', 'LF',
      'FORMF', 'SPACE', 'TEMPTR', 'CURPOS', 'SNDTON', 'SNDDUR', 'TIMVAL', 'VIDRAM'));

    LDstPath := OCmoc.PathToInclude + 'vectrex/';
    Main(LDstPath, OCmoc.PathToSrcLib + 'libvectrex/asm/vectrexdefs.asm',
      '_VECTREX_VECTREXDEFS_H', default(TStringDynArray));
    Main(LDstPath, OCmoc.PathToSrcLib + 'libvectrex/asm/vectrexbios.asm',
      '_VECTREX_VECTREXBIOS_H', default(TStringDynArray));

    WriteLn;
    WriteLn('Done');
  except
    on LException: Exception do begin
      WriteLn(StdErr, 'Error: Exception ', OCmoc.StringQuoted(OCmoc.DosToUnix(ParamStr(0))));
      ExitCode := LException.HelpContext;
    end;
  end;
  ReadLn;
end.
