var
    socrates:   file of byte;
    aristotle:  TextFile;
    zeno:       file of integer;
    beruska:    string;
    kobra:      byte;
    zizala:     integer;
begin
    assign(socrates, 'files_socrates');
    assign(aristotle, 'files_socrates');
    assign(zeno, 'files_socrates');

    writeln();

    // bytove cteni
    reset(socrates); // cteni a zapis
    read(socrates, kobra);
    WriteLn('prvni byte raw: ', kobra);
    WriteLn('prvni byte char: ', char(kobra));

    read(socrates, kobra);
    WriteLn('druhy byte raw: ', kobra);
    WriteLn('druhy byte char: ', char(kobra));
    close(socrates);

    writeln();

    // int cteni
    reset(zeno); // cteni a zapis
    read(zeno, zizala);
    WriteLn('prvni int raw: ', zizala); // 104 * 256 + 97 = 26721 LE :)
    close(zeno);

    writeln();

    reset(socrates);
    seek(socrates, 0);
    write(socrates, 98);
    close(socrates);

    // string cteni
    reset(aristotle);
    read(aristotle, beruska);
    WriteLn('string cteni: ', beruska);
    close(aristotle);
end.

// hexdump:       od -t x1 -An files_socrates
// write binary:  echo -n -e '\x61\x68\x6F' > files_socrates
// compile & run: fpc .\files.pas; rm files.o; .\files.exe