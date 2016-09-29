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
  StrUtils, SysUtils, UCmocAsmParser, UCmocUtils;

procedure M6502Translate(var ALines: OAsmLines);

implementation

const

  TCharSetRegA = ['a', 'A'];
  TCharSetRegX = ['x', 'X'];
  TCharSetRegY = ['y', 'Y'];

type

  TAsmLanguage = (al6809, al6502, alSweet16);
  T6502Mode = (amError, amImpl, amIndi, amAccu, amImme, amAbsM, amAbsX, amAbsY, amIndX, amIndY);
  T6502Modes = set of T6502Mode;

function M6502AddrMode(const AParam: string; var LValue: string): T6502Mode;
var
  LLength: integer;
begin
  LValue := EmptyStr;
  LLength := Length(AParam);
  if LLength > 0 then begin
    if AParam[1] = '#' then begin
      LValue := Copy(AParam, 2, MaxInt);
      Result := amImme;
    end else if (Length(AParam) = 1) and (AParam[1] in TCharSetRegA) then begin
      LValue := AParam;
      Result := amAccu;
    end else if LLength >= 4 then begin
      if (AParam[1] = '(') then begin
        if (AParam[LLength] = ')') then begin
          if (AParam[LLength - 1] in TCharSetRegX) and (AParam[LLength - 2] = ',') then begin
            Result := amIndX;
          end else begin
            Result := amIndi;
          end;
        end else if (AParam[LLength] in TCharSetRegY) and (AParam[LLength - 1] = ',') and
          (AParam[LLength - 2] = ')') then begin
          Result := amIndY;
        end else begin
          Result := amError;
        end;
        if Result <> amError then begin
          if Result = amIndi then begin
            LValue := Copy(AParam, 2, Length(AParam) - 2);
          end else begin
            LValue := Copy(AParam, 2, Length(AParam) - 4);
          end;
        end;
      end else if AParam[LLength - 1] = ',' then begin
        if AParam[LLength] in TCharSetRegX then begin
          Result := amAbsX;
        end else if AParam[LLength] in TCharSetRegY then begin
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

function M6502Insert(const AModes: T6502Modes; var ALines: OAsmLines;
  const AInsertPos: integer; const A: array of variant; const AMeta: string = ''): integer;
var
  LIndex, LPos, LEnd: integer;
  LString, LValue: string;
  LMode: T6502Mode;
begin
  Result := AInsertPos;
  LMode := M6502AddrMode(ALines.Lines[Result].Par, LValue);
  if not (LMode in AModes) then begin
    OCmoc.RaiseError('invalid instruction mode');
  end;
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
          '?', LValue), '###', AMeta)) then begin
          ALines.Lines[Result].Is6502 := True;
          if Result = AInsertPos then begin
            ALines.Lines[Result].Sym := ALines.Lines[Result + 1].Sym;
          end;
          Inc(Result);
        end;
        LPos := LEnd + 1;
      end;
      Break;
    end;
    Inc(LIndex, 2);
  end;
end;

function M6502InsertStoreXY(const AModes: T6502Modes; var ALines: OAsmLines;
  const AIndex: integer; const AInstruction: string): integer;
begin
  Result := M6502Insert(AModes, ALines, AIndex, [
    amImme, 'LDA #?:STA _regz+1,pcr:### _regz,pcr',
    amAbsM, 'LDA ?,pcr:STA _regz+1,pcr:### _regz,pcr',
    amAbsX, 'LDA ?,x:STA _regz+1,pcr:### _regz,pcr',
    amAbsY, 'LDA ?,y:STA _regz+1,pcr:### _regz,pcr'],
    AInstruction[Length(AInstruction)]);
end;

function M6502InsertLoadXY(const AModes: T6502Modes; var ALines: OAsmLines;
  const AIndex: integer; const AInstruction: string): integer;
begin
  Result := M6502Insert(AModes, ALines, AIndex, [
    amImme, 'LDA #?:STA _regz+1,pcr:### _regz,pcr',
    amAbsM, 'LDA ?,pcr:STA _regz+1,pcr:### _regz,pcr',
    amAbsX, 'PSHS x:EXG x,d:LEAX ?,pcr:ABX:EXG x,d:### ,x:PULS x',
    amAbsY, 'PSHS b:TFR y,d:ADDD ?:TFR d,x:LDB ,x:CLRA:TFR d,x:PULS b'],
    AInstruction);
end;

function M6502InsertCalc(const AModes: T6502Modes; var ALines: OAsmLines;
  const AIndex: integer; const AInstruction: string): integer;
begin
  Result := M6502Insert(AModes, ALines, AIndex, [
    amAccu, '###', amImme, '### #?', amAbsM, '### ?',
    amAbsX, '### <?,x', amAbsY, '### <?,y', amIndX, '### [<?,x]',
    amIndY, 'PSHS b:LDD ?:EXG a,b:STD _regz,pcr:TFR y,d:ADDD _regz,pcr:STD _regz,pcr:PULS b:### [_regz,pcr]'],
    AInstruction);
end;

function M6502InsertPush(var ALines: OAsmLines; const AIndex: integer;
  const ARegister: string): integer;
begin
  Result := M6502Insert([amImpl], ALines, AIndex, [amImpl, 'PSHS ###'], ARegister);
end;

