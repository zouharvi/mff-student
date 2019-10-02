program PtrTypes;

type
	PLongint = ^longint;
	PInt = ^integer;
var
	arr : array[0..15] of byte;
	li  : PLongint;
	ni  : PInt;

begin
	writeln('test');
	arr[0] := $01;
	arr[1] := $FF;
	arr[2] := $01;
	arr[3] := $8F;
	writeln(arr[0]);
	li := @arr[0];
	ni := @arr[0];
	writeln(li^);
	writeln(ni^);
	writeln(PInt(@arr[0])^);
end.
