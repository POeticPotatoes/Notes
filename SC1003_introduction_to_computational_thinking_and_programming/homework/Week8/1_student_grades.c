#include <stdio.h>

int main() {
    int id=0, mark;
    char input[100];

    printf("Enter student ID:\n");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &id);
    printf("Enter student grade:\n");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &mark);

    while (id != -1) {
        printf("ID = %d", id);
        if (mark >= 75)
            printf("Grade = A\n");
        else if (mark >= 65)
            printf("Grade = B\n");
        else if (mark >= 55)
            printf("Grade = C\n");
        else if (mark >= 45)
            printf("Grade = D\n");
        else  
            printf("Grade = F\n");

        id = 0;
        mark = 0;
        printf("Enter student ID:\n");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &id);
        printf("Enter student grade:\n");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &mark);
    }
}
