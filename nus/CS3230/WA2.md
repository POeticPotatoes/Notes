### Yang Iiyu A0309471A
# Task 1: Counters
### 1.  
We use the Potential Method. Consider the function: $\phi(n) = 2\cdot\sum_{\forall i} (i \mod 3)$, ie. the sum of all positions modulo 3, multipled by 2.

Consider the recursive binary tree of invocations for any operation:
* Every leaf node which does not trigger recursive calls increases our potential function by 2, since a position is simply incremented by 1 mod 3.

* Every internal node reduces some position by 2 mod 3, thus our potential function decreases by 4.

* All internal nodes have exactly 2 leaf nodes

We assert that there is always 1 more leaf node than internal nodes. Proof by construction:
* Start with 1 leaf node and 0 internal nodes, so the difference in count is 1.

* Repeat the following until the full invocation tree is constructed:
    1. Replace a leaf node with an internal node and its 2 leaf children.
    2. Both the number of leaves and internal nodes increases by 1, thus the difference remains at 1.

Because of this property, given a tree of $k$ invocations, we have $(k-1)/2$ internal nodes and $(k+1)/2$ leaves.  

Thus $\Delta\phi(n)$ for the $n^{th}$ operation is $2\cdot\frac{k+1}{2} - 4\cdot\frac{k-1}{2}=3-k$

---

Recall that the cost of an operation is the number of invocations triggered. Thus for any operation we have:
Actual Cost|$\Delta\phi(n)$|Amortized Cost
|-|-|-
$k$|$3-k$|$3\in O(1)$

Therefore by potential method we can conclude that the amortized cost per operation is $O(1)$


### 2.
We propose the following sequence of operations:
* Divide the n operations into 3 groups: 

    * The first 2 groups are of size $\lceil n/3\rceil$

    * The last group contains the remaining operations. It is fine as long as this set is nonempty (which it should be for $n>4$).

* Using the first 2 groups, increment position $2i$ for all $0\leq i\leq n/3$ twice each, eg. $[2,0,2,0,2,0,2,...]$.

    * This requires $2\cdot\lfloor n/3 \rfloor\leq 2\cdot\lceil n/3 \rceil$ operations, thus there are always enough operations to perform this.

* Next, we call $Increment(0)$ using an element from the last group.
    * Because the first $2\cdot\lfloor n/3\rfloor$ positions follow the $[2,0,2,0,...]$ pattern, we invocate at least $2\cdot\lfloor n/3\rfloor\in\Omega(n)$ calls, thus the cost of this operation is similarly $\Omega(n)$

### 3.
We propose the following finite sequence of operations: $[Increment(0), Increment(1), Increment(0)]$

* After the second operation, we have $[1,1,0,0,...]$

* For the third operation, we have: 
    1. $[2,1,0,0,0,...]$, Recursive case triggered at position 0, with the next recursive invocation being $Increment(1)$

    2. $[2,2,0,0,0,...]$, Recursive case triggered at position 1
    3. $[2,2,1,0,0,...]$
    4. $[2,2,1,1,0,...]$  
    5. $[2,2,2,1,0,...]$, Recursive case triggered at position 2, with the next recursive invocation being $Increment(3)$

* We can observe that the $[2,1,0]$ pattern has repeated after the fifth step, thus the same recursive pattern repeats at position 3. eg. after the $9^{th}$ step we can expect to see $[2,2,2,2,2,1,0,...]$

---
To prove that the sequence is non-terminating, we sjow that each position $\gt 2$ always triggers a recursive call, up to infinity:

* Base case: Observe that our assertion holds true in our initial demonstration:

    * On the fifth step when the recursive case is triggered at position 2, all non-negative positions $\lt 2$ have already triggered a recursive call. 

* Induction step:

    * Consider some position $k\geq2$
    
    * Assuming our initial assertion, then positions $k-1$ and $k-2$ will have triggered recursive calls that increment position $k$
    
    * Because $C[k]$ is necessarily increased by 2, a recursive call *must* be triggered by either of the 2 increments

    * Thus our assumption holds true for the inductive case

Because an increment operation must be performed for all numbers up to infinity, the third operation is non terminating. 

Therefore we have achieve a non-terminating process after 3 operations under modulo 2.

# Task 2: Maximal Independent Set
### 1.
Consider the following algorithm:
1. For some vertex $v\in S$, check if it shares an edge with any other vertex in $S$
2. If it does, then return false
3. Otherwise, repeat step 1 until all vertices in $S$ have been checked
4. If no vertices in $S$ share an edge, then return true

This is sufficient to answer the decision problem, because a maximal independent set can always be constructed from $S$ as long as $S$ is an independent set. Proof by contradiction:
* Assume our assertion is wrong
* Then $S$ cannot be maximal or be a subset of a maximal independent set
* Thus any independent set it belongs to must be a proper subset of some other independent set
* Due to the transitivity of subsets, this means the graph must be infinite. (contradiction)

