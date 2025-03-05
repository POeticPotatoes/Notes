## Hash Functions
### Security Requirements
* Collision Resistance
    * Computationally infeasible to find any
        * $<F, F'>, F' \neq F$
        * $H(F) = H(F')$
* Preimage Resistance
    * Given h, computationally infeasible to find $H(F) = h$
* Second Preimage Resistance
    * Given f, computationally infeasible to find $H(F') = H(F)$
    * Collision Resistance, given a specific F
### Limitations of Unkeyed Hashes
* Integrity verification but not authentication (sender's identity)
* Collision/ Second Preimage Resistance is scary (birthday attacks)

### Attacks
* Brute force: $>2^n$ by pigeonhole principle
* Birthday paradox probability
    * M messages, T possible randomly chosen digests
    * P(collision) = $1 - e^{-\frac{M^2}{2T}}$
    * ie. when $M > 1.17 \times T^{1/2}$, P(collision) > 0.5
        * if $T=2^n$, $M > 1.17 * 2^{n/2} \approx 2^{n/2}$
    * Hashes should be designed such that known attacks **cannot do better** than bday attack

## Keyed Hash: Message Authentication Code (MAC)
* Hash Function that uses a **secret key**
* Secret key must be shared between sender and receiver

### Popular Examples
* AES CBC Mode final block can be used as a MAC
* HMAC (Hash-based MAC, based on SHA)
* Common uses:
    * If the channel is not secure to deliver a digest, MAC can be used if secret key is already shared

## Signature Schemes
* Reverse direction of RSA is considered **signing**
* PKC (Public Key Crypto) version of MAC is  Digital Signatures
* Issue: RSA is slow (inefficient for signing large files)
    * Solution: Signing hash values

### Comparison between MAC and Signatures: Non-repudiation
* MAC: Both sides can generate messages with secret key
* Signatures: Only one side can generate a message with private key
