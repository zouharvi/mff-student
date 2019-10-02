type
    pInteger = ^integer;
var
    stonozka : pInteger;
    chroust : pInteger;
    
    admiral : integer;
    ponorka : integer;

begin
    ponorka := 5;
    admiral := 8;

    WriteLn('ponorka: ', ponorka, ' admiral: ', admiral);
    stonozka := @ponorka;
    stonozka^ := 98;
    WriteLn('ponorka: ', ponorka, ' admiral: ', admiral);

    new(stonozka);
    new(chroust);
    stonozka^ := 54;
    chroust^ := -7;
    WriteLn('stonozka^: ', stonozka^, ' chroust^: ', chroust^);

    stonozka := chroust;
    chroust^ := 21;
    WriteLn('stonozka^: ', stonozka^, ' chroust^: ', chroust^);
end.

// new(P), dispose(P)
// compile & run: fpc ./memory.pas; rm memory.o; ./memory.exe