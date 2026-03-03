principle of easiest penetration (most vulnerable at its weakest point)

Threat model
* Setup
* Assumption (Prereqs)
* Attacker Capability
* Attacker Goal

NOP sled

Requirements for payload use
1. Loaded in memory
2. Executable
3. Divertable

x86 Layout (Always draw high to low)
* HIGH
* Env variables
* Command Line args
* Caller's frame
* Your frame
    * return pointer
    * base pointer < RBP points here
    * variables growing lower
    * < stack pointer 
* LOW

Argument Registers
1. RDI
2. RSI
3. RDX
4. RCX

Heap Organization
* glibc (std. C) manages mem allocations
* stores allocated and unallocated chunks in linkedlist
* requests for more VA pages when all memory is allocated

Double free
* Add 2 entries to free list
* Allocate once
* Modify the linked list in new allocation
* Allocate again -> Now points to custom addresses

Code Checking Tools (static code analysis)
* Address Sanitizer
* ITS4 (It is the Software, Stupid --- Security Scanner)
* RATS (Rough Auditing Tool for Security)
* Flawfinder

Stack Canary
* Cannot overcome double free/ use after free
* Threat model is spatial overflow
* Susceptible to format streams

Other solutions
* Guard Pages: Memory protection with pages with NR, NW, NX (Not on by default)
* Non executable data (DEP): data can only be written OR executed (W XOR X)
    * Does not prevent redirection
* ASLR: Susceptible to NOP sled & Format streams
* research: bitblaze

Examples of Reference Monitor Policies
* Linux seccomp
    * Only exit() sigreturn() read() write() to already-open file descriptors
* Linux seccomp-bf
    * Configurable policies
* Linux Security Modules (framework)
* Policies can include syscall data args as well

Allow vs Block listing
* Cons: Allow is very restrictive

Security Principles
* Separation of Concerns -> Add a layer of indirection/ flexibility
* Minimize Trusted Code Base

User vs MAC authentication: Authenticity (Identity) vs Integrity (Unmodified)

Means of User Authentication
* knows (password, PIN)
* possesses (key, token, smartcard)
* is (static biometrics): fingerprint, retina
    * (modern) iphone and android systems are offline, isolated from rest of chip (not extractable by phone hackers)
    * alipay and singpass are online (ass)
* does (dynamic biometrics): voice, sign

Access Control Principles
* Authentication function -> Access Control Function (Queries Authorization Database) -> System Resources
* Note that subject is tricky
    * eg. the subject in a browser is the website, protecting data from other websites
    * android: subject is the application, protecting data from other applications
* SetUID (suid) lets others use permission as owner (typically set as execute bit for stuff like sudo)
* sticky bit on directories limit rename/ move/ delete

Discretionary Access Control (DAC) vs Mandatory Access Control (MAC)
* DAC not fixed, every owner decides access rules, eg UNIX
* MAC fixed by admin, owner cannot change access rights of anyth created or owned, eg Android & Browser
    * Saves a ton of space on access control (Subject x Role + Role x Object tables smaller than Subject x Object tables)

Capability Example
* `$ cp < foo.txt > bar.txt`
* foo.txt and bar.txt provide capabilities
* cp can only use capabilities provided, has no default authority
* It is an **Alternative** to Access Control:
    * Access Control is prespecified and implemented centrally by security monitor
    * Access rights can change, checks use latest rights
    * Assumption of complete mediation (No missing access checks)
    * Capabilities have no pre-specified policy of who can access what
    * Capabilities can be revoked when access rights change
    * Assumption of unforgeability (Must not be leaked or forged)

Examples of "Pollution" in Bell LaPadula
* Reading lower security stuff with buffer overflow
* Writing shit up

Chinese Wall Model (Partition)
* Alternative to BLP and Biba
* Subjects, Information (Objects, Dataset (DS), Conflict of Interest Class (CI)), Access Rules
* Basically separate everything

False positives
* U have to assume processes are mixing inputs and outputs tgt (compromising their access controls)
* Solution is isolation (like the chrome example)
* Note that solutions must always operate at a level below the problem, eg. kernel problems must be solved by hardware

this lecturer guy is crazy
