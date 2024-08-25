# Logic
1. Logic: Representation + Inference
2. Reasoning: Construction of new statement
3. Entailment: Chaining

## Types of Reasoning
* Mechanical (Abstraction)
* Deductive (Modus Ponens)
* Inductive (Modus Tollens, dangerous as generalisation)

## Knowledge Representation Language
* Formal languages are not **expressive** (Cannot represent incomplete data)
* Natural languages **expressive** (Too ambiguous)

<ins>Desired Properties</ins> (ECUCE)
* Expressive
* Concise
* Unambiguous (True/False)
* Context Independent (Arbitrary meaning)
* Effective

**Tautology** is true under all possible interpretations in all possible worlds

**Satisfiable** is true in some world (Not fucked)

**Soundness** logically follows (makes sense)

**Complete** can explain/prove everything in system (closed)

## Propositional Logic

**Literal**: $\lnot P$

**Clause**: $P\lor Q$

**Unit Resolution**: resolution where 1 clause is a literal

**Full Resolution**: general

## First Order Logic

1. Allows description of relations/ properties
2. Permits use of constants/ variables
3. Separates inference from knowledge

Components:  
* Variables
* Terms
* Predicates (True or false): `Cringe(MushokuTensei)`
* Functions (Functional relations, object): `SelectCringe(x)`
* Sentences
    * Atomic: literal
    * Complex: clause
    * Rule/ Complementary form
    * Well formed formula (WFF): All variables properly quantified

# Logical Agents
## Knowledge-Based Approach
* Agents that know
    * Competence: Being told new knowledge
    * Adaptability: Updating knowledge
    * Logic: **Representation** State, properties, evolution of world
        * goals of agent, actions, effect
* Agents that reason
    * Use knowledge to deduce actions
    * Logic: Inference

### Knowledge Base
* Set of sentences (representation of facts)
    * Knowledge representation language
* Actions:
    * Tell: Add sentence
    * Ask: Retrieve knowledge
* Inference mechanism: based on KB

### Problem Formulation
* States
* Operators
* Goal

### Levels of Knowledge
1. Epistemological Level (Declarative description): `If there is x then there is y`
2. Logical (Logical Encoding): `Implies(x, y)`
3. Implementation (Physical Representation) `int Implies[][];`
