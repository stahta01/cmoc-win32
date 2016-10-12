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
    Items: array of OAsmLine;
  public
    function Count: integer; inline;
  public
    procedure Insert(const AIndex: integer; const ASymbol, AInstruction, AParameters: string);
    procedure Add(const ASymbol, AInstruction, AParameters: string);
  public
    function AddSourceLine(const ASrcLine: string): boolean;
    function InsertSourceLine(const AIndex: integer; const ASrcLine: string): boolean;
  public
    procedure AddSource(const AStrings: TStrings);
  public
    procedure SaveToStrings(const AStrings: TStrings);
    procedure SaveToFile(const AFileName: TFileName);
  public
    function SameInstArgs(const A, B: integer): boolean;
  public
    function CanChange(const ALow, AHigh: integer): boolean;
    procedure Remove(const ALow, AHigh: integer);
  end;

implementation

function OAsmSource.Count: integer;
begin
  Result := System.Length(Items);
end;

procedure OAsmSource.Insert(const AIndex: integer;
  const ASymbol, AInstruction, AParameters: string);
var
  LIndex: integer;
begin
  System.SetLength(Items, Count + 1);
  for LIndex := Count - 2 downto AIndex do begin
    Items[LIndex + 1] := Items[LIndex];
  end;
  Items[AIndex].SetLine(ASymbol, AInstruction, AParameters);
end;

procedure OAsmSource.Add(const ASymbol, AInstruction, AParameters: string);
begin
  Insert(Count, ASymbol, AInstruction, AParameters);
end;

function OAsmSource.AddSourceLine(const ASrcLine: string): boolean;
var
  LAsmLine: OAsmLine;
begin
  LAsmLine := default(OAsmLine);
  Result := LAsmLine.SetLine(ASrcLine);
  if Result then begin
    Add(LAsmLine.Symb, LAsmLine.Inst, LAsmLine.Args);
  end;
end;

function OAsmSource.InsertSourceLine(const AIndex: integer; const ASrcLine: string): boolean;
var
  LAsmLine: OAsmLine;
begin
  LAsmLine := default(OAsmLine);
  Result := LAsmLine.SetLine(ASrcLine);
  if Result then begin
    Insert(AIndex, LAsmLine.Symb, LAsmLine.Inst, LAsmLine.Args);
  end;
end;

procedure OAsmSource.AddSource(const AStrings: TStrings);
var
  LIndex: integer;
begin
  for LIndex := 0 to AStrings.Count - 1 do begin
    AddSourceLine(AStrings[LIndex]);
  end;
end;

procedure OAsmSource.SaveToStrings(const AStrings: TStrings);
var
  LIndex: integer;
begin
  AStrings.Clear;
  for LIndex := 0 to Count - 1 do begin
    AStrings.Add(Items[LIndex].AsString);
  end;
end;

procedure OAsmSource.SaveToFile(const AFileName: TFileName);
var
  LStrings: TStrings;
begin
  LStrings := TStringList.Create;
  try
    SaveToStrings(LStrings);
    LStrings.SaveToFile(AFileName);
  finally
    FreeAndNil(LStrings);
  end;
end;

function OAsmSource.SameInstArgs(const A, B: integer): boolean;
begin
  Result := Items[A].SameInst(Items[B].Inst) and Items[A].SameArgs(Items[B].Args);
end;

function OAsmSource.CanChange(const ALow, AHigh: integer): boolean;
var
  LIndex: integer;
begin
  Result := (ALow <= AHigh) and (ALow >= 0) and (ALow < Count) and
    (AHigh >= 0) and (AHigh < Count) and not Items[ALow].Removed;
  if Result then begin
    for LIndex := ALow + 1 to AHigh do begin
      if Items[LIndex].Removed or Items[LIndex].HasSymb then begin
        Exit(False);
      end;
    end;
  end;
end;

procedure OAsmSource.Remove(const ALow, AHigh: integer);
var
  LIndex: integer;
begin
  for LIndex := ALow to AHigh do begin
    Items[LIndex].Removed := True;
  end;
end;

end.
