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

unit UCmocAsm;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, SysUtils, UCmocDefs, UCmocUtils;

const

  Asm_SECTION = Char_TAB + 'SECTION' + Char_TAB + 'SECTION_NAME';
  Asm_ENDSECTION = Char_TAB + 'ENDSECTION';

function Asm_SYMBOL(const AName: string; const AValue: string = '*'): string;
function Asm_EXPORT(const AName: string): string;
function Asm_EXTERN(const AName: string): string;

implementation

function Asm_SYMBOL(const AName, AValue: string): string;
begin
  Result := AName + Char_TAB + AValue;
end;

function Asm_EXTERN(const AName: string): string;
begin
  Result := Asm_SYMBOL(AName, 'EXTERN');
end;

function Asm_EXPORT(const AName: string): string;
begin
  Result := Asm_SYMBOL(AName, 'EXPORT');
end;

end.

