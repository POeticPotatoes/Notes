#include <stdio.h>
#define MAX 1000

void merge(char *a, char *b, char *c);

int main() {
    char a[MAX], b[MAX], c[MAX];
    scanf("%s", a);
    scanf("%s", b);

    merge(a,b,c);
    printf("Result: %s\n", c);
}

void merge(char *a, char *b, char *c) {
    int count[128] = {};
    int i=0, j;
    for (;*a;a++) count[*a]++;
    for (;*b;b++) count[*b]++;
    for (;i<128;i++) for (j=0;j<count[i];j++) *c++ = i;
    *c = '\0';
}
