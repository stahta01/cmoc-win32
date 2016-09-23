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

unit UCmocParserFast;

{$INCLUDE cmoc.inc}

interface

uses
  SysUtils, UCmocCharSet;



type
  TParserFast = object
  strict private
    FBeg, FTok, FPos: pchar;
  public
    procedure SetParser(const A: pchar);
    procedure Rewind;
    procedure TokenClear;
    function Done: boolean;
    function TokenAsString: string;
  public
    procedure ParseWhile(A: TSysCharSet);
    procedure ParseUntil(A: TSysCharSet);
  public
    procedure ParseParameter;
  end;

implementation

procedure TParserFast.SetParser(const A: pchar);
begin
  FBeg := A;
  Rewind;
end;

procedure TParserFast.Rewind;
begin
  FPos := FBeg;
  TokenClear;
end;

procedure TParserFast.TokenClear;
begin
  FTok := FPos;
end;

function TParserFast.Done: boolean;
begin
  Result := FPos^ = #0;
end;

function TParserFast.TokenAsString: string;
begin
  SetString(Result, FTok, FPos - FTok);
end;

procedure TParserFast.ParseWhile(A: TSysCharSet);
begin
  Exclude(A, #0);
  while FPos^ in A do begin
    Inc(FPos);
  end;
end;

procedure TParserFast.ParseUntil(A: TSysCharSet);
begin
  Include(A, #0);
  while not (FPos^ in A) do begin
    Inc(FPos);
  end;
end;

procedure TParserFast.ParseParameter;
begin
  while FPos^ in OCharSet.Graph do begin
    if FPos^ = '''' then begin
      repeat
        Inc(FPos);
      until FPos^ in [#0, ''''];
      if FPos^ <> #0 then begin
        Inc(FPos);
      end;
    end else begin
      Inc(FPos);
    end;
  end;
end;

end.
