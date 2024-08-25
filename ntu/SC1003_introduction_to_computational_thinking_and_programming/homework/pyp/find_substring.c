#include <stdio.h>
#define MAX 1000

int findSubstring(char *str, char *substr);

int main() {
    char str1[MAX], str2[MAX];
    scanf("%s", str1);
    scanf("%s", str2);
    printf("Result: %d\n", findSubstring(str1, str2));
}

int check(char *str, char *substr) {
    for (;*substr;str++,substr++) if (!*str || *str != *substr) return 0;
    return 1;
}

int findSubstring(char *str, char *substr) {
    for (;*str;str++) if (check(str, substr)) return 1;
    return 0;
}
