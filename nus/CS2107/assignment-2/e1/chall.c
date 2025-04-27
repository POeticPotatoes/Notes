#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// REDACTED!!! You will never find my secret! **Randomly generated per run
char* secret = "[REDACTED]";

// Flush stdin and stdout buffers (safe to ignore)
int setup() {
    setbuf(stdin, 0);
    setbuf(stdout, 0);
}

// You want to reach this function!
int win() {
    char* argv[3] = {"/bin/cat", "flag.txt", NULL};
    printf("Good job!\n");
    execve("/bin/cat", argv, NULL);
    exit(0);
}

int main() {
    setup();
    // Define buffer
    char buf[128];

    // Print welcome message
    printf("Welcome to the stack!\n");
    printf("We have all sorts of goodies here, only for the eyes of authorized users :)\n");
    printf("Please enter your secret identity key:\n");

    // Read user input
    fgets(buf, 0x128, stdin);

    // Verify user input with secret
    if (!strcmp(secret, buf)) { // If user input matches secret, print flag
        win();
    }

    // If no match at all, print access denied message >:(
    printf("Access denied! Why are you trying to access my system?? >:(\n");
}