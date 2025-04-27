#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main();
int menu();

int setup() {
    setbuf(stdin, 0);
    setbuf(stdout, 0);
}

int win() {
    char* argv[3] = {"/bin/cat", "flag.txt", NULL};
    printf("Good job!\n");
    execve("/bin/cat", argv, NULL);
}

// Get offset here
int initialize() {
    char buf[0x20];
    printf("\033[1;92m");
    printf("Please enter your username:\n");
    fgets(buf, 0x20, stdin);
    printf("\n\nWelcome, ");
    printf(buf);
    sleep(1);
}

// Useless
int check_status() {
    printf("Checking status...\n");
    sleep(1.5);
    printf("\033[1;91m");
    printf("SYSADMIN 31337 ver. 2.10.7\n");
    printf("Status: OK\n");
    printf("Mainframe access: LOCKED\n");
    printf("User status: USER\n");
    printf("User level: LEVEL 1 ACCESS\n");
    printf("\033[1;92m");
    printf("\nPress enter to return to menu\n");
    getchar();
}

// Bypass occurs here
int access_mainframe() {
    char buf[0x30];
    printf("Please enter your super secret access key:\n");
    gets(buf);
    printf("\033[1;91m");
    printf("Access denied! Admins have been notified of attempted access.\n");
    printf("\033[1;92m");
    sleep(2);
}

int menu() {
    char input[4];

    initialize();

    while(1) {
        printf("\n\n\n\n\n\n");
        printf("\033[1;91m");
        printf("  #####  #     #  #####     #    ######  #     # ### #     # \n");
        printf(" #     #  #   #  #     #   # #   #     # ##   ##  #  ##    # \n");
        printf(" #         # #   #        #   #  #     # # # # #  #  # #   # \n");
        printf("  #####     #     #####  #     # #     # #  #  #  #  #  #  # \n");
        printf("       #    #          # ####### #     # #     #  #  #   # # \n");
        printf(" #     #    #    #     # #     # #     # #     #  #  #    ## \n");
        printf("  #####     #     #####  #     # ######  #     # ### #     # \n");
        printf("                                                              \n");
        printf("  #####    #    #####   #####  #######                       \n");
        printf(" #     #  ##   #     # #     # #    #                        \n");
        printf("       # # #         #       #     #                         \n");
        printf("  #####    #    #####   #####     #                          \n");
        printf("       #   #         #       #   #                           \n");
        printf(" #     #   #   #     # #     #   #                           \n");
        printf("  #####  #####  #####   #####    #                           \n");
        printf("\033[1;92m");
        printf("\n1. Check status\n");
        printf("2. Access mainframe\n");
        printf("3. Exit\n");
        printf("\nOption: ");
        fgets(input, 4, stdin);
        switch(atoi(input)) {
            case 1:
                check_status();
                break;
            case 2:
                access_mainframe();
                break;
            case 3:
                printf("Exiting system...\n");
                printf("Goodbye\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                sleep(1.5);
                continue;
        }
    }
}

int main() {
    setup();
    menu();
}
