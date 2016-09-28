program app;

{$mode objfpc}{$H+}

uses
  Classes,
  UCmocAPP,
  UCmocPreprocessor;

{$R *.res}

begin
  try
    with CCmocAPP.Create do begin
      try
        Preprocess(System.Output, System.Input);
      finally
        Free;
      end;
    end;
  except
  end;
end.
