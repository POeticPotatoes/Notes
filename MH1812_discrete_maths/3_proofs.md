# Mathematical Proofs
## Direct Proof
(In which proving is done directly)
## Proof by Induction
$[P(1)\land\forall k(P(k)\rightarrow P(k+1))]\rightarrow\forall nP(n)$  

    1: P1
    2: P1 implies P2
    3: By Modus Ponens, P2
    4: This implies P3, P4, P5, etc
    5. Therefore P(n) for all n.

## Proof by Contradiction
Show that 
$(\lnot P(k)\rightarrow C\land\lnot C)\rightarrow P(k)$

    1. Negate P
    2. Find a contradiction
    3. Therefore P must be true

#### Proof By Contrapositive
$(\lnot Q(n)\rightarrow\lnot P(n))\rightarrow(P(n)\rightarrow Q(n))$
