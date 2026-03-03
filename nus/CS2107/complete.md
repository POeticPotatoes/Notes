### Definitions
* Known tradeoffs: Ease-of-use, performance, cost
* Challenges:
    * Not considered in early design stage
    * Requiremment formulation
    * Design difficulty
    * Bugs
    * Managing issues

### Describing Security
* Rigorous method of describing security: describing **class of attacks it can prevent** 
* Defined on attacker's goals + capabilities (attack model, threat model, adversary model, security model)

#### Types of Authentication
1. Communicating Entity Authentication: Verifying identity of parties
2. Data Origin Authentication: Verifying source of data

* MAC & Digital Signatures provide both
* Passwords provide communicating entity authentication
* Credentials: information that proves identity (communicating entity)

#### Types of Credentials
* Knows (passwords)
* Is (biometrics)
* Has (documents)

#### Passwords
* Passwords are generated, rememberable
* Keys are binary sequences, infeasible to remember
* Keys can be derived from passwords

#### Password Systems (Knows)
1. Bootstrapping
    * User and server establish common password
    * Server keeps password file
    * Change password after login to avoid default password
2. Authentication
    * Server authenticates some entity
    * Entity must convince server that it knows the password
3. Password reset: Only authentic entity can reset password

#### Password storage (hashing)
* Preimage resistance is the most important

#### Password Reset/ pwd reset poisoning
* Goal: obtain OTP to change pwd
* Pwd reset link rng could be predicted
* Pwd reset poisoning: changing host request domain to have a malicious reset link sent to user
* mitigation: 
    * ensure robust validation/ sanitization of HTTP headers & user inputs
    * use server-side configurations to generate URLs
    * educate users about shitty links
    * HTTPS, 2FA

#### Password Reccs
* NIST password guide: 8-15 chars
    * Upper, lower, number, char
* Proactive checker
* \>= 29 bit entropy, do 36-59 for more security against **online**
* for **offline**, 128

#### Dictionary Attacks
* Online: brute force (rate limit!!)
* Offline: dictionary attack (salt it!!)
* Pasword checking/ metering helps for strong passwords
* Regular password changing
* 2FA

#### Stealing Techniques
* Sniffing
    * Shoulder surfing (peeking)
    * Side-channel attacks (sound, em waves, etc)
* Virus and keylogger software/ hardware
* Phishing: fake website
    * Prevent by blacklisting sites, training users
* Cache/ Lost password files

##### Biometric Data
* Issue of noise: chance of precise match is low
    * Therefore FMR false match rate (false positive) and FNMR (false non) is issue
* Presentation attacks: fake prints
    * Check if person is live, temperature
    * Limit attempts
* Replay attacks
    * Check for liveness, 2FA

#### Tokens
* OTPS: to increase security, enter password for OTP
* Time-based: share same pseudo random based on time
* Sequence-based: maintain manual counter with server

#### 2FA
* 2 factors must be employed (strict definition)
* 2 step verification: email + password is something you know (not strict)

## Encryption
### Security Requirements
* Correctness: $D_k(E_k(x)) = x$
* Security:
    * Difficulty of deriving useful information of the key or plaintext from ciphertext
    * Ciphertext indistinguishable from random stream
* Probabilistic: for same plaintext, different ciphertext can be produced
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

## Encryption
### Symmetric (Block Ciphers DES-56, AES-128)
* **Kerckhoff's Principle**: System should be secure even if everything about the system except secret key is public knowledge (Basis of open source systems)
* **Key Space**: set of possible keys
* **Key Size**: number of bits to represent a key
* **Initialization Vector (IV)**: Ensures even if same key is used, keystream will be different
    * Examples: RC4, AES in CTR mode
* **Pseudo-random generator (PRG)**

#### Block Cipher Encryption Modes
* Electronic Code Book (ECB): Same key would result in repeated blocks
* Cipher Block Chaining (CBC): XOR block with previous block (Not parallelizable)
* Counter Mode (CTR): Use increasing IV for block encryption, similar to stream cipher

#### Attacks
Meet in the Middle (2DES)
* If multiple encryptions are used on DES key space is not increased:
    * For KPA: encrypt from plaintext and decrypt from ciphertext: map and find match
    * For k-bit keys: crypto operations reduced to $2^{k+1}$ with similar storage space
* 3DES (121) encryption remedy

Padding Oracle Attack
* PKCS#7 Padding standard: padding value is number of bytes padded
* Padding Oracle: decrypts and checks if padding format is correct (returns YES/NO)
    * Initial padding can be determined if server has an error
