#include <stdio.h>
#define MAX 1000

int countSubstring(char *a, char *b);

int main() {
    char a[MAX], b[MAX];
    scanf("%s", a);
    scanf("%s", b);

    printf("Result: %d\n", countSubstring(a, b));
}

int check(char *a, char *b) {
    for (;*b;b++,a++) if (!*a || *a!=*b) return 0;
    return 1;
}

int countSubstring(char *a, char *b) {
    int ans=0;
    for (;*a;a++) ans += check(a, b);
    return ans;
}
