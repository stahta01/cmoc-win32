{
 ***************************************************************************
 *                                                                         *
 *   This source is free software; you can redistribute it and/or modify   *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This code is distributed in the hope that it will be useful, but      *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   General Public License for more details.                              *
 *                                                                         *
 *   A copy of the GNU General Public License is available on the World    *
 *   Wide Web at <http://www.gnu.org/copyleft/gpl.html>. You can also      *
 *   obtain it by writing to the Free Software Foundation,                 *
 *   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.        *
 *                                                                         *
 ***************************************************************************
}

unit UCmocProcess_ASM;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, StrUtils, SysUtils, UCmocAsm, UCmocProcess_TOOLS, UCmocUtils;

type

  CCmocProcess_ASM = class(CCmocProcess_TOOLS)
  strict private
    FAsmCode, FExportSymbols, FExternSymbols: TStringList;
  strict private
    procedure TrimSource;
    procedure ExtractSymbols;
    function FindGlobalValues(const ASymbol: string): TCmocGlobalValues;
    procedure SetGlobalInitSymbol(const AName: string);
    procedure ResetSymbols;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  strict private
    procedure AddImport(const ASymbol: string);
    procedure AddExport(const ASymbol: string);
  public
    procedure CMOC2(const ADst, ASrc: TFileName; const AInitSymbol: string);
  end;

implementation

constructor CCmocProcess_ASM.Create(AOwner: TComponent);
begin
  inherited;
  FAsmCode := TStringList.Create;

  FExportSymbols := TStringList.Create;
  FExportSymbols.Sorted := True;
  FExportSymbols.CaseSensitive := True;
  FExportSymbols.Duplicates := dupIgnore;

  FExternSymbols := TStringList.Create;
  FExternSymbols.Sorted := True;
  FExternSymbols.CaseSensitive := True;
  FExternSymbols.Duplicates := dupIgnore;
end;

destructor CCmocProcess_ASM.Destroy;
begin
  FreeAndNil(FAsmCode);
  FreeAndNil(FExportSymbols);
  FreeAndNil(FExternSymbols);
  inherited;
end;

procedure CCmocProcess_ASM.ResetSymbols;
begin
  FExportSymbols.Clear;
  FExternSymbols.Clear;

  AddImport('DIV16'); // YES
  AddImport('DIV16BY10'); // YES
  AddImport('DIV8'); // YES
  AddImport('DIV8BY7'); // YES
  AddImport('MUL16'); // YES
  AddImport('SDIV16'); // YES
  AddImport('SDIV8'); // YES

  //AddImport('MUL168_TO24');
  //AddImport('MUL168_TO32');

  AddImport('shiftByteLeft');
  AddImport('shiftByteRightSigned');
  AddImport('shiftByteRightUnsigned');
  AddImport('shiftLeft');
  AddImport('shiftRightSigned');
  AddImport('shiftRightSigned');
  AddImport('shiftRightUnsigned');

end;

procedure CCmocProcess_ASM.AddImport(const ASymbol: string);
begin
  FExternSymbols.Add(ASymbol);
end;

procedure CCmocProcess_ASM.AddExport(const ASymbol: string);
begin
  FExportSymbols.Add(ASymbol);
end;

procedure CCmocProcess_ASM.TrimSource;
var
  LIndex: integer;
  LLine: string;
begin
  for LIndex := FAsmCode.Count - 1 downto 0 do begin
    LLine := TrimLeft(FAsmCode[LIndex]);
    if (Length(LLine) = 0) or (LLine[1] in ['#', '*']) then begin
      FAsmCode.Delete(LIndex);
    end;
  end;
  if FAsmCode.Count > 0 then begin
    repeat
      LLine := FAsmCode[0];
      FAsmCode.Delete(0);
    until (FAsmCode.Count = 0) or AnsiContainsStr(LLine, Sym_FunctionsStart);
  end;
  if FAsmCode.Count > 0 then begin
    repeat
      LLine := FAsmCode[FAsmCode.Count - 1];
      FAsmCode.Delete(FAsmCode.Count - 1);
    until (FAsmCode.Count = 0) or AnsiContainsStr(LLine, Sym_ProgramEnd);
  end;
end;

procedure CCmocProcess_ASM.ExtractSymbols;
var
  LIndex: integer;
  LToken: string;
  LParser, LParser2: OAsmParser;