* CBC and CTR are vulnerable to padding oracle
* Prevention
    * Deny access to oracle
    * Change padding standard

### Asymmetric Encryption (RSA-3072)
* Representation: $<k_e, k_d>$ (public, private), known as **decryption key**

#### Requirements
* Given public key, ciphertext, difficult to determine plaintext
    * implies difficult to get private key from public key
* Since anyone can encrypt text, encryption oracle is always accessible
    * Chosen plaintext attack must be considered
* Secure broadcast channel (verify authenticity of key ownership)

#### Key Generation
1. Choose p, q, compute 
    * $n = pq$
    * $\phi(n) = (p-1)(q-1)$ (totient function)
2. Randomly choose exponent e such that $gcd(e, \phi(n))$ = 1
3. Find multiplicative inverse of e mod $\phi(n)$
4. Publish $<n, e>$ as public key, $d$ as private key

#### Security of RSA
* RSA problem: given $<c, e, n>$ without d is difficult
    * Commonly equated to integer factorization problem, not definitively proven
* 2048 bits is still considered secure

#### IV and Padding
* IV is still required
* Homomorphic property: ciphertexts can be multiplied
    * RSA is **malleable**, ie ciphertexts can be manipulated
* Therefore padding schemes are used (eg. OAEP, Optimal Asymmetric Encryption Padding)

#### Efficiency
* 128-bit AES and 3072-bit RSA have same equivalent key strength
* Key management might be difficult for larger keys
* Exponentiation is much more computationally intensive compared to substitution and permutation (SIGNIFICANTLY slower than AES)

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

#### Attacks
* Birthday paradox's probability
    * M messages, T possible randomly chosen digests
    * P(collision) = $1 - e^{-\frac{M^2}{2T}}$
    * ie. when $M > 1.17 \times T^{1/2}$, P(collision) > 0.5
        * if $T=2^n$, $M > 1.17 * 2^{n/2} \approx 2^{n/2}$
    * Hashes should be designed such that known attacks **cannot do better** than bday attack

#### Keyed Hash: Message Authentication Code (MAC)
Secret key must be shared between sender and receiver
* AES CBC Mode final block can be used as a MAC
* HMAC (Hash-based MAC, based on SHA)

#### Signature Schemes (Non-Repudiation)
* PKC (Public Key Crypto) version of MAC is Digital Signatures
* Issue: RSA is slow (inefficient for signing large files)

## Key Distribution
Key ideas
* Securely distribute keys
* Announce/ distribute/ broadcast key only once

Old Solutions
* Public announcement, hard coded verification
    * Broadcasts key publicly
    * Developer can hardcode public key into software for updates
    * Not standardized
    * No systematic way to search/ verify public key, needs additional verification
    * Not easy to update
* Publish in publicly available directory
    * Anyone can post in server
    * Unclear how to verify info
    * Not everyone can trust server
    * Extreme load

### Public Key Infrastructure
Framework to securely distribute keys. Key Features:
1. Key pair generation
2. Digital certificate
3. Certificate revocation

#### Digital Certificate
* Binds entity to a public key
* Correctness is asserted via a signature by a certificate authority (CA)
* CA (Charlie) is a **trusted third party** with its own public/ private key
* CAs tend to be organised in a hierarchy of trust
    * Root CAs: trusted
    * Intermediate CA: verifiable

Contains:
* Entity identity
* Public key
* Validity (Exp date)

#### X.509 Format
Universally accepted standard for public key certificates
* Contains some extensions that may be critical
* If marked as critical and cannot be processed by some implementation, it must be rejected

#### Domain Validated (DV) Certificate (Buying domains)
* Least stringent
* Only verifies if applicant owns domain
* Only confirms ownership, no entity validation

#### Extended Validation (EV) Certificate
* Much more stringent identity validation
* Extremely rigorous
* More expensive, more time

#### Certificate Issues
* Crazy amount of CAs
* Compelled certificates
    * Governments can order CAs to issue false certificates
    * Used to covertly intercept/ hijack individuals' secure communications

#### Certificate Revocation
1. Certificate Revocation List
    * Only track changes
2. Short-Lived Certificate: Heavy load
3. Online Certificate Status Protocol (OCSP)
    * Check with CA whether still valid
    * Traffic overhead
    * CA learns users' activity
4. OCSP Stapling
    * OCSP response queried by server periodically
    * Sends OCSP along with cert
    * Better

