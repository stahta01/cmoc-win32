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

unit UCmocDefs;

{$INCLUDE cmoc.inc}

interface

const

  Ver_CMOC = '0.1.32';
  Ver_LWTOOLS = '4.13';

  Char_SPC = char(#32);
  Char_TAB = char(#9);

  CharSet_Space = [#0..#32, #127..#255];
  CharSet_Alpha = ['a'..'z', 'A'..'Z'];
  CharSet_Digit = ['0'..'9'];
  CharSet_XDigit = CharSet_Digit + ['a'..'f', 'A'..'F'];
  CharSet_IdentHead = CharSet_Alpha + ['_'];
  CharSet_IdentBody = CharSet_IdentHead + CharSet_Digit;
  CharSet_SymbolHead = CharSet_IdentHead + ['.'];
  CharSet_SymbolBody = CharSet_IdentBody + ['.', '$'];

  FileExt_O = '.o';
  FileExt_I = '.i';
  FileExt_OBJ = '.obj';
  FileExt_C = '.c';
  FileExt_A = '.a';
  FileExt_ROM = '.rom';
  FileExt_WAV = '.wav';
  FileExt_CAS = '.cas';
  FileExt_BIN = '.bin';
  FileExt_ASM = '.asm';
  FileExt_EXE = '.exe';
  FileExt_RAW = '.raw';
  FileExt_SREC = '.srec';

  Tool_CMOC = 'cmoc';
  Tool_CMOC2 = 'cmoc2';
  Tool_BCPP = 'bcc-cpp';
  Tool_MCPP = 'mcpp';
  Tool_LWASM = 'lwasm';
  Tool_LWASM2 = 'lwasm2';
  Tool_LWLINK = 'lwlink';
  Tool_LWAR = 'lwar';
  Tool_ASTYLE = 'astyle';
  Tool_WIMGTOOL = 'wimgtool';
  Tool_CMOCIDE = 'cmocide';
  Tool_F9DASM = 'f9dasm';

  Origin_DEFAULT = $2800;

  Target_COCO = 'coco';
  Target_DRAGON = 'dragon';

  Machine_COCOUS = 'cocous';
  Machine_COCO3 = 'coco3';
  Machine_DRAGON64 = 'dragon64';

  Format_OBJ = 'obj';
  Format_RAW = 'raw';
  Format_DECB = 'decb';
  Format_SREC = 'srec';
  Format_WAV = 'wav';
  Format_CAS = 'cas';

  Opt_ScriptFile2 = '-s';
  Opt_MapFile2 = '-m';
  Opt_6809 = '--6809';
  Opt_6800compat = '--6800compat';
  Opt_DontLink1 = '-c';
  Opt_Create1 = '--create';
  Opt_Add1 = '--add';
  Opt_Define2 = '-D';
  Opt_EmitUncalled1 = '--emit-uncalled';
  Opt_Entry2 = '-e';
  Opt_Format2 = '-f';
  Opt_Help1 = '--help';
  Opt_Include2 = '-I';
  Opt_Optimize0 = '-O0';
  Opt_Optimize2 = '-O2';
  Opt_Origin2 = '--org';
  Opt_LibPath2 = '-L';
  Opt_LibInclude2 = '-l';
  Opt_Output2 = '-o';
  Opt_Target2 = '-t';
  Opt_NoAddr1 = '-noaddr';
  Opt_Out2 = '-out';
  Opt_Verbose1 = '-V';
  Opt_Werror1 = '-Werror';
  Opt_NoLineInfo1 = '-P';
  Opt_DontAssemble1 = '-S';
  Opt_Machine2 = '-machine';
  Opt_NoTapeFast1 = '-no-tape-fast';
  Opt_NoDos1 = '-nodos';
  Opt_NoExtBas1 = '-noextbas';
  Opt_Offset2 = '-offset';
  Opt_Cart2 = '-cart';
  Opt_Bas2 = '-bas';
  Opt_Ram2 = '-ram';
  Opt_ExtBas2 = '-extbas';
  Opt_Dos2 = '-dos';
  Opt_Type2 = '-type';
  Opt_Load2 = '-load';
  Opt_NoCode1 = '-nocode';
  Opt_NoMaximize1 = '-nomaximize';

  Def_CMOC = '__CMOC__';
  Def_DATE = '__DATE__';
  Def_FILE = '__FILE__';
  Def_6809 = '__6809__';

  Sym_ProgramStart = 'program_start';
  Sym_ProgramEnd = 'program_end';
  Sym_FunctionsStart = 'functions_start';
  Sym_WritableGlobalsStart = 'writable_globals_start';
  Sym_INITGL = 'INITGL';
  Sym_INITLIB = 'INITLIB';

  Env_PATH = 'PATH';
  Env_PKGDATADIR = 'PKGDATADIR';

implementation

end.

