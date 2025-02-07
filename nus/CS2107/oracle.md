## Definitions
* **Kerckhoff's Principle**: System should be secure even if everything about the system except secret key is public knowledge (Basis of open source systems)
* **Key Space**: set of possible keys
* **Key Size**: number of bits to represent a key
* **Initialization Vector (IV)**: Ensures even if same key is used, keystream will be different
    * Can be sent with ciphertext
    * Examples: RC4, AES in CTR mode
* **Pseudo-random generator (PRG)**

## Block Cipher Encryption Modes
#### Electronic Code Book (ECB)
* Encrypt each block individually
* Downside: Same key would result in repeated blocks
#### Cipher Block Chaining (CBC)
* XOR block with previous block
* Downside: Not parallelizable
#### Counter Mode (CTR)
* Use increasing IV for block encryption
* Similar to stream cipher

## Attacks
#### Meet in the Middle (2DES)
* If multiple encryptions are used on DES key space is not increased:
    * For KPA: encrypt from plaintext and decrypt from ciphertext: map and find match
    * For k-bit keys: crypto operations reduced to $2^{k+1}$ with similar storage space
* 3DES (121) encryption remedy
#### Padding Oracle Attack
* PKCS#7 Padding standard: padding value is number of bytes padded
* Padding Oracle: decrypts and checks if padding format is correct (returns YES/NO)
    * Weaker form of decryption oracle
* CTO: given ciphertext(iv,c): modify padding and last non-padded byte until oracle recognises non-padded byte as padding
* Initial padding can be determined if server has an error
* CBC and CTR are vulnerable to padding oracle
* Prevention
    * Deny access to oracle
    * Change padding standard
