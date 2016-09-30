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
  Classes, StrUtils, SysUtils, U6502, UCmocAsmParser, UCmocDefs, UCmocPreprocessor,
  UCmocUtils;

type

  CAmoc = class(CCmocPreprocessorBase)
  strict private
    FSource: OAsmSource;
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

constructor CAmoc.Create(AOwner: TComponent);
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

destructor CAmoc.Destroy;
begin
  FreeAndNil(FExportSymbols);
  FreeAndNil(FExternSymbols);
  inherited;
end;

procedure CAmoc.ResetSymbols;
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

procedure CAmoc.AddImport(const ASymbol: string);
begin
  FExternSymbols.Add(ASymbol);
end;

procedure CAmoc.AddExport(const ASymbol: string);
begin
  FExportSymbols.Add(ASymbol);
end;

procedure CAmoc.TrimSource;
var
  LIndex: integer;
begin
  for LIndex := 0 to FSource.Count - 1 do begin
    FSource.Lines[LIndex].Deleted := not FSource.Lines[LIndex].IsSym(Sym_FunctionsStart);
    if not FSource.Lines[LIndex].Deleted then begin
      break;
    end;
  end;
  for LIndex := FSource.Count - 1 downto 0 do begin
    FSource.Lines[LIndex].Deleted := not FSource.Lines[LIndex].IsSym(Sym_ProgramEnd);
    if not FSource.Lines[LIndex].Deleted then begin
      break;
    end;
  end;
  for LIndex := 0 to FSource.Count - 1 do begin
    if AnsiMatchText(FSource.Lines[LIndex].Sym, ['program_end', 'functions_start',
      'functions_end',
      'string_literals_start', 'string_literals_end', 'writable_globals_start',
      'writable_globals_end']) then begin
      FSource.Lines[LIndex].Deleted := True;
    end;
  end;
end;

procedure CAmoc.ExtractSymbols;
var
  LIndex: integer;
  LString: string;
  LParser: OAsmParser;
begin
  for LIndex := 0 to FSource.Count - 1 do begin
    if SymbolIsPublic(FSource.Lines[LIndex].Sym) then begin
      AddExport(FSource.Lines[LIndex].Sym);
    end;
    if FSource.Lines[LIndex].IsIns('RMB') then begin
      FSource.Lines[LIndex].Ins := 'ZMB';
    end;
  end;
  for LIndex := 0 to FSource.Count - 1 do begin
    LParser.SetString(FSource.Lines[LIndex].Par);
    while LParser.Next do begin
      LString := LParser.Token;
      if SymbolIsPublic(LString) and (FExportSymbols.IndexOf(LString) < 0) then begin
        AddImport(LString);
      end;
    end;
  end;
end;

procedure CAmoc.SetGlobalInitSymbol(const AName: string);
var
  LIndex: integer;
begin
  for LIndex := FSource.Count - 2 downto 0 do begin
    if AnsiStartsStr(Sym_INITGL, FSource.Lines[LIndex].Sym) then begin
      if FSource.Lines[LIndex + 1].IsIns('rts') then begin
        FSource.Lines[LIndex + 0].Deleted := True;
        FSource.Lines[LIndex + 1].Deleted := True;
      end else begin
        FSource.Lines[LIndex].Sym := AName;
        AddExport(AName);
      end;
      Break;
    end;
  end;
end;

procedure CAmoc.Preprocess(const ADst, ASrc: TStrings);
var
  LSymbol: string;
begin
  FSource.AsmAddStrings(ASrc);
  TrimSource;
  ResetSymbols;
  SetGlobalInitSymbol(FInitSymbol);
  ExtractSymbols;
  for LSymbol in FExternSymbols do begin
    FSource.Insert(0, LSymbol, 'extern', EmptyStr);
  end;
  for LSymbol in FExportSymbols do begin
    FSource.Insert(0, LSymbol, 'export', EmptyStr);
  end;
  FSource.Insert(0, EmptyStr, 'pragma',
    '6809,6800compat,6809conv,m80ext,shadow,autobranchlength');
  FSource.Insert(1, 'jsrbas', 'macro', EmptyStr);
  FSource.Insert(2, EmptyStr, 'pshs', 'u');
  FSource.Insert(3, EmptyStr, 'jsr', '\1');
  FSource.Insert(4, EmptyStr, 'puls', 'u');
  FSource.Insert(5, EmptyStr, 'endm', EmptyStr);
  FSource.Insert(6, EmptyStr, 'section', 'SECTION_NAME');
  FSource.Add(EmptyStr, 'endsection', EmptyStr);
  M6502Translate(FSource);
  FSource.SaveToStrings(ADst);
end;

end.
