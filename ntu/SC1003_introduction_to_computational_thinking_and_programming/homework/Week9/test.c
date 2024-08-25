#include <stdio.h>

int main() {
    
    int number;
    int *p;
    p = 100;
    number = 8;
    p = &number;
    *p=10;
    number=0x16b4a7500;

    printf("number: %d\n", number);
    printf("*number: %p\n", &number);
    printf("p: %p\n", p);
    printf("&p: %p\n", &p);
    printf("*p: %d\n", *p);
}
