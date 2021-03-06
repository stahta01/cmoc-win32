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

unit UCmocTranslate;

{$INCLUDE cmoc.inc}

interface

uses
  SysUtils, UCmocAsmSource, UCmocTranslate6502, UCmocUtils;

procedure Translate(var ASrc: OAsmSource);

implementation

type
  TProcessorMode = (pm6809, pm6502, pmSweet16);

procedure Translate(var ASrc: OAsmSource);
var
  LIndex: integer;
  LProcessorMode: TProcessorMode;
begin
  LProcessorMode := pm6809;
  LIndex := 0;
  while LIndex < Length(ASrc.Items) do begin
    with ASrc.Items[LIndex] do begin
      if not (Removed or Is6502 or (Length(Inst) = 0)) then begin
        Removed := SameInst('.p09');
        if Removed then begin
          LProcessorMode := pm6809;
        end else begin
          Removed := SameInst('.p02');
          if Removed then begin
            LProcessorMode := pm6502;
          end else begin
            case LProcessorMode of
              pm6502: begin
                Translate6502(ASrc, LIndex);
              end;
            end;
          end;
        end;
      end;
    end;
    Inc(LIndex);
  end;
end;

end.
