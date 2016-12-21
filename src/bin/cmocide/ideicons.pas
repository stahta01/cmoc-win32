unit IdeIcons;

{$mode objfpc}{$H+}

interface

uses
  Classes, FileUtils, Graphics, SysUtils;

type
  TIdeIcons = class
  public
    New, Open, Save, Undo, Redo, Cut, Copy, Paste, Delete, SyntaxCheck, Compile,
    Build, BuildAndRun: TIcon;
  public
    constructor Create;
  public
    function LoadFromFile(const A: string): TIcon;
  end;

implementation

constructor TIdeIcons.Create;
begin
  New := LoadFromFile('new.png');
  Open := LoadFromFile('open.png');
  Save := LoadFromFile('save.png');
  Undo := LoadFromFile('undo.png');
  Redo := LoadFromFile('redo.png');
  Cut := LoadFromFile('cut.png');
  Copy := LoadFromFile('copy.png');
  Paste := LoadFromFile('paste.png');
  Delete := LoadFromFile('cross.png');

  SyntaxCheck := LoadFromFile('tick.png');
  Compile := LoadFromFile('compile.png');
  Build := LoadFromFile('bricks.png');
  BuildAndRun := LoadFromFile('brick_go.png');
end;

function TIdeIcons.LoadFromFile(const A: string): TIcon;
begin
  Result := TIcon.Create;
  Result.LoadFromFile(ProgramDirectory + 'images' + DirectorySeparator + A);
end;

end.
