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

unit UCmocPlatform;

{$INCLUDE cmoc.inc}

interface

uses StrUtils;

type
  OPlatform = object
  public
    class function IsDev: boolean;
    class function IsLinux: boolean;
    class function IsWindows: boolean;
  end;

implementation

class function OPlatform.IsDev: boolean;
begin
  Result := AnsiStartsText('c:\dev\', ParamStr(0));
end;

class function OPlatform.IsLinux: boolean;
begin
  {$ifdef LINUX}
  Result := True;
  {$else}
  Result := False;
  {$endif}
end;

class function OPlatform.IsWindows: boolean;
begin
  {$ifdef WINDOWS}
  Result := True;
  {$else}
  Result := False;
  {$endif}
end;

end.

