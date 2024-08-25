#include <stdio.h>

typedef struct {
float operand1, operand2;
char op;    /* operator ‘+’,‘‐’,‘*’ or ‘/’  */
} bexpression;

float compute1(bexpression expr);

int main() {
    float a,b;
    char c;
    scanf("%f %f %c", &a, &b, &c);
    while (a&&b) {
        bexpression expr = {a,b,c};
        printf("Result: %f\n", compute1(expr));
        scanf("%f %f %c", &a, &b, &c);
    }
}

float compute1(bexpression expr) {
    switch (expr.op) {
        case '+':
            return expr.operand1 + expr.operand2;
        case '-':
            return expr.operand1 - expr.operand2;
        case '*':
            return expr.operand1 * expr.operand2;
        case '/':
            return expr.operand1 / expr.operand2;
    }
    return 0;
}
