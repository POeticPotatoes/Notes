
2. Prove that $\forall n\in N, \sum_{n-1}^{i=0}(2i+1) = n^2$  

    Proof by induction:  

    let $P(n)\equiv\sum_{i=0}^{n-1}(2i+1) = n^2$  

    $n=1, \sum_{i=0}^{n-1}(2i+1) = 1 = n^2, \therefore P(1)\equiv T$  

    Assume $P(k)\equiv T, k\in\mathbb{N}:$  

    for $n=k+1, \sum_{i=0}^{n-1}(2i+1)=k^2 + 2k + 1 = (k+1)^2$  

    $\therefore P(k)\rightarrow P(k+1)$  

    By induction,

    $\therefore \forall n\in N, \sum_{n-1}^{i=0}(2i+1) = n^2$  
