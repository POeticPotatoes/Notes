#include <stdio.h>
#include <math.h>

typedef struct {
    double radius;
    double x;
    double y;
} circle;

circle circles[2];

int intersect(circle c1, circle c2);
int contain(circle *c1, circle *c2);

int main() {
    for (int i=0;i<2;i++) {
        int radius, x, y;
        scanf("%d %d %d", &radius, &x, &y);
        if (!radius) break;
        circle *c = circles+i;
        c->radius = radius;
        c->x = x;
        c->y = y;
    }

    int action;
    printf("What do you want to do:\n");
    scanf("%d", &action);

    if (action == 1) {
        int result = intersect(circles[0], circles[1]);
        printf("Result: %d\n", result);
    }
    if (action == 2) {
        int result = contain(circles, circles+1);
        printf("Result: %d\n", result);
    }
}

int intersect(circle c1, circle c2) {
    double x = c1.x-c2.x, y=c1.y-c2.y, radii = c1.radius + c2.radius, distance = x*x + y*y;
    return (radii*radii-distance) > -0.0000001f;
}

int contain(circle *c1, circle *c2) {
    double x = c1->x-c2->x, y=c1->y-c2->y, distance = sqrt(x*x + y*y);
    return c1->radius >= c2->radius + distance;
}
