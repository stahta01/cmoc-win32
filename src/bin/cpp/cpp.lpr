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

program cpp;

{$INCLUDE cmoc.inc}

uses
  Classes,
  FileUtil,
  SysUtils,
  Types,
  UCmocCharSet,
  UCmocDefs,
  UCmocParserFast,
  UCmocStringDynArray;

{$R *.res}


  procedure Main;
  var
    LIndex: integer;
    LParam: string;
    LParams: TStringDynArray;
    LParser: TParserFast;
  begin
    LParser := default(TParserFast);
    LParams := TStringDynArray.Create('-P', '-a', '-W', '0');
    LParser.SetParser(CmdLine);
    LIndex := 0;
    while not LParser.Done do begin
      LParser.ParseUntil(OCharSet.Graph);
      LParser.TokenClear;
      LParser.ParseParameter;
      if LIndex > 0 then begin
        LParam := LParser.TokenAsString;
        if Length(LParam) > 0 then begin
          if LParam[1] = '-' then begin
            if (Length(LParam) > 1) and (LParam[2] in ['D', 'I', 'U']) then begin
              OStringDynArray.Add(LParams, '-' + LParam[2]);
              OStringDynArray.Add(LParams, AnsiDequotedStr(Copy(LParam, 3, MaxInt), ''''));
            end;
          end else begin
            OStringDynArray.Add(LParams, LParam);
          end;
        end;
      end;
      Inc(LIndex);
    end;
    ExecuteProcess(ProgramDirectory + Tool_MCPP, LParams, [ExecInheritsHandles]);
  end;

begin
  Main;
end.
