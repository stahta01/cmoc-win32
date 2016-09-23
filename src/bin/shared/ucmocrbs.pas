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

unit UCmocRbs;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, FileUtil, LCLType, SysUtils;

function RbsLoadFromFile(const AStream: TStream; ASize: SizeInt = -1): rawbytestring;
function RbsLoadFromFile(const AFileName: string): rawbytestring;
function RbsLoadFromResource(const AResName: string): rawbytestring;

procedure RbsSaveToFile(const A: rawbytestring; const AFileName: string);

function RbsByte(const A: byte): rawbytestring;
function RbsWord(const A: word): rawbytestring;
function RbsByte(const A: rawbytestring; const AIndex: integer): byte;
function RbsWord(const A: rawbytestring; const AIndex: integer): word;

function RbsDecbLength(const A: rawbytestring): word;
function RbsDecbBegin(const A: rawbytestring): word;

function RbsDecb(const A: rawbytestring; const AAddr: word): rawbytestring;
function RbsDecb(const A: rawbytestring; const AAddr, AExec: word): rawbytestring;

function RbsVideo(const A: rawbytestring): rawbytestring;

function RbsCompressBlock(const A: rawbytestring; const AType: byte): rawbytestring;

implementation

function RbsLoadFromFile(const AStream: TStream; ASize: SizeInt): rawbytestring;
begin
  if ASize < 0 then begin
    ASize := AStream.Size - AStream.Position;
  end;
  SetLength(Result, ASize);
  AStream.ReadBuffer(Result[1], ASize);
end;

function RbsLoadFromFile(const AFileName: string): rawbytestring;
var
  LStream: TStream;
begin
  LStream := TFileStream.Create(AFileName, fmOpenRead);
  try
    Result := RbsLoadFromFile(LStream);
  finally
    FreeAndNil(LStream);
  end;
end;

function RbsLoadFromResource(const AResName: string): rawbytestring;
var
  LStream: TStream;
begin
  LStream := TResourceStream.Create(HINSTANCE, AResName, RT_RCDATA);
  try
    Result := RbsLoadFromFile(LStream);
  finally
    FreeAndNil(LStream);
  end;
end;

procedure RbsSaveToFile(const A: rawbytestring; const AFileName: string);
begin
  with TFileStream.Create(AFileName, fmCreate) do begin
    try
      WriteBuffer(A[1], Length(A));
    finally
      Free;
    end;
  end;
end;

function RbsByte(const A: byte): rawbytestring;
begin
  Result := char(A);
end;

function RbsWord(const A: word): rawbytestring;
begin
  Result := RbsByte(A shr 8) + RbsByte(A);
end;

function RbsByte(const A: rawbytestring; const AIndex: integer): byte;
begin
  Result := pbyte(@A[AIndex + 1])^;
end;

function RbsWord(const A: rawbytestring; const AIndex: integer): word;
begin
  Result := swap(pword(@A[AIndex + 1])^);
end;

function RbsDecbLength(const A: rawbytestring): word;
begin
  Result := RbsWord(A, 1);
end;

function RbsDecbBegin(const A: rawbytestring): word;
begin
  Result := RbsWord(A, 3);
end;

function RbsDecb(const A: rawbytestring; const AAddr: word): rawbytestring;
begin
  Result := RbsByte(0) + RbsWord(Length(A)) + RbsWord(AAddr) + A;
end;

function RbsDecb(const A: rawbytestring; const AAddr, AExec: word): rawbytestring;
begin
  Result := RbsDecb(A, AAddr) + RbsByte(255) + RbsWord(0) + RbsWord(AExec);
end;

function RbsVideo(const A: rawbytestring): rawbytestring;
var
  LIndex: integer;
begin
  Result := A;
  for LIndex := 1 to Length(Result) do begin
    if Result[LIndex] in [#96..#127] then begin
      Result[LIndex] := char(byte(Result[LIndex]) - 96);
    end else if Result[LIndex] in [#32..#63] then begin
      Result[LIndex] := char(byte(Result[LIndex]) + 64);
    end;
  end;
end;

function RbsCompress_LZSS(const A: rawbytestring): rawbytestring;
var
  LSrc, LDst: TFileName;
begin
  LSrc := GetTempDir(False) + 'rbscompress.src.bin';
  LDst := GetTempDir(False) + 'rbscompress.dst.bin';
  try
    RbsSaveToFile(A, LSrc);
    ExecuteProcess(ProgramDirectory + 'lzss.exe', ['e', LSrc, LDst]);
    Result := RbsLoadFromFile(LDst);
  finally
    DeleteFile(LSrc);
    DeleteFile(LDst);
  end;
end;

function RbsCompress_Exomizer(const A: rawbytestring): rawbytestring;
var
  LSrc, LDst: TFileName;
begin
  LSrc := GetTempDir(False) + 'rbscompress.src.bin';
  LDst := GetTempDir(False) + 'rbscompress.dst.bin';
  try
    RbsSaveToFile(A, LSrc);
    ExecuteProcess(ProgramDirectory + 'exomizer.exe', ['raw', '-b', '-o', LDst, LSrc]);
    Result := RbsLoadFromFile(LDst);
  finally
    DeleteFile(LSrc);
    DeleteFile(LDst);
  end;
end;

function RbsCompressBlock(const A: rawbytestring; const AType: byte): rawbytestring;
begin
  case AType of
    0: begin
      Result := A;
    end;
    1: begin
      Result := RbsCompress_Exomizer(A);
    end;
    12: begin  // (1 << 12) = 4096 ring buffer size (Default).
      Result := RbsCompress_LZSS(A);
    end else begin
      raise Exception.Create('Unknown compression type');
    end;
  end;
  Result := RbsByte(AType) + RbsWord(Length(A)) + RbsWord(Length(Result)) + Result;
end;

end.
