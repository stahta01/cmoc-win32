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

unit UCmocAPP;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, StrUtils, SysUtils, UCmocAsm, UCmocAsmSplit, UCmocDefs, UCmocPreprocessor,
  UCmocStrings, UCmocUtils;

type


  CCmocAPP = class(CCmocPreprocessorBase)
  strict private
    FAsmCode, FExportSymbols, FExternSymbols: TStrings;
  strict private
    procedure AddImport(const ASymbol: string);
    procedure AddExport(const ASymbol: string);
    procedure TrimSource;
    procedure ExtractSymbols;
    function FindGlobalValues(const ASymbol: string): TCmocGlobalValues;
    procedure SetGlobalInitSymbol(const AName: string);
    procedure ResetSymbols;
  protected
    procedure Preprocess(const ADst, ASrc: TStrings); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  public
    FInitSymbol: string;
  end;

implementation

constructor CCmocAPP.Create(AOwner: TComponent);
begin
  inherited;
  FExportSymbols := TStringList.Create;
  with TStringList(FExportSymbols) do begin
    Sorted := True;
    CaseSensitive := True;
    Duplicates := dupIgnore;
  end;
  FExternSymbols := TStringList.Create;
  with TStringList(FExternSymbols) do begin
    Sorted := True;
    CaseSensitive := True;
    Duplicates := dupIgnore;
  end;
end;

destructor CCmocAPP.Destroy;
begin
  FreeAndNil(FExportSymbols);
  FreeAndNil(FExternSymbols);
  inherited;
end;

procedure CCmocAPP.ResetSymbols;
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

procedure CCmocAPP.AddImport(const ASymbol: string);
begin
  FExternSymbols.Add(ASymbol);
end;

procedure CCmocAPP.AddExport(const ASymbol: string);
begin
  FExportSymbols.Add(ASymbol);
end;

procedure CCmocAPP.TrimSource;
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

procedure CCmocAPP.ExtractSymbols;
var
  LIndex: integer;
  LParser: OAsmParser;
  LSym, LCmd, LPar: string;
begin
  for  LIndex := 0 to FAsmCode.Count - 1 do begin
    if AsmSplit(FAsmCode[LIndex], LSym, LCmd, LPar) then begin
      if OCmoc.SymbolIsPublic(LSym) then begin
        AddExport(LSym);
      end;
      if SameText(LCmd, 'RMB') then begin
        FAsmCode[LIndex] := LSym + Char_TAB + 'ZMB' + Char_TAB + LPar;
      end;
    end;
  end;
  for LIndex := 0 to FAsmCode.Count - 1 do begin
    if AsmSplit(FAsmCode[LIndex], LSym, LCmd, LPar) then begin
      LParser.SetString(LPar);
      while LParser.Next do begin
        LSym := LParser.Token;
        if OCmoc.SymbolIsPublic(LSym) and (FExportSymbols.IndexOf(LSym) < 0) then begin
          AddImport(LSym);
        end;
      end;
    end;
  end;
end;

function CCmocAPP.FindGlobalValues(const ASymbol: string): TCmocGlobalValues;
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

procedure CCmocAPP.SetGlobalInitSymbol(const AName: string);
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

procedure CCmocAPP.Preprocess(const ADst, ASrc: TStrings);
var
  LSymbol: string;
begin
  FAsmCode := ASrc;
  TrimSource;
  ResetSymbols;
  SetGlobalInitSymbol(FInitSymbol);
  ExtractSymbols;
  for LSymbol in FExternSymbols do begin
    FAsmCode.Insert(0, Asm_EXTERN(LSymbol));
  end;
  for LSymbol in FExportSymbols do begin
    FAsmCode.Insert(0, Asm_EXPORT(LSymbol));
  end;
  FAsmCode._InsertStrings(0, [Char_TAB +
    'PRAGMA' + Char_TAB + '6809,6800compat,6809conv,m80ext,shadow,autobranchlength',
    'jsrbas' + Char_TAB + 'MACRO', Char_TAB + 'pshs u', Char_TAB + 'jsr \1',
    Char_TAB + 'puls u', Char_TAB + 'ENDM',
    Asm_SECTION]);
  FAsmCode.Add(Asm_ENDSECTION);
  OCmoc.StringsInsertWinCMOCHeader(FAsmCode);
  ADst.Assign(FAsmCode);
end;

end.
