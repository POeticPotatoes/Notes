#include <stdio.h>
#define MAX 1000

char values[] = "0123456789abcde";

void decTohexStr(char *str, int num);

int main() {
    int num;
    char result[MAX];
    scanf("%d", &num);

    decTohexStr(result, num);
    printf("Result: %s\n", result);
}

void decTohexStr(char *str, int num) {
    char result[MAX];
    int i=0, j=0;
    for (;num;num/=16) *(result+i++) = values[num%16];
    *(str+i) = '\0';
    for (;i--;j++) str[j] = result[i];
}
