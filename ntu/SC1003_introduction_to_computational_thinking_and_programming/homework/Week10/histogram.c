#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, count[10] = {};
    scanf("%d", &n);
    while (n--) count[rand()%100/10]++;
    for (int i=0;i<10;i++) {
        printf("%d-%d%s|", i*10, i*10+9, i?"":"  ");
        while (count[i]--) printf("*");
        printf("\n");
    }
}