#### Security Issues with PKI
* CA might issue to some scam
* Hard to detect bad CA
* Scary to announce scams for CAs

Hence we have **Certificate Transparency**
* Provide a **certificate log** (CL): public, verifiable, append-only log of certificates
    * **Proof of inclusion** provided with certificate
* Anyone can monitor logs for mess-ups

Requirements of CL: 
* Available
* Consistent
* Low latency
    * Issue Signed Certificate Timestamp (SCT), promise to add within maximum merge delay (MMD)

## TLS
### Components of TLS
* Data formatting
* Transmission
* Error Checking

#### TCP Protocol Order
1. 3-Way TCP Handshake: TCP SYN, TCP SYN + ACK, ACK
2. Authenticated Key Exchange
    * "Client Heya", crypto info
    * "Server Yahoo", provide certificate (Verified by client)
    * Authenticated Client key exchange, send secret key info (Verify client cert if needed)
3. TLS Complete: Both Done
4. Secure Communication: talk

#### Key Exchange
* Unilateral authentication: Bob challenges Alice to encrypt **nonce** with shared secret key
    * Prevents Replay
    * Nonce: Number Used Once (randomly generated challenge)
* Key Exchange Protocol:
    * PKC based (Easy authentication, no PFS)
    * Diffie Hellman (PFS)
    * Password-Authenticated Key Agreement (PAKE)
* Authenticated Key Exchange
    * Diffie Helman (DH) can sign messages during key exchange: Station-To-Station Protocol (STS)

#### Security Requirements
* Perfect Forward Secrecy (PFS): Even if long-term key is compromised, past communication sessions are still secure
    * Achieved with temporary, ephemeral keys
    * Mandated by TLS
    * Use keys sparingly + for specific functions
        * eg. different sesh keys for enc and auth

#### Diffie Hellman Key Exchange
1. Public: Generator G + Prime p
2. Alice chooses secret $a$ and computes $x=g^a\mod p$
3. Bob chooses secret $b$ and computes $y=g^b\mod p$
4. Transmit x and y
5. Final secret: $g^{ab}\mod p$

* Assumes difficulty in finding $g^{ab}$ from $g^a\mod p$ and $g^b\mod p$
* Discrete logarithm problem:
    * $y = g^x\mod p$, given g, y and p, difficult to find x
* Issue: No defense against MITM attack

#### Secure Communication (Authenticated Encryption)
Combines both encryption + authentication
### Protocols
* Encrypt then MAC (EtM): **best**
    * Example: AES-GCM, used by TLS1.2, TLS1.3 AEAD (Authenticated encryption w/ associated data)
* Encrypt and MAC (E&M)
    * No ciphertext integrity, only plaintext integrity
    * MACing plaintext is spooky (potential issues)
    * Used for SSH with mods
* Mac then Encrypt (MtE)
    * Padding oracle if not well implemented
    * Used by SSL (boomer, TLS newer and replaces SSL)

#### Issues
* Handshake Slo (Multiple round trips)
* Separate from base layers of TCP (New layer: more complex, inefficient)
* QUIC (Quick UDP Internet Connections): uses only 1 RTT for new connection
    1. Client: Hello, Crypto info
    2. Server: Yo, Cert, cipher suit, key materials, fin
    3. Client: Fin

## Network Security
Assumption: Some attacker among intermediate roles

Advantages of network layers: Modularity, Abstraction, Isolation  
Layers: Application, Transport (datagram), Network (packet), Link (frame), Physical

### Types of Attacks
#### Transport (DNS Spoof, DoS on DNS)
* Root DNS, Top level domain (TLD), authoritative
* DNS Spoofing: Reply to QID
* DoS on DNS: Solution is more servers
* Solutions
    * Integrity: DNSSEC (Signed response)
    * Confidentiality: DoH, DoT, DoQ (HTTPS (443), TLS (853), QUIC(784))

#### Link (ARP Poisoning)
* Happens cuz stateless, no auth, broadcast
* Solution: Static ARP entries/ Prevent single MAC multiple MAC with firewall

#### Application (DoS/ DDoS)
Reflection Attack (ICMP/ Smurf): Pizza ordering with ICMP PING on victim IP
* Amplification Attack (UDP, NTP): Request vs Response size diff (amplification factor)
* Solution
    * Routers do not broadcast
    * Prevent IP Spoofing (Not easy), Remove amplifiers (Distributed), Blocking (Collateral)

