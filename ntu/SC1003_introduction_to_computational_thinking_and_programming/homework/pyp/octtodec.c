#include <stdio.h>
int octStrTodec(char *str);
int main()
{
 char str[20],*sp;
 int num;

 printf("Enter an octal number: \n");
 scanf("%s",str);
 num=octStrTodec(str);
 printf("octStrTodec(): %d\n",num);
 return 0;
}
int octStrTodec(char *str)
{
    int ans;
    for (ans=0;*str;str++) ans *= 8, ans += *str-48;
    return ans;
}
