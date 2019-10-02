program interpreter_6502;
uses
    Sysutils;

const
    MEM_SIZE = 40;

var
    mem:        array[0..(MEM_SIZE-1)] of byte;    // RAM
    PC:         integer = 0;                       // program counter
    A, X, Y:    byte;                              // accumulator, registers
    C, Z:       boolean;                           // carry, zero flag
    

    UserInterrupt: boolean = False;
    CPUInterrupt:  boolean = False;
    UserSkip:      boolean = False;
    UserInput:     string;
    token:         byte;

function CopyToMEM(filename: string):shortint;
var
    source:  file of byte;
    b: byte;
    i: integer;
begin
    Assign(source, filename);
    Reset(source);
    i := 0;
    CopyToMEM := 0;

    while not eof(source) do
    begin
      read(source, b);
      mem[i] := b;
      inc(i);
      if i >= MEM_SIZE then
      begin
        writeln('ERROR -1: File is too big. Memory size: ', MEM_SIZE, 'B');
        CopyToMEM := -1;
        break;
      end;
    end;
    Close(source);
end;

function HexToDec(s: string):byte;
begin
    HexToDec := 0;
    if (s[1] >= 'A') and (s[1] <= 'F') then
        HexToDec := HextoDec + ord(s[1]) - ord('A') + 10
    else HexToDec := HextoDec + StrToInt(s[1]);
    HexToDec := HexToDec * 16;
    if (s[2] >= 'A') and (s[2] <= 'F') then
        HexToDec := HextoDec + ord(s[2]) - ord('A') + 10
    else HexToDec := HextoDec + StrToInt(s[2]);
end;

function ParseASM(sourceFN, targetFN: string):shortint;
var
    source: file of char;
    target: file of byte;
    c1, c2: char;
begin
    ParseASM := 0;
    Assign(source, sourceFN);
    Assign(target, targetFN);
    Reset(source);
    Rewrite(target);
    c1 := 'x';
    c2 := 'x';

    while not eof(source) do
    begin
        if c1 = 'x' then
            c1 := c2;
        read(source, c2);
        if c2 = ';' then
            while c2 <> #10 do
                read(source, c2); 

        if (c2 = #10) or (c2 = ' ') then // newline
            c2 := 'x';

        if (c1 <> 'x') and (c2 <> 'x') then begin
            blockwrite(target, HexToDec(Concat(c1, c2)),1);
            c1 := 'x';
            c2 := 'x';
        end;
    end;

    Close(source);
    Close(target);
end;

function ShowMEM():shortint;
var
    i : integer;
begin
    ShowMEM := 0;
    writeln(' Token: ', IntToHex(token, 2));
    write(' RAM: ');
    for i := 0 to  MEM_SIZE -1 do begin
        write(IntToHex(mem[i], 2));
    end;
    writeln();
    writeln(' PC: ', IntToHex(PC, 2), ' A: ', IntToHex(A, 2), ' X: ', IntToHex(X, 2), ' Y: ', IntToHex(Y, 2));
    write(' C: ', C, ' Z: ', Z);
end;

begin
    ParseASM('source.asm', 'source.basm');
    CopyToMEM('source.basm');
    while (not UserInterrupt) and (not CPUInterrupt) do begin
        if not UserSkip then begin
            write('$', IntToHex(PC, 2), ': ');
            token := mem[PC];
            if token = $EA then begin
                Write('NOP');
                PC := PC + 1;
            end else if token = $A2 then begin // immediate
                Write('LDX $', IntToHex(mem[PC+1], 2));
                X := mem[PC+1];
                PC := PC + 2;
            end else if token = $A6 then begin // absolute address
                Write('LDX ($', IntToHex(mem[PC+1], 2), ')');
                X := mem[mem[PC+1]];
                PC := PC + 2;
            end else if token = $A9 then begin
                Write('LDA $', IntToHex(mem[PC+1], 2));
                A := mem[PC+1];
                PC := PC + 2;
            end else if token = $A5 then begin
                Write('LDA ($', IntToHex(mem[PC+1], 2), ')');
                A := mem[mem[PC+1]];
                PC := PC + 2;
            end else if token = $69 then begin
                Write('ADC $', IntToHex(mem[PC+1], 2));
                A := A + mem[PC+1];
                PC := PC + 2;
            end else if token = $E9 then begin
                Write('SBC $', IntToHex(mem[PC+1], 2));
                A := A - mem[PC+1];
                PC := PC + 2;
            end else if token = $85 then begin // absolute
                Write('STA $', IntToHex(mem[PC+1], 2));
                mem[mem[PC+1]] := A;
                PC := PC + 2;
            end else if token = $95 then begin // relative to X
                Write('STA $', IntToHex(mem[PC+1], 2),'+X');
                mem[mem[PC+1]+X] := A;
                PC := PC + 2;
            end else if token = $4C then begin
                Write('JMP $', IntToHex(mem[PC+1], 2));
                PC := mem[PC+1];
            end else if token = $6C then begin
                Write('JMP ($', IntToHex(mem[PC+1], 2), ')');
                PC := mem[mem[PC+1]];
            end else if token = $90 then begin
                Write('BCC $', IntToHex(mem[PC+1], 2));
                if not C then
                    PC := PC + 2 + shortint(mem[PC+1])
                else
                    PC := PC + 2;
            end else if token = $B0 then begin
                Write('BCS $', IntToHex(mem[PC+1], 2));
                if C then
                    PC := PC + 2 + shortint(mem[PC+1])
                else
                    PC := PC + 2;
            end else if token = $C9 then begin
                Write('CMP $', IntToHex(mem[PC+1], 2));
                C := (A >= mem[PC+1]);
                PC := PC + 2;
            end else begin
                writeln('Token not implemented. ');
                ShowMEM();
                writeln();
                CPUInterrupt := True;
            end;
        end;

        UserSkip := False;
        if not CPUInterrupt then begin
            write(#9#9#9);
            readln(UserInput);
            if UserInput = 'q' then
                UserInterrupt := True
            else if UserInput = 'm' then begin
                UserSkip := True;
                ShowMEM();
            end;
        end;
    end;
end.
