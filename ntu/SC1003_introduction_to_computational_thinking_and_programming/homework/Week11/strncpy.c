#include <stdio.h>
#include <stdlib.h>

char *stringcopy(char *s1, char *s2, int n);

int main() {
    int s, n;
    puts("Enter the size of the original string:");
    scanf("%d",&s);

    char *a = malloc(sizeof(char[s+1]));

    puts("Enter the string:");
    getchar();
    fgets(a, s, stdin);
    if (a[s]) a[s] = '\0';
    while (getchar() != '\n');

    puts("Enter the number of characters to copy:");
    scanf("%d", &n);

    char *b = malloc(sizeof(char[n]));
    stringcopy(a,b,n);

    puts(b);
}

char *stringcopy(char *s1, char *s2, int n) {
    int c=-1;
    while (s1[++c]) s2[c] = s1[c];
    while (++c < n) s2[c] = '\0';
    return s1;
}
