#include <stdio.h>
#define TRUE 1
#define FALSE 0
int romanNum(char *str);
int romanNum2(char *str);
int main()
{
     int num;
     char roman[10];
     printf("Enter a Roman number: \n");
     scanf("%s",roman);
     printf("romanNum(): %d\n", romanNum(roman));
     printf("romanNum2(): %d\n", romanNum2(roman));
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

int romanNum2(char *str) {
    int i=0, t, c, s=1;
    for (;str[i];i++);
    char prev = str[--i];
    switch (prev) {
        case 'I': c = 1; break;
        case 'V': c = 5; break;
        case 'X': c = 10; break;
    }
    t = c;
    for (;i--;) {
        if (str[i] == prev) {
            if (s) t+=c;
            else t-=c;
            continue;
        }
        s = str[i]>prev;
        switch (str[i]) {
            case 'I': c = 1; break;
            case 'V': c = 5; break;
            case 'X': c = 10; break;
        }
        if (s) t+=c;
        else t-=c;
    }
    return t;
}
