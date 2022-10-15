q1([],X,X).
q1([H|T1],T2,[H|T3]):-
    q1(T1,T2,T3).

q2([H|T],R):-
    q2(T,R1),append(R1,[H],R).
q2([],[]).

q3([H|T],R):-
    member(H,T),!,
    q3(T,R).
q3([H|T],[H|R]):-
    q3(T,R).
q3([],[]).


pri(2).
pri(3).
pri(N):-
    N>3,N mod 2=\=0,\+ fac(N,3).
fac(N,P):- N mod P =:=0.
fac(N,P):- P*P<N,P1 is P+2,fac(N,P1).

q5(N):-
    N=:=1,write('0');
    N>=2,write('0'),nl,write('1'),nl,
    sub5(N,0,1,2).
sub5(N,X,Y,C):-
    N>2,
    N>C,
    R is X+Y,
    write(R),nl,
    X1 is Y,
    Y1 is R,
    C1 is C+1,
    sub5(N,X1,Y1,C1).

q6([X,Y],X,Y).
q6([_|T],X,Y):-
    q6(T,X,Y).

q61([_,_],[]).
q61([H|T],[H|R]):-
    q61(T,R).


nth(X,[X|_],1).
nth(X,[_|T],N):-
    N>1, N1 is N-1,nth(X,T,N1).










