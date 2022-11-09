#include <stdio.h>

void printChar(int a, int b, int c);

int main() {
    int a,b,c;

    scanf("%d %d %d", &a,&b,&c);
    printChar(a,b,c);
}

void printChar(int a, int b, int c) {
    int max=0, i;
    if (a > max) max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    
    for (i=max;i;i--) {
        printf("%c", a>=i?'*':' ');
        printf("%c", b>=i?'*':' ');
        printf("%c\n", c>=i?'*':' ');
    }
}
