#include <stdio.h>
#include <math.h>

float get_distance(int x1, int y1, int x2, int y2);
void get_distance2(int x1, int y1, int x2, int y2, float *result);

int main() {
    int x1, y1, x2, y2;
    float result;
    printf("Input x1, y1, x2, and y2: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    printf("Distances:\n    get_distance : %.2f\n", get_distance(x1,y1,x2,y2));
    get_distance2(x1,y1,x2,y2,&result);
    printf("    get_distance2: %.2f\n", result);
}

// NOTE: We use longs because the squared values may be larger than the max value of ints
float get_distance(int x1, int y1, int x2, int y2) {
    long x=x1-x2, y=y1-y2;
    return sqrt(x*x + y*y);
}

void get_distance2(int x1, int y1, int x2, int y2, float *result) {
    long x=x1-x2, y=y1-y2;
    *result = sqrt(x*x + y*y);
}
