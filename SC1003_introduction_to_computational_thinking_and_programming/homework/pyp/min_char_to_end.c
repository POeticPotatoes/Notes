#include <stdio.h>
#include <string.h>
void minCharToEnd(char *str);
int main()
{
 char str[80];

 printf("Enter a string: \n");
 scanf("%s",str);
 minCharToEnd(str);
 printf("minCharToEnd(): %s",str);
 return 0;
}
void minCharToEnd(char *str)
{
    int min, i=0;
    char s = 127;
    for (;str[i];i++) if (str[i] < s) min=i,s=str[i];
    for (;str[min];min++) str[min] = str[min+1];
    str[min-1] = s;
}
