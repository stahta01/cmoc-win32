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

unit UCmocPipe;

{$INCLUDE cmoc.inc}

interface

uses
  Classes, Process, SysUtils, UCmocProcess, UCmocUtils;

procedure PipeExecute(const AExecutable: TFileName; const AParameters: array of string;
  const ACurrentDirectory: TFileName; const AInput, AOutput, AStderr: TStream;
  const ASleep: cardinal = 20);

implementation

procedure PipeExecute(const AExecutable: TFileName; const AParameters: array of string;
  const ACurrentDirectory: TFileName; const AInput, AOutput, AStderr: TStream;
  const ASleep: cardinal);
var
  LBuffer: array[word] of byte;
  LCount: longint;
begin
  LBuffer[0] := 0;
  with TProcess.Create(nil) do begin
    try
      Options := [poUsePipes];
      ShowWindow := swoHIDE;
      Executable := AExecutable;
      CurrentDirectory := ACurrentDirectory;
      Parameters.AddStrings(AParameters);
      try
        Execute;
      except
        _CheckExitCode(2);
      end;
      if Assigned(AInput) then begin
        while Running and (Input.Write(LBuffer, AInput.Read(LBuffer, SizeOf(LBuffer))) > 0) do
        begin
          Sleep(ASleep);
        end;
      end;
      CloseInput;
      while Running or (Output.NumBytesAvailable > 0) or (Stderr.NumBytesAvailable > 0) do begin
        if Stderr.NumBytesAvailable > 0 then begin
          LCount := Stderr.Read(LBuffer, SizeOf(LBuffer));
          if Assigned(AStderr) then begin
            AStderr.Write(LBuffer, LCount);
          end;
        end;
        if Output.NumBytesAvailable > 0 then begin
          LCount := Output.Read(LBuffer, SizeOf(LBuffer));
          if Assigned(AOutput) then begin
            AOutput.Write(LBuffer, LCount);
          end;
        end;
        if (Stderr.NumBytesAvailable = 0) and (Output.NumBytesAvailable = 0) then begin
          Sleep(ASleep);
        end;
      end;
      _CheckExitCode(ExitCode);
    finally
      Free;
    end;
  end;
end;

end.
