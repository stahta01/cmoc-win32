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

unit UCmocXRoar;

{$INCLUDE cmoc.inc}

interface

const

  Opt_XRoar_Run = '-run';
  Opt_XRoar_Load = '-load';
  Opt_XRoar_Machine = '-machine';
  Opt_XRoar_Bas = '-bas';
  Opt_XRoar_Cart = '-cart';
  Opt_XRoar_CartType = '-cart-type';
  Opt_XRoar_CartAutoRun = '-cart-autorun';
  Opt_XRoar_Dos = '-dos';
  Opt_XRoar_ExtBas = '-extbas';
  Opt_XRoar_NoDos = '-nodos';
  Opt_XRoar_NoExtBas = '-noextbas';
  Opt_XRoar_NoTapeFast = '-no-tape-fast';
  Opt_XRoar_Ram = '-ram';
  Opt_XRoar_Type = '-type';
  Opt_XRoar_CartBecker = '-cart-becker';
  Opt_XRoar_Becker = '-becker';
  Opt_XRoar_BeckerIp = '-becker-ip';
  Opt_XRoar_BeckerPort = '-becker-port';

var

  Opt_XRoar_All: array[0..15] of
  string = (Opt_XRoar_Machine, Opt_XRoar_Bas, Opt_XRoar_ExtBas, Opt_XRoar_Dos,
    Opt_XRoar_Cart, Opt_XRoar_CartType, Opt_XRoar_CartAutoRun, Opt_XRoar_NoExtBas,
    Opt_XRoar_NoDos, Opt_XRoar_Ram, Opt_XRoar_NoTapeFast, Opt_XRoar_Type,
    Opt_XRoar_CartBecker, Opt_XRoar_Becker, Opt_XRoar_BeckerIp, Opt_XRoar_BeckerPort);

implementation

end.
