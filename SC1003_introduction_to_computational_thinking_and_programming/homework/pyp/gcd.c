#include <stdio.h>

int gcd(int a, int b);

int main() {
    int a, b;

    scanf("%d %d", &a, &b);
    printf("Result: %d\n", gcd(a,b));
}

int gcd(int a, int b) {
    int temp;
    while (a) temp = a%b, a=b, b=temp;
    return b;
}
