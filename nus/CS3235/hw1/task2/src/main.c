#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

__attribute__((constructor))
void setup(void) {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
}

void sig_handler(int signum){
    printf("Time's up! Too slow!\n");
    exit(-1);
}

void vulnerable() {
    char buffer[64];
    printf("Your message: ");
    read(0, buffer, 256);  // Buffer overflow vulnerability
    printf("You said: %s\n", buffer);
}

int main(int argc, char *argv[]){
    printf("=== Welcome to Task2: Ret2System (32-bit) ===\n");
    printf("Hint: system() is your friend, but where is /bin/sh?\n\n");

    signal(SIGALRM, sig_handler);
    alarm(10);

    vulnerable();

    printf("Goodbye!\n");
    return 0;
}
