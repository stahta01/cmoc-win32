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

unit UCmocCharSet;

{$INCLUDE cmoc.inc}

interface

type
  OCharSet = object
  const
    All = [#0..#255];
    Ascii = [#0..#127];
    Cntrl = [#0..#31, #127];
    Digit = ['0'..'9'];
    XLower = Digit + ['a'..'f'];
    XUpper = Digit + ['A'.. 'F'];
    XDigit = XLower + XUpper;
    Lower = ['a'..'z'];
    Upper = ['A'..'Z'];
    Alpha = Lower + Upper;
    Alnum = Alpha + Digit;
    Print = [#32..#126];
    Graph = Print - [#32];
  end;

implementation

end.
