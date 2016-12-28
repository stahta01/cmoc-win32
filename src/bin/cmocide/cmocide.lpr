program cmocide;

{$mode objfpc}{$H+}

uses
  FindForms,
  Forms,
  MainForm, ControlEvents;

begin
  Application.Title := 'WinCMOC IDE v0.8';
  Application.Initialize;
  Application.CreateForm(TFormIDE, FormMain);
  Application.CreateForm(TFormFind, FormFind);
  Application.Run;
end.