begin
  LParser := default(OAsmParser);
  LParser2 := default(OAsmParser);
  for LIndex := 0 to FAsmCode.Count - 1 do begin
    LParser.SetString(FAsmCode[LIndex]);
    if LParser.Next then begin
      LToken := LParser.Token;
      if LToken[1] = '_' then begin
        if OCmoc.SymbolIsPublic(LToken) then begin
          AddExport(LToken);
        end;
      end else if SameText(LToken, 'RMB') then begin
        FAsmCode[LIndex] := Char_TAB + 'ZMB' + Char_TAB + Trim(LParser.Remaining);
      end else if LParser.Next and SameText(LToken, 'RMB') then begin
        FAsmCode[LIndex] := LToken + Char_TAB + 'ZMB' + Char_TAB + Trim(LParser.Remaining);
      end;
    end;
  end;
  for LIndex := 0 to FAsmCode.Count - 1 do begin
    LParser.SetString(FAsmCode[LIndex]);
    if LParser.Next and LParser.Next then begin
      LParser.IncludeUntil(CharSet_Space);
      LParser2.SetString(LParser.Token);
      while LParser2.Next do begin
        LToken := LParser2.Token;
        if OCmoc.SymbolIsPublic(LToken) and (FExportSymbols.IndexOf(LToken) < 0) then begin
          AddImport(LToken);
        end;
      end;
    end;
  end;
end;

function CCmocProcess_ASM.FindGlobalValues(const ASymbol: string): TCmocGlobalValues;
var
  LIndex: integer;
  LParser: OAsmParser;
  LVar: TCmocGlobalValue;
begin
  LParser := default(OAsmParser);
  Result := default(TCmocGlobalValues);
  for LIndex := 0 to FAsmCode.Count - 1 do begin
    LParser.SetString(FAsmCode[LIndex]);
    if LParser.Next then begin
      LVar := default(TCmocGlobalValue);
      case LParser.Token of
        'STB': begin
          LVar.Type_ := 'FCB';
        end;
        'STD', 'STX': begin
          LVar.Type_ := 'FDB';
        end;
      end;
      if LParser.NextAndTokenIs(ASymbol) and LParser.NextAndTokenIs('+') then begin
        LParser.Next;
        LVar.Offset := LParser.Token;
        LParser.SetString(FAsmCode[LIndex - 1]);
        LParser.Next;
        if LParser.SameText('LEAX') then begin
          if LParser.Next then begin
            LVar.Value := LParser.Token;
            Assert(LParser.NextAndTokenIs('+') and LParser.Next);
            LVar.Value := LVar.Value + '+' + LParser.Token;
          end;
        end else if LParser.SameText('TFR') then begin
          LParser.SetString(FAsmCode[LIndex - 2]);
          if LParser.NextAndTokenIs('LEAX') and LParser.Next then begin
            LVar.Value := LParser.Token;
            Assert(LParser.NextAndTokenIs('+') and LParser.Next);
            LVar.Value := LVar.Value + '+' + LParser.Token;
          end;
        end else if (LParser.SameText('LDB') or LParser.SameText('LDD')) then begin
          if LParser.NextAndTokenIs('#') and LParser.NextAndTokenIs('$') then begin
            if LParser.Next then begin
              LVar.Value := '$' + LParser.Token;
            end;
          end;
        end;
        if Length(LVar.Value) > 0 then begin
          SetLength(Result, Length(Result) + 1);
          Result[High(Result)] := LVar;
        end;
      end;
    end;
  end;
end;

procedure CCmocProcess_ASM.SetGlobalInitSymbol(const AName: string);
var
  LIndex: integer;
begin
  for LIndex := FAsmCode.Count - 2 downto 0 do begin
    if AnsiStartsStr(Sym_INITGL, FAsmCode[LIndex]) then begin
      if AnsiStartsStr('RTS', TrimLeft(FAsmCode[LIndex + 1])) then begin
        FAsmCode.Delete(LIndex);
        FAsmCode.Delete(LIndex);
      end else begin
        FAsmCode[LIndex] := Asm_SYMBOL(AName);
        AddExport(AName);
      end;
      Break;
    end;
  end;
end;

procedure CCmocProcess_ASM.CMOC2(const ADst, ASrc: TFileName; const AInitSymbol: string);
var
  LSymbol: string;
begin
  FAsmCode.LoadFromFile(ASrc);
  TrimSource;
  ResetSymbols;
  SetGlobalInitSymbol(AInitSymbol);
  ExtractSymbols;
  for LSymbol in FExternSymbols do begin
    FAsmCode.Insert(0, Asm_EXTERN(LSymbol));
  end;
  for LSymbol in FExportSymbols do begin
    FAsmCode.Insert(0, Asm_EXPORT(LSymbol));
  end;
  //FAsmCode.Insert(0, '#define RMB ZMB');
  FAsmCode.Insert(0, Asm_SECTION);
  FAsmCode.Add(Asm_ENDSECTION);
  OCmoc.StringsInsertWinCMOCHeader(FAsmCode);
  FAsmCode.SaveToFile(ADst);
end;

end.
