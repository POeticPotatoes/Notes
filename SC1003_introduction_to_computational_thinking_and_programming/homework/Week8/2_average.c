#include <stdio.h>

int main() {
    
    int t;
    printf("Enter number of lines:\n");
    scanf("%d", &t);

    for (int i=1;i<=t;i++) {
        int c=0, n;
        float t = 0;
        printf("Enter line %d (end with -1):\n", i);
        scanf("%d", &n);
        while (n != -1) {
            c++; // This is a c++ joke (superior language)
            t += n;
            scanf("%d", &n);
        }
        if (c == 0) { // Avoid trolling
            printf("Average = 0\n");
            continue;
        }
        printf("Average = %.2f\n", t/c);
    }
}