function M6502InsertPull(var ALines: OAsmLines; const AIndex: integer;
  const ARegister: string): integer;
begin
  Result := M6502Insert([amImpl], ALines, AIndex, [amImpl, 'PULS ###'], ARegister);
end;

function M6502InsertBranch(var ALines: OAsmLines; const AIndex: integer;
  const AInstruction: string): integer;
begin
  Result := M6502Insert([amAbsM], ALines, AIndex, [amAbsM, '### ?'], AInstruction);
end;

function M6502InsertImplied(var ALines: OAsmLines; const AIndex: integer;
  const AInstruction: string): integer;
begin
  Result := M6502Insert([amImpl], ALines, AIndex, [amImpl, '###'], AInstruction);
end;

procedure M6502Translate(var ALines: OAsmLines);
var
  LIndex: integer;
  LLanguage: TAsmLanguage;
begin
  LLanguage := al6809;
  LIndex := 0;
  while LIndex < Length(ALines.Lines) do begin
    with ALines.Lines[LIndex] do begin
      if not (Deleted or Is6502 or (Length(Ins) = 0)) then begin
        if IsIns('.p09') then begin
          Deleted := True;
          LLanguage := al6809;
        end else if IsIns('.p02') then begin
          Deleted := True;
          LLanguage := al6502;
        end else begin
          if Length(Par) > 0 then begin
            // Compatiblity change
            if Par[1] = '=' then begin
              Par[1] := '#';
            end;
          end;
          Ins := UpperCase(Ins);
          case LLanguage of
            al6502: begin
              case Ins of
                'SEI', 'CLI', 'SEC', 'CLC', 'NOP', 'RTS', 'RTI': begin
                  LIndex := M6502InsertImplied(ALines, LIndex, Ins);
                end;
                'BCC', 'BCS', 'BEQ', 'BMI', 'BNE', 'BPL', 'BVC', 'BVS': begin
                  LIndex := M6502InsertBranch(ALines, LIndex, Ins);
                end;
                'INX', 'INY': begin
                  LIndex := M6502Insert([amImpl], ALines, LIndex,
                    [amImpl, 'EXG ###,d:ADDB #1:EXG ###,d'], Ins[3]);
                end;
                'DEX', 'DEY': begin
                  LIndex := M6502Insert([amImpl], ALines, LIndex,
                    [amImpl, 'EXG ###,d:SUBB #1:EXG ###,d'], Ins[3]);
                end;
                'TAX', 'TAY': begin
                  LIndex := M6502Insert([amImpl], ALines,
                    LIndex, [amImpl, 'CLRA:TFR d,###'], Ins[3]);
                end;
                'TXA', 'TYA': begin
                  LIndex := M6502Insert([amImpl], ALines, LIndex, [amImpl, 'TFR ###,d'], Ins[2]);
                end;
                'PHA': begin
                  LIndex := M6502InsertPush(ALines, LIndex, 'b');
                end;
                'PLA': begin
                  LIndex := M6502InsertPull(ALines, LIndex, 'b');
                end;
                'PHP': begin
                  LIndex := M6502InsertPush(ALines, LIndex, 'cc');
                end;
                'PLP': begin
                  LIndex := M6502InsertPull(ALines, LIndex, 'cc');
                end;
                'JSR': begin
                  LIndex := M6502Insert([amAbsM, amIndi], ALines, LIndex,
                    [amAbsM, 'BSR ?', amIndi, 'BSR [?]']);
                end;
                'JMP': begin
                  LIndex := M6502Insert([amAbsM, amIndi], ALines, LIndex,
                    [amAbsM, 'BRA ?', amIndi, 'BRA [?]']);
                end;
                'STX': begin
                  LIndex := M6502InsertStoreXY([amAbsM, amAbsY], ALines, LIndex, Ins);
                end;
                'STY': begin
                  LIndex := M6502InsertStoreXY([amAbsM, amAbsX], ALines, LIndex, Ins);
                end;
                'LDX': begin
                  LIndex := M6502InsertLoadXY([amImme, amAbsM, amAbsY], ALines, LIndex, Ins);
                end;
                'LDY': begin
                  LIndex := M6502InsertLoadXY([amImme, amAbsM, amAbsX], ALines, LIndex, Ins);
                end;
                'ASL', 'ROL', 'ROR', 'LSR': begin
                  LIndex := M6502InsertCalc([amImpl, amAccu, amAbsM, amAbsX],
                    ALines, LIndex, Ins + 'B');
                end;
                'LDA', 'STA', 'ORA': begin
                  LIndex := M6502InsertCalc([amImme, amAbsM, amAbsX, amAbsY, amIndX, amIndY],
                    ALines, LIndex, Copy(Ins, 1, 2) + 'B');
                end;
                'ADC', 'SBC', 'AND', 'EOR': begin
                  LIndex := M6502InsertCalc([amImme, amAbsM, amAbsX, amAbsY, amIndX, amIndY],
                    ALines, LIndex, Ins + 'B');
                end;
                'INC', 'DEC': begin
                  LIndex := M6502InsertCalc([amAbsM, amAbsX], ALines, LIndex, Ins);
                end;
                'FCB', 'FDB': begin
                end else begin
                  OCmoc.RaiseError('unknown 6502 mnemonic', Ins);
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
