## 1.1
We prove that the additive inverse -x is unique by contradiction:

Assume the additive inverse -x is not unique, then there exists $a, b\in F$ such that:
1. $a+x=0\land b+x = 0$
2. $a\neq b$

Consider the expression $(a + (-b))$. We can show that:
* $-b \in F$ by definition
* If $a + (-b) = c$, then $c\in F$ since $F$ is closed under addition.
* Adding $b$ to both sides, $(a + (-b)) + b = a + (-b + b) = a + 0_F = a$
* Hence w.l.o.g. $(\exist c\in F)(a = b + c)$
* We can further assume $c\neq 0_F$ since otherwise $a = b + 0_F = b$

Then adding $x$ to both sides, we have:

$x + (b + c) = (x + b) + c = c$

$x + a = 0_F$

Implying that $c = 0_F$, contradicting our earlier assumption. $\blacksquare$

## 1.2

We start from the definition of $-1_F$:

$1_F + (-1_F) = 0_F$

Then by the distributive law:

$(1_F + (-1_F))x = 0_F x$

$1_Fx + (-1_F)x = 0_Fx$

$x + (-1_F)x = 0_F$

Adding $-x$ to both sides, we have:

$-x + (x +(-1_F)x) = (-x + x) + (-1_F)x = 0_F + (-1_F)x = (-1_F)x$

$-x + 0_F = -x$

Therefore we have shown that $(-1_F)x = -x$. $\blacksquare$
