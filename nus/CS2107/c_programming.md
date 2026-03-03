## C Programming
* Execution Integrity: Trusted and authorized code is running
* Memory Integrity: Integrity of data and code
* Control-Flow Integrity: Execution Flow

Secure Programming: Writing software designed to function under malicious attacks
* Usually, atypical operation environment are not considered

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
