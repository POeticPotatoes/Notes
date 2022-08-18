1. Show that 2 is the only prime number which is even.  
    * Let F be a function such that F(n) returns a set containing sets of possible factorisations for $n\in\mathbb{Z}$.  
    * Since prime numbers are defined as numbers only divisible by itself and 1, for the set of prime numbers $P$:
        $\forall p\in\mathbb{P}, F(p) = \{\{1, p\}\}$
    * Even numbers are defined as numbers which are divisible by 2. For the set of even numbers $E$:
        $\forall e\in\mathbb{E}$, $F(e)\in\{2, f\}, f\in\mathbb{Z}$
    * The set of prime numbers which are even can be determined with the intersection of all possible factorisations of prime numbers and even numbers, $F(\mathbb{P})\cap F(\mathbb{E})$
    * $F(\mathbb{P})\cap F(\mathbb{E}) = \{\{1, 2\}\}$ where $p = 2, e = 2, f = 1$
    * Therefore the only prime number which is even is 2.
2. Prove that if n^2 is even, n is even, for n an integer
    * Given that the set of prime factors for an integer n is F(n),   
        $F(n^2) = F(n)$
    * If n^2 is even,  
    $2\in F(n^2)$  
    $\implies 2\in F(n)$
11. $u \rightarrow \lnot p$  
    $\implies u\rightarrow r \land \lnot s$ since $\lnot p \rightarrow r\land\lnot s$ (Hypothetical Syllogism)  
    $\implies u\rightarrow r\land\lnot t$ since $t\rightarrow s\implies\lnot s\rightarrow\lnot t$ (Modus Tollens)  
    $\implies \lnot(r\land\lnot t)\rightarrow\lnot u$ (Modus Tollens)  
    $\implies\lnot r\lor t\rightarrow\lnot u$ (De Morgan)  
    $\implies t\rightarrow\lnot u$

    since $u\lor w, t\rightarrow\lnot u$  
    $\therefore t\rightarrow w$
