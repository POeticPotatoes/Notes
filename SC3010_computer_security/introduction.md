# Computer Security
## Key intention
* Allow intended use of computer systems
* Prevent unwanted use that may cause harm

### Attack Motivations
* Financial profit 
    * Steal personal data and sell them to the black market
    * Obtain credit-card information/ bank accounts
    * Ransomware
* Politics
    * Government Actors (Spying on information)
    * Private Activism

## Computer System Security
Objective: Provide a protected environment for data and their processing

### Reasons for System Security Failure
* Cryptographic Algorithms are broken
* Security Features are not **designed** correctly
* Security Features are not **used** correctly
* Security **Components** are not **implemented** correctly
* Security **Components** are not **configured** correctly
* Security is not **managed** properly
* **Threat environment** may change and assumptions are now invalid


## Trust
The degree to which an entity is expected to behave

Must be defined:
* What the entity is expected to do
* What the entity is expected NOT to do

Security CANNOT be established in a computer system if NO entities are trusted

### Trusted Computing Base (TCB)
A set of system components that MUST be trusted to ensure the security of the system. Components outside of the TCB can be malicious and misbehave

* Assume all components in the TCB are secure with _valid justifications_
* Prevent any damages from any components **outside** of the TCB
* Smaller TCB -> More trustworthy as less assumptions can be violated
    * Also more challenging as more entities are considered malicious

### Threat Model
<important>
Describing adversaries
1. What is (and is not) trusted
2. For untrusted resources: 
    * resources, 
    * capabilities, 
    * knowledge, 
    * actions
3. Security Properties to achieve (Security Goals)
</important>

### Security Properties
Security goals that we aim to achieve for the system

<important>
CIA Model

* Confidentiality: Prevent unauthorized disclosure of info
* Integrity: Prevent unauthorized modification of info
* Availability: Prevent unauthorized **withholding** of information
</important>

Other properties
* Accountability: Actions of an entity can be traced
* Non-repudiation: Unforgeable evidence that specific actions occur
* Authenticity: Ensure that communicated entity is correct

### Security Strategies
* Prevention: Prevent system from being damaged
* Detection: Detect **when, how, whom** damaged your system
* Reaction (After Detection): Allow system to recover from a damaged state

### Design Principles
* Principle of Least Privilege
    * Entity should be given minimal permissions to complete its task
    * Give privilege when required, and revoke privilege after use
    * Granting extra permissions can allow malicious entities to perform attacks
* Principle of Separation of Privilege
    * Separation of duty: Distribute privileges to different entities working together
    * Single malicious entity will not have the permissions to perform an attack
* Defence in depth
    * Multiple types of defenses should be layered
    * Increase difficulty of attacking entire system
