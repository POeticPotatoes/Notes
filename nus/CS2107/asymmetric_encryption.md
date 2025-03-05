# Asymmetric Encryption
* Representation: $<k_e, k_d>$ (public, private), known as **decryption key**
* Both are required for decryption

## Requirements
* Given public key, ciphertext, difficult to determine plaintext
    * implies difficult to get private key from public key
* Since anyone can encrypt text, encryption oracle is always accessible
    * Chosen plaintext attack must be considered
* Secure broadcast channel (verify authenticity of key ownership)

## Classroom RSA
* Stages:
    1. Key generation
    2. Encryption
    3. Decryption 

### Key Generation
1. Choose p, q, compute 
    * $n = pq$
    * $\phi(n) = (p-1)(q-1)$ (totient function)
2. Randomly choose exponent e such that $gcd(e, \phi(n))$ = 1
3. Find multiplicative inverse of e mod $\phi(n)$
4. Publish $<n, e>$ as public key, $d$ as private key

### Encryption
1. Public key: $<n, e>$
2. given m,  ciphertext $c = m^e mod\ n$

### Decryption
1. Decryption key: $<n, d>$
2. Given c, the plaintext $m = c^d mod\ n$

| Key idea: Difficult to derive d unless you obtain p and q from n

| Correctness: for any positive m < n, D(E(m)) = m

## Security of RSA
* RSA problem: given $<c, e, n>$ without d is difficult
    * Commonly equated to integer factorization problem, not definitively proven
* 2048 bits is still considered secure

### IV and Padding
#### Problems
* IV is still required
* Homomorphic property: ciphertexts can be multiplied
    * RSA is **malleable**, ie ciphertexts can be manipulated
* Therefore padding schemes are used (eg. OAEP, Optimal Asymmetric Encryption Padding)

### Efficiency
* 128-bit AES and 3072-bit RSA have same equivalent key strength
* Key management might be difficult for larger keys
* Exponentiation is much more computationally intensive compared to substitution and permutation (SIGNIFICANTLY slower than AES)
    * Therefore RSA can be used to transmit the secret key of AES securely instead

