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

unit UCmoc6502;

{$INCLUDE cmoc.inc}

interface

uses
  StrUtils, SysUtils, UCmocAsmSource, UCmocUtils;

procedure M6502Translate(var ASource: OAsmSource);

implementation

const

  TCharSetRegA = ['a', 'A'];
  TCharSetRegX = ['x', 'X'];
  TCharSetRegY = ['y', 'Y'];

type

  TAsmLanguage = (al6809, al6502, alSweet16);
  T6502Mode = (amError, amImpl, amAccu, amImme, amIndi, amIndi_PID, amAbsM,
    amAbsM_PID, amAbsX, amAbsX_PID, amAbsY, amAbsY_PID, amIndX, amIndX_PID, amIndY, amIndY_PID);
  T6502Modes = set of T6502Mode;

function M6502AddrMode(const AParam: string; var LValue: string): T6502Mode;

  function LIsPositionIndependant: boolean;
  begin
    Result := (Length(LValue) > 0) and (LValue[1] = ':');
    if Result then begin
      Delete(LValue, 1, 1);
    end;
  end;

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
            if LIsPositionIndependant then begin
              Result := amIndi_PID;
            end;
          end else begin
            LValue := Copy(AParam, 2, Length(AParam) - 4);
            if LIsPositionIndependant then begin
              if Result = amIndX then begin
                Result := amIndX_PID;
              end else begin
                Result := amIndY_PID;
              end;
            end;
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
          if LIsPositionIndependant then begin
            if Result = amAbsX then begin
              Result := amAbsX_PID;
            end else begin
              Result := amAbsY_PID;
            end;
          end;
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
  if (Result = amAbsM) and LIsPositionIndependant then begin
    Result := amAbsM_PID;
  end;
end;

function M6502Insert(const AModes: T6502Modes; var ASource: OAsmSource;
  const AInsertPos: integer; const A: array of variant; const AMeta: string = ''): integer;
var
  LIndex, LPos, LEnd: integer;
  LString, LValue: string;
  LMode: T6502Mode;
begin
  Result := AInsertPos;
  LMode := M6502AddrMode(ASource.Lines[Result].Parameters, LValue);
  if not (LMode in AModes) then begin
    OCmoc.RaiseError('invalid instruction mode');
  end;
  ASource.Lines[Result].IsDeleted := True;
  LIndex := 0;
  while LIndex < High(A) do begin
    if A[LIndex] = LMode then begin
      LString := A[LIndex + 1] + '|';
      LPos := 1;
      while True do begin
        LEnd := PosEx('|', LString, LPos);
        if LEnd = 0 then begin
          Break;
        end;
        if ASource.InsertSourceLine(Result, #9 +
          AnsiReplaceStr(AnsiReplaceStr(Copy(LString, LPos, LEnd - LPos),
          '?', LValue), '###', AMeta)) then begin
          ASource.Lines[Result].Is6502 := True;
          if Result = AInsertPos then begin
            ASource.Lines[Result].Symbol := ASource.Lines[Result + 1].Symbol;
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

const
  GOffsetX = 'EXG x,d|ADDD ?,pcr|STD 15|EXG x,d|';
  GOffsetY = 'EXG y,d|ADDD ?,pcr|STD 15|EXG y,d|';

function M6502InsertStoreXY(const AModes: T6502Modes; var ASource: OAsmSource;
  const AIndex: integer; const AInstruction: string): integer;
begin
  Result := M6502Insert(AModes, ASource, AIndex, [
    amAbsM, 'EXG ###,d|STB ?|EXG ###,d', amAbsM_PID, 'EXG ###,d|STB ?,pcr|EXG ###,d',
    amAbsX, 'EXG y,d|STB ?,x|EXG y,d', amAbsY, 'EXG x,d|STB ?,y|EXG x,d',
    amAbsX_PID, GOffsetX + 'EXG y,d|STB [15]|EXG y,d',
    amAbsY_PID, GOffsetY + 'EXG x,d|STB [15]|EXG x,d'],
    AInstruction[Length(AInstruction)]);
