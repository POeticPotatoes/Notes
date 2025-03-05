# Types of Authentication
1. Communicating Entity Authentication
    * Verifying identity of parties
2. Data Origin Authentication
    * Verifying source of data

* MAC & Digital Signatures provide both
* Passwords proide communicating entity authentication
* Credentials: information that proves identity (communicating entity)

### Types of Credentials
* Knows (passwords)
* Is (biometrics)
* Has (documents)

# Passwords
### Passwords vs Keys
* Passwords are generated, rememberable
* Keys are binary sequences, infeasible to remember
* Keys can be derived from passwords

### Password Systems (Knows)
1. Bootstrapping
    * User and server establish common password
    * Server keeps password file
2. Authentication
    * Server authenticates some entity
    * Entity must convince server that it knows the password
3. Password reset
    * Only authentic entity can reset password
    * If current password is not known, need some other credential
        * Human (manual) verification
        * Recovery email
        * Security questions
### Bootstrapping
* Default password: Attacker may intercept/ know default password
    * Change password after login...

### Password storage (hashing)
* Preimage resistance is the most important

### Password Reset/ pwd reset poisoning
* Goal: obtain OTP to change pwd
* Pwd reset link rng could be predicted
* Pwd reset poisoning: changing host request domain to have a malicious reset link sent to user
* mitigation: 
    * ensure robust validation/ sanitization of HTTP headers & user inputs
    * use server-side configurations to generate URLs
    * educate users about shitty links
    * HTTPS, 2FA

## Password Reccs
* NIST password guide: 8-15 chars
    * Upper, lower, number, char
* Proactive checker
* \>= 29 bit entropy, do 36-59 for more security against **online**
* for **offline**, 128

### Dictionary Attacks
* Online: brute force (rate limit!!)
* Offline: also brute force, but offline (salt it!!)
* Pasword checking/ metering helps for strong passwords
* Regular password changing
* 2FA

### Stealing Techniques
* Sniffing
    * Shoulder surfing (peeking)
    * Side-channel attacks (sound, em waves, etc)
* Virus and keylogger
    * Software/ hardware
* Phishing
    * Fake website
    * Prevent by blacklisting sites, training users
* Cache/ Lost password files
    * Shared workstations

# Biometric Data
* Issue of noise: chance of precise match is low
    * Biometrics measure similarity instead, based on predefined threshold
    * Therefore FMR false match rate (false positive) and FNMR (false non) is issue
* Presentation attacks: fake prints
    * Check if person is live, temperature
    * Limit attempts
* Replay attacks
    * Check for liveness, 2FA

# Tokens
* OTPS: to increase security, enter password for OTP
* Time-based: share same pseudo random based on time
* Sequence-based: maintain manual counter with server

# 2FA
* 2 factors must be employed (strict definition)
* 2 step verification: email + password is something you know (not strict)
