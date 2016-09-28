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

unit UCmocPreprocessor;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, SysUtils;

type

  CCmocPreprocessorBase = class(TComponent)
  protected
    procedure Preprocess(const ADst, ASrc: TStrings); virtual; abstract;
  public
    procedure Preprocess(const ADst: TStrings; var ASrc: TextFile);
    procedure Preprocess(var ADst, ASrc: TextFile);
    procedure Preprocess(const ADst: TFileName; var ASrc: TextFile);
    procedure Preprocess(const ADst, ASrc: TFileName);
  end;

implementation

procedure CCmocPreprocessorBase.Preprocess(const ADst: TStrings; var ASrc: TextFile);
var
  LLine: string;
  LStrings: TStrings;
begin
  LStrings := TStringList.Create;
  try
    while not EOF(ASrc) do begin
      ReadLn(LLine);
      LStrings.Add(LLine);
    end;
    Preprocess(ADst, LStrings);
  finally
    FreeAndNil(LStrings);
  end;
end;

procedure CCmocPreprocessorBase.Preprocess(var ADst, ASrc: TextFile);
var
  LLine: string;
  LStrings: TStrings;
begin
  LStrings := TStringList.Create;
  try
    Preprocess(LStrings, ASrc);
    for LLine in LStrings do begin
      WriteLn(ADst, LLine);
    end;
  finally
    FreeAndNil(LStrings);
  end;
end;

procedure CCmocPreprocessorBase.Preprocess(const ADst: TFileName; var ASrc: TextFile);
var
  LTextFile: TextFile;
begin
  AssignFile(LTextFile, ADst);
  try
    Rewrite(LTextFile);
    Preprocess(LTextFile, ASrc);
  finally
    Close(LTextFile);
  end;
end;

procedure CCmocPreprocessorBase.Preprocess(const ADst, ASrc: TFileName);
var
  LTextFile: TextFile;
begin
  AssignFile(LTextFile, ASrc);
  try
    Reset(LTextFile);
    Preprocess(ADst, LTextFile);
  finally
    Close(LTextFile);
  end;
end;

end.