end;

function M6502InsertLoadXY(const AModes: T6502Modes; var ASource: OAsmSource;
  const AIndex: integer; const AInstruction: string): integer;
begin
  Result := M6502Insert(AModes, ASource, AIndex, [
    amImme, 'LDA #?|STA 16|LD### 15',
    amAbsM, 'LDA ?|STA 16|LD### 15', amAbsM_PID, 'LDA ?,pcr|STA 16|LD### 15',
    amAbsX, 'LDA ?,x|STA 16|LDY 15', amAbsY, 'LDA ?,y|STA 16|LDX 15',
    amAbsX_PID, GOffsetX + 'EXG y,d|LDB [15]|EXG y,d',
    amAbsY_PID, GOffsetY + 'EXG x,d|LDB [15]|EXG x,d'],
    AInstruction[Length(AInstruction)]);
end;

function M6502InsertLoadStoreA(const AModes: T6502Modes; var ASource: OAsmSource;
  const AIndex: integer; const AInstruction: string): integer;
begin
  Result := M6502Insert(AModes, ASource, AIndex, [
    amAccu, '###', amImme, '### #?',
    amAbsM, '### ?', amAbsM_PID, '### ?,pcr',
    amAbsX, '### ?,x', amAbsY, '### ?,y',
    amAbsX_PID, GOffsetX + '### [15]', amAbsY_PID, GOffsetY + '### [15]',
    amIndX, '### [?,x]', amIndX_PID, GOffsetX + '### [15,x]',
    amIndY, 'PSHS b|LDD ?|EXG a,b|STD 15|TFR y,d|ADDD 15|STD 15|PULS b|### [15]',
    amIndY_PID, 'PSHS b|LDD ?,pcr|EXG a,b|STD 15|TFR y,d|ADDD 15|STD 15|PULS b|### [15]'],
    AInstruction);
end;

function M6502InsertPush(var ASource: OAsmSource; const AIndex: integer;
  const ARegister: string): integer;
begin
  Result := M6502Insert([amImpl], ASource, AIndex, [amImpl, 'PSHS ###'], ARegister);
end;

function M6502InsertPull(var ASource: OAsmSource; const AIndex: integer;
  const ARegister: string): integer;
begin
  Result := M6502Insert([amImpl], ASource, AIndex, [amImpl, 'PULS ###'], ARegister);
end;

function M6502InsertBranch(var ASource: OAsmSource; const AIndex: integer;
  const AInstruction: string): integer;
begin
  Result := M6502Insert([amAbsM], ASource, AIndex, [amAbsM, '### ?'], AInstruction);
end;

function M6502InsertImplied(var ASource: OAsmSource; const AIndex: integer;
  const AInstruction: string): integer;
begin
  Result := M6502Insert([amImpl], ASource, AIndex, [amImpl, '###'], AInstruction);
end;

procedure M6502Translate(var ASource: OAsmSource);
var
  LIndex: integer;
  LLanguage: TAsmLanguage;
