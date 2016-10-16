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
  Classes, SysUtils, UCobadoRemote, UCobadoStream;

type

  CCobadoSession = class(CCobadoRemote)
  strict private
    FTextIndex: integer;
    FParams, FText: TStrings;
  strict private
    procedure Command_LS;
    procedure Command_CD;
    procedure Command_SAVE;
    procedure Command_MORE;
    procedure Command_MORE2;
  public
    constructor Create(const AOwner: TComponent; const AStream: TStream); override;
    destructor Destroy; override;
  public
    function GetString(const AIndex: integer; const ADefault: string = ''): string;
    procedure Command(const ACmd: string);
    procedure Command_DONE;
  end;

implementation

constructor CCobadoSession.Create(const AOwner: TComponent; const AStream: TStream);
begin
  inherited;
  FParams := TStringList.Create;
  FText := TStringList.Create;
end;

destructor CCobadoSession.Destroy;
begin
  FreeAndNil(FParams);
  FreeAndNil(FText);
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

procedure CCobadoSession.Command_DONE;
begin
  SendCode(ccDone);
end;

procedure CCobadoSession.Command_MORE2;
var
  LIndex: integer;
begin
  LIndex := 0;
  while (FTextIndex < FText.Count) and (LIndex < 16) do begin
    PrintString(#13 + FText[FTextIndex]);
    Inc(FTextIndex);
    Inc(LIndex);
  end;
end;

procedure CCobadoSession.Command_MORE;
begin
  ClearLineBuffer;
  FTextIndex := 0;
  FText.LoadFromFile(GetString(1));
  Command_MORE2;
end;

procedure CCobadoSession.Command_LS;
var
  LSearchRec: TSearchRec;
begin
  ClearLineBuffer;
  PrintChar(#13);
  if FindFirst(GetString(1, AllFilesMask), faDirectory, LSearchRec) = 0 then begin
    try
      repeat
        if (LSearchRec.Attr and faDirectory) <> 0 then begin
          PrintColumn('[' + LSearchRec.Name + ']');
        end;
      until FindNext(LSearchRec) <> 0;
    finally
      FindClose(LSearchRec);
    end;
  end;
  if FindFirst(GetString(1, AllFilesMask), 0, LSearchRec) = 0 then begin
    try
      repeat
        PrintColumn(LSearchRec.Name);
      until FindNext(LSearchRec) <> 0;
    finally
      FindClose(LSearchRec);
    end;
  end;
  PrintCurrentDir;
end;

procedure CCobadoSession.Command_CD;
begin
  ClearLineBuffer;
  SetCurrentDir(GetString(1));
  PrintCurrentDir;
end;

procedure CCobadoSession.Command_SAVE;
begin
  ClearLineBuffer;
end;

procedure CCobadoSession.Command(const ACmd: string);
var
  LIndex: integer;
begin
  FParams.CommaText := ACmd;
  try
    case LowerCase(GetString(0)) of
      'ls': begin
        Command_LS;
      end;
      'funny': begin
        ClearLineBuffer;
        for LIndex := 0 to 511 do begin
          Poke(LIndex + 1024, LIndex);
        end;
      end;
      'cd': begin
        Command_CD;
      end;
      'more': begin
        Command_MORE;
      end;
      'save': begin
        Command_SAVE;
      end;
    end;
  except
    on LException: Exception do begin
      PrintString(#13 + LException.Message);
    end;
  end;
end;

end.
