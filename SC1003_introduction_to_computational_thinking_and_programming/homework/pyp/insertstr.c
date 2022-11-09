#include <stdio.h>
#define MAX 1000

void insertStr(char *a, char *b);

int main() {
    char a[MAX],b[MAX];
    scanf("%s", a);
    scanf("%s", b);

    insertStr(a,b);
    printf("Result: %s\n",a);
}

void insertStr(char *a, char *b) {
    int count[128] = {}, i=0, j;
    char *c = a;
    for (;*a;a++) count[*a]++;
    for (;*b;b++) count[*b]++;
    for (;i<128;i++) for (j=0;j<count[i];j++) *c++ = i;
    *c = '\0';
}
