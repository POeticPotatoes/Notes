#include <stdio.h>
#define MAX 10

int hexStrToDec(char *hex);

int main() {
    char a[MAX];
    scanf("%s", a);

    printf("Result: %d\n", hexStrToDec(a));
}

int convert(char c) {
    if (c<97) return c-48;
    return c-87;
}

int hexStrToDec(char *hex) {
    int ans = 0;
    for (;*hex;hex++) ans *=16, ans += convert(*hex);
    return ans;
}
