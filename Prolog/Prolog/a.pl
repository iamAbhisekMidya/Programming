prg([],K):-
    nl,
    write('No of Even Element is '),
    write(K),nl.
prg([H|T],K):-
    H mod 2 =:= 1,
    Y is K+1,
    prg(T,Y);
    prg(T,K).

check_eq([X,Y|_]):-
    X=:=Y.

go:-
    write('Enter a list'),nl,
	read(L1),
	write('Enter another list'),nl,
	read(L2),
        le(L1,X),
        le(L2,Y),
        X=:=Y.
le([],0).
le([_|T],N):-le(T,Z), N is Z+1.

my_last(X,[X]).
my_last(X,[_|TAIL]):-my_last(X,TAIL).


addevenlist([],E):-
    write(E).
addevenlist([H|T],E):-
    H mod 2=:=0,
    Y is E+H,
    addevenlist(T,Y);
    addevenlist(T,E).

fl([H|T]):-
    my_l(T,X),
    X =:= H.
my_l([_|T],X):-
    my_l(T,X).
my_l([X],X).


rvl(X,Y):-
   reverse(X,Y).

palindrm(X):-
    reverse(X,X).

%nth eliment, 3rd ekllement, in the list,

nth(X,[X|_],1).
nth(X,[_|T],K):- K>1, K1 is K-1, nth(X,T,K1).

lastt([X],X).
lastt([_|T],X):- lastt(T,X).


