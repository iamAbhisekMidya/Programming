remdups([], []).
remdups([H|T], [H|T1]) :- subtract(T, [H], T2), remdups(T2, T1).
