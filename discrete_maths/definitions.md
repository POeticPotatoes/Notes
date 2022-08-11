# Mathematical Proofs
## Definitions
A **mathematical proof** is a verification of a **proposition** by a chain of logical deductions from a set of **axioms**


A **proposition** is a **declarative statement** that is either True or False

A **paradox** is a **declarative statement** that cannot be assigned a truth value

A **contradiction** is a **compound proposition** that is always false

A **tautology** is a **compound proposition** that is always true

A **predicate** is a **proposition** whose truth depends on the value of a variable(s)

A **domain** is the collection of all possible variables that a **predicate variable** may take

An **argument** is a sequence of statements. 

A **conclusion** is the last statement of an **argument**, and all previous statements are **premises** (or **assumptions/hypotheses**)

A **valid argument** is an argument where the **conclusion** is true if the **premises** are true. An **argument** is only valid if and only if "the conjunction of **premises** implying the **conclusion**" is a **tautology**.

A **critical row** is a row in a truth table where all **premises** are true. If in all critical rows the **conclusion** is true, the **argument** is **valid**, else it is **invalid**.

A **counterexample** is a **critical row** where the **conclusion** is false. This invalidates an **argument**

A **fallacy** is an error in reasoning that results in an invalid **argument**

## Symbols
#### Propositional Logic	

|Logic | Symbol| Notes|
|-|-|-|
|NOT| $\lnot$|
|OR| $\lor$|
|AND|$\land$|
|XOR|$\oplus$|
|Equivalent|$\equiv$|Means that it has the same truth table|
|Implies|$\implies, \rightarrow$| $p\rightarrow q\equiv \lnot p \lor q$
|Not Implies|$\nrightarrow$
|If and Only If|$\iff,\leftrightarrow$| $p\iff q\equiv \lnot(p\oplus q)$
|By Definition|$\triangleq$|
|Contradiction|$\bot$|
|Tautology|$\top$|
|Provability|$\vdash, \dashv$| $x\vdash y$ where *x* is a set of axioms and *y* is a statement
|Therefore|$\therefore$

#### Predicate Logic	
|Logic|Symbol|Notes|
|-|-|-|
|For All|$\forall$| Universal quantifier
|Exists, Some|$\exists$| Existential quantification
|In, Contains|$\in$|
|Domain|$\mathbb{D}$
|Union|$\cup$
|Intersection|$\cap$
|Semantically Implies|$\models$

#### Modal Logic	
|Logic|Symbol|Notes|
|-|-|-|
|QED|$\Box$
||$\Diamond$

#### Miscellaneous
$\mathbb{set}$
$\mathbb{Z}$
$\mathbb{N}$
$\Delta$
$\delta$

## Laws of Logic
#### De Morgan's Laws
$\lnot(p\land q)\equiv\lnot p\lor\lnot q$  
$\lnot(p\lor q)\equiv\lnot p\land\lnot q$  

#### Distributive Law
$p\land(q\lor r)\equiv(p\land q)\lor(p\land r)$  
$p\lor(q\land r)\equiv(p\lor q)\land(p\land r)$  

#### Double negation
$\lnot\lnot p\equiv p$

#### Absorbtion
$p\lor(p\land q)\equiv p$  
$p\land(p\lor q)\equiv p$

#### Idempotent
$p\land p\equiv p$  
$p\lor p\equiv p$  

## Additional Terms
A **vacuously true** proposition is **true by default**:  
if $p \rightarrow q$ and *q* is true even if *p* is false, *p* is *vacuously true*

if $p\rightarrow q$:  
* p is a **sufficient condition** for q: $\lnot p \nrightarrow\lnot q$
* q is a **necessary condition** for p: $\lnot q \rightarrow\lnot p$

|Statement| $p\rightarrow q$|
|-|-|
|Converse|$q\rightarrow p$|
|Inverse|$\lnot p\rightarrow\lnot q$|
|Contrapositive|$\lnot q\rightarrow\lnot p$|

## Argument Types
|Argument Name|Notation|
|-|-|
|Modus Ponens|$(p\implies q)\land p\therefore q$
|Modus Tollens|$(p\implies q)\land\lnot q\therefore \lnot p$
|Conjunctive Simplification (Particularising)|$p\lor q\therefore p$
|Conjunctive Addition (Specialising)|$p, q\therefore p\land q$
|Disjunctive Addition (Generalisation)|$p\therefore p\lor q$
|Disjunctive Syllogism (Case Elimination)| $(p\lor q)\land\lnot p\therefore q$
|Rule of Contradiction|$(\lnot p\implies!!)\land!!\therefore p$
|Alternative Rule of Contradiction|$(\lnot p\implies\bot)\land\bot\therefore p$
|Dilemma|$(p\lor q)\land(p\implies r)\land(q\implies r)\therefore r$
|Hypothetical Syllogism|$(p\implies q)\land (q\implies r)\therefore p\implies r$
