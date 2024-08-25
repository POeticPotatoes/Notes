% Example call: successor(queen-elizabeth, X).

% Queen Elizabeth, monarch of the united kingdom
monarch(queen-elizabeth).

% Her children
parent(queen-elizabeth, prince-charles).
parent(queen-elizabeth, princess-ann).
parent(queen-elizabeth, prince-andrew).
parent(queen-elizabeth, prince-edward).

% Genders
female(queen-elizabeth).
female(princess-ann).
male(prince-charles).
male(prince-andrew).
male(prince-edward).

% Record of Order of Birth
order-of-birth(queen-elizabeth, 
    [prince-charles, princess-ann, prince-andrew, prince-edward]).

% Confirm that A is next in line
eligible(A, [B|O]) :-
    A = B.

% Utility function to remove item from array
remover( _, [], []).
remover( R, [R|T], T2) :- remover( R, T, T2).
remover( R, [H|T], [H|T2]) :- H \= R, remover( R, T, T2).

% Check if succession order matches eligibility among remaining siblings
nxt(K, [], []).
nxt(K, [X|Y], O) :-
    eligible(X, O),
    remover(X, O, R),
    nxt(K, Y, R).

% Find a valid order of succession
succession(K, X) :-
    order-of-birth(K, O),
    nxt(K, X, O).
