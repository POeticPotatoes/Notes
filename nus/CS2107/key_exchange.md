# TLS
### Components of TLS
* Data formatting
* Transmission
* Error Checking

## TCP Protocol Order
1. 3-Way TCP Handshake: TCP SYN, TCP SYN + ACK, ACK
2. Authenticated Key Exchange
    * "Client Heya", crypto info
    * "Server Yahoo", provide certificate (Verified by client)
    * Authenticated Client key exchange, send secret key info (Verify client cert if needed)
3. TLS Complete: Both Done
4. Secure Communication: talk

## 2. Key Exchange
* Unilateral authentication: Bob challenges Alice to encrypt **nonce** with shared secret key
    * Prevents Replay
    * Nonce: Number Used Once (randomly generated challenge)
    * Both MAC and PKC works (For PKC, initial cert is required)
* Key Exchange Protocol:
    * PKC based (Easy authentication, no PFS)
    * Diffie Hellman (PFS)
    * Password-Authenticated Key Agreement (PAKE)
* Authenticated Key Exchange
    * Diffie Helman (DH) can sign messages during key exchange: Station-To-Station Protocol (STS)
    * PKC is already based

#### Security Requirements
* Perfect Forward Secrecy (PFS): Even if long-term key is compromised, past communication sessions are still secure
    * Achieved with temporary, ephemeral keys
    * Diffie Helman is better
    * Mandated by TLS
    * Use keys sparingly + for specific functions
        * eg. different sesh keys for enc and auth

### Diffie Hellman Key Exchange
1. Public: Generator G + Prime p
2. Alice chooses secret $a$ and computes $x=g^a\mod p$
3. Bob chooses secret $b$ and computes $y=g^b\mod p$
4. Transmit x and y
5. Final secret: $g^{ab}\mod p$

* Assumes difficulty in finding $g^{ab}$ from $g^a\mod p$ and $g^b\mod p$
* Discrete logarithm problem:
    * $y = g^x\mod p$, given g, y and p, difficult to find x
* Issue: No defense against MITM attack

## 4. Secure Communication (Authenticated Encryption)
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
* QUIC (Quick UDP Internet Connections): uses 1 RTT for new connection
