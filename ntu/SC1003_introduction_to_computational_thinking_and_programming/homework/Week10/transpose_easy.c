#include <stdio.h>
#define SIZE 100

/* 
 * Consider large programs with large numbers of data structures.
 * It would be a massive waste of space to have all arrays set to a default size, even if they are empty.
 * Hence, using a defined SIZE is only good in practice but infeasible IRL.
 * The alternative solution is to use **dynamically allocated memory** which only expands when required.
 * I wrote an alternative solution in transpose.c which demonstrates this (out of curriculum but really important).
*/

void transpose2D(int ar[][SIZE], int rowSize, int colSize);
void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize);
void printArray(int ar[][SIZE], int rowSize, int colSize);

int arr[SIZE][SIZE] = {};

int main() {
    int rowSize, colSize;
    printf("Enter number of columns:\n");
    scanf("%d", &colSize);
    printf("Enter number of rows:\n");
    scanf("%d", &rowSize);
    printf("Enter matrix:\n");
    for (int y=0;y<rowSize;y++)
        for (int x=0;x<colSize;x++)
            scanf("%d", arr[y]+x);
    int action = 1;
    while (action) {
        printf("Current array:\n");
        printArray(arr, rowSize, colSize);
        printf("What do you want to do?\n(1) Transpose\n(2) Triangulate\n");
        scanf("%d", &action);
        switch(action) {
            case 1:
                transpose2D(arr, rowSize, colSize);
                int temp = rowSize;
                rowSize = colSize;
                colSize = temp;
                printf("Matrix was successfully transposed\n");
                break;
            case 2:
                if (rowSize != colSize) {
                    printf("Only square matrices can be reduced!\n");
                    break;
                }
                reduceMatrix2D(arr, rowSize, colSize);
                printf("Matrix was reduced successfully.\n");
        }
    }
}

void printArray(int ar[][SIZE], int rowSize, int colSize) {
    for (int y=0;y<rowSize;y++) {
        for (int x=0;x<colSize;x++)
            printf(" %d", arr[y][x]);
        printf("\n");
    }
}


void transpose2D(int ar[][SIZE], int rowSize, int colSize) {
    for (int y=0;y<colSize;y++) {
        for (int x=y;x<rowSize;x++) {
            int temp = ar[y][x];
            ar[y][x] = ar[x][y];
            ar[x][y] = temp;
        }
    }
}

void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize) {
    for (int i=0;i<colSize;i++) {
        for (int n=i+1;n<colSize;n++) {
            ar[i][i] += ar[n][i];
            ar[n][i] = 0;
        }
    }
}
