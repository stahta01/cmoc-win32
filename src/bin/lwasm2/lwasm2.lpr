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

program lwasm2;

{$INCLUDE cmoc.inc}

uses
  Classes,
  FileUtil,
  Process,
  StrUtils,
  SysUtils,
  Types,
  UCmocUtils;

{$R *.res}

type

  CCmocProcess_LWASM2 = class(CCmocProcess)
  public
    procedure ProcessLWASM;
  end;

  procedure CCmocProcess_LWASM2.ProcessLWASM;
  var
    LIndex: integer;
    LSrcFile, LDstFile: TFileName;
    LParams: TStringDynArray;
  begin
    if ParamCount < 2 then begin
      OCMOC.RaiseError('No input file selected', Tool_LWASM);
    end;
    LSrcFile := OCMOC.DosToUnix(ParamStr(ParamCount));
    LDstFile := LSrcFile + FileExt_I;
(* TODO: Change DAT for OS9
#if defined(OS9)
#define DAT Y  /* CMOC uses Y to point to the data segment of the current process. */
#else
#define DAT PCR  /* The data segment at a fixed offset of the code segment. */
#endif
*)
    if OCMOC.FileChanged(LDstFile, LSrcFile) then begin
      Execute(OCMOC.FileNameTool(Tool_MCPP), TStringDynArray.Create('-a', '-P',
        '-W', '0', Opt_Output2, LDstFile, Opt_Define2, 'DAT=PCR', LSrcFile));
    end;
    LParams := default(TStringDynArray);
    for LIndex := 1 to ParamCount - 1 do begin
      OCMOC.StringDynArrayAppend(LParams, ParamStr(LIndex));
    end;
    OCMOC.StringDynArrayAppend(LParams, LDstFile);

    Execute(OCMOC.FileNameTool(Tool_LWASM), LParams);
  end;

begin
  try
    with CCmocProcess_LWASM2.Create(nil) do begin
      try
        ProcessLWASM;
      finally
        Free;
      end;
    end;
  except
    on LException: Exception do begin
      WriteLn(StdErr, 'Error: Exception ', OCmoc.DosToUnix(QuotedStr(ParamStr(0))));
      ExitCode := LException.HelpContext;
    end;
  end;
end.
