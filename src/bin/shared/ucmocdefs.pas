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

unit UCmocDefs;

{$INCLUDE cmoc.inc}

interface

const

  Ver_CMOC = '0.1.33';
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
  Tool_AMOC = 'amoc';
  Tool_BCPP = 'bcc-cpp';
  Tool_MCPP = 'mcpp';
  Tool_LWASM = 'lwasm';
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

  //Opt_6800compat = '--6800compat';
  //Opt_6809 = '--6809';
  Opt_Add1 = '--add';
  Opt_Create1 = '--create';
  Opt_Define2 = '-D';
  Opt_DontAssemble1 = '-S';
  Opt_DontLink1 = '-c';
  Opt_EmitUncalled1 = '--emit-uncalled';
  Opt_Entry2 = '-e';
  Opt_Format2 = '-f';
  Opt_Help1 = '--help';
  Opt_Include2 = '-I';
  Opt_InitGL1 = '--initgl';
  Opt_LibInclude2 = '-l';
  Opt_LibPath2 = '-L';
  Opt_Linkin1 = '--linkin';
  Opt_MapFile2 = '-m';
  Opt_NoAddr1 = '-noaddr';
  Opt_NoCode1 = '-nocode';
  Opt_NoLineInfo1 = '-P';
  Opt_NoMaximize1 = '-nomaximize';
  Opt_O = '-O';
  Opt_O0 = Opt_O + '0';
  Opt_O1 = Opt_O + '1';
  Opt_O2 = Opt_O + '2';
  Opt_Offset2 = '-offset';
  Opt_Optimize = '--optimize';
  Opt_Origin2 = '--org';
  Opt_Out2 = '-out';
  Opt_Output2 = '-o';
  Opt_ScriptFile2 = '-s';
  Opt_Target2 = '-t';
  Opt_Verbose1 = '-V';
  Opt_Werror1 = '-Werror';


  Def_CMOC = '__CMOC__';
  Def_DATE = '__DATE__';
  Def_FILE = '__FILE__';

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

