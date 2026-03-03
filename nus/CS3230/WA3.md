
### Yang Iiyu A0309471A
# Task 1: Complexity of 3-SAT Variants
### 1.
Proof that U-3-SAT is in NP:
* Given a 3-CNF formula $\phi$ and U, define the certificate to be a set of truth assignments for all literals in $\phi$
    * If some literal $a$ is true, then its negation $\lnot a$ must be false
* Then we simply need to verify that for every clause of $\phi$, this truth assignment results in  a number of true literals that is in U.
* Doing so can be done in $O(1)$ for each clause by evaluating all 3 literals and checking U, thus the verification can be completed in $O(n)$ where $n$ is the number of clauses. Thus $U-3SAT$ is in NP for any $U$.

### 2.
Proof that $\{0\}-3SAT$ is solvable in polynomial time:
* Observe that *no* literals can evaluate to true in this problem.
* Thus if some literal exists in $\phi$, then its negation must not exist in $\phi$
* Conversely, if all literals are independent of each other, then we can always set them all to false.

Thus it is sufficient to verify that no literal and its negation both exist in $\phi$. This can be done in $O(n)$ by simply iterating over all clauses in $\phi$ and maintaining a set of all encountered literals. If we encounter a negation of a literal we have already encountered, then we can instantly return false.

Thus we have solved the problem in polynomial time of $O(n)$.

### 3.
Proof that $\{0, 3\}-3SAT$ is solvable in polynomial time:
* Observe that if some literal in $\phi$ evaluates to true, then any clause containing its negation must be entirely false.
* The converse of this statement is also true (if some literal evaluates to false then any clause containing its negation must be entirely true).
* Then inverting all truth values of all literals in a valid certificate also results in a valid certificate.

Thus we can construct a valid certificate (if it exists) in the following manner:
* Maintain 2 sets of literals, A and B
* For each clause $x$ in $\phi$:
    * Consider the literals in $x$:
        * If there exists a pair of literals that already exist in A and B respectively, then there is no solution.
        * Otherwise, if it contains any literal that already exists in A or B, then add all literals in $x$ to the same set.
        * Otherwise, no literal in $x$ has been added to A or B yet, and we can add all literals to either A or B (it does not matter, based on our previous observations)
    * Add all negations of the literals in $x$ to the opposing set, eg. if all literals in $x$ were added to B, then add all their negations to A.
* Assign all literals in A to true, and all literals in B to false.

This construction succeeds because:
* All literals in a clause share the same truth assignment since they belong to the same set
* All negations are maintained (if some literal is assigned true, then its negation is correctly assigned false)

Thus we have a construction in $O(n)$ that produces a valid solution for $\{0,3\}-3SAT$ iff any solution exists, ie. we have solved the decision problem in polynomial time.

### 4.
Proof that $\{0, 1, 2\}-3SAT$ is NP complete:

We propose the following reduction:
* Consider $\{1,2,3\}-3SAT(\phi)$
* Let $\phi'$ be the result of negating all literals in $\phi$
* Then $\{1,2,3\}-3SAT(\phi)$ is equivalent to $\{0,1,2\}-3SAT(\phi')$

$\{1,2,3\}-3SAT$ asks if some assignment exists such that at least 1 literal in every clause evaluates to true.
* Then any valid solution implies that there is no clause where all 3 literals evaluate to false.
* Our answer remains the same if we invert all literals in $\phi$ and ask if an assignment exists that has no clause where all 3 literals are true (if and only if)
* This new decision problem corresponds to $\{0,1,2\}-3SAT$.

This reduction can be performed in $O(n)$. Thus we have shown that instances of $\{1,2,3\}-3SAT$ are polynomially reducible to $\{0, 1, 2\}-3SAT$.

## Task 2: Complexity of MIS Variants
### 1.
To prove that `Extend-MIS-out` is in NP, we only need to prove that a certificate is verifiable in polynomial time:
* Define a certificate to be a proposed set of vertices $A\subseteq V$
* Then we only need to verify that:
    1. $S\cap A=\empty$. This can be done by iterating over $S$ and $A$
    2. $A$ is a maximal set. This can be done in $O(V + E)$ by iterating over all vertices in the set and verifying that they either belong to $A$ or share an edge with some vertex in $A$.
    3. $A$ is an independent set. This can be done in $O(V+E)$ by iterating over all vertices in $A$ and verifying that they do not share an edge with any other vertex in $A$

Thus a certificate is verifiable in polynomial time, and `Extend-MIS-out` is in $NP$.

### 2.
We start with the `3-SAT` problem, described by the set of clauses $\phi$.
Then we can construct a graph $G$ from any $\phi$ in the following manner:
* Represent all unique literals as a vertex
* Every unique literal shares an edge with its negation
* Represent each clause as a vertex $c1, c2, \cdots$
* For each literal contained within each clause, an edge is shared between the literal vertex and the clause vertex.

**Note that this construction can be done in polynomial time.** Let the set of all clause vertices be $C$. Then we assert that `3-SAT` is effectively reduced to solving `Extend-MIS-out(G, C)`.

#### $\phi$ is a YES (3-SAT) -> (G, C) is a YES (Extend-MIS-out)
1. Consider a `YES` instance of `3-SAT`
2. Map all true literals in this assignment to their corresponding vertices in $G$, and take this selection to be the solution to `Extend-MIS-out`:
    * All selected vertices are clearly independent, since each vertex only shares an edge with its negation and any clauses that contain it (clauses are never selected under this mapping).
    * The selection is maximal, since `3-SAT` guarantees that each clause vertex is connected to at least one selected vertex, and each literal vertex is either itself selected or its negation is selected. This means that no other vertices can be added to the current selection.
3. Therefore the mapped selection is indeed a Maximal Independent Set that excludes all $C$.

#### (iff): $\phi$ (3-SAT) <- (G, C) (Extend-MIS-out)
1. Consider a `YES` instance of `Extend-MIS-out`
2. For all literals in $\phi$ whose vertex was selected, we assign them as true, and take this assignment to be our solution for `3-SAT`:
    * Each literal or its negation is necessarily assigned, as previously shown
    * Each clause must evaluate to true (Proof by contradiction: otherwise, no selected vertex is adjacent to the clause vertex in $G$ and the `YES` instance would not be maximal)
3. Threfore the mapped instance is indeed a valid solution for `3-SAT`.

Therefore we have proven a polynomial time reduction of `3-SAT` to `Extend-MIS-out`, and that `Extend-MIS-out` is NP-Complete.

### 3.
To prove that `min-MIS` is in NP, we only need to prove that a certificate is verifiable in polynomial time:
* Define the certificate to be a set of vertices $A\subseteq V$.
* Then we only need to verify that:
    1. $|A| \leq k$. This is trivial.
    2. $A$ is a maximal set. This can be done in $O(V + E)$ by iterating over all vertices in the set and verifying that they either belong to $A$ or share an edge with some vertex in $A$.
    3. $A$ is an independent set. This can be done in $O(V+E)$ by iterating over all vertices in $A$ and verifying that they do not share an edge with any other vertex in $A$

Thus a certificate is verifiable in polynomial time, and `min-MIS` is in $NP$.

### 4.
Input: A graph of size 1 with no edges, $k=0$
* $G' = G$ and $k'=  k$
* `min-VC` returns `YES`, but `min-MIS` return `NO` since the (only) MIS is of size 1.

### 5.
idk lol
