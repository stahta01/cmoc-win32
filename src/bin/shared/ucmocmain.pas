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

unit UCmocMain;

{$INCLUDE cmoc.inc}

interface

uses
  SysUtils, UCmocParams, UCmocRbs;

type
  TMainProcedure = procedure(const AParams: TCmocParams);

procedure CmocMain(AMainProcedure: TMainProcedure);

implementation

procedure CmocMain(AMainProcedure: TMainProcedure);
var
  LParams: TCmocParams;
begin
  LParams := TCmocParams.Create;
  try
    try
      AMainProcedure(LParams);
    except
      on LException: Exception do begin
        WriteLn(StdErr, LineEnding + Trim(RbsLoadFromResource('USAGE')) + LineEnding + LineEnding +
          'This is free and unencumbered software released into the public domain.' + LineEnding +
          'For more information, please refer to <http://unlicense.org/>' + LineEnding);
        WriteLn(StdErr, 'Error: ' + LException.Message);
        if (startupinfo.dwFlags and 1) <> 0 then begin
          WriteLn;
          WriteLn('Press enter to exit');
          ReadLn;
        end;
      end;
    end;
  finally
    FreeAndNil(LParams);
  end;
end;

end.
