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

% Check for gender priority (Check if list contains a male)
no-gender-clash(A, []).
no-gender-clash(A, [B|C]) :-
    male(A) ;
    (female(A), female(B), no-gender-clash(A, C)).

% Check order among remaining siblings
next-in-line(A, [A|C]).
next-in-line(A, [B|C]) :-
    A \= B,
    female(B),
    male(A), 
    next-in-line(A,C).


% Consider gender + order for eligibility
eligible(A, O) :-
    no-gender-clash(A, O),
    next-in-line(A, O).

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
