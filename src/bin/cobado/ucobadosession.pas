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

unit UCobadoSession;

{$INCLUDE cobado.inc}

interface

uses
  Classes, SSockets, SysUtils, UCobadoStream;

type

  CCobadoSession = class(TComponent)
  strict private
    FParams: TStrings;
  public
    FSocket: TSocketStream;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  public
    function GetString(const AIndex: integer; const ADefault: string = ''): string;
    procedure Command(const ACmd: string);
  end;

implementation

constructor CCobadoSession.Create(AOwner: TComponent);
begin
  inherited;
  FParams := TStringList.Create;
end;

destructor CCobadoSession.Destroy;
begin
  FreeAndNil(FParams);
  inherited;
end;

function CCobadoSession.GetString(const AIndex: integer; const ADefault: string): string;
begin
  if AIndex < FParams.Count then begin
    Result := FParams[AIndex];
  end else begin
    Result := ADefault;
  end;
end;

procedure CCobadoSession.Command(const ACmd: string);
var
  LIndex: integer;
  LSearchRec: TSearchRec;
begin
  FParams.CommaText := ACmd;
  case LowerCase(GetString(0)) of
    'dir': begin
      FSocket.ChrOut(#13);
      if FindFirst(GetString(1, '*.*'), faDirectory, LSearchRec) = 0 then begin
        try
          repeat
            FSocket.StrOut(LSearchRec.Name + #13);
          until FindNext(LSearchRec) <> 0;
        finally
          FindClose(LSearchRec);
        end;
      end;
    end;
    'funny': begin
      for LIndex := 0 to 511 do begin
        FSocket.Poke(LIndex + 1024, LIndex);
      end;
    end;
    'cd': begin
      SetCurrentDir(GetString(1));
    end;
  end;
end;

end.
