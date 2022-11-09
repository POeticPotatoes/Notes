#include <stdio.h>
#define N 20
int main()
{
    int a[N],i,j,k,m;
    int size;
    /* Write your code here Ð for additional local variables */
    printf("Enter array size: \n");
    scanf("%d",&size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++)
        scanf("%d", &a[i]);
    printf("Result: \n");
    for (i=1;i<=size;i++) {
        for (j=0;j<size;j++) printf("%d", a[(j-i+size)%size]);
        printf("\n");
    }
 return 0;
} 
