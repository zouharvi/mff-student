const
    m1 = 4;
    m2 = 5;
    m3 = 6;
    s1 = 4;
    s2 = 5;
    s3 = 0;
var
    i, j, k : integer;
    vitez : array[0..m1, 0..m2, 0..m3] of integer;
    final : array[0..(m1+m2+m3)] of integer;

function max2(a, b: integer) :integer ; begin
    if a > b then max2 := a
    else max2 := b;
end;

function min2(a, b: integer) :integer ; begin
    if a < b then min2 := a
    else min2 := b;
end;

procedure lij(n1, n2, n3, i: integer); 
var
    x1, x2, x3: integer;
begin
    if (vitez[n1, n2, n3] < i) and (vitez[n1, n2, n3] <> 9999) then exit
    else begin
        vitez[n1, n2, n3] := i;
        
        // 2 -> 1
        x1 := min2(n1+n2, m1);
        x2 := x1 - n1;
        lij(x1, x2, n3, i+1);
        // 1 -> 2
        x2 := min2(n1+n2, m2);
        x1 := x2 - n2;
        lij(x1, x2, n3, i+1);

        // 1 -> 3
        x3 := min2(n1+n3, m3);
        x1 := x3 - n3;
        lij(x1, n2, x3, i+1);
        // 3 -> 1
        x1 := min2(n1+n3, m1);
        x3 := x1 - n1;
        lij(x1, n2, x3, i+1);

        if ( i <= 3) then
        begin
            writeln('B: ', n2, ' C: ', n3);
        end;
        // 2 -> 3
        x3 := min2(n2+n3, m3);
        x2 := x3 - n3;
        lij(n1, x2, x3, i+1);
        // 3 -> 2
        x2 := min2(n2+n3, m2);
        x3 := x2 - n2;
        lij(n1, x2, x3, i+1);
    end;
end;

begin
    for i := 0 to m1 do
        for j := 0 to m2 do
            for k := 0 to m3 do
                vitez[i, j, k] := 9999;
                
    for i := 0 to (m1+m2+m3) do
        final[i] := 9999;
    
    vitez[s1, s2, s3] := 0;
    lij(s1, s2, s3, 0);
    for i := 0 to m1 do
        for j := 0 to m2 do
            for k := 0 to m3 do begin
                final[i] := min2(vitez[i, j, k], final[i]);
                final[j] := min2(vitez[i, j, k], final[j]);
                final[k] := min2(vitez[i, j, k], final[k]);
            end;
    for i := 0 to (s1+s2+s3) do
        if final[i] <> 9999 then
            writeln(i, ', ', final[i]);
end.