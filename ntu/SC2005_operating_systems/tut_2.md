false
true
false
false

2.
Data is global, fixed in size, and shared among all child processes
Stack is not shared between child processes and can grow in size and change values

3.
Single threaded process has a single process that executes linearly

Multi threaded process spawns multiple child processes that may complete in parallel and execute simultaneously, increasing throughput

threads in a process code, data and heap regions are shared, but stack is unique, have their own TCB

4.
Initial state, P0 is ready and P1 is executing
P1 triggers an interrupt, goes waiting
user->kernel, context switch, services interrupt, P1 is now ready
scheduler dispatches P0, kernel->user
P0 is now running, P1 is ready
P0 executes IO system call, triggering interrupt, goes waiting
user->kernel, context switch, services interrupt, p0 is now read
scheduler dispatches P1, kernel->user
P1 is now running, P0 is ready
