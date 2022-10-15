prime_factor(N, D) :-
    find_prime_factor(N, 2, D).

find_prime_factor(N, D, D) :-
    0 is N mod D.
find_prime_factor(N, D, R) :-
    D < N,
    (0 is N mod D ->
    (N1 is N/D, find_prime_factor(N1, D, R));
    (D1 is D + 1, find_prime_factor(N, D1, R))).

prime_factors(N, L) :-
    findall(D, prime_factor(N, D), L).
