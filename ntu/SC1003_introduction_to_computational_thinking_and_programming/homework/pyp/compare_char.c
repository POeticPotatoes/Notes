#include <stdio.h>
#define MAX 1000

void compareChar(char *a, char *b, char *c);

int main() {
    char a[MAX], b[MAX], c[MAX];
    scanf("%s", a);
    scanf("%s", b);

    compareChar(a,b,c);
    printf("Result: %s\n", c);
}

void compareChar(char *a, char *b, char *c) {
    for (;*a;a++,b++) *c++ = *a>*b?*a:*b;
    for (;*b;b++) *c++ = *b;
    *c = '\0';
}
