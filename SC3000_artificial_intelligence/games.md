# Constraint Satisfaction Problems (CSP)
Discover a state of the game that satisfies a given set of constraints

A state is defined by **assignment** of values to some/all of the variables:  
Variables $V_i$ with values from domain $D_i$

An assignment is consistent/legal if <ins>no constraints are violated</ins>

A **solution** is an assignment with every variable given a value <ins>(complete) and all constraints satisfied</ins>

Examples:
* Assignment problems
* Timetabling problems
* Hardware configuration
* Transportation scheduling
* Factory scheduling
* Floor planning

Games:
* Eight queens
* Cryptarithmetic Puzzle
* Map Colouring

Constraint definition:
* Explicit (List-based), Implicit

Technique:
* Backtracking Search (Do not waste time searching when constraints have already been violated)
* Additional heuristics:
    * Which variable to assign next
        * Most constraining shrinks search size
        * Least constraining reduces chance of dead end
    * What order to try assignments
        * Minimum conflicts heuristic  
          Given initial assignment, selects variable in scope of violated constraint and assigns value that minimises violated constraints
    * Forward-checking & constraint propagation (marking deadzones)

# Adversarial Search
Existence of **hostile agents**:
* Other agents act to diminish agent's wellbeing
* Uncertainty can exist even with deterministic actions (Contingency problems)

Games are usually time-limited and have very large search spaces
* Search efficiency is crucial

 Definitions:
 * Initial State: Board + First move
 * Operators: Legal moves
 * Terminal test: Is game over?
 * Utility function: Scores outcome of a game

### Minimax Search:
 * 3 steps:
    1. Generate game down to terminal states
    2. Calculate utility
    3. Select best move
* Cannot guarantee completeness for games of large search space (Imperfect Decisions)
    1. Replace utility function with estimated desirability of position (Evaluation function)
    2. Partial tree search
    3. Replace terminal test with cut-off test
* Requirement for evaluation functions
    * Efficient computation
    * Consistent with utility function on terminal states
    * Accurately reflects chance of winning
* Additional concerns
    1. Does not give global best result (best possible state)
    2. Assumes opponent acts rationally
    3. Might achieve a lower score due to assumption of opponent skill

### Monte-Carlo Search Tree
* Random search tree
* Considers g-function (in g+h)
    * Policy Network (g)
    * Value Network (h)
