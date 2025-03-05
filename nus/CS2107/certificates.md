# Key Distribution
Key ideas
* Securely distribute keys
* Announce/ distribute/ broadcast key only once

Solutions
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
* Public Key Infrastructure (PKI)
    * Can be public/ private
    * The solution!

## Public Key Infrastructure
Framework to securely distribute keys. Key Features:
1. Key pair generation
2. Digital certificate
3. Certificate revocation

### Digital Certificate
* Binds entity to a public key
* Correctness is asserted via a signature by a certificate authority (CA)
* CA (Charlie) is a **trusted third party** with its own public/ private key
    * Assume public key is preloaded and securely distributed
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

#### Self-Signed Certificate
* Signed by organisation's own private key
* User must manually accept certificate

#### Domain Validated (DV) Certificate (Buying domains)
* Least stringent
* Only verifies if applicant owns domain
* Only confirms ownership, no entity validation

#### Extended Validation (EV) Certificate
* Much more stringent identity validation
* Extremely rigorous
* More expensive, more time

### Certificate Issues
* Crazy amount of CAs
* Compelled certificates
    * Governments can order CAs to issue false certificates
    * Used to covertly intercept/ hijack individuals' secure communications

### Certificate Revocation
1. Certificate Revocation List
    * Can be large
    * Only track changes
2. Short-Lived Certificate
    * Heavy load
3. Online Certificate Status Protocol (OCSP)
    * Check with CA whether still valid
    * Traffic overhead
    * CA learns users' activity
4. OCSP Stapling
    * OCSP response queried by server periodically
    * Sends OCSP along with cert
    * Better

### Security Issues with PKI
* CA might issue to some scam
* Hard to detect bad CA
* Scary to announce scams for CAs

Hence we have **Certificate Transparency**
* Provide a **certificate log** (CL): public, verifiable, append-only log of certificates
    * **Proof of inclusion** provided with certificate
* Anyone can monitor logs for mess-ups
    * No scams
    * No changes
* Data structure: Merkle Tree
    * Distribute signed tree head
    * Share neighbour nodes at each level to calculate back signed tree head

Requirements of CL: 
* Available
* Consistent
* Low latency
    * Issue Signed Certificate Timestamp (SCT), promise to add within maximum merge delay (MMD)

