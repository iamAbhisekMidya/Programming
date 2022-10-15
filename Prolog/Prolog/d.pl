q2([X,Y|_]):- X=:=Y.

q3([H|T]):- q5([H|T],N), N=\=2.

q4(X,Y):- q5(X,N1),q5(Y,N2), N1=:=N2.

q5([_|T],N):- q5(T,N1), N is N1+1.
q5([],0).

q6([X],X).
q6([_|T],X):- q6(T,X).

q7([_|T],X,Y):- q7(T,X,Y).
q7([X,Y|_],X,Y).
q7([Y,X|_],X,Y).

q8([_|T],X):- q8(T,X).
q8([H|_],H).

q9([],X,X).
q9([H|T1],T2,[H|T3]):- q9(T1,T2,T3).

q10([],[]).
q10([H|T],X):- q10(T,X1),append(X1,[H],X).

q11(X):- reverse(X,X).

%q12(N,X):-
%    X>0,
%    X1 is X*X,
%    N =:= X1,
%    write(X);
%    X>0,
%    X2 is X-1,
%    q12(N,X2).
%
q13(0,Y):-
    write(Y).
q13(X,0):-
    write(X).
q13(X,Y):-
    X>Y,X1 is X-Y, q13(X1,Y);
    Y>X,Y1 is Y-X, q13(X,Y1);
    write(X).

q14(X,Y):-
    X>Y,write(X);
    Y>=X,write(Y).

q15([H|T]):-
    max1([H|T],H).

max1([H|T],X):-
    H>X,
    X1 is H,
    max1(T,X1);
    max1(T,X).
max1([],X):- write(X).

q16([X,Y|Z]):-
    X=<Y,q16([Y|Z]).
q16([]).
q16([_]).

q19(N,X):-
    X>0,
    X1 is X*X,
    N =:= X1,
    write(X);
    X>0,
    X2 is X-1,
    q19(N,X2).


q20(X,Y,R):-
    Z is X//Y,
    Z1 is Z*Y,
    R is X-Z1.

q21(R):-
    X is R*R*R,
    write(X).


