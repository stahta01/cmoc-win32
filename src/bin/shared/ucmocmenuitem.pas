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

unit UCmocMenuItem;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, Menus, SysUtils;

type
  TMenuItemHelper = class helper for TMenuItem
  public
    procedure _HideDuplicateSeperators;
    procedure _SetVisible(const AVisible: boolean);
  end;

implementation

procedure TMenuItemHelper._HideDuplicateSeperators;
var
  LIndex, LVisibleIndex: integer;
begin
  LVisibleIndex := 0;
  for LIndex := 0 to Count - 1 do begin
    if Items[LIndex].Caption = '-' then begin
      Items[LIndex].Visible := (LVisibleIndex > 0) and (LIndex < Count - 1) and
        (Items[LIndex + 1].Caption <> '-');
    end;
    if Items[LIndex].Visible then begin
      Inc(LVisibleIndex);
    end;
  end;
end;

procedure TMenuItemHelper._SetVisible(const AVisible: boolean);
begin
  Visible := AVisible;
  if Assigned(Parent) then begin
    Parent._HideDuplicateSeperators;
  end;
end;

end.
