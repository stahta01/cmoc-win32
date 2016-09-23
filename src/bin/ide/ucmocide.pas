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

unit UCmocIDE;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, KeyInputIntf, SysUtils;

type

  TStringsHelper = class helper for TStrings
  public
    procedure _Write(const AString: string; const APrefix: string = default(string));
    procedure _WriteLn(const AString: string; const APrefix: string = default(string));
  end;

  TKeyInputHelper = class helper for TKeyInput
    procedure _ApplyShortCut(const AShortCut: TShortCut);
  end;

  CStringsStream = class(TStream)
  strict private
    FStrings: TStrings;
  public
    Task: string;
  public
    constructor Create(const AStrings: TStrings);
  public
    function Write(const ABuffer; ACount: longint): longint; override;
  end;

implementation

procedure TStringsHelper._Write(const AString, APrefix: string);
var
  LLastLine: string;
begin
  BeginUpdate;
  try
    if Count = 0 then begin
      LLastLine := APrefix;
    end else begin
      LLastLine := APrefix + Strings[Count - 1];
      Delete(Count - 1);
    end;
    AddText(LLastLine + AString + LineEnding);
  finally
    EndUpdate;
  end;
end;

procedure TStringsHelper._WriteLn(const AString, APrefix: string);
begin
  _Write(AString + LineEnding, APrefix);
end;

procedure TKeyInputHelper._ApplyShortCut(const AShortCut: TShortCut);
var
  LShiftState: TShiftState;
begin
  LShiftState := default(TShiftState);
  if (AShortCut and scShift) <> 0 then begin
    Include(LShiftState, ssShift);
  end;
  if (AShortCut and scAlt) <> 0 then begin
    Include(LShiftState, ssAlt);
  end;
  if (AShortCut and scCtrl) <> 0 then begin
    Include(LShiftState, ssCtrl);
  end;
  Apply(LShiftState);
  Press(AShortCut and $FF);
  Unapply(LShiftState);
end;

constructor CStringsStream.Create(const AStrings: TStrings);
begin
  inherited Create;
  FStrings := AStrings;
end;

function CStringsStream.Write(const ABuffer; ACount: longint): longint;
var
  LString: string;
begin
  SetString(LString, @ABuffer, ACount);
  if Length(Task) = 0 then begin
    FStrings._Write(LString);
  end else begin
    FStrings._Write(LString, Task + ': ');
  end;
  Result := ACount;
end;

end.

