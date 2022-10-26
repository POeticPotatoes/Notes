#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stringcmp(char *s1, char *s2);

int main() {
    char s1[100], s2[100];

    puts("Enter a source string:");
    fgets(s1, MAX, stdin);

    puts("Enter a target string:");
    fgets(s2, MAX, stdin);

    printf("stringcmp(): %d\n", stringcmp(s1, s2));
}

int stringcmp(char *s1, char *s2) {
    int i=-1;
    while (s1[++i]) if (s1[i] != s2[i]) return -1+2*(s1[i]>s2[i]);
    if (s2[i]) return -1;
    return 0;
}
