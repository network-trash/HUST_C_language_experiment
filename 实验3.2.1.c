#include <stdio.h>
unsigned long long sum_fac(int n);           //语法错误一：函数使用前未声明 
int main(void)
{
	int k;
    for(k=1;k<=20;k++)
        printf("k=%d\tthe sum is %llu\n",k,sum_fac(k));        //应该改成llu
    return 0;
}
unsigned long long sum_fac(int n)
{
    static unsigned long long s=0;             //注意到要求各项的累计和，因此要用静态变量 
    unsigned long long fac=1;                  //要用unsigned long long以防止超标 
    int i;
   	for(i=1;i<=n;i++)
        fac*=i;
    s+=fac;
    return s;
}
