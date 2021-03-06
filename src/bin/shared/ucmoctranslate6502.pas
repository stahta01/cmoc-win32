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

unit UCmocTranslate6502;

{$INCLUDE cmoc.inc}

interface

uses
  StrUtils, SysUtils, UCmocAsmLine, UCmocAsmSource, UCmocUtils;

procedure Translate6502(var ASrc: OAsmSource; var AIndex: integer);

implementation

const

  SInvalidInstructionMode = 'Invalid 6502 instruction mode';
  SUnknownMnemonic = 'Unknown 6502 mnemonic';

type

  TAddrMode6502 = (amImpl, amAccu, amImme, amIndi, amIndi_PID, amAbsM,
    amAbsM_PID, amAbsX, amAbsX_PID, amAbsY, amAbsY_PID, amIndX, amIndX_PID, amIndY, amIndY_PID);
  TAddrMode6502s = set of TAddrMode6502;

function GetAddrMode(const AParam: string; var LValue: string): TAddrMode6502;

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
          OCmoc.RaiseError(SInvalidInstructionMode);
        end;
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
      end else if AParam[LLength - 1] = ',' then begin
        if AParam[LLength] in TCharSetRegX then begin
          Result := amAbsX;
        end else if AParam[LLength] in TCharSetRegY then begin
          Result := amAbsY;
        end else begin
          OCmoc.RaiseError(SInvalidInstructionMode);
        end;
        LValue := Copy(AParam, 1, Length(AParam) - 2);
        if LIsPositionIndependant then begin
          if Result = amAbsX then begin
            Result := amAbsX_PID;
          end else begin
            Result := amAbsY_PID;
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

procedure Insert_ASM(const AModes: TAddrMode6502s; var ASource: OAsmSource;
  var AInsertPos: integer; const ARules: array of variant; const AMeta: string = '');
var
  LRuleIndex, LPos, LEnd: integer;
  LString, LValue: string;
  LMode: TAddrMode6502;
begin
  LMode := GetAddrMode(ASource.Items[AInsertPos].Args, LValue);
  if not (LMode in AModes) then begin
    OCmoc.RaiseError(SInvalidInstructionMode);
  end;
  ASource.Items[AInsertPos].Removed := True;
  LRuleIndex := 0;
  while LRuleIndex < High(ARules) do begin
    if ARules[LRuleIndex] = LMode then begin
      LString := ARules[LRuleIndex + 1] + '|';
      LPos := 1;
      while True do begin
        LEnd := PosEx('|', LString, LPos);
        if LEnd = 0 then begin
          Break;
        end;
        if ASource.InsertSourceLine(AInsertPos, #9 +
          AnsiReplaceStr(AnsiReplaceStr(Copy(LString, LPos, LEnd - LPos),
          '?', LValue), '###', AMeta)) then begin
          ASource.Items[AInsertPos].Is6502 := True;
          ASource.Items[AInsertPos].Symb := ASource.Items[AInsertPos + 1].Symb;
          ASource.Items[AInsertPos + 1].Symb := EmptyStr;
          Inc(AInsertPos);
        end;
        LPos := LEnd + 1;
      end;
      Break;
    end;
    Inc(LRuleIndex, 2);
  end;
end;

const
  LEAZX = 'EXG x,d|ADDD ?,pcr|STD 15|EXG x,d|';
  LEAZY = 'EXG y,d|ADDD ?,pcr|STD 15|EXG y,d|';
  STXB_Z = 'EXG x,d|STB [15]|EXG x,d|';
  STYB_Z = 'EXG y,d|STB [15]|EXG y,d|';
  LDXB_Z = 'EXG x,d|LDB [15]|EXG x,d|';
  LDYB_Z = 'EXG y,d|LDB [15]|EXG y,d|';

procedure Insert_STXY(const AAddrModes: TAddrMode6502s; var ASource: OAsmSource;
  var AIndex: integer; const AInstruction: string);
begin
  Insert_ASM(AAddrModes, ASource, AIndex, [
    amAbsM, 'EXG ###,d|STB ?|EXG ###,d',
    amAbsX, 'EXG y,d|STB ?,x|EXG y,d', amAbsY, 'EXG x,d|STB ?,y|EXG x,d',
    amAbsM_PID, 'EXG ###,d|STB ?,pcr|EXG ###,d',
    amAbsX_PID, LEAZX + STYB_Z,
    amAbsY_PID, LEAZY + STXB_Z], AInstruction[Length(AInstruction)]);
end;

procedure Insert_LDXY(const AAddrModes: TAddrMode6502s; var ASource: OAsmSource;
  var AIndex: integer; const AInstruction: string);
begin
  Insert_ASM(AAddrModes, ASource, AIndex, [
    amImme, 'LDA #?|STA 16|LD### 15', amAbsM, 'LDA ?|STA 16|LD### 15',
    amAbsX, 'LDA ?,x|STA 16|LDY 15', amAbsY, 'LDA ?,y|STA 16|LDX 15',
    amAbsM_PID, 'LDA ?,pcr|STA 16|LD### 15',
    amAbsX_PID, LEAZX + 'EXG y,d|LDB [15]|EXG y,d',
    amAbsY_PID, LEAZY + 'EXG x,d|LDB [15]|EXG x,d'], AInstruction[Length(AInstruction)]);
end;

procedure Insert_LSA(const AAddrModes: TAddrMode6502s; var ASource: OAsmSource;
  var AIndex: integer; const AInstruction: string);