Our algorithm requires us to check all edges for all vertices in the subset. By handshake theorem, we have $2E\in O(E)$ operations. Since each edge must be individually represented in our problem, we can consider this to be solvable in polynomial time.

> This can also be expressed due to the constraint that G is simple and undirected as $O(V^2)$. Nonetheless, all $O(V^2)$ edges must be individually described, thus the problem remains in polynomial time.

### 2.
Observe that if and only if all neighbours of a vertex $v$ do not exist in a MIS, then $v$ must be present in the set (otherwise it would not be maximal as $v$ may be selected).

Therefore it is sufficient to guarantee that a vertex exists in MIS by adding all of its neighbours to a set and checking if some MIS exists excluding that set.

We propose the following reduction:
* Start with an empty set $W$
* Add all elements in $S_0$ to $W$
* For all vertices in $S$, add their neighbours into $W$
* Use Extend-MIS-out to obtain an answer for $G$ and subset $W$

Consider the cases:
1. YES: Then we guarantee that some MIS exists where all of $S_0$ is not present and all of $S$ can be (and are indeed) included
2. NO: Then for all possible MIS, either some vertex in $S_0$ is present, or some neighbour of a vertex v in $S$ is present (thus v itself cannot be included)

Thus we show a 1 to 1 mapping between Extend-MIS and Extend-MIS-out.

Proof of polynomial time:
* Adding all elements to $S_0$ can be done in $O(p(V))$ with various data structures. Since $S_0$ itself is $O(V)$ as each vertex inside $S_0$ is individually represented, this step is polynomial.
* Adding all neighbours of vertices in $S$. Since there are at most $E$ neighbours, this step is $O(p(E))$.
* Our combined complexity for problem reduction is therefore $O(p(V)+p(E))$, which is in polynomial time.

Therefore we have achieved some polynomial $O(p(V) + p(E))$ reduction from `Extend-MIS` to `Extend-MIS-out`.

### 3.
We cannot prove so. Consider the graph $G =(1, \{\})$. Then we have $G' = (2, \{(1,v^*)\})$.

The answer for this graph for the set $S=\{1\}$ is `NO` because there is only 1 MIS for this graph which contains the only vertex. However, the call to Extend-MIS-out returns `YES` because selecting $v'$ is indeed a valid MIS for $G'$.

### 4.
The algorithm:
1. Initialise an empty set of vertices, $W$
2. For each vertex $v$ not in $S$ or $S_0$:
    1. Use `Extend-MIS` to check for a Maximal Independent Set $I$ such that $(S_i\cup \{v\})\subseteq I$ and $I\cap S_0 = \emptyset$
    2. If `YES`, then add $v$ to $W$
3. Final step: Use `Extend-MIS` to check for a Maximal Independent Set $I$ such that $(S_i\cup W)\subseteq I$ and $I\cap S_0 = \emptyset$
    1. The answer to `Extend-MIS-unique` is the answer to this final query.

We assert that our algorithm returns `YES` if and only if there is only 1 maximal independent subset which contains $S_i$ and excludes $S_0$.

* Observe that $W$ contains all vertices that belongs to *some* valid MIS that satisfies the constraints for `Extend-MIS`.

* For the case where `Extend-MIS-unique` should return `NO`:

    * Either no valid solution for Extend-MIS with $S_i$ and $S_0$ exists (in which case our algorithm also returns `NO`), or at least 1 vertex $v\in W$ belongs to a different valid MIS from the rest of the vertices.

    * Then there must be a pair $(u, v),\ u,v\in W$ where $u$ and $v$ share an edge. Otherwise, $v$ could be included into the same MIS as the other vertices.

    * Then our algorithm returns `NO` in our final step as no MIS including both $u$ and $v$ can exist.

* For the case where `Extend-MIS-unique` should return `YES`:

    * Since all vertices in $W$ already belong to the same unique MIS, the final step returns `YES`.

Proof of Polynomial time:
* Checking each vertex requires a single call to `Extend-MIS`. This is repeated $V$ times for each vertex and each check can be done in polynomial time.
* Checking the final step also requires a single call to `Extend-MIS`. The union of $W$ and $S_i$ can similarly be done in polynomial time with hashsets, treesets or other similar data structures.
* Thus the total running time of the algorithm is $O((V+1) \cdot (T(p(n)) + O(p(n))))$ where $p(n)$ is our described polynomial-time-reduction and $T(n)$ is the polynomial-time oracle for `Extend MIS`.

Therefore we can conclude that the algorithm is a polynomial time reduction of `Extend-MIS-unique` to `Extend-MIS`.
