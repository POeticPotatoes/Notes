# Markov Decision Process
$s_t$: state

$t$: time

$r_x$: reward for transitioning to time x

Agent and environment interaction:
1. Observe state $s_t\in S$
2. Produce action $a_t\in A(s_t)$
3. Get reward $r_{t+1}$ and next state $s_{t+1}\in S$

Markovian Property: Transition only depends on current state, not previous history

## Formulation of MDP
* States
* Actions
* Transition Model $P(s'|s,a)$
* Reward $R(s) or r(s, a, s')$ (using action a to transition from s to s')
* Policy: Solution

RAP Star Loves Pie: Reward, Action, Probability, State, Policy

V(s): Value of a state  
Q(s, a): Value of an action in a state

$V^\pi (s) = \sum_{a\in A}Q^\pi (s, a)p(a|s)$

(Value of a state is the product of each possible action-state pair and the probabilities of them occurring)
