#include <stdio.h>
#define MAX 1000

void strIntersect(char *a, char *b, char *c);

int main() {
    char a[MAX], b[MAX], c[MAX];
    scanf("%s", a);
    scanf("%s", b);
    strIntersect(a, b, c);

    printf("Result: %s\n", c);
}

void strIntersect(char *a, char *b, char *c) {
    int v1[128] = {}, v2[128] = {};
    for (;*a;a++) v1[*a]++;
    for (;*b;b++) v2[*b]++;

    for (int i=0;i<128;i++) if (v1[i] && v2[i]) *(c++) = i;
    *c = '\0';
}
