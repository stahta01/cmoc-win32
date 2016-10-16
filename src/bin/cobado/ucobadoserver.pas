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

unit UCobadoServer;

{$INCLUDE cobado.inc}

interface

uses
  Classes, SSockets, SysUtils, UCobadoSession;

type

  CCobadoServer = class(TInetServer)
  protected
    procedure DoConnect(ASocket: TSocketStream); override;
  end;

implementation

procedure CCobadoServer.DoConnect(ASocket: TSocketStream);
var
  LBuffer: string;
  LChar: char;
  LSession: CCobadoSession;
begin
  LSession := CCobadoSession.Create(nil, ASocket);
  try
    while True do begin
      LBuffer := EmptyStr;
      while True do begin
        LChar := char(ASocket.ReadByte);
        if LChar = #0 then begin
          Break;
        end else begin
          LBuffer += LChar;
        end;
      end;
      LSession.Command(LBuffer);
      LSession.Command_DONE;
    end;
  finally
    FreeAndNil(LSession);
  end;
end;

end.
