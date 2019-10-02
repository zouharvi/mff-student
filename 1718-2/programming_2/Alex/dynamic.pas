type
    pUlita = ^ulita;
    ulita = record
        hodnota : integer;
        dalsi: pUlita;
    end; 

procedure Zobraz(propiska: pUlita);
begin
    while propiska <> nil do begin
        writeln(propiska^.hodnota);
        propiska := propiska^.dalsi;
    end;
end;

var
    hlava : pUlita;
begin
    new(hlava);
    hlava^.hodnota := 54;
    WriteLn('hlava^.hodnota: ', hlava^.hodnota);

    writeln('%%%');
    Zobraz(hlava);
    writeln('&&&');

    new(hlava^.dalsi);
    hlava^.dalsi^.hodnota := 98;
    new(hlava^.dalsi^.dalsi);
    hlava^.dalsi^.dalsi^.hodnota := 12;
    Zobraz(hlava);
end.
// compile & run: fpc ./dynamic.pas; rm dynamic.o; ./dynamic.exe