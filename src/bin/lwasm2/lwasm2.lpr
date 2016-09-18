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
  UCmocDefs,
  UCmocUtils;

{$R *.res}

type

  CCmocProcess_LWASM2 = class(CCmocProcess)
  public
    procedure ProcessLWASM;
  end;

(* TODO: Change DAT for OS9
#if defined(OS9)
#define DAT Y  /* CMOC uses Y to point to the data segment of the current process. */
#else
#define DAT PCR  /* The data segment at a fixed offset of the code segment. */
#endif
*)

  procedure CCmocProcess_LWASM2.ProcessLWASM;
  var
    LIndex: integer;
    LSrc: TFileName;
    LParams: TStringDynArray;
  begin
    LParams := default(TStringDynArray);
    for LIndex := 1 to ParamCount do begin
      OStringDynArray.Add(LParams, ParamStr(LIndex));
    end;
    if Length(LParams) = 0 then begin
      OStringDynArray.Add(LParams, Opt_Help1);
    end else if FileExists(LParams[High(LParams)]) then begin
      LSrc := OCmoc.DosToUnix(LParams[High(LParams)]);
      LParams[High(LParams)] := LSrc + FileExt_I;
      ExecuteTool(Tool_MCPP, TStringDynArray.Create('-a', '-P',
        '-W', '0', Opt_Output2, LParams[High(LParams)], Opt_Define2, 'DAT=pcr', LSrc));
    end;
    ExecuteTool(Tool_LWASM, LParams);
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
      WriteLn(StdErr, 'Error: Exception ', OCmoc.StringQuoted(OCmoc.DosToUnix(ParamStr(0))));
      ExitCode := LException.HelpContext;
    end;
  end;
end.
