program cmocide;

{$mode objfpc}{$H+}

uses
  Forms,
  MainForm, UPaintBox;

const
  ProgramName = 'cmocide';

{$include main.inc}

begin
  Application.Title := 'WinCMOC IDE v0.8';
  Application.Initialize;
  Application.CreateForm(TFormIDE, FormMain);
  Application.Run;
end.
