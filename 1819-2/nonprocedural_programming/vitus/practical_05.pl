:- op(550, xfx, ekv).
:- op(500, xfy, imp).
:- op(450, xfy, or).
:- op(400, xfy, and).
:- op(350,  fx, non).


% Korektně zadaná formule.
correct(X) :- ground(X), correct_(X).

correct_(X) :- atom(X).
correct_(F ekv G) :- correct_(F), correct_(G).
correct_(F imp G) :- correct_(F), correct_(G).
correct_(F or  G) :- correct_(F), correct_(G).
correct_(F and G) :- correct_(F), correct_(G).
correct_(  non G) :-              correct_(G).

sat(F) :-
    once(sat_(F, _)).

sat_(F, Model) :-
  correct(F),
  vars(F, Vars),
  genModel(Vars, Model),
  eval(F, Model, true).

vars_(F, [F]) :- atom(F).
vars_(A ekv B, TotalVars) :- vars_(A, AVars), vars_(B, BVars), append(AVars, BVars, TotalVars), !.
vars_(A imp B, TV) :- vars_(A ekv B, TV).
vars_(A or B, TV) :- vars_(A ekv B, TV).
vars_(A and B, TV) :- vars_(A ekv B, TV).
vars_(non B, TV) :- vars_(B, TV).

vars(A ekv B, TotalVarsSet) :- vars_(A ekv B, TotalVars), list_to_set(TotalVars, TotalVarsSet).
vars(A imp B, TVS) :- vars(A ekv B, TVS).
vars(A or B, TVS) :- vars(A ekv B, TVS).
vars(A and B, TVS) :- vars(A ekv B, TVS).
vars(non B, TVS) :- vars(B ekv B, TVS).

genModel([], []).
genModel([V|Vars], [V-true|Model]) :- genModel(Vars, Model).
genModel([V|Vars], [V-false|Model]) :- genModel(Vars, Model).

eval(A, Model, Value) :- atom(A), !, member(A-Value, Model).
eval(A ekv B, Model, Value) :- 
    (
        Value = true,
        (
            eval(A, Model, true), eval(B, Model, true)
        ) ; (
            eval(A, Model, false), eval(B, Model, false)
        )
    ) ; (
        Value = false, (
        (eval(A, Model, true), eval(B, Model, false)) ;
        (eval(A, Model, false), eval(B, Model, true))
    )).
eval(A and B, Model, Value) :- 
    (
        Value = true, eval(A, Model, true), eval(B, Model, true)
    ) ; (
        Value = false, (
            eval(A, Model, false) ; eval(B, Model, false)
        )
    ).
eval(A or B, Model, Value) :- 
    (
        Value = false, eval(A, Model, false), eval(B, Model, false)
    ) ; (
        Value = true, (
            eval(A, Model, true) ; eval(B, Model, true)
        )
    ).
eval(A imp B, Model, Value) :- 
    (
        Value = false, eval(A, Model, true), eval(B, Model, false)
    ) ; (
        Value = true, (
            eval(A, Model, false) ; eval(B, Model, true)
        )
    ).
eval(non B, Model, Value) :- 
    (Value = true,
        eval(B, Model, false))
    ;
    (Value = false,
        eval(B, Model, true)
    ).