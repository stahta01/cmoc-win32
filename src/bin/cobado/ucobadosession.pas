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
    FBinary: TMemoryStream;
  strict private
    procedure Command_DIR;
    procedure Command_CD;
    procedure Command_SAVE;
    procedure Command_LOAD;
    procedure Command_MORE;
    procedure Command_MORE2;
  public
    constructor Create(const AOwner: TComponent; const AStream: TStream); override;
    destructor Destroy; override;
  public
    function GetString(const AIndex: integer): string;
    function GetWord(const AIndex: integer): word;
    function GetString(const AIndex: integer; const ADefault: string): string;
    procedure Command(const ACommandLine: string);
    procedure Command_DONE;
  end;

implementation

constructor CCobadoSession.Create(const AOwner: TComponent; const AStream: TStream);
begin
  inherited;
  FParams := TStringList.Create;
  FText := TStringList.Create;
  FBinary := TMemoryStream.Create;
end;

destructor CCobadoSession.Destroy;
begin
  FreeAndNil(FParams);
  FreeAndNil(FBinary);
  FreeAndNil(FText);
  inherited;
end;

function CCobadoSession.GetString(const AIndex: integer): string;
begin
  if AIndex < FParams.Count then begin
    Result := FParams[AIndex];
  end else begin
    raise Exception.CreateFmt('Missing parameter #%d', [AIndex]);
  end;
end;

function CCobadoSession.GetWord(const AIndex: integer): word;
begin
  Result := StrToInt(GetString(AIndex));
end;

function CCobadoSession.GetString(const AIndex: integer; const ADefault: string): string;
begin
  try
    Result := GetString(AIndex);
  except
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

procedure CCobadoSession.Command_DIR;
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

procedure CCobadoSession.Command_LOAD;
var
  LFileName: TFileName;
  LAddr, LSize: word;
  LData: string;
begin
  ClearLineBuffer;
  LFileName := GetString(1);
  FBinary.LoadFromFile(LFileName);
  FBinary.Position := 0;
  case LowerCase(ExtractFileExt(LFileName)) of
    '.bas': begin
      if FBinary.ReadByte = $ff then begin
        LSize := Swap(FBinary.ReadWord);
        LAddr := PeekW(_TXTTAB);
        SetLength(LData, LSize);
        FBinary.ReadBuffer(LData[1], Length(LData));
        SetMem(LAddr, LData);
        PokeW(_VARTAB, LAddr + LSize);
        PokeW(_ARYTAB, LAddr + LSize);
        PokeW(_ARYEND, LAddr + LSize);
        PokeW(_CHARAD, LAddr - 1);
        PokeW(_STRTAB, PeekW(_MEMSIZ));
        PokeW(_TEMPPT, _STRSTK);
      end;
    end;
    '.bin': begin
      while True do begin
        case FBinary.ReadByte of
          $00: begin
            LSize := Swap(FBinary.ReadWord);
            LAddr := Swap(FBinary.ReadWord);
            SetLength(LData, LSize);
            FBinary.ReadBuffer(LData[1], LSize);
            SetMem(LAddr, LData);
          end;
          $ff: begin
            FBinary.ReadWord;
            PokeW(_EXECJP, Swap(FBinary.ReadWord));
            Break;
          end;
        end;
      end;
    end else begin
      raise Exception.Create('Unsupported file type');
    end;
  end;
end;

procedure CCobadoSession.Command_SAVE;
var
  LAddr, LSize, LExec: word;
  LFileName: TFileName;
  LData: string;
begin
  ClearLineBuffer;
  LFileName := GetString(1);
  FBinary.Clear;
  case LowerCase(ExtractFileExt(LFileName)) of
    '.bin': begin
      LAddr := GetWord(2);
      LSize := GetWord(3);
      LExec := GetWord(4);
      FBinary.WriteByte(0);
      FBinary.WriteWord(Swap(LSize));
      FBinary.WriteWord(Swap(LAddr));
      LData := GetMem(LAddr, LSize);
      FBinary.WriteBuffer(LData[1], Length(LData));
      FBinary.WriteByte(255);
      FBinary.WriteWord(0);
      FBinary.WriteWord(LExec);
      FBinary.SaveToFile(LFileName);
    end;
    '.bas': begin
      LAddr := PeekW(25);  // TXTTAB
      LSize := PeekW(27) - LAddr; // VARTAB
      FBinary.WriteByte($ff);
      FBinary.WriteWord(Swap(LSize));
      LData := GetMem(LAddr, LSize);
      FBinary.WriteBuffer(LData[1], Length(LData));
      FBinary.SaveToFile(LFileName);
    end else begin
      raise Exception.Create('Unsupported file type');
    end;
  end;
end;

procedure CCobadoSession.Command(const ACommandLine: string);
var
  LIndex: integer;
begin
  FParams.CommaText := ACommandLine;
  if FParams.Count > 0 then begin
    try
      case LowerCase(GetString(0)) of
        'ls': begin
          Command_DIR;
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
        'ld': begin
          Command_LOAD;
        end;
        'st': begin
          Command_SAVE;
        end;
      end;
    except
      on LException: Exception do begin
        PrintString(#13 + LException.Message);
      end;
    end;
  end;
end;

end.
