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

unit UCmocSynEdit;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, Controls, Dialogs, Graphics, LazSynEditText, StdCtrls, StrUtils,
  SynEdit, SynEditHighlighter, SynEditLines, SynEditTypes, SysUtils;

type

  TSynEditNotifyReason = LazSynEditText.TSynEditNotifyReason;
  TSynEditStrings = LazSynEditText.TSynEditStrings;

  TSynEditHelper = class helper for TSynEdit
  public
    procedure _SetCaretYCentered(const ACaretY: integer);
  public
    procedure _ChangeText(const AText: string);
  public
    function _FindReplace(const AFindText, AReplaceText: string;
      const AOptions: TSynSearchOptions): integer;
    function _Find(const A: TFindDialog): integer;
    function _Replace(const A: TReplaceDialog): integer;
  public
    procedure _SetSelText(const AText: string);
    procedure _UpperCaseSelText;
    procedure _LowerCaseSelText;
  end;

  CSynEdit = class(TSynEdit)
  strict private
    FFileName: TFileName;
  strict private
    procedure SetFileName(const AFileName: TFileName);
  public
    constructor Create(AOwner: TComponent); override;
  public
    procedure LoadFromFile(const AFileName: TFileName);
    procedure SaveToFile(const AFileName: TFileName);
    function GetStrings: TSynEditLines;
  public
    property FileName: TFileName read FFileName write SetFileName;
  end;

implementation

const

  _SearchStringNotFound1 = 'Search string ''%s'' not found.';
  _SearchCompletedRestart1 = 'Search completed. Do you want to restart from the %s?';

procedure TSynEditHelper._SetCaretYCentered(const ACaretY: integer);
begin
  CaretY := ACaretY - (LinesInWindow div 2) + 1;
  CaretY := ACaretY + (LinesInWindow div 2) - 1;
  CaretY := ACaretY;
end;

procedure TSynEditHelper._ChangeText(const AText: string);
var
  LCaretXY: TPoint;
begin
  if Text <> AText then begin
    LCaretXY := CaretXY;
    BeginUndoBlock;
    try
      SelectAll;
      SelText := AText;
    finally
      EndUndoBlock;
    end;
    CaretXY := LCaretXY;
  end;
end;

function TSynEditHelper._FindReplace(const AFindText, AReplaceText: string;
  const AOptions: TSynSearchOptions): integer;
var
  LCaretXY: TPoint;
begin
  Result := SearchReplace(AFindText, AReplaceText, AOptions);
  if Result = 0 then begin
    if MessageDlg(Format(_SearchCompletedRestart1, [IfThen(ssoBackwards in AOptions,
      'end', 'beginning')]), mtConfirmation, [mbYes, mbNo], 0) = mrYes then begin
      LCaretXY := CaretXY;
      if ssoBackwards in AOptions then begin
        CaretXY := Point(MaxInt, MaxInt);
      end else begin
        CaretXY := Point(0, 0);
      end;
      Result := SearchReplace(AFindText, default(string), AOptions);
      if Result = 0 then begin
        CaretXY := LCaretXY;
        MessageDlg(Format(_SearchStringNotFound1, [AFindText]), mtInformation, [mbOK], 0);
      end;
    end;
  end;
end;

function SynSearchOptions(const AOptions: TFindOptions): TSynSearchOptions;
begin
  Result := [];
  if not (frDown in AOptions) then begin
    Result += [ssoBackwards];
  end;
  if not (frEntireScope in AOptions) then begin
    Result += [ssoSelectedOnly];
  end;
  if frWholeWord in AOptions then begin
    Result += [ssoWholeWord];
  end;
  if frMatchCase in AOptions then begin
    Result += [ssoMatchCase];
  end;
  if frReplace in AOptions then begin
    Result += [ssoReplace];
  end;
  if frReplaceAll in AOptions then begin
    Result += [ssoReplaceAll];
  end;
end;

function TSynEditHelper._Find(const A: TFindDialog): integer;
begin
  Result := _FindReplace(A.FindText, default(string), SynSearchOptions(A.Options));
end;

function TSynEditHelper._Replace(const A: TReplaceDialog): integer;
begin
  Result := _FindReplace(A.FindText, A.ReplaceText, SynSearchOptions(A.Options));
end;

procedure TSynEditHelper._SetSelText(const AText: string);
var
  LBlock: TRect;
begin
  LBlock.TopLeft := BlockBegin;
  LBlock.BottomRight := BlockEnd;
  SelText := AText;
  BlockBegin := LBlock.TopLeft;
  BlockEnd := LBlock.BottomRight;
end;

procedure TSynEditHelper._UpperCaseSelText;
begin
  _SetSelText(UpperCase(SelText));
end;

procedure TSynEditHelper._LowerCaseSelText;
begin
  _SetSelText(LowerCase(SelText));
end;

constructor CSynEdit.Create(AOwner: TComponent);
begin
  inherited;
  ScrollBars := ssAutoBoth;
end;

procedure CSynEdit.SetFileName(const AFileName: TFileName);
begin
  FFileName := AFileName;
  Modified := False;
  if Assigned(OnStatusChange) then begin
    OnStatusChange(Self, [scCaretX, scCaretY, scModified, scInsertMode]);
  end;
end;

procedure CSynEdit.LoadFromFile(const AFileName: TFileName);
begin
  Lines.LoadFromFile(AFileName);
  SetFileName(AFileName);
end;

procedure CSynEdit.SaveToFile(const AFileName: TFileName);
begin
  Lines.SaveToFile(AFileName);
  SetFileName(AFileName);
end;

function CSynEdit.GetStrings: TSynEditLines;
begin
  Result := Lines as TSynEditLines;
end;

end.
