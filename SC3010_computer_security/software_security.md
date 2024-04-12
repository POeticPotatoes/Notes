# Software Security
## Common Terminology
* **Vulnerability** -> weakness which allows attacker to reduce a system's information assurance
* **Exploit** -> technique which takes advantage of a vulnerability, used by attackers to attack a system
* **Payload** -> custom malicious code that attacker wishes to be executed

## Types of Vulnerabilities
* Memory safety violations
    * Buffer overflow & over-reads
    * Dangling pointers
* Input validation errors
    * Format string attacks
    * SQL injection
    * Code injection
    * Cross-site scripting in web applications
* Race conditions
    * Time of check to time of use bugs
    * Symlink races
* Privilege-confusion bugs
    * Cross-site request forgery
    * Clickjacking
    * FTP bounce attack
* Privilege escalation
* Side-channel attack
    * Timing attack

## Types of Malware (Non Exclusive)
* Virus (Propagates to different computers. Must be triggered by a user)
* Worms (Propagates to different computers **without user intervention**)
* Trojans (Pretend to do something useful to mask malicious behaviours)
* Backdoor (Allow a remote party to gain remote access to computer)
* Adware (Unwanted advertisement)
* Ransomware (Block user data until a ransom is paid)
* Spyware (Gather information about user and send to attacker)
* Crimeware (Automates cybercrime)


## Reasons behind Software Vulnerabilities
It is **impossible** to have a system without vulnerabilities

* Human mistakes
* Human ignorance
* Programming language security
* Software bugs
* Intelligent adversary
    * Will lead bugs to worst possible consequences
    * Selects targets intelligently


## Vulnerabilities in C
###  C Memory Layout
Program|
|-|
Code
Static Vars
Stack
Heap

#### Frame Layout
Frame||
|-|-
Function Parameters| <- BP
Return address (Instruction jump)
Calling SP (Original SP)
Variables
||<-SP
### Buffer Overflow
More input is placed into a buffer than allocated capacity, overwriting information

If the buffer is on the stack/heap/data, overwriting memory locations could cause
* Corruption of program data
* Unexpected transfer of control
* Memory access violation
* Execution of code chosen by attacker

#### Stack Smashing Exploit
* Inject the malicious code into the memory of the target program
* Overwrite return address with address of malicious code

Absolute address of malicious code is sometimes unknown, then the return address must be guessed.  

To improve the chances of finding malicious code, inserting many NOP instructions can create a successful range to land in.

#### Injecting ShellCode
* Allows attacker to run any command by launching a shell
* Shellcode must be converted to assembly, and then stored in binary to a buffer

#### Format String Vulnerabilities
* Escape sequences are essentially instructions
* Attacker can control escape sequences & arguments in user_input
* Number of arguments should match escape sequences
* Mismatch can cause vulnerability
* C compiler does not check such mismatches (could be intentional)

#### Scripting Vulnerabilities
Occurs in scripting languages which:
* Construct commands from predefined code fragments/user input at **runtime**
* Pass script to another software component where it is executed
* Domain-specific language, very high level
* eg. Bash, PowerShell, PHP, JS, Python

An attacker can
* Hide additional commands in user input
