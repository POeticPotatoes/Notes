# FINALLY
### Definitions
* Computer Security: Protection for automated information system that preserves **integrity, availability, confidentiality**
* Known tradeoffs: Ease-of-use, performance, cost
* Challenges:
    * Not considered in early design stage
    * Requiremment formulation
    * Design difficulty
    * Bugs
    * Managing

### Describing Security
* Rigorous method of describing security: describing **class of attacks it can prevent** 
* Defined on attacker's goals + capabilities (attack model, threat model, adversary model, security model)

## Encryption
### Properties
* Correctness: $D_k(E_k(x)) = x$
* Security:
    * Difficulty of deriving useful information of the key or plaintext from ciphertext
    * Ciphertext indistinguishable from random stream
* Probabilistic: for same plaintext, different ciphertext can be produced
* Common Terminology: 
    * Alice -> Bob
    * Eve: Eavesdropper
    * Mallory: Modifier
* Goals of an Attacker
    * Total break: find key
    * Partial break: info about plaintext
    * Distinguishability: Distinguish 2 ciphertexts with a probability > .5
        * Indistinguishability (IND) means the scheme is **semantically secure**
### Attack Types
* Ciphertext-only + some information about plaintext (CTO)
    * Apply statistical tests
    * Exhaust possible keys
    * Challenge: inconclusive test
* Known Plaintext (KPA): Collection of plaintext -> ciphertext (Cannot choose plaintext)
    * May guess plaintext patterns (postscript format, headers)
    * May find key
* Chosen Plaintext (CPA): choose plaintext -> ciphertext
    * **Encryption Oracle**
* Chosen Ciphertext (CCA2): choose ciphertext -> plaintext
    * **Decryption oracle**
    * Weaker forms can only decode some parts of plaintext


