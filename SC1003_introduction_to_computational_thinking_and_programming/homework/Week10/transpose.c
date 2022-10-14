#include <stdio.h>
#include <stdlib.h>

/*
 * This is a proper solution using the concept of heap memory and pointer arithmetic
 * The pros of this solution is it does not need a maximum SIZE.
 * In other words, n can be as you want (until 2.147 billion, or as large as your RAM will hold).
 * If you want an easier solution (in curriculum), check out transpose_easy.c
 */

void transpose2D(int **ar, int rowSize, int colSize);
void reduceMatrix2D(int *ar, int rowSize, int colSize);
void printMatrix(int *ar, int x, int y);

int main() {
    int x, y;

     /* Dynamically allocate arrays (with malloc, not in curriculum) */
    printf("Size of Columns/Rows:\n");
    scanf("%d %d", &x, &y);

    /* Read the matrix from the user */
    int *matrix = malloc(sizeof(int*)*y*x);
    int size = x*y;
    for (int i=0;i<size;i++) scanf("%d", matrix+i);

    /* Main code */
    int action = 1;
    while (action) {
        printf("Current matrix:\n");
        printMatrix(matrix, x, y);

        printf("What do you want to do?\n(1) Transpose\n(2) Triangulate\n");
        scanf("%d", &action);

        switch (action) {
        case 1:
            transpose2D(&matrix, y, x);
            int temp = x;
            x = y;
            y = temp;
            printf("Matrix was transposed successfully.\n");
            break;
        case 2:
            if (x != y) {
                printf("Only square matrices can be reduced!\n");
                break;
            }
            reduceMatrix2D(matrix, y, x);
            printf("Matrix was reduced successfully.\n");
            break;
        }
    }

    /* Deallocate memory after using malloc */
    free(matrix);
}

/* Simple function to print a matrix */
void printMatrix(int *ar, int x, int y) {
    for (int r=0;r<y;r++) {
        for (int c=0;c<x;c++)
            printf(" %d", ar[x*r+c]);
        printf("\n");
    }
}

 /* Since ar is dynamically allocated and modified in-place, it's an int** instead of int[][SIZE] */
void transpose2D(int **ar, int rowSize, int colSize) {
    /* Allocate new memory and assign values with funky pointer arithmetic */
    int *matrix = malloc(sizeof(int)*rowSize*colSize);
    for (int y=0;y<colSize;y++)
        for (int x=0;x<rowSize;x++)
            matrix[y*rowSize+x] = (*ar)[y+colSize*x] ;

    /* Free the old memory */
    free(*ar);
    /* Change the pointer in place */
    *ar = matrix;
}

void reduceMatrix2D(int *ar, int rowSize, int colSize) {
    for (int i=0;i<colSize;i++)
        for (int n=i+1;n<colSize;n++) {
            ar[i*colSize+i] += ar[n*colSize+i];
            ar[n*colSize+i] = 0;
        }
}
