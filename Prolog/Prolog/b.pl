%1. N th element Find
%
%Ans)

nth(X,[_|T],N):- N>1, N1 is N-1, nth(X,T,N1).
nth(X,[X|_],1).


%2. Last element

%Ans)

lste(X,[_|T]):- lste(X,T).
lste(X,[X]).


%3. Reverse lest.

%Ans)

rl(L1,L2):- reverse(L1,L2).

%4. Palindrome

%Ans)

palin(L):- reverse(L,L).


%5. Even/odd Count

eocount([],E,O):- write(E),nl,write(O).
eocount([H|T],E,O):- H mod 2 =:= 0, E1 is E+1,eocount(T,E1,O);O1 is O+1,eocount(T,E,O1).


eosum([],E,O):-write(E),nl,write(O).
eosum([H|T],E,O):- H mod 2 =:= 0 , E1 is E + H,eosum(T,E1,O);O1 is O+H, eosum(T,E,O1).

%
%7. len string

%Ans).
%

len1([],0).
len1([_|T],X):- len1(T,X1),X is X1+1.


%8. orderlst

%Ans)

olist([_]).
olist([X,Y|Z]):- X < Y, olist([Y|Z]).

gcd(X,Y):- X>Y, X1 is X-Y,gcd(X1,Y);Y>X, Y1 is Y-X,gcd(X,Y1);write(X).

%10. Factorial

%Ans)

fact(N):- factorial(N,1).
factorial(N,R):- N>0, R1 is N*R, N1 is N-1,factorial(N1,R1);write(R).










