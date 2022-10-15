
%linear Search 8. Write a prolog program to determine whether an element is a member of a list
lc([X|_],X).
lc([_|T],X):-
    lc(T,X).

%2. Write a prolog program to determine whether in a list, the first two elements are same.

q2([X,Y|_]):- X=:=Y.

%3. Write a prolog program that checks whether a list does not contain exactly two elements.

q3(L):-
    len(L,N),
    N =\=2.

len([_|T],N):-
  len(T,N1),N is N1+1.
len([],0).

%4. Write a prolog program to determine whether the two lists are of same length.

q4(X,Y):-
    len(X,A),
    len(Y,B),
    A=:=B.


%6. Write a prolog program to find the last element of a list.

q6([_|T]):-
    q6(T).
q6([X]):-
    write(X).



%7. Write a prolog program to check whether two elements are consecutive elements in a list.


q7([_|T],X,Y):-
    q7(T,X,Y).
q7([X,Y|_],X,Y).
q7([Y,X|_],X,Y).



%9. Write a prolog program to append two lists to generate a 3rd list

q9([H|T1],T2,[H|T3]):-
    q9(T1,T2,T3).
q9([],X,X).



%10. Write a prolog program to reverse a list
%
q10(X,Y):-
    reverse(X,Y).


append1([],L2,L2).
append1([H|T1],T2,[H,T3]):-
    append1(T1,T2,T3).



rev([H|T],X):-
    rev(T,X1),
    append(X1,[H],X).
rev([],[]).


gcd(X,Y):-
    X>Y, X1 is X-Y, gcd(X1,Y);
    Y>X, Y1 is Y-X, gcd(X,Y1);
    write(X).

prg([H|T]):-max([H|T],H).
max([H|T],X):-
    H>X,X1 is H,max(T,X1);
    max(T,X).
max([],X):-
    write(X).

fact(X,Y):-
    X>0,
    Y1 is Y*X,
    X1 is X-1,
    fact(X1,Y1);
    write(Y).

fi(N):-
    N =:=1,write(0);
    N >=2,write(0),write(', '),write(1),fibo(0,1,N).

fibo(A,B,N):-
    N>2,
    Y is A+B,
    A1 is B,
    B1 is Y,
    N1 is N-1,
    write(', '),
    write(Y),
    fibo(A1,B1,N1).
