* 1a  
    Computer Organisation is the underlying organisation of hardware componenets that are designed to provide support for an operating system and its users.
* 1b  
    Interrupts are triggered by hardware and used by the operating system to control user mode processes. During an interrupt, the system triggers a context switch from user mode to kernel mode, saving the registers of the current process to its PCB. This may be triggered due to unauthorised access of memory space beyond a process' allocated space (segmentation fault) due to a timer to allow preemptive process scheduling to take place, or when a DMA process completes its data transfer and notifies the system.
2
true
false
false
true

multiprogramming
virtualising a cpu to complete multiple processes on a system, allowing for shorter response and waiting times for each process
goal: cpu utilisation

multiprocessing
allowing a single system to use multiple cores, allowing multiple processes to be completed simultaneously on different processors.
goal increase computing power with parallel architecture
