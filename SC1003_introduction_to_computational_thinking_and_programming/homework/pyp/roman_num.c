#include <stdio.h>
#define TRUE 1
#define FALSE 0
int romanNum(char *str);
int main()
{
     int num;
     char roman[10];
     printf("Enter a Roman number: \n");
     scanf("%s",roman);
     num = romanNum(roman);
     printf("romanNum(): %d\n", num);
     return 0;
}
int romanNum(char *str) {
    int ans=0, i;
    char cur = *str;
    switch (cur) {
        case 'I': i = 1; break;
        case 'V': i = 5; break;
        case 'X': i = 10; break;
    }
    for (;*str&&*str==cur;str++) ans += i;
    if (!*str) return ans;
    
    if (*str > cur) return romanNum(str)-ans;
    else return ans + romanNum(str);
}
