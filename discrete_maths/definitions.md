# Mathematical Proofs
## Definitions
A **mathematical proof** is a verification of a **proposition** by a chain of logical deductions from a set of **axioms**

A **proposition** is a **declarative statement** that is either True or False

A **paradox** is a **declarative statement** that cannot be assigned a truth value

A **contradiction** is a **compound proposition** that is always false

A **tautology** is a **compound proposition** that is always true

A **predicate** is a **proposition** whose truth depends on the value of a variable(s)

#### Further Definitions
If $p \rightarrow q$ and q is true even if *p* is false, *p* is *vacuously true* or *true by default*

## Symbols

Propositional Logic	

|Logic | Symbol| Notes|
|-|-|-|
|NOT| $\lnot$|
|OR| $\lor$|
|AND|$\land$|
|Equivalent|$\equiv$|Means that it has the same truth table|
|Implies|$\implies, \rightarrow$
↔	$\leftrightarrow$
⊢	$\vdash$
⊣	$\dashv$

Predicate Logic	
∀	$\forall$
∃	$\exists$
∈	$\in$
    $\cup$
    $\cap$
⊨	$\models$

Modal Logic	
□	$\Box$
◊	$\Diamond$

$\mathbb{set}$
$\mathbb{N}$
$\equiv$
$\Delta$
$\delta$

## Laws of Logic
#### De Morgan's Laws
!(p&&q) $\equiv$ (!p)||(!q)  
!(p||q) $\equiv$ (!p)&&(!q)

#### Distributive Law
p&&(p||r)=(p&&q)||(p&&r)
p||(q&&r)=(p||q)&&(p||r)

#### Double negation
!!p = p

#### Absorbtion
p||(p&&q)=p
p&&(p||q)=p

#### Idempotent
p&&p=p
p||p=p
