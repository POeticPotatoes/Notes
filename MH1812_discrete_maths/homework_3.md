1. Question 1
    1. $\exists x,y\in D, M(x,y)\land T(x,y)$
    2. $\exists x\in D, \forall y\in D, M(x,y)$
2. Question 2
    1. There exists a student enrolled in MH1812
    2. There exists a course that Carol is taking
    3. There exists a student who is taking both MH1812 and CZ2002
    4. There are two students who will only take courses together
3. Question 3
    1. false, x=2, y=2, z=2, P(x,y,z)=8
    2. true, x=1,y=1,z=1, P(x,y,z)=1
    3. true, z = 1/(xy), P(x,y,z)=1
    4. false, x != 1/(yz), P(x,y,z)!= 1
4. Question 4
    1. $\exists x,y,\lnot P(x,y)$
    2. $\forall x,y,\lnot P(x,y)$
5. Question 5
    1. $\forall x, \lnot(P(x,MH1812)\land P(x,CZ2002))$
    2. $\forall x,\forall y,\forall z,(x=y\lor\lnot(P(x,z)\leftrightarrow P(y,z)))$
6. Question 6:  
    $\forall x\in D, P(x)\rightarrow Q(x)$  
    Contrapositive: $\forall x\in D, \lnot Q(x)\rightarrow\lnot P(x)$

    |$P(x)$|$Q(x)$|$P(x)\rightarrow Q(x)$|$\lnot Q(x)\rightarrow\lnot P(x)$
    |-|-|-|-
    |T|T|T|T|
    |F|T|T|T|
    |T|F|F|F|
    |F|F|T|T

    $\therefore (P(x)\rightarrow Q(x))\equiv(\lnot Q(x)\rightarrow\lnot P(x))$
7. Question 7:  
    LHS = $\lnot(\forall x,P(x)\rightarrow Q(x))$  
    $\equiv \lnot(\forall x, (\lnot P(x)\lor Q(x))$  
    $\equiv\exists x,\lnot(\lnot P(x)\lor Q(x))$  
    $\equiv\exists x,(P(x)\land\lnot Q(x))$ = RHS
