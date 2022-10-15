laste([_|T],X):-
    laste(T,X).
laste([X],X).

rev([],[]).
rev([H|T],X):-
    rev(T,X1),append(X1,[H],X).

gcd(X,0,X):- X>0.
gcd(X,Y,G):- Y>0,T is X mod Y,gcd(Y,T,G).


pri(2).
pri(3).
pri(N):-
    N>3,N mod 2 =\=0, \+ fac(N,3).
fac(N,P):- N mod P =:=0.
fac(N,P):- P*P<N,P1 is P+2,fac(N,P1).

app([],X,X).
app([H|T1],T2,[H|T3]):-
    app(T1,T2,T3).

redup([],[]).
redup([H|T],R):-
    member(H,T),!,
    redup(T,R).
redup([H|T],[H|R]):-
    redup(T,R).

nth(X,[_|T],N):-
    N>1,N1 is N-1,nth(X,T,N1).
nth(X,[X|_],1).



lenn([],0).
lenn([_|T],N):-
    lenn(T,N1),N is N1+1.






