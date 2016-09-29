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

unit U6502;

{$INCLUDE cmoc.inc}

interface

uses
  StrUtils, SysUtils, UCmocAsmParser;

procedure M6502Translate(var ALines: OAsmLines);

implementation

type

  TAsmLanguage = (al6809, al6502, alSweet16);
  TAddrMode6502 = (amError, amImpl, amAccu, amImme, amAbsM, amAbsX, amAbsY, amIndX, amIndY);

function M6502AddrMode(const AParam: string; var LValue: string): TAddrMode6502;
var
  LLength: integer;
begin
  LValue := EmptyStr;
  LLength := Length(AParam);
  if LLength > 0 then begin
    if AParam[1] = '#' then begin
      LValue := Copy(AParam, 2, MaxInt);
      Result := amImme;
    end else if SameText(AParam, 'A') then begin
      LValue := AParam;
      Result := amAccu;
    end else if LLength >= 4 then begin
      if (AParam[1] = '(') then begin
        if (AParam[LLength] = ')') and (AParam[LLength - 1] in ['x', 'X']) and
          (AParam[LLength - 2] = ',') then begin
          Result := amIndX;
        end else if (AParam[LLength] in ['y', 'Y']) and (AParam[LLength - 1] = ',') and
          (AParam[LLength - 2] = ')') then begin
          Result := amIndY;
        end else begin
          Result := amError;
        end;
        if Result <> amError then begin
          LValue := Copy(AParam, 2, Length(AParam) - 4);
        end;
      end else if AParam[LLength - 1] = ',' then begin
        if AParam[LLength] in ['x', 'X'] then begin
          Result := amAbsX;
        end else if AParam[LLength] in ['y', 'Y'] then begin
          Result := amAbsY;
        end else begin
          Result := amError;
        end;
        if Result <> amError then begin
          LValue := Copy(AParam, 1, Length(AParam) - 2);
        end;
      end else begin
        Result := amAbsM;
        LValue := AParam;
      end;
    end else begin
      Result := amAbsM;
      LValue := AParam;
    end;
  end else begin
    Result := amImpl;
    LValue := EmptyStr;
  end;
end;

function M6502Insert(var ALines: OAsmLines; const AInsertPos: integer;
  const A: array of variant; const AVal: string = ''): integer;
var
  LIndex, LPos, LEnd: integer;
  LString, LPar: string;
  LMode: TAddrMode6502;
begin
  Result := AInsertPos;
  LMode := M6502AddrMode(ALines.Lines[Result].Par, LPar);
  ALines.Lines[Result].Deleted := True;
  LIndex := 0;
  while LIndex < High(A) do begin
    if A[LIndex] = LMode then begin
      LString := A[LIndex + 1] + ':';
      LPos := 1;
      while True do begin
        LEnd := PosEx(':', LString, LPos);
        if LEnd = 0 then begin
          Break;
        end;
        if ALines.AsmInsert(Result, #9 +
          AnsiReplaceStr(AnsiReplaceStr(Copy(LString, LPos, LEnd - LPos),
          '?', LPar), '###', AVal)) then begin
          ALines.Lines[Result].Ignore := True;
          Inc(Result);
        end;
        LPos := LEnd + 1;
      end;
      Break;
    end;
    Inc(LIndex, 2);
  end;
end;

procedure M6502Translate(var ALines: OAsmLines);
var
  LIndex: integer;
  LMeta: string;
  LLanguage: TAsmLanguage;
