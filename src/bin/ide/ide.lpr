program ide;

{$mode objfpc}{$H+}

uses
 {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
    {$ENDIF}  {$ENDIF}
  Forms,
  Interfaces, // this includes the LCL widgetset
  lazmouseandkeyinput,
  UCmocIDE,
  unitcmocidesynedit { you can add units after this },
  UnitCmocIDE;

{$R *.res}

begin
  Application.Title:='WinCMOC IDE v0.6';
  RequireDerivedFormResource := True;
  Application.Initialize;
  Application.CreateForm(TFormCmocIDE, FormCmocIDE);
  Application.CreateForm(TFormCmocIDESynEdit, FormCmocIDESynEdit);
  Application.Run;
end.
