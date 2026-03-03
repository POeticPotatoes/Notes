## Access Control
Works between user and system resources, restricts operations on objects by subjects
* Subject, Principal: humans
* Object: **the thing**
* Access Modes: actions/ operations

### Security Perimeter
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

### Controlled Invocation
* Allow predefined access mode: elevated privilege (bridge)
* Unix: Real UID: invoker, Effective UID: determines access rights
* s: Set User ID (SUID)

#### Time Of Check To Time Of Use (TOCTTOU)
Race condition between check and usage using symlinks

Solution:
* Avoid separate system calls (NOFOLLOW flag for `open()`)
* Fstat: Use file descriptor to retrieve file info and check perms instead of name
* OS Access Control: Set EUID to user, let OS do it
