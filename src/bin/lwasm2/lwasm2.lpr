(*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

Derek John Evans <https://sourceforge.net/u/buzzphp/profile/>
*)

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
  UCmocStringDynArray,
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