begin
  LLanguage := al6809;
  LIndex := 0;
  while LIndex < Length(ALines.Lines) do begin
    with ALines.Lines[LIndex] do begin
      if not (Deleted or Ignore) then begin
        if IsIns('LANG') then begin
          Deleted := True;
          case UpperCase(Par) of
            '6502': begin
              LLanguage := al6502;
            end;
            '6809': begin
              LLanguage := al6809;
            end;
            'SWEET16': begin
              LLanguage := alSweet16;
            end else begin
              LLanguage := al6809;
            end;
          end;
        end else begin
          Ins := UpperCase(Ins);
          case LLanguage of
            al6502: begin
              case Ins of
                'SEI', 'CLI', 'SEC', 'CLC', 'NOP', 'RTS', 'RTI': begin
                  LIndex := M6502Insert(ALines, LIndex, [amImpl, '###'], Ins);
                end;
                'BCC', 'BCS', 'BEQ', 'BMI', 'BNE', 'BPL', 'BVC', 'BVS': begin
                  LIndex := M6502Insert(ALines, LIndex, [amAbsM, '### ?'], Ins);
                end;
                'INX', 'INY': begin
                  LIndex := M6502Insert(ALines, LIndex,
                    [amImpl, 'EXG ###,d:INCB:EXG ###,d'], Ins[3]);
                end;
                'DEX', 'DEY': begin
                  LIndex := M6502Insert(ALines, LIndex,
                    [amImpl, 'EXG ###,d:DECB:EXG ###,d'], Ins[3]);
                end;
                'TAX', 'TAY': begin
                  LIndex := M6502Insert(ALines, LIndex, [amImpl, 'CLR a:TFR d,###'], Ins[3]);
                end;
                'TXA', 'TYA': begin
                  LIndex := M6502Insert(ALines, LIndex, [amImpl, 'TFR ###,d'], Ins[2]);
                end;
                'PHA': begin
                  LIndex := M6502Insert(ALines, LIndex, [amImpl, 'PSHS b']);
                end;
                'PLA': begin
                  LIndex := M6502Insert(ALines, LIndex, [amImpl, 'PULS b']);
                end;
                'JSR': begin
                  LIndex := M6502Insert(ALines, LIndex, [amAbsM, 'BSR ?']);
                end;
                'JMP': begin
                  LIndex := M6502Insert(ALines, LIndex, [amAbsM, 'BRA ?']);
                end;
                'STX', 'STY': begin
                  LIndex := M6502Insert(ALines, LIndex, [
                    amImme, 'EXG d,###:STB #?:EXG d,###',
                    amAbsM, 'EXG d,###:STB ?:EXG d,###',
                    amAbsX, 'EXG d,###:STB ?,x:EXG d,###',
                    amAbsY, 'EXG d,###:STB ?,y:EXG d,###'],
                    Ins[Length(Ins)]);
                end;
                'LDX', 'LDY': begin
                  LIndex := M6502Insert(ALines, LIndex, [
                    amImme, 'LDA #?:STA _regz+1:### _regz',
                    amAbsM, 'LDA ?:STA _regz+1:### _regz',
                    amAbsX, 'LDA ?,x:STA _regz+1:### _regz',
                    amAbsY, 'LDA ?,y:STA _regz+1:### _regz'],
                    Ins);
                end;
                'LDA', 'STA', 'ADC', 'SBC', 'ORA', 'AND', 'ROL', 'ROR', 'LSR', 'ASL',
                'INC', 'DEC', 'EOR': begin
                  LMeta := Ins;
                  case LMeta of
                    'LDA', 'STA', 'ORA': begin
                      LMeta[Length(LMeta)] := 'B';
                    end;
                    'ADC', 'SBC', 'AND', 'EOR', 'ROL', 'ROR', 'LSR', 'ASL': begin
                      LMeta := Ins + 'B';
                    end;
                  end;
                  LIndex := M6502Insert(ALines, LIndex, [
                    amAccu, '###B', amImme, '### #?', amAbsM, '### ?',
                    amAbsX, '### <?,x',
                    amAbsY, '### <?,y',
                    amIndX, '### [<?,x]',
                    amIndY,
                    'PSHS b:LDD ?:EXG a,b:STD _regz:TFR y,d:ADDD _regz:STD _regz:PULS b:### [_regz]'],
                    LMeta);
                end else begin
                end;
              end;
            end;
          end;
        end;
      end;
    end;
    Inc(LIndex);
  end;
end;

end.
