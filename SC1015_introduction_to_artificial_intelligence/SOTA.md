# Introduction to AI
> AI is intelligence demonstrated by machines, as opposed to **natural intelligence (NI)** demonstrated by humans/animals

## History of AI
* 1956 - Dartmouth Conference, sparking the **Golden Age of AI**
    * Perceptron, ADALINE
* 1970 - AI Winter
    * XOR Problem
* 1990 - New Golden Age
    * Multi-layered Perceptron (Backpropagation)
    * SVM
    * Deep Neural Network (Pretraining)

## AI Perspectives
||Humanly|Rationally
|-|-|-
|Thinking|Cognitive Modelling<br> 1960s: "Cognitive Revolution"<br> Requires scientific theories of internal brain<br> Both approaches (Cognitive Science & Cognitive Neuroscience) are **distict** from AI | Issues: <ul><li>Not all intelligent behaviour is logically deliberated</li><li>What is the purpose of thinking rationally</li></ul>
|Acting|Turing Test (1950)| Doing the **right** thing (to achieve some goal)<br><br> Hence, we seek agents with the **best performance**
> This course is about designing agents which **act rationally**

### Unsolved problems
* Stochastic, open environments
* Multiple Players
* Sequential online decisions
* Strategic selfish behaviour
* Distributed optimisation

## Agents
* **Rational agents** are ones that act to maximise the expected value of an objective performance measure, given the percept sequence to date
* Rationality depends on
    * Performance measure (Goals)
    * Everything percieved (Percepts)
    * Built-in knowledge (Environment)
    * Actions that can be performed (Actions)
* Autonomous agents learn from past experience

### Types of Agents
* Simple Reflex Agents (Combinatorial) (Rules, Sensors & Effectors)
* Reflex Agents with State (Sequential)
* Utility based Agents (Happiness as **Utility**)

### Types of Environment
* Accessible - Complete understanding of environment
* Deterministic - Next state is completely determined by current state and actions
* Episodic - Episode is not affected by previous taken actions
* Static - Does not change while deliberating
* Discrete - Limited number of distinct percepts/actions
