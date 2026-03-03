#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>

__attribute__((constructor))
void setup(void) {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
}
 
void sig_handler(int signum){
	printf("Quick! Quick! Tell me your answer.\n");
	exit(-1);
}

int main(int argc, char *argv[]){

	printf("Hello hackers! Do you know where is the library?\n");
	
	signal(SIGALRM,sig_handler); // Register signal handler
 
	alarm(3);
	char buffer[32];

	printf("> ");
	read(0, buffer, 0x100);

	return 0;
}