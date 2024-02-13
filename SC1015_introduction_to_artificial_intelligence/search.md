# Search Strategies
## Search Paradigms
* Completeness: Find a solution
* Time, Space
* Optimality: Find best solution
* Branching Factor: Maximum/Average degree of nodes in a tree
* Uninformed/Informed
    * Uninformed: Only information available in problem definition
    * Informed: Problem-specific knowledge to guide search

## Uninformed Search
BFS, UCS, DFS, DLS(Depth Limited), Iterative Deepening Search
### BFS
* For a tree: $O(b^d)$, b is max branching factor, d is depth of soln
### UCS
* Complete
* Time: $O(b^d)$
* Space = Time
* Optimal
### DFS
* Complete:
    * Infinie depth: No
    * Finite depth: No, unless cycle check
    * TREE: Yes
* Time: $O(b^m)$ If solutions are dense, may be faster
* Space: $O(bm)$
* Optimal: No

### Iterative Deepening Search
* Iteratively estimate max depth of DLS one by one
* Complete: Yes
* Time: $O(b^d)
* Space: $O(bd)$
* Optimal: Yes

## Informed Search
Using **problem-specific** knowledge to decide order of node expansion
* Heuristic Function $h(n)$: **Estimated** cost of the cheapest path from n to a goal
* Depends only on state at that node
* Not larger than real cost (admissible)

### Greedy (Best First Search)
* Not Complete
* Time $O(b^m)$
* Space = time
* Not optimal

### A* Search
* UCS + Greedy (Sum h(n) and cost)
* Optimal
* Complete
* Time: number of nodes with < cost
* Space = time
