#include "stdio.h"
char *strcpy(char *,char *);
int main(void)//我的main函数只能返回值为int 
{
    char a[50],b[60]="there is a boat on the lake.";
    printf("%s\n",strcpy(a,b));
}
char *strcpy(char *s,char *t)
{
	char *p = s;
    while(*s++=*t++)//经过了这一步操作以后s的值发生了变化 
    ;
    return (p);
}
