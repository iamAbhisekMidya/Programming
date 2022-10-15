prg21([X,Y|_]):- X=:=Y.

prg22([_|T]):- prg22(T).
prg22([X,X]).

prg3(L):- prg5(L,N),N=:=2.

prg4(X,Y):-
    prg5(X,N1),prg5(Y,N2),N1=:=N2.

prg5([_|T],N):- prg5(T,N1),N is N1+1.
prg5([],0).

prg6([_|T],X):- prg6(T,X).
prg6([X],X).

prg7([_|T],X,Y):-prg7(T,X,Y).
prg7([X,Y|_],X,Y).
prg7([Y,X|_],X,Y).

prg8([_|T],X):- prg8(T,X).
prg8([X|_],X).

prg9([],X,X).
prg9([H|T1],T2,[H|T3]):- prg9(T1,T2,T3).

prg10([],[]).
prg10([H|T],X):-
    prg10(T,X1),append(X1,[H],X).

prg11(L):- reverse(L,L).

prg13(X,Y):-
    X>Y, X1 is X-Y,gcd(X1,Y);
    Y>X, Y1 is Y-X,gcd(X,Y1);
    write(X).
prg13(0,X):- write(X).
prg13(X,0):- write(X).

prg15([H|T]):-
    sb15([H|T],H).
sb15([H|T],X):-
    H>X, X1 is H,
    sb15(T,X1);
    sb15(T,X).
sb15([],X):-
    write(X).

prg16([X,Y|Z]):-
    X<Y,prg16([Y|Z]).
prg16([]).
prg16([_]).

prg17([H|T],R):-
    member(H,T),!,
    prg17(T,R).
prg17([H|T],[H|R]):-
    prg17(T,R).
prg17([],[]).

q19(N):-
    R is N//2,
    subm19(N,1,R).
subm19(N,S,R):-
    S=<R,
    S*S=:=N,
    write(S);
    S=<R,
    S1 is S+1,
    subm19(N,S1,R).

q20(X,Y,Z):-
    R is X//Y,
    R1 is R*Y,
    Z is X-R1.

q25(N,S):-
    N>=1,
    S1 is S+N,
    N1 is N-1,
    q25(N1,S1);
    write(S).

q28(N,S):-
    N>0,
    S1 is S*N,
    N1 is N-1,
    q28(N1,S1);
    write(S).

q30(L,[H|T]):-
    member(H,L),
    q30(L,T).
q30(_,[]).



remlast([_,_],[]).
remlast([H|T],[H|R]):-
    remlast(T,R).



oddsum(L):-
    subprg1(L,0).
subprg1([H|T],R):-
    H mod 2 =:=1,
    R1 is R+H,
    subprg1(T,R1);
    subprg1(T,R).
subprg1([],R):-
    write(R).


evensum(L):-
    subprg(L,0).
subprg([H|T],R):-
    H mod 2 =:=0,
    R1 is R+H,
    subprg(T,R1);
    subprg(T,R).
subprg([],R):-
    write(R).


evenoddsum(L):-
    subprg3(L,0,0).
subprg3([H|T],E,O):-
    H mod 2 =:=0,
    E1 is E+H,
    subprg3(T,E1,O);
    O1 is O+H,
    subprg3(T,E,O1).
subprg3([],E,O):-
    write('Evensum '),write(E),nl,
    write('Oddsum '),write(O) .