begin
  LLanguage := al6809;
  LIndex := 0;
  while LIndex < Length(ASource.Lines) do begin
    with ASource.Lines[LIndex] do begin
      if not (IsDeleted or Is6502 or (Length(Instruction) = 0)) then begin
        if SameInstruction('.p09') then begin
          IsDeleted := True;
          LLanguage := al6809;
        end else if SameInstruction('.p02') then begin
          IsDeleted := True;
          LLanguage := al6502;
        end else begin
          Instruction := UpperCase(Instruction);
          case LLanguage of
            al6502: begin
              case Instruction of
                'SEI', 'CLI', 'SEC', 'CLC', 'NOP', 'RTS', 'RTI': begin
                  LIndex := M6502InsertImplied(ASource, LIndex, Instruction);
                end;
                'BCC', 'BCS', 'BEQ', 'BMI', 'BNE', 'BPL', 'BVC', 'BVS': begin
                  LIndex := M6502InsertBranch(ASource, LIndex, Instruction);
                end;
                'INX', 'INY': begin
                  LIndex := M6502Insert([amImpl], ASource, LIndex,
                    [amImpl, 'EXG ###,d|ADDB #1|EXG ###,d'], Instruction[3]);
                end;
                'DEX', 'DEY': begin
                  LIndex := M6502Insert([amImpl], ASource, LIndex,
                    [amImpl, 'EXG ###,d|SUBB #1|EXG ###,d'], Instruction[3]);
                end;
                'TAX', 'TAY': begin
                  LIndex := M6502Insert([amImpl], ASource,
                    LIndex, [amImpl, 'CLRA|TFR d,###'], Instruction[3]);
                end;
                'TXA', 'TYA': begin
                  LIndex := M6502Insert([amImpl], ASource, LIndex,
                    [amImpl, 'TFR ###,d'], Instruction[2]);
                end;
                'PHA': begin
                  LIndex := M6502InsertPush(ASource, LIndex, 'b');
                end;
                'PLA': begin
                  LIndex := M6502InsertPull(ASource, LIndex, 'b');
                end;
                'PHP': begin
                  LIndex := M6502InsertPush(ASource, LIndex, 'cc');
                end;
                'PLP': begin
                  LIndex := M6502InsertPull(ASource, LIndex, 'cc');
                end;
                'JSR': begin
                  LIndex := M6502Insert([amAbsM, amIndi], ASource, LIndex,
                    [amAbsM, 'BSR ?', amIndi, 'BSR [?]']);
                end;
                'JMP': begin
                  LIndex := M6502Insert([amAbsM, amIndi], ASource, LIndex,
                    [amAbsM, 'BRA ?', amIndi, 'BRA [?]']);
                end;
                'STX': begin
                  LIndex := M6502InsertStoreXY([amAbsM, amAbsM_PID, amAbsY, amAbsY_PID],
                    ASource, LIndex, Instruction);
                end;
                'STY': begin
                  LIndex := M6502InsertStoreXY([amAbsM, amAbsM_PID, amAbsX, amAbsX_PID],
                    ASource, LIndex, Instruction);
                end;
                'LDX': begin
                  LIndex := M6502InsertLoadXY([amImme, amAbsM, amAbsM_PID, amAbsY, amAbsY_PID],
                    ASource, LIndex, Instruction);
                end;
                'LDY': begin
                  LIndex := M6502InsertLoadXY([amImme, amAbsM, amAbsM_PID, amAbsX, amAbsX_PID],
                    ASource, LIndex, Instruction);
                end;
                'ASL', 'ROL', 'ROR', 'LSR': begin
                  LIndex := M6502InsertLoadStoreA([amImpl, amAccu, amAbsM,
                    amAbsM_PID, amAbsX, amAbsX_PID], ASource, LIndex, Instruction + 'B');
                end;
                'LDA', 'STA', 'ORA': begin
                  LIndex := M6502InsertLoadStoreA([amImme, amAbsM, amAbsM_PID, amAbsX, amAbsX_PID,
                    amAbsY, amAbsY_PID, amIndX, amIndX_PID, amIndY, amIndY_PID], ASource,
                    LIndex, Copy(Instruction, 1, 2) + 'B');
                end;
                'ADC', 'SBC', 'AND', 'EOR': begin
                  LIndex := M6502InsertLoadStoreA([amImme, amAbsM, amAbsM_PID, amAbsX, amAbsX_PID,
                    amAbsY, amAbsY_PID, amIndX, amIndX_PID, amIndY, amIndY_PID],
                    ASource, LIndex, Instruction + 'B');
                end;
                'INC', 'DEC': begin
                  LIndex := M6502InsertLoadStoreA([amAbsM, amAbsM_PID, amAbsX, amAbsX_PID],
                    ASource, LIndex, Instruction);
                end;
                'FCB', 'FDB': begin
                end else begin
                  OCmoc.RaiseError('unknown 6502 mnemonic', Instruction);
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
