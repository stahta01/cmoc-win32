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

unit UCmocPeephole;

{$INCLUDE cmoc.inc}

interface

uses
  SysUtils, UCmocAsmLine, UCmocAsmSource;

procedure Peephole(var ASrc: OAsmSource);
procedure Peephole_Rejuice(var ASrc: OAsmSource);

implementation

procedure PSHS_TO_STORE(var ALine: OAsmLine; const AOffset: string);
begin
  if ALine.SameArgs('D') or ALine.SameArgs('B,A') or ALine.SameArgs('A,B') then begin
    ALine.SetLine(ALine.Symb, 'STD', AOffset + ',S');
  end else if ALine.SameArgs('X') then begin
    ALine.SetLine(ALine.Symb, 'STX', AOffset + ',S');
  end else if ALine.SameArgs('Y') then begin
    ALine.SetLine(ALine.Symb, 'STY', AOffset + ',S');
  end;
  ALine.Comm := 'Optimized #' + AOffset;
end;

procedure SourcePeephole1(const ASrc: OAsmSource);

  function Find_PSHS(out AResult: integer; AIndex: integer): boolean;
  begin
    Result := False;
    for AIndex := AIndex + 1 to ASrc.Count - 1 do begin
      with ASrc.Items[AIndex] do begin
        if HasSymb or HasRegs(TCharSetRegS) then begin
          Break;
        end;
        if SameInst('PSHS') then begin
          if SameArgs('B,A') or SameArgs('A,B') or SameArgs('D') or
            SameArgs('X') or SameArgs('Y') then begin
            AResult := AIndex;
            Result := True;
            Break;
          end;
        end;
      end;
    end;
  end;

var
  LIndex, LPos1, LPos2, LPos3: integer;
begin
  for LIndex := 0 to ASrc.Count - 1 do begin
    with ASrc.Items[LIndex] do begin
      if not Removed then begin
        if SameInst('LEAS') then begin
          if SameArgs('2,S') then begin
            Removed := Find_PSHS(LPos1, LIndex);
            if Removed then begin
              PSHS_TO_STORE(ASrc.Items[LPos1], '0');
            end;
          end else if SameArgs('4,S') then begin
            Removed := Find_PSHS(LPos1, LIndex) and Find_PSHS(LPos2, LPos1);
            if Removed then begin
              PSHS_TO_STORE(ASrc.Items[LPos1], '2');
              PSHS_TO_STORE(ASrc.Items[LPos2], '0');
            end;
          end else if SameArgs('6,S') then begin
            Removed := Find_PSHS(LPos1, LIndex) and Find_PSHS(LPos2, LPos1) and
              Find_PSHS(LPos3, LPos2);
            if Removed then begin
              PSHS_TO_STORE(ASrc.Items[LPos1], '4');
              PSHS_TO_STORE(ASrc.Items[LPos2], '2');
              PSHS_TO_STORE(ASrc.Items[LPos3], '0');
            end;
          end;
        end;
      end;
    end;
  end;
end;

procedure SourcePeephole_Duplicates(const ASrc: OAsmSource);
var
  LIndex: integer;

  procedure DuplicateRemove;
  begin
    if ASrc.SameInstArgs(LIndex, LIndex + 1) then begin
      if not ASrc.Items[LIndex].HasSymb then begin
        ASrc.Items[LIndex + 0].Removed := True;
      end else if not ASrc.Items[LIndex + 1].HasSymb then begin
        ASrc.Items[LIndex + 1].Removed := True;
      end;
    end;
  end;

begin
  for LIndex := 0 to ASrc.Count - 2 do begin
    if not (ASrc.Items[LIndex].Removed or ASrc.Items[LIndex + 1].Removed) then begin
      if ASrc.Items[LIndex].SameInst('rts') then begin
        DuplicateRemove;
      end;
    end;
  end;
end;

// Bin size count down for rpncalc-v2.c
// 16,146
// 16,129
// 16,107
// 16,065
// 16,062
// 15,975
// 15,910
// 15,834
// 15,834

procedure Peephole_Rejuice(var ASrc: OAsmSource);
var
  LIndex: integer;
  LRejuice: boolean;
  A, B, C, D: ^OAsmLine;

  procedure RejuiceBRA(const AName: string; const ALength: integer);
  begin
    A^.Inst := 'lbra';
    A^.Args := AName;
    ASrc.Remove(LIndex + 1, LIndex + ALength);
  end;

  procedure RejuiceBSR(const AName: string; const ALength: integer);
  begin
    A^.Inst := 'lbsr';
    A^.Args := AName;
    ASrc.Remove(LIndex + 1, LIndex + ALength);
  end;

begin
  LRejuice := True;
  with ASrc do begin
    for LIndex := 0 to Count - 1 do begin
      if Items[LIndex].SameInst('.rejuice') then begin
        Items[LIndex].Removed := True;
        LRejuice := StrToBool(Items[LIndex].Args);
      end;
      if LRejuice then begin
        if CanChange(LIndex, LIndex + 1) then begin
          A := @Items[LIndex + 0];
          B := @Items[LIndex + 1];
          if A^.Same('leas', ',u') and B^.Same('puls', 'u,pc') then begin
            RejuiceBRA('_rejuice_5', 1);
          end else if A^.Same('pshs', 'u') and B^.Same('leau', ',s') then begin
            RejuiceBSR('_rejuice_4', 1);
          end else if CanChange(LIndex, LIndex + 2) then begin
            C := @Items[LIndex + 2];
            if A^.Same('leax', 'd,x') and B^.Same('ldb', ',x') then begin
              if C^.SameInst('clra') then begin
                RejuiceBSR('_rejuice_6', 2);
              end else if C^.SameInst('sex') then begin
                RejuiceBSR('_rejuice_7', 2);
              end;
            end else if CanChange(LIndex, LIndex + 3) then begin
              D := @Items[LIndex + 3];
              if A^.Same('ldd', ',x') then begin
                if B^.Same('tfr', 'b,a') then begin
                  if C^.SameInst('clrb') and D^.Same('std', ',x') then begin
                    // Only used in 2 places. Not useful.
                    //RejuiceBSR('_rejuice_3', 3);
                  end;
                end else if C^.Same('std', ',x') then begin
                  if B^.Same('subd', '#1') and D^.Same('addd', '#1') then begin
                    RejuiceBSR('_rejuice_1', 3);
                  end else if B^.Same('addd', '#1') and D^.Same('subd', '#1') then begin
                    RejuiceBSR('_rejuice_2', 3);
                  end;
                end;
              end;
            end;
          end;
        end;
      end;
    end;
  end;
end;

procedure Peephole(var ASrc: OAsmSource);
begin
  // Not ready. Needs to check for PULS's or branches. Anything that may change S
  //SourcePeephole1(ASrc);
  SourcePeephole_Duplicates(ASrc);
end;

end.
