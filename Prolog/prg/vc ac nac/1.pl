male(tom).
male(bob).
male(jim).

female(pam).
female(ann).
female(pat).
female(liz).

father(tom,bob).
father(tom,liz).
father(bob,ann).
father(bob,pat).

mother(pam,bob).
mother(pat,jim).

parent(Name,C):-
    father(Name,C);mother(Name,C).

grandparent(Name,C):-
    parent(Name,X),parent(X,C).

grandchild(Name,C):-
    parent(C,X),parent(X,Name).

sister(Name,X):-
    parent(Y,X),parent(Y,Name),female(Name),Name\==X.
