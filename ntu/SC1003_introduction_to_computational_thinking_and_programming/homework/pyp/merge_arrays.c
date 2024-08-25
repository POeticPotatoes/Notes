#include <stdio.h>
#include <string.h>
#define MAX 1000

void mergeArrays(int *a, int *b, int *c, int n1, int n2);

int main() {
    int a[MAX], b[MAX], c[MAX], n1, n2, i, n3;

    scanf("%d %d", &n1, &n2);
    n3 = n1+n2;

    for (i=0;i<n1;i++) scanf("%d", a+i);
    for (i=0;i<n2;i++) scanf("%d", b+i);

    mergeArrays(a,b,c,n1,n2);
    printf("Result:");
    for (i=0;i<n3;i++) printf(" %d", c[i]);
    printf("\n");
}

void mergeArrays(int *a, int *b, int *c, int n1, int n2) {
    int i=0,j=0;
    for (;i<n1;i++) {
        for (;j<n2&&b[j]<a[i];j++) *c++ = b[j];
        *c++ = a[i];
    }
    for (;j<n2;j++) *c++ = b[j];
}
