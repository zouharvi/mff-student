% fib(?A, +N).
fib(1, 1).
fib(1, 2).
fib(A, N) :- 
    N > 2,
    N1 is N - 1,
    N2 is N - 2,
    fib(T1, N1), 
    fib(T2, N2),
    A is T1 + T2.