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

unit AmocProcess;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, StrUtils, SysUtils, UCmocAsmParser, UCmocDefs, UCmocPreprocessor,
  UCmocUtils;

type

  CCmocPreprocessor_ASM = class(CCmocPreprocessorBase)
  strict private
    FItems: OAsmItems;
    FExportSymbols, FExternSymbols: TStrings;
  strict private
    procedure AddImport(const ASymbol: string);
    procedure AddExport(const ASymbol: string);
    procedure TrimSource;
    procedure ExtractSymbols;
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

constructor CCmocPreprocessor_ASM.Create(AOwner: TComponent);
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

destructor CCmocPreprocessor_ASM.Destroy;
begin
  FreeAndNil(FExportSymbols);
  FreeAndNil(FExternSymbols);
  inherited;
end;

procedure CCmocPreprocessor_ASM.ResetSymbols;
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

procedure CCmocPreprocessor_ASM.AddImport(const ASymbol: string);
begin
  FExternSymbols.Add(ASymbol);
end;

procedure CCmocPreprocessor_ASM.AddExport(const ASymbol: string);
begin
  FExportSymbols.Add(ASymbol);
end;

procedure CCmocPreprocessor_ASM.TrimSource;
var
  LIndex: integer;
begin
  for LIndex := 0 to FItems.Count - 1 do begin
    FItems.Items[LIndex].Deleted := not FItems.Items[LIndex].IsSym(Sym_FunctionsStart);
    if not FItems.Items[LIndex].Deleted then begin
      break;
    end;
  end;
  for LIndex := FItems.Count - 1 downto 0 do begin
    FItems.Items[LIndex].Deleted := not FItems.Items[LIndex].IsSym(Sym_ProgramEnd);
    if not FItems.Items[LIndex].Deleted then begin
      break;
    end;
  end;
end;

procedure CCmocPreprocessor_ASM.ExtractSymbols;
var
  LIndex: integer;
  LString: string;
  LParser: OAsmParser;
begin
  for LIndex := 0 to FItems.Count - 1 do begin
    if SymbolIsPublic(FItems.Items[LIndex].Sym) then begin
      AddExport(FItems.Items[LIndex].Sym);
    end;
    if FItems.Items[LIndex].IsCmd('RMB') then begin
      FItems.Items[LIndex].Cmd := 'ZMB';
    end;
  end;
  for LIndex := 0 to FItems.Count - 1 do begin
    LParser.SetString(FItems.Items[LIndex].Par);
    while LParser.Next do begin
      LString := LParser.Token;
      if SymbolIsPublic(LString) and (FExportSymbols.IndexOf(LString) < 0) then begin
        AddImport(LString);
      end;
    end;
  end;
end;

procedure CCmocPreprocessor_ASM.SetGlobalInitSymbol(const AName: string);
var
  LIndex: integer;
begin
  for LIndex := FItems.Count - 2 downto 0 do begin
    if AnsiStartsStr(Sym_INITGL, FItems.Items[LIndex].Sym) then begin
      if FItems.Items[LIndex + 1].IsCmd('RTS') then begin
        FItems.Items[LIndex].Deleted := True;
        FItems.Items[LIndex + 1].Deleted := True;
      end else begin
        FItems.Items[LIndex].Sym := AName;
        AddExport(AName);
      end;
      Break;
    end;
  end;
end;

procedure CCmocPreprocessor_ASM.Preprocess(const ADst, ASrc: TStrings);
var
  LSymbol: string;
begin
  FItems.AddSourceLines(ASrc);
  TrimSource;
  ResetSymbols;
  SetGlobalInitSymbol(FInitSymbol);
  ExtractSymbols;
  for LSymbol in FExternSymbols do begin
    FItems.Insert(0, LSymbol, 'EXTERN', EmptyStr);
  end;
  for LSymbol in FExportSymbols do begin
    FItems.Insert(0, LSymbol, 'EXPORT', EmptyStr);
  end;
  FItems.Insert(0, EmptyStr, 'PRAGMA', '6809,6800compat,6809conv,m80ext,shadow,autobranchlength');
  FItems.Insert(1, 'jsrbas', 'MACRO', EmptyStr);
  FItems.Insert(2, EmptyStr, 'pshs', 'u');
  FItems.Insert(3, EmptyStr, 'jsr', '\1');
  FItems.Insert(4, EmptyStr, 'puls', 'u');
  FItems.Insert(5, EmptyStr, 'ENDM', EmptyStr);
  FItems.Insert(6, EmptyStr, 'SECTION', 'SECTION_NAME');
  FItems.Add(EmptyStr, 'ENDSECTION', EmptyStr);

  FItems.SaveToStrings(ADst);
end;

end.
