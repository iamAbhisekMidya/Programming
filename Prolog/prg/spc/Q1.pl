parent(bart,homer).
parent(bart,marge).
parent(lisa,homer).
parent(lisa,marge).
parent(maggie,homer).
parent(maggie,marge).
parent(homer,abraham).
parent(herb,abraham).
parent(tod,ned).
parent(rod,ned).
parent(marge,jackie).
parent(patty,jackie).
parent(selma,jackie).

female(maggie).
female(lisa).
female(marge).
female(patty).
female(selma).
female(jackie).

male(bart).
male(homer).
male(herb).
male(burns).
male(smithers).
male(tod).
male(rod).
male(ned).
male(abraham).

brother(X,Name):-
    parent(X,Y),parent(Name,Y),male(Name),Name \== X.

sister(X,Name):-
     parent(X,Y),parent(Name,Y),female(Name),Name \== X.

uncle(X,Name):-
    parent(X,Y),brother(Y,Name).

aunt(X,Name):-
    parent(X,Y),sister(Y,Name).

grandfather(C,Name):-
    parent(C,X),parent(X,Name),male(Name).

granddaughter(Y,X):-
    parent(X,Z),parent(Z,Y).

ancestor(X, Y) :- parent(X, Y).
ancestor(X, Y) :- parent(X, Z), ancestor(Z, Y).

descendant(X, Y) :- parent(Y, X).
descendant(X, Y) :- parent(Z, X), descendant(Z,Y).

