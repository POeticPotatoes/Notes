# Introduction
Internal: 
* Systems Security
* Infrastructure Security
* Software & Platform Security

External:
* Human, Organisation, Regulatory aspects
* Attacks & Defences

## Main Objectives of Computer Security
Type| Keyword | Definition | Suggestion | Crypto
Availability | Access | Redundancy
Authentication | Identity | 2FA | Y
Authorization | Permission | Access Control List
Confidentiality | Secrecy | Encryption | Y
Integrity | Unmodified | MAC-msg auth code | Y
Non-Repudiation | Undeniable | Digital Signature |Y
Accountability | Responsibility | Log Trail

### Definitions
* Authentication: Verifying the user's identity
* Authorization: Checking if a user has permission to perform an action
* Confidentiality: Maintain secrecy of the contents of a transient message/data on temporary/persistent storage
* Integrity: No third party may modify contents of messages during communication
* Accountability: Determine who attacker/ principal is if something goes wrong/ errors are identified
* Availability: Respond to all users in reasonable timeframe
* Non-Repudiation: Ensure undeniability of a transaction by any party involved

## Authentication
Usually done over TLS/SSL (Ecommerce provide server authentication during purchase)
* Weak/ Simple Authentication
    * Unilateral
    * Prove knowledge of secret by giving secret
* Strong Authentication
    * Mutual
    * Prove knowledge of secret without giving secret

Based on:
1. Know (passwords)
    * Might not be strong
    * Vulnerable to password cracking programs
2. Have
    * OTP Cards
        * RSA SecurID
        * Flashes a new password periodically (60s)
        * Server knows algorithm for generation, verifies password (Synchronous)
        * Other systems generate password on PIN entry
        * Now relies on smartphones
    * Smart Cards
        * Tamper resistant, will self-destruct
        * Issues challenge to user
        * User enters PIN
        * User is then authenticated
        * Access to secret information on card is granted
        * Smart card reader must be trusted (eg setting up kiosk with bait)
    * ATM Cards
        * Magnetic stripe that stores data
3. Are (Biometric)
    * Types
        * Palm Scan
        * Iris Scan (more acceptable, very slow)
        * Retina Scan
        * Fingerprint (not socially accepted, think of criminal)
        * Voice (compare to databank of signals)
        * Face
        * Signature
    * False positive/ false negative
    * Consider effectiveness & social acceptability
    * Key changing (if biological measurements are taken, impersonation can occur)
    * Must defend against fraud (Processing fingerprints from glass surfaces)

## Encryption
Password hashes: Argon2, bcrypt, PBKDF2
* Age passwords
* Limit login attempts
* Inform User of last login

Types
* Passphrase (long phrases)
* Visual drawing patterns
* Picture passwords
* OTPs (Based on HOTP, HMAC based algo)

One Time Pad Problems:
1. How to generate true random
2. How to store securely
3. How to encrypt/ decrypt securely
4. How to synchronize
5. How to agree on new OTP

# Singtel Case Study
1. **Effective Training** Methods against phishing
2. Internet connections to prized assets must be regulated, especially **remote connections**
3. 2FA should not be bypassable
4. Coding Vulnerabilities must be patched, cannot rely on users
5. Strong passwords policy/enforcement
6. Vulnerabilities highlighted in penetration tests must be fixed
7. Inactive email accounts must be removed immediately (reduce attack surface area)

# CRYPTOGRAPHY
Fundamental Concepts
* Confusion (obscure relationship between plaintext and ciphertext)
* Diffusion (1 change affects entire ciphertext)

## Symmetric Key
### Stream cipher (enigma, grain)
* Key is stretched into infinite (extremely long period) keystream
* Similar to OTP

Steps
1. Generate pseudorandom bits (deterministic, relies on seed)
2. Encrypt by XORing with generated keystream

Example  
$KS = SC(K, n), C=P\oplus KS$

KS: KeyString  
SC: Stream Cipher  
C: Ciphertext  
P: Plaintext

Both encryption & decryption can use the exact same circuit: **Feedback Shift Registers (FSR)**.

#### Feedback Shift Registers (Linear Recurrence)
* Example: $S_{i} = S_{i-1} \oplus S_{i-2}$

### Block cipher (Rijndael, AES (Advanced Encryption Standard))
* Multiple weirdo rounds
* Relies on substitution table for non-linear operations

#### Modes of Encryption
* ECB (Electronic Codebook): Chop into blocks + padding
    * Facilitates parallel encryption/ decryption
    * If blocks are same, repeated cipher will appear
* CBC (Cypher Block Chaining)
    * IV XORs input (IV chains from previous block) before encryption
    * Cypher blocks will be different
    * Cannot be encrypted in parallel
* CTR (Counter)
    * Basically generates a pad with a deterministic/ random counter
    * Can be done in parallel

### Key Security
1. Generate keys
2. Store keys
    * Never store in plaintext
    * Store in Hardware Security Module HSM or isolated cyrptographic service (All operations must be done in HSM)
3. Lifecycle of keys
4. How many different keys
5. How to destroy keys

### Hash Functions
1. Pre-Image Resistance
2. Second Pre-Image Resistance (Knowing password and digest, no collision can be found)
3. Collision Resistance (Collision must not be found easily)

Other Good Properties
1. Fast for integrity checking
2. Slow for password hashing
3. Long length
4. Diffusion

## Asymmetric Key Cryptography
Confidentiality + Authentication

Example: RSA 1024, 2048

### Strength of Private Key Algo
* Algo Design
* RNG
* Key Length
* Secure Implementation

### RSA
* N is the product of 2 k-bit prime numbers
* To find primes:
    * Find large random odd number, find nearest prime
* However, some parameters are weak
    1. If prime is <512 bits, considered small
    2. If p & q are not independently generated
    3. RNG fails
    4. Decryption key $d\leq [N^{0.25}]/3$
    5. p-1 is a product of small primes
    6. Reuse of N

### Diffie-Helman Key Exchange
* Prime p must be >1024
* For long term, go 1536/2048
* Make sure p-1 has a super large prime factor
* Choose p-1 = 2q, q is prime

# Cryptographic Failures
* Use of hard-coded password
* Broken or Risky Crypto Algorithm
* Insufficient Entropy

Requirements for a Cryptographically strong System
1. Strong Crypto Algos
2. Secure Hash Function
3. Strong RNG (ISAAC, FORTUNA)

* Same Crypto Algos (private/ public)
* Keys Used (crypto secure RNG)
* Protocol must be robust, no leakage, no weakened entropy
