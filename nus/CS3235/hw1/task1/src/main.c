#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

__attribute__((constructor))
void setup(void) {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
}

void sig_handler(int signum){
    printf("Time's up! Too slow!\n");
    exit(-1);
}

// This is the backdoor function - students need to find and jump to it
void backdoor() {
    printf("Congratulations! You found the backdoor!\n");
    system("/bin/sh");
}

void vulnerable() {
    char buffer[64];
    printf("Enter your name: ");
    gets(buffer);  // Obvious vulnerability
    printf("Hello, %s!\n", buffer);
}

int main(int argc, char *argv[]){
    printf("=== Welcome to Task1: Ret2Backdoor ===\n");
    printf("Can you find the hidden function?\n\n");

    signal(SIGALRM, sig_handler);
    alarm(10);

    vulnerable();

    printf("Goodbye!\n");
    return 0;
}
