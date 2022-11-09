#include <stdio.h>
#include <string.h>
#define MAX 1000

void compressString(char *a);

int main() {
    char a[MAX];
    scanf("%s", a);

    compressString(a);
    printf("Result: %s\n", a);
}

void compressString(char *a) {
    char prev=*a;
    int cur=1;
    for (a++;*a;a++) {
        if (*a == prev) {
            cur++;
            continue;
        }
        if (cur == 1) printf("%c", prev);
        else printf("[%d%c]", cur, prev);
        prev = *a;
        cur = 1;
    }
    if (cur == 1) printf("%c", prev);
    else printf("[%d%c]", cur, prev);
    printf("\n");
}
