# Artificial Intelligence

## Definitions
### Agent
* **Perceives** features through **sensors**
* **Acts** through **effectors**

Problem Solving Sequence
* Define goal
* Formulate problem
    * Initial state
    * Action set
    * State space
    * Goal test predicate
    * Cost function (To compare solutions)
* Identify solutions (sequences of **legal action execution**)
* Search state space (algorithm of how to find a **good solution**)
    * No knowledge -> Uninformed Search
    * Knowledge -> Informed Search

<important>

#### Rationality
A **Rational action**: maximises the expected value of an objective **performance** measure given the percept **sequence to date**

Rationality depends on:
1. Percepts: **features** perceived by the sensor
2. Actions: **actions** that can be performed
3. Goals: **performance** measure
4. Environment: **built-in knowledge** aobut the environment

Environment description:
1. Accessible: Complete state of the environment
2. Deterministic: Future state only depends on current state and actions
3. Episodic: Episode is not affected by previous actions
4. Static: Environment does not change during deliberation
5. Discrete/ Continuous: Same definition as stats
</important>

### Problem Types
* Single State Problem
    * Accessible, Deterministic
* Multiple State Problem
    * Inaccessible initial state, Deterministic
    * Try to shrink possible current states
    * State becomes a **subset** of possible states

#### Measuring Problem Solving Performance
$Total\ Cost = Search\ Cost\ (Offline) + Execution\ Cost\ (Online)$

## Search Types
### Search Characteristics
* Completeness
* Time Complexity
* Space Complexity
* Optimality
* Uninformed vs Informed (Using **problem specific knowledge**)