### Security Protocol
#### TLS/SSL
Application-Transport

#### Internet Protocol Security (IPSec)
Network Layer
* Authentication Header (AH) no encryption, only integrity/ auth of IP address
* Encapsulating Security Payload (ESP): Also confidentiality, although src/dest IP still visible in transport mode

#### WiFi Protected Access (WPA2)
Link-Physical

#### Virtual Private Network (VPN)
Tunnel mode of ESP (Network Layer)
* Revealed src/dest: VPN client and server

## C Programming
* Execution Integrity: Trusted and authorized code is running
* Memory Integrity: Integrity of data and code
* Control-Flow Integrity: Execution Flow

Exploits
* Stack Smashing: Place program in stack and r2w
* Stack Leak: printf
    * `%n`: write number of characters into integer
* SSL Bug: URL textbox in browser uses \0, but SSL doesn't
    * Assuming valid certificate, but weirdo domain (canvas.edu.sg\0.attacker.com)

Solution:
* Input validation, conversion to canonical representation, whitelists/ blacklists
* Use safe functions (strncpy(), printf(), fprintf())
* Bound checking for overflow
* Canary (Compiler designer): Issue is performance and only works on stack-based buf overflow
* Type safety
* Testing: White-box, black-box, grey-box
* Mem randomization (Address Space Layout Randomization (ASLR))
* Non-executable stack

## Web Security
HTTP: Stateless
* form: action(url), method
* Cookie: data set by server, `set-cookie` response header, sent back with `cookie` header

#### Cookie
* value/expiry + MAC using server key (DONT use seq num)
* Scope: control domains, subdomains, paths, that can use cookie (set by server)
    * Domain scope/ path scope: `Set-Cookie: user=john;path=/admin;domain=ex.com`
* Attributes: 
    * `secure`: only sent over https, 
    * `HTTPOnly`: not accessible by javascript
    * `SameSite`: for cross-site requests (`strict/lax`) lax means sent via top-level navigation
* Same-Origin Policy (SOP): Implemented in web browsers, prevents non-same origin tabs sharing information in javascript
    * Prevents direct access of cookies
    * Prevents reading of responses from triggered request (Request is NOT stopped)
    * Same Origin: Protocol/ Host/ Port, Same Site: Protocol/ Last part of domain name

#### Cross-Site Request Forgery (CSRP)
Autosumbit form with `<script>document.evil.submit()</script>`
* Needs auth cookie present + clicked on evil link
* Solution:
    * Check HTTP referrer header
    * CSRF Tokens: Generate unique token per session, included in HTML form as hidden field
    * `SameSite=strict`

#### XSS Attack
* Reflected: Link sent to user, Persistent: Link stored in server
* Solution: Blacklisting (Hard), Whitelisting, Escape untrusted input, `httpOnly`

#### SQL Injection

## Access Control
Works between user and system resources, restricts operations on objects by subjects
* Subject, Principal: humans
* Object: **the thing**
* Access Modes: actions/ operations

#### Security Perimeter
Limits spread of malicious activities in/ out
* Principle of Least privilege (fewest resources necessary)
* Compartmentalization (divide sensitive information into isolated sections)
* Defense in depth/ Swiss Cheeze (defence in depth)
* Segregation of duties (prevent single person from having complete control)

#### Discretionary Access Control (DAC)
Owner sets permissions
* Access Control Matrix/ List (ACL)/ Capabilities List by reference monitor
* ACL vs Capabilities: Hard to obtain list of objects a subj has access to (and vice versa)

#### Mandatory Access Control (MAC)
Perms are based on centralized system-wide policy
* Public, Confidential, Secret, Top Secret
* Bell-LaPadula (Military, Govt): No read up, No write down (Confidentiality)
* Biba (Businesses): No write up: No read down (Integrity)

#### Intermediate Control
* Grouping (Unix: Owner, group, world)
* Role-based, Protection Rings (Highest 0, unix: kernel and user mode)

#### Controlled Invocation
* Allow predefined access mode: elevated privilege (bridge)
* Unix: Real UID: invoker, Effective UID: determines access rights
* s: Set User ID (SUID)

#### Time Of Check To Time Of Use (TOCTTOU)
Race condition between check and usage using symlinks

Solution:
* Avoid separate system calls (NOFOLLOW flag for `open()`)
* Fstat: Use file descriptor to retrieve file info and check perms instead of name
* OS Access Control: Set EUID to user, let OS do it
