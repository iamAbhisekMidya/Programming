prg6([_|T],X,Y):-
    prg6(T,X,Y).
prg6([X,Y],X,Y).
prg6([Y,X],X,Y).


prg61([_|T],X,Y):-
    prg61(T,X,Y).
prg61([X,Y],X,Y).

prg62([_|T]):-
    prg62(T).
prg62([X,X]).

prg1([H|T1],T2,[H|T3]):-
    prg1(T1,T2,T3).
prg1([],X,X).

prg2([H|T],X):-
    prg2(T,X1),
    append(X1,[H],X).
prg2([],[]).

prg3([],[]).
prg3([H|T],R):-
    member(H,T),!,
    prg3(T,R).
prg3([H|T],[H|R]):-
    prg3(T,R).

prg4([H|T],R):-
    H mod 2 =:=0,
    R1 is R+H,
    prg4(T,R1);
    prg4(T,R).
prg4([],R):- write(R).
