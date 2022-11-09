#include <stdio.h>
#define MAX 100

void pigLatin(char *orig, char *result);

int main() {
    char orig[MAX], result[MAX];
    scanf("%s", orig);

    pigLatin(orig, result);
    printf("Result: %s\n", result);
}

int first(char *orig) {
    int i=0;
    for (;orig[i];i++)
        switch (orig[i]) {
            case 'y':
                if (i) break;
            case 'a': case 'e': case 'i': case 'o': case 'u': return i;
            default: break;
        }
    return i;
}

void pigLatin(char *orig, char *result) {
    int i = first(orig), j=0, k=i;
    for (;orig[i];i++) *result++ = orig[i];
    for (;j<k;j++) *result++ = orig[j];
    *result++ = 'a';
    *result++ = 'y';
    *result++ = '\0';
}