begin
  Insert_ASM(AAddrModes, ASource, AIndex, [
    amAccu, '###', amImme, '### #?', amAbsM, '### ?', amAbsX, '### ?,x', amAbsY, '### ?,y',
    amIndX, '### [?,x]',
    amIndY, 'PSHS b|LDD ?|EXG a,b|STD 15|TFR y,d|ADDD 15|STD 15|PULS b|### [15]',
    amAbsM_PID, '### ?,pcr',
    amAbsX_PID, LEAZX + '### [15]', amAbsY_PID, LEAZY + '### [15]',
    amIndX_PID, LEAZX + '### [15,x]',
    amIndY_PID, 'PSHS b|LDD ?,pcr|EXG a,b|STD 15|TFR y,d|ADDD 15|STD 15|PULS b|### [15]'],
    AInstruction);
end;

procedure Insert_PH(var ASource: OAsmSource; var AIndex: integer; const ARegister: string);
begin
  Insert_ASM([amImpl], ASource, AIndex, [amImpl, 'PSHS ###'], ARegister);
end;

procedure Insert_PL(var ASource: OAsmSource; var AIndex: integer; const ARegister: string);
begin
  Insert_ASM([amImpl], ASource, AIndex, [amImpl, 'PULS ###'], ARegister);
end;

procedure Translate6502(var ASrc: OAsmSource; var AIndex: integer);
var
  S: string;
begin
  S := UpperCase(ASrc.Items[AIndex].Inst);
  case S of
    'SEI', 'CLI', 'SEC', 'CLC', 'NOP', 'RTS', 'RTI': begin
      Insert_ASM([amImpl], ASrc, AIndex, [amImpl, '###'], S);
    end;
    'BCC', 'BCS', 'BEQ', 'BMI', 'BNE', 'BPL', 'BVC', 'BVS': begin
      Insert_ASM([amAbsM, amAbsM_PID], ASrc, AIndex, [amAbsM, '### ?', amAbsM_PID, '### ?'], S);
    end;
    'INX', 'INY': begin
      Insert_ASM([amImpl], ASrc, AIndex, [amImpl, 'EXG ###,d|ADDB #1|EXG ###,d'], S[3]);
    end;
    'DEX', 'DEY': begin
      Insert_ASM([amImpl], ASrc, AIndex, [amImpl, 'EXG ###,d|SUBB #1|EXG ###,d'], S[3]);
    end;
    'TAX', 'TAY': begin
      Insert_ASM([amImpl], ASrc, AIndex, [amImpl, 'CLRA|TFR d,###'], S[3]);
    end;
    'TXA', 'TYA': begin
      Insert_ASM([amImpl], ASrc, AIndex, [amImpl, 'TFR ###,d'], S[2]);
    end;
    'PHA': begin
      Insert_PH(ASrc, AIndex, 'b');
    end;
    'PLA': begin
      Insert_PL(ASrc, AIndex, 'b');
    end;
    'PHP': begin
      Insert_PH(ASrc, AIndex, 'cc');
    end;
    'PLP': begin
      Insert_PL(ASrc, AIndex, 'cc');
    end;
    'JMP': begin
      Insert_ASM([amAbsM, amAbsM_PID, amIndi, amIndi_PID], ASrc, AIndex,
        [amAbsM, 'JMP ?', amAbsM_PID, 'BRA ?', amIndi, 'JMP [?]', amIndi_PID, 'BRA [?]']);
    end;
    'JSR': begin
      Insert_ASM([amAbsM, amAbsM_PID, amIndi, amIndi_PID], ASrc, AIndex,
        [amAbsM, 'JSR ?', amAbsM_PID, 'BSR ?', amIndi, 'JSR [?]', amIndi_PID, 'BSR [?]']);
    end;
    'STX': begin
      Insert_STXY([amAbsM, amAbsM_PID, amAbsY, amAbsY_PID], ASrc, AIndex, S);
    end;
    'STY': begin
      Insert_STXY([amAbsM, amAbsM_PID, amAbsX, amAbsX_PID], ASrc, AIndex, S);
    end;
    'LDX': begin
      Insert_LDXY([amImme, amAbsM, amAbsM_PID, amAbsY, amAbsY_PID], ASrc, AIndex, S);
    end;
    'LDY': begin
      Insert_LDXY([amImme, amAbsM, amAbsM_PID, amAbsX, amAbsX_PID], ASrc, AIndex, S);
    end;
    'ASL', 'ROL', 'ROR', 'LSR': begin
      Insert_LSA([amImpl, amAccu, amAbsM, amAbsM_PID, amAbsX, amAbsX_PID], ASrc, AIndex, S + 'B');
    end;
    'LDA', 'STA', 'ORA': begin
      Insert_LSA([amImme, amAbsM, amAbsM_PID, amAbsX, amAbsX_PID, amAbsY, amAbsY_PID,
        amIndX, amIndX_PID, amIndY, amIndY_PID], ASrc, AIndex, S[1] + S[2] + 'B');
    end;
    'ADC', 'SBC', 'AND', 'EOR': begin
      Insert_LSA([amImme, amAbsM, amAbsM_PID, amAbsX, amAbsX_PID, amAbsY, amAbsY_PID,
        amIndX, amIndX_PID, amIndY, amIndY_PID], ASrc, AIndex, S + 'B');
    end;
    'INC', 'DEC': begin
      Insert_LSA([amAbsM, amAbsM_PID, amAbsX, amAbsX_PID], ASrc, AIndex, S);
    end;
    'FCB', 'FDB': begin
    end else begin
      OCmoc.RaiseError(SUnknownMnemonic, S);
    end;
  end;
end;

end.
