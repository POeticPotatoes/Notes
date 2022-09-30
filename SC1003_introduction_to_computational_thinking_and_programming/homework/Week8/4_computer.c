#include <stdio.h>

int main() {
    float x, ans = 1, cur = 1;

    printf("Enter x:\n");
    scanf("%f", &x);

    for (int i=1;i<10;i++) {
        cur *= x;
        cur /= i;
        ans += cur;
    }

    printf("Result = %.2f\n", ans);
}
