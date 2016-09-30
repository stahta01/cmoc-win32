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

unit UCmocAsmSource;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, SysUtils, UCmocAsmLine;

type

  OAsmSource = object
  public
    Lines: array of OAsmLine;
  public
    function Count: integer;
  public
    procedure Insert(const AIndex: integer; const ASymbol, AInstruction, AParameters: string);
    procedure Add(const ASymbol, AInstruction, AParameters: string);
  public
    function AddSourceLine(const ASrcLine: string): boolean;
    function InsertSourceLine(const AIndex: integer; const ASrcLine: string): boolean;
  public
    procedure AddSource(const A: TStrings);
  public
    procedure SaveToStrings(const A: TStrings);
    procedure SaveToFile(const A: TFileName);
  end;

implementation

function OAsmSource.Count: integer;
begin
  Result := Length(Lines);
end;

procedure OAsmSource.Insert(const AIndex: integer;
  const ASymbol, AInstruction, AParameters: string);
var
  LIndex: integer;
begin
  SetLength(Lines, Length(Lines) + 1);
  for LIndex := High(Lines) - 1 downto AIndex do begin
    Lines[LIndex + 1] := Lines[LIndex];
  end;
  Lines[AIndex].SetLine(ASymbol, AInstruction, AParameters);
end;

procedure OAsmSource.Add(const ASymbol, AInstruction, AParameters: string);
begin
  SetLength(Lines, Length(Lines) + 1);
  Lines[High(Lines)].SetLine(ASymbol, AInstruction, AParameters);
end;

function OAsmSource.AddSourceLine(const ASrcLine: string): boolean;
var
  LAsmLine: OAsmLine;
begin
  LAsmLine := default(OAsmLine);
  Result := LAsmLine.SetLine(ASrcLine);
  if Result then begin
    Add(LAsmLine.Symbol, LAsmLine.Instruction, LAsmLine.Parameters);
  end;
end;

function OAsmSource.InsertSourceLine(const AIndex: integer; const ASrcLine: string): boolean;
var
  LAsmLine: OAsmLine;
begin
  LAsmLine := default(OAsmLine);
  Result := LAsmLine.SetLine(ASrcLine);
  if Result then begin
    Insert(AIndex, LAsmLine.Symbol, LAsmLine.Instruction, LAsmLine.Parameters);
  end;
end;

procedure OAsmSource.AddSource(const A: TStrings);
var
  LIndex: integer;
begin
  for LIndex := 0 to A.Count - 1 do begin
    AddSourceLine(A[LIndex]);
  end;
end;

procedure OAsmSource.SaveToStrings(const A: TStrings);
var
  LIndex: integer;
begin
  A.Clear;
  for LIndex := Low(Lines) to High(Lines) do begin
    if not Lines[LIndex].IsDeleted then begin
      A.Add(Lines[LIndex].AsString);
    end;
  end;
end;

procedure OAsmSource.SaveToFile(const A: TFileName);
var
  LStrings: TStrings;
begin
  LStrings := TStringList.Create;
  try
    SaveToStrings(LStrings);
    LStrings.SaveToFile(A);
  finally
    FreeAndNil(LStrings);
  end;
end;

end.
