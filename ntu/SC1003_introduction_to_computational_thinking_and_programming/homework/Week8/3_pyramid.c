#include <stdio.h>

int main() {
    
    int size;
    printf("Yo, what size?\n");
    scanf("%d", &size);

    for (int i=0;i<size;i++) {
        for (int n=0;n<=i;n++)
            printf("%d", i%3+1);
        printf("\n");
    }
}
