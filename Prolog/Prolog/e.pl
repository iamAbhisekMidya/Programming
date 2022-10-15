re_dup([],[]).

re_dup([H|T],R) :-
    member(H,T),!,
    re_dup(T,R).

re_dup([H|T],[H|R]) :-
    re_dup(T,R).


onbyn(N,R):-
    N>0,
    R1 is R+ 1/N,
    N1 is N-1,
    onbyn(N1,R1);
    write(R).




