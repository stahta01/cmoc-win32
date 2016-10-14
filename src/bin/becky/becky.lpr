program becky;

{$mode objfpc}{$H+}

uses
  Classes,
  FpHttpClient,
  SSockets,
  SysUtils,
  UBeckyServer,
  UBeckyStream;

{$R *.res}


  procedure Main;
  begin
    with TBeckyServer.Create('127.0.0.1', 65504) do begin
      try
        WriteLn('Becky Server');
        WriteLn('Binding');
        Bind;
        while True do begin
          try
            StartAccepting;
          except
          end;
          WriteLn('Disconnected');
        end;
      finally
        Free;
      end;
    end;
  end;

begin
  try
    Main;
  except
    on E: Exception do begin
      WriteLn(E.Message);
    end;
  end;
  ReadLn;
end.
